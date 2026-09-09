#!/usr/bin/env python3
"""Generate objdiff-only assembly for the payload's data and BSS sections.

The original payload data is currently available as one unsplit binary blob.
This script preserves that blob as ``.data``, adds labels for data objects whose
target addresses are known, and describes the known IWRAM objects in ``.bss``.
The message control-code handler table is emitted as symbol references so the
resulting object has relocations comparable to the C translation unit.

This output is only an objdiff target artifact.  It does not alter the payload
linker layout or make claims about whether any original object was ``const``.
"""

from __future__ import annotations

import argparse
import struct
from dataclasses import dataclass
from pathlib import Path


ELF_HEADER_SIZE = 52
ELFCLASS32 = 1
ELFDATA2LSB = 1
EM_ARM = 40
SHT_SYMTAB = 2
STT_FUNC = 2

TEXT_ADDRESS = 0x0201820C
DATA_ADDRESS = 0x02029698
IWRAM_ADDRESS = 0x03000000
EXPECTED_DATA_SIZE = 0x1068C

# Final-link ranges owned by each translation unit.  Section-relative target
# objects are generated from these ranges so objdiff displays data beside the
# source file that defines it while retaining the final binary's TU order.
UNIT_DATA_RANGES = {
    "interrupt": ((".data", 0x0000, 0x0038),),
    "m_msg": ((".data", 0x0038, 0x169C),),
    "lib": ((".data", 0x169C, 0x191C), (".rodata", 0x191C, 0x1924)),
    "joyboot": ((".data", 0x1924, 0x1931),),
    "island_program": ((".data", 0x1934, 0x1C54),),
    "m_msg_sprite": ((".data", 0x1C54, 0x1D48),),
    "multisio": ((".data", 0x1D48, 0x1D61),),
    "island_field": ((".data", 0x1D64, 0x66A0),),
    "building": ((".data", 0x66A0, 0x6720),),
    "animated_field_obj": ((".data", 0x6720, 0x6834),),
    "field_obj": ((".data", 0x6834, 0x6A94),),
    "islander": ((".data", 0x6A94, 0xAB6C),),
    "item": ((".data", 0xAB6C, 0xAE50),),
    "falling_fruit": ((".data", 0xAE50, 0xB088),),
    "entity": ((".data", 0xB088, 0xB6F4),),
    "player_hand": ((".data", 0xB6F4, 0xB84C),),
    "time_palette": ((".data", 0xB84C, 0xB90C),),
    "msg_data": ((".data", 0xB90C, 0xC15C),),
    "world_pal": ((".data", 0xC15C, 0xC55C),),
    "sound": ((".data", 0xC55C, 0xCA90),),
    "sound_data": ((".data", 0xCA90, 0x1068C),),
}

UNIT_BSS_RANGES = {
    "main": (0x0000, 0x0004),
    "m_msg": (0x0010, 0x001E),
    "islander": (0x0020, 0x0028),
    "sound": (0x0028, 0x1B40),
    "data": (0x1B40, 0x4BAC),
}


@dataclass(frozen=True, slots=True)
class ElfSection:
    section_type: int
    offset: int
    size: int
    link: int
    entry_size: int


@dataclass(frozen=True, slots=True)
class DataObject:
    name: str
    offset: int
    size: int
    relocation_kind: str | None = None
    global_symbol: bool = False


@dataclass(frozen=True, slots=True)
class BssObject:
    name: str
    address: int
    size: int
    global_symbol: bool = False


