	.include "../asm/macros/function.inc"
	.include "../constants/gba_constants.inc"
	.data
	.syntax unified

/* Original address: 0x02029698 */
.global sInitialIntrTable
.type sInitialIntrTable, %object
sInitialIntrTable:
    .incbin "data/data.bin", 0x0, 0x38
.size sInitialIntrTable, . - sInitialIntrTable

.incbin "data/data.bin", 0x38, 0x1648

/* Original address: 0x0202AD18 */
.global gMsgChoiceTemplateParams
.type gMsgChoiceTemplateParams, %object
gMsgChoiceTemplateParams:
    .incbin "data/data.bin", 0x1680, 0x4
.size gMsgChoiceTemplateParams, . - gMsgChoiceTemplateParams


/* Original address: 0x0202AD1C */
.global sFontTileBufferVramDestinations
.type sFontTileBufferVramDestinations, %object
sFontTileBufferVramDestinations:
    .incbin "data/data.bin", 0x1684, 0xC
.size sFontTileBufferVramDestinations, . - sFontTileBufferVramDestinations
/* Original address: 0x0202AD28 */
.global sFontTileBufferSizes
.type sFontTileBufferSizes, %object
sFontTileBufferSizes:
    .incbin "data/data.bin", 0x1690, 0xC
.size sFontTileBufferSizes, . - sFontTileBufferSizes

/* Original address: 0x0202AD34 */
.global sSineTable
.type sSineTable, %object
sSineTable:
    .incbin "data/data.bin", 0x169C, 0x280
.size sSineTable, . - sSineTable

/* Original address: 0x0202AFB4 */
.global sHiddenOamAttributes
.type sHiddenOamAttributes, %object
sHiddenOamAttributes:
    .incbin "data/data.bin", 0x191C, 0x8
.size sHiddenOamAttributes, . - sHiddenOamAttributes


	@ Original address: 0x0202AFBC
	.global sJoybootGbaHandshake
	.type sJoybootGbaHandshake, %object
sJoybootGbaHandshake:
	@ "AAFJ", read as one little-endian word.
	.incbin "data/data.bin", 0x1924, 4
	.size sJoybootGbaHandshake, . - sJoybootGbaHandshake

.incbin "data/data.bin", 0x1928, 4

	@ Original address: 0x0202AFC4
	.global sJoybootGameCubeHandshake
	.type sJoybootGameCubeHandshake, %object
sJoybootGameCubeHandshake:
	@ "GAFJ", compared after swapping the received word.
	.incbin "data/data.bin", 0x192C, 4
	.size sJoybootGameCubeHandshake, . - sJoybootGameCubeHandshake

.incbin "data/data.bin", 0x1930, 0x4C

	@ Original address: 0x0202B014
	.global sTimeOfDayPalette2Table
	.type sTimeOfDayPalette2Table, %object
sTimeOfDayPalette2Table: @ 0x0202B014
	.incbin "data/data.bin", 0x197C, 0x180
	.size sTimeOfDayPalette2Table, . - sTimeOfDayPalette2Table

	@ Original address: 0x0202B194
	.global sTimeOfDayPalette3Table
	.type sTimeOfDayPalette3Table, %object
sTimeOfDayPalette3Table: @ 0x0202B194
	.incbin "data/data.bin", 0x1AFC, 0xF0
	.size sTimeOfDayPalette3Table, . - sTimeOfDayPalette3Table

.incbin "data/data.bin", 0x1BEC, 0x38

	@ Original address: 0x0202B2BC
	.global sIslandProgramModeEnterProcs
	.type sIslandProgramModeEnterProcs, %object
sIslandProgramModeEnterProcs: @ 0x0202B2BC
	@ [0] NULL, [1] normal, [2] field load
	@ [3] mosaic reveal, [4] mosaic cover, [5] message
	.incbin "data/data.bin", 0x1C24, 0x18
	.size sIslandProgramModeEnterProcs, . - sIslandProgramModeEnterProcs

.incbin "data/data.bin", 0x1C3C, 0x28

	@ Original address: 0x0202B2FC
	.global sMsgSpriteProfiles
	.type sMsgSpriteProfiles, %object
sMsgSpriteProfiles:
	.incbin "data/data.bin", 0x1C64, 0x34
	.size sMsgSpriteProfiles, . - sMsgSpriteProfiles

