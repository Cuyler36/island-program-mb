#ifndef GUARD_M2C_H
#define GUARD_M2C_H

/* Temporary types and accessors used by initial m2c reconstructions. */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define M2C_ERROR(description) (0)
#define ROTATE_RIGHT(value, shift) \
    (((u32)(value) >> (shift)) | ((u32)(value) << (32 - (shift))))

typedef struct m2c_dma {
    volatile u32 src;
    volatile u32 dest;
    volatile u32 control;
} m2c_dma;

typedef struct m2c_irq {
    volatile u16 enable;
    volatile u16 request;
} m2c_irq;

#define REG_DMA3 (*(volatile m2c_dma *)0x040000D4)
#define REG_IRQ (*(volatile m2c_irq *)0x04000200)

extern u32 gIntrTable[];
void _start(void);

/* Register-call veneers. Their effective signatures depend on the caller. */
void _call_via_r0();
void _call_via_r1();
void _call_via_r2();
void _call_via_r3();
void _call_via_r4();
void _call_via_r5();
void _call_via_r6();
void _call_via_r7();
void _call_via_r8();
void _call_via_r9();
void _call_via_sl();
void _call_via_fp();
void _call_via_ip();
void _call_via_sp();
void _call_via_lr();

#endif