DATA_OBJECTS = (
    # Original address: 0x02029698
    DataObject("sInitialIntrTable", 0x0, 0x38, "thumb_functions", global_symbol=True),
    DataObject("sMsgGlyphWidths", 0x0038, 0x0100),
    DataObject("sFontCodeWidths", 0x0138, 0x0100),
    DataObject("sMsgFontGlyphs", 0x0238, 0x1000),
    DataObject("sMsgSpaceGlyph", 0x1238, 0x0010),
    DataObject("sCachedMessageIds", 0x1248, 0x0024),
    DataObject("sMsgControlCodeHandlers", 0x126C, 0x01C4, "thumb_functions"),
    # Original address: 0x0202AAC8; mMsg_UpdateChoiceHighlight's two-choice initializer.
    DataObject("gMsgTwoChoiceHighlightTiles", 0x1430, 0x0008, "choice_tiles", True),
    # Original address: 0x0202AAD0; mMsg_UpdateChoiceHighlight's three-choice initializer.
    DataObject("gMsgThreeChoiceHighlightTiles", 0x1438, 0x000C, "choice_tiles", True),
    DataObject("gMsgWindowScrollOffsets", 0x148C, 0x0030),
    DataObject("sMsgControlCodeInfo", 0x14BC, 0x01C4),
    # Original address: 0x0202AD18
    DataObject("gMsgChoiceTemplateParams", 0x1680, 0x4, global_symbol=True),
    # Original address: 0x0202AD1C
    DataObject("sFontTileBufferVramDestinations", 0x1684, 0xC, global_symbol=True),
    # Original address: 0x0202AD28
    DataObject("sFontTileBufferSizes", 0x1690, 0xC, global_symbol=True),
    # Original address: 0x0202AD34
    DataObject("gSineTable", 0x169C, 0x280, global_symbol=True),
    # Original address: 0x0202AFB4
    DataObject("sHiddenOamAttributes", 0x191C, 0x8, global_symbol=True),
    # Original address: 0x0202AFBC
    DataObject("sJoybootGbaHandshake", 0x1924, 0x0005, global_symbol=True),
    # Original address: 0x0202AFC4
    DataObject("sJoybootGameCubeHandshake", 0x192C, 0x0005, global_symbol=True),
    # Original address: 0x0202AFDC
    DataObject("sIslandProgramNoticeUpdateProcs", 0x1944, 0x10, "thumb_functions", True),
    # Original address: 0x0202AFFC
    DataObject("sIslandProgramPromptUpdateProcs", 0x1964, 0x10, "thumb_functions", True),
    DataObject("sTimeOfDayPalette2Table", 0x197C, 0x0180, global_symbol=True),
    DataObject("sTimeOfDayPalette3Table", 0x1AFC, 0x00F0, global_symbol=True),
    # Original address: 0x0202B2A0
    DataObject("sIslandProgramTransferUpdateProcs", 0x1C08, 0x1C, "thumb_functions", True),
    DataObject("sIslandProgramModeEnterProcs", 0x1C24, 0x0018, "thumb_functions", True),
    # Original address: 0x0202B2D4
    DataObject("sIslandProgramModeUpdateProcs", 0x1C3C, 0x18, "thumb_functions", True),
    # Original address: 0x0202B2FC
    DataObject("sMsgSpriteProfiles", 0x1C64, 0x34, "data_pointers", global_symbol=True),
    # Original address: 0x0202B378
    DataObject("sMsgContinuePromptAnimations", 0x1CE0, 4, "data_pointers", global_symbol=True),
    # Original address: 0x0202B3DC
    DataObject("sMsgChoiceCursorAnimations", 0x1D44, 4, "data_pointers", global_symbol=True),
    # Original address: 0x0202B3FC
    DataObject("sIslandRightAcreTilemaps", 0x1D64, 0x2000, global_symbol=True),
    # Original address: 0x0202D3FC
    DataObject("sIslandLeftAcreTilemaps", 0x3D64, 0x2000, global_symbol=True),
    # Original address: 0x0202F3FC
    DataObject("sFieldPaletteAnimation0", 0x5D64, 0x200, global_symbol=True),
    # Original address: 0x0202F5FC
    DataObject("sFieldPaletteAnimation2", 0x5F64, 0x200, global_symbol=True),
    DataObject("g_ItemDefinitions", 0x6164, 0x0420, global_symbol=True),
    # Original address: 0x0202FC1C
    DataObject("sCabanaTilemap", 0x6584, 0x80, global_symbol=True),
    # Original address: 0x0202FC9C
    DataObject("sIslanderHouseTilemap", 0x6604, 0x60, global_symbol=True),
    # Original address: 0x0202FCFC
    DataObject("sCabanaFootprint", 0x6664, 0x10, global_symbol=True),
    # Original address: 0x0202FD0C
    DataObject("sIslanderHouseFootprint", 0x6674, 0x9, global_symbol=True),
    # Original address: 0x0202FD16
    DataObject("sFieldEntityBaseTiles", 0x667E, 0x12, global_symbol=True),
    # Original address: 0x0202FD28
    DataObject("sIslandFieldUpdateProcs", 0x6690, 0x10, "thumb_functions", global_symbol=True),
    # Original address: 0x0202FD40
    DataObject("sIslandBuildingSprites", 0x66A8, 0x78, global_symbol=True),
    # Original address: 0x0202FDB8
    DataObject("sFieldAnimOAMData", 0x6720, 0xC0, global_symbol=True),
    # Original address: 0x0202FE78
    DataObject("sFieldAnimations", 0x67E0, 0x38, "animation_frames", global_symbol=True),
    # Original address: 0x0202FEB0
    DataObject("sFieldAnimationFrames", 0x6818, 0x1C, "data_pointers", global_symbol=True),
    DataObject("gFieldObjectSpriteFrameIndices", 0x6848, 0x0098, global_symbol=True),
    DataObject("gFieldObjectSpriteFrames", 0x68E0, 0x0180, global_symbol=True),
    # Original address: 0x020300F8
    DataObject("sFruitDropOffsetsX", 0x6A60, 0x0C, global_symbol=True),
    # Original address: 0x02030104
    DataObject("sFruitDropOffsetsY", 0x6A6C, 0x0C, global_symbol=True),
    # Original address: 0x02030110
    DataObject("sFieldObjectInitialTimers", 0x6A78, 0x13, global_symbol=True),
    # Original address: 0x02030123
    DataObject("sFieldObjectShakeFrames", 0x6A8B, 0x09, global_symbol=True),
    DataObject("sOAMData", 0x6A94, 0x2668, global_symbol=True),
    DataObject("sIslanderAnimFrames", 0x90FC, 0x08E0, "islander_frames", True),
    DataObject("sIslanderAnimFrameLists", 0x99DC, 0x060C, "islander_frame_list", True),
    # Original address: 0x02033680
    DataObject("gIslanderAnimData", 0x9FE8, 0x018C, "islander_anim_table", True),
    # Original address: 0x0203380C
    DataObject("IslanderMoveProcTable", 0xA174, 0x0054, "thumb_functions", True),
    DataObject("sIslanderMoveAction11SubMoveProcs", 0xA1C8, 0x000C, "thumb_functions"),
    DataObject("sIslanderFishingSubMoveProcs", 0xA1D4, 0x0020, "thumb_functions"),
    DataObject("sIslanderReceiveItemSubMoveProcs", 0xA220, 0x000C, "thumb_functions"),
    # Original address: 0x020338C4
    DataObject("sIslanderMoodEmotions", 0xA22C, 0x000E, global_symbol=True),
    # Original address: 0x020338D2
    DataObject("sIslanderTreeActionChances", 0xA23A, 0x0008, global_symbol=True),
    DataObject("gIslanderDirectionSectors", 0xA244, 0x0020, global_symbol=True),
    DataObject("sFishingRewardGeneratorIndices", 0xA264, 0x0080),
    DataObject("sFishingRewardItemTypes", 0xA2E4, 0x0080),
    DataObject("sIslanderCollisionSampleOffsets", 0xA364, 0x0020),
    DataObject("collision_check_offsets", 0xA384, 0x0010),
    # Original address: 0x02033A2C
    DataObject("gIslanderMoveCollisionOffsets", 0xA394, 0x0040, global_symbol=True),
    DataObject("sIslanderMoveSteps", 0xA3EC, 0x0040, global_symbol=True),
    # Original address: 0x02033AC4
    DataObject("gIslanderAnimMirrorFlags", 0xA42C, 0x0063, global_symbol=True),
    DataObject("gMoveAction11ObjectAnimFrames", 0xA48F, 0x0009, global_symbol=True),
    # Original address: 0x02033B30
    DataObject("sFlyingItemFruitParams", 0xA498, 0x18, global_symbol=True),
    # Original address: 0x02033B48
    DataObject("sFlyingItemParams", 0xA4B0, 0x280, global_symbol=True),
    # Original address: 0x02033DC8
    DataObject("sFloatingItemHourOffsets", 0xA730, 0x18, global_symbol=True),
    DataObject("gMoveAction11EmotionSpawnOffsets", 0xA748, 0x0004, global_symbol=True),
    # Original address: 0x02033DE4
    DataObject("sFloatingItemBaseIndices", 0xA74C, 0xFC, global_symbol=True),
    DataObject("gMoveAction11EntitySpawnParams", 0xA848, 0x009C, global_symbol=True),
    # Original address: 0x02033F80
    DataObject("sIslanderFlowerItems", 0xA8E8, 0x12, global_symbol=True),
    # Original address: 0x02033F92
    DataObject("sIslanderRewardAdjust", 0xA8FA, 0x12, global_symbol=True),
    DataObject("gIslanderFavoriteHours", 0xA90C, 0x0012, global_symbol=True),
    DataObject("ISLANDER_FOOD_PREFERENCES", 0xA91E, 0x00AC, global_symbol=True),
    # Original address: 0x020344E8
    DataObject("sFallingFruitUpdateProcs", 0xAE50, 0x10, "thumb_functions", True),
    # Original address: 0x020344F8
    DataObject("sFallingFruitProfiles", 0xAE60, 0x228, global_symbol=True),
    # Original address: 0x020347E0
    DataObject("sEntityUpdateProcs", 0xB148, 0x2C, "thumb_functions", True),
    # Original address: 0x02034C24
    DataObject("sEntityToppleFrames", 0xB58C, 0x20, "data_pointers", True),
    # Original address: 0x02034C44
    DataObject("sEntityLeafFrames", 0xB5AC, 0x50, "data_pointers", True),
    # Original address: 0x02034CE0
    DataObject("sEntityReactionAnimations", 0xB648, 0x14, "data_pointers", True),
    DataObject("gItemGeneratorDefs", 0xB65C, 0x0098, global_symbol=True),
    # Original address: 0x02034E0C
    DataObject("sPlayerHandUpdateProcs", 0xB774, 0x18, "thumb_functions", True),
    # Original address: 0x02034ED4
    DataObject("sPlayerHandAnimations", 0xB83C, 0x10, "data_pointers", global_symbol=True),
    DataObject("time_of_day_palettes", 0xB84C, 0x00C0, global_symbol=True),
    DataObject("gMsgTextData", 0xB90C, 0x07D2),
    DataObject("sMsgOffsets", 0xC0E0, 0x007C),
    DataObject("sBgPalettes", 0xC15C, 0x0200),
    # Original address: 0x020359F4
    DataObject("sInitialObjPalette", 0xC35C, 0x200, global_symbol=True),
    # Original address: 0x02035C10
    DataObject("sSoundEffectTable", 0xC578, 0xAC, global_symbol=True),
    # Original address: 0x02035CBC
    DataObject("sMusicTable", 0xC624, 0x4, global_symbol=True),
    # Original address: 0x02035CC4
    DataObject("sPsgWaveVolume", 0xC62C, 0x5, global_symbol=True),
    # Original address: 0x02035CCC
    DataObject("sSoundInstrumentChannelTypes", 0xC634, 0x5, global_symbol=True),
    # Original address: 0x02035CD4
    DataObject("sSoundKeySampleEnvelope", 0xC63C, 0xC, global_symbol=True),
    # Original address: 0x02035CE0
    DataObject("sPsgPitchTable", 0xC648, 0xF0, global_symbol=True),
    # Original address: 0x02035DD0
    DataObject("sNoisePitchTable", 0xC738, 0x78, global_symbol=True),
    # Original address: 0x02035E48
    DataObject("sPcmPitchTable", 0xC7B0, 0x1E0, global_symbol=True),
    # Original address: 0x02036028
    DataObject("sSoundVibratoWave", 0xC990, 0x100, global_symbol=True),
)

