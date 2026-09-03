	.include "../asm/macros/function.inc"
	.text
	.syntax unified

	thumb_func_start __umodsi3
__umodsi3: @ 0x02029524
	cmp r1, #0
	beq _020295DA
	movs r3, #1
	cmp r0, r1
	bhs _02029530
	mov pc, lr
_02029530:
	push {r4}
	movs r4, #1
	lsls r4, r4, #0x1c
_02029536:
	cmp r1, r4
	bhs _02029544
	cmp r1, r0
	bhs _02029544
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _02029536
_02029544:
	lsls r4, r4, #3
_02029546:
	cmp r1, r4
	bhs _02029554
	cmp r1, r0
	bhs _02029554
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _02029546
_02029554:
	movs r2, #0
	cmp r0, r1
	blo _0202955C
	subs r0, r0, r1
_0202955C:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0202956E
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_0202956E:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _02029580
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_02029580:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _02029592
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
_02029592:
	mov ip, r3
	cmp r0, #0
	beq _020295A0
	lsrs r3, r3, #4
	beq _020295A0
	lsrs r1, r1, #4
	b _02029554
_020295A0:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	bne _020295AC
	pop {r4}
	mov pc, lr
_020295AC:
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq _020295BA
	lsrs r4, r1, #3
	adds r0, r0, r4
_020295BA:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq _020295C8
	lsrs r4, r1, #2
	adds r0, r0, r4
_020295C8:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq _020295D6
	lsrs r4, r1, #1
	adds r0, r0, r4
_020295D6:
	pop {r4}
	mov pc, lr
_020295DA:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	thumb_func_end __umodsi3
	.align 2, 0