.incbin "data/data.bin", 0x1C98, 0x48

	@ Original address: 0x0202B378
	.global sMsgContinuePromptAnimations
	.type sMsgContinuePromptAnimations, %object
sMsgContinuePromptAnimations:
	.incbin "data/data.bin", 0x1CE0, 4
	.size sMsgContinuePromptAnimations, . - sMsgContinuePromptAnimations

.incbin "data/data.bin", 0x1CE4, 0x60

	@ Original address: 0x0202B3DC
	.global sMsgChoiceCursorAnimations
	.type sMsgChoiceCursorAnimations, %object
sMsgChoiceCursorAnimations:
	.incbin "data/data.bin", 0x1D44, 4
	.size sMsgChoiceCursorAnimations, . - sMsgChoiceCursorAnimations

.incbin "data/data.bin", 0x1D48, 0x1C

	@ Original address: 0x0202B3FC
	.global sIslandRightAcreTilemaps
	.type sIslandRightAcreTilemaps, %object
sIslandRightAcreTilemaps:
	.incbin "data/data.bin", 0x1D64, 0x2000
	.size sIslandRightAcreTilemaps, . - sIslandRightAcreTilemaps

	@ Original address: 0x0202D3FC
	.global sIslandLeftAcreTilemaps
	.type sIslandLeftAcreTilemaps, %object
sIslandLeftAcreTilemaps:
	.incbin "data/data.bin", 0x3D64, 0x2000
	.size sIslandLeftAcreTilemaps, . - sIslandLeftAcreTilemaps

	@ Original address: 0x0202F3FC
	.global sFieldPaletteAnimation0
	.type sFieldPaletteAnimation0, %object
sFieldPaletteAnimation0:
	.incbin "data/data.bin", 0x5D64, 0x200
	.size sFieldPaletteAnimation0, . - sFieldPaletteAnimation0

	@ Original address: 0x0202F5FC
	.global sFieldPaletteAnimation2
	.type sFieldPaletteAnimation2, %object
sFieldPaletteAnimation2:
	.incbin "data/data.bin", 0x5F64, 0x200
	.size sFieldPaletteAnimation2, . - sFieldPaletteAnimation2

.incbin "data/data.bin", 0x6164, 0x420

	@ Original address: 0x0202FC1C
	.global sCabanaTilemap
	.type sCabanaTilemap, %object
sCabanaTilemap:
	.incbin "data/data.bin", 0x6584, 0x80
	.size sCabanaTilemap, . - sCabanaTilemap

	@ Original address: 0x0202FC9C
	.global sIslanderHouseTilemap
	.type sIslanderHouseTilemap, %object
sIslanderHouseTilemap:
	.incbin "data/data.bin", 0x6604, 0x60
	.size sIslanderHouseTilemap, . - sIslanderHouseTilemap

	@ Original address: 0x0202FCFC
	.global sCabanaFootprint
	.type sCabanaFootprint, %object
sCabanaFootprint:
	.incbin "data/data.bin", 0x6664, 0x10
	.size sCabanaFootprint, . - sCabanaFootprint

	@ Original address: 0x0202FD0C
	.global sIslanderHouseFootprint
	.type sIslanderHouseFootprint, %object
sIslanderHouseFootprint:
	.incbin "data/data.bin", 0x6674, 0x9
	.size sIslanderHouseFootprint, . - sIslanderHouseFootprint

.incbin "data/data.bin", 0x667D, 0x1

	@ Original address: 0x0202FD16
	.global sFieldEntityBaseTiles
	.type sFieldEntityBaseTiles, %object
sFieldEntityBaseTiles:
	.incbin "data/data.bin", 0x667E, 0x12
	.size sFieldEntityBaseTiles, . - sFieldEntityBaseTiles

	@ Original address: 0x0202FD28
	.global sIslandFieldUpdateProcs
	.type sIslandFieldUpdateProcs, %object
sIslandFieldUpdateProcs:
	.incbin "data/data.bin", 0x6690, 0x10
	.size sIslandFieldUpdateProcs, . - sIslandFieldUpdateProcs

.incbin "data/data.bin", 0x66A0, 0x8

	@ Original address: 0x0202FD40
	.global sIslandBuildingSprites
	.type sIslandBuildingSprites, %object
