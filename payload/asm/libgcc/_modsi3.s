	.include "../asm/macros/function.inc"
	.text
	.syntax unified

	thumb_func_start __modsi3
__modsi3: @ 0x020293DC
	movs r3, #1
	cmp r1, #0
	beq _020294A0
	bpl _020293E6
	rsbs r1, r1, #0
_020293E6:
	push {r4}
	push {r0}
	cmp r0, #0
	bpl _020293F0
	rsbs r0, r0, #0
_020293F0:
	cmp r0, r1
	blo _02029494
	movs r4, #1
	lsls r4, r4, #0x1c
_020293F8:
	cmp r1, r4
	bhs _02029406
	cmp r1, r0
	bhs _02029406
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _020293F8
_02029406:
	lsls r4, r4, #3
_02029408:
	cmp r1, r4
	bhs _02029416
	cmp r1, r0
	bhs _02029416
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _02029408
_02029416:
	movs r2, #0
	cmp r0, r1
	blo _0202941E
	subs r0, r0, r1
_0202941E:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _02029430
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_02029430:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _02029442
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_02029442:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _02029454
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_02029454:
	mov ip, r3
	cmp r0, #0
	beq _02029462
	lsrs r3, r3, #4
	beq _02029462
	lsrs r1, r1, #4
	b _02029416
_02029462:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	beq _02029494
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq _02029478
	lsrs r4, r1, #3
	adds r0, r0, r4
_02029478:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq _02029486
	lsrs r4, r1, #2
	adds r0, r0, r4
_02029486:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq _02029494
	lsrs r4, r1, #1
	adds r0, r0, r4
_02029494:
	pop {r4}
	cmp r4, #0
	bpl _0202949C
	rsbs r0, r0, #0
_0202949C:
	pop {r4}
	mov pc, lr
_020294A0:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	thumb_func_end __modsi3
	.align 2, 0
