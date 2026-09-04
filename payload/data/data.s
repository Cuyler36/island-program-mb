	.include "../asm/macros/function.inc"
	.include "../constants/gba_constants.inc"
	.data
	.syntax unified

.incbin "data/data.bin", 0, 0xA1F4

	.global IslanderSubMoveAction_BuryProcTbl
	.type IslanderSubMoveAction_BuryProcTbl, %object
IslanderSubMoveAction_BuryProcTbl:
	@ [0] Islander_BuryItem_State0, [1] Islander_BuryItem_State1
	@ [2] Islander_BuryItem_State2, [3] Islander_BuryItem_State3
	@ [4] Islander_BuryItem_State4, [5] Islander_BuryItem_State5
	.incbin "data/data.bin", 0xA1F4, 0x18
	.size IslanderSubMoveAction_BuryProcTbl, . - IslanderSubMoveAction_BuryProcTbl

.incbin "data/data.bin", 0xA20C, 0x6480