sIslandBuildingSprites:
	.incbin "data/data.bin", 0x66A8, 0x78
	.size sIslandBuildingSprites, . - sIslandBuildingSprites

.incbin "data/data.bin", 0x6720, 0xF8

	@ Original address: 0x0202FEB0
	.global sFieldAnimationFrames
	.type sFieldAnimationFrames, %object
sFieldAnimationFrames:
	.incbin "data/data.bin", 0x6818, 0x1C
	.size sFieldAnimationFrames, . - sFieldAnimationFrames

.incbin "data/data.bin", 0x6834, 0x14

	.global gFieldObjectSpriteFrameIndices
	.type gFieldObjectSpriteFrameIndices, %object
gFieldObjectSpriteFrameIndices: @ 0x0202FEE0
	.incbin "data/data.bin", 0x6848, 0x98
	.size gFieldObjectSpriteFrameIndices, . - gFieldObjectSpriteFrameIndices

	.global gFieldObjectSpriteFrames
	.type gFieldObjectSpriteFrames, %object
gFieldObjectSpriteFrames: @ 0x0202FF78
	.incbin "data/data.bin", 0x68E0, 0x180
	.size gFieldObjectSpriteFrames, . - gFieldObjectSpriteFrames

	@ Original address: 0x020300F8
	.global sFruitDropOffsetsX
	.type sFruitDropOffsetsX, %object
sFruitDropOffsetsX:
	.incbin "data/data.bin", 0x6A60, 0x0C
	.size sFruitDropOffsetsX, . - sFruitDropOffsetsX

	@ Original address: 0x02030104
	.global sFruitDropOffsetsY
	.type sFruitDropOffsetsY, %object
sFruitDropOffsetsY:
	.incbin "data/data.bin", 0x6A6C, 0x0C
	.size sFruitDropOffsetsY, . - sFruitDropOffsetsY

	@ Original address: 0x02030110
	.global sFieldObjectInitialTimers
	.type sFieldObjectInitialTimers, %object
sFieldObjectInitialTimers:
	.incbin "data/data.bin", 0x6A78, 0x13
	.size sFieldObjectInitialTimers, . - sFieldObjectInitialTimers

	@ Original address: 0x02030123
	.global sFieldObjectShakeFrames
	.type sFieldObjectShakeFrames, %object
sFieldObjectShakeFrames:
	.incbin "data/data.bin", 0x6A8B, 0x09
	.size sFieldObjectShakeFrames, . - sFieldObjectShakeFrames

.incbin "data/data.bin", 0x6A94, 0x36E0

	@ Original address: 0x0203380C
	.global IslanderMoveProcTable
	.type IslanderMoveProcTable, %object
IslanderMoveProcTable:
	.incbin "data/data.bin", 0xA174, 0x54
	.size IslanderMoveProcTable, . - IslanderMoveProcTable

.incbin "data/data.bin", 0xA1C8, 0x2C

	.global IslanderSubMoveAction_BuryProcTbl
	.type IslanderSubMoveAction_BuryProcTbl, %object
IslanderSubMoveAction_BuryProcTbl:
	@ [0] Islander_BuryItem_State0, [1] Islander_BuryItem_State1
	@ [2] Islander_BuryItem_State2, [3] Islander_BuryItem_State3
	@ [4] Islander_BuryItem_State4, [5] Islander_BuryItem_State5
	.incbin "data/data.bin", 0xA1F4, 0x18
	.size IslanderSubMoveAction_BuryProcTbl, . - IslanderSubMoveAction_BuryProcTbl

.incbin "data/data.bin", 0xA20C, 0x20

	@ Original address: 0x020338C4
	.global sIslanderMoodEmotions
	.type sIslanderMoodEmotions, %object
sIslanderMoodEmotions:
	.incbin "data/data.bin", 0xA22C, 0xE
	.size sIslanderMoodEmotions, . - sIslanderMoodEmotions

	@ Original address: 0x020338D2
	.global sIslanderTreeActionChances
	.type sIslanderTreeActionChances, %object
sIslanderTreeActionChances:
	.incbin "data/data.bin", 0xA23A, 8
	.size sIslanderTreeActionChances, . - sIslanderTreeActionChances

