#ifndef JOYBOOT_H
#define JOYBOOT_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Joy Bus transfer state used by JoybootHandler. */
/* sizeof(JoybusTransferWork) == 0x40 */
typedef struct JoybusTransferWork {
    /* 0x00 */ u32* buffer;
    /* 0x04 */ s32 word_index;
    /* 0x08 */ s32 transfer_size;
    /* 0x0C */ s32 packet_index;
    /* 0x10 */ u8 _10[8];
    /* 0x18 */ u32 command;
    /* 0x1C */ u32 packet_checksum;
    /* 0x20 */ u32 total_checksum;
    /* 0x24 */ s8 checksum_result;
    /* 0x25 */ s8 result;
    /* 0x26 */ u8 enabled;
    /* 0x27 */ u8 _27[2];
    /* 0x29 */ u8 connected;
    /* 0x2A */ u8 interrupt_count;
    /* 0x2B */ u8 _2B[0x15];
} JoybusTransferWork;

void Joybus_Init(void);
void JoybootHandler(void);
void Joybus_Reset(void);
s32 Joybus_CheckTimeout(u8 arg0);

/* Original address: 0x03003120 */
extern JoybusTransferWork gTransmissionBuf_p;

#define gTransWork gTransmissionBuf_p

#ifdef __cplusplus
}
#endif

#endif // JOYBOOT_H