OAM_ENTRY_ADDRESS = DATA_ADDRESS + 0x6A94
OAM_ENTRY_SIZE = 0x2668
ISLANDER_FRAME_ADDRESS = DATA_ADDRESS + 0x90FC
ISLANDER_FRAME_SIZE = 0x08E0
ISLANDER_FRAME_LIST_ADDRESS = DATA_ADDRESS + 0x99DC
ISLANDER_FRAME_LIST_SIZE = 0x060C

BSS_OBJECTS = (
    BssObject("transfer_size", 0x03000000, 0x0004, True),
    BssObject("sMsgDirtyTileOffset", 0x03000010, 0x0004),
    BssObject("sMsgDirtyTileCount", 0x03000014, 0x0004),
    BssObject("_03000018", 0x03000018, 0x0004),
    BssObject("sMsgPreviousTextRow", 0x0300001C, 0x0001),
    BssObject("sMsgPreviousTextX", 0x0300001D, 0x0001),
    BssObject("sFloatingItemIndex", 0x03000020, 0x0004),
    BssObject("sBssPadding_03000024", 0x03000024, 0x0004),
    BssObject("sCurrentSoundEffects", 0x03000028, 0x000A),
    BssObject("sBssPadding_03000032", 0x03000032, 0x0006),
    BssObject("sSoundEffectStates", 0x03000038, 0x0018),
    BssObject("sCurrentMusic", 0x03000050, 0x0002),
    BssObject("sMusicEmotion", 0x03000052, 0x0001),
    BssObject("sBssPadding_03000053", 0x03000053, 0x0005),
    BssObject("gPcmOutputBuffers", 0x03000058, 0x0008),
    BssObject("gPcmRightOutputBuffers", 0x03000060, 0x0008),
    BssObject("gSoundTimerReload", 0x03000068, 0x0002),
    BssObject("gPcmOutputBufferIndex", 0x0300006A, 0x0001),
    BssObject("gSoundDmaEnabled", 0x0300006B, 0x0001),
    BssObject("sBssPadding_0300006C", 0x0300006C, 0x0004),
    BssObject("gSoundChannelLists", 0x03000070, 0x01F4),
    BssObject("sBssPadding_03000264", 0x03000264, 0x0004),
    BssObject("sSoundKeySampleInstrument", 0x03000268, 0x0008),
    BssObject("gSoundNoteCallback", 0x03000270, 0x0004),
    BssObject("gSoundControlCallback", 0x03000274, 0x0004),
    BssObject("gSoundCommands", 0x03000278, 0x030C),
    BssObject("gSoundCommandRead", 0x03000584, 0x0004),
    BssObject("gSoundCommandWrite", 0x03000588, 0x0004),
    BssObject("gSoundCommandCommitted", 0x0300058C, 0x0004),
    BssObject("gSoundCommandEnd", 0x03000590, 0x0004),
    BssObject("gSoundBank", 0x03000594, 0x0004),
    BssObject("gPcmOutputMixer", 0x03000598, 0x0004),
    BssObject("gPcmChannelMixer", 0x0300059C, 0x0004),
    BssObject("gPcmResampleMixer", 0x030005A0, 0x0004),
    BssObject("gSoundPcmBuffers", 0x030005A4, 0x02C0),
    BssObject("gPcmMixBuffer", 0x03000864, 0x02C0),
    BssObject("gSoundTracks", 0x03000B24, 0x0540),
    BssObject("gSoundMixerCode", 0x03001064, 0x0360),
    BssObject("gPcmChannels", 0x030013C4, 0x0364),
    BssObject("gPsgChannels", 0x03001728, 0x01F0),
    BssObject("gSoundPlayers", 0x03001918, 0x0220),
    BssObject("sBssPadding_03001B38", 0x03001B38, 0x0008),
    BssObject("gIslandData", 0x03001B40, 0x0004, True),
    BssObject("gGameState", 0x03001B50, 0x0870, True),
    BssObject("gIntrTable", 0x030023C0, 0x0040, True),
    BssObject("gIslandLandInfo", 0x03002400, 0x0010, True),
    BssObject("GameOAMData", 0x03002410, 0x0400, True),
    BssObject("gFontGlyphBlitterCode", 0x03002810, 0x0160, True),
    BssObject("gIslandTransferData", 0x03002970, 0x0004, True),
    BssObject("gMsgWindowNotice", 0x03002980, 0x00A0, True),
    BssObject("sMsgWindows", 0x03002A20, 0x05A0, True),
    BssObject("gMsgWindowMain", 0x03002FC0, 0x00A0, True),
    BssObject("gMsgWindowPrompt", 0x03003060, 0x00A0, True),
    BssObject("gMsgGlyph", 0x03003100, 0x0020, True),
    BssObject("gTransWork", 0x03003120, 0x0040, True),
    BssObject("sBssPadding_03003160", 0x03003160, 0x05B0, True),
    BssObject("gIslandFieldWork", 0x03003710, 0x04A0, True),
    BssObject("gIslandBuildings", 0x03003BB0, 0x0028, True),
    BssObject("sBssPadding_03003BD8", 0x03003BD8, 0x0028, True),
    BssObject("gFieldObjects", 0x03003C00, 0x05A0, True),
    BssObject("gIslander", 0x030041A0, 0x00C0, True),
    BssObject("gFallingFruit", 0x03004260, 0x0528, True),
    BssObject("sBssPadding_03004788", 0x03004788, 0x0008, True),
    BssObject("g_EntityTable", 0x03004790, 0x03F0, True),
    BssObject("gPlayer", 0x03004B80, 0x002C, True),
)