.incbin "data/data.bin", 0xA242, 0x152

	@ Original address: 0x02033A2C
	.global gIslanderMoveCollisionOffsets
	.type gIslanderMoveCollisionOffsets, %object
gIslanderMoveCollisionOffsets:
	.incbin "data/data.bin", 0xA394, 0x40
	.size gIslanderMoveCollisionOffsets, . - gIslanderMoveCollisionOffsets

.incbin "data/data.bin", 0xA3D4, 0x18

	@ Original address: 0x02033A84
	.global sIslanderMoveSteps
	.type sIslanderMoveSteps, %object
sIslanderMoveSteps:
	.incbin "data/data.bin", 0xA3EC, 0x40
	.size sIslanderMoveSteps, . - sIslanderMoveSteps

.incbin "data/data.bin", 0xA42C, 0x6C

	@ Original address: 0x02033B30
	.global sFlyingItemFruitParams
	.type sFlyingItemFruitParams, %object
sFlyingItemFruitParams:
	.incbin "data/data.bin", 0xA498, 0x18
	.size sFlyingItemFruitParams, . - sFlyingItemFruitParams

	@ Original address: 0x02033B48
	.global sFlyingItemParams
	.type sFlyingItemParams, %object
sFlyingItemParams:
	.incbin "data/data.bin", 0xA4B0, 0x280
	.size sFlyingItemParams, . - sFlyingItemParams

	@ Original address: 0x02033DC8
	.global sFloatingItemHourOffsets
	.type sFloatingItemHourOffsets, %object
sFloatingItemHourOffsets:
	.incbin "data/data.bin", 0xA730, 0x18
	.size sFloatingItemHourOffsets, . - sFloatingItemHourOffsets

.incbin "data/data.bin", 0xA748, 0x4

	@ Original address: 0x02033DE4
	.global sFloatingItemBaseIndices
	.type sFloatingItemBaseIndices, %object
sFloatingItemBaseIndices:
	.incbin "data/data.bin", 0xA74C, 0xFC
	.size sFloatingItemBaseIndices, . - sFloatingItemBaseIndices

.incbin "data/data.bin", 0xA848, 0xA0

	@ Original address: 0x02033F80
	.global sIslanderFlowerItems
	.type sIslanderFlowerItems, %object
sIslanderFlowerItems:
	.incbin "data/data.bin", 0xA8E8, 0x12
	.size sIslanderFlowerItems, . - sIslanderFlowerItems

	@ Original address: 0x02033F92
	.global sIslanderRewardAdjust
	.type sIslanderRewardAdjust, %object
sIslanderRewardAdjust:
	.incbin "data/data.bin", 0xA8FA, 0x12
	.size sIslanderRewardAdjust, . - sIslanderRewardAdjust

.incbin "data/data.bin", 0xA90C, 0x544

    @ Original address: 0x020344E8
    .global sFallingFruitUpdateProcs
    .type sFallingFruitUpdateProcs, %object
sFallingFruitUpdateProcs:
    .incbin "data/data.bin", 0xAE50, 0x10
    .size sFallingFruitUpdateProcs, . - sFallingFruitUpdateProcs

    @ Original address: 0x020344F8
    .global sFallingFruitProfiles
    .type sFallingFruitProfiles, %object
sFallingFruitProfiles:
    .incbin "data/data.bin", 0xAE60, 0x228
    .size sFallingFruitProfiles, . - sFallingFruitProfiles

.incbin "data/data.bin", 0xB088, 0xC0

/* Original address: 0x020347E0 */
.global sEntityUpdateProcs
.type sEntityUpdateProcs, %object
sEntityUpdateProcs:
    .incbin "data/data.bin", 0xB148, 0x2C
.size sEntityUpdateProcs, . - sEntityUpdateProcs

.incbin "data/data.bin", 0xB174, 0x418

/* Original address: 0x02034C24 */
.global sEntityToppleFrames
.type sEntityToppleFrames, %object
sEntityToppleFrames:
    .incbin "data/data.bin", 0xB58C, 0x20
.size sEntityToppleFrames, . - sEntityToppleFrames

/* Original address: 0x02034C44 */
.global sEntityLeafFrames
.type sEntityLeafFrames, %object
sEntityLeafFrames:
    .incbin "data/data.bin", 0xB5AC, 0x50
