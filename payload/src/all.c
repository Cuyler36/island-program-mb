#include "global.h"
#include "m_name_table.h"
#include <string.h>

/* Original address: 0x0202AAC8 */
extern void *gMsgTwoChoiceHighlightTiles[2];
/* Original address: 0x0202AAD0 */
extern void *gMsgThreeChoiceHighlightTiles[3];
/* Original address: 0x0202AFBC */
extern u32 sJoybootGbaHandshake;
/* Original address: 0x0202AFC4 */
extern u32 sJoybootGameCubeHandshake;
/* Original address: 0x0202B00C */
extern s32 sNoticeResultMessages[2];

/* Original address: 0x0202B014 */
extern const u16 sTimeOfDayPalette2Table[24][8];
/* Original address: 0x0202B194 */
extern const u16 sTimeOfDayPalette3Table[24][5];

/* sizeof(IslandBuildingSprite) == 0x14. */
typedef struct IslandBuildingSprite {
    /* 0x00 */ u32 oam_attributes;
    /* 0x04 */ s32 y_offset;
    /* 0x08 */ s32 x_offset;
    /* 0x0C */ u16 tile_num;
    /* 0x0E */ u8 palette_num;
    /* 0x0F */ u8 h_flip;
    /* 0x10 */ u8 v_flip;
    /* 0x11 */ u8 pad_11[3];
} IslandBuildingSprite;

/* sizeof(AnimatedFieldObject) == 0x0C. */
typedef struct AnimatedFieldObject {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u8 anim_timer;
    /* 0x09 */ u8 anim_frame;
    /* 0x0A */ u8 pad_0A[2];
} AnimatedFieldObject;

/* Original address: 0x0202FD40 */
extern IslandBuildingSprite sIslandBuildingSprites[6];
/* Original address: 0x03003BF0 */
extern AnimatedFieldObject gAnimatedFieldObjects[];
/* Original address: 0x0202FEB0 */
extern AnimFrameData *sFieldAnimationFrames[7];
/* sizeof(FallingFruit) == 0x2C. */
typedef struct FallingFruit {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 height;
    /* 0x0C */ s32 landing_y;
    /* 0x10 */ s32 landing_x;
    /* 0x14 */ s32 origin_y;
    /* 0x18 */ s32 velocity_y;
    /* 0x1C */ s32 gravity;
    /* 0x20 */ u16 tile_idx;
    /* 0x22 */ u8 state;
    /* 0x23 */ u8 type;
    /* 0x24 */ u8 anim_frame;
    /* 0x25 */ u8 acre;
    /* 0x26 */ u8 timer;
    /* 0x27 */ u8 sound_played;
    /* 0x28 */ u8 can_land;
    /* 0x29 */ u8 pad_29[3];
} FallingFruit;

/* Original address: 0x03004260 */
extern FallingFruit gFallingFruit[30];
/* sizeof(FallingFruitProfile) == 0x18. */
typedef struct FallingFruitProfile {
    /* 0x00 */ u32 oam_attributes;
    /* 0x04 */ s32 y_offset;
    /* 0x08 */ s32 x_offset;
    /* 0x0C */ u16 sprite_tile;
    /* 0x0E */ u16 ground_tile;
    /* 0x10 */ mActor_name_t item;
    /* 0x12 */ u8 palette;
    /* 0x13 */ u8 h_flip;
    /* 0x14 */ u8 field_tile;
    /* 0x15 */ u8 pad_15[3];
} FallingFruitProfile;

/* Original address: 0x020344E8 */
extern void (*sFallingFruitUpdateProcs[4])(s32);
/* Original address: 0x020344F8 */
extern FallingFruitProfile sFallingFruitProfiles[23];
/* Original address: 0x020300F8 */
extern u8 sFruitDropOffsetsX[3][4];
/* Original address: 0x02030104 */
extern u8 sFruitDropOffsetsY[3][4];
/* Original address: 0x02030110 */
extern u8 sFieldObjectInitialTimers[19];
/* Original address: 0x02030123 */
extern u8 sFieldObjectShakeFrames[9];


/* Original address: 0x02034C24 */
extern AnimFrameData *sEntityToppleFrames[8];
/* Original address: 0x02034C44 */
extern AnimFrameData *sEntityLeafFrames[20];
/* Original address: 0x02034CE0 */
extern AnimFrameData **sEntityReactionAnimations[5];
/* Original address: 0x02034E0C */
extern void (*sPlayerHandUpdateProcs[6])(void);
/* Original address: 0x020347E0 */
extern void (*sEntityUpdateProcs[11])(s32);
/* Original address: 0x0202AD34 */
extern const s16 sSineTable[320];

/* Original address: 0x03003250 */
extern m_msg_sprite_c gMsgSprites[12];
/* Original address: 0x0202B2FC */
extern mMsg_SpriteProfile* sMsgSpriteProfiles[13];

/* Original address: 0x0203E9A0 */
extern u16 gIslandDataReceived;

/* Original address: 0x0202B3FC */
extern const u16 sIslandRightAcreTilemaps[4][1024];
/* Original address: 0x0202D3FC */
extern const u16 sIslandLeftAcreTilemaps[4][1024];
/* Original address: 0x0202FC1C */
extern const u16 sCabanaTilemap[64];
/* Original address: 0x0202FC9C */
extern const u16 sIslanderHouseTilemap[48];
/* Original address: 0x0202FCFC */
extern const u8 sCabanaFootprint[16];
/* Original address: 0x0202FD0C */
extern const u8 sIslanderHouseFootprint[9];
/* Original address: 0x0202FD16 */
extern const u16 sFieldEntityBaseTiles[9];

/* Serial island exchange work; sizeof(IslandLinkWork) == 0x38. */
typedef struct IslandLinkWork {
    /* 0x00 */ u8 master;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 connected_players;
    /* 0x03 */ u8 checksum_ok;
    /* 0x04 */ u8 checksum_bad;
    /* 0x05 */ u8 _05[3];
    /* 0x08 */ u16* send_data;
    /* 0x0C */ u16* receive_data;
    /* 0x10 */ s32 send_index;
    /* 0x14 */ s32 receive_index;
    /* 0x18 */ s32 send_packet_index;
    /* 0x1C */ s32 receive_packet_index;
    /* 0x20 */ s32 timeout;
    /* 0x24 */ u16 received_checksum;
    /* 0x26 */ u16 receive_packet_checksum;
    /* 0x28 */ u16 send_packet_checksum;
    /* 0x2A */ u16 send_checksum;
    /* 0x2C */ u16 receive_checksum;
    /* 0x2E */ s16 checksum_index;
    /* 0x30 */ s8 result;
    /* 0x31 */ u8 packet_error;
    /* 0x32 */ u8 serial_error;
    /* 0x33 */ u8 handshake_delay;
    /* 0x34 */ u8 send_handshake;
    /* 0x35 */ u8 _35[3];
} IslandLinkWork;

/* Original address: 0x030036D0 */
extern IslandLinkWork gIslandLinkWork;
/* Original address: 0x03002970 */
extern Island_agb_c* gIslandTransferData;

/* Word access also includes the adjacent multiplayer send register. */
#define ISLAND_SERIAL_WORD (*(vu32*)REG_ADDR_SIOCNT)
#define ISLAND_LINK_HALFWORDS 0x1CC0

typedef union IslandSerialStatus {
    u32 word;
    struct {
        u32 baud_rate : 2;
        u32 slave : 1;
        u32 ready : 1;
        u32 player_id : 2;
        u32 error : 1;
        u32 busy : 1;
        u32 _08 : 4;
        u32 mode : 2;
        u32 irq_enable : 1;
        u32 _0F : 17;
    } bits;
} IslandSerialStatus;

#define ISLAND_SERIAL_STATUS (*(volatile IslandSerialStatus*)REG_ADDR_SIOCNT)

void IslandProgram_Main();                                   /* extern */
void SoundDriver_DisablePcm();                                   /* extern */
extern u8 sub_02029004[];
extern u8 sub_020290C4[];
extern u8 sub_020291E4[];

extern int transfer_size;
extern int sMsgDirtyTileOffset;
extern int sMsgDirtyTileCount;
extern int _03000018; // ??
extern u8 sMsgPreviousTextRow;
extern u8 sMsgPreviousTextX;

#define gTransWork gTransmissionBuf_p

/* Original address: 0x03001B50 */
extern GameState gGameState;

/* Original address: 0x03002400 */
extern mISL_landinfo_agb_c gIslandLandInfo;

/* Original address: 0x03003710 */
extern IslandFieldWork gIslandFieldWork;
extern IslandBuilding gIslandBuildings[ISLAND_BUILDING_COUNT]; // @0x03003BB0
extern FieldObject gFieldObjects[FIELD_OBJECT_COUNT]; // @0x03003C00
extern Islander_AGB gIslander; // @0x030041A0
/* Original address: 0x03004790 */
extern Entity g_EntityTable[12];
extern Player gPlayer; // @0x03004B80
/* Original address: 0x03001B40 */
extern Island_agb_c* gIslandData;

void AgbMain(void) {
    InitializeHardware();
    transfer_size = sizeof(Island_agb_c);
    IslandProgram_Main();
}

/* Original address: 0x02018228 */
void UnusedInterruptHandler(void) {
    // nothing
}

extern u8 gUnk3002410[0x400];

/* Original address: 0x0201822C */
void VBlankInterruptHandler(void) {
    u8 temp_r5;
    u16 temp;

    GameAudio_VBlank();
    if (gGameState.pcm_disable_pending == 1) {
        gGameState.pcm_disable_pending = 0;
        SoundDriver_DisablePcm();
    }
    temp_r5 = gGameState.frame_committed;
    if (temp_r5 == 0) {
        CpuFastCopy(gUnk3002410, (void*)OAM, sizeof(gUnk3002410));
        REG_DISPCNT = gGameState.dispcnt;
        REG_BG0HOFS = gGameState.bg0_hofs;
        REG_BG0VOFS = gGameState.bg0_vofs;
        REG_BG1HOFS = gGameState.bg1_hofs;
        REG_BG1VOFS = gGameState.bg1_vofs;
        REG_BG2HOFS = gGameState.bg2_hofs;
        REG_BG2VOFS = gGameState.bg2_vofs;
        REG_BG3HOFS = gGameState.bg3_hofs;
        REG_BG3VOFS = gGameState.bg3_vofs;
        REG_BLDALPHA = gGameState.bldalpha;
        REG_BLDY = gGameState.bldy;
        REG_BLDCNT = gGameState.bldcnt;
        REG_BG0CNT = gGameState.bg0cnt;
        REG_BG1CNT = gGameState.bg1cnt;
        REG_BG2CNT = gGameState.bg2cnt;
        REG_BG3CNT = gGameState.bg3cnt;

        if (gGameState.vblank_latch == 1) {
            gGameState.vblank_latch = temp_r5;
        }

        gGameState.vblank_counter++;
        gGameState.frame_committed = 1;
    }

    REG_IF = gGameState.vblank_flags = 1;
    REG_DISPSTAT = 8;
    GameAudio_UpdateDriver();
}

/* Original address: 0x02018364 */
void HBlankInterruptHandler(void) {
    // nothing
}

/* Original address: 0x02018368 */
void VCountInterruptHandler(void) {
    // nothing
}

extern u8 sMsgGlyphWidths[256];

extern u8 sFontCodeWidths[256];

extern u8 sMsgFontGlyphs[16][2][16][8];

extern u8 sMsgSpaceGlyph[2][8];

extern int sCachedMessageIds[9];
extern mMsg_Window_c sMsgWindow_03002980; // @0x03002980
extern mMsg_Window_c sMsgWindows[9]; // @0x03002A20
extern mMsg_Window_c sMsgWindow_03002fc0; // @0x03002FC0
extern mMsg_Window_c sMsgWindow_03003060; // @0x03003060

/* Original address: 0x0201836C */
void mFont_GetGlyphRows(void* lower_rows, void* upper_rows, u8 character) {
    union {
        u64 packed;
        u8 rows[8];
    } lower, upper;
    u8* lower_dest;
    u32 glyph_offset;
    s32 i;

    lower.packed = *(u64*)lower_rows;
    upper.packed = *(u64*)upper_rows;

    if ((character == CHAR_CONTROL_CODE) || (character == 0x80) ||
        (character == CHAR_NEW_LINE)) {
        *(u64*)lower_rows = 0;
        *(u64*)upper_rows = 0;
        return;
    }

    /* Each 16-character block stores the upper tiles before the lower tiles. */
    glyph_offset = ((character >> 4) * 32 + (character & 0xF)) * 8;
    lower_dest = lower.rows;
    for (i = 0; i < 8; i++) {
        if (character != 0x20) {
            upper.rows[i] = ((u8*)sMsgFontGlyphs)[glyph_offset + i];
            lower_dest[i] = ((u8*)sMsgFontGlyphs + sizeof(sMsgFontGlyphs[0][0]))[glyph_offset + i];
        } else {
            upper.rows[i] = sMsgSpaceGlyph[0][i];
            lower_dest[i] = sMsgSpaceGlyph[1][i];
        }
    }

    *(u64*)lower_rows = lower.packed;
    *(u64*)upper_rows = upper.packed;
}

int mFont_GetGlyphWidth(u32 c) {
    if (c < 0x100) {
        return sMsgGlyphWidths[c];
    }
    return -1;
}

int mFont_GetCodeWidth(u32 c) {
    if (c < 0x100) {
        return sFontCodeWidths[c];
    }
    return -1;
}

void mMsg_MainSetup_Hide(mMsg_Window_c* msg) {
    mMsg_InitWindow(msg, msg->text, msg->tile_data);
}

void mMsg_Main_Hide(mMsg_Window_c* msg) {
    mMsg_MainSetup_Window(msg);
}

void mMsg_MainSetup_Appear(mMsg_Window_c* msg) {
    msg->message_length = mMsg_LoadMessage(msg->text, msg->next_message_id);
    if (msg->message_length > 0) {
        msg->draw_enabled = 1;
        msg->message_id = msg->next_message_id;
        msg->next_message_id = -1;
        msg->current_mode = msg->requested_mode;
        msg->requested_mode = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        GameAudio_PlayEffect0(0x1F);
    }
}

void mMsg_Main_Appear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);

    if (msg->transition_frame > 10 && mMsg_RequestCursor(msg) != 0) {
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame++;
    }
}

int mMsg_Cont_SetNextMessage(mMsg_Window_c* msg, s16* offset, int choice) {
    u32 message_id = (*(msg->text + *offset + 2) << 8) | *(msg->text + *offset + 3);

    if (choice == 0xFF || choice == msg->choice_index) {
        if (message_id <= 30) {
            msg->next_message_id = message_id;
        } else {
            msg->cancel_continue = 1;
        }
    }

    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_SetChoiceCount(mMsg_Window_c* msg, s16* offset, int count) {
    msg->choice_count = count;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 4;
}

int mMsg_Cont_SetChoiceText(mMsg_Window_c* msg, s16* offset, int index) {
    mMsg_ChoiceEntry_c* choice = &msg->choices[index];

    choice->length = *(msg->text + *offset + 2);
    mMsg_Copy(msg->text + *offset + 3, choice->text, choice->length);
    choice->line = msg->text_row;
    choice->x = msg->text_x;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_Last(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Continue(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Clear(mMsg_Window_c* msg, s16* offset) {
    mMsg_ClearText(msg);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Button(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        *offset += mFont_CodeSize_get(msg->text + *offset);
        return 2;
    }
}

int mMsg_Cont_SetNextMessageF(mMsg_Window_c* msg, s16* offset) {
    msg->force_next = 1;
    return mMsg_Cont_SetNextMessage(msg, offset, 0xFF);
}

int mMsg_Cont_SetNextMessage0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 0);
}

int mMsg_Cont_SetNextMessage1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 1);
}

int mMsg_Cont_SetTemporaryColor(mMsg_Window_c* msg, s16* offset) {
    msg->temporary_color_length = *(msg->text + *offset + 3);
    msg->temporary_color = *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Space(mMsg_Window_c* msg, s16* offset) {
    msg->text_x += *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_MoveDown(mMsg_Window_c* msg, s16* offset) {
    msg->text_row++;
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_RestoreCachedMessage(mMsg_Window_c* msg, s16* offset) {
    int i;
    for (i = 0; i < ARRAY_COUNT(sCachedMessageIds); i++) {
        if (sCachedMessageIds[i] == msg->message_id && &sMsgWindows[i] != msg) {
            u8* tile_data = msg->tile_data;
            u8* text = msg->text;
            u8 selected_choice = msg->selected_choice;

            CpuFastCopy(&sMsgWindows[i], msg, sizeof(mMsg_Window_c));
            msg->tile_data = tile_data;
            msg->text = text;
            msg->selected_choice = selected_choice;
            msg->draw_enabled = 1;
            mMsg_Copy(sMsgWindows[i].text, msg->text, msg->message_length);
            CpuFastCopy(sMsgWindows[i].tile_data, msg->tile_data, 0x1200);
            mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
            break;
        }
    }

    if (i == ARRAY_COUNT(sCachedMessageIds)) {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return 1;
}

int mMsg_Cont_SetChoiceCount2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 2);
}

int mMsg_Cont_SetChoiceCount3(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 3);
}

int mMsg_Cont_SetChoiceText0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 0);
}

int mMsg_Cont_SetChoiceText1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 1);
}

int mMsg_Cont_SetChoiceText2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 2);
}

int mMsg_Cont_CheckChoice(mMsg_Window_c* msg, s16* offset) {
    int ret = 3;

    if (*(msg->text + *offset + 2) == msg->choice_index + 1) {
        ret = 2;
    } else {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return ret;
}

int mMsg_Cont_SoundTrgSys(mMsg_Window_c* msg, s16* offset) {
    u8 sound = *(msg->text + *offset + 2);

    if (sound == 7 || sound == 8) {
        GameAudio_PlayEffect0(sound == 7 ? 0x10 : 0x02);
    }

    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 3;
}

/**
 * @brief Dummy procedure for control codes that don't do anything on GBA.
 * @param msg Pointer to the message structure.
 * @param ofs_p Pointer to the offset in the message code.
 * @return 1.
 */
int mMsg_Cont_Noop(mMsg_Window_c* msg, s16* offset) {
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

typedef int (*mMsg_CONTROL_CODE_PROC)(mMsg_Window_c* msg, s16* offset);

extern mMsg_CONTROL_CODE_PROC sMsgControlCodeHandlers[];

// @0x0201892c
/* Ghidra name: Msg_ProcessControlCode (differs from the existing contextual name). */
int mMsg_ProcessControlCode(mMsg_Window_c* msg, s16* offset) {
    int ret = 1;
    u8 code = msg->text[*offset];
    u8 type = msg->text[*offset + 1];
    
    if (code == CHAR_CONTROL_CODE && type <= mFont_CONT_CODE_CHECK_CHOICE) {
        ret = sMsgControlCodeHandlers[type](msg, offset);
    }

    return ret;
}

void mMsg_MainSetup_Cursor(mMsg_Window_c* msg) {
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Cursor(mMsg_Window_c* msg) {
    int process_res;
    u8 res;
    int i;

    sMsgPreviousTextRow = msg->text_row;
    sMsgPreviousTextX = msg->text_x;
    
    process_res = mMsg_ProcessText(msg, msg->tile_data, 1);
    switch (process_res) {
        case 4:
            res = mMsg_RequestChoice(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
        case 2:
            res = mMsg_RequestNormal(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
    }

    for (i = sMsgPreviousTextRow; sMsgPreviousTextRow < msg->text_row; i++) {
        int temp;

        sMsgDirtyTileOffset = sMsgPreviousTextRow * msg->tile_stride + sMsgPreviousTextX / 8;
        temp = msg->tile_stride * 8 - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }
        sMsgDirtyTileCount = temp >> 3;

        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
        sMsgPreviousTextX = msg->text_start_x;
        sMsgPreviousTextRow += 2;
        sMsgPreviousTextRow &= 0xFE;
    }

    if (sMsgPreviousTextX != msg->text_x) {
        int temp;

        sMsgDirtyTileOffset = msg->text_row * msg->tile_stride + sMsgPreviousTextX / 8;
        sMsgDirtyTileCount = MIN(msg->tile_stride * 8, msg->text_x);

        temp = sMsgDirtyTileCount - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }

        sMsgDirtyTileCount = temp >> 3;
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
    }
}

static int mMsg_CheckAdvanceInput(void) {
    return gGameState.keys.buttons.pressed & (u16)(A_BUTTON | B_BUTTON);
}

void mMsg_MainSetup_Normal(mMsg_Window_c* msg) {
    msg->status_flags &= ~mMsg_STATUS_END_REACHED;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Normal(mMsg_Window_c* msg) {
    int is_terminal_code = 0;

    if (mMsg_EndTimerDec(msg) == 1) {
        if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
            if (mMsg_RequestDisappear(msg) != 0) {
                mMsg_MainSetup_Window(msg);
            }
            return;
        }
    }

    if (mMsg_CheckAdvanceInput() || msg->force_next == 1) {
        if (msg->lock_continue == 0) {

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 0) {
                if ((u32)msg->next_message_id <= 30 &&
                    mMsg_ChangeMsgData(msg, msg->next_message_id) == 1) {
                    if (mMsg_RequestCursor(msg) != 0) {
                        mMsg_MainSetup_Window(msg);
                        msg->force_next = 0;
                        msg->next_message_id = -1;
                    }
                }
                return;
            }

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 1) {
                goto here;
            } else {
                is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CHECK_CHOICE,
                                                        msg->text_offset);
                if (!is_terminal_code) {
                    is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_LAST,
                                                            msg->text_offset);
                }
            }
            if (is_terminal_code || mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
                here:
                if (is_terminal_code && (msg->status_flags & (1 << 1))) {
                    msg->status_flags |= (1 << 2);
                } else if (mMsg_RequestDisappear(msg) != 0) {
                    mMsg_MainSetup_Window(msg);
                }
            } else if (mMsg_RequestCursor(msg) != 0) {
                mMsg_MainSetup_Window(msg);
                msg->force_next = 0;
            }
            return;
        }
    }

    if (!mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
        msg->lock_continue == 0 && msg->continue_prompt == ((void *)0)) {
        if (msg->message_id == 1 || msg->message_id == 2)
            msg->continue_prompt = mMsg_CreateSprite(0xA, 0xC8, 0x68, 1);
        else
            msg->continue_prompt = mMsg_CreateSprite(0xA, 0xC8, 0x68, 0);
    }
}

void mMsg_MainSetup_Disappear(mMsg_Window_c* msg) {
    msg->transition_frame = 12;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x20);
}

static void mMsg_Main_Disappear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if (msg->transition_frame == 0 && mMsg_RequestHide(msg) != 0) {
        gGameState.sleep_requested = 0;
        gGameState.sleep_dialog_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame--;
    }
}

/* Original address: 0x03003100 */
extern mFont_GlyphDraw_c gMsgGlyph;
/* Original address: 0x02000400 */
extern u8 gMsgCodeBuffers[9][0x220];
/* Original address: 0x02001D80 */
extern u8 gMsgTileBuffers[9][0x1200];
/* Original address: 0x02001720 */
extern u8 gMsgMainText[0x220];
/* Original address: 0x02001940 */
extern u8 gMsgPromptText[0x220];
/* Original address: 0x02001B60 */
extern u8 gMsgNoticeText[0x220];
/* Original address: 0x0200BF80 */
extern u8 gMsgMainTiles[0x1200];
/* Original address: 0x0200D180 */
extern u8 gMsgPromptTiles[0x1200];
/* Original address: 0x0200E380 */
extern u8 gMsgNoticeTiles[0x1200];
/* Original address: 0x0200F580 */
extern u8 gMsgWindowTileData[2][0x480];
/* Original address: 0x020147E0 */
extern u8 gMsgThreeChoiceTileData[3][0xD80];
#define gMsgVram ((u8 *)(BG_VRAM + TILE_OFFSET_4BPP(0x100)))

#if 0
/* Original address: 0x02000000 */
extern u16 gBgPaletteBuffer[256];
/* Original address: 0x02000200 */
extern u16 gObjPaletteBuffer[256];
#else
#define gBgPaletteBuffer ((u16*)0x02000000)
#define gObjPaletteBuffer ((u16*)0x02000200)
#endif

/* These tables are indexed by the one-based mMsg_MODE_* values. */
// #define gMsgModeSetupCallbacks ((mMsg_Callback*)0x0202AADC)
/* Original address: 0x0202AB00 */
extern mMsg_Callback gMsgModeCallbacks[9];
/* Original address: 0x0202AD18 */
extern const u8 gMsgChoiceTemplateParams[4];
/* Original address: 0x0202AD1C */
extern void *const sFontTileBufferVramDestinations[3];
/* Original address: 0x0202AD28 */
extern const u32 sFontTileBufferSizes[3];
/* Original address: 0x0202AFB4 */
extern const IslanderOamData sHiddenOamAttributes;

typedef void (*mMsg_SETUP_PROC)(mMsg_Window_c*);
typedef void (*mMsg_MAIN_PROC)(mMsg_Window_c*);

// @0x0202AADC
extern mMsg_SETUP_PROC gMsgModeSetupCallbacks[];

// @0x0202AB24
extern int gMsgWindowScrollOffsets[12];

// @0x02034EE4
extern u16 time_of_day_palettes[24 * 4];

// @0x02034FA4 - CHAR_* plus control codes
extern u8 gMsgTextData[2002];

/* Original address: 0x02035778; big-endian message end offsets. */
extern u32 sMsgOffsets[31];

/* Original address: 0x020357F4 */
extern u16 sBgPalettes[16][16];

// @0x0202AB54
extern mFont_ControlCodeInfo_c sMsgControlCodeInfo[];

/* Original address: 0x02018D10 */
s32 mMsg_CheckChoiceNext(mMsg_Window_c *msg) {
    s32 result;

    if (msg->message_id == 0x19) {
        result = 0;
        if ((gGameState.keys.buttons.pressed & DPAD_DOWN) &&
            msg->choice_count - 1 > msg->choice_index) {
            result = 1;
        }
    } else {
        result = 0;
        if ((gGameState.keys.buttons.pressed & DPAD_RIGHT) &&
            msg->choice_count - 1 > msg->choice_index) {
            result = 1;
        }
    }
    return result;
}

/* Original address: 0x02018D64 */
s32 mMsg_CheckChoicePrevious(mMsg_Window_c *msg) {
    s32 result;

    if (msg->message_id == 0x19) {
        result = 0;
        if (gGameState.keys.buttons.pressed & DPAD_UP) {
            result = msg->choice_index != 0;
        }
    } else {
        result = 0;
        if (gGameState.keys.buttons.pressed & DPAD_LEFT) {
            result = msg->choice_index != 0;
        }
    }
    return result;
}

void mMsg_UpdateChoiceCursorPosition(mMsg_Window_c *msg) {
    m_msg_sprite_c *cursor;

    cursor = msg->choice_cursor;
    if (cursor != NULL) {
        cursor->_30 = (msg->choices[msg->choice_index].line + 7) * 8;
        cursor->_2C = msg->choices[msg->choice_index].x + 0x2F;
    }
}

/* Original address: 0x02018DE8 */
void mMsg_UpdateChoiceHighlight(mMsg_Window_c *msg) {
    void *two_choice_tiles[2];
    void *three_choice_tiles[3];
    u16 first_choice_tile;

    memcpy(two_choice_tiles, gMsgTwoChoiceHighlightTiles, sizeof(two_choice_tiles));
    memcpy(three_choice_tiles, gMsgThreeChoiceHighlightTiles, sizeof(three_choice_tiles));
    first_choice_tile = msg->tile_stride * msg->choices[0].line;

    if (msg->message_id == 0x19) {
        CpuFastSet(three_choice_tiles[msg->choice_index],
                   (void *)(BG_VRAM + TILE_OFFSET_4BPP(first_choice_tile + 0x100)),
                   (msg->tile_stride * 0x30) & 0x1FFFFF);
        CpuFastSet(three_choice_tiles[msg->choice_index],
                   msg->tile_data + TILE_OFFSET_4BPP(first_choice_tile),
                   (msg->tile_stride * 0x30) & 0x1FFFFF);
    } else {
        CpuFastSet(two_choice_tiles[msg->choice_index],
                   (void *)(BG_VRAM + TILE_OFFSET_4BPP(first_choice_tile + 0x100)),
                   (msg->tile_stride * 0x10) & 0x1FFFFF);
        CpuFastSet(two_choice_tiles[msg->choice_index],
                   msg->tile_data + TILE_OFFSET_4BPP(first_choice_tile),
                   (msg->tile_stride * 0x10) & 0x1FFFFF);
    }
}

void mMsg_MainSetup_Choice(mMsg_Window_c *msg) {
    msg->choice_cursor = mMsg_CreateSprite(0xBU, 0, 0, 0);
    mMsg_UpdateChoiceCursorPosition(msg);
    mMsg_UpdateChoiceHighlight(msg);
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
}

void mMsg_Main_Choice(mMsg_Window_c *msg) {
    u16 sound;
    s8 choice_index;

    if (msg->selected_choice != -1) {
        if (mMsg_TimerDec(msg) != 0) {
            mMsg_MainSetup_Window(msg);
        }
    } else {
        if (msg->choice_cursor == NULL) {
            msg->choice_cursor = mMsg_CreateSprite(0xBU, 0, 0, 0);
            mMsg_UpdateChoiceCursorPosition(msg);
            mMsg_UpdateChoiceHighlight(msg);
            return;
        }
        if ((A_BUTTON & gGameState.keys.buttons.pressed) && (mMsg_RequestCursor(msg) != 0)) {
            msg->force_next = 1;
            choice_index = msg->choice_index;
            msg->selected_choice = choice_index;
            __asm__("" : "+r" (choice_index)); // @HACK
            sound = choice_index == 0 ? 0x10 : 0x11;
            mMsg_SetTimer(msg, 0x14);
            GameAudio_PlayEffect0(sound);
            return;
        }
        if (mMsg_CheckChoiceNext(msg) != 0) {
            msg->choice_index += 1;
            GameAudio_PlayEffect0(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        if (mMsg_CheckChoicePrevious(msg) != 0) {
            msg->choice_index -= 1;
            GameAudio_PlayEffect0(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        mMsg_UpdateChoiceCursorPosition(msg);
    }
}

void mMsg_MainSetup_DisappearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 12;
    msg->saved_mode = msg->current_mode;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x20U);
}

void mMsg_Main_DisappearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0) {
        msg->transition_frame = (u8) msg->transition_frame - 1;
        return;
    }
    msg->draw_enabled = 0;
}

void mMsg_MainSetup_AppearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 0;
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x1FU);
}

void mMsg_Main_AppearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0xA) {
        msg->current_mode = msg->saved_mode;
        msg->draw_enabled = 1;
        return;
    }
    msg->transition_frame = (u8) msg->transition_frame + 1;
}

void mMsg_CopyTilesToVram(s32 tile, s32 count, u8 *tile_data) {
    if (count > 0) {
        CpuFastCopy(tile_data + (tile * 32), gMsgVram + (tile * 16) + (tile * 16), count * 32);
    }
}

s32 mMsg_GetWindowScrollOffset(s8 *frame) {
    if (*frame >= 12) {
        *frame = 11;
    }
    if (*frame < 0) {
        *frame = 0;
    }

    return gMsgWindowScrollOffsets[(s8) (u8) *frame];
}

s8 mMsg_RequestMode(mMsg_Window_c *msg, s8 mode) {
    msg->requested_mode = mode;
    return 1;
}

s8 mMsg_RequestDisappear(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR);
}

s8 mMsg_RequestAppear(mMsg_Window_c *msg, s32 message_id) {
    s8 result;

    result = mMsg_RequestMode(msg, mMsg_MODE_APPEAR);
    if (result == 1) {
        msg->next_message_id = message_id;
    }
    return result;
}

s8 mMsg_RequestCursor(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CURSOR);
}

s8 mMsg_RequestNormal(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_NORMAL);
}

s8 mMsg_RequestHide(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_HIDE);
}

s8 mMsg_RequestChoice(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CHOICE);
}

s8 mMsg_RequestDisappearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_CURSOR || msg->current_mode == mMsg_MODE_NORMAL || msg->current_mode == mMsg_MODE_CHOICE) {
        return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR_WAIT);
    }

    return 0;
}

s8 mMsg_RequestAppearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_DISAPPEAR_WAIT) {
        return mMsg_RequestMode(msg, mMsg_MODE_APPEAR_WAIT);
    }

    return 0;
}

static inline void mMsg_SwapWordBytes(mMsg_U32Bytes_c *encoded, mMsg_U32Bytes_c *decoded) {
    decoded->bytes[3] = encoded->bytes[0];
    decoded->bytes[2] = encoded->bytes[1];
    decoded->bytes[1] = encoded->bytes[2];
    decoded->bytes[0] = encoded->bytes[3];
}

/* Original address: 0x020191E8 */
s32 mMsg_GetMessageBody(u32 index, u8 **data, s16 *size) {
    mMsg_U32Bytes_c encoded;
    mMsg_U32Bytes_c decoded;
    u32 message_offset;
    u32 message_size;

    if (index >= ARRAY_COUNT(sMsgOffsets)) {
        *data = NULL;
        *size = 0;
        return 0;
    }
    if (index != 0) {
        encoded.word = (sMsgOffsets + index)[-1];
        mMsg_SwapWordBytes(&encoded, &decoded);
        message_offset = decoded.word;
    } else {
        message_offset = 0;
    }
    encoded.word = sMsgOffsets[index];
    mMsg_SwapWordBytes(&encoded, &decoded);
    message_size = decoded.word - message_offset;
    if (message_size < 0x200) {
        *data = &gMsgTextData[message_offset];
        *size = message_size;
    } else {
        *size = 0;
        *data = NULL;
    }
    return 1;
}

/* Ghidra name: mMsg_GetStrLenWithEndContCodes (differs from the existing contextual name). */
s16 mMsg_GetMessageLength(u8 *text) {
    s32 offset;
    u8 *next;
    u8 control_code;

    offset = 0;
loop_1:
    offset += mFont_CodeSize_get(&text[offset]);
    next = &text[offset];
    if ((next[0] != CHAR_CONTROL_CODE) ||
        ((control_code = next[1], (control_code != mFont_CONT_CODE_MSG_TIME_END)) &&
         (control_code != mFont_CONT_CODE_LAST) && (control_code != mFont_CONT_CODE_CONTINUE))) {
        if (offset <= 0x1FF) {
            goto loop_1;
        }
    }
    return (s16) offset;
}

/* Ghidra name: ControlCode_GetSize (differs from the existing contextual name). */
s8 mFont_CodeSize_get(u8 *code) {
    u8 size;

    if (code[0] == CHAR_CONTROL_CODE) {
        size = sMsgControlCodeInfo[code[1]].size;
    } else {
        size = 1;
    }
    return (s8) size;
}

/* Original address: 0x020192E8 */
s16 mMsg_LoadMessage(u8 *text, s32 index) {
    s16 size;
    u8 *source;

    if ((mMsg_GetMessageBody((u32) index, &source, &size) == 1) && (source != NULL) && (size != 0)) {
        mMsg_Copy(source, text, size);
        return mMsg_GetMessageLength(text);
    }
    return 0;
}

void mMsg_ClearText(mMsg_Window_c *msg) {
    CpuFastFill(0x55555555, msg->tile_data, 0x1200);
    mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
    msg->text_x = msg->text_start_x;
    msg->text_row = 0;
    msg->temporary_color_length = 0;
}

s32 mMsg_ChangeMsgData(mMsg_Window_c *msg, s32 index) {
    s32 result;

    result = 0;
    if (((u32) index <= 0x1EU) && ((mMsg_LoadMessage(msg->text, index) << 0x10) != 0)) {
        msg->message_id = index;
        msg->next_message_id = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        mMsg_SetTimer(msg, 0x14);
        result = 1;
    }
    return result;
}

void mMsg_SetTimer(mMsg_Window_c *msg, s32 frames) {
    msg->text_delay_timer = frames;
}

/* Ghidra name: Msg_DecrementCodeSize (differs; this decrements the text-delay timer). */
s32 mMsg_TimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->text_delay_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->text_delay_timer = next_timer;
    return expired;
}

void mMsg_SetEndTimer(mMsg_Window_c *msg, s32 frames) {
    msg->end_timer = frames;
}

s32 mMsg_EndTimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->end_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->end_timer = next_timer;
    return expired;
}

void mMsg_DestroySprites(mMsg_Window_c *msg) {
    m_msg_sprite_c *sprite;

    sprite = msg->choice_cursor;
    if (sprite != NULL) {
        mMsg_DeactivateSprite(sprite);
        msg->choice_cursor = NULL;
    }
    sprite = msg->continue_prompt;
    if (sprite != NULL) {
        mMsg_DeactivateSprite(sprite);
        msg->continue_prompt = NULL;
    }
}

s32 mMsg_CheckControlCode(u8 *text, u8 type, s16 offset) {
    s32 result;
    u8 *code;

    result = 0;
    code = &text[offset];
    if ((code[0] == CHAR_CONTROL_CODE) && (code[1] == type)) {
        result = 1;
    }
    return result;
}

/* Ghidra name: Msg_ProcessLines (differs from the existing contextual name). */
/* Original address: 0x02019440 */
s32 mMsg_ProcessText(mMsg_Window_c *msg, u8 *tile_data, s32 max_characters) {
    u8 *destination;
    s32 result;
    u8 palette;
    s32 glyph_width;
    s32 characters_processed;
    s8 tile_stride;
    u8 *code;
    u8 temporary_color_length;
    u8 character;

    result = 1;
    palette = 6;
    if (mMsg_TimerDec(msg) != 0) {
        return 1;
    }
    characters_processed = 0;
    while ((characters_processed < max_characters) && (msg->text_delay_timer == 0)) {
        code = &msg->text[msg->text_offset];
        character = *code;
        if (character == CHAR_NEW_LINE) {
            msg->text_offset += mFont_CodeSize_get(code);
            msg->text_x = msg->text_start_x;
            msg->text_row += 2;
            msg->text_row &= ~1;
            break;
        } else {
            if (character == CHAR_CONTROL_CODE) {
                result = mMsg_ProcessControlCode(msg, &msg->text_offset);
                if ((result >= 2) && (result <= 4)) {
                    break;
                }
            } else {
                glyph_width = mFont_GetGlyphWidth(character);
                tile_stride = msg->tile_stride;
                if (tile_stride * 8 >= (s16) (msg->text_x - 1) + glyph_width) {
                    destination = tile_data + ((tile_stride * msg->text_row) << 5);
                    temporary_color_length = msg->temporary_color_length;
                    if (temporary_color_length != 0) {
                        palette = msg->temporary_color;
                        msg->temporary_color_length = temporary_color_length - 1;
                    }
                    if (character == 0x20) {
                        character = 0x80;
                    }
                    mFont_DrawCharToTiles(destination, msg->text_x, 0, (u16)msg->tile_stride, character, palette, glyph_width - 1);
                    msg->text_x += glyph_width;
                }
                msg->text_offset += mFont_CodeSize_get(&msg->text[msg->text_offset]);
                characters_processed += 1;
            }
        }
    }
    return result;
}

/* Original address: 0x02019580 */
void mMsg_Init(void) {
    u8 init_data[4];
    s32 i;

    memcpy(init_data, gMsgChoiceTemplateParams, sizeof(init_data));

    for (i = 0; i < 2; i++) {
        u8 *codeBuf = gMsgCodeBuffers[i];
        u8 *tileBuf = gMsgTileBuffers[i];
        u8 *windowTileBuf = gMsgWindowTileData[i];

        mMsg_InitWindow(&sMsgWindows[i], gMsgCodeBuffers[i], gMsgTileBuffers[i]);
        sMsgWindows[i].text_x = sMsgWindows[i].text_start_x;
        sMsgWindows[i].text_row = 0;
        sMsgWindows[i].message_length = mMsg_LoadMessage(sMsgWindows[i].text, 0x18);
        sMsgWindows[i].text[5] = init_data[i * 2];
        sMsgWindows[i].text[0xF] = init_data[i * 2 + 1];
        sMsgWindows[i].tile_data = gMsgWindowTileData[i];
        CpuFastFill(0x55555555, sMsgWindows[i].tile_data, 0x480);

        while (mMsg_ProcessText(&sMsgWindows[i], sMsgWindows[i].tile_data, 1) == 1) {
        }
    }

    for (i = 0; i < ARRAY_COUNT(sMsgWindows); i++) {
        mMsg_Window_c* msg = &sMsgWindows[i];
        u8 *codeBuf = gMsgCodeBuffers[i];
        u8 *tileBuf = gMsgTileBuffers[i];
        u16 saved_text_offset;

        mMsg_InitWindow(msg, codeBuf, tileBuf);
        mMsg_ClearText(msg);
        sMsgWindows[i].message_id = sCachedMessageIds[i];
        sMsgWindows[i].message_length = mMsg_LoadMessage(sMsgWindows[i].text, sMsgWindows[i].message_id);
        sMsgWindows[i].current_mode = mMsg_MODE_CURSOR;

        do {
            saved_text_offset = sMsgWindows[i].text_offset;
        } while (mMsg_ProcessText(&sMsgWindows[i], sMsgWindows[i].tile_data, 1) == 1);
        sMsgWindows[i].text_offset = saved_text_offset;
    }
}

void mMsg_MainSetup_Window(mMsg_Window_c *msg) {
    // TODO: chained conditional comparison that got optimized
    if (((u8)(msg->requested_mode - 1) <= 8U) && (gMsgModeSetupCallbacks[msg->requested_mode] != NULL)) {
        mMsg_DestroySprites(msg);
        gMsgModeSetupCallbacks[msg->requested_mode](msg);
    }
}

void mMsg_InitWindow(mMsg_Window_c *msg, u8 *text, u8 *tile_data) {
    CpuFastFill(0, msg, sizeof(*msg));
    msg->tile_data = tile_data;
    msg->text = text;
    msg->next_message_id = -1;
    msg->message_id = -1;
    msg->current_mode = mMsg_MODE_HIDE;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
    msg->tile_stride = 0x12;
    msg->text_start_x = 1;
    msg->draw_enabled = 0;
}

void mMsg_Main_Window(mMsg_Window_c *msg) {
    void (*main)(mMsg_Window_c *);

    main = gMsgModeCallbacks[(s8) (u8) msg->current_mode];
    if (main != NULL) {
        main(msg);
    }
}

/* Original address: 0x020197CC */
s32 mFont_DrawStringToTiles(u8 *tile_data, u16 *cursor, u16 y, u16 tile_stride, u8 *text, s32 length, u8 palette, u8 stop_at_newline, u8 fixed_width) {
    s32 characters_drawn;
    u32 character;
    s32 character_width;
    u16 current_x;

    for (characters_drawn = 0; characters_drawn < length; characters_drawn++) {
        character = text[characters_drawn];
        if ((stop_at_newline == 1 && character == CHAR_NEW_LINE) || character == CHAR_CONTROL_CODE) {
            break;
        }
        character++,character--; // Required to match
        if (fixed_width != 1) {
            character_width = mFont_GetGlyphWidth(character);
        } else {
            character_width = 8;
        }
        current_x = *cursor;
        if (character_width + current_x > tile_stride * 8) {
            break;
        }
        mFont_DrawCharToTiles(tile_data + (((y >> 3) * tile_stride) << 5),
                              current_x, y & 7, tile_stride, character, palette,
                              character_width - 1);
        *cursor += character_width;
    }
    return characters_drawn;
}

/* Original address: 0x02019880 */
void mFont_DrawCharToTiles(u8 *tile_data, s32 tile_offset, s32 row, s32 tile_stride, s32 character, s32 palette, s32 width) {
    mFont_GlyphDraw_c* glyph = &gMsgGlyph;

    glyph->tile_data = tile_data;
    glyph->tile_offset = tile_offset;
    glyph->row = row;
    glyph->tile_stride = tile_stride;
    glyph->palette = palette;
    mFont_GetGlyphRows(glyph->glyph_lower_rows, glyph->glyph_upper_rows, character);
    mFont_BlitGlyphToTiles(glyph, width);
}

/* Original address: 0x020198B8 */
void mFont_CopyTileBufferToVram(s8 index) {
    void* dest[3];
    void* src[3];
    u32 size[3];

    memcpy(dest, sFontTileBufferVramDestinations, sizeof(dest));
    memset(src, 0, sizeof(src));
    memcpy(size, sFontTileBufferSizes, sizeof(size));

    if (index >= 0) {
        CpuFastCopy(src[index], dest[index], size[index]);
    }
}

/* Original address: 0x02019910 */
void mFont_FillTileBuffer(u8 value, s8 index) {
    void* dest[3];
    u32 size[3];
    u32 pixels;
    s32 i;

    memset(dest, 0, sizeof(dest));
    memcpy(size, sFontTileBufferSizes, sizeof(size));

    if (index >= 0) {
        pixels = 0;
        for (i = 0; i < 8; i++) {
            pixels |= (value & 0xF) << (i * 4);
        }
        CpuFastFill(pixels, dest[index], size[index]);
    }
}

/* Original address: 0x02019980 */
void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c *glyph, s32 width) {
    s32 glyph_row;
    u16 y;
    s32 column;
    u16 x;
    u16 tile_index;
    u16 byte_offset;
    u8 packed_pixels;

    for (glyph_row = 0, y = glyph->row; glyph_row < 8; glyph_row++, y++) {
        for (column = 0, x = glyph->tile_offset; column < width; column++, x++) {
            tile_index = (y >> 3) * glyph->tile_stride + (x >> 3);
            if ((glyph->glyph_upper_rows[glyph_row] >> column) & 1) {
                byte_offset = (tile_index << 5) + (y & 7) * 4 + ((x & 7) >> 1);
                packed_pixels = glyph->tile_data[byte_offset];

                if (x & 1) {
                    // packed_pixels &= 0xF;
                    packed_pixels = (packed_pixels & 0xF) | ((glyph->palette & 0xF) << 4);
                } else {
                    // packed_pixels &= 0xF0;
                    packed_pixels = (packed_pixels & 0xF0) | (glyph->palette & 0xF);
                }
                glyph->tile_data[byte_offset] = packed_pixels;
            }
            tile_index += glyph->tile_stride;
            if ((glyph->glyph_lower_rows[glyph_row] >> column) & 1) {
                byte_offset = (tile_index << 5) + (y & 7) * 4 + ((x & 7) >> 1);
                packed_pixels = glyph->tile_data[byte_offset];

                if (x & 1) {
                    packed_pixels &= 0xF;
                    packed_pixels |= (glyph->palette & 0xF) << 4;
                } else {
                    packed_pixels &= 0xF0;
                    packed_pixels |= glyph->palette & 0xF;
                }
                glyph->tile_data[byte_offset] = packed_pixels;
            }
        }
    }
}

/* Original address: 0x02019ABC */
s16 FixedMul8(s16 lhs, s16 rhs) {
    return (lhs * rhs) / 256;
}

/* Original address: 0x02019AD8 */
s16 FixedDiv8(s16 numerator, s16 denominator) {
    return (s16) (((s32) (numerator << 0x10) >> 8) / (s32) denominator);
}

s32 rand_u16(GameState *state) {
    u32 m = state->rng_state * 0x41C64E6D;
    u32 a = state->vblank_counter + 0x3039;
    state->rng_state = m + a;
    return (s32)((u32)(state->rng_state << 1) >> 0x11);
}

/* Original address: 0x02019B18 */
void GameState_SeedRandom(GameState *state, u32 seed) {
    state->rng_state = seed;
}

/* Original address: 0x02019B1C */
void GameState_SetBrightnessFade(GameState *state, u16 darken, u16 blend_control, u16 intensity) {
    if (darken == 1) {
        state->bldcnt = blend_control | 0xC0;
    } else {
        state->bldcnt = blend_control | 0x80;
    }
    if (intensity > 16) {
        intensity = 16;
    }
    state->bldy = intensity;
}

/* Original address: 0x02019B58 */
u16 GameState_StepBrightnessFade(GameState *state, u8 direction, u8 amount) {
    u16 intensity = state->bldy;

    if (direction == 1) {
        intensity += amount;
        if ((s16)intensity > 16) {
            intensity = 16;
        }
    } else if (direction == 0) {
        intensity -= amount;
        if ((s16)intensity < 0) {
            intensity = 0;
        }
    }
    state->bldy = intensity;
    return state->bldy;
}

/* Original address: 0x02019BA8 */
void GetPaletteColor(u16 *palette, u8 x, u8 y, u8 *red, u8 *green, u8 *blue) {
    u16 temp_r1_3514;

    temp_r1_3514 = palette[((0xF & x) * 0x10) + (y & 0xF)];
    *blue = (temp_r1_3514 >> 0xA) & 0x1F;
    *green = (temp_r1_3514 >> 5) & 0x1F;
    *red = temp_r1_3514 & 0x1F;
}

/* Original address: 0x02019BD8 */
void SetPaletteColor(u8 palette, u8 bank, u8 color, u8 red, u8 green, u8 blue) {
    u16 *buffer;
    u16 packed_color;

    if (palette == 1) {
        buffer = gObjPaletteBuffer;
        // buffer = (u16*)0x02000200;
    } else {
        buffer = gBgPaletteBuffer;
        // buffer = (u16*)0x02000000;
    }
    packed_color = RGB(red, green, blue);
    buffer[(bank & 0xF) * 16 + (color & 0xF)] = packed_color;
    gGameState.palette_dirty = 1;
}

/* Original address: 0x02019C3C */
void WaitForVBlank(void) {
    gGameState.vblank_flags &= ~1;
    while (!(gGameState.vblank_flags & 1)) {
    }
    gGameState.vblank_flags &= ~1;
}

/* Original address: 0x02019C88 */
void ClearOamBuffer(void) {
    IslanderOamData *oam = (IslanderOamData *)gUnk3002410;
    IslanderOamData *end = (IslanderOamData *)(gUnk3002410 + sizeof(gUnk3002410));

    while (oam < end) {
        *oam++ = sHiddenOamAttributes;
    }
    gGameState.oam_count = 0;
}

/* Original address: 0x02019CC0 */
void GameState_ReadKeys(void) {
    u16 temp_r2_3660;

    temp_r2_3660 = 0x3FF ^ REG_KEYINPUT;
    gGameState.keys.buttons.pressed = temp_r2_3660 & ~gGameState.keys.buttons.held;
    gGameState.keys.buttons.held = temp_r2_3660;
}

/* Original address: 0x02019CFC */
void EnableVBlankInterrupt(void) {
    REG_IME = 0;
    REG_DISPCNT = 0x80;
    REG_DISPSTAT = 8;
    REG_IE = 1;
    REG_IF = 1;
    REG_IME = 1;
}

/* Original address: 0x02019D28 */
void GameAudio_VBlank(void) {
    SoundDriver_VBlank();
}

/* Original address: 0x02019D34 */
void GameAudio_Init(void) {
    Audio_Init();
}

/* Original address: 0x02019D40 */
void GameAudio_UpdateDriver(void) {
    SoundDriver_Update();
}

/* Original address: 0x02019D4C */
void GameAudio_Update(void) {
    Audio_Update();
}

/* Original address: 0x02019D58 */
void GameAudio_PlayEffect2(u16 value) {
    Sound_PlayEffect2(value);
}

/* Original address: 0x02019D68 */
void GameAudio_StopEffect2(u16 value) {
    Sound_StopEffect2(value);
}

/* Original address: 0x02019D78 */
void GameAudio_PlayEffect0(u16 value) {
    Sound_PlayEffect0(value);
}

/* Original address: 0x02019D88 */
void GameAudio_PlayMusic(u16 value) {
    Sound_PlayMusic(value);
}

/* Original address: 0x02019D98 */
void GameAudio_StopMusic(u16 value) {
    Sound_StopMusic(value);
}

void mMsg_ReplaceChar(u8 *data, u8 from, u8 to, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (data[i] == from) {
                data[i] = to;
            }
        }
    }
}

s32 mMsg_TrimTrailingSpaces(u8 *data, s32 length) {
    s32 trimmed_length;

    trimmed_length = 0;
    if (length > 0) {
        trimmed_length = length;
        while (trimmed_length > 0 && *(data + trimmed_length - 1) == 0x80) {
            trimmed_length--;
        }
    }
    return trimmed_length;
}

s32 mMsg_StringsDiffer(u8 *lhs, u8 *rhs, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (lhs[i] != rhs[i]) {
                break;
            }
        }
    }

    return i != length;
}

/* Ghidra name: mMsg_memcpy (differs from the existing contextual name). */
void mMsg_Copy(u8 *src, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = src[i];
        }
    }
}

void mMsg_Fill(u8 value, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = value;
        }
    }
}

/* Original address: 0x02029698 */
extern const u32 sInitialIntrTable[14];
/* Original address: 0x020359F4 */
extern const u16 sInitialObjPalette[256];
/* Original address: 0x0203B000 */
extern Island_agb_c gInitialIsland;
/* Original address: 0x020102A0 */
extern Island_agb_c gIsland;
/* Original address: 0x03002810 */
extern u32 gFontGlyphBlitterCode[0x58];

/* Original address: 0x02019E88 */
void InitializeHardware(void) {
    RegisterRamReset(RESET_SOUND_REGS | RESET_REGS);
    DmaFill32(3, 0, IWRAM_START, 0x7800);
    REG_WAITCNT = 0x4014;
    DmaCopy16(3, sInitialIntrTable, gIntrTable, sizeof(sInitialIntrTable));
    DmaCopy16(3, _intr, gGameState.interrupt_code, sizeof(gGameState.interrupt_code));
    INTR_VECTOR = gGameState.interrupt_code;
    GameAudio_Init();
}

/* Initial m2c reconstructions after InitializeHardware. */

/* Initial reconstructions; progressively replace raw field accesses with recovered types. */

/* Forward declarations retain m2c's current inferred signatures. */
void sub_02019F08(void);
void InitializeIsland(void);
void IslandProgram_UpdateFrame(void);
void IslandProgram_Main(void);
s32 Swap32(u32 *arg0);
void Joybus_Init(void);
void JoybootHandler(void);
void Joybus_Reset(void);
s32 Joybus_CheckTimeout(u8 arg0);
void IslandProgram_Restart(void);
s32 IslandProgram_PrepareDialogTransition(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_CheckWindowResumed(IslandProgramWork *work, s8 arg1);
u8 IslandProgram_CheckSleepRequest(IslandProgramWork *work);
s32 IslandProgram_UpdateInputTimeout(s16 *arg0, s32 arg1);
void IslandProgram_SetDialogPalette(IslandProgramWork *work, s8 arg1);
void IslandProgram_SetupDialogDisplay(IslandProgramWork *work, u8 arg1);
void IslandProgram_RestoreDialogDisplay(IslandProgramWork *work, s8 arg1);
void IslandProgram_UpdateMessages(IslandProgramWork *work);
s32 IslandProgram_TryOpenTransferDialog(IslandProgramWork *work, u8 arg1);
s32 IslandProgram_TryOpenNoticeDialog(IslandProgramWork *work, u8 arg1);
s32 IslandProgram_TryOpenSleepDialog(IslandProgramWork *work, u8 arg1);
void IslandProgram_BeginJoybusReceive(IslandProgramWork *work);
s8 IslandProgram_PollJoybusReceive(IslandProgramWork *work);
void IslandProgram_BeginJoybusSend(IslandProgramWork *work);
s16 IslandProgram_PollJoybusSend(IslandProgramWork *work);
void sub_0201ADDC(void);
s32 IslandProgram_RequestNoticeState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestNoticeTransfer(IslandProgramWork *work);
s32 IslandProgram_RequestNoticeResult(IslandProgramWork *work);
s32 IslandProgram_RequestNoticeRestart(IslandProgramWork *work);
void IslandProgram_ApplyPendingNoticeState(IslandProgramWork *work);
void IslandProgram_EnterNoticeTransfer(IslandProgramWork *work);
void IslandProgram_UpdateNoticeTransfer(IslandProgramWork *work);
void IslandProgram_EnterNoticeResult(IslandProgramWork *work);
void IslandProgram_UpdateNoticeResult(IslandProgramWork *work);
void IslandProgram_EnterNoticeRestart(IslandProgramWork *work);
void IslandProgram_UpdateNoticeRestart(IslandProgramWork *work);
s32 IslandProgram_RequestSleepState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestSleepPrompt(IslandProgramWork *work);
s32 IslandProgram_RequestSleepMode(IslandProgramWork *work);
s32 IslandProgram_RequestSleepCleanup(IslandProgramWork *work);
void IslandProgram_ApplyPendingSleepState(IslandProgramWork *work);
void IslandProgram_EnterSleepPrompt(IslandProgramWork *work);
void IslandProgram_UpdateSleepPrompt(IslandProgramWork *work);
void IslandProgram_EnterSleepMode(IslandProgramWork *work);
void IslandProgram_UpdateSleepMode(IslandProgramWork *work);
void IslandProgram_EnterSleepCleanup(IslandProgramWork *work);
void IslandProgram_UpdateSleepCleanup(IslandProgramWork *work);
void IslandProgram_SetupOverviewDisplay(void);
void IslandProgram_UpdateTimeOfDayPalette(IslandProgramWork *work);
s32 IslandProgram_RequestTransferState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestTransferPrompt(IslandProgramWork *work);
s32 IslandProgram_RequestTransferProgress(IslandProgramWork *work);
s32 IslandProgram_RequestTransferRetry(IslandProgramWork *work);
s32 IslandProgram_RequestTransferComplete(IslandProgramWork *work);
s32 IslandProgram_RequestTransferCleanup(IslandProgramWork *work);
s32 IslandProgram_RequestTransferRestart(IslandProgramWork *work);
void IslandProgram_ApplyPendingTransferState(IslandProgramWork *work);
void IslandProgram_EnterTransferPrompt(IslandProgramWork *work);
void IslandProgram_UpdateTransferPrompt(IslandProgramWork *work);
void IslandProgram_EnterTransferProgress(IslandProgramWork *work);
void IslandProgram_UpdateTransferProgress(IslandProgramWork *work);
void IslandProgram_EnterTransferRetry(IslandProgramWork *work);
void IslandProgram_UpdateTransferRetry(IslandProgramWork *work);
void IslandProgram_EnterTransferComplete(IslandProgramWork *work);
void IslandProgram_UpdateTransferComplete(IslandProgramWork *work);
void IslandProgram_EnterTransferCleanup(IslandProgramWork *work);
void IslandProgram_UpdateTransferCleanup(IslandProgramWork *work);
void IslandProgram_EnterTransferRestart(IslandProgramWork *work);
void IslandProgram_UpdateTransferRestart(IslandProgramWork *work);
s32 IslandProgram_RequestMode(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestNormalMode(IslandProgramWork *work);
s32 IslandProgram_RequestFieldLoadMode(IslandProgramWork *work);
s32 IslandProgram_RequestMosaicCoverMode(IslandProgramWork *work);
s32 IslandProgram_RequestMosaicRevealMode(IslandProgramWork *work);
s32 IslandProgram_RequestMessageMode(IslandProgramWork *work);
void IslandProgram_ApplyPendingMode(IslandProgramWork *work);
void IslandProgram_EnterNormalMode(IslandProgramWork *work);
void IslandProgram_UpdateNormalMode(IslandProgramWork *work);
void IslandProgram_EnterFieldLoadMode(IslandProgramWork *work);
void IslandProgram_UpdateFieldLoadMode(IslandProgramWork *work);
void IslandProgram_EnterMosaicCoverMode(IslandProgramWork *work);
void IslandProgram_UpdateMosaicCoverMode(IslandProgramWork *work);
void IslandProgram_EnterMosaicRevealMode(IslandProgramWork *work);
void IslandProgram_UpdateMosaicRevealMode(IslandProgramWork *work);
void IslandProgram_EnterMessageMode(IslandProgramWork *work);
void IslandProgram_UpdateMessageMode(IslandProgramWork *work);
void IslandProgram_InitWork(void);
void IslandProgram_Update(void);
void sub_0201C198(void);
u16 IslandProgram_GetElapsedSeconds(void);
s32 IslandProgram_UpdateLinkTransfer(void);
void IslandProgram_TryOpenPendingDialog(IslandProgramWork *work, u8 window, u8 allow_notice, u8 allow_transfer, u8 allow_prompt);
void mMsg_InitSprites(void);
void mMsg_DeactivateSprite(m_msg_sprite_c *sprite);
m_msg_sprite_c *mMsg_CreateSprite(u8 type, s32 x, s32 y, s32 param);
s32 mMsg_FindSpriteByType(u8 arg0);
s32 mMsg_IsSpriteAnimationFinished(m_msg_sprite_c *sprite, AnimFrameData *const *animations);
void mMsg_StartSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations, s16 animation);
void mMsg_UpdateSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations);
void mMsg_CopySpriteOam(m_msg_sprite_c *sprite, IslanderOamData *source, IslanderOamData *dest);
void mMsg_UpdateAndDrawSprites(void);
void sub_0201C5F8(void *arg0);
void mMsg_ContinuePromptSetColor(s32 arg0);
void mMsg_ContinuePromptCycleColor(m_msg_sprite_c *sprite);
void mMsg_ContinuePromptInit(m_msg_sprite_c *sprite);
void mMsg_ContinuePromptDestroy(m_msg_sprite_c* sprite);
void mMsg_ContinuePromptUpdate(m_msg_sprite_c* sprite);
void mMsg_ContinuePromptDraw(m_msg_sprite_c* sprite);
void mMsg_ChoiceCursorIdle(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorInit(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorDestroy(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorUpdate(m_msg_sprite_c* sprite);
void mMsg_ChoiceCursorDraw(m_msg_sprite_c* sprite);
void InitIslandLinkTransfer(s32 arg0);
void StopIslandLinkTransfer(void);
s32 UpdateIslandLinkTransfer(void);
void IslandLinkSerialInterrupt(void);
s32 LoadIslandBuildingTiles(u16 arg0, s32 arg1, u8 arg2);
void LoadIslandFieldEntity(u16 arg0, s32 arg1, u8 arg2);
void LoadIslandForeground(void);
void UpdateHourlyPalette(void);
void InitIslandField(void);
void ExpandIslandBg3(void);
/* Original address: 0x0202FD28 */
extern void (*const sIslandFieldUpdateProcs[4])(void);
/* Original address: 0x0202F3FC */
extern const u16 sFieldPaletteAnimation0[256];
/* Original address: 0x0202F5FC */
extern const u16 sFieldPaletteAnimation2[256];
/* Original address: 0x02000000 */
#define gFieldPaletteBuffer ((u16 *)0x02000000)
/* Original address: 0x02000040 */
#define gFieldPaletteBuffer2 ((u16 *)0x02000040)

s32 UpdateIslandMosaic(u8 cover);
s32 UpdateIslandField(void);
void GameStateUpdateFunc_Normal(void);
void IslandField_UpdateJoybusExit(void);
void IslandField_UpdateSleepExit(void);
void IslandField_UpdateOverviewExit(void);
void DrawIslandField(void);
void InitIslandBuilding(s32 index, u8 type, s32 tile, u8 acre);
void sub_0201E030(void);
void sub_0201E034(void);
void IslandBuilding_Update(u8 arg0, u8 arg1);
void IslandBuilding_DrawSprite(IslandBuildingSprite *sprite, s32 building_index, u8 sprite_index);
void IslandBuilding_Draw(s32 arg0, u8 arg1);
void AnimatedFieldObject_Init(s32 arg0, s32 arg1, u8 arg2);
void AnimatedFieldObject_Update(s32 arg0);
void AnimatedFieldObject_Draw(s32 arg0);
void FieldObject_AttachEntity(s32 arg0, s32 arg1);
void FieldObject_Init(s32 arg0, u16 arg1, s32 arg2, u8 arg3);
void FieldObject_Update(s32 arg0);
void FieldObject_Idle(s32 idx);
void FieldObject_SpawnToppleEffect(s32 arg0);
void FieldObject_UpdateForegroundItem(s32 arg0);
void FieldObject_HandleHit(s32 arg0);
void FieldObject_UpdateShake(s32 arg0);
void FieldObject_UpdateTopple(s32 object_index);
void FieldObject_Deactivate(s32 arg0);
void FieldObject_DrawSprite(FieldObjectSpriteFrame *frame, s32 object_index);
void FieldObject_Draw(s32 object_index);
s32 Islander_StoreItem(u16 item_type, u16 generator_idx);
s16 Islander_GetFishingItem(void);
s32 Islander_SetupDigApproach(u8 tile_offset);
s32 Islander_CanDigHere(void);
s32 Islander_ChangeMoveDir(s32 target_x, s32 target_y, u8 move_mode);
void Islander_UpdateCollisionTiles(u8 direction);
void WriteItemToTile(s32 x, u8 tile_idx, u16 item, u16 item_tile);
s32 CheckSurroundingCollision(u16 arg0, u16 *arg1);
s32 Islander_ChooseNewMoveDirection(u8 arg0);
s32 Islander_CanMoveInDirection(u8 direction);
void Islander_BuryRandomItem(s32 arg0);
void Islander_PlantRandomFlower(void);
void Islander_UpdateBlink(void);
s32 Islander_FaceTargetAndCheckArrival(s32 arg0, s32 arg1);
s32 Islander_PlayAnim(u8 arg0);
void Islander_ClearStoredItem(s32 arg0);
s32 Islander_SpawnReactionEffect(u8 arg0, u8 arg1);
s32 SpawnEntity(u8 spawn_flag, u8 spawn_mode, u16 item_type, u16 item);
s32 Islander_SelectTreeApproach(FieldObject *object, s32 right_x, s32 left_x);
s32 Islander_SetupTreeApproach(FieldObject *object);
s32 Islander_DecideTreeAction(void);
void Islander_MoveWithCollision(void);
void Islander_AdjustAnimForTool(void);
s32 Islander_MoveTowardX(u8 keep_facing, s32 target);
s32 Islander_MoveTowardY(u8 keep_facing, s32 target);
s32 Islander_FindNearbyTree(void);
s32 Islander_TryInteractWithBuriedItem(u8 layer);
void Islander_OnMoodChanged(void);
void WriteItemTileToVRAM(u16 *tilemap, u16 tile_base);
u16 Item_GetItemIdFromTileId(s32 arg0);
s32 Islander_TryDropTool(void);
void Islander_Init(void);
s32 Island_GetFloatingItem(void);
void Islander_StepFlyingItem(void);
s32 Islander_TryStartFishing(void);
u16 Islander_TakeCurrentTileItem(void);
s32 Islander_TryInteractWithCurrentTile(void);
s32 Islander_TryStartDigging(void);
void RestoreHeldItemsToField(void);
void Islander_UpdateMovement(void);
void Islander_StartHouseTransition(void);
void Islander_MoveIndoorsOrOutdoors(void);
void Islander_StartWandering(void);
void Islander_UpdateWandering(void);
void IslanderMoveAction_MoveToTarget(void);
void Islander_StartFoodProcessing(void);
void Islander_ProcessFood(void);
void IslanderMoveAction_UpdateEmotion(void);
void Islander_UpdateEmotionAnimation(void);
void Islander_StartClickReaction(void);
void Islander_CheckClickedOnTimer(void);
void Islander_StartFieldObjectInteraction(void);
void Islander_MoveAction11_State0(void);
void Islander_MoveAction11_State1(void);
void Islander_MoveAction11_State2(void);
void Islander_UpdateFieldObjectInteraction(void);
void Islander_Fishing_Init(void);
void Islander_Fishing_State0(void);
void Islander_Fishing_State1(void);
void Islander_Fishing_State2(void);
void Islander_Fishing_State3(void);
void Islander_Fishing_State4(void);
void Islander_Fishing_State5(void);
void Islander_Fishing_State6(void);
void Islander_Fishing_State7(void);
void IslanderMoveAction_Fishing(void);
void Islander_ReceiveItem_Init(void);
void IslanderMoveAction_ReceiveItem(void);
void Islander_DespawnFlyingItem(void);
void Islander_StoreHeldItem(void);
void Islander_ProcessFishReceived(void);
void IslanderMoveAction_Dig(void);
void Islander_BuryItem_State0(void);
void Islander_BuryItem_State1(void);
void Islander_BuryItem_State2(void);
void Islander_BuryItem_State3(void);
void Islander_BuryItem_State4(void);
void Islander_BuryItem_State5(void);
void IslanderMoveAction_Bury(void);
void Islander_MoveAction20_Init(void);
void Islander_MoveAction20_State0(void);
void Islander_MoveAction20_State1(void);
void Islander_MoveAction20_State2(void);
void Islander_MoveAction20_State3(void);
void Islander_MoveAction20_State4(void);
void Islander_MoveAction20_Move(void);
void Islander_Draw(void);
s32 Item_IsFossil(mActor_name_t arg0);
s32 Item_IsGyroid(mActor_name_t arg0);
s32 Item_IsNES(mActor_name_t arg0);
s32 Item_IsFurniture(mActor_name_t arg0);
s32 Item_IsApple(mActor_name_t arg0);
s32 Item_IsOrange(mActor_name_t arg0);
s32 Item_IsPeach(mActor_name_t arg0);
s32 Item_IsPear(mActor_name_t arg0);
s32 Item_IsCherry(mActor_name_t arg0);
s32 Item_IsTurnip(mActor_name_t arg0);
s32 Item_IsMushroom(mActor_name_t arg0);
s32 Item_IsCandy(mActor_name_t arg0);
s32 Item_Is100Bells(mActor_name_t arg0);
s32 Item_Is1KBells(mActor_name_t arg0);
s32 Item_Is10KBells(mActor_name_t arg0);
s32 Item_Is30KBells(mActor_name_t arg0);
s32 Item_IsFlowerBag(mActor_name_t arg0);
s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t arg0);
s32 Item_IsNet(mActor_name_t arg0);
s32 Item_IsGoldenNet(mActor_name_t arg0);
s32 Item_IsAxe(mActor_name_t arg0);
s32 Item_IsGoldenAxe(mActor_name_t arg0);
s32 Item_IsShovel(mActor_name_t arg0);
s32 Item_IsGoldenShovel(mActor_name_t arg0);
s32 Item_IsFishingRod(mActor_name_t arg0);
s32 Item_IsGoldenRod(mActor_name_t arg0);
s32 Item_IsUmbrella(mActor_name_t arg0);
s32 Item_IsPaint(mActor_name_t arg0);
s32 Item_IsBalloon(mActor_name_t arg0);
s32 Item_IsPinwheel(mActor_name_t arg0);
s32 Item_IsHandFan(mActor_name_t arg0);
s32 Item_IsSignboard(mActor_name_t arg0);
s32 Item_IsShirt(mActor_name_t arg0);
s32 Item_IsCarpet(mActor_name_t arg0);
s32 Item_IsWallpaper(mActor_name_t arg0);
s32 Item_IsAirCheck(mActor_name_t arg0);
s32 Item_IsTrash(mActor_name_t arg0);
s32 Item_IsPitfall(mActor_name_t arg0);
s32 Item_IsConchSeaShellIcon(mActor_name_t arg0);
s32 Item_IsLionsPawShellIcon(mActor_name_t arg0);
s32 Item_IsCoral(mActor_name_t arg0);
s32 Item_IsFlowerLeaves(mActor_name_t arg0);
s32 Item_IsPurpleCosmos(mActor_name_t arg0);
s32 Item_IsBlueCosmos(mActor_name_t arg0);
s32 Item_IsYellowCosmos(mActor_name_t arg0);
s32 Item_IsRedTulips(mActor_name_t arg0);
s32 Item_IsWhiteTulips(mActor_name_t arg0);
s32 Item_IsYellowTulips(mActor_name_t arg0);
s32 Item_IsWhitePansies(mActor_name_t arg0);
s32 Item_IsPurplePansies(mActor_name_t arg0);
s32 Item_IsYellowPansies(mActor_name_t arg0);
s32 Item_IsCoconut(mActor_name_t arg0);
s32 Item_IsCabana(mActor_name_t arg0);
s32 Item_IsIslanderHouse(mActor_name_t arg0);
s32 Item_IsSapling(mActor_name_t arg0);
s32 Item_IsSmallTree(mActor_name_t arg0);
s32 Item_IsMediumTree(mActor_name_t arg0);
s32 Item_IsLargeTree(mActor_name_t arg0);
s32 Item_IsFullyGrownTree(mActor_name_t arg0);
s32 Item_IsDeadSapling(mActor_name_t arg0);
s32 Item_IsFruitAppleTree(mActor_name_t arg0);
s32 Item_IsFruitOrangeTree(mActor_name_t arg0);
s32 Item_IsFruitPeachTree(mActor_name_t arg0);
s32 Item_IsPearFruitTree(mActor_name_t arg0);
s32 Item_IsFruitCherryTree(mActor_name_t arg0);
s32 Item_IsSmallStump(mActor_name_t arg0);
s32 Item_IsMediumStump(mActor_name_t arg0);
s32 Item_IsLargeStump(mActor_name_t arg0);
s32 Item_IsFullyGrownStump(mActor_name_t arg0);
s32 Item_IsPalmSapling(mActor_name_t arg0);
s32 Item_IsSmallPalmTree(mActor_name_t arg0);
s32 Item_IsMediumPalmTree(mActor_name_t arg0);
s32 Item_IsLargePalmTree(mActor_name_t arg0);
s32 Item_IsPalmTree(mActor_name_t arg0);
s32 Item_IsDeadPalmSapling(mActor_name_t arg0);
s32 Item_IsFruitPalmTree(mActor_name_t arg0);
s32 Item_IsSmallPalmStump(mActor_name_t arg0);
s32 Item_IsMediumPalmStump(mActor_name_t arg0);
s32 Item_IsLargePalmStump(mActor_name_t arg0);
s32 Item_IsFullyGrownPalmStump(mActor_name_t arg0);
s32 Item_IsIslandFlag(mActor_name_t arg0);
s32 Item_IsHole(mActor_name_t arg0);
s32 Item_IsBuriedPitfall(mActor_name_t arg0);
s32 Item_IsCedarSapling(mActor_name_t arg0);
s32 Item_IsDeadCedarSapling(mActor_name_t arg0);
s32 Item_IsWeed(mActor_name_t arg0);
s32 Item_IsRock(mActor_name_t arg0);
s32 Item_IsReserved(mActor_name_t arg0);
s32 Item_GetTypeIndex(mActor_name_t arg0);
mActor_name_t Item_GetItemFromTypeIndex(s32 idx);
mActor_name_t Item_TypeToIslandItem(s32 idx);
void FallingFruit_Init(s32 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_02024C00(void);
void sub_02024C04(void);
void FallingFruit_BeginFall(s32 arg0);
void FallingFruit_UpdateFall(s32 arg0);
void FallingFruit_Update(s32 arg0);
void FallingFruit_Draw(s32 arg0);
void Entity_Reset(s32 arg0);
void Entity_PlaceLandedItem(s32 arg0);
void Entity_UpdateLifetime(s32 arg0);
void Entity_BeginToppleEffect(s32 arg0);
void Entity_UpdateToppleEffect(s32 arg0);
void Entity_BeginLeafEffect(s32 arg0);
void Entity_UpdateLeafEffect(s32 arg0);
void Entity_BeginReactionEffect(s32 arg0);
void Entity_UpdateReactionEffect(s32 arg0);
void Entity_BeginItemDrop(s32 arg0);
void Entity_UpdateItemDrop(s32 arg0);
void Entity_BeginFloatingItem(s32 arg0);
void Entity_UpdateFloatingItem(s32 arg0);
void Entity_Update(s32 arg0);
void Entity_DrawFloatingItemShadow(s32 arg0);
void Entity_DrawSprite(s32 arg0);
s32 PlayerHand_IsItemPlacementBlocked(void);
s32 PlayerHand_IsNearInteractionTarget(s32 arg0, s32 arg1, u16 arg2);
s32 PlayerHand_CheckHouseDoorInteraction(void);
s32 PlayerHand_TryInteractWithIslander(void);
s32 PlayerHand_TrySelectIslanderTarget(void);
void PlayerHand_Init(void);
void PlayerHand_UpdateMovement(void);
void PlayerHand_ResetToIdle(void);
void PlayerHand_UpdateIdle(void);
void Field_RestoreNeighborTreeTile(u16 tile_idx, s32 x, u8 neighbor_tile, u8 acre, u8 right_side);
void Field_RestoreAdjacentTreeTiles(u16 arg0, s32 arg1);
void PlayerHand_BeginCarrying(void);
void PlayerHand_UpdateCarrying(void);
void PlayerHand_BeginPlacing(void);
void PlayerHand_UpdatePlacing(void);
void PlayerHand_Update(void);
void PlayerHand_Draw(void);
void Audio_Init(void);
void Audio_Update(void);
void Sound_InitEffects(void);
void sub_02026A34(void);
void Sound_PlayEffect0(u16 value);
void Sound_PlayEffect1(u16 arg0);
void Sound_StopEffect1(u8 arg0);
void Sound_PlayEffect2(u16 value);
void Sound_StopEffect2(u16 value);
void Sound_InitMusic(void);
void sub_02026C0C(void);
void Sound_PlayMusic(u16 value);
void Sound_StopMusic(u16 value);
void ChangeEmotion(u8 arg0);
typedef struct SoundTrack SoundTrack;
void Sound_PlayEmotionNote(SoundTrack *arg0, u8 arg1, u8 arg2, u16 arg3);
void Sound_ApplyEmotionTrackDelay(SoundTrack *arg0, u8 arg1);
typedef struct SoundBank SoundBank;
void SoundDriver_Init(const SoundBank *bank);
void SoundDriver_VBlank(void);
void SoundDriver_Update(void);
void SoundDriver_InitPcmBuffers(s8 *buffers);
void SoundDriver_SwapPcmBuffers(void);
void SoundDriver_DisablePcm(void);
void SoundDriver_EnablePcm(void);
void SoundDriver_InitChannelLists(void);
typedef struct SoundChannel SoundChannel;
void Sound_UnlinkChannel(SoundChannel *channel);

void Sound_InsertPcmChannelByPriority(SoundChannel *arg0);
s32 Sound_NoteToPitch(SoundChannel *arg0, u8 arg1, u8 arg2);
u8 Sound_NoteToNoiseControl(u16 arg0);
s32 Sound_UpdateChannelEnvelope(SoundChannel *arg0);
void sub_02027370(u8 arg0);
u32 Sound_UpdatePcmChannelVolume(SoundChannel *arg0);
u8 Sound_GetPsgEnvelopeControl(SoundChannel *arg0, u8 arg1);
u32 Sound_UpdateChannelPitch(SoundChannel *arg0);
void Sound_UpdatePcmChannels(void);
void Sound_UpdatePsgChannels(void);
void Sound_PlayNote(SoundTrack *track, u8 key, u8 velocity, u16 duration);
void Sound_ReleaseChannel(SoundChannel *channel);
void Sound_StopChannel(SoundChannel *channel);
void Sound_StartPsgChannel(SoundChannel *channel, u8 envelope);
SoundChannel *Sound_AllocateChannel(u8 type, SoundTrack *track, u8 priority);
u8 Sound_MixPcmChannel(SoundChannel *channel, u32 volume, u32 pitch, u8 pan);
void Sound_InitKeySampleInstrument(void);
typedef struct SoundInstrumentResult SoundInstrumentResult;
typedef struct SoundPlayer SoundPlayer;
void Sound_ResolveInstrument(SoundTrack *track, u8 key, SoundInstrumentResult *result);
void Sound_InitPlayers(void);
void Sound_ResetPlayerParameters(SoundPlayer *player);
void Sound_UpdatePlayers(void);
void Sound_StartMusic(s32 player, u32 music);
void Sound_StartEffect(s32 player, u32 group, u32 effect);
void Sound_StartMusicSequence(s32 index, const u8 *sequence, const u16 *bank);
void Sound_StartEffectSequence(s32 index, const u8 *sequence, const u16 *bank, u32 effect);
void Sound_StopPlayer(s32 arg0);
void Sound_FadeOutPlayer(s32 index, s32 frames);
void Sound_SetPlayerPaused(s32 arg0, u8 arg1);
u32 Sound_GetPlayerStatus(s32 arg0);
void Sound_InitTracks(void);
SoundTrack *Sound_FindFreeTrack(void);
void Sound_StartTrack(SoundTrack *track, SoundPlayer *player, const u8 *sequence);
void Sound_ReleaseTrackChannels(SoundTrack *track);
void Sound_StopTrack(SoundTrack *track);
s32 Sound_UpdateTrack(SoundTrack *track);
void Sound_AttachChannelToTrack(SoundTrack *track, SoundChannel *channel);
void Sound_DetachChannelFromTrack(SoundTrack *track, SoundChannel *channel);
u16 Sound_ReadSequenceDuration(SoundTrack *track);
void Sound_SetTrackBank(SoundTrack *track, u32 bank);
typedef struct SoundCommand SoundCommand;
typedef void (*SoundNoteCallback)(SoundTrack *track, u8 key, u8 velocity, u16 duration);
typedef void (*SoundControlCallback)(SoundTrack *track, u8 code);
void Sound_InitCommandQueue(void);
SoundCommand *Sound_ReadCommand(void);
void Sound_CommitCommands(void);
void Sound_QueueStartMusic(u16 player, u16 music);
void Sound_QueueStartEffect(u32 player, u16 group, u16 effect);
void Sound_QueueFadeOutPlayer(u16 player, u16 frames);
void Sound_QueueSetPlayerPaused(u16 player, u8 paused);
void Sound_QueueSetPlayerTempoAdjust(u16 player, s16 adjustment);
void Sound_QueueSetPlayerMasterVolume(u16 player, u8 volume);
void Sound_QueueSetPlayerTempoMode(u16 player, u8 mode);
void Sound_QueueSetTracksMuted(u32 player, u32 tracks, u8 muted);
void Sound_QueueSetTracksExpression(u32 player, u32 tracks, u8 expression);
void Sound_QueueSetTracksPan(u32 player, u32 tracks, u8 pan);
void Sound_QueueCommand10(u8 value);
void Sound_QueueCallback(void (*callback)(u32), u32 argument);
void Sound_QueueSetControlCallback(SoundControlCallback callback);
void Sound_QueueSetNoteCallback(SoundNoteCallback callback);
void Sound_ProcessCommands(void);

void sub_02019F08(void) {

}

/* Original address: 0x02019F0C */
void InitializeIsland(void) {
    s32 i;

    DmaCopy16(3, sBgPalettes, gBgPaletteBuffer, BG_PLTT_SIZE);
    DmaCopy16(3, sInitialObjPalette, gObjPaletteBuffer, OBJ_PLTT_SIZE);
    DmaCopy16(3, gBgPaletteBuffer, PLTT, PLTT_SIZE);
    gIslandTransferData = &gInitialIsland;
    gIslandData = &gIsland;
    CpuCopy32(&gInitialIsland, &gIsland, sizeof(gIsland));
    for (i = 0; i < (s32)(sizeof(gIslandLandInfo) / sizeof(u32)); i++) {
        ((u32 *)&gIslandLandInfo)[i] = ((u32 *)&gIslandTransferData->landinfo)[i];
    }
    gGameState.game_time_frames = gIslandTransferData->renew_time.hour * 3600;
    gGameState.game_time_frames += gIslandTransferData->renew_time.min * 60;
    gGameState.game_time_frames = (gGameState.game_time_frames + gIslandTransferData->renew_time.sec) * 60;
    gGameState.bg0cnt = 0x1C00;
    gGameState.bg1cnt = 0xD801;
    gGameState.bg2cnt = 0xD402;
    gGameState.bg3cnt = 0xD003;
    CpuFastCopy(gIslandTransferData->earth_tex, (void *)BG_VRAM, sizeof(gIslandTransferData->earth_tex));
    CpuFastCopy(gIslandTransferData->npc_tex, (void *)OBJ_VRAM0, sizeof(gIslandTransferData->npc_tex));
    CpuFastCopy(gIslandTransferData->npc_pal, &gObjPaletteBuffer[16], sizeof(gIslandTransferData->npc_pal));
    CpuFastCopy(&gObjPaletteBuffer[16], (void *)(OBJ_PLTT + PLTT_OFFSET_4BPP(1)), PLTT_SIZE_4BPP);
    gGameState.dispcnt = 0;
    Joybus_Init();
    mMsg_InitSprites();
    mMsg_InitWindow(&sMsgWindow_03002fc0, gMsgMainText, gMsgMainTiles);
    mMsg_InitWindow(&sMsgWindow_03003060, gMsgPromptText, gMsgPromptTiles);
    mMsg_InitWindow(&sMsgWindow_03002980, gMsgNoticeText, gMsgNoticeTiles);
    IslandProgram_InitWork();
}

/* Original address: 0x0201A0C8 */
void IslandProgram_UpdateFrame(void) {
    IslandProgram_Update();
}

/* Original address: 0x0201A0D4 */
void IslandProgram_Main(void) {
    CpuFastCopy(mFont_BlitGlyphToTiles, gFontGlyphBlitterCode, sizeof(gFontGlyphBlitterCode));
    mMsg_Init();
    EnableVBlankInterrupt();
    gGameState.frame_committed = 1;
    gGameState.current_music_id = 0xFFFF;
    sub_02019F08();
    InitializeIsland();
    for (;;) {
        GameState_ReadKeys();
        if (gGameState.sleep_mode_active == 1 && gGameState.sleep_ready == 1) {
            vu16 saved_interrupt_enable;
            vu16 saved_display_control;

            saved_interrupt_enable = REG_IE;
            /* The original reads DISPCNT here without restoring it directly. */
            saved_display_control = REG_DISPCNT;
            REG_DISPCNT = 0x80;
            REG_KEYCNT = 0x8204;
            REG_IE = 0x1000;
            SoundBiasReset();
            asm("swi 0x3"); /* BIOS Stop */
            SoundBiasSet();
            REG_IE = saved_interrupt_enable;
            REG_KEYCNT = 0;
            gGameState.joybus_notice_requested = 0;
            gGameState.joybus_notice_active = 0;
            gGameState.sleep_ready = 0;
            gGameState.sleep_mode_active = 0;
            Joybus_Reset();
        }
        ClearOamBuffer();
        if ((gTransWork.command >= 0xFFFE0101 && gTransWork.command <= 0xFFFE0102) ||
            gTransWork.command == 0xFFFE0202) {
            gGameState.joybus_notice_requested = 1;
        }
        IslandProgram_UpdateFrame();
        gGameState.game_time_frames++;
        if (gGameState.game_time_frames >= 24 * 60 * 60 * 60) {
            gGameState.game_time_frames -= 24 * 60 * 60 * 60;
        }
        GameAudio_Update();
        gGameState.frame_committed = 0;
        WaitForVBlank();
    }
}

s32 Swap32(u32 *arg0) {
    u8 bytes[4];
    u8* arg0_ptr = (u8*)arg0;

    bytes[0] = arg0_ptr[3];
    bytes[1] = arg0_ptr[2];
    bytes[2] = arg0_ptr[1];
    bytes[3] = arg0_ptr[0];

    return *(s32*)bytes;
}

/* Original address: 0x0201A218 */
void Joybus_Init(void) {
    u16 saved_ime = REG_IME;

    REG_IME = 0;
    REG_RCNT = 0xC000;
    REG_JOYSTAT = 0;
    (void)REG_JOY_RECV;
    REG_JOY_TRANS = 0;
    REG_JOYCNT = 0x47;
    REG_IF = 0x80;
    REG_IF = 0x80;
    REG_IE |= 0x80;
    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
    REG_IME = saved_ime;
}

/* Original address: 0x0202AFBC */
// extern const u32 sJoybootGbaHandshake;
/* Original address: 0x0202AFC4 */
// extern const u32 sJoybootGameCubeHandshake;

/* Original address: 0x0201A288 */
void JoybootHandler(void) {
    u32 received;
    u32 joycnt;

    joycnt = REG_JOYCNT;
    if (joycnt & 1) {
        if (!gTransWork.connected) {
            received = REG_JOY_RECV;
            REG_JOY_TRANS = sJoybootGbaHandshake;
            gTransWork.connected = FALSE;
        } else {
            joycnt |= 2;
        }
    }

    if (joycnt & 2) {
        received = REG_JOY_RECV;
        if (gTransWork.connected == TRUE) {
            switch (gTransWork.command) {
            case 0xFFFE0105:
                REG_JOY_TRANS = 0xFFFE0207;
                gTransWork.connected = FALSE;
                gTransWork.command = 0;
                break;
            case 0xFFFE0101:
            case 0xFFFE0102:
            {
                if (gTransWork.word_index > gTransWork.transfer_size / 4) {
                    if (gTransWork.checksum_result != 0) {
                        if (!(REG_JOYSTAT & 8)) {
                            u32 response = 0xFFFE0209;
                            if (gTransWork.checksum_result == 1) {
                                response = 0xFFFE0208;
                            }
                            REG_JOY_TRANS = response;
                            gTransWork.result = gTransWork.checksum_result;
                            gTransWork.connected = FALSE;
                            gTransWork.command = 0;
                        }
                    } else if (received == 0xFFFE0106) {
                        gTransWork.checksum_result = 1;
                    } else {
                        gTransWork.checksum_result = 2;
                    }
                } else if (gTransWork.packet_index >= 0) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        if (gTransWork.word_index == gTransWork.transfer_size / 4) {
                            REG_JOY_TRANS = ~gTransWork.total_checksum;
                            gTransWork.word_index++;
                        } else if ((gTransWork.packet_index & 0xFF) == 0xFF) {
                            REG_JOY_TRANS = ~gTransWork.packet_checksum;
                            gTransWork.packet_checksum = status;
                        } else {
                            u32 word = gTransWork.buffer[gTransWork.word_index];
                            gTransWork.packet_checksum += word;
                            gTransWork.total_checksum += word;
                            REG_JOY_TRANS = word;
                            gTransWork.word_index++;
                        }
                        gTransWork.packet_index++;
                    }
                } else if (gTransWork.enabled == TRUE) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        REG_JOY_TRANS = 0xFFFE0204;
                        gTransWork.packet_index = status;
                    }
                } else {
                    REG_JOY_TRANS = 0xFFFE0205;
                }
                break;
            }
            case 0xFFFE0202:
            {
                if (gTransWork.word_index > gTransWork.transfer_size / 4) {
                    if (!(REG_JOYSTAT & 8)) {
                        if (gTransWork.total_checksum == -1) {
                            REG_JOY_TRANS = 0xFFFE0208;
                            gTransWork.result = 1;
                        } else {
                            REG_JOY_TRANS = 0xFFFE0209;
                            gTransWork.result = 2;
                        }
                        gTransWork.connected = FALSE;
                        gTransWork.command = 0;
                    }
                } else if (gTransWork.packet_index > -1) {
                    s32 swapped = Swap32(&received);
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        if (gTransWork.word_index == gTransWork.transfer_size / 4) {
                            gTransWork.buffer[gTransWork.word_index] = received;
                            gTransWork.total_checksum += swapped;
                            gTransWork.word_index++;
                        } else if ((u8)gTransWork.packet_index == 0xFF) {
                            gTransWork.packet_checksum += swapped;
                            if (gTransWork.packet_checksum != -1) {
                                gTransWork.result = 2;
                            }
                            gTransWork.packet_checksum = status;
                        } else {
                            gTransWork.buffer[gTransWork.word_index] = received;
                            gTransWork.packet_checksum += swapped;
                            gTransWork.total_checksum += swapped;
                            gTransWork.word_index++;
                        }
                        gTransWork.packet_index++;
                    }
                } else if (gTransWork.enabled == TRUE) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        REG_JOY_TRANS = 0xFFFE0104;
                        gTransWork.packet_index = status;
                    }
                } else {
                    REG_JOY_TRANS = 0xFFFE0205;
                }
                break;
            }
            default:
                gTransWork.command = received;
                switch (received) {
                case 0xFFFE0101:
                case 0xFFFE0102:
                case 0xFFFE0202:
                    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
                    gTransWork.packet_index = -1;
                    gTransWork.command = received;
                    gTransWork.connected = TRUE;
                    break;
                }
                break;
            }
        } else if (Swap32(&received) == sJoybootGameCubeHandshake) {
            gTransWork.connected = TRUE;
        }
    }

    REG_JOYCNT = joycnt;
    gTransWork.interrupt_count = 0;
}

/* Original address: 0x0201A620 */
void Joybus_Reset(void) {
    u16 saved_ime = REG_IME;

    REG_IME = 0;
    REG_RCNT = 0x8000;
    REG_RCNT = 0xC000;
    REG_JOYSTAT = 0;
    (void)REG_JOY_RECV;
    REG_JOY_TRANS = 0;
    REG_JOYCNT = 0x47;
    REG_IF = 0x80;
    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
    REG_IME = saved_ime;
}

/* Original address: 0x0201A688 */
s32 Joybus_CheckTimeout(u8 reset_on_timeout) {
    s32 timed_out = FALSE;

    if (gTransWork.interrupt_count <= 10U) {
        REG_IME = 0;
        gTransWork.interrupt_count++;
        REG_IME = 1;
    } else {
        if (reset_on_timeout) {
            Joybus_Reset();
        }
        timed_out = TRUE;
    }
    return timed_out;
}

/* Interworking trampoline used to enter the ARM startup code. */
/* Original address: 0x02029308 */
void _call_via_r0(void (*entry)(void));

/* Original address: 0x0201A6C8 */
void IslandProgram_Restart(void) {
    void (*entry)(void) = _start;

    gIslandDataReceived = 0;
    REG_IME = 0;
    REG_DISPSTAT = 0;
    REG_IE = 0;
    REG_IF = 0xFFFF;
    REG_DISPCNT = 0x80;
    _call_via_r0(entry);
}

/* Original address: 0x0201A714 */
s32 IslandProgram_PrepareDialogTransition(IslandProgramWork *work, s8 arg1) {
    s32 var_r7_4955;

    var_r7_4955 = 0;
    if (work->window_ready[arg1] == TRUE) {
        if ((!work->current_window->draw_enabled) && (mMsg_RequestAppearWait(work->current_window) == 1)) {
            mMsg_MainSetup_Window(work->current_window);
            var_r7_4955 = 1;
        }
    } else if ((work->current_window == NULL) || (work->current_window->current_mode == mMsg_MODE_HIDE)) {
        var_r7_4955 = 1;
    } else if (mMsg_RequestDisappearWait(work->current_window) == 1) {
        mMsg_MainSetup_Window(work->current_window);
        work->window_ready[arg1] = TRUE;
    }

    return var_r7_4955;
}

/* Original address: 0x0201A780 */
s32 IslandProgram_CheckWindowResumed(IslandProgramWork *work, s8 arg1) {
    s32 var_r5_5036 = 0;

    if (work->current_window == NULL) {
        return 1;
    }

    if (work->current_window->draw_enabled == TRUE) {
        work->window_ready[arg1] = 0;
        if (arg1 == 1) {
            work->transfer_succeeded = 0;
        }
    }

    var_r5_5036 = 0;
    if (work->window_ready[arg1] == 0) {
        var_r5_5036 = 1;
    }
    return var_r5_5036;
}

/* Original address: 0x0201A7C8 */
u8 IslandProgram_CheckSleepRequest(IslandProgramWork* work) {
    u8 var_r4_5054 = 0;

    if (gGameState.sleep_requested == 1) {
        var_r4_5054 = 1;
    } else if (gGameState.keys.buttons.pressed & SELECT_BUTTON) {
        var_r4_5054 = 1;
    } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 18000) == 1) {
        var_r4_5054 = 1;
    }
    return var_r4_5054;
}

/* Original address: 0x0201A810 */
s32 IslandProgram_UpdateInputTimeout(s16 *arg0, s32 arg1) {
    s32 var_r3_5091;

    var_r3_5091 = 0;
    if (arg1 <= *arg0) {
        var_r3_5091 = 1;
    } else if (KEYS_MASK & gGameState.keys.buttons.held) {
        *arg0 = 0;
    } else {
        *arg0 = (u16) *arg0 + 1;
    }
    return var_r3_5091;
}

/* Original address: 0x0201A854 */
void IslandProgram_SetDialogPalette(IslandProgramWork *work, s8 arg1) {
    u8 r;
    u8 g;
    u8 b;
    s32 i;

    switch (arg1) {
        case 4:
            SetPaletteColor(0, 7, 1, 0x10, 0x17, 0x11);
            SetPaletteColor(0, 7, 2, 0x15, 0x1B, 0x13);
            SetPaletteColor(0, 7, 3, 0x1A, 0x1F, 0x1A);
            SetPaletteColor(0, 7, 4, 0x17, 0x1E, 0x14);
            SetPaletteColor(0, 7, 5, 0x16, 0x1D, 0x16);
            break;
        case 3:
            SetPaletteColor(0, 7, 1, 0x17, 0x17, 0x11);
            SetPaletteColor(0, 7, 2, 0x1B, 0x1B, 0x13);
            SetPaletteColor(0, 7, 3, 0x1F, 0x1F, 0x1A);
            SetPaletteColor(0, 7, 4, 0x1D, 0x1D, 0x15);
            SetPaletteColor(0, 7, 5, 0x1E, 0x1F, 9);
            SetPaletteColor(0, 7, 6, 0xA, 0xB, 8);
            break;
        case 1:
            if (work->use_warm_dialog_palette == 1) {
                SetPaletteColor(0, 7, 1, 0x16, 0xA, 4);
                SetPaletteColor(0, 7, 2, 0x1A, 0xE, 6);
                SetPaletteColor(0, 7, 3, 0x1E, 0xD, 3);
                SetPaletteColor(0, 7, 4, 0x1D, 0x15, 0xC);
                SetPaletteColor(0, 7, 5, 0x1F, 0x1F, 0x15);
                break;
            } else if (work->use_cool_dialog_palette == 1) {
                SetPaletteColor(0, 7, 1, 8, 0x10, 0x14);
                SetPaletteColor(0, 7, 2, 0xA, 0x14, 0x1B);
                SetPaletteColor(0, 7, 3, 0x15, 0x19, 0x1F);
                SetPaletteColor(0, 7, 4, 0x10, 0x17, 0x1D);
                SetPaletteColor(0, 7, 5, 7, 0xF, 0x1F);
                SetPaletteColor(0, 7, 6, 0x1F, 0x1F, 0x1F);
                break;
            }
        // fallthrough 1 -> 2/default
        case 2:
        default:
            for (i = 1; i <= 6; i++) {
                GetPaletteColor(sBgPalettes[0], 7, i, &r, &g, &b);
                SetPaletteColor(0, 7, i, r, g, b);
            }
            break;
    }
    CpuFastSet(&gFieldPaletteBuffer[7 * 16], (void *)(BG_PLTT + PLTT_OFFSET_4BPP(7)), 8U);
}

/* Original address: 0x0201AA98 */
void IslandProgram_SetupDialogDisplay(IslandProgramWork *work, u8 arg1) {
    if (work->dialog_display_owner == 0 && arg1 != 1) {
        work->saved_bg3cnt = gGameState.bg3cnt;
        work->saved_dispcnt = gGameState.dispcnt;
        work->saved_bldy = gGameState.bldy;
        work->saved_bg3_vofs = gGameState.bg3_vofs;
        work->saved_bg3_hofs = gGameState.bg3_hofs;
        work->dialog_display_owner = arg1;
    }
    gGameState.bg3cnt &= 0xFFFC;
    gGameState.dispcnt |= 0x1800;
    gGameState.bldy = 0;
    gGameState.bg3_vofs = 0;
    gGameState.bg3_hofs = 0;
}

/* Original address: 0x0201AB3C */
void IslandProgram_RestoreDialogDisplay(IslandProgramWork *work, s8 arg1) {
    u16 temp_r1_5496;

    if (arg1 == work->dialog_display_owner) {
        gGameState.bg3cnt = work->saved_bg3cnt;
        gGameState.dispcnt = work->saved_dispcnt;
        if (gIslandDataReceived == 1) {
            gGameState.dispcnt &= 0xFDFF;
        }
        gGameState.bldy = work->saved_bldy;
        gGameState.bg3_vofs = work->saved_bg3_vofs;
        gGameState.bg3_hofs = work->saved_bg3_hofs;
        work->dialog_display_owner = 0;
    }
}

/* Original address: 0x0201ABBC */
void IslandProgram_UpdateMessages(IslandProgramWork *work) {
    mMsg_Window_c *temp_r1_5544;

    temp_r1_5544 = work->current_window;
    if ((temp_r1_5544 != NULL) && (gGameState.sleep_mode_active == 0)) {
        mMsg_Main_Window(temp_r1_5544);
    }
    mMsg_UpdateAndDrawSprites();
}

/* Original address: 0x0201ABE4 */
s32 IslandProgram_TryOpenTransferDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5569;

    var_r1_5569 = 0;
    if ((gGameState.sleep_mode_active == 0) && (work->pending_transfer_state != 0)) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->transfer_return_window_id = arg1;
            work->transfer_saved_window = work->current_window;
            IslandProgram_ApplyPendingTransferState(work);
        }
        var_r1_5569 = 1;
    }
    return var_r1_5569;
}

/* Original address: 0x0201AC38 */
s32 IslandProgram_TryOpenNoticeDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5613;

    var_r1_5613 = 0;
    if ((gGameState.sleep_mode_active == 0) && (work->pending_notice_state != 0)) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->notice_return_window_id = arg1;
            work->notice_saved_window = work->current_window;
            IslandProgram_ApplyPendingNoticeState(work);
        }
        var_r1_5613 = 1;
    }
    return var_r1_5613;
}

/* Original address: 0x0201AC8C */
s32 IslandProgram_TryOpenSleepDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5657;

    var_r1_5657 = 0;
    if (work->pending_sleep_state != 0) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->sleep_return_window_id = arg1;
            work->sleep_saved_window = work->current_window;
            IslandProgram_ApplyPendingSleepState(work);
        }
        var_r1_5657 = 1;
    }
    return var_r1_5657;
}

/* Original address: 0x0201ACCC */
void IslandProgram_BeginJoybusReceive(IslandProgramWork *work) {
    Island_agb_c* island = gIslandData;
    s32 transfer_size = sizeof(*island);

    gTransWork.transfer_size = transfer_size;
    gTransWork.buffer = (u32*)island;
    gTransWork.enabled = TRUE;
    work->joybus_transfer_mode = 2;
    work->joybus_sending = 0;
}

/* Original address: 0x0201ACF8 */
s8 IslandProgram_PollJoybusReceive(IslandProgramWork *work) {
    s32 var_r1_5714;

    var_r1_5714 = 0;
    if (gTransWork.result != 0) {
        var_r1_5714 = gTransWork.result;
    } else if (!gTransWork.connected) {
        var_r1_5714 = 2;
    }

    if (var_r1_5714 == 1) {
        work->transfer_succeeded = var_r1_5714;
    }

    return var_r1_5714;
}

/* Original address: 0x0201AD34 */
void IslandProgram_BeginJoybusSend(IslandProgramWork *work) {
    Island_agb_c* island = gIslandData;
    s32 transfer_size = sizeof(*island);

    gTransWork.transfer_size = transfer_size;
    gTransWork.buffer = (u32*)island;
    gTransWork.enabled = TRUE;
    
    if (gTransWork.command == 0xFFFE0101) {
        work->notice_send_active = 1;
    } else {
        work->notice_send_active = 0;
    }

    work->joybus_transfer_mode = 1;
    work->joybus_sending = 1;
}

/* Original address: 0x0201AD84 */
s16 IslandProgram_PollJoybusSend(IslandProgramWork *work) {
    s32 var_r3_5792;

    var_r3_5792 = 0;
    if (gTransWork.result != 0) {
        var_r3_5792 = gTransWork.result;
    } else if (gTransWork.connected == 0) {
        var_r3_5792 = 2;
    }

    if (work->notice_send_active == 0 && work->joybus_sending == 1 && (var_r3_5792 == 1)) {
        gIslandDataReceived = (u16) var_r3_5792;
        gIslandData->in_use = TRUE;
    }
    return var_r3_5792;
}

void sub_0201ADDC(void) {

}

/* Original address: 0x0201ADE0 */
s32 IslandProgram_RequestNoticeState(IslandProgramWork *work, s8 arg1) {
    work->pending_notice_state = arg1;
    return 1;
}

/* Original address: 0x0201ADE8 */
s32 IslandProgram_RequestNoticeTransfer(IslandProgramWork *work) {
    work->pending_notice_state = 1;
    return 1;
}

/* Original address: 0x0201ADF4 */
s32 IslandProgram_RequestNoticeResult(IslandProgramWork *work) {
    work->pending_notice_state = 2;
    return 1;
}

/* Original address: 0x0201AE00 */
s32 IslandProgram_RequestNoticeRestart(IslandProgramWork *work) {
    work->pending_notice_state = 3;
    return 1;
}

/* Original address: 0x0201AE0C */
void IslandProgram_ApplyPendingNoticeState(IslandProgramWork *work) {
    extern const IslandProgramModeProc sIslandProgramNoticeEnterProcs[];

    IslandProgramModeProc proc;

    if ((u8)work->pending_notice_state <= 3) {
        proc = sIslandProgramNoticeEnterProcs[work->pending_notice_state];
        if (proc != NULL) {
            proc(work);
            work->input_idle_timer = 0;
        }
    }
}

/* Original address: 0x0201AE40 */
void IslandProgram_EnterNoticeTransfer(IslandProgramWork *work) {
    int msg_id = gTransWork.command == 0xFFFE0101 ? 30 : 11;

    if (mMsg_RequestAppear(&sMsgWindow_03002980, msg_id) == 1) {
        if (gTransWork.command == 0xFFFE0202) {
            IslandProgram_BeginJoybusReceive(work);
        } else {
            IslandProgram_BeginJoybusSend(work);
        }
        IslandProgram_SetDialogPalette(work, 2);
        IslandProgram_SetupDialogDisplay(work, 2);

        work->notice_state = work->pending_notice_state;
        work->current_window = &sMsgWindow_03002980;
    }

    work->pending_notice_state = 0;
}

/* Original address: 0x0201AEBC */
void IslandProgram_UpdateNoticeTransfer(IslandProgramWork *work) {
    if (work->joybus_sending == 0) {
        work->joybus_result = IslandProgram_PollJoybusReceive(work);
    } else {
        if (work->retry_timer == 0) {
            work->retry_result = IslandProgram_PollJoybusSend(work);
            if (work->retry_result != 0) {
                work->retry_timer = 60;
            } else {
                work->joybus_result = 0;
            }
        } else {
            work->retry_timer--;
            if (work->retry_timer == 0) {
                work->joybus_result = work->retry_result;
            }
        }
    }
    if ((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE) && (work->joybus_result != 0) && (IslandProgram_RequestNoticeResult(work) != 0)) {
        IslandProgram_ApplyPendingNoticeState(work);
    }
}

/* Original address: 0x0201AF48 */
void IslandProgram_EnterNoticeResult(IslandProgramWork *work) {
    s32 sp[2];

    memcpy(sp, sNoticeResultMessages, sizeof(sp));

    if (work->notice_send_active == 1) {
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.sleep_requested = 0;
        gGameState.sleep_dialog_active = 0;
        if (work->joybus_result != 2) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
            work->notice_result_wait_timer = 0;
        } else {
            work->notice_result_wait_timer = 60;
            GameAudio_PlayEffect0(0x28U);
        }
        work->notice_state = work->pending_notice_state;
        work->notice_result_state = 0;
    } else {
        if ((mMsg_ChangeMsgData(work->current_window, sp[work->joybus_result - 1]) == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
            GameAudio_PlayEffect0(work->joybus_result == 1 ? 0x27 : 0x28);
            gGameState.joybus_notice_requested = 0;
            gGameState.joybus_notice_active = 0;
            mMsg_MainSetup_Window(work->current_window);
            work->notice_state = work->pending_notice_state;
            work->notice_result_state = 0;
        }
    }
    work->pending_notice_state = 0;
}

/* Original address: 0x0201B04C */
void IslandProgram_UpdateNoticeResult(IslandProgramWork *work) {
    s32 temp_r0_6172;
    s32 temp_r0_6175;
    s8 temp_r0_6232;
    u8 temp_r1_6169;
    u8 temp_r2_6190;
    void *temp_r0_6223;
    void *temp_r1_6187;

    if ((work->notice_send_active == 1) && work->notice_result_wait_timer != 0) {
        work->notice_result_wait_timer--;
        if (work->notice_result_wait_timer == 0) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
        }
    } else {
        if (!work->current_window->draw_enabled) {
            if (work->transfer_succeeded == 1) {
                work->notice_state = 3;
                GameState_SetBrightnessFade(&gGameState, 0x80U, 0x3FU, 0U);
                gGameState.dispcnt &= 0xFEFF;
                work->transfer_succeeded = 0;
                return;
            }
            work->notice_state = 0;
            work->input_idle_timer = 0;
            work->notice_send_active = 0;
            switch (work->notice_return_window_id) {
                case 1:
                    IslandProgram_SetDialogPalette(work, 1);
                    break;
                case 3:
                    IslandProgram_SetDialogPalette(work, 3);
                    break;
            }
            work->current_window = work->notice_saved_window;
            IslandProgram_RestoreDialogDisplay(work, 2);
            mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
            if (gGameState.joybus_notice_requested == 1) {
                work->transition_requested = 1;
            }
        } else if (((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE)) && (work->notice_send_active == 0) && (gGameState.joybus_notice_requested == 1)) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
        }
    }
}

/* Original address: 0x0201B168 */
void IslandProgram_EnterNoticeRestart(IslandProgramWork *work) {

}

/* Original address: 0x0201B16C */
void IslandProgram_UpdateNoticeRestart(IslandProgramWork *work) {
    if (GameState_StepBrightnessFade(&gGameState, 1, 1) == 0x10) {
        IslandProgram_Restart();
    }
}

/* Original address: 0x0201B18C */
s32 IslandProgram_RequestSleepState(IslandProgramWork *work, s8 arg1) {
    work->pending_sleep_state = arg1;
    return 1;
}

/* Original address: 0x0201B194 */
s32 IslandProgram_RequestSleepPrompt(IslandProgramWork *work) {
    work->pending_sleep_state = 1;
    return 1;
}

/* Original address: 0x0201B1A0 */
s32 IslandProgram_RequestSleepMode(IslandProgramWork *work) {
    work->pending_sleep_state = 2;
    return 1;
}

/* Original address: 0x0201B1AC */
s32 IslandProgram_RequestSleepCleanup(IslandProgramWork *work) {
    work->pending_sleep_state = 3;
    return 1;
}

/* Original address: 0x0201B1B8 */
void IslandProgram_ApplyPendingSleepState(IslandProgramWork *work) {
    extern const IslandProgramModeProc sIslandProgramSleepEnterProcs[];
    IslandProgramModeProc proc;

    if ((u8)work->pending_sleep_state <= 3) {
        proc = sIslandProgramSleepEnterProcs[work->pending_sleep_state];
        if (proc != NULL) {
            proc(work);
            work->input_idle_timer = 0;
        }
    }
}

/* Original address: 0x0201B1EC */
void IslandProgram_EnterSleepPrompt(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&sMsgWindow_03003060, 21) == 1) {
        IslandProgram_SetDialogPalette(work, 3);
        IslandProgram_SetupDialogDisplay(work, 3);
        work->sleep_state = work->pending_sleep_state;
        work->input_idle_timer = 0;
        work->current_window = &sMsgWindow_03003060;
    }
    work->pending_sleep_state = 0;
}

/* Original address: 0x0201B238 */
void IslandProgram_UpdateSleepPrompt(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestSleepCleanup(work) == 1) {
            IslandProgram_ApplyPendingSleepState(work);
        }
    } else if (work->current_window->current_mode >= mMsg_MODE_CURSOR && work->current_window->current_mode <= mMsg_MODE_CHOICE) {
        if (work->current_window->selected_choice != -1) {
            if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) == 0) || (work->current_window->message_id != 22)) {
                if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
                    if (IslandProgram_RequestSleepMode(work) != 0) {
                        IslandProgram_ApplyPendingSleepState(work);
                    }
                }
            } else {
                if (IslandProgram_RequestSleepMode(work) != 0) {
                    IslandProgram_ApplyPendingSleepState(work);
                }
            }
        } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
            if (IslandProgram_RequestSleepMode(work) != 0) {
                IslandProgram_ApplyPendingSleepState(work);
            }
        } else if (gGameState.joybus_notice_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201B2E8 */
void IslandProgram_EnterSleepMode(IslandProgramWork *work) {
    work->sleep_state = work->pending_sleep_state;
    work->pending_sleep_state = 0;
    work->input_idle_timer = 0;
    gGameState.sleep_timer = 0;
    gGameState.sleep_mode_active = 1;
    gGameState.pcm_disable_pending = 1;
    GameAudio_StopMusic(0x14U);
}

/* Original address: 0x0201B328 */
void IslandProgram_UpdateSleepMode(IslandProgramWork *work) {

    if (gGameState.sleep_mode_active == 1) {
        if (gGameState.sleep_timer > 120) {
            int result = mMsg_ChangeMsgData(work->current_window, 23);
            if ((result == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
                work->input_idle_timer = 0;
                work->current_window->text_delay_timer = 0;
                mMsg_MainSetup_Window(work->current_window);
                gGameState.sleep_ready = result;
            }
        }
        gGameState.sleep_timer++;
        return;
    }

    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestSleepCleanup(work) == 1) {
            IslandProgram_ApplyPendingSleepState(work);
        }
    } else if (work->current_window->current_mode >= mMsg_MODE_CURSOR && work->current_window->current_mode <= mMsg_MODE_CHOICE) {
        if (work->current_window->selected_choice != -1) {
            if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) && (work->current_window->message_id == 23)) {
                if (IslandProgram_RequestSleepMode(work) != 0) {
                    IslandProgram_ApplyPendingSleepState(work);
                    gGameState.sleep_timer = 120;
                }
            }
        } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
            if (IslandProgram_RequestSleepMode(work) != 0) {
                IslandProgram_ApplyPendingSleepState(work);
                gGameState.sleep_timer = 120;
            }
        } else if (gGameState.joybus_notice_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201B420 */
void IslandProgram_EnterSleepCleanup(IslandProgramWork *work) {
    work->sleep_state = work->pending_sleep_state;
    work->pending_sleep_state = 0;
    if (gGameState.sleep_timer != 0) {
        if ((s16) gGameState.current_music_id != -1) {
            GameAudio_PlayMusic(gGameState.current_music_id);
        }
        SoundDriver_EnablePcm();
        gGameState.sleep_timer = 0;
    }
}

/* Original address: 0x0201B464 */
void IslandProgram_UpdateSleepCleanup(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        work->sleep_state = 0;
        if (work->sleep_return_window_id == 1) {
            IslandProgram_SetDialogPalette(work, 1);
        }
        work->sleep_return_window_id = 0;
        work->current_window = work->sleep_saved_window;
        IslandProgram_RestoreDialogDisplay(work, 3);
        mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
        work->input_idle_timer = 0;
    }
}

/* Original address: 0x0201B4B0 */
void IslandProgram_SetupOverviewDisplay(void) {
    gGameState.dispcnt = (gGameState.dispcnt & 0xE0FF) | 0x700;
    gGameState.bg3cnt &= 0xFFFC;
    gGameState.bg1cnt = (gGameState.bg1cnt & 0xFFFC) | 1;
    gGameState.bg0cnt = (gGameState.bg0cnt & 0xFFFC) | 2;
    gGameState.bg2cnt = (gGameState.bg2cnt & 0xFFFC) | 3;
    if (gIslandData->weather != mEnv_WEATHER_CLEAR) {
        gGameState.bg0cnt |= 0x100; // rain flag
    } else {
        gGameState.bg0cnt |= 0x000; // clear flag
    }
    if (gIslandDataReceived == 1) {
        gGameState.dispcnt &= 0xFDFF;
    }
    gGameState.bg1_vofs = 0x100;
    gGameState.bg1_hofs = 0x100;
    gGameState.bg2_vofs = 0x100;
    gGameState.bg2_hofs = 0;
}

/* Original address: 0x0201B594 */
void IslandProgram_UpdateTimeOfDayPalette(IslandProgramWork *work) {
    u8 time_of_day = (u8)(gGameState.game_time_frames / 216000U);

    if (time_of_day != work->time_of_day) {
        u16 *palette;

        CpuCopy16(sTimeOfDayPalette2Table[time_of_day], current_time_of_day_palette2,
                  sizeof(sTimeOfDayPalette2Table[time_of_day]));
        CpuCopy16(sTimeOfDayPalette3Table[time_of_day], current_time_of_day_palette3,
                  sizeof(sTimeOfDayPalette3Table[time_of_day]));
        CpuFastCopy(time_of_day_palette_buffer2, (void *)(BG_PLTT + 0x180), PLTT_SIZE_4BPP);
        CpuFastCopy(time_of_day_palette_buffer3, (void *)(BG_PLTT + 0x1C0), PLTT_SIZE_4BPP);

        palette = &time_of_day_palettes[time_of_day * 4];
        CpuCopy16(palette, current_time_of_day_palette0, sizeof(current_time_of_day_palette0));
        CpuCopy16(palette, current_time_of_day_palette1, sizeof(current_time_of_day_palette1));
        CpuFastCopy(current_time_of_day_palette0, (void *)(BG_PLTT + 0x100), PLTT_SIZE_4BPP);
        CpuFastCopy(current_time_of_day_palette1, (void *)(BG_PLTT + 0x120), PLTT_SIZE_4BPP);
        work->time_of_day = time_of_day;
    }
    gGameState.bldcnt = 0x2441;
    gGameState.bldalpha = 0x1006;
}

/* Original address: 0x0201B680 */
s32 IslandProgram_RequestTransferState(IslandProgramWork *work, s8 arg1) {
    work->pending_transfer_state = arg1;
    return 1;
}

/* Original address: 0x0201B688 */
s32 IslandProgram_RequestTransferPrompt(IslandProgramWork *work) {
    work->pending_transfer_state = 1;
    return 1;
}

/* Original address: 0x0201B694 */
s32 IslandProgram_RequestTransferProgress(IslandProgramWork *work) {
    work->pending_transfer_state = 2;
    return 1;
}

/* Original address: 0x0201B6A0 */
s32 IslandProgram_RequestTransferRetry(IslandProgramWork *work) {
    work->pending_transfer_state = 3;
    return 1;
}

/* Original address: 0x0201B6AC */
s32 IslandProgram_RequestTransferComplete(IslandProgramWork *work) {
    work->pending_transfer_state = 4;
    return 1;
}

/* Original address: 0x0201B6B8 */
s32 IslandProgram_RequestTransferCleanup(IslandProgramWork *work) {
    work->pending_transfer_state = 5;
    return 1;
}

/* Original address: 0x0201B6C4 */
s32 IslandProgram_RequestTransferRestart(IslandProgramWork *work) {
    work->pending_transfer_state = 6;
    return 1;
}

/* Original address: 0x0201B6D0 */
void IslandProgram_ApplyPendingTransferState(IslandProgramWork *work) {
    IslandProgramModeProc proc;

    if ((u8)work->pending_transfer_state <= 6) {
        extern const IslandProgramModeProc sIslandProgramTransferEnterProcs[];

        proc = sIslandProgramTransferEnterProcs[work->pending_transfer_state];
        if (proc != NULL) {
            proc(work);
        }
    }
}

/* Original address: 0x0201B6FC */
void IslandProgram_EnterTransferPrompt(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&sMsgWindow_03002980, 4) == 1) {
        IslandProgram_SetDialogPalette(work, 4);
        IslandProgram_SetupDialogDisplay(work, 4U);
        InitIslandLinkTransfer(0);
        StopIslandLinkTransfer();
        *gIntrTable = (u32) IslandLinkSerialInterrupt;
        work->transfer_state = work->pending_transfer_state;
        work->current_window = &sMsgWindow_03002980;
    }
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B75C */
void IslandProgram_UpdateTransferPrompt(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestTransferCleanup(work) == 1) {
            IslandProgram_ApplyPendingTransferState(work);
        }
    } else if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) && (work->current_window->message_id == 6) && (IslandProgram_RequestTransferProgress(work) == 1)) {
        IslandProgram_ApplyPendingTransferState(work);
    }
}

/* Original address: 0x0201B7B0 */
void IslandProgram_EnterTransferProgress(IslandProgramWork *work) {
    s32 var_r2_7139;
    int i;

    if ((mMsg_ChangeMsgData(work->current_window, 15) == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
        mMsg_MainSetup_Window(work->current_window);
        var_r2_7139 = 0;
        work->transfer_state = work->pending_transfer_state;
        gIslandData->checksum = 0;

        // clear the land info? I don't know why they didn't use memset here.
        for (i = 0; i < (s32)(sizeof(gIslandData->landinfo) / sizeof(s32)); i++) {
            ((s32*)&gIslandData->landinfo)[i] = 0;
        }
        work->link_transfer_started = 1;
        InitIslandLinkTransfer(0);
    }
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B824 */
void IslandProgram_UpdateTransferProgress(IslandProgramWork *work) {
    s32 temp_r0_7180;
    s32 temp_r0_7232;
    u32 temp_r0_7182;

    temp_r0_7180 = IslandProgram_UpdateLinkTransfer();
    temp_r0_7182 = temp_r0_7180 - 7;
    switch (temp_r0_7182) {
    case 1:
    case 3:
    case 9:
        if ((IslandProgram_RequestTransferRetry(work) == 1) && (mMsg_ChangeMsgData(work->current_window, temp_r0_7180) == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
            mMsg_MainSetup_Window(work->current_window);
            mMsg_ClearText(work->current_window);
            IslandProgram_ApplyPendingTransferState(work);
            return;
        }
    default:
        return;
    case 2:
        if (IslandProgram_RequestTransferComplete(work) == 1) {
            temp_r0_7232 = mMsg_ChangeMsgData(work->current_window, temp_r0_7180);
            if ((temp_r0_7232 == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
                mMsg_MainSetup_Window(work->current_window);
                mMsg_ClearText(work->current_window);
                IslandProgram_ApplyPendingTransferState(work);
                work->transfer_succeeded = temp_r0_7232;
                return;
            }
        }
        break;
    case 0:
        if ((mMsg_ChangeMsgData(work->current_window, temp_r0_7180) == 1) && ((mMsg_RequestCursor(work->current_window) << 0x18) != 0)) {
            mMsg_MainSetup_Window(work->current_window);
            mMsg_ClearText(work->current_window);
        }
        break;
    }
}

/* Original address: 0x0201B90C */
void IslandProgram_EnterTransferRetry(IslandProgramWork *work) {
    work->transfer_state = work->pending_transfer_state;
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B91C */
void IslandProgram_UpdateTransferRetry(IslandProgramWork *work) {
    s32 temp_r0_7298;

    if (mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) {
        temp_r0_7298 = mMsg_ChangeMsgData(work->current_window, 0x11);
        if ((temp_r0_7298 == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
            work->transfer_state = temp_r0_7298;
            mMsg_MainSetup_Window(work->current_window);
        }
    }
}

/* Original address: 0x0201B960 */
void IslandProgram_EnterTransferComplete(IslandProgramWork *work) {
    work->transfer_state = work->pending_transfer_state;
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B970 */
void IslandProgram_UpdateTransferComplete(IslandProgramWork* work) {
    if (!work->current_window->draw_enabled && IslandProgram_RequestTransferCleanup(work) == 1) {
        IslandProgram_ApplyPendingTransferState(work);
    }
}

/* Original address: 0x0201B994 */
void IslandProgram_EnterTransferCleanup(IslandProgramWork *work) {
    s32 *var_r7_7399;
    s32 temp_r0_7404;
    s32 var_r3_7393;
    s8 *var_r2_7359;
    u8 temp_r3_7355;
    int i;

    temp_r3_7355 = work->link_transfer_started;
    if (work->link_transfer_started == 0) {
        work->transfer_state = work->pending_transfer_state;
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
    } else if (mMsg_RequestAppear(&sMsgWindow_03002980, 18) == 1) {
        // Again, why not use memcpy here?
        for (i = 0; i < (s32)(sizeof(gIslandData->landinfo) / sizeof(s32)); i++) {
            ((s32*)&gIslandData->landinfo)[i] = ((s32*)&gIslandLandInfo)[i];
        }
        work->transfer_state = work->pending_transfer_state;
        work->current_window = &sMsgWindow_03002980;
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
    }

    work->pending_transfer_state = 0;
}

/* Original address: 0x0201BA54 */
void IslandProgram_UpdateTransferCleanup(IslandProgramWork *work) {
    s8 temp_r2_7459;
    s8 var_r1_7472;
    u8 temp_r0_7450;

    if (!work->current_window->draw_enabled) {
        work->transfer_state = 0;

        switch (work->transfer_return_window_id) {
            case 1:
                IslandProgram_SetDialogPalette(work, 1);
                break;
            case 3:
                IslandProgram_SetDialogPalette(work, 3);
                break;
            default:
                IslandProgram_RestoreDialogDisplay(work, 4);
                break;
        }

        work->transfer_return_window_id = 0;
        work->current_window = work->transfer_saved_window;
        IslandProgram_RestoreDialogDisplay(work, 4);
        mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
        if (work->transfer_succeeded == 1) {
            work->transfer_state = 6;
            GameState_SetBrightnessFade(&gGameState, 0x80U, 0x3FU, 0U);
            gGameState.dispcnt &= 0xFEFF;
            GameAudio_StopMusic(0x14U);
            work->transfer_succeeded = 0;
        }
        work->link_transfer_started = 0;
        work->input_idle_timer = 0;
        *gIntrTable = (u32)JoybootHandler;
        Joybus_Init();
    }
}

/* Original address: 0x0201BB20 */
void IslandProgram_EnterTransferRestart(IslandProgramWork *work) {

}

/* Original address: 0x0201BB24 */
void IslandProgram_UpdateTransferRestart(IslandProgramWork *work) {
    if (GameState_StepBrightnessFade(&gGameState, 1U, 1U) == 0x10) {
        IslandProgram_Restart();
    }
}

/* Original address: 0x0201BB44 */
s32 IslandProgram_RequestMode(IslandProgramWork *work, s8 arg1) {
    work->pending_mode = arg1;
    return 1;
}

/* Original address: 0x0201BB4C */
s32 IslandProgram_RequestNormalMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 1);
}

/* Original address: 0x0201BB58 */
s32 IslandProgram_RequestFieldLoadMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 2);
}

/* Original address: 0x0201BB64 */
s32 IslandProgram_RequestMosaicCoverMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 4);
}

/* Original address: 0x0201BB70 */
s32 IslandProgram_RequestMosaicRevealMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 3);
}

/* Original address: 0x0201BB7C */
s32 IslandProgram_RequestMessageMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 5);
}

/* Original address: 0x0201BB88 */
void IslandProgram_ApplyPendingMode(IslandProgramWork *work) {
    IslandProgramModeProc proc;

    if ((u32)work->pending_mode <= 5U) {
        proc = sIslandProgramModeEnterProcs[work->pending_mode];
        if (proc != NULL) {
            proc(work);
        }
    }
}

/* Original address: 0x0201BBB4 */
void IslandProgram_EnterNormalMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    work->current_window = NULL;
    gGameState.current_music_id = 0;
    GameAudio_PlayMusic(0);
    gGameState.pcm_disable_pending = 1;
    IslandProgram_SetupOverviewDisplay();
}

/* Original address: 0x0201BBF8 */
void IslandProgram_UpdateNormalMode(IslandProgramWork *work) {
    if (gIslandDataReceived == 0) {
        if ((gGameState.keys.buttons.pressed & 9) && IslandProgram_RequestMosaicCoverMode(work) == 1) {
            IslandProgram_ApplyPendingMode(work);
            return;
        }
        if (gGameState.joybus_notice_requested != 0 ||
            (gGameState.transfer_requested != 0 || gGameState.sleep_requested != 0)) {
            work->transition_requested = 1;
        }
    } else {
        if ((gGameState.keys.buttons.pressed & 1) && IslandProgram_RequestMessageMode(work) == 1) {
            IslandProgram_ApplyPendingMode(work);
            return;
        }
        if (gGameState.joybus_notice_requested != 0 || gGameState.sleep_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201BCA4 */
void IslandProgram_EnterFieldLoadMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    gGameState.current_music_id = 1;
    GameAudio_PlayMusic(gGameState.current_music_id);
    SoundDriver_EnablePcm();
    gGameState.dispcnt = (0xE0FF & gGameState.dispcnt) | 0x1F00;
    gGameState.bg0cnt &= 0xFFFC;
    gGameState.bg1cnt = (0xFFFC & gGameState.bg1cnt) | 1;
    gGameState.bg2cnt = (0xFFFC & gGameState.bg2cnt) | 2;
    gGameState.bg3cnt = (0xFFFC & gGameState.bg3cnt) | 3;
    gGameState.bg0_vofs = 0;
    gGameState.bg0_hofs = 0;
    gGameState.bg1_vofs = 0;
    gGameState.bg1_hofs = 0;
    gGameState.bg2_vofs = 0;
    gGameState.bg2_hofs = 0;
    gGameState.bg3_vofs = 0x100;
    gGameState.bg3_hofs = 0x100;
}

/* Original address: 0x0201BD7C */
void IslandProgram_UpdateFieldLoadMode(IslandProgramWork *work) {
    u8 temp_r4_7859;

    temp_r4_7859 = UpdateIslandField();
    DrawIslandField();
    if ((temp_r4_7859 == 1) && ((s32) IslandProgram_RequestMosaicRevealMode(work) == 1)) {
        IslandProgram_ApplyPendingMode(work);
    }
}

/* Original address: 0x0201BDA8 */
void IslandProgram_EnterMosaicCoverMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    GameAudio_StopMusic(0x14U);
}

/* Original address: 0x0201BDC4 */
void IslandProgram_UpdateMosaicCoverMode(IslandProgramWork *work) {
    if (UpdateIslandMosaic(1U) == 1 && IslandProgram_RequestFieldLoadMode(work) == 1) {
        IslandProgram_ApplyPendingMode(work);
    }
}

/* Original address: 0x0201BDE8 */
void IslandProgram_EnterMosaicRevealMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    gGameState.current_music_id = 0;
    GameAudio_PlayMusic(0U);
    IslandProgram_SetupOverviewDisplay();
    gGameState.bg1_vofs = 0x100;
    gGameState.bg1_hofs = 0x100;
    gGameState.bg2_vofs = 0x100;
    gGameState.bg2_hofs = 0;
}

/* Original address: 0x0201BE3C */
void IslandProgram_UpdateMosaicRevealMode(IslandProgramWork *work) {
    s32 transition_complete;

    transition_complete = UpdateIslandMosaic(0U);
    if (transition_complete == 1) {
        work->mode = transition_complete;
        gGameState.pcm_disable_pending = transition_complete;
    }
}

/* Original address: 0x0201BE68 */
void IslandProgram_EnterMessageMode(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&sMsgWindow_03002fc0, 0x1A) == 1) {
        s8 prev;

        IslandProgram_SetDialogPalette(work, 1);
        IslandProgram_SetupDialogDisplay(work, 1U);
        prev = work->pending_mode;
        work->mode = prev;
        work->current_window = &sMsgWindow_03002fc0;
    }
    work->pending_mode = 0;
}

/* Original address: 0x0201BEB0 */
void IslandProgram_UpdateMessageMode(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        work->mode = 1;
    } else if ((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE) && (work->current_window->selected_choice == -1) && ((gGameState.joybus_notice_requested != 0) || (gGameState.sleep_requested != 0))) {
        work->transition_requested = 1;
    }
}

/* Original address: 0x0201BF10 */
void IslandProgram_InitWork(void) {
    CpuFastFill(0, &gIslandProgramWork, sizeof(IslandProgramWork));
    gIslandProgramWork.time_of_day = -1;
    InitIslandField();
    if (IslandProgram_RequestNormalMode(&gIslandProgramWork) == 1) {
        IslandProgram_ApplyPendingMode(&gIslandProgramWork);
    }
    IslandProgram_UpdateTimeOfDayPalette(&gIslandProgramWork);
}

/* Original address: 0x0202AFDC */
extern IslandProgramModeProc const sIslandProgramNoticeUpdateProcs[4];

/* Original address: 0x0202AFFC */
extern IslandProgramModeProc const sIslandProgramPromptUpdateProcs[4];

/* Original address: 0x0202B2A0 */
extern IslandProgramModeProc const sIslandProgramTransferUpdateProcs[7];

/* Original address: 0x0202B2D4 */
extern IslandProgramModeProc const sIslandProgramModeUpdateProcs[6];

/* Original address: 0x0201BF58 */
void IslandProgram_Update(void) {
    u8 transition_requested;
    u8 allow_link_reset;
    IslandProgramWork *work = &gIslandProgramWork;

    allow_link_reset = 1;
    if ((work->notice_state != 3) && (work->transfer_state != 6) && (work->mode != 2)) {
        IslandProgram_UpdateTimeOfDayPalette(work);
    }
    if (gIslandData->weather != 0) {
        gGameState.bg0_hofs = work->weather_scroll + ((u16)gGameState.bg2_hofs >> 1);
        gGameState.bg0_vofs -= 4;
        work->weather_scroll += 1;
    }
    IslandProgram_UpdateMessages(work);
    if (work->notice_state != 0) {
        sIslandProgramNoticeUpdateProcs[work->notice_state](work);
        transition_requested = work->transition_requested;
        if (transition_requested == 1) {
            IslandProgram_RequestNoticeTransfer(work);
            work->transition_requested = 0;
            IslandProgram_ApplyPendingNoticeState(work);
            gGameState.joybus_notice_active = transition_requested;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        }
    } else if (work->transfer_state != 0) {
        sIslandProgramTransferUpdateProcs[work->transfer_state](work);
        allow_link_reset = 0;
    } else if (work->sleep_state != 0) {
        if (work->transition_requested == 0) {
            if (work->window_ready[3] == 0) {
                sIslandProgramPromptUpdateProcs[work->sleep_state](work);
            } else if ((work->current_window == NULL) || (work->current_window->draw_enabled == 1)) {
                work->window_ready[3] = 0;
            }
        }
        if (work->transition_requested == 1) {
            IslandProgram_TryOpenPendingDialog(work, 3U, 1U, 1U, 0);
        }
    } else if (work->mode != 0) {
        if ((work->mode == 1) && (gIslandDataReceived == 0) && (gGameState.keys.buttons.pressed & B_BUTTON)) {
            gGameState.transfer_requested = 1;
        }
        gGameState.sleep_requested = IslandProgram_CheckSleepRequest(work);
        if (work->transition_requested == 0) {
            if (work->window_ready[1] == 0) {
                sIslandProgramModeUpdateProcs[gIslandProgramWork.mode](&gIslandProgramWork);
            } else if ((work->current_window == NULL) || (work->current_window->draw_enabled == 1)) {
                work->window_ready[1] = 0;
                work->input_idle_timer = 0;
            }
        }
        if (work->transition_requested == 1) {
            IslandProgram_TryOpenPendingDialog(work, 1U, 1U, 1U, (s32) work->transition_requested);
        }
    }
    Joybus_CheckTimeout(allow_link_reset);
}

void sub_0201C198(void) {

}

/* Original address: 0x0201C19C */
u16 IslandProgram_GetElapsedSeconds(void) {
    return (u16) (gIslandProgramWork.elapsed_milliseconds / 1000);
}

/* Original address: 0x0201C1B8 */
s32 IslandProgram_UpdateLinkTransfer(void) {
    return UpdateIslandLinkTransfer();
}

/* Original address: 0x0201C1C4 */
void IslandProgram_TryOpenPendingDialog(IslandProgramWork *work, u8 window, u8 allow_notice, u8 allow_transfer, u8 allow_prompt) {
    s32 ready = IslandProgram_PrepareDialogTransition(work, (s8)window);

    if (ready == 1) {
        if (allow_notice != 0 && gGameState.joybus_notice_requested != 0) {
            IslandProgram_RequestNoticeTransfer(work);
            work->transition_requested = 0;
            work->notice_return_window_id = window;
            work->notice_saved_window = work->current_window;
            IslandProgram_ApplyPendingNoticeState(work);
            gGameState.joybus_notice_active = ready;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        } else if (allow_transfer != 0 && gGameState.transfer_requested != 0) {
            IslandProgram_RequestTransferPrompt(work);
            work->transition_requested = 0;
            work->transfer_return_window_id = window;
            work->transfer_saved_window = work->current_window;
            IslandProgram_ApplyPendingTransferState(work);
            gGameState.transfer_dialog_active = 1;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        } else if (allow_prompt != 0 && gGameState.sleep_requested != 0) {
            IslandProgram_RequestSleepPrompt(work);
            work->transition_requested = 0;
            work->sleep_return_window_id = window;
            work->sleep_saved_window = work->current_window;
            IslandProgram_ApplyPendingSleepState(work);
            gGameState.sleep_dialog_active = 1;
        }
    }
}

/* Original address: 0x0201C2E0 */
void mMsg_InitSprites(void) {
    s32 sp0;

    sp0 = 0;
    CpuFastSet(&sp0, gMsgSprites, 0x01000120U);
}

/* Original address: 0x0201C300 */
void mMsg_DeactivateSprite(m_msg_sprite_c *sprite) {
    sprite->_57 = 0;
    sprite->update = NULL;
    sprite->draw = NULL;
}

/* Original address: 0x0201C310 */
m_msg_sprite_c *mMsg_CreateSprite(u8 type, s32 x, s32 y, s32 param) {
    u32 zero;
    m_msg_sprite_c *result = NULL;
    s32 index = mMsg_FindSpriteByType(0);

    if (index >= 0) {
        const mMsg_SpriteProfile *profile = sMsgSpriteProfiles[type];
        m_msg_sprite_c *sprite;

        zero = 0;
        sprite = &gMsgSprites[index];
        CpuFastSet(&zero, sprite, 0x01000018);
        gMsgSprites[index].init = profile->init;
        gMsgSprites[index].destroy = profile->destroy;
        gMsgSprites[index].update = profile->update;
        gMsgSprites[index].draw = profile->draw;
        sprite->_57 = type;
        gMsgSprites[index]._2C = x;
        gMsgSprites[index]._30 = y;
        gMsgSprites[index]._14 = param;
        if (sprite->init != NULL) {
            sprite->init(sprite);
        }
        result = sprite;
    }
    return result;
}

static inline s32 mMsg_ScanSpriteType(u8 type) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 == type) {
            break;
        }
    }
    return i;
}

/* Original address: 0x0201C3C8 */
s32 mMsg_FindSpriteByType(u8 type) {
    s32 index = mMsg_ScanSpriteType(type);

    if (index >= 12) {
        index = -1;
    }
    return index;
}

/* Original address: 0x0201C3F8 */
s32 mMsg_IsSpriteAnimationFinished(m_msg_sprite_c *sprite, AnimFrameData *const *animations) {
    s32 finished = 0;
    AnimFrameData *frames = animations[sprite->animation_index];

    if (sprite->frame_timer == 0 && frames[sprite->frame_index + 1].sprite_gfx_p == NULL) {
        finished = 1;
    }
    return finished;
}

/* Original address: 0x0201C428 */
void mMsg_StartSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations, s16 animation) {
    sprite->animation_index = animation;
    sprite->frame_timer = animations[sprite->animation_index][0].duration;
    sprite->frame_index = 0;
}

/* Original address: 0x0201C444 */
void mMsg_UpdateSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations) {
    AnimFrameData *frames = animations[sprite->animation_index];

    if (sprite->frame_timer - 1 <= 0) {
        u8 action_flag;

        if (frames[sprite->frame_index + 1].sprite_gfx_p == NULL) {
            action_flag = (u8)frames[sprite->frame_index].action_flag;
            if (action_flag != 0) {
                sprite->frame_index = 0;
            } else {
                sprite->frame_timer = 0;
                return;
            }
        } else {
            sprite->frame_index++;
        }
        sprite->frame_timer = frames[sprite->frame_index].duration;
    } else {
        sprite->frame_timer--;
    }
}

/* Original address: 0x0201C490 */
void mMsg_CopySpriteOam(m_msg_sprite_c *sprite, IslanderOamData *source, IslanderOamData *dest) {
    dest->y = source->y + sprite->_30 + sprite->offset_y;
    dest->affine_mode = source->affine_mode;
    dest->obj_mode = source->obj_mode;
    dest->mosaic = source->mosaic;
    dest->bpp = source->bpp;
    dest->shape = source->shape;
    dest->x = source->x + sprite->_2C + sprite->offset_x;
    dest->matrix_num = source->matrix_num;
    dest->h_flip = source->h_flip;
    dest->v_flip = source->v_flip;
    dest->size = source->size;
    dest->tile_num = source->tile_num;
    dest->priority = source->priority;
    dest->palette_num = source->palette_num;
    dest->affine_param = source->affine_param;
}

/* Original address: 0x0201C5A0 */
void mMsg_UpdateAndDrawSprites(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 != 0 && gMsgSprites[i].update != NULL) {
            gMsgSprites[i].update(&gMsgSprites[i]);
        }
    }
    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 != 0 && gMsgSprites[i].draw != NULL) {
            gMsgSprites[i].draw(&gMsgSprites[i]);
        }
    }
}

void sub_0201C5F8(void *arg0) {

}

/* Original address: 0x0202B37C */
extern const u8 sMsgContinuePromptRed[8];
/* Original address: 0x0202B384 */
extern const u8 sMsgContinuePromptGreen[8];
/* Original address: 0x0202B38C */
extern const u8 sMsgContinuePromptBlue[8];

/* Original address: 0x0201C5FC */
void mMsg_ContinuePromptSetColor(s32 arg0) {
    u8 red[8];
    u8 green[8];
    u8 blue[8];

    memcpy(red, sMsgContinuePromptRed, sizeof(red));
    memcpy(green, sMsgContinuePromptGreen, sizeof(green));
    memcpy(blue, sMsgContinuePromptBlue, sizeof(blue));
    SetPaletteColor(1U, 7U, 6U, red[arg0], green[arg0], blue[arg0]);
    CpuFastSet(&gObjPaletteBuffer[7 * 16], (void *)(OBJ_PLTT + PLTT_OFFSET_4BPP(7)), 8U);
}

/* Original address: 0x0201C668 */
void mMsg_ContinuePromptCycleColor(m_msg_sprite_c *sprite) {
    mMsg_ContinuePromptSetColor((sprite->color_phase & 3) + sprite->_14 * 4);
    sprite->color_timer++;
    if (sprite->color_timer > 10) {
        sprite->color_phase++;
        sprite->color_timer = 0;
    }
    sub_0201C5F8(sprite);
}

/* Original address: 0x0201C69C */
void mMsg_ContinuePromptInit(m_msg_sprite_c *sprite) {
    mMsg_StartSpriteAnimation(sprite, sMsgContinuePromptAnimations, 0);
    sub_0201C5F8(sprite);
    sprite->state_proc = mMsg_ContinuePromptCycleColor;
    sprite->state_proc(sprite);
}

/* Original address: 0x0201C6C8 */
void mMsg_ContinuePromptDestroy(m_msg_sprite_c* sprite) {

}

/* Original address: 0x0201C6CC */
void mMsg_ContinuePromptUpdate(m_msg_sprite_c* sprite) {
    if (sprite->state_proc != NULL) {
        sprite->state_proc(sprite);
    }
    mMsg_UpdateSpriteAnimation(sprite, sMsgContinuePromptAnimations);
}

/* Original address: 0x0201C6EC */
void mMsg_ContinuePromptDraw(m_msg_sprite_c* sprite) {
    IslanderOamData* oam = sMsgContinuePromptAnimations[sprite->animation_index]->sprite_gfx_p;

    while (oam->affine_param != 0xFFFF) {
        mMsg_CopySpriteOam(sprite, oam, (IslanderOamData *)gUnk3002410 + gGameState.oam_count);
        gGameState.oam_count++;
        oam++;
    }
}

/* Original address: 0x0201C740 */
void mMsg_ChoiceCursorIdle(m_msg_sprite_c *sprite) {

}

/* Original address: 0x0201C744 */
void mMsg_ChoiceCursorInit(m_msg_sprite_c *sprite) {
    mMsg_StartSpriteAnimation(sprite, sMsgChoiceCursorAnimations, 0);
    sprite->state_proc = mMsg_ChoiceCursorIdle;
    sprite->state_proc(sprite);
}

/* Original address: 0x0201C768 */
void mMsg_ChoiceCursorDestroy(m_msg_sprite_c *sprite) {

}

/* Original address: 0x0201C76C */
void mMsg_ChoiceCursorUpdate(m_msg_sprite_c* sprite) {
    if (sprite->state_proc != NULL) {
        sprite->state_proc(sprite);
    }
    mMsg_UpdateSpriteAnimation(sprite, sMsgChoiceCursorAnimations);
}

/* Original address: 0x0201C78C */
void mMsg_ChoiceCursorDraw(m_msg_sprite_c* sprite) {
    IslanderOamData* oam = sMsgChoiceCursorAnimations[sprite->animation_index]->sprite_gfx_p;

    while (oam->affine_param != 0xFFFF) {
        mMsg_CopySpriteOam(sprite, oam, (IslanderOamData *)gUnk3002410 + gGameState.oam_count);
        gGameState.oam_count++;
        oam++;
    }
}

/* Original address: 0x0201C7E0 */
void InitIslandLinkTransfer(s32 unused) {
    u32 zero;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_RCNT = 0;
    ISLAND_SERIAL_WORD = 0x2000;
    REG_SIOCNT |= 0x4003;
    zero = 0;
    CpuSet(&zero, &gIslandLinkWork, 0x05000000 | (sizeof(gIslandLinkWork) / 4));
    gIslandLinkWork.send_packet_index = -1;
    gIslandLinkWork.receive_packet_index = -1;
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

/* Original address: 0x0201C870 */
void StopIslandLinkTransfer(void) {
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0xA4FB;
    REG_IF = 0xC0;
}

/* Original address: 0x0201C8C0 */
s32 UpdateIslandLinkTransfer(void) {
    IslandSerialStatus serial;
    s32 result;

    serial.word = ISLAND_SERIAL_WORD;
    result = -1;
    switch (gIslandLinkWork.state) {
    case 0:
        if (gIslandLinkWork.timeout > 600) {
            u32 connection = serial.word & 0x88;

            result = 16;
            if (connection != 8) {
                result = 8;
            }
        } else if ((u8)(serial.word & 0x88) == 8) {
            u16* data;
            s32 remaining;
            u16 checksum;

            if ((u8)(serial.word & 4) == 0) {
                REG_IME = 0;
                REG_IE &= 0xFF7F;
                REG_IE |= 0x40;
                REG_IME = 1;
                ISLAND_SERIAL_STATUS.bits.irq_enable = 0;
                REG_IF = 0xC0;
                REG_TM3CNT = 0xA4FB;
                gIslandLinkWork.master = 8;
                ISLAND_SERIAL_STATUS.bits.busy = 1;
            }
            data = (u16*)gIslandData;
            gIslandLinkWork.send_data = data;
            gIslandLinkWork.receive_data = (u16*)gIslandTransferData;
            checksum = 0;
            remaining = ISLAND_LINK_HALFWORDS;
            do {
                checksum += *data++;
            } while (--remaining != 0);
            gIslandLinkWork.send_checksum = ~checksum;
            if (gIslandLinkWork.master != 0) {
                REG_TM3CNT_H = 0xC0;
            }
            gIslandLinkWork.timeout = 0;
            gIslandLinkWork.state = 2;
        }
        break;
    case 2:
        if (gIslandLinkWork.serial_error != 0) {
            result = 8;
        } else if ((gIslandLinkWork.connected_players & 1) && (gIslandLinkWork.connected_players & 0xE)) {
            if ((u32)serial.bits.player_id > 1) {
                result = 8;
            } else {
                result = 7;
                gIslandLinkWork.timeout = 0;
                gIslandLinkWork.state = 3;
                GameAudio_PlayEffect2(0x29);
            }
        } else if (gIslandLinkWork.timeout > 600) {
            result = 16;
        } else if (!((gIslandLinkWork.connected_players >> serial.bits.player_id) & 1)) {
            if (gIslandLinkWork.handshake_delay <= 7) {
                gIslandLinkWork.handshake_delay++;
            } else {
                gIslandLinkWork.send_handshake = 1;
            }
        } else {
            gIslandLinkWork.handshake_delay = 0;
        }
        break;
    case 3: {
        s32 received = gIslandLinkWork.receive_index;
        s32 count = received;

        if (gIslandLinkWork.serial_error != 0 || gIslandLinkWork.timeout > 1 || gIslandLinkWork.packet_error != 0) {
            result = 10;
        } else {
            if (received > ISLAND_LINK_HALFWORDS) {
                count = ISLAND_LINK_HALFWORDS;
            } else if (received < 0) {
                count = 0;
            }
            if (gIslandLinkWork.checksum_index < count) {
                IslandLinkWork* work = &gIslandLinkWork;

                do {
                    work->receive_checksum += work->receive_data[work->checksum_index++];
                } while (work->checksum_index < count);
                work->timeout = 0;
            }
            if (received > ISLAND_LINK_HALFWORDS) {
                if ((s16)(gIslandLinkWork.received_checksum + gIslandLinkWork.receive_checksum) == -1) {
                    gIslandLinkWork.checksum_ok = 1;
                } else {
                    gIslandLinkWork.checksum_bad = 1;
                }
                gIslandLinkWork.timeout = 0;
                gIslandLinkWork.state = 4;
            }
        }
        break;
    }
    case 4:
        if (gIslandLinkWork.result == 1) {
            result = 9;
        } else if (gIslandLinkWork.result == -1 || gIslandLinkWork.serial_error != 0 || gIslandLinkWork.timeout > 6) {
            result = 10;
        }
        if (result != -1) {
            gIslandLinkWork.state = 5;
        }
        break;
    }
    gIslandLinkWork.timeout++;
    if (result != -1 && result != 7) {
        u16 sound;

        GameAudio_StopEffect2(0x29);
        sound = 0x28;
        if (result == 9) {
            sound = 0x27;
        }
        GameAudio_PlayEffect0(sound);
        StopIslandLinkTransfer();
    }
    return result;
}

/* Original address: 0x0201CB50 */
void IslandLinkSerialInterrupt(void) {
    union {
        u64 all;
        u16 halfwords[4];
    } received;
    IslandLinkWork *work;
    IslandSerialStatus serial;
    s32 player;
    u16 *data;
    u16 result0;
    u16 result1;
    u16 response;

    received.all = REG_SIOMLT_RECV;
    work = &gIslandLinkWork;
    serial.word = ISLAND_SERIAL_WORD;
    work->serial_error = serial.bits.error;
    if (work->receive_packet_index < 0) {
        player = 0;
        data = received.halfwords;
        do {
            if (*data == 0xFEFE) {
                work->connected_players |= 1 << player;
            }
            data++;
            player++;
        } while (player <= 3);
        if ((work->connected_players & 3) == 3) {
            work->send_packet_index++;
            work->receive_packet_index++;
            work->send_packet_checksum = 0;
            work->receive_packet_checksum = 0;
        }
    } else if (work->receive_packet_index <= 0x1DAD) {
        work->receive_packet_checksum += received.halfwords[serial.bits.player_id ^ 1];
        if ((work->receive_packet_index & 31) == 31) {
            if ((s16)work->receive_packet_checksum != -1) {
                work->packet_error |= 1;
            }
            work->receive_packet_checksum = 0;
        } else {
            s32 index = work->receive_index;
            if (index < ISLAND_LINK_HALFWORDS) {
                work->receive_data[index] = received.halfwords[serial.bits.player_id ^ 1];
                work->receive_index = index + 1;
            }
        }
        work->receive_packet_index++;
    } else if (work->receive_packet_index == 0x1DAE) {
        work->received_checksum = received.halfwords[1 ^ serial.bits.player_id];
        work->receive_packet_index = work->receive_packet_index + 1;
        work->receive_index++;
    } else {
        result0 = received.halfwords[0];
        if (result0 >= 0xFEFC && result0 <= 0xFEFD) {
            result1 = received.halfwords[1];
            if (result1 >= 0xFEFC && result1 <= 0xFEFD) {
                if (result0 == 0xFEFD && result1 == result0) {
                    work->result = 1;
                } else {
                    work->result = -1;
                }
            }
        }
    }
    if (work->send_packet_index < 0) {
        if (work->send_handshake) {
            REG_SIOMLT_SEND = 0xFEFE;
        }
        work->send_packet_checksum = 0;
    } else if (work->send_packet_index <= 0x1DAD) {
        if ((work->send_packet_index & 31) == 31) {
            REG_SIOMLT_SEND = ~work->send_packet_checksum;
            work->send_packet_checksum = 0;
        } else {
            s32 index = work->send_index;
            u16 *send = &work->send_data[index];
            REG_SIOMLT_SEND = *send;
            work->send_packet_checksum += *send;
            work->send_index = index + 1;
        }
        work->send_packet_index++;
    } else if (work->send_packet_index == 0x1DAE) {
        REG_SIOMLT_SEND = work->send_checksum;
        work->send_packet_index = work->send_packet_index + 1;
    } else if (work->send_packet_index > 0x1DAE && (work->checksum_ok || work->checksum_bad)) {
        response = 0xFEFC;
        if (work->checksum_ok) {
            response = 0xFEFD;
        }
        REG_SIOMLT_SEND = response;
    }
    if (work->master == 8) {
        REG_TM3CNT_H = 0;
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}

/* Original address: 0x0201CDA0 */
s32 LoadIslandBuildingTiles(u16 tile_id, s32 pos, u8 acre) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 origin;
    s32 i;
    u32 tilemap;
    const u16 *source;
    const u8 *offset;
    s32 tile;
    u16 *dest;
    u16 *field_tile;

    switch (tile_id) {
    case 1:
        origin = pos - 0x11;
        tilemap = ((u32)BG_SCREEN_ADDR(24) + ((origin & 0xFF0) << 3));
        tilemap += (origin & 15) * 4;
        i = 0;
        source = sCabanaTilemap;
        do {
            tile = *source;
            if (tile != 0) {
                dest = (u16 *)(tilemap + ((i & 0xFF8) << 3));
                dest += i & 7;
                *dest = tile;
            }
            source++;
            i++;
        } while (i <= 63);
        for (i = 0; i <= 15; i++) {
            field->fg_tiles[0][(u8)(origin + sCabanaFootprint[i])] = ITEM_TYPE_CABANA;
        }
        field->entity_active[15] = 1;
        InitIslandBuilding(0, 0, pos, 0);
        break;
    case 2:
        origin = pos - 0x11;
        if (acre == 0) {
            tilemap = ((u32)BG_SCREEN_ADDR(24) + ((origin & 0xFF0) << 3));
        } else {
            tilemap = ((u32)BG_SCREEN_ADDR(25) + ((origin & 0xFF0) << 3));
        }
        tilemap += (origin & 15) * 4;
        i = 0;
        source = sIslanderHouseTilemap;
        do {
            tile = *source;
            if (tile != 0) {
                dest = (u16 *)(tilemap + ((i & 0xFF8) << 3));
                dest += i & 7;
                *dest = tile;
            }
            source++;
            i++;
        } while (i <= 47);
        offset = sIslanderHouseFootprint;
        do {
            if (acre == 0) {
                field_tile = &field->fg_tiles[0][(u8)(*offset + origin)];
            } else {
                field_tile = &field->fg_tiles[1][(u8)(*offset + origin)];
            }
            *field_tile = ITEM_TYPE_ISLANDER_HOUSE;
            offset++;
        } while (offset <= &sIslanderHouseFootprint[8]);
        field->special_tile_idx = origin + 0x21;
        field->entity_active[18] = 1;
        InitIslandBuilding(1, 2, pos, acre);
        break;
    default:
        return 1;
    }
    return 0;
}

/* Original address: 0x0201CF3C */
void LoadIslandFieldEntity(u16 type, s32 pos, u8 acre) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 right_acre = 0;
    s32 left_pos;
    u32 tilemap;
    u16 *dest;
    u16 tile;
    s32 next_tile;
    s32 remaining;
    s32 slot;
    u8 *active;
    u16 ground_tile;
    s32 column_offset;
    u16 *ground;

    switch (type) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        left_pos = (((pos & 15) - 1) & 15) | (pos & 0xF0);
        if (acre == 0 || (left_pos & 15) == 15) {
            dest = (u16 *)BG_SCREEN_ADDR(24);
            field->tile_id_scratch = field->fg_tiles[0][left_pos];
        } else {
            dest = (u16 *)BG_SCREEN_ADDR(25);
            field->tile_id_scratch = field->fg_tiles[1][left_pos];
            right_acre = 1;
        }
        dest = (u16 *)((u32)dest + ((left_pos & 0xFF0) << 3));
        dest += (left_pos & 15) * 2;
        tile = sFieldEntityBaseTiles[type - 5];
        dest += 33;
        if (field->tile_id_scratch == 0xFFF) {
            *dest = tile;
        }
        dest++;
        next_tile = tile + 1;
        remaining = 2;
        do {
            /* Continue the row in the next screen block at an acre boundary. */
            if (right_acre == 0 && (((u32)dest & 0xFF) == 0 || ((u32)dest & 0xFF) == 0x40 ||
                                    ((u32)dest & 0xFF) == 0x80 || ((u32)dest & 0xFF) == 0xC0)) {
                dest += 0x3E0;
            }
            *dest = next_tile;
            remaining--;
            dest++;
            next_tile++;
        } while (remaining >= 0);
        if (type >= 12 && type <= 13) {
            return;
        }
        slot = 0;
        active = &field->entity_active[54];
        do {
            if (*active == 0) {
                *active = 1;
                FieldObject_Init(slot, type, pos, acre);
                return;
            }
            active++;
            slot++;
        } while (slot <= 29);
        break;
    case 19:
        AnimatedFieldObject_Init(84, pos, acre);
        break;
    case 20:
        if (acre == 0) {
            ground = (u16 *)(BG_SCREEN_ADDR(20) + ((pos & 0xFF0) << 3));
            column_offset = (pos & 15) << 2;
            ground = (u16 *)((u32)ground + column_offset);
            tilemap = BG_SCREEN_ADDR(24) + ((pos & 0xFF0) << 3);
        } else {
            ground = (u16 *)(BG_SCREEN_ADDR(21) + ((pos & 0xFF0) << 3));
            column_offset = (pos & 15) << 2;
            ground = (u16 *)((u32)ground + column_offset);
            tilemap = BG_SCREEN_ADDR(25) + ((pos & 0xFF0) << 3);
        }
        dest = (u16 *)(tilemap + column_offset);
        ground_tile = *ground & 0x3FF;
        field->tile_render_scratch = ground_tile;
        if ((ground_tile >= 10 && ground_tile <= 15) || (ground_tile >= 0xC6 && ground_tile <= 0xCB)) {
            *dest++ = 0x22AC;
            *dest = 0x22AD;
            dest += 31;
            *dest = 0x22AE;
            dest[1] = 0x22AF;
        }
        break;
    case 3:
    case 4:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        slot = 0;
        active = &field->entity_active[54];
        do {
            if (*active == 0) {
                *active = 1;
                FieldObject_Init(slot, type, pos, acre);
                return;
            }
            active++;
            slot++;
        } while (slot <= 29);
        break;
    }
}

/* Original address: 0x0201D19C */
void LoadIslandForeground(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    ItemGroupStruct *definition;
    u16 *fg0_tile;
    u16 *fg1_tile;
    u16 *vram_tile;
    u16 tile_id;
    s32 render_offset;
    s32 item_type;
    s32 result;
    s32 pos;

    field->tile_render_scratch = 0x5851;
    pos = 0;
    vram_tile = (u16 *)BG_SCREEN_ADDR(24);
    do {
        *vram_tile = 0x200;
        pos += 2;
        vram_tile++;
    } while (pos <= 0xFFF);

    fg0_tile = field->fg_tiles[0];
    fg1_tile = field->fg_tiles[1];
    pos = 0xFF;
    do {
        *fg0_tile = 0xFFF;
        *fg1_tile = 0xFFF;
        fg1_tile++;
        fg0_tile++;
        pos--;
    } while (pos >= 0);

    for (pos = 0; pos <= 0xFF; pos++) {
        if ((Item_GetTypeIndex(gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF]) & 0x8000) == 0) {
            item_type = Item_GetTypeIndex(gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF]);
            if (item_type <= ITEM_TYPE_RESERVED) {
                definition = &g_ItemDefinitions[item_type];
                if (item_type == ITEM_TYPE_RESERVED) {
                    if (field->fg_tiles[0][pos] == 0xFFF) {
                        field->fg_tiles[0][pos] = 0x7777;
                    }
                } else {
                    field->fg_tiles[0][pos] = item_type;
                }

                if (definition->field_tile_id == 0x270) {
                    gIslandData->deposit[0][(pos >> 4) & 0xF] |= 1 << (pos & 0xF);
                    gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF] = ITM_PITFALL;
                    field->fg_tiles[0][pos] = 0x10;
                }

                if (item_type != ITEM_TYPE_RESERVED) {
                    result = LoadIslandBuildingTiles(definition->field_tile_id, pos, 0);
                    if (result == 1) {
                        tile_id = definition->field_tile_id;
                        field->tile_id_scratch = tile_id;
                        if ((gIslandData->deposit[0][(pos >> 4) & 0xF] >> (pos & 0xF)) & result) {
                            field->tile_id_scratch = 0x1270;
                        }

                        render_offset = 0;
                        field->tile_render_scratch = 0;
                        do {
                            vram_tile = (u16 *)((u32)BG_SCREEN_ADDR(24) + render_offset +
                                                ((pos & 0xFF0) << 3) + ((pos & 0xF) << 2));
                            vram_tile[0] = field->tile_render_scratch +
                                           field->tile_id_scratch;
                            vram_tile[1] = field->tile_render_scratch +
                                           field->tile_id_scratch + 1;
                            render_offset += 0x40;
                            field->tile_render_scratch = 2;
                        } while (render_offset <= 0x4F);

                        LoadIslandFieldEntity(definition->field_entity_type, pos, 0);
                    }
                }
            }
        }

        if ((Item_GetTypeIndex(gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF]) & 0x8000) == 0) {
            item_type = Item_GetTypeIndex(gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF]);
            if (item_type <= ITEM_TYPE_RESERVED) {
                definition = &g_ItemDefinitions[item_type];
                if (item_type == ITEM_TYPE_RESERVED) {
                    if (field->fg_tiles[1][pos] == 0xFFF) {
                        field->fg_tiles[1][pos] = 0x7777;
                    }
                } else {
                    field->fg_tiles[1][pos] = item_type;
                }

                if (definition->field_tile_id == 0x270) {
                    gIslandData->deposit[1][(pos >> 4) & 0xF] |= 1 << (pos & 0xF);
                    gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF] = 0x2512;
                    field->fg_tiles[1][pos] = 0x10;
                }

                if (item_type != ITEM_TYPE_RESERVED) {
                    result = LoadIslandBuildingTiles(definition->field_tile_id, pos, 1);
                    if (result == 1) {
                        tile_id = definition->field_tile_id;
                        field->tile_id_scratch = tile_id;
                        if ((gIslandData->deposit[1][(pos >> 4) & 0xF] >> (pos & 0xF)) & result) {
                            field->tile_id_scratch = 0x1270;
                        }

                        render_offset = 0;
                        field->tile_render_scratch = 0;
                        do {
                            vram_tile = (u16 *)((u32)BG_SCREEN_ADDR(25) + render_offset +
                                                ((pos & 0xFF0) << 3) + ((pos & 0xF) << 2));
                            vram_tile[0] = field->tile_render_scratch +
                                           field->tile_id_scratch;
                            vram_tile[1] = field->tile_render_scratch +
                                           field->tile_id_scratch + 1;
                            render_offset += 0x40;
                            field->tile_render_scratch = 2;
                        } while (render_offset <= 0x4F);

                        LoadIslandFieldEntity(definition->field_entity_type, pos, 1);
                    }
                }
            }
        }
    }
}

/* Original address: 0x0201D550 */
void UpdateHourlyPalette(void) {
    u16 *palette0;
    u16 *palette1;
    s32 i;
    u16 color;
    u16 palette_index;
    u8 hour;
    IslandFieldWork *field = &gIslandFieldWork;

    hour = gGameState.game_time_frames / (60 * 60 * 60);
    if (field->last_palette_hour != hour) {
        do { i = 0; } while (0);
        palette0 = current_time_of_day_palette0 + 1;
        palette1 = current_time_of_day_palette1 + 1;
        do {
            palette_index = (hour << 2) + i;
            color = time_of_day_palettes[palette_index];
            *palette0 = color;
            *palette1 = color;
            i++;
            palette0++;
            palette1++;
        } while (i < 4);

        field->last_palette_hour = hour;
    }
}

static inline void LoadAcreTilemap(s32 terrain, s32 acre) {
    switch (terrain) {
    case 0:
        DmaCopy32(3, sIslandLeftAcreTilemaps[0], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 1:
        DmaCopy32(3, sIslandLeftAcreTilemaps[1], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 2:
        DmaCopy32(3, sIslandLeftAcreTilemaps[2], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 3:
        DmaCopy32(3, sIslandLeftAcreTilemaps[3], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    }
}

void InitIslandField(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 terrain;
    s32 i;
    u8 hour = gGameState.game_time_frames / (60 * 60 * 60);

    if (field->last_palette_hour != hour) {
        {
            u16 *palette0;
            u16 *palette1;
            u16 color;
            u16 palette_index;
        
        
            i = 0;
            palette0 = current_time_of_day_palette0;
            palette1 = current_time_of_day_palette1;
            do {
                palette_index = (hour << 2) + i;
                color = time_of_day_palettes[palette_index];
                *palette0 = color;
                *palette1 = color;
                i++;
                palette0++;
                palette1++;
            } while (i < 4);
        }
        field->last_palette_hour = hour;
    }
    field->last_palette_hour = 0xFF;
    field->entity_active[0] = 1;
    PlayerHand_Init();
    Islander_Init();
    field->palette_anim_timer = 4;
    field->palette_anim_frame = 0;
    field->unk_499 = 0;
    field->special_tile_idx = 0;
    field->entity_dist_x = 0;
    field->entity_dist_y = 0;
    field->bg3_scroll_y = 0;
    field->unk_004 = 0;
    field->transition_state = 0;
    field->mosaic = 0;
    field->unk_49D = 0;
    terrain = gIslandData->bg_data[0] & 3;
    field->transition_proc_idx = 0;
    LoadAcreTilemap(terrain, 0);
    terrain = gIslandData->bg_data[1] & 3;
    LoadAcreTilemap(terrain, 1);

    for (i = 0; i < ARRAY_COUNT(field->entity_active); i++) {
        field->entity_active[i] = 0;
    }
    LoadIslandForeground();
}

/* Original address: 0x0201D7AC */
void ExpandIslandBg3(void) {
    if (!(0xC000 & REG_BG3CNT)) {
        gGameState.bg3cnt = (0xC000 | gGameState.bg3cnt) ^ 0x300;
        if (gIslandData->weather != 0) {
            Sound_StopEffect2(0x26U);
        }
    }
}

/* Original address: 0x0201D800 */
s32 UpdateIslandMosaic(u8 cover) {
    IslandFieldWork *field = &gIslandFieldWork;

    if (cover != 0) {
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        field->mosaic += 0x1111;
        if (field->mosaic == 0xFFFF) {
            field->transition_state = 2;
            REG_MOSAIC = field->mosaic;
            return 1;
        } else {
            REG_MOSAIC = field->mosaic;
            return 0;
        }
    } else if (gGameState.bg1cnt & 0x40) {
        if (field->mosaic == 0) {
            field->mosaic = 0xFFFF;
        }
        field->transition_state = 0;
        field->transition_proc_idx = 0;
        field->mosaic -= 0x1111;
        if (field->mosaic == 0) {
            gGameState.bg1cnt ^= 0x40;
            gGameState.bg2cnt ^= 0x40;
            gGameState.bg3cnt ^= 0x40;
            REG_MOSAIC = field->mosaic;
            return 1;
        } else {
            REG_MOSAIC = field->mosaic;
            return 0;
        }
    }
    return 1;
}

/* Original address: 0x0201D904 */
s32 UpdateIslandField(void) {
    IslandFieldWork *field = &gIslandFieldWork;

    REG_MOSAIC = 0;
    sIslandFieldUpdateProcs[field->transition_proc_idx]();
    if (field->transition_state == 3) {
        return 1;
    }
    return 0;
}

/* Original address: 0x0201D94C */
void GameStateUpdateFunc_Normal(void) {
    Islander_AGB *islander = &gIslander;
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    u16 palette_index;
    u8 frame;
    s32 scroll_y;
    u16 *palette2;
    u16 *palette0;
    s32 camera_y;
    u16 mosaic_enabled;
    s32 mosaic_complete;
    u8 joybus_notice_requested;
    u8 sleep_requested;

    UpdateHourlyPalette();
    gGameState.bldcnt = 0x3E41;
    gGameState.bldalpha = 0x1006;
    if (islander->carry_state != 1) {
        mosaic_complete = UpdateIslandMosaic(0U);
        if (mosaic_complete == 0) {
            gGameState.bg1_hofs = ((s32) player->x >> 8) - 0x80;
            camera_y = ((s32) player->y >> 8) - 0x50;
            gGameState.bg1_vofs = camera_y;
            if (camera_y & 0x800) {
                gGameState.bg1_vofs = 0;
            }
            if ((u32) gGameState.bg1_vofs > 0x60U) {
                gGameState.bg1_vofs = 0x60;
            }
            if (0x800 & gGameState.bg1_hofs) {
                gGameState.bg1_hofs = 0;
            }
            if ((u32) gGameState.bg1_hofs > 0x100U) {
                gGameState.bg1_hofs = 0x100;
            }
            ChangeEmotion((u8) (islander->emotion + 1));
            gGameState.bg2_hofs = gGameState.bg1_hofs;
            gGameState.bg2_vofs = gGameState.bg1_vofs;
            field->gameplay_active = 1;
            return;
        }
    }
    joybus_notice_requested = gGameState.joybus_notice_requested;
    if ((joybus_notice_requested == 1) && (islander->carry_state != 1)) {
        Sound_StopMusic(0x14U);
        Sound_InitMusic();
        field->mosaic = 0;
        field->unk_49D = 0;
        field->gameplay_active = 0;
        field->transition_state = joybus_notice_requested;
        field->transition_proc_idx = joybus_notice_requested;
        return;
    }
    sleep_requested = gGameState.sleep_requested;
    if ((sleep_requested == 1) && (islander->carry_state != 1)) {
        Sound_StopMusic(0x14U);
        Sound_InitMusic();
        field->mosaic = 0U;
        field->unk_49D = 0;
        field->gameplay_active = 0;
        field->transition_state = sleep_requested;
        field->transition_proc_idx = 2U;
        return;
    }
    if ((2 & gGameState.keys.buttons.pressed) && (islander->carry_state != 1)) {
        mosaic_enabled = 0x40 & gGameState.bg1cnt;
        if (mosaic_enabled == 0) {
            Sound_StopMusic(0x14U);
            Sound_InitMusic();
            field->mosaic = mosaic_enabled;
            field->unk_49D = 0;
            field->gameplay_active = 0;
            field->transition_state = 1U;
            field->transition_proc_idx = 3U;
            return;
        }
    }
    if ((0xC000 & REG_BG3CNT) && (0xC000 & gGameState.bg3cnt)) {
        gGameState.bg3cnt = (0xC000 ^ gGameState.bg3cnt) | 0x300;
        if (gIslandData->weather != 0) {
            Sound_PlayEffect2(0x26U);
        }
    }
    if (--field->palette_anim_timer == 0) {
        field->palette_anim_timer = 8;
        palette0 = gFieldPaletteBuffer;
        palette2 = gFieldPaletteBuffer2;
        frame = field->palette_anim_frame;
        i = 0;
        do {
            palette_index = frame * 16 + i;
            *palette0 = sFieldPaletteAnimation0[palette_index];
            *palette2 = sFieldPaletteAnimation2[palette_index];
            i += 1;
            palette0++;
            palette2++;
        } while (i <= 0xF);
        if (++field->palette_anim_frame > 13) {
            field->palette_anim_frame = 0U;
        }
    }
    CpuSet(gFieldPaletteBuffer, (void *)PLTT, 0x200U);
    gGameState.bg3_hofs = gGameState.bg1_hofs;
    scroll_y = field->bg3_scroll_y + 0x40;
    field->bg3_scroll_y = scroll_y;
    gGameState.bg3_vofs = (u16) ((s32) (gGameState.bg1_vofs + scroll_y) >> 8);
    PlayerHand_Update();
    Islander_UpdateMovement();
    i = 0;
    do {
        if (field->entity_active[i + 21] == 1) {
            FallingFruit_Update(i);
        }
        i += 1;
    } while (i <= 0x1D);
    i = 0;
    do {
        if (field->entity_active[i + 54] == 1) {
            FieldObject_Update(i);
        }
        i += 1;
    } while (i <= 0x1D);
    if (field->entity_active[2] == 1) {
        Entity_Update(2);
    }
    i = 3;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_Update(i);
        }
        i += 1;
    } while (i <= 0xB);
    IslandBuilding_Update(1U, 2);
    AnimatedFieldObject_Update(0x54);
}

/* Original address: 0x0201DCE4 */
void IslandField_UpdateJoybusExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gGameState.joybus_notice_active = 1;
        gIslandFieldWork.transition_state = 3;
    }
}

/* Original address: 0x0201DD24 */
void IslandField_UpdateSleepExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gGameState.sleep_dialog_active = 1;
        gIslandFieldWork.transition_state = 3;
    }
}

/* Original address: 0x0201DD64 */
void IslandField_UpdateOverviewExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gIslandFieldWork.transition_state = 3;
    }
}

static inline void DrawIslanderBehindFieldObjects(Islander_AGB *islander) {
    if (islander->move_action == 0x14) {
        if (islander->carry_state == 2) {
            Islander_Draw();
        }
    }
}

/* Original address: 0x0201DD94 */
void DrawIslandField(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    s32 house_drawn;
    s32 islander_drawn;
    s32 distance_y;
    s32 distance_x;
    s32 islander_y;
    s32 entity;
    s32 cabana_drawn;
    u32 entity_id;

    gGameState.oam_count = 0;
    if (field->entity_active[2] == 1) {
        Entity_DrawSprite(2);
    }
    DrawIslanderBehindFieldObjects(islander);
    i = 0;
    do {
        if (field->entity_active[i] == 1) {
            PlayerHand_Draw();
        }
        i += 1;
    } while (i <= 1);
    i = 3;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_DrawSprite(i);
        }
        i += 1;
    } while (i <= 0xB);
    AnimatedFieldObject_Draw(0x54);
    cabana_drawn = 0;
    house_drawn = 0;
    islander_drawn = 0;
    for (i = 0x1E; i >= 0; i--) {
        if (field->entity_active[i + 54] == 1) {
            FieldObject *object = &gFieldObjects[i];
            if ((cabana_drawn == 0) && ((u32) gIslandBuildings[0].tile_idx > (u32) object->tile_idx)) {
                IslandBuilding_Draw(0, 0U);
                cabana_drawn = 1;
            }
            if ((house_drawn == 0) && ((u32) gIslandBuildings[1].tile_idx > (u32) object->tile_idx)) {
                IslandBuilding_Draw(1, 2U);
                house_drawn = 1;
            }
            entity_id = object->falling_fruit_id;
            if (entity_id != 0) {
                if (entity_id != 0xFFFF) {
                    FallingFruit_Draw(entity_id - 1);
                } else {
                    entity = 0;
                    do {
                        if (field->entity_active[entity + 21] == 1) {
                            FallingFruit_Draw(entity);
                        }
                        entity += 1;
                    } while (entity <= 2);
                }
            }
            distance_x = object->x - (islander->x >> 8);
            field->entity_dist_x = distance_x;
            islander_y = islander->y;
            field->entity_dist_y = object->y - (islander_y >> 8);
            if (distance_x < 0) {
                field->entity_dist_x = -distance_x;
            }
            distance_y = field->entity_dist_y;
            if (distance_y < 0) {
                field->entity_dist_y = -distance_y;
            }
            if (field->entity_dist_x <= 0x10 && field->entity_dist_y <= 0x10 &&
                (object->tile_idx & 0xF0) < (((islander_y + 0xD00) >> 8) & 0xF0) &&
                islander_drawn == 0) {
                Islander_Draw();
                islander_drawn = 1;
            }
            FieldObject_Draw(i);
        }
    }
    if (cabana_drawn == 0) {
        IslandBuilding_Draw(0, 0U);
    }
    if (house_drawn == 0) {
        IslandBuilding_Draw(1, 2U);
    }
    if (islander_drawn == 0) {
        Islander_Draw();
    }
    IslandBuilding_Draw(1, 1U);
    i = 0;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_DrawFloatingItemShadow(i);
        }
        i += 1;
    } while (i <= 0xB);
}

/* Original address: 0x0201DF9C */
void InitIslandBuilding(s32 index, u8 type, s32 tile, u8 acre) {
    IslandBuilding *building = &gIslandBuildings[index];
    Islander_AGB *islander = &gIslander;

    if (type == 0) {
        building->y = (tile & 0xFFF0) + 16;
        building->x = (tile & 0xF) * 16 + 16;
    } else {
        building->y = (tile & 0xFFF0) + 8;
        if (acre == 0) {
            building->x = (tile & 0xF) * 16 + 8;
        } else {
            building->x = (tile & 0xF) * 16 + 0x108;
        }
        islander->x = building->x << 8;
        islander->y = (building->y << 8) + 0x100;
        islander->accepted_x = islander->x;
        islander->accepted_y = islander->y;
        building->interaction_x = building->x - 8;
        building->interaction_y = building->y - 4;
    }
    building->tile_idx = tile;
    building->state = 1;
}

void sub_0201E030(void) {

}

void sub_0201E034(void) {

}

typedef void (*IslandBuilding_PROC)(void);

// Original address: 0x0202FD38
extern IslandBuilding_PROC gIslandBuildingProcs[2];

/* Original address: 0x0201E038 */
void IslandBuilding_Update(u8 arg0, u8 arg1) {
    IslandBuilding *building = &gIslandBuildings[1];

    if (arg1 == 2) {
        gIslandBuildingProcs[building->state]();
    }
}

/* Original address: 0x0201E060 */
void IslandBuilding_DrawSprite(IslandBuildingSprite *sprite, s32 building_index, u8 sprite_index) {
    IslandBuilding *building = &gIslandBuildings[building_index];
    IslanderOamData *oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];

    if (sprite_index != 5 || building->state == 1) {
        oam->shape = (sprite->oam_attributes >> 14) & 3;
        oam->size = sprite->oam_attributes >> 30;
        oam->h_flip = sprite->h_flip;
        oam->v_flip = sprite->v_flip;
        oam->palette_num = sprite->palette_num;
        oam->priority = 1;
        oam->x = sprite->x_offset + (building->x - gGameState.bg2_hofs);
        oam->y = sprite->y_offset + (building->y - (u8)gGameState.bg2_vofs);
        oam->tile_num = sprite->tile_num;
        oam->mosaic = 1;
    }
    gGameState.oam_count++;
}

/* Original address: 0x0201E178 */
void IslandBuilding_Draw(s32 building_index, u8 part) {
    s32 first = 0;
    s32 end = 0;
    s32 i;

    switch (part) {
    case 0:
        first = 0;
        end = 3;
        break;
    case 2:
        first = 3;
        end = 5;
        break;
    case 1:
        first = 5;
        end = 6;
        break;
    }
    for (i = first; i < end; i++) {
        IslandBuilding_DrawSprite(&sIslandBuildingSprites[i], building_index, i);
    }
}

/* Original address: 0x0201E1E0 */
void AnimatedFieldObject_Init(s32 index, s32 tile, u8 acre) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];

    object->x = 0;
    if (acre != 0) {
        object->x = 0x100;
    }
    object->x |= (tile & 0xF) * 16 + 12;
    object->y = (tile & 0xF0) + 8;
    object->anim_timer = 0;
    object->anim_frame = 0;
    object->anim_timer = sFieldAnimationFrames[0]->duration;
}

/* Original address: 0x0201E230 */
void AnimatedFieldObject_Update(s32 index) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];

    object->anim_timer--;
    if (object->anim_timer == 0) {
        object->anim_frame++;
        if ((u8)sFieldAnimationFrames[object->anim_frame]->action_flag == 0xFF) {
            object->anim_frame = 0;
        }
        object->anim_timer = sFieldAnimationFrames[object->anim_frame]->duration;
    }
}

/* Original address: 0x0201E27C */
void AnimatedFieldObject_Draw(s32 index) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];
    IslanderOamData *source = sFieldAnimationFrames[object->anim_frame]->sprite_gfx_p;

    while (source->affine_param != 0xFFFF) {
        IslanderOamData *oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];

        oam->y = source->y + object->y - (u8)gGameState.bg2_vofs;
        oam->obj_mode = source->obj_mode;
        oam->bpp = source->bpp;
        oam->shape = source->shape;
        oam->h_flip = source->h_flip;
        oam->v_flip = source->v_flip;
        oam->size = source->size;
        oam->x = source->x + object->x - gGameState.bg2_hofs;
        oam->tile_num = source->tile_num;
        oam->mosaic = 1;
        oam->priority = 1;
        oam->palette_num = source->palette_num;
        gGameState.oam_count++;
        source++;
    }
}

/* Original address: 0x0201E3DC */
void FieldObject_AttachEntity(s32 object_index, s32 type) {
    FieldObject *object;
    IslandFieldWork *field;
    s32 slot;

    object = gFieldObjects + object_index;
    field = &gIslandFieldWork;
    for (slot = 3; slot < 30; slot++) {
        if (field->entity_active[slot + 24] == 0) {
            field->entity_active[slot + 24] = 1;
            FallingFruit_Init(object_index, slot, type, object->layer);
            object->falling_fruit_id = slot + 1;
            break;
        }
    }
}

/* Original address: 0x0201E430 */
void FieldObject_Init(s32 object_index, u16 type, s32 tile, u8 layer) {
    FieldObject *object;
    s32 tile_x;

    object = &gFieldObjects[object_index];
    object->type = type;
    object->x_flip = 0;
    object->rotation = 0;
    object->topple_x_offset = 0;
    object->topple_y_offset = 0;
    object->topple_extra_x_offset = 0;
    object->action_state = 0;
    object->anim_counter = 0;
    object->anim_frame = 0;
    object->anim_timer = 0;
    object->hits_remaining = 0;
    object->falling_fruit_id = 0;
    object->fruit_drop_processed = 0;
    object->drop_tile_x = 0;
    object->drop_tile_y = 0;
    object->drop_existing_item = 0;
    object->shake_animation_paused = 0;
    object->favorite_hour_item_eligible = 0;
    object->y = (0xF0 & tile) + 8;
    tile_x = (0xF & tile) * 0x10;
    object->x = tile_x + 8;
    object->tile_idx = tile & 0xFF;
    if (layer != 0) {
        object->x = tile_x + 0x108;
    }
    object->hits_remaining = sFieldObjectInitialTimers[object->type];
    object->layer = layer;
    if (object->type == 0x12) {
        FieldObject_AttachEntity(object_index, 0U);
    }
    if (object->type == 7) {
        FieldObject_AttachEntity(object_index, 3U);
    }
    if (object->type == 8) {
        FieldObject_AttachEntity(object_index, 7U);
    }
    if (object->type == 9) {
        FieldObject_AttachEntity(object_index, 0xBU);
    }
    if (object->type == 0xA) {
        FieldObject_AttachEntity(object_index, 0xFU);
    }
    if (object->type == 0xB) {
        FieldObject_AttachEntity(object_index, 0x13U);
    }
    if (object->type == 6) {
        object->favorite_hour_item_eligible = 1;
    }
}

typedef void (*FieldObject_PROC)(int);

// Original address: 0x0202FECC
extern FieldObject_PROC gFieldObjectProcs[];

/* Original address: 0x0201E538 */
void FieldObject_Update(s32 idx) {
    FieldObject *object = &gFieldObjects[idx];
    gFieldObjectProcs[object->action_state](idx);
}

/* Original address: 0x0201E560 */
void FieldObject_Idle(s32 idx) {

}

/* Original address: 0x0201E564 */
void FieldObject_SpawnToppleEffect(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 slot;
    Entity *entity;
    s32 offset_x;
    s32 offset_y;

    if (object->type != 3 && object->type != 14) {
        for (slot = 3; slot < 10; slot++) {
            if (field->entity_active[slot + 3] == 0) {
                entity = &g_EntityTable[slot];
                field->entity_active[slot + 3] = 1;
                Entity_Reset(slot);
                offset_x = 16 - rand_u16(&gGameState) % 33;
                offset_y = rand_u16(&gGameState) % 17 + 16;
                if (object->type == 4) {
                    offset_y = 16;
                }
                entity->x = object->x + offset_x;
                entity->y = object->y - offset_y;
                entity->update_type = 1;
                break;
            }
        }
    }
}

/* Original address: 0x0201E608 */
void FieldObject_UpdateForegroundItem(s32 object_index) {
    FieldObject *object;
    s16 item;

    object = &gFieldObjects[object_index];
    item = 0;
    if (object->action_state == 3) {
        if (object->type == 3) {
            item = 1;
        }
        if (object->type == 4) {
            item = 2;
        }
        if (object->type == 5) {
            item = 3;
        }
        if (object->type == 6) {
            item = 4;
        }
        if (object->type == 0xE) {
            item = 0x70;
        }
        if (object->type == 0xF) {
            item = 0x71;
        }
        if (object->type == 0x10) {
            item = 0x72;
        }
        if (object->type == 0x11) {
            item = 0x73;
        }
    } else {
        if (object->type == 0x12) {
            item = 0x858;
            object->type = 0x11;
        }
        if (object->type == 7) {
            item = 0x809;
            object->type = 6;
        }
        if (object->type == 8) {
            item = 0x811;
            object->type = 6;
        }
        if (object->type == 9) {
            item = 0x819;
            object->type = 6;
        }
        if (object->type == 0xA) {
            item = 0x821;
            object->type = 6;
        }
        if (object->type == 0xB) {
            item = 0x829;
            object->type = 6;
        }
    }
    if (!(object->x & 0x100)) {
        gIslandData->fgblock[0][0].items[(object->tile_idx >> 4) & 0xF][object->tile_idx & 0xF] = item;
    } else {
        gIslandData->fgblock[0][1].items[(object->tile_idx >> 4) & 0xF][object->tile_idx & 0xF] = item;
    }
}

/* Original address: 0x0201E710 */
void FieldObject_HandleHit(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 fruit_index;
    s32 timer;
    u32 x;
    u32 y;
    u16 tile_x;
    u16 tile_y;
    s32 candidate;
    u16 tile;
    u16 fg_tile;
    u8 acre;
    FallingFruit *fruit;

    timer = object->hits_remaining;
    if (timer == 0 || (timer & 0x80)) {
        FieldObject_SpawnToppleEffect(object_index);
        object->anim_timer = 8;
        object->anim_counter = 0;
        object->rotation_threshold = 0xFFFF;
        object->action_state = 3;
        FieldObject_UpdateForegroundItem(object_index);
        Sound_PlayEffect0(0x13);
    } else {
        Sound_PlayEffect0(0x18);
        object->anim_timer = 2;
        object->anim_counter = 0;
        object->anim_frame = 0;
        object->action_state = 2;
    }
    if (object->falling_fruit_id == 0) {
        return;
    }
    if (object->fruit_drop_processed != 0) {
        return;
    }
    for (fruit_index = 0; fruit_index < 3; fruit_index++) {
        if (field->entity_active[fruit_index + 21] == 1 && object->falling_fruit_id != 0) {
            field->entity_active[object->falling_fruit_id + 23] = 0;
            object->falling_fruit_id = 0;
            return;
        }
        for (candidate = 0; candidate < 4; candidate++) {
            tile = object->tile_idx;
            y = (tile + sFruitDropOffsetsY[fruit_index][candidate] * 16) & 0xF0;
            object->drop_tile_y = y;
            x = ((tile & 0xF) + sFruitDropOffsetsX[fruit_index][candidate]) & 0xF;
            object->drop_tile_x = x;
            acre = 0;
            if (object->layer == 0) {
                object->drop_existing_item = gIslandData->fgblock[0][0].items[y >> 4][object->drop_tile_x];
                fg_tile = field->fg_tiles[0][x | y];
                if (x <= 1) {
                    acre = 1;
                    object->drop_existing_item = gIslandData->fgblock[0][1].items[y >> 4][object->drop_tile_x];
                    fg_tile = field->fg_tiles[1][x | y];
                }
            }
            if (object->layer != 0) {
                acre = 1;
                tile_x = object->drop_tile_x;
                tile_y = object->drop_tile_y;
                object->drop_existing_item = gIslandData->fgblock[0][1].items[tile_y >> 4][tile_x & 0xF];
                fg_tile = field->fg_tiles[1][(u8)(tile_y + tile_x)];
                if (tile_x > 13) {
                    acre = 0;
                    object->drop_existing_item = gIslandData->fgblock[0][0].items[tile_y >> 4][tile_x & 0xF];
                    fg_tile = field->fg_tiles[0][(u8)(tile_y + tile_x)];
                }
            }
            if (acre == 0) {
                object->drop_tilemap = (u16 *)BG_SCREEN_ADDR(20);
            } else {
                object->drop_tilemap = (u16 *)BG_SCREEN_ADDR(21);
            }
            object->drop_tilemap = object->drop_tilemap + ((object->drop_tile_y + object->drop_tile_x) & 0xF0) * 4 +
                                   ((object->drop_tile_y + object->drop_tile_x) & 0xF) * 2;
            if ((object->drop_existing_item == 0 && fg_tile == 0xFFF &&
                 (u16)((*object->drop_tilemap & 0x3FF) - 0x20) <= 0x5E) || candidate == 3) {
                field->entity_active[fruit_index + 21] = 1;
                if (object->type == 18) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 1, acre);
                }
                if (object->type == 7) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 4, acre);
                }
                if (object->type == 8) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 8, acre);
                }
                if (object->type == 9) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 12, acre);
                }
                if (object->type == 10) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 16, acre);
                }
                if (object->type == 11) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 20, acre);
                }
                if (acre == 0) {
                    field->fg_tiles[0][(u8)(object->drop_tile_y + (u8)object->drop_tile_x)] = 0x7777;
                } else {
                    field->fg_tiles[1][(u8)(object->drop_tile_y + (u8)object->drop_tile_x)] = 0x7777;
                }
                fruit = &gFallingFruit[fruit_index];
                fruit->landing_x = object->drop_tile_x * 16;
                if (acre != 0) {
                    fruit->landing_x |= 0x100;
                }
                fruit->landing_y = object->drop_tile_y;
                fruit->tile_idx = object->drop_tile_x + object->drop_tile_y;
                if (object->drop_existing_item == 0 && fg_tile == 0xFFF) {
                    fruit->can_land = 1;
                }
                break;
            }
        }
        if (object->type == 18 && fruit_index == 1) {
            break;
        }
    }
    FieldObject_UpdateForegroundItem(object_index);
    if (object->action_state == 3) {
        if (object->layer == 0) {
            if (object->type == 18) {
                field->fg_tiles[0][object->tile_idx] = 0x25;
            } else {
                field->fg_tiles[0][object->tile_idx] = 0x34;
            }
        }
        if (object->layer != 0) {
            if (object->type == 18) {
                field->fg_tiles[1][object->tile_idx] = 0x25;
            } else {
                field->fg_tiles[1][object->tile_idx] = 0x34;
            }
        }
    }
    object->fruit_drop_processed = 1;
    field->entity_active[object->falling_fruit_id + 23] = 0;
    object->falling_fruit_id = 0xFFFF;
}

/* Original address: 0x0201EB48 */
void FieldObject_UpdateShake(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 count;
    s32 slot;
    Entity *entity;
    s32 random;
    s32 x;
    s32 y;

    if (object->shake_animation_paused == 0) {
        object->anim_timer--;
        if (object->anim_timer == 0) {
            object->anim_timer = 2;
            object->anim_counter++;
            object->anim_frame = sFieldObjectShakeFrames[object->anim_counter];
        }
    }
    if (object->anim_counter & 1) {
        if (object->type != 3 && object->type != 14) {
            for (count = 0; count < 3; count++) {
                for (slot = 3; slot < 10; slot++) {
                    if (field->entity_active[slot + 3] == 0) {
                        entity = &g_EntityTable[slot];
                        field->entity_active[slot + 3] = 1;
                        Entity_Reset(slot);
                        random = rand_u16(&gGameState);
                        x = object->x + 16;
                        entity->x = x - random % 33;
                        random = rand_u16(&gGameState);
                        y = object->y - 16;
                        entity->y = y - random % 17;
                        entity->update_type = 3;
                        break;
                    }
                }
            }
        }
    }
    if (object->anim_frame > 2) {
        object->anim_timer = 0;
        object->anim_counter = 0;
        object->anim_frame = 0;
        object->shake_animation_paused = 0;
        object->action_state = 0;
    }
}

/* Original address: 0x0201EC6C */
void FieldObject_UpdateTopple(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    u32 rotation_step;
    u32 drop_angle;
    u32 rotation_speed;
    u32 rotation_threshold;

    if (object->anim_timer != 0) {
        object->anim_timer--;
        if (!(object->anim_timer & 1)) {
            object->topple_x_offset++;
        }
    } else {
        rotation_step = 0x200;
        drop_angle = 0xF200;
        switch (object->type) {
        case 14:
        case 3:
            rotation_step = 0x800;
            drop_angle = 0xE800;
            break;
        case 4:
            rotation_step = 0x400;
            drop_angle = 0xF800;
            break;
        }
        rotation_speed = rotation_step + object->rotation_speed;
        object->rotation_speed = rotation_speed;
        if ((u16)rotation_speed > rotation_step) {
            object->rotation_speed = rotation_step;
        }
        object->rotation -= object->rotation_speed;
        if (object->rotation <= object->rotation_threshold) {
            rotation_threshold = (object->rotation_threshold & 0xFF00) - rotation_step;
            object->rotation_threshold = rotation_threshold;
            object->topple_x_offset++;
            if ((u16)rotation_threshold < drop_angle) {
                object->topple_y_offset++;
            }
            if (object->type != 3 && object->type != 14) {
                if (object->topple_extra_x_offset <= 5) {
                    object->topple_extra_x_offset++;
                }
            }
        }
        if (object->rotation <= 0xD000) {
            object->rotation = 0xD000;
            object->anim_counter++;
            if (object->anim_counter > 0x20) {
                object->action_state = 4;
                object->falling_fruit_id = 0;
            }
        }
    }
}

/* Original address: 0x0201ED50 */
void FieldObject_Deactivate(s32 object_index) {
    gIslandFieldWork.entity_active[object_index + 54] = 0;
}

/* Original address: 0x0201ED68 */
void FieldObject_DrawSprite(FieldObjectSpriteFrame *frame, s32 object_index) {
    /* The BIOS reads the affine source as words. */
    struct ObjAffineSrcData transform __attribute__((aligned(4)));
    struct { s16 pa, pb, pc, pd; } matrix;
    FieldObject *object = &gFieldObjects[object_index];
    IslanderOamData *oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];

    oam->shape = (frame->oam_attributes >> 14) & 3;
    oam->size = frame->oam_attributes >> 30;
    oam->tile_num = frame->tile_num;
    oam->h_flip = 0;
    oam->priority = 1;
    oam->palette_num = 0;
    oam->mosaic = 1;
    if ((u8)(object->action_state - 3) <= 1) {
        oam->affine_mode = 1;
        oam->matrix_num = 0;
        oam->obj_mode = 0;
        transform.xScale = 0x100;
        transform.yScale = 0x100;
        if (object->x_flip == 0) {
            transform.rotation = object->rotation;
        } else {
            transform.rotation = -object->rotation;
        }
        ObjAffineSet(&transform, &matrix, 1, 2);
        oam = (IslanderOamData *)gUnk3002410;
        oam->affine_param = matrix.pa;
        oam++;
        oam->affine_param = matrix.pb;
        oam++;
        oam->affine_param = matrix.pc;
        oam[1].affine_param = matrix.pd;
        oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];
    }
    if (object->x_flip == 0) {
        oam->x = frame->x_offset + (object->x - gGameState.bg2_hofs) + object->topple_x_offset + object->topple_extra_x_offset;
    } else {
        oam->x = frame->x_offset + (object->x - gGameState.bg2_hofs) - object->topple_x_offset - object->topple_extra_x_offset;
    }
    oam->y = frame->y_offset + (object->y - (u8)gGameState.bg2_vofs) + (u8)object->topple_y_offset;
    gGameState.oam_count++;
}

/* Original address: 0x0201EF44 */
void FieldObject_Draw(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    u16 camera_y = gGameState.bg2_vofs;
    s32 y = object->y;

    if (y >= camera_y && y <= camera_y + 200 &&
        (object->action_state != 3 || !(object->anim_counter & 2))) {
        u8 *frame_indices = gFieldObjectSpriteFrameIndices;
        u16 type = object->type;
        u8 anim_frame = object->anim_frame;
        u8 frame_index = frame_indices[type * 8 + anim_frame];

        FieldObject_DrawSprite(&gFieldObjectSpriteFrames[frame_index], object_index);
    }
}

/* Original address: 0x0201EFB8 */
s32 Islander_StoreItem(u16 item_type, u16 generator_idx) {
    Islander_AGB *islander = &gIslander;
    ItemGroupStruct *definition = &g_ItemDefinitions[item_type];
    mActor_name_t *stored_item;
    u16 *stored_type_plus_one;
    s32 slot;
    ItemGeneratorDef *generator;

    islander->held_item_sprite = 0x800000;
    islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;
    if (definition->interaction_type != 4) {
        slot = 0;
        stored_item = islander->stored_item_ids;
        stored_type_plus_one = islander->stored_item_type_plus_one;
        do {
            if (*stored_type_plus_one == 0) {
                *stored_type_plus_one = item_type + 1;
                generator = &gItemGeneratorDefs[generator_idx];
                if (generator->use_island_id == 0) {
                    *stored_item = generator->item;
                } else {
                    *stored_item = Item_TypeToIslandItem(generator->item);
                }
                return 1;
            }
            stored_item++;
            stored_type_plus_one++;
            slot++;
        } while (slot < 5);
    }
    return 0;
}

/* Original address: 0x020338FC */
extern u16 sFishingRewardGeneratorIndices[64];

/* Original address: 0x0203397C */
extern u16 sFishingRewardItemTypes[64];

static inline u16 FishingSpecialCatchAttr2(u16 generator_idx) {
    if (generator_idx == 0x7F) {
        return 0x434E;
    } else {
        return 0x4350;
    }
}

/* Original address: 0x0201F030 */
s16 Islander_GetFishingItem(void) {
    Islander_AGB *islander = &gIslander;
    ItemGroupStruct *definition;
    s32 reward_idx;
    u16 generator_idx;
    u16 item_attr2;
    u32 item_flags;

    reward_idx = (islander->emotion & 3) * 16;
    if ((islander->equipped_tool_state & 0xF) == 8) {
        reward_idx += 8;
    }
    reward_idx = (reward_idx + rand_u16(&gGameState) % 8) & 0x3F;
    generator_idx = sFishingRewardGeneratorIndices[reward_idx];
    if ((u16)(generator_idx - 0x7E) > 1) {
        if (generator_idx != 0x25 && islander->stored_item_type_plus_one[4] != 0) {
            definition = &g_ItemDefinitions[sFishingRewardItemTypes[reward_idx]];
            item_flags = 0x800000;
            islander->held_item_sprite = item_flags;
            item_attr2 = definition->held_item_oam_attr2;
        } else {
            Islander_StoreItem(sFishingRewardItemTypes[reward_idx], sFishingRewardGeneratorIndices[reward_idx]);
            return 0;
        }
    } else {
        item_flags = 0x800000;
        islander->held_item_sprite = item_flags;
        item_attr2 = FishingSpecialCatchAttr2(generator_idx);
    }
    islander->held_item_sprite = item_attr2 | item_flags;
    return 0xFE;
}

/* Try mirrored approach tiles; save the dig tile and both movement waypoints. */
/* Original address: 0x0201F0FC */
s32 Islander_SetupDigApproach(u8 tile_offset) {
    u16 *right_tiles;
    u16 *left_tiles;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 items[2];
    u8 tile = islander->tile_idx;
    u8 row = (tile & 0xF0) + (tile_offset & 0xF0);
    u32 right_tile = row;
    u32 left_tile = row;
    u16 *right_info;
    u16 *left_info;
    u32 right_row;
    u32 right_col;
    u16 tile_id;

    right_tile |= ((tile & 0xF) + (tile_offset & 0xF)) & 0xF;
    left_tile |= ((tile & 0xF) - (tile_offset & 0xF)) & 0xF;
    islander->interaction_tile = 0;
    islander->next_target_x = 0;
    if ((islander->x & 0xFF0000) == 0) {
        right_tiles = (u16 *)BG_SCREEN_ADDR(20);
        items[0] = field->fg_tiles[0][right_tile];
        if ((tile & 0xF) > (right_tile & 0xF)) {
            right_tiles = (u16 *)BG_SCREEN_ADDR(21);
            items[0] = field->fg_tiles[1][right_tile];
        }
        left_tiles = (u16 *)BG_SCREEN_ADDR(20);
        items[1] = field->fg_tiles[0][left_tile];
    } else {
        islander->interaction_tile = 0x8000;
        right_tiles = (u16 *)BG_SCREEN_ADDR(21);
        items[0] = field->fg_tiles[1][right_tile];
        left_tiles = (u16 *)BG_SCREEN_ADDR(21);
        items[1] = field->fg_tiles[1][left_tile];
        if ((tile & 0xF) < (left_tile & 0xF)) {
            left_tiles = (u16 *)BG_SCREEN_ADDR(20);
            items[1] = field->fg_tiles[0][left_tile];
        }
    }
    islander->interaction_tile |= islander->tile_idx;
    right_row = right_tile & 0xF0;
    right_col = right_tile & 0xF;
    right_tiles += right_row * 4;
    right_tiles += right_col * 2;
    right_info = right_tiles;
    left_tiles += (left_tile & 0xF0) * 4;
    left_info = left_tiles + (left_tile & 0xF) * 2;
    if (CheckSurroundingCollision(items[0], right_info) != 0 ||
        (tile_id = *right_info & 0x3FF) <= 5 ||
        (u16)(tile_id - 0x10) <= 5 || tile_id > 0xAF) {
        if (CheckSurroundingCollision(items[1], left_info) != 0 ||
            (tile_id = *left_info & 0x3FF) <= 5 ||
            (u16)(tile_id - 0x10) <= 5 || tile_id > 0xAF) {
            islander->interaction_tile = 0;
            return 0;
        }
        if ((u32)left_info & 0x800) {
            islander->next_target_x = 0x10000;
        }
        islander->target_action = 0x70;
        islander->target_x = islander->x & 0xFF0000;
        islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
        islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
        islander->next_target_x |= ((left_tile & 0xF) << 12) + 0x800;
        islander->next_target_y = ((left_tile & 0xF0) << 8) + 0x800;
        return left_tile;
    }
    if ((u32)right_info & 0x800) {
        islander->next_target_x = 0x10000;
    }
    islander->target_action = 0x60;
    islander->target_x = islander->x & 0xFF0000;
    islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
    islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
    islander->next_target_x |= (right_col << 12) + 0x800;
    islander->next_target_y = (right_row << 8) + 0x800;
    return right_tile;
}

/* Original address: 0x02033A1C */
extern int collision_check_offsets[4];

/* Original address: 0x0201F368 */
s32 Islander_CanDigHere(void) {
    Islander_AGB *islander = &gIslander;
    u8 *tilemap;
    u8 tile_idx;
    s32 i;

    Islander_UpdateCollisionTiles(islander->direction);
    for (i = 0; i < 4; i++) {
        if (CheckSurroundingCollision(islander->surrounding_item_types[i], islander->collision_tilemap) != 0) {
            return 0;
        }
        if ((islander->x & 0xFF0000) == 0) {
            tilemap = (u8 *)BG_SCREEN_ADDR(20);
        } else {
            tilemap = (u8 *)BG_SCREEN_ADDR(21);
        }
        tile_idx = islander->tile_idx;
        tilemap = (0xF0 & tile_idx) * 8 + tilemap;
        tilemap += (0xF & tile_idx) * 4;
        if ((u16)((*(u16 *)(tilemap + collision_check_offsets[i]) & 0x3FF) - 0x20) > 0x5E) {
            return 0;
        }
    }
    return 1;
}

static inline IslanderDirectionSector *Islander_GetDirectionSector(u16 angle) {
    IslanderDirectionSector *sectors = &gIslanderDirectionSectors[7];
    s32 sector_idx;
    if (angle < sectors->max_angle) {
        sector_idx = 0;
        sectors -= 7;
        while (sector_idx <= 6 && angle > sectors[sector_idx].max_angle) {
            sector_idx++;
        }
    } else {
        sector_idx = 0;
        sectors -= 7;
    }
    return &sectors[sector_idx];
}

/* Original address: 0x0201F3F8 */
s32 Islander_ChangeMoveDir(s32 target_x, s32 target_y, u8 move_mode) {
    Islander_AGB *islander = &gIslander;
    u8 old_direction;
    u16 angle;
    u8 direction;
    u8 direction_diff;
    IslanderDirectionSector *sectors;

    islander->work_x = target_x - islander->x;
    islander->work_y = target_y - islander->y;
    if (islander->work_x < 0) {
        islander->work_x = -islander->work_x;
    }
    if (islander->work_y < 0) {
        islander->work_y = -islander->work_y;
    }
    if (islander->work_x <= 0x100 && islander->work_y <= 0x100) {
        return 1;
    }

    islander->work_x = (target_x - islander->x) >> 8;
    islander->work_y = (target_y - islander->y) >> 8;
    old_direction = islander->direction;
    switch (move_mode) {
    case 0:
        if (Islander_MoveTowardX(0, target_x)) {
            Islander_MoveTowardY(0, target_y);
            islander->work_x = 0;
        } else {
            islander->work_y = 0;
        }
        break;
    case 1:
        if (Islander_MoveTowardY(0, target_y)) {
            Islander_MoveTowardX(0, target_x);
            islander->work_y = 0;
        } else {
            islander->work_x = 0;
        }
        break;
    default:
        Islander_MoveTowardX(1, target_x);
        Islander_MoveTowardY(1, target_y);
        angle = ArcTan2((s16)islander->work_x, (s16)islander->work_y);
        sectors = Islander_GetDirectionSector(angle);
        direction_diff = islander->direction - sectors->direction;
        direction = sectors->direction;
        if (direction_diff & 0x80) {
            direction_diff = ~direction_diff;
            direction_diff++;
        }
        if ((u8)(direction_diff - 2) <= 4) {
            islander->direction = direction;
        }
    }
    if (islander->direction != old_direction) {
        Islander_AdjustAnimForTool();
    }
    return 0;
}

/* Original address: 0x020339FC */
extern s32 sIslanderCollisionSampleOffsets[8];

/* Original address: 0x0201F538 */
void Islander_UpdateCollisionTiles(u8 direction) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 y = (islander->y >> 8) & 0xFF0;
    s32 x = (islander->x >> 8) & 0xFF0;
    s32 i;
    u8 tile_idx;
    s32 terrain_tile_idx;
    u16 *tilemap;

    /* The direction argument is unused in the original routine. */
    tile_idx = y;
    tile_idx |= (x & 0xF0) >> 4;
    islander->tile_idx = tile_idx;
    for (i = 0; i < 4; i++) {
        x = islander->x + sIslanderCollisionSampleOffsets[(u8)(i * 2)];
        y = islander->y + sIslanderCollisionSampleOffsets[(u8)(i * 2 + 1)];
        tile_idx = (y >> 8) & ~0xF;
        tile_idx |= ((x >> 8) & 0xF0) >> 4;
        if ((x & 0xFF0000) == 0) {
            islander->surrounding_tile_indices[i] = tile_idx;
            islander->surrounding_item_types[i] = field->fg_tiles[0][tile_idx];
        } else {
            islander->surrounding_tile_indices[i] = tile_idx;
            islander->surrounding_item_types[i] = field->fg_tiles[1][tile_idx];
        }
    }
    islander->work_x = islander->x - 0x200;
    islander->work_y = islander->y + 0x200;
    y = (islander->work_y >> 8) & 0xFF0;
    x = (islander->work_x >> 8) & 0xFF0;
    terrain_tile_idx = y | ((x & 0xF0) >> 4);
    islander->terrain_tile_idx = terrain_tile_idx;
    if ((islander->work_x & 0xFF0000) == 0) {
        tilemap = (u16 *)BG_SCREEN_ADDR(20);
    } else {
        tilemap = (u16 *)BG_SCREEN_ADDR(21);
    }
    islander->collision_tilemap = (terrain_tile_idx & 0xF0) * 4 + tilemap + (terrain_tile_idx & 0xF) * 2;
}

/* Original address: 0x0201F660 */
void WriteItemToTile(s32 x, u8 tile_idx, u16 item, u16 item_tile) {
    u16 *tilemap_vram;

    if ((x & 0xFF0000) == 0) {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
    } else {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
    }

    tilemap_vram += (tile_idx & 0xF0) * 4;
    tilemap_vram += (tile_idx & 0xF) * 2;
    WriteItemTileToVRAM(tilemap_vram, item_tile);
}

static inline s32 HasSurroundingTileCollision(u16 *tile_info) {
    int i;

    for (i = 0; i < ARRAY_COUNT(collision_check_offsets); i++) {
        u32 tile = *(u16*)((u8*)tile_info + collision_check_offsets[i]) & 0x3FF;

        if ((i == 1 && tile == 0x096) || (u16)(tile - 0xB0) < 6 || (u16)(tile - 0xC0) < 0x16 || (u16)(tile - 0xE0) < 0x320) {
            return 1;
        }
    }

    return 0;
}

/* Original address: 0x0201F6DC */
s32 CheckSurroundingCollision(u16 main_tile, u16 *tile_info) {
    if (!HasSurroundingTileCollision(tile_info)) {
        if ((u16)(main_tile - 0x1F) < 2 || (u16)(main_tile - 0x22) < 4 || (u16)(main_tile - 0x27) < 9 || (u16)(main_tile - 0x31) < 4 || (u16)(main_tile - 0x36) < 7 || main_tile == 0x41) {
            return 1;
        }
    } else {
        return 2;
    }

    return 0;
}

/* Original address: 0x0201F78C */
s32 Islander_ChooseNewMoveDirection(u8 allow_reverse) {
    Islander_AGB *islander = &gIslander;
    s32 direction;
    s32 count;

    for (direction = 0; direction < 8; direction++) {
        islander->blocked_directions[direction] = 0;
        islander->direction_candidates[direction] = 0xFF;
    }

    islander->blocked_directions[islander->direction] = 1;
    if (allow_reverse == 0) {
        direction = islander->direction + 4;
        if (direction > 7) {
            direction = islander->direction - 4;
        }
        islander->blocked_directions[direction] = 1;
    }

    for (direction = 0; direction < 8; direction++) {
        if (islander->blocked_directions[direction] == 0 && Islander_CanMoveInDirection(direction) == 0) {
            islander->blocked_directions[direction] = 1;
        }
    }

    direction = 0;
    count = 0;
    for (; direction < 8; direction++) {
        if (islander->blocked_directions[direction] == 0) {
            islander->direction_candidates[count] = direction;
            count++;
        }
    }

    if (count == 0) {
        return 0x777;
    } else {
        direction = islander->direction_candidates[rand_u16(&gGameState) % count];
        return direction;
    }
}

/* Original address: 0x02033A2C */
extern s32 gIslanderMoveCollisionOffsets[16];

/* Original address: 0x0201F844 */
s32 Islander_CanMoveInDirection(u8 direction) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 offset_idx = direction * 2;
    s32 x = islander->x + gIslanderMoveCollisionOffsets[offset_idx];
    s32 y_offset = gIslanderMoveCollisionOffsets[offset_idx + 1] + 0x800;
    s32 y = islander->y + y_offset;
    s32 row = (y >> 8) & ~0xF;
    u8 tile = ((x >> 12) & 0xF) | row;
    u32 tilemap;

    if ((x & 0xFF0000) == 0) {
        islander->surrounding_item_types[0] = field->fg_tiles[0][tile];
        tilemap = BG_SCREEN_ADDR(20);
    } else {
        islander->surrounding_item_types[0] = field->fg_tiles[1][tile];
        tilemap = BG_SCREEN_ADDR(21);
    }
    tilemap = (tile & 0xF0) * 8 + tilemap;
    tilemap += (tile & 0xF) * 4;
    islander->collision_tilemap = (u16 *)tilemap;
    if (CheckSurroundingCollision(islander->surrounding_item_types[0], (u16 *)tilemap) == 0) {
        return 1;
    } else {
        return 0;
    }
}

/* Original address: 0x0201F8FC */
void Islander_BuryRandomItem(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    BuriedItemUpdateGroup *buried_item_update;
    ItemGeneratorDef *generator_def;
    ItemGroupStruct *item_definition;
    Island_agb_c *island_data;
    u16 *deposit;
    mActor_name_t buried_item;
    s32 update_idx;
    u8 generator_idx;
    u8 tile_idx = islander->interaction_tile;
    s32 group_idx;

    for (group_idx = 0; group_idx < ARRAY_COUNT(gBuriedItemRngTileGroups); group_idx++) {
        if (item_type == ((u16 *)gBuriedItemRngTileGroups)[(u8)(group_idx * 5)]) {
            item_type = ((u16 *)gBuriedItemRngTileGroups)[(u8)((group_idx * 5) + 1 + islander->emotion)];
            break;
        }
    }

    if (group_idx >= ARRAY_COUNT(gBuriedItemRngTileGroups)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }
    if ((islander->equipped_tool_state & 0xF) == 7) {
        item_type += 0x10;
    }

    item_type += rand_u16(&gGameState) % 4;
    if (item_type >= 0x120) {
        item_type = 0;
    }

    generator_idx = gBuriedItemGeneratorIndices[item_type];
    generator_def = &gItemGeneratorDefs[generator_idx];
    item_definition = &g_ItemDefinitions[generator_def->item_type];

    if ((item_definition->default_generator_idx == 0xFFF) || (generator_idx == 0xD)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }

    islander->held_item_sprite = item_definition->held_item_oam_attr2 | 0x800000;

    if (IS_ITEM_TYPE_FRUIT(generator_def->item_type)) {
        islander->buried_item_tile_base = 0x3260;
        if (generator_def->item_type == ITEM_TYPE_COCONUT) {
            islander->buried_item_tile_base = 0x3268;
        }

        for (update_idx = 0; update_idx < 6; update_idx++) {
            buried_item_update = &gBuriedItemUpdateGroups[update_idx];
            if (buried_item_update->item_type == generator_def->item_type) {
                break;
            }
        }

        if ((islander->interaction_tile & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = 0x7777;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[0][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = 0x7777;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[1][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        }
    } else {
        islander->buried_item_tile_base = 0x1270;
        if (generator_def->use_island_id == 0) {
            buried_item = generator_def->item;
        } else {
            buried_item = Item_TypeToIslandItem(generator_def->item);
        }

        if ((islander->interaction_tile & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[0][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[1][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        }
    }
}

/* Original address: 0x0201FB9C */
void Islander_PlantRandomFlower(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 tile_idx = islander->interaction_tile;
    u8 flower;

    islander->held_item_sprite = 0x800000;
    flower = rand_u16(&gGameState) % 9;
    islander->held_item_sprite |= 0x5344;
    if ((islander->interaction_tile & 0x8000) == 0) {
        field->fg_tiles[0][tile_idx] = 0x7777;
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = sIslanderFlowerItems[flower];
        gIslandData->deposit[0][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
    } else {
        field->fg_tiles[1][tile_idx] = 0x7777;
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = sIslanderFlowerItems[flower];
        gIslandData->deposit[1][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
    }
    islander->buried_item_tile_base = (g_ItemDefinitions + ITEM_TYPE_PURPLE_COSMOS)[flower].field_tile_id;
}

/* Original address: 0x0201FCB0 */
void Islander_UpdateBlink(void) {
    Islander_AGB *islander = &gIslander;
    u8 direction = islander->direction;

    if ((direction == 0 || direction == 2 || direction == 1 || direction == 6 || direction == 7) && islander->emotion == 0) {
        if (islander->blink_timer == 0) {
            islander->blink_frame = (islander->blink_frame + 1) & 1;
            if (islander->blink_frame == 0) {
                islander->blink_timer = rand_u16(&gGameState) % 65 + 0x20;
            } else {
                islander->blink_timer = 4;
            }
        }
        islander->blink_timer--;
    }
}

static inline s32 Islander_FindDirectionSector(u16 angle) {
    s32 sector;
    IslanderDirectionSector *sectors = &gIslanderDirectionSectors[7];

    if (angle < sectors->max_angle) {
        sectors = gIslanderDirectionSectors;
        for (sector = 0; sector < 7; sector++) {
            if (angle <= sectors[sector].max_angle) {
                break;
            }
        }
    } else {
        sector = 0;
    }
    return sector;
}

/* Original address: 0x0201FD1C */
s32 Islander_FaceTargetAndCheckArrival(s32 target_x, s32 target_y) {
    Islander_AGB *islander = &gIslander;
    u16 angle;
    s32 sector;
    s32 tile_y;

    islander->work_x = (target_x - islander->x) >> 8;
    islander->work_y = (target_y - islander->y) >> 8;
    angle = ArcTan2(islander->work_x, islander->work_y);
    sector = Islander_FindDirectionSector(angle);
    if (islander->direction_change_cooldown_timer == 0) {
        if (gIslanderDirectionSectors[sector].direction != islander->direction) {
            islander->direction = gIslanderDirectionSectors[sector].direction;
            Islander_AdjustAnimForTool();
            islander->direction_change_cooldown_timer = 0x20;
        }
    }
    if (islander->work_x < 0) {
        islander->work_x = -islander->work_x;
    }
    if (islander->work_y < 0) {
        islander->work_y = -islander->work_y;
    }
    if (islander->work_x <= 1 && islander->work_y <= 1) {
        tile_y = (islander->y >> 8) & 0xFF0;
        islander->work_y = tile_y;
        islander->work_x = (islander->x >> 8) & 0xFF0;
        islander->tile_idx = tile_y;
        islander->tile_idx = ((islander->work_x & 0xF0) >> 4) | tile_y;
        return 1;
    }
    return 0;
}

/* Original address: 0x0201FDF4 */
s32 Islander_PlayAnim(u8 stop_at_end) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *frame;

    islander->anim_timer--;
    if (islander->anim_timer & 0x80) {
        islander->anim_frame++;
        frame = gIslanderAnimData[islander->anim_id][islander->anim_frame];
        if ((u8)frame->action_flag == 0xFF) {
            islander->anim_frame = 0;
            if (stop_at_end == 1) {
                return 1;
            }
        }
        frame = gIslanderAnimData[islander->anim_id][islander->anim_frame];
        islander->anim_timer = frame->duration;
    }
    return 0;
}

/* Original address: 0x0201FE6C */
void Islander_ClearStoredItem(s32 index) {
    Islander_AGB *islander = &gIslander;
    s32 i;

    islander->stored_item_type_plus_one[index] = 0;
    islander->stored_item_ids[index] = 0;
    for (i = index; i < 4; i++) {
        if (islander->stored_item_type_plus_one[i] == 0 && islander->stored_item_ids[i] == 0) {
            islander->stored_item_type_plus_one[i] = islander->stored_item_type_plus_one[i + 1];
            islander->stored_item_ids[i] = islander->stored_item_ids[i + 1];
            islander->stored_item_type_plus_one[i + 1] = 0;
            islander->stored_item_ids[i + 1] = 0;
        }
    }
}

/* Original address: 0x0201FED4 */
s32 Islander_SpawnReactionEffect(u8 effect, u8 duration) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    Entity *entity;

    for (i = 3; i < 12; i++) {
        if (field->entity_active[i + 3] == 0) {
            entity = &g_EntityTable[i];
            field->entity_active[i + 3] = 1;
            Entity_Reset(i);
            entity->lifetime = duration;
            entity->reaction_type = effect;
            entity->update_type = 5;
            entity->x = islander->x >> 8;
            entity->y = islander->y >> 8;
            return 1;
        }
    }
    return 0;
}

static inline u16 Islander_GetTerrainTile(u16 *tilemap) {
    return *tilemap & 0x3FF;
}

/* Original address: 0x0201FF48 */
s32 SpawnEntity(u8 spawn_flag, u8 spawn_mode, u16 item_type, u16 item) {
    s32 active_idx;
    s32 entity_idx;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 *tilemap;
    u16 tile;
    u16 terrain_tile;
    u8 tile_idx;
    Entity *entity;
    ItemGroupStruct *definition;

    if (spawn_mode == 0) {
        if (!(islander->x & 0xFF0000)) {
            tile = field->fg_tiles[0][islander->tile_idx];
            if (tile != 0xFFF && tile != 0x3333) {
                return 0;
            }
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
        } else {
            tile = field->fg_tiles[1][islander->tile_idx];
            if (tile != 0xFFF && tile != 0x3333) {
                return 0;
            }
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
        }
        tilemap += (0xF0 & islander->tile_idx) * 4;
        tilemap += (0xF & islander->tile_idx) * 2;
        if (CheckSurroundingCollision(0, tilemap) != 0) {
            return 0;
        }
        terrain_tile = Islander_GetTerrainTile(tilemap);
        if (terrain_tile <= 5U || (u16)(terrain_tile - 0x10) <= 5U || terrain_tile > 0xAFU) {
            return 0;
        }
    }
    if (spawn_mode == 2) {
        spawn_mode = 0;
    }
    for (entity_idx = 3, active_idx = 6; entity_idx < 12; active_idx++, entity_idx++) {
        if (field->entity_active[active_idx] == 0) {
            entity = &g_EntityTable[entity_idx];
            definition = &g_ItemDefinitions[item_type];
            Entity_Reset(entity_idx);
            entity->x = (islander->x >> 8) - 8;
            entity->y = (islander->y >> 8) - 0x10;
            if (spawn_mode == 0) {
                entity->update_type = 7;
            } else {
                entity->update_type = 9;
                islander->floating_balloon_target_entity_id = entity_idx;
            }
            field->entity_active[active_idx] = 1;
            entity->item_type_indices[0] = item_type;
            entity->item_ids[0] = item;
            entity->items_are_resolved = spawn_flag;
            tile_idx = islander->tile_idx;
            entity->landing_tile = tile_idx;
            if (islander->x & 0xFF0000) {
                entity->landing_tile = tile_idx | 0x1000;
            }
            entity->sprite_tile = definition->held_item_oam_attr2 & 0x3FF;
            entity->palette = definition->held_item_oam_attr2 >> 12;
            return entity_idx;
        }
    }
    return 0;
}

/* Original address: 0x02020118 */
s32 Islander_SelectTreeApproach(FieldObject *object, s32 right_x, s32 left_x) {
    Islander_AGB *islander = &gIslander;
    s32 i;
    u8 tile_idx;

    islander->tree_approach_x[0] = right_x;
    islander->tree_approach_x[1] = left_x;
    if (right_x == 0 && left_x == 0) {
        return 0;
    }
    islander->target_y = ((0xF0 & object->tile_idx) << 8) + 0x800;
    islander->item_work.held_item.type_idx = 0;
    if (islander->tree_approach_x[0] != 0 && islander->tree_approach_x[1] != 0) {
        for (i = 0; i < 2; i++) {
            islander->tree_approach_eval[i] = islander->tree_approach_x[i] - islander->x;
            if (islander->tree_approach_eval[i] < 0) {
                islander->tree_approach_eval[i] = 0;
            }
        }
        islander->target_x = islander->tree_approach_x[0] + 0x500;
        islander->target_action = 0x40;
        if (islander->tree_approach_eval[0] > islander->tree_approach_eval[1]) {
            islander->target_x = islander->tree_approach_x[1];
            islander->target_action = 0x30;
            islander->target_x = islander->tree_approach_x[1] + 0xA00;
        }
        islander->next_target_x = 0;
        islander->next_target_y = 0;
    } else {
        islander->target_x = islander->tree_approach_x[0] + 0x500;
        islander->target_action = 0x40;
        if (islander->tree_approach_x[1] != 0) {
            islander->target_x = islander->tree_approach_x[1];
            islander->target_action = 0x30;
            islander->target_x = islander->tree_approach_x[1] + 0xA00;
        }
        islander->next_target_x = islander->target_x;
        islander->next_target_y = islander->target_y;
        islander->target_x -= islander->x;
        if (islander->target_x < 0) {
            islander->target_x = -islander->target_x;
        }
        islander->target_y = islander->next_target_y - islander->y;
        if (islander->target_y < 0) {
            islander->target_y = -islander->target_y;
        }
        if (islander->target_x <= 0xFFF && islander->target_y <= 0xFFF) {
            islander->target_x = islander->next_target_x;
            islander->target_y = islander->next_target_y;
            islander->next_target_x = 0;
            islander->next_target_y = 0;
        } else {
            islander->target_x = 0;
            islander->target_y = 0;
            if (object->layer != 0) {
                islander->target_x = 0x10000;
            }
            if ((object->y << 8) > islander->y) {
                tile_idx = object->tile_idx - 0x10;
                islander->target_x |= ((0xF & tile_idx) << 12) + 0x800;
                islander->target_y = ((tile_idx & 0xF0) << 8) + 0x0FFFF400;
            } else {
                tile_idx = object->tile_idx + 0x10;
                islander->target_x |= ((0xF & tile_idx) << 12) + 0x800;
                islander->target_y = ((tile_idx & 0xF0) << 8) + 0x800;
            }
        }
    }
    return 1;
}

/* Original address: 0x0202029C */
s32 Islander_SetupTreeApproach(FieldObject *object) {
    u16 tile_ids[2];
    u32 tilemap_addresses[2];
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u32 tile_idx = object->tile_idx;
    s32 column = 0xF & tile_idx;
    s32 right_column = column + 1;
    s32 side;

    islander->tree_approach_eval[0] = right_column;
    islander->tree_approach_x[0] = islander->tree_approach_eval[0] << 12;
    if (object->layer == 0) {
        tilemap_addresses[0] = BG_SCREEN_ADDR(20);
        tile_ids[0] = field->fg_tiles[0][(0xF0 & tile_idx) + islander->tree_approach_eval[0]];
        if (islander->tree_approach_eval[0] == 0x10) {
            islander->tree_approach_eval[0] = 0;
            tilemap_addresses[0] = BG_SCREEN_ADDR(21);
            tile_ids[0] = field->fg_tiles[1][0xF0 & tile_idx];
            islander->tree_approach_x[0] = 0x10000;
        }
        islander->tree_approach_eval[0] = (0xF0 & tile_idx) + islander->tree_approach_eval[0];
        islander->tree_approach_eval[1] = (0xF & object->tile_idx) - 1;
        islander->tree_approach_x[1] = islander->tree_approach_eval[1] << 12;
        tilemap_addresses[1] = BG_SCREEN_ADDR(20);
        tile_ids[1] = field->fg_tiles[0][(0xF0 & object->tile_idx) + islander->tree_approach_eval[1]];
        islander->tree_approach_eval[1] = (0xF0 & object->tile_idx) + islander->tree_approach_eval[1];
    } else {
        islander->tree_approach_x[0] |= 0x10000;
        islander->tree_approach_x[1] = 0x10000;
        tilemap_addresses[0] = BG_SCREEN_ADDR(21);
        tile_ids[0] = field->fg_tiles[1][(tile_idx & 0xF0) + islander->tree_approach_eval[0]];
        islander->tree_approach_eval[0] = (tile_idx & 0xF0) + islander->tree_approach_eval[0];
        islander->tree_approach_eval[1] = column - 1;
        islander->tree_approach_x[1] = (islander->tree_approach_eval[1] << 12) | 0x10000;
        tilemap_addresses[1] = BG_SCREEN_ADDR(21);
        tile_ids[1] = field->fg_tiles[1][(tile_idx & 0xF0) + islander->tree_approach_eval[1]];
        if ((islander->tree_approach_eval[1] & 0xFF) == 0xFF) {
            islander->tree_approach_eval[1] = 0xF;
            islander->tree_approach_x[1] = 0;
            tilemap_addresses[1] = BG_SCREEN_ADDR(20);
            tile_ids[1] = field->fg_tiles[0][(0xF0 & tile_idx) + islander->tree_approach_eval[1]];
            islander->tree_approach_x[1] = islander->tree_approach_eval[1] << 12;
        }
        islander->tree_approach_eval[1] += tile_idx & 0xF0;
    }
    for (side = 0; side < 2; side++) {
        tilemap_addresses[side] += (islander->tree_approach_eval[side] & 0xF0) * 8;
        tilemap_addresses[side] += (islander->tree_approach_eval[side] & 0xF) * 4;
        if ((*(u16 *)tilemap_addresses[side] & 0x3FF) > 0x7F) {
            islander->tree_approach_x[side] = 0;
        }
        if (tile_ids[side] == 0x7777 || tile_ids[side] == 0x1F || tile_ids[side] == 0x20) {
            islander->tree_approach_x[side] = 0;
        }
    }
    return Islander_SelectTreeApproach(object, islander->tree_approach_x[0], islander->tree_approach_x[1]);
}

/* Original address: 0x020338D2 */
extern u8 sIslanderTreeActionChances[8];

/* Original address: 0x02020480 */
s32 Islander_DecideTreeAction(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 tree;
    s32 state;
    s32 i;
    u8 chance;
    u8 chance_idx;
    s32 approach;
    FieldObject *object;

    if (islander->tree_action_cooldown_timer != 0) {
        islander->tree_action_skipped = 0;
        return 0;
    }
    tree = Islander_FindNearbyTree();
    if (tree == 0) {
        islander->tree_action_skipped = tree;
        return 0;
    }
    state = islander->equipped_tool_state & 0xF;
    if (state == 0 || state == 2 || state == 6) {
        for (i = 0; i < FIELD_OBJECT_COUNT; i++) {
            if (field->entity_active[0x36 + i] == 1) {
                object = &gFieldObjects[i];
                if (object->tile_idx == islander->surrounding_tile_indices[(u8)(tree - 1)] &&
                    object->layer == (islander->x & 0x10000) >> 16) {
                    break;
                }
            }
        }
        if (i == FIELD_OBJECT_COUNT) {
            islander->tree_action_skipped = 0;
            return 0;
        }
        if (islander->tree_action_skipped == 0) {
            chance_idx = islander->emotion * 2 + islander->reward_adjust;
            chance = sIslanderTreeActionChances[chance_idx];
            if (chance < (s32)rand_u16(&gGameState) % 101) {
                islander->tree_action_skipped = 1;
            } else {
                islander->target_field_object_idx = i;
                islander->item_work.held_item.type_idx = 0;
                object = &gFieldObjects[islander->target_field_object_idx];
                approach = Islander_SetupTreeApproach(object);
                if (approach != 0) {
                    islander->previous_direction = islander->direction;
                    islander->move_action = 4;
                    IslanderMoveAction_MoveToTarget();
                    return 1;
                }
                islander->target_x = approach;
                islander->target_y = approach;
                islander->tree_action_cooldown_timer = 0x50;
            }
        }
    }
    return 0;
}

/* Original address: 0x02033A84 */
extern s32 sIslanderMoveSteps[8][2];


/* Original address: 0x020205E0 */
void Islander_MoveWithCollision(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 collision;
    s32 i;
    s32 *step = sIslanderMoveSteps[islander->direction];

    islander->x += step[0];
    islander->y += step[1];
    if (islander->collision_bypass_timer != 0) {
        islander->collision_bypass_timer--;
        if ((islander->accepted_x & 0xFFF00) != (islander->x & 0xFFF00)) {
            islander->accepted_x = islander->x & 0xFFF00;
        }
        if ((islander->accepted_y & 0xFFF00) != (islander->y & 0xFFF00)) {
            islander->accepted_y = islander->y & 0xFFF00;
        }
        return;
    }

    Islander_UpdateCollisionTiles(islander->direction);
    collision = 0;
    for (i = 0; i < 4; i++) {
        collision = CheckSurroundingCollision(islander->surrounding_item_types[i], islander->collision_tilemap);
        if (collision != 0) {
            break;
        }
    }
    if (i == 4) {
        if ((islander->accepted_x & 0xFFF00) != (islander->x & 0xFFF00)) {
            islander->accepted_x = islander->x & 0xFFF00;
        }
        if ((islander->accepted_y & 0xFFF00) != (islander->y & 0xFFF00)) {
            islander->accepted_y = islander->y & 0xFFF00;
        }
        islander->tree_action_skipped = 0;
        if (islander->collision_retry_count != 0) {
            islander->collision_recovery_timer++;
            if (islander->collision_recovery_timer > 0x20) {
                islander->collision_retry_count = 0;
                islander->collision_recovery_timer = 0;
            }
        }
    } else {
        if (collision != 1 || (!(islander->direction >= 3 && islander->direction <= 5) ||
            field->special_tile_idx != islander->tile_idx || gPlayer.near_house_door != 1)) {
            if (collision == 1 && Islander_DecideTreeAction() != 0) {
                return;
            }
            islander->x = islander->accepted_x;
            islander->y = islander->accepted_y;
            collision = Islander_ChooseNewMoveDirection(1);
            islander->target_x = 0;
            islander->target_y = 0;
            islander->collision_retry_count++;
            if (collision != 0x777 && islander->collision_retry_count <= 6) {
                islander->direction = collision;
                islander->move_action = 2;
                Islander_StartWandering();
                return;
            }
        } else {
            IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];

            islander->target_x = house->x << 8;
            islander->target_y = (house->y << 8) + 0x1000;
            islander->target_action = 0x20;
            islander->item_work.held_item.type_idx = 0;
            islander->move_action = 4;
            IslanderMoveAction_MoveToTarget();
            return;
        }
        islander->collision_retry_count = 0;
        islander->move_action = 0x13;
        Islander_MoveAction20_Init();
    }
}

/* Original address: 0x02020790 */
void Islander_AdjustAnimForTool(void) {
    u32 var_r1_17464;

    var_r1_17464 = 0xF & gIslander.equipped_tool_state;
    if (var_r1_17464 > 4U) {
        var_r1_17464 = (u32) (u16) (var_r1_17464 - 4);
    }
    gIslander.anim_id = (var_r1_17464 * 8) + gIslander.direction;
}

/* Original address: 0x020207C0 */
s32 Islander_MoveTowardX(u8 keep_facing, s32 target) {
    Islander_AGB *islander = &gIslander;
    s32 x = islander->x;
    s32 distance = target - x;

    if (distance < 0) {
        distance = -distance;
    }
    if (distance > 0x100) {
        if (target > x) {
            islander->x = x + 0x40;
            if (keep_facing == 0) {
                islander->direction = 6;
            }
        } else {
            islander->x = x - 0x40;
            if (keep_facing == 0) {
                islander->direction = 2;
            }
        }
        return 0;
    }
    return 1;
}

/* Original address: 0x02020814 */
s32 Islander_MoveTowardY(u8 keep_facing, s32 target) {
    Islander_AGB *islander = &gIslander;
    s32 y = islander->y;
    s32 distance = target - y;

    if (distance < 0) {
        distance = -distance;
    }
    if (distance > 0x100) {
        if (target > y) {
            islander->y = y + 0x40;
            if (keep_facing == 0) {
                islander->direction = 0;
            }
        } else {
            islander->y = y - 0x40;
            if (keep_facing == 0) {
                islander->direction = 4;
            }
        }
        return 0;
    }
    return 1;
}

/* Original address: 0x0202086C */
s32 Islander_FindNearbyTree(void) {
    Islander_AGB *islander = &gIslander;
    s32 i;
    u16 item_type;

    for (i = 0; i < 4; i++) {
        item_type = islander->surrounding_item_types[i];
        if ((item_type >= ITEM_TYPE_SMALL_TREE && item_type <= ITEM_TYPE_FULLY_GROWN_TREE) ||
            (item_type >= ITEM_TYPE_FRUIT_APPLE_TREE && item_type <= ITEM_TYPE_FRUIT_CHERRY_TREE) ||
            (item_type >= ITEM_TYPE_SMALL_PALM_TREE && item_type <= ITEM_TYPE_PALM_TREE) ||
            item_type == ITEM_TYPE_FRUIT_PALM_TREE) {
            return ++i;
        }
    }
    return 0;
}

/* Original address: 0x020208BC */
s32 Islander_TryInteractWithBuriedItem(u8 layer) {
    Islander_AGB *islander = &gIslander;
    u8 *tile_idx = &islander->tile_idx;
    IslandFieldWork *field = &gIslandFieldWork;
    Island_agb_c *island = gIslandData;
    u32 tile;
    ItemGroupStruct *definition;
    u16 special_tile;
    s32 chance;
    s32 state;

    if ((island->deposit[layer][*tile_idx >> 4] >> (0xF & *tile_idx)) & 1) {
        if (islander->digging_cooldown_timer == 0 &&
            ((state = 0xF & islander->equipped_tool_state) == 3 || state == 7)) {
            if (!(islander->x & 0xFF0000)) {
                tile = field->fg_tiles[0][*tile_idx];
            } else {
                tile = field->fg_tiles[1][*tile_idx];
            }
            definition = &g_ItemDefinitions[tile];
            if (tile != 0xFFF) {
                special_tile = tile & 0x8000;
                if (special_tile == 0 && tile != 0x3333 && tile != 0x7777 &&
                    definition->interaction_type != 0xFFF) {
                    chance = 50;
                    if (islander->reward_adjust == 1) {
                        chance = 25;
                    }
                    if (chance >= (s32)rand_u16(&gGameState) % 101 &&
                        (u16)Islander_SetupDigApproach(0xF1) != 0) {
                        islander->accepted_x = islander->target_x;
                        islander->accepted_y = islander->target_y;
                        islander->buried_item_tile_base = 0;
                        islander->item_work.held_item.type_idx = 2;
                        islander->move_action = 4;
                        IslanderMoveAction_MoveToTarget();
                        return 2;
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x020209E0 */
void Islander_OnMoodChanged(void) {
    Islander_AGB *islander = &gIslander;
    u16 *emotions = sIslanderMoodEmotions;
    u16 emotion = emotions[islander->mood_level];

    islander->emotion = emotion;
    ChangeEmotion(emotion + 1);
}

/* Original address: 0x02020A0C */
void WriteItemTileToVRAM(u16 *tilemap, u16 tile_base) {
    *tilemap++ = tile_base;
    *tilemap = tile_base + 1;
    tilemap += 31;
    tilemap[0] = tile_base + 2;
    tilemap[1] = tile_base + 3;
}

/* Original address: 0x02020A24 */
u16 Item_GetItemIdFromTileId(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    BuriedItemUpdateGroup *buried_item_update;
    int i;

    if (IS_ITEM_TYPE_FRUIT(item_type)) {
        islander->buried_item_tile_base = 0x3260;
        if (item_type == ITEM_TYPE_COCONUT) {
            islander->buried_item_tile_base = 0x3268;
        }

        for (i = 0; i < ARRAY_COUNT(gBuriedItemUpdateGroups); i++) {
            buried_item_update = &gBuriedItemUpdateGroups[i];
            if (buried_item_update->item_type == item_type) {
                break;
            }
        }

        return buried_item_update->buried_item;
    }

    return EMPTY_NO;
}

/* Original address: 0x02020A78 */
s32 Islander_TryDropTool(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 placed = 0;
    u16 tile = islander->equipped_tool_state & 0xF;
    u32 tool = tile;
    s32 collision;

    if (tile > 4) {
        tile -= 4;
    }
    tile = tile * 2 + 0x8043;
    if (tool > 4) {
        tile++;
    }
    if (Islander_CanDigHere() != 0) {
        Islander_UpdateCollisionTiles(islander->direction);
        collision = CheckSurroundingCollision(islander->tile_idx, islander->collision_tilemap);
        if ((islander->x & 0xFF0000) == 0) {
            if (collision == 0) {
                if (field->fg_tiles[0][islander->tile_idx] == 0xFFF) {
                    field->fg_tiles[0][islander->tile_idx] = tile;
                    placed = 1;
                }
            }
        } else if (collision == 0) {
            if (field->fg_tiles[1][islander->tile_idx] == 0xFFF) {
                field->fg_tiles[1][islander->tile_idx] = tile;
                placed = 1;
            }
        }
        if (placed == 1) {
            WriteItemToTile(islander->x, islander->tile_idx, islander->removed_tool_item, 0x6234);
            if (islander->removed_tool_layer == 0) {
                field->fg_tiles[0][islander->removed_tool_tile_idx] = 0xFFF;
            } else {
                field->fg_tiles[1][islander->removed_tool_tile_idx] = 0xFFF;
            }
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->equipped_tool_state = 0;
            islander->removed_tool_item = 0;
            Islander_AdjustAnimForTool();
            return 1;
        }
    }
    return 0;
}

/* Original address: 0x02020B88 */
void Islander_Init(void) {
    Islander_AGB *islander = &gIslander;
    s32 i;

    islander->x = 0;
    islander->y = 0;
    islander->accepted_x = 0;
    islander->accepted_y = 0;
    islander->target_x = 0;
    islander->target_y = 0;
    islander->next_target_x = 0;
    islander->next_target_y = 0;
    islander->flying_item_x = 0;
    islander->flying_item_y = 0;
    islander->work_x = 0;
    islander->work_y = 0;
    islander->surrounding_item_types[0] = 0;
    islander->collision_tilemap = 0;
    islander->removed_tool_layer = 0;
    islander->removed_tool_tile_idx = 0;
    islander->held_item_sprite = 0;
    islander->wander_timer = 0;
    islander->move_action = 0;
    islander->anim_id = 0;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->direction = 0;
    islander->previous_direction = 0;
    islander->equipped_tool_state = 0;
    islander->removed_tool_item = 0;
    islander->tile_idx = 0;
    islander->interaction_tile = 0;
    islander->terrain_tile_idx = 0;
    islander->emotion = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->mood_level = 0;
    islander->direction_change_cooldown_timer = 0;
    islander->stored_item_slot = 0;
    islander->islander_npc_idx = 0;
    islander->reaction_anim_id = 0;
    islander->click_cooldown_timer = 0;
    islander->target_action = 0;
    islander->collision_bypass_timer = 0;
    islander->target_field_object_idx = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->item_work.held_item.tile_no = 0;
    islander->action_state = 0;
    islander->player_interaction_tile_idx = 0;
    islander->fishing_cooldown_timer = 0;
    islander->floating_balloon_target_entity_id = 0;
    islander->interaction_target_is_islander = 0;
    islander->buried_item_tile_base = 0;
    islander->carry_wait_timer = 0;
    islander->carry_state = 0;
    islander->immediate_item_type_plus_one = 0;
    islander->reward_adjust = 0;
    islander->equipped_tool_timer = 0;
    islander->collision_retry_count = 0;
    islander->favorite_hour_item_spawned = 0;
    islander->tree_action_skipped = 0;
    islander->collision_recovery_timer = 0;
    islander->removed_field_item_type = 0;
    islander->dig_target_layer = 0;
    islander->dig_target_tile_idx = 0;

    islander->digging_cooldown_timer = 0x78;
    islander->flying_item_spawn_timer = 0x2A30;
    islander->islander_npc_idx = gIslandData->npc_idx;
    islander->reward_adjust = sIslanderRewardAdjust[islander->islander_npc_idx];
    for (i = 0; i < 4; i++) {
        islander->surrounding_item_types[i] = 0;
        islander->surrounding_tile_indices[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        islander->stored_item_type_plus_one[i] = 0;
        islander->stored_item_ids[i] = 0;
    }
    islander->mood_level = 3;
    Islander_OnMoodChanged();
    ChangeEmotion(islander->emotion + 1);
    Sound_InitMusic();
    islander->anim_timer = 0xFE;
    islander->anim_id = ISLANDER_ANIM_60;
    islander->move_action = 0;
}

/* Original address: 0x02020D20 */
s32 Island_GetFloatingItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 *index = &sFloatingItemIndex;

    *index = islander->islander_npc_idx * 7;
    *index += sFloatingItemHourOffsets[field->last_palette_hour];
    *index = sFloatingItemBaseIndices[*index];
    *index += gMoveAction11EmotionSpawnOffsets[islander->emotion];
    if ((islander->equipped_tool_state & 0xF) == 5) {
        *index += 20;
    }
    if (*index >= 160) {
        return 0;
    }
    if (*index > 160) {
        *index = 0;
    }
    return *index;
}

/* Original address: 0x02020DA8 */
void Islander_StepFlyingItem(void) {
    Islander_AGB *islander = &gIslander;
    Entity *balloon;
    s32 i;
    u16 *items;
    EntitySpawnParams *params;
    u16 *tile_ids;
    u16 tile;
    u16 item;
    s32 chance;

    if (islander->move_action == 16) {
        return;
    }
    if (islander->flying_item_spawn_timer != 0) {
        islander->flying_item_spawn_timer--;
        return;
    }
    if (islander->stored_item_type_plus_one[4] == 0 && islander->flying_item_x == 0 && islander->flying_item_y == 0) {
        i = Island_GetFloatingItem();
        params = &sFlyingItemParams[i];
        i = SpawnEntity(0, 1, params->type, params->param);
        if (i == 0) {
            return;
        }
        balloon = &g_EntityTable[i];
        if ((rand_u16(&gGameState) & 1) == 0) {
            balloon->x = 16;
            balloon->horizontal_velocity = 24;
            balloon->vertical_velocity_or_x_limit = 465;
        } else {
            balloon->x = 464;
            balloon->horizontal_velocity = -24;
            balloon->vertical_velocity_or_x_limit = 15;
        }
        balloon->y = (rand_u16(&gGameState) % 5) * 16 + 80;
        islander->flying_item_x = balloon->x;
        islander->flying_item_y = balloon->y;
        params++;
        items = &balloon->item_ids[1];
        tile_ids = &balloon->item_type_indices[1];
        i = 3;
        do {
            tile = params->type;
            item = params->param;
            if (item == 4) {
                EntitySpawnParams *fruit = &sFlyingItemFruitParams[rand_u16(&gGameState) % 6];
                tile = fruit->type;
                item = fruit->param;
            }
            *tile_ids = tile;
            *items = item;
            items++;
            tile_ids++;
            i--;
            params++;
        } while (i >= 0);
    } else if (islander->move_action == 3) {
        if (islander->stored_item_type_plus_one[4] != 0) {
            islander->floating_balloon_target_entity_id = 0;
            return;
        }
        if ((islander->equipped_tool_state & 0xF) == 1 || (islander->equipped_tool_state & 0xF) == 5) {
            islander->work_x = islander->flying_item_x - islander->x;
            islander->work_y = islander->flying_item_y - islander->y;
            if (islander->work_x < 0) {
                islander->work_x = -islander->work_x;
            }
            if (islander->work_y < 0) {
                islander->work_y = -islander->work_y;
            }
            if (islander->work_x <= 0x1000 && islander->work_y <= 0x1000) {
                chance = 100;
                if (islander->reward_adjust == 1) {
                    chance = 50;
                }
                if (chance >= rand_u16(&gGameState) % 101) {
                    if (islander->x > islander->flying_item_x) {
                        islander->direction = 0;
                    } else {
                        islander->direction = 1;
                    }
                    islander->move_action = MoveActionReceiveItemInit;
                    Islander_ReceiveItem_Init();
                }
            }
        }
    }
}

/* Original address: 0x02020F54 */
s32 Islander_TryStartFishing(void) {
    u16 tile;
    u16 *tilemap;
    s32 i;
    s32 water_tiles;
    s32 chance;
    Islander_AGB *islander = &gIslander;
    s32 can_fish = 0;

    if (islander->fishing_cooldown_timer == 0 && ((islander->equipped_tool_state & 0xF) == 4 || (islander->equipped_tool_state & 0xF) == 8)) {
        if (!(islander->x & 0xFF0000)) {
            tile = islander->tile_idx - 2;
            tile += 16;
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
        } else {
            tile = islander->tile_idx + 18;
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
        }
        tilemap += (tile & 0xF0) * 4;
        tilemap += (tile & 0xF) * 2;
        i = 0;
        water_tiles = 0;
        do {
            tile = *tilemap & 0x3FF;
            if (tile == 0xF6) {
                water_tiles++;
            }
            if (i == 0 || i == 2) {
                tilemap++;
            } else if (i == 1) {
                tilemap += 31;
            }
            i++;
        } while (i < 4);
        if (water_tiles > 3) {
            can_fish = 1;
        }
        if (can_fish != 0) {
            chance = 25;
            if (islander->reward_adjust == 1) {
                chance = 50;
            }
            if (chance > rand_u16(&gGameState) % 101) {
                if (!(islander->x & 0xFF0000)) {
                    islander->direction = 0;
                } else {
                    islander->direction = 1;
                }
                islander->move_action = MoveAction13;
                Islander_Fishing_Init();
                return 1;
            }
        }
    }
    return 0;
}

/* Original address: 0x02021050 */
u16 Islander_TakeCurrentTileItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item;

    if (!(islander->x & 0xFF0000)) {
        field->fg_tiles[0][islander->tile_idx] = 0x7777;
        item = gIslandData->fgblock[0][0].items[islander->tile_idx >> 4][islander->tile_idx & 0xF];
    } else {
        field->fg_tiles[1][islander->tile_idx] = 0x7777;
        item = gIslandData->fgblock[0][1].items[islander->tile_idx >> 4][islander->tile_idx & 0xF];
    }
    return item;
}

/* Original address: 0x020210D4 */
s32 Islander_TryInteractWithCurrentTile(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item = 0;
    u16 tile;
    ItemGroupStruct *definition;
    s32 state;
    s32 result;
    s32 slot;

    state = islander->equipped_tool_state & 0xF;
    if (state != 0 && state != 3 && state != 7) {
        return 0;
    }
    if (!(islander->x & 0xFF0000)) {
        tile = field->fg_tiles[0][islander->tile_idx];
    } else {
        tile = field->fg_tiles[1][islander->tile_idx];
    }
    if (tile == 0xFFF) {
        return 0;
    }
    if (tile & 0x8000) {
        return 0;
    }
    if (tile == 0x7777) {
        return 0;
    }
    if (tile == 0x3333) {
        return 0;
    }
    definition = &g_ItemDefinitions[tile];
    if (definition->held_item_oam_attr2 == 0xFFF) {
        return 0;
    }
    if (!(islander->x & 0xFF0000)) {
        result = Islander_TryInteractWithBuriedItem(0);
    } else {
        result = Islander_TryInteractWithBuriedItem(1);
    }
    if (result == 2) {
        return 1;
    }
    if (result == 1) {
        return 0;
    }

    islander->removed_field_item_type = 0;
    if ((islander->equipped_tool_state & 0xF) == 3 || (islander->equipped_tool_state & 0xF) == 7) {
        if (islander->stored_item_type_plus_one[4] != 0 ||
            (definition->interaction_type >= 7 && definition->interaction_type <= 14)) {
            return 0;
        }
        item = Islander_TakeCurrentTileItem();
    } else if (!(definition->interaction_type >= 5 && definition->interaction_type <= 6)) {
        if (definition->interaction_type >= 7 && definition->interaction_type <= 14) {
            islander->removed_tool_item = Islander_TakeCurrentTileItem();
            islander->removed_field_item_type = tile;
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->removed_tool_tile_idx = islander->tile_idx;
            if (islander->x & 0xFF0000) {
                islander->removed_tool_layer = 1;
            }
        } else {
            if (islander->stored_item_type_plus_one[4] != 0) {
                return 0;
            }
            item = Islander_TakeCurrentTileItem();
        }
    }

    if (!(islander->x & 0xFF0000)) {
        field->fg_tiles[0][islander->tile_idx] = 0x7777;
    } else {
        field->fg_tiles[1][islander->tile_idx] = 0x7777;
    }
    islander->target_x = islander->x & 0xFF0000;
    islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
    islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
    islander->item_work.held_item.type_idx = 2;
    islander->target_action = 0x10;
    islander->move_action = 4;
    islander->immediate_item_type_plus_one = 0;
    if (item != 0) {
        for (slot = 0; slot < 5; slot++) {
            if (islander->stored_item_type_plus_one[slot] == 0) {
                islander->stored_item_type_plus_one[slot] = tile + 1;
                islander->stored_item_ids[slot] = item;
                islander->stored_item_slot = slot;
                return 1;
            }
        }
    } else {
        if (islander->removed_field_item_type == 0) {
            islander->immediate_item_type_plus_one = tile + 1;
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x020212F4 */
s32 Islander_TryStartDigging(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 tile;
    u8 *standing_tile;

    if ((islander->emotion == ISLANDER_EMOTION_HAPPY || islander->emotion == ISLANDER_EMOTION_ANGRY) &&
        ((islander->equipped_tool_state & 0xF) == 3 || (islander->equipped_tool_state & 0xF) == 7) && islander->digging_cooldown_timer == 0) {
        if (!(islander->x & 0xFF0000)) {
            standing_tile = &islander->tile_idx;
            tile = field->fg_tiles[0][*standing_tile];
        } else {
            standing_tile = &islander->tile_idx;
            tile = field->fg_tiles[1][*standing_tile];
        }
        if (tile == 0xFFF && rand_u16(&gGameState) % 101 <= 5 &&
            Islander_CanDigHere() != 0 && (u16)Islander_SetupDigApproach(0xF1) != 0) {
            islander->accepted_x = islander->target_x;
            islander->accepted_y = islander->target_y;
            islander->dig_target_layer = 0;
            islander->dig_target_tile_idx = *standing_tile;
            if (islander->x & 0xFF0000) {
                islander->dig_target_layer = 1;
            }
            islander->buried_item_tile_base = 0;
            islander->item_work.held_item.type_idx = 2;
            islander->move_action = MoveAction4;
            IslanderMoveAction_MoveToTarget();
            return 2;
        }
    }
    return 0;
}

/* Original address: 0x020213DC */
void RestoreHeldItemsToField(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Player *player = &gPlayer;
    u32 tool;
    u16 tile;
    u16 *tilemap_vram;

    if (player->held_item_layer != 0 || player->held_item_tile_idx != 0) {
        ItemGroupStruct *definition = &g_ItemDefinitions[player->held_item_type_idx];
        WriteItemToTile(player->held_item_layer << 16, player->held_item_tile_idx,
                        player->held_item, definition->field_tile_id);
        if (player->held_item_layer == 0) {
            field->fg_tiles[0][player->held_item_tile_idx] = player->held_item_type_idx;
        } else {
            field->fg_tiles[1][player->held_item_tile_idx] = player->held_item_type_idx;
        }
        player->held_item_layer = 0;
        player->held_item_tile_idx = 0;
        field->entity_active[2] = 0;
    }

    tool = islander->equipped_tool_state & 0xF;
    if (tool != 0) {
        tile = tool;
        if (tile > 4) {
            tile -= 4;
        }
        tile = tile * 2 + 0x8043;
        if (tool > 4) {
            tile++;
        }
        if (islander->removed_tool_layer != 0 || islander->removed_tool_tile_idx != 0) {
            if (islander->removed_tool_layer == 0) {
                field->fg_tiles[0][islander->removed_tool_tile_idx] = tile;
                tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF0) * 4;
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF) * 2;
                gIslandData->fgblock[0][0].items[(islander->removed_tool_tile_idx >> 4) & 0xF][islander->removed_tool_tile_idx & 0xF] = islander->removed_tool_item;
            } else {
                field->fg_tiles[1][islander->removed_tool_tile_idx] = tile;
                tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF0) * 4;
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF) * 2;
                gIslandData->fgblock[0][1].items[(islander->removed_tool_tile_idx >> 4) & 0xF][islander->removed_tool_tile_idx & 0xF] = islander->removed_tool_item;
            }
            WriteItemTileToVRAM(tilemap_vram, 0x6234);
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->equipped_tool_state = 0;
            islander->removed_tool_item = 0;
            if (islander->move_action == MoveAction3) {
                Islander_AdjustAnimForTool();
            }
        }
    }
}
/* Original address: 0x02021574 */
void Islander_UpdateMovement(void) {
    Islander_AGB *islander = &gIslander;

    if (gIslandFieldWork.gameplay_active != 0) {
        Islander_StepFlyingItem();
        if ((islander->move_action >= MoveAction9 && islander->move_action <= CheckClickedOnTimer) ||
            islander->click_cooldown_timer == 0) {
            if (islander->move_action == MoveAction3) {
                Islander_MoveWithCollision();
            }
            IslanderMoveProcTable[islander->move_action]();
        }
    }
}

/* Original address: 0x020215D0 */
void Islander_StartHouseTransition(void) {
    gIslander.anim_timer = 0;
    gIslander.anim_frame = 0;
    gIslander.target_x = 0;
    gIslander.target_y = 0;
    gIslander.direction = 0;
    if (gIslander.anim_id == 0x60) {
        gIslander.anim_timer = 0xFE;
    }
    gIslander.move_action = 1;
}

/* Original address: 0x02021608 */
void Islander_MoveIndoorsOrOutdoors(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    s32 i;
    u8 anim_id;

    if (islander->anim_timer != 0xFE) {
        if (islander->anim_timer == 0) {
            if (islander->anim_id == ISLANDER_ANIM_5F) {
                if (islander->anim_frame == 8) {
                    Sound_PlayEffect0(1);
                }
                if (islander->anim_frame == 0x13) {
                    Sound_PlayEffect0(0xE);
                }
            } else {
                if (islander->anim_frame == 1) {
                    Sound_PlayEffect0(1);
                }
                if (islander->anim_frame == 0xB) {
                    Sound_PlayEffect0(0xE);
                }
            }
        }
        if (Islander_PlayAnim(1) != 0) {
            anim_id = islander->anim_id;
            if (anim_id == ISLANDER_ANIM_60) {
                house->state = 1;
                islander->y += 0x1200;
                islander->accepted_y = islander->y;
                islander->direction_change_cooldown_timer = anim_id;
                islander->move_action = ActionOutside;
                Islander_StartWandering();
                islander->collision_bypass_timer = 0x40;
                islander->wander_timer = 0x60;
            } else {
                for (i = 0; i < 5; i++) {
                    if (islander->stored_item_type_plus_one[0] != 0) {
                        islander->mood_level++;
                        if (islander->mood_level > 6) {
                            islander->mood_level = 6;
                        }
                        Islander_OnMoodChanged();
                        Islander_ClearStoredItem(0);
                    }
                }
                islander->anim_timer = 0xFE;
                islander->anim_id = ISLANDER_ANIM_60;
                islander->move_action = ActionInside;
                house->state = 1;
            }
        }
    }
}
/* Original address: 0x02021720 */
void Islander_StartWandering(void) {
    Islander_AGB *islander = &gIslander;
    s32 base_duration = 0;
    AnimFrameData *anim;

    islander->anim_id = ISLANDER_ANIM_00;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->reaction_anim_id = ISLANDER_ANIM_00;
    Islander_AdjustAnimForTool();
    anim = *gIslanderAnimData[islander->anim_id];
    switch (islander->emotion) {
    case ISLANDER_EMOTION_NEUTRAL:
    case ISLANDER_EMOTION_HAPPY:
        base_duration = 0x180;
        break;
    case ISLANDER_EMOTION_ANGRY:
    case ISLANDER_EMOTION_SAD:
        base_duration = 0x100;
        break;
    }
    islander->wander_timer = base_duration + rand_u16(&gGameState) % 337;
    islander->anim_timer = anim->duration;
    islander->move_action = MoveAction3;
}

/* Original address: 0x020217AC */
void Islander_UpdateWandering(void) {
    Islander_AGB *islander = &gIslander;
    s32 direction = 0;

    Islander_UpdateBlink();
    if (islander->tree_action_cooldown_timer != 0) {
        islander->tree_action_cooldown_timer--;
    }
    if (islander->digging_cooldown_timer != 0) {
        islander->digging_cooldown_timer--;
    }
    if (islander->direction_change_cooldown_timer != 0) {
        islander->direction_change_cooldown_timer--;
    }
    if (islander->fishing_cooldown_timer != 0) {
        islander->fishing_cooldown_timer--;
    }
    if (islander->equipped_tool_state & 0xF) {
        if (islander->equipped_tool_timer > 0x1C20) {
            if (Islander_TryDropTool() != 0) {
                islander->equipped_tool_timer = 0;
            }
        } else {
            islander->equipped_tool_timer++;
        }
    }
    if (Islander_TryInteractWithCurrentTile() == 0 && Islander_TryStartFishing() == 0 && Islander_TryStartDigging() == 0) {
        if (islander->target_x != 0 && islander->target_y != 0 &&
            Islander_FaceTargetAndCheckArrival(islander->target_x, islander->target_y) != 0) {
            if (islander->wander_timer < 0x60) {
                islander->wander_timer = 0x60;
            }
            islander->target_x = 0;
            islander->target_y = 0;
        }
        if (islander->emotion != ISLANDER_EMOTION_HAPPY || islander->target_y == 0) {
            if (islander->wander_timer == 0) {
                direction = Islander_ChooseNewMoveDirection(0);
                if (direction != 0x777) {
                    islander->direction = direction;
                    islander->move_action = ActionOutside;
                    Islander_StartWandering();
                    return;
                }
            } else {
                islander->wander_timer--;
            }
        }
        Islander_PlayAnim(0);
    }
}

/* Original address: 0x020218B0 */
void IslanderMoveAction_MoveToTarget(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    FieldObject *object = NULL;
    s32 continue_moving = 0;

    Islander_UpdateBlink();
    if (islander->target_y & 0xFFFF0000) {
        islander->target_y &= 0xFFFF;
    }
    if (islander->next_target_y & 0xFFFF0000) {
        islander->next_target_y &= 0xFFFF;
    }
    if (Islander_ChangeMoveDir(islander->target_x, islander->target_y,
                             (u8)islander->item_work.held_item.type_idx)) {
        if (islander->target_action == 0x30 || islander->target_action == 0x40) {
            object = &gFieldObjects[islander->target_field_object_idx];
        }
        switch (islander->target_action) {
        case 0x10:
            islander->move_action = MoveAction5;
            Islander_StartFoodProcessing();
            break;
        case 0x20:
            islander->x = islander->target_x;
            islander->y = islander->target_y - 0x1000;
            house->state = 0;
            islander->anim_id = ISLANDER_ANIM_5F;
            islander->move_action = ActionInside;
            Islander_StartHouseTransition();
            islander->anim_timer = 4;
            break;
        case 0x30:
            object->x_flip = 0;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                if ((islander->equipped_tool_state & 0xF) != 2 && (islander->equipped_tool_state & 0xF) != 6) {
                    islander->anim_id = 0x62;
                } else {
                    islander->anim_id = ISLANDER_ANIM_55;
                }
                islander->x = islander->target_x;
                islander->y = islander->target_y;
                islander->move_action = MoveAction11;
                Islander_StartFieldObjectInteraction();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x40:
            object->x_flip = 1;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                if ((islander->equipped_tool_state & 0xF) != 2 && (islander->equipped_tool_state & 0xF) != 6) {
                    islander->anim_id = ISLANDER_ANIM_61;
                } else {
                    islander->anim_id = ISLANDER_ANIM_54;
                }
                islander->x = islander->target_x;
                islander->y = islander->target_y;
                islander->move_action = MoveAction11;
                Islander_StartFieldObjectInteraction();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x50:
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            Islander_ChooseNewMoveDirection(1);
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            break;
        case 0x60:
            islander->direction = 0;
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                islander->item_work.held_item.type_idx = 0;
                islander->target_action = 0;
                islander->move_action = MoveActionDig;
                IslanderMoveAction_Dig();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x70:
            islander->direction = 1;
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                islander->item_work.held_item.type_idx = 0;
                islander->target_action = 0;
                islander->move_action = MoveActionDig;
                IslanderMoveAction_Dig();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        }
        if (!continue_moving) {
            islander->item_work.held_item.type_idx = 0;
            islander->target_action = 0;
            islander->target_x = 0;
            islander->target_y = 0;
            return;
        }
    }
    Islander_PlayAnim(0);
}


/* Original address: 0x02021AD8 */
void Islander_StartFoodProcessing(void) {
    Islander_AGB *islander = &gIslander;
    u8 *anim_id = &islander->anim_id;
    u8 *tilemap;
    u8 initial_frame = 0;
    u32 item_type_idx;

    islander->anim_frame = initial_frame;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->anim_id = ISLANDER_ANIM_56;
    islander->anim_timer = gIslanderAnimData[*anim_id][0]->duration;
    if (islander->removed_tool_layer == 0 && islander->removed_tool_tile_idx == 0) {
        WriteItemToTile(islander->x, islander->tile_idx, 0, 0x200);
    } else {
        if ((islander->x & 0xFF0000) == 0) {
            tilemap = (u8 *)BG_SCREEN_ADDR(24);
        } else {
            tilemap = (u8 *)BG_SCREEN_ADDR(25);
        }
        tilemap = (0xF0 & islander->tile_idx) * 8 + tilemap;
        tilemap = (0xF & islander->tile_idx) * 4 + tilemap;
        WriteItemTileToVRAM((u16*)tilemap, 0x200);
    }
    Field_RestoreAdjacentTreeTiles(islander->tile_idx, islander->x);

    if (islander->immediate_item_type_plus_one == 0) {
        if (islander->removed_field_item_type == 0) {
            item_type_idx = islander->stored_item_type_plus_one[islander->stored_item_slot] - 1;
        } else {
            item_type_idx = islander->removed_field_item_type;
        }
    } else {
        item_type_idx = islander->immediate_item_type_plus_one - 1;
    }
    islander->held_item_sprite = (item_type_idx + g_ItemDefinitions)->held_item_oam_attr2 | 0x800000;
    islander->move_action = ProcessFood;
}

/* Original address: 0x02021BCC */
void Islander_ProcessFood(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    ItemGroupStruct *definition;
    u32 item_type_idx;
    s32 result;
    s32 i;

    if (islander->anim_id == ISLANDER_ANIM_56) {
        if (islander->anim_timer == 0) {
            if (islander->anim_frame == 2) {
                Sound_PlayEffect0(0x1D);
            }
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    result = 0;
    if (islander->immediate_item_type_plus_one == 0) {
        if (islander->removed_field_item_type == 0) {
            item_type_idx = islander->stored_item_type_plus_one[islander->stored_item_slot] - 1;
        } else {
            item_type_idx = islander->removed_field_item_type;
        }
    } else {
        item_type_idx = islander->immediate_item_type_plus_one - 1;
    }

    definition = g_ItemDefinitions + item_type_idx;
    islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;

    switch (islander->anim_id) {
    case ISLANDER_ANIM_56:
        islander->anim_id = ISLANDER_ANIM_58;
        if (islander->immediate_item_type_plus_one != 0) {
            islander->anim_id = ISLANDER_ANIM_57;
            Sound_PlayEffect0(0x19);
        }
        break;

    case ISLANDER_ANIM_57: {
        u8 *food_preferences;
        u8 *food_preference_layout;

        islander->held_item_sprite = 0;
        if ((islander->x & 0xFF0000) == 0) {
            field->fg_tiles[0][islander->tile_idx] = 0xFFF;
        } else {
            field->fg_tiles[1][islander->tile_idx] = 0xFFF;
        }

        i = 0;
        food_preferences = (u8 *)&ISLANDER_FOOD_PREFERENCES;
        food_preference_layout = food_preferences + sizeof(ISLANDER_FOOD_PREFERENCES.preferences);
        for (; i < 9; i++) {
            if (item_type_idx == food_preference_layout[i]) {
                u8 preference_idx = islander->islander_npc_idx * 9 + i;
                u8 preference = food_preferences[preference_idx];

                islander->mood_level += preference;
                if ((preference & 0x80) == 0) {
                    islander->reaction_anim_id = ISLANDER_ANIM_59;
                } else {
                    islander->reaction_anim_id = ISLANDER_ANIM_5D;
                }
                break;
            }
        }

        result = 3;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        } else if (islander->mood_level > 5) {
            if ((islander->x & 0xFF0000) == 0) {
                field->fg_tiles[0][islander->tile_idx] = 0x3333;
            } else {
                field->fg_tiles[1][islander->tile_idx] = 0x3333;
            }
            islander->mood_level = 6;
            break;
        }
        islander->immediate_item_type_plus_one = 0;
        break;
    }

    case ISLANDER_ANIM_58:
        islander->held_item_sprite = 0;
        if ((islander->x & 0xFF0000) == 0) {
            if (islander->removed_tool_tile_idx != islander->tile_idx) {
                field->fg_tiles[0][islander->tile_idx] = 0xFFF;
            }
        } else if (islander->removed_tool_tile_idx != islander->tile_idx) {
            field->fg_tiles[1][islander->tile_idx] = 0xFFF;
        }

        switch (definition->interaction_type) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            islander->reaction_anim_id = ISLANDER_ANIM_59;
            result = 3;
            break;
        case 4:
            islander->mood_level = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
            result = 1;
            break;
        case 8:
            islander->equipped_tool_state = 5;
            result = 2;
            break;
        case 7:
            islander->equipped_tool_state = 1;
            result = 2;
            break;
        case 10:
            islander->equipped_tool_state = 6;
            result = 2;
            break;
        case 9:
            islander->equipped_tool_state = 2;
            result = 2;
            break;
        case 12:
            islander->equipped_tool_state = 7;
            result = 2;
            break;
        case 11:
            islander->equipped_tool_state = 3;
            result = 2;
            break;
        case 14:
            islander->equipped_tool_state = 8;
            result = 2;
            break;
        case 13:
            islander->equipped_tool_state = 4;
            result = 2;
            break;
        default:
            break;
        }
        break;
    }

    switch (result) {
    case 1:
        Islander_ClearStoredItem(islander->stored_item_slot);
        /* fallthrough */
    case 3:
        if (result != 1) {
            Islander_OnMoodChanged();
            if ((islander->emotion == ISLANDER_EMOTION_SAD) && (islander->reward_adjust == 0)) {
                islander->emotion = ISLANDER_EMOTION_ANGRY;
                ChangeEmotion(2);
            }
        }
        islander->item_work.held_item.type_idx = 2;
        islander->target_action = 0x50;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case 2:
        WriteItemToTile(islander->x, islander->tile_idx, 0, 0x200);
        islander->equipped_tool_timer = 0;
        islander->direction_change_cooldown_timer = 0x20;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
        break;
    }

    islander->anim_timer = gIslanderAnimData[islander->anim_id][islander->anim_frame]->duration;
}

void IslanderMoveAction_UpdateEmotion(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->anim_id = islander->reaction_anim_id;
    anim_data = *gIslanderAnimData[islander->anim_id];

    switch (islander->reaction_anim_id) {
    case ISLANDER_ANIM_59:
        Sound_PlayEffect0(9);
        break;
    case ISLANDER_ANIM_5A:
        Sound_PlayEffect0(10);
        break;
    case ISLANDER_ANIM_ANGRY:
        Sound_PlayEffect0(11);
        break;
    case ISLANDER_ANIM_SAD:
        Sound_PlayEffect0(12);
        break;
    case ISLANDER_ANIM_5D:
        Sound_PlayEffect0(13);
        break;
    case ISLANDER_ANIM_5E:
        break;
    }

    ChangeEmotion(islander->emotion + 1);
    islander->anim_timer = anim_data->duration;
    islander->move_action = MoveAction8;
}

/* Original address: 0x02022054 */
void Islander_UpdateEmotionAnimation(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    mActor_name_t *stored_item;
    u16 *stored_type_plus_one;
    s32 i;
    u16 random = 0;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->direction_change_cooldown_timer = 0x20;
    if ((islander->immediate_item_type_plus_one != 0) && (islander->reaction_anim_id == ISLANDER_ANIM_59)) {
        islander->immediate_item_type_plus_one = random;
        if (islander->mood_level == 6) {
            if (islander->stored_item_type_plus_one[0] != 0) {
                if (SpawnEntity(1, 0, islander->stored_item_type_plus_one[0] - 1,
                                islander->stored_item_ids[0]) != 0) {
                    Islander_ClearStoredItem(0);
                }
            } else {
                random = rand_u16(&gGameState) % 101;
                if (random < 60) {
                    SpawnEntity(0, 0, 0xB, 8);
                } else if (random < 90) {
                    SpawnEntity(0, 0, 0x42, 9);
                } else if (random < 98) {
                    SpawnEntity(0, 0, 0x43, 10);
                } else {
                    SpawnEntity(0, 0, 0x44, 11);
                }
            }
        }
    }

    if (islander->target_action == 0x50) {
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->anim_frame = 0;
        Islander_AdjustAnimForTool();
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->move_action = MoveAction4;
        IslanderMoveAction_MoveToTarget();
        return;
    }

    if (islander->target_action == 0x80) {
        house->state = 0;
        islander->x = house->x << 8;
        islander->y = house->y << 8;
        islander->target_action = 0;
        islander->anim_id = ISLANDER_ANIM_5F;
        islander->move_action = ActionInside;
        Islander_StartHouseTransition();
        islander->anim_timer = 4;
        {
            u16 empty_item = 0;

            stored_item = islander->stored_item_ids;
            stored_type_plus_one = islander->stored_item_type_plus_one;
            i = 4;
            do {
                *stored_type_plus_one = empty_item;
                *stored_item = empty_item;
                stored_item++;
                stored_type_plus_one++;
                i--;
            } while (i >= 0);
        }
        return;
    }

    Islander_ChooseNewMoveDirection(1);
    islander->move_action = ActionOutside;
    Islander_StartWandering();
}

/* Original address: 0x020221C0 */
void Islander_StartClickReaction(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    IslanderDirectionSector *sector;
    u16 tile_id;
    u16 angle;
    s32 sector_idx;

    if (islander->interaction_target_is_islander == 0) {
        if ((islander->target_x & 0xFF0000) == 0) {
            tile_id = field->fg_tiles[0][islander->player_interaction_tile_idx];
        } else {
            tile_id = field->fg_tiles[1][islander->player_interaction_tile_idx];
        }

        if ((tile_id == 0xFFF) || (tile_id == 0x3333) || (tile_id == 0x7777) ||
            ((g_ItemDefinitions + tile_id)->held_item_oam_attr2 == 0xFFF)) {
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            return;
        }
    }

    Islander_SpawnReactionEffect(0, 0x30);
    islander->click_cooldown_timer = 0x30;
    islander->direction_change_cooldown_timer = 0x60;
    islander->work_x = (islander->target_x - islander->x) >> 8;
    islander->work_y = (islander->target_y - islander->y) >> 8;
    angle = ArcTan2((s16)islander->work_x, (s16)islander->work_y);

    sector = &gIslanderDirectionSectors[7];
    if (angle < sector->max_angle) {
        sector_idx = 0;
        sector -= 7;
        if (angle > sector->max_angle) {
            do {
                sector_idx++;
                sector++;
            } while ((sector_idx <= 6) && (angle > sector->max_angle));
        }
    } else {
        sector_idx = 0;
    }

    islander->direction = gIslanderDirectionSectors[sector_idx].direction;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    Islander_AdjustAnimForTool();
    islander->move_action = CheckClickedOnTimer;
}

void Islander_CheckClickedOnTimer(void) {
    Islander_AGB *islander = &gIslander;
    u8 timer;
    u8 state;

    timer = --islander->click_cooldown_timer;
    if (timer == 0) {
        if (islander->reaction_anim_id == ISLANDER_ANIM_00) {
            state = islander->equipped_tool_state;
            if (state & 0x40) {
                islander->equipped_tool_state = state - 0x40;
                Islander_TryDropTool();
            }
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            return;
        }

        islander->reaction_anim_id = 0;
        islander->mood_level--;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        }
        Islander_OnMoodChanged();

        if ((islander->emotion == ISLANDER_EMOTION_NEUTRAL) ||
            (islander->emotion == ISLANDER_EMOTION_HAPPY)) {
            islander->direction = 0;
            Islander_SpawnReactionEffect(1, 0x30);
            islander->click_cooldown_timer = 0x30;
            return;
        }

        if (islander->reward_adjust == 0) {
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
        } else {
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
        }
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
}

/* Original address: 0x020223AC */
void Islander_StartFieldObjectInteraction(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];

    islander->anim_frame = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->item_work.held_item.type_idx = 0;
    islander->tree_action_cooldown_timer = 0;
    if (((islander->equipped_tool_state & 0xF) != 2) && ((islander->equipped_tool_state & 0xF) != 6)) {
        islander->action_state = 0;
        field_object->shake_animation_paused = 1;
        field_object->action_state = 1;
    } else {
        field_object->shake_animation_paused = 0;
        islander->action_state = 1;
    }
    islander->move_action = MoveAction12;
}

void Islander_MoveAction11_State0(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];

    if ((islander->anim_frame != 0) && (islander->anim_timer == 1)) {
        field_object->anim_frame = gMoveAction11ObjectAnimFrames[islander->anim_frame - 1];
    }
    if (Islander_PlayAnim(1) != 0) {
        islander->tree_action_cooldown_timer = 600;
        islander->action_state = 0;
        field_object->anim_frame = 3;
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->item_work.held_item.type_idx = 1;
        islander->target_field_object_idx = 0;
        Islander_AdjustAnimForTool();
        islander->item_work.held_item.type_idx = 1;
        islander->target_action = 0x50;
        islander->move_action = MoveAction4;
        IslanderMoveAction_MoveToTarget();
    }
}

void Islander_MoveAction11_State1(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];
    Entity *entity;
    EntitySpawnParams *spawn_params;
    u16 *tiles;
    s32 spawn_idx;
    s32 random;
    s32 entity_tile_idx;
    s32 map_tile_offset;

    if (Islander_PlayAnim(1) != 0) {
        if ((field_object->hits_remaining == 0) || (field_object->hits_remaining & 0x80)) {
            islander->tree_action_cooldown_timer = 0x20;
            islander->action_state = 2;
        } else {
            islander->move_action = MoveAction11;
            Islander_StartFieldObjectInteraction();
        }
    }

    if ((islander->anim_frame != 3) || (islander->anim_timer != 1)) {
        return;
    }

    if ((field_object->favorite_hour_item_eligible == 1) && (islander->favorite_hour_item_spawned == 0) &&
        (islander->item_work.held_item.type_idx == 0) &&
        (field->last_palette_hour == gIslanderFavoriteHours[islander->islander_npc_idx]) &&
        ((rand_u16(&gGameState) % 101) <= 24)) {
        if (field_object->layer == 0) {
            map_tile_offset = field_object->tile_idx;
            map_tile_offset += 0x10;
            map_tile_offset *= sizeof(u16);
            tiles = field->fg_tiles[0];
        } else {
            map_tile_offset = field_object->tile_idx;
            map_tile_offset += 0x10;
            map_tile_offset *= sizeof(u16);
            tiles = field->fg_tiles[1];
        }
        if (*(u16 *)((u8 *)tiles + map_tile_offset) == 0xFFF) {
            islander->item_work.held_item.type_idx = 1;
            spawn_idx = 0;
            if ((islander->equipped_tool_state & 0xF) == 6) {
                spawn_idx = 0x14;
            }
            spawn_idx += gMoveAction11EmotionSpawnOffsets[islander->emotion];
            random = rand_u16(&gGameState);
            spawn_idx += random % 4;
            spawn_params = &gMoveAction11EntitySpawnParams[spawn_idx];
            spawn_idx = SpawnEntity(0, 2, spawn_params->type, spawn_params->param);
            if (spawn_idx != 0) {
                if (field_object->layer == 0) {
                    map_tile_offset = islander->tile_idx;
                    map_tile_offset *= sizeof(u16);
                    tiles = field->fg_tiles[0];
                } else {
                    map_tile_offset = islander->tile_idx;
                    map_tile_offset *= sizeof(u16);
                    tiles = field->fg_tiles[1];
                }
                *(u16 *)((u8 *)tiles + map_tile_offset) = 0x3333;
                entity = &g_EntityTable[spawn_idx];
                entity->base_y = (entity->y + 0x20) << 8;
                entity_tile_idx = field_object->tile_idx + 0x10;
                entity->landing_tile = entity_tile_idx;
                if (field_object->layer != 0) {
                    entity->landing_tile = entity_tile_idx | 0x1000;
                }
                entity->landing_delay_timer = 0x35;
                entity->y -= 0x20;
                entity->x = field_object->x - 8;
                islander->favorite_hour_item_spawned = 1;
            }
        }
    }
    field_object->action_state = 1;
    field_object->hits_remaining--;
    Sound_PlayEffect0(0);
}

void Islander_MoveAction11_State2(void) {
    Islander_AGB *islander = &gIslander;
    u16 next_timer;

    next_timer = (islander->tree_action_cooldown_timer = islander->tree_action_cooldown_timer - 1);
    if (next_timer == 0) {
        islander->tree_action_cooldown_timer = 600;
        islander->item_work.held_item.type_idx = next_timer;
        islander->action_state = 0;
        if (islander->emotion == ISLANDER_EMOTION_ANGRY) {
            islander->mood_level++;
            if (islander->mood_level > 6) {
                islander->mood_level = 6;
            }
            Islander_OnMoodChanged();
        }
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->item_work.held_item.type_idx = 1;
        islander->target_action = 0x50;
        islander->reaction_anim_id = ISLANDER_ANIM_59;
        IslanderMoveAction_UpdateEmotion();
    }
}

extern Islander_SUB_MOVE_PROC sIslanderMoveAction11SubMoveProcs[];

/* Original address: 0x0202275C */
void Islander_UpdateFieldObjectInteraction(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderMoveAction11SubMoveProcs[islander->action_state]();
}

void Islander_Fishing_Init(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_38;
    } else {
        islander->anim_id = ISLANDER_ANIM_41;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->action_state = 0;
    islander->move_action = MoveActionFishing;
}

void Islander_Fishing_State0(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;
    u8 *anim_timer;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_39;
        } else {
            islander->anim_id = ISLANDER_ANIM_42;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_timer = anim_data->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->item_work.held_item.tile_no = 0x20;
        islander->action_state = 1;
    }
    anim_timer = &islander->anim_timer;
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        Sound_PlayEffect0(0x14);
    }
}

void Islander_Fishing_State1(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->anim_frame = 0;
        islander->item_work.held_item.tile_no = 0x30;
        islander->item_work.held_item.type_idx = timer;
        Islander_SpawnReactionEffect(0, 0x30);
        islander->action_state = 2;
    }
}

void Islander_Fishing_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (--islander->item_work.held_item.tile_no == 0) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_3A;
        } else {
            islander->anim_id = ISLANDER_ANIM_43;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->action_state = 3;
        Sound_PlayEffect1(0x15);
        islander->item_work.held_item.tile_no = 0x51;
    }
}

void Islander_Fishing_State3(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->item_work.held_item.tile_no = timer;
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_3B;
        } else {
            islander->anim_id = ISLANDER_ANIM_44;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = Islander_GetFishingItem();
        islander->action_state = 4;
        Sound_StopEffect1(0x15);
        Sound_PlayEffect0(0x16);
    }
}

void Islander_Fishing_State4(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }
    Sound_PlayEffect0(0x1C);
    if (islander->item_work.held_item.type_idx == 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
    } else {
        if ((islander->held_item_sprite & 0xFFFF) == 0x434E) {
            islander->mood_level--;
            if (islander->mood_level & 0x80) {
                islander->mood_level = 0;
            }
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if ((islander->held_item_sprite & 0xFFFF) == 0x4350) {
            islander->mood_level++;
            if (islander->mood_level > 6) {
                islander->mood_level = 6;
            }
            Islander_SpawnReactionEffect(3, 0x30);
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3F;
            } else {
                islander->anim_id = ISLANDER_ANIM_48;
            }
        } else if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
        Islander_OnMoodChanged();
    }
    anim_data = *gIslanderAnimData[islander->anim_id];
    islander->action_state = 6;
    islander->item_work.held_item.tile_no = 0;
    islander->anim_frame = 0;
    islander->anim_timer = anim_data->duration;
}

void Islander_Fishing_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            islander->mood_level = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->move_action = ActionOutside;
            Islander_StartWandering();
        }
        islander->held_item_sprite = 0;
    }
}

void Islander_Fishing_State6(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        islander->fishing_cooldown_timer = 0x708;
        if (islander->item_work.held_item.type_idx == 0) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3C;
            } else {
                islander->anim_id = ISLANDER_ANIM_45;
            }
            islander->action_state = 5;
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3D;
            } else {
                islander->anim_id = ISLANDER_ANIM_46;
            }
            islander->action_state = 7;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->item_work.held_item.tile_no = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
    }
}

void Islander_Fishing_State7(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        Islander_ChooseNewMoveDirection(1);
        islander->held_item_sprite = 0;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
    }
}

void IslanderMoveAction_Fishing(void) {
    extern Islander_SUB_MOVE_PROC sIslanderFishingSubMoveProcs[];

    Islander_AGB *islander = &gIslander;

    sIslanderFishingSubMoveProcs[islander->action_state]();
}

void Islander_ReceiveItem_Init(void) {
    Islander_AGB *islander = &gIslander;

    islander->anim_frame = 0;
    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_4A;
    } else {
        islander->anim_id = ISLANDER_ANIM_4F;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->held_item_sprite = 0x800000;
    islander->action_state = 0;
    islander->move_action = MoveActionReceiveItem;
}

extern Islander_SUB_MOVE_PROC sIslanderReceiveItemSubMoveProcs[];

void IslanderMoveAction_ReceiveItem(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderReceiveItemSubMoveProcs[islander->action_state]();
}

void Islander_DespawnFlyingItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 *anim_timer;
    u8 anim_timer_value;
    Entity *entity;
    AnimFrameData *anim_data;
    s32 anim_finished;

    if (islander->held_item_sprite == 0) {
        islander->move_action = ActionOutside;
        Islander_StartWandering();
        return;
    }
    anim_timer_value = islander->anim_timer;
    anim_timer = &islander->anim_timer;
    if (anim_timer_value == 0) {
        if (islander->anim_frame == 2) {
            Sound_PlayEffect0(0x1A);
        }
        if (islander->anim_frame == 4) {
            Sound_PlayEffect0(0x1B);
        }
        if (islander->anim_frame == 8) {
            Sound_PlayEffect0(0x1C);
        }
    }
    anim_finished = Islander_PlayAnim(1);
    if (anim_finished != 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_4C;
            } else {
                islander->anim_id = ISLANDER_ANIM_51;
            }
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_4D;
            } else {
                islander->anim_id = ISLANDER_ANIM_52;
            }
            Islander_SpawnReactionEffect(3, 0x30);
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        *anim_timer = anim_data->duration;
        islander->action_state = 1;
        return;
    }

    entity = &g_EntityTable[islander->floating_balloon_target_entity_id];
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        islander->held_item_sprite = 0x800000;
        field->entity_active[islander->floating_balloon_target_entity_id + 3] = anim_finished;
        islander->item_work.held_item.tile_no = entity->item_type_indices[entity->frame_index];
        islander->item_work.held_item.type_idx = entity->item_ids[entity->frame_index];
        islander->flying_item_spawn_timer = 0x2A30;
        islander->flying_item_spawn_timer += (rand_u16(&gGameState) % 109) * 100;
        islander->flying_item_x = anim_finished;
        islander->flying_item_y = anim_finished;
        islander->floating_balloon_target_entity_id = 0;
        islander->held_item_sprite |= (g_ItemDefinitions + islander->item_work.held_item.tile_no)->held_item_oam_attr2;
    }
}

void Islander_StoreHeldItem(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        Islander_StoreItem(islander->item_work.held_item.tile_no,
                           islander->item_work.held_item.type_idx);
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_4B;
        } else {
            islander->anim_id = ISLANDER_ANIM_50;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
        islander->action_state = 2;
    }
}

void Islander_ProcessFishReceived(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        Islander_ChooseNewMoveDirection(1);
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            islander->mood_level = 0;
            islander->held_item_sprite = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
            return;
        }
        islander->held_item_sprite = 0;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
    }
}

void IslanderMoveAction_Dig(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_28;
    } else {
        islander->anim_id = ISLANDER_ANIM_30;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->action_state = 0;
    islander->move_action = MoveActionBury;
}

void Islander_BuryItem_State0(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 tile_idx = islander->interaction_tile;
    bool32 dug_empty = FALSE;
    u16 *tilemap_vram;
    ItemGroupStruct *definition;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 3) {
            Sound_PlayEffect0(0x21);
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->item_work.held_item.type_idx = 0;
    if (islander->interaction_tile & 0x8000) {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
        if (field->fg_tiles[1][tile_idx] == 0xFFF) {
            dug_empty = 1;
        } else {
            islander->item_work.held_item.type_idx = field->fg_tiles[1][tile_idx];
            if (islander->item_work.held_item.type_idx > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[1][tile_idx] = 0x7777;
    } else {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
        if (field->fg_tiles[0][tile_idx] == 0xFFF) {
            dug_empty = 1;
        } else {
            islander->item_work.held_item.type_idx = field->fg_tiles[0][tile_idx];
            if (islander->item_work.held_item.type_idx > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[0][tile_idx] = 0x7777;
    }

    tilemap_vram += (tile_idx & 0xF0) * 4;
    tilemap_vram += (tile_idx & 0xF) * 2;
    WriteItemTileToVRAM(tilemap_vram, 0x12AC);
    if (dug_empty == FALSE) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_2B;
        } else {
            islander->anim_id = ISLANDER_ANIM_33;
        }
        definition = g_ItemDefinitions + islander->item_work.held_item.type_idx;

        islander->held_item_sprite = 0x800000;
        islander->held_item_sprite |= definition->held_item_oam_attr2;
        islander->action_state = 2;
    } else {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_2A;
        } else {
            islander->anim_id = ISLANDER_ANIM_32;
        }
        islander->action_state = 1;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
}

void Islander_BuryItem_State1(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Island_agb_c *island;
    mActor_name_t item;
    u8 tile_idx = islander->interaction_tile;
    s32 is_tree;
    s32 item_type;
    ItemGroupStruct *definition;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    is_tree = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_29;
    } else {
        islander->anim_id = ISLANDER_ANIM_31;
    }
    islander->action_state = 4;
    islander->buried_item_tile_base = 0x1270;

    if (islander->emotion == ISLANDER_EMOTION_HAPPY) {
        islander->mood_level--;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        }
        Islander_OnMoodChanged();

        if (islander->stored_item_type_plus_one[0] != 0) {
            item_type = islander->stored_item_type_plus_one[0];
            item_type--;
            definition = &g_ItemDefinitions[item_type];
            islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;
            item = islander->stored_item_ids[0];
            if (Item_GetItemIdFromTileId(item_type) != 0) {
                item = Item_GetItemIdFromTileId(item_type);
                is_tree = 1;
            }
            Islander_ClearStoredItem(0);
        } else {
            Islander_PlantRandomFlower();
            return;
        }
    } else if ((s32)rand_u16(&gGameState) % 101 <= 49) {
        islander->held_item_sprite = 0x80609E;
        item = Item_TypeToIslandItem(0x11);
    } else {
        islander->held_item_sprite = 0x8050C0;
        item = 0x2512;
        islander->mood_level++;
        if (islander->mood_level > 6) {
            islander->mood_level = 6;
        }
        Islander_OnMoodChanged();
    }

    if (!(islander->interaction_tile & 0x8000)) {
        field->fg_tiles[0][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[0][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    } else {
        field->fg_tiles[1][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[1][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    }
}

void Islander_BuryItem_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2D;
            } else {
                islander->anim_id = ISLANDER_ANIM_35;
            }
            islander->mood_level = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
        } else if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FOSSIL) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_SEEDLING_DIARY_TICKET_GRAB_BAG) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_PITFALL) ||
                   IS_ITEM_TYPE_TOOL(islander->item_work.held_item.type_idx) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_AIR_CHECK) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_FLOWER_BAG)) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2F;
            } else {
                islander->anim_id = ISLANDER_ANIM_37;
            }
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2E;
            } else {
                islander->anim_id = ISLANDER_ANIM_36;
            }
            Islander_SpawnReactionEffect(3, 0x30);
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->action_state = 5;
        Sound_PlayEffect0(0x1C);
    }
}

/* Ghidra name: Islander_BuryItem (differs; duplicate label, state 3 of the bury action). */
void Islander_BuryItem_State3(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FURNITURE) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_GYROID) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_TURNIP) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_MUSHROOM) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CANDY) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_100_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_SHIRT) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_1K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_10K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_30K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CARPET) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_WALLPAPER) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_NES)) {
            Islander_BuryRandomItem(islander->item_work.held_item.type_idx);
        }
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            Islander_PlantRandomFlower();
        } else {
            if ((islander->buried_item_tile_base != 0x3260) && (islander->buried_item_tile_base != 0x3268)) {
                islander->buried_item_tile_base = 0x1270;
            }
        }
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_29;
        } else {
            islander->anim_id = ISLANDER_ANIM_31;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->action_state = 4;
    }
}

void Islander_BuryItem_State4(void) {
    Islander_AGB *islander = &gIslander;
    u16 world_state = islander->interaction_tile;
    u8 tile_idx = world_state;
    u8 *tilemap_vram;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 0xE) {
            tilemap_vram = (0x8000 & world_state) ?
                (u8 *)BG_SCREEN_ADDR(25) : (u8 *)BG_SCREEN_ADDR(24);
            tilemap_vram += (tile_idx & 0xF0) * 8;
            tilemap_vram += (tile_idx & 0xF) * 4;
            WriteItemTileToVRAM((u16*)tilemap_vram, 0x200);
        }
    }
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 1) {
            Sound_PlayEffect0(0x1E);
        }
        if (islander->anim_frame == 0xA) {
            Sound_PlayEffect0(0x22);
        }
        if (islander->anim_frame == 0x11) {
            Sound_PlayEffect0(0x23);
        }
    }

    if (Islander_PlayAnim(1) != 0) {
        islander->held_item_sprite = 0;
        islander->dig_target_layer = 0;
        islander->dig_target_tile_idx = 0;

        tilemap_vram = (0x8000 & islander->interaction_tile) ?
            (u8 *)BG_SCREEN_ADDR(25) : (u8 *)BG_SCREEN_ADDR(24);
        tilemap_vram += (tile_idx & 0xF0) * 8;
        tilemap_vram += (tile_idx & 0xF) * 4;
        WriteItemTileToVRAM((u16*)tilemap_vram, islander->buried_item_tile_base);
        islander->digging_cooldown_timer = 0x78;
        if (islander->buried_item_tile_base != 0x1270) {
            Sound_PlayEffect0(0x24);
        }

        if (islander->reaction_anim_id == ISLANDER_ANIM_ANGRY) {
            islander->collision_retry_count = 0;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->target_action = 0x50;
            islander->mood_level = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->target_action = 0x50;
            islander->collision_retry_count = 0;
            islander->anim_frame = 0;
            islander->anim_timer = 0;
            Islander_AdjustAnimForTool();
            islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
            islander->target_x = islander->accepted_x;
            islander->target_y = islander->accepted_y;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->move_action = MoveAction4;
            IslanderMoveAction_MoveToTarget();
        }
        islander->interaction_tile = 0;
    }
}

void Islander_BuryItem_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->anim_id == ISLANDER_ANIM_2F) ||
            (islander->anim_id == ISLANDER_ANIM_37)) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_29;
            } else {
                islander->anim_id = ISLANDER_ANIM_31;
            }
            islander->action_state = 4;
            islander->buried_item_tile_base = 0x1270;
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2C;
            } else {
                islander->anim_id = ISLANDER_ANIM_34;
            }
            islander->action_state = 3;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
    }
}

void IslanderMoveAction_Bury(void) {
    Islander_AGB* islander = &gIslander;

    IslanderSubMoveAction_BuryProcTbl[islander->action_state]();
}

void Islander_MoveAction20_Init(void) {
    Islander_AGB* islander = &gIslander;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->item_work.move_action20.phase = 0;
    islander->item_work.move_action20.timer = 0;
    islander->anim_id = ISLANDER_ANIM_5E;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->carry_wait_timer = 0x2A30;
    islander->target_x = 0;
    islander->target_y = 0;
    islander->accepted_x = islander->x;
    islander->accepted_y = islander->y;
    islander->action_state = 0;
    islander->move_action = MoveAction20;
}

void Islander_MoveAction20_State0(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->carry_state == 2) {
        islander->item_work.move_action20.phase = 0;
        islander->item_work.move_action20.timer = 0;
        islander->action_state = 3;
        return;
    }

    Islander_PlayAnim(0);
    islander->carry_wait_timer--;
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 2) {
            Islander_SpawnReactionEffect(4, 0x20);
            Sound_PlayEffect0(0x25);
        }
    }

    if (islander->carry_wait_timer & 0x8000) {
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        islander->carry_state = 1;
        islander->item_work.move_action20.phase = 0;
        islander->action_state = 1;
    }
}

void Islander_MoveAction20_State1(void) {
    Islander_AGB* islander = &gIslander;
    IslandBuilding* house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    Player* player = &gPlayer;
    s32 player_y;
    u16 phase;

    phase = (islander->item_work.move_action20.phase += 0x1111);
    if (phase == 0xFFFF) {
        islander->x = house->x << 8;
        player_y = house->y << 8;
        islander->y = player_y + 0x1000;
        player->y = player_y;
        player->x = islander->x + 0x1000;
        gGameState.bg1_hofs = (player->x >> 8) - 0x80;
        gGameState.bg1_vofs = (player->y >> 8) - 0x50;
        if (gGameState.bg1_vofs & 0x800) {
            gGameState.bg1_vofs = 0;
        }
        if (gGameState.bg1_vofs > 0x60) {
            gGameState.bg1_vofs = 0x60;
        }
        if (gGameState.bg1_hofs & 0x800) {
            gGameState.bg1_hofs = 0;
        }
        if (gGameState.bg1_hofs > 0x100) {
            gGameState.bg1_hofs = 0x100;
        }
        gGameState.bg2_hofs = gGameState.bg1_hofs;
        gGameState.bg2_vofs = gGameState.bg1_vofs;
        islander->action_state = 2;
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State2(void) {
    Islander_AGB* islander = &gIslander;
    IslandFieldWork* island_field = &gIslandFieldWork;
    u32 mosaic;

    mosaic = (islander->item_work.move_action20.phase -= 0x1111);
    if (mosaic == 0) {
        gGameState.bg1cnt ^= 0x40;
        gGameState.bg2cnt ^= 0x40;
        gGameState.bg3cnt ^= 0x40;
        islander->carry_state = 0;
        islander->target_x = mosaic;
        islander->target_y = mosaic;
        islander->tile_idx = island_field->special_tile_idx;
        islander->mood_level = 0;
        islander->target_action = 0x80;
        islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
        islander->emotion = ISLANDER_EMOTION_ANGRY;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State3(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->carry_state == 1) {
        islander->item_work.move_action20.timer = 0x10;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->action_state = 4;
    }
}
void Islander_MoveAction20_State4(void) {
    Islander_AGB* islander = &gIslander;
    s32 collision;
    s32 i;

    islander->item_work.move_action20.timer--;
    if ((islander->item_work.move_action20.timer & 0x8000) == 0) {
        return;
    }

    switch ((IslanderMoveAction20Phase)islander->item_work.move_action20.phase) {
    case ISLANDER_MOVE_ACTION20_PHASE_BEGIN:
        Islander_SpawnReactionEffect(1, 0x30);
        islander->anim_frame = 0;
        islander->anim_timer = 0;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x30;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_02:
        islander->anim_id = ISLANDER_ANIM_02;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_06:
        islander->anim_id = ISLANDER_ANIM_06;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_00:
        islander->anim_id = ISLANDER_ANIM_00;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x10;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_CHECK_POSITION:
        islander->work_x = islander->accepted_x - islander->x;
        islander->work_y = islander->accepted_y - islander->y;
        if (islander->work_x < 0) {
            islander->work_x = -islander->work_x;
        }
        if (islander->work_y < 0) {
            islander->work_y = -islander->work_y;
        }
        if (islander->work_x <= 0x2000 && islander->work_y <= 0x2000) {
            islander->item_work.move_action20.timer = 2;
            islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
            return;
        }

        Islander_UpdateCollisionTiles(islander->direction);
        for (i = 0; i < 4; i++) {
            collision = CheckSurroundingCollision(islander->surrounding_item_types[i], (u16*)islander->collision_tilemap);
            if (collision != 0) {
                islander->item_work.move_action20.timer = 2;
                islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
                return;
            }
        }

        islander->reaction_anim_id = ISLANDER_ANIM_59;
        if (islander->mood_level < 3) {
            islander->mood_level = 3;
            Islander_OnMoodChanged();
        }
        islander->target_action = collision;
        islander->carry_state = collision;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_RESTART:
        islander->accepted_x = islander->x;
        islander->accepted_y = islander->y;
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->action_state = 1;
        break;
    }
}

void Islander_MoveAction20_Move(void) {
    extern Islander_SUB_MOVE_PROC sIslanderMoveAction20SubMoveProcs[];

    Islander_AGB* islander = &gIslander; // I don't know why I have to pull this out to match, but I do
    sIslanderMoveAction20SubMoveProcs[(u8)islander->action_state]();
}

/* Original address: 0x02023B58 */
void Islander_Draw(void) {
    Islander_AGB* islander = &gIslander;
    IslanderOamData* source;
    s32 sprite_count;

    islander->work_y = islander->y >> 8;
    islander->work_x = islander->x >> 8;
    source = gIslanderAnimData[islander->anim_id][islander->anim_frame]->sprite_gfx_p;

    if (islander->anim_timer == 0xFE) {
        return;
    }

    sprite_count = 0;
    if (source->affine_param == 0xFFFF) {
        return;
    }

    do {
        IslanderOamData* oam = &((IslanderOamData*)gUnk3002410)[gGameState.oam_count];
        u32 x;
        u8 state;

        oam->y = source->y + islander->work_y - gGameState.bg2_vofs;
        oam->obj_mode = source->obj_mode;
        oam->bpp = source->bpp;
        oam->shape = source->shape;
        oam->h_flip = source->h_flip;
        oam->v_flip = source->v_flip;
        oam->size = source->size;
        oam->mosaic = TRUE;

        x = source->x;
        if (gIslanderAnimMirrorFlags[islander->anim_id] != FALSE) {
            oam->h_flip = source->h_flip ^ TRUE;
            x = ~x;
            x++;
            if (oam->shape == 0 && oam->size == 1) {
                x -= 16;
            } else {
                x -= 8;
            }
        }

        oam->x = x + islander->work_x - gGameState.bg2_hofs;
        oam->priority = 1;
        oam->palette_num = source->palette_num;
        oam->tile_num = source->tile_num;

        {
            u32 tile_override = islander->held_item_sprite;

            if ((tile_override & 0xFFFF0000) != 0 && (tile_override & 0xFFFF) != 0 &&
                oam->tile_num == ((tile_override >> 16) & 0xFFFF)) {
                tile_override &= 0xFFF;
                oam->tile_num = tile_override;
                oam->palette_num = (islander->held_item_sprite & 0xF000) >> 12;
            }
        }

        state = islander->equipped_tool_state & 0xF;
        if ((state == 6 || state == 8 || state == 5 || state == 7) && oam->palette_num == 2) {
            oam->palette_num = 8;
        }

        if ((u8)(islander->move_action - MoveAction3) <= 1) {
            if (islander->direction == 0) {
                if (source->tile_num == 0x40 || source->tile_num == 0x42) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->blink_frame == 0) {
                            oam->tile_num = 0x40;
                        } else {
                            oam->tile_num = 0x42;
                        }
                        break;
                    case 1:
                        oam->tile_num = 0x44;
                        break;
                    case 2:
                        oam->tile_num = 0x46;
                        break;
                    case 3:
                        oam->tile_num = 0x48;
                        break;
                    }
                }
            } else {
                if (((islander->direction >= 1 && islander->direction <= 2) || islander->direction == 6 || islander->direction == 7) &&
                    (source->tile_num == 0 || source->tile_num == 2)) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->blink_frame == 0) {
                            oam->tile_num = 0;
                        } else {
                            oam->tile_num = 2;
                        }
                        break;
                    case 1:
                        oam->tile_num = 4;
                        break;
                    case 2:
                        oam->tile_num = 6;
                        break;
                    case 3:
                        oam->tile_num = 8;
                        break;
                    }
                }
            }
        }

        gGameState.oam_count++;
        sprite_count++;
        source++;
        if (sprite_count > 0x21) {
            return;
        }
    } while (source->affine_param != 0xFFFF);
}

s32 Item_IsFossil(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item == ITM_FOSSIL) || ((mActor_name_t)(item - FTR_DINO_START) <= (FTR_DINO_END - FTR_DINO_START)) ||
        (item == RSV_ISLAND_FOSSIL)) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemIsGryoidOrUnk (differs; corrected typo and reserve-alias wording). */
s32 Item_IsGyroid(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)((item) - HANIWA_START)) <= ((HANIWA_END - HANIWA_START)) || item == RSV_ISLAND_HANIWA) {
        result = 1;
    }
    return result;
}

s32 Item_IsNES(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - FTR_FAMICOM_START) <= (FTR_FAMICOM_END - FTR_FAMICOM_START)) ||
        (item == RSV_ISLAND_FAMICOM)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFurniture(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item != ITM_FOSSIL) && ((mActor_name_t)(item - FTR_DINO_START) > (FTR_DINO_END - FTR_DINO_START)) && (item != RSV_ISLAND_FOSSIL) &&
        ((mActor_name_t)((item - HANIWA_START)) > ((HANIWA_END - HANIWA_START))) && (item != RSV_ISLAND_HANIWA) &&
        ((mActor_name_t)(item - FTR_FAMICOM_START) > (FTR_FAMICOM_END - FTR_FAMICOM_START)) && (item != RSV_ISLAND_FAMICOM) &&
        (ITEM_IS_FTR(item) || (item == RSV_ISLAND_FTR_COMMON) || (item == RSV_ISLAND_FTR_RARE) || (item == RSV_ISLAND_FTR_EVENT) || (item == RSV_ISLAND_FTR_ISLAND))) {
        result = 1;
    }
    return result;
}

s32 Item_IsApple(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_APPLE) {
        result = 1;
    }
    return result;
}

s32 Item_IsOrange(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_ORANGE) {
        result = 1;
    }
    return result;
}

s32 Item_IsPeach(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEACH) {
        result = 1;
    }
    return result;
}

s32 Item_IsPear(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEAR) {
        result = 1;
    }
    return result;
}

s32 Item_IsCherry(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CHERRY) {
        result = 1;
    }
    return result;
}

s32 Item_IsTurnip(mActor_name_t item) {
    s32 result;
    u32 shifted_item;

    shifted_item = item << 16;
    result = 0;
    if (((shifted_item & 0xF0000000) == (NAME_TYPE_ITEM1 << 28)) &&
        (((shifted_item >> 24) & 0xF) == ITEM1_CAT_KABU)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMushroom(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_MUSHROOM) {
        result = 1;
    }
    return result;
}

s32 Item_IsCandy(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CANDY) {
        result = 1;
    }
    return result;
}

s32 Item_Is100Bells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_100) {
        result = 1;
    }
    return result;
}

s32 Item_Is1KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_1000) {
        result = 1;
    }
    return result;
}

s32 Item_Is10KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_10000) {
        result = 1;
    }
    return result;
}

s32 Item_Is30KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_30000) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerBag(mActor_name_t item) {
    if (((mActor_name_t)(item - ITM_WHITE_PANSY_BAG) <= (ITM_YELLOW_TULIP_BAG - ITM_WHITE_PANSY_BAG)) ||
        (item == RSV_ISLAND_FLOWER_BAG)) {
        return 1;
    }
    return 0;
}

s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((Item_IsFlowerBag(item) == 0) && ITEM_NAME_CHK_TYPE(item, NAME_TYPE_ITEM1)) {
        if ((ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PAPER) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PLANT) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_TICKET) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_DUMMY) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_HUKUBUKURO)) {
            result = 1;
        }
    }
    return result;
}

s32 Item_IsNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsAxe(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_AXE) || (item_no == ITM_AXE_USE_7) || (item_no == ITM_AXE_USE_6) ||
        (item_no == ITM_AXE_USE_5) || (item_no == ITM_AXE_USE_4) || (item_no == ITM_AXE_USE_3) ||
        (item_no == ITM_AXE_USE_2) || (item_no == ITM_AXE_USE_1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenAxe(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_AXE) {
        result = 1;
    }
    return result;
}

s32 Item_IsShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsFishingRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsUmbrella(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_UMBRELLA_START) <= (ITM_UMBRELLA31 - ITM_UMBRELLA_START)) ||
        (item == RSV_ISLAND_UMBRELLA)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPaint(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_RED_PAINT) <= (ITM_BROWN_PAINT - ITM_RED_PAINT)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBalloon(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BALLOON_START) <= (ITM_BUNNY_O_BALLOON - ITM_BALLOON_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPinwheel(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_YELLOW_PINWHEEL) <= (ITM_FANCY_PINWHEEL - ITM_YELLOW_PINWHEEL)) {
        result = 1;
    }
    return result;
}

s32 Item_IsHandFan(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BLUEBELL_FAN) <= (ITM_LEAF_FAN - ITM_BLUEBELL_FAN)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSignboard(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SIGNBOARD) {
        result = 1;
    }
    return result;
}

s32 Item_IsShirt(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CLOTH)) ||
        (item_no == RSV_ISLAND_CLOTH_COMMON) || (item_no == RSV_ISLAND_CLOTH_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCarpet(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CARPET)) ||
        (item_no == RSV_ISLAND_CARPET_COMMON) || (item_no == RSV_ISLAND_CARPET_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsWallpaper(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_WALL)) ||
        (item_no == RSV_ISLAND_WALL_COMMON) || (item_no == RSV_ISLAND_WALL_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsAirCheck(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_MINIDISK)) ||
        (item_no == RSV_ISLAND_MINIDISK)) {
        result = 1;
    }
    return result;
}

s32 Item_IsTrash(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_DUST0_EMPTY_CAN) <= (ITM_DUST2_OLD_TIRE - ITM_DUST0_EMPTY_CAN)) ||
        (item == RSV_ISLAND_TRASH)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_PITFALL) {
        result = 1;
    }
    return result;
}

s32 Item_IsConchSeaShellIcon(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_SHELL1) <= (ITM_SHELL3 - ITM_SHELL1)) || (item == ITM_SHELL6)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLionsPawShellIcon(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_SHELL0) || (item_no == ITM_SHELL4) || (item_no == ITM_SHELL5)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoral(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHELL7) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerLeaves(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - FLOWER_LEAVES_PANSIES0) <= (FLOWER_LEAVES_TULIP2 - FLOWER_LEAVES_PANSIES0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurpleCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS1) {
        result = 1;
    }
    return result;
}

s32 Item_IsBlueCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS2) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS0) {
        result = 1;
    }
    return result;
}

s32 Item_IsRedTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP0) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhiteTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP2) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhitePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES0) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurplePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowPansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES2) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoconut(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_COCONUT) {
        result = 1;
    }
    return result;
}

s32 Item_IsCabana(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_MY) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslanderHouse(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_NPC) {
        result = 1;
    }
    return result;
}

s32 Item_IsSapling(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_SAPLING) || (item_no == TREE_APPLE_SAPLING) || (item_no == TREE_ORANGE_SAPLING) ||
        (item_no == TREE_PEACH_SAPLING) || (item_no == TREE_PEAR_SAPLING) || (item_no == TREE_CHERRY_SAPLING) ||
        (item_no == TREE_1000BELLS_SAPLING) || (item_no == TREE_10000BELLS_SAPLING) ||
        (item_no == TREE_30000BELLS_SAPLING) || (item_no == TREE_100BELLS_SAPLING)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S0) || (item_no == TREE_APPLE_S0) || (item_no == TREE_ORANGE_S0) ||
        (item_no == TREE_PEACH_S0) || (item_no == TREE_PEAR_S0) || (item_no == TREE_CHERRY_S0) ||
        (item_no == TREE_1000BELLS_S0) || (item_no == TREE_10000BELLS_S0) ||
        (item_no == TREE_30000BELLS_S0) || (item_no == TREE_100BELLS_S0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S1) || (item_no == TREE_APPLE_S1) || (item_no == TREE_ORANGE_S1) ||
        (item_no == TREE_PEACH_S1) || (item_no == TREE_PEAR_S1) || (item_no == TREE_CHERRY_S1) ||
        (item_no == TREE_1000BELLS_S1) || (item_no == TREE_10000BELLS_S1) ||
        (item_no == TREE_30000BELLS_S1) || (item_no == TREE_100BELLS_S1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S2) || (item_no == TREE_APPLE_S2) || (item_no == TREE_ORANGE_S2) ||
        (item_no == TREE_PEACH_S2) || (item_no == TREE_PEAR_S2) || (item_no == TREE_CHERRY_S2) ||
        (item_no == TREE_1000BELLS_S2) || (item_no == TREE_10000BELLS_S2) ||
        (item_no == TREE_30000BELLS_S2) || (item_no == TREE_100BELLS_S2)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    result = 0;
    item_no = item;
    if (((mActor_name_t)(item - TREE_BEES) <= (TREE_FTR - TREE_BEES)) || (item_no == TREE_BELLS) || (item_no == TREE) ||
        ((mActor_name_t)(item_no - TREE_APPLE_NOFRUIT_0) <= (TREE_APPLE_NOFRUIT_2 - TREE_APPLE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_ORANGE_NOFRUIT_0) <= (TREE_ORANGE_NOFRUIT_2 - TREE_ORANGE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEACH_NOFRUIT_0) <= (TREE_PEACH_NOFRUIT_2 - TREE_PEACH_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEAR_NOFRUIT_0) <= (TREE_PEAR_NOFRUIT_2 - TREE_PEAR_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_CHERRY_NOFRUIT_0) <= (TREE_CHERRY_NOFRUIT_2 - TREE_CHERRY_NOFRUIT_0)) ||
        (item_no == TREE_1000BELLS) || (item_no == TREE_10000BELLS) || (item_no == TREE_30000BELLS) ||
        (item_no == TREE_100BELLS)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitAppleTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_APPLE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitOrangeTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_ORANGE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPeachTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEACH_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsPearFruitTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEAR_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitCherryTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_CHERRY_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S0) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S1) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S2) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - TREE_PALM_NOFRUIT_0) <= (TREE_PALM_NOFRUIT_2 - TREE_PALM_NOFRUIT_0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslandFlag(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLAG) {
        result = 1;
    }
    return result;
}

s32 Item_IsHole(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - HOLE_START) <= (HOLE_END - HOLE_START)) || (item == RSV_ISLAND_HOLE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBuriedPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - BURIED_PITFALL_HOLE_START) <=
        (BURIED_PITFALL_HOLE_RSV_END - BURIED_PITFALL_HOLE_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == CEDAR_TREE_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_CEDAR_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsWeed(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - GRASS_A) <= (GRASS_C - GRASS_A)) {
        result = 1;
    }
    return result;
}

s32 Item_IsRock(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ROCK_A) <= (ROCK_E - ROCK_A)) ||
        ((mActor_name_t)(item - MONEY_ROCK_A) <= (MONEY_ROCK_E - MONEY_ROCK_A))) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemCheckFunc (differs; this specifically tests reserved item 0xFFFF). */
s32 Item_IsReserved(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == RSV_NO) {
        result = 1;
    }
    return result;
}


typedef int (*Item_CHK_PROC)(mActor_name_t);

typedef struct item_type_entry_s {
    Item_CHK_PROC chk_proc;
    mActor_name_t item;
} Item_TypeEntry_c;

extern ItemGroupStruct g_ItemDefinitions[ITEM_TYPE_COUNT];

extern Item_TypeEntry_c Item_TypeEntries[ITEM_TYPE_COUNT];

/* Ghidra name: Item_GetTileId (differs; this returns the matching predicate-table index). */
s32 Item_GetTypeIndex(mActor_name_t item) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(Item_TypeEntries); i++) {
        if (Item_TypeEntries[i].chk_proc(item) != 0) {
            return i;
        }
    }
    return -1;
}

mActor_name_t Item_GetItemFromTypeIndex(s32 idx) {
    if (idx < ARRAY_COUNT(Item_TypeEntries)) {
        return Item_TypeEntries[idx].item;
    }
    return EMPTY_NO;
}

extern mActor_name_t gc_rsv_island_item_table[18];

mActor_name_t Item_TypeToIslandItem(s32 idx) {
    if (idx < ARRAY_COUNT(gc_rsv_island_item_table)) {
        return gc_rsv_island_item_table[idx];
    }
    return EMPTY_NO;
}

/* Original address: 0x02024B08 */
void FallingFruit_Init(s32 object_index, u16 fruit_index, u8 type, u8 acre) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    FallingFruitProfile *profile;
    FieldObject *object;

    fruit->type = type;
    fruit->acre = acre;
    fruit->sound_played = 0;
    fruit->landing_x = 0;
    fruit->origin_y = 0;
    fruit->landing_y = 0;
    fruit->tile_idx = 0;
    fruit->can_land = 0;
    profile = &sFallingFruitProfiles[fruit->type];
    object = &gFieldObjects[object_index];
    fruit->state = 1;
    switch (fruit->type) {
    case 1: case 2:
    case 4: case 5: case 6:
    case 8: case 9: case 10:
    case 12: case 13: case 14:
    case 16: case 17: case 18:
    case 20: case 21: case 22:
        fruit->state = 2;
        /* fallthrough */
    case 0: case 3: case 7: case 11: case 15: case 19:
        fruit->y = object->y + profile->y_offset;
        fruit->origin_y = fruit->y;
        fruit->x = object->x + profile->x_offset;
        fruit->anim_frame = profile->h_flip;
        break;
    }
}

void sub_02024C00(void) {

}

void sub_02024C04(void) {

}

/* Original address: 0x02024C08 */
void FallingFruit_BeginFall(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];

    rand_u16(&gGameState);
    fruit->height = 0;
    fruit->velocity_y = 0x200;
    fruit->gravity = 0x20;
    fruit->timer = 16;
    fruit->state = 3;
}

/* Original address: 0x02024C44 */
void FallingFruit_UpdateFall(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    IslandFieldWork *field = &gIslandFieldWork;

    fruit->timer--;
    fruit->x += (fruit->landing_x - fruit->x) >> 1;
    fruit->y = fruit->origin_y - (fruit->height >> 8);
    fruit->height += fruit->velocity_y;
    fruit->velocity_y -= fruit->gravity;
    if (fruit->timer == 12 && fruit->sound_played == 0) {
        Sound_PlayEffect0(0x17);
        fruit->sound_played = 1;
    }
    if ((fruit->timer & 0x80) && fruit->landing_y < fruit->y) {
        if (fruit->can_land == 1) {
            FallingFruitProfile *profile = &sFallingFruitProfiles[fruit->type];
            s32 row_offset;
            u16 tile_offset;
            row_offset = 0;
            tile_offset = 0;
            do {
                u16 *tilemap;
                if (fruit->acre == 0) {
                    tilemap = (u16 *)((0xFF0 & fruit->tile_idx) * 8 + BG_SCREEN_ADDR(24) + row_offset +
                                     (0xF & fruit->tile_idx) * 4);
                } else {
                    tilemap = (u16 *)((0xFF0 & fruit->tile_idx) * 8 + BG_SCREEN_ADDR(25) + row_offset +
                                     (0xF & fruit->tile_idx) * 4);
                }
                tilemap[0] = tile_offset + profile->ground_tile;
                tilemap[1] = tile_offset + profile->ground_tile + 1;
                row_offset += 64;
                tile_offset = 2;
            } while (row_offset < 80);
            if (fruit->acre == 0) {
                gIslandData->fgblock[0][0].items[(fruit->tile_idx >> 4) & 0xF][fruit->tile_idx & 0xF] = profile->item;
                field->fg_tiles[0][fruit->tile_idx] = profile->field_tile;
            } else {
                gIslandData->fgblock[0][1].items[(fruit->tile_idx >> 4) & 0xF][fruit->tile_idx & 0xF] = profile->item;
                field->fg_tiles[1][fruit->tile_idx] = profile->field_tile;
            }
        }
        fruit->state = 0;
        field->entity_active[fruit_index + 21] = 0;
    }
}

/* Original address: 0x02024DD0 */
void FallingFruit_Update(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    sFallingFruitUpdateProcs[fruit->state](fruit_index);
}

/* Original address: 0x02024DF8 */
void FallingFruit_Draw(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    FallingFruitProfile *profile = &sFallingFruitProfiles[fruit->type];
    GameState *game = &gGameState;
    IslanderOamData *oam = &((IslanderOamData *)gUnk3002410)[game->oam_count];

    oam->shape = (profile->oam_attributes >> 14) & 3;
    oam->size = profile->oam_attributes >> 30;
    oam->tile_num = profile->sprite_tile;
    oam->mosaic = 1;
    oam->h_flip = fruit->anim_frame;
    oam->priority = 1;
    oam->palette_num = profile->palette;
    oam->x = fruit->x - game->bg2_hofs;
    oam->y = fruit->y - (u8)game->bg2_vofs;
    game->oam_count++;
}

/* Original address: 0x02024F08 */
void Entity_Reset(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    s32 i;

    entity->x = 0;
    entity->y = 0;
    entity->height_offset = 0;
    entity->precise_x = 0;
    entity->base_y = 0;
    entity->vertical_velocity_or_x_limit = 0;
    entity->horizontal_velocity = 0;
    entity->reserved_1C = 0;
    entity->vertical_acceleration_or_bob_velocity = 0;
    entity->depth_offset = 0;
    entity->anim_timer = 0;
    entity->frame_index = 0;
    entity->update_type = 0;
    entity->anim_id = 0;
    entity->lifetime = 10;
    entity->sprite_tile = 0;
    entity->palette = 0;
    entity->reaction_type = 0;
    entity->h_flip = 0;
    entity->affine_scale = 0;
    entity->rotation = 0;
    for (i = 0; i < 5; i++) {
        entity->item_type_indices[i] = 0;
        entity->item_ids[i] = 0;
    }
    entity->landing_delay_timer = 0;
    entity->bob_phase = 0;
    entity->reserved_48 = 0;
    entity->landing_tile = 0;
}

/* Original address: 0x02024F8C */
void Entity_PlaceLandedItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item = entity->item_ids[0];
    u8 tile_idx;
    u16 *tilemap;
    ItemGroupStruct *definition;

    if (entity->items_are_resolved == 0) {
        ItemGeneratorDef *generator = &gItemGeneratorDefs[item];
        if (generator->use_island_id == 0) {
            item = generator->item;
        } else {
            item = Item_TypeToIslandItem(generator->item);
        }
    }
    tile_idx = entity->landing_tile;
    if (!(entity->landing_tile & 0x1000)) {
        field->fg_tiles[0][tile_idx] = entity->item_type_indices[0] | 0x8000;
        tilemap = (u16 *)BG_SCREEN_ADDR(24);
        tilemap += (tile_idx & 0xF0) * 4;
        tilemap += (tile_idx & 0xF) * 2;
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
    } else {
        field->fg_tiles[1][tile_idx] = entity->item_type_indices[0] | 0x8000;
        tilemap = (u16 *)BG_SCREEN_ADDR(25);
        tilemap += (tile_idx & 0xF0) * 4;
        tilemap += (tile_idx & 0xF) * 2;
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
    }
    definition = &g_ItemDefinitions[entity->item_type_indices[0]];
    *tilemap++ = definition->field_tile_id;
    *tilemap = definition->field_tile_id + 1;
    tilemap += 31;
    tilemap[0] = definition->field_tile_id + 2;
    tilemap[1] = definition->field_tile_id + 3;
    field->entity_active[entity_index + 3] = 0;
}

/* Original address: 0x020250B0 */
void Entity_UpdateLifetime(s32 entity_index) {
    IslandFieldWork *field = &gIslandFieldWork;
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->lifetime == 0) {
        field->entity_active[entity_index + 3] = 0;
    } else {
        entity->lifetime--;
    }
}

/* Original address: 0x020250EC */
void Entity_BeginToppleEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityToppleFrames[0]->duration;
    entity->anim_id = 1;
    entity->update_type = 2;
}

/* Original address: 0x02025118 */
void Entity_UpdateToppleEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        if ((entity->frame_index & 7) == 0) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = sEntityToppleFrames[entity->frame_index]->duration;
    }
}

/* Original address: 0x02025180 */
void Entity_BeginLeafEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityLeafFrames[0]->duration;
    entity->anim_id = 2;
    entity->update_type = 4;
}

/* Original address: 0x020251AC */
void Entity_UpdateLeafEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        if (entity->frame_index > 19) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = sEntityLeafFrames[entity->frame_index]->duration;
    }
}

/* Original address: 0x02025210 */
void Entity_BeginReactionEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    AnimFrameData *frame = sEntityReactionAnimations[entity->reaction_type][0];

    switch (entity->reaction_type) {
    case 0:
        Sound_PlayEffect0(5);
        break;
    case 1:
        Sound_PlayEffect0(6);
        break;
    case 2:
        Sound_PlayEffect0(7);
        break;
    case 3:
        Sound_PlayEffect0(8);
        break;
    case 4:
        break;
    }
    entity->anim_timer = frame->duration;
    entity->frame_index = 0;
    entity->anim_id = 3;
    entity->update_type = 6;
}

/* Original address: 0x0202529C */
void Entity_UpdateReactionEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;
    AnimFrameData *frame;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        frame = sEntityReactionAnimations[entity->reaction_type][entity->frame_index];
        if ((u8)frame->action_flag == 0xFF) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = frame->duration;
    }
}

/* Original address: 0x02025310 */
void Entity_BeginItemDrop(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->precise_x = entity->x << 8;
    entity->base_y = entity->y << 8;
    entity->height_offset = 0;
    entity->vertical_velocity_or_x_limit = 0x200;
    entity->vertical_acceleration_or_bob_velocity = 0x20;
    Sound_PlayEffect0(30);
    entity->anim_id = 0;
    entity->update_type = 8;
}

/* Original address: 0x02025354 */
void Entity_UpdateItemDrop(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    s32 landing_y;

    entity->x = entity->precise_x >> 8;
    landing_y = entity->base_y >> 8;
    entity->y = landing_y - (entity->height_offset >> 8);
    entity->height_offset += entity->vertical_velocity_or_x_limit;
    entity->vertical_velocity_or_x_limit -= entity->vertical_acceleration_or_bob_velocity;
    if (entity->landing_delay_timer == 0) {
        if (entity->y > landing_y + 8) {
            Entity_PlaceLandedItem(entity_index);
        }
    } else {
        entity->landing_delay_timer--;
    }
}

/* Original address: 0x020253A8 */
void Entity_BeginFloatingItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->precise_x = entity->x << 8;
    entity->base_y = entity->y << 8;
    entity->height_offset = 0;
    entity->vertical_acceleration_or_bob_velocity = 0x20;
    entity->depth_offset = 0;
    entity->anim_timer = 16;
    entity->frame_index = 0;
    entity->affine_scale = 0x300;
    entity->bob_phase = 0;
    entity->reserved_48 = 0;
    entity->anim_id = 0;
    entity->update_type = 10;
}

/* Original address: 0x02025400 */
void Entity_UpdateFloatingItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 offscreen = 0;
    ItemGroupStruct *definition;
    s32 wave;

    entity->precise_x += entity->horizontal_velocity;
    entity->x = entity->precise_x >> 8;
    entity->y = (entity->base_y >> 8) - entity->depth_offset + (entity->height_offset >> 8);
    islander->flying_item_x = entity->precise_x;
    islander->flying_item_y = entity->base_y;
    entity->height_offset += entity->vertical_acceleration_or_bob_velocity;
    if (entity->horizontal_velocity >= 0) {
        if (entity->x > entity->vertical_velocity_or_x_limit) {
            offscreen = 1;
        }
    } else if (entity->x < entity->vertical_velocity_or_x_limit) {
        offscreen = 1;
    }
    if (islander->stored_item_type_plus_one[4] != 0 || offscreen != 0) {
        entity->rotation -= 0x700;
        entity->affine_scale += 0x10;
        if (entity->depth_offset > 0 && !(entity->affine_scale & 0x10)) {
            entity->depth_offset--;
        }
        if (entity->affine_scale <= 0x300) {
            return;
        }
        entity->affine_scale = 0x300;
        entity->rotation = 0;
        islander->flying_item_spawn_timer = 10800;
        islander->flying_item_spawn_timer += (rand_u16(&gGameState) % 109) * 100;
        islander->flying_item_x = 0;
        islander->flying_item_y = 0;
        field->entity_active[entity_index + 3] = 0;
        return;
    }
    if (entity->depth_offset < 24) {
        entity->depth_offset++;
    }
    entity->rotation += 0x700;
    entity->affine_scale -= 0x10;
    if (entity->affine_scale < 0x100) {
        entity->affine_scale = 0x100;
        entity->rotation = 0;
        if (entity->anim_timer == 0) {
            entity->anim_timer = 16;
            entity->frame_index++;
            if (entity->frame_index > 4) {
                entity->frame_index = 0;
            }
            if (entity->item_ids[entity->frame_index] == 0 &&
                entity->item_type_indices[entity->frame_index] == 0) {
                entity->frame_index = 0;
            }
            definition = &g_ItemDefinitions[entity->item_type_indices[entity->frame_index]];
            entity->sprite_tile = definition->held_item_oam_attr2 & 0x3FF;
            entity->palette = definition->held_item_oam_attr2 >> 12;
        }
        entity->anim_timer--;
    }
    wave = sSineTable[entity->bob_phase];
    entity->vertical_acceleration_or_bob_velocity = wave >> 2;
    if (wave & 0x8000) {
        entity->vertical_acceleration_or_bob_velocity |= 0xFFFF0000;
    }
    entity->bob_phase = (entity->bob_phase + 4) & 0xFF;
    if (entity->bob_phase == 0) {
        entity->vertical_acceleration_or_bob_velocity = 0;
    }
}

/* Original address: 0x020255F0 */
void Entity_Update(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    sEntityUpdateProcs[entity->update_type](entity_index);
}

/* Original address: 0x02025618 */
void Entity_DrawFloatingItemShadow(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->update_type == 10) {
        GameState *game = &gGameState;
        IslanderOamData *oam = &((IslanderOamData *)gUnk3002410)[game->oam_count];
        s32 camera_x;

        oam->y = (entity->base_y >> 8) + (entity->height_offset >> 8) - (u8)game->bg2_vofs;
        camera_x = game->bg2_hofs - 8;
        oam->x = entity->x - camera_x;
        oam->shape = 0;
        oam->size = 0;
        oam->tile_num = 0x200;
        oam->palette_num = 1;
        oam->priority = 1;
        game->oam_count++;
    }
}

/* Original address: 0x020256D0 */
void Entity_DrawSprite(s32 entity_index) {
    /* The BIOS reads the affine source as words. */
    struct ObjAffineSrcData transform __attribute__((aligned(4)));
    struct { s16 pa, pb, pc, pd; } matrix;
    Entity *entity = &g_EntityTable[entity_index];
    AnimFrameData *frame = NULL;
    IslanderOamData *sprite;
    IslanderOamData *oam;
    s32 i;

    switch (entity->anim_id) {
    case 1:
        frame = sEntityToppleFrames[entity->frame_index];
        break;
    case 2:
        frame = sEntityLeafFrames[entity->frame_index];
        break;
    case 3:
        frame = sEntityReactionAnimations[entity->reaction_type][entity->frame_index];
        break;
    }
    if (entity->anim_id != 0) {
        sprite = frame->sprite_gfx_p;
        for (i = 0; i < 12 && sprite->affine_param != 0xFFFF; i++, sprite++) {
            oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];
            oam->y = sprite->y + entity->y - (u8)gGameState.bg2_vofs;
            oam->obj_mode = sprite->obj_mode;
            oam->bpp = sprite->bpp;
            oam->shape = sprite->shape;
            oam->x = sprite->x + entity->x - gGameState.bg2_hofs;
            oam->h_flip = entity->h_flip;
            oam->v_flip = sprite->v_flip;
            oam->size = sprite->size;
            oam->tile_num = sprite->tile_num;
            oam->priority = 1;
            if (entity->update_type == 6) {
                oam->priority = 0;
            }
            oam->palette_num = sprite->palette_num;
            oam->mosaic = 1;
            gGameState.oam_count++;
        }
    } else {
        oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];
        oam->y = entity->y - (u8)gGameState.bg2_vofs;
        oam->x = entity->x - gGameState.bg2_hofs;
        oam->shape = 0;
        oam->size = 1;
        oam->tile_num = entity->sprite_tile;
        oam->palette_num = entity->palette;
        oam->mosaic = 1;
        oam->priority = 1;
        gGameState.oam_count++;
        if (entity->update_type == 10) {
            oam->affine_mode = 1;
            oam->matrix_num = 1;
            oam->obj_mode = 0;
            transform.xScale = entity->affine_scale;
            transform.yScale = entity->affine_scale;
            transform.rotation = entity->rotation;
            ObjAffineSet(&transform, &matrix, 1, 2);
            ((IslanderOamData *)gUnk3002410)[4].affine_param = matrix.pa;
            ((IslanderOamData *)gUnk3002410)[5].affine_param = matrix.pb;
            ((IslanderOamData *)gUnk3002410)[6].affine_param = matrix.pc;
            ((IslanderOamData *)gUnk3002410)[7].affine_param = matrix.pd;
        }
    }
}

/* Original address: 0x020259C8 */
s32 PlayerHand_IsItemPlacementBlocked(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 *tilemap = NULL;
    u16 item = 0;
    u16 terrain;

    player->tile_idx = (player->work_y & ~0xF) | ((player->work_x & 0xF0) >> 4);
    if (!(player->work_x & 0xFF00)) {
        if (field->fg_tiles[0][player->tile_idx] != 0xFFF &&
            field->fg_tiles[0][player->tile_idx] != 0x7777) {
            return 1;
        }
        if (islander->dig_target_layer == 0 && player->tile_idx == islander->dig_target_tile_idx) {
            return 1;
        }
        if (field->fg_tiles[0][player->tile_idx] == 0xFFF ||
            (player->held_item_layer == 0 && player->tile_idx == player->held_item_tile_idx)) {
            field->fg_tiles[0][player->tile_idx] = 0xFFF;
            item = field->fg_tiles[0][player->tile_idx];
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
            tilemap += (player->tile_idx & 0xF0) * 4;
            tilemap += (player->tile_idx & 0xF) * 2;
        }
    } else {
        if (field->fg_tiles[1][player->tile_idx] != 0xFFF &&
            field->fg_tiles[1][player->tile_idx] != 0x7777) {
            return 1;
        }
        if (islander->dig_target_layer != 0 && player->tile_idx == islander->dig_target_tile_idx) {
            return 1;
        }
        if (field->fg_tiles[1][player->tile_idx] == 0xFFF ||
            (player->held_item_layer != 0 && player->tile_idx == player->held_item_tile_idx)) {
            field->fg_tiles[1][player->tile_idx] = 0xFFF;
            item = field->fg_tiles[1][player->tile_idx];
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
            tilemap += (player->tile_idx & 0xF0) * 4;
            tilemap += (player->tile_idx & 0xF) * 2;
        }
    }
    if (CheckSurroundingCollision(item, tilemap) == 0) {
        terrain = Islander_GetTerrainTile(tilemap);
        if ((terrain > 5 && (u16)(terrain - 0x10) > 5 && terrain != 0x82 && terrain <= 0xAF) ||
            (*tilemap & 0x3FF) == 0x13) {
            IslandBuilding *building = &gIslandBuildings[1];
            s32 cursor_x = (player->x >> 8) - 8;
            player->work_x = building->interaction_x - cursor_x;
            player->work_y = building->interaction_y - (player->y >> 8);
            if (player->work_x < 0) {
                player->work_x = -player->work_x;
            }
            if (player->work_y < 0) {
                player->work_y = -player->work_y;
            }
            if (player->work_x > 0x20 || player->work_y > 0x20) {
                return 0;
            }
        }
    } else {
        terrain = Islander_GetTerrainTile(tilemap);
        if ((u16)(terrain - 0xBC) <= 3 || (u16)(terrain - 0xC6) <= 5) {
            return 0;
        }
    }
    return 1;
}

/* Original address: 0x02025B94 */
s32 PlayerHand_IsNearInteractionTarget(s32 x, s32 y, u16 range) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    s32 dx = player->x - islander->x;
    s32 dy;

    if (dx < 0) {
        dx = -dx;
    }
    if (dx <= 0x2FFF) {
        dx = player->x - x;
        dy = player->y - y;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        dx >>= 8;
        dy >>= 8;
        if (dx <= range && dy <= range) {
            return 1;
        }
    }
    return 0;
}

/* Original address: 0x02025BEC */
s32 PlayerHand_CheckHouseDoorInteraction(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandBuilding *building = &gIslandBuildings[1];

    player->near_house_door = 0;
    if (PlayerHand_IsNearInteractionTarget(building->interaction_x << 8, building->interaction_y << 8, 0x10U) != 0) {
        player->near_house_door = 1;
    }
    if (islander->move_action == 1) {
        if ((player->near_house_door != 0) && (islander->anim_timer == 0xFE)) {
            islander->anim_timer = 4;
            building->state = 0;
            player->near_house_door = 0;
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x02025C4C */
s32 PlayerHand_TryInteractWithIslander(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;

    if (islander->collision_bypass_timer == 0 && islander->move_action == 3) {
        islander->target_x = player->x;
        islander->target_y = player->y;
    }
    if (islander->move_action == 3) {
        if (PlayerHand_IsNearInteractionTarget(islander->x, islander->y, 8)) {
            islander->reaction_anim_id = 1;
            Islander_SpawnReactionEffect(2, 0x30);
            if (islander->equipped_tool_state != 0) {
                islander->equipped_tool_state |= 0x40;
                islander->reaction_anim_id = 0;
            }
            player->near_house_door = 0;
            islander->move_action = 10;
            islander->click_cooldown_timer = 0x30;
            player->action_state = 0;
            PlayerHand_ResetToIdle();
            return 1;
        }
    } else if (islander->move_action == 20 && islander->action_state == 0 &&
               PlayerHand_IsNearInteractionTarget(islander->x, islander->y, 16)) {
        Sound_PlayEffect0(3);
        islander->carry_state = 2;
        player->action_state = 2;
        PlayerHand_BeginCarrying();
        return 1;
    }
    return 0;
}

/* Original address: 0x02025D1C */
s32 PlayerHand_TrySelectIslanderTarget(void) {
    u8 temp_r0_29010;

    if ((gIslander.move_action == 3) && ((temp_r0_29010 = gIslander.equipped_tool_state, (temp_r0_29010 == 1)) || (temp_r0_29010 == 5)) && (PlayerHand_IsNearInteractionTarget(gIslander.flying_item_x, gIslander.flying_item_y, 0x10U) != 0)) {
        gIslander.move_action = 9;
        gIslander.target_x = (s32) gIslander.flying_item_x;
        gIslander.target_y = (s32) gIslander.flying_item_y;
        gIslander.reaction_anim_id = 0;
        gIslander.interaction_target_is_islander = 1;
        return 1;
    }
    return 0;
}

/* Original address: 0x02025D70 */
void PlayerHand_Init(void) {
    Player *player = &gPlayer;

    player->x = 0xF800;
    player->y = 0x8800;
    player->saved_x = 0xF800;
    player->saved_y = 0x8800;
    player->anim_frame = 0;
    player->anim_timer = 0;
    player->anim_id = 0;
    player->interaction_attempt_active = 0;
    player->held_item_oam_attr2 = 0;
    player->tile_idx = 0;
    player->held_item = 0;
    player->held_item_type_idx = 0;
    player->placement_input_delay = 0;
    player->near_house_door = 0;
    player->interaction_cooldown_timer = 0;
    player->work_y = 0;
    player->work_x = 0;
    player->held_item_layer = 0;
    player->held_item_tile_idx = 0;
    player->left_neighbor_tile_idx = 0;
    player->right_neighbor_tile_idx = 0;
    player->action_state = 0;
}

static inline void PlayerHand_UpdateCamera(Player *player) {
    GameState *camera = &gGameState;
    s32 camera_y;
    camera->bg1_hofs = ((s32) player->x >> 8) - 0x80;
    camera_y = ((s32) player->y >> 8) - 0x50;
    camera->bg1_vofs = camera_y;
    if (camera_y & 0x800) {
        camera->bg1_vofs = 0;
    }
    if ((u32) camera->bg1_vofs > 0x60U) {
        camera->bg1_vofs = 0x60;
    }
    if (0x800 & camera->bg1_hofs) {
        camera->bg1_hofs = 0;
    }
    if ((u32) camera->bg1_hofs > 0x100U) {
        camera->bg1_hofs = 0x100;
    }
    camera->bg2_hofs = camera->bg1_hofs;
    camera->bg2_vofs = camera->bg1_vofs;
}

/* Original address: 0x02025DC8 */
void PlayerHand_UpdateMovement(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    GameState *game = &gGameState;

    s32 previous_y;
    s32 previous_y_down;
    s32 previous_x;
    s32 previous_x_right;

    if (0x400040 & game->keys.combined) {
        previous_y = player->y;
        player->y = previous_y - 0x180;
        if (0x100 & game->keys.buttons.held) {
            player->y = previous_y - 0x300;
        }
        if (player->y <= 0xE00) {
            player->y = 0xE00;
        }
    } else if (game->keys.combined & 0x800080) {
        previous_y_down = player->y;
        player->y = previous_y_down + 0x180;
        if (0x100 & game->keys.buttons.held) {
            player->y = previous_y_down + 0x300;
        }
        if (islander->carry_state == 0) {
            if (player->y > 0xF7FF) {
                player->y = 0xF800;
            }
        } else {
            if (player->y > 0xE7FF) {
                player->y = 0xE800;
            }
        }
    }
    if (0x200020 & gGameState.keys.combined) {
        previous_x = player->x;
        player->x = previous_x - 0x180;
        if (0x100 & gGameState.keys.buttons.held) {
            player->x = previous_x - 0x300;
        }
        if (player->x <= 0x600) {
            player->x = 0x600;
        }
    } else if (gGameState.keys.combined & 0x100010) {
        previous_x_right = player->x;
        player->x = previous_x_right + 0x180;
        if (0x100 & gGameState.keys.buttons.held) {
            player->x = previous_x_right + 0x300;
        }
        if (player->x > 0x1DFFF) {
            player->x = 0x1E000;
        }
    }
    PlayerHand_UpdateCamera(player);
}

/* Original address: 0x02025F60 */
void PlayerHand_ResetToIdle(void) {
    Player *player = &gPlayer;
    AnimFrameData *frame;

    player->anim_id = 0;
    frame = sPlayerHandAnimations[0][0];
    player->interaction_attempt_active = 0;
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    player->action_state = 1;
}

static inline s32 PlayerHand_IsTileBuried(Player *player) {
    if (!(player->work_x & 0xFF00)) {
        if ((gIslandData->deposit[0][player->tile_idx >> 4] >> (player->tile_idx & 0xF)) & 1) {
            return 1;
        }
    } else {
        if ((gIslandData->deposit[1][player->tile_idx >> 4] >> (player->tile_idx & 0xF)) & 1) {
            return 1;
        }
    }
    return 0;
}

/* Original address: 0x02025F90 */
void PlayerHand_UpdateIdle(void) {
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item_type;
    ItemGroupStruct *definition;
    ItemGroupStruct *definitions;
    Island_agb_c *island;
    s32 column, row;
    mActor_name_t item;
    mActor_name_t *tile;
    AnimFrameData *frame;

    if ((player->interaction_cooldown_timer == 0 || --player->interaction_cooldown_timer == 0) && (gGameState.keys.buttons.pressed & 1)) {
        player->work_y = (player->y >> 8) & 0xFF0;
        player->work_x = (player->x >> 8) & 0xFF0;
        player->tile_idx = player->work_y | ((player->work_x & 0xF0) >> 4);
        if (!(player->work_x & 0xFF00)) {
            item_type = field->fg_tiles[0][player->tile_idx];
        } else {
            item_type = field->fg_tiles[1][player->tile_idx];
        }
        definitions = g_ItemDefinitions;
        definition = &definitions[item_type];
        if (item_type == 0xFFF || item_type == 0x7777 || item_type == 0x3333 ||
            definition->interaction_type == 0xFFF) {
            player->interaction_attempt_active = 1;
        } else {
            if (PlayerHand_IsTileBuried(player)) {
                player->interaction_attempt_active = 1;
            } else {
                item_type &= 0xFFF;
                definition = &definitions[item_type];
                if (definition->held_item_oam_attr2 != 0xFFF) {
                    if (!((player->x >> 8) & 0xFF00)) {
                        field->fg_tiles[0][player->tile_idx] = 0x7777;
                        island = gIslandData;
                        column = player->tile_idx & 0xF;
                        row = player->tile_idx >> 4;
                        tile = &island->fgblock[0][0].items[row][column];
                        item = *tile;
                        *tile = 0;
                        player->held_item_layer = 0;
                    } else {
                        field->fg_tiles[1][player->tile_idx] = 0x7777;
                        island = gIslandData;
                        column = player->tile_idx & 0xF;
                        row = player->tile_idx >> 4;
                        tile = &island->fgblock[0][1].items[row][column];
                        item = *tile;
                        *tile = 0;
                        player->held_item_layer = 1;
                    }
                    player->held_item_tile_idx = player->tile_idx;
                    player->held_item_type_idx = item_type;
                    player->held_item_oam_attr2 = definition->held_item_oam_attr2;
                    player->held_item = item;
                    Sound_PlayEffect0(3);
                    player->action_state = 2;
                    PlayerHand_BeginCarrying();
                    return;
                }
                player->interaction_attempt_active = 1;
            }
        }
    }
    if (player->interaction_attempt_active == 0) {
        PlayerHand_UpdateMovement();
    } else if (player->anim_timer == 0) {
        player->anim_timer--;
    } else {
        player->anim_frame++;
        frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
        if ((u8)frame->action_flag != 0xFF) {
            player->anim_timer = frame->duration;
        } else if (PlayerHand_CheckHouseDoorInteraction() != 0) {
            Sound_PlayEffect0(2);
            player->action_state = 0;
            PlayerHand_ResetToIdle();
        } else if (PlayerHand_TryInteractWithIslander() == 0) {
            if (PlayerHand_TrySelectIslanderTarget() != 0) {
                player->action_state = 0;
                PlayerHand_ResetToIdle();
            } else {
                Sound_PlayEffect0(2);
                player->action_state = 0;
                PlayerHand_ResetToIdle();
            }
        }
    }
}

/* Original address: 0x0202622C */
void Field_RestoreNeighborTreeTile(u16 tile_idx, s32 x, u8 neighbor_tile, u8 acre, u8 right_side) {
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item_type;
    u16 *tilemap;

    if (acre == 0) {
        item_type = field->fg_tiles[0][neighbor_tile];
    } else {
        item_type = field->fg_tiles[1][neighbor_tile];
    }
    if (!(x & 0xFF0000)) {
        tilemap = (u16*)BG_SCREEN_ADDR(24);
    } else {
        tilemap = (u16*)BG_SCREEN_ADDR(25);
    }
    tilemap += (tile_idx & 0xF0) * 4;
    tilemap += (tile_idx & 0xF) * 2;
    if (item_type == ITEM_TYPE_LARGE_TREE || item_type == ITEM_TYPE_LARGE_STUMP) {
        if (right_side == 0) {
            tilemap += 0x20;
            *tilemap = 0x328F;
        } else {
            tilemap += 0x21;
            *tilemap = 0x328C;
        }
    }
    if (item_type == ITEM_TYPE_FULLY_GROWN_TREE ||
        (u16)(item_type - ITEM_TYPE_FRUIT_APPLE_TREE) <= ITEM_TYPE_FRUIT_CHERRY_TREE - ITEM_TYPE_FRUIT_APPLE_TREE ||
        item_type == ITEM_TYPE_FULLY_GROWN_STUMP) {
        if (right_side == 0) {
            tilemap += 0x20;
            *tilemap = 0x3297;
        } else {
            tilemap += 0x21;
            *tilemap = 0x3294;
        }
    }
}

/* Original address: 0x020262DC */
void Field_RestoreAdjacentTreeTiles(u16 tile_idx, s32 x) {
    Player *player = &gPlayer;
    u8 left = (tile_idx & 0xF) - 1;
    u8 right = (tile_idx & 0xF) + 1;
    u8 row = tile_idx & 0xF0;
    left &= 0xF;
    right &= 0xF;
    player->left_neighbor_tile_idx = left | row;
    player->right_neighbor_tile_idx = right | row;
    if (!(player->x & 0xFF0000)) {
        Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 0, 0);
        if (!(player->right_neighbor_tile_idx & 0xF)) {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 1, 1);
        } else {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 0, 1);
        }
    } else {
        Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 1, 1);
        if ((player->left_neighbor_tile_idx & 0xF) == 0xF) {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 0, 0);
        } else {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 1, 0);
        }
    }
}

/* Original address: 0x020263A0 */
void PlayerHand_BeginCarrying(void) {
    Player *player = &gPlayer;
    Entity *entity = &g_EntityTable[2];
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    AnimFrameData *frame;

    player->anim_id = 1;
    frame = sPlayerHandAnimations[1][0];
    player->interaction_attempt_active = 0;
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    if (islander->carry_state == 0) {
        field->entity_active[2] = 1;
        Entity_Reset(2);
        entity->lifetime = 0x30;
        entity->x = (player->x >> 8) - 8;
        entity->y = (player->y >> 8) - 2;
        entity->sprite_tile = player->held_item_oam_attr2 & 0x3FF;
        entity->palette = player->held_item_oam_attr2 >> 12;
        entity->anim_id = 0;
        WriteItemToTile(player->x, player->tile_idx, 0, 0x200);
        Field_RestoreAdjacentTreeTiles(player->tile_idx, player->x);
    } else {
        islander->x = player->x;
        islander->y = player->y + 0x1200;
    }
    player->placement_input_delay = 0x20;
    player->action_state = 3;
}

/* Original address: 0x02026464 */
void PlayerHand_UpdateCarrying(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    Entity *entity = &g_EntityTable[2];
    AnimFrameData *frame;
    AnimFrameData *blocked_frame;

    if (islander->carry_state == 0) {
        if (player->held_item_layer == 0 && player->held_item_tile_idx == 0) {
            player->action_state = 0;
            PlayerHand_ResetToIdle();
            return;
        }
    }
    if ((player->placement_input_delay == 0 || --player->placement_input_delay == 0) &&
        (gGameState.keys.buttons.pressed & 1)) {
        if (islander->carry_state != 0) {
            player->work_x = ((player->x >> 8) - 8) & 0xFF0;
            player->work_y = ((player->y >> 8) + 0x18) & 0xFF0;
        } else {
            player->work_x = entity->x + 8;
            player->work_y = entity->y + 8;
        }
        if (PlayerHand_IsItemPlacementBlocked() == 0) {
            Sound_PlayEffect0(4);
            player->action_state = 4;
            PlayerHand_BeginPlacing();
            return;
        }
        player->anim_id = 3;
        blocked_frame = sPlayerHandAnimations[3][0];
        player->anim_frame = 0;
        player->anim_timer = blocked_frame->duration;
        Sound_PlayEffect0(0x12);
    }
    PlayerHand_UpdateMovement();
    if (islander->carry_state == 0) {
        entity->lifetime = 0x30;
        entity->x = (player->x >> 8) - 8;
        entity->y = (player->y >> 8) - 2;
    } else {
        islander->x = player->x;
        islander->y = player->y + 0x1200;
    }
    if (player->anim_timer == 0) {
        player->anim_frame++;
        frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
        if ((u8)frame->action_flag == 0xFF) {
            player->anim_frame--;
            return;
        }
        player->anim_timer = frame->duration;
    } else {
        player->anim_timer--;
    }
}

/* Original address: 0x020265A8 */
void PlayerHand_BeginPlacing(void) {
    Player *player = &gPlayer;
    AnimFrameData *frame;
    player->anim_id = 2;
    frame = sPlayerHandAnimations[2][0];
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    player->action_state = 5;
}

/* Original address: 0x020265D4 */
void PlayerHand_UpdatePlacing(void) {
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    s32 attract_islander = 0;
    AnimFrameData *frame;
    ItemGroupStruct *definition;
    s32 dx, dy;

    if (islander->carry_state == 0 && player->held_item_layer == 0 && player->held_item_tile_idx == 0) {
        player->action_state = 0;
        PlayerHand_ResetToIdle();
        return;
    }
    if (player->anim_timer != 0) {
        player->anim_timer--;
        if (player->anim_frame == 3 && player->anim_timer == 0) {
            field->entity_active[2] = 0;
        }
        return;
    }
    player->anim_frame++;
    frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
    if ((u8)frame->action_flag != 0xFF) {
        player->anim_timer = frame->duration;
        return;
    }
    if (islander->carry_state == 0) {
        definition = &g_ItemDefinitions[player->held_item_type_idx];
        WriteItemToTile(player->x, player->tile_idx, player->held_item, definition->field_tile_id);
        if (player->held_item_layer == 0) {
            field->fg_tiles[0][player->held_item_tile_idx] = 0xFFF;
        } else {
            field->fg_tiles[1][player->held_item_tile_idx] = 0xFFF;
        }
        if (!(player->x & 0xFF0000)) {
            field->fg_tiles[0][player->tile_idx] = player->held_item_type_idx;
        } else {
            field->fg_tiles[1][player->tile_idx] = player->held_item_type_idx;
        }
        player->held_item_layer = 0;
        player->held_item_tile_idx = 0;
        if (islander->move_action == 3) {
            if (islander->stored_item_type_plus_one[4] == 0) {
                if (islander->equipped_tool_state == 0) {
                    attract_islander = 1;
                } else if (islander->equipped_tool_state == 3 || islander->equipped_tool_state == 7) {
                    if (definition->interaction_type <= 3 || definition->interaction_type == 5 ||
                        definition->interaction_type == 6) {
                        attract_islander = 1;
                    }
                }
            } else if (islander->equipped_tool_state == 0 && (u16)(definition->interaction_type - 5) <= 9) {
                attract_islander = 1;
            }
        }
        dx = player->x - islander->x;
        if (dx < 0) dx = -dx;
        dy = player->y - islander->y;
        if (dy < 0) dy = -dy;
        if (dx <= 0x2FFF && dy <= 0x2FFF && attract_islander == 1) {
            islander->target_x = (player->x & 0xFF0000) | (((player->tile_idx & 0xF) << 12) + 0x800);
            islander->target_y = ((player->tile_idx & 0xF0) << 8) + 0x800;
            islander->move_action = 9;
        }
    } else {
        islander->carry_state = 1;
    }
    player->interaction_cooldown_timer = 0x20;
    islander->player_interaction_tile_idx = player->tile_idx;
    player->action_state = 0;
    PlayerHand_ResetToIdle();
}

/* Original address: 0x020267D0 */
void PlayerHand_Update(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    field->entity_active[0] = 1;
    field->entity_active[1] = 1;
    if (islander->move_action != 0x14 || islander->action_state == 0 || islander->carry_state == 2) {
        sPlayerHandUpdateProcs[player->action_state]();
    }
}

/* Original address: 0x02026830 */
void PlayerHand_Draw(void) {
    Player *player = &gPlayer;
    IslanderOamData *sprite;
    IslanderOamData *oam;
    u32 i;

    player->work_y = player->y >> 8;
    player->work_x = player->x >> 8;
    sprite = sPlayerHandAnimations[player->anim_id][player->anim_frame]->sprite_gfx_p;
    gIslandFieldWork.entity_active[0] = 0;
    gIslandFieldWork.entity_active[1] = 0;
    i = 0;
    if (sprite->affine_param == 0xFFFF) {
        return;
    }
    do {
        oam = &((IslanderOamData *)gUnk3002410)[gGameState.oam_count];
        oam->obj_mode = sprite->obj_mode;
        oam->bpp = sprite->bpp;
        oam->shape = sprite->shape;
        oam->h_flip = sprite->h_flip;
        oam->v_flip = sprite->v_flip;
        oam->size = sprite->size;
        oam->y = sprite->y + player->work_y - (u8)gGameState.bg2_vofs;
        oam->x = sprite->x + player->work_x - gGameState.bg2_hofs;
        oam->tile_num = sprite->tile_num;
        oam->mosaic = 1;
        oam->priority = 0;
        oam->palette_num = sprite->palette_num;
        gIslandFieldWork.entity_active[i] = 1;
        gGameState.oam_count++;
        i++;
        sprite++;
    } while (sprite->affine_param != 0xFFFF);
}

/* Original address: 0x02035BF4 */
extern const SoundBank sSoundBank;

/* Original address: 0x020269C8 */
void Audio_Init(void) {
    SoundDriver_Init(&sSoundBank);
    Sound_InitMusic();
    Sound_InitEffects();
}

/* Original address: 0x020269E0 */
void Audio_Update(void) {
    sub_02026A34();
    Sound_CommitCommands();
}

/* sizeof(SoundEffectState) == 0x08. */
typedef struct SoundEffectState {
    /* 0x00 */ s32 sound_id;
    /* 0x04 */ u8 active;
    /* 0x05 */ u8 unk_05[3];
} SoundEffectState;

/* sizeof(SoundPlayer) == 0x44; eight players at 0x03001918. */
struct SoundPlayer {
    /* 0x00 */ const u16 *bank;
    /* 0x04 */ const u8 *sequence;
    /* 0x08 */ SoundTrack *tracks[10];
    /* 0x30 */ union {
        struct { u8 tempo[2]; u8 tempo_adjust[2]; } bytes;
        struct { u16 tempo; s16 tempo_adjust; } values;
    } timing;
    /* 0x34 */ u16 volume;
    /* 0x36 */ s16 volume_step;
    /* 0x38 */ u16 target_volume;
    /* 0x3A */ u16 fade_timer;
    /* 0x3C */ union {
        s8 flags;
        struct { u8 paused : 1; u8 reserved : 7; } __attribute__((packed)) bits;
    } __attribute__((packed)) control;
    /* 0x3D */ u8 unk_3D[3];
    /* 0x40 */ u8 master_volume;
    /* 0x41 */ u8 status;
    /* 0x42 */ u8 is_sound_effect;
    /* 0x43 */ u8 tempo_mode;
};

/* Original address: 0x03000028 */
extern s16 sCurrentSoundEffects[5];
/* Original address: 0x03000038 */
extern SoundEffectState sSoundEffectStates[3];
/* Original address: 0x03000050 */
extern u16 sCurrentMusic;
/* Original address: 0x03000052 */
extern u8 sMusicEmotion;
/* Original address: 0x03001918 */
extern SoundPlayer gSoundPlayers[8];
/* Original address: 0x02035C10 */
extern const u32 sSoundEffectTable[43];
/* Original address: 0x02035CBC */
extern const u8 sMusicTable[2][2];

/* Original address: 0x020269F0 */
void Sound_InitEffects(void) {
    s16 *current = sCurrentSoundEffects;
    s32 i;

    for (i = 0; i < 3; i++) {
        sSoundEffectStates[i].sound_id = -1;
        sSoundEffectStates[i].active = 0;
    }
    CpuFill16(0xFFFF, current, sizeof(sCurrentSoundEffects));
}

void sub_02026A34(void) {

}

/* Original address: 0x02026A38 */
void Sound_PlayEffect0(u16 value) {
    u16 player = 0;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026AB8 */
void Sound_PlayEffect1(u16 value) {
    u16 player = 1;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026B38 */
void Sound_StopEffect1(u8 arg0) {
    Sound_QueueFadeOutPlayer(1U, 0U);
}

/* Original address: 0x02026B48 */
void Sound_PlayEffect2(u16 value) {
    u16 player = 2;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026BC8 */
void Sound_StopEffect2(u16 value) {
    Sound_QueueFadeOutPlayer(2U, 0U);
}

/* Original address: 0x02026BD8 */
void Sound_InitMusic(void) {
    Sound_QueueSetNoteCallback(Sound_PlayEmotionNote);
    Sound_QueueSetControlCallback(Sound_ApplyEmotionTrackDelay);
    sCurrentMusic = 0xFFFF;
    sMusicEmotion = 0;
}

void sub_02026C0C(void) {

}

/* Original address: 0x02026C10 */
void Sound_PlayMusic(u16 value) {
    if (Sound_GetPlayerStatus(4) == 0 || sCurrentMusic != value) {
        Sound_QueueStartMusic(4, sMusicTable[value][0]);
        if (value == 1) {
            ChangeEmotion(sMusicEmotion);
        } else {
            Sound_QueueSetTracksMuted(4, 0, 0);
        }
        sCurrentMusic = value;
    }
}

/* Original address: 0x02026C68 */
void Sound_StopMusic(u16 value) {
    Sound_QueueFadeOutPlayer(4U, value);
}

/* Original address: 0x02026C7C */
void ChangeEmotion(u8 emotion) {
    u8 tempo_mode;
    u16 tempo_adjust;

    if (emotion == sMusicEmotion)
        return;
    sMusicEmotion = emotion;
    if (Sound_GetPlayerStatus(4) == 0 || sCurrentMusic != 1)
        return;

    tempo_mode = 0;
    tempo_adjust = 0;
    switch (emotion) {
    case 1:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0, 1);
        break;
    case 2:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0x94, 1);
        tempo_adjust = 30;
        tempo_mode = 1;
        break;
    case 3:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0x210, 1);
        tempo_adjust = -16;
        tempo_mode = 1;
        break;
    case 4:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0, 1);
        {
            u8 tempo_low = gSoundPlayers[4].timing.bytes.tempo[0];
            u8 tempo_high = gSoundPlayers[4].timing.bytes.tempo[1];
            tempo_adjust = (s16)((tempo_high << 8) | tempo_low) >> 1;
        }
        break;
    default:
        return;
    }
    Sound_QueueSetPlayerTempoMode(4, tempo_mode);
    Sound_QueueSetPlayerTempoAdjust(4, (s16)tempo_adjust);
}

typedef struct SoundEnvelopePoint {
    s16 duration;
    s16 volume;
} SoundEnvelopePoint;

/* sizeof(SoundEnvelope) == 0x14. */
typedef struct SoundEnvelope {
    s32 volume;
    s32 target_volume;
    u16 timer;
    s16 step;
    const SoundEnvelopePoint *points;
    s8 index;
    u8 unk_11[3];
} SoundEnvelope;

typedef struct SoundVibratoParams {
    u16 delay;
    u16 unk_02;
    s32 speed;
    s32 depth;
} SoundVibratoParams;

typedef struct SoundVibrato {
    u32 phase;
    s32 delay;
    SoundVibratoParams *params;
} SoundVibrato;

typedef struct SoundPitchSlide {
    s32 delay;
    s32 timer;
    s32 offset;
    s32 target;
    s32 step;
    struct SoundPitchSlideParams *params;
} SoundPitchSlide;

/* sizeof(SoundPitchSlideParams) == 8. */
typedef struct SoundPitchSlideParams {
    u8 enabled;
    u8 flags;
    u8 key;
    u8 unk_03;
    u16 delay;
    u16 duration;
} SoundPitchSlideParams;

/* sizeof(SoundTrack) == 0x54. Unrecovered fields retain their offsets. */
struct SoundTrack {
    const u8 *sequence;
    const u32 *sample_offsets;
    SoundPlayer *player;
    SoundChannel *channel;
    SoundVibratoParams vibrato;
    SoundPitchSlideParams slide;
    /* 0x24 */ const u8 *return_stack[3];
    /* 0x30 */ const u8 **stack_pointer;
    /* 0x34 */ s32 tick_accumulator;
    u8 unk_38[8];
    /* 0x40 */ u16 bank;
    /* 0x42 */ u16 program;
    /* 0x44 */ u16 note_duration;
    /* 0x46 */ u16 rest_duration;
    /* 0x48 */ u8 velocity;
    /* 0x49 */ u8 tie;
    /* 0x4A */ u8 muted;
    u8 pan;
    u8 unk_4C;
    u8 volume;
    u8 expression;
    s8 pitch_bend;
    u8 pitch_bend_range;
    u8 transpose;
    u8 priority;
    u8 unk_53;
};

/* Original address: 0x03000B24 */
extern SoundTrack gSoundTracks[16];

typedef struct SoundInstrument {
    u8 type;
    u8 flags;
    u16 sample;
    u16 envelope;
    u8 release;
    u8 root_key;
} SoundInstrument;

typedef struct SoundInstrumentMap {
    u8 type;
    u8 flags;
    u16 table;
    u8 first_key;
    u8 unk_05;
} SoundInstrumentMap;

/* The square-wave instrument extends the common eight-byte header. */
typedef struct SoundSquareInstrument {
    SoundInstrument instrument;
    u8 sweep;
} SoundSquareInstrument;

typedef struct SoundKeyInstrument {
    u16 instrument;
    u8 pan;
    u8 unk_03;
} SoundKeyInstrument;

typedef struct SoundInstrumentSplit {
    u8 last_key;
    u8 unk_01;
    u16 instrument;
} SoundInstrumentSplit;

/* sizeof(SoundBank) == 0x1C; table offsets are relative to each table. */
struct SoundBank {
    /* 0x00 */ const u32 *sample_offsets;
    /* 0x04 */ const u32 *instrument_offsets;
    /* 0x08 */ const u32 *music_sequence_offsets;
    /* 0x0C */ const u32 *effect_sequence_offsets;
    /* 0x10 */ const u16 *sample_indices;
    /* 0x14 */ const u32 *music_bank_offsets;
    /* 0x18 */ const u32 *effect_bank_offsets;
};

/* Original address: 0x03000268 */
extern SoundInstrument sSoundKeySampleInstrument;
/* Original address: 0x02035CD4 */
extern const SoundEnvelopePoint sSoundKeySampleEnvelope[3];

typedef struct SoundSample {
    u32 length;
    u32 frequency;
    u32 loop_start;
    u32 loop_end;
} SoundSample;

typedef struct SoundDutySequence {
    u16 length;
    u8 values[1];
} SoundDutySequence;

/* sizeof(SoundInstrumentResult) == 0x14; filled by Sound_ResolveInstrument. */
struct SoundInstrumentResult {
    SoundInstrument *instrument;
    const SoundEnvelopePoint *envelope;
    SoundDutySequence *duty_sequence;
    const u16 *wave;
    u8 pan;
    u8 fixed_pan;
    u8 fixed_pitch;
};

/* Original address: 0x02035CCC */
extern const u8 sSoundInstrumentChannelTypes[5];

/* sizeof(SoundChannel) == 0x7C, confirmed by both channel pool strides. */
struct SoundChannel {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 unk_02[2];
    /* 0x04 */ SoundTrack *track;
    /* 0x08 */ u8 priority;
    /* 0x09 */ u8 velocity;
    /* 0x0A */ u8 unk_0A[2];
    /* 0x0C */ u32 base_pitch;
    /* 0x10 */ u32 pitch;
    /* 0x14 */ u32 volume;
    /* 0x18 */ u16 gate_timer;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 fixed_pan;
    /* 0x1C */ u8 pan;
    /* 0x1D */ u8 unk_1D[3];
    /* 0x20 */ SoundVibrato vibrato;
    /* 0x2C */ SoundPitchSlide slide;
    /* 0x44 */ SoundEnvelope envelope;
    /* 0x58 */ SoundInstrument *instrument;
    /* 0x5C */ u8 release;
    /* 0x5D */ u8 unk_5D[3];
    /* 0x60 */ SoundSample *sample;
    /* 0x64 */ u32 age;
    /* 0x68 */ union {
        SoundDutySequence *sequence;
        const u16 *wave;
        u8 duty;
    } psg;
    /* 0x6C */ SoundChannel *prev;
    /* 0x70 */ SoundChannel *next;
    /* 0x74 */ SoundChannel *track_prev;
    /* 0x78 */ SoundChannel *track_next;
};

/* sizeof(SoundChannelLists) == 0x1F4; sentinel offsets 0x04/0x80/0xFC/0x178. */
typedef struct SoundChannelLists {
    void *wave;
    SoundChannel active_head;
    SoundChannel active_tail;
    SoundChannel free_head;
    SoundChannel free_tail;
} SoundChannelLists;

/* Original address: 0x03000058 */
extern s8 *gPcmOutputBuffers[2];
/* Original address: 0x03000060 */
extern s8 *gPcmRightOutputBuffers[2];
/* Original address: 0x03000068 */
extern u16 gSoundTimerReload;
/* Original address: 0x0300006A */
extern u8 gPcmOutputBufferIndex;
/* Original address: 0x0300006B */
extern u8 gSoundDmaEnabled;
/* Original address: 0x03000070 */
extern SoundChannelLists gSoundChannelLists;
/* Original address: 0x03000594 */
extern const SoundBank *gSoundBank;
/* Original address: 0x03000598 */
extern void (*gPcmOutputMixer)(s32 *, s8 *, s32 *);
typedef u32 (*PcmChannelMixer)(const s8 *, s16 *, s16 *, s16 *, u32, u32, u32, u32);
/* Original address: 0x0300059C */
extern PcmChannelMixer gPcmChannelMixer;
/* Original address: 0x030005A0 */
extern void (*gPcmResampleMixer)(void);
/* Original address: 0x030005A4 */
extern s8 gSoundPcmBuffers[2][2][176];
/* Original address: 0x03001064 */
extern u32 gSoundMixerCode[0xD8];
/* Original address: 0x030013C4 */
extern SoundChannel gPcmChannels[7];
/* Original address: 0x03001728 */
extern SoundChannel gPsgChannels[4];

/* Disabling DMA requires a readback before the channel is reprogrammed. */
#define SOUND_DMA_DISABLE(n) do { \
    vu16 *regs = (vu16 *)REG_ADDR_DMA##n; \
    regs[5] = ((u32)regs[5] << 17) >> 17; \
    regs[5]; \
} while (0)

/* Channel links are also accessed by the byte-oriented sound data code. */
#define SOUND_WRITE_LINK(field, value) do { \
    ((u8 *)&(field))[0] = (u32)(value); \
    ((u8 *)&(field))[1] = ((u32)(value) >> 8) & 0xFF; \
    ((u8 *)&(field))[2] = ((u32)(value) >> 16) & 0xFF; \
    ((u8 *)&(field))[3] = (u32)(value) >> 24; \
} while (0)

/* Original address: 0x02026D74 */
void Sound_PlayEmotionNote(SoundTrack *arg0, u8 note, u8 velocity, u16 duration) {
    SoundTrack *track = (SoundTrack *)arg0;
    if (track != track->player->tracks[9]) {
        if (sMusicEmotion == 2) {
            switch ((u8)(note % 12U)) {
            case 0: note += 2; break;
            case 1:
            case 3:
            case 5: note++; break;
            }
        } else {
            switch ((u8)(note % 12U)) {
            case 0:
            case 5:
            case 7: note--; break;
            }
        }
    }
    Sound_PlayNote((SoundTrack *)arg0, note, velocity, duration);
}

/* Original address: 0x02026DFC */
void Sound_ApplyEmotionTrackDelay(SoundTrack *arg0, u8 event) {
    SoundPlayer *player = ((SoundTrack *)arg0)->player;
    if ((sMusicEmotion == 4 && event != 0) ||
        (sMusicEmotion == 2 && (*(vu8 *)REG_ADDR_TM0CNT_L & 15U) <= 4)) {
        int i;
        for (i = 0; i < 10; i++) {
            SoundTrack *track = player->tracks[i];
            if (track != NULL)
                track->tick_accumulator += 1800;
        }
    }
}

/* Original address: 0x02026E4C */
void SoundDriver_Init(const SoundBank *bank) {
    gSoundBank = bank;
    *(vu8 *)REG_ADDR_SOUNDCNT_X = 0;
    *(vu8 *)REG_ADDR_SOUNDCNT_X = 0x80;
    REG_SOUNDCNT_L = 0xFF77;
    *(vu8 *)REG_ADDR_SOUNDCNT_H = 0x0D;
    REG_SOUNDBIAS = (REG_SOUNDBIAS & 0x3FFF) | 0x4000;
    REG_SOUND1CNT_L = 8;
    REG_SOUND1CNT_H = 0xF000;
    CpuFastCopy(sub_02029004, gSoundMixerCode, sizeof(gSoundMixerCode));
    gPcmOutputMixer = (void (*)(s32 *, s8 *, s32 *))gSoundMixerCode;
    gPcmChannelMixer = (PcmChannelMixer)((u8 *)gSoundMixerCode + (sub_020290C4 - sub_02029004));
    gPcmResampleMixer = (void (*)(void))((u8 *)gSoundMixerCode + (sub_020291E4 - sub_02029004));
    SoundDriver_InitPcmBuffers(&gSoundPcmBuffers[0][0][0]);
    Sound_InitCommandQueue();
    Sound_InitKeySampleInstrument();
    SoundDriver_InitChannelLists();
    Sound_InitTracks();
    Sound_InitPlayers();
}

/* Original address: 0x02026F0C */
void SoundDriver_VBlank(void) {
    SoundDriver_SwapPcmBuffers();
}

/* Original address: 0x02026F18 */
void SoundDriver_Update(void) {
    Sound_ProcessCommands();
    Sound_UpdatePlayers();
    Sound_UpdatePsgChannels();
    if (gSoundDmaEnabled != 0) {
        Sound_UpdatePcmChannels();
    }
}

/* Original address: 0x02026F3C */
void SoundDriver_InitPcmBuffers(s8 *buffers) {
    gSoundDmaEnabled = 1;
    gPcmOutputBuffers[0] = buffers;
    gPcmRightOutputBuffers[0] = buffers + 176;
    gPcmOutputBuffers[1] = buffers + 352;
    gPcmRightOutputBuffers[1] = buffers + 528;
    gSoundTimerReload = 0xF9C4;
    gPcmOutputBufferIndex = 0;
    *(vu8 *)(REG_ADDR_SOUNDCNT_H + 1) = 0x9A;
    REG_FIFO_A = 0;
    REG_FIFO_B = 0;
}

/* Original address: 0x02026FAC */
void SoundDriver_SwapPcmBuffers(void) {
    REG_TM0CNT = gSoundTimerReload | 0x800000;
    if (gSoundDmaEnabled) {
        SOUND_DMA_DISABLE(1);
        SOUND_DMA_DISABLE(2);
        DmaSet(1, gPcmOutputBuffers[gPcmOutputBufferIndex], REG_ADDR_FIFO_A, 0xB6400004);
        DmaSet(2, gPcmRightOutputBuffers[gPcmOutputBufferIndex], REG_ADDR_FIFO_B, 0xB6400004);
        gPcmOutputBufferIndex = 1 - gPcmOutputBufferIndex;
    }
}

/* Original address: 0x02027040 */
void SoundDriver_DisablePcm(void) {
    gSoundDmaEnabled = 0;
    SOUND_DMA_DISABLE(1);
    SOUND_DMA_DISABLE(2);
}

/* Original address: 0x02027068 */
void SoundDriver_EnablePcm(void) {
    gSoundDmaEnabled = 1;
}

/* Original address: 0x02027074 */
void SoundDriver_InitChannelLists(void) {
    SoundChannel *tail;
    int i;
    gSoundChannelLists.wave = NULL;
    tail = &gSoundChannelLists.free_tail;
    for (i = 3; i >= 0; i--)
        gPsgChannels[i].state = 0;
    gPsgChannels[0].type = 1;
    gPsgChannels[1].type = 2;
    gPsgChannels[2].type = 3;
    gPsgChannels[3].type = 4;
    for (i = 0; i < 7; i++) {
        gPcmChannels[i].state = 0;
        gPcmChannels[i].type = 0;
    }
    gSoundChannelLists.free_head.next = gPcmChannels;
    SOUND_WRITE_LINK(gPcmChannels[0].next, &gPcmChannels[1]);
    SOUND_WRITE_LINK(gPcmChannels[0].prev, &gSoundChannelLists.free_head);
    for (i = 1; i < 6; i++) {
        SOUND_WRITE_LINK(gPcmChannels[i].next, &gPcmChannels[i + 1]);
        SOUND_WRITE_LINK(gPcmChannels[i].prev, &gPcmChannels[i - 1]);
    }
    SOUND_WRITE_LINK(gPcmChannels[6].next, tail);
    SOUND_WRITE_LINK(gPcmChannels[6].prev, &gPcmChannels[5]);
    tail->prev = &gPcmChannels[6];
    gSoundChannelLists.active_head.next = &gSoundChannelLists.active_tail;
    gSoundChannelLists.active_tail.prev = &gSoundChannelLists.active_head;
}

/* Original address: 0x020271FC */
void Sound_UnlinkChannel(SoundChannel *channel) {
    channel->prev->next = channel->next;
    channel->next->prev = channel->prev;
}



/* The channel mixer accumulates halfwords; the output mixer packs them as words. */
typedef union PcmMixBuffer {
    s16 samples[352];
    s32 words[176];
} PcmMixBuffer;

/* Original address: 0x03000864 */
extern PcmMixBuffer gPcmMixBuffer;
/* Original address: 0x02035CC4 */
extern const u8 sPsgWaveVolume[5];
/* Original address: 0x02035CE0 */
extern const u16 sPsgPitchTable[];
/* Original address: 0x02035DD0 */
extern const u8 sNoisePitchTable[120];
/* Original address: 0x02035E48 */
extern const u32 sPcmPitchTable[];
/* Original address: 0x02036028 */
extern const u8 sSoundVibratoWave[256];

/* Original address: 0x0202720C */
void Sound_InsertPcmChannelByPriority(SoundChannel *channel) {
    SoundChannel *next = gSoundChannelLists.active_head.next;

    if (channel->state == 1) {
        while (next != &gSoundChannelLists.active_tail) {
            if (next->state == 1 && channel->priority < next->priority)
                break;
            next = next->next;
        }
    } else if (channel->state == 2) {
        while (next != &gSoundChannelLists.active_tail && next->state != 1 &&
               channel->priority >= next->priority)
            next = next->next;
    } else {
        return;
    }
    channel->next = next;
    channel->prev = next->prev;
    next->prev->next = channel;
    next->prev = channel;
}

/* Original address: 0x02027294 */
s32 Sound_NoteToPitch(SoundChannel *channel, u8 key, u8 root_key) {
    s16 note = key + 48 - root_key;
    if (note < 0)
        note = 0;
    else if (note > 119)
        note = 120;
    if (channel->type == 0)
        return sPcmPitchTable[note];
    else if (channel->type == 4)
        return note;
    else
        return sPsgPitchTable[note];
}

/* Original address: 0x020272E8 */
u8 Sound_NoteToNoiseControl(u16 note) {
    if (note > 119)
        note = 119;
    return sNoisePitchTable[note];
}

/* Original address: 0x02027300 */
s32 Sound_UpdateChannelEnvelope(SoundChannel *channel) {
    SoundEnvelope *envelope = &channel->envelope;
    if (envelope->timer == 0) {
        channel->envelope.volume = envelope->target_volume;
        envelope->index++;
        if (envelope->points[envelope->index].duration < 0)
            envelope->index--;
        envelope->target_volume = envelope->points[envelope->index].volume;
        envelope->timer = envelope->points[envelope->index].duration;
        envelope->step = envelope->target_volume;
        envelope->step -= channel->envelope.volume;
        envelope->step /= envelope->timer;
    }
    envelope->volume += envelope->step;
    envelope->timer--;
    return envelope->volume;
}

void sub_02027370(u8 arg0) {
}

/* Original address: 0x02027374 */
u32 Sound_UpdatePcmChannelVolume(SoundChannel *channel) {
    u32 volume;
    if (channel->state == 1) {
        SoundTrack *track;
        SoundPlayer *player;
        volume = channel->velocity;
        volume <<= 8;
        track = channel->track;
        player = track->player;
        volume *= player->volume;
        volume >>= 7;
        volume *= player->master_volume;
        volume >>= 7;
        volume *= track->volume;
        volume >>= 15;
        volume *= track->expression;
        volume >>= 7;
        volume *= Sound_UpdateChannelEnvelope(channel);
        volume >>= 15;
        channel->volume = volume;
    } else {
        channel->volume = (channel->volume * (channel->release + 230)) >> 9;
        volume = channel->volume;
    }
    volume >>= 8;
    return volume;
}

/* Original address: 0x020273D0 */
u8 Sound_GetPsgEnvelopeControl(SoundChannel *channel, u8 boost) {
    u8 control = 0;
    u32 volume = channel->velocity;
    u32 target;
    u16 period;
    s32 difference;
    SoundTrack *track;
    SoundPlayer *player;

    if (channel->envelope.timer == 0)
        control = 1;
    Sound_UpdateChannelEnvelope(channel);
    if (control == 0)
        return 8;
    if (boost)
        volume *= 2;
    volume <<= 15;
    track = channel->track;
    volume *= track->volume;
    volume >>= 14;
    volume *= track->expression;
    volume >>= 7;
    player = track->player;
    volume *= player->master_volume;
    volume >>= 8;
    volume *= player->volume;
    if (channel->type == 3) {
        volume >>= 22;
        channel->volume = volume;
        volume *= 5;
        volume >>= 7;
        if (volume > 4)
            volume = 4;
        return volume;
    }
    volume >>= 15;
    channel->volume = volume;
    volume *= channel->envelope.volume;
    volume >>= 25;
    if (volume & ~15)
        volume = 15;
    channel->volume = (channel->volume * channel->envelope.target_volume) >> 25;
    if (channel->volume & ~15)
        channel->volume = 15;
    target = channel->volume;
    if (target == volume) {
        control = (volume << 4) | 8;
        return control;
    } else {
        period = channel->envelope.timer;
        period += 15;
        difference = target - volume;
        if (difference < 0)
            difference = -difference;
        period /= difference;
        if (period == 0) {
            control = (u8)((volume << 4) | 8);
        } else {
            if (period & 0xFFF8)
                period = 7;
            control = (u8)((volume << 4) | period);
            if (volume < target)
                control |= 8;
        }
    }
    return control;
}

/* Original address: 0x020274D0 */
u32 Sound_UpdateChannelPitch(SoundChannel *channel) {
    u32 pitch = channel->base_pitch;
    SoundTrack *track = channel->track;
    SoundPitchSlide *slide = &channel->slide;
    SoundVibrato *vibrato;
    s32 depth;
    if (slide->delay != 0) {
        slide->delay--;
    } else if (slide->timer != 0) {
        slide->offset += slide->step;
        if (--slide->timer == 0)
            slide->offset = slide->target;
    }
    pitch += slide->offset;
    if (track->pitch_bend != 0) {
        s32 bend = sPcmPitchTable[track->pitch_bend_range + 48];
        bend -= 0x8000;
        bend *= track->pitch_bend;
        bend += 0x400000;
        bend >>= 14;
        if (channel->type == 0) {
            pitch *= bend;
            pitch >>= 8;
        } else {
            pitch = 0x800 - pitch;
            pitch <<= 8;
            pitch /= (u32)bend;
            pitch = 0x800 - pitch;
        }
    }
    vibrato = &channel->vibrato;
    depth = vibrato->params->depth;
    if (depth != 0) {
        if (vibrato->delay == 0) {
            u8 wave = sSoundVibratoWave[vibrato->phase >> 1];
            if (channel->type == 0) {
                if ((s8)wave >= 0)
                    pitch += (depth * (pitch * (s8)wave)) >> 19;
                else {
                    pitch <<= 12;
                    pitch /= ((u32)(-(s8)wave * depth) >> 3) + 0x10000;
                    pitch <<= 4;
                }
            } else {
                u32 period;
                if ((s8)wave >= 0)
                    period = ((0x800 - pitch) << 19) / (u32)(depth * (s8)wave + 0x80000);
                else {
                    period = 0x800 - pitch;
                    period *= (-(s8)wave * depth + 0x80000);
                    period >>= 19;
                }
                pitch = 0x800 - period;
            }
            vibrato->phase += vibrato->params->speed;
            if ((vibrato->phase >> 1) > 255)
                vibrato->phase -= 512;
        } else {
            vibrato->delay--;
        }
    }
    return pitch;
}

/* Original address: 0x02027610 */
void Sound_UpdatePcmChannels(void) {
    SoundChannel *channel = gSoundChannelLists.active_head.next;
    s32 zero = 0;
    s32 i;
    SoundChannel *expired;
    CpuFastSet(&zero, &gPcmMixBuffer, 0x010000B0);
    while (channel != &gSoundChannelLists.active_tail) {
        u32 volume = Sound_UpdatePcmChannelVolume(channel);
        u32 pitch;
        u8 pan;
        if (channel->state == 1) {
            SoundTrack *track;
            channel->gate_timer--;
            track = channel->track;
            pan = channel->fixed_pan ? channel->pan : track->pan;
            pitch = Sound_UpdateChannelPitch(channel);
            channel->pitch = pitch;
            channel->unk_1A = track->unk_4C;
        } else {
            if (volume == 0) {
                channel = channel->next;
                Sound_StopChannel(channel->prev);
                continue;
            }
            pan = channel->pan;
            pitch = channel->pitch;
        }
        pitch >>= 2;
        pitch *= channel->sample->frequency;
        pitch /= 10512;
        pitch *= 176;
        pitch /= 176;
        pitch >>= 5;
        if (Sound_MixPcmChannel(channel, volume, pitch, pan) == 1) {
            channel = channel->next;
            Sound_StopChannel(channel->prev);
        } else {
            channel = channel->next;
        }
    }
    for (i = 0; i < 7; i++) {
        expired = &gPcmChannels[i];
        if (expired->state == 1 && expired->gate_timer == 0)
            Sound_ReleaseChannel(expired);
    }
    gPcmOutputMixer(gPcmMixBuffer.words, gPcmOutputBuffers[gPcmOutputBufferIndex], gPcmMixBuffer.words + 176);
}

/* Original address: 0x02027728 */
void Sound_UpdatePsgChannels(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        SoundChannel *channel = &gPsgChannels[i];
        u32 pitch;
        u8 pan;
        u8 envelope;
        u8 sound_index;
        u32 stereo_mask;
        u8 clear_mask;
        u8 duty;
        SoundInstrument *instrument;
        vu8 *routing;
        vu8 *duty_register;
        if (channel->state == 1 && channel->gate_timer == 0)
            Sound_ReleaseChannel(channel);
        if (channel->state == 0)
            continue;
        if (channel->state == 1) {
            pitch = Sound_UpdateChannelPitch(channel);
            channel->pitch = pitch;
            pan = channel->fixed_pan ? channel->pan : channel->track->pan;
        } else {
            pitch = channel->pitch;
            pan = channel->pan;
        }
        envelope = Sound_GetPsgEnvelopeControl(channel, pan != 64);
        routing = (vu8 *)REG_ADDR_NR51;
        sound_index = channel->type - 1;
        stereo_mask = 0x11 << sound_index;
        clear_mask = ~stereo_mask;
        if (pan == 64)
            *routing = (clear_mask & *routing) | stereo_mask;
        else if (pan < 64)
            *routing = (clear_mask & *routing) | (0x10 << sound_index);
        else
            *routing = (clear_mask & *routing) | (1 << sound_index);

        if (channel->state == 1) {
            if (channel->age == 0) {
                Sound_StartPsgChannel(channel, envelope);
                channel->age = 1;
                channel->gate_timer--;
                continue;
            }
            channel->age++;
            channel->gate_timer--;
        } else if (channel->type == 3) {
            u32 volume;
            u8 wave_volume;
            channel->volume = (channel->volume * (channel->release + 230)) >> 9;
            volume = channel->volume;
            if (pan != 64)
                volume *= 2;
            volume *= 5;
            volume >>= 7;
            if (volume != 0) {
                if (volume > 4)
                    volume = 4;
                wave_volume = volume;
                REG_NR32 = sPsgWaveVolume[wave_volume];
            } else {
                Sound_StopChannel(channel);
            }
            continue;
        }

        instrument = channel->instrument;
        if (instrument->flags & 1) {
            SoundDutySequence *sequence = channel->psg.sequence;
            u16 length = sequence->length;
            u32 age = channel->age;
            if (age < length)
                duty = sequence->values[age];
            else
                duty = sequence->values[length - 1];
        } else {
            duty = 0xFF;
        }
        switch (channel->type) {
        case 1:
            if (envelope != 8) {
                REG_NR12 = envelope;
                REG_SOUND1CNT_X = pitch | 0x8000;
            } else if (((SoundSquareInstrument *)instrument)->sweep == 8) {
                REG_SOUND1CNT_X = pitch;
            }
            duty_register = (vu8 *)REG_ADDR_NR11;
            *duty_register &= 0xC0;
            if (duty != 0xFF)
                *duty_register = duty << 6;
            break;
        case 2:
            if (envelope != 8) {
                REG_NR22 = envelope;
                REG_SOUND2CNT_H = pitch | 0x8000;
            } else {
                REG_SOUND2CNT_H = pitch;
            }
            duty_register = (vu8 *)REG_ADDR_NR21;
            *duty_register &= 0xC0;
            if (duty != 0xFF)
                *duty_register = duty << 6;
            break;
        case 3:
            REG_SOUND3CNT_X = (REG_SOUND3CNT_X & 0x4000) | pitch;
            if (envelope != 8)
                REG_NR32 = sPsgWaveVolume[envelope];
            break;
        case 4:
            if (envelope != 8) {
                REG_NR42 = envelope;
                REG_NR44 = 0x80;
            }
            if (duty != 0xFF) {
                vu8 *noise_register = (vu8 *)REG_ADDR_NR43;
                u8 noise = Sound_NoteToNoiseControl(pitch);
                if (duty != 0)
                    noise |= 8;
                *noise_register = noise;
            } else {
                REG_NR43 = Sound_NoteToNoiseControl(pitch) | (REG_NR43 & 8);
            }
            break;
        }
    }
}

/* Original address: 0x020279BC */
void Sound_PlayNote(SoundTrack *track, u8 key, u8 velocity, u16 duration) {
    SoundInstrumentResult result;
    SoundPlayer *player = track->player;
    SoundInstrument *instrument;
    SoundChannel *channel;
    if (track->muted)
        return;
    key += track->transpose;
    Sound_ResolveInstrument(track, key, &result);
    instrument = result.instrument;
    if (instrument->flags & 0x10)
        duration = (u32)duration / player->timing.values.tempo;
    else
        duration = duration / (player->timing.values.tempo_adjust + player->timing.values.tempo);
    if (track->tie && track->channel != NULL) {
        channel = track->channel;
    } else {
        channel = Sound_AllocateChannel(sSoundInstrumentChannelTypes[instrument->type], track, track->priority);
        if (channel == NULL)
            return;
        Sound_AttachChannelToTrack(track, channel);
        channel->age = 0;
        channel->vibrato.params = &track->vibrato;
        channel->vibrato.phase = 0;
        channel->vibrato.delay = track->vibrato.delay;
        channel->envelope.points = result.envelope;
        channel->envelope.volume = 0;
        channel->envelope.target_volume = 0;
        channel->envelope.timer = 0;
        channel->envelope.index = -1;
        channel->release = instrument->release;
        channel->instrument = instrument;
    }
    channel->fixed_pan = result.fixed_pan;
    if (channel->fixed_pan) {
        key = 48;
        channel->pan = result.pan;
    } else if (result.fixed_pitch) {
        key = 48;
    }
    channel->velocity = velocity;
    channel->volume = 0;
    channel->gate_timer = duration;
    channel->unk_1A = track->unk_4C;
    channel->base_pitch = Sound_NoteToPitch(channel, key, instrument->root_key);
    channel->slide.params = &track->slide;
    if (track->slide.enabled) {
        s32 pitch = Sound_NoteToPitch(channel, track->slide.key, instrument->root_key);
        channel->slide.delay = track->slide.delay;
        channel->slide.timer = ((u32)track->slide.duration * duration) >> 8;
        if (track->slide.flags & 2) {
            channel->slide.target = pitch - channel->base_pitch;
        } else {
            channel->slide.target = channel->base_pitch - pitch;
            channel->base_pitch = pitch;
        }
        channel->slide.step = channel->slide.target;
        channel->slide.step /= channel->slide.timer;
        if ((u8)(track->slide.flags & 4))
            track->slide.key = key;
        else
            track->slide.enabled = 0;
        channel->slide.offset = 0;
    } else {
        channel->slide.delay = 0;
        channel->slide.timer = 0;
        channel->slide.offset = 0;
        channel->slide.target = 0;
        channel->slide.step = 0;
    }
    if (channel->type == 0) {
        channel->sample = (SoundSample *)((u8 *)track->sample_offsets + track->sample_offsets[instrument->sample]);
    } else if (channel->type != 3) {
        if (instrument->flags & 1)
            channel->psg.sequence = result.duty_sequence;
        else
            channel->psg.duty = instrument->sample;
    } else {
        channel->psg.wave = result.wave;
    }
    if (duration == 0)
        Sound_ReleaseChannel(channel);
}

/* Original address: 0x02027B94 */
void Sound_ReleaseChannel(SoundChannel *channel) {
    if (channel->state == 1 && channel->track->tie == 0) {
        if (channel->type == 0) {
            Sound_UnlinkChannel(channel);
            channel->state = 2;
            Sound_InsertPcmChannelByPriority(channel);
        } else {
            u16 pitch = channel->pitch;
            u32 release = channel->release;
            if (channel->type == 3) {
                channel->state = 2;
            } else {
                u8 envelope;
                release >>= 5;
                if (release == 0)
                    envelope = 0;
                else
                    envelope = release | (channel->volume << 4);
                switch (channel->type) {
                case 1:
                    REG_NR12 = envelope;
                    REG_SOUND1CNT_X = pitch | 0x8000;
                    REG_NR11 &= 0xC0;
                    break;
                case 2:
                    REG_NR22 = envelope;
                    REG_SOUND2CNT_H = pitch | 0x8000;
                    REG_NR21 &= 0xC0;
                    break;
                case 4:
                    REG_NR42 = envelope;
                    REG_NR44 = 0x80;
                    break;
                }
                channel->state = 0;
            }
        }
        if (channel->fixed_pan == 0)
            channel->pan = channel->track->pan;
        Sound_DetachChannelFromTrack(channel->track, channel);
    }
}

/* Original address: 0x02027C78 */
void Sound_StopChannel(SoundChannel *channel) {
    if (channel->state != 0) {
        switch (channel->type) {
        case 0:
            Sound_UnlinkChannel(channel);
            channel->next = gSoundChannelLists.free_head.next;
            channel->prev = &gSoundChannelLists.free_head;
            gSoundChannelLists.free_head.next->prev = channel;
            gSoundChannelLists.free_head.next = channel;
            break;
        case 1:
            REG_NR12 = 8;
            REG_NR14 = 0xC0;
            break;
        case 2:
            REG_NR22 = 8;
            REG_NR24 = 0xC0;
            break;
        case 3:
            REG_NR30 = 0;
            break;
        case 4:
            REG_NR42 = 8;
            REG_NR44 = 0xC0;
            break;
        }
        Sound_DetachChannelFromTrack(channel->track, channel);
        channel->state = 0;
    }
}

/* Original address: 0x02027D14 */
void Sound_StartPsgChannel(SoundChannel *channel, u8 envelope) {
    u8 duty;
    u8 noise;
    switch (channel->type) {
    case 1:
        REG_NR10 = ((SoundSquareInstrument *)channel->instrument)->sweep;
        REG_SOUND1CNT_X = channel->base_pitch | 0x8000;
        REG_NR12 = envelope;
        if (channel->instrument->flags & 1)
            REG_NR11 = channel->psg.sequence->values[0] << 6;
        else
            REG_NR11 = channel->psg.duty << 6;
        REG_SOUND1CNT_X = channel->base_pitch | 0x8000;
        break;
    case 2:
        REG_NR22 = envelope;
        REG_SOUND2CNT_H = channel->base_pitch | 0x8000;
        REG_NR21 = channel->psg.duty << 6;
        break;
    case 3:
        if (channel->psg.wave != gSoundChannelLists.wave) {
            REG_NR30 = 0;
            CpuSet(channel->psg.wave, (void *)REG_ADDR_WAVE_RAM0, 8);
            gSoundChannelLists.wave = (void *)channel->psg.wave;
        }
        REG_NR30 = 0xC0;
        REG_SOUND3CNT_X = channel->base_pitch | 0x8000;
        REG_NR32 = sPsgWaveVolume[envelope];
        REG_NR31 = 0;
        break;
    case 4:
        REG_NR42 = envelope;
        if (channel->instrument->flags & 1) {
            noise = Sound_NoteToNoiseControl(channel->base_pitch);
            duty = channel->psg.sequence->values[0];
        } else {
            noise = Sound_NoteToNoiseControl(channel->base_pitch);
            duty = channel->psg.duty;
        }
        if (duty != 0)
            noise |= 8;
        REG_NR43 = noise;
        REG_NR44 = 0x80;
        REG_NR41 = 0;
        break;
    }
}

/* Original address: 0x02027E74 */
SoundChannel *Sound_AllocateChannel(u8 type, SoundTrack *track, u8 priority) {
    SoundChannel *channel;
    if (type == 0) {
        SoundChannel *next = gSoundChannelLists.free_head.next;
        if (next != &gSoundChannelLists.free_tail) {
            channel = next;
        } else {
            SoundChannel *active = gSoundChannelLists.active_head.next;
            if (active == &gSoundChannelLists.active_tail ||
                (active->state == 1 && priority < active->priority))
                return NULL;
            channel = active;
            Sound_StopChannel(channel);
        }
        Sound_UnlinkChannel(channel);
        channel->state = 1;
        channel->priority = priority;
        Sound_InsertPcmChannelByPriority(channel);
    } else {
        channel = &gPsgChannels[type - 1];
        if (channel->state == 1 && priority < channel->priority)
            return NULL;
        if (channel->state != 0)
            Sound_StopChannel(channel);
        channel->state = 1;
        channel->priority = priority;
    }
    return channel;
}

/* Original address: 0x02027F0C */
u8 Sound_MixPcmChannel(SoundChannel *channel, u32 volume, u32 pitch, u8 pan) {
    s32 position = channel->age;
    u32 gain = (u16)volume;
    s32 reached_end = 0;
    s32 remaining = 176;
    s16 *left;
    s16 *right;
    u32 left_gain;
    const s8 *samples = (const s8 *)(channel->sample + 1);
    u32 end;
    s16 *stop;

    left = gPcmMixBuffer.samples;
    right = left + 176;
    left_gain = (u16)((127 - pan) * gain) >> 7;
    gain = (u16)(pan * gain) >> 7;
    end = channel->sample->loop_end;
    if (end == 0)
        end = channel->sample->length;
    if ((position + pitch * remaining) >> 8 < end) {
        stop = right;
    } else {
        u32 count = ((end << 8) - position - 1 + pitch) / pitch;
        stop = left + count;
        reached_end = 1;
    }

    if (channel->sample->loop_end == 0 || reached_end == 0) {
        position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
        if (reached_end)
            return 1;
    } else {
        s32 loop_length = channel->sample->loop_end - channel->sample->loop_start;
        loop_length <<= 8;
        position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
        position -= loop_length;
        remaining -= stop - left;
        while (remaining != 0) {
            left = stop;
            right = left + 176;
            if ((position + pitch * remaining) >> 8 < end) {
                stop += remaining;
                reached_end = 0;
            } else {
                u32 count = ((end << 8) - position - 1 + pitch) / pitch;
                stop += count;
                reached_end = 1;
            }
            position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
            if (reached_end)
                position -= loop_length;
            remaining -= stop - left;
        }
    }
    channel->age = position;
    return 0;
}

/* Original address: 0x02028098 */
void Sound_InitKeySampleInstrument(void) {
    sSoundKeySampleInstrument.type = 0;
    sSoundKeySampleInstrument.flags = 0;
    sSoundKeySampleInstrument.sample = 0;
    sSoundKeySampleInstrument.envelope = 0;
    sSoundKeySampleInstrument.release = 0;
    sSoundKeySampleInstrument.root_key = 48;
}

/* Original address: 0x020280B4 */
void Sound_ResolveInstrument(SoundTrack *track, u8 key, SoundInstrumentResult *result) {
    const SoundBank *sound_bank = gSoundBank;
    u32 bank_index = track->player->bank[track->bank];
    const u32 *offsets = sound_bank->instrument_offsets;
    const u8 *bank = (const u8 *)offsets + offsets[bank_index];
    SoundInstrument *instrument = (SoundInstrument *)(bank + ((const u16 *)bank)[track->program]);
    SoundInstrument *resolved;

    result->fixed_pan = 0;
    result->fixed_pitch = 0;
    if (instrument->type & 0xF0) {
        u32 type = instrument->type;
        if (type == 0x10) {
            const SoundKeyInstrument *keys = (const SoundKeyInstrument *)(bank + instrument->sample);
            u8 index = key - ((SoundInstrumentMap *)instrument)->first_key;
            result->fixed_pan = 1;
            result->pan = keys[index].pan;
            result->instrument = (SoundInstrument *)(bank + keys[index].instrument);
            result->envelope = (const SoundEnvelopePoint *)(bank + result->instrument->envelope);
        } else if (type == 0x11) {
            const u16 *samples = (const u16 *)(bank + instrument->sample);
            sSoundKeySampleInstrument.sample = samples[key];
            result->instrument = &sSoundKeySampleInstrument;
            result->envelope = sSoundKeySampleEnvelope;
            result->fixed_pitch = 1;
        } else if (type == 0x12) {
            const SoundInstrumentSplit *split = (const SoundInstrumentSplit *)(bank + instrument->sample);
            while (key > split->last_key)
                split++;
            result->instrument = (SoundInstrument *)(bank + split->instrument);
            result->envelope = (const SoundEnvelopePoint *)(bank + result->instrument->envelope);
        }
    } else {
        result->instrument = instrument;
        result->envelope = (const SoundEnvelopePoint *)(bank + instrument->envelope);
    }
    resolved = result->instrument;
    if (resolved->type == 3)
        result->wave = (const u16 *)(bank + instrument->sample);
    if (resolved->flags & 1)
        result->duty_sequence = (SoundDutySequence *)(bank + resolved->sample);
}

/* Original address: 0x02028190 */
void Sound_InitPlayers(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 8; i++) {
        SoundPlayer *player = &gSoundPlayers[i];
        player->status = 0;
        for (j = 0; j < 10; j++) {
            player->tracks[j] = NULL;
        }
    }
}

/* Original address: 0x020281C4 */
void Sound_ResetPlayerParameters(SoundPlayer *player) {
    player->control.flags &= ~1;
    player->timing.values.tempo = 150;
    player->timing.values.tempo_adjust = 0;
    player->master_volume = 128;
    player->volume = 0x8000;
    player->volume_step = 0;
    player->fade_timer = 0;
    player->target_volume = 0;
    player->tempo_mode = 0;
}

/* Original address: 0x020281FC */
void Sound_UpdatePlayers(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        SoundPlayer *player = &gSoundPlayers[i];

        if (player->status != 0) {
            if (player->fade_timer == 0 && player->status == 2) {
                Sound_StopPlayer(i);
            } else {
                s32 active;
                SoundTrack **track;
                s32 j;

                if (player->fade_timer != 0) {
                    player->volume += player->volume_step;
                    if (--player->fade_timer == 0)
                        player->volume = player->target_volume;
                }
                active = 0;
                track = player->tracks;
                for (j = 0; j < 10; j++) {
                    if (player->tracks[j] != NULL) {
                        if ((u8)Sound_UpdateTrack(player->tracks[j]) == 0) {
                            active = 1;
                        } else {
                            player->tracks[j] = NULL;
                        }
                    }
                }

                if (!active) {
                    Sound_StopPlayer(i);
                }
            }
        }
    }
}
/* Original address: 0x0202828C */
void Sound_StartMusic(s32 player, u32 music) {
    const SoundBank *bank = gSoundBank;
    const u32 *sequences = bank->music_sequence_offsets;
    const u8 *sequence = (const u8 *)sequences + sequences[music];
    const u32 *banks = bank->music_bank_offsets;

    Sound_StartMusicSequence(player, sequence, (const u16 *)((const u8 *)banks + banks[music]));
}
/* Original address: 0x020282B4 */
void Sound_StartEffect(s32 player, u32 group, u32 effect) {
    const SoundBank *bank = gSoundBank;
    const u32 *sequences = bank->effect_sequence_offsets;
    const u8 *sequence = (const u8 *)sequences + sequences[group];
    const u32 *banks = bank->effect_bank_offsets;

    Sound_StartEffectSequence(player, sequence, (const u16 *)((const u8 *)banks + banks[group]), effect);
}

/* Music sequences begin with a signed track count and a halfword offset table. */
typedef struct SoundMusicSequence {
    /* 0x00 */ s8 track_count;
    /* 0x01 */ u8 reserved;
    /* 0x02 */ u16 track_offsets[1];
} SoundMusicSequence;

/* Original address: 0x020282E0 */
void Sound_StartMusicSequence(s32 index, const u8 *sequence, const u16 *bank) {
    SoundPlayer *player = &gSoundPlayers[index];
    const SoundMusicSequence *header;
    const u16 *offsets;
    const u16 *offset;
    s32 count;
    s32 i;

    if (player->status != 0)
        Sound_StopPlayer(index);
    player->sequence = sequence;
    player->bank = bank;
    player->is_sound_effect = 0;
    Sound_ResetPlayerParameters(player);
    header = (const SoundMusicSequence *)player->sequence;
    count = header->track_count;
    offsets = header->track_offsets;
    i = 0;
    if (i < count) {
        offset = offsets;
        do {
            if (*offset != 0) {
                SoundTrack *track = Sound_FindFreeTrack();
                player->tracks[i] = track;
                Sound_StartTrack(track, player, (void *)(player->sequence + *offset));
            }
            offset++;
            i++;
        } while (i < count);
    }
    player->status = 1;
}

/* Original address: 0x02028368 */
void Sound_StartEffectSequence(s32 index, const u8 *sequence, const u16 *bank, u32 effect) {
    SoundPlayer *player = &gSoundPlayers[index];
    SoundTrack *track;

    if (player->status != 0)
        Sound_StopPlayer(index);
    player->sequence = sequence;
    player->bank = bank;
    player->is_sound_effect = 1;
    Sound_ResetPlayerParameters(player);
    track = Sound_FindFreeTrack();
    player->tracks[0] = track;
    Sound_StartTrack(track, player, (void *)(player->sequence + ((const u16 *)player->sequence)[effect]));
    player->status = 1;
}

/* Original address: 0x020283D4 */
void Sound_StopPlayer(s32 index) {
    SoundPlayer *player = &gSoundPlayers[index];
    s32 i;

    if (player->status != 0) {
        for (i = 0; i < 10; i++) {
            Sound_StopTrack(player->tracks[i]);
            player->tracks[i] = NULL;
        }
        player->status = 0;
    }
}

/* Original address: 0x02028410 */
void Sound_FadeOutPlayer(s32 index, s32 frames) {
    SoundPlayer *player = &gSoundPlayers[index];

    if (player->status != 0) {
        player->status = 2;
        player->target_volume = 0;
        player->fade_timer = frames;
        player->volume_step = -player->volume / frames;
    }
}

/* Original address: 0x02028448 */
void Sound_SetPlayerPaused(s32 index, u8 paused) {
    SoundPlayer *players = gSoundPlayers;

    players[index].control.bits.paused = paused;
}

/* Original address: 0x0202846C */
u32 Sound_GetPlayerStatus(s32 arg0) {
    SoundPlayer *player = gSoundPlayers;

    u32 status = (arg0 + player)->status;
    return status;
}

static inline void Sound_ClearTrackOwners(SoundTrack *tracks) {
    u8 *owner = (u8 *)&tracks->player;
    s32 i;

    for (i = 15; i >= 0; i--) {
        owner[0] = 0;
        owner[1] = 0;
        owner[2] = 0;
        owner[3] = 0;
        owner += sizeof(SoundTrack);
    }
}

/* Original address: 0x02028480 */
void Sound_InitTracks(void) {
    Sound_ClearTrackOwners(gSoundTracks);
}

static inline SoundTrack *Sound_FindFreeTrackInPool(SoundTrack *track, SoundTrack *last) {
    do {
        if (track->player == NULL)
            return track;
        track++;
    } while ((s32)track <= (s32)last);
    return NULL;
}

/* Original address: 0x020284A0 */
SoundTrack *Sound_FindFreeTrack(void) {
    return Sound_FindFreeTrackInPool(gSoundTracks, &gSoundTracks[15]);
}

/* Original address: 0x020284C4 */
void Sound_StartTrack(SoundTrack *track, SoundPlayer *player, const u8 *sequence) {
    if (track != NULL) {
        if (track->player != NULL)
            Sound_StopTrack(track);
        track->tick_accumulator = 0;
        track->tie = 0;
        track->muted = 0;
        track->sequence = sequence;
        track->player = player;
        track->channel = NULL;
        Sound_SetTrackBank(track, 0);
        track->pan = 64;
        track->vibrato.delay = 0;
        track->vibrato.speed = 34;
        track->vibrato.depth = 0;
        track->slide.enabled = 0;
        track->slide.flags = 0;
        track->slide.key = 0;
        track->slide.delay = 0;
        track->slide.duration = 0;
        track->volume = 128;
        track->expression = 128;
        track->pitch_bend = 0;
        track->pitch_bend_range = 2;
        track->transpose = 0;
        if (player->is_sound_effect == 1) {
            track->priority = 12;
            track->unk_4C = 127;
            track->unk_53 = 1;
        } else {
            track->priority = 3;
            track->unk_4C = 0;
            track->unk_53 = 0;
        }
        track->note_duration = 127;
        track->velocity = 127;
        track->rest_duration = 0;
        track->stack_pointer = track->return_stack;
    }
}

/* Original address: 0x02028580 */
void Sound_ReleaseTrackChannels(SoundTrack *track) {
    u8 tie;
    SoundChannel *next;
    SoundChannel *channel;

    if (track != NULL) {
        tie = track->tie;
        track->tie = 0;
        channel = track->channel;
        while (channel != NULL) {
            next = channel->track_next;
            Sound_ReleaseChannel(channel);
            channel = next;
        }
        track->tie = tie;
    }
}

/* Original address: 0x020285B0 */
void Sound_StopTrack(SoundTrack *track) {
    if (track != NULL) {
        Sound_ReleaseTrackChannels(track);
        track->player = NULL;
    }
}


/* Original address: 0x03000270 */
extern SoundNoteCallback gSoundNoteCallback;
/* Original address: 0x03000274 */
extern SoundControlCallback gSoundControlCallback;

/* Original address: 0x020285C8 */
s32 Sound_UpdateTrack(SoundTrack *track) {
    SoundPlayer *player;
    u8 command;
    u32 duration;
    u8 velocity;
    u16 offset;

    if (track == NULL || track->player == NULL)
        return 1;
    player = track->player;
    if (player->control.flags & 1) {
        Sound_ReleaseTrackChannels(track);
    } else {
        while (track->tick_accumulator <= 0) {
            command = *track->sequence++;
            if (command <= 0xBF) {
                if (command <= 0x5F) {
                    duration = track->note_duration;
                    velocity = track->velocity;
                } else {
                    duration = Sound_ReadSequenceDuration(track);
                    track->note_duration = duration;
                    velocity = *track->sequence++;
                    track->velocity = velocity;
                    command -= 0x60;
                }
                duration *= 150;
                if (gSoundNoteCallback != NULL && (player->tempo_mode & 1))
                    gSoundNoteCallback(track, command, velocity, duration);
                else
                    Sound_PlayNote(track, command, velocity, duration);
                if (track->unk_53 == 1)
                    track->tick_accumulator += duration;
            } else if (command == 0xC0) {
                duration = track->rest_duration;
                duration *= 150;
                track->tick_accumulator += duration;
            } else if (command == 0xC1) {
                duration = Sound_ReadSequenceDuration(track);
                track->rest_duration = duration;
                duration *= 150;
                track->tick_accumulator += duration;
            } else if ((command & 0xF0) == 0xD0) {
                track->slide.flags = command & 0x0F;
                track->slide.key = *track->sequence + track->transpose;
                track->sequence++;
                track->slide.duration = *track->sequence++;
                if (track->slide.flags & 1) {
                    track->slide.delay = *track->sequence++;
                } else {
                    track->slide.delay = 0;
                }
                track->slide.enabled = 1;
            } else {
                switch (command) {
                case 0xFF: /* Return from a pattern, or end the track. */
                    if (track->stack_pointer == track->return_stack) {
                        Sound_StopTrack(track);
                        return 2;
                    }
                    track->sequence = *--track->stack_pointer;
                    break;
                case 0xE8:
                    track->slide.enabled = 0;
                    break;
                case 0xF0: /* Jump to an offset in the player's sequence. */
                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    track->sequence = player->sequence;
                    track->sequence += offset;
                    break;
                case 0xF4: /* Call a pattern. */
                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    *track->stack_pointer++ = track->sequence;
                    track->sequence = player->sequence;
                    track->sequence += offset;
                    break;
                case 0xC2:
                    track->program = *track->sequence++;
                    break;
                case 0xC7:
                    Sound_SetTrackBank(track, *track->sequence++);
                    break;
                case 0xC3:
                    track->pan = *track->sequence++;
                    break;
                case 0xC4:
                    track->priority = *track->sequence++;
                    break;
                case 0xE0:
                    track->volume = *track->sequence++;
                    break;
                case 0xE1:
                    track->pitch_bend = *track->sequence++;
                    break;
                case 0xE2:
                    track->pitch_bend_range = *track->sequence++;
                    break;
                case 0xE9:
                    track->transpose = *track->sequence++;
                    break;
                case 0xE3:
                    track->unk_4C = *track->sequence++;
                    break;
                case 0xC5:
                case 0xC6:
                    Sound_ReleaseTrackChannels(track);
                    track->tie = command == 0xC5;
                    break;
                case 0xC8:
                    track->unk_53 = 1;
                    break;
                case 0xC9:
                    track->unk_53 = 0;
                    break;
                case 0xCA:
                    if (gSoundControlCallback != NULL)
                        gSoundControlCallback(track, *track->sequence++);
                    else
                        track->sequence++;
                    break;
                case 0xE4:
                    player->timing.values.tempo = *track->sequence++;
                    break;
                case 0xE5:
                    track->vibrato.delay = *track->sequence++;
                    break;
                case 0xE7:
                    track->vibrato.depth = *track->sequence++;
                    break;
                case 0xE6:
                    track->vibrato.speed = *track->sequence++;
                    break;
                case 0xF8: { /* Start another track with the current instrument settings. */
                    u8 index = *track->sequence++;
                    SoundTrack *child;

                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    if (player->tracks[index] == NULL) {
                        child = Sound_FindFreeTrack();
                        player->tracks[index] = child;
                    } else {
                        child = player->tracks[index];
                        Sound_StopTrack(child);
                    }
                    Sound_StartTrack(child, player, player->sequence + offset);
                    child->sample_offsets = track->sample_offsets;
                    child->bank = track->bank;
                    child->program = track->program;
                    child->pan = track->pan;
                    child->unk_4C = track->unk_4C;
                    child->volume = track->volume;
                    child->expression = track->expression;
                    child->priority = track->priority;
                    child->pitch_bend = track->pitch_bend;
                    child->pitch_bend_range = track->pitch_bend_range;
                    child->transpose = track->transpose;
                    break;
                }
                }
            }
        }
        track->tick_accumulator -= player->timing.values.tempo;
        track->tick_accumulator -= player->timing.values.tempo_adjust;
    }
    return 0;
}

/* Original address: 0x02028A34 */
void Sound_AttachChannelToTrack(SoundTrack *track, SoundChannel *channel) {
    if (channel->track == NULL) {
        SoundChannel *next;

        channel->track = track;
        channel->track_prev = NULL;
        next = track->channel;
        channel->track_next = next;
        track->channel = channel;
        if (next != NULL)
            next->track_prev = channel;
    }
}

/* Original address: 0x02028A4C */
void Sound_DetachChannelFromTrack(SoundTrack *track, SoundChannel *channel) {
    if (channel->track != NULL) {
        channel->track = NULL;
        if (channel->track_next != NULL)
            channel->track_next->track_prev = channel->track_prev;
        if (channel->track_prev != NULL)
            channel->track_prev->track_next = channel->track_next;
        else
            track->channel = channel->track_next;
    }
}

/* Original address: 0x02028A74 */
u16 Sound_ReadSequenceDuration(SoundTrack *track) {
    u32 duration = *track->sequence++;

    if (duration & 0x80)
        duration = ((duration & 0x7F) << 8) | *track->sequence++;
    return duration;
}

/* Original address: 0x02028A98 */
void Sound_SetTrackBank(SoundTrack *track, u32 bank) {
    const SoundBank *sound_bank;
    u32 sample;
    const u32 *offsets;

    track->bank = bank;
    track->program = 0;
    sound_bank = gSoundBank;
    sample = sound_bank->sample_indices[track->player->bank[bank]];
    offsets = sound_bank->sample_offsets;
    track->sample_offsets = (const u32 *)((const u8 *)offsets + offsets[sample]);
}

/* Each command is 0x0C bytes; the ring occupies 0x03000278..0x03000577. */
enum SoundCommandType {
    SOUND_COMMAND_START_MUSIC = 0,
    SOUND_COMMAND_START_EFFECT = 1,
    SOUND_COMMAND_FADE_OUT_PLAYER = 2,
    SOUND_COMMAND_SET_PLAYER_PAUSED = 3,
    SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST = 4,
    SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME = 5,
    SOUND_COMMAND_SET_PLAYER_TEMPO_MODE = 6,
    SOUND_COMMAND_SET_TRACKS_MUTED = 7,
    SOUND_COMMAND_SET_TRACKS_EXPRESSION = 9,
    SOUND_COMMAND_SET_TRACKS_PAN = 8,
    SOUND_COMMAND_COMMAND_10 = 10,
    SOUND_COMMAND_CALLBACK = 11,
    SOUND_COMMAND_SET_CONTROL_CALLBACK = 12,
    SOUND_COMMAND_SET_NOTE_CALLBACK = 13,
};

struct SoundCommand {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 reserved;
    /* 0x04 */ union {
        u32 value;
        struct { u16 value; u16 player; } parts;
        void (*callback)(u32);
        SoundControlCallback control_callback;
        SoundNoteCallback note_callback;
    } arg0;
    /* 0x08 */ u32 arg1;
};

/* Original address: 0x03000278 */
extern SoundCommand gSoundCommands[64];
/* Original address: 0x03000584 */
extern SoundCommand *gSoundCommandRead;
/* Original address: 0x03000588 */
extern SoundCommand *gSoundCommandWrite;
/* Original address: 0x0300058C */
extern SoundCommand *gSoundCommandCommitted;
/* Original address: 0x03000590 */
extern SoundCommand *gSoundCommandEnd;

/* Original address: 0x02028ACC */
void Sound_InitCommandQueue(void) {
    gSoundCommandRead = gSoundCommands;
    gSoundCommandWrite = gSoundCommands;
    gSoundCommandCommitted = gSoundCommands;
    gSoundCommandEnd = gSoundCommands + 64;
    gSoundNoteCallback = NULL;
    gSoundControlCallback = NULL;
}

static inline void Sound_AdvanceCommandPointer(SoundCommand **cursor) {
    (*cursor)++;
    if (*cursor == gSoundCommandEnd) {
        *cursor = gSoundCommands;
    }
}

/* Original address: 0x02028B0C */
SoundCommand *Sound_ReadCommand(void) {
    SoundCommand *command = gSoundCommandRead;

    if (command == gSoundCommandCommitted) {
        return NULL;
    } else {
        Sound_AdvanceCommandPointer(&gSoundCommandRead);
        return command;
    }
}

/* Original address: 0x02028B44 */
void Sound_CommitCommands(void) {
    gSoundCommandCommitted = gSoundCommandWrite;
}

/* Original address: 0x02028B58 */
void Sound_QueueStartMusic(u16 player, u16 music) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_START_MUSIC;
    command->arg0.value = player;
    command->arg1 = music;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028B90 */
void Sound_QueueStartEffect(u32 player, u16 group, u16 effect) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_START_EFFECT;
    command->arg0.value = (player << 16) | group;
    command->arg1 = effect;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028BCC */
void Sound_QueueFadeOutPlayer(u16 player, u16 frames) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_FADE_OUT_PLAYER;
    command->arg0.value = player;
    command->arg1 = frames;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C04 */
void Sound_QueueSetPlayerPaused(u16 player, u8 paused) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_PAUSED;
    command->arg0.value = player;
    command->arg1 = paused;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C3C */
void Sound_QueueSetPlayerTempoAdjust(u16 player, s16 adjustment) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST;
    command->arg0.value = player;
    command->arg1 = adjustment;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C74 */
void Sound_QueueSetPlayerMasterVolume(u16 player, u8 volume) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME;
    command->arg0.value = player;
    command->arg1 = volume;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028CAC */
void Sound_QueueSetPlayerTempoMode(u16 player, u8 mode) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_TEMPO_MODE;
    command->arg0.value = player;
    command->arg1 = mode;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028CE4 */
void Sound_QueueSetTracksMuted(u32 player, u32 tracks, u8 muted) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_MUTED;
    command->arg0.value = (player << 16) | muted;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D1C */
void Sound_QueueSetTracksExpression(u32 player, u32 tracks, u8 expression) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_EXPRESSION;
    command->arg0.value = (player << 16) | expression;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D54 */
void Sound_QueueSetTracksPan(u32 player, u32 tracks, u8 pan) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_PAN;
    command->arg0.value = (player << 16) | pan;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D8C */
void Sound_QueueCommand10(u8 value) {
    gSoundCommandWrite->type = SOUND_COMMAND_COMMAND_10;
    gSoundCommandWrite->arg0.value = value;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028DB8 */
void Sound_QueueCallback(void (*callback)(u32), u32 argument) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_CALLBACK;
    command->arg0.callback = callback;
    command->arg1 = argument;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028DE8 */
void Sound_QueueSetControlCallback(SoundControlCallback callback) {
    gSoundCommandWrite->type = SOUND_COMMAND_SET_CONTROL_CALLBACK;
    gSoundCommandWrite->arg0.control_callback = callback;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028E10 */
void Sound_QueueSetNoteCallback(SoundNoteCallback callback) {
    gSoundCommandWrite->type = SOUND_COMMAND_SET_NOTE_CALLBACK;
    gSoundCommandWrite->arg0.note_callback = callback;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028E38 */
void Sound_ProcessCommands(void) {
    SoundCommand *command;

    while ((command = Sound_ReadCommand()) != NULL) {
        switch (command->type) {
        case SOUND_COMMAND_START_MUSIC:
            Sound_StartMusic(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_START_EFFECT:
            Sound_StartEffect(command->arg0.value >> 16, command->arg0.value & 0xFFFF, command->arg1);
            break;
        case SOUND_COMMAND_FADE_OUT_PLAYER:
            Sound_FadeOutPlayer(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_SET_PLAYER_PAUSED:
            Sound_SetPlayerPaused(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_SET_PLAYER_TEMPO_MODE: {
            SoundPlayer *players = gSoundPlayers;
            u8 *tempo_mode = &players[command->arg0.value].tempo_mode;

            *tempo_mode = command->arg1;
            break;
        }
        case SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST: {
            SoundPlayer *players = gSoundPlayers;
            SoundPlayer *player = &players[command->arg0.value];
            u32 adjustment = command->arg1;

            player->timing.bytes.tempo_adjust[0] = adjustment;
            player->timing.bytes.tempo_adjust[1] = adjustment >> 8;
            break;
        }
        case SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME: {
            SoundPlayer *players = gSoundPlayers;
            u8 *master_volume = &players[command->arg0.value].master_volume;

            *master_volume = command->arg1;
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_MUTED: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                track = player->tracks;
                do {
                    if ((command->arg1 & 1) && *track != NULL) {
                        (*track)->muted = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_EXPRESSION: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                track = player->tracks;
                do {
                    if ((command->arg1 & 1) && *track != NULL) {
                        (*track)->expression = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_PAN: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                track = player->tracks;
                do {
                    if ((command->arg1 & 1) && *track != NULL) {
                        (*track)->pan = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_CALLBACK:
            command->arg0.callback(command->arg1);
            break;
        case SOUND_COMMAND_SET_CONTROL_CALLBACK:
            gSoundControlCallback = command->arg0.control_callback;
            break;
        case SOUND_COMMAND_SET_NOTE_CALLBACK:
            gSoundNoteCallback = command->arg0.note_callback;
            break;
        case SOUND_COMMAND_COMMAND_10:
            sub_02027370(command->arg0.value);
            break;
        }
    }
}

/* ARM-state mixer routines copied to IWRAM by SoundDriver_Init. */
asm(".include \"asm/all_arm.inc\"");

/* AGB BIOS wrappers kept in assembly so their SWI sequences remain exact. */
asm(".include \"asm/gflib/syscalls.inc\"");