# Additional boundaries recovered during the data.c consolidation.
DATA_OBJECTS = tuple(sorted(DATA_OBJECTS + (
    # Original address: 0x0202AADC
    DataObject("gMsgModeSetupCallbacks", 0x1444, 0x24, "thumb_functions", global_symbol=True),
    # Original address: 0x0202AB00
    DataObject("gMsgModeCallbacks", 0x1468, 0x24, "thumb_functions", global_symbol=True),
    # Original address: 0x0202AFCC
    DataObject("sIslandProgramNoticeEnterProcs", 0x1934, 0x10, "thumb_functions", global_symbol=True),
    # Original address: 0x0202AFEC
    DataObject("sIslandProgramSleepEnterProcs", 0x1954, 0x10, "thumb_functions", global_symbol=True),
    # Original address: 0x0202B00C
    DataObject("sNoticeResultMessages", 0x1974, 0x8, global_symbol=True),
    # Original address: 0x0202B284
    DataObject("sIslandProgramTransferEnterProcs", 0x1BEC, 0x1C, "thumb_functions", global_symbol=True),
    # Original address: 0x0202B2EC
    DataObject("mMsg_null_sprite_profile", 0x1C54, 0x10, global_symbol=True),
    # Original address: 0x0202B330
    DataObject("mMsg_continue_prompt_sprite_profile", 0x1C98, 0x10, "thumb_functions", global_symbol=True),
    # Original address: 0x0202B340
    DataObject("sContinuePromptAnimOamData", 0x1CA8, 0x28, global_symbol=True),
    # Original address: 0x0202B368
    DataObject("sMsgContinuePromptAnimData", 0x1CD0, 0x10, "animation_frames", global_symbol=True),
    # Original address: 0x0202B37C
    DataObject("sMsgContinuePromptRed", 0x1CE4, 8, global_symbol=True),
    # Original address: 0x0202B384
    DataObject("sMsgContinuePromptGreen", 0x1CEC, 8, global_symbol=True),
    # Original address: 0x0202B38C
    DataObject("sMsgContinuePromptBlue", 0x1CF4, 8, global_symbol=True),
    # Original address: 0x0202B394
    DataObject("mMsg_choice_cursor_sprite_profile", 0x1CFC, 0x10, "thumb_functions", global_symbol=True),
    # Original address: 0x0202B3A4
    DataObject("sMsgChoiceCursorAnimOamData", 0x1D0C, 0x28, global_symbol=True),
    # Original address: 0x0202B3CC
    DataObject("sMsgChoiceCursorAnimData", 0x1D34, 0x10, "animation_frames", global_symbol=True),
    # Original address: 0x0202B3E0
    DataObject("multi_sio_ver", 0x1D48, 0x19),
    # Original address: 0x0202FD15
    DataObject("sData_0202FD15", 0x667D, 0x1, global_symbol=True),
    # Original address: 0x0202FD38
    DataObject("gIslandBuildingProcs", 0x66A0, 0x8, "thumb_functions", global_symbol=True),
    # Original address: 0x0202FECC
    DataObject("gFieldObjectProcs", 0x6834, 0x14, "thumb_functions", global_symbol=True),
    # Original address: 0x0203388C
    DataObject("IslanderSubMoveAction_BuryProcTbl", 0xA1F4, 0x18, "thumb_functions", global_symbol=True),
    # Original address: 0x020338A4
    DataObject("sIslanderMoveAction20SubMoveProcs", 0xA20C, 0x14, "thumb_functions", global_symbol=True),
    # Original address: 0x020338DA
    DataObject("sData_020338DA", 0xA242, 0x2, global_symbol=True),
    # Original address: 0x02033A6C
    DataObject("gBuriedItemUpdateGroups", 0xA3D4, 0x18, global_symbol=True),
    # Original address: 0x02033F7C
    DataObject("sData_02033F7C", 0xA8E4, 0x4, global_symbol=True),
    # Original address: 0x02034062
    DataObject("gBuriedItemRngTileGroups", 0xA9CA, 0x82, global_symbol=True),
    # Original address: 0x020340E4
    DataObject("gBuriedItemGeneratorIndices", 0xAA4C, 0x120, global_symbol=True),
    # Original address: 0x02034204
    DataObject("Item_TypeEntries", 0xAB6C, 0x2C0, "item_type_entries", global_symbol=True),
    # Original address: 0x020344C4
    DataObject("gc_rsv_island_item_table", 0xAE2C, 0x24, global_symbol=True),
    # Original address: 0x02034720
    DataObject("sEntityReactionOamData", 0xB088, 0xC0, global_symbol=True),
    # Original address: 0x0203480C
    DataObject("sEntityToppleOamData", 0xB174, 0x180, global_symbol=True),
    # Original address: 0x0203498C
    DataObject("sEntityLeafOamData", 0xB2F4, 0x140, global_symbol=True),
    # Original address: 0x02034ACC
    DataObject("sEntityMainAnimFrames", 0xB434, 0xE0, "animation_frames", True),
    # Original address: 0x02034BAC
    DataObject("sEntityReactionAnimFrames", 0xB514, 0x78, "animation_frames", True),
    # Original address: 0x02034C94
    DataObject("sEntityReactionAnimation0", 0xB5FC, 0x14, "data_pointers", True),
    # Original address: 0x02034CA8
    DataObject("sEntityReactionAnimation1", 0xB610, 0x10, "data_pointers", True),
    # Original address: 0x02034CB8
    DataObject("sEntityReactionAnimation2", 0xB620, 0xC, "data_pointers", True),
    # Original address: 0x02034CC4
    DataObject("sEntityReactionAnimation3", 0xB62C, 0x14, "data_pointers", True),
    # Original address: 0x02034CD8
    DataObject("sEntityReactionAnimation4", 0xB640, 0x8, "data_pointers", True),
    # Original address: 0x02034D8C
    DataObject("sPlayerHandOamData", 0xB6F4, 0x80, global_symbol=True),
    # Original address: 0x02034E24
    DataObject("sPlayerHandAnimFrames", 0xB78C, 0x58, "animation_frames", global_symbol=True),
    # Original address: 0x02034E7C
    DataObject("sPlayerHandIdleAnimation", 0xB7E4, 0x20, "data_pointers", global_symbol=True),
    # Original address: 0x02034E9C
    DataObject("sPlayerHandCarryingAnimation", 0xB804, 0x18, "data_pointers", global_symbol=True),
    # Original address: 0x02034EB4
    DataObject("sPlayerHandPlacingAnimation", 0xB81C, 0x14, "data_pointers", global_symbol=True),
    # Original address: 0x02034EC8
    DataObject("sPlayerHandBlockedAnimation", 0xB830, 0xC, "data_pointers", global_symbol=True),
    # Original address: 0x02035BF4
    DataObject("sSoundBank", 0xC55C, 0x1C, "data_pointers", True),
    # Original address: 0x02035CC0
    DataObject("sData_02035CC0", 0xC628, 0x4, global_symbol=True),
    # Original address: 0x02035CC9
    DataObject("sData_02035CC9", 0xC631, 0x3, global_symbol=True),
    # Original address: 0x02035CD1
    DataObject("sData_02035CD1", 0xC639, 0x3, global_symbol=True),
    # Original address: 0x02036128
    DataObject("sound_data", 0xCA90, 0x3BFC, global_symbol=True),
), key=lambda obj: obj.offset))

