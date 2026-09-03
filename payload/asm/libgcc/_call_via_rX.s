	.include "../asm/macros/function.inc"
	.text
	.syntax unified

	thumb_func_start _call_via_r0
_call_via_r0: @ 0x02029308
	bx r0
	nop
	thumb_func_end _call_via_r0

	thumb_func_start _call_via_r1
_call_via_r1: @ 0x0202930C
	bx r1
	nop
	thumb_func_end _call_via_r1

	thumb_func_start _call_via_r2
_call_via_r2: @ 0x02029310
	bx r2
	nop
	thumb_func_end _call_via_r2

	thumb_func_start _call_via_r3
_call_via_r3: @ 0x02029314
	bx r3
	nop
	thumb_func_end _call_via_r3

	thumb_func_start _call_via_r4
_call_via_r4: @ 0x02029318
	bx r4
	nop
	thumb_func_end _call_via_r4

	thumb_func_start _call_via_r5
_call_via_r5: @ 0x0202931C
	bx r5
	nop
	thumb_func_end _call_via_r5

	thumb_func_start _call_via_r6
_call_via_r6: @ 0x02029320
	bx r6
	nop
	thumb_func_end _call_via_r6

	thumb_func_start _call_via_r7
_call_via_r7: @ 0x02029324
	bx r7
	nop
	thumb_func_end _call_via_r7

	thumb_func_start _call_via_r8
_call_via_r8: @ 0x02029328
	bx r8
	nop
	thumb_func_end _call_via_r8

	thumb_func_start _call_via_r9
_call_via_r9: @ 0x0202932C
	bx sb
	nop
	thumb_func_end _call_via_r9

	thumb_func_start _call_via_sl
_call_via_sl: @ 0x02029330
	bx sl
	nop
	thumb_func_end _call_via_sl

	thumb_func_start _call_via_fp
_call_via_fp: @ 0x02029334
	bx fp
	nop
	thumb_func_end _call_via_fp

	thumb_func_start _call_via_ip
_call_via_ip: @ 0x02029338
	bx ip
	nop
	thumb_func_end _call_via_ip

	thumb_func_start _call_via_sp
_call_via_sp: @ 0x0202933C
	bx sp
	nop
	thumb_func_end _call_via_sp

	thumb_func_start _call_via_lr
_call_via_lr: @ 0x02029340
	bx lr
	nop
	thumb_func_end _call_via_lr
	.align 2, 0
