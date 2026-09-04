	.arm
	.align 2, 0

	.global sub_02029004
	.type sub_02029004, %function
sub_02029004:
	push {r4, r5}
	mov r4, #0x7f
	mov r5, #0xff00
	orr r5, r5, #0x80
.Lsub_02029004_loop:
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	ldrsh r3, [r0], #2
	ands ip, r3, r5
	cmpne ip, r5
	addne r3, r4, r3, lsr #31
	strb r3, [r1], #1
	cmp r0, r2
	bne .Lsub_02029004_loop
	pop {r4, r5}
	.word 0xe12fff1e @ bx lr; encoded directly to avoid R_ARM_V4BX
	.size sub_02029004, . - sub_02029004

	.global sub_020290C4
	.type sub_020290C4, %function
sub_020290C4:
	mov ip, sp
	push {r4, r5, r6, r7, r8, sb}
	ldm ip, {r4, r5, r6, r7}
	sub ip, r3, r1
	and ip, ip, #7
	cmp ip, #0
	bne .Lsub_020290C4_remainder
.Lsub_020290C4_loop:
	add ip, r0, r4, lsr #8
	ldrsb r8, [ip]
	mul sb, r8, r6
	ldrsh ip, [r1]
	add ip, ip, sb, asr #8
	strh ip, [r1], #2
	mul sb, r8, r7
	ldrsh ip, [r2]
	add ip, ip, sb, asr #8
	strh ip, [r2], #2
	add r4, r4, r5
	add ip, r0, r4, lsr #8
	ldrsb r8, [ip]
	mul sb, r8, r6
	ldrsh ip, [r1]
	add ip, ip, sb, asr #8
	strh ip, [r1], #2
	mul sb, r8, r7
	ldrsh ip, [r2]
	add ip, ip, sb, asr #8
	strh ip, [r2], #2
	add r4, r4, r5
	add ip, r0, r4, lsr #8
	ldrsb r8, [ip]
	mul sb, r8, r6
	ldrsh ip, [r1]
	add ip, ip, sb, asr #8
	strh ip, [r1], #2
	mul sb, r8, r7
	ldrsh ip, [r2]
	add ip, ip, sb, asr #8
	strh ip, [r2], #2
	add r4, r4, r5
	add ip, r0, r4, lsr #8
	ldrsb r8, [ip]
	mul sb, r8, r6
	ldrsh ip, [r1]
	add ip, ip, sb, asr #8
	strh ip, [r1], #2
	mul sb, r8, r7
	ldrsh ip, [r2]
	add ip, ip, sb, asr #8
	strh ip, [r2], #2
	add r4, r4, r5
	cmp r1, r3
	blo .Lsub_020290C4_loop
	mov r0, r4
	pop {r4, r5, r6, r7, r8, sb}
	.word 0xe12fff1e @ bx lr; encoded directly to avoid R_ARM_V4BX
.Lsub_020290C4_remainder:
	add ip, r0, r4, lsr #8
	ldrsb r8, [ip]
	mul sb, r8, r6
	ldrsh ip, [r1]
	add ip, ip, sb, asr #8
	strh ip, [r1], #2
	mul sb, r8, r7
	ldrsh ip, [r2]
	add ip, ip, sb, asr #8
	strh ip, [r2], #2
	add r4, r4, r5
	cmp r1, r3
	blo .Lsub_020290C4_remainder
	mov r0, r4
	pop {r4, r5, r6, r7, r8, sb}
	.word 0xe12fff1e @ bx lr; encoded directly to avoid R_ARM_V4BX
	.size sub_020290C4, . - sub_020290C4

	.global sub_020291E4
	.type sub_020291E4, %function
sub_020291E4:
	push {r4, r5}
	mov r4, #1
	sub ip, r3, #1
	lsl r4, r4, ip
.Lsub_020291E4_loop:
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	ldrsh r5, [r0]
	ldrsh ip, [r1]
	add r5, r5, ip
	strh r5, [r0], #2
	add ip, ip, r4
	asr ip, ip, r3
	strh ip, [r1], #2
	cmp r0, r2
	blo .Lsub_020291E4_loop
	pop {r4, r5}
	.word 0xe12fff1e @ bx lr; encoded directly to avoid R_ARM_V4BX
	.size sub_020291E4, . - sub_020291E4

	.thumb