def read_elf_sections(data: bytes) -> list[ElfSection]:
    if len(data) < ELF_HEADER_SIZE or data[:4] != b"\x7fELF":
        raise ValueError("text object is not an ELF file")
    if data[4] != ELFCLASS32 or data[5] != ELFDATA2LSB:
        raise ValueError("only 32-bit little-endian ELF files are supported")
    machine = struct.unpack_from("<H", data, 18)[0]
    if machine != EM_ARM:
        raise ValueError(f"expected an ARM ELF object, found e_machine={machine}")

    section_offset = struct.unpack_from("<I", data, 32)[0]
    section_entry_size, section_count = struct.unpack_from("<HH", data, 46)
    if section_entry_size < 40:
        raise ValueError(f"invalid ELF32 section-header size {section_entry_size}")

    sections: list[ElfSection] = []
    for index in range(section_count):
        offset = section_offset + index * section_entry_size
        if offset + 40 > len(data):
            raise ValueError("section-header table extends beyond the text object")
        fields = struct.unpack_from("<IIIIIIIIII", data, offset)
        sections.append(
            ElfSection(
                section_type=fields[1],
                offset=fields[4],
                size=fields[5],
                link=fields[6],
                entry_size=fields[9],
            )
        )
    return sections


def read_c_string(data: bytes, offset: int, limit: int) -> str:
    end = data.find(b"\0", offset, limit)
    if end < 0:
        raise ValueError("unterminated ELF string-table entry")
    return data[offset:end].decode("ascii")