.size sEntityLeafFrames, . - sEntityLeafFrames

.incbin "data/data.bin", 0xB5FC, 0x4C

/* Original address: 0x02034CE0 */
.global sEntityReactionAnimations
.type sEntityReactionAnimations, %object
sEntityReactionAnimations:
    .incbin "data/data.bin", 0xB648, 0x14
.size sEntityReactionAnimations, . - sEntityReactionAnimations

.incbin "data/data.bin", 0xB65C, 0x118

/* Original address: 0x02034E0C */
.global sPlayerHandUpdateProcs
.type sPlayerHandUpdateProcs, %object
sPlayerHandUpdateProcs:
    .incbin "data/data.bin", 0xB774, 0x18
.size sPlayerHandUpdateProcs, . - sPlayerHandUpdateProcs

.incbin "data/data.bin", 0xB78C, 0xB0

/* Original address: 0x02034ED4 */
.global sPlayerHandAnimations
.type sPlayerHandAnimations, %object
sPlayerHandAnimations:
    .incbin "data/data.bin", 0xB83C, 0x10
.size sPlayerHandAnimations, . - sPlayerHandAnimations

.incbin "data/data.bin", 0xB84C, 0x910

.incbin "data/data.bin", 0xC15C, 0x200

/* Original address: 0x020359F4 */
.global sInitialObjPalette
.type sInitialObjPalette, %object
sInitialObjPalette:
    .incbin "data/data.bin", 0xC35C, 0x200
.size sInitialObjPalette, . - sInitialObjPalette

.incbin "data/data.bin", 0xC55C, 0x1C

/* Original address: 0x02035C10 */
.global sSoundEffectTable
.type sSoundEffectTable, %object
sSoundEffectTable:
    .incbin "data/data.bin", 0xC578, 0xAC
.size sSoundEffectTable, . - sSoundEffectTable

/* Original address: 0x02035CBC */
.global sMusicTable
.type sMusicTable, %object
sMusicTable:
    .incbin "data/data.bin", 0xC624, 0x4
.size sMusicTable, . - sMusicTable

.incbin "data/data.bin", 0xC628, 0x4

/* Original address: 0x02035CC4 */
.global sPsgWaveVolume
.type sPsgWaveVolume, %object
sPsgWaveVolume:
    .incbin "data/data.bin", 0xC62C, 0x5
.size sPsgWaveVolume, . - sPsgWaveVolume

.incbin "data/data.bin", 0xC631, 0x3

/* Original address: 0x02035CCC */
.global sSoundInstrumentChannelTypes
.type sSoundInstrumentChannelTypes, %object
sSoundInstrumentChannelTypes:
    .incbin "data/data.bin", 0xC634, 0x5
.size sSoundInstrumentChannelTypes, . - sSoundInstrumentChannelTypes

.incbin "data/data.bin", 0xC639, 0x3

/* Original address: 0x02035CD4 */
.global sSoundKeySampleEnvelope
.type sSoundKeySampleEnvelope, %object
sSoundKeySampleEnvelope:
    .incbin "data/data.bin", 0xC63C, 0xC
.size sSoundKeySampleEnvelope, . - sSoundKeySampleEnvelope

/* Original address: 0x02035CE0 */
.global sPsgPitchTable
.type sPsgPitchTable, %object
sPsgPitchTable:
    .incbin "data/data.bin", 0xC648, 0xF0
.size sPsgPitchTable, . - sPsgPitchTable

/* Original address: 0x02035DD0 */
.global sNoisePitchTable
.type sNoisePitchTable, %object
sNoisePitchTable:
    .incbin "data/data.bin", 0xC738, 0x78
.size sNoisePitchTable, . - sNoisePitchTable

/* Original address: 0x02035E48 */
.global sPcmPitchTable
.type sPcmPitchTable, %object
sPcmPitchTable:
    .incbin "data/data.bin", 0xC7B0, 0x1E0
.size sPcmPitchTable, . - sPcmPitchTable

/* Original address: 0x02036028 */
.global sSoundVibratoWave
.type sSoundVibratoWave, %object
sSoundVibratoWave:
    .incbin "data/data.bin", 0xC990, 0x100
.size sSoundVibratoWave, . - sSoundVibratoWave

.incbin "data/data.bin", 0xCA90, 0x3BFC
