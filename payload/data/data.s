	.include "../asm/macros/function.inc"
	.include "../constants/gba_constants.inc"
	.data
	.syntax unified

.incbin "data/data.bin", 0, 0x1924

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

.incbin "data/data.bin", 0x1C3C, 0x4C0C

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

.incbin "data/data.bin", 0x6A60, 0x3794

	.global IslanderSubMoveAction_BuryProcTbl
	.type IslanderSubMoveAction_BuryProcTbl, %object
IslanderSubMoveAction_BuryProcTbl:
	@ [0] Islander_BuryItem_State0, [1] Islander_BuryItem_State1
	@ [2] Islander_BuryItem_State2, [3] Islander_BuryItem_State3
	@ [4] Islander_BuryItem_State4, [5] Islander_BuryItem_State5
	.incbin "data/data.bin", 0xA1F4, 0x18
	.size IslanderSubMoveAction_BuryProcTbl, . - IslanderSubMoveAction_BuryProcTbl

.incbin "data/data.bin", 0xA20C, 0x2E

	@ Original address: 0x020338D2
	.global sIslanderTreeActionChances
	.type sIslanderTreeActionChances, %object
sIslanderTreeActionChances:
	.incbin "data/data.bin", 0xA23A, 8
	.size sIslanderTreeActionChances, . - sIslanderTreeActionChances

.incbin "data/data.bin", 0xA242, 0x1AA

	@ Original address: 0x02033A84
	.global sIslanderMoveSteps
	.type sIslanderMoveSteps, %object
sIslanderMoveSteps:
	.incbin "data/data.bin", 0xA3EC, 0x40
	.size sIslanderMoveSteps, . - sIslanderMoveSteps

.incbin "data/data.bin", 0xA42C, 0x6260
