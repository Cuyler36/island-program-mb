	.include "../asm/macros/function.inc"
	.include "../constants/gba_constants.inc"
	.text
	.syntax unified

	thumb_func_start AgbMain
AgbMain: @ 0x0201820C
	push {lr}
	bl sub_02019E88
	ldr r1, _02018224 @ =0x03000000
	movs r0, #0xe6
	lsls r0, r0, #6
	str r0, [r1]
	bl sub_0201A0D4
	pop {r0}
	bx r0
	.align 2, 0
_02018224: .4byte 0x03000000

	thumb_func_start sub_02018228
sub_02018228: @ 0x02018228
	bx lr
	.align 2, 0

	thumb_func_start sub_0201822C
sub_0201822C: @ 0x0201822C
	push {r4, r5, r6, lr}
	bl sub_02019D28
	ldr r4, _0201833C @ =0x03001B50
	ldr r0, _02018340 @ =0x0000085A
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bne _02018246
	movs r0, #0
	strb r0, [r1]
	bl sub_02027040
_02018246:
	ldr r1, _02018344 @ =0x0000085F
	adds r6, r4, r1
	ldrb r5, [r6]
	cmp r5, #0
	bne _0201831A
	ldr r0, _02018348 @ =0x03002410
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _0201834C @ =0x0000082A
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #0x10
	adds r2, #0x12
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #0x34
	subs r2, #0x2e
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #4
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #0x48
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _02018350 @ =0x00000859
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bne _0201830C
	strb r5, [r1]
_0201830C:
	ldr r1, _02018354 @ =0x0000085B
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
_0201831A:
	ldr r2, _02018358 @ =0x04000202
	ldr r0, _0201833C @ =0x03001B50
	ldr r1, _0201835C @ =0x00000814
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r1, #1
	strh r1, [r0]
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r1, _02018360 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	bl sub_02019D40
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201833C: .4byte 0x03001B50
_02018340: .4byte 0x0000085A
_02018344: .4byte 0x0000085F
_02018348: .4byte 0x03002410
_0201834C: .4byte 0x0000082A
_02018350: .4byte 0x00000859
_02018354: .4byte 0x0000085B
_02018358: .4byte 0x04000202
_0201835C: .4byte 0x00000814
_02018360: .4byte 0x04000004

	thumb_func_start sub_02018364
sub_02018364: @ 0x02018364
	bx lr
	.align 2, 0

	thumb_func_start sub_02018368
sub_02018368: @ 0x02018368
	bx lr
	.align 2, 0

	thumb_func_start mFont_GetGlyphRows
mFont_GetGlyphRows: @ 0x0201836C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov ip, r0
	mov r8, r1
	lsls r2, r2, #0x18
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsrs r7, r2, #0x18
	movs r1, #0x81
	lsls r1, r1, #0x18
	adds r0, r2, r1
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0201839E
	cmp r7, #0xcd
	bne _020183AA
_0201839E:
	movs r0, #0
	movs r1, #0
	mov r2, ip
	str r0, [r2]
	str r1, [r2, #4]
	b _02018402
_020183AA:
	lsrs r1, r2, #0x1c
	lsls r1, r1, #5
	movs r0, #0xf
	ands r0, r7
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _020183D4 @ =0x020298D0
	mov r4, sp
	ldr r6, _020183D8 @ =0x0202A8D0
	add r3, sp, #8
	adds r0, r2, #0
	adds r0, #0x80
	adds r5, r1, r0
	adds r1, r1, r2
	movs r2, #7
_020183C8:
	cmp r7, #0x20
	beq _020183DC
	ldrb r0, [r1]
	strb r0, [r3]
	ldrb r0, [r5]
	b _020183E2
	.align 2, 0
_020183D4: .4byte 0x020298D0
_020183D8: .4byte 0x0202A8D0
_020183DC:
	ldrb r0, [r6]
	strb r0, [r3]
	ldrb r0, [r6, #8]
_020183E2:
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	adds r3, #1
	adds r5, #1
	adds r1, #1
	subs r2, #1
	cmp r2, #0
	bge _020183C8
	ldr r0, [sp]
	ldr r1, [sp, #4]
	mov r2, ip
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
_02018402:
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start mFont_GetGlyphWidth
mFont_GetGlyphWidth: @ 0x02018414
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xff
	bls _02018422
	movs r0, #1
	rsbs r0, r0, #0
	b _02018428
_02018422:
	ldr r0, _0201842C @ =0x020296D0
	adds r0, r1, r0
	ldrb r0, [r0]
_02018428:
	pop {r1}
	bx r1
	.align 2, 0
_0201842C: .4byte 0x020296D0

	thumb_func_start mFont_GetCodeWidth
mFont_GetCodeWidth: @ 0x02018430
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xff
	bls _0201843E
	movs r0, #1
	rsbs r0, r0, #0
	b _02018444
_0201843E:
	ldr r0, _02018448 @ =0x020297D0
	adds r0, r1, r0
	ldrb r0, [r0]
_02018444:
	pop {r1}
	bx r1
	.align 2, 0
_02018448: .4byte 0x020297D0

	thumb_func_start mMsg_MainSetup_Hide
mMsg_MainSetup_Hide: @ 0x0201844C
	push {lr}
	ldr r1, [r0, #0x54]
	ldr r2, [r0, #0x50]
	bl mMsg_InitWindow
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_Main_Hide
mMsg_Main_Hide: @ 0x0201845C
	push {lr}
	bl mMsg_MainSetup_Window
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_MainSetup_Appear
mMsg_MainSetup_Appear: @ 0x02018468
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl mMsg_LoadMessage
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _020184B4
	adds r1, #0xe
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0x71
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x6c
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl mMsg_ClearText
	movs r0, #0x1f
	bl sub_02019D78
_020184B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_Main_Appear
mMsg_Main_Appear: @ 0x020184BC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x76
	adds r0, r4, #0
	bl mMsg_GetWindowScrollOffset
	ldr r1, _020184F0 @ =0x03001B50
	ldr r2, _020184F4 @ =0x0000084A
	adds r1, r1, r2
	strh r0, [r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	ble _020184F8
	adds r0, r5, #0
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _020184F8
	adds r0, r5, #0
	bl mMsg_MainSetup_Window
	b _02018502
	.align 2, 0
_020184F0: .4byte 0x03001B50
_020184F4: .4byte 0x0000084A
_020184F8:
	adds r1, r5, #0
	adds r1, #0x76
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_02018502:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start mMsg_Cont_SetNextMessage
mMsg_Cont_SetNextMessage: @ 0x02018508
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r3, #0x54]
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r1, r1, #8
	ldrb r0, [r0, #3]
	orrs r1, r0
	cmp r2, #0xff
	beq _0201852C
	adds r0, r3, #0
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r2, r0
	bne _0201853C
_0201852C:
	cmp r1, #0x1e
	bhi _02018534
	str r1, [r3, #0x58]
	b _0201853C
_02018534:
	adds r1, r3, #0
	adds r1, #0x7b
	movs r0, #1
	strb r0, [r1]
_0201853C:
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r3, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_SetChoiceCount
mMsg_Cont_SetChoiceCount: @ 0x0201855C
	push {r4, lr}
	adds r4, r1, #0
	adds r1, r0, #0
	adds r1, #0x7f
	strb r2, [r1]
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetChoiceText
mMsg_Cont_SetChoiceText: @ 0x02018584
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r4, r4, #3
	adds r4, r5, r4
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	strb r0, [r4, #0x12]
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	adds r0, #3
	adds r1, r4, #0
	adds r1, #8
	ldrb r2, [r4, #0x12]
	bl mMsg_Copy
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0x78
	ldrb r0, [r0]
	str r0, [r4, #4]
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_Last
mMsg_Cont_Last: @ 0x020185E4
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x68]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _02018604
	ldr r0, _02018600 @ =0xFFFFFEFF
	ands r1, r0
	str r1, [r2, #0x68]
	movs r0, #2
	b _0201860A
	.align 2, 0
_02018600: .4byte 0xFFFFFEFF
_02018604:
	orrs r1, r3
	str r1, [r2, #0x68]
	movs r0, #3
_0201860A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_Continue
mMsg_Cont_Continue: @ 0x02018610
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x68]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _02018630
	ldr r0, _0201862C @ =0xFFFFFEFF
	ands r1, r0
	str r1, [r2, #0x68]
	movs r0, #2
	b _02018636
	.align 2, 0
_0201862C: .4byte 0xFFFFFEFF
_02018630:
	orrs r1, r3
	str r1, [r2, #0x68]
	movs r0, #3
_02018636:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_Clear
mMsg_Cont_Clear: @ 0x0201863C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl mMsg_ClearText
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_Button
mMsg_Cont_Button: @ 0x02018664
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r1, [r2, #0x68]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _0201869C
	ldr r0, _02018698 @ =0xFFFFFEFF
	ands r1, r0
	str r1, [r2, #0x68]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #2
	b _020186A2
	.align 2, 0
_02018698: .4byte 0xFFFFFEFF
_0201869C:
	orrs r1, r3
	str r1, [r2, #0x68]
	movs r0, #3
_020186A2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetNextMessageF
mMsg_Cont_SetNextMessageF: @ 0x020186A8
	push {lr}
	adds r3, r0, #0
	adds r3, #0x79
	movs r2, #1
	strb r2, [r3]
	movs r2, #0xff
	bl mMsg_Cont_SetNextMessage
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetNextMessage0
mMsg_Cont_SetNextMessage0: @ 0x020186BC
	push {lr}
	movs r2, #0
	bl mMsg_Cont_SetNextMessage
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetNextMessage1
mMsg_Cont_SetNextMessage1: @ 0x020186C8
	push {lr}
	movs r2, #1
	bl mMsg_Cont_SetNextMessage
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetTemporaryColor
mMsg_Cont_SetTemporaryColor: @ 0x020186D4
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	adds r1, r2, #0
	adds r1, #0x7e
	strb r0, [r1]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	adds r1, r2, #0
	adds r1, #0x7d
	strb r0, [r1]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_Space
mMsg_Cont_Space: @ 0x02018718
	push {r4, lr}
	adds r4, r1, #0
	adds r3, r0, #0
	adds r3, #0x78
	movs r1, #0
	ldrsh r2, [r4, r1]
	ldr r1, [r0, #0x54]
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	ldrb r2, [r3]
	adds r1, r1, r2
	strb r1, [r3]
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_MoveDown
mMsg_Cont_MoveDown: @ 0x02018750
	push {r4, lr}
	adds r4, r1, #0
	adds r2, r0, #0
	adds r2, #0x74
	ldrb r1, [r2]
	adds r1, #1
	strb r1, [r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_RestoreCachedMessage
mMsg_Cont_RestoreCachedMessage: @ 0x0201877C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0
	mov sl, r0
	movs r1, #0x77
	adds r1, r1, r7
	mov sb, r1
	movs r3, #0
	ldr r2, _02018808 @ =0x0202A8E0
_0201879A:
	ldr r1, [r2]
	ldr r0, [r7, #0x5c]
	cmp r1, r0
	bne _02018810
	ldr r4, _0201880C @ =0x03002A20
	mov r8, r4
	adds r0, r3, r4
	cmp r0, r7
	beq _02018810
	ldr r4, [r7, #0x50]
	ldr r5, [r7, #0x54]
	mov r1, sb
	ldrb r6, [r1]
	adds r1, r7, #0
	movs r2, #0x28
	str r3, [sp, #4]
	bl CpuFastSet
	str r4, [r7, #0x50]
	str r5, [r7, #0x54]
	mov r2, sb
	strb r6, [r2]
	adds r1, r7, #0
	adds r1, #0x7c
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	adds r0, #0x54
	ldr r3, [sp, #4]
	adds r0, r3, r0
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	adds r2, r7, #0
	adds r2, #0x6e
	movs r4, #0
	ldrsh r2, [r2, r4]
	bl mMsg_Copy
	mov r0, r8
	adds r0, #0x50
	ldr r3, [sp, #4]
	adds r0, r3, r0
	ldr r0, [r0]
	ldr r1, [r7, #0x50]
	movs r2, #0x90
	lsls r2, r2, #3
	bl CpuFastSet
	ldr r2, [r7, #0x50]
	movs r0, #0
	movs r1, #0x90
	bl mMsg_CopyTilesToVram
	b _0201881E
	.align 2, 0
_02018808: .4byte 0x0202A8E0
_0201880C: .4byte 0x03002A20
_02018810:
	adds r3, #0xa0
	adds r2, #4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #8
	ble _0201879A
_0201881E:
	mov r2, sl
	cmp r2, #9
	bne _0201883C
	ldr r4, [sp]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
_0201883C:
	movs r0, #1
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_SetChoiceCount2
mMsg_Cont_SetChoiceCount2: @ 0x02018850
	push {lr}
	movs r2, #2
	bl mMsg_Cont_SetChoiceCount
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetChoiceCount3
mMsg_Cont_SetChoiceCount3: @ 0x0201885C
	push {lr}
	movs r2, #3
	bl mMsg_Cont_SetChoiceCount
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetChoiceText0
mMsg_Cont_SetChoiceText0: @ 0x02018868
	push {lr}
	movs r2, #0
	bl mMsg_Cont_SetChoiceText
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetChoiceText1
mMsg_Cont_SetChoiceText1: @ 0x02018874
	push {lr}
	movs r2, #1
	bl mMsg_Cont_SetChoiceText
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_SetChoiceText2
mMsg_Cont_SetChoiceText2: @ 0x02018880
	push {lr}
	movs r2, #2
	bl mMsg_Cont_SetChoiceText
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_CheckChoice
mMsg_Cont_CheckChoice: @ 0x0201888C
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r5, #3
	movs r1, #0
	ldrsh r2, [r4, r1]
	ldr r1, [r0, #0x54]
	adds r2, r1, r2
	ldrb r1, [r2, #2]
	adds r0, #0x80
	ldrb r0, [r0]
	adds r0, #1
	cmp r1, r0
	bne _020188AA
	movs r5, #2
	b _020188BA
_020188AA:
	adds r0, r2, #0
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
_020188BA:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Cont_SoundTrgSys
mMsg_Cont_SoundTrgSys: @ 0x020188C4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	ldrb r1, [r1, #2]
	subs r0, r1, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _020188EA
	movs r0, #2
	cmp r1, #7
	bne _020188E6
	movs r0, #0x10
_020188E6:
	bl sub_02019D78
_020188EA:
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #3
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Cont_Noop
mMsg_Cont_Noop: @ 0x02018908
	push {r4, lr}
	adds r4, r1, #0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_ProcessControlCode
mMsg_ProcessControlCode: @ 0x0201892C
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r2, #1
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r3, #0x54]
	adds r1, r1, r0
	ldrb r0, [r1]
	ldrb r1, [r1, #1]
	cmp r0, #0x7f
	bne _0201895A
	cmp r1, #0x70
	bhi _0201895A
	ldr r0, _02018964 @ =0x0202A904
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	adds r0, r3, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r2, r0, #0
_0201895A:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_02018964: .4byte 0x0202A904

	thumb_func_start mMsg_MainSetup_Cursor
mMsg_MainSetup_Cursor: @ 0x02018968
	adds r2, r0, #0
	adds r2, #0x71
	ldrb r1, [r2]
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r2]
	bx lr

	thumb_func_start mMsg_Main_Cursor
mMsg_Main_Cursor: @ 0x02018978
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r6, _020189B8 @ =0x0300001C
	adds r7, r4, #0
	adds r7, #0x74
	ldrb r0, [r7]
	strb r0, [r6]
	ldr r0, _020189BC @ =0x0300001D
	mov r8, r0
	adds r5, r4, #0
	adds r5, #0x78
	ldrb r0, [r5]
	mov r1, r8
	strb r0, [r1]
	ldr r1, [r4, #0x50]
	adds r0, r4, #0
	movs r2, #1
	bl mMsg_ProcessText
	cmp r0, #2
	beq _020189C0
	cmp r0, #4
	bne _020189D6
	adds r0, r4, #0
	bl mMsg_RequestChoice
	b _020189C6
	.align 2, 0
_020189B8: .4byte 0x0300001C
_020189BC: .4byte 0x0300001D
_020189C0:
	adds r0, r4, #0
	bl mMsg_RequestNormal
_020189C6:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _020189CE
	b _02018AC2
_020189CE:
	adds r0, r4, #0
	bl mMsg_MainSetup_Window
	b _02018AC2
_020189D6:
	ldrb r1, [r6]
	movs r0, #0
	ldrsb r0, [r7, r0]
	mov sl, r5
	cmp r1, r0
	bge _02018A58
	ldr r2, _02018AD0 @ =0x03000010
	mov sb, r2
	adds r5, r4, #0
	adds r5, #0x73
	mov r7, r8
	ldr r3, _02018AD4 @ =0x03000014
	mov r8, r3
_020189F0:
	ldrb r1, [r6]
	movs r0, #0
	ldrsb r0, [r5, r0]
	muls r1, r0, r1
	ldrb r0, [r7]
	lsrs r0, r0, #3
	adds r3, r1, r0
	mov r0, sb
	str r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #3
	ldrb r1, [r7]
	subs r0, r0, r1
	adds r1, r0, #7
	cmp r1, #0
	bge _02018A14
	adds r1, #7
_02018A14:
	asrs r1, r1, #3
	mov r2, r8
	str r1, [r2]
	ldr r2, [r4, #0x50]
	adds r0, r3, #0
	bl mMsg_CopyTilesToVram
	movs r1, #0
	ldrsb r1, [r5, r1]
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	mov r2, r8
	ldr r1, [r2]
	ldr r2, [r4, #0x50]
	bl mMsg_CopyTilesToVram
	adds r0, r4, #0
	adds r0, #0x75
	ldrb r0, [r0]
	strb r0, [r7]
	ldrb r0, [r6]
	adds r0, #2
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r6]
	ldrb r1, [r6]
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _020189F0
_02018A58:
	ldr r2, _02018AD8 @ =0x0300001D
	ldrb r0, [r2]
	mov r3, sl
	ldrb r3, [r3]
	cmp r0, r3
	beq _02018AC2
	ldr r7, _02018AD0 @ =0x03000010
	mov r8, r7
	adds r0, r4, #0
	adds r0, #0x74
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r4, #0
	adds r5, #0x73
	movs r0, #0
	ldrsb r0, [r5, r0]
	muls r1, r0, r1
	ldrb r0, [r2]
	lsrs r0, r0, #3
	adds r3, r1, r0
	mov r0, r8
	str r3, [r0]
	ldr r6, _02018AD4 @ =0x03000014
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r0, #3
	mov r7, sl
	ldrb r0, [r7]
	ldrb r2, [r2]
	cmp r0, r1
	ble _02018A98
	adds r0, r1, #0
_02018A98:
	str r0, [r6]
	subs r0, r0, r2
	adds r1, r0, #7
	cmp r1, #0
	bge _02018AA4
	adds r1, #7
_02018AA4:
	asrs r1, r1, #3
	str r1, [r6]
	ldr r2, [r4, #0x50]
	adds r0, r3, #0
	bl mMsg_CopyTilesToVram
	movs r1, #0
	ldrsb r1, [r5, r1]
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [r6]
	ldr r2, [r4, #0x50]
	bl mMsg_CopyTilesToVram
_02018AC2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02018AD0: .4byte 0x03000010
_02018AD4: .4byte 0x03000014
_02018AD8: .4byte 0x0300001D

	thumb_func_start mMsg_CheckAdvanceInput
mMsg_CheckAdvanceInput: @ 0x02018ADC
	ldr r0, _02018AEC @ =0x03001B50
	ldr r1, _02018AF0 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	bx lr
	.align 2, 0
_02018AEC: .4byte 0x03001B50
_02018AF0: .4byte 0x0000081A

	thumb_func_start mMsg_MainSetup_Normal
mMsg_MainSetup_Normal: @ 0x02018AF4
	ldr r1, [r0, #0x68]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0x68]
	adds r2, r0, #0
	adds r2, #0x71
	ldrb r1, [r2]
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r2]
	bx lr
	.align 2, 0

	thumb_func_start mMsg_Main_Normal
mMsg_Main_Normal: @ 0x02018B10
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	bl mMsg_EndTimerDec
	cmp r0, #1
	bne _02018B32
	ldr r0, [r5, #0x54]
	adds r1, r5, #0
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #0x58
	bl mMsg_CheckControlCode
	cmp r0, #0
	bne _02018C02
_02018B32:
	bl mMsg_CheckAdvanceInput
	cmp r0, #0
	bne _02018B44
	adds r0, r5, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #1
	bne _02018C30
_02018B44:
	adds r0, r5, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02018C30
	ldr r0, [r5, #0x54]
	adds r4, r5, #0
	adds r4, #0x6c
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _02018B9E
	adds r0, r5, #0
	adds r0, #0x7b
	ldrb r6, [r0]
	cmp r6, #0
	bne _02018B9E
	ldr r1, [r5, #0x58]
	cmp r1, #0x1e
	bls _02018B74
	b _02018C74
_02018B74:
	adds r0, r5, #0
	bl mMsg_ChangeMsgData
	cmp r0, #1
	bne _02018C74
	adds r0, r5, #0
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02018C74
	adds r0, r5, #0
	bl mMsg_MainSetup_Window
	adds r0, r5, #0
	adds r0, #0x79
	strb r6, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x58]
	b _02018C74
_02018B9E:
	ldr r0, [r5, #0x54]
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _02018BB8
	adds r0, r5, #0
	adds r0, #0x7b
	ldrb r0, [r0]
	cmp r0, #1
	beq _02018BEC
_02018BB8:
	ldr r0, [r5, #0x54]
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #0x70
	bl mMsg_CheckControlCode
	adds r7, r0, #0
	cmp r7, #0
	bne _02018BF0
	ldr r0, [r5, #0x54]
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #0
	bl mMsg_CheckControlCode
	adds r7, r0, #0
	cmp r7, #0
	bne _02018BF0
	ldr r0, [r5, #0x54]
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #0x58
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _02018C16
_02018BEC:
	cmp r7, #0
	beq _02018C02
_02018BF0:
	ldr r1, [r5, #0x68]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _02018C02
	movs r0, #4
	orrs r1, r0
	str r1, [r5, #0x68]
	b _02018C74
_02018C02:
	adds r0, r5, #0
	bl mMsg_RequestDisappear
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02018C74
	adds r0, r5, #0
	bl mMsg_MainSetup_Window
	b _02018C74
_02018C16:
	adds r0, r5, #0
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02018C74
	adds r0, r5, #0
	bl mMsg_MainSetup_Window
	adds r0, r5, #0
	adds r0, #0x79
	strb r7, [r0]
	b _02018C74
_02018C30:
	ldr r0, [r5, #0x54]
	adds r1, r5, #0
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	bne _02018C74
	adds r0, r5, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02018C74
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	bne _02018C74
	ldr r0, [r5, #0x5c]
	subs r0, #1
	cmp r0, #1
	bhi _02018C66
	movs r0, #0xa
	movs r1, #0xc8
	movs r2, #0x68
	movs r3, #1
	b _02018C6E
_02018C66:
	movs r0, #0xa
	movs r1, #0xc8
	movs r2, #0x68
	movs r3, #0
_02018C6E:
	bl sub_0201C310
	str r0, [r5, #0x4c]
_02018C74:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_MainSetup_Disappear
mMsg_MainSetup_Disappear: @ 0x02018C7C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x76
	movs r0, #0xc
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x71
	ldrb r1, [r3]
	adds r0, r2, #0
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r3]
	movs r0, #0x20
	bl sub_02019D78
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_Main_Disappear
mMsg_Main_Disappear: @ 0x02018CA4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x76
	adds r0, r4, #0
	bl mMsg_GetWindowScrollOffset
	ldr r6, _02018CF0 @ =0x03001B50
	ldr r2, _02018CF4 @ =0x0000084A
	adds r1, r6, r2
	movs r7, #0
	strh r0, [r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _02018D00
	adds r0, r5, #0
	bl mMsg_RequestHide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02018D00
	ldr r1, _02018CF8 @ =0x0000084E
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _02018CFC @ =0x0000084F
	adds r0, r6, r2
	strb r7, [r0]
	subs r1, #2
	adds r0, r6, r1
	strb r7, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r7, [r0]
	adds r0, r5, #0
	bl mMsg_MainSetup_Window
	b _02018D0A
	.align 2, 0
_02018CF0: .4byte 0x03001B50
_02018CF4: .4byte 0x0000084A
_02018CF8: .4byte 0x0000084E
_02018CFC: .4byte 0x0000084F
_02018D00:
	adds r1, r5, #0
	adds r1, #0x76
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_02018D0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start mMsg_CheckChoiceNext
mMsg_CheckChoiceNext: @ 0x02018D10
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0x19
	bne _02018D30
	movs r3, #0
	ldr r0, _02018D28 @ =0x03001B50
	ldr r1, _02018D2C @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	b _02018D3C
	.align 2, 0
_02018D28: .4byte 0x03001B50
_02018D2C: .4byte 0x0000081A
_02018D30:
	movs r3, #0
	ldr r0, _02018D5C @ =0x03001B50
	ldr r1, _02018D60 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x10
_02018D3C:
	ands r0, r1
	cmp r0, #0
	beq _02018D56
	adds r0, r2, #0
	adds r0, #0x7f
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #0
	adds r1, #0x80
	ldrb r1, [r1]
	cmp r0, r1
	ble _02018D56
	movs r3, #1
_02018D56:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_02018D5C: .4byte 0x03001B50
_02018D60: .4byte 0x0000081A

	thumb_func_start mMsg_CheckChoicePrevious
mMsg_CheckChoicePrevious: @ 0x02018D64
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0x19
	bne _02018D84
	movs r3, #0
	ldr r0, _02018D7C @ =0x03001B50
	ldr r1, _02018D80 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x40
	b _02018D90
	.align 2, 0
_02018D7C: .4byte 0x03001B50
_02018D80: .4byte 0x0000081A
_02018D84:
	movs r3, #0
	ldr r0, _02018DA8 @ =0x03001B50
	ldr r1, _02018DAC @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x20
_02018D90:
	ands r0, r1
	cmp r0, #0
	beq _02018DA2
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r3, r0, #0x1f
_02018DA2:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_02018DA8: .4byte 0x03001B50
_02018DAC: .4byte 0x0000081A

	thumb_func_start mMsg_UpdateChoiceCursorPosition
mMsg_UpdateChoiceCursorPosition: @ 0x02018DB0
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, [r3, #0x48]
	cmp r4, #0
	beq _02018DE2
	adds r2, r3, #0
	adds r2, #0x80
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	ldr r0, [r0]
	adds r0, #7
	lsls r0, r0, #3
	str r0, [r4, #0x30]
	ldrb r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r0, r3, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x2f
	str r0, [r4, #0x2c]
_02018DE2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start mMsg_UpdateChoiceHighlight
mMsg_UpdateChoiceHighlight: @ 0x02018DE8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r0, _02018E68 @ =0x0202AAC8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r1, sp
	ldr r0, _02018E6C @ =0x0202AAD0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	movs r0, #0x73
	adds r0, r0, r7
	mov r8, r0
	movs r3, #0
	ldrsb r3, [r0, r3]
	ldr r0, [r7]
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, [r7, #0x5c]
	cmp r0, #0x19
	bne _02018E74
	adds r5, r7, #0
	adds r5, #0x80
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, r2
	lsls r1, r1, #5
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #4
	ldr r6, _02018E70 @ =0x001FFFFF
	ands r2, r6
	bl CpuFastSet
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	lsls r2, r4, #5
	ldr r1, [r7, #0x50]
	adds r1, r1, r2
	mov r4, r8
	movs r3, #0
	ldrsb r3, [r4, r3]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #4
	ands r2, r6
	bl CpuFastSet
	b _02018EBA
	.align 2, 0
_02018E68: .4byte 0x0202AAC8
_02018E6C: .4byte 0x0202AAD0
_02018E70: .4byte 0x001FFFFF
_02018E74:
	adds r6, r7, #0
	adds r6, #0x80
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r5, sp, #0xc
	adds r0, r0, r5
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, r2
	lsls r1, r1, #5
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	lsls r2, r3, #4
	ldr r3, _02018EC8 @ =0x001FFFFF
	mov sb, r3
	ands r2, r3
	bl CpuFastSet
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	lsls r2, r4, #5
	ldr r1, [r7, #0x50]
	adds r1, r1, r2
	mov r4, r8
	movs r2, #0
	ldrsb r2, [r4, r2]
	lsls r2, r2, #4
	mov r3, sb
	ands r2, r3
	bl CpuFastSet
_02018EBA:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02018EC8: .4byte 0x001FFFFF

	thumb_func_start mMsg_MainSetup_Choice
mMsg_MainSetup_Choice: @ 0x02018ECC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0201C310
	str r0, [r4, #0x48]
	adds r0, r4, #0
	bl mMsg_UpdateChoiceCursorPosition
	adds r0, r4, #0
	bl mMsg_UpdateChoiceHighlight
	adds r2, r4, #0
	adds r2, #0x71
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r2]
	adds r4, #0x77
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start mMsg_Main_Choice
mMsg_Main_Choice: @ 0x02018F08
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x77
	movs r1, #0
	ldrsb r1, [r5, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _02018F2E
	adds r0, r4, #0
	bl mMsg_TimerDec
	cmp r0, #0
	beq _02018FE6
	adds r0, r4, #0
	bl mMsg_MainSetup_Window
	b _02018FE6
_02018F2E:
	ldr r0, [r4, #0x48]
	cmp r0, #0
	bne _02018F50
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0201C310
	str r0, [r4, #0x48]
	adds r0, r4, #0
	bl mMsg_UpdateChoiceCursorPosition
	adds r0, r4, #0
	bl mMsg_UpdateChoiceHighlight
	b _02018FE6
_02018F50:
	ldr r0, _02018F98 @ =0x03001B50
	ldr r1, _02018F9C @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02018FA0
	adds r0, r4, #0
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02018FA0
	adds r1, r4, #0
	adds r1, #0x79
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x80
	ldrb r0, [r0]
	strb r0, [r5]
	lsls r0, r0, #0x18
	movs r5, #0x11
	cmp r0, #0
	bne _02018F86
	movs r5, #0x10
_02018F86:
	adds r0, r4, #0
	movs r1, #0x14
	bl mMsg_SetTimer
	adds r0, r5, #0
	bl sub_02019D78
	b _02018FE6
	.align 2, 0
_02018F98: .4byte 0x03001B50
_02018F9C: .4byte 0x0000081A
_02018FA0:
	adds r0, r4, #0
	bl mMsg_CheckChoiceNext
	cmp r0, #0
	beq _02018FC0
	adds r1, r4, #0
	adds r1, #0x80
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xf
	bl sub_02019D78
	adds r0, r4, #0
	bl mMsg_UpdateChoiceHighlight
_02018FC0:
	adds r0, r4, #0
	bl mMsg_CheckChoicePrevious
	cmp r0, #0
	beq _02018FE0
	adds r1, r4, #0
	adds r1, #0x80
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0xf
	bl sub_02019D78
	adds r0, r4, #0
	bl mMsg_UpdateChoiceHighlight
_02018FE0:
	adds r0, r4, #0
	bl mMsg_UpdateChoiceCursorPosition
_02018FE6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start mMsg_MainSetup_DisappearWait
mMsg_MainSetup_DisappearWait: @ 0x02018FEC
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x76
	movs r0, #0xc
	strb r0, [r2]
	subs r2, #6
	ldrb r0, [r2]
	adds r3, r1, #0
	adds r3, #0x72
	strb r0, [r3]
	adds r1, #0x71
	ldrb r0, [r1]
	strb r0, [r2]
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0x20
	bl sub_02019D78
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_Main_DisappearWait
mMsg_Main_DisappearWait: @ 0x02019018
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x76
	adds r0, r4, #0
	bl mMsg_GetWindowScrollOffset
	ldr r1, _02019040 @ =0x03001B50
	ldr r2, _02019044 @ =0x0000084A
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _02019048
	subs r0, r1, #1
	strb r0, [r4]
	b _02019050
	.align 2, 0
_02019040: .4byte 0x03001B50
_02019044: .4byte 0x0000084A
_02019048:
	adds r1, r5, #0
	adds r1, #0x7c
	movs r0, #0
	strb r0, [r1]
_02019050:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_MainSetup_AppearWait
mMsg_MainSetup_AppearWait: @ 0x02019058
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x76
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x71
	ldrb r1, [r3]
	adds r0, r2, #0
	adds r0, #0x70
	strb r1, [r0]
	movs r0, #0xff
	strb r0, [r3]
	movs r0, #0x1f
	bl sub_02019D78
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_Main_AppearWait
mMsg_Main_AppearWait: @ 0x02019080
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x76
	adds r0, r4, #0
	bl mMsg_GetWindowScrollOffset
	ldr r1, _020190B4 @ =0x03001B50
	ldr r2, _020190B8 @ =0x0000084A
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	ble _020190BC
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x7c
	movs r0, #1
	strb r0, [r1]
	b _020190C0
	.align 2, 0
_020190B4: .4byte 0x03001B50
_020190B8: .4byte 0x0000084A
_020190BC:
	adds r0, r1, #1
	strb r0, [r4]
_020190C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_CopyTilesToVram
mMsg_CopyTilesToVram: @ 0x020190C8
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	ble _020190E6
	lsls r0, r3, #5
	adds r0, r2, r0
	lsls r1, r3, #5
	ldr r2, _020190EC @ =0x06002000
	adds r1, r1, r2
	lsls r2, r4, #3
	ldr r3, _020190F0 @ =0x001FFFFF
	ands r2, r3
	bl CpuFastSet
_020190E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_020190EC: .4byte 0x06002000
_020190F0: .4byte 0x001FFFFF

	thumb_func_start mMsg_GetWindowScrollOffset
mMsg_GetWindowScrollOffset: @ 0x020190F4
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	ble _02019104
	movs r0, #0xb
	strb r0, [r1]
_02019104:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _02019110
	movs r0, #0
	strb r0, [r1]
_02019110:
	ldr r0, _02019124 @ =0x0202AB24
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_02019124: .4byte 0x0202AB24

	thumb_func_start mMsg_RequestMode
mMsg_RequestMode: @ 0x02019128
	adds r0, #0x71
	strb r1, [r0]
	movs r0, #1
	bx lr

	thumb_func_start mMsg_RequestDisappear
mMsg_RequestDisappear: @ 0x02019130
	push {lr}
	movs r1, #6
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestAppear
mMsg_RequestAppear: @ 0x02019140
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #2
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _02019156
	str r5, [r4, #0x58]
_02019156:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestCursor
mMsg_RequestCursor: @ 0x0201915C
	push {lr}
	movs r1, #3
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestNormal
mMsg_RequestNormal: @ 0x0201916C
	push {lr}
	movs r1, #4
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestHide
mMsg_RequestHide: @ 0x0201917C
	push {lr}
	movs r1, #1
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestChoice
mMsg_RequestChoice: @ 0x0201918C
	push {lr}
	movs r1, #5
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start mMsg_RequestDisappearWait
mMsg_RequestDisappearWait: @ 0x0201919C
	push {lr}
	adds r1, r0, #0
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _020191B2
	movs r0, #0
	b _020191BE
_020191B2:
	adds r0, r1, #0
	movs r1, #7
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_020191BE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_RequestAppearWait
mMsg_RequestAppearWait: @ 0x020191C4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	beq _020191D8
	movs r0, #0
	b _020191E4
_020191D8:
	adds r0, r1, #0
	movs r1, #8
	bl mMsg_RequestMode
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_020191E4:
	pop {r1}
	bx r1

	thumb_func_start mMsg_GetMessageBody
mMsg_GetMessageBody: @ 0x020191E8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r1, #0
	adds r5, r2, #0
	cmp r0, #0x1e
	bls _020191FC
	movs r0, #0
	str r0, [r4]
	strh r0, [r5]
	b _0201927A
_020191FC:
	cmp r0, #0
	beq _0201922C
	lsls r2, r0, #2
	ldr r0, _02019228 @ =0x02035774
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [sp]
	add r1, sp, #4
	mov r0, sp
	ldrb r0, [r0]
	strb r0, [r1, #3]
	mov r0, sp
	ldrb r0, [r0, #1]
	strb r0, [r1, #2]
	mov r0, sp
	ldrb r0, [r0, #2]
	strb r0, [r1, #1]
	mov r0, sp
	ldrb r0, [r0, #3]
	strb r0, [r1]
	ldr r3, [sp, #4]
	b _02019232
	.align 2, 0
_02019228: .4byte 0x02035774
_0201922C:
	movs r3, #0
	movs r2, #0
	add r1, sp, #4
_02019232:
	ldr r0, _02019268 @ =0x02035778
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [sp]
	mov r0, sp
	ldrb r0, [r0]
	movs r2, #0
	strb r0, [r1, #3]
	mov r0, sp
	ldrb r0, [r0, #1]
	strb r0, [r1, #2]
	mov r0, sp
	ldrb r0, [r0, #2]
	strb r0, [r1, #1]
	mov r0, sp
	ldrb r0, [r0, #3]
	strb r0, [r1]
	ldr r0, [sp, #4]
	subs r1, r0, r3
	ldr r0, _0201926C @ =0x000001FF
	cmp r1, r0
	bhi _02019274
	ldr r0, _02019270 @ =0x02034FA4
	adds r0, r3, r0
	str r0, [r4]
	strh r1, [r5]
	b _02019278
	.align 2, 0
_02019268: .4byte 0x02035778
_0201926C: .4byte 0x000001FF
_02019270: .4byte 0x02034FA4
_02019274:
	strh r2, [r5]
	str r2, [r4]
_02019278:
	movs r0, #1
_0201927A:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_GetMessageLength
mMsg_GetMessageLength: @ 0x02019284
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0201928A:
	adds r0, r5, r4
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x7f
	bne _020192AC
	ldrb r0, [r1, #1]
	cmp r0, #0x58
	beq _020192B2
	cmp r0, #0
	beq _020192B2
	cmp r0, #1
	beq _020192B2
_020192AC:
	ldr r0, _020192BC @ =0x000001FF
	cmp r4, r0
	ble _0201928A
_020192B2:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_020192BC: .4byte 0x000001FF

	thumb_func_start mFont_CodeSize_get
mFont_CodeSize_get: @ 0x020192C0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0x7f
	bne _020192DC
	ldr r1, _020192D8 @ =0x0202AB54
	ldrb r0, [r2, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	b _020192DE
	.align 2, 0
_020192D8: .4byte 0x0202AB54
_020192DC:
	movs r0, #1
_020192DE:
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_LoadMessage
mMsg_LoadMessage: @ 0x020192E8
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, r1, #0
	add r1, sp, #4
	mov r2, sp
	bl mMsg_GetMessageBody
	cmp r0, #1
	bne _02019326
	ldr r1, [sp, #4]
	cmp r1, #0
	beq _02019326
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _02019326
	mov r0, sp
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r1, #0
	adds r1, r4, #0
	bl mMsg_Copy
	adds r0, r4, #0
	bl mMsg_GetMessageLength
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _02019328
_02019326:
	movs r0, #0
_02019328:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start mMsg_ClearText
mMsg_ClearText: @ 0x02019330
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0201936C @ =0x55555555
	str r0, [sp]
	ldr r1, [r4, #0x50]
	ldr r2, _02019370 @ =0x01000480
	mov r0, sp
	bl CpuFastSet
	ldr r2, [r4, #0x50]
	movs r0, #0
	movs r1, #0x90
	bl mMsg_CopyTilesToVram
	adds r0, r4, #0
	adds r0, #0x75
	ldrb r1, [r0]
	adds r0, #3
	movs r2, #0
	strb r1, [r0]
	subs r0, #4
	strb r2, [r0]
	adds r0, #0xa
	strb r2, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201936C: .4byte 0x55555555
_02019370: .4byte 0x01000480

	thumb_func_start mMsg_ChangeMsgData
mMsg_ChangeMsgData: @ 0x02019374
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r6, #0
	cmp r5, #0x1e
	bhi _020193AA
	ldr r0, [r4, #0x54]
	bl mMsg_LoadMessage
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _020193AA
	str r5, [r4, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x6c
	strh r6, [r0]
	adds r0, r4, #0
	bl mMsg_ClearText
	adds r0, r4, #0
	movs r1, #0x14
	bl mMsg_SetTimer
	movs r6, #1
_020193AA:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_SetTimer
mMsg_SetTimer: @ 0x020193B4
	str r1, [r0, #0x60]
	bx lr

	thumb_func_start mMsg_TimerDec
mMsg_TimerDec: @ 0x020193B8
	push {lr}
	movs r3, #0
	ldr r1, [r0, #0x60]
	cmp r1, #1
	bne _020193C4
	movs r3, #1
_020193C4:
	movs r2, #0
	cmp r1, #0
	ble _020193CC
	subs r2, r1, #1
_020193CC:
	str r2, [r0, #0x60]
	adds r0, r3, #0
	pop {r1}
	bx r1

	thumb_func_start mMsg_SetEndTimer
mMsg_SetEndTimer: @ 0x020193D4
	str r1, [r0, #0x64]
	bx lr

	thumb_func_start mMsg_EndTimerDec
mMsg_EndTimerDec: @ 0x020193D8
	push {lr}
	movs r3, #0
	ldr r1, [r0, #0x64]
	cmp r1, #1
	bne _020193E4
	movs r3, #1
_020193E4:
	movs r2, #0
	cmp r1, #0
	ble _020193EC
	subs r2, r1, #1
_020193EC:
	str r2, [r0, #0x64]
	adds r0, r3, #0
	pop {r1}
	bx r1

	thumb_func_start mMsg_DestroySprites
mMsg_DestroySprites: @ 0x020193F4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x48]
	cmp r0, #0
	beq _02019406
	bl sub_0201C300
	movs r0, #0
	str r0, [r4, #0x48]
_02019406:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq _02019414
	bl sub_0201C300
	movs r0, #0
	str r0, [r4, #0x4c]
_02019414:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_CheckControlCode
mMsg_CheckControlCode: @ 0x0201941C
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r3, #0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r2, r0, r2
	ldrb r0, [r2]
	cmp r0, #0x7f
	bne _02019438
	ldrb r0, [r2, #1]
	cmp r0, r1
	bne _02019438
	movs r3, #1
_02019438:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_ProcessText
mMsg_ProcessText: @ 0x02019440
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	str r1, [sp, #0xc]
	mov sl, r2
	movs r0, #1
	str r0, [sp, #0x10]
	movs r1, #6
	str r1, [sp, #0x14]
	adds r0, r5, #0
	bl mMsg_TimerDec
	cmp r0, #0
	beq _02019496
	movs r0, #1
	b _02019570
_02019468:
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r2, r8
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x75
	ldrb r1, [r0]
	adds r0, #3
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x74
	ldrb r0, [r2]
	adds r0, #2
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r2]
	b _0201956E
_02019496:
	movs r2, #0
	mov sb, r2
	cmp sb, sl
	bge _0201956E
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bne _0201956E
	movs r0, #0x6c
	adds r0, r0, r5
	mov r8, r0
_020194AA:
	mov r2, r8
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	ldrb r4, [r0]
	cmp r4, #0xcd
	beq _02019468
	cmp r4, #0x7f
	bne _020194D0
	adds r0, r5, #0
	mov r1, r8
	bl mMsg_ProcessControlCode
	str r0, [sp, #0x10]
	subs r0, #2
	cmp r0, #2
	bls _0201956E
	b _02019564
_020194D0:
	adds r0, r4, #0
	bl mFont_GetGlyphWidth
	adds r7, r0, #0
	adds r3, r5, #0
	adds r3, #0x73
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r1, r2, #3
	adds r6, r5, #0
	adds r6, #0x78
	ldrb r0, [r6]
	subs r0, #1
	adds r0, r0, r7
	cmp r1, r0
	blt _02019544
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r2, r0
	lsls r0, r0, #5
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	mov ip, r1
	adds r2, r5, #0
	adds r2, #0x7e
	ldrb r0, [r2]
	cmp r0, #0
	beq _0201951A
	adds r1, r5, #0
	adds r1, #0x7d
	ldrb r1, [r1]
	str r1, [sp, #0x14]
	subs r0, #1
	strb r0, [r2]
_0201951A:
	cmp r4, #0x20
	bne _02019520
	movs r4, #0x80
_02019520:
	ldrb r1, [r6]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r4, [sp]
	ldr r2, [sp, #0x14]
	str r2, [sp, #4]
	subs r0, r7, #1
	str r0, [sp, #8]
	mov r0, ip
	movs r2, #0
	bl mFont_DrawCharToTiles
	ldrb r0, [r6]
	adds r0, r0, r7
	strb r0, [r6]
_02019544:
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	bl mFont_CodeSize_get
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	movs r0, #1
	add sb, r0
_02019564:
	cmp sb, sl
	bge _0201956E
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _020194AA
_0201956E:
	ldr r0, [sp, #0x10]
_02019570:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start mMsg_Init
mMsg_Init: @ 0x02019580
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r1, _020196E0 @ =0x0202AD18
	mov r0, sp
	movs r2, #4
	bl memcpy
	movs r0, #0
	mov sb, r0
	mov r1, sp
	adds r1, #4
	str r1, [sp, #8]
	ldr r7, _020196E4 @ =0x03002A20
	adds r7, #0x50
	mov sl, r0
	ldr r2, _020196E8 @ =0x0200F580
	mov r8, r2
	mov r5, sp
	ldr r6, _020196E4 @ =0x03002A20
	adds r6, #0x6e
	ldr r0, _020196EC @ =0x02001D80
	str r0, [sp, #0xc]
	ldr r1, _020196F0 @ =0x02000400
	str r1, [sp, #0x10]
	ldr r2, _020196E4 @ =0x03002A20
	str r2, [sp, #0x14]
_020195BC:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	bl mMsg_InitWindow
	ldrb r0, [r6, #7]
	movs r1, #0
	strb r0, [r6, #0xa]
	strb r1, [r6, #6]
	ldr r4, _020196E4 @ =0x03002A20
	adds r4, #0x54
	add r4, sl
	ldr r0, [r4]
	movs r1, #0x18
	bl mMsg_LoadMessage
	strh r0, [r6]
	ldr r1, [r4]
	ldrb r0, [r5]
	strb r0, [r1, #5]
	ldr r1, [r4]
	ldrb r0, [r5, #1]
	strb r0, [r1, #0xf]
	mov r0, r8
	str r0, [r7]
	ldr r0, _020196F4 @ =0x55555555
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	mov r1, r8
	ldr r2, _020196F8 @ =0x01000120
	bl CpuFastSet
	mov r4, sl
_020195FE:
	ldr r1, [r7]
	ldr r2, _020196E4 @ =0x03002A20
	adds r0, r4, r2
	movs r2, #1
	bl mMsg_ProcessText
	cmp r0, #1
	beq _020195FE
	adds r7, #0xa0
	movs r0, #0xa0
	add sl, r0
	movs r1, #0x90
	lsls r1, r1, #3
	add r8, r1
	adds r5, #2
	adds r6, #0xa0
	ldr r2, [sp, #0xc]
	movs r0, #0x90
	lsls r0, r0, #5
	adds r2, r2, r0
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x10]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r1, r2
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, #0xa0
	str r0, [sp, #0x14]
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #1
	ble _020195BC
	movs r0, #0
	mov sb, r0
_02019646:
	mov r1, sb
	lsls r6, r1, #2
	adds r4, r6, r1
	lsls r4, r4, #5
	ldr r2, _020196E4 @ =0x03002A20
	adds r5, r4, r2
	lsls r1, r1, #4
	add r1, sb
	lsls r1, r1, #5
	ldr r0, _020196F0 @ =0x02000400
	adds r1, r1, r0
	mov r0, sb
	lsls r2, r0, #3
	add r2, sb
	lsls r2, r2, #9
	ldr r0, _020196EC @ =0x02001D80
	adds r2, r2, r0
	adds r0, r5, #0
	bl mMsg_InitWindow
	adds r0, r5, #0
	bl mMsg_ClearText
	ldr r2, _020196E4 @ =0x03002A20
	adds r2, #0x5c
	adds r2, r4, r2
	ldr r0, _020196FC @ =0x0202A8E0
	adds r0, r6, r0
	ldr r1, [r0]
	str r1, [r2]
	ldr r2, _02019700 @ =0x03002A74
	adds r0, r4, r2
	ldr r0, [r0]
	bl mMsg_LoadMessage
	adds r1, r5, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r1, #2
	movs r0, #3
	strb r0, [r1]
	mov r8, r6
	movs r0, #1
	add r0, sb
	mov sl, r0
	ldr r1, _02019704 @ =0x03002A70
	adds r6, r4, r1
	adds r4, r5, #0
	adds r4, #0x6c
_020196A8:
	ldrh r7, [r4]
	ldr r1, [r6]
	adds r0, r5, #0
	movs r2, #1
	bl mMsg_ProcessText
	cmp r0, #1
	beq _020196A8
	mov r0, r8
	add r0, sb
	lsls r0, r0, #5
	ldr r2, _020196E4 @ =0x03002A20
	adds r0, r0, r2
	adds r0, #0x6c
	strh r7, [r0]
	mov sb, sl
	mov r0, sb
	cmp r0, #8
	ble _02019646
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020196E0: .4byte 0x0202AD18
_020196E4: .4byte 0x03002A20
_020196E8: .4byte 0x0200F580
_020196EC: .4byte 0x02001D80
_020196F0: .4byte 0x02000400
_020196F4: .4byte 0x55555555
_020196F8: .4byte 0x01000120
_020196FC: .4byte 0x0202A8E0
_02019700: .4byte 0x03002A74
_02019704: .4byte 0x03002A70

	thumb_func_start mMsg_MainSetup_Window
mMsg_MainSetup_Window: @ 0x02019708
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x71
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _02019742
	ldr r6, _02019748 @ =0x0202AADC
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	cmp r0, #0
	beq _02019742
	adds r0, r5, #0
	bl mMsg_DestroySprites
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_02019742:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_02019748: .4byte 0x0202AADC

	thumb_func_start mMsg_InitWindow
mMsg_InitWindow: @ 0x0201974C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r6, #0
	str r6, [sp]
	ldr r2, _020197A0 @ =0x01000028
	mov r0, sp
	adds r1, r7, #0
	bl CpuFastSet
	str r4, [r7, #0x50]
	str r5, [r7, #0x54]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x58]
	str r0, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0x70
	movs r1, #1
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x71
	movs r0, #0xff
	strb r0, [r2]
	adds r2, #6
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	subs r2, #4
	movs r0, #0x12
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x75
	strb r1, [r0]
	adds r0, #7
	strb r6, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020197A0: .4byte 0x01000028

	thumb_func_start mMsg_Main_Window
mMsg_Main_Window: @ 0x020197A4
	push {lr}
	adds r2, r0, #0
	ldr r1, _020197C8 @ =0x0202AB00
	adds r0, #0x70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _020197C2
	adds r0, r2, #0
	bl _call_via_r1
_020197C2:
	pop {r0}
	bx r0
	.align 2, 0
_020197C8: .4byte 0x0202AB00

	thumb_func_start mFont_DrawStringToTiles
mFont_DrawStringToTiles: @ 0x020197CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0xc]
	mov sb, r1
	ldr r0, [sp, #0x44]
	ldr r1, [sp, #0x48]
	ldr r4, [sp, #0x4c]
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x14]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0x18]
	movs r6, #0
	lsrs r0, r2, #0x13
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	lsls r0, r0, #5
	mov sl, r0
	movs r7, #0xe0
	lsls r7, r7, #0xb
	ands r7, r2
	b _02019834
_02019812:
	str r4, [sp]
	ldr r3, [sp, #0x10]
	str r3, [sp, #4]
	subs r0, r5, #1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	add r0, sl
	adds r1, r2, #0
	lsrs r2, r7, #0x10
	mov r3, r8
	bl mFont_DrawCharToTiles
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	adds r6, #1
_02019834:
	ldr r3, [sp, #0x40]
	cmp r6, r3
	bge _0201986E
	ldr r1, [sp, #0x3c]
	adds r0, r1, r6
	ldrb r4, [r0]
	ldr r3, [sp, #0x14]
	cmp r3, #1
	bne _0201984A
	cmp r4, #0xcd
	beq _0201986E
_0201984A:
	cmp r4, #0x7f
	beq _0201986E
	ldr r0, [sp, #0x18]
	cmp r0, #1
	beq _0201985E
	adds r0, r4, #0
	bl mFont_GetGlyphWidth
	adds r5, r0, #0
	b _02019860
_0201985E:
	movs r5, #8
_02019860:
	mov r1, sb
	ldrh r2, [r1]
	adds r1, r5, r2
	mov r3, r8
	lsls r0, r3, #3
	cmp r1, r0
	ble _02019812
_0201986E:
	adds r0, r6, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start mFont_DrawCharToTiles
mFont_DrawCharToTiles: @ 0x02019880
	push {r4, r5, r6, r7, lr}
	adds r6, r2, #0
	ldr r2, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r7, [sp, #0x1c]
	ldr r4, _020198B4 @ =0x03003100
	str r0, [r4]
	strh r1, [r4, #4]
	strh r6, [r4, #6]
	strh r3, [r4, #8]
	strb r5, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r4, #0
	adds r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl mFont_GetGlyphRows
	adds r0, r4, #0
	adds r1, r7, #0
	bl mFont_BlitGlyphToTiles
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020198B4: .4byte 0x03003100

	thumb_func_start sub_020198B8
sub_020198B8: @ 0x020198B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r1, sp
	ldr r0, _02019908 @ =0x0202AD1C
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	add r5, sp, #0xc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xc
	bl memset
	add r3, sp, #0x18
	adds r1, r3, #0
	ldr r0, _0201990C @ =0x0202AD28
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	lsls r4, r4, #0x18
	asrs r2, r4, #0x18
	cmp r2, #0
	blt _02019900
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	mov r4, sp
	adds r1, r4, r2
	ldr r1, [r1]
	adds r2, r3, r2
	ldr r2, [r2]
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	bl CpuFastSet
_02019900:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02019908: .4byte 0x0202AD1C
_0201990C: .4byte 0x0202AD28

	thumb_func_start sub_02019910
sub_02019910: @ 0x02019910
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sp
	movs r1, #0
	movs r2, #0xc
	bl memset
	add r2, sp, #0xc
	adds r1, r2, #0
	ldr r0, _0201997C @ =0x0202AD28
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	lsls r0, r4, #0x18
	mov ip, r2
	cmp r0, #0
	blt _02019972
	movs r4, #0
	movs r3, #0
	adds r5, r0, #0
	add r7, sp, #0x18
	movs r2, #0xf
	ands r2, r6
_02019946:
	lsls r1, r3, #2
	adds r0, r2, #0
	lsls r0, r1
	orrs r4, r0
	adds r3, #1
	cmp r3, #7
	ble _02019946
	str r4, [sp, #0x18]
	asrs r0, r5, #0x16
	mov r2, sp
	adds r1, r2, r0
	ldr r1, [r1]
	add r0, ip
	ldr r2, [r0]
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x11
	orrs r2, r0
	adds r0, r7, #0
	bl CpuFastSet
_02019972:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201997C: .4byte 0x0202AD28

	thumb_func_start mFont_BlitGlyphToTiles
mFont_BlitGlyphToTiles: @ 0x02019980
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r3, r0, #0
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldrh r1, [r3, #6]
	mov sb, r1
_02019998:
	movs r2, #0
	mov r8, r2
	ldrh r7, [r3, #4]
	ldr r5, [sp, #4]
	adds r5, #1
	str r5, [sp, #8]
	mov r0, sb
	adds r0, #1
	str r0, [sp, #0xc]
	ldr r1, [sp]
	cmp r8, r1
	bge _02019A98
	mov r0, sb
	movs r2, #7
	ands r0, r2
	lsls r0, r0, #2
	mov sl, r0
	movs r5, #0xf
	mov ip, r5
_020199BE:
	mov r0, sb
	lsrs r1, r0, #3
	ldrh r0, [r3, #8]
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	lsrs r1, r7, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x18
	ldr r5, [sp, #4]
	adds r0, r0, r5
	ldrb r0, [r0]
	mov r1, r8
	asrs r0, r1
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _02019A2A
	lsls r1, r6, #5
	add r1, sl
	adds r0, r7, #0
	movs r5, #7
	ands r0, r5
	lsrs r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, [r3]
	adds r0, r1, r4
	ldrb r0, [r0]
	adds r2, r0, #0
	adds r0, r7, #0
	movs r5, #1
	ands r0, r5
	adds r5, r1, #0
	cmp r0, #0
	beq _02019A1A
	mov r0, ip
	ands r2, r0
	ldrb r1, [r3, #0xe]
	ands r0, r1
	lsls r0, r0, #4
	b _02019A24
_02019A1A:
	movs r0, #0xf0
	ands r2, r0
	ldrb r1, [r3, #0xe]
	mov r0, ip
	ands r0, r1
_02019A24:
	orrs r2, r0
	adds r0, r5, r4
	strb r2, [r0]
_02019A2A:
	ldrh r0, [r3, #8]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r2, r8
	asrs r0, r2
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _02019A88
	lsls r1, r6, #5
	add r1, sl
	adds r0, r7, #0
	movs r2, #7
	ands r0, r2
	lsrs r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, [r3]
	adds r0, r1, r4
	ldrb r0, [r0]
	adds r2, r0, #0
	adds r0, r7, #0
	ands r0, r5
	adds r5, r1, #0
	cmp r0, #0
	beq _02019A78
	mov r0, ip
	ands r2, r0
	ldrb r1, [r3, #0xe]
	ands r0, r1
	lsls r0, r0, #4
	b _02019A82
_02019A78:
	movs r0, #0xf0
	ands r2, r0
	ldrb r1, [r3, #0xe]
	mov r0, ip
	ands r0, r1
_02019A82:
	orrs r2, r0
	adds r0, r5, r4
	strb r2, [r0]
_02019A88:
	movs r1, #1
	add r8, r1
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r2, [sp]
	cmp r8, r2
	blt _020199BE
_02019A98:
	ldr r5, [sp, #8]
	str r5, [sp, #4]
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r5, #7
	bgt _02019AAA
	b _02019998
_02019AAA:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019ABC
sub_02019ABC: @ 0x02019ABC
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r0, r1, r0
	cmp r0, #0
	bge _02019ACE
	adds r0, #0xff
_02019ACE:
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02019AD8
sub_02019AD8: @ 0x02019AD8
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02019AF0
sub_02019AF0: @ 0x02019AF0
	adds r2, r0, #0
	ldr r1, [r2, #0xc]
	ldr r0, _02019B0C @ =0x41C64E6D
	muls r0, r1, r0
	ldr r3, _02019B10 @ =0x0000085B
	adds r1, r2, r3
	ldrb r1, [r1]
	ldr r3, _02019B14 @ =0x00003039
	adds r1, r1, r3
	adds r0, r0, r1
	str r0, [r2, #0xc]
	lsls r0, r0, #1
	lsrs r0, r0, #0x11
	bx lr
	.align 2, 0
_02019B0C: .4byte 0x41C64E6D
_02019B10: .4byte 0x0000085B
_02019B14: .4byte 0x00003039

	thumb_func_start sub_02019B18
sub_02019B18: @ 0x02019B18
	str r1, [r0, #0xc]
	bx lr

	thumb_func_start sub_02019B1C
sub_02019B1C: @ 0x02019B1C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	cmp r1, #1
	bne _02019B34
	movs r0, #0xc0
	b _02019B36
_02019B34:
	movs r0, #0x80
_02019B36:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r2, r5, r1
	adds r1, r4, #0
	orrs r1, r0
	strh r1, [r2]
	cmp r3, #0x10
	bls _02019B48
	movs r3, #0x10
_02019B48:
	ldr r1, _02019B54 @ =0x0000081E
	adds r0, r5, r1
	strh r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02019B54: .4byte 0x0000081E

	thumb_func_start sub_02019B58
sub_02019B58: @ 0x02019B58
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r4, r2, #0
	ldr r3, _02019B80 @ =0x0000081E
	adds r0, r5, r3
	ldrh r3, [r0]
	cmp r1, #1
	bne _02019B84
	adds r0, r3, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _02019B94
	movs r3, #0x10
	b _02019B94
	.align 2, 0
_02019B80: .4byte 0x0000081E
_02019B84:
	cmp r1, #0
	bne _02019B94
	subs r0, r3, r4
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _02019B94
	movs r3, #0
_02019B94:
	ldr r1, _02019BA4 @ =0x0000081E
	adds r0, r5, r1
	strh r3, [r0]
	ldrh r0, [r0]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_02019BA4: .4byte 0x0000081E

	thumb_func_start sub_02019BA8
sub_02019BA8: @ 0x02019BA8
	push {r4, r5, r6, lr}
	ldr r6, [sp, #0x10]
	ldr r5, [sp, #0x14]
	movs r4, #0xf
	ands r2, r4
	ands r4, r1
	lsls r4, r4, #4
	adds r4, r4, r2
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	lsrs r0, r1, #0xa
	movs r4, #0x1f
	movs r2, #0x1f
	ands r0, r2
	strb r0, [r5]
	lsrs r0, r1, #5
	ands r0, r2
	strb r0, [r6]
	ands r1, r4
	strb r1, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_02019BD8
sub_02019BD8: @ 0x02019BD8
	push {r4, r5, r6, r7, lr}
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r1, r5, #0x18
	movs r5, #0x80
	lsls r5, r5, #0x12
	cmp r0, #1
	bne _02019C00
	ldr r5, _02019C30 @ =0x02000200
_02019C00:
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #0xa
	ands r4, r2
	lsls r0, r4, #5
	orrs r1, r0
	ands r3, r2
	orrs r3, r1
	movs r0, #0xf
	ands r6, r0
	ands r7, r0
	lsls r0, r6, #4
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r3, [r0]
	ldr r0, _02019C34 @ =0x03001B50
	ldr r1, _02019C38 @ =0x00000852
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02019C30: .4byte 0x02000200
_02019C34: .4byte 0x03001B50
_02019C38: .4byte 0x00000852

	thumb_func_start sub_02019C3C
sub_02019C3C: @ 0x02019C3C
	push {r4, lr}
	ldr r2, _02019C7C @ =0x03001B50
	ldr r0, _02019C80 @ =0x00000814
	adds r3, r2, r0
	ldrh r1, [r3]
	ldr r0, _02019C84 @ =0x0000FFFE
	ands r0, r1
	ldrh r1, [r3]
	strh r0, [r3]
	ldrh r1, [r3]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _02019C68
	adds r2, r3, #0
	movs r3, #1
_02019C5E:
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _02019C5E
_02019C68:
	ldr r0, _02019C80 @ =0x00000814
	adds r1, r4, r0
	ldrh r2, [r1]
	ldr r0, _02019C84 @ =0x0000FFFE
	ands r0, r2
	ldrh r2, [r1]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02019C7C: .4byte 0x03001B50
_02019C80: .4byte 0x00000814
_02019C84: .4byte 0x0000FFFE

	thumb_func_start sub_02019C88
sub_02019C88: @ 0x02019C88
	push {r4, r5, lr}
	ldr r1, _02019CB4 @ =0x03002410
	movs r0, #0x80
	lsls r0, r0, #3
	adds r4, r1, r0
	ldr r5, _02019CB8 @ =0x03001B50
	cmp r1, r4
	bhs _02019CA4
	ldr r0, _02019CBC @ =0x0202AFB4
	ldr r2, [r0]
	ldr r3, [r0, #4]
_02019C9E:
	stm r1!, {r2, r3}
	cmp r1, r4
	blo _02019C9E
_02019CA4:
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02019CB4: .4byte 0x03002410
_02019CB8: .4byte 0x03001B50
_02019CBC: .4byte 0x0202AFB4

	thumb_func_start sub_02019CC0
sub_02019CC0: @ 0x02019CC0
	push {r4, lr}
	ldr r0, _02019CE8 @ =0x04000130
	ldrh r0, [r0]
	ldr r1, _02019CEC @ =0x000003FF
	adds r2, r1, #0
	eors r2, r0
	ldr r1, _02019CF0 @ =0x03001B50
	ldr r3, _02019CF4 @ =0x00000818
	adds r4, r1, r3
	ldrh r3, [r4]
	adds r0, r2, #0
	bics r0, r3
	ldr r3, _02019CF8 @ =0x0000081A
	adds r1, r1, r3
	strh r0, [r1]
	strh r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02019CE8: .4byte 0x04000130
_02019CEC: .4byte 0x000003FF
_02019CF0: .4byte 0x03001B50
_02019CF4: .4byte 0x00000818
_02019CF8: .4byte 0x0000081A

	thumb_func_start sub_02019CFC
sub_02019CFC: @ 0x02019CFC
	ldr r2, _02019D20 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x80
	strh r0, [r1]
	adds r1, #4
	movs r0, #8
	strh r0, [r1]
	ldr r1, _02019D24 @ =0x04000200
	movs r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	strh r0, [r2]
	bx lr
	.align 2, 0
_02019D20: .4byte 0x04000208
_02019D24: .4byte 0x04000200

	thumb_func_start sub_02019D28
sub_02019D28: @ 0x02019D28
	push {lr}
	bl sub_02026F0C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D34
sub_02019D34: @ 0x02019D34
	push {lr}
	bl sub_020269C8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D40
sub_02019D40: @ 0x02019D40
	push {lr}
	bl sub_02026F18
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D4C
sub_02019D4C: @ 0x02019D4C
	push {lr}
	bl sub_020269E0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D58
sub_02019D58: @ 0x02019D58
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_02026B48
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D68
sub_02019D68: @ 0x02019D68
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_02026BC8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D78
sub_02019D78: @ 0x02019D78
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_02026A38
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D88
sub_02019D88: @ 0x02019D88
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_02026C10
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019D98
sub_02019D98: @ 0x02019D98
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_02026C68
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start mMsg_ReplaceChar
mMsg_ReplaceChar: @ 0x02019DA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	movs r2, #0
	cmp r3, #0
	ble _02019DCE
	cmp r2, r3
	bge _02019DCE
_02019DBE:
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, r5
	bne _02019DC8
	strb r4, [r1]
_02019DC8:
	adds r2, #1
	cmp r2, r3
	blt _02019DBE
_02019DCE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start mMsg_TrimTrailingSpaces
mMsg_TrimTrailingSpaces: @ 0x02019DD4
	push {lr}
	adds r3, r0, #0
	movs r2, #0
	cmp r1, #0
	ble _02019DFC
	adds r2, r1, #0
	adds r0, r3, r2
	subs r0, #1
	ldrb r0, [r0]
	cmp r0, #0x80
	bne _02019DFC
	subs r0, r2, #1
	adds r1, r0, r3
_02019DEE:
	subs r1, #1
	subs r2, #1
	cmp r2, #0
	ble _02019DFC
	ldrb r0, [r1]
	cmp r0, #0x80
	beq _02019DEE
_02019DFC:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_StringsDiffer
mMsg_StringsDiffer: @ 0x02019E04
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r3, #0
	cmp r2, #0
	ble _02019E2E
	cmp r3, r2
	bge _02019E2E
	ldrb r0, [r5]
	ldrb r1, [r4]
	cmp r0, r1
	bne _02019E2E
_02019E1C:
	adds r3, #1
	cmp r3, r2
	bge _02019E2E
	adds r0, r5, r3
	adds r1, r4, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _02019E1C
_02019E2E:
	adds r1, r3, #0
	eors r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start mMsg_Copy
mMsg_Copy: @ 0x02019E40
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r2, #0
	ble _02019E5E
	movs r3, #0
	cmp r3, r2
	bge _02019E5E
_02019E50:
	adds r0, r4, r3
	adds r1, r5, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, r2
	blt _02019E50
_02019E5E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start mMsg_Fill
mMsg_Fill: @ 0x02019E64
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r2, #0
	ble _02019E80
	movs r3, #0
	cmp r3, r2
	bge _02019E80
_02019E76:
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, r2
	blt _02019E76
_02019E80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02019E88
sub_02019E88: @ 0x02019E88
	push {lr}
	sub sp, #4
	movs r0, #0xc0
	bl RegisterRamReset
	movs r0, #0
	str r0, [sp]
	ldr r1, _02019EDC @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	str r0, [r1, #4]
	ldr r0, _02019EE0 @ =0x85001E00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _02019EE4 @ =0x04000204
	ldr r3, _02019EE8 @ =0x00004014
	adds r0, r3, #0
	strh r0, [r2]
	ldr r0, _02019EEC @ =0x02029698
	str r0, [r1]
	ldr r0, _02019EF0 @ =0x030023C0
	str r0, [r1, #4]
	ldr r0, _02019EF4 @ =0x8000001C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _02019EF8 @ =_intr
	str r0, [r1]
	ldr r2, _02019EFC @ =0x03001B64
	str r2, [r1, #4]
	ldr r0, _02019F00 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _02019F04 @ =0x03007FFC
	str r2, [r0]
	bl sub_02019D34
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_02019EDC: .4byte 0x040000D4
_02019EE0: .4byte 0x85001E00
_02019EE4: .4byte 0x04000204
_02019EE8: .4byte 0x00004014
_02019EEC: .4byte 0x02029698
_02019EF0: .4byte 0x030023C0
_02019EF4: .4byte 0x8000001C
_02019EF8: .4byte _intr
_02019EFC: .4byte 0x03001B64
_02019F00: .4byte 0x80000400
_02019F04: .4byte 0x03007FFC

	thumb_func_start sub_02019F08
sub_02019F08: @ 0x02019F08
	bx lr
	.align 2, 0

	thumb_func_start sub_02019F0C
sub_02019F0C: @ 0x02019F0C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0201A030 @ =0x040000D4
	ldr r1, _0201A034 @ =0x020357F4
	str r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0x12
	str r3, [r0, #4]
	ldr r2, _0201A038 @ =0x80000100
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0201A03C @ =0x020359F4
	str r1, [r0]
	ldr r1, _0201A040 @ =0x02000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0201A044 @ =0x80000200
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0201A048 @ =0x03002970
	ldr r0, _0201A04C @ =0x0203B000
	str r0, [r4]
	ldr r2, _0201A050 @ =0x03001B40
	ldr r1, _0201A054 @ =0x020102A0
	str r1, [r2]
	ldr r2, _0201A058 @ =0x04000E60
	bl CpuSet
	movs r2, #0
	adds r7, r4, #0
	adds r3, r7, #0
	ldr r4, _0201A05C @ =0x03002400
_02019F54:
	lsls r0, r2, #2
	ldr r1, [r3]
	adds r0, r0, r1
	ldr r0, [r0, #0x14]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #3
	ble _02019F54
	ldr r4, _0201A060 @ =0x03001B50
	ldr r3, [r7]
	ldr r1, _0201A064 @ =0x0000193E
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #4
	str r0, [r4, #0x10]
	ldr r2, _0201A068 @ =0x0000193D
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x10]
	ldr r1, _0201A06C @ =0x0000193C
	adds r3, r3, r1
	ldrb r1, [r3]
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	str r1, [r4, #0x10]
	ldr r2, _0201A070 @ =0x00000822
	adds r1, r4, r2
	movs r6, #0
	movs r0, #0xe0
	lsls r0, r0, #5
	strh r0, [r1]
	ldr r0, _0201A074 @ =0x00000824
	adds r1, r4, r0
	ldr r0, _0201A078 @ =0x0000D801
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	ldr r0, _0201A07C @ =0x0000D402
	strh r0, [r1]
	ldr r0, _0201A080 @ =0x00000828
	adds r1, r4, r0
	ldr r0, _0201A084 @ =0x0000D003
	strh r0, [r1]
	ldr r0, [r7]
	ldr r1, _0201A088 @ =0x00001948
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0x13
	movs r5, #0x80
	lsls r5, r5, #3
	adds r2, r5, #0
	bl CpuFastSet
	ldr r0, [r7]
	ldr r2, _0201A08C @ =0x00002948
	adds r0, r0, r2
	ldr r1, _0201A090 @ =0x06010000
	adds r2, r5, #0
	bl CpuFastSet
	ldr r0, [r7]
	ldr r1, _0201A094 @ =0x00003948
	adds r0, r0, r1
	ldr r5, _0201A098 @ =0x02000220
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0201A09C @ =0x05000220
	adds r0, r5, #0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0201A0A0 @ =0x0000082A
	adds r4, r4, r2
	strh r6, [r4]
	bl sub_0201A218
	bl sub_0201C2E0
	ldr r0, _0201A0A4 @ =0x03002FC0
	ldr r1, _0201A0A8 @ =0x02001720
	ldr r2, _0201A0AC @ =0x0200BF80
	bl mMsg_InitWindow
	ldr r0, _0201A0B0 @ =0x03003060
	ldr r1, _0201A0B4 @ =0x02001940
	ldr r2, _0201A0B8 @ =0x0200D180
	bl mMsg_InitWindow
	ldr r0, _0201A0BC @ =0x03002980
	ldr r1, _0201A0C0 @ =0x02001B60
	ldr r2, _0201A0C4 @ =0x0200E380
	bl mMsg_InitWindow
	bl sub_0201BF10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201A030: .4byte 0x040000D4
_0201A034: .4byte 0x020357F4
_0201A038: .4byte 0x80000100
_0201A03C: .4byte 0x020359F4
_0201A040: .4byte 0x02000200
_0201A044: .4byte 0x80000200
_0201A048: .4byte 0x03002970
_0201A04C: .4byte 0x0203B000
_0201A050: .4byte 0x03001B40
_0201A054: .4byte 0x020102A0
_0201A058: .4byte 0x04000E60
_0201A05C: .4byte 0x03002400
_0201A060: .4byte 0x03001B50
_0201A064: .4byte 0x0000193E
_0201A068: .4byte 0x0000193D
_0201A06C: .4byte 0x0000193C
_0201A070: .4byte 0x00000822
_0201A074: .4byte 0x00000824
_0201A078: .4byte 0x0000D801
_0201A07C: .4byte 0x0000D402
_0201A080: .4byte 0x00000828
_0201A084: .4byte 0x0000D003
_0201A088: .4byte 0x00001948
_0201A08C: .4byte 0x00002948
_0201A090: .4byte 0x06010000
_0201A094: .4byte 0x00003948
_0201A098: .4byte 0x02000220
_0201A09C: .4byte 0x05000220
_0201A0A0: .4byte 0x0000082A
_0201A0A4: .4byte 0x03002FC0
_0201A0A8: .4byte 0x02001720
_0201A0AC: .4byte 0x0200BF80
_0201A0B0: .4byte 0x03003060
_0201A0B4: .4byte 0x02001940
_0201A0B8: .4byte 0x0200D180
_0201A0BC: .4byte 0x03002980
_0201A0C0: .4byte 0x02001B60
_0201A0C4: .4byte 0x0200E380

	thumb_func_start sub_0201A0C8
sub_0201A0C8: @ 0x0201A0C8
	push {lr}
	bl sub_0201BF58
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201A0D4
sub_0201A0D4: @ 0x0201A0D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _0201A1BC @ =mFont_BlitGlyphToTiles
	ldr r1, _0201A1C0 @ =0x03002810
	movs r2, #0x58
	bl CpuFastSet
	bl mMsg_Init
	bl sub_02019CFC
	ldr r4, _0201A1C4 @ =0x03001B50
	ldr r0, _0201A1C8 @ =0x0000085F
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0201A1CC @ =0x00000816
	adds r1, r4, r2
	ldr r0, _0201A1D0 @ =0x0000FFFF
	strh r0, [r1]
	bl sub_02019F08
	bl sub_02019F0C
	adds r5, r4, #0
	movs r0, #0x85
	lsls r0, r0, #4
	adds r7, r5, r0
	ldr r6, _0201A1D4 @ =0x04000200
	ldr r1, _0201A1D8 @ =0x00000101
	mov r8, r1
_0201A116:
	bl sub_02019CC0
	ldrh r0, [r7]
	cmp r0, r8
	bne _0201A172
	mov r1, sp
	ldrh r0, [r6]
	strh r0, [r1]
	mov r2, sp
	adds r2, #2
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0x80
	strh r0, [r1]
	ldr r4, _0201A1DC @ =0x04000132
	ldr r2, _0201A1E0 @ =0x00008204
	adds r0, r2, #0
	strh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r6]
	bl SoundBiasReset
	svc #3
	bl SoundBiasSet
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	movs r1, #0
	strh r1, [r4]
	ldr r2, _0201A1E4 @ =0x00000856
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	subs r2, #6
	adds r0, r5, r2
	strb r1, [r0]
	strb r1, [r7]
	bl sub_0201A620
_0201A172:
	bl sub_02019C88
	ldr r0, _0201A1E8 @ =0x03003120
	ldr r1, [r0, #0x18]
	ldr r2, _0201A1EC @ =0x0001FEFF
	adds r0, r1, r2
	cmp r0, #1
	bls _0201A188
	ldr r0, _0201A1F0 @ =0xFFFE0202
	cmp r1, r0
	bne _0201A190
_0201A188:
	ldr r0, _0201A1E4 @ =0x00000856
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0201A190:
	bl sub_0201A0C8
	ldr r4, _0201A1C4 @ =0x03001B50
	ldr r2, [r4, #0x10]
	adds r1, r2, #1
	str r1, [r4, #0x10]
	ldr r0, _0201A1F4 @ =0x004F19FF
	cmp r1, r0
	bls _0201A1A8
	ldr r1, _0201A1F8 @ =0xFFB0E601
	adds r0, r2, r1
	str r0, [r4, #0x10]
_0201A1A8:
	bl sub_02019D4C
	ldr r2, _0201A1C8 @ =0x0000085F
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	bl sub_02019C3C
	b _0201A116
	.align 2, 0
_0201A1BC: .4byte mFont_BlitGlyphToTiles
_0201A1C0: .4byte 0x03002810
_0201A1C4: .4byte 0x03001B50
_0201A1C8: .4byte 0x0000085F
_0201A1CC: .4byte 0x00000816
_0201A1D0: .4byte 0x0000FFFF
_0201A1D4: .4byte 0x04000200
_0201A1D8: .4byte 0x00000101
_0201A1DC: .4byte 0x04000132
_0201A1E0: .4byte 0x00008204
_0201A1E4: .4byte 0x00000856
_0201A1E8: .4byte 0x03003120
_0201A1EC: .4byte 0x0001FEFF
_0201A1F0: .4byte 0xFFFE0202
_0201A1F4: .4byte 0x004F19FF
_0201A1F8: .4byte 0xFFB0E601

	thumb_func_start sub_0201A1FC
sub_0201A1FC: @ 0x0201A1FC
	sub sp, #4
	mov r2, sp
	ldrb r1, [r0, #3]
	strb r1, [r2]
	ldrb r1, [r0, #2]
	strb r1, [r2, #1]
	ldrb r1, [r0, #1]
	strb r1, [r2, #2]
	mov r1, sp
	ldrb r0, [r0]
	strb r0, [r1, #3]
	ldr r0, [sp]
	add sp, #4
	bx lr

	thumb_func_start sub_0201A218
sub_0201A218: @ 0x0201A218
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, _0201A268 @ =0x04000208
	ldrh r4, [r5]
	movs r2, #0
	strh r2, [r5]
	ldr r1, _0201A26C @ =0x04000134
	movs r3, #0xc0
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _0201A270 @ =0x04000158
	strh r2, [r0]
	subs r0, #8
	ldr r0, [r0]
	ldr r0, _0201A274 @ =0x04000154
	movs r3, #0
	str r3, [r0]
	adds r1, #0xc
	movs r0, #0x47
	strh r0, [r1]
	ldr r0, _0201A278 @ =0x04000202
	movs r1, #0x80
	strh r1, [r0]
	strh r1, [r0]
	ldr r2, _0201A27C @ =0x04000200
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	str r3, [sp]
	ldr r1, _0201A280 @ =0x03003120
	ldr r2, _0201A284 @ =0x01000010
	mov r0, sp
	bl CpuFastSet
	strh r4, [r5]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201A268: .4byte 0x04000208
_0201A26C: .4byte 0x04000134
_0201A270: .4byte 0x04000158
_0201A274: .4byte 0x04000154
_0201A278: .4byte 0x04000202
_0201A27C: .4byte 0x04000200
_0201A280: .4byte 0x03003120
_0201A284: .4byte 0x01000010

	thumb_func_start sub_0201A288
sub_0201A288: @ 0x0201A288
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, _0201A2C0 @ =0x04000140
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #1
	mov r1, r8
	ands r0, r1
	ldr r6, _0201A2C4 @ =0x03003120
	cmp r0, #0
	beq _0201A2DC
	adds r3, r6, #0
	adds r3, #0x29
	ldrb r2, [r3]
	cmp r2, #0
	bne _0201A2D4
	ldr r0, _0201A2C8 @ =0x04000150
	ldr r0, [r0]
	str r0, [sp, #4]
	ldr r1, _0201A2CC @ =0x04000154
	ldr r0, _0201A2D0 @ =0x0202AFBC
	ldr r0, [r0]
	str r0, [r1]
	strb r2, [r3]
	b _0201A2DC
	.align 2, 0
_0201A2C0: .4byte 0x04000140
_0201A2C4: .4byte 0x03003120
_0201A2C8: .4byte 0x04000150
_0201A2CC: .4byte 0x04000154
_0201A2D0: .4byte 0x0202AFBC
_0201A2D4:
	movs r0, #2
	mov r1, r8
	orrs r1, r0
	mov r8, r1
_0201A2DC:
	movs r7, #2
	mov r0, r8
	ands r0, r7
	cmp r0, #0
	bne _0201A2E8
	b _0201A5FA
_0201A2E8:
	ldr r0, _0201A324 @ =0x04000150
	ldr r0, [r0]
	str r0, [sp, #4]
	adds r4, r6, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r2, [r5]
	cmp r2, #1
	beq _0201A2FC
	b _0201A5E8
_0201A2FC:
	ldr r1, [r4, #0x18]
	ldr r0, _0201A328 @ =0xFFFE0105
	cmp r1, r0
	beq _0201A33C
	cmp r1, r0
	bhi _0201A32C
	subs r0, #3
	cmp r1, r0
	bls _0201A310
	b _0201A59C
_0201A310:
	subs r0, #1
	cmp r1, r0
	bhs _0201A318
	b _0201A59C
_0201A318:
	adds r0, r4, #0
	ldr r1, [r0, #8]
	cmp r1, #0
	bge _0201A354
	adds r1, #3
	b _0201A354
	.align 2, 0
_0201A324: .4byte 0x04000150
_0201A328: .4byte 0xFFFE0105
_0201A32C:
	ldr r0, _0201A338 @ =0xFFFE0202
	cmp r1, r0
	bne _0201A334
	b _0201A468
_0201A334:
	b _0201A59C
	.align 2, 0
_0201A338: .4byte 0xFFFE0202
_0201A33C:
	ldr r0, _0201A34C @ =0x04000154
	ldr r1, _0201A350 @ =0xFFFE0207
	str r1, [r0]
	movs r0, #0
	strb r0, [r5]
	str r0, [r4, #0x18]
	b _0201A5FA
	.align 2, 0
_0201A34C: .4byte 0x04000154
_0201A350: .4byte 0xFFFE0207
_0201A354:
	asrs r1, r1, #2
	ldr r0, [r0, #4]
	cmp r0, r1
	ble _0201A3C2
	ldr r2, _0201A398 @ =0x03003120
	adds r3, r2, #0
	adds r3, #0x24
	ldrb r5, [r3]
	movs r4, #0
	ldrsb r4, [r3, r4]
	cmp r4, #0
	beq _0201A3A8
	ldr r0, _0201A39C @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0201A37E
	b _0201A5FA
_0201A37E:
	ldr r3, _0201A3A0 @ =0xFFFE0209
	cmp r4, #1
	bne _0201A386
	subs r3, #1
_0201A386:
	ldr r0, _0201A3A4 @ =0x04000154
	str r3, [r0]
	adds r0, r2, #0
	adds r0, #0x25
	strb r5, [r0]
	adds r0, #4
	strb r1, [r0]
	str r1, [r2, #0x18]
	b _0201A5FA
	.align 2, 0
_0201A398: .4byte 0x03003120
_0201A39C: .4byte 0x04000158
_0201A3A0: .4byte 0xFFFE0209
_0201A3A4: .4byte 0x04000154
_0201A3A8:
	ldr r1, _0201A3B8 @ =0xFFFE0106
	ldr r0, [sp, #4]
	cmp r0, r1
	bne _0201A3BC
	movs r0, #1
	strb r0, [r3]
	b _0201A5FA
	.align 2, 0
_0201A3B8: .4byte 0xFFFE0106
_0201A3BC:
	movs r0, #2
	strb r0, [r3]
	b _0201A5FA
_0201A3C2:
	adds r3, r6, #0
	ldr r2, [r3, #0xc]
	cmp r2, #0
	blt _0201A438
	ldr r0, _0201A3F4 @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0201A3DC
	b _0201A5FA
_0201A3DC:
	ldr r0, [r3, #8]
	cmp r0, #0
	bge _0201A3E4
	adds r0, #3
_0201A3E4:
	asrs r0, r0, #2
	ldr r4, [r3, #4]
	cmp r4, r0
	bne _0201A3FC
	ldr r0, _0201A3F8 @ =0x04000154
	ldr r1, [r3, #0x20]
	mvns r1, r1
	b _0201A42A
	.align 2, 0
_0201A3F4: .4byte 0x04000158
_0201A3F8: .4byte 0x04000154
_0201A3FC:
	movs r0, #0xff
	ands r2, r0
	cmp r2, #0xff
	bne _0201A414
	ldr r1, _0201A410 @ =0x04000154
	ldr r0, [r3, #0x1c]
	mvns r0, r0
	str r0, [r1]
	str r5, [r3, #0x1c]
	b _0201A54E
	.align 2, 0
_0201A410: .4byte 0x04000154
_0201A414:
	ldr r1, [r3]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r3, #0x1c]
	adds r0, r0, r1
	str r0, [r3, #0x1c]
	ldr r0, [r3, #0x20]
	adds r0, r0, r1
	str r0, [r3, #0x20]
	ldr r0, _0201A434 @ =0x04000154
_0201A42A:
	str r1, [r0]
	adds r0, r4, #1
	str r0, [r3, #4]
	b _0201A54E
	.align 2, 0
_0201A434: .4byte 0x04000154
_0201A438:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201A444
	b _0201A58C
_0201A444:
	ldr r0, _0201A45C @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0201A456
	b _0201A5FA
_0201A456:
	ldr r1, _0201A460 @ =0x04000154
	ldr r0, _0201A464 @ =0xFFFE0204
	b _0201A57A
	.align 2, 0
_0201A45C: .4byte 0x04000158
_0201A460: .4byte 0x04000154
_0201A464: .4byte 0xFFFE0204
_0201A468:
	ldr r1, [r4, #8]
	cmp r1, #0
	bge _0201A470
	adds r1, #3
_0201A470:
	asrs r1, r1, #2
	ldr r0, [r4, #4]
	cmp r0, r1
	ble _0201A4D4
	ldr r0, _0201A4A0 @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0201A486
	b _0201A5FA
_0201A486:
	ldr r1, [r4, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0201A4AC
	ldr r0, _0201A4A4 @ =0x04000154
	ldr r1, _0201A4A8 @ =0xFFFE0208
	str r1, [r0]
	adds r0, r4, #0
	adds r0, #0x25
	strb r2, [r0]
	b _0201A4B8
	.align 2, 0
_0201A4A0: .4byte 0x04000158
_0201A4A4: .4byte 0x04000154
_0201A4A8: .4byte 0xFFFE0208
_0201A4AC:
	ldr r0, _0201A4C8 @ =0x04000154
	ldr r1, _0201A4CC @ =0xFFFE0209
	str r1, [r0]
	adds r0, r4, #0
	adds r0, #0x25
	strb r7, [r0]
_0201A4B8:
	ldr r1, _0201A4D0 @ =0x03003120
	adds r2, r1, #0
	adds r2, #0x29
	movs r0, #0
	strb r0, [r2]
	str r0, [r1, #0x18]
	b _0201A5FA
	.align 2, 0
_0201A4C8: .4byte 0x04000154
_0201A4CC: .4byte 0xFFFE0209
_0201A4D0: .4byte 0x03003120
_0201A4D4:
	ldr r0, [r4, #0xc]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r5
	ble _0201A55C
	add r0, sp, #4
	bl sub_0201A1FC
	adds r3, r0, #0
	ldr r0, _0201A514 @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0201A4F8
	b _0201A5FA
_0201A4F8:
	ldr r0, [r4, #8]
	cmp r0, #0
	bge _0201A500
	adds r0, #3
_0201A500:
	asrs r0, r0, #2
	ldr r2, [r4, #4]
	cmp r2, r0
	bne _0201A518
	ldr r1, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [sp, #4]
	str r1, [r0]
	b _0201A542
	.align 2, 0
_0201A514: .4byte 0x04000158
_0201A518:
	ldrb r0, [r4, #0xc]
	cmp r0, #0xff
	bne _0201A532
	ldr r0, [r4, #0x1c]
	adds r0, r0, r3
	str r0, [r4, #0x1c]
	cmp r0, r5
	beq _0201A52E
	adds r0, r4, #0
	adds r0, #0x25
	strb r7, [r0]
_0201A52E:
	str r1, [r4, #0x1c]
	b _0201A54E
_0201A532:
	ldr r1, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [sp, #4]
	str r1, [r0]
	ldr r0, [r4, #0x1c]
	adds r0, r0, r3
	str r0, [r4, #0x1c]
_0201A542:
	ldr r0, [r4, #0x20]
	adds r0, r0, r3
	str r0, [r4, #0x20]
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0201A54E:
	ldr r1, _0201A558 @ =0x03003120
	ldr r0, [r1, #0xc]
	adds r0, #1
	str r0, [r1, #0xc]
	b _0201A5FA
	.align 2, 0
_0201A558: .4byte 0x03003120
_0201A55C:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201A58C
	ldr r0, _0201A580 @ =0x04000158
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0201A5FA
	ldr r1, _0201A584 @ =0x04000154
	ldr r0, _0201A588 @ =0xFFFE0104
_0201A57A:
	str r0, [r1]
	str r2, [r6, #0xc]
	b _0201A5FA
	.align 2, 0
_0201A580: .4byte 0x04000158
_0201A584: .4byte 0x04000154
_0201A588: .4byte 0xFFFE0104
_0201A58C:
	ldr r1, _0201A594 @ =0x04000154
	ldr r0, _0201A598 @ =0xFFFE0205
	str r0, [r1]
	b _0201A5FA
	.align 2, 0
_0201A594: .4byte 0x04000154
_0201A598: .4byte 0xFFFE0205
_0201A59C:
	ldr r4, _0201A5D8 @ =0x03003120
	ldr r1, [sp, #4]
	str r1, [r4, #0x18]
	ldr r0, _0201A5DC @ =0xFFFE0101
	cmp r1, r0
	blo _0201A5FA
	adds r0, #1
	cmp r1, r0
	bls _0201A5B4
	ldr r0, _0201A5E0 @ =0xFFFE0202
	cmp r1, r0
	bne _0201A5FA
_0201A5B4:
	movs r0, #0
	str r0, [sp]
	ldr r2, _0201A5E4 @ =0x01000010
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0xc]
	ldr r0, [sp, #4]
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	b _0201A5FA
	.align 2, 0
_0201A5D8: .4byte 0x03003120
_0201A5DC: .4byte 0xFFFE0101
_0201A5E0: .4byte 0xFFFE0202
_0201A5E4: .4byte 0x01000010
_0201A5E8:
	add r0, sp, #4
	bl sub_0201A1FC
	ldr r1, _0201A614 @ =0x0202AFC4
	ldr r1, [r1]
	cmp r0, r1
	bne _0201A5FA
	movs r0, #1
	strb r0, [r5]
_0201A5FA:
	ldr r0, _0201A618 @ =0x04000140
	mov r1, r8
	strh r1, [r0]
	ldr r0, _0201A61C @ =0x03003120
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201A614: .4byte 0x0202AFC4
_0201A618: .4byte 0x04000140
_0201A61C: .4byte 0x03003120

	thumb_func_start sub_0201A620
sub_0201A620: @ 0x0201A620
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, _0201A670 @ =0x04000208
	ldrh r4, [r5]
	movs r2, #0
	strh r2, [r5]
	ldr r1, _0201A674 @ =0x04000134
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _0201A678 @ =0x04000158
	strh r2, [r0]
	subs r0, #8
	ldr r0, [r0]
	ldr r0, _0201A67C @ =0x04000154
	movs r2, #0
	str r2, [r0]
	adds r1, #0xc
	movs r0, #0x47
	strh r0, [r1]
	adds r1, #0xc2
	movs r0, #0x80
	strh r0, [r1]
	str r2, [sp]
	ldr r1, _0201A680 @ =0x03003120
	ldr r2, _0201A684 @ =0x01000010
	mov r0, sp
	bl CpuFastSet
	strh r4, [r5]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201A670: .4byte 0x04000208
_0201A674: .4byte 0x04000134
_0201A678: .4byte 0x04000158
_0201A67C: .4byte 0x04000154
_0201A680: .4byte 0x03003120
_0201A684: .4byte 0x01000010

	thumb_func_start sub_0201A688
sub_0201A688: @ 0x0201A688
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, _0201A6AC @ =0x03003120
	adds r4, r0, #0
	adds r4, #0x2a
	ldrb r1, [r4]
	cmp r1, #0xa
	bhi _0201A6B4
	ldr r0, _0201A6B0 @ =0x04000208
	strh r2, [r0]
	adds r1, #1
	strb r1, [r4]
	movs r1, #1
	strh r1, [r0]
	b _0201A6BE
	.align 2, 0
_0201A6AC: .4byte 0x03003120
_0201A6B0: .4byte 0x04000208
_0201A6B4:
	cmp r3, #0
	beq _0201A6BC
	bl sub_0201A620
_0201A6BC:
	movs r2, #1
_0201A6BE:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201A6C8
sub_0201A6C8: @ 0x0201A6C8
	push {lr}
	ldr r0, _0201A6F8 @ =_start
	ldr r1, _0201A6FC @ =0x0203E9A0
	movs r2, #0
	strh r2, [r1]
	ldr r1, _0201A700 @ =0x04000208
	strh r2, [r1]
	ldr r1, _0201A704 @ =0x04000004
	strh r2, [r1]
	ldr r1, _0201A708 @ =0x04000200
	strh r2, [r1]
	ldr r2, _0201A70C @ =0x04000202
	ldr r3, _0201A710 @ =0x0000FFFF
	adds r1, r3, #0
	strh r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	strh r1, [r2]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0201A6F8: .4byte _start
_0201A6FC: .4byte 0x0203E9A0
_0201A700: .4byte 0x04000208
_0201A704: .4byte 0x04000004
_0201A708: .4byte 0x04000200
_0201A70C: .4byte 0x04000202
_0201A710: .4byte 0x0000FFFF

	thumb_func_start sub_0201A714
sub_0201A714: @ 0x0201A714
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, #0x64
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, #1
	bne _0201A74C
	ldr r1, [r5, #0x14]
	adds r0, r1, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201A776
	adds r0, r1, #0
	bl mMsg_RequestAppearWait
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0201A776
	ldr r0, [r5, #0x14]
	bl mMsg_MainSetup_Window
_0201A748:
	movs r7, #1
	b _0201A776
_0201A74C:
	ldr r1, [r5, #0x14]
	cmp r1, #0
	beq _0201A748
	adds r0, r1, #0
	adds r0, #0x70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0201A748
	adds r0, r1, #0
	bl mMsg_RequestDisappearWait
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #1
	bne _0201A776
	ldr r0, [r5, #0x14]
	bl mMsg_MainSetup_Window
	strb r4, [r6]
_0201A776:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201A780
sub_0201A780: @ 0x0201A780
	push {r4, r5, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r5, #0
	ldr r0, [r2, #0x14]
	cmp r0, #0
	bne _0201A794
	movs r0, #1
	b _0201A7C2
_0201A794:
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r4, r1, #0x18
	adds r3, r2, #0
	adds r3, #0x64
	cmp r0, #1
	bne _0201A7B2
	asrs r1, r4, #0x18
	adds r0, r3, r1
	strb r5, [r0]
	cmp r1, #1
	bne _0201A7B2
	adds r0, r2, #0
	adds r0, #0x6d
	strb r5, [r0]
_0201A7B2:
	movs r5, #0
	asrs r0, r4, #0x18
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201A7C0
	movs r5, #1
_0201A7C0:
	adds r0, r5, #0
_0201A7C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0201A7C8
sub_0201A7C8: @ 0x0201A7C8
	push {r4, lr}
	adds r2, r0, #0
	movs r4, #0
	ldr r1, _0201A800 @ =0x03001B50
	ldr r3, _0201A804 @ =0x0000084E
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201A7F6
	ldr r3, _0201A808 @ =0x0000081A
	adds r0, r1, r3
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0201A7F6
	adds r0, r2, #0
	adds r0, #0x2c
	ldr r1, _0201A80C @ =0x00004650
	bl sub_0201A810
	cmp r0, #1
	bne _0201A7F8
_0201A7F6:
	movs r4, #1
_0201A7F8:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0201A800: .4byte 0x03001B50
_0201A804: .4byte 0x0000084E
_0201A808: .4byte 0x0000081A
_0201A80C: .4byte 0x00004650

	thumb_func_start sub_0201A810
sub_0201A810: @ 0x0201A810
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bgt _0201A822
	movs r3, #1
	b _0201A84A
_0201A822:
	ldr r0, _0201A838 @ =0x03001B50
	ldr r1, _0201A83C @ =0x00000818
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _0201A840 @ =0x000003FF
	ands r0, r1
	cmp r0, #0
	beq _0201A844
	strh r3, [r2]
	b _0201A84A
	.align 2, 0
_0201A838: .4byte 0x03001B50
_0201A83C: .4byte 0x00000818
_0201A840: .4byte 0x000003FF
_0201A844:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_0201A84A:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201A854
sub_0201A854: @ 0x0201A854
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r2, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #2
	bne _0201A864
	b _0201AA3A
_0201A864:
	cmp r1, #2
	bgt _0201A86E
	cmp r1, #1
	beq _0201A956
	b _0201AA3A
_0201A86E:
	cmp r1, #3
	beq _0201A8DE
	cmp r1, #4
	beq _0201A878
	b _0201AA3A
_0201A878:
	movs r0, #0x17
	str r0, [sp]
	movs r0, #0x11
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0x10
	bl sub_02019BD8
	movs r0, #0x1b
	str r0, [sp]
	movs r0, #0x13
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0x15
	bl sub_02019BD8
	movs r0, #0x1f
	str r0, [sp]
	movs r0, #0x1a
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #3
	movs r3, #0x1a
	bl sub_02019BD8
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #4
	movs r3, #0x17
	bl sub_02019BD8
	movs r0, #0x1d
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #5
	movs r3, #0x16
	bl sub_02019BD8
	b _0201AA78
_0201A8DE:
	movs r0, #0x17
	str r0, [sp]
	movs r0, #0x11
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0x17
	bl sub_02019BD8
	movs r0, #0x1b
	str r0, [sp]
	movs r0, #0x13
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0x1b
	bl sub_02019BD8
	movs r4, #0x1f
	str r4, [sp]
	movs r0, #0x1a
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #3
	movs r3, #0x1f
	bl sub_02019BD8
	movs r0, #0x1d
	str r0, [sp]
	movs r0, #0x15
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #4
	movs r3, #0x1d
	bl sub_02019BD8
	str r4, [sp]
	movs r0, #9
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #5
	movs r3, #0x1e
	bl sub_02019BD8
	movs r0, #0xb
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #6
	movs r3, #0xa
	bl sub_02019BD8
	b _0201AA78
_0201A956:
	adds r0, r2, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201A9BE
	movs r0, #0xa
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0x16
	bl sub_02019BD8
	movs r0, #0xe
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0x1a
	bl sub_02019BD8
	movs r0, #0xd
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #3
	movs r3, #0x1e
	bl sub_02019BD8
	movs r4, #0x15
	str r4, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #4
	movs r3, #0x1d
	bl sub_02019BD8
	movs r0, #0x1f
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #5
	b _0201AA32
_0201A9BE:
	adds r0, r2, #0
	adds r0, #0x6e
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201AA3A
	movs r0, #0x10
	str r0, [sp]
	movs r4, #0x14
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #1
	movs r3, #8
	bl sub_02019BD8
	str r4, [sp]
	movs r0, #0x1b
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0xa
	bl sub_02019BD8
	movs r0, #0x19
	str r0, [sp]
	movs r4, #0x1f
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #3
	movs r3, #0x15
	bl sub_02019BD8
	movs r0, #0x17
	str r0, [sp]
	movs r0, #0x1d
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #4
	movs r3, #0x10
	bl sub_02019BD8
	movs r0, #0xf
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #5
	movs r3, #7
	bl sub_02019BD8
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #7
	movs r2, #6
_0201AA32:
	movs r3, #0x1f
	bl sub_02019BD8
	b _0201AA78
_0201AA3A:
	movs r5, #1
	mov r0, sp
	adds r0, #9
	mov r1, sp
	adds r1, #0xa
	adds r7, r0, #0
	adds r6, r1, #0
_0201AA48:
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	str r7, [sp]
	str r6, [sp, #4]
	ldr r0, _0201AA8C @ =0x020357F4
	movs r1, #7
	adds r2, r4, #0
	add r3, sp, #8
	bl sub_02019BA8
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r0, [r7]
	str r0, [sp]
	ldrb r0, [r6]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #7
	adds r2, r4, #0
	bl sub_02019BD8
	adds r5, #1
	cmp r5, #6
	ble _0201AA48
_0201AA78:
	ldr r0, _0201AA90 @ =0x020000E0
	ldr r1, _0201AA94 @ =0x050000E0
	movs r2, #8
	bl CpuFastSet
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201AA8C: .4byte 0x020357F4
_0201AA90: .4byte 0x020000E0
_0201AA94: .4byte 0x050000E0

	thumb_func_start sub_0201AA98
sub_0201AA98: @ 0x0201AA98
	push {r4, r5, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r3, r2, #0
	adds r3, #0x50
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r4, _0201AB20 @ =0x03001B50
	cmp r0, #0
	bne _0201AAE8
	cmp r5, #1
	beq _0201AAE8
	ldr r1, _0201AB24 @ =0x00000828
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2, #0x34]
	adds r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2, #0x36]
	subs r1, #0xc
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x48
	strh r1, [r0]
	ldr r1, _0201AB28 @ =0x0000084A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x44
	strh r1, [r0]
	ldr r1, _0201AB2C @ =0x00000848
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x46
	strh r1, [r0]
	strb r5, [r3]
_0201AAE8:
	ldr r5, _0201AB24 @ =0x00000828
	adds r2, r4, r5
	ldrh r1, [r2]
	ldr r0, _0201AB30 @ =0x0000FFFC
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	ldr r0, _0201AB34 @ =0x0000082A
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r5, #0xc0
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0201AB38 @ =0x0000081E
	adds r0, r4, r1
	strh r3, [r0]
	ldr r5, _0201AB28 @ =0x0000084A
	adds r0, r4, r5
	strh r3, [r0]
	adds r1, #0x2a
	adds r0, r4, r1
	strh r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201AB20: .4byte 0x03001B50
_0201AB24: .4byte 0x00000828
_0201AB28: .4byte 0x0000084A
_0201AB2C: .4byte 0x00000848
_0201AB30: .4byte 0x0000FFFC
_0201AB34: .4byte 0x0000082A
_0201AB38: .4byte 0x0000081E

	thumb_func_start sub_0201AB3C
sub_0201AB3C: @ 0x0201AB3C
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r2, #0
	adds r5, #0x50
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bne _0201AB98
	ldr r3, _0201ABA0 @ =0x03001B50
	ldrh r1, [r2, #0x34]
	ldr r4, _0201ABA4 @ =0x00000828
	adds r0, r3, r4
	strh r1, [r0]
	ldrh r1, [r2, #0x36]
	ldr r0, _0201ABA8 @ =0x0000082A
	adds r4, r3, r0
	strh r1, [r4]
	ldr r0, _0201ABAC @ =0x0203E9A0
	ldrh r0, [r0]
	cmp r0, #1
	bne _0201AB70
	ldr r0, _0201ABB0 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r4]
_0201AB70:
	adds r0, r2, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r4, _0201ABB4 @ =0x0000081E
	adds r0, r3, r4
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r4, #0x2c
	adds r0, r3, r4
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r1, [r0]
	ldr r2, _0201ABB8 @ =0x00000848
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, #0
	strb r0, [r5]
_0201AB98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201ABA0: .4byte 0x03001B50
_0201ABA4: .4byte 0x00000828
_0201ABA8: .4byte 0x0000082A
_0201ABAC: .4byte 0x0203E9A0
_0201ABB0: .4byte 0x0000FDFF
_0201ABB4: .4byte 0x0000081E
_0201ABB8: .4byte 0x00000848

	thumb_func_start sub_0201ABBC
sub_0201ABBC: @ 0x0201ABBC
	push {lr}
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq _0201ABD8
	ldr r0, _0201ABE0 @ =0x03001B50
	movs r2, #0x85
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201ABD8
	adds r0, r1, #0
	bl mMsg_Main_Window
_0201ABD8:
	bl sub_0201C5A0
	pop {r0}
	bx r0
	.align 2, 0
_0201ABE0: .4byte 0x03001B50

	thumb_func_start sub_0201ABE4
sub_0201ABE4: @ 0x0201ABE4
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r1, #0
	ldr r0, _0201AC34 @ =0x03001B50
	movs r2, #0x85
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201AC2A
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0201AC2A
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0201A714
	cmp r0, #1
	bne _0201AC28
	adds r0, r4, #0
	adds r0, #0x5f
	strb r5, [r0]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0x10]
	adds r0, r4, #0
	bl sub_0201B6D0
_0201AC28:
	movs r1, #1
_0201AC2A:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0201AC34: .4byte 0x03001B50

	thumb_func_start sub_0201AC38
sub_0201AC38: @ 0x0201AC38
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r1, #0
	ldr r0, _0201AC88 @ =0x03001B50
	movs r2, #0x85
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201AC7E
	adds r0, r4, #0
	adds r0, #0x58
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0201AC7E
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0201A714
	cmp r0, #1
	bne _0201AC7C
	adds r0, r4, #0
	adds r0, #0x5d
	strb r5, [r0]
	ldr r0, [r4, #0x14]
	str r0, [r4, #8]
	adds r0, r4, #0
	bl sub_0201AE0C
_0201AC7C:
	movs r1, #1
_0201AC7E:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0201AC88: .4byte 0x03001B50

	thumb_func_start sub_0201AC8C
sub_0201AC8C: @ 0x0201AC8C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0201ACC2
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0201A714
	cmp r0, #1
	bne _0201ACC0
	adds r0, r4, #0
	adds r0, #0x5e
	strb r5, [r0]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0xc]
	adds r0, r4, #0
	bl sub_0201B1B8
_0201ACC0:
	movs r1, #1
_0201ACC2:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201ACCC
sub_0201ACCC: @ 0x0201ACCC
	ldr r1, _0201ACF0 @ =0x03002970
	ldr r3, [r1]
	movs r2, #0xe6
	lsls r2, r2, #6
	ldr r1, _0201ACF4 @ =0x03003120
	str r2, [r1, #8]
	str r3, [r1]
	adds r1, #0x26
	movs r3, #0
	movs r2, #1
	strb r2, [r1]
	adds r2, r0, #0
	adds r2, #0x6a
	movs r1, #2
	strb r1, [r2]
	adds r0, #0x71
	strb r3, [r0]
	bx lr
	.align 2, 0
_0201ACF0: .4byte 0x03002970
_0201ACF4: .4byte 0x03003120

	thumb_func_start sub_0201ACF8
sub_0201ACF8: @ 0x0201ACF8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	ldr r3, _0201AD10 @ =0x03003120
	adds r2, r3, #0
	adds r2, #0x25
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _0201AD14
	adds r1, r0, #0
	b _0201AD20
	.align 2, 0
_0201AD10: .4byte 0x03003120
_0201AD14:
	adds r0, r3, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201AD20
	movs r1, #2
_0201AD20:
	cmp r1, #1
	bne _0201AD2A
	adds r0, r4, #0
	adds r0, #0x6d
	strb r1, [r0]
_0201AD2A:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201AD34
sub_0201AD34: @ 0x0201AD34
	push {lr}
	adds r3, r0, #0
	ldr r0, _0201AD60 @ =0x03001B40
	ldr r2, [r0]
	movs r1, #0xe6
	lsls r1, r1, #6
	ldr r0, _0201AD64 @ =0x03003120
	str r1, [r0, #8]
	str r2, [r0]
	adds r1, r0, #0
	adds r1, #0x26
	movs r2, #1
	strb r2, [r1]
	ldr r1, [r0, #0x18]
	ldr r0, _0201AD68 @ =0xFFFE0101
	cmp r1, r0
	bne _0201AD6C
	adds r0, r3, #0
	adds r0, #0x70
	strb r2, [r0]
	b _0201AD74
	.align 2, 0
_0201AD60: .4byte 0x03001B40
_0201AD64: .4byte 0x03003120
_0201AD68: .4byte 0xFFFE0101
_0201AD6C:
	adds r1, r3, #0
	adds r1, #0x70
	movs r0, #0
	strb r0, [r1]
_0201AD74:
	adds r0, r3, #0
	adds r0, #0x6a
	movs r1, #1
	strb r1, [r0]
	adds r0, #7
	strb r1, [r0]
	pop {r0}
	bx r0

	thumb_func_start sub_0201AD84
sub_0201AD84: @ 0x0201AD84
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r2, _0201AD9C @ =0x03003120
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0201ADA0
	adds r3, r0, #0
	b _0201ADAC
	.align 2, 0
_0201AD9C: .4byte 0x03003120
_0201ADA0:
	adds r0, r2, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201ADAC
	movs r3, #2
_0201ADAC:
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _0201ADCA
	cmp r3, #1
	bne _0201ADCA
	ldr r0, _0201ADD4 @ =0x0203E9A0
	movs r1, #1
	strh r3, [r0]
	ldr r0, _0201ADD8 @ =0x03001B40
	ldr r0, [r0]
	strb r1, [r0, #0x13]
_0201ADCA:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0201ADD4: .4byte 0x0203E9A0
_0201ADD8: .4byte 0x03001B40

	thumb_func_start sub_0201ADDC
sub_0201ADDC: @ 0x0201ADDC
	bx lr
	.align 2, 0

	thumb_func_start sub_0201ADE0
sub_0201ADE0: @ 0x0201ADE0
	adds r0, #0x58
	strb r1, [r0]
	movs r0, #1
	bx lr

	thumb_func_start sub_0201ADE8
sub_0201ADE8: @ 0x0201ADE8
	adds r0, #0x58
	movs r1, #1
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201ADF4
sub_0201ADF4: @ 0x0201ADF4
	adds r0, #0x58
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201AE00
sub_0201AE00: @ 0x0201AE00
	adds r0, #0x58
	movs r1, #3
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201AE0C
sub_0201AE0C: @ 0x0201AE0C
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x58
	ldrb r0, [r2]
	cmp r0, #3
	bhi _0201AE34
	ldr r1, _0201AE3C @ =0x0202AFCC
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0201AE34
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	strh r0, [r4, #0x2c]
_0201AE34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201AE3C: .4byte 0x0202AFCC

	thumb_func_start sub_0201AE40
sub_0201AE40: @ 0x0201AE40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0201AE78 @ =0x03003120
	ldr r1, [r5, #0x18]
	ldr r0, _0201AE7C @ =0xFFFE0101
	movs r2, #0xb
	cmp r1, r0
	bne _0201AE52
	movs r2, #0x1e
_0201AE52:
	ldr r0, _0201AE80 @ =0x03002980
	adds r1, r2, #0
	bl mMsg_RequestAppear
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	adds r1, #0x58
	cmp r0, #1
	bne _0201AEAE
	ldr r1, [r5, #0x18]
	ldr r0, _0201AE84 @ =0xFFFE0202
	cmp r1, r0
	bne _0201AE88
	adds r0, r4, #0
	bl sub_0201ACCC
	b _0201AE8E
	.align 2, 0
_0201AE78: .4byte 0x03003120
_0201AE7C: .4byte 0xFFFE0101
_0201AE80: .4byte 0x03002980
_0201AE84: .4byte 0xFFFE0202
_0201AE88:
	adds r0, r4, #0
	bl sub_0201AD34
_0201AE8E:
	adds r0, r4, #0
	movs r1, #2
	bl sub_0201A854
	adds r0, r4, #0
	movs r1, #2
	bl sub_0201AA98
	adds r1, r4, #0
	adds r1, #0x58
	ldrb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x53
	strb r0, [r2]
	ldr r0, _0201AEB8 @ =0x03002980
	str r0, [r4, #0x14]
_0201AEAE:
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201AEB8: .4byte 0x03002980

	thumb_func_start sub_0201AEBC
sub_0201AEBC: @ 0x0201AEBC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x71
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201AED6
	adds r0, r4, #0
	bl sub_0201ACF8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	b _0201AF14
_0201AED6:
	adds r5, r4, #0
	adds r5, #0x74
	ldrb r0, [r5]
	cmp r0, #0
	bne _0201AF00
	adds r0, r4, #0
	bl sub_0201AD84
	adds r1, r4, #0
	adds r1, #0x75
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0201AEFA
	movs r0, #0x3c
	strb r0, [r5]
	b _0201AF14
_0201AEFA:
	adds r0, r4, #0
	adds r0, #0x60
	b _0201AF12
_0201AF00:
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0201AF14
	adds r0, r4, #0
	adds r0, #0x75
	ldrb r1, [r0]
	subs r0, #0x15
_0201AF12:
	strb r1, [r0]
_0201AF14:
	ldr r0, [r4, #0x14]
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0201AF42
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0201AF42
	adds r0, r4, #0
	bl sub_0201ADF4
	cmp r0, #0
	beq _0201AF42
	adds r0, r4, #0
	bl sub_0201AE0C
_0201AF42:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0201AF48
sub_0201AF48: @ 0x0201AF48
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0201AF9C @ =0x0202B00C
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r2, [r0]
	cmp r2, #1
	bne _0201AFD2
	ldr r1, _0201AFA0 @ =0x03001B50
	ldr r3, _0201AFA4 @ =0x00000856
	adds r0, r1, r3
	movs r3, #0
	strb r3, [r0]
	ldr r4, _0201AFA8 @ =0x00000857
	adds r0, r1, r4
	strb r3, [r0]
	subs r4, #9
	adds r0, r1, r4
	strb r3, [r0]
	ldr r0, _0201AFAC @ =0x0000084F
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, r5, #0
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0201AFB0
	ldr r0, [r5, #0x14]
	adds r0, #0x7b
	strb r2, [r0]
	ldr r0, [r5, #0x14]
	adds r0, #0x79
	strb r2, [r0]
	str r3, [r5, #0x28]
	b _0201AFBA
	.align 2, 0
_0201AF9C: .4byte 0x0202B00C
_0201AFA0: .4byte 0x03001B50
_0201AFA4: .4byte 0x00000856
_0201AFA8: .4byte 0x00000857
_0201AFAC: .4byte 0x0000084F
_0201AFB0:
	movs r0, #0x3c
	str r0, [r5, #0x28]
	movs r0, #0x28
	bl sub_02019D78
_0201AFBA:
	adds r2, r5, #0
	adds r2, #0x58
	ldrb r0, [r2]
	adds r3, r5, #0
	adds r3, #0x53
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x62
	strb r1, [r0]
	adds r6, r2, #0
	b _0201B032
_0201AFD2:
	ldr r0, [r5, #0x14]
	adds r4, r5, #0
	adds r4, #0x60
	movs r1, #0
	ldrsb r1, [r4, r1]
	subs r1, #1
	lsls r1, r1, #2
	add r1, sp
	ldr r1, [r1]
	bl mMsg_ChangeMsgData
	adds r6, r5, #0
	adds r6, #0x58
	cmp r0, #1
	bne _0201B032
	ldr r0, [r5, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B032
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0x28
	cmp r0, #1
	bne _0201B008
	movs r1, #0x27
_0201B008:
	adds r0, r1, #0
	bl sub_02019D78
	ldr r0, _0201B040 @ =0x03001B50
	ldr r2, _0201B044 @ =0x00000856
	adds r1, r0, r2
	movs r4, #0
	strb r4, [r1]
	ldr r3, _0201B048 @ =0x00000857
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5, #0x14]
	bl mMsg_MainSetup_Window
	ldrb r0, [r6]
	adds r1, r5, #0
	adds r1, #0x53
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x62
	strb r4, [r0]
_0201B032:
	movs r0, #0
	strb r0, [r6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201B040: .4byte 0x03001B50
_0201B044: .4byte 0x00000856
_0201B048: .4byte 0x00000857

	thumb_func_start sub_0201B04C
sub_0201B04C: @ 0x0201B04C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x70
	ldrb r1, [r0]
	cmp r1, #1
	bne _0201B074
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0201B074
	subs r0, #1
	str r0, [r4, #0x28]
	cmp r0, #0
	bne _0201B15A
	ldr r0, [r4, #0x14]
	adds r0, #0x7b
	strb r1, [r0]
	ldr r0, [r4, #0x14]
	adds r0, #0x79
	strb r1, [r0]
	b _0201B15A
_0201B074:
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x7c
	ldrb r2, [r0]
	cmp r2, #0
	bne _0201B128
	adds r5, r4, #0
	adds r5, #0x6d
	ldrb r0, [r5]
	cmp r0, #1
	bne _0201B0C0
	adds r1, r4, #0
	adds r1, #0x53
	movs r0, #3
	strb r0, [r1]
	ldr r4, _0201B0B4 @ =0x03001B50
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x3f
	movs r3, #0
	bl sub_02019B1C
	ldr r0, _0201B0B8 @ =0x0000082A
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _0201B0BC @ =0x0000FEFF
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	strb r1, [r5]
	b _0201B15A
	.align 2, 0
_0201B0B4: .4byte 0x03001B50
_0201B0B8: .4byte 0x0000082A
_0201B0BC: .4byte 0x0000FEFF
_0201B0C0:
	adds r0, r4, #0
	adds r0, #0x53
	strb r2, [r0]
	movs r1, #0
	strh r2, [r4, #0x2c]
	adds r0, #0x1d
	strb r1, [r0]
	subs r0, #0x13
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0201B0E0
	cmp r0, #3
	beq _0201B0EA
	b _0201B0F2
_0201B0E0:
	adds r0, r4, #0
	movs r1, #1
	bl sub_0201A854
	b _0201B0F2
_0201B0EA:
	adds r0, r4, #0
	movs r1, #3
	bl sub_0201A854
_0201B0F2:
	ldr r0, [r4, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	movs r1, #2
	bl sub_0201AB3C
	ldr r0, [r4, #0x14]
	ldr r2, [r0, #0x50]
	movs r0, #0
	movs r1, #0x90
	bl mMsg_CopyTilesToVram
	ldr r0, _0201B120 @ =0x03001B50
	ldr r1, _0201B124 @ =0x00000856
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bne _0201B15A
	adds r0, r4, #0
	adds r0, #0x72
	strb r1, [r0]
	b _0201B15A
	.align 2, 0
_0201B120: .4byte 0x03001B50
_0201B124: .4byte 0x00000856
_0201B128:
	adds r0, r1, #0
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0201B15A
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201B15A
	ldr r0, _0201B160 @ =0x03001B50
	ldr r2, _0201B164 @ =0x00000856
	adds r0, r0, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _0201B15A
	adds r0, r1, #0
	adds r0, #0x7b
	strb r2, [r0]
	ldr r0, [r4, #0x14]
	adds r0, #0x79
	strb r2, [r0]
_0201B15A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201B160: .4byte 0x03001B50
_0201B164: .4byte 0x00000856

	thumb_func_start sub_0201B168
sub_0201B168: @ 0x0201B168
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B16C
sub_0201B16C: @ 0x0201B16C
	push {lr}
	ldr r0, _0201B188 @ =0x03001B50
	movs r1, #1
	movs r2, #1
	bl sub_02019B58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0201B184
	bl sub_0201A6C8
_0201B184:
	pop {r0}
	bx r0
	.align 2, 0
_0201B188: .4byte 0x03001B50

	thumb_func_start sub_0201B18C
sub_0201B18C: @ 0x0201B18C
	adds r0, #0x59
	strb r1, [r0]
	movs r0, #1
	bx lr

	thumb_func_start sub_0201B194
sub_0201B194: @ 0x0201B194
	adds r0, #0x59
	movs r1, #1
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B1A0
sub_0201B1A0: @ 0x0201B1A0
	adds r0, #0x59
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B1AC
sub_0201B1AC: @ 0x0201B1AC
	adds r0, #0x59
	movs r1, #3
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B1B8
sub_0201B1B8: @ 0x0201B1B8
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x59
	ldrb r0, [r2]
	cmp r0, #3
	bhi _0201B1E0
	ldr r1, _0201B1E8 @ =0x0202AFEC
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0201B1E0
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	strh r0, [r4, #0x2c]
_0201B1E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201B1E8: .4byte 0x0202AFEC

	thumb_func_start sub_0201B1EC
sub_0201B1EC: @ 0x0201B1EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0201B234 @ =0x03003060
	adds r0, r5, #0
	movs r1, #0x15
	bl mMsg_RequestAppear
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0201B224
	adds r0, r4, #0
	movs r1, #3
	bl sub_0201A854
	adds r0, r4, #0
	movs r1, #3
	bl sub_0201AA98
	adds r0, r4, #0
	adds r0, #0x59
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x54
	movs r2, #0
	strb r0, [r1]
	strh r2, [r4, #0x2c]
	str r5, [r4, #0x14]
_0201B224:
	adds r1, r4, #0
	adds r1, #0x59
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201B234: .4byte 0x03003060

	thumb_func_start sub_0201B238
sub_0201B238: @ 0x0201B238
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x14]
	adds r0, r2, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201B254
	adds r0, r4, #0
	bl sub_0201B1AC
	cmp r0, #1
	bne _0201B2D8
	b _0201B2BC
_0201B254:
	adds r0, r2, #0
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0201B2D8
	adds r0, r2, #0
	adds r0, #0x77
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0201B2A2
	ldr r0, [r2, #0x54]
	adds r1, r2, #0
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _0201B290
	ldr r0, [r4, #0x14]
	ldr r0, [r0, #0x5c]
	cmp r0, #0x16
	beq _0201B2B2
_0201B290:
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x96
	lsls r1, r1, #2
	bl sub_0201A810
	cmp r0, #1
	bne _0201B2D8
	b _0201B2B2
_0201B2A2:
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x96
	lsls r1, r1, #2
	bl sub_0201A810
	cmp r0, #1
	bne _0201B2C4
_0201B2B2:
	adds r0, r4, #0
	bl sub_0201B1A0
	cmp r0, #0
	beq _0201B2D8
_0201B2BC:
	adds r0, r4, #0
	bl sub_0201B1B8
	b _0201B2D8
_0201B2C4:
	ldr r0, _0201B2E0 @ =0x03001B50
	ldr r1, _0201B2E4 @ =0x00000856
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201B2D8
	adds r1, r4, #0
	adds r1, #0x72
	movs r0, #1
	strb r0, [r1]
_0201B2D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201B2E0: .4byte 0x03001B50
_0201B2E4: .4byte 0x00000856

	thumb_func_start sub_0201B2E8
sub_0201B2E8: @ 0x0201B2E8
	push {lr}
	adds r3, r0, #0
	movs r0, #0x59
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	adds r0, r3, #0
	adds r0, #0x54
	movs r1, #0
	strb r2, [r0]
	mov r2, ip
	strb r1, [r2]
	strh r1, [r3, #0x2c]
	ldr r0, _0201B320 @ =0x03001B50
	str r1, [r0, #8]
	movs r2, #0x85
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #1
	strb r2, [r1]
	ldr r1, _0201B324 @ =0x0000085A
	adds r0, r0, r1
	strb r2, [r0]
	movs r0, #0x14
	bl sub_02019D98
	pop {r0}
	bx r0
	.align 2, 0
_0201B320: .4byte 0x03001B50
_0201B324: .4byte 0x0000085A

	thumb_func_start sub_0201B328
sub_0201B328: @ 0x0201B328
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, _0201B378 @ =0x03001B50
	movs r1, #0x85
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201B380
	ldr r0, [r6, #8]
	cmp r0, #0x78
	ble _0201B36C
	ldr r0, [r4, #0x14]
	movs r1, #0x17
	bl mMsg_ChangeMsgData
	adds r5, r0, #0
	cmp r5, #1
	bne _0201B36C
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B36C
	movs r1, #0
	strh r1, [r4, #0x2c]
	ldr r0, [r4, #0x14]
	str r1, [r0, #0x60]
	bl mMsg_MainSetup_Window
	ldr r3, _0201B37C @ =0x00000851
	adds r0, r6, r3
	strb r5, [r0]
_0201B36C:
	ldr r1, _0201B378 @ =0x03001B50
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0201B414
	.align 2, 0
_0201B378: .4byte 0x03001B50
_0201B37C: .4byte 0x00000851
_0201B380:
	ldr r2, [r4, #0x14]
	adds r0, r2, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201B39E
	adds r0, r4, #0
	bl sub_0201B1AC
	cmp r0, #1
	bne _0201B414
	adds r0, r4, #0
	bl sub_0201B1B8
	b _0201B414
_0201B39E:
	adds r0, r2, #0
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0201B414
	adds r0, r2, #0
	adds r0, #0x77
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0201B3DC
	ldr r0, [r2, #0x54]
	adds r1, r2, #0
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _0201B414
	ldr r0, [r4, #0x14]
	ldr r0, [r0, #0x5c]
	cmp r0, #0x17
	bne _0201B414
	b _0201B3EC
_0201B3DC:
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x96
	lsls r1, r1, #2
	bl sub_0201A810
	cmp r0, #1
	bne _0201B402
_0201B3EC:
	adds r0, r4, #0
	bl sub_0201B1A0
	cmp r0, #0
	beq _0201B414
	adds r0, r4, #0
	bl sub_0201B1B8
	movs r0, #0x78
	str r0, [r6, #8]
	b _0201B414
_0201B402:
	ldr r1, _0201B41C @ =0x00000856
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201B414
	adds r1, r4, #0
	adds r1, #0x72
	movs r0, #1
	strb r0, [r1]
_0201B414:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201B41C: .4byte 0x00000856

	thumb_func_start sub_0201B420
sub_0201B420: @ 0x0201B420
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r0, #0x54
	movs r5, #0
	strb r1, [r0]
	strb r5, [r2]
	ldr r4, _0201B45C @ =0x03001B50
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0201B454
	ldr r0, _0201B460 @ =0x00000816
	adds r2, r4, r0
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0201B44E
	ldrh r0, [r2]
	bl sub_02019D88
_0201B44E:
	bl sub_02027068
	str r5, [r4, #8]
_0201B454:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201B45C: .4byte 0x03001B50
_0201B460: .4byte 0x00000816

	thumb_func_start sub_0201B464
sub_0201B464: @ 0x0201B464
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	adds r0, #0x7c
	ldrb r5, [r0]
	cmp r5, #0
	bne _0201B4A8
	adds r0, r4, #0
	adds r0, #0x54
	strb r5, [r0]
	adds r6, r4, #0
	adds r6, #0x5e
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #1
	bne _0201B48C
	adds r0, r4, #0
	movs r1, #1
	bl sub_0201A854
_0201B48C:
	strb r5, [r6]
	ldr r0, [r4, #0xc]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	movs r1, #3
	bl sub_0201AB3C
	ldr r0, [r4, #0x14]
	ldr r2, [r0, #0x50]
	movs r0, #0
	movs r1, #0x90
	bl mMsg_CopyTilesToVram
	strh r5, [r4, #0x2c]
_0201B4A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201B4B0
sub_0201B4B0: @ 0x0201B4B0
	push {r4, r5, r6, lr}
	ldr r4, _0201B55C @ =0x03001B50
	ldr r0, _0201B560 @ =0x0000082A
	adds r2, r4, r0
	ldrh r1, [r2]
	ldr r0, _0201B564 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0201B568 @ =0x00000828
	adds r3, r4, r0
	ldrh r2, [r3]
	ldr r1, _0201B56C @ =0x0000FFFC
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r0, _0201B570 @ =0x00000824
	adds r3, r4, r0
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	movs r2, #1
	movs r6, #0
	orrs r0, r2
	strh r0, [r3]
	ldr r3, _0201B574 @ =0x00000822
	adds r5, r4, r3
	ldrh r0, [r5]
	adds r3, r1, #0
	ands r3, r0
	movs r0, #2
	orrs r3, r0
	orrs r3, r6
	strh r3, [r5]
	ldr r0, _0201B578 @ =0x00000826
	adds r2, r4, r0
	ldrh r0, [r2]
	ands r1, r0
	movs r0, #3
	orrs r1, r0
	strh r1, [r2]
	ldr r0, _0201B57C @ =0x03001B40
	ldr r0, [r0]
	ldr r1, _0201B580 @ =0x0000193A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201B51E
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
	orrs r3, r0
_0201B51E:
	strh r3, [r5]
	ldr r0, _0201B584 @ =0x0203E9A0
	ldrh r0, [r0]
	cmp r0, #1
	bne _0201B534
	ldr r3, _0201B560 @ =0x0000082A
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _0201B588 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
_0201B534:
	ldr r1, _0201B58C @ =0x00000842
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #6
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _0201B590 @ =0x00000844
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201B55C: .4byte 0x03001B50
_0201B560: .4byte 0x0000082A
_0201B564: .4byte 0x0000E0FF
_0201B568: .4byte 0x00000828
_0201B56C: .4byte 0x0000FFFC
_0201B570: .4byte 0x00000824
_0201B574: .4byte 0x00000822
_0201B578: .4byte 0x00000826
_0201B57C: .4byte 0x03001B40
_0201B580: .4byte 0x0000193A
_0201B584: .4byte 0x0203E9A0
_0201B588: .4byte 0x0000FDFF
_0201B58C: .4byte 0x00000842
_0201B590: .4byte 0x00000844

	thumb_func_start sub_0201B594
sub_0201B594: @ 0x0201B594
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r6, _0201B630 @ =0x03001B50
	ldr r0, [r6, #0x10]
	ldr r1, _0201B634 @ =0x00034BC0
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r7, r4, #0
	adds r7, #0x63
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r5, r0
	beq _0201B616
	lsls r0, r5, #4
	ldr r1, _0201B638 @ =0x0202B014
	adds r0, r0, r1
	ldr r1, _0201B63C @ =0x02000190
	movs r2, #8
	bl CpuSet
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #1
	ldr r1, _0201B640 @ =0x0202B194
	adds r0, r0, r1
	ldr r1, _0201B644 @ =0x020001D6
	movs r2, #5
	bl CpuSet
	ldr r0, _0201B648 @ =0x02000180
	ldr r1, _0201B64C @ =0x05000180
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0201B650 @ =0x020001C0
	ldr r1, _0201B654 @ =0x050001C0
	movs r2, #8
	bl CpuFastSet
	lsls r4, r5, #3
	ldr r0, _0201B658 @ =0x02034EE4
	adds r4, r4, r0
	ldr r1, _0201B65C @ =0x02000102
	adds r0, r4, #0
	movs r2, #4
	bl CpuSet
	ldr r1, _0201B660 @ =0x02000122
	adds r0, r4, #0
	movs r2, #4
	bl CpuSet
	ldr r0, _0201B664 @ =0x02000100
	ldr r1, _0201B668 @ =0x05000100
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0201B66C @ =0x02000120
	ldr r1, _0201B670 @ =0x05000120
	movs r2, #8
	bl CpuFastSet
	strb r5, [r7]
_0201B616:
	movs r0, #0x82
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, _0201B674 @ =0x00002441
	strh r0, [r1]
	ldr r0, _0201B678 @ =0x0000081C
	adds r1, r6, r0
	ldr r0, _0201B67C @ =0x00001006
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201B630: .4byte 0x03001B50
_0201B634: .4byte 0x00034BC0
_0201B638: .4byte 0x0202B014
_0201B63C: .4byte 0x02000190
_0201B640: .4byte 0x0202B194
_0201B644: .4byte 0x020001D6
_0201B648: .4byte 0x02000180
_0201B64C: .4byte 0x05000180
_0201B650: .4byte 0x020001C0
_0201B654: .4byte 0x050001C0
_0201B658: .4byte 0x02034EE4
_0201B65C: .4byte 0x02000102
_0201B660: .4byte 0x02000122
_0201B664: .4byte 0x02000100
_0201B668: .4byte 0x05000100
_0201B66C: .4byte 0x02000120
_0201B670: .4byte 0x05000120
_0201B674: .4byte 0x00002441
_0201B678: .4byte 0x0000081C
_0201B67C: .4byte 0x00001006

	thumb_func_start sub_0201B680
sub_0201B680: @ 0x0201B680
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	bx lr

	thumb_func_start sub_0201B688
sub_0201B688: @ 0x0201B688
	adds r0, #0x5a
	movs r1, #1
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B694
sub_0201B694: @ 0x0201B694
	adds r0, #0x5a
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B6A0
sub_0201B6A0: @ 0x0201B6A0
	adds r0, #0x5a
	movs r1, #3
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B6AC
sub_0201B6AC: @ 0x0201B6AC
	adds r0, #0x5a
	movs r1, #4
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B6B8
sub_0201B6B8: @ 0x0201B6B8
	adds r0, #0x5a
	movs r1, #5
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B6C4
sub_0201B6C4: @ 0x0201B6C4
	adds r0, #0x5a
	movs r1, #6
	strb r1, [r0]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_0201B6D0
sub_0201B6D0: @ 0x0201B6D0
	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x5a
	ldrb r0, [r2]
	cmp r0, #6
	bhi _0201B6F4
	ldr r1, _0201B6F8 @ =0x0202B284
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0201B6F4
	adds r0, r3, #0
	bl _call_via_r1
_0201B6F4:
	pop {r0}
	bx r0
	.align 2, 0
_0201B6F8: .4byte 0x0202B284

	thumb_func_start sub_0201B6FC
sub_0201B6FC: @ 0x0201B6FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0201B750 @ =0x03002980
	adds r0, r5, #0
	movs r1, #4
	bl mMsg_RequestAppear
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0201B740
	adds r0, r4, #0
	movs r1, #4
	bl sub_0201A854
	adds r0, r4, #0
	movs r1, #4
	bl sub_0201AA98
	movs r0, #0
	bl sub_0201C7E0
	bl sub_0201C870
	ldr r0, _0201B754 @ =0x030023C0
	ldr r1, _0201B758 @ =sub_0201CB50
	str r1, [r0]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x55
	strb r0, [r1]
	str r5, [r4, #0x14]
_0201B740:
	adds r1, r4, #0
	adds r1, #0x5a
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201B750: .4byte 0x03002980
_0201B754: .4byte 0x030023C0
_0201B758: .4byte sub_0201CB50

	thumb_func_start sub_0201B75C
sub_0201B75C: @ 0x0201B75C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201B77E
	adds r0, r4, #0
	bl sub_0201B6B8
	cmp r0, #1
	bne _0201B7A8
	adds r0, r4, #0
	bl sub_0201B6D0
	b _0201B7A8
_0201B77E:
	ldr r0, [r1, #0x54]
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _0201B7A8
	ldr r0, [r4, #0x14]
	ldr r0, [r0, #0x5c]
	cmp r0, #6
	bne _0201B7A8
	adds r0, r4, #0
	bl sub_0201B694
	cmp r0, #1
	bne _0201B7A8
	adds r0, r4, #0
	bl sub_0201B6D0
_0201B7A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201B7B0
sub_0201B7B0: @ 0x0201B7B0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	movs r1, #0xf
	bl mMsg_ChangeMsgData
	cmp r0, #1
	bne _0201B80E
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B80E
	ldr r0, [r4, #0x14]
	bl mMsg_MainSetup_Window
	adds r0, r4, #0
	adds r0, #0x5a
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x55
	movs r2, #0
	strb r0, [r1]
	ldr r1, _0201B81C @ =0x03001B40
	ldr r0, [r1]
	ldr r3, _0201B820 @ =0x0000397F
	adds r0, r0, r3
	strb r2, [r0]
	movs r0, #0x69
	adds r0, r0, r4
	mov ip, r0
	adds r5, r1, #0
	movs r3, #0
_0201B7F4:
	ldr r1, [r5]
	lsls r0, r2, #2
	adds r0, r0, r1
	str r3, [r0, #0x14]
	adds r2, #1
	cmp r2, #3
	ble _0201B7F4
	movs r0, #1
	mov r1, ip
	strb r0, [r1]
	movs r0, #0
	bl sub_0201C7E0
_0201B80E:
	adds r1, r4, #0
	adds r1, #0x5a
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201B81C: .4byte 0x03001B40
_0201B820: .4byte 0x0000397F

	thumb_func_start sub_0201B824
sub_0201B824: @ 0x0201B824
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0201C1B8
	adds r5, r0, #0
	subs r0, r5, #7
	cmp r0, #9
	bhi _0201B904
	lsls r0, r0, #2
	ldr r1, _0201B840 @ =_0201B844
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0201B840: .4byte _0201B844
_0201B844: @ jump table
	.4byte _0201B8E0 @ case 0
	.4byte _0201B86C @ case 1
	.4byte _0201B8A2 @ case 2
	.4byte _0201B86C @ case 3
	.4byte _0201B904 @ case 4
	.4byte _0201B904 @ case 5
	.4byte _0201B904 @ case 6
	.4byte _0201B904 @ case 7
	.4byte _0201B904 @ case 8
	.4byte _0201B86C @ case 9
_0201B86C:
	adds r0, r4, #0
	bl sub_0201B6A0
	cmp r0, #1
	bne _0201B904
	ldr r0, [r4, #0x14]
	adds r1, r5, #0
	bl mMsg_ChangeMsgData
	cmp r0, #1
	bne _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_MainSetup_Window
	ldr r0, [r4, #0x14]
	bl mMsg_ClearText
	adds r0, r4, #0
	bl sub_0201B6D0
	b _0201B904
_0201B8A2:
	adds r0, r4, #0
	bl sub_0201B6AC
	cmp r0, #1
	bne _0201B904
	ldr r0, [r4, #0x14]
	adds r1, r5, #0
	bl mMsg_ChangeMsgData
	adds r5, r0, #0
	cmp r5, #1
	bne _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_MainSetup_Window
	ldr r0, [r4, #0x14]
	bl mMsg_ClearText
	adds r0, r4, #0
	bl sub_0201B6D0
	adds r0, r4, #0
	adds r0, #0x6d
	strb r5, [r0]
	b _0201B904
_0201B8E0:
	ldr r0, [r4, #0x14]
	adds r1, r5, #0
	bl mMsg_ChangeMsgData
	cmp r0, #1
	bne _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B904
	ldr r0, [r4, #0x14]
	bl mMsg_MainSetup_Window
	ldr r0, [r4, #0x14]
	bl mMsg_ClearText
_0201B904:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201B90C
sub_0201B90C: @ 0x0201B90C
	adds r3, r0, #0
	adds r3, #0x5a
	ldrb r2, [r3]
	adds r0, #0x55
	movs r1, #0
	strb r2, [r0]
	strb r1, [r3]
	bx lr

	thumb_func_start sub_0201B91C
sub_0201B91C: @ 0x0201B91C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x14]
	ldr r0, [r1, #0x54]
	adds r1, #0x6c
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #1
	bl mMsg_CheckControlCode
	cmp r0, #0
	beq _0201B95A
	ldr r0, [r4, #0x14]
	movs r1, #0x11
	bl mMsg_ChangeMsgData
	adds r5, r0, #0
	cmp r5, #1
	bne _0201B95A
	ldr r0, [r4, #0x14]
	bl mMsg_RequestCursor
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0201B95A
	adds r0, r4, #0
	adds r0, #0x55
	strb r5, [r0]
	ldr r0, [r4, #0x14]
	bl mMsg_MainSetup_Window
_0201B95A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0201B960
sub_0201B960: @ 0x0201B960
	adds r3, r0, #0
	adds r3, #0x5a
	ldrb r2, [r3]
	adds r0, #0x55
	movs r1, #0
	strb r2, [r0]
	strb r1, [r3]
	bx lr

	thumb_func_start sub_0201B970
sub_0201B970: @ 0x0201B970
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201B98E
	adds r0, r4, #0
	bl sub_0201B6B8
	cmp r0, #1
	bne _0201B98E
	adds r0, r4, #0
	bl sub_0201B6D0
_0201B98E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0201B994
sub_0201B994: @ 0x0201B994
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r0, #0x69
	ldrb r3, [r0]
	cmp r3, #0
	bne _0201B9D8
	adds r2, r5, #0
	adds r2, #0x5a
	ldrb r1, [r2]
	subs r0, #0x14
	strb r1, [r0]
	ldr r1, _0201B9CC @ =0x03001B50
	ldr r4, _0201B9D0 @ =0x00000856
	adds r0, r1, r4
	strb r3, [r0]
	adds r4, #1
	adds r0, r1, r4
	strb r3, [r0]
	subs r4, #0xb
	adds r0, r1, r4
	strb r3, [r0]
	ldr r0, _0201B9D4 @ =0x0000084D
	adds r1, r1, r0
	strb r3, [r1]
	b _0201BA32
	.align 2, 0
_0201B9CC: .4byte 0x03001B50
_0201B9D0: .4byte 0x00000856
_0201B9D4: .4byte 0x0000084D
_0201B9D8:
	ldr r4, _0201BA40 @ =0x03002980
	adds r0, r4, #0
	movs r1, #0x12
	bl mMsg_RequestAppear
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0x5a
	mov r8, r4
	cmp r0, #1
	bne _0201BA32
	movs r3, #0
	movs r4, #0x55
	adds r4, r4, r5
	mov ip, r4
	ldr r4, _0201BA44 @ =0x03001B50
	ldr r6, _0201BA48 @ =0x03002970
	ldr r7, _0201BA4C @ =0x03002400
_0201B9FE:
	ldr r0, [r6]
	lsls r1, r3, #2
	adds r1, r1, r0
	ldm r7!, {r0}
	str r0, [r1, #0x14]
	adds r3, #1
	cmp r3, #3
	ble _0201B9FE
	ldrb r0, [r2]
	movs r1, #0
	mov r3, ip
	strb r0, [r3]
	mov r0, r8
	str r0, [r5, #0x14]
	ldr r3, _0201BA50 @ =0x00000856
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	subs r3, #0xb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
_0201BA32:
	movs r0, #0
	strb r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201BA40: .4byte 0x03002980
_0201BA44: .4byte 0x03001B50
_0201BA48: .4byte 0x03002970
_0201BA4C: .4byte 0x03002400
_0201BA50: .4byte 0x00000856

	thumb_func_start sub_0201BA54
sub_0201BA54: @ 0x0201BA54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x14]
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201BB00
	adds r1, r6, #0
	adds r1, #0x55
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x5f
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r5, r1, #0
	adds r4, r0, #0
	cmp r2, #1
	beq _0201BA8A
	cmp r2, #3
	beq _0201BA90
	adds r0, r6, #0
	movs r1, #4
	bl sub_0201AB3C
	b _0201BA98
_0201BA8A:
	adds r0, r6, #0
	movs r1, #1
	b _0201BA94
_0201BA90:
	adds r0, r6, #0
	movs r1, #3
_0201BA94:
	bl sub_0201A854
_0201BA98:
	movs r0, #0
	mov r8, r0
	mov r1, r8
	strb r1, [r4]
	ldr r0, [r6, #0x10]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	movs r1, #4
	bl sub_0201AB3C
	ldr r0, [r6, #0x14]
	ldr r2, [r0, #0x50]
	movs r0, #0
	movs r1, #0x90
	bl mMsg_CopyTilesToVram
	adds r7, r6, #0
	adds r7, #0x6d
	ldrb r0, [r7]
	cmp r0, #1
	bne _0201BAEA
	movs r0, #6
	strb r0, [r5]
	ldr r4, _0201BB0C @ =0x03001B50
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x3f
	movs r3, #0
	bl sub_02019B1C
	ldr r0, _0201BB10 @ =0x0000082A
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _0201BB14 @ =0x0000FEFF
	ands r0, r1
	movs r5, #0
	strh r0, [r4]
	movs r0, #0x14
	bl sub_02019D98
	strb r5, [r7]
_0201BAEA:
	adds r0, r6, #0
	adds r0, #0x69
	mov r1, r8
	strb r1, [r0]
	mov r0, r8
	strh r0, [r6, #0x2c]
	ldr r1, _0201BB18 @ =0x030023C0
	ldr r0, _0201BB1C @ =sub_0201A288
	str r0, [r1]
	bl sub_0201A218
_0201BB00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201BB0C: .4byte 0x03001B50
_0201BB10: .4byte 0x0000082A
_0201BB14: .4byte 0x0000FEFF
_0201BB18: .4byte 0x030023C0
_0201BB1C: .4byte sub_0201A288

	thumb_func_start sub_0201BB20
sub_0201BB20: @ 0x0201BB20
	bx lr
	.align 2, 0

	thumb_func_start sub_0201BB24
sub_0201BB24: @ 0x0201BB24
	push {lr}
	ldr r0, _0201BB40 @ =0x03001B50
	movs r1, #1
	movs r2, #1
	bl sub_02019B58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0201BB3C
	bl sub_0201A6C8
_0201BB3C:
	pop {r0}
	bx r0
	.align 2, 0
_0201BB40: .4byte 0x03001B50

	thumb_func_start sub_0201BB44
sub_0201BB44: @ 0x0201BB44
	adds r0, #0x57
	strb r1, [r0]
	movs r0, #1
	bx lr

	thumb_func_start sub_0201BB4C
sub_0201BB4C: @ 0x0201BB4C
	push {lr}
	movs r1, #1
	bl sub_0201BB44
	pop {r1}
	bx r1

	thumb_func_start sub_0201BB58
sub_0201BB58: @ 0x0201BB58
	push {lr}
	movs r1, #2
	bl sub_0201BB44
	pop {r1}
	bx r1

	thumb_func_start sub_0201BB64
sub_0201BB64: @ 0x0201BB64
	push {lr}
	movs r1, #4
	bl sub_0201BB44
	pop {r1}
	bx r1

	thumb_func_start sub_0201BB70
sub_0201BB70: @ 0x0201BB70
	push {lr}
	movs r1, #3
	bl sub_0201BB44
	pop {r1}
	bx r1

	thumb_func_start sub_0201BB7C
sub_0201BB7C: @ 0x0201BB7C
	push {lr}
	movs r1, #5
	bl sub_0201BB44
	pop {r1}
	bx r1

	thumb_func_start sub_0201BB88
sub_0201BB88: @ 0x0201BB88
	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x57
	ldrb r0, [r2]
	cmp r0, #5
	bhi _0201BBAC
	ldr r1, _0201BBB0 @ =0x0202B2BC
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0201BBAC
	adds r0, r3, #0
	bl _call_via_r1
_0201BBAC:
	pop {r0}
	bx r0
	.align 2, 0
_0201BBB0: .4byte 0x0202B2BC

	thumb_func_start sub_0201BBB4
sub_0201BBB4: @ 0x0201BBB4
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x57
	ldrb r0, [r4]
	adds r3, r2, #0
	adds r3, #0x52
	movs r1, #0
	strb r0, [r3]
	strb r1, [r4]
	str r1, [r2, #0x14]
	ldr r4, _0201BBEC @ =0x03001B50
	ldr r2, _0201BBF0 @ =0x00000816
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0
	bl sub_02019D88
	ldr r0, _0201BBF4 @ =0x0000085A
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	bl sub_0201B4B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201BBEC: .4byte 0x03001B50
_0201BBF0: .4byte 0x00000816
_0201BBF4: .4byte 0x0000085A

	thumb_func_start sub_0201BBF8
sub_0201BBF8: @ 0x0201BBF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0201BC38 @ =0x0203E9A0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0201BC4C
	ldr r0, _0201BC3C @ =0x03001B50
	ldr r1, _0201BC40 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0201BC1E
	adds r0, r4, #0
	bl sub_0201BB64
	cmp r0, #1
	beq _0201BC66
_0201BC1E:
	ldr r1, _0201BC3C @ =0x03001B50
	ldr r2, _0201BC44 @ =0x00000856
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201BC8E
	subs r2, #0xa
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, _0201BC48 @ =0x00FF00FF
	ands r0, r1
	b _0201BC8A
	.align 2, 0
_0201BC38: .4byte 0x0203E9A0
_0201BC3C: .4byte 0x03001B50
_0201BC40: .4byte 0x0000081A
_0201BC44: .4byte 0x00000856
_0201BC48: .4byte 0x00FF00FF
_0201BC4C:
	ldr r0, _0201BC70 @ =0x03001B50
	ldr r1, _0201BC74 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0201BC78
	adds r0, r4, #0
	bl sub_0201BB7C
	cmp r0, #1
	bne _0201BC78
_0201BC66:
	adds r0, r4, #0
	bl sub_0201BB88
	b _0201BC96
	.align 2, 0
_0201BC70: .4byte 0x03001B50
_0201BC74: .4byte 0x0000081A
_0201BC78:
	ldr r1, _0201BC9C @ =0x03001B50
	ldr r2, _0201BCA0 @ =0x00000856
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201BC8E
	subs r2, #8
	adds r0, r1, r2
	ldrb r0, [r0]
_0201BC8A:
	cmp r0, #0
	beq _0201BC96
_0201BC8E:
	adds r1, r4, #0
	adds r1, #0x72
	movs r0, #1
	strb r0, [r1]
_0201BC96:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201BC9C: .4byte 0x03001B50
_0201BCA0: .4byte 0x00000856

	thumb_func_start sub_0201BCA4
sub_0201BCA4: @ 0x0201BCA4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0x57
	ldrb r1, [r2]
	adds r0, #0x52
	movs r5, #0
	strb r1, [r0]
	strb r5, [r2]
	ldr r4, _0201BD54 @ =0x03001B50
	ldr r0, _0201BD58 @ =0x00000816
	adds r1, r4, r0
	movs r6, #1
	movs r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	bl sub_02019D88
	bl sub_02027068
	ldr r1, _0201BD5C @ =0x0000082A
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _0201BD60 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xf8
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0201BD64 @ =0x00000822
	adds r3, r4, r0
	ldrh r1, [r3]
	ldr r2, _0201BD68 @ =0x0000FFFC
	adds r0, r2, #0
	ands r0, r1
	strh r0, [r3]
	ldr r1, _0201BD6C @ =0x00000824
	adds r3, r4, r1
	ldrh r1, [r3]
	adds r0, r2, #0
	ands r0, r1
	orrs r0, r6
	strh r0, [r3]
	ldr r0, _0201BD70 @ =0x00000826
	adds r3, r4, r0
	ldrh r1, [r3]
	adds r0, r2, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r3]
	ldr r3, _0201BD74 @ =0x00000828
	adds r1, r4, r3
	ldrh r0, [r1]
	ands r2, r0
	movs r0, #3
	orrs r2, r0
	strh r2, [r1]
	ldr r1, _0201BD78 @ =0x0000083E
	adds r0, r4, r1
	strh r5, [r0]
	adds r3, #0x14
	adds r0, r4, r3
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r3, #4
	adds r0, r4, r3
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r3, #4
	adds r0, r4, r3
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r3, #4
	adds r4, r4, r3
	strh r1, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201BD54: .4byte 0x03001B50
_0201BD58: .4byte 0x00000816
_0201BD5C: .4byte 0x0000082A
_0201BD60: .4byte 0x0000E0FF
_0201BD64: .4byte 0x00000822
_0201BD68: .4byte 0x0000FFFC
_0201BD6C: .4byte 0x00000824
_0201BD70: .4byte 0x00000826
_0201BD74: .4byte 0x00000828
_0201BD78: .4byte 0x0000083E

	thumb_func_start sub_0201BD7C
sub_0201BD7C: @ 0x0201BD7C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_0201D904
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_0201DD94
	cmp r4, #1
	bne _0201BDA2
	adds r0, r5, #0
	bl sub_0201BB70
	cmp r0, #1
	bne _0201BDA2
	adds r0, r5, #0
	bl sub_0201BB88
_0201BDA2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0201BDA8
sub_0201BDA8: @ 0x0201BDA8
	push {lr}
	adds r3, r0, #0
	adds r3, #0x57
	ldrb r2, [r3]
	adds r0, #0x52
	movs r1, #0
	strb r2, [r0]
	strb r1, [r3]
	movs r0, #0x14
	bl sub_02019D98
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201BDC4
sub_0201BDC4: @ 0x0201BDC4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	bl sub_0201D800
	cmp r0, #1
	bne _0201BDE2
	adds r0, r4, #0
	bl sub_0201BB58
	cmp r0, #1
	bne _0201BDE2
	adds r0, r4, #0
	bl sub_0201BB88
_0201BDE2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0201BDE8
sub_0201BDE8: @ 0x0201BDE8
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r2, #0x57
	ldrb r1, [r2]
	adds r0, #0x52
	movs r5, #0
	strb r1, [r0]
	strb r5, [r2]
	ldr r4, _0201BE2C @ =0x03001B50
	ldr r1, _0201BE30 @ =0x00000816
	adds r0, r4, r1
	strh r5, [r0]
	movs r0, #0
	bl sub_02019D88
	bl sub_0201B4B0
	ldr r2, _0201BE34 @ =0x00000842
	adds r0, r4, r2
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0201BE38 @ =0x00000844
	adds r4, r4, r0
	strh r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201BE2C: .4byte 0x03001B50
_0201BE30: .4byte 0x00000816
_0201BE34: .4byte 0x00000842
_0201BE38: .4byte 0x00000844

	thumb_func_start sub_0201BE3C
sub_0201BE3C: @ 0x0201BE3C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl sub_0201D800
	adds r1, r0, #0
	cmp r1, #1
	bne _0201BE5A
	adds r0, r4, #0
	adds r0, #0x52
	strb r1, [r0]
	ldr r0, _0201BE60 @ =0x03001B50
	ldr r2, _0201BE64 @ =0x0000085A
	adds r0, r0, r2
	strb r1, [r0]
_0201BE5A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201BE60: .4byte 0x03001B50
_0201BE64: .4byte 0x0000085A

	thumb_func_start sub_0201BE68
sub_0201BE68: @ 0x0201BE68
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0201BEAC @ =0x03002FC0
	adds r0, r5, #0
	movs r1, #0x1a
	bl mMsg_RequestAppear
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0201BE9C
	adds r0, r4, #0
	movs r1, #1
	bl sub_0201A854
	adds r0, r4, #0
	movs r1, #1
	bl sub_0201AA98
	adds r0, r4, #0
	adds r0, #0x57
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	str r5, [r4, #0x14]
_0201BE9C:
	adds r1, r4, #0
	adds r1, #0x57
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201BEAC: .4byte 0x03002FC0

	thumb_func_start sub_0201BEB0
sub_0201BEB0: @ 0x0201BEB0
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x14]
	adds r0, r1, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201BEC6
	adds r1, r2, #0
	adds r1, #0x52
	b _0201BF00
_0201BEC6:
	adds r0, r1, #0
	adds r0, #0x70
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0201BF04
	adds r0, r1, #0
	adds r0, #0x77
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0201BF04
	ldr r1, _0201BF08 @ =0x03001B50
	ldr r3, _0201BF0C @ =0x00000856
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201BEFC
	subs r3, #8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201BF04
_0201BEFC:
	adds r1, r2, #0
	adds r1, #0x72
_0201BF00:
	movs r0, #1
	strb r0, [r1]
_0201BF04:
	pop {r0}
	bx r0
	.align 2, 0
_0201BF08: .4byte 0x03001B50
_0201BF0C: .4byte 0x00000856

	thumb_func_start sub_0201BF10
sub_0201BF10: @ 0x0201BF10
	push {r4, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r4, _0201BF50 @ =0x030031D0
	ldr r2, _0201BF54 @ =0x01000020
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	adds r1, r4, #0
	adds r1, #0x63
	movs r0, #0xff
	strb r0, [r1]
	bl sub_0201D5C4
	adds r0, r4, #0
	bl sub_0201BB4C
	cmp r0, #1
	bne _0201BF40
	adds r0, r4, #0
	bl sub_0201BB88
_0201BF40:
	adds r0, r4, #0
	bl sub_0201B594
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201BF50: .4byte 0x030031D0
_0201BF54: .4byte 0x01000020

	thumb_func_start sub_0201BF58
sub_0201BF58: @ 0x0201BF58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, _0201C024 @ =0x030031D0
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x53
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	beq _0201BF96
	adds r0, r5, #0
	adds r0, #0x55
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	beq _0201BF96
	adds r0, r5, #0
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0201BF96
	adds r0, r5, #0
	bl sub_0201B594
_0201BF96:
	ldr r0, _0201C028 @ =0x03001B40
	ldr r0, [r0]
	ldr r1, _0201C02C @ =0x0000193A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201BFCC
	ldr r2, _0201C030 @ =0x03001B50
	adds r3, r5, #0
	adds r3, #0x73
	ldr r4, _0201C034 @ =0x00000844
	adds r0, r2, r4
	ldrh r0, [r0]
	lsrs r0, r0, #1
	ldrb r1, [r3]
	adds r0, r0, r1
	subs r4, #8
	adds r1, r2, r4
	strh r0, [r1]
	ldr r0, _0201C038 @ =0x0000083E
	adds r2, r2, r0
	ldrh r0, [r2]
	subs r0, #4
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0201BFCC:
	adds r0, r5, #0
	bl sub_0201ABBC
	adds r1, r5, #0
	adds r1, #0x53
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0201C048
	ldr r0, _0201C03C @ =0x0202AFDC
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r5, #0
	adds r6, #0x72
	ldrb r7, [r6]
	cmp r7, #1
	beq _0201BFFE
	b _0201C186
_0201BFFE:
	adds r0, r5, #0
	bl sub_0201ADE8
	movs r4, #0
	strb r4, [r6]
	adds r0, r5, #0
	bl sub_0201AE0C
	ldr r0, _0201C030 @ =0x03001B50
	ldr r2, _0201C040 @ =0x00000857
	adds r1, r0, r2
	strb r7, [r1]
	subs r2, #9
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _0201C044 @ =0x0000084F
	adds r0, r0, r1
	strb r4, [r0]
	b _0201C186
	.align 2, 0
_0201C024: .4byte 0x030031D0
_0201C028: .4byte 0x03001B40
_0201C02C: .4byte 0x0000193A
_0201C030: .4byte 0x03001B50
_0201C034: .4byte 0x00000844
_0201C038: .4byte 0x0000083E
_0201C03C: .4byte 0x0202AFDC
_0201C040: .4byte 0x00000857
_0201C044: .4byte 0x0000084F
_0201C048:
	adds r1, r5, #0
	adds r1, #0x55
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0201C074
	ldr r0, _0201C070 @ =0x0202B2A0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0
	mov r8, r2
	b _0201C186
	.align 2, 0
_0201C070: .4byte 0x0202B2A0
_0201C074:
	adds r3, r5, #0
	adds r3, #0x54
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _0201C0D8
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	bne _0201C0C0
	adds r1, r5, #0
	adds r1, #0x67
	ldrb r0, [r1]
	cmp r0, #0
	bne _0201C0B0
	ldr r0, _0201C0AC @ =0x0202AFFC
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	b _0201C0C0
	.align 2, 0
_0201C0AC: .4byte 0x0202AFFC
_0201C0B0:
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _0201C0BE
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201C0C0
_0201C0BE:
	strb r2, [r1]
_0201C0C0:
	ldrb r0, [r4]
	cmp r0, #1
	bne _0201C186
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #1
	bl sub_0201C1C4
	b _0201C186
_0201C0D8:
	adds r0, r5, #0
	adds r0, #0x52
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0201C186
	cmp r2, #1
	bne _0201C106
	ldr r0, _0201C144 @ =0x0203E9A0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0201C106
	ldr r3, _0201C148 @ =0x03001B50
	ldr r4, _0201C14C @ =0x0000081A
	adds r0, r3, r4
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0201C106
	ldr r1, _0201C150 @ =0x0000084C
	adds r0, r3, r1
	strb r2, [r0]
_0201C106:
	adds r0, r5, #0
	bl sub_0201A7C8
	ldr r1, _0201C148 @ =0x03001B50
	ldr r2, _0201C154 @ =0x0000084E
	adds r1, r1, r2
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _0201C172
	adds r2, r5, #0
	adds r2, #0x65
	ldrb r0, [r2]
	cmp r0, #0
	bne _0201C160
	ldr r2, _0201C158 @ =0x0202B2D4
	ldr r0, _0201C15C @ =0x030031D0
	adds r1, r0, #0
	adds r1, #0x52
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	b _0201C172
	.align 2, 0
_0201C144: .4byte 0x0203E9A0
_0201C148: .4byte 0x03001B50
_0201C14C: .4byte 0x0000081A
_0201C150: .4byte 0x0000084C
_0201C154: .4byte 0x0000084E
_0201C158: .4byte 0x0202B2D4
_0201C15C: .4byte 0x030031D0
_0201C160:
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _0201C16E
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201C172
_0201C16E:
	strb r1, [r2]
	strh r1, [r5, #0x2c]
_0201C172:
	ldrb r0, [r4]
	cmp r0, #1
	bne _0201C186
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl sub_0201C1C4
_0201C186:
	mov r0, r8
	bl sub_0201A688
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0201C198
sub_0201C198: @ 0x0201C198
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C19C
sub_0201C19C: @ 0x0201C19C
	push {lr}
	ldr r0, _0201C1B4 @ =0x030031D0
	ldr r0, [r0, #0x18]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_0201C1B4: .4byte 0x030031D0

	thumb_func_start sub_0201C1B8
sub_0201C1B8: @ 0x0201C1B8
	push {lr}
	bl sub_0201C8C0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201C1C4
sub_0201C1C4: @ 0x0201C1C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r0, [sp, #0x20]
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsrs r7, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_0201A714
	mov r8, r0
	cmp r0, #1
	bne _0201C2C4
	cmp r4, #0
	beq _0201C238
	ldr r6, _0201C22C @ =0x03001B50
	ldr r1, _0201C230 @ =0x00000856
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201C238
	adds r0, r5, #0
	bl sub_0201ADE8
	adds r0, r5, #0
	adds r0, #0x72
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x15
	strb r7, [r0]
	ldr r0, [r5, #0x14]
	str r0, [r5, #8]
	adds r0, r5, #0
	bl sub_0201AE0C
	ldr r1, _0201C234 @ =0x00000857
	adds r0, r6, r1
	mov r1, r8
	strb r1, [r0]
	b _0201C26E
	.align 2, 0
_0201C22C: .4byte 0x03001B50
_0201C230: .4byte 0x00000856
_0201C234: .4byte 0x00000857
_0201C238:
	mov r0, sb
	cmp r0, #0
	beq _0201C28C
	ldr r6, _0201C27C @ =0x03001B50
	ldr r1, _0201C280 @ =0x0000084C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201C28C
	adds r0, r5, #0
	bl sub_0201B688
	adds r0, r5, #0
	adds r0, #0x72
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x13
	strb r7, [r0]
	ldr r0, [r5, #0x14]
	str r0, [r5, #0x10]
	adds r0, r5, #0
	bl sub_0201B6D0
	ldr r0, _0201C284 @ =0x0000084D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_0201C26E:
	ldr r1, _0201C288 @ =0x0000084E
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	b _0201C2C4
	.align 2, 0
_0201C27C: .4byte 0x03001B50
_0201C280: .4byte 0x0000084C
_0201C284: .4byte 0x0000084D
_0201C288: .4byte 0x0000084E
_0201C28C:
	mov r0, sl
	cmp r0, #0
	beq _0201C2C4
	ldr r4, _0201C2D4 @ =0x03001B50
	ldr r1, _0201C2D8 @ =0x0000084E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201C2C4
	adds r0, r5, #0
	bl sub_0201B194
	adds r1, r5, #0
	adds r1, #0x72
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5e
	strb r7, [r0]
	ldr r0, [r5, #0x14]
	str r0, [r5, #0xc]
	adds r0, r5, #0
	bl sub_0201B1B8
	ldr r0, _0201C2DC @ =0x0000084F
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0201C2C4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201C2D4: .4byte 0x03001B50
_0201C2D8: .4byte 0x0000084E
_0201C2DC: .4byte 0x0000084F

	thumb_func_start sub_0201C2E0
sub_0201C2E0: @ 0x0201C2E0
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _0201C2F8 @ =0x03003250
	ldr r2, _0201C2FC @ =0x01000120
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0201C2F8: .4byte 0x03003250
_0201C2FC: .4byte 0x01000120

	thumb_func_start sub_0201C300
sub_0201C300: @ 0x0201C300
	adds r2, r0, #0
	adds r2, #0x57
	movs r1, #0
	strb r1, [r2]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C310
sub_0201C310: @ 0x0201C310
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov sl, r2
	str r3, [sp, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r4, #0
	movs r0, #0
	bl sub_0201C3C8
	adds r2, r0, #0
	cmp r2, #0
	blt _0201C3AA
	ldr r1, _0201C3BC @ =0x0202B2FC
	mov r3, r8
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r5, [r0]
	str r4, [sp]
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r4, r4, #5
	ldr r6, _0201C3C0 @ =0x03003250
	adds r7, r4, r6
	ldr r2, _0201C3C4 @ =0x01000018
	mov r0, sp
	adds r1, r7, #0
	bl CpuFastSet
	ldr r0, [r5]
	str r0, [r7]
	adds r0, r6, #4
	adds r0, r4, r0
	ldr r1, [r5, #4]
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #8
	adds r0, r4, r0
	ldr r1, [r5, #8]
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc
	adds r0, r4, r0
	ldr r1, [r5, #0xc]
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x57
	mov r1, r8
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x2c
	adds r0, r4, r0
	mov r3, sb
	str r3, [r0]
	adds r0, r6, #0
	adds r0, #0x30
	adds r0, r4, r0
	mov r1, sl
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #0x14
	adds r4, r4, r0
	ldr r3, [sp, #4]
	str r3, [r4]
	ldr r1, [r7]
	cmp r1, #0
	beq _0201C3A8
	adds r0, r7, #0
	bl _call_via_r1
_0201C3A8:
	adds r4, r7, #0
_0201C3AA:
	adds r0, r4, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0201C3BC: .4byte 0x0202B2FC
_0201C3C0: .4byte 0x03003250
_0201C3C4: .4byte 0x01000018

	thumb_func_start sub_0201C3C8
sub_0201C3C8: @ 0x0201C3C8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, _0201C3D8 @ =0x03003250
	adds r1, r0, #0
	adds r1, #0x57
	b _0201C3E4
	.align 2, 0
_0201C3D8: .4byte 0x03003250
_0201C3DC:
	adds r1, #0x60
	adds r2, #1
	cmp r2, #0xb
	bgt _0201C3EA
_0201C3E4:
	ldrb r0, [r1]
	cmp r0, r3
	bne _0201C3DC
_0201C3EA:
	adds r0, r2, #0
	cmp r0, #0xb
	ble _0201C3F4
	movs r0, #1
	rsbs r0, r0, #0
_0201C3F4:
	pop {r1}
	bx r1

	thumb_func_start sub_0201C3F8
sub_0201C3F8: @ 0x0201C3F8
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r4, #0x38
	ldrsh r0, [r2, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0x34
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bne _0201C420
	movs r4, #0x36
	ldrsh r0, [r2, r4]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _0201C420
	movs r3, #1
_0201C420:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_0201C428
sub_0201C428: @ 0x0201C428
	push {r4, lr}
	movs r3, #0
	strh r2, [r0, #0x38]
	movs r4, #0x38
	ldrsh r2, [r0, r4]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r1, [r1, #4]
	strh r1, [r0, #0x34]
	strh r3, [r0, #0x36]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0201C444
sub_0201C444: @ 0x0201C444
	push {lr}
	adds r2, r0, #0
	movs r3, #0x38
	ldrsh r0, [r2, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	subs r0, #1
	cmp r0, #0
	bgt _0201C486
	movs r1, #0x36
	ldrsh r0, [r2, r1]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r1, [r0, #8]
	cmp r1, #0
	bne _0201C474
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _0201C48A
	strh r1, [r2, #0x36]
	b _0201C47A
_0201C474:
	ldrh r0, [r2, #0x36]
	adds r0, #1
	strh r0, [r2, #0x36]
_0201C47A:
	movs r1, #0x36
	ldrsh r0, [r2, r1]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	b _0201C48A
_0201C486:
	ldrh r0, [r2, #0x34]
	subs r0, #1
_0201C48A:
	strh r0, [r2, #0x34]
	pop {r0}
	bx r0

	thumb_func_start sub_0201C490
sub_0201C490: @ 0x0201C490
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r3, [r0, #0x30]
	ldrb r4, [r1]
	adds r4, r4, r3
	ldr r3, [r0, #0x24]
	adds r3, r3, r4
	strb r3, [r2]
	ldrb r3, [r1, #1]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	ldrb r5, [r2, #1]
	movs r4, #4
	rsbs r4, r4, #0
	ands r4, r5
	orrs r4, r3
	strb r4, [r2, #1]
	ldrb r5, [r1, #1]
	movs r3, #0xc
	ands r3, r5
	movs r5, #0xd
	rsbs r5, r5, #0
	mov sb, r5
	ands r5, r4
	orrs r5, r3
	strb r5, [r2, #1]
	ldrb r4, [r1, #1]
	movs r3, #0x10
	ands r3, r4
	movs r4, #0x11
	rsbs r4, r4, #0
	mov r8, r4
	mov r6, r8
	ands r6, r5
	orrs r6, r3
	strb r6, [r2, #1]
	ldrb r3, [r1, #1]
	movs r4, #0x20
	ands r4, r3
	movs r5, #0x21
	rsbs r5, r5, #0
	adds r3, r5, #0
	ands r3, r6
	orrs r3, r4
	strb r3, [r2, #1]
	ldrb r4, [r1, #1]
	lsrs r4, r4, #6
	lsls r4, r4, #6
	movs r6, #0x3f
	ands r3, r6
	orrs r3, r4
	strb r3, [r2, #1]
	ldrh r3, [r1, #2]
	lsls r3, r3, #0x17
	lsrs r3, r3, #0x17
	ldr r4, [r0, #0x2c]
	adds r3, r3, r4
	ldr r0, [r0, #0x20]
	adds r3, r3, r0
	ldr r4, _0201C594 @ =0x000001FF
	adds r0, r4, #0
	ands r3, r0
	ldrh r4, [r2, #2]
	ldr r0, _0201C598 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r3
	strh r0, [r2, #2]
	ldrb r3, [r1, #3]
	movs r0, #0xe
	ands r0, r3
	ldrb r4, [r2, #3]
	movs r3, #0xf
	rsbs r3, r3, #0
	ands r3, r4
	orrs r3, r0
	strb r3, [r2, #3]
	ldrb r4, [r1, #3]
	movs r0, #0x10
	ands r0, r4
	mov r4, r8
	ands r4, r3
	orrs r4, r0
	strb r4, [r2, #3]
	ldrb r3, [r1, #3]
	movs r0, #0x20
	ands r0, r3
	ands r5, r4
	orrs r5, r0
	strb r5, [r2, #3]
	ldrb r0, [r1, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	ands r5, r6
	orrs r5, r0
	strb r5, [r2, #3]
	ldrh r3, [r1, #4]
	lsls r3, r3, #0x16
	lsrs r3, r3, #0x16
	ldrh r4, [r2, #4]
	ldr r0, _0201C59C @ =0xFFFFFC00
	ands r0, r4
	orrs r0, r3
	strh r0, [r2, #4]
	ldrb r3, [r1, #5]
	movs r0, #0xc
	ands r0, r3
	ldrb r3, [r2, #5]
	mov r5, sb
	ands r5, r3
	orrs r5, r0
	mov sb, r5
	strb r5, [r2, #5]
	ldrb r0, [r1, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0xf
	mov r4, sb
	ands r4, r3
	orrs r4, r0
	strb r4, [r2, #5]
	ldrh r0, [r1, #6]
	strh r0, [r2, #6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201C594: .4byte 0x000001FF
_0201C598: .4byte 0xFFFFFE00
_0201C59C: .4byte 0xFFFFFC00

	thumb_func_start sub_0201C5A0
sub_0201C5A0: @ 0x0201C5A0
	push {r4, r5, r6, lr}
	ldr r0, _0201C5F4 @ =0x03003250
	adds r6, r0, #0
	adds r6, #0x57
	adds r4, r0, #0
	movs r5, #0xb
_0201C5AC:
	ldrb r0, [r6]
	cmp r0, #0
	beq _0201C5BE
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _0201C5BE
	adds r0, r4, #0
	bl _call_via_r1
_0201C5BE:
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0201C5AC
	ldr r0, _0201C5F4 @ =0x03003250
	adds r6, r0, #0
	adds r6, #0x57
	adds r4, r0, #0
	movs r5, #0xb
_0201C5D2:
	ldrb r0, [r6]
	cmp r0, #0
	beq _0201C5E4
	ldr r1, [r4, #0xc]
	cmp r1, #0
	beq _0201C5E4
	adds r0, r4, #0
	bl _call_via_r1
_0201C5E4:
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0201C5D2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201C5F4: .4byte 0x03003250

	thumb_func_start sub_0201C5F8
sub_0201C5F8: @ 0x0201C5F8
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C5FC
sub_0201C5FC: @ 0x0201C5FC
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r1, _0201C654 @ =0x0202B37C
	add r0, sp, #8
	movs r2, #8
	bl memcpy
	add r5, sp, #0x10
	ldr r1, _0201C658 @ =0x0202B384
	adds r0, r5, #0
	movs r2, #8
	bl memcpy
	add r4, sp, #0x18
	ldr r1, _0201C65C @ =0x0202B38C
	adds r0, r4, #0
	movs r2, #8
	bl memcpy
	mov r0, sp
	adds r0, r0, r6
	adds r0, #8
	ldrb r3, [r0]
	adds r5, r5, r6
	ldrb r0, [r5]
	str r0, [sp]
	adds r4, r4, r6
	ldrb r0, [r4]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #7
	movs r2, #6
	bl sub_02019BD8
	ldr r0, _0201C660 @ =0x020002E0
	ldr r1, _0201C664 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201C654: .4byte 0x0202B37C
_0201C658: .4byte 0x0202B384
_0201C65C: .4byte 0x0202B38C
_0201C660: .4byte 0x020002E0
_0201C664: .4byte 0x050002E0

	thumb_func_start sub_0201C668
sub_0201C668: @ 0x0201C668
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #3
	ands r0, r1
	ldr r1, [r4, #0x14]
	lsls r1, r1, #2
	adds r0, r0, r1
	bl sub_0201C5FC
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #0xa
	ble _0201C690
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
_0201C690:
	adds r0, r4, #0
	bl sub_0201C5F8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0201C69C
sub_0201C69C: @ 0x0201C69C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0201C6C0 @ =0x0202B378
	movs r2, #0
	bl sub_0201C428
	adds r0, r4, #0
	bl sub_0201C5F8
	ldr r1, _0201C6C4 @ =sub_0201C668
	str r1, [r4, #0x10]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201C6C0: .4byte 0x0202B378
_0201C6C4: .4byte sub_0201C668

	thumb_func_start sub_0201C6C8
sub_0201C6C8: @ 0x0201C6C8
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C6CC
sub_0201C6CC: @ 0x0201C6CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq _0201C6DA
	bl _call_via_r1
_0201C6DA:
	ldr r1, _0201C6E8 @ =0x0202B378
	adds r0, r4, #0
	bl sub_0201C444
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201C6E8: .4byte 0x0202B378

	thumb_func_start sub_0201C6EC
sub_0201C6EC: @ 0x0201C6EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _0201C730 @ =0x0202B378
	movs r2, #0x38
	ldrsh r0, [r6, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, [r0]
	ldrh r0, [r4, #6]
	ldr r1, _0201C734 @ =0x0000FFFF
	cmp r0, r1
	beq _0201C728
	ldr r5, _0201C738 @ =0x030023B0
	adds r7, r1, #0
_0201C70A:
	ldrb r2, [r5]
	lsls r2, r2, #3
	ldr r0, _0201C73C @ =0x03002410
	adds r2, r2, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_0201C490
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r4, #8
	ldrh r0, [r4, #6]
	cmp r0, r7
	bne _0201C70A
_0201C728:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201C730: .4byte 0x0202B378
_0201C734: .4byte 0x0000FFFF
_0201C738: .4byte 0x030023B0
_0201C73C: .4byte 0x03002410

	thumb_func_start sub_0201C740
sub_0201C740: @ 0x0201C740
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C744
sub_0201C744: @ 0x0201C744
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0201C760 @ =0x0202B3DC
	movs r2, #0
	bl sub_0201C428
	ldr r1, _0201C764 @ =sub_0201C740
	str r1, [r4, #0x10]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201C760: .4byte 0x0202B3DC
_0201C764: .4byte sub_0201C740

	thumb_func_start sub_0201C768
sub_0201C768: @ 0x0201C768
	bx lr
	.align 2, 0

	thumb_func_start sub_0201C76C
sub_0201C76C: @ 0x0201C76C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq _0201C77A
	bl _call_via_r1
_0201C77A:
	ldr r1, _0201C788 @ =0x0202B3DC
	adds r0, r4, #0
	bl sub_0201C444
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201C788: .4byte 0x0202B3DC

	thumb_func_start sub_0201C78C
sub_0201C78C: @ 0x0201C78C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _0201C7D0 @ =0x0202B3DC
	movs r2, #0x38
	ldrsh r0, [r6, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, [r0]
	ldrh r0, [r4, #6]
	ldr r1, _0201C7D4 @ =0x0000FFFF
	cmp r0, r1
	beq _0201C7C8
	ldr r5, _0201C7D8 @ =0x030023B0
	adds r7, r1, #0
_0201C7AA:
	ldrb r2, [r5]
	lsls r2, r2, #3
	ldr r0, _0201C7DC @ =0x03002410
	adds r2, r2, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_0201C490
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r4, #8
	ldrh r0, [r4, #6]
	cmp r0, r7
	bne _0201C7AA
_0201C7C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201C7D0: .4byte 0x0202B3DC
_0201C7D4: .4byte 0x0000FFFF
_0201C7D8: .4byte 0x030023B0
_0201C7DC: .4byte 0x03002410

	thumb_func_start sub_0201C7E0
sub_0201C7E0: @ 0x0201C7E0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	ldr r6, _0201C850 @ =0x04000208
	movs r2, #0
	strh r2, [r6]
	ldr r5, _0201C854 @ =0x04000200
	ldrh r1, [r5]
	ldr r0, _0201C858 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	mov sb, r0
	strh r0, [r6]
	ldr r0, _0201C85C @ =0x04000134
	strh r2, [r0]
	ldr r2, _0201C860 @ =0x04000128
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0201C864 @ =0x00004003
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	ldr r4, _0201C868 @ =0x030036D0
	ldr r2, _0201C86C @ =0x0500000E
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	mov r3, r8
	strh r3, [r6]
	ldrh r0, [r5]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r5]
	mov r0, sb
	strh r0, [r6]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201C850: .4byte 0x04000208
_0201C854: .4byte 0x04000200
_0201C858: .4byte 0x0000FF3F
_0201C85C: .4byte 0x04000134
_0201C860: .4byte 0x04000128
_0201C864: .4byte 0x00004003
_0201C868: .4byte 0x030036D0
_0201C86C: .4byte 0x0500000E

	thumb_func_start sub_0201C870
sub_0201C870: @ 0x0201C870
	push {r4, lr}
	ldr r3, _0201C8A4 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _0201C8A8 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0201C8AC @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0201C8B0 @ =0x04000134
	strh r4, [r0]
	ldr r1, _0201C8B4 @ =0x04000128
	ldr r2, _0201C8B8 @ =0x00002003
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x1c
	ldr r0, _0201C8BC @ =0x0000A4FB
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201C8A4: .4byte 0x04000208
_0201C8A8: .4byte 0x04000200
_0201C8AC: .4byte 0x0000FF3F
_0201C8B0: .4byte 0x04000134
_0201C8B4: .4byte 0x04000128
_0201C8B8: .4byte 0x00002003
_0201C8BC: .4byte 0x0000A4FB

	thumb_func_start sub_0201C8C0
sub_0201C8C0: @ 0x0201C8C0
	push {r4, r5, r6, r7, lr}
	ldr r5, _0201C8E0 @ =0x04000128
	ldr r2, [r5]
	movs r7, #1
	rsbs r7, r7, #0
	ldr r0, _0201C8E4 @ =0x030036D0
	mov ip, r0
	ldrb r0, [r0, #1]
	mov r3, ip
	cmp r0, #2
	beq _0201C9C8
	cmp r0, #2
	bgt _0201C8E8
	cmp r0, #0
	beq _0201C8F6
	b _0201CB18
	.align 2, 0
_0201C8E0: .4byte 0x04000128
_0201C8E4: .4byte 0x030036D0
_0201C8E8:
	cmp r0, #3
	bne _0201C8EE
	b _0201CA4A
_0201C8EE:
	cmp r0, #4
	bne _0201C8F4
	b _0201CAE0
_0201C8F4:
	b _0201CB18
_0201C8F6:
	mov r0, ip
	ldr r1, [r0, #0x20]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	ble _0201C912
	movs r0, #0x88
	ands r2, r0
	movs r7, #0x10
	cmp r2, #8
	bne _0201C90E
	b _0201CB18
_0201C90E:
	movs r7, #8
	b _0201CB18
_0201C912:
	movs r0, #0x88
	adds r4, r2, #0
	ands r4, r0
	cmp r4, #8
	beq _0201C91E
	b _0201CB18
_0201C91E:
	movs r0, #4
	ands r2, r0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0201C966
	ldr r3, _0201C9A4 @ =0x04000208
	strh r0, [r3]
	ldr r2, _0201C9A8 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0201C9AC @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldrb r1, [r5, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	ldr r1, _0201C9B0 @ =0x04000202
	movs r0, #0xc0
	strh r0, [r1]
	subs r1, #0xf6
	ldr r0, _0201C9B4 @ =0x0000A4FB
	str r0, [r1]
	mov r1, ip
	strb r4, [r1]
	ldrb r0, [r5]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r5]
_0201C966:
	ldr r0, _0201C9B8 @ =0x03001B40
	ldr r1, [r0]
	mov r2, ip
	str r1, [r2, #8]
	ldr r0, _0201C9BC @ =0x03002970
	ldr r0, [r0]
	str r0, [r2, #0xc]
	movs r3, #0
	movs r2, #0xe6
	lsls r2, r2, #5
_0201C97A:
	ldrh r0, [r1]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0201C97A
	ldr r4, _0201C9C0 @ =0x030036D0
	mvns r0, r3
	strh r0, [r4, #0x2a]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0201C99C
	ldr r1, _0201C9C4 @ =0x0400010E
	movs r0, #0xc0
	strh r0, [r1]
_0201C99C:
	str r2, [r4, #0x20]
	movs r0, #2
	strb r0, [r4, #1]
	b _0201CB18
	.align 2, 0
_0201C9A4: .4byte 0x04000208
_0201C9A8: .4byte 0x04000200
_0201C9AC: .4byte 0x0000FF7F
_0201C9B0: .4byte 0x04000202
_0201C9B4: .4byte 0x0000A4FB
_0201C9B8: .4byte 0x03001B40
_0201C9BC: .4byte 0x03002970
_0201C9C0: .4byte 0x030036D0
_0201C9C4: .4byte 0x0400010E
_0201C9C8:
	mov r0, ip
	adds r0, #0x32
	ldrb r3, [r0]
	cmp r3, #0
	bne _0201C90E
	mov r0, ip
	ldrb r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0201CA04
	movs r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0201CA04
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1e
	movs r7, #8
	cmp r0, #1
	bls _0201C9F2
	b _0201CB18
_0201C9F2:
	movs r7, #7
	mov r1, ip
	str r3, [r1, #0x20]
	movs r0, #3
	strb r0, [r1, #1]
	movs r0, #0x29
	bl sub_02019D58
	b _0201CB18
_0201CA04:
	ldr r3, _0201CA14 @ =0x030036D0
	ldr r1, [r3, #0x20]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	ble _0201CA18
	movs r7, #0x10
	b _0201CB18
	.align 2, 0
_0201CA14: .4byte 0x030036D0
_0201CA18:
	ldrb r1, [r3, #2]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1e
	asrs r1, r0
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	bne _0201CA40
	adds r1, r3, #0
	adds r1, #0x33
	ldrb r0, [r1]
	cmp r0, #7
	bhi _0201CA38
	adds r0, #1
	strb r0, [r1]
	b _0201CB18
_0201CA38:
	adds r0, r3, #0
	adds r0, #0x34
	strb r2, [r0]
	b _0201CB18
_0201CA40:
	adds r1, r3, #0
	adds r1, #0x33
	movs r0, #0
	strb r0, [r1]
	b _0201CB18
_0201CA4A:
	mov r2, ip
	ldr r5, [r2, #0x14]
	adds r4, r5, #0
	mov r0, ip
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201CA6A
	ldr r0, [r2, #0x20]
	cmp r0, #1
	bgt _0201CA6A
	mov r0, ip
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201CA6E
_0201CA6A:
	movs r7, #0xa
	b _0201CB18
_0201CA6E:
	movs r0, #0xe6
	lsls r0, r0, #5
	cmp r5, r0
	ble _0201CA7A
	adds r4, r0, #0
	b _0201CA80
_0201CA7A:
	cmp r5, #0
	bge _0201CA80
	movs r4, #0
_0201CA80:
	movs r1, #0x2e
	ldrsh r0, [r3, r1]
	cmp r0, r4
	bge _0201CAAC
	adds r2, r3, #0
	ldr r6, [r3, #0xc]
_0201CA8C:
	ldrh r0, [r2, #0x2e]
	adds r1, r0, #1
	strh r1, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2, #0x2c]
	movs r1, #0x2e
	ldrsh r0, [r2, r1]
	cmp r0, r4
	blt _0201CA8C
	movs r0, #0
	str r0, [r2, #0x20]
_0201CAAC:
	movs r0, #0xe6
	lsls r0, r0, #5
	cmp r5, r0
	ble _0201CB18
	ldrh r0, [r3, #0x2c]
	ldrh r2, [r3, #0x24]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0201CACC
	movs r0, #1
	strb r0, [r3, #3]
	b _0201CAD0
_0201CACC:
	movs r0, #1
	strb r0, [r3, #4]
_0201CAD0:
	ldr r0, _0201CADC @ =0x030036D0
	movs r1, #0
	str r1, [r0, #0x20]
	movs r1, #4
	strb r1, [r0, #1]
	b _0201CB18
	.align 2, 0
_0201CADC: .4byte 0x030036D0
_0201CAE0:
	mov r0, ip
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0201CAF2
	movs r7, #9
	b _0201CB0A
_0201CAF2:
	cmp r0, r7
	beq _0201CB08
	mov r0, ip
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201CB08
	mov r1, ip
	ldr r0, [r1, #0x20]
	cmp r0, #6
	ble _0201CB0A
_0201CB08:
	movs r7, #0xa
_0201CB0A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r7, r0
	beq _0201CB18
	ldr r1, _0201CB4C @ =0x030036D0
	movs r0, #5
	strb r0, [r1, #1]
_0201CB18:
	ldr r0, _0201CB4C @ =0x030036D0
	ldr r1, [r0, #0x20]
	adds r1, #1
	str r1, [r0, #0x20]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r7, r0
	beq _0201CB42
	cmp r7, #7
	beq _0201CB42
	movs r0, #0x29
	bl sub_02019D68
	movs r0, #0x28
	cmp r7, #9
	bne _0201CB3A
	movs r0, #0x27
_0201CB3A:
	bl sub_02019D78
	bl sub_0201C870
_0201CB42:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0201CB4C: .4byte 0x030036D0

	thumb_func_start sub_0201CB50
sub_0201CB50: @ 0x0201CB50
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0201CBBC @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0201CBC0 @ =0x030036D0
	ldr r0, _0201CBC4 @ =0x04000128
	ldr r1, [r0]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x1f
	adds r3, r2, #0
	adds r3, #0x32
	strb r0, [r3]
	ldr r3, [r2, #0x1c]
	mov ip, r2
	cmp r3, #0
	bge _0201CBCC
	movs r3, #0
	ldr r6, _0201CBC8 @ =0x0000FEFE
	mov r4, ip
	mov r2, sp
	movs r5, #1
_0201CB80:
	ldrh r0, [r2]
	cmp r0, r6
	bne _0201CB90
	adds r0, r5, #0
	lsls r0, r3
	ldrb r1, [r4, #2]
	orrs r0, r1
	strb r0, [r4, #2]
_0201CB90:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	ble _0201CB80
	mov r0, ip
	ldrb r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	beq _0201CBA6
	b _0201CCB0
_0201CBA6:
	mov r1, ip
	ldr r0, [r1, #0x18]
	adds r0, #1
	str r0, [r1, #0x18]
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	movs r0, #0
	strh r0, [r1, #0x28]
	strh r0, [r1, #0x26]
	b _0201CCB0
	.align 2, 0
_0201CBBC: .4byte 0x04000120
_0201CBC0: .4byte 0x030036D0
_0201CBC4: .4byte 0x04000128
_0201CBC8: .4byte 0x0000FEFE
_0201CBCC:
	ldr r0, _0201CC14 @ =0x00001DAD
	cmp r3, r0
	bgt _0201CC48
	lsls r4, r1, #0x1a
	lsrs r0, r4, #0x1e
	movs r5, #1
	eors r0, r5
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	mov r2, ip
	ldrh r2, [r2, #0x26]
	adds r1, r0, r2
	mov r6, ip
	strh r1, [r6, #0x26]
	movs r0, #0x1f
	ands r3, r0
	cmp r3, #0x1f
	bne _0201CC18
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0201CC0A
	mov r2, ip
	adds r2, #0x31
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_0201CC0A:
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0x26]
	b _0201CC38
	.align 2, 0
_0201CC14: .4byte 0x00001DAD
_0201CC18:
	mov r3, ip
	ldr r2, [r3, #0x14]
	ldr r0, _0201CC44 @ =0x00001CBF
	cmp r2, r0
	bgt _0201CC38
	ldr r0, [r3, #0xc]
	lsls r1, r2, #1
	adds r1, r1, r0
	lsrs r0, r4, #0x1e
	eors r0, r5
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	str r0, [r3, #0x14]
_0201CC38:
	mov r6, ip
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
	b _0201CCB0
	.align 2, 0
_0201CC44: .4byte 0x00001CBF
_0201CC48:
	ldr r0, _0201CC6C @ =0x00001DAE
	cmp r3, r0
	bne _0201CC70
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1e
	movs r0, #1
	eors r0, r1
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #0x24]
	adds r0, r3, #1
	str r0, [r1, #0x1c]
	ldr r0, [r1, #0x14]
	adds r0, #1
	str r0, [r1, #0x14]
	b _0201CCB0
	.align 2, 0
_0201CC6C: .4byte 0x00001DAE
_0201CC70:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r3, r2, #0
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0201CCB0
	mov r0, sp
	ldrh r2, [r0, #2]
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0201CCB0
	ldr r0, _0201CCA4 @ =0x0000FEFD
	cmp r1, r0
	bne _0201CCA8
	cmp r2, r1
	bne _0201CCA8
	mov r1, ip
	adds r1, #0x30
	movs r0, #1
	b _0201CCAE
	.align 2, 0
_0201CCA4: .4byte 0x0000FEFD
_0201CCA8:
	mov r1, ip
	adds r1, #0x30
	movs r0, #0xff
_0201CCAE:
	strb r0, [r1]
_0201CCB0:
	mov r3, ip
	ldr r2, [r3, #0x18]
	cmp r2, #0
	bge _0201CCD8
	mov r0, ip
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201CCC8
	ldr r1, _0201CCD0 @ =0x04000128
	ldr r0, _0201CCD4 @ =0x0000FEFE
	strh r0, [r1, #2]
_0201CCC8:
	movs r0, #0
	mov r6, ip
	strh r0, [r6, #0x28]
	b _0201CD6A
	.align 2, 0
_0201CCD0: .4byte 0x04000128
_0201CCD4: .4byte 0x0000FEFE
_0201CCD8:
	ldr r0, _0201CCF8 @ =0x00001DAD
	cmp r2, r0
	bgt _0201CD2C
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0x1f
	bne _0201CD00
	ldr r0, _0201CCFC @ =0x04000128
	mov r2, ip
	ldrh r1, [r2, #0x28]
	mvns r1, r1
	movs r2, #0
	strh r1, [r0, #2]
	mov r3, ip
	strh r2, [r3, #0x28]
	b _0201CD1C
	.align 2, 0
_0201CCF8: .4byte 0x00001DAD
_0201CCFC: .4byte 0x04000128
_0201CD00:
	ldr r3, _0201CD28 @ =0x04000128
	mov r6, ip
	ldr r2, [r6, #0x10]
	ldr r1, [r6, #8]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r3, #2]
	ldrh r0, [r0]
	ldrh r1, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r6, #0x28]
	adds r2, #1
	str r2, [r6, #0x10]
_0201CD1C:
	mov r2, ip
	ldr r0, [r2, #0x18]
	adds r0, #1
	str r0, [r2, #0x18]
	b _0201CD6A
	.align 2, 0
_0201CD28: .4byte 0x04000128
_0201CD2C:
	ldr r0, _0201CD40 @ =0x00001DAE
	cmp r2, r0
	bne _0201CD48
	ldr r0, _0201CD44 @ =0x04000128
	mov r3, ip
	ldrh r1, [r3, #0x2a]
	strh r1, [r0, #2]
	adds r0, r2, #1
	str r0, [r3, #0x18]
	b _0201CD6A
	.align 2, 0
_0201CD40: .4byte 0x00001DAE
_0201CD44: .4byte 0x04000128
_0201CD48:
	cmp r2, r0
	ble _0201CD6A
	mov r6, ip
	ldrb r2, [r6, #3]
	cmp r2, #0
	bne _0201CD5A
	ldrb r0, [r6, #4]
	cmp r0, #0
	beq _0201CD6A
_0201CD5A:
	ldr r0, _0201CD90 @ =0x0000FEFC
	adds r1, r0, #0
	cmp r2, #0
	beq _0201CD66
	ldr r2, _0201CD94 @ =0x0000FEFD
	adds r1, r2, #0
_0201CD66:
	ldr r0, _0201CD98 @ =0x04000128
	strh r1, [r0, #2]
_0201CD6A:
	mov r3, ip
	ldrb r0, [r3]
	cmp r0, #8
	bne _0201CD86
	ldr r3, _0201CD9C @ =0x0400010E
	movs r0, #0
	strh r0, [r3]
	ldr r2, _0201CD98 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xc0
	strh r0, [r3]
_0201CD86:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0201CD90: .4byte 0x0000FEFC
_0201CD94: .4byte 0x0000FEFD
_0201CD98: .4byte 0x04000128
_0201CD9C: .4byte 0x0400010E

	thumb_func_start sub_0201CDA0
sub_0201CDA0: @ 0x0201CDA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldr r1, _0201CDC8 @ =0x03003710
	mov sl, r1
	cmp r0, #1
	beq _0201CDCC
	cmp r0, #2
	beq _0201CE60
	movs r0, #1
	b _0201CF22
	.align 2, 0
_0201CDC8: .4byte 0x03003710
_0201CDCC:
	mov r1, sb
	subs r1, #0x11
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _0201CE4C @ =0x0600C000
	adds r4, r0, r2
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r2, #0
	str r1, [sp]
	movs r6, #0x10
	add r6, sl
	mov r8, r6
	ldr r0, _0201CE50 @ =0x00000FF8
	mov ip, r0
	ldr r5, _0201CE54 @ =0x0202FC1C
	movs r7, #7
_0201CDF6:
	ldrh r3, [r5]
	cmp r3, #0
	beq _0201CE10
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	lsls r0, r0, #3
	adds r1, r4, r0
	adds r0, r2, #0
	ands r0, r7
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r3, [r1]
_0201CE10:
	adds r5, #2
	adds r2, #1
	cmp r2, #0x3f
	ble _0201CDF6
	movs r3, #0
	ldr r1, [sp]
	ldr r6, _0201CE58 @ =0x0202FCFC
	mov r4, r8
	movs r5, #0x1f
_0201CE22:
	adds r0, r3, r6
	ldrb r2, [r0]
	adds r0, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r4, r0
	strh r5, [r0]
	adds r3, #1
	cmp r3, #0xf
	ble _0201CE22
	ldr r1, _0201CE5C @ =0x00000426
	add r1, sl
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	mov r2, sb
	movs r3, #0
	bl sub_0201DF9C
	b _0201CF20
	.align 2, 0
_0201CE4C: .4byte 0x0600C000
_0201CE50: .4byte 0x00000FF8
_0201CE54: .4byte 0x0202FC1C
_0201CE58: .4byte 0x0202FCFC
_0201CE5C: .4byte 0x00000426
_0201CE60:
	mov r1, sb
	subs r1, #0x11
	str r1, [sp]
	cmp r7, #0
	bne _0201CE7C
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _0201CE78 @ =0x0600C000
	adds r4, r0, r2
	b _0201CE88
	.align 2, 0
_0201CE78: .4byte 0x0600C000
_0201CE7C:
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r1
	lsls r0, r0, #3
	ldr r6, _0201CEE4 @ =0x0600C800
	adds r4, r0, r6
_0201CE88:
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r2, #0
	ldr r0, _0201CEE8 @ =0x00000FF8
	mov r8, r0
	ldr r5, _0201CEEC @ =0x0202FC9C
	movs r1, #7
	mov ip, r1
_0201CE9C:
	ldrh r3, [r5]
	cmp r3, #0
	beq _0201CEB8
	adds r0, r2, #0
	mov r6, r8
	ands r0, r6
	lsls r0, r0, #3
	adds r1, r4, r0
	adds r0, r2, #0
	mov r6, ip
	ands r0, r6
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r3, [r1]
_0201CEB8:
	adds r5, #2
	adds r2, #1
	cmp r2, #0x2f
	ble _0201CE9C
	ldr r1, [sp]
	movs r4, #0x20
	movs r3, #0x84
	lsls r3, r3, #2
	add r3, sl
	ldr r2, _0201CEF0 @ =0x0202FD0C
	adds r6, r2, #0
	adds r6, #8
	mov r5, sl
	adds r5, #0x10
_0201CED4:
	cmp r7, #0
	bne _0201CEF4
	ldrb r0, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r5, r0
	b _0201CEFE
	.align 2, 0
_0201CEE4: .4byte 0x0600C800
_0201CEE8: .4byte 0x00000FF8
_0201CEEC: .4byte 0x0202FC9C
_0201CEF0: .4byte 0x0202FD0C
_0201CEF4:
	ldrb r0, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r3, r0
_0201CEFE:
	strh r4, [r0]
	adds r2, #1
	cmp r2, r6
	ble _0201CED4
	adds r1, #0x21
	ldr r0, _0201CF34 @ =0x0000049A
	add r0, sl
	strb r1, [r0]
	ldr r1, _0201CF38 @ =0x00000429
	add r1, sl
	movs r0, #1
	strb r0, [r1]
	movs r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl sub_0201DF9C
_0201CF20:
	movs r0, #0
_0201CF22:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0201CF34: .4byte 0x0000049A
_0201CF38: .4byte 0x00000429

	thumb_func_start sub_0201CF3C
sub_0201CF3C: @ 0x0201CF3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov ip, r2
	ldr r6, _0201CF6C @ =0x03003710
	movs r0, #0
	mov sl, r0
	subs r0, r7, #3
	cmp r0, #0x11
	bls _0201CF62
	b _0201D188
_0201CF62:
	lsls r0, r0, #2
	ldr r1, _0201CF70 @ =_0201CF74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0201CF6C: .4byte 0x03003710
_0201CF70: .4byte _0201CF74
_0201CF74: @ jump table
	.4byte _0201D174 @ case 0
	.4byte _0201D174 @ case 1
	.4byte _0201CFBC @ case 2
	.4byte _0201CFBC @ case 3
	.4byte _0201CFBC @ case 4
	.4byte _0201CFBC @ case 5
	.4byte _0201CFBC @ case 6
	.4byte _0201CFBC @ case 7
	.4byte _0201CFBC @ case 8
	.4byte _0201CFBC @ case 9
	.4byte _0201CFBC @ case 10
	.4byte _0201D174 @ case 11
	.4byte _0201D174 @ case 12
	.4byte _0201D174 @ case 13
	.4byte _0201D174 @ case 14
	.4byte _0201D174 @ case 15
	.4byte _0201D0B4 @ case 16
	.4byte _0201D0C0 @ case 17
_0201CFBC:
	movs r1, #0xf
	adds r0, r5, #0
	ands r0, r1
	subs r3, r0, #1
	ands r3, r1
	movs r0, #0xf0
	ands r0, r5
	orrs r3, r0
	mov r2, ip
	cmp r2, #0
	beq _0201CFDA
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0xf
	bne _0201CFF8
_0201CFDA:
	ldr r4, _0201CFF0 @ =0x0600C000
	lsls r1, r3, #1
	adds r0, r6, #0
	adds r0, #0x10
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _0201CFF4 @ =0x00000414
	adds r0, r6, r2
	strh r1, [r0]
	b _0201D010
	.align 2, 0
_0201CFF0: .4byte 0x0600C000
_0201CFF4: .4byte 0x00000414
_0201CFF8:
	ldr r4, _0201D0A0 @ =0x0600C800
	lsls r1, r3, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _0201D0A4 @ =0x00000414
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #1
	mov sl, r0
_0201D010:
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r3
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r0, #0xf
	ands r3, r0
	lsls r0, r3, #2
	adds r4, r4, r0
	ldr r1, _0201D0A8 @ =0x0202FD16
	subs r0, r7, #5
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r4, #0x42
	ldr r1, _0201D0A4 @ =0x00000414
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, _0201D0AC @ =0x00000FFF
	cmp r1, r0
	bne _0201D03C
	strh r2, [r4]
_0201D03C:
	adds r4, #2
	adds r2, #1
	adds r3, r7, #0
	subs r3, #0xc
	str r3, [sp]
	movs r0, #0xff
	mov sb, r0
	movs r1, #0xf8
	lsls r1, r1, #3
	mov r8, r1
	movs r3, #2
_0201D052:
	mov r0, sl
	cmp r0, #0
	bne _0201D070
	adds r1, r4, #0
	mov r0, sb
	ands r1, r0
	cmp r1, #0
	beq _0201D06E
	cmp r1, #0x40
	beq _0201D06E
	cmp r1, #0x80
	beq _0201D06E
	cmp r1, #0xc0
	bne _0201D070
_0201D06E:
	add r4, r8
_0201D070:
	strh r2, [r4]
	subs r3, #1
	adds r4, #2
	adds r2, #1
	cmp r3, #0
	bge _0201D052
	ldr r1, [sp]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0201D088
	b _0201D188
_0201D088:
	movs r2, #0
	ldr r0, _0201D0B0 @ =0x0000044D
	adds r3, r6, r0
_0201D08E:
	adds r1, r3, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0201D15C
	adds r3, r1, #1
	adds r2, #1
	cmp r2, #0x1d
	ble _0201D08E
	b _0201D188
	.align 2, 0
_0201D0A0: .4byte 0x0600C800
_0201D0A4: .4byte 0x00000414
_0201D0A8: .4byte 0x0202FD16
_0201D0AC: .4byte 0x00000FFF
_0201D0B0: .4byte 0x0000044D
_0201D0B4:
	movs r0, #0x54
	adds r1, r5, #0
	mov r2, ip
	bl sub_0201E1E0
	b _0201D188
_0201D0C0:
	mov r1, ip
	cmp r1, #0
	bne _0201D0E8
	movs r1, #0xff
	lsls r1, r1, #4
	ands r1, r5
	lsls r1, r1, #3
	ldr r2, _0201D0E0 @ =0x0600A000
	adds r4, r1, r2
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r3, _0201D0E4 @ =0x0600C000
	adds r1, r1, r3
	b _0201D100
	.align 2, 0
_0201D0E0: .4byte 0x0600A000
_0201D0E4: .4byte 0x0600C000
_0201D0E8:
	movs r1, #0xff
	lsls r1, r1, #4
	ands r1, r5
	lsls r1, r1, #3
	ldr r0, _0201D144 @ =0x0600A800
	adds r4, r1, r0
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _0201D148 @ =0x0600C800
	adds r1, r1, r2
_0201D100:
	adds r1, r1, r0
	ldrh r0, [r4]
	ldr r2, _0201D14C @ =0x000003FF
	ands r2, r0
	ldr r3, _0201D150 @ =0x00000412
	adds r0, r6, r3
	strh r2, [r0]
	adds r0, r2, #0
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0201D126
	adds r0, r2, #0
	subs r0, #0xc6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0201D188
_0201D126:
	ldr r2, _0201D154 @ =0x000022AC
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0201D158 @ =0x000022AD
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #0x3e
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r3, #2
	adds r0, r3, #0
	strh r0, [r1, #2]
	b _0201D188
	.align 2, 0
_0201D144: .4byte 0x0600A800
_0201D148: .4byte 0x0600C800
_0201D14C: .4byte 0x000003FF
_0201D150: .4byte 0x00000412
_0201D154: .4byte 0x000022AC
_0201D158: .4byte 0x000022AD
_0201D15C:
	movs r0, #1
	strb r0, [r3]
	b _0201D166
_0201D162:
	movs r0, #1
	strb r0, [r1]
_0201D166:
	adds r0, r2, #0
	adds r1, r7, #0
	adds r2, r5, #0
	mov r3, ip
	bl sub_0201E430
	b _0201D188
_0201D174:
	movs r2, #0
	ldr r0, _0201D198 @ =0x0000044D
	adds r1, r6, r0
_0201D17A:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0201D162
	adds r1, #1
	adds r2, #1
	cmp r2, #0x1d
	ble _0201D17A
_0201D188:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201D198: .4byte 0x0000044D

	thumb_func_start sub_0201D19C
sub_0201D19C: @ 0x0201D19C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0201D270 @ =0x03003710
	ldr r2, _0201D274 @ =0x00000412
	adds r1, r0, r2
	ldr r0, _0201D278 @ =0x00005851
	strh r0, [r1]
	movs r3, #0
	mov r8, r3
	ldr r2, _0201D27C @ =0x0600C000
	ldr r1, _0201D280 @ =0x00000FFF
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
_0201D1C0:
	strh r0, [r2]
	movs r5, #2
	add r8, r5
	adds r2, #2
	cmp r8, r1
	ble _0201D1C0
	ldr r7, _0201D270 @ =0x03003710
	adds r7, #0x10
	str r7, [sp, #4]
	ldr r2, _0201D280 @ =0x00000FFF
	ldr r0, _0201D270 @ =0x03003710
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r0, r3
	adds r0, r7, #0
	movs r4, #0xff
	mov r8, r4
_0201D1E2:
	strh r2, [r0]
	strh r2, [r1]
	adds r1, #2
	adds r0, #2
	movs r5, #1
	rsbs r5, r5, #0
	add r8, r5
	mov r7, r8
	cmp r7, #0
	bge _0201D1E2
	movs r0, #0
	mov r8, r0
_0201D1FA:
	ldr r1, _0201D284 @ =0x03001B40
	ldr r2, [r1]
	mov r1, r8
	movs r3, #0xf
	ands r1, r3
	lsls r1, r1, #1
	mov r5, r8
	asrs r4, r5, #4
	adds r0, r4, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r5, r1, r0
	adds r2, #0x24
	adds r2, r2, r5
	ldrh r0, [r2]
	bl sub_02024A9C
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	mov r7, r8
	adds r7, #1
	str r7, [sp]
	mov sl, r4
	cmp r1, #0
	beq _0201D230
	b _0201D37E
_0201D230:
	ldr r1, _0201D284 @ =0x03001B40
	ldr r0, [r1]
	adds r0, #0x24
	adds r0, r0, r5
	ldrh r0, [r0]
	bl sub_02024A9C
	adds r6, r0, #0
	cmp r6, #0x57
	ble _0201D246
	b _0201D37E
_0201D246:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _0201D288 @ =0x0202F7FC
	adds r0, r0, r1
	mov sb, r0
	cmp r6, #0x57
	bne _0201D290
	mov r2, r8
	lsls r0, r2, #1
	ldr r3, [sp, #4]
	adds r2, r3, r0
	ldrh r1, [r2]
	adds r7, r0, #0
	ldr r4, _0201D280 @ =0x00000FFF
	cmp r1, r4
	bne _0201D29C
	ldr r0, _0201D28C @ =0x00007777
	strh r0, [r2]
	b _0201D29C
	.align 2, 0
_0201D270: .4byte 0x03003710
_0201D274: .4byte 0x00000412
_0201D278: .4byte 0x00005851
_0201D27C: .4byte 0x0600C000
_0201D280: .4byte 0x00000FFF
_0201D284: .4byte 0x03001B40
_0201D288: .4byte 0x0202F7FC
_0201D28C: .4byte 0x00007777
_0201D290:
	mov r5, r8
	lsls r1, r5, #1
	ldr r7, [sp, #4]
	adds r0, r7, r1
	strh r6, [r0]
	adds r7, r1, #0
_0201D29C:
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #0x9c
	lsls r0, r0, #2
	cmp r1, r0
	bne _0201D2E0
	ldr r1, _0201D3F0 @ =0x03001B40
	ldr r5, [r1]
	mov r4, sl
	movs r2, #0xf
	ands r4, r2
	lsls r0, r4, #1
	ldr r1, _0201D3F4 @ =0x000018F8
	adds r3, r5, r1
	adds r3, r3, r0
	mov r2, r8
	movs r0, #0xf
	ands r2, r0
	movs r0, #1
	lsls r0, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	lsls r2, r2, #1
	lsls r4, r4, #5
	adds r2, r2, r4
	adds r5, #0x24
	adds r5, r5, r2
	ldr r0, _0201D3F8 @ =0x00002512
	strh r0, [r5]
	ldr r2, [sp, #4]
	adds r1, r2, r7
	movs r0, #0x10
	strh r0, [r1]
_0201D2E0:
	mov r3, r8
	adds r3, #1
	str r3, [sp]
	cmp r6, #0x57
	beq _0201D37E
	mov r4, sb
	ldrh r0, [r4]
	mov r1, r8
	movs r2, #0
	bl sub_0201CDA0
	adds r3, r0, #0
	cmp r3, #1
	bne _0201D37E
	ldrh r0, [r4]
	ldr r5, _0201D3FC @ =0x03003710
	ldr r7, _0201D400 @ =0x00000414
	adds r2, r5, r7
	movs r4, #0
	strh r0, [r2]
	ldr r0, _0201D3F0 @ =0x03001B40
	ldr r1, [r0]
	mov r0, sl
	movs r5, #0xf
	ands r0, r5
	lsls r0, r0, #1
	ldr r7, _0201D3F4 @ =0x000018F8
	adds r1, r1, r7
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r0, r8
	ands r0, r5
	asrs r1, r0
	ands r1, r3
	cmp r1, #0
	beq _0201D32C
	ldr r0, _0201D404 @ =0x00001270
	strh r0, [r2]
_0201D32C:
	movs r4, #0
	ldr r1, _0201D3FC @ =0x03003710
	ldr r3, _0201D408 @ =0x00000412
	adds r0, r1, r3
	strh r4, [r0]
	movs r1, #0xff
	lsls r1, r1, #4
	mov r5, r8
	ands r1, r5
	lsls r6, r1, #3
	movs r1, #0xf
	ands r1, r5
	lsls r1, r1, #2
	adds r5, r2, #0
	adds r3, r0, #0
	movs r7, #2
	mov ip, r7
_0201D34E:
	ldr r0, _0201D40C @ =0x0600C000
	adds r2, r4, r0
	adds r2, r2, r6
	adds r2, r2, r1
	ldrh r0, [r3]
	ldrh r7, [r5]
	adds r0, r0, r7
	strh r0, [r2]
	ldrh r0, [r3]
	ldrh r7, [r5]
	adds r0, r0, r7
	adds r0, #1
	strh r0, [r2, #2]
	adds r4, #0x40
	mov r0, ip
	strh r0, [r3]
	cmp r4, #0x4f
	ble _0201D34E
	mov r1, sb
	ldrh r0, [r1, #2]
	mov r1, r8
	movs r2, #0
	bl sub_0201CF3C
_0201D37E:
	ldr r5, _0201D3F0 @ =0x03001B40
	ldr r2, [r5]
	mov r1, r8
	movs r3, #0xf
	ands r1, r3
	lsls r1, r1, #1
	mov r0, sl
	ands r0, r3
	lsls r0, r0, #5
	adds r4, r1, r0
	movs r7, #0x89
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r2, r2, r4
	ldrh r0, [r2]
	bl sub_02024A9C
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _0201D3AC
	b _0201D514
_0201D3AC:
	ldr r0, [r5]
	adds r1, r7, #0
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	bl sub_02024A9C
	adds r6, r0, #0
	cmp r6, #0x57
	ble _0201D3C2
	b _0201D514
_0201D3C2:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _0201D410 @ =0x0202F7FC
	adds r0, r0, r1
	mov sb, r0
	cmp r6, #0x57
	bne _0201D41C
	mov r2, r8
	lsls r0, r2, #1
	ldr r3, _0201D3FC @ =0x03003710
	movs r4, #0x84
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r2, r1, r0
	ldrh r1, [r2]
	adds r7, r0, #0
	ldr r5, _0201D414 @ =0x00000FFF
	cmp r1, r5
	bne _0201D42E
	ldr r0, _0201D418 @ =0x00007777
	strh r0, [r2]
	b _0201D42E
	.align 2, 0
_0201D3F0: .4byte 0x03001B40
_0201D3F4: .4byte 0x000018F8
_0201D3F8: .4byte 0x00002512
_0201D3FC: .4byte 0x03003710
_0201D400: .4byte 0x00000414
_0201D404: .4byte 0x00001270
_0201D408: .4byte 0x00000412
_0201D40C: .4byte 0x0600C000
_0201D410: .4byte 0x0202F7FC
_0201D414: .4byte 0x00000FFF
_0201D418: .4byte 0x00007777
_0201D41C:
	mov r7, r8
	lsls r1, r7, #1
	ldr r2, _0201D530 @ =0x03003710
	movs r3, #0x84
	lsls r3, r3, #2
	adds r0, r2, r3
	adds r0, r0, r1
	strh r6, [r0]
	adds r7, r1, #0
_0201D42E:
	mov r4, sb
	ldrh r1, [r4]
	movs r0, #0x9c
	lsls r0, r0, #2
	cmp r1, r0
	bne _0201D47A
	ldr r0, _0201D534 @ =0x03001B40
	ldr r5, [r0]
	mov r4, sl
	movs r1, #0xf
	ands r4, r1
	lsls r0, r4, #1
	ldr r2, _0201D538 @ =0x00001918
	adds r3, r5, r2
	adds r3, r3, r0
	mov r2, r8
	ands r2, r1
	movs r0, #1
	lsls r0, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	lsls r2, r2, #1
	lsls r4, r4, #5
	adds r2, r2, r4
	movs r3, #0x89
	lsls r3, r3, #2
	adds r5, r5, r3
	adds r5, r5, r2
	ldr r0, _0201D53C @ =0x00002512
	strh r0, [r5]
	ldr r4, _0201D530 @ =0x03003710
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r4, r5
	adds r0, r0, r7
	movs r1, #0x10
	strh r1, [r0]
_0201D47A:
	cmp r6, #0x57
	beq _0201D514
	mov r7, sb
	ldrh r0, [r7]
	mov r1, r8
	movs r2, #1
	bl sub_0201CDA0
	adds r3, r0, #0
	cmp r3, #1
	bne _0201D514
	ldrh r0, [r7]
	ldr r1, _0201D530 @ =0x03003710
	ldr r4, _0201D540 @ =0x00000414
	adds r2, r1, r4
	movs r4, #0
	strh r0, [r2]
	ldr r5, _0201D534 @ =0x03001B40
	ldr r0, [r5]
	movs r7, #0xf
	mov r1, sl
	ands r7, r1
	lsls r1, r7, #1
	ldr r5, _0201D538 @ =0x00001918
	adds r0, r0, r5
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r0, r8
	movs r7, #0xf
	ands r0, r7
	asrs r1, r0
	ands r1, r3
	cmp r1, #0
	beq _0201D4C2
	ldr r0, _0201D544 @ =0x00001270
	strh r0, [r2]
_0201D4C2:
	movs r4, #0
	ldr r1, _0201D530 @ =0x03003710
	ldr r3, _0201D548 @ =0x00000412
	adds r0, r1, r3
	strh r4, [r0]
	movs r1, #0xff
	lsls r1, r1, #4
	mov r5, r8
	ands r1, r5
	lsls r6, r1, #3
	movs r1, #0xf
	ands r1, r5
	lsls r1, r1, #2
	adds r5, r2, #0
	adds r3, r0, #0
	movs r7, #2
	mov sl, r7
_0201D4E4:
	ldr r0, _0201D54C @ =0x0600C800
	adds r2, r4, r0
	adds r2, r2, r6
	adds r2, r2, r1
	ldrh r0, [r3]
	ldrh r7, [r5]
	adds r0, r0, r7
	strh r0, [r2]
	ldrh r0, [r3]
	ldrh r7, [r5]
	adds r0, r0, r7
	adds r0, #1
	strh r0, [r2, #2]
	adds r4, #0x40
	mov r0, sl
	strh r0, [r3]
	cmp r4, #0x4f
	ble _0201D4E4
	mov r1, sb
	ldrh r0, [r1, #2]
	mov r1, r8
	movs r2, #1
	bl sub_0201CF3C
_0201D514:
	ldr r2, [sp]
	mov r8, r2
	cmp r2, #0xff
	bgt _0201D51E
	b _0201D1FA
_0201D51E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201D530: .4byte 0x03003710
_0201D534: .4byte 0x03001B40
_0201D538: .4byte 0x00001918
_0201D53C: .4byte 0x00002512
_0201D540: .4byte 0x00000414
_0201D544: .4byte 0x00001270
_0201D548: .4byte 0x00000412
_0201D54C: .4byte 0x0600C800

	thumb_func_start sub_0201D550
sub_0201D550: @ 0x0201D550
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0201D5A8 @ =0x03003710
	mov r8, r0
	ldr r0, _0201D5AC @ =0x03001B50
	ldr r0, [r0, #0x10]
	ldr r1, _0201D5B0 @ =0x00034BC0
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0201D5B4 @ =0x00000416
	add r0, r8
	ldrb r0, [r0]
	cmp r0, r5
	beq _0201D59E
	movs r2, #0
	ldr r4, _0201D5B8 @ =0x02000102
	ldr r3, _0201D5BC @ =0x02000122
	ldr r7, _0201D5C0 @ =0x02034EE4
	lsls r1, r5, #0x12
	movs r6, #0x80
	lsls r6, r6, #9
_0201D580:
	lsrs r0, r1, #0x10
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r4]
	strh r0, [r3]
	adds r1, r1, r6
	adds r2, #1
	adds r4, #2
	adds r3, #2
	cmp r2, #3
	ble _0201D580
	ldr r0, _0201D5B4 @ =0x00000416
	add r0, r8
	strb r5, [r0]
_0201D59E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201D5A8: .4byte 0x03003710
_0201D5AC: .4byte 0x03001B50
_0201D5B0: .4byte 0x00034BC0
_0201D5B4: .4byte 0x00000416
_0201D5B8: .4byte 0x02000102
_0201D5BC: .4byte 0x02000122
_0201D5C0: .4byte 0x02034EE4

	thumb_func_start sub_0201D5C4
sub_0201D5C4: @ 0x0201D5C4
	push {r4, r5, r6, r7, lr}
	ldr r6, _0201D684 @ =0x03003710
	ldr r0, _0201D688 @ =0x03001B50
	ldr r0, [r0, #0x10]
	ldr r1, _0201D68C @ =0x00034BC0
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0201D690 @ =0x00000416
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, r5
	beq _0201D60E
	movs r2, #0
	ldr r4, _0201D694 @ =0x02000102
	ldr r3, _0201D698 @ =0x02000122
	ldr r0, _0201D69C @ =0x02034EE4
	mov ip, r0
	lsls r1, r5, #0x12
	movs r7, #0x80
	lsls r7, r7, #9
_0201D5F0:
	lsrs r0, r1, #0x10
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r4]
	strh r0, [r3]
	adds r1, r1, r7
	adds r2, #1
	adds r4, #2
	adds r3, #2
	cmp r2, #3
	ble _0201D5F0
	ldr r1, _0201D690 @ =0x00000416
	adds r0, r6, r1
	strb r5, [r0]
_0201D60E:
	ldr r2, _0201D690 @ =0x00000416
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _0201D6A0 @ =0x00000417
	adds r1, r6, r3
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	bl sub_02025D70
	bl sub_02020B88
	ldr r0, _0201D6A4 @ =0x00000497
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0201D6A8 @ =0x00000499
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _0201D6AC @ =0x0000049A
	adds r0, r6, r3
	strb r4, [r0]
	str r4, [r6, #8]
	str r4, [r6, #0xc]
	str r4, [r6]
	str r4, [r6, #4]
	adds r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	subs r2, #0x89
	adds r0, r6, r2
	movs r1, #0
	strh r4, [r0]
	adds r3, #3
	adds r0, r6, r3
	strb r1, [r0]
	ldr r0, _0201D6B0 @ =0x03001B40
	ldr r0, [r0]
	ldr r2, _0201D6B4 @ =0x00001938
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r2, #3
	ands r2, r0
	subs r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	cmp r2, #1
	beq _0201D6D0
	cmp r2, #1
	bgt _0201D6B8
	cmp r2, #0
	beq _0201D6C2
	b _0201D700
	.align 2, 0
_0201D684: .4byte 0x03003710
_0201D688: .4byte 0x03001B50
_0201D68C: .4byte 0x00034BC0
_0201D690: .4byte 0x00000416
_0201D694: .4byte 0x02000102
_0201D698: .4byte 0x02000122
_0201D69C: .4byte 0x02034EE4
_0201D6A0: .4byte 0x00000417
_0201D6A4: .4byte 0x00000497
_0201D6A8: .4byte 0x00000499
_0201D6AC: .4byte 0x0000049A
_0201D6B0: .4byte 0x03001B40
_0201D6B4: .4byte 0x00001938
_0201D6B8:
	cmp r2, #2
	beq _0201D6E0
	cmp r2, #3
	beq _0201D6F0
	b _0201D700
_0201D6C2:
	ldr r1, _0201D6C8 @ =0x040000D4
	ldr r0, _0201D6CC @ =0x0202D3FC
	b _0201D6F4
	.align 2, 0
_0201D6C8: .4byte 0x040000D4
_0201D6CC: .4byte 0x0202D3FC
_0201D6D0:
	ldr r1, _0201D6D8 @ =0x040000D4
	ldr r0, _0201D6DC @ =0x0202DBFC
	b _0201D6F4
	.align 2, 0
_0201D6D8: .4byte 0x040000D4
_0201D6DC: .4byte 0x0202DBFC
_0201D6E0:
	ldr r1, _0201D6E8 @ =0x040000D4
	ldr r0, _0201D6EC @ =0x0202E3FC
	b _0201D6F4
	.align 2, 0
_0201D6E8: .4byte 0x040000D4
_0201D6EC: .4byte 0x0202E3FC
_0201D6F0:
	ldr r1, _0201D71C @ =0x040000D4
	ldr r0, _0201D720 @ =0x0202EBFC
_0201D6F4:
	str r0, [r1]
	ldr r0, _0201D724 @ =0x0600A000
	str r0, [r1, #4]
	ldr r0, _0201D728 @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0201D700:
	ldr r0, _0201D72C @ =0x03001B40
	ldr r0, [r0]
	ldr r1, _0201D730 @ =0x00001939
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r2, #3
	ands r2, r0
	cmp r2, #1
	beq _0201D74C
	cmp r2, #1
	bgt _0201D734
	cmp r2, #0
	beq _0201D73E
	b _0201D77C
	.align 2, 0
_0201D71C: .4byte 0x040000D4
_0201D720: .4byte 0x0202EBFC
_0201D724: .4byte 0x0600A000
_0201D728: .4byte 0x84000200
_0201D72C: .4byte 0x03001B40
_0201D730: .4byte 0x00001939
_0201D734:
	cmp r2, #2
	beq _0201D75C
	cmp r2, #3
	beq _0201D76C
	b _0201D77C
_0201D73E:
	ldr r1, _0201D744 @ =0x040000D4
	ldr r0, _0201D748 @ =0x0202B3FC
	b _0201D770
	.align 2, 0
_0201D744: .4byte 0x040000D4
_0201D748: .4byte 0x0202B3FC
_0201D74C:
	ldr r1, _0201D754 @ =0x040000D4
	ldr r0, _0201D758 @ =0x0202BBFC
	b _0201D770
	.align 2, 0
_0201D754: .4byte 0x040000D4
_0201D758: .4byte 0x0202BBFC
_0201D75C:
	ldr r1, _0201D764 @ =0x040000D4
	ldr r0, _0201D768 @ =0x0202C3FC
	b _0201D770
	.align 2, 0
_0201D764: .4byte 0x040000D4
_0201D768: .4byte 0x0202C3FC
_0201D76C:
	ldr r1, _0201D798 @ =0x040000D4
	ldr r0, _0201D79C @ =0x0202CBFC
_0201D770:
	str r0, [r1]
	ldr r0, _0201D7A0 @ =0x0600A800
	str r0, [r1, #4]
	ldr r0, _0201D7A4 @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0201D77C:
	movs r1, #0
	movs r2, #0x7f
	ldr r3, _0201D7A8 @ =0x00000496
	adds r0, r6, r3
_0201D784:
	strb r1, [r0]
	subs r0, #1
	subs r2, #1
	cmp r2, #0
	bge _0201D784
	bl sub_0201D19C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201D798: .4byte 0x040000D4
_0201D79C: .4byte 0x0202CBFC
_0201D7A0: .4byte 0x0600A800
_0201D7A4: .4byte 0x84000200
_0201D7A8: .4byte 0x00000496

	thumb_func_start sub_0201D7AC
sub_0201D7AC: @ 0x0201D7AC
	push {lr}
	ldr r0, _0201D7EC @ =0x0400000E
	ldrh r1, [r0]
	movs r3, #0xc0
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0201D7E8
	ldr r2, _0201D7F0 @ =0x03001B50
	ldr r0, _0201D7F4 @ =0x00000828
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r3, #0
	orrs r0, r1
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	ldr r0, _0201D7F8 @ =0x03001B40
	ldr r0, [r0]
	ldr r1, _0201D7FC @ =0x0000193A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201D7E8
	movs r0, #0x26
	bl sub_02026BC8
_0201D7E8:
	pop {r0}
	bx r0
	.align 2, 0
_0201D7EC: .4byte 0x0400000E
_0201D7F0: .4byte 0x03001B50
_0201D7F4: .4byte 0x00000828
_0201D7F8: .4byte 0x03001B40
_0201D7FC: .4byte 0x0000193A

	thumb_func_start sub_0201D800
sub_0201D800: @ 0x0201D800
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r5, _0201D854 @ =0x03003710
	cmp r2, #0
	beq _0201D878
	ldr r2, _0201D858 @ =0x03001B50
	ldr r0, _0201D85C @ =0x00000824
	adds r3, r2, r0
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3]
	ldr r7, _0201D860 @ =0x00000826
	adds r3, r2, r7
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0201D864 @ =0x00000828
	adds r2, r2, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r2, #0x82
	lsls r2, r2, #3
	adds r1, r5, r2
	ldr r3, _0201D868 @ =0x00001111
	adds r0, r3, #0
	ldrh r7, [r1]
	adds r2, r0, r7
	strh r2, [r1]
	lsls r1, r2, #0x10
	ldr r0, _0201D86C @ =0xFFFF0000
	cmp r1, r0
	bne _0201D8F0
	ldr r1, _0201D870 @ =0x0000049B
	adds r0, r5, r1
	movs r1, #2
	strb r1, [r0]
_0201D84E:
	ldr r0, _0201D874 @ =0x0400004C
	strh r2, [r0]
	b _0201D8FC
	.align 2, 0
_0201D854: .4byte 0x03003710
_0201D858: .4byte 0x03001B50
_0201D85C: .4byte 0x00000824
_0201D860: .4byte 0x00000826
_0201D864: .4byte 0x00000828
_0201D868: .4byte 0x00001111
_0201D86C: .4byte 0xFFFF0000
_0201D870: .4byte 0x0000049B
_0201D874: .4byte 0x0400004C
_0201D878:
	ldr r6, _0201D8D4 @ =0x03001B50
	ldr r7, _0201D8D8 @ =0x00000824
	adds r3, r6, r7
	ldrh r1, [r3]
	movs r4, #0x40
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0201D8FC
	movs r0, #0x82
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0201D89A
	ldr r0, _0201D8DC @ =0x0000FFFF
	strh r0, [r1]
_0201D89A:
	ldr r7, _0201D8E0 @ =0x0000049B
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0201D8E4 @ =0xFFFFEEEF
	adds r0, r2, #0
	ldrh r5, [r1]
	adds r2, r0, r5
	strh r2, [r1]
	lsls r0, r2, #0x10
	cmp r0, #0
	bne _0201D8F0
	ldrh r0, [r3]
	eors r0, r4
	strh r0, [r3]
	ldr r7, _0201D8E8 @ =0x00000826
	adds r1, r6, r7
	ldrh r0, [r1]
	eors r0, r4
	strh r0, [r1]
	ldr r0, _0201D8EC @ =0x00000828
	adds r1, r6, r0
	ldrh r0, [r1]
	eors r0, r4
	strh r0, [r1]
	b _0201D84E
	.align 2, 0
_0201D8D4: .4byte 0x03001B50
_0201D8D8: .4byte 0x00000824
_0201D8DC: .4byte 0x0000FFFF
_0201D8E0: .4byte 0x0000049B
_0201D8E4: .4byte 0xFFFFEEEF
_0201D8E8: .4byte 0x00000826
_0201D8EC: .4byte 0x00000828
_0201D8F0:
	ldr r0, _0201D8F8 @ =0x0400004C
	strh r2, [r0]
	movs r0, #0
	b _0201D8FE
	.align 2, 0
_0201D8F8: .4byte 0x0400004C
_0201D8FC:
	movs r0, #1
_0201D8FE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0201D904
sub_0201D904: @ 0x0201D904
	push {r4, lr}
	ldr r4, _0201D930 @ =0x03003710
	ldr r1, _0201D934 @ =0x0400004C
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0201D938 @ =0x0202FD28
	ldr r2, _0201D93C @ =0x0000049C
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0201D940 @ =0x0000049B
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #3
	beq _0201D944
	movs r0, #0
	b _0201D946
	.align 2, 0
_0201D930: .4byte 0x03003710
_0201D934: .4byte 0x0400004C
_0201D938: .4byte 0x0202FD28
_0201D93C: .4byte 0x0000049C
_0201D940: .4byte 0x0000049B
_0201D944:
	movs r0, #1
_0201D946:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_0201D94C
sub_0201D94C: @ 0x0201D94C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _0201D9FC @ =0x030041A0
	ldr r5, _0201DA00 @ =0x03004B80
	ldr r6, _0201DA04 @ =0x03003710
	bl sub_0201D550
	ldr r0, _0201DA08 @ =0x03001B50
	mov r8, r0
	movs r1, #0x82
	lsls r1, r1, #4
	add r1, r8
	ldr r0, _0201DA0C @ =0x00003E41
	strh r0, [r1]
	ldr r1, _0201DA10 @ =0x0000081C
	add r1, r8
	ldr r0, _0201DA14 @ =0x00001006
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201DA28
	movs r0, #0
	bl sub_0201D800
	adds r2, r0, #0
	cmp r2, #0
	bne _0201DA28
	ldr r0, [r5]
	asrs r0, r0, #8
	subs r0, #0x80
	movs r4, #0x84
	lsls r4, r4, #4
	add r4, r8
	strh r0, [r4]
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	subs r0, #0x50
	ldr r5, _0201DA18 @ =0x00000842
	add r5, r8
	strh r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #4
	ands r0, r3
	cmp r0, #0
	beq _0201D9B0
	strh r2, [r5]
_0201D9B0:
	ldrh r0, [r5]
	cmp r0, #0x60
	bls _0201D9BA
	movs r0, #0x60
	strh r0, [r5]
_0201D9BA:
	ldrh r1, [r4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0201D9C6
	strh r2, [r4]
_0201D9C6:
	ldrh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bls _0201D9D2
	strh r1, [r4]
_0201D9D2:
	adds r0, r7, #0
	adds r0, #0x90
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_02026C7C
	ldrh r1, [r4]
	ldr r0, _0201DA1C @ =0x00000844
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r5]
	ldr r0, _0201DA20 @ =0x00000846
	add r0, r8
	strh r1, [r0]
	ldr r2, _0201DA24 @ =0x0000049E
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _0201DC98
	.align 2, 0
_0201D9FC: .4byte 0x030041A0
_0201DA00: .4byte 0x03004B80
_0201DA04: .4byte 0x03003710
_0201DA08: .4byte 0x03001B50
_0201DA0C: .4byte 0x00003E41
_0201DA10: .4byte 0x0000081C
_0201DA14: .4byte 0x00001006
_0201DA18: .4byte 0x00000842
_0201DA1C: .4byte 0x00000844
_0201DA20: .4byte 0x00000846
_0201DA24: .4byte 0x0000049E
_0201DA28:
	ldr r1, _0201DA70 @ =0x03001B50
	ldr r3, _0201DA74 @ =0x00000856
	adds r0, r1, r3
	ldrb r4, [r0]
	adds r3, r1, #0
	cmp r4, #1
	bne _0201DA80
	adds r0, r7, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201DA80
	movs r0, #0x14
	bl sub_02026C68
	bl sub_02026BD8
	movs r7, #0x82
	lsls r7, r7, #3
	adds r1, r6, r7
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0201DA78 @ =0x0000049D
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0201DA7C @ =0x0000049E
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #0x8b
	adds r0, r6, r7
	strb r4, [r0]
	subs r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	b _0201DC98
	.align 2, 0
_0201DA70: .4byte 0x03001B50
_0201DA74: .4byte 0x00000856
_0201DA78: .4byte 0x0000049D
_0201DA7C: .4byte 0x0000049E
_0201DA80:
	ldr r2, _0201DAC8 @ =0x0000084E
	adds r0, r3, r2
	ldrb r4, [r0]
	cmp r4, #1
	bne _0201DAD8
	adds r0, r7, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201DAD8
	movs r0, #0x14
	bl sub_02026C68
	bl sub_02026BD8
	movs r3, #0x82
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r7, _0201DACC @ =0x0000049D
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0201DAD0 @ =0x0000049E
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0201DAD4 @ =0x0000049B
	adds r0, r6, r2
	strb r4, [r0]
	adds r3, #0x8c
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	b _0201DC98
	.align 2, 0
_0201DAC8: .4byte 0x0000084E
_0201DACC: .4byte 0x0000049D
_0201DAD0: .4byte 0x0000049E
_0201DAD4: .4byte 0x0000049B
_0201DAD8:
	ldr r1, _0201DB34 @ =0x0000081A
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0201DB44
	adds r0, r7, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #1
	beq _0201DB44
	ldr r2, _0201DB38 @ =0x00000824
	adds r0, r3, r2
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0201DB44
	movs r0, #0x14
	bl sub_02026C68
	bl sub_02026BD8
	movs r3, #0x82
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r1, #0
	strh r4, [r0]
	ldr r7, _0201DB3C @ =0x0000049D
	adds r0, r6, r7
	strb r1, [r0]
	ldr r2, _0201DB40 @ =0x0000049E
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #0x8b
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	subs r7, #1
	adds r1, r6, r7
	movs r0, #3
	strb r0, [r1]
	b _0201DC98
	.align 2, 0
_0201DB34: .4byte 0x0000081A
_0201DB38: .4byte 0x00000824
_0201DB3C: .4byte 0x0000049D
_0201DB40: .4byte 0x0000049E
_0201DB44:
	ldr r0, _0201DCA4 @ =0x0400000E
	ldrh r1, [r0]
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0201DB84
	ldr r0, _0201DCA8 @ =0x00000828
	adds r3, r3, r0
	ldrh r1, [r3]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0201DB84
	adds r0, r2, #0
	eors r0, r1
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0201DCAC @ =0x03001B40
	ldr r0, [r0]
	ldr r3, _0201DCB0 @ =0x0000193A
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201DB84
	movs r0, #0x26
	bl sub_02026B48
_0201DB84:
	ldr r7, _0201DCB4 @ =0x00000497
	adds r1, r6, r7
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0201DBEE
	movs r0, #8
	strb r0, [r1]
	movs r5, #0x80
	lsls r5, r5, #0x12
	ldr r3, _0201DCB8 @ =0x02000040
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	ldr r2, _0201DCBC @ =0x0202F3FC
	mov r8, r2
	ldr r7, _0201DCC0 @ =0x0202F5FC
	mov ip, r7
	lsls r2, r0, #0x14
	movs r0, #0x80
	lsls r0, r0, #9
	mov sb, r0
_0201DBB8:
	lsrs r1, r2, #0x10
	lsls r1, r1, #1
	mov r7, r8
	adds r0, r1, r7
	ldrh r0, [r0]
	strh r0, [r5]
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r3]
	add r2, sb
	adds r4, #1
	adds r5, #2
	adds r3, #2
	cmp r4, #0xf
	ble _0201DBB8
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bls _0201DBEE
	movs r0, #0
	strb r0, [r1]
_0201DBEE:
	movs r0, #0x80
	lsls r0, r0, #0x12
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuSet
	ldr r2, _0201DCC4 @ =0x03001B50
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r3, _0201DCC8 @ =0x00000848
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, [r6]
	adds r1, #0x40
	str r1, [r6]
	ldr r7, _0201DCCC @ =0x00000842
	adds r0, r2, r7
	ldrh r0, [r0]
	adds r0, r0, r1
	asrs r0, r0, #8
	ldr r1, _0201DCD0 @ =0x0000084A
	adds r2, r2, r1
	strh r0, [r2]
	bl sub_020267D0
	bl sub_02021574
	movs r4, #0
_0201DC2E:
	adds r0, r6, r4
	ldr r2, _0201DCD4 @ =0x0000042C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DC40
	adds r0, r4, #0
	bl sub_02024DD0
_0201DC40:
	adds r4, #1
	cmp r4, #0x1d
	ble _0201DC2E
	movs r4, #0
_0201DC48:
	adds r0, r6, r4
	ldr r3, _0201DCD8 @ =0x0000044D
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DC5A
	adds r0, r4, #0
	bl sub_0201E538
_0201DC5A:
	adds r4, #1
	cmp r4, #0x1d
	ble _0201DC48
	ldr r7, _0201DCDC @ =0x00000419
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DC70
	movs r0, #2
	bl sub_020255F0
_0201DC70:
	movs r4, #3
_0201DC72:
	adds r0, r6, r4
	ldr r1, _0201DCE0 @ =0x0000041A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DC84
	adds r0, r4, #0
	bl sub_020255F0
_0201DC84:
	adds r4, #1
	cmp r4, #0xb
	ble _0201DC72
	movs r0, #1
	movs r1, #2
	bl sub_0201E038
	movs r0, #0x54
	bl sub_0201E230
_0201DC98:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201DCA4: .4byte 0x0400000E
_0201DCA8: .4byte 0x00000828
_0201DCAC: .4byte 0x03001B40
_0201DCB0: .4byte 0x0000193A
_0201DCB4: .4byte 0x00000497
_0201DCB8: .4byte 0x02000040
_0201DCBC: .4byte 0x0202F3FC
_0201DCC0: .4byte 0x0202F5FC
_0201DCC4: .4byte 0x03001B50
_0201DCC8: .4byte 0x00000848
_0201DCCC: .4byte 0x00000842
_0201DCD0: .4byte 0x0000084A
_0201DCD4: .4byte 0x0000042C
_0201DCD8: .4byte 0x0000044D
_0201DCDC: .4byte 0x00000419
_0201DCE0: .4byte 0x0000041A

	thumb_func_start sub_0201DCE4
sub_0201DCE4: @ 0x0201DCE4
	push {r4, lr}
	ldr r0, _0201DD14 @ =0x03003710
	ldr r1, _0201DD18 @ =0x0000049B
	adds r4, r0, r1
	ldrb r0, [r4]
	bl sub_0201D800
	ldrb r0, [r4]
	cmp r0, #2
	bne _0201DD0E
	bl sub_0201D7AC
	bl sub_020213DC
	ldr r0, _0201DD1C @ =0x03001B50
	ldr r1, _0201DD20 @ =0x00000857
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #3
	strb r0, [r4]
_0201DD0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201DD14: .4byte 0x03003710
_0201DD18: .4byte 0x0000049B
_0201DD1C: .4byte 0x03001B50
_0201DD20: .4byte 0x00000857

	thumb_func_start sub_0201DD24
sub_0201DD24: @ 0x0201DD24
	push {r4, lr}
	ldr r0, _0201DD54 @ =0x03003710
	ldr r1, _0201DD58 @ =0x0000049B
	adds r4, r0, r1
	ldrb r0, [r4]
	bl sub_0201D800
	ldrb r0, [r4]
	cmp r0, #2
	bne _0201DD4E
	bl sub_0201D7AC
	bl sub_020213DC
	ldr r0, _0201DD5C @ =0x03001B50
	ldr r1, _0201DD60 @ =0x0000084F
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #3
	strb r0, [r4]
_0201DD4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201DD54: .4byte 0x03003710
_0201DD58: .4byte 0x0000049B
_0201DD5C: .4byte 0x03001B50
_0201DD60: .4byte 0x0000084F

	thumb_func_start sub_0201DD64
sub_0201DD64: @ 0x0201DD64
	push {r4, lr}
	ldr r0, _0201DD8C @ =0x03003710
	ldr r1, _0201DD90 @ =0x0000049B
	adds r4, r0, r1
	ldrb r0, [r4]
	bl sub_0201D800
	ldrb r0, [r4]
	cmp r0, #2
	bne _0201DD84
	bl sub_0201D7AC
	bl sub_020213DC
	movs r0, #3
	strb r0, [r4]
_0201DD84:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201DD8C: .4byte 0x03003710
_0201DD90: .4byte 0x0000049B

	thumb_func_start sub_0201DD94
sub_0201DD94: @ 0x0201DD94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0201DE90 @ =0x030041A0
	mov sb, r0
	ldr r7, _0201DE94 @ =0x03003710
	ldr r0, _0201DE98 @ =0x03001B50
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0201DE9C @ =0x00000419
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DDC2
	movs r0, #2
	bl sub_020256D0
_0201DDC2:
	mov r0, sb
	adds r0, #0x87
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _0201DDDA
	mov r0, sb
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #2
	bne _0201DDDA
	bl sub_02023B58
_0201DDDA:
	movs r6, #0
	ldr r0, _0201DEA0 @ =0x00000417
	adds r4, r7, r0
_0201DDE0:
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DDEC
	bl sub_02026830
_0201DDEC:
	adds r6, #1
	cmp r6, #1
	ble _0201DDE0
	movs r6, #3
_0201DDF4:
	adds r0, r7, r6
	ldr r1, _0201DEA4 @ =0x0000041A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DE06
	adds r0, r6, #0
	bl sub_020256D0
_0201DE06:
	adds r6, #1
	cmp r6, #0xb
	ble _0201DDF4
	movs r0, #0x54
	bl sub_0201E27C
	movs r4, #0
	mov sl, r4
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r6, #0x1e
_0201DE20:
	adds r0, r7, r6
	ldr r4, _0201DEA8 @ =0x0000044D
	adds r0, r0, r4
	ldrb r0, [r0]
	subs r1, r6, #1
	mov r8, r1
	cmp r0, #1
	beq _0201DE32
	b _0201DF34
_0201DE32:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #4
	ldr r1, _0201DEAC @ =0x03003C00
	adds r5, r0, r1
	mov r4, sl
	cmp r4, #0
	bne _0201DE58
	ldr r0, _0201DEB0 @ =0x03003BB0
	ldrb r0, [r0, #0x10]
	ldrh r1, [r5, #0xe]
	cmp r0, r1
	bls _0201DE58
	movs r0, #0
	movs r1, #0
	bl sub_0201E178
	movs r4, #1
	mov sl, r4
_0201DE58:
	ldr r0, [sp]
	cmp r0, #0
	bne _0201DE74
	ldr r0, _0201DEB4 @ =0x03003BC4
	ldrb r0, [r0, #0x10]
	ldrh r1, [r5, #0xe]
	cmp r0, r1
	bls _0201DE74
	movs r0, #1
	movs r1, #2
	bl sub_0201E178
	movs r4, #1
	str r4, [sp]
_0201DE74:
	ldrh r1, [r5, #0x1c]
	subs r0, r6, #1
	mov r8, r0
	cmp r1, #0
	beq _0201DED6
	ldr r0, _0201DEB8 @ =0x0000FFFF
	cmp r1, r0
	beq _0201DEBC
	adds r0, r1, #0
	subs r0, #1
	bl sub_02024DF8
	b _0201DED6
	.align 2, 0
_0201DE90: .4byte 0x030041A0
_0201DE94: .4byte 0x03003710
_0201DE98: .4byte 0x03001B50
_0201DE9C: .4byte 0x00000419
_0201DEA0: .4byte 0x00000417
_0201DEA4: .4byte 0x0000041A
_0201DEA8: .4byte 0x0000044D
_0201DEAC: .4byte 0x03003C00
_0201DEB0: .4byte 0x03003BB0
_0201DEB4: .4byte 0x03003BC4
_0201DEB8: .4byte 0x0000FFFF
_0201DEBC:
	movs r4, #0
_0201DEBE:
	adds r0, r7, r4
	ldr r1, _0201DF94 @ =0x0000042C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DED0
	adds r0, r4, #0
	bl sub_02024DF8
_0201DED0:
	adds r4, #1
	cmp r4, #2
	ble _0201DEBE
_0201DED6:
	mov r4, sb
	ldr r0, [r4]
	asrs r0, r0, #8
	ldr r1, [r5]
	subs r2, r1, r0
	str r2, [r7, #8]
	ldr r3, [r4, #4]
	asrs r1, r3, #8
	ldr r0, [r5, #4]
	subs r0, r0, r1
	str r0, [r7, #0xc]
	cmp r2, #0
	bge _0201DEF4
	rsbs r0, r2, #0
	str r0, [r7, #8]
_0201DEF4:
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bge _0201DEFE
	rsbs r0, r0, #0
	str r0, [r7, #0xc]
_0201DEFE:
	ldr r0, [r7, #8]
	cmp r0, #0x10
	bgt _0201DF2E
	ldr r0, [r7, #0xc]
	cmp r0, #0x10
	bgt _0201DF2E
	ldrh r0, [r5, #0xe]
	movs r2, #0xf0
	adds r1, r2, #0
	ands r1, r0
	movs r4, #0xd0
	lsls r4, r4, #4
	adds r0, r3, r4
	asrs r0, r0, #8
	ands r0, r2
	cmp r1, r0
	bge _0201DF2E
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0201DF2E
	bl sub_02023B58
	movs r1, #1
	str r1, [sp, #4]
_0201DF2E:
	adds r0, r6, #0
	bl sub_0201EF44
_0201DF34:
	mov r6, r8
	cmp r6, #0
	blt _0201DF3C
	b _0201DE20
_0201DF3C:
	mov r4, sl
	cmp r4, #0
	bne _0201DF4A
	movs r0, #0
	movs r1, #0
	bl sub_0201E178
_0201DF4A:
	ldr r0, [sp]
	cmp r0, #0
	bne _0201DF58
	movs r0, #1
	movs r1, #2
	bl sub_0201E178
_0201DF58:
	ldr r1, [sp, #4]
	cmp r1, #0
	bne _0201DF62
	bl sub_02023B58
_0201DF62:
	movs r0, #1
	movs r1, #1
	bl sub_0201E178
	movs r6, #0
_0201DF6C:
	adds r0, r7, r6
	ldr r4, _0201DF98 @ =0x0000041A
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0201DF7E
	adds r0, r6, #0
	bl sub_02025618
_0201DF7E:
	adds r6, #1
	cmp r6, #0xb
	ble _0201DF6C
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201DF94: .4byte 0x0000042C
_0201DF98: .4byte 0x0000041A

	thumb_func_start sub_0201DF9C
sub_0201DF9C: @ 0x0201DF9C
	push {r4, r5, lr}
	adds r4, r2, #0
	lsls r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _0201DFCC @ =0x03003BB0
	adds r2, r2, r0
	ldr r3, _0201DFD0 @ =0x030041A0
	cmp r1, #0
	bne _0201DFD8
	ldr r0, _0201DFD4 @ =0x0000FFF0
	ands r0, r4
	adds r0, #0x10
	str r0, [r2, #4]
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #4
	adds r0, #0x10
	str r0, [r2]
	b _0201E024
	.align 2, 0
_0201DFCC: .4byte 0x03003BB0
_0201DFD0: .4byte 0x030041A0
_0201DFD4: .4byte 0x0000FFF0
_0201DFD8:
	ldr r0, _0201DFF0 @ =0x0000FFF0
	ands r0, r4
	adds r0, #8
	str r0, [r2, #4]
	cmp r5, #0
	bne _0201DFF4
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #4
	adds r0, #8
	b _0201E000
	.align 2, 0
_0201DFF0: .4byte 0x0000FFF0
_0201DFF4:
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #4
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r0, r1
_0201E000:
	str r0, [r2]
	ldr r1, [r2]
	lsls r1, r1, #8
	str r1, [r3]
	ldr r0, [r2, #4]
	lsls r0, r0, #8
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
	str r0, [r3, #4]
	str r1, [r3, #8]
	str r0, [r3, #0xc]
	ldr r0, [r2]
	subs r0, #8
	str r0, [r2, #8]
	ldr r0, [r2, #4]
	subs r0, #4
	str r0, [r2, #0xc]
_0201E024:
	strb r4, [r2, #0x10]
	movs r0, #1
	strb r0, [r2, #0x11]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0201E030
sub_0201E030: @ 0x0201E030
	bx lr
	.align 2, 0

	thumb_func_start sub_0201E034
sub_0201E034: @ 0x0201E034
	bx lr
	.align 2, 0

	thumb_func_start sub_0201E038
sub_0201E038: @ 0x0201E038
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0201E058 @ =0x03003BC4
	cmp r1, #2
	bne _0201E052
	ldr r0, _0201E05C @ =0x0202FD38
	ldrb r1, [r2, #0x11]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0201E052:
	pop {r0}
	bx r0
	.align 2, 0
_0201E058: .4byte 0x03003BC4
_0201E05C: .4byte 0x0202FD38

	thumb_func_start sub_0201E060
sub_0201E060: @ 0x0201E060
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0201E154 @ =0x03003BB0
	adds r0, r0, r1
	mov ip, r0
	ldr r3, _0201E158 @ =0x03001B50
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0201E15C @ =0x03002410
	adds r6, r0, r1
	mov r8, r3
	cmp r2, #5
	bne _0201E096
	mov r2, ip
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _0201E13C
_0201E096:
	ldr r0, [r7]
	lsrs r0, r0, #0xe
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	ldrb r1, [r6, #1]
	movs r2, #0x3f
	adds r4, r2, #0
	ands r4, r1
	orrs r4, r0
	strb r4, [r6, #1]
	ldr r0, [r7]
	movs r3, #0xf
	lsrs r0, r0, #0x1e
	lsls r0, r0, #6
	ldrb r1, [r6, #3]
	ands r2, r1
	orrs r2, r0
	strb r2, [r6, #3]
	ldrb r1, [r7, #0xf]
	movs r5, #1
	ands r1, r5
	lsls r1, r1, #4
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #3]
	ldrb r1, [r7, #0x10]
	ands r1, r5
	lsls r1, r1, #5
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #3]
	ldrb r0, [r7, #0xe]
	lsls r0, r0, #4
	ldrb r1, [r6, #5]
	ands r3, r1
	orrs r3, r0
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r3, r0
	movs r0, #4
	orrs r3, r0
	strb r3, [r6, #5]
	ldr r0, _0201E160 @ =0x00000844
	add r0, r8
	ldrh r1, [r0]
	mov r2, ip
	ldr r0, [r2]
	subs r0, r0, r1
	ldr r1, [r7, #8]
	adds r1, r1, r0
	ldr r2, _0201E164 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r6, #2]
	ldr r0, _0201E168 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #2]
	ldr r2, [r7, #4]
	mov r1, ip
	ldr r0, [r1, #4]
	ldr r1, _0201E16C @ =0x00000846
	add r1, r8
	ldrb r1, [r1]
	subs r0, r0, r1
	adds r2, r2, r0
	strb r2, [r6]
	ldrh r0, [r7, #0xc]
	ldr r1, _0201E170 @ =0x000003FF
	ands r1, r0
	ldrh r2, [r6, #4]
	ldr r0, _0201E174 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #4]
	movs r0, #0x10
	orrs r4, r0
	strb r4, [r6, #1]
_0201E13C:
	movs r1, #0x86
	lsls r1, r1, #4
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201E154: .4byte 0x03003BB0
_0201E158: .4byte 0x03001B50
_0201E15C: .4byte 0x03002410
_0201E160: .4byte 0x00000844
_0201E164: .4byte 0x000001FF
_0201E168: .4byte 0xFFFFFE00
_0201E16C: .4byte 0x00000846
_0201E170: .4byte 0x000003FF
_0201E174: .4byte 0xFFFFFC00

	thumb_func_start sub_0201E178
sub_0201E178: @ 0x0201E178
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r3, r1, #0
	movs r0, #0
	movs r6, #0
	cmp r1, #1
	beq _0201E1AA
	cmp r1, #1
	bgt _0201E198
	cmp r1, #0
	beq _0201E19E
	b _0201E1AE
_0201E198:
	cmp r3, #2
	beq _0201E1A4
	b _0201E1AE
_0201E19E:
	movs r0, #0
	movs r6, #3
	b _0201E1AE
_0201E1A4:
	movs r0, #3
	movs r6, #5
	b _0201E1AE
_0201E1AA:
	movs r0, #5
	movs r6, #6
_0201E1AE:
	adds r4, r0, #0
	cmp r4, r6
	bge _0201E1D0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r5, r0, #2
	ldr r7, _0201E1DC @ =0x0202FD40
_0201E1BC:
	adds r0, r5, r7
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	mov r1, r8
	bl sub_0201E060
	adds r5, #0x14
	adds r4, #1
	cmp r4, r6
	blt _0201E1BC
_0201E1D0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201E1DC: .4byte 0x0202FD40

	thumb_func_start sub_0201E1E0
sub_0201E1E0: @ 0x0201E1E0
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0201E228 @ =0x03003BF0
	adds r3, r1, r0
	movs r4, #0
	str r4, [r3]
	cmp r2, #0
	beq _0201E1FE
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3]
_0201E1FE:
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #4
	adds r0, #0xc
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	movs r0, #0xf0
	ands r0, r5
	adds r0, #8
	str r0, [r3, #4]
	strb r4, [r3, #8]
	strb r4, [r3, #9]
	ldr r0, _0201E22C @ =0x0202FEB0
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r3, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0201E228: .4byte 0x03003BF0
_0201E22C: .4byte 0x0202FEB0

	thumb_func_start sub_0201E230
sub_0201E230: @ 0x0201E230
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0201E274 @ =0x03003BF0
	adds r1, r1, r0
	ldrb r0, [r1, #8]
	subs r0, #1
	strb r0, [r1, #8]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0201E26E
	ldrb r0, [r1, #9]
	adds r0, #1
	strb r0, [r1, #9]
	ldr r3, _0201E278 @ =0x0202FEB0
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	cmp r0, #0xff
	bne _0201E262
	strb r2, [r1, #9]
_0201E262:
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r1, #8]
_0201E26E:
	pop {r0}
	bx r0
	.align 2, 0
_0201E274: .4byte 0x03003BF0
_0201E278: .4byte 0x0202FEB0

	thumb_func_start sub_0201E27C
sub_0201E27C: @ 0x0201E27C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0201E3B4 @ =0x03003BF0
	adds r6, r1, r0
	ldr r1, _0201E3B8 @ =0x0202FEB0
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r5, [r0]
	ldrh r0, [r5, #6]
	ldr r1, _0201E3BC @ =0x0000FFFF
	cmp r0, r1
	bne _0201E2A6
	b _0201E3A6
_0201E2A6:
	ldr r2, _0201E3C0 @ =0x03001B50
	mov r8, r2
	movs r0, #0x86
	lsls r0, r0, #4
	add r0, r8
	mov ip, r0
	movs r7, #1
	movs r1, #0x21
	rsbs r1, r1, #0
	mov sl, r1
	movs r2, #0x3f
	mov sb, r2
_0201E2BE:
	mov r0, ip
	ldrb r3, [r0]
	lsls r3, r3, #3
	ldr r1, _0201E3C4 @ =0x03002410
	adds r3, r3, r1
	ldr r0, [r6, #4]
	ldrb r1, [r5]
	adds r1, r1, r0
	ldr r0, _0201E3C8 @ =0x00000846
	add r0, r8
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r3]
	ldrb r1, [r5, #1]
	movs r0, #0xc
	ands r0, r1
	ldrb r1, [r3, #1]
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3, #1]
	ldrb r0, [r5, #1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r7
	lsls r0, r0, #5
	mov r1, sl
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #1]
	ldrb r0, [r5, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r4, sb
	ands r4, r1
	orrs r4, r0
	strb r4, [r3, #1]
	ldrb r0, [r5, #3]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1f
	ands r0, r7
	lsls r0, r0, #4
	ldrb r1, [r3, #3]
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3, #3]
	ldrb r0, [r5, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r7
	lsls r0, r0, #5
	mov r1, sl
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	ldrb r0, [r5, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sb
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	ldrh r1, [r5, #2]
	lsls r1, r1, #0x17
	lsrs r1, r1, #0x17
	ldr r0, [r6]
	adds r1, r1, r0
	ldr r0, _0201E3CC @ =0x00000844
	add r0, r8
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r2, _0201E3D0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0201E3D4 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r3, #4]
	ldr r0, _0201E3D8 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	movs r0, #0x10
	orrs r4, r0
	strb r4, [r3, #1]
	ldrb r1, [r3, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r3, #5]
	ldrb r2, [r5, #5]
	lsrs r2, r2, #4
	lsls r2, r2, #4
	movs r1, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #5]
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r5, #8
	ldrh r0, [r5, #6]
	ldr r2, _0201E3BC @ =0x0000FFFF
	cmp r0, r2
	bne _0201E2BE
_0201E3A6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201E3B4: .4byte 0x03003BF0
_0201E3B8: .4byte 0x0202FEB0
_0201E3BC: .4byte 0x0000FFFF
_0201E3C0: .4byte 0x03001B50
_0201E3C4: .4byte 0x03002410
_0201E3C8: .4byte 0x00000846
_0201E3CC: .4byte 0x00000844
_0201E3D0: .4byte 0x000001FF
_0201E3D4: .4byte 0xFFFFFE00
_0201E3D8: .4byte 0xFFFFFC00

	thumb_func_start sub_0201E3DC
sub_0201E3DC: @ 0x0201E3DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #4
	ldr r2, _0201E418 @ =0x03003C00
	adds r5, r0, r2
	ldr r3, _0201E41C @ =0x03003710
	movs r4, #3
	lsls r2, r1, #0x18
_0201E3F0:
	adds r0, r3, r4
	ldr r7, _0201E420 @ =0x0000042F
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0
	bne _0201E424
	movs r0, #1
	strb r0, [r1]
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r3, [r0]
	adds r0, r6, #0
	lsrs r2, r2, #0x18
	bl sub_02024B08
	adds r0, r4, #1
	strh r0, [r5, #0x1c]
	b _0201E42A
	.align 2, 0
_0201E418: .4byte 0x03003C00
_0201E41C: .4byte 0x03003710
_0201E420: .4byte 0x0000042F
_0201E424:
	adds r4, #1
	cmp r4, #0x1d
	ble _0201E3F0
_0201E42A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0201E430
sub_0201E430: @ 0x0201E430
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r7, r3, #0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #4
	ldr r3, _0201E530 @ =0x03003C00
	adds r5, r0, r3
	movs r4, #0
	movs r3, #0
	strh r1, [r5, #0xc]
	adds r0, r5, #0
	adds r0, #0x29
	strb r4, [r0]
	strh r3, [r5, #0x10]
	strh r3, [r5, #0x16]
	strh r3, [r5, #0x18]
	strh r3, [r5, #0x1a]
	subs r0, #1
	strb r4, [r0]
	subs r0, #2
	strb r4, [r0]
	subs r0, #1
	strb r4, [r0]
	adds r0, #2
	strb r4, [r0]
	movs r0, #0x2a
	adds r0, r0, r5
	mov ip, r0
	strb r4, [r0]
	strh r3, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x2b
	strb r4, [r0]
	strh r3, [r5, #0x1e]
	strh r3, [r5, #0x20]
	strh r3, [r5, #0x22]
	adds r0, #1
	strb r4, [r0]
	movs r1, #0x2d
	adds r1, r1, r5
	mov r8, r1
	strb r4, [r1]
	movs r0, #0xf0
	ands r0, r2
	adds r0, #8
	str r0, [r5, #4]
	movs r0, #0xf
	ands r0, r2
	lsls r1, r0, #4
	adds r0, r1, #0
	adds r0, #8
	str r0, [r5]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r5, #0xe]
	cmp r7, #0
	beq _0201E4B4
	movs r0, #0x84
	lsls r0, r0, #1
	adds r0, r1, r0
	str r0, [r5]
_0201E4B4:
	ldr r1, _0201E534 @ =0x02030110
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x24
	strb r7, [r0]
	ldrh r0, [r5, #0xc]
	cmp r0, #0x12
	bne _0201E4D4
	adds r0, r6, #0
	movs r1, #0
	bl sub_0201E3DC
_0201E4D4:
	ldrh r0, [r5, #0xc]
	cmp r0, #7
	bne _0201E4E2
	adds r0, r6, #0
	movs r1, #3
	bl sub_0201E3DC
_0201E4E2:
	ldrh r0, [r5, #0xc]
	cmp r0, #8
	bne _0201E4F0
	adds r0, r6, #0
	movs r1, #7
	bl sub_0201E3DC
_0201E4F0:
	ldrh r0, [r5, #0xc]
	cmp r0, #9
	bne _0201E4FE
	adds r0, r6, #0
	movs r1, #0xb
	bl sub_0201E3DC
_0201E4FE:
	ldrh r0, [r5, #0xc]
	cmp r0, #0xa
	bne _0201E50C
	adds r0, r6, #0
	movs r1, #0xf
	bl sub_0201E3DC
_0201E50C:
	ldrh r0, [r5, #0xc]
	cmp r0, #0xb
	bne _0201E51A
	adds r0, r6, #0
	movs r1, #0x13
	bl sub_0201E3DC
_0201E51A:
	ldrh r0, [r5, #0xc]
	cmp r0, #6
	bne _0201E526
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_0201E526:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201E530: .4byte 0x03003C00
_0201E534: .4byte 0x02030110

	thumb_func_start sub_0201E538
sub_0201E538: @ 0x0201E538
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r2, _0201E558 @ =0x03003C00
	adds r1, r1, r2
	ldr r2, _0201E55C @ =0x0202FECC
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0201E558: .4byte 0x03003C00
_0201E55C: .4byte 0x0202FECC

	thumb_func_start sub_0201E560
sub_0201E560: @ 0x0201E560
	bx lr
	.align 2, 0

	thumb_func_start sub_0201E564
sub_0201E564: @ 0x0201E564
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0201E5E4 @ =0x03003C00
	adds r6, r1, r0
	ldr r1, _0201E5E8 @ =0x03003710
	ldrh r0, [r6, #0xc]
	cmp r0, #3
	beq _0201E5FE
	cmp r0, #0xe
	beq _0201E5FE
	movs r3, #3
	ldr r0, _0201E5EC @ =0x03001B50
	mov r8, r0
_0201E586:
	adds r0, r1, r3
	ldr r4, _0201E5F0 @ =0x0000041A
	adds r2, r0, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _0201E5F8
	movs r0, #0x54
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, _0201E5F4 @ =0x03004790
	adds r4, r1, r0
	movs r7, #1
	strb r7, [r2]
	adds r0, r3, #0
	bl sub_02024F08
	mov r0, r8
	bl sub_02019AF0
	movs r1, #0x21
	bl __modsi3
	movs r1, #0x10
	subs r5, r1, r0
	mov r0, r8
	bl sub_02019AF0
	movs r1, #0x11
	bl __modsi3
	adds r1, r0, #0
	adds r1, #0x10
	ldrh r0, [r6, #0xc]
	cmp r0, #4
	bne _0201E5CE
	movs r1, #0x10
_0201E5CE:
	ldr r0, [r6]
	adds r0, r0, r5
	str r0, [r4]
	ldr r0, [r6, #4]
	subs r0, r0, r1
	str r0, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x4e
	strb r7, [r0]
	b _0201E5FE
	.align 2, 0
_0201E5E4: .4byte 0x03003C00
_0201E5E8: .4byte 0x03003710
_0201E5EC: .4byte 0x03001B50
_0201E5F0: .4byte 0x0000041A
_0201E5F4: .4byte 0x03004790
_0201E5F8:
	adds r3, #1
	cmp r3, #9
	ble _0201E586
_0201E5FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0201E608
sub_0201E608: @ 0x0201E608
	push {r4, lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0201E654 @ =0x03003C00
	adds r3, r1, r0
	movs r4, #0
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #3
	bne _0201E658
	ldrh r0, [r3, #0xc]
	cmp r0, #3
	bne _0201E628
	movs r4, #1
_0201E628:
	cmp r0, #4
	bne _0201E62E
	movs r4, #2
_0201E62E:
	cmp r0, #5
	bne _0201E634
	movs r4, #3
_0201E634:
	cmp r0, #6
	bne _0201E63A
	movs r4, #4
_0201E63A:
	cmp r0, #0xe
	bne _0201E640
	movs r4, #0x70
_0201E640:
	cmp r0, #0xf
	bne _0201E646
	movs r4, #0x71
_0201E646:
	cmp r0, #0x10
	bne _0201E64C
	movs r4, #0x72
_0201E64C:
	cmp r0, #0x11
	bne _0201E6A0
	movs r4, #0x73
	b _0201E6A0
	.align 2, 0
_0201E654: .4byte 0x03003C00
_0201E658:
	ldrh r0, [r3, #0xc]
	cmp r0, #0x12
	bne _0201E664
	ldr r4, _0201E6C8 @ =0x00000858
	movs r0, #0x11
	strh r0, [r3, #0xc]
_0201E664:
	ldrh r0, [r3, #0xc]
	cmp r0, #7
	bne _0201E670
	ldr r4, _0201E6CC @ =0x00000809
	movs r0, #6
	strh r0, [r3, #0xc]
_0201E670:
	ldrh r0, [r3, #0xc]
	cmp r0, #8
	bne _0201E67C
	ldr r4, _0201E6D0 @ =0x00000811
	movs r0, #6
	strh r0, [r3, #0xc]
_0201E67C:
	ldrh r0, [r3, #0xc]
	cmp r0, #9
	bne _0201E688
	ldr r4, _0201E6D4 @ =0x00000819
	movs r0, #6
	strh r0, [r3, #0xc]
_0201E688:
	ldrh r0, [r3, #0xc]
	cmp r0, #0xa
	bne _0201E694
	ldr r4, _0201E6D8 @ =0x00000821
	movs r0, #6
	strh r0, [r3, #0xc]
_0201E694:
	ldrh r0, [r3, #0xc]
	cmp r0, #0xb
	bne _0201E6A0
	ldr r4, _0201E6DC @ =0x00000829
	movs r0, #6
	strh r0, [r3, #0xc]
_0201E6A0:
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0201E6E4
	ldr r0, _0201E6E0 @ =0x03001B40
	ldr r2, [r0]
	ldrh r0, [r3, #0xe]
	movs r3, #0xf
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #1
	lsrs r0, r0, #4
	ands r0, r3
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r2, #0x24
	b _0201E700
	.align 2, 0
_0201E6C8: .4byte 0x00000858
_0201E6CC: .4byte 0x00000809
_0201E6D0: .4byte 0x00000811
_0201E6D4: .4byte 0x00000819
_0201E6D8: .4byte 0x00000821
_0201E6DC: .4byte 0x00000829
_0201E6E0: .4byte 0x03001B40
_0201E6E4:
	ldr r0, _0201E70C @ =0x03001B40
	ldr r2, [r0]
	ldrh r0, [r3, #0xe]
	movs r3, #0xf
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #1
	lsrs r0, r0, #4
	ands r0, r3
	lsls r0, r0, #5
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r2, r2, r0
_0201E700:
	adds r2, r2, r1
	strh r4, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201E70C: .4byte 0x03001B40

	thumb_func_start sub_0201E710
sub_0201E710: @ 0x0201E710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov sb, r0
	lsls r0, r0, #1
	add r0, sb
	lsls r0, r0, #4
	ldr r1, _0201E770 @ =0x03003C00
	adds r5, r0, r1
	ldr r0, _0201E774 @ =0x03003710
	str r0, [sp]
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	cmp r1, #0
	beq _0201E740
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0201E77C
_0201E740:
	mov r0, sb
	bl sub_0201E564
	adds r1, r5, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x26
	strb r6, [r0]
	ldr r0, _0201E778 @ =0x0000FFFF
	strh r0, [r5, #0x14]
	adds r4, r5, #0
	adds r4, #0x28
	movs r0, #3
	strb r0, [r4]
	mov r0, sb
	bl sub_0201E608
	movs r0, #0x13
	bl sub_02026A38
	str r4, [sp, #0x1c]
	b _0201E798
	.align 2, 0
_0201E770: .4byte 0x03003C00
_0201E774: .4byte 0x03003710
_0201E778: .4byte 0x0000FFFF
_0201E77C:
	movs r0, #0x18
	bl sub_02026A38
	adds r0, r5, #0
	adds r0, #0x27
	movs r1, #2
	strb r1, [r0]
	subs r0, #1
	strb r6, [r0]
	subs r0, #1
	strb r6, [r0]
	adds r0, #3
	strb r1, [r0]
	str r0, [sp, #0x1c]
_0201E798:
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _0201E7A0
	b _0201EB2E
_0201E7A0:
	adds r0, r5, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	beq _0201E7AE
	b _0201EB2E
_0201E7AE:
	movs r1, #0
	mov sl, r1
	ldr r3, _0201E8E4 @ =0x00000417
	ldr r2, [sp]
	adds r3, r2, r3
	str r3, [sp, #8]
	movs r4, #0
	str r4, [sp, #0x24]
	ldr r6, _0201E8E8 @ =0x0000042C
	adds r6, r2, r6
	str r6, [sp, #0x28]
_0201E7C4:
	ldr r7, [sp, #0x28]
	ldrb r0, [r7]
	cmp r0, #1
	bne _0201E7D4
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq _0201E7D4
	b _0201EAF4
_0201E7D4:
	movs r0, #0
	str r0, [sp, #4]
	mov r1, sl
	lsls r1, r1, #2
	str r1, [sp, #0x14]
	adds r2, r5, #0
	adds r2, #0x24
	str r2, [sp, #0x18]
	ldrh r4, [r5, #0xe]
	mov r3, sp
	strh r4, [r3, #0xc]
	str r2, [sp, #0x10]
_0201E7EC:
	ldr r6, [sp, #0x14]
	ldr r7, [sp, #4]
	adds r2, r6, r7
	ldr r1, _0201E8EC @ =0x02030104
	adds r0, r2, r1
	ldrb r6, [r0]
	lsls r0, r6, #4
	mov r4, sp
	ldrh r4, [r4, #0xc]
	adds r3, r4, r0
	movs r0, #0xf0
	ands r3, r0
	adds r7, r3, #0
	strh r3, [r5, #0x20]
	ldr r6, _0201E8F0 @ =0x020300F8
	adds r2, r2, r6
	movs r1, #0xf
	adds r0, r1, #0
	mov r4, sp
	ldrh r4, [r4, #0xc]
	ands r0, r4
	ldrb r2, [r2]
	adds r2, r0, r2
	ands r2, r1
	adds r6, r2, #0
	strh r2, [r5, #0x1e]
	movs r0, #0
	mov r8, r0
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0201E884
	ldr r4, _0201E8F4 @ =0x03001B40
	ldr r4, [r4]
	mov ip, r4
	ldrh r1, [r5, #0x1e]
	lsls r1, r1, #1
	lsls r4, r3, #1
	adds r1, r1, r4
	mov r0, ip
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5, #0x22]
	adds r0, r6, #0
	orrs r0, r7
	lsls r3, r0, #1
	ldr r0, [sp]
	adds r0, #0x10
	adds r0, r0, r3
	ldrh r7, [r0]
	ldrh r1, [r5, #0x1e]
	cmp r2, #1
	bhi _0201E878
	movs r6, #1
	mov r8, r6
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r0, #0x89
	lsls r0, r0, #2
	add r0, ip
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5, #0x22]
	ldr r7, [sp]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r3
	ldrh r7, [r0]
_0201E878:
	ldr r2, [sp, #0x10]
	ldrb r0, [r2]
	ldrh r2, [r5, #0x1e]
	ldrh r3, [r5, #0x20]
	cmp r0, #0
	beq _0201E8DA
_0201E884:
	movs r3, #1
	mov r8, r3
	ldr r4, _0201E8F4 @ =0x03001B40
	ldr r4, [r4]
	mov ip, r4
	ldrh r2, [r5, #0x1e]
	movs r1, #0xf
	ands r1, r2
	lsls r1, r1, #1
	ldrh r3, [r5, #0x20]
	lsrs r0, r3, #4
	lsls r0, r0, #5
	adds r4, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	add r0, ip
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r5, #0x22]
	adds r0, r3, r2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x17
	ldr r6, [sp]
	movs r7, #0x84
	lsls r7, r7, #2
	adds r0, r6, r7
	adds r0, r0, r1
	ldrh r7, [r0]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bls _0201E8DA
	movs r0, #0
	mov r8, r0
	mov r0, ip
	adds r0, #0x24
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r5, #0x22]
	adds r0, r6, #0
	adds r0, #0x10
	adds r0, r0, r1
	ldrh r7, [r0]
_0201E8DA:
	mov r1, r8
	cmp r1, #0
	bne _0201E8FC
	ldr r0, _0201E8F8 @ =0x0600A000
	b _0201E8FE
	.align 2, 0
_0201E8E4: .4byte 0x00000417
_0201E8E8: .4byte 0x0000042C
_0201E8EC: .4byte 0x02030104
_0201E8F0: .4byte 0x020300F8
_0201E8F4: .4byte 0x03001B40
_0201E8F8: .4byte 0x0600A000
_0201E8FC:
	ldr r0, _0201E9F8 @ =0x0600A800
_0201E8FE:
	str r0, [r5, #8]
	adds r1, r3, r2
	movs r2, #0xf0
	adds r0, r1, #0
	ands r0, r2
	lsls r0, r0, #3
	ldr r2, [r5, #8]
	adds r2, r2, r0
	movs r0, #0xf
	ands r1, r0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [r5, #8]
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	bne _0201E936
	ldr r0, _0201E9FC @ =0x00000FFF
	cmp r7, r0
	bne _0201E936
	ldrh r0, [r1]
	ldr r2, _0201EA00 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5e
	bls _0201E93E
_0201E936:
	ldr r3, [sp, #4]
	cmp r3, #3
	beq _0201E93E
	b _0201EA68
_0201E93E:
	movs r0, #1
	ldr r4, [sp, #0x28]
	strb r0, [r4]
	ldrh r0, [r5, #0xc]
	cmp r0, #0x12
	bne _0201E95E
	mov r2, sl
	adds r2, #1
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r6, [sp, #0x24]
	lsrs r1, r6, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E95E:
	ldrh r0, [r5, #0xc]
	cmp r0, #7
	bne _0201E978
	mov r2, sl
	adds r2, #4
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r3, [sp, #0x24]
	lsrs r1, r3, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E978:
	ldrh r0, [r5, #0xc]
	cmp r0, #8
	bne _0201E992
	mov r2, sl
	adds r2, #8
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r4, [sp, #0x24]
	lsrs r1, r4, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E992:
	ldrh r0, [r5, #0xc]
	cmp r0, #9
	bne _0201E9AC
	mov r2, sl
	adds r2, #0xc
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r6, [sp, #0x24]
	lsrs r1, r6, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E9AC:
	ldrh r0, [r5, #0xc]
	cmp r0, #0xa
	bne _0201E9C6
	mov r2, sl
	adds r2, #0x10
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r3, [sp, #0x24]
	lsrs r1, r3, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E9C6:
	ldrh r0, [r5, #0xc]
	cmp r0, #0xb
	bne _0201E9E0
	mov r2, sl
	adds r2, #0x14
	lsls r2, r2, #0x18
	mov r0, sb
	ldr r4, [sp, #0x24]
	lsrs r1, r4, #0x10
	lsrs r2, r2, #0x18
	mov r3, r8
	bl sub_02024B08
_0201E9E0:
	mov r6, r8
	cmp r6, #0
	bne _0201EA04
	ldrh r0, [r5, #0x20]
	ldrb r1, [r5, #0x1e]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldr r1, [sp]
	adds r1, #0x10
	b _0201EA16
	.align 2, 0
_0201E9F8: .4byte 0x0600A800
_0201E9FC: .4byte 0x00000FFF
_0201EA00: .4byte 0x000003FF
_0201EA04:
	ldrh r0, [r5, #0x20]
	ldrb r2, [r5, #0x1e]
	adds r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldr r3, [sp]
	movs r4, #0x84
	lsls r4, r4, #2
	adds r1, r3, r4
_0201EA16:
	adds r1, r1, r0
	ldr r0, _0201EA5C @ =0x00007777
	strh r0, [r1]
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, _0201EA60 @ =0x03004260
	adds r1, r1, r0
	ldrh r0, [r5, #0x1e]
	lsls r2, r0, #4
	str r2, [r1, #0x10]
	mov r6, r8
	cmp r6, #0
	beq _0201EA3A
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r2, r0
	str r2, [r1, #0x10]
_0201EA3A:
	ldrh r0, [r5, #0x20]
	str r0, [r1, #0xc]
	ldrh r0, [r5, #0x1e]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	bne _0201EA74
	ldr r0, _0201EA64 @ =0x00000FFF
	cmp r7, r0
	bne _0201EA74
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	b _0201EA74
	.align 2, 0
_0201EA5C: .4byte 0x00007777
_0201EA60: .4byte 0x03004260
_0201EA64: .4byte 0x00000FFF
_0201EA68:
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
	cmp r3, #3
	bgt _0201EA74
	b _0201E7EC
_0201EA74:
	ldrh r0, [r5, #0xc]
	cmp r0, #0x12
	bne _0201EA80
	mov r4, sl
	cmp r4, #1
	beq _0201EA9C
_0201EA80:
	ldr r6, [sp, #0x24]
	movs r7, #0x80
	lsls r7, r7, #9
	adds r6, r6, r7
	str r6, [sp, #0x24]
	ldr r0, [sp, #0x28]
	adds r0, #1
	str r0, [sp, #0x28]
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #2
	bgt _0201EA9C
	b _0201E7C4
_0201EA9C:
	mov r0, sb
	bl sub_0201E608
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
	cmp r0, #3
	bne _0201EB16
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0201EADC
	ldrh r0, [r5, #0xc]
	cmp r0, #0x12
	bne _0201EAC6
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r1, #0x10
	adds r1, r1, r0
	movs r0, #0x25
	b _0201EAD2
_0201EAC6:
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r1, #0x10
	adds r1, r1, r0
	movs r0, #0x34
_0201EAD2:
	strh r0, [r1]
	ldr r6, [sp, #0x18]
	ldrb r0, [r6]
	cmp r0, #0
	beq _0201EB16
_0201EADC:
	ldrh r0, [r5, #0xc]
	cmp r0, #0x12
	bne _0201EB04
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #1
	ldr r7, [sp]
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r1, r1, r0
	movs r0, #0x25
	b _0201EB14
_0201EAF4:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x17
	ldr r3, [sp, #8]
	adds r0, r3, r0
	movs r1, #0
	strb r1, [r0]
	strh r1, [r5, #0x1c]
	b _0201EB2E
_0201EB04:
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #1
	ldr r4, [sp]
	movs r6, #0x84
	lsls r6, r6, #2
	adds r1, r4, r6
	adds r1, r1, r0
	movs r0, #0x34
_0201EB14:
	strh r0, [r1]
_0201EB16:
	movs r1, #0
	movs r0, #1
	ldr r7, [sp, #0x20]
	strb r0, [r7]
	ldrh r0, [r5, #0x1c]
	ldr r2, [sp]
	adds r0, r2, r0
	ldr r3, _0201EB40 @ =0x0000042E
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, _0201EB44 @ =0x0000FFFF
	strh r0, [r5, #0x1c]
_0201EB2E:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201EB40: .4byte 0x0000042E
_0201EB44: .4byte 0x0000FFFF

	thumb_func_start sub_0201EB48
sub_0201EB48: @ 0x0201EB48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0201EC14 @ =0x03003C00
	adds r6, r1, r0
	ldr r0, _0201EC18 @ =0x03003710
	mov sb, r0
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201EB98
	adds r1, r6, #0
	adds r1, #0x27
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0201EB98
	movs r0, #2
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x26
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _0201EC1C @ =0x02030123
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x25
	strb r0, [r1]
_0201EB98:
	adds r2, r6, #0
	adds r2, #0x26
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	str r2, [sp]
	movs r1, #0x25
	adds r1, r1, r6
	mov sl, r1
	cmp r0, #0
	beq _0201EC38
	ldrh r0, [r6, #0xc]
	cmp r0, #3
	beq _0201EC38
	cmp r0, #0xe
	beq _0201EC38
	movs r0, #0
	ldr r3, _0201EC20 @ =0x03001B50
	mov r8, r3
_0201EBBE:
	movs r2, #3
	adds r7, r0, #1
_0201EBC2:
	mov r1, sb
	adds r0, r1, r2
	ldr r3, _0201EC24 @ =0x0000041A
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0
	bne _0201EC2C
	movs r0, #0x54
	adds r5, r2, #0
	muls r5, r0, r5
	ldr r0, _0201EC28 @ =0x03004790
	adds r5, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl sub_02024F08
	mov r0, r8
	bl sub_02019AF0
	ldr r4, [r6]
	adds r4, #0x10
	movs r1, #0x21
	bl __modsi3
	subs r4, r4, r0
	str r4, [r5]
	mov r0, r8
	bl sub_02019AF0
	ldr r4, [r6, #4]
	subs r4, #0x10
	movs r1, #0x11
	bl __modsi3
	subs r4, r4, r0
	str r4, [r5, #4]
	adds r5, #0x4e
	movs r0, #3
	strb r0, [r5]
	b _0201EC32
	.align 2, 0
_0201EC14: .4byte 0x03003C00
_0201EC18: .4byte 0x03003710
_0201EC1C: .4byte 0x02030123
_0201EC20: .4byte 0x03001B50
_0201EC24: .4byte 0x0000041A
_0201EC28: .4byte 0x03004790
_0201EC2C:
	adds r2, #1
	cmp r2, #9
	ble _0201EBC2
_0201EC32:
	adds r0, r7, #0
	cmp r0, #2
	ble _0201EBBE
_0201EC38:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #2
	bls _0201EC5A
	adds r1, r6, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	ldr r3, [sp]
	strb r0, [r3]
	mov r1, sl
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	subs r1, #4
	strb r0, [r1]
_0201EC5A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201EC6C
sub_0201EC6C: @ 0x0201EC6C
	push {r4, r5, lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0201EC98 @ =0x03003C00
	adds r2, r1, r0
	adds r1, r2, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0
	beq _0201EC9C
	subs r0, #1
	strb r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0201ED48
	ldrh r0, [r2, #0x16]
	adds r0, #1
	strh r0, [r2, #0x16]
	b _0201ED48
	.align 2, 0
_0201EC98: .4byte 0x03003C00
_0201EC9C:
	movs r4, #0x80
	lsls r4, r4, #2
	movs r5, #0xf2
	lsls r5, r5, #8
	ldrh r0, [r2, #0xc]
	cmp r0, #4
	beq _0201ECC2
	cmp r0, #4
	bgt _0201ECB4
	cmp r0, #3
	beq _0201ECB8
	b _0201ECCA
_0201ECB4:
	cmp r0, #0xe
	bne _0201ECCA
_0201ECB8:
	movs r4, #0x80
	lsls r4, r4, #4
	movs r5, #0xe8
	lsls r5, r5, #8
	b _0201ECCA
_0201ECC2:
	movs r4, #0x80
	lsls r4, r4, #3
	movs r5, #0xf8
	lsls r5, r5, #8
_0201ECCA:
	ldrh r0, [r2, #0x12]
	adds r0, r4, r0
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	bls _0201ECDA
	strh r4, [r2, #0x12]
_0201ECDA:
	ldrh r0, [r2, #0x10]
	ldrh r1, [r2, #0x12]
	subs r0, r0, r1
	strh r0, [r2, #0x10]
	ldrh r3, [r2, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	bhi _0201ED1E
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r3
	subs r1, r1, r4
	strh r1, [r2, #0x14]
	ldrh r0, [r2, #0x16]
	adds r0, #1
	strh r0, [r2, #0x16]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r5
	bhs _0201ED0A
	ldrh r0, [r2, #0x18]
	adds r0, #1
	strh r0, [r2, #0x18]
_0201ED0A:
	ldrh r0, [r2, #0xc]
	cmp r0, #3
	beq _0201ED1E
	cmp r0, #0xe
	beq _0201ED1E
	ldrh r0, [r2, #0x1a]
	cmp r0, #5
	bhi _0201ED1E
	adds r0, #1
	strh r0, [r2, #0x1a]
_0201ED1E:
	ldrh r0, [r2, #0x10]
	movs r1, #0xd0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0201ED48
	strh r1, [r2, #0x10]
	adds r1, r2, #0
	adds r1, #0x26
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _0201ED48
	adds r0, r2, #0
	adds r0, #0x28
	movs r1, #4
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2, #0x1c]
_0201ED48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0201ED50
sub_0201ED50: @ 0x0201ED50
	ldr r1, _0201ED60 @ =0x03003710
	adds r1, r1, r0
	ldr r0, _0201ED64 @ =0x0000044D
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
_0201ED60: .4byte 0x03003710
_0201ED64: .4byte 0x0000044D

	thumb_func_start sub_0201ED68
sub_0201ED68: @ 0x0201ED68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0201EE3C @ =0x03003C00
	adds r7, r0, r1
	ldr r0, _0201EE40 @ =0x03001B50
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0201EE44 @ =0x03002410
	adds r6, r0, r1
	mov r2, r8
	ldr r0, [r2]
	lsrs r0, r0, #0xe
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	ldrb r1, [r6, #1]
	movs r2, #0x3f
	adds r4, r2, #0
	ands r4, r1
	orrs r4, r0
	strb r4, [r6, #1]
	mov r1, r8
	ldr r0, [r1]
	movs r5, #0xf
	lsrs r0, r0, #0x1e
	lsls r0, r0, #6
	ldrb r1, [r6, #3]
	ands r2, r1
	orrs r2, r0
	strb r2, [r6, #3]
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldr r1, _0201EE48 @ =0x000003FF
	ands r1, r0
	ldrh r3, [r6, #4]
	ldr r0, _0201EE4C @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r6, #4]
	movs r3, #0x11
	rsbs r3, r3, #0
	ands r3, r2
	strb r3, [r6, #3]
	ldrb r1, [r6, #5]
	movs r2, #0xd
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	ands r0, r5
	strb r0, [r6, #5]
	movs r0, #0x10
	orrs r4, r0
	strb r4, [r6, #1]
	adds r0, r7, #0
	adds r0, #0x28
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0201EE9C
	movs r0, #4
	rsbs r0, r0, #0
	ands r4, r0
	movs r0, #1
	orrs r4, r0
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r6, #3]
	ands r4, r2
	strb r4, [r6, #1]
	ldr r2, _0201EE50 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	ldr r1, _0201EE54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201EE58
	ldrh r1, [r7, #0x10]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	b _0201EE68
	.align 2, 0
_0201EE3C: .4byte 0x03003C00
_0201EE40: .4byte 0x03001B50
_0201EE44: .4byte 0x03002410
_0201EE48: .4byte 0x000003FF
_0201EE4C: .4byte 0xFFFFFC00
_0201EE50: .4byte 0xFFFF0000
_0201EE54: .4byte 0x0000FFFF
_0201EE58:
	ldrh r0, [r7, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
_0201EE68:
	add r4, sp, #8
	mov r0, sp
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r6, _0201EEC8 @ =0x03002410
	ldrh r0, [r4]
	strh r0, [r6, #6]
	adds r6, #8
	ldrh r0, [r4, #2]
	strh r0, [r6, #6]
	adds r6, #8
	ldrh r0, [r4, #4]
	strh r0, [r6, #6]
	ldrh r0, [r4, #6]
	strh r0, [r6, #0xe]
	ldr r0, _0201EECC @ =0x03001B50
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0201EEC8 @ =0x03002410
	adds r6, r0, r1
_0201EE9C:
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201EED8
	ldr r3, _0201EECC @ =0x03001B50
	ldr r4, _0201EED0 @ =0x00000844
	adds r0, r3, r4
	ldrh r1, [r0]
	ldr r0, [r7]
	subs r0, r0, r1
	mov r2, r8
	ldr r1, [r2, #8]
	adds r1, r1, r0
	ldrh r4, [r7, #0x16]
	adds r1, r1, r4
	ldrh r0, [r7, #0x1a]
	adds r1, r1, r0
	ldr r2, _0201EED4 @ =0x000001FF
	adds r0, r2, #0
	b _0201EEF6
	.align 2, 0
_0201EEC8: .4byte 0x03002410
_0201EECC: .4byte 0x03001B50
_0201EED0: .4byte 0x00000844
_0201EED4: .4byte 0x000001FF
_0201EED8:
	ldr r3, _0201EF30 @ =0x03001B50
	ldr r4, _0201EF34 @ =0x00000844
	adds r0, r3, r4
	ldrh r1, [r0]
	ldr r0, [r7]
	subs r0, r0, r1
	mov r2, r8
	ldr r1, [r2, #8]
	adds r1, r1, r0
	ldrh r0, [r7, #0x16]
	subs r1, r1, r0
	ldrh r0, [r7, #0x1a]
	subs r1, r1, r0
	ldr r4, _0201EF38 @ =0x000001FF
	adds r0, r4, #0
_0201EEF6:
	ands r1, r0
	ldrh r2, [r6, #2]
	ldr r0, _0201EF3C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #2]
	mov r0, r8
	ldr r2, [r0, #4]
	ldr r0, [r7, #4]
	ldr r4, _0201EF40 @ =0x00000846
	adds r1, r3, r4
	ldrb r1, [r1]
	subs r0, r0, r1
	adds r2, r2, r0
	ldrb r7, [r7, #0x18]
	adds r2, r2, r7
	strb r2, [r6]
	movs r0, #0x86
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201EF30: .4byte 0x03001B50
_0201EF34: .4byte 0x00000844
_0201EF38: .4byte 0x000001FF
_0201EF3C: .4byte 0xFFFFFE00
_0201EF40: .4byte 0x00000846

	thumb_func_start sub_0201EF44
sub_0201EF44: @ 0x0201EF44
	push {r4, lr}
	adds r4, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	ldr r1, _0201EFA4 @ =0x03003C00
	adds r3, r0, r1
	ldr r0, _0201EFA8 @ =0x03001B50
	ldr r1, _0201EFAC @ =0x00000846
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r3, #4]
	cmp r1, r0
	blt _0201EF9C
	adds r0, #0xc8
	cmp r1, r0
	bgt _0201EF9C
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #3
	bne _0201EF7E
	adds r0, r3, #0
	adds r0, #0x26
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0201EF9C
_0201EF7E:
	ldr r2, _0201EFB0 @ =0x0202FEE0
	ldrh r0, [r3, #0xc]
	adds r1, r3, #0
	adds r1, #0x25
	lsls r0, r0, #3
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldr r1, _0201EFB4 @ =0x0202FF78
	adds r0, r0, r1
	adds r1, r4, #0
	bl sub_0201ED68
_0201EF9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0201EFA4: .4byte 0x03003C00
_0201EFA8: .4byte 0x03001B50
_0201EFAC: .4byte 0x00000846
_0201EFB0: .4byte 0x0202FEE0
_0201EFB4: .4byte 0x0202FF78

	thumb_func_start sub_0201EFB8
sub_0201EFB8: @ 0x0201EFB8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r5, _0201F004 @ =0x030041A0
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #2
	ldr r0, _0201F008 @ =0x0202F7FC
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #0x10
	str r2, [r5, #0x40]
	ldrh r0, [r1, #4]
	orrs r0, r2
	str r0, [r5, #0x40]
	ldrh r0, [r1, #8]
	cmp r0, #4
	beq _0201F026
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0x64
	adds r1, r5, #0
	adds r1, #0x5a
_0201EFEA:
	ldrh r0, [r1]
	cmp r0, #0
	bne _0201F01C
	adds r0, r3, #1
	strh r0, [r1]
	lsls r1, r6, #2
	ldr r0, _0201F00C @ =0x02034CF4
	adds r1, r1, r0
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _0201F010
	ldrh r0, [r1]
	b _0201F016
	.align 2, 0
_0201F004: .4byte 0x030041A0
_0201F008: .4byte 0x0202F7FC
_0201F00C: .4byte 0x02034CF4
_0201F010:
	ldrh r0, [r1]
	bl sub_02024AEC
_0201F016:
	strh r0, [r4]
	movs r0, #1
	b _0201F028
_0201F01C:
	adds r4, #2
	adds r1, #2
	adds r2, #1
	cmp r2, #4
	ble _0201EFEA
_0201F026:
	movs r0, #0
_0201F028:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201F030
sub_0201F030: @ 0x0201F030
	push {r4, r5, r6, lr}
	ldr r5, _0201F0A8 @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x90
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	lsls r4, r0, #4
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #8
	bne _0201F050
	adds r4, #8
_0201F050:
	ldr r0, _0201F0AC @ =0x03001B50
	bl sub_02019AF0
	adds r1, r0, #0
	cmp r1, #0
	bge _0201F05E
	adds r0, r1, #7
_0201F05E:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r1, r0
	adds r4, r4, r0
	movs r0, #0x3f
	ands r4, r0
	ldr r1, _0201F0B0 @ =0x020338FC
	lsls r3, r4, #1
	adds r0, r3, r1
	ldrh r2, [r0]
	adds r0, r2, #0
	subs r0, #0x7e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r1, #0
	cmp r0, #1
	bls _0201F0D4
	cmp r2, #0x25
	beq _0201F0BC
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r0, [r0]
	cmp r0, #0
	beq _0201F0BC
	ldr r0, _0201F0B4 @ =0x0203397C
	adds r0, r3, r0
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0201F0B8 @ =0x0202F7FC
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	str r1, [r5, #0x40]
	ldrh r0, [r0, #4]
	b _0201F0EA
	.align 2, 0
_0201F0A8: .4byte 0x030041A0
_0201F0AC: .4byte 0x03001B50
_0201F0B0: .4byte 0x020338FC
_0201F0B4: .4byte 0x0203397C
_0201F0B8: .4byte 0x0202F7FC
_0201F0BC:
	ldr r0, _0201F0D0 @ =0x0203397C
	lsls r1, r4, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	adds r1, r1, r6
	ldrh r1, [r1]
	bl sub_0201EFB8
	movs r0, #0
	b _0201F0F0
	.align 2, 0
_0201F0D0: .4byte 0x0203397C
_0201F0D4:
	movs r1, #0x80
	lsls r1, r1, #0x10
	str r1, [r5, #0x40]
	cmp r2, #0x7f
	bne _0201F0E8
	ldr r0, _0201F0E4 @ =0x0000434E
	b _0201F0EA
	.align 2, 0
_0201F0E4: .4byte 0x0000434E
_0201F0E8:
	ldr r0, _0201F0F8 @ =0x00004350
_0201F0EA:
	orrs r0, r1
	str r0, [r5, #0x40]
	movs r0, #0xfe
_0201F0F0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0201F0F8: .4byte 0x00004350

	thumb_func_start sub_0201F0FC
sub_0201F0FC: @ 0x0201F0FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r7, _0201F1A0 @ =0x030041A0
	ldr r1, _0201F1A4 @ =0x03003710
	mov sl, r1
	adds r1, r7, #0
	adds r1, #0x8e
	ldrb r4, [r1]
	movs r3, #0xf0
	adds r1, r3, #0
	ands r1, r4
	adds r2, r0, #0
	ands r2, r3
	adds r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	mov sb, r8
	movs r2, #0xf
	movs r3, #0xf
	mov ip, r3
	mov r1, ip
	ands r1, r4
	mov ip, r1
	ands r0, r3
	adds r1, r1, r0
	ands r1, r2
	mov r3, r8
	orrs r3, r1
	mov r8, r3
	mov r1, ip
	subs r0, r1, r0
	ands r0, r2
	mov r2, sb
	orrs r2, r0
	mov sb, r2
	adds r2, r7, #0
	adds r2, #0x7a
	movs r0, #0
	strh r0, [r2]
	str r0, [r7, #0x18]
	ldr r0, [r7]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0201F1B0
	ldr r4, _0201F1A8 @ =0x0600A000
	adds r5, r4, #0
	mov r1, sp
	lsls r2, r3, #1
	mov r3, sl
	adds r3, #0x10
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, r8
	movs r1, #0xf
	ands r0, r1
	cmp ip, r0
	bls _0201F192
	ldr r5, _0201F1AC @ =0x0600A800
	mov r0, sp
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
	adds r1, r2, r1
	ldrh r1, [r1]
	strh r1, [r0]
_0201F192:
	adds r6, r4, #0
	mov r0, sp
	mov r2, sb
	lsls r1, r2, #1
	adds r1, r1, r3
	b _0201F1EC
	.align 2, 0
_0201F1A0: .4byte 0x030041A0
_0201F1A4: .4byte 0x03003710
_0201F1A8: .4byte 0x0600A000
_0201F1AC: .4byte 0x0600A800
_0201F1B0:
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r2]
	ldr r3, _0201F294 @ =0x0600A800
	adds r5, r3, #0
	mov r2, sp
	mov r1, r8
	lsls r0, r1, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r6, r3, #0
	mov r0, sb
	lsls r3, r0, #1
	adds r1, r3, r1
	ldrh r0, [r1]
	strh r0, [r2, #2]
	mov r0, sb
	movs r1, #0xf
	ands r0, r1
	cmp ip, r0
	bhs _0201F1F0
	ldr r6, _0201F298 @ =0x0600A000
	mov r0, sp
	mov r1, sl
	adds r1, #0x10
	adds r1, r3, r1
_0201F1EC:
	ldrh r1, [r1]
	strh r1, [r0, #2]
_0201F1F0:
	adds r4, r7, #0
	adds r4, #0x7a
	adds r2, r7, #0
	adds r2, #0x8e
	str r2, [sp, #4]
	ldrb r0, [r2]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	mov r3, r8
	movs r0, #0xf0
	ands r3, r0
	str r3, [sp, #8]
	lsls r0, r3, #3
	adds r5, r5, r0
	mov sl, r8
	mov r1, sl
	movs r2, #0xf
	ands r1, r2
	mov sl, r1
	lsls r0, r1, #2
	adds r2, r0, r5
	mov r0, sb
	movs r3, #0xf0
	ands r0, r3
	lsls r0, r0, #3
	adds r6, r6, r0
	mov r0, sb
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r6, r6, r0
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, #0
	str r2, [sp, #0x10]
	bl sub_0201F6DC
	ldr r3, [sp, #4]
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	cmp r0, #0
	bne _0201F262
	ldrh r0, [r2]
	ldr r1, _0201F29C @ =0x000003FF
	ands r1, r0
	adds r3, r1, #0
	cmp r3, #5
	bls _0201F262
	adds r0, r1, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0201F262
	cmp r3, #0xaf
	bls _0201F300
_0201F262:
	mov r0, sp
	ldrh r0, [r0, #2]
	adds r1, r6, #0
	bl sub_0201F6DC
	cmp r0, #0
	bne _0201F28E
	adds r1, r6, #0
	ldrh r0, [r1]
	ldr r2, _0201F29C @ =0x000003FF
	ands r2, r0
	adds r3, r2, #0
	cmp r3, #5
	bls _0201F28E
	adds r0, r2, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0201F28E
	cmp r3, #0xaf
	bls _0201F2A0
_0201F28E:
	movs r0, #0
	strh r0, [r4]
	b _0201F356
	.align 2, 0
_0201F294: .4byte 0x0600A800
_0201F298: .4byte 0x0600A000
_0201F29C: .4byte 0x000003FF
_0201F2A0:
	movs r4, #0x80
	lsls r4, r4, #4
	ands r1, r4
	cmp r1, #0
	beq _0201F2B0
	movs r0, #0x80
	lsls r0, r0, #9
	str r0, [r7, #0x18]
_0201F2B0:
	adds r1, r7, #0
	adds r1, #0x99
	movs r0, #0x70
	strb r0, [r1]
	ldr r1, [r7]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r1, r0
	str r1, [r7, #0x10]
	ldr r0, [sp, #0xc]
	ldrb r2, [r0]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0xc
	adds r0, r0, r4
	orrs r1, r0
	str r1, [r7, #0x10]
	ldr r2, [sp, #0xc]
	ldrb r1, [r2]
	movs r2, #0xf0
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #8
	adds r0, r0, r4
	str r0, [r7, #0x14]
	mov r0, sb
	ands r0, r3
	lsls r0, r0, #0xc
	adds r0, r0, r4
	ldr r1, [r7, #0x18]
	orrs r1, r0
	str r1, [r7, #0x18]
	mov r0, sb
	ands r0, r2
	lsls r0, r0, #8
	adds r0, r0, r4
	str r0, [r7, #0x1c]
	mov r0, sb
	b _0201F356
_0201F300:
	movs r3, #0x80
	lsls r3, r3, #4
	ands r2, r3
	cmp r2, #0
	beq _0201F310
	movs r0, #0x80
	lsls r0, r0, #9
	str r0, [r7, #0x18]
_0201F310:
	adds r1, r7, #0
	adds r1, #0x99
	movs r0, #0x60
	strb r0, [r1]
	ldr r1, [r7]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r1, r0
	str r1, [r7, #0x10]
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	adds r0, r0, r3
	orrs r1, r0
	str r1, [r7, #0x10]
	ldr r2, [sp, #4]
	ldrb r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #8
	adds r0, r0, r3
	str r0, [r7, #0x14]
	mov r0, sl
	lsls r1, r0, #0xc
	adds r1, r1, r3
	ldr r0, [r7, #0x18]
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r1, [sp, #8]
	lsls r0, r1, #8
	adds r0, r0, r3
	str r0, [r7, #0x1c]
	mov r0, r8
_0201F356:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201F368
sub_0201F368: @ 0x0201F368
	push {r4, r5, lr}
	ldr r4, _0201F39C @ =0x030041A0
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	bl sub_0201F538
	movs r5, #0
_0201F378:
	lsls r1, r5, #1
	adds r0, r4, #0
	adds r0, #0x48
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #0x44]
	bl sub_0201F6DC
	cmp r0, #0
	bne _0201F3D8
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0201F3A4
	ldr r2, _0201F3A0 @ =0x0600A000
	b _0201F3A6
	.align 2, 0
_0201F39C: .4byte 0x030041A0
_0201F3A0: .4byte 0x0600A000
_0201F3A4:
	ldr r2, _0201F3DC @ =0x0600A800
_0201F3A6:
	adds r0, r4, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	lsls r1, r1, #3
	adds r2, r1, r2
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, _0201F3E0 @ =0x02033A1C
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r2, r0
	ldrh r0, [r0]
	ldr r2, _0201F3E4 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5e
	bls _0201F3E8
_0201F3D8:
	movs r0, #0
	b _0201F3F0
	.align 2, 0
_0201F3DC: .4byte 0x0600A800
_0201F3E0: .4byte 0x02033A1C
_0201F3E4: .4byte 0x000003FF
_0201F3E8:
	adds r5, #1
	cmp r5, #3
	ble _0201F378
	movs r0, #1
_0201F3F0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201F3F8
sub_0201F3F8: @ 0x0201F3F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldr r4, _0201F43C @ =0x030041A0
	ldr r0, [r4]
	subs r1, r5, r0
	str r1, [r4, #0x20]
	ldr r0, [r4, #4]
	subs r0, r6, r0
	str r0, [r4, #0x24]
	cmp r1, #0
	bge _0201F41E
	rsbs r0, r1, #0
	str r0, [r4, #0x20]
_0201F41E:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bge _0201F428
	rsbs r0, r0, #0
	str r0, [r4, #0x24]
_0201F428:
	ldr r0, [r4, #0x20]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _0201F440
	ldr r0, [r4, #0x24]
	cmp r0, r1
	bgt _0201F440
	movs r0, #1
	b _0201F52A
	.align 2, 0
_0201F43C: .4byte 0x030041A0
_0201F440:
	ldr r0, [r4]
	subs r0, r5, r0
	asrs r0, r0, #8
	str r0, [r4, #0x20]
	ldr r0, [r4, #4]
	subs r0, r6, r0
	asrs r0, r0, #8
	str r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	mov sb, r1
	mov r8, r0
	cmp r7, #0
	beq _0201F49C
	cmp r7, #1
	beq _0201F4B4
	movs r0, #1
	adds r1, r5, #0
	bl sub_020207C0
	movs r0, #1
	adds r1, r6, #0
	bl sub_02020814
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r1, _0201F498 @ =0x020338F8
	ldrh r0, [r1]
	cmp r3, r0
	bhs _0201F4E4
	movs r2, #0
	subs r1, #0x1c
	adds r4, r1, #0
	ldrh r1, [r4]
	cmp r3, r1
	bls _0201F4EA
	b _0201F4D2
	.align 2, 0
_0201F498: .4byte 0x020338F8
_0201F49C:
	movs r0, #0
	adds r1, r5, #0
	bl sub_020207C0
	cmp r0, #0
	beq _0201F4CA
	movs r0, #0
	adds r1, r6, #0
	bl sub_02020814
	str r7, [r4, #0x20]
	b _0201F51C
_0201F4B4:
	movs r0, #0
	adds r1, r6, #0
	bl sub_02020814
	cmp r0, #0
	beq _0201F4CE
	movs r0, #0
	adds r1, r5, #0
	bl sub_020207C0
	movs r0, #0
_0201F4CA:
	str r0, [r4, #0x24]
	b _0201F51C
_0201F4CE:
	str r0, [r4, #0x20]
	b _0201F51C
_0201F4D2:
	adds r2, #1
	cmp r2, #6
	bgt _0201F4EA
	lsls r0, r2, #2
	adds r1, r0, r4
	ldrh r1, [r1]
	cmp r3, r1
	bhi _0201F4D2
	b _0201F4EA
_0201F4E4:
	movs r2, #0
	adds r4, r1, #0
	subs r4, #0x1c
_0201F4EA:
	lsls r0, r2, #2
	adds r1, r0, r4
	mov r2, r8
	ldrb r0, [r2]
	ldrb r2, [r1, #2]
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0201F50E
	mvns r0, r1
	lsls r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r1, r0, #0x18
_0201F50E:
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0201F51C
	mov r0, r8
	strb r2, [r0]
_0201F51C:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, sb
	beq _0201F528
	bl sub_02020790
_0201F528:
	movs r0, #0
_0201F52A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201F538
sub_0201F538: @ 0x0201F538
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0201F5CC @ =0x030041A0
	mov ip, r0
	ldr r7, _0201F5D0 @ =0x03003710
	ldr r1, [r0, #4]
	asrs r1, r1, #8
	movs r2, #0xff
	lsls r2, r2, #4
	ldr r0, [r0]
	asrs r0, r0, #8
	ands r0, r2
	ands r1, r2
	lsls r1, r1, #0x18
	movs r2, #0xf0
	ands r0, r2
	lsls r0, r0, #0x14
	orrs r0, r1
	lsrs r1, r0, #0x18
	mov r0, ip
	adds r0, #0x8e
	strb r1, [r0]
	movs r5, #0
	ldr r1, _0201F5D4 @ =0x020339FC
	mov r8, r1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sb, r2
	mov r4, ip
	adds r4, #0x48
	movs r6, #0x80
	lsls r6, r6, #0x11
_0201F57E:
	lsls r0, r5, #0x19
	lsrs r0, r0, #0x16
	add r0, r8
	mov r3, ip
	ldr r1, [r3]
	ldr r0, [r0]
	adds r3, r1, r0
	lsrs r0, r6, #0x18
	lsls r0, r0, #2
	add r0, r8
	mov r2, ip
	ldr r1, [r2, #4]
	ldr r0, [r0]
	adds r1, r1, r0
	asrs r2, r1, #8
	movs r1, #0x10
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r2, r0
	lsls r2, r2, #0x18
	asrs r0, r3, #8
	movs r1, #0xf0
	ands r0, r1
	lsls r0, r0, #0x14
	orrs r0, r2
	lsrs r1, r0, #0x18
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r3, r0
	cmp r3, #0
	bne _0201F5D8
	strh r1, [r4, #8]
	lsls r0, r1, #1
	adds r1, r7, #0
	adds r1, #0x10
	adds r1, r1, r0
	ldrh r0, [r1]
	b _0201F5E0
	.align 2, 0
_0201F5CC: .4byte 0x030041A0
_0201F5D0: .4byte 0x03003710
_0201F5D4: .4byte 0x020339FC
_0201F5D8:
	strh r1, [r4, #8]
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
_0201F5E0:
	strh r0, [r4]
	adds r4, #2
	movs r2, #0x80
	lsls r2, r2, #0x12
	adds r6, r6, r2
	adds r5, #1
	cmp r5, #3
	ble _0201F57E
	mov r3, ip
	ldr r1, [r3]
	ldr r0, _0201F630 @ =0xFFFFFE00
	adds r1, r1, r0
	str r1, [r3, #0x20]
	ldr r0, [r3, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r3, #0x24]
	asrs r2, r0, #8
	movs r0, #0xff
	lsls r0, r0, #4
	asrs r1, r1, #8
	ands r1, r0
	ands r2, r0
	mov r0, ip
	adds r0, #0x8f
	movs r3, #0xf0
	ands r1, r3
	asrs r1, r1, #4
	orrs r2, r1
	strb r2, [r0]
	mov r1, ip
	ldr r0, [r1, #0x20]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0201F638
	ldr r1, _0201F634 @ =0x0600A000
	b _0201F63A
	.align 2, 0
_0201F630: .4byte 0xFFFFFE00
_0201F634: .4byte 0x0600A000
_0201F638:
	ldr r1, _0201F65C @ =0x0600A800
_0201F63A:
	adds r0, r2, #0
	ands r0, r3
	lsls r0, r0, #3
	adds r1, r0, r1
	movs r0, #0xf
	ands r2, r0
	lsls r0, r2, #2
	adds r1, r1, r0
	mov r2, ip
	str r1, [r2, #0x44]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201F65C: .4byte 0x0600A800

	thumb_func_start sub_0201F660
sub_0201F660: @ 0x0201F660
	push {r4, r5, r6, r7, lr}
	lsls r4, r1, #0x18
	lsrs r5, r4, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0201F698
	ldr r3, _0201F690 @ =0x0600C000
	ldr r0, _0201F694 @ =0x03001B40
	ldr r2, [r0]
	movs r1, #0xf
	ands r1, r5
	lsls r1, r1, #1
	lsrs r0, r4, #0x1c
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r2, #0x24
	b _0201F6B0
	.align 2, 0
_0201F690: .4byte 0x0600C000
_0201F694: .4byte 0x03001B40
_0201F698:
	ldr r3, _0201F6D4 @ =0x0600C800
	ldr r0, _0201F6D8 @ =0x03001B40
	ldr r2, [r0]
	movs r1, #0xf
	ands r1, r5
	lsls r1, r1, #1
	lsrs r0, r4, #0x1c
	lsls r0, r0, #5
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r2, r2, r0
_0201F6B0:
	adds r2, r2, r1
	strh r6, [r2]
	movs r0, #0xf0
	ands r0, r5
	lsls r0, r0, #3
	adds r3, r3, r0
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #2
	adds r3, r3, r0
	adds r0, r3, #0
	adds r1, r7, #0
	bl sub_02020A0C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201F6D4: .4byte 0x0600C800
_0201F6D8: .4byte 0x03001B40

	thumb_func_start sub_0201F6DC
sub_0201F6DC: @ 0x0201F6DC
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	movs r3, #0
	ldr r6, _0201F774 @ =0x000003FF
	ldr r5, _0201F778 @ =0x0000031F
	ldr r1, _0201F77C @ =0x02033A1C
_0201F6EE:
	ldr r0, [r1]
	adds r0, r4, r0
	ldrh r0, [r0]
	adds r2, r6, #0
	ands r2, r0
	cmp r3, #1
	bne _0201F700
	cmp r2, #0x96
	beq _0201F780
_0201F700:
	adds r0, r2, #0
	subs r0, #0xb0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _0201F780
	adds r0, r2, #0
	subs r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x15
	bls _0201F780
	adds r0, r2, #0
	subs r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	bls _0201F780
	adds r1, #4
	adds r3, #1
	cmp r3, #3
	ble _0201F6EE
	mov r0, ip
	subs r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0201F76E
	mov r0, ip
	subs r0, #0x22
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0201F76E
	mov r0, ip
	subs r0, #0x27
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _0201F76E
	mov r0, ip
	subs r0, #0x31
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0201F76E
	mov r0, ip
	subs r0, #0x36
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bls _0201F76E
	mov r0, ip
	cmp r0, #0x41
	bne _0201F784
_0201F76E:
	movs r0, #1
	b _0201F786
	.align 2, 0
_0201F774: .4byte 0x000003FF
_0201F778: .4byte 0x0000031F
_0201F77C: .4byte 0x02033A1C
_0201F780:
	movs r0, #2
	b _0201F786
_0201F784:
	movs r0, #0
_0201F786:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0201F78C
sub_0201F78C: @ 0x0201F78C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r2, _0201F82C @ =0x030041A0
	movs r5, #0
	movs r3, #0xff
	adds r6, r2, #0
	adds r6, #0xa2
	movs r0, #0xaa
	adds r0, r0, r2
	mov r8, r0
	adds r1, r6, #0
	movs r4, #7
_0201F7AA:
	strb r5, [r1]
	ldrb r0, [r1, #8]
	orrs r0, r3
	strb r0, [r1, #8]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _0201F7AA
	adds r1, r2, #0
	adds r1, #0x8b
	ldrb r0, [r1]
	adds r0, r6, r0
	movs r2, #1
	strb r2, [r0]
	cmp r7, #0
	bne _0201F7D8
	ldrb r0, [r1]
	adds r4, r0, #4
	cmp r4, #7
	ble _0201F7D4
	subs r4, r0, #4
_0201F7D4:
	adds r0, r6, r4
	strb r2, [r0]
_0201F7D8:
	movs r4, #0
_0201F7DA:
	adds r5, r6, r4
	ldrb r0, [r5]
	cmp r0, #0
	bne _0201F7F2
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0201F844
	cmp r0, #0
	bne _0201F7F2
	movs r0, #1
	strb r0, [r5]
_0201F7F2:
	adds r4, #1
	cmp r4, #7
	ble _0201F7DA
	movs r4, #0
	movs r5, #0
	adds r2, r6, #0
	mov r1, r8
_0201F800:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201F80E
	adds r0, r1, r5
	strb r4, [r0]
	adds r5, #1
_0201F80E:
	adds r4, #1
	cmp r4, #7
	ble _0201F800
	cmp r5, #0
	beq _0201F834
	ldr r0, _0201F830 @ =0x03001B50
	bl sub_02019AF0
	adds r1, r5, #0
	bl __modsi3
	add r0, r8
	ldrb r4, [r0]
	adds r0, r4, #0
	b _0201F836
	.align 2, 0
_0201F82C: .4byte 0x030041A0
_0201F830: .4byte 0x03001B50
_0201F834:
	ldr r0, _0201F840 @ =0x00000777
_0201F836:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0201F840: .4byte 0x00000777

	thumb_func_start sub_0201F844
sub_0201F844: @ 0x0201F844
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0201F8A8 @ =0x030041A0
	mov ip, r1
	ldr r5, _0201F8AC @ =0x03003710
	ldr r2, _0201F8B0 @ =0x02033A2C
	lsls r1, r0, #1
	lsls r0, r0, #3
	adds r0, r0, r2
	mov r4, ip
	ldr r3, [r4]
	ldr r0, [r0]
	adds r3, r3, r0
	adds r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #4]
	adds r1, r1, r0
	asrs r1, r1, #8
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r1, r0
	asrs r0, r3, #0xc
	movs r2, #0xf
	ands r0, r2
	orrs r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r3, r0
	cmp r3, #0
	bne _0201F8B8
	lsls r0, r4, #1
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r1, #0x48
	strh r0, [r1]
	ldr r2, _0201F8B4 @ =0x0600A000
	b _0201F8CC
	.align 2, 0
_0201F8A8: .4byte 0x030041A0
_0201F8AC: .4byte 0x03003710
_0201F8B0: .4byte 0x02033A2C
_0201F8B4: .4byte 0x0600A000
_0201F8B8:
	lsls r0, r4, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r1, #0x48
	strh r0, [r1]
	ldr r2, _0201F8F0 @ =0x0600A800
_0201F8CC:
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #3
	adds r2, r0, r2
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #2
	adds r2, r2, r0
	mov r4, ip
	str r2, [r4, #0x44]
	ldrh r0, [r1]
	adds r1, r2, #0
	bl sub_0201F6DC
	cmp r0, #0
	bne _0201F8F4
	movs r0, #1
	b _0201F8F6
	.align 2, 0
_0201F8F0: .4byte 0x0600A800
_0201F8F4:
	movs r0, #0
_0201F8F6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0201F8FC
sub_0201F8FC: @ 0x0201F8FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r7, _0201F94C @ =0x030041A0
	ldr r0, _0201F950 @ =0x03003710
	mov sl, r0
	adds r0, r7, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	mov r8, r0
	movs r4, #0
	ldr r1, _0201F954 @ =0x02034062
	mov sb, r1
	mov ip, sb
	movs r2, #0
	movs r3, #0
	movs r6, #0xa0
	lsls r6, r6, #0x13
_0201F926:
	adds r1, r3, #0
	lsrs r0, r2, #0x18
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	cmp r5, r0
	beq _0201F958
	adds r2, r2, r6
	adds r3, r1, #5
	adds r4, #1
	cmp r4, #0xc
	ble _0201F926
_0201F93E:
	cmp r4, #0xc
	ble _0201F96C
	adds r1, r7, #0
	adds r1, #0x6e
	movs r0, #0xf
	strh r0, [r1]
	b _0201FB84
	.align 2, 0
_0201F94C: .4byte 0x030041A0
_0201F950: .4byte 0x03003710
_0201F954: .4byte 0x02034062
_0201F958:
	adds r1, r7, #0
	adds r1, #0x90
	adds r0, r3, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, sb
	ldrh r5, [r0]
	b _0201F93E
_0201F96C:
	adds r0, r7, #0
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #7
	bne _0201F97E
	adds r5, #0x10
_0201F97E:
	ldr r0, _0201F9C8 @ =0x03001B50
	bl sub_02019AF0
	adds r1, r0, #0
	cmp r1, #0
	bge _0201F98C
	adds r0, r1, #3
_0201F98C:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	adds r5, r5, r0
	ldr r0, _0201F9CC @ =0x0000011F
	cmp r5, r0
	ble _0201F99C
	movs r5, #0
_0201F99C:
	ldr r0, _0201F9D0 @ =0x020340E4
	adds r0, r5, r0
	ldrb r5, [r0]
	lsls r1, r5, #2
	ldr r0, _0201F9D4 @ =0x02034CF4
	adds r6, r1, r0
	ldrb r1, [r6, #2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0201F9D8 @ =0x0202F7FC
	adds r2, r0, r1
	ldrh r1, [r2, #6]
	ldr r0, _0201F9DC @ =0x00000FFF
	cmp r1, r0
	beq _0201F9C0
	cmp r5, #0xd
	bne _0201F9E0
_0201F9C0:
	adds r0, r7, #0
	adds r0, #0x6e
	strh r4, [r0]
	b _0201FB84
	.align 2, 0
_0201F9C8: .4byte 0x03001B50
_0201F9CC: .4byte 0x0000011F
_0201F9D0: .4byte 0x020340E4
_0201F9D4: .4byte 0x02034CF4
_0201F9D8: .4byte 0x0202F7FC
_0201F9DC: .4byte 0x00000FFF
_0201F9E0:
	ldrh r0, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r7, #0x40]
	ldrb r1, [r6, #2]
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0201F9FA
	cmp r1, #0x1e
	bne _0201FAD4
_0201F9FA:
	adds r1, r7, #0
	adds r1, #0x7c
	ldr r0, _0201FA78 @ =0x00003260
	strh r0, [r1]
	ldrb r0, [r6, #2]
	cmp r0, #0x1e
	bne _0201FA0C
	ldr r0, _0201FA7C @ =0x00003268
	strh r0, [r1]
_0201FA0C:
	movs r4, #0
	ldr r5, _0201FA80 @ =0x02033A6C
	ldrh r0, [r5]
	ldrb r1, [r6, #2]
	adds r7, #0x7a
	mov r3, r8
	lsls r2, r3, #1
	ldr r6, _0201FA84 @ =0x03001B40
	mov sb, r6
	lsrs r3, r3, #4
	cmp r0, r1
	beq _0201FA36
	adds r6, r5, #0
_0201FA26:
	adds r4, #1
	cmp r4, #5
	bgt _0201FA36
	lsls r0, r4, #2
	adds r5, r0, r6
	ldrh r0, [r5]
	cmp r0, r1
	bne _0201FA26
_0201FA36:
	ldrh r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0201FA90
	mov r0, sl
	adds r0, #0x10
	adds r0, r0, r2
	ldr r1, _0201FA88 @ =0x00007777
	strh r1, [r0]
	mov r0, sb
	ldr r2, [r0]
	movs r4, #0xf
	mov r1, r8
	ands r4, r1
	lsls r1, r4, #1
	lsls r0, r3, #5
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r1, [r5, #2]
	strh r1, [r0]
	lsls r3, r3, #1
	ldr r6, _0201FA8C @ =0x000018F8
	adds r2, r2, r6
	adds r2, r2, r3
	movs r1, #1
	lsls r1, r4
	ldrh r0, [r2]
	bics r0, r1
	b _0201FB82
	.align 2, 0
_0201FA78: .4byte 0x00003260
_0201FA7C: .4byte 0x00003268
_0201FA80: .4byte 0x02033A6C
_0201FA84: .4byte 0x03001B40
_0201FA88: .4byte 0x00007777
_0201FA8C: .4byte 0x000018F8
_0201FA90:
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, sl
	adds r0, r0, r2
	ldr r1, _0201FACC @ =0x00007777
	strh r1, [r0]
	mov r0, sb
	ldr r2, [r0]
	movs r4, #0xf
	mov r1, r8
	ands r4, r1
	lsls r1, r4, #1
	lsls r0, r3, #5
	adds r1, r1, r0
	movs r6, #0x89
	lsls r6, r6, #2
	adds r0, r2, r6
	adds r0, r0, r1
	ldrh r1, [r5, #2]
	strh r1, [r0]
	lsls r3, r3, #1
	ldr r0, _0201FAD0 @ =0x00001918
	adds r2, r2, r0
	adds r2, r2, r3
	movs r1, #1
	lsls r1, r4
	ldrh r0, [r2]
	bics r0, r1
	b _0201FB82
	.align 2, 0
_0201FACC: .4byte 0x00007777
_0201FAD0: .4byte 0x00001918
_0201FAD4:
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r1, _0201FAE8 @ =0x00001270
	strh r1, [r0]
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _0201FAEC
	ldrh r5, [r6]
	b _0201FAF6
	.align 2, 0
_0201FAE8: .4byte 0x00001270
_0201FAEC:
	ldrh r0, [r6]
	bl sub_02024AEC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0201FAF6:
	adds r0, r7, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0201FB44
	mov r1, r8
	lsls r0, r1, #1
	mov r1, sl
	adds r1, #0x10
	adds r1, r1, r0
	ldrb r0, [r6, #2]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _0201FB3C @ =0x03001B40
	ldr r2, [r0]
	movs r4, #0xf
	mov r3, r8
	ands r4, r3
	lsls r1, r4, #1
	lsrs r3, r3, #4
	lsls r0, r3, #5
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x24
	adds r0, r0, r1
	strh r5, [r0]
	lsls r3, r3, #1
	ldr r6, _0201FB40 @ =0x000018F8
	adds r2, r2, r6
	b _0201FB78
	.align 2, 0
_0201FB3C: .4byte 0x03001B40
_0201FB40: .4byte 0x000018F8
_0201FB44:
	mov r1, r8
	lsls r0, r1, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
	adds r1, r1, r0
	ldrb r0, [r6, #2]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _0201FB94 @ =0x03001B40
	ldr r2, [r0]
	movs r4, #0xf
	mov r3, r8
	ands r4, r3
	lsls r1, r4, #1
	lsrs r3, r3, #4
	lsls r0, r3, #5
	adds r1, r1, r0
	movs r6, #0x89
	lsls r6, r6, #2
	adds r0, r2, r6
	adds r0, r0, r1
	strh r5, [r0]
	lsls r3, r3, #1
	ldr r0, _0201FB98 @ =0x00001918
	adds r2, r2, r0
_0201FB78:
	adds r2, r2, r3
	movs r0, #1
	lsls r0, r4
	ldrh r1, [r2]
	orrs r0, r1
_0201FB82:
	strh r0, [r2]
_0201FB84:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201FB94: .4byte 0x03001B40
_0201FB98: .4byte 0x00001918

	thumb_func_start sub_0201FB9C
sub_0201FB9C: @ 0x0201FB9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0201FC1C @ =0x030041A0
	mov r8, r0
	ldr r1, _0201FC20 @ =0x03003710
	mov sb, r1
	mov r5, r8
	adds r5, #0x7a
	ldrb r0, [r5]
	lsls r4, r0, #0x18
	lsrs r6, r4, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x10
	mov r1, r8
	str r0, [r1, #0x40]
	ldr r0, _0201FC24 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #9
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r1, r8
	ldr r0, [r1, #0x40]
	ldr r1, _0201FC28 @ =0x00005344
	orrs r0, r1
	mov r1, r8
	str r0, [r1, #0x40]
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0201FC3C
	lsls r0, r6, #1
	mov r1, sb
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0201FC2C @ =0x00007777
	strh r1, [r0]
	ldr r0, _0201FC30 @ =0x03001B40
	ldr r3, [r0]
	movs r5, #0xf
	ands r5, r6
	lsls r1, r5, #1
	lsrs r4, r4, #0x1c
	lsls r0, r4, #5
	adds r1, r1, r0
	adds r2, r3, #0
	adds r2, #0x24
	adds r2, r2, r1
	ldr r0, _0201FC34 @ =0x02033F80
	lsls r6, r7, #1
	adds r0, r6, r0
	ldrh r0, [r0]
	strh r0, [r2]
	lsls r4, r4, #1
	ldr r0, _0201FC38 @ =0x000018F8
	adds r3, r3, r0
	b _0201FC72
	.align 2, 0
_0201FC1C: .4byte 0x030041A0
_0201FC20: .4byte 0x03003710
_0201FC24: .4byte 0x03001B50
_0201FC28: .4byte 0x00005344
_0201FC2C: .4byte 0x00007777
_0201FC30: .4byte 0x03001B40
_0201FC34: .4byte 0x02033F80
_0201FC38: .4byte 0x000018F8
_0201FC3C:
	lsls r0, r6, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sb
	adds r0, r0, r1
	ldr r1, _0201FC9C @ =0x00007777
	strh r1, [r0]
	ldr r0, _0201FCA0 @ =0x03001B40
	ldr r3, [r0]
	movs r5, #0xf
	ands r5, r6
	lsls r1, r5, #1
	lsrs r4, r4, #0x1c
	lsls r0, r4, #5
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r2, r2, r1
	ldr r0, _0201FCA4 @ =0x02033F80
	lsls r6, r7, #1
	adds r0, r6, r0
	ldrh r0, [r0]
	strh r0, [r2]
	lsls r4, r4, #1
	ldr r1, _0201FCA8 @ =0x00001918
	adds r3, r3, r1
_0201FC72:
	adds r3, r3, r4
	movs r1, #1
	lsls r1, r5
	ldrh r0, [r3]
	bics r0, r1
	strh r0, [r3]
	adds r0, r6, r7
	lsls r0, r0, #2
	ldr r1, _0201FCAC @ =0x0202F8EC
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x7c
	strh r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201FC9C: .4byte 0x00007777
_0201FCA0: .4byte 0x03001B40
_0201FCA4: .4byte 0x02033F80
_0201FCA8: .4byte 0x00001918
_0201FCAC: .4byte 0x0202F8EC

	thumb_func_start sub_0201FCB0
sub_0201FCB0: @ 0x0201FCB0
	push {r4, lr}
	ldr r2, _0201FD04 @ =0x030041A0
	adds r0, r2, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	beq _0201FCCE
	cmp r0, #2
	beq _0201FCCE
	cmp r0, #1
	beq _0201FCCE
	cmp r0, #6
	beq _0201FCCE
	cmp r0, #7
	bne _0201FD16
_0201FCCE:
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #0
	bne _0201FD16
	adds r0, r2, #0
	adds r0, #0x92
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _0201FD10
	subs r0, #1
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #1
	ands r1, r2
	strb r1, [r0]
	cmp r1, #0
	bne _0201FD0C
	ldr r0, _0201FD08 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x41
	bl __modsi3
	adds r0, #0x20
	b _0201FD0E
	.align 2, 0
_0201FD04: .4byte 0x030041A0
_0201FD08: .4byte 0x03001B50
_0201FD0C:
	movs r0, #4
_0201FD0E:
	strb r0, [r4]
_0201FD10:
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_0201FD16:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0201FD1C
sub_0201FD1C: @ 0x0201FD1C
	push {r4, r5, lr}
	ldr r4, _0201FD6C @ =0x030041A0
	ldr r2, [r4]
	subs r0, r0, r2
	asrs r0, r0, #8
	str r0, [r4, #0x20]
	ldr r2, [r4, #4]
	subs r1, r1, r2
	asrs r1, r1, #8
	str r1, [r4, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _0201FD70 @ =0x020338F8
	ldrh r1, [r0]
	cmp r2, r1
	bhs _0201FD74
	movs r1, #0
	subs r0, #0x1c
	adds r5, r4, #0
	adds r5, #0x94
	ldrh r3, [r0]
	cmp r2, r3
	bls _0201FD7A
	adds r3, r0, #0
_0201FD58:
	adds r1, #1
	cmp r1, #6
	bgt _0201FD7A
	lsls r0, r1, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r2, r0
	bhi _0201FD58
	b _0201FD7A
	.align 2, 0
_0201FD6C: .4byte 0x030041A0
_0201FD70: .4byte 0x020338F8
_0201FD74:
	movs r1, #0
	adds r5, r4, #0
	adds r5, #0x94
_0201FD7A:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0201FD9C
	lsls r1, r1, #2
	ldr r0, _0201FDE8 @ =0x020338DC
	adds r0, r1, r0
	adds r1, r4, #0
	adds r1, #0x8b
	ldrb r0, [r0, #2]
	ldrb r2, [r1]
	cmp r0, r2
	beq _0201FD9C
	strb r0, [r1]
	bl sub_02020790
	movs r0, #0x20
	strb r0, [r5]
_0201FD9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bge _0201FDA6
	rsbs r0, r0, #0
	str r0, [r4, #0x20]
_0201FDA6:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bge _0201FDB0
	rsbs r0, r0, #0
	str r0, [r4, #0x24]
_0201FDB0:
	ldr r0, [r4, #0x20]
	cmp r0, #1
	bgt _0201FDEC
	ldr r0, [r4, #0x24]
	cmp r0, #1
	bgt _0201FDEC
	ldr r2, [r4, #4]
	asrs r2, r2, #8
	movs r1, #0xff
	lsls r1, r1, #4
	ands r2, r1
	str r2, [r4, #0x24]
	ldr r0, [r4]
	asrs r0, r0, #8
	ands r0, r1
	str r0, [r4, #0x20]
	adds r3, r4, #0
	adds r3, #0x8e
	strb r2, [r3]
	ldr r0, [r4, #0x20]
	movs r1, #0xf0
	ands r0, r1
	asrs r0, r0, #4
	orrs r0, r2
	strb r0, [r3]
	movs r0, #1
	b _0201FDEE
	.align 2, 0
_0201FDE8: .4byte 0x020338DC
_0201FDEC:
	movs r0, #0
_0201FDEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0201FDF4
sub_0201FDF4: @ 0x0201FDF4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0201FE44 @ =0x030041A0
	mov ip, r0
	mov r1, ip
	adds r1, #0x8a
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0201FE64
	mov r2, ip
	adds r2, #0x89
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _0201FE48 @ =0x02033680
	mov r4, ip
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r1, [r2]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrb r0, [r1, #6]
	cmp r0, #0xff
	bne _0201FE4C
	movs r0, #0
	strb r0, [r2]
	cmp r5, #1
	bne _0201FE4C
	movs r0, #1
	b _0201FE66
	.align 2, 0
_0201FE44: .4byte 0x030041A0
_0201FE48: .4byte 0x02033680
_0201FE4C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r1, [r2]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrh r1, [r1, #4]
	mov r0, ip
	adds r0, #0x8a
	strb r1, [r0]
_0201FE64:
	movs r0, #0
_0201FE66:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0201FE6C
sub_0201FE6C: @ 0x0201FE6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0201FED0 @ =0x030041A0
	mov ip, r1
	lsls r2, r0, #1
	mov r4, ip
	adds r4, #0x5a
	adds r1, r2, r4
	movs r3, #0
	strh r3, [r1]
	mov r1, ip
	adds r1, #0x64
	adds r2, r2, r1
	strh r3, [r2]
	adds r1, r0, #0
	cmp r1, #3
	bgt _0201FEC6
	mov r8, r4
_0201FE92:
	lsls r2, r1, #1
	mov r0, r8
	adds r6, r0, r2
	ldrh r0, [r6]
	adds r7, r1, #1
	cmp r0, #0
	bne _0201FEC0
	mov r4, ip
	adds r4, #0x64
	adds r5, r4, r2
	ldrh r3, [r5]
	cmp r3, #0
	bne _0201FEC0
	lsls r1, r7, #1
	mov r0, r8
	adds r2, r0, r1
	ldrh r0, [r2]
	strh r0, [r6]
	adds r1, r4, r1
	ldrh r0, [r1]
	strh r0, [r5]
	strh r3, [r2]
	strh r3, [r1]
_0201FEC0:
	adds r1, r7, #0
	cmp r1, #3
	ble _0201FE92
_0201FEC6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0201FED0: .4byte 0x030041A0

	thumb_func_start sub_0201FED4
sub_0201FED4: @ 0x0201FED4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r5, _0201FF28 @ =0x030041A0
	ldr r1, _0201FF2C @ =0x03003710
	movs r3, #3
_0201FEE4:
	adds r0, r1, r3
	ldr r4, _0201FF30 @ =0x0000041A
	adds r2, r0, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _0201FF38
	movs r0, #0x54
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, _0201FF34 @ =0x03004790
	adds r4, r1, r0
	movs r0, #1
	strb r0, [r2]
	adds r0, r3, #0
	bl sub_02024F08
	adds r0, r4, #0
	adds r0, #0x40
	strh r6, [r0]
	adds r0, #0xb
	strb r7, [r0]
	adds r1, r4, #0
	adds r1, #0x4e
	movs r0, #5
	strb r0, [r1]
	ldr r0, [r5]
	asrs r0, r0, #8
	str r0, [r4]
	ldr r0, [r5, #4]
	asrs r0, r0, #8
	str r0, [r4, #4]
	movs r0, #1
	b _0201FF40
	.align 2, 0
_0201FF28: .4byte 0x030041A0
_0201FF2C: .4byte 0x03003710
_0201FF30: .4byte 0x0000041A
_0201FF34: .4byte 0x03004790
_0201FF38:
	adds r3, #1
	cmp r3, #0xb
	ble _0201FEE4
	movs r0, #0
_0201FF40:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0201FF48
sub_0201FF48: @ 0x0201FF48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #4]
	ldr r7, _0201FFA4 @ =0x030041A0
	ldr r0, _0201FFA8 @ =0x03003710
	mov sl, r0
	cmp r1, #0
	bne _02020018
	ldr r0, [r7]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0201FFB8
	adds r2, r7, #0
	adds r2, #0x8e
	ldrb r0, [r2]
	lsls r0, r0, #1
	mov r1, sl
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r3, [r0]
	ldr r0, _0201FFAC @ =0x00000FFF
	cmp r3, r0
	beq _0201FFA0
	ldr r0, _0201FFB0 @ =0x00003333
	cmp r3, r0
	beq _0201FFA0
	b _02020104
_0201FFA0:
	ldr r4, _0201FFB4 @ =0x0600A000
	b _0201FFDA
	.align 2, 0
_0201FFA4: .4byte 0x030041A0
_0201FFA8: .4byte 0x03003710
_0201FFAC: .4byte 0x00000FFF
_0201FFB0: .4byte 0x00003333
_0201FFB4: .4byte 0x0600A000
_0201FFB8:
	adds r2, r7, #0
	adds r2, #0x8e
	ldrb r0, [r2]
	lsls r0, r0, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
	adds r0, r0, r1
	ldrh r3, [r0]
	ldr r0, _02020074 @ =0x00000FFF
	cmp r3, r0
	beq _0201FFD8
	ldr r0, _02020078 @ =0x00003333
	cmp r3, r0
	beq _0201FFD8
	b _02020104
_0201FFD8:
	ldr r4, _0202007C @ =0x0600A800
_0201FFDA:
	ldrb r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	bl sub_0201F6DC
	cmp r0, #0
	beq _0201FFFA
	b _02020104
_0201FFFA:
	ldrh r0, [r4]
	ldr r2, _02020080 @ =0x000003FF
	ands r2, r0
	adds r1, r2, #0
	cmp r1, #5
	bhi _02020008
	b _02020104
_02020008:
	adds r0, r2, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _02020104
	cmp r1, #0xaf
	bhi _02020104
_02020018:
	mov r1, sb
	cmp r1, #2
	bne _02020022
	movs r2, #0
	mov sb, r2
_02020022:
	movs r6, #3
	movs r5, #6
_02020026:
	ldr r0, _02020084 @ =0x00000417
	add r0, sl
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _020200FC
	movs r0, #0x54
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, _02020088 @ =0x03004790
	adds r4, r1, r0
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #2
	ldr r1, _0202008C @ =0x0202F7FC
	adds r3, r0, r1
	adds r0, r6, #0
	str r3, [sp, #8]
	bl sub_02024F08
	ldr r0, [r7]
	asrs r0, r0, #8
	subs r0, #8
	str r0, [r4]
	ldr r0, [r7, #4]
	asrs r0, r0, #8
	subs r0, #0x10
	str r0, [r4, #4]
	ldr r3, [sp, #8]
	mov r2, sb
	cmp r2, #0
	bne _02020090
	adds r1, r4, #0
	adds r1, #0x4e
	movs r0, #7
	strb r0, [r1]
	b _0202009E
	.align 2, 0
_02020074: .4byte 0x00000FFF
_02020078: .4byte 0x00003333
_0202007C: .4byte 0x0600A800
_02020080: .4byte 0x000003FF
_02020084: .4byte 0x00000417
_02020088: .4byte 0x03004790
_0202008C: .4byte 0x0202F7FC
_02020090:
	adds r1, r4, #0
	adds r1, #0x4e
	movs r0, #9
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x9e
	strb r6, [r0]
_0202009E:
	ldr r0, _020200F4 @ =0x00000417
	add r0, sl
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	movs r5, #0
	mov r0, r8
	strh r0, [r4, #0x28]
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r4, #0x32]
	adds r0, r4, #0
	adds r0, #0x4a
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0]
	adds r0, r7, #0
	adds r0, #0x8e
	ldrb r2, [r0]
	strh r2, [r4, #0x3c]
	ldr r0, [r7]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _020200DC
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r2, r0
	strh r2, [r4, #0x3c]
_020200DC:
	ldrh r0, [r3, #4]
	ldr r2, _020200F8 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #0x3e]
	ldrh r0, [r3, #4]
	lsrs r0, r0, #0xc
	adds r1, r4, #0
	adds r1, #0x50
	strb r0, [r1]
	adds r0, r6, #0
	b _02020106
	.align 2, 0
_020200F4: .4byte 0x00000417
_020200F8: .4byte 0x000003FF
_020200FC:
	adds r5, #1
	adds r6, #1
	cmp r6, #0xb
	ble _02020026
_02020104:
	movs r0, #0
_02020106:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02020118
sub_02020118: @ 0x02020118
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r3, _02020130 @ =0x030041A0
	str r1, [r3, #0x30]
	str r2, [r3, #0x34]
	cmp r1, #0
	bne _02020134
	cmp r2, #0
	bne _02020134
	movs r0, #0
	b _02020296
	.align 2, 0
_02020130: .4byte 0x030041A0
_02020134:
	ldrh r1, [r4, #0xe]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x6e
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _020201B6
	ldr r0, [r3, #0x34]
	cmp r0, #0
	beq _020201B6
	movs r0, #0x99
	adds r0, r0, r3
	mov ip, r0
	movs r6, #0
	adds r2, r3, #0
	adds r2, #0x28
	adds r4, r3, #0
	adds r4, #0x30
	movs r5, #1
_0202016A:
	ldr r1, [r4]
	ldr r0, [r3]
	subs r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bge _02020178
	str r6, [r2]
_02020178:
	adds r2, #4
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _0202016A
	ldr r0, [r3, #0x30]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r3, #0x10]
	movs r2, #0
	movs r0, #0x40
	mov r1, ip
	strb r0, [r1]
	ldr r1, [r3, #0x28]
	ldr r0, [r3, #0x2c]
	cmp r1, r0
	ble _020201B0
	ldr r0, [r3, #0x34]
	str r0, [r3, #0x10]
	movs r0, #0x30
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r3, #0x34]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r3, #0x10]
_020201B0:
	str r2, [r3, #0x18]
	str r2, [r3, #0x1c]
	b _02020294
_020201B6:
	ldr r0, [r3, #0x30]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x99
	movs r6, #0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, [r3, #0x34]
	cmp r0, #0
	beq _020201E0
	str r0, [r3, #0x10]
	movs r0, #0x30
	strb r0, [r1]
	ldr r0, [r3, #0x34]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r3, #0x10]
_020201E0:
	ldr r0, [r3, #0x10]
	str r0, [r3, #0x18]
	ldr r1, [r3, #0x14]
	str r1, [r3, #0x1c]
	ldr r1, [r3]
	subs r0, r0, r1
	str r0, [r3, #0x10]
	cmp r0, #0
	bge _020201F6
	rsbs r0, r0, #0
	str r0, [r3, #0x10]
_020201F6:
	ldr r2, [r3, #0x1c]
	ldr r0, [r3, #4]
	subs r1, r2, r0
	str r1, [r3, #0x14]
	adds r5, r0, #0
	cmp r1, #0
	bge _02020208
	rsbs r0, r1, #0
	str r0, [r3, #0x14]
_02020208:
	ldr r0, [r3, #0x10]
	ldr r1, _02020224 @ =0x00000FFF
	cmp r0, r1
	bgt _02020228
	ldr r0, [r3, #0x14]
	cmp r0, r1
	bgt _02020228
	ldr r0, [r3, #0x18]
	str r0, [r3, #0x10]
	str r2, [r3, #0x14]
	str r6, [r3, #0x18]
	str r6, [r3, #0x1c]
	b _02020294
	.align 2, 0
_02020224: .4byte 0x00000FFF
_02020228:
	movs r0, #0
	str r0, [r3, #0x10]
	str r0, [r3, #0x14]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0202023E
	movs r0, #0x80
	lsls r0, r0, #9
	str r0, [r3, #0x10]
_0202023E:
	ldr r0, [r4, #4]
	lsls r0, r0, #8
	cmp r0, r5
	ble _02020270
	ldrb r0, [r4, #0xe]
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #0xc
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	movs r0, #0xf0
	ands r4, r0
	lsls r0, r4, #8
	ldr r1, _0202026C @ =0x0FFFF400
	adds r0, r0, r1
	b _02020292
	.align 2, 0
_0202026C: .4byte 0x0FFFF400
_02020270:
	ldrb r0, [r4, #0xe]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #0xc
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	movs r0, #0xf0
	ands r4, r0
	lsls r0, r4, #8
	adds r0, r0, r2
_02020292:
	str r0, [r3, #0x14]
_02020294:
	movs r0, #1
_02020296:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0202029C
sub_0202029C: @ 0x0202029C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	ldr r0, _02020350 @ =0x030041A0
	mov ip, r0
	ldr r1, _02020354 @ =0x03003710
	mov sl, r1
	ldr r2, [sp, #0xc]
	ldrh r2, [r2, #0xe]
	mov sb, r2
	movs r7, #0xf
	mov r3, sb
	ands r7, r3
	adds r6, r7, #1
	str r6, [r0, #0x28]
	lsls r1, r6, #0xc
	str r1, [r0, #0x30]
	ldr r0, [sp, #0xc]
	adds r0, #0x24
	ldrb r2, [r0]
	cmp r2, #0
	bne _02020360
	ldr r5, _02020358 @ =0x0600A000
	mov r8, r5
	str r5, [sp, #4]
	mov r0, sp
	movs r5, #0xf0
	adds r1, r5, #0
	ands r1, r3
	adds r1, r1, r6
	lsls r1, r1, #1
	mov r7, sl
	adds r7, #0x10
	adds r1, r1, r7
	ldrh r1, [r1]
	strh r1, [r0]
	mov r4, sb
	cmp r6, #0x10
	bne _02020316
	mov r0, ip
	str r2, [r0, #0x28]
	ldr r0, _0202035C @ =0x0600A800
	str r0, [sp, #4]
	mov r2, sp
	adds r0, r5, #0
	ands r0, r4
	lsls r0, r0, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #9
	mov r1, ip
	str r0, [r1, #0x30]
_02020316:
	adds r0, r5, #0
	ands r0, r4
	mov r2, ip
	ldr r1, [r2, #0x28]
	adds r0, r0, r1
	str r0, [r2, #0x28]
	ldr r0, [sp, #0xc]
	ldrh r3, [r0, #0xe]
	movs r0, #0xf
	ands r0, r3
	subs r0, #1
	str r0, [r2, #0x2c]
	lsls r1, r0, #0xc
	str r1, [r2, #0x34]
	add r4, sp, #4
	mov r1, r8
	str r1, [r4, #4]
	mov r2, sp
	adds r1, r5, #0
	ands r1, r3
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r2, #2]
	mov r2, ip
	str r1, [r2, #0x2c]
	b _020203E6
	.align 2, 0
_02020350: .4byte 0x030041A0
_02020354: .4byte 0x03003710
_02020358: .4byte 0x0600A000
_0202035C: .4byte 0x0600A800
_02020360:
	movs r2, #0x80
	lsls r2, r2, #9
	orrs r1, r2
	mov r3, ip
	str r1, [r3, #0x30]
	str r2, [r3, #0x34]
	ldr r5, _02020470 @ =0x0600A800
	str r5, [sp, #4]
	mov r3, sp
	movs r0, #0xf0
	mov r1, sb
	ands r1, r0
	mov r8, r1
	adds r1, r1, r6
	lsls r0, r1, #1
	movs r4, #0x84
	lsls r4, r4, #2
	add r4, sl
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r3]
	mov r3, ip
	str r1, [r3, #0x28]
	subs r1, r7, #1
	str r1, [r3, #0x2c]
	lsls r0, r1, #0xc
	orrs r0, r2
	str r0, [r3, #0x34]
	add r3, sp, #4
	str r5, [r3, #4]
	mov r2, sp
	mov r5, r8
	adds r0, r5, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r1, r0
	mov r4, sb
	cmp r1, #0xff
	bne _020203DE
	movs r0, #0xf
	mov r1, ip
	str r0, [r1, #0x2c]
	movs r0, #0
	str r0, [r1, #0x34]
	ldr r0, _02020474 @ =0x0600A000
	str r0, [sp, #8]
	mov r3, sp
	movs r0, #0xf0
	ands r0, r4
	ldr r2, [r1, #0x2c]
	adds r0, r0, r2
	lsls r0, r0, #1
	mov r1, sl
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #2]
	lsls r2, r2, #0xc
	mov r3, ip
	str r2, [r3, #0x34]
_020203DE:
	mov r5, ip
	ldr r0, [r5, #0x2c]
	add r0, r8
	str r0, [r5, #0x2c]
_020203E6:
	movs r0, #0x28
	add r0, ip
	mov sl, r0
	movs r1, #0
	mov sb, r1
	movs r7, #0
	mov r6, sp
	mov r5, ip
	adds r5, #0x30
	movs r2, #1
	mov r8, r2
_020203FC:
	adds r3, r7, #0
	add r3, sp
	adds r3, #4
	mov r0, sl
	adds r4, r0, r7
	ldr r1, [r4]
	movs r0, #0xf0
	ands r1, r0
	lsls r1, r1, #3
	ldr r2, [r3]
	adds r2, r2, r1
	str r2, [r3]
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	str r2, [r3]
	ldrh r1, [r2]
	ldr r0, _02020478 @ =0x000003FF
	ands r0, r1
	cmp r0, #0x7f
	bls _0202042E
	mov r1, sb
	str r1, [r5]
_0202042E:
	ldrh r0, [r6]
	ldr r2, _0202047C @ =0x00007777
	cmp r0, r2
	beq _0202043E
	cmp r0, #0x1f
	beq _0202043E
	cmp r0, #0x20
	bne _02020442
_0202043E:
	mov r3, sb
	str r3, [r5]
_02020442:
	adds r7, #4
	adds r6, #2
	adds r5, #4
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _020203FC
	mov r2, ip
	ldr r1, [r2, #0x30]
	ldr r2, [r2, #0x34]
	ldr r0, [sp, #0xc]
	bl sub_02020118
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_02020470: .4byte 0x0600A800
_02020474: .4byte 0x0600A000
_02020478: .4byte 0x000003FF
_0202047C: .4byte 0x00007777

	thumb_func_start sub_02020480
sub_02020480: @ 0x02020480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _020204A4 @ =0x030041A0
	ldr r0, _020204A8 @ =0x03003710
	mov sb, r0
	adds r0, r5, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _020204AC
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	b _020205D2
	.align 2, 0
_020204A4: .4byte 0x030041A0
_020204A8: .4byte 0x03003710
_020204AC:
	bl sub_0202086C
	adds r2, r0, #0
	cmp r2, #0
	bne _020204BE
	adds r0, r5, #0
	adds r0, #0xb5
	strb r2, [r0]
	b _020205D0
_020204BE:
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq _020204D6
	cmp r1, #2
	beq _020204D6
	cmp r1, #6
	beq _020204D6
	b _020205D0
_020204D6:
	movs r6, #0
	movs r1, #0xb5
	adds r1, r1, r5
	mov sl, r1
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r1, r5, #0
	adds r1, #0x50
	adds r1, r1, r0
	mov r8, r1
	ldr r2, _02020534 @ =0x03003C00
	mov ip, r2
	movs r4, #0
	ldr r3, _02020538 @ =0x0000044D
	add r3, sb
_020204F6:
	ldrb r0, [r3]
	cmp r0, #1
	bne _0202051E
	mov r7, ip
	adds r1, r4, r7
	ldrh r0, [r1, #0xe]
	mov r2, r8
	ldrh r2, [r2]
	cmp r0, r2
	bne _0202051E
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r2, [r0]
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	asrs r0, r0, #0x10
	cmp r2, r0
	beq _02020528
_0202051E:
	adds r4, #0x30
	adds r3, #1
	adds r6, #1
	cmp r6, #0x1d
	ble _020204F6
_02020528:
	cmp r6, #0x1e
	bne _0202053C
	movs r0, #0
	mov r7, sl
	strb r0, [r7]
	b _020205D2
	.align 2, 0
_02020534: .4byte 0x03003C00
_02020538: .4byte 0x0000044D
_0202053C:
	mov r0, sl
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _020205D0
	adds r0, r5, #0
	adds r0, #0x90
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0xa1
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _02020578 @ =0x020338D2
	adds r0, r0, r1
	ldrb r4, [r0]
	ldr r0, _0202057C @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r4, r0
	bge _02020580
	movs r0, #1
	mov r1, sl
	strb r0, [r1]
	b _020205D0
	.align 2, 0
_02020578: .4byte 0x020338D2
_0202057C: .4byte 0x03001B50
_02020580:
	adds r1, r5, #0
	adds r1, #0x9b
	strb r6, [r1]
	adds r0, r5, #0
	adds r0, #0x6e
	mov r2, r8
	strh r2, [r0]
	ldrb r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _020205C0 @ =0x03003C00
	adds r1, r1, r0
	adds r0, r1, #0
	bl sub_0202029C
	cmp r0, #0
	beq _020205C4
	adds r0, r5, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
	movs r0, #1
	b _020205D2
	.align 2, 0
_020205C0: .4byte 0x03003C00
_020205C4:
	str r0, [r5, #0x10]
	str r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x7e
	movs r0, #0x50
	strh r0, [r1]
_020205D0:
	movs r0, #0
_020205D2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_020205E0
sub_020205E0: @ 0x020205E0
	push {r4, r5, r6, lr}
	ldr r4, _02020634 @ =0x030041A0
	ldr r6, _02020638 @ =0x03003710
	adds r3, r4, #0
	adds r3, #0x8b
	ldrb r1, [r3]
	lsls r1, r1, #3
	ldr r0, _0202063C @ =0x02033A84
	adds r1, r1, r0
	ldr r2, [r4]
	ldr r0, [r1]
	adds r2, r2, r0
	str r2, [r4]
	ldr r0, [r4, #4]
	ldr r1, [r1, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	adds r1, r4, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	cmp r0, #0
	beq _02020644
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #8]
	ldr r3, _02020640 @ =0x000FFF00
	ands r0, r3
	adds r1, r3, #0
	ands r1, r2
	cmp r0, r1
	beq _02020620
	str r1, [r4, #8]
_02020620:
	ldr r0, [r4, #0xc]
	ands r0, r3
	ldr r1, [r4, #4]
	ands r1, r3
	cmp r0, r1
	bne _0202062E
	b _02020788
_0202062E:
	str r1, [r4, #0xc]
	b _02020788
	.align 2, 0
_02020634: .4byte 0x030041A0
_02020638: .4byte 0x03003710
_0202063C: .4byte 0x02033A84
_02020640: .4byte 0x000FFF00
_02020644:
	ldrb r0, [r3]
	bl sub_0201F538
	movs r2, #0
	movs r5, #0
	b _02020652
_02020650:
	adds r5, #1
_02020652:
	cmp r5, #3
	bgt _0202066C
	lsls r1, r5, #1
	adds r0, r4, #0
	adds r0, #0x48
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #0x44]
	bl sub_0201F6DC
	adds r2, r0, #0
	cmp r2, #0
	beq _02020650
_0202066C:
	cmp r5, #4
	bne _020206BC
	ldr r0, [r4, #8]
	ldr r2, _020206B8 @ =0x000FFF00
	ands r0, r2
	ldr r1, [r4]
	ands r1, r2
	cmp r0, r1
	beq _02020680
	str r1, [r4, #8]
_02020680:
	ldr r0, [r4, #0xc]
	ands r0, r2
	ldr r1, [r4, #4]
	ands r1, r2
	cmp r0, r1
	beq _0202068E
	str r1, [r4, #0xc]
_0202068E:
	adds r0, r4, #0
	adds r0, #0xb5
	movs r2, #0
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0xb2
	ldrb r0, [r3]
	cmp r0, #0
	beq _02020788
	adds r1, r4, #0
	adds r1, #0xb3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _02020788
	strb r2, [r3]
	strb r2, [r1]
	b _02020788
	.align 2, 0
_020206B8: .4byte 0x000FFF00
_020206BC:
	cmp r2, #1
	bne _020206F2
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _020206EA
	ldr r1, _02020734 @ =0x0000049A
	adds r0, r6, r1
	adds r1, r4, #0
	adds r1, #0x8e
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _020206EA
	ldr r0, _02020738 @ =0x03004B80
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r0, #1
	beq _02020740
_020206EA:
	bl sub_02020480
	cmp r0, #0
	bne _02020788
_020206F2:
	ldr r0, [r4, #8]
	str r0, [r4]
	ldr r0, [r4, #0xc]
	str r0, [r4, #4]
	movs r0, #1
	bl sub_0201F78C
	adds r2, r0, #0
	movs r0, #0
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0xb2
	ldrb r0, [r1]
	adds r3, r0, #1
	strb r3, [r1]
	ldr r0, _0202073C @ =0x00000777
	cmp r2, r0
	beq _02020778
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _02020778
	adds r0, r4, #0
	adds r0, #0x8b
	strb r2, [r0]
	subs r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _02020788
	.align 2, 0
_02020734: .4byte 0x0000049A
_02020738: .4byte 0x03004B80
_0202073C: .4byte 0x00000777
_02020740:
	ldr r1, _02020774 @ =0x03003BC4
	ldr r0, [r1]
	lsls r0, r0, #8
	str r0, [r4, #0x10]
	ldr r0, [r1, #4]
	lsls r0, r0, #8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x99
	movs r1, #0
	movs r0, #0x20
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x6e
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
	b _02020788
	.align 2, 0
_02020774: .4byte 0x03003BC4
_02020778:
	movs r0, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #0x13
	strb r0, [r1]
	bl sub_020236D0
_02020788:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02020790
sub_02020790: @ 0x02020790
	push {lr}
	ldr r3, _020207BC @ =0x030041A0
	adds r0, r3, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #4
	bls _020207A8
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_020207A8:
	adds r2, r3, #0
	adds r2, #0x8b
	lsls r0, r1, #3
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x88
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_020207BC: .4byte 0x030041A0

	thumb_func_start sub_020207C0
sub_020207C0: @ 0x020207C0
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r6, r5, #0
	ldr r1, _020207F4 @ =0x030041A0
	ldr r3, [r1]
	subs r2, r4, r3
	cmp r2, #0
	bge _020207D6
	rsbs r2, r2, #0
_020207D6:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	ble _0202080C
	cmp r4, r3
	ble _020207F8
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r1]
	cmp r5, #0
	bne _02020808
	adds r1, #0x8b
	movs r0, #6
	b _02020806
	.align 2, 0
_020207F4: .4byte 0x030041A0
_020207F8:
	adds r0, r3, #0
	subs r0, #0x40
	str r0, [r1]
	cmp r6, #0
	bne _02020808
	adds r1, #0x8b
	movs r0, #2
_02020806:
	strb r0, [r1]
_02020808:
	movs r0, #0
	b _0202080E
_0202080C:
	movs r0, #1
_0202080E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_02020814
sub_02020814: @ 0x02020814
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r6, r1, #0
	ldr r4, _02020848 @ =0x030041A0
	ldr r3, [r4, #4]
	subs r2, r5, r3
	cmp r2, #0
	bge _0202082A
	rsbs r2, r2, #0
_0202082A:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	ble _02020862
	cmp r5, r3
	ble _0202084C
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r4, #4]
	cmp r1, #0
	bne _0202085E
	adds r0, r4, #0
	adds r0, #0x8b
	strb r1, [r0]
	b _0202085E
	.align 2, 0
_02020848: .4byte 0x030041A0
_0202084C:
	adds r0, r3, #0
	subs r0, #0x40
	str r0, [r4, #4]
	cmp r6, #0
	bne _0202085E
	adds r1, r4, #0
	adds r1, #0x8b
	movs r0, #4
	strb r0, [r1]
_0202085E:
	movs r0, #0
	b _02020864
_02020862:
	movs r0, #1
_02020864:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0202086C
sub_0202086C: @ 0x0202086C
	push {lr}
	ldr r3, _020208AC @ =0x030041A0
	movs r2, #0
_02020872:
	lsls r0, r2, #1
	adds r1, r3, #0
	adds r1, #0x48
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r1, #0
	subs r0, #0x22
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _020208A4
	adds r0, r1, #0
	subs r0, #0x27
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _020208A4
	adds r0, r1, #0
	subs r0, #0x31
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _020208A4
	cmp r1, #0x36
	bne _020208B0
_020208A4:
	adds r2, #1
	adds r0, r2, #0
	b _020208B8
	.align 2, 0
_020208AC: .4byte 0x030041A0
_020208B0:
	adds r2, #1
	cmp r2, #3
	ble _02020872
	movs r0, #0
_020208B8:
	pop {r1}
	bx r1

	thumb_func_start sub_020208BC
sub_020208BC: @ 0x020208BC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	ldr r4, _02020920 @ =0x030041A0
	ldr r6, _02020924 @ =0x03003710
	ldr r1, _02020928 @ =0x03001B40
	ldr r2, [r1]
	adds r5, r4, #0
	adds r5, #0x8e
	ldrb r3, [r5]
	lsrs r1, r3, #4
	lsls r1, r1, #1
	lsrs r0, r0, #0x13
	adds r1, r1, r0
	ldr r0, _0202092C @ =0x000018F8
	adds r2, r2, r0
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r3
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _020209D8
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #0
	bne _020209D4
	adds r0, r4, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #3
	beq _0202090A
	cmp r1, #7
	bne _020209D4
_0202090A:
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02020930
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x10
	b _0202093A
	.align 2, 0
_02020920: .4byte 0x030041A0
_02020924: .4byte 0x03003710
_02020928: .4byte 0x03001B40
_0202092C: .4byte 0x000018F8
_02020930:
	ldrb r0, [r5]
	lsls r0, r0, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r6, r2
_0202093A:
	adds r0, r0, r1
	ldrh r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r1, _020209C0 @ =0x0202F7FC
	adds r2, r0, r1
	ldr r5, _020209C4 @ =0x00000FFF
	cmp r3, r5
	beq _020209D4
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _020209D4
	ldr r0, _020209C8 @ =0x00003333
	cmp r3, r0
	beq _020209D4
	ldr r0, _020209CC @ =0x00007777
	cmp r3, r0
	beq _020209D4
	ldrh r0, [r2, #8]
	cmp r0, r5
	beq _020209D4
	movs r5, #0x32
	adds r0, r4, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #1
	bne _02020980
	movs r5, #0x19
_02020980:
	ldr r0, _020209D0 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r5, r0
	blt _020209D4
	movs r0, #0xf1
	bl sub_0201F0FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _020209D4
	ldr r0, [r4, #0x10]
	str r0, [r4, #8]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0xc]
	adds r0, r4, #0
	adds r0, #0x7c
	strh r6, [r0]
	adds r1, r4, #0
	adds r1, #0x6e
	movs r0, #2
	strh r0, [r1]
	adds r1, #0x19
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
	movs r0, #2
	b _020209DA
	.align 2, 0
_020209C0: .4byte 0x0202F7FC
_020209C4: .4byte 0x00000FFF
_020209C8: .4byte 0x00003333
_020209CC: .4byte 0x00007777
_020209D0: .4byte 0x03001B50
_020209D4:
	movs r0, #1
	b _020209DA
_020209D8:
	movs r0, #0
_020209DA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_020209E0
sub_020209E0: @ 0x020209E0
	push {lr}
	ldr r1, _02020A04 @ =0x030041A0
	ldr r2, _02020A08 @ =0x020338C4
	adds r0, r1, #0
	adds r0, #0x93
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #0x90
	strb r0, [r1]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_02026C7C
	pop {r0}
	bx r0
	.align 2, 0
_02020A04: .4byte 0x030041A0
_02020A08: .4byte 0x020338C4

	thumb_func_start sub_02020A0C
sub_02020A0C: @ 0x02020A0C
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r1, [r0]
	adds r0, #2
	adds r2, r1, #1
	strh r2, [r0]
	adds r0, #0x3e
	adds r2, r1, #2
	strh r2, [r0]
	adds r1, #3
	strh r1, [r0, #2]
	bx lr

	thumb_func_start sub_02020A24
sub_02020A24: @ 0x02020A24
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _02020A64 @ =0x030041A0
	subs r0, r4, #3
	cmp r0, #4
	bls _02020A34
	cmp r4, #0x1e
	bne _02020A70
_02020A34:
	adds r1, #0x7c
	ldr r0, _02020A68 @ =0x00003260
	strh r0, [r1]
	cmp r4, #0x1e
	bne _02020A42
	adds r0, #8
	strh r0, [r1]
_02020A42:
	movs r3, #0
	ldr r1, _02020A6C @ =0x02033A6C
	ldrh r0, [r1]
	cmp r0, r4
	beq _02020A5E
	adds r2, r1, #0
_02020A4E:
	adds r2, #4
	adds r3, #1
	cmp r3, #5
	bgt _02020A5E
	adds r1, r2, #0
	ldrh r0, [r1]
	cmp r0, r4
	bne _02020A4E
_02020A5E:
	ldrh r0, [r1, #2]
	b _02020A72
	.align 2, 0
_02020A64: .4byte 0x030041A0
_02020A68: .4byte 0x00003260
_02020A6C: .4byte 0x02033A6C
_02020A70:
	movs r0, #0
_02020A72:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_02020A78
sub_02020A78: @ 0x02020A78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _02020AE8 @ =0x030041A0
	ldr r7, _02020AEC @ =0x03003710
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r1, r5, #0
	cmp r5, #4
	bls _02020A9C
	subs r0, r5, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_02020A9C:
	lsls r0, r5, #0x11
	ldr r2, _02020AF0 @ =0x80430000
	adds r0, r0, r2
	lsrs r5, r0, #0x10
	cmp r1, #4
	bls _02020AAE
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_02020AAE:
	bl sub_0201F368
	cmp r0, #0
	beq _02020B7C
	adds r0, r6, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	bl sub_0201F538
	adds r4, r6, #0
	adds r4, #0x8e
	ldrb r0, [r4]
	ldr r1, [r6, #0x44]
	bl sub_0201F6DC
	adds r2, r0, #0
	ldr r0, [r6]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02020AF4
	cmp r2, #0
	bne _02020B12
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x10
	b _02020B02
	.align 2, 0
_02020AE8: .4byte 0x030041A0
_02020AEC: .4byte 0x03003710
_02020AF0: .4byte 0x80430000
_02020AF4:
	cmp r2, #0
	bne _02020B12
	ldrb r0, [r4]
	lsls r0, r0, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r7, r2
_02020B02:
	adds r2, r0, r1
	ldrh r1, [r2]
	ldr r0, _02020B44 @ =0x00000FFF
	cmp r1, r0
	bne _02020B12
	strh r5, [r2]
	movs r5, #1
	mov r8, r5
_02020B12:
	mov r0, r8
	cmp r0, #1
	bne _02020B7C
	ldr r0, [r6]
	ldrb r1, [r4]
	adds r4, r6, #0
	adds r4, #0x72
	ldrh r2, [r4]
	ldr r3, _02020B48 @ =0x00006234
	bl sub_0201F660
	adds r0, r6, #0
	adds r0, #0x85
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _02020B4C
	adds r2, r6, #0
	adds r2, #0x86
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x10
	b _02020B5A
	.align 2, 0
_02020B44: .4byte 0x00000FFF
_02020B48: .4byte 0x00006234
_02020B4C:
	adds r2, r6, #0
	adds r2, #0x86
	ldrb r0, [r2]
	lsls r0, r0, #1
	movs r5, #0x84
	lsls r5, r5, #2
	adds r1, r7, r5
_02020B5A:
	adds r1, r1, r0
	ldr r0, _02020B78 @ =0x00000FFF
	strh r0, [r1]
	movs r0, #0
	strb r0, [r2]
	strb r0, [r3]
	adds r1, r6, #0
	adds r1, #0x8d
	strb r0, [r1]
	strh r0, [r4]
	bl sub_02020790
	movs r0, #1
	b _02020B7E
	.align 2, 0
_02020B78: .4byte 0x00000FFF
_02020B7C:
	movs r0, #0
_02020B7E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_02020B88
sub_02020B88: @ 0x02020B88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _02020D0C @ =0x030041A0
	movs r2, #0
	str r2, [r4]
	str r2, [r4, #4]
	str r2, [r4, #8]
	str r2, [r4, #0xc]
	str r2, [r4, #0x10]
	str r2, [r4, #0x14]
	str r2, [r4, #0x18]
	str r2, [r4, #0x1c]
	str r2, [r4, #0x38]
	str r2, [r4, #0x3c]
	str r2, [r4, #0x20]
	str r2, [r4, #0x24]
	adds r3, r4, #0
	adds r3, #0x48
	movs r0, #0
	strh r2, [r3]
	str r2, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x85
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	str r2, [r4, #0x40]
	subs r1, #0x2e
	strh r2, [r1]
	adds r1, #0x2f
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #0x1b
	strh r2, [r1]
	adds r1, #0x1c
	strb r0, [r1]
	subs r1, #0x14
	strh r2, [r1]
	adds r1, #0x15
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r5, r4, #0
	adds r5, #0x96
	strb r0, [r5]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #0x2d
	strh r2, [r1]
	adds r1, #2
	strh r2, [r1]
	adds r1, #0x2c
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #0x29
	strh r2, [r1]
	adds r1, #0x2a
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #0x23
	strh r2, [r1]
	adds r1, #4
	strh r2, [r1]
	adds r1, #4
	strb r0, [r1]
	adds r1, #0x1c
	strb r0, [r1]
	adds r6, r4, #0
	adds r6, #0xa1
	strb r0, [r6]
	subs r1, #0x1e
	strh r2, [r1]
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #2
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	subs r1, #0x40
	movs r0, #0x78
	strh r0, [r1]
	subs r1, #2
	ldr r0, _02020D10 @ =0x00002A30
	strh r0, [r1]
	ldr r0, _02020D14 @ =0x03001B40
	ldr r0, [r0]
	ldr r1, _02020D18 @ =0x00001944
	adds r0, r0, r1
	ldr r0, [r0]
	strb r0, [r5]
	ldr r1, _02020D1C @ =0x02033F92
	ldrb r0, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	movs r0, #0
	movs r2, #3
_02020C9A:
	strh r0, [r3]
	strh r0, [r3, #8]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _02020C9A
	movs r0, #0x87
	adds r0, r0, r4
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x88
	adds r6, r4, #0
	adds r6, #0x8a
	adds r5, r4, #0
	adds r5, #0x90
	movs r1, #0x93
	adds r1, r1, r4
	mov ip, r1
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x5a
	movs r2, #4
_02020CCA:
	strh r3, [r1]
	strh r3, [r0]
	adds r0, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _02020CCA
	movs r4, #0
	movs r0, #3
	mov r1, ip
	strb r0, [r1]
	bl sub_020209E0
	ldrb r0, [r5]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_02026C7C
	bl sub_02026BD8
	movs r0, #0xfe
	strb r0, [r6]
	movs r0, #0x60
	strb r0, [r7]
	mov r0, r8
	strb r4, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02020D0C: .4byte 0x030041A0
_02020D10: .4byte 0x00002A30
_02020D14: .4byte 0x03001B40
_02020D18: .4byte 0x00001944
_02020D1C: .4byte 0x02033F92

	thumb_func_start sub_02020D20
sub_02020D20: @ 0x02020D20
	push {r4, lr}
	ldr r0, _02020D7C @ =0x030041A0
	mov ip, r0
	ldr r2, _02020D80 @ =0x03003710
	ldr r4, _02020D84 @ =0x03000020
	adds r0, #0x96
	ldrb r0, [r0]
	lsls r1, r0, #3
	subs r1, r1, r0
	str r1, [r4]
	ldr r3, _02020D88 @ =0x02033DC8
	ldr r0, _02020D8C @ =0x00000416
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	str r1, [r4]
	ldr r0, _02020D90 @ =0x02033DE4
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r2, [r1]
	str r2, [r4]
	ldr r1, _02020D94 @ =0x02033DE0
	mov r0, ip
	adds r0, #0x90
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	str r2, [r4]
	mov r0, ip
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #5
	bne _02020D72
	adds r0, r2, #0
	adds r0, #0x14
	str r0, [r4]
_02020D72:
	ldr r0, [r4]
	cmp r0, #0x9f
	ble _02020D98
	movs r0, #0
	b _02020DA2
	.align 2, 0
_02020D7C: .4byte 0x030041A0
_02020D80: .4byte 0x03003710
_02020D84: .4byte 0x03000020
_02020D88: .4byte 0x02033DC8
_02020D8C: .4byte 0x00000416
_02020D90: .4byte 0x02033DE4
_02020D94: .4byte 0x02033DE0
_02020D98:
	cmp r0, #0xa0
	ble _02020DA0
	movs r0, #0
	str r0, [r4]
_02020DA0:
	ldr r0, [r4]
_02020DA2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_02020DA8
sub_02020DA8: @ 0x02020DA8
	push {r4, r5, r6, r7, lr}
	ldr r5, _02020DC8 @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _02020DB8
	b _02020F4C
_02020DB8:
	adds r1, r5, #0
	adds r1, #0x76
	ldrh r0, [r1]
	cmp r0, #0
	beq _02020DCC
	subs r0, #1
	strh r0, [r1]
	b _02020F4C
	.align 2, 0
_02020DC8: .4byte 0x030041A0
_02020DCC:
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _02020EA8
	ldr r0, [r5, #0x38]
	cmp r0, #0
	bne _02020EA8
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _02020EA8
	bl sub_02020D20
	adds r4, r0, #0
	lsls r1, r4, #2
	ldr r0, _02020E28 @ =0x02033B48
	adds r6, r1, r0
	ldrh r2, [r6]
	ldrh r3, [r6, #2]
	movs r0, #0
	movs r1, #1
	bl sub_0201FF48
	adds r4, r0, #0
	cmp r4, #0
	bne _02020E04
	b _02020F4C
_02020E04:
	movs r0, #0x54
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, _02020E2C @ =0x03004790
	adds r4, r1, r0
	ldr r0, _02020E30 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _02020E38
	movs r0, #0x10
	str r0, [r4]
	movs r0, #0x18
	str r0, [r4, #0x18]
	ldr r0, _02020E34 @ =0x000001D1
	b _02020E46
	.align 2, 0
_02020E28: .4byte 0x02033B48
_02020E2C: .4byte 0x03004790
_02020E30: .4byte 0x03001B50
_02020E34: .4byte 0x000001D1
_02020E38:
	movs r0, #0xe8
	lsls r0, r0, #1
	str r0, [r4]
	movs r0, #0x18
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	movs r0, #0xf
_02020E46:
	str r0, [r4, #0x14]
	ldr r0, _02020EA0 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #4
	adds r0, #0x50
	str r0, [r4, #4]
	ldr r0, [r4]
	str r0, [r5, #0x38]
	ldr r0, [r4, #4]
	str r0, [r5, #0x3c]
	adds r6, #4
	adds r7, r4, #0
	adds r7, #0x34
	adds r5, r4, #0
	adds r5, #0x2a
	movs r4, #3
_02020E6E:
	ldrh r1, [r6]
	ldrh r0, [r6, #2]
	cmp r0, #4
	bne _02020E8C
	ldr r0, _02020EA0 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #2
	ldr r1, _02020EA4 @ =0x02033B30
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
_02020E8C:
	strh r1, [r5]
	strh r0, [r7]
	adds r7, #2
	adds r5, #2
	subs r4, #1
	adds r6, #4
	cmp r4, #0
	bge _02020E6E
	b _02020F4C
	.align 2, 0
_02020EA0: .4byte 0x03001B50
_02020EA4: .4byte 0x02033B30
_02020EA8:
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #3
	bne _02020F4C
	ldrh r6, [r2]
	cmp r6, #0
	beq _02020EC4
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strb r0, [r1]
	b _02020F4C
_02020EC4:
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	beq _02020ED6
	cmp r1, #5
	bne _02020F4C
_02020ED6:
	ldr r1, [r5, #0x38]
	ldr r0, [r5]
	subs r2, r1, r0
	str r2, [r5, #0x20]
	ldr r0, [r5, #0x3c]
	ldr r1, [r5, #4]
	subs r0, r0, r1
	str r0, [r5, #0x24]
	cmp r2, #0
	bge _02020EEE
	rsbs r0, r2, #0
	str r0, [r5, #0x20]
_02020EEE:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	bge _02020EF8
	rsbs r0, r0, #0
	str r0, [r5, #0x24]
_02020EF8:
	ldr r0, [r5, #0x20]
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bgt _02020F4C
	ldr r0, [r5, #0x24]
	cmp r0, r1
	bgt _02020F4C
	movs r4, #0x64
	adds r0, r5, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #1
	bne _02020F16
	movs r4, #0x32
_02020F16:
	ldr r0, _02020F38 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r4, r0
	blt _02020F4C
	ldr r1, [r5]
	ldr r0, [r5, #0x38]
	cmp r1, r0
	ble _02020F3C
	adds r0, r5, #0
	adds r0, #0x8b
	strb r6, [r0]
	b _02020F44
	.align 2, 0
_02020F38: .4byte 0x03001B50
_02020F3C:
	adds r1, r5, #0
	adds r1, #0x8b
	movs r0, #1
	strb r0, [r1]
_02020F44:
	movs r0, #0xf
	strb r0, [r7]
	bl sub_02022C30
_02020F4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02020F54
sub_02020F54: @ 0x02020F54
	push {r4, r5, r6, r7, lr}
	ldr r5, _02020F98 @ =0x030041A0
	movs r7, #0
	adds r0, r5, #0
	adds r0, #0x74
	ldrh r0, [r0]
	cmp r0, #0
	bne _02021048
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #4
	beq _02020F76
	cmp r1, #8
	bne _02021048
_02020F76:
	ldr r0, [r5]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02020FA0
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	lsls r0, r0, #0x10
	movs r1, #0xe0
	lsls r1, r1, #0xc
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	ldr r2, _02020F9C @ =0x0600A000
	b _02020FAC
	.align 2, 0
_02020F98: .4byte 0x030041A0
_02020F9C: .4byte 0x0600A000
_02020FA0:
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x12
	ldr r2, _02020FDC @ =0x0600A800
_02020FAC:
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r0, #0xf
	ands r4, r0
	lsls r0, r4, #2
	adds r2, r2, r0
	movs r1, #0
	movs r3, #0
	ldr r6, _02020FE0 @ =0x000003FF
_02020FC2:
	ldrh r0, [r2]
	adds r4, r6, #0
	ands r4, r0
	cmp r4, #0xf6
	bne _02020FCE
	adds r3, #1
_02020FCE:
	cmp r1, #0
	beq _02020FD6
	cmp r1, #2
	bne _02020FE4
_02020FD6:
	adds r2, #2
	b _02020FEA
	.align 2, 0
_02020FDC: .4byte 0x0600A800
_02020FE0: .4byte 0x000003FF
_02020FE4:
	cmp r1, #1
	bne _02020FEA
	adds r2, #0x3e
_02020FEA:
	adds r1, #1
	cmp r1, #3
	ble _02020FC2
	cmp r3, #3
	ble _02020FF6
	movs r7, #1
_02020FF6:
	cmp r7, #0
	beq _02021048
	movs r4, #0x19
	adds r0, r5, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #1
	bne _02021008
	movs r4, #0x32
_02021008:
	ldr r0, _0202102C @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r4, r0
	ble _02021048
	ldr r1, [r5]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _02021030
	adds r0, r5, #0
	adds r0, #0x8b
	strb r1, [r0]
	b _02021038
	.align 2, 0
_0202102C: .4byte 0x03001B50
_02021030:
	adds r1, r5, #0
	adds r1, #0x8b
	movs r0, #1
	strb r0, [r1]
_02021038:
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #0xd
	strb r0, [r1]
	bl sub_0202277C
	movs r0, #1
	b _0202104A
_02021048:
	movs r0, #0
_0202104A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_02021050
sub_02021050: @ 0x02021050
	push {r4, lr}
	ldr r3, _02021088 @ =0x030041A0
	ldr r2, _0202108C @ =0x03003710
	ldr r0, [r3]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02021098
	adds r3, #0x8e
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r1, r2, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _02021090 @ =0x00007777
	strh r1, [r0]
	ldr r0, _02021094 @ =0x03001B40
	ldr r2, [r0]
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #1
	lsrs r1, r1, #4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r2, #0x24
	b _020210C2
	.align 2, 0
_02021088: .4byte 0x030041A0
_0202108C: .4byte 0x03003710
_02021090: .4byte 0x00007777
_02021094: .4byte 0x03001B40
_02021098:
	adds r3, #0x8e
	ldrb r0, [r3]
	lsls r0, r0, #1
	movs r4, #0x84
	lsls r4, r4, #2
	adds r1, r2, r4
	adds r0, r0, r1
	ldr r1, _020210CC @ =0x00007777
	strh r1, [r0]
	ldr r0, _020210D0 @ =0x03001B40
	ldr r2, [r0]
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #1
	lsrs r1, r1, #4
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x89
	lsls r1, r1, #2
	adds r2, r2, r1
_020210C2:
	adds r2, r2, r0
	ldrh r0, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_020210CC: .4byte 0x00007777
_020210D0: .4byte 0x03001B40

	thumb_func_start sub_020210D4
sub_020210D4: @ 0x020210D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0202111C @ =0x030041A0
	ldr r0, _02021120 @ =0x03003710
	mov r8, r0
	movs r1, #0
	mov sl, r1
	adds r0, r4, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq _02021100
	cmp r1, #3
	beq _02021100
	cmp r1, #7
	beq _02021100
	b _020212B8
_02021100:
	ldr r1, [r4]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _02021124
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r1, r1, #1
	mov r0, r8
	adds r0, #0x10
	b _02021132
	.align 2, 0
_0202111C: .4byte 0x030041A0
_02021120: .4byte 0x03003710
_02021124:
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r1, r1, #1
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, r8
_02021132:
	adds r0, r0, r1
	ldrh r6, [r0]
	adds r7, r2, #0
	adds r2, r6, #0
	ldr r3, _02021184 @ =0x00000FFF
	cmp r2, r3
	bne _02021142
	b _020212B8
_02021142:
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _02021152
	b _020212B8
_02021152:
	ldr r0, _02021188 @ =0x00007777
	cmp r2, r0
	bne _0202115A
	b _020212B8
_0202115A:
	ldr r0, _0202118C @ =0x00003333
	cmp r2, r0
	bne _02021162
	b _020212B8
_02021162:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _02021190 @ =0x0202F7FC
	adds r5, r0, r1
	ldrh r0, [r5, #4]
	cmp r0, r3
	bne _02021174
	b _020212B8
_02021174:
	movs r0, #0xff
	lsls r0, r0, #0x10
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	bne _02021194
	movs r0, #0
	b _02021196
	.align 2, 0
_02021184: .4byte 0x00000FFF
_02021188: .4byte 0x00007777
_0202118C: .4byte 0x00003333
_02021190: .4byte 0x0202F7FC
_02021194:
	movs r0, #1
_02021196:
	bl sub_020208BC
	cmp r0, #2
	bne _020211A0
	b _020212E2
_020211A0:
	cmp r0, #1
	bne _020211A6
	b _020212B8
_020211A6:
	adds r0, r4, #0
	adds r0, #0xb6
	movs r1, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x8d
	ldrb r1, [r1]
	movs r2, #0xf
	ands r2, r1
	mov sb, r0
	cmp r2, #3
	beq _020211C2
	cmp r2, #7
	bne _020211DA
_020211C2:
	adds r0, r4, #0
	adds r0, #0x62
	ldrh r0, [r0]
	cmp r0, #0
	bne _020212B8
	ldrh r0, [r5, #8]
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _020212B8
	b _0202122A
_020211DA:
	ldrh r1, [r5, #8]
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _02021234
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _02021220
	bl sub_02021050
	adds r2, r4, #0
	adds r2, #0x72
	movs r1, #0
	strh r0, [r2]
	mov r0, sb
	strb r6, [r0]
	adds r2, #0x14
	strb r1, [r2]
	adds r3, r4, #0
	adds r3, #0x85
	strb r1, [r3]
	ldrb r0, [r7]
	strb r0, [r2]
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _02021240
	movs r0, #1
	strb r0, [r3]
	b _02021234
_02021220:
	adds r0, r4, #0
	adds r0, #0x62
	ldrh r0, [r0]
	cmp r0, #0
	bne _020212B8
_0202122A:
	bl sub_02021050
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
_02021234:
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0202124A
_02021240:
	ldrb r0, [r7]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x10
	b _02021254
_0202124A:
	ldrb r0, [r7]
	lsls r0, r0, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, r8
_02021254:
	adds r1, r1, r0
	ldr r0, _020212BC @ =0x00007777
	strh r0, [r1]
	ldr r1, [r4]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r1, r0
	str r1, [r4, #0x10]
	ldrb r2, [r7]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	orrs r1, r0
	str r1, [r4, #0x10]
	ldrb r1, [r7]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #8
	adds r0, r0, r2
	str r0, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r1, #0
	movs r0, #2
	strh r0, [r2]
	adds r2, #0x2b
	movs r0, #0x10
	strb r0, [r2]
	subs r2, #0x12
	movs r0, #4
	strb r0, [r2]
	adds r2, #0x19
	strb r1, [r2]
	mov r1, sl
	cmp r1, #0
	beq _020212C0
	movs r3, #0
	subs r2, #0x46
_020212A6:
	lsls r5, r3, #1
	adds r1, r2, #0
	ldrh r0, [r1]
	cmp r0, #0
	beq _020212CE
	adds r2, r1, #2
	adds r3, #1
	cmp r3, #4
	ble _020212A6
_020212B8:
	movs r0, #0
	b _020212E4
	.align 2, 0
_020212BC: .4byte 0x00007777
_020212C0:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _020212E2
	adds r0, r6, #1
	strb r0, [r2]
	b _020212E2
_020212CE:
	adds r0, r6, #1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x64
	adds r0, r0, r5
	mov r1, sl
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x95
	strb r3, [r0]
_020212E2:
	movs r0, #1
_020212E4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_020212F4
sub_020212F4: @ 0x020212F4
	push {r4, r5, lr}
	ldr r4, _02021340 @ =0x030041A0
	ldr r3, _02021344 @ =0x03003710
	adds r0, r4, #0
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #3
	beq _02021308
	cmp r0, #1
	bne _020213D4
_02021308:
	adds r0, r4, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #3
	beq _0202131A
	cmp r1, #7
	bne _020213D4
_0202131A:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #0
	bne _020213D4
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02021348
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r0, r3, #0
	adds r0, #0x10
	b _02021356
	.align 2, 0
_02021340: .4byte 0x030041A0
_02021344: .4byte 0x03003710
_02021348:
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r1, r1, #1
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r3, r5
_02021356:
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r5, r2, #0
	ldr r0, _020213CC @ =0x00000FFF
	cmp r1, r0
	bne _020213D4
	ldr r0, _020213D0 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r0, #5
	bgt _020213D4
	bl sub_0201F368
	cmp r0, #0
	beq _020213D4
	movs r0, #0xf1
	bl sub_0201F0FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _020213D4
	ldr r0, [r4, #0x10]
	str r0, [r4, #8]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0xc]
	adds r2, r4, #0
	adds r2, #0xb7
	movs r3, #0
	strb r3, [r2]
	ldrb r1, [r5]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _020213AE
	movs r0, #1
	strb r0, [r2]
_020213AE:
	adds r0, r4, #0
	adds r0, #0x7c
	strh r3, [r0]
	adds r1, r4, #0
	adds r1, #0x6e
	movs r0, #2
	strh r0, [r1]
	adds r1, #0x19
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
	movs r0, #2
	b _020213D6
	.align 2, 0
_020213CC: .4byte 0x00000FFF
_020213D0: .4byte 0x03001B50
_020213D4:
	movs r0, #0
_020213D6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_020213DC
sub_020213DC: @ 0x020213DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _02021428 @ =0x030041A0
	ldr r6, _0202142C @ =0x03003710
	ldr r2, _02021430 @ =0x03004B80
	ldrh r0, [r2, #0x28]
	cmp r0, #0
	beq _02021456
	movs r0, #0x24
	adds r0, r0, r2
	mov r8, r0
	ldrb r0, [r0]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #2
	ldr r0, _02021434 @ =0x0202F7FC
	adds r3, r3, r0
	adds r4, r2, #0
	adds r4, #0x28
	ldrb r0, [r4]
	lsls r0, r0, #0x10
	adds r5, r2, #0
	adds r5, #0x29
	ldrb r1, [r5]
	ldrh r2, [r2, #0x1a]
	ldrh r3, [r3]
	bl sub_0201F660
	ldrb r0, [r4]
	cmp r0, #0
	bne _02021438
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x10
	b _02021442
	.align 2, 0
_02021428: .4byte 0x030041A0
_0202142C: .4byte 0x03003710
_02021430: .4byte 0x03004B80
_02021434: .4byte 0x0202F7FC
_02021438:
	ldrb r0, [r5]
	lsls r0, r0, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r6, r2
_02021442:
	adds r0, r0, r1
	mov r2, r8
	ldrb r1, [r2]
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4]
	strb r0, [r5]
	ldr r4, _020214DC @ =0x00000419
	adds r1, r6, r4
	strb r0, [r1]
_02021456:
	adds r0, r7, #0
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r5, #0xf
	mov ip, r5
	movs r4, #0xf
	adds r3, r4, #0
	ands r3, r1
	mov sb, r0
	cmp r3, #0
	beq _0202155C
	adds r2, r3, #0
	cmp r2, #4
	bls _02021478
	subs r0, r2, #4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_02021478:
	lsls r0, r2, #0x11
	ldr r1, _020214E0 @ =0x80430000
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	cmp r3, #4
	bls _0202148A
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0202148A:
	adds r0, r7, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r1, _020214E4 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	beq _0202155C
	adds r0, r7, #0
	adds r0, #0x85
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _020214F0
	adds r3, r7, #0
	adds r3, #0x86
	ldrb r1, [r3]
	lsls r1, r1, #1
	adds r0, r6, #0
	adds r0, #0x10
	adds r0, r0, r1
	strh r2, [r0]
	ldr r6, _020214E8 @ =0x0600C000
	ldrb r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #3
	adds r6, r0, r6
	adds r0, r4, #0
	ands r0, r1
	lsls r2, r0, #2
	adds r6, r6, r2
	ldr r2, _020214EC @ =0x03001B40
	ldr r2, [r2]
	lsls r0, r0, #1
	lsrs r1, r1, #4
	mov r4, ip
	ands r1, r4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r2, #0x24
	b _0202152A
	.align 2, 0
_020214DC: .4byte 0x00000419
_020214E0: .4byte 0x80430000
_020214E4: .4byte 0x00FFFF00
_020214E8: .4byte 0x0600C000
_020214EC: .4byte 0x03001B40
_020214F0:
	adds r3, r7, #0
	adds r3, #0x86
	ldrb r1, [r3]
	lsls r1, r1, #1
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r6, r5
	adds r0, r0, r1
	strh r2, [r0]
	ldr r6, _02021568 @ =0x0600C800
	ldrb r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #3
	adds r6, r0, r6
	adds r0, r4, #0
	ands r0, r1
	lsls r2, r0, #2
	adds r6, r6, r2
	ldr r2, _0202156C @ =0x03001B40
	ldr r2, [r2]
	lsls r0, r0, #1
	lsrs r1, r1, #4
	mov r4, ip
	ands r1, r4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r5, #0x14
	adds r2, r2, r5
_0202152A:
	adds r2, r2, r0
	adds r1, r7, #0
	adds r1, #0x72
	ldrh r0, [r1]
	strh r0, [r2]
	adds r4, r3, #0
	adds r5, r1, #0
	ldr r1, _02021570 @ =0x00006234
	adds r0, r6, #0
	bl sub_02020A0C
	movs r0, #0
	strb r0, [r4]
	mov r1, r8
	strb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	strh r0, [r5]
	adds r0, r7, #0
	adds r0, #0x87
	ldrb r0, [r0]
	cmp r0, #3
	bne _0202155C
	bl sub_02020790
_0202155C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02021568: .4byte 0x0600C800
_0202156C: .4byte 0x03001B40
_02021570: .4byte 0x00006234

	thumb_func_start sub_02021574
sub_02021574: @ 0x02021574
	push {r4, r5, lr}
	ldr r4, _020215C0 @ =0x030041A0
	ldr r0, _020215C4 @ =0x03003710
	ldr r1, _020215C8 @ =0x0000049E
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _020215BA
	bl sub_02020DA8
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #9
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _020215A4
	adds r0, r4, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _020215BA
_020215A4:
	cmp r1, #3
	bne _020215AC
	bl sub_020205E0
_020215AC:
	ldr r0, _020215CC @ =0x0203380C
	ldrb r1, [r5]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_020215BA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020215C0: .4byte 0x030041A0
_020215C4: .4byte 0x03003710
_020215C8: .4byte 0x0000049E
_020215CC: .4byte 0x0203380C

	thumb_func_start sub_020215D0
sub_020215D0: @ 0x020215D0
	push {lr}
	ldr r1, _02021604 @ =0x030041A0
	adds r3, r1, #0
	adds r3, #0x8a
	movs r0, #0
	strb r0, [r3]
	adds r2, r1, #0
	adds r2, #0x89
	strb r0, [r2]
	str r0, [r1, #0x10]
	str r0, [r1, #0x14]
	adds r2, #2
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x88
	ldrb r0, [r0]
	cmp r0, #0x60
	bne _020215F8
	movs r0, #0xfe
	strb r0, [r3]
_020215F8:
	adds r1, #0x87
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_02021604: .4byte 0x030041A0

	thumb_func_start sub_02021608
sub_02021608: @ 0x02021608
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _02021650 @ =0x030041A0
	ldr r0, _02021654 @ =0x03003BC4
	mov sl, r0
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _02021710
	cmp r0, #0
	bne _02021674
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	cmp r0, #0x5f
	bne _02021658
	adds r5, r4, #0
	adds r5, #0x89
	ldrb r0, [r5]
	cmp r0, #8
	bne _02021640
	movs r0, #1
	bl sub_02026A38
_02021640:
	ldrb r0, [r5]
	cmp r0, #0x13
	bne _02021674
	movs r0, #0xe
	bl sub_02026A38
	b _02021674
	.align 2, 0
_02021650: .4byte 0x030041A0
_02021654: .4byte 0x03003BC4
_02021658:
	adds r5, r4, #0
	adds r5, #0x89
	ldrb r0, [r5]
	cmp r0, #1
	bne _02021668
	movs r0, #1
	bl sub_02026A38
_02021668:
	ldrb r0, [r5]
	cmp r0, #0xb
	bne _02021674
	movs r0, #0xe
	bl sub_02026A38
_02021674:
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02021710
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r5, [r0]
	mov sb, r0
	cmp r5, #0x60
	bne _020216BE
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #0x11]
	ldr r0, [r4, #4]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r4, #4]
	str r0, [r4, #0xc]
	adds r0, r4, #0
	adds r0, #0x94
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	adds r1, r4, #0
	adds r1, #0x9a
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strh r5, [r0]
	b _02021710
_020216BE:
	adds r7, r4, #0
	adds r7, #0x8a
	movs r0, #0x87
	adds r0, r0, r4
	mov r8, r0
	adds r6, r4, #0
	adds r6, #0x5a
	movs r5, #4
_020216CE:
	ldrh r0, [r6]
	cmp r0, #0
	beq _020216F4
	adds r1, r4, #0
	adds r1, #0x93
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _020216EA
	movs r0, #6
	strb r0, [r1]
_020216EA:
	bl sub_020209E0
	movs r0, #0
	bl sub_0201FE6C
_020216F4:
	subs r5, #1
	cmp r5, #0
	bge _020216CE
	movs r1, #0
	movs r0, #0xfe
	strb r0, [r7]
	movs r0, #0x60
	mov r2, sb
	strb r0, [r2]
	mov r0, r8
	strb r1, [r0]
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #0x11]
_02021710:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02021720
sub_02021720: @ 0x02021720
	push {r4, r5, r6, lr}
	ldr r5, _02021768 @ =0x030041A0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x88
	strb r6, [r4]
	adds r0, r5, #0
	adds r0, #0x89
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #7
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #5
	strb r6, [r0]
	bl sub_02020790
	ldr r1, _0202176C @ =0x02033680
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, [r0]
	adds r0, r5, #0
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #2
	bgt _02021770
	cmp r0, #1
	bge _0202177A
	cmp r0, #0
	beq _02021774
	b _0202177E
	.align 2, 0
_02021768: .4byte 0x030041A0
_0202176C: .4byte 0x02033680
_02021770:
	cmp r0, #3
	bne _0202177E
_02021774:
	movs r6, #0xc0
	lsls r6, r6, #1
	b _0202177E
_0202177A:
	movs r6, #0x80
	lsls r6, r6, #1
_0202177E:
	ldr r0, _020217A4 @ =0x03001B50
	bl sub_02019AF0
	ldr r1, _020217A8 @ =0x00000151
	bl __modsi3
	adds r0, r6, r0
	adds r1, r5, #0
	adds r1, #0x58
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r1, #0x32
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_020217A4: .4byte 0x03001B50
_020217A8: .4byte 0x00000151

	thumb_func_start sub_020217AC
sub_020217AC: @ 0x020217AC
	push {r4, r5, r6, lr}
	ldr r4, _02021818 @ =0x030041A0
	movs r6, #0
	bl sub_0201FCB0
	adds r1, r4, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	cmp r0, #0
	beq _020217C4
	subs r0, #1
	strh r0, [r1]
_020217C4:
	adds r1, r4, #0
	adds r1, #0x78
	ldrh r0, [r1]
	cmp r0, #0
	beq _020217D2
	subs r0, #1
	strh r0, [r1]
_020217D2:
	adds r1, r4, #0
	adds r1, #0x94
	ldrb r0, [r1]
	cmp r0, #0
	beq _020217E0
	subs r0, #1
	strb r0, [r1]
_020217E0:
	adds r1, r4, #0
	adds r1, #0x74
	ldrh r0, [r1]
	cmp r0, #0
	beq _020217EE
	subs r0, #1
	strh r0, [r1]
_020217EE:
	adds r0, r4, #0
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _02021820
	adds r5, r4, #0
	adds r5, #0x82
	ldrh r1, [r5]
	movs r0, #0xe1
	lsls r0, r0, #5
	cmp r1, r0
	bls _0202181C
	bl sub_02020A78
	cmp r0, #0
	beq _02021820
	strh r6, [r5]
	b _02021820
	.align 2, 0
_02021818: .4byte 0x030041A0
_0202181C:
	adds r0, r1, #1
	strh r0, [r5]
_02021820:
	bl sub_020210D4
	cmp r0, #0
	bne _020218AA
	bl sub_02020F54
	cmp r0, #0
	bne _020218AA
	bl sub_020212F4
	adds r5, r0, #0
	cmp r5, #0
	bne _020218AA
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _02021860
	ldr r1, [r4, #0x14]
	cmp r1, #0
	beq _02021860
	bl sub_0201FD1C
	cmp r0, #0
	beq _02021860
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r1]
	cmp r0, #0x5f
	bhi _0202185C
	movs r0, #0x60
	strh r0, [r1]
_0202185C:
	str r5, [r4, #0x10]
	str r5, [r4, #0x14]
_02021860:
	adds r0, r4, #0
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #3
	bne _02021870
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _020218A4
_02021870:
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r1]
	cmp r0, #0
	bne _020218A0
	movs r0, #0
	bl sub_0201F78C
	adds r6, r0, #0
	ldr r0, _0202189C @ =0x00000777
	cmp r6, r0
	beq _020218A4
	adds r0, r4, #0
	adds r0, #0x8b
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _020218AA
	.align 2, 0
_0202189C: .4byte 0x00000777
_020218A0:
	subs r0, #1
	strh r0, [r1]
_020218A4:
	movs r0, #0
	bl sub_0201FDF4
_020218AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_020218B0
sub_020218B0: @ 0x020218B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _02021938 @ =0x030041A0
	ldr r0, _0202193C @ =0x03003BC4
	mov sb, r0
	movs r6, #0
	movs r7, #0
	bl sub_0201FCB0
	ldr r1, [r5, #0x14]
	ldr r2, _02021940 @ =0xFFFF0000
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _020218D8
	ldr r0, _02021944 @ =0x0000FFFF
	ands r1, r0
	str r1, [r5, #0x14]
_020218D8:
	ldr r1, [r5, #0x1c]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _020218E8
	ldr r0, _02021944 @ =0x0000FFFF
	ands r1, r0
	str r1, [r5, #0x1c]
_020218E8:
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	adds r4, r5, #0
	adds r4, #0x6e
	ldrb r2, [r4]
	bl sub_0201F3F8
	mov r8, r4
	cmp r0, #0
	bne _020218FE
	b _02021AC6
_020218FE:
	adds r0, r5, #0
	adds r0, #0x99
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x30
	beq _0202190E
	cmp r1, #0x40
	bne _0202191E
_0202190E:
	adds r0, r5, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _02021948 @ =0x03003C00
	adds r6, r1, r0
_0202191E:
	ldrb r0, [r4]
	cmp r0, #0x40
	beq _020219DE
	cmp r0, #0x40
	bgt _02021952
	cmp r0, #0x20
	beq _02021976
	cmp r0, #0x20
	bgt _0202194C
	cmp r0, #0x10
	beq _02021968
	b _02021AB4
	.align 2, 0
_02021938: .4byte 0x030041A0
_0202193C: .4byte 0x03003BC4
_02021940: .4byte 0xFFFF0000
_02021944: .4byte 0x0000FFFF
_02021948: .4byte 0x03003C00
_0202194C:
	cmp r0, #0x30
	beq _020219A8
	b _02021AB4
_02021952:
	cmp r0, #0x60
	beq _02021A46
	cmp r0, #0x60
	bgt _02021960
	cmp r0, #0x50
	beq _02021A2A
	b _02021AB4
_02021960:
	cmp r0, #0x70
	bne _02021966
	b _02021A72
_02021966:
	b _02021AB4
_02021968:
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #5
	strb r0, [r1]
	bl sub_02021AD8
	b _02021AB4
_02021976:
	ldr r0, [r5, #0x10]
	str r0, [r5]
	ldr r0, [r5, #0x14]
	ldr r1, _020219A4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r5, #4]
	movs r2, #0
	mov r0, sb
	strb r2, [r0, #0x11]
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0x5f
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x87
	strb r2, [r0]
	bl sub_020215D0
	adds r1, r5, #0
	adds r1, #0x8a
	movs r0, #4
	strb r0, [r1]
	b _02021AB4
	.align 2, 0
_020219A4: .4byte 0xFFFFF000
_020219A8:
	adds r0, r6, #0
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _02021A62
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	bne _02021A62
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #2
	beq _020219D6
	cmp r1, #6
	beq _020219D6
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0x62
	b _02021A12
_020219D6:
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0x55
	b _02021A12
_020219DE:
	adds r0, r6, #0
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _02021A62
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	bne _02021A62
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #2
	beq _02021A0C
	cmp r1, #6
	beq _02021A0C
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0x61
	b _02021A12
_02021A0C:
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0x54
_02021A12:
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	str r0, [r5]
	ldr r0, [r5, #0x14]
	str r0, [r5, #4]
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #0xb
	strb r0, [r1]
	bl sub_020223AC
	b _02021AB4
_02021A2A:
	ldr r0, [r5, #0x10]
	str r0, [r5]
	ldr r0, [r5, #0x14]
	str r0, [r5, #4]
	movs r0, #1
	bl sub_0201F78C
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _02021AB4
_02021A46:
	adds r1, r5, #0
	adds r1, #0x8b
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	str r0, [r5]
	ldr r0, [r5, #0x14]
	str r0, [r5, #4]
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _02021A62
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	beq _02021A8E
_02021A62:
	ldr r0, [r5, #0x18]
	str r0, [r5, #0x10]
	ldr r0, [r5, #0x1c]
	str r0, [r5, #0x14]
	movs r0, #0
	str r0, [r5, #0x18]
	str r0, [r5, #0x1c]
	b _02021AC6
_02021A72:
	adds r1, r5, #0
	adds r1, #0x8b
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	str r0, [r5]
	ldr r0, [r5, #0x14]
	str r0, [r5, #4]
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _02021AA4
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	bne _02021AA4
_02021A8E:
	movs r0, #0
	mov r2, r8
	strh r1, [r2]
	strb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #0x11
	strb r0, [r1]
	bl sub_02022F28
	b _02021AB4
_02021AA4:
	ldr r0, [r5, #0x18]
	str r0, [r5, #0x10]
	ldr r0, [r5, #0x1c]
	str r0, [r5, #0x14]
	movs r0, #0
	str r0, [r5, #0x18]
	str r0, [r5, #0x1c]
	movs r7, #1
_02021AB4:
	cmp r7, #0
	bne _02021AC6
	movs r0, #0
	mov r1, r8
	strh r7, [r1]
	strb r0, [r4]
	str r7, [r5, #0x10]
	str r7, [r5, #0x14]
	b _02021ACC
_02021AC6:
	movs r0, #0
	bl sub_0201FDF4
_02021ACC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_02021AD8
sub_02021AD8: @ 0x02021AD8
	push {r4, r5, lr}
	ldr r5, _02021B2C @ =0x030041A0
	adds r2, r5, #0
	adds r2, #0x88
	movs r0, #0
	adds r1, r5, #0
	adds r1, #0x89
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x8a
	strb r0, [r3]
	adds r1, #8
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r1, #0x56
	strb r1, [r2]
	ldr r0, _02021B30 @ =0x02033680
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r1, _02021B34 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _02021B38
	ldr r0, [r5]
	adds r4, r5, #0
	adds r4, #0x8e
	ldrb r1, [r4]
	movs r3, #0x80
	lsls r3, r3, #2
	movs r2, #0
	bl sub_0201F660
	b _02021B68
	.align 2, 0
_02021B2C: .4byte 0x030041A0
_02021B30: .4byte 0x02033680
_02021B34: .4byte 0x00FFFF00
_02021B38:
	ldr r0, [r5]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	ldr r2, _02021B94 @ =0x0600C800
	cmp r0, #0
	bne _02021B48
	ldr r2, _02021B98 @ =0x0600C000
_02021B48:
	adds r4, r5, #0
	adds r4, #0x8e
	ldrb r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r2, #0
	bl sub_02020A0C
_02021B68:
	ldrb r0, [r4]
	ldr r1, [r5]
	bl sub_020262DC
	adds r1, r5, #0
	adds r1, #0xa0
	ldrb r0, [r1]
	cmp r0, #0
	bne _02021BA0
	adds r1, #0x16
	ldrb r0, [r1]
	cmp r0, #0
	bne _02021B9C
	adds r0, r5, #0
	adds r0, #0x95
	ldrb r0, [r0]
	lsls r0, r0, #1
	subs r1, #0x5c
	adds r1, r1, r0
	ldrh r0, [r1]
	b _02021BA2
	.align 2, 0
_02021B94: .4byte 0x0600C800
_02021B98: .4byte 0x0600C000
_02021B9C:
	ldrb r1, [r1]
	b _02021BA4
_02021BA0:
	ldrb r0, [r1]
_02021BA2:
	subs r1, r0, #1
_02021BA4:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02021BC8 @ =0x0202F7FC
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r5, #0x40]
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #6
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02021BC8: .4byte 0x0202F7FC

	thumb_func_start sub_02021BCC
sub_02021BCC: @ 0x02021BCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, _02021C38 @ =0x030041A0
	ldr r0, _02021C3C @ =0x03003710
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	cmp r0, #0x56
	bne _02021C02
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02021C02
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #2
	bne _02021C02
	movs r0, #0x1d
	bl sub_02026A38
_02021C02:
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	bne _02021C0E
	b _02021F8E
_02021C0E:
	movs r1, #0
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0xa0
	ldrb r1, [r0]
	str r0, [sp, #8]
	cmp r1, #0
	bne _02021C44
	adds r1, r4, #0
	adds r1, #0xb6
	ldrb r0, [r1]
	cmp r0, #0
	bne _02021C40
	adds r0, r4, #0
	adds r0, #0x95
	ldrb r0, [r0]
	lsls r0, r0, #1
	subs r1, #0x5c
	adds r1, r1, r0
	ldrh r0, [r1]
	b _02021C48
	.align 2, 0
_02021C38: .4byte 0x030041A0
_02021C3C: .4byte 0x03003710
_02021C40:
	ldrb r7, [r1]
	b _02021C4A
_02021C44:
	ldr r2, [sp, #8]
	ldrb r0, [r2]
_02021C48:
	subs r7, r0, #1
_02021C4A:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	ldr r1, _02021C74 @ =0x0202F7FC
	adds r2, r0, r1
	ldrh r0, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r4, #0x40]
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r1, [r0]
	str r0, [sp, #4]
	cmp r1, #0x57
	beq _02021CA4
	cmp r1, #0x57
	bgt _02021C78
	cmp r1, #0x56
	beq _02021C80
	b _02021EDE
	.align 2, 0
_02021C74: .4byte 0x0202F7FC
_02021C78:
	cmp r1, #0x58
	bne _02021C7E
	b _02021DA8
_02021C7E:
	b _02021EDE
_02021C80:
	movs r0, #0x58
	ldr r3, [sp, #4]
	strb r0, [r3]
	ldr r5, [sp, #8]
	ldrb r0, [r5]
	adds r6, r4, #0
	adds r6, #0x8a
	adds r5, r4, #0
	adds r5, #0x89
	cmp r0, #0
	bne _02021C98
	b _02021EE6
_02021C98:
	movs r0, #0x57
	strb r0, [r3]
	movs r0, #0x19
	bl sub_02026A38
	b _02021EE6
_02021CA4:
	movs r0, #0
	str r0, [r4, #0x40]
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02021CCC
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r1, #0x10
	b _02021CDC
_02021CC2:
	adds r1, r4, #0
	adds r1, #0x97
	movs r0, #0x59
	strb r0, [r1]
	b _02021D48
_02021CCC:
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r3, [sp]
	movs r5, #0x84
	lsls r5, r5, #2
	adds r1, r3, r5
_02021CDC:
	adds r1, r1, r0
	ldr r0, _02021D34 @ =0x00000FFF
	strh r0, [r1]
	mov r8, r2
	movs r0, #0
	mov sb, r0
	adds r6, r4, #0
	adds r6, #0x8a
	adds r5, r4, #0
	adds r5, #0x89
	ldr r2, _02021D38 @ =0x02033FB6
	movs r1, #0x93
	adds r1, r1, r4
	mov ip, r1
	mov r3, ip
	movs r0, #0x97
	adds r0, r0, r4
	mov sl, r0
	adds r0, r2, #0
	adds r0, #0xa2
_02021D04:
	ldrb r1, [r0]
	cmp r7, r1
	bne _02021D3C
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	add r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r2
	ldrb r1, [r0]
	ldrb r2, [r3]
	adds r0, r1, r2
	strb r0, [r3]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _02021CC2
	movs r0, #0x5d
	mov r3, sl
	strb r0, [r3]
	b _02021D48
	.align 2, 0
_02021D34: .4byte 0x00000FFF
_02021D38: .4byte 0x02033FB6
_02021D3C:
	adds r0, #1
	movs r1, #1
	add sb, r1
	mov r1, sb
	cmp r1, #8
	ble _02021D04
_02021D48:
	movs r2, #3
	mov sb, r2
	mov r3, ip
	ldrb r1, [r3]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _02021D5E
	movs r0, #0
	strb r0, [r3]
	b _02021DA0
_02021D5E:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _02021DA0
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02021D7E
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r1, #0x10
	b _02021D8C
_02021D7E:
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r3, [sp]
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r3, r2
_02021D8C:
	adds r1, r1, r0
	ldr r0, _02021D9C @ =0x00003333
	strh r0, [r1]
	movs r0, #6
	mov r3, ip
	strb r0, [r3]
	b _02021EE6
	.align 2, 0
_02021D9C: .4byte 0x00003333
_02021DA0:
	movs r0, #0
	ldr r1, [sp, #8]
	strb r0, [r1]
	b _02021EE6
_02021DA8:
	movs r0, #0
	str r0, [r4, #0x40]
	ldr r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02021DD2
	adds r0, r4, #0
	adds r0, #0x86
	adds r1, r4, #0
	adds r1, #0x8e
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _02021DF4
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r1, [sp]
	adds r1, #0x10
	b _02021DEE
_02021DD2:
	adds r0, r4, #0
	adds r0, #0x86
	adds r1, r4, #0
	adds r1, #0x8e
	ldrb r0, [r0]
	ldrb r5, [r1]
	cmp r0, r5
	beq _02021DF4
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r3, [sp]
	movs r5, #0x84
	lsls r5, r5, #2
	adds r1, r3, r5
_02021DEE:
	adds r1, r1, r0
	ldr r0, _02021E10 @ =0x00000FFF
	strh r0, [r1]
_02021DF4:
	ldrh r0, [r2, #8]
	subs r0, #1
	adds r6, r4, #0
	adds r6, #0x8a
	adds r5, r4, #0
	adds r5, #0x89
	cmp r0, #0xd
	bhi _02021EE6
	lsls r0, r0, #2
	ldr r1, _02021E14 @ =_02021E18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02021E10: .4byte 0x00000FFF
_02021E14: .4byte _02021E18
_02021E18: @ jump table
	.4byte _02021E50 @ case 0
	.4byte _02021E50 @ case 1
	.4byte _02021E50 @ case 2
	.4byte _02021E5E @ case 3
	.4byte _02021E50 @ case 4
	.4byte _02021E50 @ case 5
	.4byte _02021E86 @ case 6
	.4byte _02021E78 @ case 7
	.4byte _02021E9C @ case 8
	.4byte _02021E8E @ case 9
	.4byte _02021EB6 @ case 10
	.4byte _02021EA8 @ case 11
	.4byte _02021ED2 @ case 12
	.4byte _02021EC4 @ case 13
_02021E50:
	adds r1, r4, #0
	adds r1, #0x97
	movs r0, #0x59
	strb r0, [r1]
	movs r0, #3
	mov sb, r0
	b _02021EDE
_02021E5E:
	adds r1, r4, #0
	adds r1, #0x93
	movs r0, #0
	strb r0, [r1]
	subs r1, #3
	movs r0, #1
	strb r0, [r1]
	adds r1, #7
	movs r0, #0x5b
	strb r0, [r1]
	movs r1, #1
	mov sb, r1
	b _02021EDE
_02021E78:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #5
	strb r0, [r1]
	movs r2, #2
	mov sb, r2
	b _02021EDE
_02021E86:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #1
	b _02021ED8
_02021E8E:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #6
	strb r0, [r1]
	movs r5, #2
	mov sb, r5
	b _02021EDE
_02021E9C:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #2
	strb r0, [r1]
	mov sb, r0
	b _02021EDE
_02021EA8:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #7
	strb r0, [r1]
	movs r0, #2
	mov sb, r0
	b _02021EDE
_02021EB6:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #3
	strb r0, [r1]
	movs r1, #2
	mov sb, r1
	b _02021EDE
_02021EC4:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #8
	strb r0, [r1]
	movs r2, #2
	mov sb, r2
	b _02021EDE
_02021ED2:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #4
_02021ED8:
	strb r0, [r1]
	movs r3, #2
	mov sb, r3
_02021EDE:
	adds r6, r4, #0
	adds r6, #0x8a
	adds r5, r4, #0
	adds r5, #0x89
_02021EE6:
	mov r0, sb
	cmp r0, #2
	beq _02021F4A
	cmp r0, #2
	bgt _02021EF6
	cmp r0, #1
	beq _02021EFE
	b _02021F76
_02021EF6:
	mov r1, sb
	cmp r1, #3
	beq _02021F08
	b _02021F76
_02021EFE:
	adds r0, r4, #0
	adds r0, #0x95
	ldrb r0, [r0]
	bl sub_0201FE6C
_02021F08:
	mov r2, sb
	cmp r2, #1
	beq _02021F30
	bl sub_020209E0
	adds r1, r4, #0
	adds r1, #0x90
	ldrb r0, [r1]
	cmp r0, #2
	bne _02021F30
	adds r0, r4, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	bne _02021F30
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	bl sub_02026C7C
_02021F30:
	adds r1, r4, #0
	adds r1, #0x6e
	movs r0, #2
	strh r0, [r1]
	adds r1, #0x2b
	movs r0, #0x50
	strb r0, [r1]
	subs r1, #0x12
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
	b _02021F76
_02021F4A:
	ldr r0, [r4]
	adds r1, r4, #0
	adds r1, #0x8e
	ldrb r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	movs r2, #0
	bl sub_0201F660
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
	adds r1, #0x12
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x87
	mov r3, sb
	strb r3, [r0]
	bl sub_02021720
_02021F76:
	ldr r1, _02021FA0 @ =0x02033680
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r5]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldrh r0, [r0, #4]
	strb r0, [r6]
_02021F8E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02021FA0: .4byte 0x02033680

	thumb_func_start sub_02021FA4
sub_02021FA4: @ 0x02021FA4
	push {r4, r5, lr}
	ldr r4, _02021FE4 @ =0x030041A0
	adds r1, r4, #0
	adds r1, #0x89
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #7
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x97
	ldrb r0, [r3]
	subs r1, #0xa
	strb r0, [r1]
	ldr r2, _02021FE8 @ =0x02033680
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r5, [r0]
	ldrb r0, [r3]
	subs r0, #0x59
	cmp r0, #5
	bhi _0202202E
	lsls r0, r0, #2
	ldr r1, _02021FEC @ =_02021FF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02021FE4: .4byte 0x030041A0
_02021FE8: .4byte 0x02033680
_02021FEC: .4byte _02021FF0
_02021FF0: @ jump table
	.4byte _02022008 @ case 0
	.4byte _02022010 @ case 1
	.4byte _02022018 @ case 2
	.4byte _02022020 @ case 3
	.4byte _02022028 @ case 4
	.4byte _0202202E @ case 5
_02022008:
	movs r0, #9
	bl sub_02026A38
	b _0202202E
_02022010:
	movs r0, #0xa
	bl sub_02026A38
	b _0202202E
_02022018:
	movs r0, #0xb
	bl sub_02026A38
	b _0202202E
_02022020:
	movs r0, #0xc
	bl sub_02026A38
	b _0202202E
_02022028:
	movs r0, #0xd
	bl sub_02026A38
_0202202E:
	adds r0, r4, #0
	adds r0, #0x90
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_02026C7C
	ldrh r0, [r5, #4]
	adds r1, r4, #0
	adds r1, #0x8a
	strb r0, [r1]
	subs r1, #3
	movs r0, #8
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02022054
sub_02022054: @ 0x02022054
	push {r4, r5, r6, lr}
	ldr r4, _020220B8 @ =0x030041A0
	ldr r6, _020220BC @ =0x03003BC4
	movs r5, #0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	bne _02022068
	b _020221B8
_02022068:
	adds r0, r4, #0
	adds r0, #0x94
	movs r1, #0x20
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	ldrb r0, [r1]
	cmp r0, #0
	beq _02022118
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x59
	bne _02022118
	strb r5, [r1]
	adds r0, r4, #0
	adds r0, #0x93
	ldrb r0, [r0]
	cmp r0, #6
	bne _02022118
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r2, [r0]
	cmp r2, #0
	beq _020220C0
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #0xa
	ldrh r3, [r0]
	movs r0, #1
	movs r1, #0
	bl sub_0201FF48
	cmp r0, #0
	beq _02022118
	movs r0, #0
	bl sub_0201FE6C
	b _02022118
	.align 2, 0
_020220B8: .4byte 0x030041A0
_020220BC: .4byte 0x03003BC4
_020220C0:
	ldr r0, _020220E4 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x3b
	bhi _020220E8
	movs r0, #0
	movs r1, #0
	movs r2, #0xb
	movs r3, #8
	bl sub_0201FF48
	b _02022118
	.align 2, 0
_020220E4: .4byte 0x03001B50
_020220E8:
	cmp r5, #0x59
	bhi _020220FA
	movs r0, #0
	movs r1, #0
	movs r2, #0x42
	movs r3, #9
	bl sub_0201FF48
	b _02022118
_020220FA:
	cmp r5, #0x61
	bhi _0202210C
	movs r0, #0
	movs r1, #0
	movs r2, #0x43
	movs r3, #0xa
	bl sub_0201FF48
	b _02022118
_0202210C:
	movs r0, #0
	movs r1, #0
	movs r2, #0x44
	movs r3, #0xb
	bl sub_0201FF48
_02022118:
	adds r1, r4, #0
	adds r1, #0x99
	ldrb r0, [r1]
	cmp r0, #0x50
	bne _0202215C
	ldr r0, [r4, #8]
	str r0, [r4, #0x10]
	ldr r0, [r4, #0xc]
	str r0, [r4, #0x14]
	subs r1, #0x10
	movs r0, #0
	strb r0, [r1]
	bl sub_02020790
	ldr r1, _02022158 @ =0x02033680
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r1, r4, #0
	adds r1, #0x8a
	strb r0, [r1]
	subs r1, #3
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
	b _020221B8
	.align 2, 0
_02022158: .4byte 0x02033680
_0202215C:
	cmp r0, #0x80
	bne _020221A6
	movs r2, #0
	strb r2, [r6, #0x11]
	ldr r0, [r6]
	lsls r0, r0, #8
	str r0, [r4]
	ldr r0, [r6, #4]
	lsls r0, r0, #8
	str r0, [r4, #4]
	strb r2, [r1]
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x5f
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x87
	strb r2, [r0]
	bl sub_020215D0
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #4
	strb r0, [r1]
	movs r3, #0
	subs r1, #0x26
	adds r0, r4, #0
	adds r0, #0x5a
	movs r2, #4
_02022196:
	strh r3, [r0]
	strh r3, [r1]
	adds r1, #2
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bge _02022196
	b _020221B8
_020221A6:
	movs r0, #1
	bl sub_0201F78C
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
_020221B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020221C0
sub_020221C0: @ 0x020221C0
	push {r4, r5, r6, r7, lr}
	ldr r4, _020221EC @ =0x030041A0
	ldr r2, _020221F0 @ =0x03003710
	adds r0, r4, #0
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202224C
	ldr r0, [r4, #0x10]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _020221F4
	adds r0, r4, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r1, r2, #0
	adds r1, #0x10
	b _02022202
	.align 2, 0
_020221EC: .4byte 0x030041A0
_020221F0: .4byte 0x03003710
_020221F4:
	adds r0, r4, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r2, r3
_02022202:
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0202223C @ =0x00000FFF
	cmp r0, r2
	beq _0202222C
	ldr r0, _02022240 @ =0x00003333
	cmp r1, r0
	beq _0202222C
	ldr r0, _02022244 @ =0x00007777
	cmp r1, r0
	beq _0202222C
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02022248 @ =0x0202F7FC
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	cmp r0, r2
	bne _0202224C
_0202222C:
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _020222F0
	.align 2, 0
_0202223C: .4byte 0x00000FFF
_02022240: .4byte 0x00003333
_02022244: .4byte 0x00007777
_02022248: .4byte 0x0202F7FC
_0202224C:
	movs r0, #0
	movs r1, #0x30
	bl sub_0201FED4
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0x30
	strb r0, [r1]
	subs r1, #4
	movs r0, #0x60
	strb r0, [r1]
	ldr r0, [r4, #0x10]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x14]
	ldr r2, [r4, #4]
	subs r1, r1, r2
	asrs r1, r1, #8
	str r1, [r4, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _020222BC @ =0x020338F8
	ldrh r1, [r0]
	cmp r2, r1
	bhs _020222C0
	movs r1, #0
	subs r0, #0x1c
	adds r6, r4, #0
	adds r6, #0x87
	adds r7, r0, #0
	adds r5, r4, #0
	adds r5, #0x8b
	movs r3, #0x89
	adds r3, r3, r4
	mov ip, r3
	adds r3, r4, #0
	adds r3, #0x8a
	ldrh r4, [r0]
	cmp r2, r4
	bls _020222D8
_020222AC:
	adds r0, #4
	adds r1, #1
	cmp r1, #6
	bgt _020222D8
	ldrh r4, [r0]
	cmp r2, r4
	bhi _020222AC
	b _020222D8
	.align 2, 0
_020222BC: .4byte 0x020338F8
_020222C0:
	movs r1, #0
	adds r6, r4, #0
	adds r6, #0x87
	adds r7, r0, #0
	subs r7, #0x1c
	adds r5, r4, #0
	adds r5, #0x8b
	movs r0, #0x89
	adds r0, r0, r4
	mov ip, r0
	adds r3, r4, #0
	adds r3, #0x8a
_020222D8:
	lsls r0, r1, #2
	adds r0, r0, r7
	ldrb r0, [r0, #2]
	movs r1, #0
	strb r0, [r5]
	mov r4, ip
	strb r1, [r4]
	strb r1, [r3]
	bl sub_02020790
	movs r0, #0xa
	strb r0, [r6]
_020222F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020222F8
sub_020222F8: @ 0x020222F8
	push {r4, r5, r6, r7, lr}
	ldr r4, _02022340 @ =0x030041A0
	adds r7, r4, #0
	adds r7, #0x98
	ldrb r0, [r7]
	subs r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _020223A6
	adds r6, r4, #0
	adds r6, #0x97
	ldrb r0, [r6]
	cmp r0, #0
	bne _02022344
	adds r2, r4, #0
	adds r2, #0x8d
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _02022330
	adds r0, r1, #0
	subs r0, #0x40
	strb r0, [r2]
	bl sub_02020A78
_02022330:
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _020223A6
	.align 2, 0
_02022340: .4byte 0x030041A0
_02022344:
	strb r5, [r6]
	adds r2, r4, #0
	adds r2, #0x93
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0202235A
	strb r5, [r2]
_0202235A:
	bl sub_020209E0
	adds r1, r4, #0
	adds r1, #0x90
	ldrb r0, [r1]
	cmp r0, #0
	beq _0202236C
	cmp r0, #3
	bne _02022380
_0202236C:
	adds r0, r4, #0
	adds r0, #0x8b
	strb r5, [r0]
	movs r0, #1
	movs r1, #0x30
	bl sub_0201FED4
	movs r0, #0x30
	strb r0, [r7]
	b _020223A6
_02022380:
	adds r0, r4, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022392
	movs r0, #0x5b
	strb r0, [r6]
	movs r0, #1
	b _02022398
_02022392:
	movs r0, #0x5c
	strb r0, [r6]
	movs r0, #2
_02022398:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
_020223A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_020223AC
sub_020223AC: @ 0x020223AC
	push {r4, lr}
	ldr r3, _02022410 @ =0x030041A0
	adds r0, r3, #0
	adds r0, #0x9b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _02022414 @ =0x03003C00
	adds r4, r0, r1
	adds r0, r3, #0
	adds r0, #0x89
	movs r1, #0
	strb r1, [r0]
	ldr r2, _02022418 @ =0x02033680
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r3, #0
	adds r2, #0x8a
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x6e
	strh r1, [r0]
	adds r0, #0x10
	strh r1, [r0]
	adds r0, #0xf
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #2
	beq _0202241C
	cmp r1, #6
	beq _0202241C
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
	subs r0, #4
	strb r1, [r0]
	b _0202242C
	.align 2, 0
_02022410: .4byte 0x030041A0
_02022414: .4byte 0x03003C00
_02022418: .4byte 0x02033680
_0202241C:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #1
	strb r0, [r1]
_0202242C:
	adds r1, r3, #0
	adds r1, #0x87
	movs r0, #0xc
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0202243C
sub_0202243C: @ 0x0202243C
	push {r4, r5, r6, lr}
	ldr r5, _020224CC @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x9b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _020224D0 @ =0x03003C00
	adds r4, r0, r1
	adds r1, r5, #0
	adds r1, #0x89
	ldrb r0, [r1]
	cmp r0, #0
	beq _02022474
	adds r0, r5, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #1
	bne _02022474
	ldr r0, _020224D4 @ =0x02033B27
	ldrb r1, [r1]
	subs r1, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
_02022474:
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _020224C6
	adds r1, r5, #0
	adds r1, #0x7e
	movs r2, #0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x9c
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5, #8]
	str r0, [r5, #0x10]
	ldr r0, [r5, #0xc]
	str r0, [r5, #0x14]
	adds r6, r5, #0
	adds r6, #0x6e
	movs r4, #1
	strh r4, [r6]
	adds r0, r5, #0
	adds r0, #0x9b
	strb r2, [r0]
	bl sub_02020790
	strh r4, [r6]
	adds r1, r5, #0
	adds r1, #0x99
	movs r0, #0x50
	strb r0, [r1]
	subs r1, #0x12
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
_020224C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_020224CC: .4byte 0x030041A0
_020224D0: .4byte 0x03003C00
_020224D4: .4byte 0x02033B27

	thumb_func_start sub_020224D8
sub_020224D8: @ 0x020224D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r7, _02022524 @ =0x03003710
	ldr r5, _02022528 @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x9b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0202252C @ =0x03003C00
	adds r6, r0, r1
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _0202253C
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	cmp r1, #0
	beq _02022512
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _02022530
_02022512:
	adds r1, r5, #0
	adds r1, #0x7e
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #0x1e
	movs r0, #2
	strb r0, [r1]
	b _0202253C
	.align 2, 0
_02022524: .4byte 0x03003710
_02022528: .4byte 0x030041A0
_0202252C: .4byte 0x03003C00
_02022530:
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #0xb
	strb r0, [r1]
	bl sub_020223AC
_0202253C:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r0, [r0]
	ldr r1, _020225B8 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _020225BC @ =0x00010300
	cmp r0, r1
	beq _0202254E
	b _020226D0
_0202254E:
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	beq _0202255A
	b _020226BA
_0202255A:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	beq _02022568
	b _020226BA
_02022568:
	subs r0, #0x46
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _02022574
	b _020226BA
_02022574:
	ldr r0, _020225C0 @ =0x00000416
	adds r2, r7, r0
	ldr r1, _020225C4 @ =0x02033FA4
	adds r0, r5, #0
	adds r0, #0x96
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0202258C
	b _020226BA
_0202258C:
	ldr r0, _020225C8 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r0, #0x18
	ble _0202259E
	b _020226BA
_0202259E:
	adds r0, r6, #0
	adds r0, #0x24
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _020225CC
	ldrh r1, [r6, #0xe]
	adds r1, #0x10
	lsls r1, r1, #1
	adds r0, r7, #0
	adds r0, #0x10
	b _020225D8
	.align 2, 0
_020225B8: .4byte 0x00FFFF00
_020225BC: .4byte 0x00010300
_020225C0: .4byte 0x00000416
_020225C4: .4byte 0x02033FA4
_020225C8: .4byte 0x03001B50
_020225CC:
	ldrh r1, [r6, #0xe]
	adds r1, #0x10
	lsls r1, r1, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r7, r2
_020225D8:
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _02022650 @ =0x00000FFF
	cmp r1, r0
	bne _020226BA
	movs r3, #0
	mov sb, r3
	movs r0, #1
	strh r0, [r4]
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x8d
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #6
	bne _020225FC
	movs r4, #0x14
_020225FC:
	ldr r1, _02022654 @ =0x02033DE0
	adds r0, r5, #0
	adds r0, #0x90
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r4, r4, r0
	ldr r0, _02022658 @ =0x03001B50
	bl sub_02019AF0
	adds r1, r0, #0
	cmp r1, #0
	bge _02022618
	adds r0, r1, #3
_02022618:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	adds r4, r4, r0
	lsls r0, r4, #2
	ldr r1, _0202265C @ =0x02033EE0
	adds r0, r0, r1
	ldrh r2, [r0]
	ldrh r3, [r0, #2]
	movs r0, #0
	movs r1, #2
	bl sub_0201FF48
	adds r4, r0, #0
	cmp r4, #0
	beq _020226BA
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _02022660
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x10
	b _0202266E
	.align 2, 0
_02022650: .4byte 0x00000FFF
_02022654: .4byte 0x02033DE0
_02022658: .4byte 0x03001B50
_0202265C: .4byte 0x02033EE0
_02022660:
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r7, r2
_0202266E:
	adds r1, r1, r0
	ldr r0, _020226E0 @ =0x00003333
	strh r0, [r1]
	movs r0, #0x54
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, _020226E4 @ =0x03004790
	adds r1, r1, r0
	ldr r0, [r1, #4]
	adds r0, #0x20
	lsls r0, r0, #8
	str r0, [r1, #0x10]
	ldrh r0, [r6, #0xe]
	adds r2, r0, #0
	adds r2, #0x10
	strh r2, [r1, #0x3c]
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	beq _020226A0
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r2, r0
	strh r2, [r1, #0x3c]
_020226A0:
	adds r2, r1, #0
	adds r2, #0x52
	movs r0, #0x35
	strb r0, [r2]
	ldr r0, [r1, #4]
	subs r0, #0x20
	str r0, [r1, #4]
	ldr r0, [r6]
	subs r0, #8
	str r0, [r1]
	movs r0, #1
	mov r1, sl
	strb r0, [r1]
_020226BA:
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	adds r1, #2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	bl sub_02026A38
_020226D0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020226E0: .4byte 0x00003333
_020226E4: .4byte 0x03004790

	thumb_func_start sub_020226E8
sub_020226E8: @ 0x020226E8
	push {r4, r5, lr}
	ldr r4, _02022758 @ =0x030041A0
	adds r2, r4, #0
	adds r2, #0x7e
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _02022752
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r2]
	subs r2, #0x10
	strh r1, [r2]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x90
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #1
	bne _02022734
	subs r1, #9
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _02022730
	movs r0, #6
	strb r0, [r1]
_02022730:
	bl sub_020209E0
_02022734:
	ldr r0, [r4, #8]
	str r0, [r4, #0x10]
	ldr r0, [r4, #0xc]
	str r0, [r4, #0x14]
	movs r0, #1
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x99
	movs r0, #0x50
	strb r0, [r1]
	subs r1, #2
	movs r0, #0x59
	strb r0, [r1]
	bl sub_02021FA4
_02022752:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02022758: .4byte 0x030041A0

	thumb_func_start sub_0202275C
sub_0202275C: @ 0x0202275C
	push {lr}
	ldr r0, _02022774 @ =0x030041A0
	ldr r1, _02022778 @ =0x02033860
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_02022774: .4byte 0x030041A0
_02022778: .4byte 0x02033860

	thumb_func_start sub_0202277C
sub_0202277C: @ 0x0202277C
	push {lr}
	ldr r3, _02022794 @ =0x030041A0
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022798
	adds r1, r3, #0
	adds r1, #0x88
	movs r0, #0x38
	b _0202279E
	.align 2, 0
_02022794: .4byte 0x030041A0
_02022798:
	adds r1, r3, #0
	adds r1, #0x88
	movs r0, #0x41
_0202279E:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _020227D4 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	movs r1, #0x8a
	movs r2, #0
	strb r0, [r1, r3]
	adds r0, r3, #0
	adds r0, #0x89
	strb r2, [r0]
	subs r0, #0x1b
	movs r1, #0
	strh r2, [r0]
	adds r0, #0x2e
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x87
	movs r0, #0xe
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_020227D4: .4byte 0x02033680

	thumb_func_start sub_020227D8
sub_020227D8: @ 0x020227D8
	push {r4, lr}
	ldr r4, _020227F8 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022834
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020227FC
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x39
	b _02022802
	.align 2, 0
_020227F8: .4byte 0x030041A0
_020227FC:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x42
_02022802:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022854 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
	subs r0, #0x1b
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x70
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_02022834:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0202284E
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #3
	bne _0202284E
	movs r0, #0x14
	bl sub_02026A38
_0202284E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02022854: .4byte 0x02033680

	thumb_func_start sub_02022858
sub_02022858: @ 0x02022858
	push {r4, lr}
	ldr r4, _0202289C @ =0x030041A0
	movs r0, #0
	bl sub_0201FDF4
	adds r3, r4, #0
	adds r3, #0x70
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _02022896
	adds r1, r4, #0
	adds r1, #0x89
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x30
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x6e
	strh r2, [r0]
	movs r0, #0
	movs r1, #0x30
	bl sub_0201FED4
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #2
	strb r0, [r1]
_02022896:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0202289C: .4byte 0x030041A0

	thumb_func_start sub_020228A0
sub_020228A0: @ 0x020228A0
	push {r4, lr}
	ldr r4, _020228C4 @ =0x030041A0
	adds r1, r4, #0
	adds r1, #0x70
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _02022908
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020228C8
	adds r1, #0x18
	movs r0, #0x3a
	b _020228CE
	.align 2, 0
_020228C4: .4byte 0x030041A0
_020228C8:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x43
_020228CE:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022910 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
	subs r0, #0x1b
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x15
	bl sub_02026AB8
	adds r1, r4, #0
	adds r1, #0x70
	movs r0, #0x51
	strh r0, [r1]
_02022908:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02022910: .4byte 0x02033680

	thumb_func_start sub_02022914
sub_02022914: @ 0x02022914
	push {r4, lr}
	ldr r4, _02022944 @ =0x030041A0
	movs r0, #0
	bl sub_0201FDF4
	adds r1, r4, #0
	adds r1, #0x70
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0202298A
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022948
	adds r1, #0x18
	movs r0, #0x3b
	b _0202294E
	.align 2, 0
_02022944: .4byte 0x030041A0
_02022948:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x44
_0202294E:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022990 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
	bl sub_0201F030
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r1, #0x2e
	movs r0, #4
	strb r0, [r1]
	movs r0, #0x15
	bl sub_02026B38
	movs r0, #0x16
	bl sub_02026A38
_0202298A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02022990: .4byte 0x02033680

	thumb_func_start sub_02022994
sub_02022994: @ 0x02022994
	push {r4, r5, lr}
	ldr r4, _020229D4 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	bne _020229A4
	b _02022AD8
_020229A4:
	movs r0, #0x1c
	bl sub_02026A38
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	cmp r0, #0
	bne _02022A06
	ldr r0, [r4, #0x40]
	ldr r1, _020229D8 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _020229DC @ =0x0000609E
	cmp r0, r1
	bne _020229E8
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020229E0
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x3e
	b _02022A00
	.align 2, 0
_020229D4: .4byte 0x030041A0
_020229D8: .4byte 0x0000FFFF
_020229DC: .4byte 0x0000609E
_020229E0:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x47
	b _02022A00
_020229E8:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020229FA
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x40
	b _02022A00
_020229FA:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x49
_02022A00:
	strb r0, [r1]
	adds r5, r1, #0
	b _02022AB0
_02022A06:
	ldr r1, [r4, #0x40]
	ldr r0, _02022A3C @ =0x0000FFFF
	ands r1, r0
	ldr r0, _02022A40 @ =0x0000434E
	cmp r1, r0
	bne _02022A4C
	adds r2, r4, #0
	adds r2, #0x93
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _02022A28
	movs r0, #0
	strb r0, [r2]
_02022A28:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022A44
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x3e
	b _02022AA8
	.align 2, 0
_02022A3C: .4byte 0x0000FFFF
_02022A40: .4byte 0x0000434E
_02022A44:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x47
	b _02022AA8
_02022A4C:
	ldr r0, _02022A84 @ =0x00004350
	cmp r1, r0
	bne _02022A90
	adds r1, r4, #0
	adds r1, #0x93
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _02022A68
	movs r0, #6
	strb r0, [r1]
_02022A68:
	movs r0, #3
	movs r1, #0x30
	bl sub_0201FED4
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022A88
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x3f
	b _02022AA8
	.align 2, 0
_02022A84: .4byte 0x00004350
_02022A88:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x48
	b _02022AA8
_02022A90:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022AA2
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x40
	b _02022AA8
_02022AA2:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x49
_02022AA8:
	strb r0, [r1]
	adds r5, r1, #0
	bl sub_020209E0
_02022AB0:
	ldr r1, _02022AE0 @ =0x02033680
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #0
	strh r2, [r0]
	adds r0, #0x19
	strb r1, [r0]
	ldrh r1, [r3, #4]
	adds r0, #1
	strb r1, [r0]
_02022AD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02022AE0: .4byte 0x02033680

	thumb_func_start sub_02022AE4
sub_02022AE4: @ 0x02022AE4
	push {r4, lr}
	ldr r4, _02022B20 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022B3C
	ldr r0, [r4, #0x40]
	ldr r1, _02022B24 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _02022B28 @ =0x0000609E
	cmp r0, r1
	bne _02022B2C
	adds r1, r4, #0
	adds r1, #0x93
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x5c
	strb r0, [r1]
	subs r1, #7
	movs r0, #2
	strb r0, [r1]
	subs r1, #9
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
	b _02022B38
	.align 2, 0
_02022B20: .4byte 0x030041A0
_02022B24: .4byte 0x0000FFFF
_02022B28: .4byte 0x0000609E
_02022B2C:
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
_02022B38:
	movs r0, #0
	str r0, [r4, #0x40]
_02022B3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02022B44
sub_02022B44: @ 0x02022B44
	push {r4, r5, lr}
	ldr r4, _02022B78 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022BD6
	adds r1, r4, #0
	adds r1, #0x74
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _02022B8E
	adds r0, #0x1d
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022B7C
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x3c
	b _02022B82
	.align 2, 0
_02022B78: .4byte 0x030041A0
_02022B7C:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x45
_02022B82:
	strb r0, [r1]
	adds r2, r1, #0
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #5
	b _02022BB0
_02022B8E:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022BA0
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x3d
	b _02022BA6
_02022BA0:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x46
_02022BA6:
	strb r0, [r1]
	adds r2, r1, #0
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #7
_02022BB0:
	strb r0, [r1]
	ldr r1, _02022BDC @ =0x02033680
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [r0]
	adds r1, r4, #0
	adds r1, #0x70
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0x89
	strb r2, [r0]
	ldrh r1, [r3, #4]
	adds r0, #1
	strb r1, [r0]
_02022BD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02022BDC: .4byte 0x02033680

	thumb_func_start sub_02022BE0
sub_02022BE0: @ 0x02022BE0
	push {r4, lr}
	ldr r4, _02022C0C @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022C04
	movs r0, #1
	bl sub_0201F78C
	movs r0, #0
	str r0, [r4, #0x40]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
_02022C04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02022C0C: .4byte 0x030041A0

	thumb_func_start sub_02022C10
sub_02022C10: @ 0x02022C10
	push {lr}
	ldr r0, _02022C28 @ =0x030041A0
	ldr r1, _02022C2C @ =0x0203386C
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_02022C28: .4byte 0x030041A0
_02022C2C: .4byte 0x0203386C

	thumb_func_start sub_02022C30
sub_02022C30: @ 0x02022C30
	push {lr}
	ldr r2, _02022C4C @ =0x030041A0
	adds r1, r2, #0
	adds r1, #0x89
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022C50
	subs r1, #1
	movs r0, #0x4a
	b _02022C56
	.align 2, 0
_02022C4C: .4byte 0x030041A0
_02022C50:
	adds r1, r2, #0
	adds r1, #0x88
	movs r0, #0x4f
_02022C56:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022C88 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r3, r2, #0
	adds r3, #0x8a
	movs r1, #0
	strb r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x87
	movs r0, #0x10
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_02022C88: .4byte 0x02033680

	thumb_func_start sub_02022C8C
sub_02022C8C: @ 0x02022C8C
	push {lr}
	ldr r0, _02022CA4 @ =0x030041A0
	ldr r1, _02022CA8 @ =0x020338B8
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_02022CA4: .4byte 0x030041A0
_02022CA8: .4byte 0x020338B8

	thumb_func_start sub_02022CAC
sub_02022CAC: @ 0x02022CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r6, _02022CD0 @ =0x030041A0
	ldr r0, _02022CD4 @ =0x03003710
	mov sb, r0
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _02022CD8
	adds r1, r6, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
	b _02022E32
	.align 2, 0
_02022CD0: .4byte 0x030041A0
_02022CD4: .4byte 0x03003710
_02022CD8:
	adds r0, r6, #0
	adds r0, #0x8a
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _02022D0C
	adds r4, r6, #0
	adds r4, #0x89
	ldrb r0, [r4]
	cmp r0, #2
	bne _02022CF4
	movs r0, #0x1a
	bl sub_02026A38
_02022CF4:
	ldrb r0, [r4]
	cmp r0, #4
	bne _02022D00
	movs r0, #0x1b
	bl sub_02026A38
_02022D00:
	ldrb r0, [r4]
	cmp r0, #8
	bne _02022D0C
	movs r0, #0x1c
	bl sub_02026A38
_02022D0C:
	movs r0, #1
	bl sub_0201FDF4
	adds r5, r0, #0
	cmp r5, #0
	beq _02022D98
	ldr r0, [r6, #0x40]
	ldr r1, _02022D38 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _02022D3C @ =0x0000609E
	cmp r0, r1
	bne _02022D4C
	adds r0, r6, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022D40
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #0x4c
	b _02022D46
	.align 2, 0
_02022D38: .4byte 0x0000FFFF
_02022D3C: .4byte 0x0000609E
_02022D40:
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #0x51
_02022D46:
	strb r0, [r1]
	adds r4, r1, #0
	b _02022D70
_02022D4C:
	adds r0, r6, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022D5E
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #0x4d
	b _02022D64
_02022D5E:
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #0x52
_02022D64:
	strb r0, [r1]
	adds r4, r1, #0
	movs r0, #3
	movs r1, #0x30
	bl sub_0201FED4
_02022D70:
	ldr r1, _02022D94 @ =0x02033680
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0]
	adds r2, r6, #0
	adds r2, #0x89
	movs r0, #0
	strb r0, [r2]
	ldrh r0, [r1, #4]
	strb r0, [r7]
	adds r1, r6, #0
	adds r1, #0x9c
	movs r0, #1
	strb r0, [r1]
	b _02022E32
	.align 2, 0
_02022D94: .4byte 0x02033680
_02022D98:
	movs r1, #0x9e
	adds r1, r1, r6
	mov r8, r1
	ldrb r1, [r1]
	movs r0, #0x54
	muls r1, r0, r1
	ldr r0, _02022E40 @ =0x03004790
	adds r3, r1, r0
	ldrb r0, [r7]
	cmp r0, #1
	bne _02022E32
	adds r0, r6, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #3
	bne _02022E32
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [r6, #0x40]
	mov r1, r8
	ldrb r0, [r1]
	add r0, sb
	ldr r1, _02022E44 @ =0x0000041A
	adds r0, r0, r1
	strb r5, [r0]
	adds r2, r3, #0
	adds r2, #0x4c
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r0, r3, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r6, #0
	adds r4, #0x70
	movs r1, #0
	mov sb, r1
	strh r0, [r4]
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r0, r3, #0
	adds r0, #0x32
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r6, #0
	adds r3, #0x6e
	strh r0, [r3]
	adds r7, r6, #0
	adds r7, #0x76
	ldr r0, _02022E48 @ =0x00002A30
	strh r0, [r7]
	ldr r0, _02022E4C @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x6d
	bl __modsi3
	movs r1, #0x64
	muls r0, r1, r0
	ldrh r1, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	str r5, [r6, #0x38]
	str r5, [r6, #0x3c]
	mov r1, sb
	mov r0, r8
	strb r1, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02022E50 @ =0x0202F7FC
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r0, [r6, #0x40]
	orrs r0, r1
	str r0, [r6, #0x40]
_02022E32:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02022E40: .4byte 0x03004790
_02022E44: .4byte 0x0000041A
_02022E48: .4byte 0x00002A30
_02022E4C: .4byte 0x03001B50
_02022E50: .4byte 0x0202F7FC

	thumb_func_start sub_02022E54
sub_02022E54: @ 0x02022E54
	push {r4, lr}
	ldr r4, _02022E84 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022EB4
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r1, [r1]
	bl sub_0201EFB8
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022E88
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x4b
	b _02022E8E
	.align 2, 0
_02022E84: .4byte 0x030041A0
_02022E88:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x50
_02022E8E:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022EBC @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0]
	adds r2, r4, #0
	adds r2, #0x89
	movs r0, #0
	strb r0, [r2]
	ldrh r0, [r1, #4]
	adds r2, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #2
	strb r0, [r1]
_02022EB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02022EBC: .4byte 0x02033680

	thumb_func_start sub_02022EC0
sub_02022EC0: @ 0x02022EC0
	push {r4, lr}
	ldr r4, _02022F04 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _02022F20
	movs r0, #1
	bl sub_0201F78C
	ldr r0, [r4, #0x40]
	ldr r1, _02022F08 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _02022F0C @ =0x0000609E
	cmp r0, r1
	bne _02022F10
	adds r1, r4, #0
	adds r1, #0x93
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x40]
	adds r1, #4
	movs r0, #0x5c
	strb r0, [r1]
	subs r1, #7
	movs r0, #2
	strb r0, [r1]
	subs r1, #9
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
	b _02022F20
	.align 2, 0
_02022F04: .4byte 0x030041A0
_02022F08: .4byte 0x0000FFFF
_02022F0C: .4byte 0x0000609E
_02022F10:
	movs r0, #0
	str r0, [r4, #0x40]
	adds r1, r4, #0
	adds r1, #0x87
	movs r0, #2
	strb r0, [r1]
	bl sub_02021720
_02022F20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02022F28
sub_02022F28: @ 0x02022F28
	push {lr}
	ldr r3, _02022F40 @ =0x030041A0
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022F44
	adds r1, r3, #0
	adds r1, #0x88
	movs r0, #0x28
	b _02022F4A
	.align 2, 0
_02022F40: .4byte 0x030041A0
_02022F44:
	adds r1, r3, #0
	adds r1, #0x88
	movs r0, #0x30
_02022F4A:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _02022F80 @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	movs r1, #0x8a
	movs r2, #0
	strb r0, [r1, r3]
	adds r0, r3, #0
	adds r0, #0x89
	strb r2, [r0]
	subs r0, #0x1b
	movs r1, #0
	strh r2, [r0]
	adds r0, #0x2e
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x87
	movs r0, #0x12
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_02022F80: .4byte 0x02033680

	thumb_func_start sub_02022F84
sub_02022F84: @ 0x02022F84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _02022FFC @ =0x030041A0
	ldr r6, _02023000 @ =0x03003710
	adds r0, r4, #0
	adds r0, #0x7a
	ldrb r7, [r0]
	movs r0, #0
	mov sb, r0
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02022FB4
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #3
	bne _02022FB4
	movs r0, #0x21
	bl sub_02026A38
_02022FB4:
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	bne _02022FC0
	b _02023110
_02022FC0:
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0202302C
	ldr r1, _02023004 @ =0x0600C800
	mov ip, r1
	lsls r0, r7, #1
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r6, r2
	adds r1, r1, r0
	ldrh r3, [r1]
	adds r2, r3, #0
	ldr r1, _02023008 @ =0x00000FFF
	adds r5, r0, #0
	cmp r2, r1
	bne _0202300C
	movs r0, #1
	mov sb, r0
	b _02023018
	.align 2, 0
_02022FFC: .4byte 0x030041A0
_02023000: .4byte 0x03003710
_02023004: .4byte 0x0600C800
_02023008: .4byte 0x00000FFF
_0202300C:
	mov r1, r8
	strh r3, [r1]
	cmp r2, #0x56
	bls _02023018
	movs r0, #0x1e
	strh r0, [r1]
_02023018:
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r0, r0, r5
	ldr r1, _02023028 @ =0x00007777
	strh r1, [r0]
	b _02023068
	.align 2, 0
_02023028: .4byte 0x00007777
_0202302C:
	ldr r0, _0202304C @ =0x0600C000
	mov ip, r0
	lsls r1, r7, #1
	adds r2, r6, #0
	adds r2, #0x10
	adds r0, r2, r1
	ldrh r6, [r0]
	adds r3, r6, #0
	ldr r0, _02023050 @ =0x00000FFF
	adds r5, r1, #0
	cmp r3, r0
	bne _02023054
	movs r1, #1
	mov sb, r1
	b _02023062
	.align 2, 0
_0202304C: .4byte 0x0600C000
_02023050: .4byte 0x00000FFF
_02023054:
	mov r0, r8
	strh r6, [r0]
	cmp r3, #0x56
	bls _02023062
	movs r0, #0x1e
	mov r1, r8
	strh r0, [r1]
_02023062:
	adds r1, r2, r5
	ldr r0, _02023098 @ =0x00007777
	strh r0, [r1]
_02023068:
	movs r0, #0xf0
	ands r0, r7
	lsls r0, r0, #3
	add ip, r0
	movs r0, #0xf
	ands r7, r0
	lsls r0, r7, #2
	add ip, r0
	ldr r1, _0202309C @ =0x000012AC
	mov r0, ip
	bl sub_02020A0C
	mov r2, sb
	cmp r2, #0
	bne _020230D0
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020230A0
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x2b
	b _020230A6
	.align 2, 0
_02023098: .4byte 0x00007777
_0202309C: .4byte 0x000012AC
_020230A0:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x33
_020230A6:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _020230CC @ =0x0202F7FC
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	str r1, [r4, #0x40]
	ldrh r0, [r0, #4]
	orrs r0, r1
	str r0, [r4, #0x40]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #2
	b _020230F2
	.align 2, 0
_020230CC: .4byte 0x0202F7FC
_020230D0:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _020230E2
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x2a
	b _020230E8
_020230E2:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x32
_020230E8:
	strb r0, [r1]
	adds r2, r1, #0
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #1
_020230F2:
	strb r0, [r1]
	ldr r1, _0202311C @ =0x02033680
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
_02023110:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0202311C: .4byte 0x02033680

	thumb_func_start sub_02023120
sub_02023120: @ 0x02023120
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _02023170 @ =0x030041A0
	ldr r0, _02023174 @ =0x03003710
	mov sb, r0
	adds r0, r5, #0
	adds r0, #0x7a
	ldrb r7, [r0]
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	bne _02023140
	b _020232EC
_02023140:
	movs r1, #0
	mov r8, r1
	ldr r1, _02023178 @ =0x02033680
	adds r2, r5, #0
	adds r2, #0x88
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x8a
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x89
	mov r1, r8
	strb r1, [r0]
	adds r0, #2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202317C
	movs r0, #0x29
	b _0202317E
	.align 2, 0
_02023170: .4byte 0x030041A0
_02023174: .4byte 0x03003710
_02023178: .4byte 0x02033680
_0202317C:
	movs r0, #0x31
_0202317E:
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #4
	strb r0, [r1]
	subs r1, #0x20
	ldr r0, _020231FC @ =0x00001270
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #3
	bne _0202320A
	adds r2, r5, #0
	adds r2, #0x93
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _020231AE
	movs r0, #0
	strb r0, [r2]
_020231AE:
	bl sub_020209E0
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	cmp r0, #0
	beq _02023204
	adds r4, r0, #0
	subs r4, #1
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _02023200 @ =0x0202F7FC
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r5, #0x40]
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r6, [r0]
	adds r0, r4, #0
	bl sub_02020A24
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _020231F4
	adds r0, r4, #0
	bl sub_02020A24
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	mov r8, r0
_020231F4:
	movs r0, #0
	bl sub_0201FE6C
	b _02023254
	.align 2, 0
_020231FC: .4byte 0x00001270
_02023200: .4byte 0x0202F7FC
_02023204:
	bl sub_0201FB9C
	b _020232EC
_0202320A:
	ldr r0, _0202322C @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x65
	bl __modsi3
	cmp r0, #0x31
	bgt _02023234
	ldr r0, _02023230 @ =0x0080609E
	str r0, [r5, #0x40]
	movs r0, #0x11
	bl sub_02024AEC
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _02023254
	.align 2, 0
_0202322C: .4byte 0x03001B50
_02023230: .4byte 0x0080609E
_02023234:
	ldr r0, _02023298 @ =0x008050C0
	str r0, [r5, #0x40]
	ldr r6, _0202329C @ =0x00002512
	adds r1, r5, #0
	adds r1, #0x93
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _02023250
	movs r0, #6
	strb r0, [r1]
_02023250:
	bl sub_020209E0
_02023254:
	adds r0, r5, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _020232AC
	lsls r1, r7, #1
	mov r0, sb
	adds r0, #0x10
	adds r0, r0, r1
	ldr r1, _020232A0 @ =0x00007777
	strh r1, [r0]
	ldr r0, _020232A4 @ =0x03001B40
	ldr r2, [r0]
	movs r4, #0xf
	ands r4, r7
	lsls r1, r4, #1
	lsrs r3, r7, #4
	lsls r0, r3, #5
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x24
	adds r0, r0, r1
	strh r6, [r0]
	mov r1, r8
	cmp r1, #0
	bne _020232EC
	lsls r0, r3, #1
	ldr r5, _020232A8 @ =0x000018F8
	adds r2, r2, r5
	b _020232E0
	.align 2, 0
_02023298: .4byte 0x008050C0
_0202329C: .4byte 0x00002512
_020232A0: .4byte 0x00007777
_020232A4: .4byte 0x03001B40
_020232A8: .4byte 0x000018F8
_020232AC:
	lsls r1, r7, #1
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r1
	ldr r1, _020232F8 @ =0x00007777
	strh r1, [r0]
	ldr r0, _020232FC @ =0x03001B40
	ldr r2, [r0]
	movs r4, #0xf
	ands r4, r7
	lsls r1, r4, #1
	lsrs r3, r7, #4
	lsls r0, r3, #5
	adds r1, r1, r0
	movs r5, #0x89
	lsls r5, r5, #2
	adds r0, r2, r5
	adds r0, r0, r1
	strh r6, [r0]
	mov r0, r8
	cmp r0, #0
	bne _020232EC
	lsls r0, r3, #1
	ldr r1, _02023300 @ =0x00001918
	adds r2, r2, r1
_020232E0:
	adds r2, r2, r0
	movs r0, #1
	lsls r0, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_020232EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020232F8: .4byte 0x00007777
_020232FC: .4byte 0x03001B40
_02023300: .4byte 0x00001918

	thumb_func_start sub_02023304
sub_02023304: @ 0x02023304
	push {r4, r5, lr}
	ldr r4, _02023330 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _020233D8
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r1, #0xf
	bne _0202334E
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023334
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x2d
	b _0202333A
	.align 2, 0
_02023330: .4byte 0x030041A0
_02023334:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x35
_0202333A:
	strb r0, [r1]
	adds r5, r1, #0
	adds r1, r4, #0
	adds r1, #0x93
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x5b
	strb r0, [r1]
	b _020233AE
_0202334E:
	cmp r1, #0
	beq _0202336C
	cmp r1, #0xc
	beq _0202336C
	cmp r1, #0x10
	beq _0202336C
	subs r0, #0x45
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bls _0202336C
	cmp r1, #0x54
	beq _0202336C
	cmp r1, #0x56
	bne _0202338A
_0202336C:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202337E
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x2f
	b _02023384
_0202337E:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x37
_02023384:
	strb r0, [r1]
	adds r5, r1, #0
	b _020233AE
_0202338A:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202339C
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x2e
	b _020233A2
_0202339C:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x36
_020233A2:
	strb r0, [r1]
	adds r5, r1, #0
	movs r0, #3
	movs r1, #0x30
	bl sub_0201FED4
_020233AE:
	ldr r1, _020233E0 @ =0x02033680
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #5
	strb r0, [r1]
	movs r0, #0x1c
	bl sub_02026A38
_020233D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020233E0: .4byte 0x02033680

	thumb_func_start sub_020233E4
sub_020233E4: @ 0x020233E4
	push {r4, r5, lr}
	ldr r4, _02023444 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _020234A6
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r2, [r1]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r1, #0
	cmp r0, #1
	bls _02023432
	adds r0, r2, #0
	cmp r0, #8
	beq _02023432
	cmp r0, #9
	beq _02023432
	cmp r0, #0xa
	beq _02023432
	cmp r0, #0xb
	beq _02023432
	cmp r0, #0xe
	beq _02023432
	cmp r0, #0x42
	beq _02023432
	cmp r0, #0x43
	beq _02023432
	cmp r0, #0x44
	beq _02023432
	cmp r0, #0x52
	beq _02023432
	cmp r0, #0x53
	beq _02023432
	cmp r0, #0x55
	bne _02023438
_02023432:
	ldrh r0, [r5]
	bl sub_0201F8FC
_02023438:
	ldrh r0, [r5]
	cmp r0, #0xf
	bne _02023448
	bl sub_0201FB9C
	b _0202345E
	.align 2, 0
_02023444: .4byte 0x030041A0
_02023448:
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2]
	ldr r0, _02023470 @ =0x00003260
	cmp r1, r0
	beq _0202345E
	adds r0, #8
	cmp r1, r0
	beq _0202345E
	ldr r0, _02023474 @ =0x00001270
	strh r0, [r2]
_0202345E:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023478
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x29
	b _0202347E
	.align 2, 0
_02023470: .4byte 0x00003260
_02023474: .4byte 0x00001270
_02023478:
	adds r1, r4, #0
	adds r1, #0x88
	movs r0, #0x31
_0202347E:
	strb r0, [r1]
	adds r0, r1, #0
	ldr r1, _020234AC @ =0x02033680
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #4
	strb r0, [r1]
_020234A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020234AC: .4byte 0x02033680

	thumb_func_start sub_020234B0
sub_020234B0: @ 0x020234B0
	push {r4, r5, r6, r7, lr}
	ldr r5, _020235C0 @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x7a
	ldrh r2, [r0]
	ldrb r6, [r0]
	adds r0, #0x10
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023528
	adds r0, r5, #0
	adds r0, #0x89
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0xe
	bne _020234F8
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	ldr r3, _020235C4 @ =0x0600C800
	cmp r0, #0
	bne _020234DE
	ldr r3, _020235C8 @ =0x0600C000
_020234DE:
	movs r0, #0xf0
	ands r0, r6
	lsls r0, r0, #3
	adds r3, r3, r0
	movs r0, #0xf
	ands r0, r6
	lsls r0, r0, #2
	adds r3, r3, r0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r3, #0
	bl sub_02020A0C
_020234F8:
	adds r0, r5, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023528
	adds r4, r7, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _02023510
	movs r0, #0x1e
	bl sub_02026A38
_02023510:
	ldrb r0, [r4]
	cmp r0, #0xa
	bne _0202351C
	movs r0, #0x22
	bl sub_02026A38
_0202351C:
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _02023528
	movs r0, #0x23
	bl sub_02026A38
_02023528:
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _0202361E
	movs r1, #0
	str r1, [r5, #0x40]
	adds r0, r5, #0
	adds r0, #0xb7
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x7a
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	ldr r3, _020235C4 @ =0x0600C800
	adds r7, r2, #0
	cmp r0, #0
	bne _02023556
	ldr r3, _020235C8 @ =0x0600C000
_02023556:
	movs r0, #0xf0
	ands r0, r6
	lsls r0, r0, #3
	adds r3, r3, r0
	movs r0, #0xf
	ands r6, r0
	lsls r0, r6, #2
	adds r3, r3, r0
	adds r4, r5, #0
	adds r4, #0x7c
	ldrh r1, [r4]
	adds r0, r3, #0
	bl sub_02020A0C
	adds r1, r5, #0
	adds r1, #0x78
	movs r6, #0
	movs r0, #0x78
	strh r0, [r1]
	ldrh r1, [r4]
	ldr r0, _020235CC @ =0x00001270
	cmp r1, r0
	beq _0202358A
	movs r0, #0x24
	bl sub_02026A38
_0202358A:
	adds r0, r5, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x5b
	bne _020235D0
	adds r0, r5, #0
	adds r0, #0xb2
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #2
	strh r0, [r1]
	adds r1, #0x2b
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x93
	strb r6, [r0]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	subs r1, #9
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
	b _0202361A
	.align 2, 0
_020235C0: .4byte 0x030041A0
_020235C4: .4byte 0x0600C800
_020235C8: .4byte 0x0600C000
_020235CC: .4byte 0x00001270
_020235D0:
	adds r1, r5, #0
	adds r1, #0x99
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb2
	strb r6, [r0]
	subs r0, #0x29
	strb r6, [r0]
	adds r4, r5, #0
	adds r4, #0x8a
	strb r6, [r4]
	bl sub_02020790
	ldr r1, _02023624 @ =0x02033680
	adds r0, r5, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r4]
	ldr r0, [r5, #8]
	str r0, [r5, #0x10]
	ldr r0, [r5, #0xc]
	str r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #2
	strh r0, [r1]
	adds r1, #0x19
	movs r0, #4
	strb r0, [r1]
	bl sub_020218B0
_0202361A:
	movs r0, #0
	strh r0, [r7]
_0202361E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02023624: .4byte 0x02033680

	thumb_func_start sub_02023628
sub_02023628: @ 0x02023628
	push {r4, lr}
	ldr r4, _02023654 @ =0x030041A0
	movs r0, #1
	bl sub_0201FDF4
	cmp r0, #0
	beq _020236A6
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0x2f
	beq _02023646
	cmp r1, #0x37
	bne _02023670
_02023646:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023658
	movs r0, #0x29
	b _0202365A
	.align 2, 0
_02023654: .4byte 0x030041A0
_02023658:
	movs r0, #0x31
_0202365A:
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #4
	strb r0, [r1]
	subs r1, #0x20
	ldr r0, _0202366C @ =0x00001270
	strh r0, [r1]
	b _0202368A
	.align 2, 0
_0202366C: .4byte 0x00001270
_02023670:
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202367E
	movs r0, #0x2c
	b _02023680
_0202367E:
	movs r0, #0x34
_02023680:
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #3
	strb r0, [r1]
_0202368A:
	ldr r1, _020236AC @ =0x02033680
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r2, r4, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x89
	strb r1, [r0]
_020236A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_020236AC: .4byte 0x02033680

	thumb_func_start sub_020236B0
sub_020236B0: @ 0x020236B0
	push {lr}
	ldr r0, _020236C8 @ =0x030041A0
	ldr r1, _020236CC @ =0x0203388C
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_020236C8: .4byte 0x030041A0
_020236CC: .4byte 0x0203388C

	thumb_func_start sub_020236D0
sub_020236D0: @ 0x020236D0
	push {r4, lr}
	ldr r0, _0202372C @ =0x030041A0
	mov ip, r0
	adds r0, #0x89
	movs r2, #0
	strb r2, [r0]
	mov r4, ip
	adds r4, #0x8a
	strb r2, [r4]
	mov r0, ip
	adds r0, #0x6e
	movs r3, #0
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #0x18
	movs r1, #0x5e
	strb r1, [r0]
	ldr r0, _02023730 @ =0x02033680
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r4]
	mov r1, ip
	adds r1, #0x80
	ldr r0, _02023734 @ =0x00002A30
	strh r0, [r1]
	mov r1, ip
	str r2, [r1, #0x10]
	str r2, [r1, #0x14]
	ldr r0, [r1]
	str r0, [r1, #8]
	ldr r0, [r1, #4]
	str r0, [r1, #0xc]
	mov r0, ip
	adds r0, #0x9c
	strb r3, [r0]
	adds r1, #0x87
	movs r0, #0x14
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0202372C: .4byte 0x030041A0
_02023730: .4byte 0x02033680
_02023734: .4byte 0x00002A30

	thumb_func_start sub_02023738
sub_02023738: @ 0x02023738
	push {r4, r5, lr}
	ldr r5, _0202375C @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #2
	bne _02023760
	adds r0, r5, #0
	adds r0, #0x6e
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #3
	strb r0, [r1]
	b _020237D2
	.align 2, 0
_0202375C: .4byte 0x030041A0
_02023760:
	movs r0, #0
	bl sub_0201FDF4
	adds r0, r5, #0
	adds r0, #0x80
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x8a
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	bne _02023792
	adds r0, #9
	ldrb r0, [r0]
	cmp r0, #2
	bne _02023792
	movs r0, #4
	movs r1, #0x20
	bl sub_0201FED4
	movs r0, #0x25
	bl sub_02026A38
_02023792:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _020237D2
	ldr r2, _020237D8 @ =0x03001B50
	ldr r0, _020237DC @ =0x00000824
	adds r3, r2, r0
	ldrh r0, [r3]
	movs r1, #0x40
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _020237E0 @ =0x00000826
	adds r3, r2, r0
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _020237E4 @ =0x00000828
	adds r2, r2, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	subs r0, #0x16
	strh r4, [r0]
	adds r0, #0x2e
	strb r1, [r0]
_020237D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020237D8: .4byte 0x03001B50
_020237DC: .4byte 0x00000824
_020237E0: .4byte 0x00000826
_020237E4: .4byte 0x00000828

	thumb_func_start sub_020237E8
sub_020237E8: @ 0x020237E8
	push {r4, r5, r6, lr}
	ldr r0, _02023894 @ =0x030041A0
	mov ip, r0
	ldr r2, _02023898 @ =0x03003BC4
	ldr r4, _0202389C @ =0x03004B80
	mov r1, ip
	adds r1, #0x6e
	ldr r3, _020238A0 @ =0x00001111
	adds r0, r3, #0
	ldrh r5, [r1]
	adds r0, r0, r5
	movs r6, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	ldr r1, _020238A4 @ =0xFFFF0000
	cmp r0, r1
	bne _02023882
	ldr r0, [r2]
	lsls r0, r0, #8
	mov r1, ip
	str r0, [r1]
	ldr r1, [r2, #4]
	lsls r1, r1, #8
	movs r3, #0x80
	lsls r3, r3, #5
	adds r2, r1, r3
	mov r5, ip
	str r2, [r5, #4]
	str r1, [r4, #4]
	adds r0, r0, r3
	str r0, [r4]
	ldr r4, _020238A8 @ =0x03001B50
	asrs r0, r0, #8
	subs r0, #0x80
	movs r3, #0x84
	lsls r3, r3, #4
	adds r2, r4, r3
	strh r0, [r2]
	asrs r1, r1, #8
	subs r1, #0x50
	ldr r5, _020238AC @ =0x00000842
	adds r3, r4, r5
	strh r1, [r3]
	subs r5, #0x42
	ands r1, r5
	cmp r1, #0
	beq _02023848
	strh r6, [r3]
_02023848:
	ldrh r0, [r3]
	cmp r0, #0x60
	bls _02023852
	movs r0, #0x60
	strh r0, [r3]
_02023852:
	ldrh r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0202385E
	strh r6, [r2]
_0202385E:
	ldrh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bls _0202386A
	strh r1, [r2]
_0202386A:
	ldrh r1, [r2]
	ldr r2, _020238B0 @ =0x00000844
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r3, _020238B4 @ =0x00000846
	adds r0, r4, r3
	strh r1, [r0]
	mov r1, ip
	adds r1, #0x9c
	movs r0, #2
	strb r0, [r1]
_02023882:
	ldr r0, _020238B8 @ =0x0400004C
	mov r1, ip
	adds r1, #0x6e
	ldrh r1, [r1]
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_02023894: .4byte 0x030041A0
_02023898: .4byte 0x03003BC4
_0202389C: .4byte 0x03004B80
_020238A0: .4byte 0x00001111
_020238A4: .4byte 0xFFFF0000
_020238A8: .4byte 0x03001B50
_020238AC: .4byte 0x00000842
_020238B0: .4byte 0x00000844
_020238B4: .4byte 0x00000846
_020238B8: .4byte 0x0400004C

	thumb_func_start sub_020238BC
sub_020238BC: @ 0x020238BC
	push {r4, r5, r6, r7, lr}
	ldr r0, _02023944 @ =0x030041A0
	mov ip, r0
	ldr r7, _02023948 @ =0x03003710
	mov r5, ip
	adds r5, #0x6e
	ldr r1, _0202394C @ =0xFFFFEEEF
	adds r0, r1, #0
	ldrh r1, [r5]
	adds r0, r0, r1
	movs r6, #0
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _02023938
	ldr r1, _02023950 @ =0x03001B50
	ldr r0, _02023954 @ =0x00000824
	adds r2, r1, r0
	ldrh r0, [r2]
	movs r3, #0x40
	eors r0, r3
	strh r0, [r2]
	ldr r0, _02023958 @ =0x00000826
	adds r2, r1, r0
	ldrh r0, [r2]
	eors r0, r3
	strh r0, [r2]
	ldr r0, _0202395C @ =0x00000828
	adds r1, r1, r0
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x84
	strb r6, [r0]
	mov r1, ip
	str r4, [r1, #0x10]
	str r4, [r1, #0x14]
	ldr r1, _02023960 @ =0x0000049A
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x8e
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x93
	strb r6, [r0]
	adds r1, #0xb
	movs r0, #0x80
	strb r0, [r1]
	subs r1, #2
	movs r0, #0x5b
	strb r0, [r1]
	subs r1, #7
	movs r0, #1
	strb r0, [r1]
	subs r1, #9
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
_02023938:
	ldr r1, _02023964 @ =0x0400004C
	ldrh r0, [r5]
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02023944: .4byte 0x030041A0
_02023948: .4byte 0x03003710
_0202394C: .4byte 0xFFFFEEEF
_02023950: .4byte 0x03001B50
_02023954: .4byte 0x00000824
_02023958: .4byte 0x00000826
_0202395C: .4byte 0x00000828
_02023960: .4byte 0x0000049A
_02023964: .4byte 0x0400004C

	thumb_func_start sub_02023968
sub_02023968: @ 0x02023968
	push {lr}
	ldr r3, _02023990 @ =0x030041A0
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #1
	bne _0202398C
	adds r1, r3, #0
	adds r1, #0x70
	movs r2, #0
	movs r0, #0x10
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x6e
	strh r2, [r0]
	adds r1, #0x2c
	movs r0, #4
	strb r0, [r1]
_0202398C:
	pop {r0}
	bx r0
	.align 2, 0
_02023990: .4byte 0x030041A0

	thumb_func_start sub_02023994
sub_02023994: @ 0x02023994
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _020239CC @ =0x030041A0
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	bne _020239B2
	b _02023B1E
_020239B2:
	adds r0, r5, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	mov r8, r0
	cmp r1, #5
	bls _020239C0
	b _02023B1E
_020239C0:
	lsls r0, r1, #2
	ldr r1, _020239D0 @ =_020239D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_020239CC: .4byte 0x030041A0
_020239D0: .4byte _020239D4
_020239D4: @ jump table
	.4byte _020239EC @ case 0
	.4byte _02023A12 @ case 1
	.4byte _02023A1A @ case 2
	.4byte _02023A34 @ case 3
	.4byte _02023A4E @ case 4
	.4byte _02023AE6 @ case 5
_020239EC:
	movs r0, #1
	movs r1, #0x30
	bl sub_0201FED4
	adds r1, r5, #0
	adds r1, #0x89
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x70
	movs r0, #0x30
	strh r0, [r1]
	b _02023B1E
_02023A12:
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #2
	b _02023A20
_02023A1A:
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #6
_02023A20:
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x70
	movs r0, #0x20
	strh r0, [r1]
	b _02023B1E
_02023A34:
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x70
	movs r0, #0x10
	strh r0, [r1]
	b _02023B1E
_02023A4E:
	ldr r1, [r5, #8]
	ldr r0, [r5]
	subs r2, r1, r0
	str r2, [r5, #0x20]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #4]
	subs r0, r0, r1
	str r0, [r5, #0x24]
	cmp r2, #0
	bge _02023A66
	rsbs r0, r2, #0
	str r0, [r5, #0x20]
_02023A66:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	bge _02023A70
	rsbs r0, r0, #0
	str r0, [r5, #0x24]
_02023A70:
	ldr r0, [r5, #0x20]
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bgt _02023A80
	ldr r0, [r5, #0x24]
	cmp r0, r1
	ble _02023AD6
_02023A80:
	adds r0, r5, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	bl sub_0201F538
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x48
_02023A90:
	ldrh r0, [r4]
	ldr r1, [r5, #0x44]
	bl sub_0201F6DC
	adds r6, r0, #0
	cmp r6, #0
	bne _02023AD6
	adds r4, #2
	adds r7, #1
	cmp r7, #3
	ble _02023A90
	adds r1, r5, #0
	adds r1, #0x97
	movs r0, #0x59
	strb r0, [r1]
	subs r1, #4
	ldrb r0, [r1]
	cmp r0, #2
	bhi _02023ABE
	movs r0, #3
	strb r0, [r1]
	bl sub_020209E0
_02023ABE:
	adds r0, r5, #0
	adds r0, #0x99
	strb r6, [r0]
	subs r0, #0x15
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x87
	movs r0, #7
	strb r0, [r1]
	bl sub_02021FA4
	b _02023B1E
_02023AD6:
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #2
	strh r1, [r0]
	movs r0, #5
	mov r1, r8
	strh r0, [r1]
	b _02023B1E
_02023AE6:
	ldr r0, [r5]
	str r0, [r5, #8]
	ldr r0, [r5, #4]
	str r0, [r5, #0xc]
	ldr r2, _02023B28 @ =0x03001B50
	ldr r0, _02023B2C @ =0x00000824
	adds r3, r2, r0
	ldrh r0, [r3]
	movs r1, #0x40
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _02023B30 @ =0x00000826
	adds r3, r2, r0
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _02023B34 @ =0x00000828
	adds r2, r2, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	mov r1, r8
	strh r4, [r1]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #1
	strb r0, [r1]
_02023B1E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02023B28: .4byte 0x03001B50
_02023B2C: .4byte 0x00000824
_02023B30: .4byte 0x00000826
_02023B34: .4byte 0x00000828

	thumb_func_start sub_02023B38
sub_02023B38: @ 0x02023B38
	push {lr}
	ldr r0, _02023B50 @ =0x030041A0
	ldr r1, _02023B54 @ =0x020338A4
	adds r0, #0x9c
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_02023B50: .4byte 0x030041A0
_02023B54: .4byte 0x020338A4

	thumb_func_start sub_02023B58
sub_02023B58: @ 0x02023B58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _02023C80 @ =0x030041A0
	mov ip, r0
	ldr r0, [r0, #4]
	asrs r0, r0, #8
	mov r1, ip
	str r0, [r1, #0x24]
	ldr r0, [r1]
	asrs r0, r0, #8
	str r0, [r1, #0x20]
	ldr r2, _02023C84 @ =0x02033680
	mov r0, ip
	adds r0, #0x88
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r0, #1
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r6, [r0]
	mov r0, ip
	adds r0, #0x8a
	ldrb r0, [r0]
	cmp r0, #0xfe
	bne _02023B9C
	b _02023EBE
_02023B9C:
	movs r2, #0
	str r2, [sp]
	ldrh r0, [r6, #6]
	ldr r1, _02023C88 @ =0x0000FFFF
	cmp r0, r1
	bne _02023BAA
	b _02023EBE
_02023BAA:
	ldr r3, _02023C8C @ =0xFFFFFC00
	mov sl, r3
_02023BAE:
	ldr r1, _02023C90 @ =0x030023B0
	ldrb r0, [r1]
	lsls r0, r0, #3
	ldr r2, _02023C94 @ =0x03002410
	adds r4, r0, r2
	mov r3, ip
	ldr r0, [r3, #0x24]
	ldrb r1, [r6]
	adds r1, r1, r0
	ldr r2, _02023C98 @ =0x03001B50
	ldr r3, _02023C9C @ =0x00000846
	adds r0, r2, r3
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r4]
	ldrb r1, [r6, #1]
	movs r0, #0xc
	ands r0, r1
	ldrb r1, [r4, #1]
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #1]
	ldrb r0, [r6, #1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #5
	subs r1, #0x22
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, #1]
	ldrb r0, [r6, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	movs r3, #0x3f
	ands r3, r1
	orrs r3, r0
	strb r3, [r4, #1]
	ldrb r0, [r6, #3]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1f
	movs r2, #1
	ands r0, r2
	lsls r0, r0, #4
	ldrb r1, [r4, #3]
	subs r2, #0x12
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #3]
	ldrb r0, [r6, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #5
	subs r1, #0x22
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, #3]
	ldrb r0, [r6, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	movs r2, #0x3f
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #3]
	movs r0, #0x10
	orrs r3, r0
	strb r3, [r4, #1]
	ldrh r0, [r6, #2]
	lsls r0, r0, #0x17
	lsrs r3, r0, #0x17
	mov r0, ip
	adds r0, #0x88
	ldrb r0, [r0]
	ldr r1, _02023CA0 @ =0x02033AC4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _02023CAA
	ldrb r0, [r6, #3]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1f
	movs r1, #1
	eors r0, r1
	ands r0, r1
	lsls r0, r0, #4
	subs r1, #0x12
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #3]
	mvns r3, r3
	adds r3, #1
	ldr r1, [r4]
	ldr r0, _02023CA4 @ =0xC000C000
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	bne _02023CA8
	subs r3, #0x10
	b _02023CAA
	.align 2, 0
_02023C80: .4byte 0x030041A0
_02023C84: .4byte 0x02033680
_02023C88: .4byte 0x0000FFFF
_02023C8C: .4byte 0xFFFFFC00
_02023C90: .4byte 0x030023B0
_02023C94: .4byte 0x03002410
_02023C98: .4byte 0x03001B50
_02023C9C: .4byte 0x00000846
_02023CA0: .4byte 0x02033AC4
_02023CA4: .4byte 0xC000C000
_02023CA8:
	subs r3, #8
_02023CAA:
	mov r2, ip
	ldr r1, [r2, #0x20]
	adds r1, r3, r1
	ldr r3, _02023DB4 @ =0x03001B50
	ldr r2, _02023DB8 @ =0x00000844
	adds r0, r3, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r3, _02023DBC @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	ldr r0, _02023DC0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrb r1, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #5]
	ldrb r1, [r6, #5]
	lsrs r1, r1, #4
	lsls r1, r1, #4
	movs r2, #0xf
	mov sb, r2
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x16
	ldr r7, _02023DC4 @ =0x000003FF
	lsrs r0, r0, #0x16
	ldrh r1, [r4, #4]
	ldr r3, _02023DC8 @ =0xFFFFFC00
	mov r8, r3
	mov r2, r8
	ands r2, r1
	orrs r2, r0
	strh r2, [r4, #4]
	mov r0, ip
	ldr r3, [r0, #0x40]
	ldr r0, _02023DCC @ =0xFFFF0000
	ands r0, r3
	cmp r0, #0
	beq _02023D44
	ldr r5, _02023DD0 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r5
	cmp r0, #0
	beq _02023D44
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	lsrs r0, r3, #0x10
	ands r0, r5
	cmp r1, r0
	bne _02023D44
	ldr r0, _02023DD4 @ =0x00000FFF
	ands r3, r0
	ands r3, r7
	mov r1, r8
	ands r2, r1
	orrs r2, r3
	strh r2, [r4, #4]
	mov r2, ip
	ldr r1, [r2, #0x40]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrb r2, [r4, #5]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
_02023D44:
	mov r0, ip
	adds r0, #0x8d
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #6
	beq _02023D5E
	cmp r1, #8
	beq _02023D5E
	cmp r1, #5
	beq _02023D5E
	cmp r1, #7
	bne _02023D72
_02023D5E:
	ldrb r1, [r4, #5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _02023D72
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r4, #5]
_02023D72:
	mov r0, ip
	adds r0, #0x87
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _02023D84
	b _02023EA0
_02023D84:
	mov r0, ip
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	bne _02023E1E
	ldrh r0, [r6, #4]
	ldr r1, _02023DC4 @ =0x000003FF
	ands r1, r0
	cmp r1, #0x40
	beq _02023DA0
	cmp r1, #0x42
	beq _02023DA0
	b _02023EA0
_02023DA0:
	mov r0, ip
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #1
	beq _02023E00
	cmp r0, #1
	bgt _02023DD8
	cmp r0, #0
	beq _02023DE2
	b _02023EA0
	.align 2, 0
_02023DB4: .4byte 0x03001B50
_02023DB8: .4byte 0x00000844
_02023DBC: .4byte 0x000001FF
_02023DC0: .4byte 0xFFFFFE00
_02023DC4: .4byte 0x000003FF
_02023DC8: .4byte 0xFFFFFC00
_02023DCC: .4byte 0xFFFF0000
_02023DD0: .4byte 0x0000FFFF
_02023DD4: .4byte 0x00000FFF
_02023DD8:
	cmp r0, #2
	beq _02023E0A
	cmp r0, #3
	beq _02023E14
	b _02023EA0
_02023DE2:
	mov r0, ip
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023DF6
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #0x40
	b _02023E9C
_02023DF6:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #0x42
	b _02023E9C
_02023E00:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #0x44
	b _02023E9C
_02023E0A:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #0x46
	b _02023E9C
_02023E14:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #0x48
	b _02023E9C
_02023E1E:
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _02023E30
	cmp r1, #6
	beq _02023E30
	cmp r1, #7
	bne _02023EA0
_02023E30:
	ldrh r0, [r6, #4]
	ldr r1, _02023E54 @ =0x000003FF
	ands r1, r0
	cmp r1, #0
	beq _02023E3E
	cmp r1, #2
	bne _02023EA0
_02023E3E:
	mov r0, ip
	adds r0, #0x90
	ldrb r0, [r0]
	cmp r0, #1
	beq _02023E80
	cmp r0, #1
	bgt _02023E58
	cmp r0, #0
	beq _02023E62
	b _02023EA0
	.align 2, 0
_02023E54: .4byte 0x000003FF
_02023E58:
	cmp r0, #2
	beq _02023E8A
	cmp r0, #3
	beq _02023E94
	b _02023EA0
_02023E62:
	mov r0, ip
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0
	bne _02023E76
	ldrh r1, [r4, #4]
	mov r0, sl
	ands r0, r1
	strh r0, [r4, #4]
	b _02023EA0
_02023E76:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #2
	b _02023E9C
_02023E80:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #4
	b _02023E9C
_02023E8A:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #6
	b _02023E9C
_02023E94:
	ldrh r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	movs r0, #8
_02023E9C:
	orrs r1, r0
	strh r1, [r4, #4]
_02023EA0:
	ldr r3, _02023ED0 @ =0x030023B0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	adds r6, #8
	cmp r0, #0x21
	bgt _02023EBE
	ldrh r0, [r6, #6]
	ldr r1, _02023ED4 @ =0x0000FFFF
	cmp r0, r1
	beq _02023EBE
	b _02023BAE
_02023EBE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02023ED0: .4byte 0x030023B0
_02023ED4: .4byte 0x0000FFFF

	thumb_func_start sub_02023ED8
sub_02023ED8: @ 0x02023ED8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _02023F00 @ =0x00002511
	cmp r1, r0
	beq _02023EF8
	ldr r3, _02023F04 @ =0xFFFFE114
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _02023EF8
	ldr r0, _02023F08 @ =0x0000FEA6
	cmp r1, r0
	bne _02023EFA
_02023EF8:
	movs r2, #1
_02023EFA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02023F00: .4byte 0x00002511
_02023F04: .4byte 0xFFFFE114
_02023F08: .4byte 0x0000FEA6

	thumb_func_start sub_02023F0C
sub_02023F0C: @ 0x02023F0C
	push {lr}
	lsls r0, r0, #0x10
	movs r3, #0
	lsrs r2, r0, #0x10
	ldr r1, _02023F2C @ =0xEA500000
	adds r0, r0, r1
	ldr r1, _02023F30 @ =0x01FB0000
	cmp r0, r1
	bls _02023F24
	ldr r0, _02023F34 @ =0x0000FEA8
	cmp r2, r0
	bne _02023F26
_02023F24:
	movs r3, #1
_02023F26:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_02023F2C: .4byte 0xEA500000
_02023F30: .4byte 0x01FB0000
_02023F34: .4byte 0x0000FEA8

	thumb_func_start sub_02023F38
sub_02023F38: @ 0x02023F38
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _02023F58 @ =0xE2580000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _02023F50
	ldr r0, _02023F5C @ =0x0000FEA4
	cmp r1, r0
	bne _02023F52
_02023F50:
	movs r2, #1
_02023F52:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02023F58: .4byte 0xE2580000
_02023F5C: .4byte 0x0000FEA4

	thumb_func_start sub_02023F60
sub_02023F60: @ 0x02023F60
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	ldr r0, _02023FDC @ =0x00002511
	cmp r2, r0
	beq _02023FD4
	ldr r1, _02023FE0 @ =0xFFFFE114
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _02023FD4
	ldr r0, _02023FE4 @ =0x0000FEA6
	cmp r2, r0
	beq _02023FD4
	ldr r1, _02023FE8 @ =0xFFFFEA50
	adds r0, r2, r1
	lsls r0, r0, #0x10
	ldr r1, _02023FEC @ =0x01FB0000
	cmp r0, r1
	bls _02023FD4
	ldr r0, _02023FF0 @ =0x0000FEA8
	cmp r2, r0
	beq _02023FD4
	ldr r1, _02023FF4 @ =0xFFFFE258
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _02023FD4
	ldr r0, _02023FF8 @ =0x0000FEA4
	cmp r2, r0
	beq _02023FD4
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r2
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	beq _02023FD2
	movs r0, #0xc0
	lsls r0, r0, #6
	cmp r1, r0
	beq _02023FD2
	ldr r0, _02023FFC @ =0x0000FEA1
	cmp r2, r0
	beq _02023FD2
	adds r0, #1
	cmp r2, r0
	beq _02023FD2
	adds r0, #1
	cmp r2, r0
	beq _02023FD2
	adds r0, #2
	cmp r2, r0
	bne _02023FD4
_02023FD2:
	movs r3, #1
_02023FD4:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_02023FDC: .4byte 0x00002511
_02023FE0: .4byte 0xFFFFE114
_02023FE4: .4byte 0x0000FEA6
_02023FE8: .4byte 0xFFFFEA50
_02023FEC: .4byte 0x01FB0000
_02023FF0: .4byte 0x0000FEA8
_02023FF4: .4byte 0xFFFFE258
_02023FF8: .4byte 0x0000FEA4
_02023FFC: .4byte 0x0000FEA1

	thumb_func_start sub_02024000
sub_02024000: @ 0x02024000
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	movs r1, #0xa0
	lsls r1, r1, #0x16
	cmp r0, r1
	bne _02024010
	movs r2, #1
_02024010:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02024018
sub_02024018: @ 0x02024018
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _0202402C @ =0x28040000
	cmp r0, r1
	bne _02024026
	movs r2, #1
_02024026:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0202402C: .4byte 0x28040000

	thumb_func_start sub_02024030
sub_02024030: @ 0x02024030
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024044 @ =0x28030000
	cmp r0, r1
	bne _0202403E
	movs r2, #1
_0202403E:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024044: .4byte 0x28030000

	thumb_func_start sub_02024048
sub_02024048: @ 0x02024048
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _0202405C @ =0x28020000
	cmp r0, r1
	bne _02024056
	movs r2, #1
_02024056:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0202405C: .4byte 0x28020000

	thumb_func_start sub_02024060
sub_02024060: @ 0x02024060
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024074 @ =0x28010000
	cmp r0, r1
	bne _0202406E
	movs r2, #1
_0202406E:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024074: .4byte 0x28010000

	thumb_func_start sub_02024078
sub_02024078: @ 0x02024078
	push {lr}
	lsls r2, r0, #0x10
	movs r3, #0
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x16
	cmp r0, r1
	bne _02024098
	lsrs r0, r2, #0x18
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _02024098
	movs r3, #1
_02024098:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_020240A0
sub_020240A0: @ 0x020240A0
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020240B4 @ =0x28050000
	cmp r0, r1
	bne _020240AE
	movs r2, #1
_020240AE:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020240B4: .4byte 0x28050000

	thumb_func_start sub_020240B8
sub_020240B8: @ 0x020240B8
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020240CC @ =0x28060000
	cmp r0, r1
	bne _020240C6
	movs r2, #1
_020240C6:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020240CC: .4byte 0x28060000

	thumb_func_start sub_020240D0
sub_020240D0: @ 0x020240D0
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020240E4 @ =0x21030000
	cmp r0, r1
	bne _020240DE
	movs r2, #1
_020240DE:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020240E4: .4byte 0x21030000

	thumb_func_start sub_020240E8
sub_020240E8: @ 0x020240E8
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	movs r1, #0x84
	lsls r1, r1, #0x16
	cmp r0, r1
	bne _020240F8
	movs r2, #1
_020240F8:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02024100
sub_02024100: @ 0x02024100
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024114 @ =0x21010000
	cmp r0, r1
	bne _0202410E
	movs r2, #1
_0202410E:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024114: .4byte 0x21010000

	thumb_func_start sub_02024118
sub_02024118: @ 0x02024118
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _0202412C @ =0x21020000
	cmp r0, r1
	bne _02024126
	movs r2, #1
_02024126:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0202412C: .4byte 0x21020000

	thumb_func_start sub_02024130
sub_02024130: @ 0x02024130
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r2, _0202414C @ =0xD6FE0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _02024146
	ldr r0, _02024150 @ =0x0000FEB1
	cmp r1, r0
	bne _02024154
_02024146:
	movs r0, #1
	b _02024156
	.align 2, 0
_0202414C: .4byte 0xD6FE0000
_02024150: .4byte 0x0000FEB1
_02024154:
	movs r0, #0
_02024156:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0202415C
sub_0202415C: @ 0x0202415C
	push {r4, r5, r6, lr}
	lsls r5, r0, #0x10
	lsrs r4, r5, #0x10
	movs r6, #0
	adds r0, r4, #0
	bl sub_02024130
	cmp r0, #0
	bne _02024198
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bne _02024198
	lsrs r1, r5, #0x18
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _02024196
	cmp r1, #9
	beq _02024196
	cmp r1, #0xc
	beq _02024196
	cmp r1, #0xb
	beq _02024196
	cmp r1, #0xe
	bne _02024198
_02024196:
	movs r6, #1
_02024198:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_020241A0
sub_020241A0: @ 0x020241A0
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	movs r1, #0x88
	lsls r1, r1, #0x16
	cmp r0, r1
	bne _020241B0
	movs r2, #1
_020241B0:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_020241B8
sub_020241B8: @ 0x020241B8
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020241CC @ =0x22390000
	cmp r0, r1
	bne _020241C6
	movs r2, #1
_020241C6:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020241CC: .4byte 0x22390000

	thumb_func_start sub_020241D0
sub_020241D0: @ 0x020241D0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _02024210 @ =0x00002201
	cmp r1, r0
	beq _02024208
	adds r0, #0x42
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	beq _02024208
	subs r0, #1
	cmp r1, r0
	bne _0202420A
_02024208:
	movs r2, #1
_0202420A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024210: .4byte 0x00002201

	thumb_func_start sub_02024214
sub_02024214: @ 0x02024214
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024228 @ =0x223A0000
	cmp r0, r1
	bne _02024222
	movs r2, #1
_02024222:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024228: .4byte 0x223A0000

	thumb_func_start sub_0202422C
sub_0202422C: @ 0x0202422C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024240 @ =0x22020000
	cmp r0, r1
	bne _0202423A
	movs r2, #1
_0202423A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024240: .4byte 0x22020000

	thumb_func_start sub_02024244
sub_02024244: @ 0x02024244
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024258 @ =0x223B0000
	cmp r0, r1
	bne _02024252
	movs r2, #1
_02024252:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024258: .4byte 0x223B0000

	thumb_func_start sub_0202425C
sub_0202425C: @ 0x0202425C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024270 @ =0x22030000
	cmp r0, r1
	bne _0202426A
	movs r2, #1
_0202426A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024270: .4byte 0x22030000

	thumb_func_start sub_02024274
sub_02024274: @ 0x02024274
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024288 @ =0x223C0000
	cmp r0, r1
	bne _02024282
	movs r2, #1
_02024282:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024288: .4byte 0x223C0000

	thumb_func_start sub_0202428C
sub_0202428C: @ 0x0202428C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _020242AC @ =0xDDFC0000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _020242A4
	ldr r0, _020242B0 @ =0x0000FEA9
	cmp r1, r0
	bne _020242A6
_020242A4:
	movs r2, #1
_020242A6:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020242AC: .4byte 0xDDFC0000
_020242B0: .4byte 0x0000FEA9

	thumb_func_start sub_020242B4
sub_020242B4: @ 0x020242B4
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _020242CC @ =0xDDD30000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _020242C6
	movs r1, #1
_020242C6:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_020242CC: .4byte 0xDDD30000

	thumb_func_start sub_020242D0
sub_020242D0: @ 0x020242D0
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _020242E8 @ =0xDDBC0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _020242E2
	movs r1, #1
_020242E2:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_020242E8: .4byte 0xDDBC0000

	thumb_func_start sub_020242EC
sub_020242EC: @ 0x020242EC
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _02024304 @ =0xDDB40000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _020242FE
	movs r1, #1
_020242FE:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024304: .4byte 0xDDB40000

	thumb_func_start sub_02024308
sub_02024308: @ 0x02024308
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _02024320 @ =0xDDAC0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0202431A
	movs r1, #1
_0202431A:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024320: .4byte 0xDDAC0000

	thumb_func_start sub_02024324
sub_02024324: @ 0x02024324
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024338 @ =0x251E0000
	cmp r0, r1
	bne _02024332
	movs r2, #1
_02024332:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024338: .4byte 0x251E0000

	thumb_func_start sub_0202433C
sub_0202433C: @ 0x0202433C
	push {r4, lr}
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	adds r2, r0, #0
	movs r4, #0
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bne _0202435E
	lsrs r0, r3, #0x18
	movs r1, #0xf
	ands r0, r1
	cmp r0, #4
	beq _0202436A
_0202435E:
	ldr r0, _02024374 @ =0x0000FEAE
	cmp r2, r0
	beq _0202436A
	adds r0, #1
	cmp r2, r0
	bne _0202436C
_0202436A:
	movs r4, #1
_0202436C:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_02024374: .4byte 0x0000FEAE

	thumb_func_start sub_02024378
sub_02024378: @ 0x02024378
	push {r4, lr}
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	adds r2, r0, #0
	movs r4, #0
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bne _0202439A
	lsrs r0, r3, #0x18
	movs r1, #0xf
	ands r0, r1
	cmp r0, #6
	beq _020243A6
_0202439A:
	ldr r0, _020243B0 @ =0x0000FEAA
	cmp r2, r0
	beq _020243A6
	adds r0, #1
	cmp r2, r0
	bne _020243A8
_020243A6:
	movs r4, #1
_020243A8:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_020243B0: .4byte 0x0000FEAA

	thumb_func_start sub_020243B4
sub_020243B4: @ 0x020243B4
	push {r4, lr}
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	adds r2, r0, #0
	movs r4, #0
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bne _020243D6
	lsrs r0, r3, #0x18
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	beq _020243E2
_020243D6:
	ldr r0, _020243EC @ =0x0000FEAC
	cmp r2, r0
	beq _020243E2
	adds r0, #1
	cmp r2, r0
	bne _020243E4
_020243E2:
	movs r4, #1
_020243E4:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_020243EC: .4byte 0x0000FEAC

	thumb_func_start sub_020243F0
sub_020243F0: @ 0x020243F0
	push {r4, lr}
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	adds r3, r0, #0
	movs r4, #0
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bne _02024412
	lsrs r0, r2, #0x18
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0xa
	beq _02024418
_02024412:
	ldr r0, _02024424 @ =0x0000FEA7
	cmp r3, r0
	bne _0202441A
_02024418:
	movs r4, #1
_0202441A:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_02024424: .4byte 0x0000FEA7

	thumb_func_start sub_02024428
sub_02024428: @ 0x02024428
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _02024448 @ =0xDAF20000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _02024440
	ldr r0, _0202444C @ =0x0000FEB2
	cmp r1, r0
	bne _02024442
_02024440:
	movs r2, #1
_02024442:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024448: .4byte 0xDAF20000
_0202444C: .4byte 0x0000FEB2

	thumb_func_start sub_02024450
sub_02024450: @ 0x02024450
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024464 @ =0x25120000
	cmp r0, r1
	bne _0202445E
	movs r2, #1
_0202445E:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024464: .4byte 0x25120000

	thumb_func_start sub_02024468
sub_02024468: @ 0x02024468
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _02024488 @ =0xDAEB0000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _02024480
	ldr r0, _0202448C @ =0x0000251A
	cmp r1, r0
	bne _02024482
_02024480:
	movs r2, #1
_02024482:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024488: .4byte 0xDAEB0000
_0202448C: .4byte 0x0000251A

	thumb_func_start sub_02024490
sub_02024490: @ 0x02024490
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _020244B4 @ =0x00002514
	cmp r1, r0
	beq _020244AA
	adds r0, #4
	cmp r1, r0
	beq _020244AA
	adds r0, #1
	cmp r1, r0
	bne _020244AC
_020244AA:
	movs r2, #1
_020244AC:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020244B4: .4byte 0x00002514

	thumb_func_start sub_020244B8
sub_020244B8: @ 0x020244B8
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020244CC @ =0x251B0000
	cmp r0, r1
	bne _020244C6
	movs r2, #1
_020244C6:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020244CC: .4byte 0x251B0000

	thumb_func_start sub_020244D0
sub_020244D0: @ 0x020244D0
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _020244E8 @ =0xF7C40000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #8
	bhi _020244E2
	movs r1, #1
_020244E2:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_020244E8: .4byte 0xF7C40000

	thumb_func_start sub_020244EC
sub_020244EC: @ 0x020244EC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024500 @ =0x08490000
	cmp r0, r1
	bne _020244FA
	movs r2, #1
_020244FA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024500: .4byte 0x08490000

	thumb_func_start sub_02024504
sub_02024504: @ 0x02024504
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024518 @ =0x084A0000
	cmp r0, r1
	bne _02024512
	movs r2, #1
_02024512:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024518: .4byte 0x084A0000

	thumb_func_start sub_0202451C
sub_0202451C: @ 0x0202451C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024530 @ =0x08480000
	cmp r0, r1
	bne _0202452A
	movs r2, #1
_0202452A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024530: .4byte 0x08480000

	thumb_func_start sub_02024534
sub_02024534: @ 0x02024534
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024548 @ =0x084B0000
	cmp r0, r1
	bne _02024542
	movs r2, #1
_02024542:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024548: .4byte 0x084B0000

	thumb_func_start sub_0202454C
sub_0202454C: @ 0x0202454C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024560 @ =0x084C0000
	cmp r0, r1
	bne _0202455A
	movs r2, #1
_0202455A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024560: .4byte 0x084C0000

	thumb_func_start sub_02024564
sub_02024564: @ 0x02024564
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024578 @ =0x084D0000
	cmp r0, r1
	bne _02024572
	movs r2, #1
_02024572:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024578: .4byte 0x084D0000

	thumb_func_start sub_0202457C
sub_0202457C: @ 0x0202457C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024590 @ =0x08450000
	cmp r0, r1
	bne _0202458A
	movs r2, #1
_0202458A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024590: .4byte 0x08450000

	thumb_func_start sub_02024594
sub_02024594: @ 0x02024594
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020245A8 @ =0x08460000
	cmp r0, r1
	bne _020245A2
	movs r2, #1
_020245A2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020245A8: .4byte 0x08460000

	thumb_func_start sub_020245AC
sub_020245AC: @ 0x020245AC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020245C0 @ =0x08470000
	cmp r0, r1
	bne _020245BA
	movs r2, #1
_020245BA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020245C0: .4byte 0x08470000

	thumb_func_start sub_020245C4
sub_020245C4: @ 0x020245C4
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020245D8 @ =0x28070000
	cmp r0, r1
	bne _020245D2
	movs r2, #1
_020245D2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020245D8: .4byte 0x28070000

	thumb_func_start sub_020245DC
sub_020245DC: @ 0x020245DC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020245F0 @ =0x58500000
	cmp r0, r1
	bne _020245EA
	movs r2, #1
_020245EA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020245F0: .4byte 0x58500000

	thumb_func_start sub_020245F4
sub_020245F4: @ 0x020245F4
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024608 @ =0x58510000
	cmp r0, r1
	bne _02024602
	movs r2, #1
_02024602:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024608: .4byte 0x58510000

	thumb_func_start sub_0202460C
sub_0202460C: @ 0x0202460C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	beq _02024652
	adds r0, #5
	cmp r1, r0
	beq _02024652
	adds r0, #8
	cmp r1, r0
	beq _02024652
	adds r0, #8
	cmp r1, r0
	beq _02024652
	adds r0, #8
	cmp r1, r0
	beq _02024652
	adds r0, #8
	cmp r1, r0
	beq _02024652
	adds r0, #8
	cmp r1, r0
	beq _02024652
	adds r0, #5
	cmp r1, r0
	beq _02024652
	adds r0, #5
	cmp r1, r0
	beq _02024652
	adds r0, #0x18
	cmp r1, r0
	bne _02024654
_02024652:
	movs r2, #1
_02024654:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0202465C
sub_0202465C: @ 0x0202465C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _020246A8 @ =0x00000801
	cmp r1, r0
	beq _020246A0
	adds r0, #5
	cmp r1, r0
	beq _020246A0
	adds r0, #8
	cmp r1, r0
	beq _020246A0
	adds r0, #8
	cmp r1, r0
	beq _020246A0
	adds r0, #8
	cmp r1, r0
	beq _020246A0
	adds r0, #8
	cmp r1, r0
	beq _020246A0
	adds r0, #8
	cmp r1, r0
	beq _020246A0
	adds r0, #5
	cmp r1, r0
	beq _020246A0
	adds r0, #5
	cmp r1, r0
	beq _020246A0
	adds r0, #0x18
	cmp r1, r0
	bne _020246A2
_020246A0:
	movs r2, #1
_020246A2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020246A8: .4byte 0x00000801

	thumb_func_start sub_020246AC
sub_020246AC: @ 0x020246AC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _020246F8 @ =0x00000802
	cmp r1, r0
	beq _020246F0
	adds r0, #5
	cmp r1, r0
	beq _020246F0
	adds r0, #8
	cmp r1, r0
	beq _020246F0
	adds r0, #8
	cmp r1, r0
	beq _020246F0
	adds r0, #8
	cmp r1, r0
	beq _020246F0
	adds r0, #8
	cmp r1, r0
	beq _020246F0
	adds r0, #8
	cmp r1, r0
	beq _020246F0
	adds r0, #5
	cmp r1, r0
	beq _020246F0
	adds r0, #5
	cmp r1, r0
	beq _020246F0
	adds r0, #0x18
	cmp r1, r0
	bne _020246F2
_020246F0:
	movs r2, #1
_020246F2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020246F8: .4byte 0x00000802

	thumb_func_start sub_020246FC
sub_020246FC: @ 0x020246FC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r0, _02024748 @ =0x00000803
	cmp r1, r0
	beq _02024740
	adds r0, #5
	cmp r1, r0
	beq _02024740
	adds r0, #8
	cmp r1, r0
	beq _02024740
	adds r0, #8
	cmp r1, r0
	beq _02024740
	adds r0, #8
	cmp r1, r0
	beq _02024740
	adds r0, #8
	cmp r1, r0
	beq _02024740
	adds r0, #8
	cmp r1, r0
	beq _02024740
	adds r0, #5
	cmp r1, r0
	beq _02024740
	adds r0, #5
	cmp r1, r0
	beq _02024740
	adds r0, #0x18
	cmp r1, r0
	bne _02024742
_02024740:
	movs r2, #1
_02024742:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024748: .4byte 0x00000803

	thumb_func_start sub_0202474C
sub_0202474C: @ 0x0202474C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _020247C4 @ =0xFFA20000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _020247BC
	cmp r1, #0x69
	beq _020247BC
	ldr r0, _020247C8 @ =0x00000804
	cmp r1, r0
	beq _020247BC
	ldr r3, _020247CC @ =0xFFFFF7F7
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _020247BC
	subs r3, #8
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _020247BC
	subs r3, #8
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _020247BC
	subs r3, #8
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _020247BC
	subs r3, #8
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _020247BC
	ldr r0, _020247D0 @ =0x00000831
	cmp r1, r0
	beq _020247BC
	adds r0, #5
	cmp r1, r0
	beq _020247BC
	adds r0, #5
	cmp r1, r0
	beq _020247BC
	adds r0, #0x18
	cmp r1, r0
	bne _020247BE
_020247BC:
	movs r2, #1
_020247BE:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020247C4: .4byte 0xFFA20000
_020247C8: .4byte 0x00000804
_020247CC: .4byte 0xFFFFF7F7
_020247D0: .4byte 0x00000831

	thumb_func_start sub_020247D4
sub_020247D4: @ 0x020247D4
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020247E8 @ =0x084E0000
	cmp r0, r1
	bne _020247E2
	movs r2, #1
_020247E2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020247E8: .4byte 0x084E0000

	thumb_func_start sub_020247EC
sub_020247EC: @ 0x020247EC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024800 @ =0x080C0000
	cmp r0, r1
	bne _020247FA
	movs r2, #1
_020247FA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024800: .4byte 0x080C0000

	thumb_func_start sub_02024804
sub_02024804: @ 0x02024804
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024818 @ =0x08140000
	cmp r0, r1
	bne _02024812
	movs r2, #1
_02024812:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024818: .4byte 0x08140000

	thumb_func_start sub_0202481C
sub_0202481C: @ 0x0202481C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024830 @ =0x081C0000
	cmp r0, r1
	bne _0202482A
	movs r2, #1
_0202482A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024830: .4byte 0x081C0000

	thumb_func_start sub_02024834
sub_02024834: @ 0x02024834
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024848 @ =0x08240000
	cmp r0, r1
	bne _02024842
	movs r2, #1
_02024842:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024848: .4byte 0x08240000

	thumb_func_start sub_0202484C
sub_0202484C: @ 0x0202484C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024860 @ =0x082C0000
	cmp r0, r1
	bne _0202485A
	movs r2, #1
_0202485A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024860: .4byte 0x082C0000

	thumb_func_start sub_02024864
sub_02024864: @ 0x02024864
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #1
	bne _02024872
	movs r1, #1
_02024872:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_02024878
sub_02024878: @ 0x02024878
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #2
	bne _02024886
	movs r1, #1
_02024886:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_0202488C
sub_0202488C: @ 0x0202488C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #3
	bne _0202489A
	movs r1, #1
_0202489A:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_020248A0
sub_020248A0: @ 0x020248A0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #4
	bne _020248AE
	movs r1, #1
_020248AE:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_020248B4
sub_020248B4: @ 0x020248B4
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020248C8 @ =0x08540000
	cmp r0, r1
	bne _020248C2
	movs r2, #1
_020248C2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020248C8: .4byte 0x08540000

	thumb_func_start sub_020248CC
sub_020248CC: @ 0x020248CC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020248E0 @ =0x08550000
	cmp r0, r1
	bne _020248DA
	movs r2, #1
_020248DA:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020248E0: .4byte 0x08550000

	thumb_func_start sub_020248E4
sub_020248E4: @ 0x020248E4
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020248F8 @ =0x08560000
	cmp r0, r1
	bne _020248F2
	movs r2, #1
_020248F2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020248F8: .4byte 0x08560000

	thumb_func_start sub_020248FC
sub_020248FC: @ 0x020248FC
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024910 @ =0x08570000
	cmp r0, r1
	bne _0202490A
	movs r2, #1
_0202490A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024910: .4byte 0x08570000

	thumb_func_start sub_02024914
sub_02024914: @ 0x02024914
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _0202492C @ =0xF7A80000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _02024926
	movs r1, #1
_02024926:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_0202492C: .4byte 0xF7A80000

	thumb_func_start sub_02024930
sub_02024930: @ 0x02024930
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024944 @ =0x085C0000
	cmp r0, r1
	bne _0202493E
	movs r2, #1
_0202493E:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024944: .4byte 0x085C0000

	thumb_func_start sub_02024948
sub_02024948: @ 0x02024948
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _0202495C @ =0x085B0000
	cmp r0, r1
	bne _02024956
	movs r2, #1
_02024956:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0202495C: .4byte 0x085B0000

	thumb_func_start sub_02024960
sub_02024960: @ 0x02024960
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #0x70
	bne _0202496E
	movs r1, #1
_0202496E:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_02024974
sub_02024974: @ 0x02024974
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #0x71
	bne _02024982
	movs r1, #1
_02024982:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_02024988
sub_02024988: @ 0x02024988
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #0x72
	bne _02024996
	movs r1, #1
_02024996:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_0202499C
sub_0202499C: @ 0x0202499C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	cmp r0, #0x73
	bne _020249AA
	movs r1, #1
_020249AA:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_020249B0
sub_020249B0: @ 0x020249B0
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _020249C4 @ =0x584E0000
	cmp r0, r1
	bne _020249BE
	movs r2, #1
_020249BE:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020249C4: .4byte 0x584E0000

	thumb_func_start sub_020249C8
sub_020249C8: @ 0x020249C8
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _020249E8 @ =0xFFEF0000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _020249E0
	ldr r0, _020249EC @ =0x0000FEB0
	cmp r1, r0
	bne _020249E2
_020249E0:
	movs r2, #1
_020249E2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_020249E8: .4byte 0xFFEF0000
_020249EC: .4byte 0x0000FEB0

	thumb_func_start sub_020249F0
sub_020249F0: @ 0x020249F0
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _02024A08 @ =0xFFD60000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bhi _02024A02
	movs r1, #1
_02024A02:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A08: .4byte 0xFFD60000

	thumb_func_start sub_02024A0C
sub_02024A0C: @ 0x02024A0C
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024A20 @ =0x085D0000
	cmp r0, r1
	bne _02024A1A
	movs r2, #1
_02024A1A:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A20: .4byte 0x085D0000

	thumb_func_start sub_02024A24
sub_02024A24: @ 0x02024A24
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024A38 @ =0x08620000
	cmp r0, r1
	bne _02024A32
	movs r2, #1
_02024A32:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A38: .4byte 0x08620000

	thumb_func_start sub_02024A3C
sub_02024A3C: @ 0x02024A3C
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, _02024A54 @ =0xFFF80000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _02024A4E
	movs r1, #1
_02024A4E:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A54: .4byte 0xFFF80000

	thumb_func_start sub_02024A58
sub_02024A58: @ 0x02024A58
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	lsrs r1, r0, #0x10
	ldr r3, _02024A80 @ =0xFF9D0000
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _02024A76
	adds r0, r1, #0
	subs r0, #0x6a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _02024A78
_02024A76:
	movs r2, #1
_02024A78:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A80: .4byte 0xFF9D0000

	thumb_func_start sub_02024A84
sub_02024A84: @ 0x02024A84
	push {lr}
	lsls r0, r0, #0x10
	movs r2, #0
	ldr r1, _02024A98 @ =0xFFFF0000
	cmp r0, r1
	bne _02024A92
	movs r2, #1
_02024A92:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_02024A98: .4byte 0xFFFF0000

	thumb_func_start sub_02024A9C
sub_02024A9C: @ 0x02024A9C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
	ldr r5, _02024AB8 @ =0x02034204
_02024AA6:
	ldr r1, [r5]
	adds r0, r6, #0
	bl _call_via_r1
	cmp r0, #0
	beq _02024ABC
	adds r0, r4, #0
	b _02024AC8
	.align 2, 0
_02024AB8: .4byte 0x02034204
_02024ABC:
	adds r5, #8
	adds r4, #1
	cmp r4, #0x57
	ble _02024AA6
	movs r0, #1
	rsbs r0, r0, #0
_02024AC8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02024AD0
sub_02024AD0: @ 0x02024AD0
	push {lr}
	adds r1, r0, #0
	cmp r1, #0x57
	bls _02024ADC
	movs r0, #0
	b _02024AE4
_02024ADC:
	ldr r0, _02024AE8 @ =0x02034204
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #4]
_02024AE4:
	pop {r1}
	bx r1
	.align 2, 0
_02024AE8: .4byte 0x02034204

	thumb_func_start sub_02024AEC
sub_02024AEC: @ 0x02024AEC
	push {lr}
	adds r1, r0, #0
	cmp r1, #0x11
	bls _02024AF8
	movs r0, #0
	b _02024B00
_02024AF8:
	ldr r0, _02024B04 @ =0x020344C4
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
_02024B00:
	pop {r1}
	bx r1
	.align 2, 0
_02024B04: .4byte 0x020344C4

	thumb_func_start sub_02024B08
sub_02024B08: @ 0x02024B08
	push {r4, r5, lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r4, #0x2c
	muls r4, r1, r4
	ldr r1, _02024B6C @ =0x03004260
	adds r4, r4, r1
	movs r1, #0x23
	adds r1, r1, r4
	mov ip, r1
	movs r1, #0
	mov r5, ip
	strb r2, [r5]
	adds r2, r4, #0
	adds r2, #0x25
	strb r3, [r2]
	adds r2, #2
	strb r1, [r2]
	str r1, [r4, #0x10]
	str r1, [r4, #0x14]
	str r1, [r4, #0xc]
	movs r2, #0
	strh r1, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x28
	strb r2, [r1]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _02024B70 @ =0x020344F8
	adds r2, r1, r2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _02024B74 @ =0x03003C00
	adds r3, r1, r0
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r5]
	cmp r0, #0x16
	bhi _02024BFA
	lsls r0, r0, #2
	ldr r1, _02024B78 @ =_02024B7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02024B6C: .4byte 0x03004260
_02024B70: .4byte 0x020344F8
_02024B74: .4byte 0x03003C00
_02024B78: .4byte _02024B7C
_02024B7C: @ jump table
	.4byte _02024BE0 @ case 0
	.4byte _02024BD8 @ case 1
	.4byte _02024BD8 @ case 2
	.4byte _02024BE0 @ case 3
	.4byte _02024BD8 @ case 4
	.4byte _02024BD8 @ case 5
	.4byte _02024BD8 @ case 6
	.4byte _02024BE0 @ case 7
	.4byte _02024BD8 @ case 8
	.4byte _02024BD8 @ case 9
	.4byte _02024BD8 @ case 10
	.4byte _02024BE0 @ case 11
	.4byte _02024BD8 @ case 12
	.4byte _02024BD8 @ case 13
	.4byte _02024BD8 @ case 14
	.4byte _02024BE0 @ case 15
	.4byte _02024BD8 @ case 16
	.4byte _02024BD8 @ case 17
	.4byte _02024BD8 @ case 18
	.4byte _02024BE0 @ case 19
	.4byte _02024BD8 @ case 20
	.4byte _02024BD8 @ case 21
	.4byte _02024BD8 @ case 22
_02024BD8:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #2
	strb r0, [r1]
_02024BE0:
	ldr r0, [r3, #4]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	str r0, [r4, #0x14]
	ldr r0, [r3]
	ldr r1, [r2, #8]
	adds r0, r0, r1
	str r0, [r4]
	ldrb r1, [r2, #0x13]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
_02024BFA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_02024C00
sub_02024C00: @ 0x02024C00
	bx lr
	.align 2, 0

	thumb_func_start sub_02024C04
sub_02024C04: @ 0x02024C04
	bx lr
	.align 2, 0

	thumb_func_start sub_02024C08
sub_02024C08: @ 0x02024C08
	push {r4, lr}
	movs r1, #0x2c
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _02024C3C @ =0x03004260
	adds r4, r4, r0
	ldr r0, _02024C40 @ =0x03001B50
	bl sub_02019AF0
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x18]
	movs r0, #0x20
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0x10
	strb r0, [r1]
	adds r4, #0x22
	movs r0, #3
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02024C3C: .4byte 0x03004260
_02024C40: .4byte 0x03001B50

	thumb_func_start sub_02024C44
sub_02024C44: @ 0x02024C44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #0x2c
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, _02024D04 @ =0x03004260
	adds r4, r1, r0
	ldr r0, _02024D08 @ =0x03003710
	mov sl, r0
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	ldr r0, [r4, #0x10]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4]
	ldr r1, [r4, #8]
	asrs r2, r1, #8
	ldr r0, [r4, #0x14]
	subs r0, r0, r2
	str r0, [r4, #4]
	ldr r0, [r4, #0x18]
	adds r1, r1, r0
	str r1, [r4, #8]
	ldr r1, [r4, #0x1c]
	subs r0, r0, r1
	str r0, [r4, #0x18]
	ldrh r0, [r4, #0x26]
	cmp r0, #0xc
	bne _02024CA0
	movs r0, #0x17
	bl sub_02026A38
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #1
	strb r0, [r1]
_02024CA0:
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _02024CAC
	b _02024DBA
_02024CAC:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #4]
	cmp r1, r0
	blt _02024CB6
	b _02024DBA
_02024CB6:
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	str r1, [sp, #4]
	adds r6, #0x15
	str r6, [sp]
	cmp r0, #1
	bne _02024DAA
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _02024D0C @ =0x020344F8
	adds r5, r1, r0
	movs r2, #0
	movs r6, #0
	movs r7, #0x25
	adds r7, r7, r4
	mov ip, r7
	ldr r0, _02024D10 @ =0x03001B40
	mov sb, r0
	movs r1, #0xff
	lsls r1, r1, #4
	mov r8, r1
_02024CEE:
	mov r7, ip
	ldrb r0, [r7]
	cmp r0, #0
	bne _02024D18
	ldrh r0, [r4, #0x20]
	mov r1, r8
	ands r1, r0
	lsls r1, r1, #3
	ldr r7, _02024D14 @ =0x0600C000
	b _02024D22
	.align 2, 0
_02024D04: .4byte 0x03004260
_02024D08: .4byte 0x03003710
_02024D0C: .4byte 0x020344F8
_02024D10: .4byte 0x03001B40
_02024D14: .4byte 0x0600C000
_02024D18:
	ldrh r0, [r4, #0x20]
	mov r1, r8
	ands r1, r0
	lsls r1, r1, #3
	ldr r7, _02024D74 @ =0x0600C800
_02024D22:
	adds r3, r1, r7
	adds r3, r3, r2
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #2
	adds r3, r3, r1
	ldrh r0, [r5, #0xe]
	adds r0, r6, r0
	strh r0, [r3]
	ldrh r0, [r5, #0xe]
	adds r0, r6, r0
	adds r0, #1
	strh r0, [r3, #2]
	adds r2, #0x40
	movs r6, #2
	cmp r2, #0x4f
	ble _02024CEE
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	bne _02024D78
	mov r7, sb
	ldr r2, [r7]
	ldrh r0, [r4, #0x20]
	movs r3, #0xf
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #1
	lsrs r0, r0, #4
	ands r0, r3
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r2, #0x24
	adds r2, r2, r1
	ldrh r0, [r5, #0x10]
	strh r0, [r2]
	ldrh r0, [r4, #0x20]
	lsls r0, r0, #1
	mov r1, sl
	adds r1, #0x10
	b _02024DA4
	.align 2, 0
_02024D74: .4byte 0x0600C800
_02024D78:
	mov r0, sb
	ldr r2, [r0]
	ldrh r0, [r4, #0x20]
	movs r3, #0xf
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #1
	lsrs r0, r0, #4
	ands r0, r3
	lsls r0, r0, #5
	adds r1, r1, r0
	movs r7, #0x89
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r2, r2, r1
	ldrh r0, [r5, #0x10]
	strh r0, [r2]
	ldrh r0, [r4, #0x20]
	lsls r0, r0, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, sl
_02024DA4:
	adds r1, r1, r0
	ldrb r0, [r5, #0x14]
	strh r0, [r1]
_02024DAA:
	movs r1, #0
	ldr r0, [sp, #4]
	strb r1, [r0]
	ldr r0, _02024DCC @ =0x00000417
	add r0, sl
	ldr r2, [sp]
	adds r0, r0, r2
	strb r1, [r0]
_02024DBA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02024DCC: .4byte 0x00000417

	thumb_func_start sub_02024DD0
sub_02024DD0: @ 0x02024DD0
	push {lr}
	movs r1, #0x2c
	muls r1, r0, r1
	ldr r2, _02024DF0 @ =0x03004260
	adds r1, r1, r2
	ldr r2, _02024DF4 @ =0x020344E8
	adds r1, #0x22
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_02024DF0: .4byte 0x03004260
_02024DF4: .4byte 0x020344E8

	thumb_func_start sub_02024DF8
sub_02024DF8: @ 0x02024DF8
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	movs r1, #0x2c
	muls r1, r0, r1
	ldr r0, _02024EE0 @ =0x03004260
	adds r1, r1, r0
	mov ip, r1
	mov r0, ip
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r6, r0, #1
	adds r6, r6, r0
	lsls r6, r6, #3
	ldr r0, _02024EE4 @ =0x020344F8
	adds r6, r6, r0
	ldr r0, _02024EE8 @ =0x03001B50
	mov r8, r0
	movs r1, #0x86
	lsls r1, r1, #4
	add r1, r8
	mov sb, r1
	ldrb r4, [r1]
	lsls r4, r4, #3
	ldr r0, _02024EEC @ =0x03002410
	adds r4, r4, r0
	ldr r0, [r6]
	lsrs r0, r0, #0xe
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	ldrb r1, [r4, #1]
	movs r2, #0x3f
	adds r3, r2, #0
	ands r3, r1
	orrs r3, r0
	strb r3, [r4, #1]
	ldr r0, [r6]
	movs r1, #0xf
	mov sl, r1
	lsrs r0, r0, #0x1e
	lsls r0, r0, #6
	ldrb r1, [r4, #3]
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #3]
	ldrh r0, [r6, #0xc]
	ldr r1, _02024EF0 @ =0x000003FF
	ands r1, r0
	ldrh r5, [r4, #4]
	ldr r0, _02024EF4 @ =0xFFFFFC00
	ands r0, r5
	orrs r0, r1
	strh r0, [r4, #4]
	movs r0, #0x10
	orrs r3, r0
	strb r3, [r4, #1]
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #3]
	ldrb r1, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #5]
	ldrb r1, [r6, #0x12]
	lsls r1, r1, #4
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
	ldr r0, _02024EF8 @ =0x00000844
	add r0, r8
	ldrh r0, [r0]
	mov r2, ip
	ldr r1, [r2]
	subs r1, r1, r0
	ldr r2, _02024EFC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	ldr r0, _02024F00 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	mov r1, ip
	ldr r0, [r1, #4]
	ldr r2, _02024F04 @ =0x00000846
	add r8, r2
	mov r2, r8
	ldrb r1, [r2]
	subs r0, r0, r1
	strb r0, [r4]
	mov r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_02024EE0: .4byte 0x03004260
_02024EE4: .4byte 0x020344F8
_02024EE8: .4byte 0x03001B50
_02024EEC: .4byte 0x03002410
_02024EF0: .4byte 0x000003FF
_02024EF4: .4byte 0xFFFFFC00
_02024EF8: .4byte 0x00000844
_02024EFC: .4byte 0x000001FF
_02024F00: .4byte 0xFFFFFE00
_02024F04: .4byte 0x00000846

	thumb_func_start sub_02024F08
sub_02024F08: @ 0x02024F08
	push {lr}
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _02024F88 @ =0x03004790
	adds r1, r1, r0
	mov ip, r1
	movs r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	str r0, [r1, #0xc]
	str r0, [r1, #0x10]
	str r0, [r1, #0x14]
	str r0, [r1, #0x18]
	str r0, [r1, #0x1c]
	str r0, [r1, #0x20]
	str r0, [r1, #0x24]
	adds r1, #0x4d
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	mov r3, ip
	adds r3, #0x40
	movs r2, #0
	movs r1, #0xa
	strh r1, [r3]
	mov r1, ip
	strh r0, [r1, #0x3e]
	adds r1, #0x50
	strb r2, [r1]
	subs r1, #5
	strb r2, [r1]
	adds r1, #6
	strb r2, [r1]
	subs r1, #0xd
	strh r0, [r1]
	subs r1, #2
	strh r0, [r1]
	movs r2, #0
	mov r0, ip
	adds r0, #0x28
	movs r1, #4
_02024F64:
	strh r2, [r0]
	strh r2, [r0, #0xa]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _02024F64
	mov r0, ip
	adds r0, #0x52
	movs r1, #0
	strb r1, [r0]
	subs r0, #0xc
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	mov r0, ip
	strh r1, [r0, #0x3c]
	pop {r0}
	bx r0
	.align 2, 0
_02024F88: .4byte 0x03004790

	thumb_func_start sub_02024F8C
sub_02024F8C: @ 0x02024F8C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #0x54
	mov r1, sb
	muls r1, r0, r1
	ldr r0, _02024FC0 @ =0x03004790
	adds r6, r1, r0
	ldr r0, _02024FC4 @ =0x03003710
	mov r8, r0
	ldrh r5, [r6, #0x32]
	adds r0, r6, #0
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02024FD6
	lsls r0, r5, #2
	ldr r1, _02024FC8 @ =0x02034CF4
	adds r1, r0, r1
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _02024FCC
	ldrh r5, [r1]
	b _02024FD6
	.align 2, 0
_02024FC0: .4byte 0x03004790
_02024FC4: .4byte 0x03003710
_02024FC8: .4byte 0x02034CF4
_02024FCC:
	ldrh r0, [r1]
	bl sub_02024AEC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_02024FD6:
	ldrh r1, [r6, #0x3c]
	lsls r7, r1, #0x18
	lsrs r4, r7, #0x18
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _02025024
	lsls r0, r4, #1
	mov r1, r8
	adds r1, #0x10
	adds r1, r1, r0
	ldrh r2, [r6, #0x28]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r3, _0202501C @ =0x0600C000
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #3
	adds r3, r0, r3
	movs r1, #0xf
	ands r1, r4
	lsls r0, r1, #2
	adds r3, r3, r0
	ldr r0, _02025020 @ =0x03001B40
	ldr r2, [r0]
	lsls r1, r1, #1
	lsrs r0, r7, #0x1c
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r2, #0x24
	b _0202505E
	.align 2, 0
_0202501C: .4byte 0x0600C000
_02025020: .4byte 0x03001B40
_02025024:
	lsls r0, r4, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, r8
	adds r1, r1, r0
	ldrh r2, [r6, #0x28]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r3, _020250A0 @ =0x0600C800
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #3
	adds r3, r0, r3
	movs r1, #0xf
	ands r1, r4
	lsls r0, r1, #2
	adds r3, r3, r0
	ldr r0, _020250A4 @ =0x03001B40
	ldr r2, [r0]
	lsls r1, r1, #1
	lsrs r0, r7, #0x1c
	lsls r0, r0, #5
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r2, r2, r0
_0202505E:
	adds r2, r2, r1
	strh r5, [r2]
	ldrh r0, [r6, #0x28]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _020250A8 @ =0x0202F7FC
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, #2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r3]
	adds r3, #0x3e
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r3]
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r3, #2]
	mov r0, r8
	add r0, sb
	ldr r1, _020250AC @ =0x0000041A
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020250A0: .4byte 0x0600C800
_020250A4: .4byte 0x03001B40
_020250A8: .4byte 0x0202F7FC
_020250AC: .4byte 0x0000041A

	thumb_func_start sub_020250B0
sub_020250B0: @ 0x020250B0
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _020250D4 @ =0x03003710
	movs r0, #0x54
	muls r0, r3, r0
	ldr r1, _020250D8 @ =0x03004790
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	bne _020250E0
	adds r0, r4, r3
	ldr r1, _020250DC @ =0x0000041A
	adds r0, r0, r1
	strb r2, [r0]
	b _020250E4
	.align 2, 0
_020250D4: .4byte 0x03003710
_020250D8: .4byte 0x03004790
_020250DC: .4byte 0x0000041A
_020250E0:
	subs r0, #1
	strh r0, [r1]
_020250E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020250EC
sub_020250EC: @ 0x020250EC
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _02025110 @ =0x03004790
	adds r2, r1, r0
	ldr r0, _02025114 @ =0x02034C24
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r1, r2, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	subs r1, #1
	movs r0, #2
	strb r0, [r1]
	bx lr
	.align 2, 0
_02025110: .4byte 0x03004790
_02025114: .4byte 0x02034C24

	thumb_func_start sub_02025118
sub_02025118: @ 0x02025118
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x54
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, _02025158 @ =0x03004790
	adds r1, r1, r0
	ldr r5, _0202515C @ =0x03003710
	movs r0, #0x4d
	adds r0, r0, r1
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r2, ip
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _02025174
	adds r2, r1, #0
	adds r2, #0x4c
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r3, #7
	ands r3, r0
	cmp r3, #0
	bne _02025164
	adds r0, r5, r4
	ldr r1, _02025160 @ =0x0000041A
	adds r0, r0, r1
	strb r3, [r0]
	b _02025174
	.align 2, 0
_02025158: .4byte 0x03004790
_0202515C: .4byte 0x03003710
_02025160: .4byte 0x0000041A
_02025164:
	ldr r1, _0202517C @ =0x02034C24
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	mov r2, ip
	strb r0, [r2]
_02025174:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0202517C: .4byte 0x02034C24

	thumb_func_start sub_02025180
sub_02025180: @ 0x02025180
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _020251A4 @ =0x03004790
	adds r2, r1, r0
	ldr r0, _020251A8 @ =0x02034C44
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r1, r2, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	subs r1, #1
	movs r0, #4
	strb r0, [r1]
	bx lr
	.align 2, 0
_020251A4: .4byte 0x03004790
_020251A8: .4byte 0x02034C44

	thumb_func_start sub_020251AC
sub_020251AC: @ 0x020251AC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _020251EC @ =0x03004790
	adds r1, r1, r0
	ldr r6, _020251F0 @ =0x03003710
	adds r3, r1, #0
	adds r3, #0x4d
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _02025206
	adds r2, r1, #0
	adds r2, #0x4c
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _020251F8
	adds r0, r6, r5
	ldr r1, _020251F4 @ =0x0000041A
	adds r0, r0, r1
	strb r4, [r0]
	b _02025206
	.align 2, 0
_020251EC: .4byte 0x03004790
_020251F0: .4byte 0x03003710
_020251F4: .4byte 0x0000041A
_020251F8:
	ldr r1, _0202520C @ =0x02034C44
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strb r0, [r3]
_02025206:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0202520C: .4byte 0x02034C44

	thumb_func_start sub_02025210
sub_02025210: @ 0x02025210
	push {r4, r5, lr}
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _02025238 @ =0x03004790
	adds r4, r1, r0
	ldr r0, _0202523C @ =0x02034CE0
	adds r1, r4, #0
	adds r1, #0x4b
	ldrb r1, [r1]
	lsls r2, r1, #2
	adds r0, r2, r0
	ldr r0, [r0]
	ldr r5, [r0]
	cmp r1, #4
	bhi _02025276
	ldr r0, _02025240 @ =0x02025244
	adds r0, r2, r0
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02025238: .4byte 0x03004790
_0202523C: .4byte 0x02034CE0
_02025240: .4byte 0x02025244

	thumb_func_start sub_02025244
sub_02025244: @ 0x02025244
	strh r0, [r3, r1]
	lsls r2, r0, #8
	strh r0, [r4, r1]
	lsls r2, r0, #8
	strh r0, [r5, r1]
	lsls r2, r0, #8
	strh r0, [r6, r1]
	lsls r2, r0, #8
	strh r6, [r6, r1]
	lsls r2, r0, #8
	movs r0, #5
	bl sub_02026A38
	b _02025276

	thumb_func_start sub_02025260
sub_02025260: @ 0x02025260
	movs r0, #6
	bl sub_02026A38
	b _02025276

	thumb_func_start sub_02025268
sub_02025268: @ 0x02025268
	movs r0, #7
	bl sub_02026A38
	b _02025276

	thumb_func_start sub_02025270
sub_02025270: @ 0x02025270
	movs r0, #8
	bl sub_02026A38
_02025276:
	ldrh r0, [r5, #4]
	adds r2, r4, #0
	adds r2, #0x4d
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x4f
	movs r0, #3
	strb r0, [r1]
	subs r1, #1
	movs r0, #6
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0202529C
sub_0202529C: @ 0x0202529C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _020252F4 @ =0x03004790
	adds r3, r1, r0
	ldr r6, _020252F8 @ =0x03003710
	movs r0, #0x4d
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0202530A
	adds r1, r3, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r2, _020252FC @ =0x02034CE0
	adds r0, r3, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r1]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrb r0, [r1, #6]
	cmp r0, #0xff
	bne _02025304
	adds r0, r6, r5
	ldr r1, _02025300 @ =0x0000041A
	adds r0, r0, r1
	strb r4, [r0]
	b _0202530A
	.align 2, 0
_020252F4: .4byte 0x03004790
_020252F8: .4byte 0x03003710
_020252FC: .4byte 0x02034CE0
_02025300: .4byte 0x0000041A
_02025304:
	ldrh r0, [r1, #4]
	mov r1, ip
	strb r0, [r1]
_0202530A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_02025310
sub_02025310: @ 0x02025310
	push {r4, r5, lr}
	movs r1, #0x54
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _02025350 @ =0x03004790
	adds r4, r4, r0
	ldr r0, [r4]
	lsls r0, r0, #8
	str r0, [r4, #0xc]
	ldr r0, [r4, #4]
	lsls r0, r0, #8
	str r0, [r4, #0x10]
	movs r5, #0
	str r5, [r4, #8]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x14]
	movs r0, #0x20
	str r0, [r4, #0x20]
	movs r0, #0x1e
	bl sub_02026A38
	adds r0, r4, #0
	adds r0, #0x4f
	strb r5, [r0]
	adds r4, #0x4e
	movs r0, #8
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02025350: .4byte 0x03004790

	thumb_func_start sub_02025354
sub_02025354: @ 0x02025354
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _02025398 @ =0x03004790
	adds r1, r1, r0
	ldr r0, [r1, #0xc]
	asrs r0, r0, #8
	str r0, [r1]
	ldr r0, [r1, #0x10]
	asrs r4, r0, #8
	ldr r2, [r1, #8]
	asrs r0, r2, #8
	subs r3, r4, r0
	str r3, [r1, #4]
	ldr r0, [r1, #0x14]
	adds r2, r2, r0
	str r2, [r1, #8]
	ldr r2, [r1, #0x20]
	subs r0, r0, r2
	str r0, [r1, #0x14]
	adds r1, #0x52
	ldrb r0, [r1]
	cmp r0, #0
	bne _0202539C
	adds r0, r4, #0
	adds r0, #8
	cmp r3, r0
	ble _020253A0
	adds r0, r5, #0
	bl sub_02024F8C
	b _020253A0
	.align 2, 0
_02025398: .4byte 0x03004790
_0202539C:
	subs r0, #1
	strb r0, [r1]
_020253A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020253A8
sub_020253A8: @ 0x020253A8
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _020253FC @ =0x03004790
	adds r1, r1, r0
	mov ip, r1
	ldr r0, [r1]
	lsls r0, r0, #8
	str r0, [r1, #0xc]
	ldr r0, [r1, #4]
	lsls r0, r0, #8
	str r0, [r1, #0x10]
	movs r1, #0
	mov r0, ip
	str r1, [r0, #8]
	movs r0, #0x20
	mov r2, ip
	str r0, [r2, #0x20]
	str r1, [r2, #0x24]
	adds r2, #0x4d
	movs r0, #0x10
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x4c
	strb r1, [r0]
	subs r2, #9
	movs r3, #0
	movs r0, #0xc0
	lsls r0, r0, #2
	strh r0, [r2]
	mov r0, ip
	adds r0, #0x46
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #7
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x4e
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_020253FC: .4byte 0x03004790

	thumb_func_start sub_02025400
sub_02025400: @ 0x02025400
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0x54
	mov r1, r8
	muls r1, r0, r1
	ldr r0, _02025458 @ =0x03004790
	adds r3, r1, r0
	ldr r7, _0202545C @ =0x030041A0
	ldr r0, _02025460 @ =0x03003710
	mov sb, r0
	movs r4, #0
	ldr r2, [r3, #0xc]
	ldr r0, [r3, #0x18]
	adds r2, r2, r0
	str r2, [r3, #0xc]
	asrs r0, r2, #8
	str r0, [r3]
	ldr r1, [r3, #0x10]
	asrs r1, r1, #8
	ldr r0, [r3, #0x24]
	subs r1, r1, r0
	ldr r0, [r3, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3, #4]
	str r2, [r7, #0x38]
	ldr r0, [r3, #0x10]
	str r0, [r7, #0x3c]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0x20]
	adds r0, r0, r1
	str r0, [r3, #8]
	ldr r0, [r3, #0x18]
	cmp r0, #0
	blt _02025464
	ldr r1, [r3]
	ldr r0, [r3, #0x14]
	cmp r1, r0
	ble _0202546E
	b _0202546C
	.align 2, 0
_02025458: .4byte 0x03004790
_0202545C: .4byte 0x030041A0
_02025460: .4byte 0x03003710
_02025464:
	ldr r1, [r3]
	ldr r0, [r3, #0x14]
	cmp r1, r0
	bge _0202546E
_0202546C:
	movs r4, #1
_0202546E:
	adds r0, r7, #0
	adds r0, #0x62
	ldrh r0, [r0]
	cmp r0, #0
	bne _0202547C
	cmp r4, #0
	beq _020254FC
_0202547C:
	adds r2, r3, #0
	adds r2, #0x42
	ldr r1, _020254EC @ =0xFFFFF900
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	ldrh r0, [r1]
	adds r4, r0, #0
	adds r4, #0x10
	strh r4, [r1]
	ldr r5, [r3, #0x24]
	cmp r5, #0
	ble _020254A8
	movs r0, #0x10
	ands r4, r0
	cmp r4, #0
	bne _020254A8
	subs r0, r5, #1
	str r0, [r3, #0x24]
_020254A8:
	ldrh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #2
	cmp r0, r3
	bhi _020254B4
	b _020255D2
_020254B4:
	movs r5, #0
	movs r4, #0
	strh r3, [r1]
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0x76
	ldr r0, _020254F0 @ =0x00002A30
	strh r0, [r6]
	ldr r0, _020254F4 @ =0x03001B50
	bl sub_02019AF0
	movs r1, #0x6d
	bl __modsi3
	movs r1, #0x64
	muls r0, r1, r0
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	str r4, [r7, #0x38]
	str r4, [r7, #0x3c]
	mov r0, sb
	add r0, r8
	ldr r1, _020254F8 @ =0x0000041A
	adds r0, r0, r1
	strb r5, [r0]
	b _020255D2
	.align 2, 0
_020254EC: .4byte 0xFFFFF900
_020254F0: .4byte 0x00002A30
_020254F4: .4byte 0x03001B50
_020254F8: .4byte 0x0000041A
_020254FC:
	ldr r0, [r3, #0x24]
	cmp r0, #0x17
	bgt _02025506
	adds r0, #1
	str r0, [r3, #0x24]
_02025506:
	adds r2, r3, #0
	adds r2, #0x42
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r6, #0
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bhi _0202559E
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	strh r4, [r2]
	adds r0, r3, #0
	adds r0, #0x4d
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _02025598
	movs r0, #0x10
	strb r0, [r5]
	adds r1, r3, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _02025556
	strb r6, [r1]
_02025556:
	ldrb r0, [r1]
	lsls r2, r0, #1
	adds r0, r3, #0
	adds r0, #0x32
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r4, r3, #0
	adds r4, #0x28
	cmp r0, #0
	bne _02025574
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _02025574
	strb r6, [r1]
_02025574:
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r4, r0
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _020255E0 @ =0x0202F7FC
	adds r1, r1, r0
	ldrh r2, [r1, #4]
	ldr r0, _020255E4 @ =0x000003FF
	ands r0, r2
	strh r0, [r3, #0x3e]
	ldrh r0, [r1, #4]
	lsrs r0, r0, #0xc
	adds r1, r3, #0
	adds r1, #0x50
	strb r0, [r1]
_02025598:
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
_0202559E:
	ldr r1, _020255E8 @ =0x0202AD34
	adds r4, r3, #0
	adds r4, #0x46
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	asrs r2, r0, #2
	str r2, [r3, #0x20]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _020255C2
	ldr r0, _020255EC @ =0xFFFF0000
	orrs r2, r0
	str r2, [r3, #0x20]
_020255C2:
	ldrh r0, [r4]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	cmp r0, #0
	bne _020255D2
	str r0, [r3, #0x20]
_020255D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020255E0: .4byte 0x0202F7FC
_020255E4: .4byte 0x000003FF
_020255E8: .4byte 0x0202AD34
_020255EC: .4byte 0xFFFF0000

	thumb_func_start sub_020255F0
sub_020255F0: @ 0x020255F0
	push {lr}
	movs r1, #0x54
	muls r1, r0, r1
	ldr r2, _02025610 @ =0x03004790
	adds r1, r1, r2
	ldr r2, _02025614 @ =0x020347E0
	adds r1, #0x4e
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_02025610: .4byte 0x03004790
_02025614: .4byte 0x020347E0

	thumb_func_start sub_02025618
sub_02025618: @ 0x02025618
	push {r4, r5, r6, lr}
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _020256B0 @ =0x03004790
	adds r5, r1, r0
	adds r0, r5, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _020256A8
	ldr r3, _020256B4 @ =0x03001B50
	movs r0, #0x86
	lsls r0, r0, #4
	adds r4, r3, r0
	ldrb r2, [r4]
	lsls r2, r2, #3
	ldr r0, _020256B8 @ =0x03002410
	adds r2, r2, r0
	ldr r1, [r5, #0x10]
	asrs r1, r1, #8
	ldr r0, [r5, #8]
	asrs r0, r0, #8
	adds r1, r1, r0
	ldr r6, _020256BC @ =0x00000846
	adds r0, r3, r6
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r2]
	ldr r0, _020256C0 @ =0x00000844
	adds r3, r3, r0
	ldrh r0, [r3]
	subs r0, #8
	ldr r1, [r5]
	subs r1, r1, r0
	ldr r3, _020256C4 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _020256C8 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrb r3, [r2, #1]
	movs r1, #0x3f
	adds r0, r1, #0
	ands r0, r3
	strb r0, [r2, #1]
	ldrb r0, [r2, #3]
	ands r1, r0
	strb r1, [r2, #3]
	ldrh r1, [r2, #4]
	ldr r0, _020256CC @ =0xFFFFFC00
	ands r0, r1
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2, #4]
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_020256A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_020256B0: .4byte 0x03004790
_020256B4: .4byte 0x03001B50
_020256B8: .4byte 0x03002410
_020256BC: .4byte 0x00000846
_020256C0: .4byte 0x00000844
_020256C4: .4byte 0x000001FF
_020256C8: .4byte 0xFFFFFE00
_020256CC: .4byte 0xFFFFFC00

	thumb_func_start sub_020256D0
sub_020256D0: @ 0x020256D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r1, #0x54
	muls r1, r0, r1
	ldr r0, _020256FC @ =0x03004790
	adds r1, r1, r0
	mov ip, r1
	movs r1, #0
	mov r0, ip
	adds r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #2
	beq _02025714
	cmp r0, #2
	bgt _02025700
	cmp r0, #1
	beq _02025706
	b _0202573E
	.align 2, 0
_020256FC: .4byte 0x03004790
_02025700:
	cmp r0, #3
	beq _02025724
	b _0202573E
_02025706:
	ldr r1, _02025710 @ =0x02034C24
	mov r0, ip
	adds r0, #0x4c
	ldrb r0, [r0]
	b _02025738
	.align 2, 0
_02025710: .4byte 0x02034C24
_02025714:
	ldr r1, _02025720 @ =0x02034C44
	mov r0, ip
	adds r0, #0x4c
	ldrb r0, [r0]
	b _02025738
	.align 2, 0
_02025720: .4byte 0x02034C44
_02025724:
	ldr r0, _02025878 @ =0x02034CE0
	mov r1, ip
	adds r1, #0x4b
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	mov r0, ip
	adds r0, #0x4c
	ldrb r0, [r0]
	ldr r1, [r1]
_02025738:
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
_0202573E:
	mov r0, ip
	adds r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202574A
	b _0202589C
_0202574A:
	ldr r3, [r1]
	movs r0, #0
	mov r8, r0
	ldrh r0, [r3, #6]
	ldr r1, _0202587C @ =0x0000FFFF
	cmp r0, r1
	bne _0202575A
	b _02025994
_0202575A:
	ldr r2, _02025880 @ =0x03001B50
	mov sb, r2
	movs r6, #0x86
	lsls r6, r6, #4
	add r6, sb
	movs r7, #0xd
	rsbs r7, r7, #0
	movs r4, #1
	movs r0, #0x3f
	mov sl, r0
_0202576E:
	ldrb r0, [r6]
	lsls r0, r0, #3
	ldr r1, _02025884 @ =0x03002410
	adds r5, r0, r1
	mov r1, ip
	ldr r0, [r1, #4]
	ldrb r1, [r3]
	adds r1, r1, r0
	ldr r0, _02025888 @ =0x00000846
	add r0, sb
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r5]
	ldrb r1, [r3, #1]
	movs r0, #0xc
	ands r0, r1
	ldrb r1, [r5, #1]
	adds r2, r7, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r5, #1]
	ldrb r0, [r3, #1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r4
	lsls r0, r0, #5
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #1]
	ldrb r0, [r3, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #1]
	ldrh r1, [r3, #2]
	lsls r1, r1, #0x17
	lsrs r1, r1, #0x17
	mov r2, ip
	ldr r0, [r2]
	adds r1, r1, r0
	ldr r0, _0202588C @ =0x00000844
	add r0, sb
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r2, _02025890 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r5, #2]
	ldr r0, _02025894 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	mov r0, ip
	adds r0, #0x51
	ldrb r0, [r0]
	ands r0, r4
	lsls r0, r0, #4
	ldrb r1, [r5, #3]
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r5, #3]
	ldrb r0, [r3, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r4
	lsls r0, r0, #5
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #3]
	ldrb r0, [r3, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #3]
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #4]
	ldr r0, _02025898 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #4]
	ldrb r0, [r5, #5]
	adds r1, r7, #0
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #5]
	mov r0, ip
	adds r0, #0x4e
	ldrb r0, [r0]
	cmp r0, #6
	bne _02025840
	ands r1, r7
	strb r1, [r5, #5]
_02025840:
	ldrb r1, [r3, #5]
	lsrs r1, r1, #4
	lsls r1, r1, #4
	ldrb r2, [r5, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r5, #1]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #1]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #1
	add r8, r0
	adds r3, #8
	mov r1, r8
	cmp r1, #0xb
	ble _0202586C
	b _02025994
_0202586C:
	ldrh r0, [r3, #6]
	ldr r2, _0202587C @ =0x0000FFFF
	cmp r0, r2
	beq _02025876
	b _0202576E
_02025876:
	b _02025994
	.align 2, 0
_02025878: .4byte 0x02034CE0
_0202587C: .4byte 0x0000FFFF
_02025880: .4byte 0x03001B50
_02025884: .4byte 0x03002410
_02025888: .4byte 0x00000846
_0202588C: .4byte 0x00000844
_02025890: .4byte 0x000001FF
_02025894: .4byte 0xFFFFFE00
_02025898: .4byte 0xFFFFFC00
_0202589C:
	ldr r2, _020259A4 @ =0x03001B50
	movs r3, #0x86
	lsls r3, r3, #4
	adds r4, r2, r3
	ldrb r0, [r4]
	lsls r0, r0, #3
	ldr r6, _020259A8 @ =0x03002410
	adds r5, r0, r6
	mov r1, ip
	ldr r0, [r1, #4]
	subs r3, #0x1a
	adds r1, r2, r3
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r5]
	ldr r0, _020259AC @ =0x00000844
	adds r2, r2, r0
	ldrh r0, [r2]
	mov r2, ip
	ldr r1, [r2]
	subs r1, r1, r0
	ldr r3, _020259B0 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r2, [r5, #2]
	ldr r0, _020259B4 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	ldrb r1, [r5, #1]
	movs r0, #0x3f
	adds r2, r0, #0
	ands r2, r1
	strb r2, [r5, #1]
	ldrb r1, [r5, #3]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r5, #3]
	mov r1, ip
	ldrh r0, [r1, #0x3e]
	ldr r1, _020259B8 @ =0x000003FF
	ands r1, r0
	ldrh r3, [r5, #4]
	ldr r0, _020259BC @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r5, #4]
	mov r0, ip
	adds r0, #0x50
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldrb r3, [r5, #5]
	movs r0, #0xf
	ands r0, r3
	orrs r0, r1
	movs r1, #0x10
	orrs r2, r1
	strb r2, [r5, #1]
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r0, ip
	adds r0, #0x4e
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _02025994
	ldrb r0, [r5, #1]
	movs r1, #4
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #1
	orrs r1, r0
	ldrb r2, [r5, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	strb r0, [r5, #3]
	ands r1, r3
	strb r1, [r5, #1]
	mov r2, ip
	adds r2, #0x44
	ldrh r0, [r2]
	ldr r3, _020259C0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r2]
	lsls r2, r2, #0x10
	ldr r0, _020259C4 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, ip
	adds r0, #0x42
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	add r4, sp, #8
	mov r0, sp
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldrh r0, [r4]
	strh r0, [r6, #0x26]
	ldrh r0, [r4, #2]
	strh r0, [r6, #0x2e]
	ldrh r0, [r4, #4]
	strh r0, [r6, #0x36]
	ldrh r0, [r4, #6]
	strh r0, [r6, #0x3e]
_02025994:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020259A4: .4byte 0x03001B50
_020259A8: .4byte 0x03002410
_020259AC: .4byte 0x00000844
_020259B0: .4byte 0x000001FF
_020259B4: .4byte 0xFFFFFE00
_020259B8: .4byte 0x000003FF
_020259BC: .4byte 0xFFFFFC00
_020259C0: .4byte 0xFFFF0000
_020259C4: .4byte 0x0000FFFF

	thumb_func_start sub_020259C8
sub_020259C8: @ 0x020259C8
	push {r4, r5, r6, r7, lr}
	ldr r4, _02025A58 @ =0x03004B80
	ldr r0, _02025A5C @ =0x030041A0
	mov ip, r0
	ldr r3, _02025A60 @ =0x03003710
	movs r6, #0
	movs r7, #0
	ldr r1, [r4, #0x14]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r1, r0
	ldr r2, [r4, #0x10]
	movs r0, #0xf0
	ands r0, r2
	asrs r0, r0, #4
	orrs r1, r0
	strb r1, [r4, #0x1e]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r2, r0
	cmp r2, #0
	bne _02025A70
	ldrb r2, [r4, #0x1e]
	lsls r0, r2, #1
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r3, [r0]
	ldr r0, _02025A64 @ =0x00000FFF
	adds r5, r1, #0
	cmp r3, r0
	beq _02025A10
	ldr r0, _02025A68 @ =0x00007777
	cmp r3, r0
	beq _02025A10
	b _02025B8A
_02025A10:
	mov r0, ip
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #0
	bne _02025A28
	mov r1, ip
	adds r1, #0xb8
	ldrb r0, [r4, #0x1e]
	ldrb r1, [r1]
	cmp r0, r1
	bne _02025A28
	b _02025B8A
_02025A28:
	lsls r0, r2, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	ldr r3, _02025A64 @ =0x00000FFF
	cmp r0, r3
	beq _02025A48
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _02025AE4
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r2, r0
	bne _02025AE4
_02025A48:
	strh r3, [r1]
	ldrb r1, [r4, #0x1e]
	lsls r0, r1, #1
	adds r0, r5, r0
	ldrh r7, [r0]
	ldr r6, _02025A6C @ =0x0600A000
	b _02025AD4
	.align 2, 0
_02025A58: .4byte 0x03004B80
_02025A5C: .4byte 0x030041A0
_02025A60: .4byte 0x03003710
_02025A64: .4byte 0x00000FFF
_02025A68: .4byte 0x00007777
_02025A6C: .4byte 0x0600A000
_02025A70:
	ldrb r2, [r4, #0x1e]
	lsls r0, r2, #1
	movs r5, #0x84
	lsls r5, r5, #2
	adds r1, r3, r5
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _02025B54 @ =0x00000FFF
	cmp r1, r0
	beq _02025A8C
	ldr r0, _02025B58 @ =0x00007777
	cmp r1, r0
	beq _02025A8C
	b _02025B8A
_02025A8C:
	mov r0, ip
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #0
	beq _02025AA2
	mov r1, ip
	adds r1, #0xb8
	ldrb r0, [r4, #0x1e]
	ldrb r1, [r1]
	cmp r0, r1
	beq _02025B8A
_02025AA2:
	lsls r0, r2, #1
	movs r1, #0x84
	lsls r1, r1, #2
	adds r3, r3, r1
	adds r1, r3, r0
	ldrh r0, [r1]
	ldr r5, _02025B54 @ =0x00000FFF
	cmp r0, r5
	beq _02025AC8
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _02025AE4
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r2, r0
	bne _02025AE4
_02025AC8:
	strh r5, [r1]
	ldrb r1, [r4, #0x1e]
	lsls r0, r1, #1
	adds r0, r3, r0
	ldrh r7, [r0]
	ldr r6, _02025B5C @ =0x0600A800
_02025AD4:
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #3
	adds r6, r0, r6
	movs r0, #0xf
	ands r1, r0
	lsls r1, r1, #2
	adds r6, r6, r1
_02025AE4:
	ldr r5, _02025B60 @ =0x000003FF
	adds r0, r7, #0
	adds r1, r6, #0
	bl sub_0201F6DC
	cmp r0, #0
	bne _02025B68
	ldrh r0, [r6]
	adds r2, r5, #0
	ands r2, r0
	adds r3, r2, #0
	adds r1, r0, #0
	cmp r3, #5
	bls _02025B14
	adds r0, r2, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _02025B14
	cmp r3, #0x82
	beq _02025B14
	cmp r3, #0xaf
	bls _02025B1C
_02025B14:
	ldr r0, _02025B60 @ =0x000003FF
	ands r0, r1
	cmp r0, #0x13
	bne _02025B8A
_02025B1C:
	ldr r2, _02025B64 @ =0x03003BC4
	ldr r0, [r4]
	asrs r0, r0, #8
	subs r0, #8
	ldr r1, [r2, #8]
	subs r3, r1, r0
	str r3, [r4, #0x10]
	ldr r1, [r4, #4]
	asrs r1, r1, #8
	ldr r0, [r2, #0xc]
	subs r0, r0, r1
	str r0, [r4, #0x14]
	cmp r3, #0
	bge _02025B3C
	rsbs r0, r3, #0
	str r0, [r4, #0x10]
_02025B3C:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bge _02025B46
	rsbs r0, r0, #0
	str r0, [r4, #0x14]
_02025B46:
	ldr r0, [r4, #0x10]
	cmp r0, #0x20
	bgt _02025B86
	ldr r0, [r4, #0x14]
	cmp r0, #0x20
	ble _02025B8A
	b _02025B86
	.align 2, 0
_02025B54: .4byte 0x00000FFF
_02025B58: .4byte 0x00007777
_02025B5C: .4byte 0x0600A800
_02025B60: .4byte 0x000003FF
_02025B64: .4byte 0x03003BC4
_02025B68:
	ldrh r0, [r6]
	adds r2, r5, #0
	ands r2, r0
	adds r0, r2, #0
	subs r0, #0xbc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _02025B86
	adds r0, r2, #0
	subs r0, #0xc6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _02025B8A
_02025B86:
	movs r0, #0
	b _02025B8C
_02025B8A:
	movs r0, #1
_02025B8C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02025B94
sub_02025B94: @ 0x02025B94
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, _02025BD8 @ =0x03004B80
	ldr r0, _02025BDC @ =0x030041A0
	ldr r1, [r4]
	ldr r0, [r0]
	subs r3, r1, r0
	cmp r3, #0
	bge _02025BAE
	rsbs r3, r3, #0
_02025BAE:
	ldr r0, _02025BE0 @ =0x00002FFF
	cmp r3, r0
	bgt _02025BE4
	subs r3, r1, r5
	ldr r0, [r4, #4]
	subs r0, r0, r6
	cmp r3, #0
	bge _02025BC0
	rsbs r3, r3, #0
_02025BC0:
	cmp r0, #0
	bge _02025BC6
	rsbs r0, r0, #0
_02025BC6:
	asrs r3, r3, #8
	asrs r0, r0, #8
	cmp r3, r2
	bgt _02025BE4
	cmp r0, r2
	bgt _02025BE4
	movs r0, #1
	b _02025BE6
	.align 2, 0
_02025BD8: .4byte 0x03004B80
_02025BDC: .4byte 0x030041A0
_02025BE0: .4byte 0x00002FFF
_02025BE4:
	movs r0, #0
_02025BE6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_02025BEC
sub_02025BEC: @ 0x02025BEC
	push {r4, r5, r6, r7, lr}
	ldr r0, _02025C38 @ =0x03004B80
	ldr r7, _02025C3C @ =0x030041A0
	ldr r6, _02025C40 @ =0x03003BC4
	adds r4, r0, #0
	adds r4, #0x26
	movs r5, #0
	strb r5, [r4]
	ldr r0, [r6, #8]
	lsls r0, r0, #8
	ldr r1, [r6, #0xc]
	lsls r1, r1, #8
	movs r2, #0x10
	bl sub_02025B94
	cmp r0, #0
	beq _02025C12
	movs r0, #1
	strb r0, [r4]
_02025C12:
	adds r0, r7, #0
	adds r0, #0x87
	ldrb r0, [r0]
	cmp r0, #1
	bne _02025C44
	ldrb r0, [r4]
	cmp r0, #0
	beq _02025C34
	adds r1, r7, #0
	adds r1, #0x8a
	ldrb r0, [r1]
	cmp r0, #0xfe
	bne _02025C34
	movs r0, #4
	strb r0, [r1]
	strb r5, [r6, #0x11]
	strb r5, [r4]
_02025C34:
	movs r0, #1
	b _02025C46
	.align 2, 0
_02025C38: .4byte 0x03004B80
_02025C3C: .4byte 0x030041A0
_02025C40: .4byte 0x03003BC4
_02025C44:
	movs r0, #0
_02025C46:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_02025C4C
sub_02025C4C: @ 0x02025C4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _02025CD0 @ =0x03004B80
	ldr r4, _02025CD4 @ =0x030041A0
	adds r0, r4, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02025C74
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #3
	bne _02025CD8
	ldr r0, [r7]
	str r0, [r4, #0x10]
	ldr r0, [r7, #4]
	str r0, [r4, #0x14]
_02025C74:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #3
	bne _02025CD8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	movs r2, #8
	bl sub_02025B94
	cmp r0, #0
	beq _02025D10
	adds r6, r4, #0
	adds r6, #0x97
	movs r5, #0
	movs r0, #1
	strb r0, [r6]
	movs r0, #2
	movs r1, #0x30
	bl sub_0201FED4
	adds r2, r4, #0
	adds r2, #0x8d
	ldrb r1, [r2]
	cmp r1, #0
	beq _02025CB2
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	strb r5, [r6]
_02025CB2:
	adds r0, r7, #0
	adds r0, #0x26
	strb r5, [r0]
	movs r0, #0xa
	mov r1, r8
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0x30
	strb r0, [r1]
	strb r5, [r7, #0x1f]
	bl sub_02025F60
	movs r0, #1
	b _02025D12
	.align 2, 0
_02025CD0: .4byte 0x03004B80
_02025CD4: .4byte 0x030041A0
_02025CD8:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _02025D10
	adds r0, r4, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0
	bne _02025D10
	ldr r0, [r4]
	ldr r1, [r4, #4]
	movs r2, #0x10
	bl sub_02025B94
	cmp r0, #0
	beq _02025D10
	movs r0, #3
	bl sub_02026A38
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #2
	strb r0, [r1]
	strb r0, [r7, #0x1f]
	bl sub_020263A0
	movs r0, #1
	b _02025D12
_02025D10:
	movs r0, #0
_02025D12:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_02025D1C
sub_02025D1C: @ 0x02025D1C
	push {r4, r5, lr}
	ldr r4, _02025D64 @ =0x030041A0
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	cmp r0, #3
	bne _02025D68
	adds r0, r4, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	cmp r0, #1
	beq _02025D38
	cmp r0, #5
	bne _02025D68
_02025D38:
	ldr r0, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	movs r2, #0x10
	bl sub_02025B94
	cmp r0, #0
	beq _02025D68
	movs r1, #0
	movs r0, #9
	strb r0, [r5]
	ldr r0, [r4, #0x38]
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x3c]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x97
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9f
	movs r0, #1
	strb r0, [r1]
	b _02025D6A
	.align 2, 0
_02025D64: .4byte 0x030041A0
_02025D68:
	movs r0, #0
_02025D6A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_02025D70
sub_02025D70: @ 0x02025D70
	ldr r3, _02025DC4 @ =0x03004B80
	movs r1, #0xf8
	lsls r1, r1, #8
	str r1, [r3]
	movs r0, #0x88
	lsls r0, r0, #8
	str r0, [r3, #4]
	str r1, [r3, #8]
	str r0, [r3, #0xc]
	adds r0, r3, #0
	adds r0, #0x21
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	subs r0, #2
	strb r2, [r0]
	adds r0, #3
	strb r2, [r0]
	movs r1, #0
	strh r2, [r3, #0x18]
	strb r1, [r3, #0x1e]
	strh r2, [r3, #0x1a]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r2, [r3, #0x14]
	str r2, [r3, #0x10]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	strb r1, [r3, #0x1c]
	strb r1, [r3, #0x1d]
	strb r1, [r3, #0x1f]
	bx lr
	.align 2, 0
_02025DC4: .4byte 0x03004B80

	thumb_func_start sub_02025DC8
sub_02025DC8: @ 0x02025DC8
	push {r4, r5, r6, lr}
	ldr r3, _02025E08 @ =0x03004B80
	ldr r5, _02025E0C @ =0x030041A0
	ldr r1, _02025E10 @ =0x03001B50
	ldr r0, _02025E14 @ =0x00000818
	adds r4, r1, r0
	ldr r2, [r4]
	ldr r0, _02025E18 @ =0x00400040
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _02025E24
	ldr r2, [r3, #4]
	ldr r1, _02025E1C @ =0xFFFFFE80
	adds r0, r2, r1
	str r0, [r3, #4]
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02025DFA
	ldr r4, _02025E20 @ =0xFFFFFD00
	adds r0, r2, r4
	str r0, [r3, #4]
_02025DFA:
	ldr r0, [r3, #4]
	movs r1, #0xe0
	lsls r1, r1, #4
	cmp r0, r1
	bgt _02025E70
	str r1, [r3, #4]
	b _02025E70
	.align 2, 0
_02025E08: .4byte 0x03004B80
_02025E0C: .4byte 0x030041A0
_02025E10: .4byte 0x03001B50
_02025E14: .4byte 0x00000818
_02025E18: .4byte 0x00400040
_02025E1C: .4byte 0xFFFFFE80
_02025E20: .4byte 0xFFFFFD00
_02025E24:
	ldr r0, _02025E5C @ =0x00800080
	ands r2, r0
	cmp r2, #0
	beq _02025E70
	ldr r2, [r3, #4]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r2, r1
	str r0, [r3, #4]
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02025E4A
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r0, r2, r4
	str r0, [r3, #4]
_02025E4A:
	adds r0, r5, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _02025E64
	ldr r1, [r3, #4]
	ldr r0, _02025E60 @ =0x0000F7FF
	b _02025E68
	.align 2, 0
_02025E5C: .4byte 0x00800080
_02025E60: .4byte 0x0000F7FF
_02025E64:
	ldr r1, [r3, #4]
	ldr r0, _02025EA8 @ =0x0000E7FF
_02025E68:
	cmp r1, r0
	ble _02025E70
	adds r0, #1
	str r0, [r3, #4]
_02025E70:
	ldr r0, _02025EAC @ =0x00000818
	adds r1, r6, r0
	ldr r2, [r1]
	ldr r0, _02025EB0 @ =0x00200020
	ands r0, r2
	cmp r0, #0
	beq _02025EBC
	ldr r2, [r3]
	ldr r4, _02025EB4 @ =0xFFFFFE80
	adds r0, r2, r4
	str r0, [r3]
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02025E98
	ldr r1, _02025EB8 @ =0xFFFFFD00
	adds r0, r2, r1
	str r0, [r3]
_02025E98:
	ldr r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #3
	cmp r0, r1
	bgt _02025EEE
	str r1, [r3]
	b _02025EEE
	.align 2, 0
_02025EA8: .4byte 0x0000E7FF
_02025EAC: .4byte 0x00000818
_02025EB0: .4byte 0x00200020
_02025EB4: .4byte 0xFFFFFE80
_02025EB8: .4byte 0xFFFFFD00
_02025EBC:
	ldr r0, _02025F50 @ =0x00100010
	ands r2, r0
	cmp r2, #0
	beq _02025EEE
	ldr r2, [r3]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r2, r4
	str r0, [r3]
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02025EE2
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r2, r1
	str r0, [r3]
_02025EE2:
	ldr r1, [r3]
	ldr r0, _02025F54 @ =0x0001DFFF
	cmp r1, r0
	ble _02025EEE
	adds r0, #1
	str r0, [r3]
_02025EEE:
	adds r1, r6, #0
	ldr r0, [r3]
	asrs r0, r0, #8
	subs r0, #0x80
	movs r4, #0x84
	lsls r4, r4, #4
	adds r2, r1, r4
	movs r5, #0
	strh r0, [r2]
	ldr r0, [r3, #4]
	asrs r0, r0, #8
	subs r0, #0x50
	adds r4, #2
	adds r3, r1, r4
	strh r0, [r3]
	subs r4, #0x42
	ands r0, r4
	cmp r0, #0
	beq _02025F16
	strh r5, [r3]
_02025F16:
	ldrh r0, [r3]
	cmp r0, #0x60
	bls _02025F20
	movs r0, #0x60
	strh r0, [r3]
_02025F20:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _02025F2C
	strh r5, [r2]
_02025F2C:
	ldrh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bls _02025F38
	strh r1, [r2]
_02025F38:
	ldrh r1, [r2]
	ldr r2, _02025F58 @ =0x00000844
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r4, _02025F5C @ =0x00000846
	adds r0, r6, r4
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_02025F50: .4byte 0x00100010
_02025F54: .4byte 0x0001DFFF
_02025F58: .4byte 0x00000844
_02025F5C: .4byte 0x00000846

	thumb_func_start sub_02025F60
sub_02025F60: @ 0x02025F60
	ldr r2, _02025F88 @ =0x03004B80
	adds r0, r2, #0
	adds r0, #0x20
	movs r1, #0
	strb r1, [r0]
	ldr r0, _02025F8C @ =0x02034ED4
	ldr r0, [r0]
	ldr r0, [r0]
	adds r3, r2, #0
	adds r3, #0x23
	strb r1, [r3]
	subs r3, #2
	strb r1, [r3]
	ldrh r0, [r0, #4]
	adds r1, r2, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r2, #0x1f]
	bx lr
	.align 2, 0
_02025F88: .4byte 0x03004B80
_02025F8C: .4byte 0x02034ED4

	thumb_func_start sub_02025F90
sub_02025F90: @ 0x02025F90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _02025FFC @ =0x03004B80
	ldr r0, _02026000 @ =0x03003710
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0
	beq _02025FB6
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02025FB6
	b _02026178
_02025FB6:
	ldr r0, _02026004 @ =0x03001B50
	ldr r1, _02026008 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _02025FC8
	b _02026178
_02025FC8:
	ldr r2, [r5, #4]
	asrs r2, r2, #8
	movs r0, #0xff
	lsls r0, r0, #4
	ands r2, r0
	str r2, [r5, #0x14]
	ldr r3, [r5]
	asrs r1, r3, #8
	ands r1, r0
	str r1, [r5, #0x10]
	movs r0, #0xf0
	ands r0, r1
	asrs r0, r0, #4
	orrs r2, r0
	strb r2, [r5, #0x1e]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	mov sb, r3
	cmp r1, #0
	bne _0202600C
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #1
	mov r2, r8
	adds r2, #0x10
	b _02026016
	.align 2, 0
_02025FFC: .4byte 0x03004B80
_02026000: .4byte 0x03003710
_02026004: .4byte 0x03001B50
_02026008: .4byte 0x0000081A
_0202600C:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #1
	movs r2, #0x84
	lsls r2, r2, #2
	add r2, r8
_02026016:
	adds r1, r1, r2
	ldrh r7, [r1]
	adds r6, r0, #0
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	ldr r1, _0202607C @ =0x0202F7FC
	adds r0, r0, r1
	mov ip, r0
	ldr r2, _02026080 @ =0x00000FFF
	mov sl, r1
	cmp r7, r2
	bne _02026032
	b _02026188
_02026032:
	ldr r0, _02026084 @ =0x00007777
	cmp r7, r0
	bne _0202603A
	b _02026188
_0202603A:
	ldr r0, _02026088 @ =0x00003333
	cmp r7, r0
	bne _02026042
	b _02026188
_02026042:
	mov r3, ip
	ldrh r0, [r3, #8]
	cmp r0, r2
	bne _0202604C
	b _02026188
_0202604C:
	ldr r0, [r5, #0x10]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _02026094
	ldr r3, _0202608C @ =0x03001B40
	ldr r1, [r3]
	ldrb r2, [r5, #0x1e]
	lsrs r0, r2, #4
	lsls r0, r0, #1
	ldr r4, _02026090 @ =0x000018F8
	adds r1, r1, r4
	adds r1, r1, r0
	ldrh r1, [r1]
	movs r0, #0xf
	ands r0, r2
	asrs r1, r0
	movs r4, #1
	ands r1, r4
	adds r2, r3, #0
	cmp r1, #0
	beq _020260B6
	b _02026192
	.align 2, 0
_0202607C: .4byte 0x0202F7FC
_02026080: .4byte 0x00000FFF
_02026084: .4byte 0x00007777
_02026088: .4byte 0x00003333
_0202608C: .4byte 0x03001B40
_02026090: .4byte 0x000018F8
_02026094:
	ldr r3, _02026108 @ =0x03001B40
	ldr r1, [r3]
	ldrb r2, [r5, #0x1e]
	lsrs r0, r2, #4
	lsls r0, r0, #1
	ldr r4, _0202610C @ =0x00001918
	adds r1, r1, r4
	adds r1, r1, r0
	ldrh r1, [r1]
	movs r0, #0xf
	ands r0, r2
	asrs r1, r0
	movs r4, #1
	ands r1, r4
	adds r2, r3, #0
	cmp r1, #0
	bne _02026192
_020260B6:
	ldr r0, _02026110 @ =0x00000FFF
	ands r7, r0
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #2
	add r1, sl
	mov ip, r1
	ldrh r1, [r1, #4]
	cmp r1, r0
	beq _02026188
	mov r0, sb
	asrs r4, r0, #8
	movs r0, #0xff
	lsls r0, r0, #8
	ands r4, r0
	cmp r4, #0
	bne _02026118
	lsls r0, r6, #1
	mov r1, r8
	adds r1, #0x10
	adds r1, r1, r0
	movs r3, #0
	ldr r0, _02026114 @ =0x00007777
	strh r0, [r1]
	ldr r2, [r2]
	ldrb r1, [r5, #0x1e]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #1
	lsrs r1, r1, #4
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r2, #0x24
	adds r2, r2, r0
	ldrh r6, [r2]
	strh r4, [r2]
	adds r0, r5, #0
	adds r0, #0x28
	strb r3, [r0]
	b _0202614C
	.align 2, 0
_02026108: .4byte 0x03001B40
_0202610C: .4byte 0x00001918
_02026110: .4byte 0x00000FFF
_02026114: .4byte 0x00007777
_02026118:
	lsls r0, r6, #1
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, r8
	adds r1, r1, r0
	movs r3, #0
	ldr r0, _02026174 @ =0x00007777
	strh r0, [r1]
	ldr r2, [r2]
	ldrb r1, [r5, #0x1e]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #1
	lsrs r1, r1, #4
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x89
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r2, r2, r0
	ldrh r6, [r2]
	strh r3, [r2]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
_0202614C:
	ldrb r0, [r5, #0x1e]
	adds r1, r5, #0
	adds r1, #0x29
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x24
	strb r7, [r0]
	mov r3, ip
	ldrh r0, [r3, #4]
	strh r0, [r5, #0x18]
	strh r6, [r5, #0x1a]
	movs r0, #3
	bl sub_02026A38
	movs r0, #2
	strb r0, [r5, #0x1f]
	bl sub_020263A0
	b _0202621C
	.align 2, 0
_02026174: .4byte 0x00007777
_02026178:
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202619A
	bl sub_02025DC8
	b _0202621C
_02026188:
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #1
	strb r0, [r1]
	b _02026178
_02026192:
	adds r0, r5, #0
	adds r0, #0x23
	strb r4, [r0]
	b _02026178
_0202619A:
	adds r3, r5, #0
	adds r3, #0x22
	ldrb r0, [r3]
	cmp r0, #0
	bne _020261AA
	subs r0, #1
	strb r0, [r3]
	b _0202621C
_020261AA:
	adds r2, r5, #0
	adds r2, #0x21
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _020261D8 @ =0x02034ED4
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r2]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrb r0, [r1, #6]
	cmp r0, #0xff
	beq _020261DC
	ldrh r0, [r1, #4]
	strb r0, [r3]
	b _0202621C
	.align 2, 0
_020261D8: .4byte 0x02034ED4
_020261DC:
	bl sub_02025BEC
	cmp r0, #0
	beq _020261F4
	movs r0, #2
	bl sub_02026A38
	movs r0, #0
	strb r0, [r5, #0x1f]
	bl sub_02025F60
	b _0202621C
_020261F4:
	bl sub_02025C4C
	adds r6, r0, #0
	cmp r6, #0
	bne _0202621C
	bl sub_02025D1C
	adds r4, r0, #0
	cmp r4, #0
	beq _02026210
	strb r6, [r5, #0x1f]
	bl sub_02025F60
	b _0202621C
_02026210:
	movs r0, #2
	bl sub_02026A38
	strb r4, [r5, #0x1f]
	bl sub_02025F60
_0202621C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0202622C
sub_0202622C: @ 0x0202622C
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r1, [sp, #0xc]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x18
	lsls r3, r3, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r1, _0202624C @ =0x03003710
	cmp r3, #0
	bne _02026250
	lsls r0, r0, #1
	adds r1, #0x10
	b _02026258
	.align 2, 0
_0202624C: .4byte 0x03003710
_02026250:
	lsls r0, r0, #1
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r1, r3
_02026258:
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r5
	ldr r3, _0202628C @ =0x0600C800
	cmp r0, #0
	bne _0202626A
	ldr r3, _02026290 @ =0x0600C000
_0202626A:
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #3
	adds r3, r3, r0
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #2
	adds r3, r3, r0
	cmp r1, #0x24
	beq _02026282
	cmp r1, #0x2e
	bne _020262A0
_02026282:
	cmp r2, #0
	bne _02026298
	adds r3, #0x40
	ldr r4, _02026294 @ =0x0000328F
	b _0202629C
	.align 2, 0
_0202628C: .4byte 0x0600C800
_02026290: .4byte 0x0600C000
_02026294: .4byte 0x0000328F
_02026298:
	adds r3, #0x42
	ldr r4, _020262C0 @ =0x0000328C
_0202629C:
	adds r0, r4, #0
	strh r0, [r3]
_020262A0:
	cmp r1, #0x25
	beq _020262B4
	adds r0, r1, #0
	subs r0, #0x27
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _020262B4
	cmp r1, #0x2f
	bne _020262D0
_020262B4:
	cmp r2, #0
	bne _020262C8
	adds r3, #0x40
	ldr r1, _020262C4 @ =0x00003297
	adds r0, r1, #0
	b _020262CE
	.align 2, 0
_020262C0: .4byte 0x0000328C
_020262C4: .4byte 0x00003297
_020262C8:
	adds r3, #0x42
	ldr r4, _020262D8 @ =0x00003294
	adds r0, r4, #0
_020262CE:
	strh r0, [r3]
_020262D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020262D8: .4byte 0x00003294

	thumb_func_start sub_020262DC
sub_020262DC: @ 0x020262DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov sb, r4
	ldr r5, _0202634C @ =0x03004B80
	movs r0, #0xf
	adds r1, r4, #0
	ands r1, r0
	subs r2, r1, #1
	movs r0, #0
	mov r8, r0
	adds r1, #1
	movs r7, #0xf
	ands r2, r7
	ands r1, r7
	movs r3, #0xf0
	adds r0, r4, #0
	ands r0, r3
	orrs r2, r0
	strb r2, [r5, #0x1c]
	orrs r1, r0
	strb r1, [r5, #0x1d]
	ldr r0, [r5]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _02026356
	ldrb r2, [r5, #0x1c]
	mov r0, r8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0
	bl sub_0202622C
	ldrb r1, [r5, #0x1d]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _02026350
	ldrb r2, [r5, #0x1d]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl sub_0202622C
	b _02026392
	.align 2, 0
_0202634C: .4byte 0x03004B80
_02026350:
	ldrb r2, [r5, #0x1d]
	movs r0, #1
	b _02026374
_02026356:
	ldrb r2, [r5, #0x1d]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl sub_0202622C
	ldrb r1, [r5, #0x1c]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0xf
	bne _02026382
	ldrb r2, [r5, #0x1c]
	mov r0, r8
_02026374:
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0
	bl sub_0202622C
	b _02026392
_02026382:
	ldrb r2, [r5, #0x1c]
	mov r0, r8
	str r0, [sp]
	mov r0, sb
	adds r1, r6, #0
	movs r3, #1
	bl sub_0202622C
_02026392:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_020263A0
sub_020263A0: @ 0x020263A0
	push {r4, r5, r6, r7, lr}
	ldr r4, _02026428 @ =0x03004B80
	ldr r5, _0202642C @ =0x03004838
	ldr r7, _02026430 @ =0x03003710
	ldr r3, _02026434 @ =0x030041A0
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #0
	movs r6, #1
	strb r6, [r0]
	ldr r0, _02026438 @ =0x02034ED4
	ldr r0, [r0, #4]
	ldr r0, [r0]
	adds r2, r4, #0
	adds r2, #0x23
	strb r1, [r2]
	subs r2, #2
	strb r1, [r2]
	ldrh r0, [r0, #4]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _02026444
	ldr r1, _0202643C @ =0x00000419
	adds r0, r7, r1
	strb r6, [r0]
	movs r0, #2
	bl sub_02024F08
	adds r1, r5, #0
	adds r1, #0x40
	movs r3, #0
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, [r4]
	asrs r1, r0, #8
	subs r1, #8
	str r1, [r5]
	ldr r1, [r4, #4]
	asrs r1, r1, #8
	subs r1, #2
	str r1, [r5, #4]
	ldrh r2, [r4, #0x18]
	ldr r1, _02026440 @ =0x000003FF
	ands r1, r2
	strh r1, [r5, #0x3e]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x1c
	adds r1, r5, #0
	adds r1, #0x50
	strb r2, [r1]
	subs r1, #1
	strb r3, [r1]
	ldrb r1, [r4, #0x1e]
	movs r3, #0x80
	lsls r3, r3, #2
	movs r2, #0
	bl sub_0201F660
	ldrb r0, [r4, #0x1e]
	ldr r1, [r4]
	bl sub_020262DC
	b _02026452
	.align 2, 0
_02026428: .4byte 0x03004B80
_0202642C: .4byte 0x03004838
_02026430: .4byte 0x03003710
_02026434: .4byte 0x030041A0
_02026438: .4byte 0x02034ED4
_0202643C: .4byte 0x00000419
_02026440: .4byte 0x000003FF
_02026444:
	ldr r0, [r4]
	str r0, [r3]
	ldr r0, [r4, #4]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r3, #4]
_02026452:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4, #0x1f]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_02026464
sub_02026464: @ 0x02026464
	push {r4, r5, r6, r7, lr}
	ldr r4, _02026484 @ =0x03004B80
	ldr r6, _02026488 @ =0x030041A0
	ldr r7, _0202648C @ =0x03004838
	adds r0, r6, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _02026490
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	bne _02026490
	strb r0, [r4, #0x1f]
	bl sub_02025F60
	b _020265A0
	.align 2, 0
_02026484: .4byte 0x03004B80
_02026488: .4byte 0x030041A0
_0202648C: .4byte 0x03004838
_02026490:
	adds r1, r4, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq _020264A8
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	adds r5, r6, #0
	adds r5, #0x84
	cmp r0, #0
	bne _02026528
_020264A8:
	ldr r0, _020264DC @ =0x03001B50
	ldr r1, _020264E0 @ =0x0000081A
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r5, r6, #0
	adds r5, #0x84
	cmp r0, #0
	beq _02026528
	ldrb r0, [r5]
	cmp r0, #0
	beq _020264E4
	ldr r0, [r4]
	asrs r0, r0, #8
	subs r0, #8
	movs r1, #0xff
	lsls r1, r1, #4
	ands r0, r1
	str r0, [r4, #0x10]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	adds r0, #0x18
	ands r0, r1
	b _020264EE
	.align 2, 0
_020264DC: .4byte 0x03001B50
_020264E0: .4byte 0x0000081A
_020264E4:
	ldr r0, [r7]
	adds r0, #8
	str r0, [r4, #0x10]
	ldr r0, [r7, #4]
	adds r0, #8
_020264EE:
	str r0, [r4, #0x14]
	bl sub_020259C8
	cmp r0, #0
	bne _02026508
	movs r0, #4
	bl sub_02026A38
	movs r0, #4
	strb r0, [r4, #0x1f]
	bl sub_020265A8
	b _020265A0
_02026508:
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0202654C @ =0x02034ED4
	ldr r0, [r0, #0xc]
	ldr r0, [r0]
	adds r1, #1
	strb r2, [r1]
	ldrh r0, [r0, #4]
	adds r1, #1
	strb r0, [r1]
	movs r0, #0x12
	bl sub_02026A38
_02026528:
	bl sub_02025DC8
	ldrb r0, [r5]
	cmp r0, #0
	bne _02026550
	adds r1, r7, #0
	adds r1, #0x40
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, [r4]
	asrs r0, r0, #8
	subs r0, #8
	str r0, [r7]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	subs r0, #2
	str r0, [r7, #4]
	b _0202655E
	.align 2, 0
_0202654C: .4byte 0x02034ED4
_02026550:
	ldr r0, [r4]
	str r0, [r6]
	ldr r0, [r4, #4]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #4]
_0202655E:
	adds r3, r4, #0
	adds r3, #0x22
	ldrb r0, [r3]
	cmp r0, #0
	bne _0202659C
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _02026594 @ =0x02034ED4
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r2]
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrb r0, [r1, #6]
	cmp r0, #0xff
	bne _02026598
	subs r0, r4, #1
	strb r0, [r2]
	b _020265A0
	.align 2, 0
_02026594: .4byte 0x02034ED4
_02026598:
	ldrh r0, [r1, #4]
	b _0202659E
_0202659C:
	subs r0, #1
_0202659E:
	strb r0, [r3]
_020265A0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020265A8
sub_020265A8: @ 0x020265A8
	ldr r3, _020265CC @ =0x03004B80
	adds r1, r3, #0
	adds r1, #0x20
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _020265D0 @ =0x02034ED4
	ldr r0, [r0, #8]
	ldr r0, [r0]
	adds r1, #1
	strb r2, [r1]
	ldrh r0, [r0, #4]
	adds r1, #1
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x1f]
	bx lr
	.align 2, 0
_020265CC: .4byte 0x03004B80
_020265D0: .4byte 0x02034ED4

	thumb_func_start sub_020265D4
sub_020265D4: @ 0x020265D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _02026600 @ =0x03004B80
	ldr r7, _02026604 @ =0x03003710
	ldr r6, _02026608 @ =0x030041A0
	movs r0, #0
	mov sb, r0
	adds r0, r6, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _0202660C
	ldrh r0, [r5, #0x28]
	cmp r0, #0
	bne _0202660C
	mov r1, sb
	strb r1, [r5, #0x1f]
	bl sub_02025F60
	b _020267C4
	.align 2, 0
_02026600: .4byte 0x03004B80
_02026604: .4byte 0x03003710
_02026608: .4byte 0x030041A0
_0202660C:
	adds r3, r5, #0
	adds r3, #0x22
	ldrb r0, [r3]
	cmp r0, #0
	beq _0202663C
	subs r0, #1
	strb r0, [r3]
	ldr r0, [r5, #0x20]
	ldr r1, _02026634 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	beq _0202662A
	b _020267C4
_0202662A:
	ldr r3, _02026638 @ =0x00000419
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	b _020267C4
	.align 2, 0
_02026634: .4byte 0x00FFFF00
_02026638: .4byte 0x00000419
_0202663C:
	adds r2, r5, #0
	adds r2, #0x21
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _02026668 @ =0x02034ED4
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r2]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrb r0, [r1, #6]
	cmp r0, #0xff
	beq _0202666C
	ldrh r0, [r1, #4]
	strb r0, [r3]
	b _020267C4
	.align 2, 0
_02026668: .4byte 0x02034ED4
_0202666C:
	adds r1, r6, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0
	beq _02026678
	b _020267A8
_02026678:
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _020266B4 @ =0x0202F7FC
	adds r0, r0, r1
	mov r8, r0
	ldr r0, [r5]
	ldrb r1, [r5, #0x1e]
	ldrh r2, [r5, #0x1a]
	mov r3, r8
	ldrh r3, [r3]
	mov ip, r3
	bl sub_0201F660
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r1, [r0]
	mov ip, r0
	cmp r1, #0
	bne _020266B8
	adds r2, r5, #0
	adds r2, #0x29
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x10
	b _020266C6
	.align 2, 0
_020266B4: .4byte 0x0202F7FC
_020266B8:
	adds r2, r5, #0
	adds r2, #0x29
	ldrb r0, [r2]
	lsls r0, r0, #1
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r7, r3
_020266C6:
	adds r1, r1, r0
	ldr r0, _020266E4 @ =0x00000FFF
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _020266E8
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x10
	b _020266F2
	.align 2, 0
_020266E4: .4byte 0x00000FFF
_020266E8:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #1
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r7, r3
_020266F2:
	adds r1, r1, r0
	ldrb r0, [r4]
	strh r0, [r1]
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x87
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #3
	bne _02026754
	subs r0, #0x25
	ldrh r0, [r0]
	cmp r0, #0
	bne _02026738
	adds r0, r6, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	cmp r0, #0
	beq _02026750
	cmp r0, #3
	beq _02026726
	cmp r0, #7
	bne _02026754
_02026726:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #3
	bls _02026750
	cmp r0, #5
	beq _02026750
	cmp r0, #6
	bne _02026754
	b _02026750
_02026738:
	adds r0, r6, #0
	adds r0, #0x8d
	ldrb r0, [r0]
	cmp r0, #0
	bne _02026754
	mov r1, r8
	ldrh r0, [r1, #8]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _02026754
_02026750:
	movs r3, #1
	mov sb, r3
_02026754:
	ldr r3, [r5]
	ldr r0, [r6]
	subs r2, r3, r0
	cmp r2, #0
	bge _02026760
	rsbs r2, r2, #0
_02026760:
	ldr r1, [r5, #4]
	ldr r0, [r6, #4]
	subs r1, r1, r0
	cmp r1, #0
	bge _0202676C
	rsbs r1, r1, #0
_0202676C:
	ldr r0, _020267A4 @ =0x00002FFF
	cmp r2, r0
	bgt _020267AC
	cmp r1, r0
	bgt _020267AC
	mov r0, sb
	cmp r0, #1
	bne _020267AC
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r3, r0
	ldrb r2, [r5, #0x1e]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	orrs r3, r0
	str r3, [r6, #0x10]
	movs r0, #0xf0
	ands r0, r2
	lsls r0, r0, #8
	adds r0, r0, r1
	str r0, [r6, #0x14]
	movs r0, #9
	strb r0, [r4]
	b _020267AC
	.align 2, 0
_020267A4: .4byte 0x00002FFF
_020267A8:
	movs r0, #1
	strb r0, [r1]
_020267AC:
	adds r1, r5, #0
	adds r1, #0x27
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	ldrb r1, [r5, #0x1e]
	adds r0, r6, #0
	adds r0, #0x9d
	strb r1, [r0]
	strb r2, [r5, #0x1f]
	bl sub_02025F60
_020267C4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_020267D0
sub_020267D0: @ 0x020267D0
	push {r4, lr}
	ldr r4, _0202681C @ =0x03004B80
	ldr r3, _02026820 @ =0x030041A0
	ldr r0, _02026824 @ =0x03003710
	ldr r2, _02026828 @ =0x00000417
	adds r1, r0, r2
	movs r2, #1
	strb r2, [r1]
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _02026806
	adds r0, r3, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0
	beq _02026806
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #2
	bne _02026814
_02026806:
	ldr r0, _0202682C @ =0x02034E0C
	ldrb r1, [r4, #0x1f]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_02026814:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0202681C: .4byte 0x03004B80
_02026820: .4byte 0x030041A0
_02026824: .4byte 0x03003710
_02026828: .4byte 0x00000417
_0202682C: .4byte 0x02034E0C

	thumb_func_start sub_02026830
sub_02026830: @ 0x02026830
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _02026998 @ =0x03004B80
	mov ip, r0
	ldr r0, [r0, #4]
	asrs r0, r0, #8
	mov r1, ip
	str r0, [r1, #0x14]
	ldr r0, [r1]
	asrs r0, r0, #8
	str r0, [r1, #0x10]
	ldr r2, _0202699C @ =0x02034ED4
	mov r0, ip
	adds r0, #0x20
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r0, #1
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r5, [r0]
	ldr r2, _020269A0 @ =0x03003710
	ldr r3, _020269A4 @ =0x00000417
	adds r0, r2, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	mov r8, r1
	ldrh r0, [r5, #6]
	ldr r1, _020269A8 @ =0x0000FFFF
	cmp r0, r1
	bne _02026882
	b _02026988
_02026882:
	ldr r2, _020269AC @ =0x03001B50
	mov sb, r2
	movs r7, #0x86
	lsls r7, r7, #4
	add r7, sb
	movs r6, #1
	movs r3, #0x3f
	mov sl, r3
_02026892:
	ldrb r3, [r7]
	lsls r3, r3, #3
	ldr r0, _020269B0 @ =0x03002410
	adds r3, r3, r0
	ldrb r1, [r5, #1]
	movs r0, #0xc
	ands r0, r1
	ldrb r1, [r3, #1]
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3, #1]
	ldrb r0, [r5, #1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r6
	lsls r0, r0, #5
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #1]
	ldrb r0, [r5, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r4, sl
	ands r4, r1
	orrs r4, r0
	strb r4, [r3, #1]
	ldrb r0, [r5, #3]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1f
	ands r0, r6
	lsls r0, r0, #4
	ldrb r1, [r3, #3]
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3, #3]
	ldrb r0, [r5, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r6
	lsls r0, r0, #5
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	ldrb r0, [r5, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	mov r1, ip
	ldr r0, [r1, #0x14]
	ldrb r1, [r5]
	adds r1, r1, r0
	ldr r0, _020269B4 @ =0x00000846
	add r0, sb
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r3]
	ldrh r1, [r5, #2]
	lsls r1, r1, #0x17
	lsrs r1, r1, #0x17
	mov r2, ip
	ldr r0, [r2, #0x10]
	adds r1, r1, r0
	ldr r0, _020269B8 @ =0x00000844
	add r0, sb
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r2, _020269BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _020269C0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r3, #4]
	ldr r0, _020269C4 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	movs r0, #0x10
	orrs r4, r0
	strb r4, [r3, #1]
	ldrb r0, [r3, #5]
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r2, r0
	strb r2, [r3, #5]
	ldrb r1, [r5, #5]
	lsrs r1, r1, #4
	lsls r1, r1, #4
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldr r3, _020269A0 @ =0x03003710
	ldr r1, _020269A4 @ =0x00000417
	adds r0, r3, r1
	add r0, r8
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	add r8, r1
	adds r5, #8
	ldrh r0, [r5, #6]
	ldr r2, _020269A8 @ =0x0000FFFF
	cmp r0, r2
	bne _02026892
_02026988:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02026998: .4byte 0x03004B80
_0202699C: .4byte 0x02034ED4
_020269A0: .4byte 0x03003710
_020269A4: .4byte 0x00000417
_020269A8: .4byte 0x0000FFFF
_020269AC: .4byte 0x03001B50
_020269B0: .4byte 0x03002410
_020269B4: .4byte 0x00000846
_020269B8: .4byte 0x00000844
_020269BC: .4byte 0x000001FF
_020269C0: .4byte 0xFFFFFE00
_020269C4: .4byte 0xFFFFFC00

	thumb_func_start sub_020269C8
sub_020269C8: @ 0x020269C8
	push {lr}
	ldr r0, _020269DC @ =0x02035BF4
	bl sub_02026E4C
	bl sub_02026BD8
	bl sub_020269F0
	pop {r0}
	bx r0
	.align 2, 0
_020269DC: .4byte 0x02035BF4

	thumb_func_start sub_020269E0
sub_020269E0: @ 0x020269E0
	push {lr}
	bl sub_02026A34
	bl sub_02028B44
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020269F0
sub_020269F0: @ 0x020269F0
	push {r4, lr}
	sub sp, #4
	ldr r4, _02026A24 @ =0x03000028
	movs r3, #1
	rsbs r3, r3, #0
	movs r2, #0
	ldr r0, _02026A28 @ =0x03000038
	movs r1, #2
_02026A00:
	str r3, [r0]
	strb r2, [r0, #4]
	adds r0, #8
	subs r1, #1
	cmp r1, #0
	bge _02026A00
	mov r0, sp
	ldr r2, _02026A2C @ =0x0000FFFF
	adds r1, r2, #0
	strh r1, [r0]
	ldr r2, _02026A30 @ =0x01000005
	adds r1, r4, #0
	bl CpuSet
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02026A24: .4byte 0x03000028
_02026A28: .4byte 0x03000038
_02026A2C: .4byte 0x0000FFFF
_02026A30: .4byte 0x01000005

	thumb_func_start sub_02026A34
sub_02026A34: @ 0x02026A34
	bx lr
	.align 2, 0

	thumb_func_start sub_02026A38
sub_02026A38: @ 0x02026A38
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r7, #0
	ldr r5, _02026A74 @ =0x02035C10
	lsls r0, r6, #2
	adds r0, r0, r5
	ldr r4, [r0]
	movs r0, #0
	bl sub_0202846C
	cmp r0, #0
	beq _02026A98
	ldr r0, _02026A78 @ =0x03000028
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r4
	cmp r0, #0
	bne _02026A7C
	lsrs r2, r4, #0x19
	movs r0, #1
	bics r0, r2
	adds r2, r0, #0
	b _02026A7E
	.align 2, 0
_02026A74: .4byte 0x02035C10
_02026A78: .4byte 0x03000028
_02026A7C:
	movs r2, #2
_02026A7E:
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	bne _02026A94
	lsrs r1, r1, #0x19
	movs r0, #1
	bics r0, r1
	cmp r2, r0
	blt _02026AAC
	b _02026A98
_02026A94:
	cmp r2, #1
	ble _02026AAC
_02026A98:
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	movs r1, #0
	bl sub_02028B90
	ldr r1, _02026AB4 @ =0x03000028
	lsls r0, r7, #1
	adds r0, r0, r1
	strh r6, [r0]
_02026AAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02026AB4: .4byte 0x03000028

	thumb_func_start sub_02026AB8
sub_02026AB8: @ 0x02026AB8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r6, #1
	ldr r5, _02026AF4 @ =0x02035C10
	lsls r0, r7, #2
	adds r0, r0, r5
	ldr r4, [r0]
	movs r0, #1
	bl sub_0202846C
	cmp r0, #0
	beq _02026B18
	ldr r0, _02026AF8 @ =0x03000028
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r4
	cmp r0, #0
	bne _02026AFC
	lsrs r2, r4, #0x19
	adds r0, r6, #0
	bics r0, r2
	adds r2, r0, #0
	b _02026AFE
	.align 2, 0
_02026AF4: .4byte 0x02035C10
_02026AF8: .4byte 0x03000028
_02026AFC:
	movs r2, #2
_02026AFE:
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	bne _02026B14
	lsrs r1, r1, #0x19
	movs r0, #1
	bics r0, r1
	cmp r2, r0
	blt _02026B2C
	b _02026B18
_02026B14:
	cmp r2, #1
	ble _02026B2C
_02026B18:
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	movs r1, #0
	bl sub_02028B90
	ldr r1, _02026B34 @ =0x03000028
	lsls r0, r6, #1
	adds r0, r0, r1
	strh r7, [r0]
_02026B2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02026B34: .4byte 0x03000028

	thumb_func_start sub_02026B38
sub_02026B38: @ 0x02026B38
	push {lr}
	movs r0, #1
	movs r1, #0
	bl sub_02028BCC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02026B48
sub_02026B48: @ 0x02026B48
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r7, #2
	ldr r5, _02026B84 @ =0x02035C10
	lsls r0, r6, #2
	adds r0, r0, r5
	ldr r4, [r0]
	movs r0, #2
	bl sub_0202846C
	cmp r0, #0
	beq _02026BA8
	ldr r0, _02026B88 @ =0x03000028
	movs r1, #4
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r4
	cmp r0, #0
	bne _02026B8C
	lsrs r2, r4, #0x19
	movs r0, #1
	bics r0, r2
	adds r2, r0, #0
	b _02026B8E
	.align 2, 0
_02026B84: .4byte 0x02035C10
_02026B88: .4byte 0x03000028
_02026B8C:
	movs r2, #2
_02026B8E:
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	bne _02026BA4
	lsrs r1, r1, #0x19
	movs r0, #1
	bics r0, r1
	cmp r2, r0
	blt _02026BBC
	b _02026BA8
_02026BA4:
	cmp r2, #1
	ble _02026BBC
_02026BA8:
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	movs r1, #0
	bl sub_02028B90
	ldr r1, _02026BC4 @ =0x03000028
	lsls r0, r7, #1
	adds r0, r0, r1
	strh r6, [r0]
_02026BBC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02026BC4: .4byte 0x03000028

	thumb_func_start sub_02026BC8
sub_02026BC8: @ 0x02026BC8
	push {lr}
	movs r0, #2
	movs r1, #0
	bl sub_02028BCC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02026BD8
sub_02026BD8: @ 0x02026BD8
	push {lr}
	ldr r0, _02026BF8 @ =sub_02026D74
	bl sub_02028E10
	ldr r0, _02026BFC @ =sub_02026DFC
	bl sub_02028DE8
	ldr r1, _02026C00 @ =0x03000050
	ldr r2, _02026C04 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _02026C08 @ =0x03000052
	movs r0, #0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_02026BF8: .4byte sub_02026D74
_02026BFC: .4byte sub_02026DFC
_02026C00: .4byte 0x03000050
_02026C04: .4byte 0x0000FFFF
_02026C08: .4byte 0x03000052

	thumb_func_start sub_02026C0C
sub_02026C0C: @ 0x02026C0C
	bx lr
	.align 2, 0

	thumb_func_start sub_02026C10
sub_02026C10: @ 0x02026C10
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #4
	bl sub_0202846C
	cmp r0, #0
	beq _02026C28
	ldr r0, _02026C44 @ =0x03000050
	ldrh r0, [r0]
	cmp r0, r4
	beq _02026C5E
_02026C28:
	ldr r0, _02026C48 @ =0x02035CBC
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrb r1, [r1]
	movs r0, #4
	bl sub_02028B58
	cmp r4, #1
	bne _02026C50
	ldr r0, _02026C4C @ =0x03000052
	ldrb r0, [r0]
	bl sub_02026C7C
	b _02026C5A
	.align 2, 0
_02026C44: .4byte 0x03000050
_02026C48: .4byte 0x02035CBC
_02026C4C: .4byte 0x03000052
_02026C50:
	movs r0, #4
	movs r1, #0
	movs r2, #0
	bl sub_02028CE4
_02026C5A:
	ldr r0, _02026C64 @ =0x03000050
	strh r4, [r0]
_02026C5E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02026C64: .4byte 0x03000050

	thumb_func_start sub_02026C68
sub_02026C68: @ 0x02026C68
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #4
	bl sub_02028BCC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02026C7C
sub_02026C7C: @ 0x02026C7C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0
	ldr r0, _02026CB4 @ =0x03000052
	ldrb r1, [r0]
	cmp r4, r1
	beq _02026D66
	strb r4, [r0]
	movs r0, #4
	bl sub_0202846C
	cmp r0, #0
	beq _02026D66
	ldr r0, _02026CB8 @ =0x03000050
	ldrh r0, [r0]
	cmp r0, #1
	bne _02026D66
	movs r7, #0
	movs r5, #0
	cmp r4, #2
	beq _02026CE0
	cmp r4, #2
	bgt _02026CBC
	cmp r4, #1
	beq _02026CC6
	b _02026D66
	.align 2, 0
_02026CB4: .4byte 0x03000052
_02026CB8: .4byte 0x03000050
_02026CBC:
	cmp r6, #3
	beq _02026D00
	cmp r6, #4
	beq _02026D24
	b _02026D66
_02026CC6:
	ldr r1, _02026CDC @ =0x0000FFFF
	movs r0, #4
	movs r2, #0
	bl sub_02028CE4
	movs r0, #4
	movs r1, #0
	movs r2, #1
	bl sub_02028CE4
	b _02026D54
	.align 2, 0
_02026CDC: .4byte 0x0000FFFF
_02026CE0:
	ldr r1, _02026CFC @ =0x0000FFFF
	movs r0, #4
	movs r2, #0
	bl sub_02028CE4
	movs r0, #4
	movs r1, #0x94
	movs r2, #1
	bl sub_02028CE4
	movs r5, #0x1e
	movs r7, #1
	b _02026D54
	.align 2, 0
_02026CFC: .4byte 0x0000FFFF
_02026D00:
	ldr r1, _02026D1C @ =0x0000FFFF
	movs r0, #4
	movs r2, #0
	bl sub_02028CE4
	movs r1, #0x84
	lsls r1, r1, #2
	movs r0, #4
	movs r2, #1
	bl sub_02028CE4
	ldr r5, _02026D20 @ =0x0000FFF0
	movs r7, #1
	b _02026D54
	.align 2, 0
_02026D1C: .4byte 0x0000FFFF
_02026D20: .4byte 0x0000FFF0
_02026D24:
	ldr r1, _02026D6C @ =0x0000FFFF
	movs r0, #4
	movs r2, #0
	bl sub_02028CE4
	movs r0, #4
	movs r1, #0
	movs r2, #1
	bl sub_02028CE4
	ldr r2, _02026D70 @ =0x03001918
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_02026D54:
	movs r0, #4
	adds r1, r7, #0
	bl sub_02028CAC
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	movs r0, #4
	bl sub_02028C3C
_02026D66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02026D6C: .4byte 0x0000FFFF
_02026D70: .4byte 0x03001918

	thumb_func_start sub_02026D74
sub_02026D74: @ 0x02026D74
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	ldr r0, [r5, #8]
	ldr r0, [r0, #0x2c]
	cmp r5, r0
	beq _02026DEA
	ldr r0, _02026DB0 @ =0x03000052
	ldrb r0, [r0]
	cmp r0, #2
	bne _02026DC6
	adds r0, r4, #0
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _02026DC2
	cmp r0, #1
	bgt _02026DB4
	cmp r0, #0
	beq _02026DBE
	b _02026DEA
	.align 2, 0
_02026DB0: .4byte 0x03000052
_02026DB4:
	cmp r0, #3
	beq _02026DC2
	cmp r0, #5
	beq _02026DC2
	b _02026DEA
_02026DBE:
	adds r0, r4, #2
	b _02026DE6
_02026DC2:
	adds r0, r4, #1
	b _02026DE6
_02026DC6:
	adds r0, r4, #0
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	beq _02026DE4
	cmp r0, #5
	bgt _02026DE0
	cmp r0, #0
	beq _02026DE4
	b _02026DEA
_02026DE0:
	cmp r0, #7
	bne _02026DEA
_02026DE4:
	subs r0, r4, #1
_02026DE6:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_02026DEA:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	adds r3, r6, #0
	bl sub_020279BC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_02026DFC
sub_02026DFC: @ 0x02026DFC
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r0, #8]
	ldr r0, _02026E44 @ =0x03000052
	ldrb r0, [r0]
	cmp r0, #4
	bne _02026E10
	cmp r1, #0
	bne _02026E20
_02026E10:
	cmp r0, #2
	bne _02026E3C
	ldr r0, _02026E48 @ =0x04000100
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #4
	bhi _02026E3C
_02026E20:
	movs r4, #0xe1
	lsls r4, r4, #3
	adds r2, #8
	movs r3, #9
_02026E28:
	ldr r1, [r2]
	cmp r1, #0
	beq _02026E34
	ldr r0, [r1, #0x34]
	adds r0, r0, r4
	str r0, [r1, #0x34]
_02026E34:
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _02026E28
_02026E3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02026E44: .4byte 0x03000052
_02026E48: .4byte 0x04000100

	thumb_func_start sub_02026E4C
sub_02026E4C: @ 0x02026E4C
	push {r4, r5, lr}
	ldr r1, _02026ED4 @ =0x03000594
	str r0, [r1]
	ldr r1, _02026ED8 @ =0x04000084
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x80
	strb r0, [r1]
	subs r1, #4
	ldr r2, _02026EDC @ =0x0000FF77
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xd
	strb r0, [r1]
	ldr r2, _02026EE0 @ =0x04000088
	ldrh r1, [r2]
	ldr r0, _02026EE4 @ =0x00003FFF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _02026EE8 @ =0x04000060
	movs r0, #8
	strh r0, [r1]
	adds r1, #2
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r5, _02026EEC @ =sub_02029004
	ldr r4, _02026EF0 @ =0x03001064
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xd8
	bl CpuFastSet
	ldr r0, _02026EF4 @ =0x03000598
	str r4, [r0]
	ldr r1, _02026EF8 @ =0x0300059C
	ldr r0, _02026EFC @ =sub_020290C4
	subs r0, r0, r5
	adds r0, r0, r4
	str r0, [r1]
	ldr r1, _02026F00 @ =0x030005A0
	ldr r0, _02026F04 @ =sub_020291E4
	subs r0, r0, r5
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _02026F08 @ =0x030005A4
	bl sub_02026F3C
	bl sub_02028ACC
	bl sub_02028098
	bl sub_02027074
	bl sub_02028480
	bl sub_02028190
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02026ED4: .4byte 0x03000594
_02026ED8: .4byte 0x04000084
_02026EDC: .4byte 0x0000FF77
_02026EE0: .4byte 0x04000088
_02026EE4: .4byte 0x00003FFF
_02026EE8: .4byte 0x04000060
_02026EEC: .4byte sub_02029004
_02026EF0: .4byte 0x03001064
_02026EF4: .4byte 0x03000598
_02026EF8: .4byte 0x0300059C
_02026EFC: .4byte sub_020290C4
_02026F00: .4byte 0x030005A0
_02026F04: .4byte sub_020291E4
_02026F08: .4byte 0x030005A4

	thumb_func_start sub_02026F0C
sub_02026F0C: @ 0x02026F0C
	push {lr}
	bl sub_02026FAC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02026F18
sub_02026F18: @ 0x02026F18
	push {lr}
	bl sub_02028E38
	bl sub_020281FC
	bl sub_02027728
	ldr r0, _02026F38 @ =0x0300006B
	ldrb r0, [r0]
	cmp r0, #0
	beq _02026F32
	bl sub_02027610
_02026F32:
	pop {r0}
	bx r0
	.align 2, 0
_02026F38: .4byte 0x0300006B

	thumb_func_start sub_02026F3C
sub_02026F3C: @ 0x02026F3C
	push {r4, lr}
	sub sp, #4
	adds r3, r0, #0
	ldr r1, _02026F8C @ =0x0300006B
	movs r0, #1
	strb r0, [r1]
	ldr r1, _02026F90 @ =0x03000058
	str r3, [r1]
	ldr r2, _02026F94 @ =0x03000060
	adds r0, r3, #0
	adds r0, #0xb0
	str r0, [r2]
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r0, r3, r4
	str r0, [r1, #4]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r3, r1
	str r0, [r2, #4]
	ldr r1, _02026F98 @ =0x03000068
	ldr r2, _02026F9C @ =0x0000F9C4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _02026FA0 @ =0x0300006A
	movs r0, #0
	strb r0, [r1]
	ldr r1, _02026FA4 @ =0x04000083
	movs r0, #0x9a
	strb r0, [r1]
	ldr r0, _02026FA8 @ =0x040000A0
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02026F8C: .4byte 0x0300006B
_02026F90: .4byte 0x03000058
_02026F94: .4byte 0x03000060
_02026F98: .4byte 0x03000068
_02026F9C: .4byte 0x0000F9C4
_02026FA0: .4byte 0x0300006A
_02026FA4: .4byte 0x04000083
_02026FA8: .4byte 0x040000A0

	thumb_func_start sub_02026FAC
sub_02026FAC: @ 0x02026FAC
	push {r4, lr}
	ldr r2, _02027018 @ =0x04000100
	ldr r0, _0202701C @ =0x03000068
	ldrh r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldr r0, _02027020 @ =0x0300006B
	ldrb r0, [r0]
	cmp r0, #0
	beq _02027010
	ldr r1, _02027024 @ =0x040000BC
	ldrh r0, [r1, #0xa]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	subs r2, #0x38
	ldrh r0, [r2, #0xa]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r2, #0xa]
	ldrh r0, [r2, #0xa]
	ldr r3, _02027028 @ =0x03000058
	ldr r4, _0202702C @ =0x0300006A
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _02027030 @ =0x040000A0
	str r0, [r1, #4]
	ldr r3, _02027034 @ =0xB6400004
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _02027038 @ =0x03000060
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0202703C @ =0x040000A4
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4]
_02027010:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02027018: .4byte 0x04000100
_0202701C: .4byte 0x03000068
_02027020: .4byte 0x0300006B
_02027024: .4byte 0x040000BC
_02027028: .4byte 0x03000058
_0202702C: .4byte 0x0300006A
_02027030: .4byte 0x040000A0
_02027034: .4byte 0xB6400004
_02027038: .4byte 0x03000060
_0202703C: .4byte 0x040000A4

	thumb_func_start sub_02027040
sub_02027040: @ 0x02027040
	ldr r1, _02027060 @ =0x0300006B
	movs r0, #0
	strb r0, [r1]
	ldr r1, _02027064 @ =0x040000BC
	ldrh r0, [r1, #0xa]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	adds r1, #0xc
	ldrh r0, [r1, #0xa]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	bx lr
	.align 2, 0
_02027060: .4byte 0x0300006B
_02027064: .4byte 0x040000BC

	thumb_func_start sub_02027068
sub_02027068: @ 0x02027068
	ldr r1, _02027070 @ =0x0300006B
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_02027070: .4byte 0x0300006B

	thumb_func_start sub_02027074
sub_02027074: @ 0x02027074
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _020271CC @ =0x03000070
	movs r0, #0
	str r0, [r1]
	adds r3, r1, #0
	ldr r2, _020271D0 @ =0x03001728
	ldr r0, _020271D4 @ =0x030013C4
	mov ip, r0
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r7, r3, r1
	movs r1, #0
	movs r4, #3
	ldr r5, _020271D8 @ =0x00000175
	adds r0, r2, r5
_02027096:
	strb r1, [r0]
	subs r0, #0x7c
	subs r4, #1
	cmp r4, #0
	bge _02027096
	movs r4, #4
	movs r0, #1
	strb r0, [r2]
	adds r1, r2, #0
	adds r1, #0x7c
	movs r0, #2
	strb r0, [r1]
	adds r1, #0x7c
	movs r0, #3
	strb r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r4, [r0]
	movs r1, #0
	ldr r0, _020271D4 @ =0x030013C4
	movs r4, #6
_020270C2:
	strb r1, [r0, #1]
	strb r1, [r0]
	adds r0, #0x7c
	subs r4, #1
	cmp r4, #0
	bge _020270C2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r3, r2
	mov r5, ip
	str r5, [r0]
	mov r1, ip
	adds r1, #0x7c
	mov r0, ip
	adds r0, #0x70
	strb r1, [r0]
	lsrs r0, r1, #8
	mov r2, ip
	adds r2, #0x71
	strb r0, [r2]
	lsrs r0, r1, #0x10
	adds r2, #1
	strb r0, [r2]
	lsrs r1, r1, #0x18
	mov r0, ip
	adds r0, #0x73
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0xfc
	subs r0, #7
	strb r1, [r0]
	lsrs r0, r1, #8
	subs r2, #5
	strb r0, [r2]
	lsrs r0, r1, #0x10
	adds r2, #1
	strb r0, [r2]
	lsrs r1, r1, #0x18
	mov r0, ip
	adds r0, #0x6f
	strb r1, [r0]
	mov r8, ip
	movs r5, #0xff
	adds r2, #0x7a
	mov r3, ip
	movs r6, #0x7c
	movs r4, #4
_02027120:
	mov r1, r8
	adds r1, #0x7c
	adds r1, r6, r1
	adds r0, r1, #0
	ands r0, r5
	strb r0, [r2, #4]
	lsrs r0, r1, #8
	ands r0, r5
	strb r0, [r2, #5]
	lsrs r0, r1, #0x10
	ands r0, r5
	strb r0, [r2, #6]
	lsrs r1, r1, #0x18
	strb r1, [r2, #7]
	adds r0, r3, #0
	ands r0, r5
	strb r0, [r2]
	lsrs r0, r3, #8
	ands r0, r5
	strb r0, [r2, #1]
	lsrs r0, r3, #0x10
	ands r0, r5
	strb r0, [r2, #2]
	lsrs r0, r3, #0x18
	strb r0, [r2, #3]
	adds r2, #0x7c
	adds r3, #0x7c
	adds r6, #0x7c
	subs r4, #1
	cmp r4, #0
	bge _02027120
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, ip
	strb r7, [r0]
	lsrs r1, r7, #8
	ldr r0, _020271DC @ =0x00000359
	add r0, ip
	strb r1, [r0]
	lsrs r1, r7, #0x10
	ldr r0, _020271E0 @ =0x0000035A
	add r0, ip
	strb r1, [r0]
	lsrs r1, r7, #0x18
	ldr r0, _020271E4 @ =0x0000035B
	add r0, ip
	strb r1, [r0]
	movs r1, #0x9b
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xd5
	lsls r0, r0, #2
	add r0, ip
	strb r1, [r0]
	lsrs r2, r1, #8
	ldr r0, _020271E8 @ =0x00000355
	add r0, ip
	strb r2, [r0]
	lsrs r2, r1, #0x10
	ldr r0, _020271EC @ =0x00000356
	add r0, ip
	strb r2, [r0]
	lsrs r1, r1, #0x18
	ldr r0, _020271F0 @ =0x00000357
	add r0, ip
	strb r1, [r0]
	ldr r0, _020271F4 @ =0xFFFFFE88
	adds r1, r7, r0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	str r0, [r7, #0x6c]
	adds r0, r7, #0
	subs r0, #0xf8
	str r0, [r1, #0x74]
	adds r1, r7, #0
	subs r1, #0x8c
	ldr r2, _020271F8 @ =0xFFFFFE8C
	adds r0, r7, r2
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020271CC: .4byte 0x03000070
_020271D0: .4byte 0x03001728
_020271D4: .4byte 0x030013C4
_020271D8: .4byte 0x00000175
_020271DC: .4byte 0x00000359
_020271E0: .4byte 0x0000035A
_020271E4: .4byte 0x0000035B
_020271E8: .4byte 0x00000355
_020271EC: .4byte 0x00000356
_020271F0: .4byte 0x00000357
_020271F4: .4byte 0xFFFFFE88
_020271F8: .4byte 0xFFFFFE8C

	thumb_func_start sub_020271FC
sub_020271FC: @ 0x020271FC
	ldr r2, [r0, #0x6c]
	ldr r1, [r0, #0x70]
	str r1, [r2, #0x70]
	ldr r1, [r0, #0x70]
	ldr r0, [r0, #0x6c]
	str r0, [r1, #0x6c]
	bx lr
	.align 2, 0

	thumb_func_start sub_0202720C
sub_0202720C: @ 0x0202720C
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _02027248 @ =0x03000070
	ldr r1, [r0, #0x74]
	ldrb r2, [r3, #1]
	cmp r2, #1
	bne _02027250
	adds r0, #0x80
	cmp r1, r0
	beq _02027280
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _0202722E
	ldrb r0, [r3, #8]
	ldrb r2, [r1, #8]
	cmp r0, r2
	blo _02027280
_0202722E:
	ldr r1, [r1, #0x70]
	ldr r0, _0202724C @ =0x030000F0
	cmp r1, r0
	beq _02027280
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _0202722E
	ldrb r0, [r3, #8]
	ldrb r4, [r1, #8]
	cmp r0, r4
	bhs _0202722E
	b _02027280
	.align 2, 0
_02027248: .4byte 0x03000070
_0202724C: .4byte 0x030000F0
_02027250:
	cmp r2, #2
	bne _0202728C
	adds r2, r0, #0
	adds r2, #0x80
	cmp r1, r2
	beq _02027280
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _02027280
	ldrb r0, [r3, #8]
	ldrb r4, [r1, #8]
	cmp r0, r4
	blo _02027280
	adds r4, r2, #0
	adds r2, r0, #0
_0202726E:
	ldr r1, [r1, #0x70]
	cmp r1, r4
	beq _02027280
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _02027280
	ldrb r0, [r1, #8]
	cmp r2, r0
	bhs _0202726E
_02027280:
	str r1, [r3, #0x70]
	ldr r0, [r1, #0x6c]
	str r0, [r3, #0x6c]
	ldr r0, [r1, #0x6c]
	str r3, [r0, #0x70]
	str r3, [r1, #0x6c]
_0202728C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_02027294
sub_02027294: @ 0x02027294
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, #0x30
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bge _020272AE
	movs r2, #0
	b _020272B4
_020272AE:
	cmp r1, #0x77
	ble _020272B4
	movs r2, #0x78
_020272B4:
	ldrb r0, [r0]
	cmp r0, #0
	bne _020272CC
	ldr r0, _020272C8 @ =0x02035E48
	lsls r1, r2, #0x10
	asrs r1, r1, #0xe
	adds r1, r1, r0
	ldr r0, [r1]
	b _020272E4
	.align 2, 0
_020272C8: .4byte 0x02035E48
_020272CC:
	cmp r0, #4
	beq _020272E0
	ldr r0, _020272DC @ =0x02035CE0
	lsls r1, r2, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	b _020272E4
	.align 2, 0
_020272DC: .4byte 0x02035CE0
_020272E0:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
_020272E4:
	bx lr
	.align 2, 0

	thumb_func_start sub_020272E8
sub_020272E8: @ 0x020272E8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x77
	bls _020272F2
	movs r1, #0x77
_020272F2:
	ldr r0, _020272FC @ =0x02035DD0
	adds r0, r1, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_020272FC: .4byte 0x02035DD0

	thumb_func_start sub_02027300
sub_02027300: @ 0x02027300
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x44
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0202735A
	ldr r0, [r4, #4]
	str r0, [r3, #0x44]
	ldrb r1, [r4, #0x10]
	adds r0, r1, #1
	strb r0, [r4, #0x10]
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	ldr r2, [r4, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bge _0202732C
	strb r1, [r4, #0x10]
_0202732C:
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r5, #2
	ldrsh r1, [r0, r5]
	str r1, [r4, #4]
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #8]
	strh r1, [r4, #0xa]
	ldr r0, [r3, #0x44]
	subs r1, r1, r0
	strh r1, [r4, #0xa]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #8]
	bl __divsi3
	strh r0, [r4, #0xa]
_0202735A:
	movs r5, #0xa
	ldrsh r1, [r4, r5]
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	ldrh r1, [r4, #8]
	subs r1, #1
	strh r1, [r4, #8]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_02027370
sub_02027370: @ 0x02027370
	bx lr
	.align 2, 0

	thumb_func_start sub_02027374
sub_02027374: @ 0x02027374
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #1]
	cmp r0, #1
	bne _020273B4
	ldrb r4, [r5, #9]
	lsls r4, r4, #8
	ldr r2, [r5, #4]
	ldr r0, [r2, #8]
	ldrh r1, [r0, #0x34]
	muls r4, r1, r4
	lsrs r4, r4, #7
	adds r0, #0x40
	ldrb r0, [r0]
	muls r4, r0, r4
	lsrs r4, r4, #7
	adds r0, r2, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	muls r4, r0, r4
	lsrs r4, r4, #0xf
	adds r2, #0x4e
	ldrb r0, [r2]
	muls r4, r0, r4
	lsrs r4, r4, #7
	adds r0, r5, #0
	bl sub_02027300
	muls r4, r0, r4
	lsrs r4, r4, #0xf
	str r4, [r5, #0x14]
	b _020273C6
_020273B4:
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r0, #0xe6
	ldr r1, [r5, #0x14]
	muls r0, r1, r0
	lsrs r0, r0, #9
	str r0, [r5, #0x14]
	adds r4, r0, #0
_020273C6:
	lsrs r4, r4, #8
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_020273D0
sub_020273D0: @ 0x020273D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	movs r6, #0
	ldrb r4, [r5, #9]
	movs r0, #0x4c
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _020273EE
	movs r6, #1
_020273EE:
	adds r0, r5, #0
	bl sub_02027300
	cmp r6, #0
	bne _020273FC
	movs r0, #8
	b _020274C2
_020273FC:
	cmp r7, #0
	beq _02027402
	lsls r4, r4, #1
_02027402:
	lsls r4, r4, #0xf
	ldr r1, [r5, #4]
	adds r0, r1, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	muls r4, r0, r4
	lsrs r4, r4, #0xe
	adds r0, r1, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	muls r4, r0, r4
	lsrs r4, r4, #7
	ldr r1, [r1, #8]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	muls r4, r0, r4
	lsrs r4, r4, #8
	ldrh r0, [r1, #0x34]
	muls r4, r0, r4
	ldrb r0, [r5]
	cmp r0, #3
	bne _02027446
	lsrs r4, r4, #0x16
	str r4, [r5, #0x14]
	lsls r0, r4, #2
	adds r4, r0, r4
	lsrs r4, r4, #7
	cmp r4, #4
	bls _02027440
	movs r4, #4
_02027440:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	b _020274C2
_02027446:
	lsrs r4, r4, #0xf
	str r4, [r5, #0x14]
	ldr r0, [r5, #0x44]
	muls r4, r0, r4
	lsrs r4, r4, #0x19
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0202745E
	movs r4, #0xf
_0202745E:
	ldr r1, [r5, #0x14]
	ldr r0, [r5, #0x48]
	muls r0, r1, r0
	lsrs r0, r0, #0x19
	str r0, [r5, #0x14]
	ands r0, r2
	cmp r0, #0
	beq _02027472
	movs r0, #0xf
	str r0, [r5, #0x14]
_02027472:
	ldr r5, [r5, #0x14]
	cmp r5, r4
	beq _0202749A
	mov r1, r8
	ldrh r2, [r1]
	adds r0, r2, #0
	adds r0, #0xf
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	subs r1, r5, r4
	cmp r1, #0
	bge _0202748C
	rsbs r1, r1, #0
_0202748C:
	adds r0, r2, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _020274A6
_0202749A:
	lsls r0, r4, #4
	movs r1, #8
	orrs r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _020274C0
_020274A6:
	ldr r0, _020274CC @ =0x0000FFF8
	ands r0, r2
	cmp r0, #0
	beq _020274B0
	movs r2, #7
_020274B0:
	lsls r0, r4, #4
	orrs r0, r2
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r4, r5
	bhs _020274C0
	movs r0, #8
	orrs r6, r0
_020274C0:
	adds r0, r6, #0
_020274C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_020274CC: .4byte 0x0000FFF8

	thumb_func_start sub_020274D0
sub_020274D0: @ 0x020274D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r3, [r5, #0xc]
	ldr r6, [r5, #4]
	adds r2, r5, #0
	adds r2, #0x2c
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _020274E8
	subs r0, #1
	str r0, [r5, #0x2c]
	b _02027502
_020274E8:
	ldr r4, [r2, #4]
	cmp r4, #0
	beq _02027502
	ldr r0, [r2, #8]
	ldr r1, [r2, #0x10]
	adds r0, r0, r1
	str r0, [r2, #8]
	subs r0, r4, #1
	str r0, [r2, #4]
	cmp r0, #0
	bne _02027502
	ldr r0, [r2, #0xc]
	str r0, [r2, #8]
_02027502:
	ldr r0, [r2, #8]
	adds r3, r3, r0
	adds r2, r6, #0
	adds r2, #0x4f
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _0202755A
	ldr r1, _02027540 @ =0x02035E48
	adds r0, r6, #0
	adds r0, #0x50
	ldrb r0, [r0]
	adds r0, #0x30
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _02027544 @ =0xFFFF8000
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	muls r1, r0, r1
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r1, r2
	asrs r1, r1, #0xe
	ldrb r0, [r5]
	cmp r0, #0
	bne _02027548
	muls r3, r1, r3
	lsrs r3, r3, #8
	b _0202755A
	.align 2, 0
_02027540: .4byte 0x02035E48
_02027544: .4byte 0xFFFF8000
_02027548:
	movs r4, #0x80
	lsls r4, r4, #4
	subs r3, r4, r3
	lsls r3, r3, #8
	adds r0, r3, #0
	bl __udivsi3
	adds r3, r0, #0
	subs r3, r4, r3
_0202755A:
	adds r4, r5, #0
	adds r4, #0x20
	ldr r0, [r4, #8]
	ldr r2, [r0, #8]
	cmp r2, #0
	beq _02027608
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _02027604
	ldr r0, _02027590 @ =0x02036028
	ldr r1, [r5, #0x20]
	lsrs r1, r1, #1
	adds r1, r1, r0
	ldrb r1, [r1]
	ldrb r0, [r5]
	cmp r0, #0
	bne _020275B0
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _02027594
	muls r0, r3, r0
	muls r0, r2, r0
	lsrs r0, r0, #0x13
	adds r3, r3, r0
	b _020275E8
	.align 2, 0
_02027590: .4byte 0x02036028
_02027594:
	lsls r3, r3, #0xc
	rsbs r0, r0, #0
	adds r1, r0, #0
	muls r1, r2, r1
	lsrs r1, r1, #3
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r3, #0
	bl __udivsi3
	adds r3, r0, #0
	lsls r3, r3, #4
	b _020275E8
_020275B0:
	lsls r0, r1, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _020275CE
	movs r0, #0x80
	lsls r0, r0, #4
	subs r0, r0, r3
	lsls r0, r0, #0x13
	muls r1, r2, r1
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r1, r2
	bl __udivsi3
	b _020275E2
_020275CE:
	movs r0, #0x80
	lsls r0, r0, #4
	rsbs r1, r1, #0
	subs r0, r0, r3
	muls r1, r2, r1
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r1, r2
	muls r0, r1, r0
	lsrs r0, r0, #0x13
_020275E2:
	movs r3, #0x80
	lsls r3, r3, #4
	subs r3, r3, r0
_020275E8:
	ldr r0, [r4, #8]
	ldr r1, [r4]
	ldr r0, [r0, #4]
	adds r1, r1, r0
	str r1, [r4]
	lsrs r0, r1, #1
	cmp r0, #0xff
	bls _02027608
	ldr r2, _02027600 @ =0xFFFFFE00
	adds r0, r1, r2
	str r0, [r4]
	b _02027608
	.align 2, 0
_02027600: .4byte 0xFFFFFE00
_02027604:
	subs r0, #1
	str r0, [r4, #4]
_02027608:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_02027610
sub_02027610: @ 0x02027610
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r4, _0202764C @ =0x03000070
	ldr r5, [r4, #0x74]
	movs r0, #0
	str r0, [sp]
	ldr r1, _02027650 @ =0x03000864
	ldr r2, _02027654 @ =0x010000B0
	mov r0, sp
	bl CpuFastSet
	adds r4, #0x80
	cmp r5, r4
	beq _020276C8
_0202762C:
	adds r0, r5, #0
	bl sub_02027374
	adds r7, r0, #0
	ldrb r0, [r5, #1]
	cmp r0, #1
	bne _02027674
	ldrh r0, [r5, #0x18]
	subs r0, #1
	strh r0, [r5, #0x18]
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0x1b]
	cmp r0, #0
	beq _02027658
	ldrb r3, [r5, #0x1c]
	b _0202765E
	.align 2, 0
_0202764C: .4byte 0x03000070
_02027650: .4byte 0x03000864
_02027654: .4byte 0x010000B0
_02027658:
	adds r0, r4, #0
	adds r0, #0x4b
	ldrb r3, [r0]
_0202765E:
	adds r6, r3, #0
	adds r0, r5, #0
	bl sub_020274D0
	adds r2, r0, #0
	str r2, [r5, #0x10]
	adds r0, r4, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	strb r0, [r5, #0x1a]
	b _0202767C
_02027674:
	cmp r7, #0
	beq _020276B0
	ldrb r6, [r5, #0x1c]
	ldr r2, [r5, #0x10]
_0202767C:
	lsrs r2, r2, #2
	ldr r0, [r5, #0x60]
	ldr r0, [r0, #4]
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _020276BC @ =0x00002910
	bl __udivsi3
	adds r2, r0, #0
	movs r0, #0xb0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0xb0
	bl __udivsi3
	adds r2, r0, #0
	lsrs r2, r2, #5
	adds r0, r5, #0
	adds r1, r7, #0
	adds r3, r6, #0
	bl sub_02027F0C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _020276C0
_020276B0:
	ldr r5, [r5, #0x70]
	ldr r0, [r5, #0x6c]
	bl sub_02027C78
	b _020276C2
	.align 2, 0
_020276BC: .4byte 0x00002910
_020276C0:
	ldr r5, [r5, #0x70]
_020276C2:
	ldr r0, _02027710 @ =0x030000F0
	cmp r5, r0
	bne _0202762C
_020276C8:
	movs r5, #0
	movs r4, #6
_020276CC:
	ldr r0, _02027714 @ =0x030013C4
	adds r1, r5, r0
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _020276E2
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	bne _020276E2
	adds r0, r1, #0
	bl sub_02027B94
_020276E2:
	adds r5, #0x7c
	subs r4, #1
	cmp r4, #0
	bge _020276CC
	ldr r3, _02027718 @ =0x03000598
	ldr r0, _0202771C @ =0x03000864
	ldr r2, _02027720 @ =0x03000058
	ldr r1, _02027724 @ =0x0300006A
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r4, #0xb0
	lsls r4, r4, #2
	adds r2, r0, r4
	ldr r3, [r3]
	bl _call_via_r3
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02027710: .4byte 0x030000F0
_02027714: .4byte 0x030013C4
_02027718: .4byte 0x03000598
_0202771C: .4byte 0x03000864
_02027720: .4byte 0x03000058
_02027724: .4byte 0x0300006A

	thumb_func_start sub_02027728
sub_02027728: @ 0x02027728
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
_02027736:
	mov r1, sl
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02027774 @ =0x03001728
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _02027754
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _02027754
	adds r0, r4, #0
	bl sub_02027B94
_02027754:
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _0202775C
	b _0202799C
_0202775C:
	cmp r0, #1
	bne _02027782
	adds r0, r4, #0
	bl sub_020274D0
	adds r6, r0, #0
	str r6, [r4, #0x10]
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _02027778
	ldrb r0, [r4, #0x1c]
	b _0202777E
	.align 2, 0
_02027774: .4byte 0x03001728
_02027778:
	ldr r0, [r4, #4]
	adds r0, #0x4b
	ldrb r0, [r0]
_0202777E:
	mov r8, r0
	b _02027788
_02027782:
	ldr r6, [r4, #0x10]
	ldrb r2, [r4, #0x1c]
	mov r8, r2
_02027788:
	movs r0, #0x40
	mov r3, r8
	eors r0, r3
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	adds r0, r4, #0
	bl sub_020273D0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _020277CC @ =0x04000081
	mov ip, r0
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov sb, r3
	movs r5, #0x11
	lsls r5, r3
	mvns r0, r5
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r2, #0
	mov r0, r8
	cmp r0, #0x40
	bne _020277D0
	mov r3, ip
	ldrb r1, [r3]
	adds r0, r2, #0
	ands r0, r1
	orrs r0, r5
	strb r0, [r3]
	b _020277FA
	.align 2, 0
_020277CC: .4byte 0x04000081
_020277D0:
	mov r0, r8
	cmp r0, #0x3f
	bhi _020277EA
	mov r1, ip
	ldrb r0, [r1]
	adds r1, r2, #0
	ands r1, r0
	movs r0, #0x10
	lsls r0, r3
	orrs r1, r0
	mov r2, ip
	strb r1, [r2]
	b _020277FA
_020277EA:
	mov r3, ip
	ldrb r0, [r3]
	ands r1, r0
	movs r0, #1
	mov r2, sb
	lsls r0, r2
	orrs r1, r0
	strb r1, [r3]
_020277FA:
	ldrb r5, [r4, #1]
	cmp r5, #1
	bne _02027824
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne _02027818
	adds r0, r4, #0
	adds r1, r7, #0
	bl sub_02027D14
	str r5, [r4, #0x64]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	b _0202799C
_02027818:
	adds r0, #1
	str r0, [r4, #0x64]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	b _02027874
_02027824:
	ldrb r0, [r4]
	cmp r0, #3
	bne _02027874
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r0, #0xe6
	ldr r1, [r4, #0x14]
	muls r0, r1, r0
	lsrs r0, r0, #9
	str r0, [r4, #0x14]
	adds r1, r0, #0
	mov r3, r8
	cmp r3, #0x40
	beq _02027844
	lsls r1, r1, #1
_02027844:
	lsls r0, r1, #2
	adds r1, r0, r1
	lsrs r1, r1, #7
	cmp r1, #0
	beq _0202786C
	cmp r1, #4
	bls _02027854
	movs r1, #4
_02027854:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _02027864 @ =0x04000073
	ldr r0, _02027868 @ =0x02035CC4
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	b _0202799C
	.align 2, 0
_02027864: .4byte 0x04000073
_02027868: .4byte 0x02035CC4
_0202786C:
	adds r0, r4, #0
	bl sub_02027C78
	b _0202799C
_02027874:
	ldr r2, [r4, #0x58]
	ldrb r1, [r2, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02027896
	ldr r0, [r4, #0x68]
	ldrh r3, [r0]
	ldr r1, [r4, #0x64]
	cmp r1, r3
	bhs _02027890
	adds r0, r0, r1
	ldrb r5, [r0, #2]
	b _02027898
_02027890:
	adds r0, r3, r0
	ldrb r5, [r0, #1]
	b _02027898
_02027896:
	movs r5, #0xff
_02027898:
	ldrb r0, [r4]
	cmp r0, #2
	beq _020278E8
	cmp r0, #2
	bgt _020278A8
	cmp r0, #1
	beq _020278B2
	b _0202799C
_020278A8:
	cmp r0, #3
	beq _02027928
	cmp r0, #4
	beq _02027950
	b _0202799C
_020278B2:
	cmp r7, #8
	beq _020278D0
	ldr r0, _020278C8 @ =0x04000063
	strb r7, [r0]
	ldr r1, _020278CC @ =0x04000064
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r6, r0
	strh r6, [r1]
	b _020278DA
	.align 2, 0
_020278C8: .4byte 0x04000063
_020278CC: .4byte 0x04000064
_020278D0:
	ldrb r0, [r2, #8]
	cmp r0, #8
	bne _020278DA
	ldr r0, _020278E0 @ =0x04000064
	strh r6, [r0]
_020278DA:
	ldr r2, _020278E4 @ =0x04000062
	b _0202790E
	.align 2, 0
_020278E0: .4byte 0x04000064
_020278E4: .4byte 0x04000062
_020278E8:
	cmp r7, #8
	beq _02027908
	ldr r0, _02027900 @ =0x04000069
	strb r7, [r0]
	ldr r1, _02027904 @ =0x0400006C
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r6, r0
	strh r6, [r1]
	b _0202790C
	.align 2, 0
_02027900: .4byte 0x04000069
_02027904: .4byte 0x0400006C
_02027908:
	ldr r0, _02027920 @ =0x0400006C
	strh r6, [r0]
_0202790C:
	ldr r2, _02027924 @ =0x04000068
_0202790E:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	strb r0, [r2]
	cmp r5, #0xff
	beq _0202799C
	lsls r0, r5, #6
	strb r0, [r2]
	b _0202799C
	.align 2, 0
_02027920: .4byte 0x0400006C
_02027924: .4byte 0x04000068
_02027928:
	ldr r0, _02027948 @ =0x04000074
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r2, r3, #0
	ands r1, r2
	orrs r1, r6
	strh r1, [r0]
	cmp r7, #8
	beq _0202799C
	subs r0, #1
	ldr r1, _0202794C @ =0x02035CC4
	adds r1, r7, r1
	ldrb r1, [r1]
	strb r1, [r0]
	b _0202799C
	.align 2, 0
_02027948: .4byte 0x04000074
_0202794C: .4byte 0x02035CC4
_02027950:
	cmp r7, #8
	beq _0202795E
	ldr r0, _0202797C @ =0x04000079
	strb r7, [r0]
	ldr r1, _02027980 @ =0x0400007D
	movs r0, #0x80
	strb r0, [r1]
_0202795E:
	cmp r5, #0xff
	beq _02027988
	ldr r4, _02027984 @ =0x0400007C
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_020272E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r5, #0
	beq _02027978
	movs r0, #8
	orrs r1, r0
_02027978:
	strb r1, [r4]
	b _0202799C
	.align 2, 0
_0202797C: .4byte 0x04000079
_02027980: .4byte 0x0400007D
_02027984: .4byte 0x0400007C
_02027988:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_020272E8
	ldr r3, _020279B8 @ =0x0400007C
	ldrb r2, [r3]
	movs r1, #8
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_0202799C:
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	bgt _020279A8
	b _02027736
_020279A8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020279B8: .4byte 0x0400007C

	thumb_func_start sub_020279BC
sub_020279BC: @ 0x020279BC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	ldr r4, [r5, #8]
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	beq _020279E4
	b _02027B86
_020279E4:
	adds r0, r5, #0
	adds r0, #0x51
	ldrb r0, [r0]
	adds r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r5, #0
	adds r1, r7, #0
	mov r2, sp
	bl sub_020280B4
	ldr r6, [sp]
	ldrb r1, [r6, #1]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _02027A10
	ldrh r1, [r4, #0x30]
	mov r0, r8
	bl __udivsi3
	b _02027A1E
_02027A10:
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	ldrh r4, [r4, #0x30]
	adds r1, r1, r4
	mov r0, r8
	bl __divsi3
_02027A1E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0
	beq _02027A38
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _02027A38
	adds r4, r0, #0
	b _02027A8C
_02027A38:
	ldr r1, _02027AA4 @ =0x02035CCC
	ldrb r0, [r6]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x52
	ldrb r2, [r1]
	adds r1, r5, #0
	bl sub_02027E74
	adds r4, r0, #0
	cmp r4, #0
	bne _02027A54
	b _02027B86
_02027A54:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_02028A34
	movs r1, #0
	str r1, [r4, #0x64]
	adds r0, r5, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	str r1, [r4, #0x20]
	ldrh r0, [r5, #0x10]
	str r0, [r4, #0x24]
	ldr r0, [sp, #4]
	str r0, [r4, #0x50]
	str r1, [r4, #0x44]
	str r1, [r4, #0x48]
	adds r0, r4, #0
	adds r0, #0x4c
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #0xff
	strb r0, [r1]
	ldrb r1, [r6, #6]
	adds r0, r4, #0
	adds r0, #0x5c
	strb r1, [r0]
	str r6, [r4, #0x58]
_02027A8C:
	mov r0, sp
	ldrb r0, [r0, #0x11]
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _02027AA8
	movs r7, #0x30
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r4, #0x1c]
	b _02027AB2
	.align 2, 0
_02027AA4: .4byte 0x02035CCC
_02027AA8:
	mov r0, sp
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _02027AB2
	movs r7, #0x30
_02027AB2:
	movs r0, #0
	mov r1, sb
	strb r1, [r4, #9]
	str r0, [r4, #0x14]
	mov r0, r8
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	strb r0, [r4, #0x1a]
	ldrb r2, [r6, #7]
	adds r0, r4, #0
	adds r1, r7, #0
	bl sub_02027294
	str r0, [r4, #0xc]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [r4, #0x40]
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _02027B3A
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r6, #7]
	adds r0, r4, #0
	bl sub_02027294
	adds r2, r0, #0
	ldrh r0, [r5, #0x20]
	str r0, [r4, #0x2c]
	ldrh r0, [r5, #0x22]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	lsrs r0, r0, #8
	str r0, [r4, #0x30]
	ldrb r1, [r5, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _02027B0C
	ldr r0, [r4, #0xc]
	subs r0, r2, r0
	str r0, [r4, #0x38]
	b _02027B14
_02027B0C:
	ldr r0, [r4, #0xc]
	subs r0, r0, r2
	str r0, [r4, #0x38]
	str r2, [r4, #0xc]
_02027B14:
	ldr r0, [r4, #0x38]
	str r0, [r4, #0x3c]
	ldr r1, [r4, #0x30]
	bl __divsi3
	str r0, [r4, #0x3c]
	ldrb r1, [r5, #0x1d]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _02027B32
	strb r7, [r5, #0x1e]
	b _02027B34
_02027B32:
	strb r0, [r5, #0x1c]
_02027B34:
	movs r0, #0
	str r0, [r4, #0x34]
	b _02027B44
_02027B3A:
	str r0, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r0, [r4, #0x34]
	str r0, [r4, #0x38]
	str r0, [r4, #0x3c]
_02027B44:
	ldrb r0, [r4]
	cmp r0, #0
	bne _02027B5A
	ldrh r0, [r6, #2]
	ldr r1, [r5, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	b _02027B7A
_02027B5A:
	cmp r0, #3
	beq _02027B76
	ldrb r1, [r6, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02027B6C
	ldr r0, [sp, #8]
	b _02027B78
_02027B6C:
	ldrh r1, [r6, #2]
	adds r0, r4, #0
	adds r0, #0x68
	strb r1, [r0]
	b _02027B7A
_02027B76:
	ldr r0, [sp, #0xc]
_02027B78:
	str r0, [r4, #0x68]
_02027B7A:
	mov r0, r8
	cmp r0, #0
	bne _02027B86
	adds r0, r4, #0
	bl sub_02027B94
_02027B86:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_02027B94
sub_02027B94: @ 0x02027B94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _02027C6A
	ldr r0, [r4, #4]
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0
	bne _02027C6A
	ldrb r3, [r4]
	cmp r3, #0
	bne _02027BC0
	adds r0, r4, #0
	bl sub_020271FC
	movs r0, #2
	strb r0, [r4, #1]
	adds r0, r4, #0
	bl sub_0202720C
	b _02027C52
_02027BC0:
	ldrh r2, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	cmp r3, #3
	bne _02027BD0
	movs r0, #2
	b _02027C50
_02027BD0:
	lsrs r1, r1, #5
	cmp r1, #0
	bne _02027BDA
	movs r1, #0
	b _02027BE4
_02027BDA:
	ldr r0, [r4, #0x14]
	lsls r0, r0, #4
	orrs r1, r0
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
_02027BE4:
	ldrb r0, [r4]
	cmp r0, #2
	beq _02027C1C
	cmp r0, #2
	bgt _02027BF4
	cmp r0, #1
	beq _02027BFA
	b _02027C4E
_02027BF4:
	cmp r0, #4
	beq _02027C44
	b _02027C4E
_02027BFA:
	ldr r0, _02027C10 @ =0x04000063
	strb r1, [r0]
	ldr r1, _02027C14 @ =0x04000064
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r2, r0
	strh r2, [r1]
	ldr r2, _02027C18 @ =0x04000062
	b _02027C2E
	.align 2, 0
_02027C10: .4byte 0x04000063
_02027C14: .4byte 0x04000064
_02027C18: .4byte 0x04000062
_02027C1C:
	ldr r0, _02027C38 @ =0x04000069
	strb r1, [r0]
	ldr r1, _02027C3C @ =0x0400006C
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r2, r0
	strh r2, [r1]
	ldr r2, _02027C40 @ =0x04000068
_02027C2E:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	strb r0, [r2]
	b _02027C4E
	.align 2, 0
_02027C38: .4byte 0x04000069
_02027C3C: .4byte 0x0400006C
_02027C40: .4byte 0x04000068
_02027C44:
	ldr r0, _02027C70 @ =0x04000079
	strb r1, [r0]
	ldr r1, _02027C74 @ =0x0400007D
	movs r0, #0x80
	strb r0, [r1]
_02027C4E:
	movs r0, #0
_02027C50:
	strb r0, [r4, #1]
_02027C52:
	ldrb r0, [r4, #0x1b]
	ldr r1, [r4, #4]
	cmp r0, #0
	bne _02027C62
	adds r0, r1, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	strb r0, [r4, #0x1c]
_02027C62:
	adds r0, r1, #0
	adds r1, r4, #0
	bl sub_02028A4C
_02027C6A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02027C70: .4byte 0x04000079
_02027C74: .4byte 0x0400007D

	thumb_func_start sub_02027C78
sub_02027C78: @ 0x02027C78
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _02027D08
	ldrb r0, [r4]
	cmp r0, #4
	bhi _02027CFC
	lsls r0, r0, #2
	ldr r1, _02027C94 @ =_02027C98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02027C94: .4byte _02027C98
_02027C98: @ jump table
	.4byte _02027CAC @ case 0
	.4byte _02027CCC @ case 1
	.4byte _02027CDC @ case 2
	.4byte _02027CE4 @ case 3
	.4byte _02027CF0 @ case 4
_02027CAC:
	adds r0, r4, #0
	bl sub_020271FC
	ldr r0, _02027CC8 @ =0x03000070
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, [r2]
	str r1, [r4, #0x70]
	adds r0, #0xfc
	str r0, [r4, #0x6c]
	str r4, [r1, #0x6c]
	str r4, [r2]
	b _02027CFC
	.align 2, 0
_02027CC8: .4byte 0x03000070
_02027CCC:
	ldr r1, _02027CD8 @ =0x04000063
	movs r0, #8
	strb r0, [r1]
	adds r1, #2
	b _02027CF8
	.align 2, 0
_02027CD8: .4byte 0x04000063
_02027CDC:
	ldr r1, _02027CE0 @ =0x04000069
	b _02027CF2
	.align 2, 0
_02027CE0: .4byte 0x04000069
_02027CE4:
	ldr r1, _02027CEC @ =0x04000070
	movs r0, #0
	b _02027CFA
	.align 2, 0
_02027CEC: .4byte 0x04000070
_02027CF0:
	ldr r1, _02027D10 @ =0x04000079
_02027CF2:
	movs r0, #8
	strb r0, [r1]
	adds r1, #4
_02027CF8:
	movs r0, #0xc0
_02027CFA:
	strb r0, [r1]
_02027CFC:
	ldr r0, [r4, #4]
	adds r1, r4, #0
	bl sub_02028A4C
	movs r0, #0
	strb r0, [r4, #1]
_02027D08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02027D10: .4byte 0x04000079

	thumb_func_start sub_02027D14
sub_02027D14: @ 0x02027D14
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldrb r3, [r4]
	cmp r3, #2
	beq _02027D98
	cmp r3, #2
	bgt _02027D2C
	cmp r3, #1
	beq _02027D36
	b _02027E64
_02027D2C:
	cmp r3, #3
	beq _02027DC4
	cmp r3, #4
	beq _02027E18
	b _02027E64
_02027D36:
	ldr r1, _02027D64 @ =0x04000060
	ldr r0, [r4, #0x58]
	ldrb r0, [r0, #8]
	strb r0, [r1]
	ldr r2, _02027D68 @ =0x04000064
	ldr r0, [r4, #0xc]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _02027D6C @ =0x04000063
	strb r5, [r0]
	ldr r0, [r4, #0x58]
	ldrb r0, [r0, #1]
	ands r3, r0
	cmp r3, #0
	beq _02027D74
	ldr r1, _02027D70 @ =0x04000062
	ldr r0, [r4, #0x68]
	ldrb r0, [r0, #2]
	b _02027D7C
	.align 2, 0
_02027D64: .4byte 0x04000060
_02027D68: .4byte 0x04000064
_02027D6C: .4byte 0x04000063
_02027D70: .4byte 0x04000062
_02027D74:
	ldr r1, _02027D90 @ =0x04000062
	adds r0, r4, #0
	adds r0, #0x68
	ldrb r0, [r0]
_02027D7C:
	lsls r0, r0, #6
	strb r0, [r1]
	ldr r0, _02027D94 @ =0x04000064
	ldr r1, [r4, #0xc]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	b _02027E64
	.align 2, 0
_02027D90: .4byte 0x04000062
_02027D94: .4byte 0x04000064
_02027D98:
	ldr r0, _02027DB8 @ =0x04000069
	strb r5, [r0]
	ldr r2, _02027DBC @ =0x0400006C
	ldr r0, [r4, #0xc]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _02027DC0 @ =0x04000068
	adds r0, r4, #0
	adds r0, #0x68
	ldrb r0, [r0]
	lsls r0, r0, #6
	b _02027E62
	.align 2, 0
_02027DB8: .4byte 0x04000069
_02027DBC: .4byte 0x0400006C
_02027DC0: .4byte 0x04000068
_02027DC4:
	ldr r6, _02027E04 @ =0x03000070
	ldr r1, [r4, #0x68]
	ldr r0, [r6]
	cmp r1, r0
	beq _02027DE2
	ldr r1, _02027E08 @ =0x04000070
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4, #0x68]
	adds r1, #0x20
	movs r2, #8
	bl CpuSet
	ldr r0, [r4, #0x68]
	str r0, [r6]
_02027DE2:
	ldr r1, _02027E08 @ =0x04000070
	movs r0, #0xc0
	strb r0, [r1]
	ldr r2, _02027E0C @ =0x04000074
	ldr r0, [r4, #0xc]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _02027E10 @ =0x04000073
	ldr r0, _02027E14 @ =0x02035CC4
	adds r0, r5, r0
	ldrb r0, [r0]
	strb r0, [r1]
	subs r1, #1
	b _02027E60
	.align 2, 0
_02027E04: .4byte 0x03000070
_02027E08: .4byte 0x04000070
_02027E0C: .4byte 0x04000074
_02027E10: .4byte 0x04000073
_02027E14: .4byte 0x02035CC4
_02027E18:
	ldr r0, _02027E38 @ =0x04000079
	strb r5, [r0]
	ldr r0, [r4, #0x58]
	ldrb r1, [r0, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02027E3C
	ldrh r0, [r4, #0xc]
	bl sub_020272E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, [r4, #0x68]
	ldrb r0, [r0, #2]
	b _02027E4C
	.align 2, 0
_02027E38: .4byte 0x04000079
_02027E3C:
	ldrh r0, [r4, #0xc]
	bl sub_020272E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x68
	ldrb r0, [r0]
_02027E4C:
	cmp r0, #0
	beq _02027E54
	movs r0, #8
	orrs r1, r0
_02027E54:
	ldr r0, _02027E6C @ =0x0400007C
	strb r1, [r0]
	ldr r1, _02027E70 @ =0x0400007D
	movs r0, #0x80
	strb r0, [r1]
	subs r1, #5
_02027E60:
	movs r0, #0
_02027E62:
	strb r0, [r1]
_02027E64:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_02027E6C: .4byte 0x0400007C
_02027E70: .4byte 0x0400007D

	thumb_func_start sub_02027E74
sub_02027E74: @ 0x02027E74
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	cmp r1, #0
	bne _02027ED2
	ldr r1, _02027E9C @ =0x03000070
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r2, [r0]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r1, r3
	cmp r2, r0
	beq _02027EA0
	adds r4, r2, #0
	b _02027EBE
	.align 2, 0
_02027E9C: .4byte 0x03000070
_02027EA0:
	ldr r2, [r1, #0x74]
	adds r0, r1, #0
	adds r0, #0x80
	cmp r2, r0
	beq _02027EE8
	ldrb r0, [r2, #1]
	cmp r0, #1
	bne _02027EB6
	ldrb r0, [r2, #8]
	cmp r5, r0
	blo _02027EE8
_02027EB6:
	adds r4, r2, #0
	adds r0, r4, #0
	bl sub_02027C78
_02027EBE:
	adds r0, r4, #0
	bl sub_020271FC
	movs r0, #1
	strb r0, [r4, #1]
	strb r5, [r4, #8]
	adds r0, r4, #0
	bl sub_0202720C
	b _02027F02
_02027ED2:
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02027EEC @ =0x030016AC
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _02027EF0
	ldrb r2, [r4, #8]
	cmp r5, r2
	bhs _02027EF0
_02027EE8:
	movs r0, #0
	b _02027F04
	.align 2, 0
_02027EEC: .4byte 0x030016AC
_02027EF0:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _02027EFC
	adds r0, r4, #0
	bl sub_02027C78
_02027EFC:
	movs r0, #1
	strb r0, [r4, #1]
	strb r5, [r4, #8]
_02027F02:
	adds r0, r4, #0
_02027F04:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02027F0C
sub_02027F0C: @ 0x02027F0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x10]
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r4, [r0, #0x64]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r0, #0
	mov r8, r0
	movs r1, #0xb0
	mov sl, r1
	ldr r2, [sp, #0x10]
	ldr r1, [r2, #0x60]
	adds r0, r1, #0
	adds r0, #0x10
	str r0, [sp, #0x20]
	ldr r2, _02027F78 @ =0x03000864
	str r2, [sp, #0x14]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r0, r2, r0
	str r0, [sp, #0x18]
	movs r0, #0x7f
	subs r0, r0, r3
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x17
	str r0, [sp, #0x1c]
	mov r0, sb
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x17
	mov sb, r0
	ldr r7, [r1, #0xc]
	cmp r7, #0
	bne _02027F68
	ldr r7, [r1]
_02027F68:
	mov r0, sl
	muls r0, r6, r0
	adds r0, r4, r0
	lsrs r0, r0, #8
	cmp r0, r7
	bhs _02027F7C
	ldr r5, [sp, #0x18]
	b _02027F94
	.align 2, 0
_02027F78: .4byte 0x03000864
_02027F7C:
	lsls r0, r7, #8
	subs r0, r0, r4
	subs r0, #1
	adds r0, r0, r6
	adds r1, r6, #0
	bl __udivsi3
	lsls r0, r0, #1
	ldr r1, [sp, #0x14]
	adds r5, r0, r1
	movs r2, #1
	mov r8, r2
_02027F94:
	ldr r1, [sp, #0x10]
	ldr r0, [r1, #0x60]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02027FA4
	mov r2, r8
	cmp r2, #0
	bne _02027FD0
_02027FA4:
	ldr r0, _02027FCC @ =0x0300059C
	str r4, [sp]
	str r6, [sp, #4]
	ldr r1, [sp, #0x1c]
	str r1, [sp, #8]
	mov r2, sb
	str r2, [sp, #0xc]
	ldr r4, [r0]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl _call_via_r4
	adds r4, r0, #0
	mov r0, r8
	cmp r0, #0
	beq _0202807E
	movs r0, #1
	b _02028084
	.align 2, 0
_02027FCC: .4byte 0x0300059C
_02027FD0:
	ldr r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #8
	str r1, [sp, #0x24]
	ldr r1, _0202802C @ =0x0300059C
	str r4, [sp]
	str r6, [sp, #4]
	ldr r2, [sp, #0x1c]
	str r2, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	ldr r4, [r1]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl _call_via_r4
	adds r4, r0, #0
	ldr r1, [sp, #0x24]
	subs r4, r4, r1
	ldr r2, [sp, #0x14]
	subs r0, r5, r2
	asrs r0, r0, #1
	mov r1, sl
	subs r1, r1, r0
	mov sl, r1
	cmp r1, #0
	beq _0202807E
_0202800A:
	str r5, [sp, #0x14]
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x18]
	mov r0, sl
	muls r0, r6, r0
	adds r0, r4, r0
	lsrs r0, r0, #8
	cmp r0, r7
	bhs _02028030
	mov r1, sl
	lsls r0, r1, #1
	adds r5, r5, r0
	movs r2, #0
	mov r8, r2
	b _02028046
	.align 2, 0
_0202802C: .4byte 0x0300059C
_02028030:
	lsls r0, r7, #8
	subs r0, r0, r4
	subs r0, #1
	adds r0, r0, r6
	adds r1, r6, #0
	bl __udivsi3
	lsls r0, r0, #1
	adds r5, r5, r0
	movs r0, #1
	mov r8, r0
_02028046:
	str r4, [sp]
	str r6, [sp, #4]
	ldr r1, [sp, #0x1c]
	str r1, [sp, #8]
	mov r2, sb
	str r2, [sp, #0xc]
	ldr r0, _02028094 @ =0x0300059C
	ldr r4, [r0]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl _call_via_r4
	adds r4, r0, #0
	mov r1, r8
	cmp r1, #0
	beq _0202806E
	ldr r2, [sp, #0x24]
	subs r4, r4, r2
_0202806E:
	ldr r1, [sp, #0x14]
	subs r0, r5, r1
	asrs r0, r0, #1
	mov r2, sl
	subs r2, r2, r0
	mov sl, r2
	cmp r2, #0
	bne _0202800A
_0202807E:
	ldr r0, [sp, #0x10]
	str r4, [r0, #0x64]
	movs r0, #0
_02028084:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_02028094: .4byte 0x0300059C

	thumb_func_start sub_02028098
sub_02028098: @ 0x02028098
	ldr r1, _020280B0 @ =0x03000268
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	movs r2, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strb r2, [r1, #6]
	movs r0, #0x30
	strb r0, [r1, #7]
	bx lr
	.align 2, 0
_020280B0: .4byte 0x03000268

	thumb_func_start sub_020280B4
sub_020280B4: @ 0x020280B4
	push {r4, r5, r6, lr}
	adds r4, r2, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r1, _0202811C @ =0x03000594
	ldr r3, [r1]
	ldr r2, [r0, #8]
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r1, [r1]
	ldr r2, [r2]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	ldr r2, [r3, #4]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	adds r3, r2, r1
	adds r0, #0x42
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	adds r5, r3, r0
	movs r0, #0
	strb r0, [r4, #0x11]
	strb r0, [r4, #0x12]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _02028164
	adds r0, r1, #0
	cmp r0, #0x10
	bne _02028120
	ldrh r2, [r5, #2]
	adds r2, r3, r2
	ldrb r0, [r5, #4]
	subs r0, r6, r0
	lsls r0, r0, #0x18
	movs r1, #1
	strb r1, [r4, #0x11]
	lsrs r0, r0, #0x16
	adds r0, r0, r2
	ldrb r1, [r0, #2]
	strb r1, [r4, #0x10]
	ldrh r0, [r0]
	adds r0, r3, r0
	str r0, [r4]
	ldrh r0, [r0, #4]
	b _02028168
	.align 2, 0
_0202811C: .4byte 0x03000594
_02028120:
	cmp r0, #0x11
	bne _02028148
	ldrh r1, [r5, #2]
	adds r1, r3, r1
	ldr r2, _02028140 @ =0x03000268
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #2]
	str r2, [r4]
	ldr r0, _02028144 @ =0x02035CD4
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #0x12]
	b _0202816C
	.align 2, 0
_02028140: .4byte 0x03000268
_02028144: .4byte 0x02035CD4
_02028148:
	cmp r0, #0x12
	bne _0202816C
	ldrh r0, [r5, #2]
	adds r0, r3, r0
	b _02028154
_02028152:
	adds r0, #4
_02028154:
	ldrb r1, [r0]
	cmp r6, r1
	bhi _02028152
	ldrh r0, [r0, #2]
	adds r0, r3, r0
	str r0, [r4]
	ldrh r0, [r0, #4]
	b _02028168
_02028164:
	str r5, [r4]
	ldrh r0, [r5, #4]
_02028168:
	adds r0, r3, r0
	str r0, [r4, #4]
_0202816C:
	ldr r2, [r4]
	ldrb r0, [r2]
	cmp r0, #3
	bne _0202817A
	ldrh r0, [r5, #2]
	adds r0, r3, r0
	str r0, [r4, #0xc]
_0202817A:
	ldrb r1, [r2, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0202818A
	ldrh r0, [r2, #2]
	adds r0, r3, r0
	str r0, [r4, #8]
_0202818A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_02028190
sub_02028190: @ 0x02028190
	push {r4, lr}
	movs r2, #0
	ldr r4, _020281C0 @ =0x03001918
	movs r3, #0
_02028198:
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r0, #0
	adds r1, #0x41
	strb r3, [r1]
	adds r2, #1
	movs r1, #9
	adds r0, #0x2c
_020281AC:
	str r3, [r0]
	subs r0, #4
	subs r1, #1
	cmp r1, #0
	bge _020281AC
	cmp r2, #7
	ble _02028198
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_020281C0: .4byte 0x03001918

	thumb_func_start sub_020281C4
sub_020281C4: @ 0x020281C4
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	ldrb r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r3, #0
	movs r2, #0
	movs r0, #0x96
	mov r1, ip
	strh r0, [r1, #0x30]
	strh r2, [r1, #0x32]
	adds r1, #0x40
	movs r0, #0x80
	strb r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #8
	mov r1, ip
	strh r0, [r1, #0x34]
	strh r2, [r1, #0x36]
	strh r2, [r1, #0x3a]
	strh r2, [r1, #0x38]
	mov r0, ip
	adds r0, #0x43
	strb r3, [r0]
	bx lr

	thumb_func_start sub_020281FC
sub_020281FC: @ 0x020281FC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r6, #0
_02028202:
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _0202822C @ =0x03001918
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x41
	ldrb r0, [r0]
	adds r7, r6, #1
	cmp r0, #0
	beq _0202827E
	ldrh r2, [r1, #0x3a]
	cmp r2, #0
	bne _02028230
	cmp r0, #2
	bne _02028246
	adds r0, r6, #0
	bl sub_020283D4
	b _0202827E
	.align 2, 0
_0202822C: .4byte 0x03001918
_02028230:
	ldrh r0, [r1, #0x36]
	ldrh r3, [r1, #0x34]
	adds r0, r0, r3
	strh r0, [r1, #0x34]
	subs r0, r2, #1
	strh r0, [r1, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _02028246
	ldrh r0, [r1, #0x38]
	strh r0, [r1, #0x34]
_02028246:
	movs r2, #0
	adds r7, r6, #1
	adds r4, r1, #0
	adds r4, #8
	movs r5, #9
_02028250:
	ldr r0, [r4]
	cmp r0, #0
	beq _0202826C
	str r2, [sp]
	bl sub_020285C8
	lsls r0, r0, #0x18
	ldr r2, [sp]
	cmp r0, #0
	bne _02028268
	movs r2, #1
	b _0202826C
_02028268:
	movs r0, #0
	str r0, [r4]
_0202826C:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _02028250
	cmp r2, #0
	bne _0202827E
	adds r0, r6, #0
	bl sub_020283D4
_0202827E:
	adds r6, r7, #0
	cmp r6, #7
	ble _02028202
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0202828C
sub_0202828C: @ 0x0202828C
	push {r4, lr}
	ldr r2, _020282B0 @ =0x03000594
	ldr r4, [r2]
	ldr r3, [r4, #8]
	lsls r1, r1, #2
	adds r2, r1, r3
	ldr r2, [r2]
	adds r3, r3, r2
	ldr r2, [r4, #0x14]
	adds r1, r1, r2
	ldr r1, [r1]
	adds r2, r2, r1
	adds r1, r3, #0
	bl sub_020282E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_020282B0: .4byte 0x03000594

	thumb_func_start sub_020282B4
sub_020282B4: @ 0x020282B4
	push {r4, r5, lr}
	adds r3, r2, #0
	ldr r2, _020282DC @ =0x03000594
	ldr r5, [r2]
	ldr r4, [r5, #0xc]
	lsls r1, r1, #2
	adds r2, r1, r4
	ldr r2, [r2]
	adds r4, r4, r2
	ldr r2, [r5, #0x18]
	adds r1, r1, r2
	ldr r1, [r1]
	adds r2, r2, r1
	adds r1, r4, #0
	bl sub_02028368
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_020282DC: .4byte 0x03000594

	thumb_func_start sub_020282E0
sub_020282E0: @ 0x020282E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r1, _02028364 @ =0x03001918
	adds r5, r0, r1
	adds r4, r5, #0
	adds r4, #0x41
	ldrb r0, [r4]
	cmp r0, #0
	beq _02028306
	adds r0, r3, #0
	bl sub_020283D4
_02028306:
	str r6, [r5, #4]
	str r7, [r5]
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl sub_020281C4
	ldr r0, [r5, #4]
	movs r7, #0
	ldrsb r7, [r0, r7]
	adds r0, #2
	movs r6, #0
	mov r8, r4
	cmp r6, r7
	bge _02028352
	adds r4, r0, #0
_0202832A:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0202834A
	bl sub_020284A0
	lsls r2, r6, #2
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	str r0, [r1]
	ldrh r1, [r4]
	ldr r2, [r5, #4]
	adds r2, r2, r1
	adds r1, r5, #0
	bl sub_020284C4
_0202834A:
	adds r4, #2
	adds r6, #1
	cmp r6, r7
	blt _0202832A
_02028352:
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_02028364: .4byte 0x03001918

	thumb_func_start sub_02028368
sub_02028368: @ 0x02028368
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov sb, r3
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _020283D0 @ =0x03001918
	adds r5, r0, r1
	movs r0, #0x41
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _02028394
	adds r0, r4, #0
	bl sub_020283D4
_02028394:
	str r6, [r5, #4]
	str r7, [r5]
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl sub_020281C4
	bl sub_020284A0
	str r0, [r5, #8]
	ldr r2, [r5, #4]
	mov r3, sb
	lsls r1, r3, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r2, r2, r1
	adds r1, r5, #0
	bl sub_020284C4
	mov r0, r8
	strb r4, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_020283D0: .4byte 0x03001918

	thumb_func_start sub_020283D4
sub_020283D4: @ 0x020283D4
	push {r4, r5, r6, r7, lr}
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0202840C @ =0x03001918
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x41
	ldrb r0, [r2]
	cmp r0, #0
	beq _02028406
	adds r7, r2, #0
	movs r6, #0
	adds r4, r1, #0
	adds r4, #8
	movs r5, #9
_020283F4:
	ldr r0, [r4]
	bl sub_020285B0
	stm r4!, {r6}
	subs r5, #1
	cmp r5, #0
	bge _020283F4
	movs r0, #0
	strb r0, [r7]
_02028406:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0202840C: .4byte 0x03001918

	thumb_func_start sub_02028410
sub_02028410: @ 0x02028410
	push {r4, lr}
	adds r3, r1, #0
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _02028444 @ =0x03001918
	adds r4, r1, r0
	adds r2, r4, #0
	adds r2, #0x41
	ldrb r0, [r2]
	cmp r0, #0
	beq _0202843E
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	strh r1, [r4, #0x38]
	strh r3, [r4, #0x3a]
	ldrh r0, [r4, #0x34]
	rsbs r0, r0, #0
	adds r1, r3, #0
	bl __divsi3
	strh r0, [r4, #0x36]
_0202843E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028444: .4byte 0x03001918

	thumb_func_start sub_02028448
sub_02028448: @ 0x02028448
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _02028468 @ =0x03001918
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	adds r2, #0x3c
	movs r0, #1
	ands r1, r0
	ldrb r3, [r2]
	subs r0, #3
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
_02028468: .4byte 0x03001918

	thumb_func_start sub_0202846C
sub_0202846C: @ 0x0202846C
	ldr r2, _0202847C @ =0x03001918
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, #0x41
	adds r1, r1, r2
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0202847C: .4byte 0x03001918

	thumb_func_start sub_02028480
sub_02028480: @ 0x02028480
	ldr r0, _0202849C @ =0x03000B24
	movs r1, #0
	adds r0, #8
	movs r2, #0xf
_02028488:
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	adds r0, #0x54
	subs r2, #1
	cmp r2, #0
	bge _02028488
	bx lr
	.align 2, 0
_0202849C: .4byte 0x03000B24

	thumb_func_start sub_020284A0
sub_020284A0: @ 0x020284A0
	ldr r1, _020284B0 @ =0x03000B24
	ldr r0, _020284B4 @ =0x000004EC
	adds r2, r1, r0
_020284A6:
	ldr r0, [r1, #8]
	cmp r0, #0
	bne _020284B8
	adds r0, r1, #0
	b _020284C0
	.align 2, 0
_020284B0: .4byte 0x03000B24
_020284B4: .4byte 0x000004EC
_020284B8:
	adds r1, #0x54
	cmp r1, r2
	ble _020284A6
	movs r0, #0
_020284C0:
	bx lr
	.align 2, 0

	thumb_func_start sub_020284C4
sub_020284C4: @ 0x020284C4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	cmp r5, #0
	beq _0202857A
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _020284DC
	adds r0, r5, #0
	bl sub_020285B0
_020284DC:
	movs r4, #0
	str r4, [r5, #0x34]
	adds r0, r5, #0
	adds r0, #0x49
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	str r6, [r5]
	str r7, [r5, #8]
	str r4, [r5, #0xc]
	adds r0, r5, #0
	movs r1, #0
	bl sub_02028A98
	adds r1, r5, #0
	adds r1, #0x4b
	movs r0, #0x40
	strb r0, [r1]
	movs r2, #0
	strh r4, [r5, #0x10]
	movs r0, #0x22
	str r0, [r5, #0x14]
	str r4, [r5, #0x18]
	strb r2, [r5, #0x1c]
	strb r2, [r5, #0x1d]
	strb r2, [r5, #0x1e]
	strh r4, [r5, #0x20]
	strh r4, [r5, #0x22]
	adds r1, #2
	movs r0, #0x80
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4f
	strb r2, [r0]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x51
	strb r2, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r3, [r0]
	cmp r3, #1
	bne _0202854E
	adds r1, #2
	movs r0, #0xc
	strb r0, [r1]
	subs r1, #6
	movs r0, #0x7f
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x53
	strb r3, [r0]
	b _02028560
_0202854E:
	adds r1, r5, #0
	adds r1, #0x52
	movs r0, #3
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r0, #7
	strb r2, [r0]
_02028560:
	adds r1, r5, #0
	adds r1, #0x44
	movs r3, #0
	movs r2, #0x7f
	movs r0, #0x7f
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x48
	strb r2, [r0]
	subs r0, #2
	strh r3, [r0]
	subs r0, #0x22
	str r0, [r5, #0x30]
_0202857A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_02028580
sub_02028580: @ 0x02028580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r4, #0
	beq _020285A8
	adds r1, r4, #0
	adds r1, #0x49
	ldrb r6, [r1]
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4, #0xc]
	adds r5, r1, #0
	cmp r0, #0
	beq _020285A6
_0202859A:
	ldr r4, [r0, #0x78]
	bl sub_02027B94
	adds r0, r4, #0
	cmp r0, #0
	bne _0202859A
_020285A6:
	strb r6, [r5]
_020285A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020285B0
sub_020285B0: @ 0x020285B0
	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	beq _020285C0
	bl sub_02028580
	movs r0, #0
	str r0, [r4, #8]
_020285C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_020285C8
sub_020285C8: @ 0x020285C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	cmp r5, #0
	beq _020285DC
	ldr r1, [r5, #8]
	cmp r1, #0
	bne _020285E0
_020285DC:
	movs r0, #1
	b _02028A26
_020285E0:
	mov r8, r1
	mov r0, r8
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _020285F2
	b _02028A0C
_020285F2:
	adds r0, r5, #0
	bl sub_02028580
	b _02028A24
_020285FA:
	adds r0, r5, #0
	bl sub_020285B0
	movs r0, #2
	b _02028A26
_02028604:
	ldr r2, [r5]
	ldrb r6, [r2]
	adds r2, #1
	str r2, [r5]
	cmp r6, #0xbf
	bhi _0202868E
	cmp r6, #0x5f
	bhi _02028620
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r4, [r0]
	adds r0, #4
	ldrb r2, [r0]
	b _02028646
_02028620:
	adds r0, r5, #0
	bl sub_02028A74
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	adds r0, #0x44
	strh r4, [r0]
	ldr r0, [r5]
	ldrb r2, [r0]
	adds r0, #1
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x48
	strb r2, [r0]
	adds r0, r6, #0
	subs r0, #0x60
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_02028646:
	movs r0, #0x96
	muls r4, r0, r4
	ldr r0, _02028670 @ =0x03000270
	ldr r7, [r0]
	cmp r7, #0
	beq _02028674
	mov r0, r8
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _02028674
	lsls r3, r4, #0x10
	lsrs r3, r3, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r7
	b _02028680
	.align 2, 0
_02028670: .4byte 0x03000270
_02028674:
	lsls r3, r4, #0x10
	lsrs r3, r3, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_020279BC
_02028680:
	adds r0, r5, #0
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #1
	beq _0202868C
	b _02028A0C
_0202868C:
	b _020286B2
_0202868E:
	cmp r6, #0xc0
	bne _0202869A
	adds r0, r5, #0
	adds r0, #0x46
	ldrh r4, [r0]
	b _020286AE
_0202869A:
	cmp r6, #0xc1
	bne _020286BA
	adds r0, r5, #0
	bl sub_02028A74
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	adds r0, #0x46
	strh r4, [r0]
_020286AE:
	movs r0, #0x96
	muls r4, r0, r4
_020286B2:
	ldr r0, [r5, #0x34]
	adds r0, r0, r4
	str r0, [r5, #0x34]
	b _02028A0C
_020286BA:
	movs r0, #0xf0
	ands r0, r6
	cmp r0, #0xd0
	bne _020286FA
	movs r0, #0xf
	ands r0, r6
	strb r0, [r5, #0x1d]
	adds r1, r5, #0
	adds r1, #0x51
	ldrb r1, [r1]
	ldrb r3, [r2]
	adds r1, r1, r3
	strb r1, [r5, #0x1e]
	adds r3, r2, #1
	str r3, [r5]
	ldrb r1, [r2, #1]
	strh r1, [r5, #0x22]
	adds r2, r3, #1
	str r2, [r5]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _020286F2
	ldrb r0, [r3, #1]
	strh r0, [r5, #0x20]
	adds r0, r2, #1
	str r0, [r5]
	b _020286F4
_020286F2:
	strh r1, [r5, #0x20]
_020286F4:
	movs r0, #1
	strb r0, [r5, #0x1c]
	b _02028A0C
_020286FA:
	adds r0, r6, #0
	subs r0, #0xc2
	cmp r0, #0x3d
	bls _02028704
	b _02028A0C
_02028704:
	lsls r0, r0, #2
	ldr r1, _02028710 @ =_02028714
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02028710: .4byte _02028714
_02028714: @ jump table
	.4byte _0202886A @ case 0
	.4byte _02028886 @ case 1
	.4byte _02028892 @ case 2
	.4byte _020288DA @ case 3
	.4byte _020288DA @ case 4
	.4byte _02028876 @ case 5
	.4byte _020288EE @ case 6
	.4byte _020288F8 @ case 7
	.4byte _02028902 @ case 8
	.4byte _02028A0C @ case 9
	.4byte _02028A0C @ case 10
	.4byte _02028A0C @ case 11
	.4byte _02028A0C @ case 12
	.4byte _02028A0C @ case 13
	.4byte _02028A0C @ case 14
	.4byte _02028A0C @ case 15
	.4byte _02028A0C @ case 16
	.4byte _02028A0C @ case 17
	.4byte _02028A0C @ case 18
	.4byte _02028A0C @ case 19
	.4byte _02028A0C @ case 20
	.4byte _02028A0C @ case 21
	.4byte _02028A0C @ case 22
	.4byte _02028A0C @ case 23
	.4byte _02028A0C @ case 24
	.4byte _02028A0C @ case 25
	.4byte _02028A0C @ case 26
	.4byte _02028A0C @ case 27
	.4byte _02028A0C @ case 28
	.4byte _02028A0C @ case 29
	.4byte _0202889E @ case 30
	.4byte _020288AA @ case 31
	.4byte _020288B6 @ case 32
	.4byte _020288CE @ case 33
	.4byte _02028928 @ case 34
	.4byte _02028932 @ case 35
	.4byte _02028942 @ case 36
	.4byte _0202893A @ case 37
	.4byte _02028822 @ case 38
	.4byte _020288C2 @ case 39
	.4byte _02028A0C @ case 40
	.4byte _02028A0C @ case 41
	.4byte _02028A0C @ case 42
	.4byte _02028A0C @ case 43
	.4byte _02028A0C @ case 44
	.4byte _02028A0C @ case 45
	.4byte _02028828 @ case 46
	.4byte _02028A0C @ case 47
	.4byte _02028A0C @ case 48
	.4byte _02028A0C @ case 49
	.4byte _02028842 @ case 50
	.4byte _02028A0C @ case 51
	.4byte _02028A0C @ case 52
	.4byte _02028A0C @ case 53
	.4byte _0202894E @ case 54
	.4byte _02028A0C @ case 55
	.4byte _02028A0C @ case 56
	.4byte _02028A0C @ case 57
	.4byte _02028A0C @ case 58
	.4byte _02028A0C @ case 59
	.4byte _02028A0C @ case 60
	.4byte _0202880C @ case 61
_0202880C:
	adds r0, r5, #0
	adds r0, #0x24
	ldr r1, [r5, #0x30]
	cmp r1, r0
	bne _02028818
	b _020285FA
_02028818:
	subs r0, r1, #4
	str r0, [r5, #0x30]
	ldr r0, [r0]
	str r0, [r5]
	b _02028A0C
_02028822:
	movs r0, #0
	strb r0, [r5, #0x1c]
	b _02028A0C
_02028828:
	mov r2, sp
	ldr r0, [r5]
	ldrb r1, [r0]
	strb r1, [r2]
	adds r0, #1
	str r0, [r5]
	ldrb r1, [r0]
	strb r1, [r2, #1]
	adds r0, #1
	str r0, [r5]
	mov r0, r8
	ldr r1, [r0, #4]
	b _02028860
_02028842:
	mov r2, sp
	ldr r1, [r5]
	ldrb r0, [r1]
	strb r0, [r2]
	adds r1, #1
	str r1, [r5]
	ldrb r0, [r1]
	strb r0, [r2, #1]
	adds r1, #1
	str r1, [r5]
	ldr r0, [r5, #0x30]
	stm r0!, {r1}
	str r0, [r5, #0x30]
	mov r2, r8
	ldr r1, [r2, #4]
_02028860:
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r1, r0
	str r1, [r5]
	b _02028A0C
_0202886A:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x42
	strh r1, [r2]
	b _02028922
_02028876:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r0, #1
	str r0, [r5]
	adds r0, r5, #0
	bl sub_02028A98
	b _02028A0C
_02028886:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4b
	strb r1, [r2]
	b _02028922
_02028892:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x52
	strb r1, [r2]
	b _02028922
_0202889E:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4d
	strb r1, [r2]
	b _02028922
_020288AA:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4f
	strb r1, [r2]
	b _02028922
_020288B6:
	ldr r0, [r5]
	ldrb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x50
	strb r2, [r1]
	b _02028922
_020288C2:
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x51
	strb r1, [r2]
	b _02028922
_020288CE:
	ldr r0, [r5]
	ldrb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x4c
	strb r2, [r1]
	b _02028922
_020288DA:
	adds r0, r5, #0
	bl sub_02028580
	movs r1, #0
	cmp r6, #0xc5
	bne _020288E8
	movs r1, #1
_020288E8:
	adds r0, r5, #0
	adds r0, #0x49
	b _02028A0A
_020288EE:
	adds r1, r5, #0
	adds r1, #0x53
	movs r0, #1
	strb r0, [r1]
	b _02028A0C
_020288F8:
	adds r1, r5, #0
	adds r1, #0x53
	movs r0, #0
	strb r0, [r1]
	b _02028A0C
_02028902:
	ldr r0, _0202891C @ =0x03000274
	ldr r2, [r0]
	cmp r2, #0
	beq _02028920
	ldr r0, [r5]
	ldrb r1, [r0]
	adds r0, #1
	str r0, [r5]
	adds r0, r5, #0
	bl _call_via_r2
	b _02028A0C
	.align 2, 0
_0202891C: .4byte 0x03000274
_02028920:
	ldr r0, [r5]
_02028922:
	adds r0, #1
	str r0, [r5]
	b _02028A0C
_02028928:
	ldr r1, [r5]
	ldrb r0, [r1]
	mov r3, r8
	strh r0, [r3, #0x30]
	b _02028948
_02028932:
	ldr r1, [r5]
	ldrb r0, [r1]
	strh r0, [r5, #0x10]
	b _02028948
_0202893A:
	ldr r1, [r5]
	ldrb r0, [r1]
	str r0, [r5, #0x18]
	b _02028948
_02028942:
	ldr r1, [r5]
	ldrb r0, [r1]
	str r0, [r5, #0x14]
_02028948:
	adds r1, #1
	str r1, [r5]
	b _02028A0C
_0202894E:
	ldr r1, [r5]
	ldrb r4, [r1]
	adds r1, #1
	str r1, [r5]
	mov r2, sp
	ldrb r0, [r1]
	strb r0, [r2]
	adds r2, r1, #1
	str r2, [r5]
	mov r3, sp
	ldrb r0, [r1, #1]
	strb r0, [r3, #1]
	adds r2, #1
	str r2, [r5]
	lsls r4, r4, #2
	mov r0, r8
	adds r0, #8
	adds r6, r0, r4
	ldr r0, [r6]
	cmp r0, #0
	bne _02028982
	bl sub_020284A0
	adds r4, r0, #0
	str r4, [r6]
	b _02028988
_02028982:
	adds r4, r0, #0
	bl sub_020285B0
_02028988:
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	ldr r2, [r1, #4]
	adds r2, r2, r0
	adds r0, r4, #0
	bl sub_020284C4
	ldr r0, [r5, #4]
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x42
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	adds r1, #9
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4c
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x52
	ldrb r0, [r0]
	adds r1, #4
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x4f
	ldrb r0, [r0]
	subs r1, #3
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x50
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x50
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x51
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x51
_02028A0A:
	strb r1, [r0]
_02028A0C:
	ldr r1, [r5, #0x34]
	cmp r1, #0
	bgt _02028A14
	b _02028604
_02028A14:
	mov r2, r8
	ldrh r0, [r2, #0x30]
	subs r0, r1, r0
	str r0, [r5, #0x34]
	movs r3, #0x32
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	str r0, [r5, #0x34]
_02028A24:
	movs r0, #0
_02028A26:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_02028A34
sub_02028A34: @ 0x02028A34
	ldr r2, [r1, #4]
	cmp r2, #0
	bne _02028A4A
	str r0, [r1, #4]
	str r2, [r1, #0x74]
	ldr r2, [r0, #0xc]
	str r2, [r1, #0x78]
	str r1, [r0, #0xc]
	cmp r2, #0
	beq _02028A4A
	str r1, [r2, #0x74]
_02028A4A:
	bx lr

	thumb_func_start sub_02028A4C
sub_02028A4C: @ 0x02028A4C
	adds r3, r0, #0
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _02028A72
	movs r0, #0
	str r0, [r1, #4]
	ldr r2, [r1, #0x78]
	cmp r2, #0
	beq _02028A62
	ldr r0, [r1, #0x74]
	str r0, [r2, #0x74]
_02028A62:
	ldr r2, [r1, #0x74]
	cmp r2, #0
	beq _02028A6E
	ldr r0, [r1, #0x78]
	str r0, [r2, #0x78]
	b _02028A72
_02028A6E:
	ldr r0, [r1, #0x78]
	str r0, [r3, #0xc]
_02028A72:
	bx lr

	thumb_func_start sub_02028A74
sub_02028A74: @ 0x02028A74
	adds r3, r0, #0
	ldr r2, [r3]
	ldrb r1, [r2]
	adds r2, #1
	str r2, [r3]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _02028A94
	movs r0, #0x7f
	ands r1, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r1, r0
	adds r0, r2, #1
	str r0, [r3]
_02028A94:
	adds r0, r1, #0
	bx lr

	thumb_func_start sub_02028A98
sub_02028A98: @ 0x02028A98
	adds r3, r0, #0
	adds r0, #0x40
	movs r2, #0
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldr r0, _02028AC8 @ =0x03000594
	ldr r2, [r0]
	ldr r0, [r3, #8]
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, [r2, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r3, #4]
	bx lr
	.align 2, 0
_02028AC8: .4byte 0x03000594

	thumb_func_start sub_02028ACC
sub_02028ACC: @ 0x02028ACC
	ldr r0, _02028AF0 @ =0x03000584
	ldr r1, _02028AF4 @ =0x03000278
	str r1, [r0]
	ldr r0, _02028AF8 @ =0x03000588
	str r1, [r0]
	ldr r0, _02028AFC @ =0x0300058C
	str r1, [r0]
	ldr r0, _02028B00 @ =0x03000590
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, _02028B04 @ =0x03000270
	movs r1, #0
	str r1, [r0]
	ldr r0, _02028B08 @ =0x03000274
	str r1, [r0]
	bx lr
	.align 2, 0
_02028AF0: .4byte 0x03000584
_02028AF4: .4byte 0x03000278
_02028AF8: .4byte 0x03000588
_02028AFC: .4byte 0x0300058C
_02028B00: .4byte 0x03000590
_02028B04: .4byte 0x03000270
_02028B08: .4byte 0x03000274

	thumb_func_start sub_02028B0C
sub_02028B0C: @ 0x02028B0C
	ldr r3, _02028B1C @ =0x03000584
	ldr r2, [r3]
	ldr r0, _02028B20 @ =0x0300058C
	ldr r0, [r0]
	cmp r2, r0
	bne _02028B24
	movs r0, #0
	b _02028B38
	.align 2, 0
_02028B1C: .4byte 0x03000584
_02028B20: .4byte 0x0300058C
_02028B24:
	adds r0, r2, #0
	adds r0, #0xc
	str r0, [r3]
	ldr r1, _02028B3C @ =0x03000590
	ldr r1, [r1]
	cmp r0, r1
	bne _02028B36
	ldr r0, _02028B40 @ =0x03000278
	str r0, [r3]
_02028B36:
	adds r0, r2, #0
_02028B38:
	bx lr
	.align 2, 0
_02028B3C: .4byte 0x03000590
_02028B40: .4byte 0x03000278

	thumb_func_start sub_02028B44
sub_02028B44: @ 0x02028B44
	ldr r0, _02028B50 @ =0x0300058C
	ldr r1, _02028B54 @ =0x03000588
	ldr r1, [r1]
	str r1, [r0]
	bx lr
	.align 2, 0
_02028B50: .4byte 0x0300058C
_02028B54: .4byte 0x03000588

	thumb_func_start sub_02028B58
sub_02028B58: @ 0x02028B58
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _02028B84 @ =0x03000588
	ldr r2, [r4]
	movs r3, #0
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028B88 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028B7E
	ldr r0, _02028B8C @ =0x03000278
	str r0, [r4]
_02028B7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028B84: .4byte 0x03000588
_02028B88: .4byte 0x03000590
_02028B8C: .4byte 0x03000278

	thumb_func_start sub_02028B90
sub_02028B90: @ 0x02028B90
	push {r4, r5, lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _02028BC0 @ =0x03000588
	ldr r3, [r5]
	movs r4, #1
	strh r4, [r3]
	lsls r0, r0, #0x10
	orrs r0, r1
	str r0, [r3, #4]
	str r2, [r3, #8]
	adds r3, #0xc
	str r3, [r5]
	ldr r0, _02028BC4 @ =0x03000590
	ldr r0, [r0]
	cmp r3, r0
	bne _02028BBA
	ldr r0, _02028BC8 @ =0x03000278
	str r0, [r5]
_02028BBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02028BC0: .4byte 0x03000588
_02028BC4: .4byte 0x03000590
_02028BC8: .4byte 0x03000278

	thumb_func_start sub_02028BCC
sub_02028BCC: @ 0x02028BCC
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _02028BF8 @ =0x03000588
	ldr r2, [r4]
	movs r3, #2
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028BFC @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028BF2
	ldr r0, _02028C00 @ =0x03000278
	str r0, [r4]
_02028BF2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028BF8: .4byte 0x03000588
_02028BFC: .4byte 0x03000590
_02028C00: .4byte 0x03000278

	thumb_func_start sub_02028C04
sub_02028C04: @ 0x02028C04
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _02028C30 @ =0x03000588
	ldr r2, [r4]
	movs r3, #3
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028C34 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028C2A
	ldr r0, _02028C38 @ =0x03000278
	str r0, [r4]
_02028C2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028C30: .4byte 0x03000588
_02028C34: .4byte 0x03000590
_02028C38: .4byte 0x03000278

	thumb_func_start sub_02028C3C
sub_02028C3C: @ 0x02028C3C
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _02028C68 @ =0x03000588
	ldr r2, [r4]
	movs r3, #4
	strh r3, [r2]
	str r0, [r2, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028C6C @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028C62
	ldr r0, _02028C70 @ =0x03000278
	str r0, [r4]
_02028C62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028C68: .4byte 0x03000588
_02028C6C: .4byte 0x03000590
_02028C70: .4byte 0x03000278

	thumb_func_start sub_02028C74
sub_02028C74: @ 0x02028C74
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _02028CA0 @ =0x03000588
	ldr r2, [r4]
	movs r3, #5
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028CA4 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028C9A
	ldr r0, _02028CA8 @ =0x03000278
	str r0, [r4]
_02028C9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028CA0: .4byte 0x03000588
_02028CA4: .4byte 0x03000590
_02028CA8: .4byte 0x03000278

	thumb_func_start sub_02028CAC
sub_02028CAC: @ 0x02028CAC
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _02028CD8 @ =0x03000588
	ldr r2, [r4]
	movs r3, #6
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028CDC @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028CD2
	ldr r0, _02028CE0 @ =0x03000278
	str r0, [r4]
_02028CD2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028CD8: .4byte 0x03000588
_02028CDC: .4byte 0x03000590
_02028CE0: .4byte 0x03000278

	thumb_func_start sub_02028CE4
sub_02028CE4: @ 0x02028CE4
	push {r4, r5, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r5, _02028D10 @ =0x03000588
	ldr r3, [r5]
	movs r4, #7
	strh r4, [r3]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r3, #4]
	str r1, [r3, #8]
	adds r3, #0xc
	str r3, [r5]
	ldr r0, _02028D14 @ =0x03000590
	ldr r0, [r0]
	cmp r3, r0
	bne _02028D0A
	ldr r0, _02028D18 @ =0x03000278
	str r0, [r5]
_02028D0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02028D10: .4byte 0x03000588
_02028D14: .4byte 0x03000590
_02028D18: .4byte 0x03000278

	thumb_func_start sub_02028D1C
sub_02028D1C: @ 0x02028D1C
	push {r4, r5, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r5, _02028D48 @ =0x03000588
	ldr r3, [r5]
	movs r4, #9
	strh r4, [r3]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r3, #4]
	str r1, [r3, #8]
	adds r3, #0xc
	str r3, [r5]
	ldr r0, _02028D4C @ =0x03000590
	ldr r0, [r0]
	cmp r3, r0
	bne _02028D42
	ldr r0, _02028D50 @ =0x03000278
	str r0, [r5]
_02028D42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02028D48: .4byte 0x03000588
_02028D4C: .4byte 0x03000590
_02028D50: .4byte 0x03000278

	thumb_func_start sub_02028D54
sub_02028D54: @ 0x02028D54
	push {r4, r5, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r5, _02028D80 @ =0x03000588
	ldr r3, [r5]
	movs r4, #8
	strh r4, [r3]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r3, #4]
	str r1, [r3, #8]
	adds r3, #0xc
	str r3, [r5]
	ldr r0, _02028D84 @ =0x03000590
	ldr r0, [r0]
	cmp r3, r0
	bne _02028D7A
	ldr r0, _02028D88 @ =0x03000278
	str r0, [r5]
_02028D7A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_02028D80: .4byte 0x03000588
_02028D84: .4byte 0x03000590
_02028D88: .4byte 0x03000278

	thumb_func_start sub_02028D8C
sub_02028D8C: @ 0x02028D8C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _02028DAC @ =0x03000588
	ldr r2, [r3]
	movs r1, #0xa
	strh r1, [r2]
	str r0, [r2, #4]
	adds r2, #0xc
	str r2, [r3]
	ldr r0, _02028DB0 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028DAA
	ldr r0, _02028DB4 @ =0x03000278
	str r0, [r3]
_02028DAA:
	bx lr
	.align 2, 0
_02028DAC: .4byte 0x03000588
_02028DB0: .4byte 0x03000590
_02028DB4: .4byte 0x03000278

	thumb_func_start sub_02028DB8
sub_02028DB8: @ 0x02028DB8
	push {r4, lr}
	ldr r4, _02028DDC @ =0x03000588
	ldr r2, [r4]
	movs r3, #0xb
	strh r3, [r2]
	str r0, [r2, #4]
	str r1, [r2, #8]
	adds r2, #0xc
	str r2, [r4]
	ldr r0, _02028DE0 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028DD6
	ldr r0, _02028DE4 @ =0x03000278
	str r0, [r4]
_02028DD6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_02028DDC: .4byte 0x03000588
_02028DE0: .4byte 0x03000590
_02028DE4: .4byte 0x03000278

	thumb_func_start sub_02028DE8
sub_02028DE8: @ 0x02028DE8
	ldr r3, _02028E04 @ =0x03000588
	ldr r2, [r3]
	movs r1, #0xc
	strh r1, [r2]
	str r0, [r2, #4]
	adds r2, #0xc
	str r2, [r3]
	ldr r0, _02028E08 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028E02
	ldr r0, _02028E0C @ =0x03000278
	str r0, [r3]
_02028E02:
	bx lr
	.align 2, 0
_02028E04: .4byte 0x03000588
_02028E08: .4byte 0x03000590
_02028E0C: .4byte 0x03000278

	thumb_func_start sub_02028E10
sub_02028E10: @ 0x02028E10
	ldr r3, _02028E2C @ =0x03000588
	ldr r2, [r3]
	movs r1, #0xd
	strh r1, [r2]
	str r0, [r2, #4]
	adds r2, #0xc
	str r2, [r3]
	ldr r0, _02028E30 @ =0x03000590
	ldr r0, [r0]
	cmp r2, r0
	bne _02028E2A
	ldr r0, _02028E34 @ =0x03000278
	str r0, [r3]
_02028E2A:
	bx lr
	.align 2, 0
_02028E2C: .4byte 0x03000588
_02028E30: .4byte 0x03000590
_02028E34: .4byte 0x03000278

	thumb_func_start sub_02028E38
sub_02028E38: @ 0x02028E38
	push {r4, lr}
	b _02028FF2
_02028E3C:
	ldrh r0, [r3]
	cmp r0, #0xd
	bls _02028E44
	b _02028FF2
_02028E44:
	lsls r0, r0, #2
	ldr r1, _02028E50 @ =_02028E54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_02028E50: .4byte _02028E54
_02028E54: @ jump table
	.4byte _02028E8C @ case 0
	.4byte _02028E96 @ case 1
	.4byte _02028EAC @ case 2
	.4byte _02028EB6 @ case 3
	.4byte _02028ED4 @ case 4
	.4byte _02028EF4 @ case 5
	.4byte _02028EC0 @ case 6
	.4byte _02028F0C @ case 7
	.4byte _02028F8C @ case 8
	.4byte _02028F4C @ case 9
	.4byte _02028FEC @ case 10
	.4byte _02028FCC @ case 11
	.4byte _02028FD6 @ case 12
	.4byte _02028FE0 @ case 13
_02028E8C:
	ldr r0, [r3, #4]
	ldr r1, [r3, #8]
	bl sub_0202828C
	b _02028FF2
_02028E96:
	ldr r1, [r3, #4]
	lsrs r0, r1, #0x10
	ldr r2, _02028EA8 @ =0x0000FFFF
	ands r1, r2
	ldr r2, [r3, #8]
	bl sub_020282B4
	b _02028FF2
	.align 2, 0
_02028EA8: .4byte 0x0000FFFF
_02028EAC:
	ldr r0, [r3, #4]
	ldr r1, [r3, #8]
	bl sub_02028410
	b _02028FF2
_02028EB6:
	ldr r0, [r3, #4]
	ldrb r1, [r3, #8]
	bl sub_02028448
	b _02028FF2
_02028EC0:
	ldr r2, _02028ED0 @ =0x03001918
	ldr r1, [r3, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x43
	b _02028F00
	.align 2, 0
_02028ED0: .4byte 0x03001918
_02028ED4:
	ldr r2, _02028EF0 @ =0x03001918
	ldr r1, [r3, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r3, #8]
	adds r2, r0, #0
	adds r2, #0x32
	strb r1, [r2]
	lsrs r1, r1, #8
	adds r0, #0x33
	strb r1, [r0]
	b _02028FF2
	.align 2, 0
_02028EF0: .4byte 0x03001918
_02028EF4:
	ldr r2, _02028F08 @ =0x03001918
	ldr r1, [r3, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x40
_02028F00:
	adds r0, r0, r2
	ldr r1, [r3, #8]
	strb r1, [r0]
	b _02028FF2
	.align 2, 0
_02028F08: .4byte 0x03001918
_02028F0C:
	ldrh r1, [r3, #6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02028F48 @ =0x03001918
	adds r1, r0, r1
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _02028FF2
	movs r4, #1
	adds r2, r1, #0
	adds r2, #8
_02028F24:
	ldr r0, [r3, #8]
	ands r0, r4
	cmp r0, #0
	beq _02028F38
	ldr r0, [r2]
	cmp r0, #0
	beq _02028F38
	ldr r1, [r3, #4]
	adds r0, #0x4a
	strb r1, [r0]
_02028F38:
	adds r2, #4
	ldr r0, [r3, #8]
	lsrs r0, r0, #1
	str r0, [r3, #8]
	cmp r0, #0
	bne _02028F24
	b _02028FF2
	.align 2, 0
_02028F48: .4byte 0x03001918
_02028F4C:
	ldrh r1, [r3, #6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02028F88 @ =0x03001918
	adds r1, r0, r1
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _02028FF2
	movs r4, #1
	adds r2, r1, #0
	adds r2, #8
_02028F64:
	ldr r0, [r3, #8]
	ands r0, r4
	cmp r0, #0
	beq _02028F78
	ldr r0, [r2]
	cmp r0, #0
	beq _02028F78
	ldr r1, [r3, #4]
	adds r0, #0x4e
	strb r1, [r0]
_02028F78:
	adds r2, #4
	ldr r0, [r3, #8]
	lsrs r0, r0, #1
	str r0, [r3, #8]
	cmp r0, #0
	bne _02028F64
	b _02028FF2
	.align 2, 0
_02028F88: .4byte 0x03001918
_02028F8C:
	ldrh r1, [r3, #6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _02028FC8 @ =0x03001918
	adds r1, r0, r1
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _02028FF2
	movs r4, #1
	adds r2, r1, #0
	adds r2, #8
_02028FA4:
	ldr r0, [r3, #8]
	ands r0, r4
	cmp r0, #0
	beq _02028FB8
	ldr r0, [r2]
	cmp r0, #0
	beq _02028FB8
	ldr r1, [r3, #4]
	adds r0, #0x4b
	strb r1, [r0]
_02028FB8:
	adds r2, #4
	ldr r0, [r3, #8]
	lsrs r0, r0, #1
	str r0, [r3, #8]
	cmp r0, #0
	bne _02028FA4
	b _02028FF2
	.align 2, 0
_02028FC8: .4byte 0x03001918
_02028FCC:
	ldr r0, [r3, #8]
	ldr r1, [r3, #4]
	bl _call_via_r1
	b _02028FF2
_02028FD6:
	ldr r1, _02028FDC @ =0x03000274
	b _02028FE2
	.align 2, 0
_02028FDC: .4byte 0x03000274
_02028FE0:
	ldr r1, _02028FE8 @ =0x03000270
_02028FE2:
	ldr r0, [r3, #4]
	str r0, [r1]
	b _02028FF2
	.align 2, 0
_02028FE8: .4byte 0x03000270
_02028FEC:
	ldrb r0, [r3, #4]
	bl sub_02027370
_02028FF2:
	bl sub_02028B0C
	adds r3, r0, #0
	cmp r3, #0
	beq _02028FFE
	b _02028E3C
_02028FFE:
	pop {r4}
	pop {r0}
	bx r0

	arm_func_start sub_02029004
sub_02029004: @ 0x02029004
	push {r4, r5}
	mov r4, #0x7f
	mov r5, #0xff00
	orr r5, r5, #0x80
_02029014:
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
	bne _02029014
	pop {r4, r5}
	bx lr

	arm_func_start sub_020290C4
sub_020290C4: @ 0x020290C4
	mov ip, sp
	push {r4, r5, r6, r7, r8, sb}
	ldm ip, {r4, r5, r6, r7}
	sub ip, r3, r1
	and ip, ip, #7
	cmp ip, #0
	bne _020291A4
_020290E0:
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
	blo _020290E0
	mov r0, r4
	pop {r4, r5, r6, r7, r8, sb}
	bx lr
_020291A4:
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
	blo _020291A4
	mov r0, r4
	pop {r4, r5, r6, r7, r8, sb}
	bx lr

	arm_func_start sub_020291E4
sub_020291E4: @ 0x020291E4
	push {r4, r5}
	mov r4, #1
	sub ip, r3, #1
	lsl r4, r4, ip
_020291F4:
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
	blo _020291F4
	pop {r4, r5}
	bx lr

	@ AGB BIOS system-call wrappers from libagbsyscall.
	thumb_func_start ArcTan2
ArcTan2: @ 0x020292E4
	svc #0xa
	bx lr
	thumb_func_end ArcTan2

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x020292E8
	svc #0xc
	bx lr
	thumb_func_end CpuFastSet

	thumb_func_start CpuSet
CpuSet: @ 0x020292EC
	svc #0xb
	bx lr
	thumb_func_end CpuSet

	thumb_func_start ObjAffineSet
ObjAffineSet: @ 0x020292F0
	svc #0xf
	bx lr
	thumb_func_end ObjAffineSet

	thumb_func_start RegisterRamReset
RegisterRamReset: @ 0x020292F4
	svc #1
	bx lr
	thumb_func_end RegisterRamReset

	thumb_func_start SoundBiasReset
SoundBiasReset: @ 0x020292F8
	movs r0, #0
	svc #0x19
	bx lr
	thumb_func_end SoundBiasReset
	.align 2, 0

	thumb_func_start SoundBiasSet
SoundBiasSet: @ 0x02029300
	movs r0, #1
	svc #0x19
	bx lr
	thumb_func_end SoundBiasSet
	.align 2, 0
