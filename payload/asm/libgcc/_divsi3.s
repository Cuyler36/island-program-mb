	.include "../asm/macros/function.inc"
	.text
	.syntax unified

	thumb_func_start __divsi3
__divsi3: @ 0x02029344
	cmp r1, #0
	beq _020293CC
	push {r4}
	adds r4, r0, #0
	eors r4, r1
	mov ip, r4
	movs r3, #1
	movs r2, #0
	cmp r1, #0
	bpl _0202935A
	rsbs r1, r1, #0
_0202935A:
	cmp r0, #0
	bpl _02029360
	rsbs r0, r0, #0
_02029360:
	cmp r0, r1
	blo _020293BE
	movs r4, #1
	lsls r4, r4, #0x1c
_02029368:
	cmp r1, r4
	bhs _02029376
	cmp r1, r0
	bhs _02029376
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _02029368
_02029376:
	lsls r4, r4, #3
_02029378:
	cmp r1, r4
	bhs _02029386
	cmp r1, r0
	bhs _02029386
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _02029378
_02029386:
	cmp r0, r1
	blo _0202938E
	subs r0, r0, r1
	orrs r2, r3
_0202938E:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0202939A
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_0202939A:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _020293A6
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_020293A6:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _020293B2
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_020293B2:
	cmp r0, #0
	beq _020293BE
	lsrs r3, r3, #4
	beq _020293BE
	lsrs r1, r1, #4
	b _02029386
_020293BE:
	adds r0, r2, #0
	mov r4, ip
	cmp r4, #0
	bpl _020293C8
	rsbs r0, r0, #0
_020293C8:
	pop {r4}
	mov pc, lr
_020293CC:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	thumb_func_end __divsi3
	.align 2, 0