def read_thumb_functions(path: Path) -> dict[int, str]:
    data = path.read_bytes()
    sections = read_elf_sections(data)
    functions: dict[int, str] = {}

    for symbol_table in (section for section in sections if section.section_type == SHT_SYMTAB):
        if symbol_table.link >= len(sections):
            raise ValueError("symbol table has an invalid string-table link")
        string_table = sections[symbol_table.link]
        string_end = string_table.offset + string_table.size
        entry_size = symbol_table.entry_size or 16
        if entry_size < 16:
            raise ValueError(f"invalid ELF32 symbol size {entry_size}")

        for relative_offset in range(0, symbol_table.size, entry_size):
            symbol_offset = symbol_table.offset + relative_offset
            if symbol_offset + 16 > len(data):
                raise ValueError("symbol table extends beyond the text object")
            name_offset, value, _, info, _, section_index = struct.unpack_from(
                "<IIIBBH", data, symbol_offset
            )
            if info & 0xF != STT_FUNC or section_index == 0 or name_offset == 0:
                continue
            name = read_c_string(
                data, string_table.offset + name_offset, string_end
            )
            pointer = TEXT_ADDRESS + (value & ~1) | 1
            old_name = functions.setdefault(pointer, name)
            if old_name != name:
                raise ValueError(
                    f"multiple function names at 0x{pointer:08X}: {old_name}, {name}"
                )

    if not functions:
        raise ValueError("no Thumb function symbols found in the text object")
    return functions


