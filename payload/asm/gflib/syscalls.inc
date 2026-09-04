	.thumb
	.align 2, 0

	.global ArcTan2
	.type ArcTan2, %function
ArcTan2:
	svc #0xa
	bx lr
	.size ArcTan2, . - ArcTan2

	.global CpuFastSet
	.type CpuFastSet, %function
CpuFastSet:
	svc #0xc
	bx lr
	.size CpuFastSet, . - CpuFastSet

	.global CpuSet
	.type CpuSet, %function
CpuSet:
	svc #0xb
	bx lr
	.size CpuSet, . - CpuSet

	.global ObjAffineSet
	.type ObjAffineSet, %function
ObjAffineSet:
	svc #0xf
	bx lr
	.size ObjAffineSet, . - ObjAffineSet

	.global RegisterRamReset
	.type RegisterRamReset, %function
RegisterRamReset:
	svc #1
	bx lr
	.size RegisterRamReset, . - RegisterRamReset

	.global SoundBiasReset
	.type SoundBiasReset, %function
SoundBiasReset:
	movs r0, #0
	svc #0x19
	bx lr
	.size SoundBiasReset, . - SoundBiasReset
	.align 2, 0

	.global SoundBiasSet
	.type SoundBiasSet, %function
SoundBiasSet:
	movs r0, #1
	svc #0x19
	bx lr
	.size SoundBiasSet, . - SoundBiasSet
	.align 2, 0
