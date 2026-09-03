	.include "../asm/macros/function.inc"
	.text
	.syntax unified

	thumb_func_start __udivsi3
__udivsi3: @ 0x020294AC
	cmp r1, #0
	beq _0202951A
	movs r3, #1
	movs r2, #0
	push {r4}
	cmp r0, r1
	blo _02029514
	movs r4, #1
	lsls r4, r4, #0x1c
_020294BE:
	cmp r1, r4
	bhs _020294CC
	cmp r1, r0
	bhs _020294CC
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _020294BE
_020294CC:
	lsls r4, r4, #3
_020294CE:
	cmp r1, r4
	bhs _020294DC
	cmp r1, r0
	bhs _020294DC
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _020294CE
_020294DC:
	cmp r0, r1
	blo _020294E4
	subs r0, r0, r1
	orrs r2, r3
_020294E4:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _020294F0
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_020294F0:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _020294FC
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_020294FC:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _02029508
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_02029508:
	cmp r0, #0
	beq _02029514
	lsrs r3, r3, #4
	beq _02029514
	lsrs r1, r1, #4
	b _020294DC
_02029514:
	adds r0, r2, #0
	pop {r4}
	mov pc, lr
_0202951A:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	thumb_func_end __udivsi3
	.align 2, 0