def quote_incbin_path(path: Path) -> str:
    return path.as_posix().replace('"', '\\"')


def emit_incbin(lines: list[str], path: str, offset: int, size: int) -> None:
    if size:
        lines.append(f'    .incbin "{path}", 0x{offset:X}, 0x{size:X}')


def emit_symbol_header(lines: list[str], name: str, global_symbol: bool) -> None:
    directive = ".global" if global_symbol else ".local"
    lines.extend((f"{directive} {name}", f".type {name}, %object", f"{name}:"))


def emit_islander_pointer(
    lines: list[str],
    pointer: int,
    target_address: int,
    target_size: int,
    target_symbol: str,
) -> None:
    if not target_address <= pointer < target_address + target_size:
        raise ValueError(
            f"pointer 0x{pointer:08X} is outside {target_symbol}"
        )
    addend = pointer - target_address
    if addend % 4:
        raise ValueError(
            f"pointer 0x{pointer:08X} has an unaligned {target_symbol} addend"
        )
    lines.append(f"    .4byte {target_symbol} + 0x{addend:X}")


def emit_data_object(
    lines: list[str], obj: DataObject, data: bytes,
    functions: dict[int, str], incbin_path: str,
) -> None:
        if obj.relocation_kind in ("thumb_functions", "item_type_entries"):
            stride = 8 if obj.relocation_kind == "item_type_entries" else 4
            if obj.size % 4:
                raise ValueError(f"pointer table {obj.name} is not word-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, stride):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                if pointer == 0:
                    lines.append("    .4byte 0")
                    if stride == 8:
                        emit_incbin(lines, incbin_path, pointer_offset + 4, 4)
                    continue
                try:
                    function_name = functions[pointer]
                except KeyError as error:
                    raise ValueError(
                        f"{obj.name} contains unknown code pointer 0x{pointer:08X} "
                        f"at target address 0x{DATA_ADDRESS + pointer_offset:08X}"
                    ) from error
                lines.append(f"    .4byte {function_name}")
                if stride == 8:
                    emit_incbin(lines, incbin_path, pointer_offset + 4, 4)
        elif obj.relocation_kind in ("data_pointers", "animation_frames"):
            stride = 8 if obj.relocation_kind == "animation_frames" else 4
            if obj.size % stride:
                raise ValueError(f"pointer table {obj.name} is not record-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, stride):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                if pointer == 0 or (stride == 8 and pointer == 0xFFFF):
                    lines.append(f"    .4byte 0x{pointer:X}")
                else:
                    target = next((entry for entry in DATA_OBJECTS
                                   if DATA_ADDRESS + entry.offset <= pointer <
                                   DATA_ADDRESS + entry.offset + entry.size), None)
                    if target is None:
                        raise ValueError(f"{obj.name} contains unknown data pointer 0x{pointer:08X}")
                    addend = pointer - (DATA_ADDRESS + target.offset)
                    if addend:
                        lines.append(f"    .4byte {target.name} + 0x{addend:X}")
                    else:
                        lines.append(f"    .4byte {target.name}")
                if stride == 8:
                    emit_incbin(lines, incbin_path, pointer_offset + 4, 4)
        elif obj.relocation_kind == "choice_tiles":
            address, symbol = ((0x0200F580, "gMsgWindowTileData") if obj.size == 8
                               else (0x020147E0, "gMsgThreeChoiceTileData"))
            for offset in range(obj.offset, obj.offset + obj.size, 4):
                pointer = struct.unpack_from("<I", data, offset)[0]
                lines.append(f"    .4byte {symbol} + 0x{pointer - address:X}")
        elif obj.relocation_kind == "islander_frames":
            if obj.size % 8:
                raise ValueError(f"frame table {obj.name} is not record-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, 8):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                if pointer == 0xFFFF:
                    lines.append("    .4byte 0xFFFF")
                else:
                    emit_islander_pointer(
                        lines,
                        pointer,
                        OAM_ENTRY_ADDRESS,
                        OAM_ENTRY_SIZE,
                        "sOAMData",
                    )
                emit_incbin(lines, incbin_path, pointer_offset + 4, 4)
        elif obj.relocation_kind == "islander_frame_list":
            if obj.size % 4:
                raise ValueError(f"frame-list table {obj.name} is not word-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, 4):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                emit_islander_pointer(
                    lines,
                    pointer,
                    ISLANDER_FRAME_ADDRESS,
                    ISLANDER_FRAME_SIZE,
                    "sIslanderAnimFrames",
                )
        elif obj.relocation_kind == "islander_anim_table":
            if obj.size % 4:
                raise ValueError(f"animation table {obj.name} is not word-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, 4):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                emit_islander_pointer(
                    lines,
                    pointer,
                    ISLANDER_FRAME_LIST_ADDRESS,
                    ISLANDER_FRAME_LIST_SIZE,
                    "sIslanderAnimFrameLists",
                )
        elif obj.relocation_kind is not None:
            raise ValueError(
                f"unknown relocation kind {obj.relocation_kind!r} for {obj.name}"
            )
        else:
            emit_incbin(lines, incbin_path, obj.offset, obj.size)
        lines.append(f".size {obj.name}, 0x{obj.size:X}")


def emit_data_range(
    lines: list[str], section: str, start: int, end: int, data: bytes,
    functions: dict[int, str], incbin_path: str,
) -> int:
    lines.extend(("", f'.section {section}, "a{("w" if section == ".data" else "")}", %progbits', ".balign 4"))
    selected = [obj for obj in DATA_OBJECTS
                if start <= obj.offset and obj.offset + obj.size <= end]
    if any(obj.offset < start or obj.offset + obj.size > end
           for obj in DATA_OBJECTS
           if obj.offset < end and obj.offset + obj.size > start):
        raise ValueError(f"data object crosses {section} range 0x{start:X}-0x{end:X}")
    cursor = start
    for obj in selected:
        if obj.offset < cursor:
            raise ValueError(f"invalid or overlapping data object {obj.name}")
        emit_incbin(lines, incbin_path, cursor, obj.offset - cursor)
        emit_symbol_header(lines, obj.name, obj.global_symbol)
        emit_data_object(lines, obj, data, functions, incbin_path)
        cursor = obj.offset + obj.size
    emit_incbin(lines, incbin_path, cursor, end - cursor)
    return len(selected)


def emit_bss_range(lines: list[str], start: int, end: int) -> int:
    lines.extend(("", '.section .bss, "aw", %nobits', ".balign 4"))
    selected = [obj for obj in BSS_OBJECTS
                if start <= obj.address - IWRAM_ADDRESS and
                obj.address - IWRAM_ADDRESS + obj.size <= end]
    cursor = start
    for obj in selected:
        offset = obj.address - IWRAM_ADDRESS
        if offset < cursor:
            raise ValueError(f"invalid or overlapping BSS object {obj.name}")
        if offset > cursor:
            lines.append(f"    .space 0x{offset - cursor:X}")
        emit_symbol_header(lines, obj.name, obj.global_symbol)
        lines.append(f"    .space 0x{obj.size:X}")
        lines.append(f".size {obj.name}, 0x{obj.size:X}")
        cursor = offset + obj.size
    if cursor < end:
        lines.append(f"    .space 0x{end - cursor:X}")
    return len(selected)


def generate_assembly(text_object: Path, data_path: Path, unit: str | None = None) -> tuple[str, int, int]:
    data = data_path.read_bytes()
    if len(data) != EXPECTED_DATA_SIZE:
        raise ValueError(
            f"expected data blob size 0x{EXPECTED_DATA_SIZE:X}, found 0x{len(data):X}"
        )
    functions = read_thumb_functions(text_object)
    incbin_path = quote_incbin_path(data_path)
    lines = [
        "@ Generated by tools/generate_objdiff_sections.py. Do not edit.",
        ".syntax unified",
    ]

    data_count = 0
    bss_count = 0
    if unit is None:
        data_count += emit_data_range(
            lines, ".data", 0, len(data), data, functions, incbin_path
        )
        bss_count += emit_bss_range(lines, 0, max(
            obj.address + obj.size for obj in BSS_OBJECTS
        ) - IWRAM_ADDRESS)
    else:
        for section, start, end in UNIT_DATA_RANGES.get(unit, ()):
            data_count += emit_data_range(
                lines, section, start, end, data, functions, incbin_path
            )
        if unit in UNIT_BSS_RANGES:
            bss_count += emit_bss_range(lines, *UNIT_BSS_RANGES[unit])

    lines.append("")
    return "\n".join(lines), data_count, bss_count


def build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--text-object",
        type=Path,
        default=Path("payload/build/payload/asm/all.o"),
    )
    parser.add_argument(
        "--data",
        type=Path,
        default=Path("payload/data/data.bin"),
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("payload/build/objdiff/all.data.target.s"),
    )
    parser.add_argument(
        "--unit",
        choices=sorted(set(UNIT_DATA_RANGES) | set(UNIT_BSS_RANGES)),
        help="generate section-relative data/BSS for one translation unit",
    )
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    output, data_count, bss_count = generate_assembly(args.text_object, args.data, args.unit)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    if not args.output.exists() or args.output.read_text(encoding="ascii") != output:
        args.output.write_text(output, encoding="ascii", newline="\n")
    print(
        f"Generated {args.output}: {data_count} data symbols and "
        f"{bss_count} BSS symbols"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
