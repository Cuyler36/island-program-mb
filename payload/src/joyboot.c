#include "joyboot.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "global.h"

/* Original address: 0x0202AFBC */
extern u32 sJoybootGbaHandshake;
/* Original address: 0x0202AFC4 */
extern u32 sJoybootGameCubeHandshake;

s32 Swap32(u32 *arg0) {
    u8 bytes[4];
    u8* arg0_ptr = (u8*)arg0;

    bytes[0] = arg0_ptr[3];
    bytes[1] = arg0_ptr[2];
    bytes[2] = arg0_ptr[1];
    bytes[3] = arg0_ptr[0];

    return *(s32*)bytes;
}

/* Original address: 0x0201A218 */
void Joybus_Init(void) {
    u16 saved_ime = REG_IME;

    REG_IME = 0;
    REG_RCNT = 0xC000;
    REG_JOYSTAT = 0;
    (void)REG_JOY_RECV;
    REG_JOY_TRANS = 0;
    REG_JOYCNT = 0x47;
    REG_IF = 0x80;
    REG_IF = 0x80;
    REG_IE |= 0x80;
    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
    REG_IME = saved_ime;
}

/* Original address: 0x0201A288 */
void JoybootHandler(void) {
    u32 received;
    u32 joycnt;

    joycnt = REG_JOYCNT;
    if (joycnt & 1) {
        if (!gTransWork.connected) {
            received = REG_JOY_RECV;
            REG_JOY_TRANS = sJoybootGbaHandshake;
            gTransWork.connected = FALSE;
        } else {
            joycnt |= 2;
        }
    }

    if (joycnt & 2) {
        received = REG_JOY_RECV;
        if (gTransWork.connected == TRUE) {
            switch (gTransWork.command) {
            case 0xFFFE0105:
                REG_JOY_TRANS = 0xFFFE0207;
                gTransWork.connected = FALSE;
                gTransWork.command = 0;
                break;
            case 0xFFFE0101:
            case 0xFFFE0102:
            {
                if (gTransWork.word_index > gTransWork.transfer_size / 4) {
                    if (gTransWork.checksum_result != 0) {
                        if (!(REG_JOYSTAT & 8)) {
                            u32 response = 0xFFFE0209;
                            if (gTransWork.checksum_result == 1) {
                                response = 0xFFFE0208;
                            }
                            REG_JOY_TRANS = response;
                            gTransWork.result = gTransWork.checksum_result;
                            gTransWork.connected = FALSE;
                            gTransWork.command = 0;
                        }
                    } else if (received == 0xFFFE0106) {
                        gTransWork.checksum_result = 1;
                    } else {
                        gTransWork.checksum_result = 2;
                    }
                } else if (gTransWork.packet_index >= 0) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        if (gTransWork.word_index == gTransWork.transfer_size / 4) {
                            REG_JOY_TRANS = ~gTransWork.total_checksum;
                            gTransWork.word_index++;
                        } else if ((gTransWork.packet_index & 0xFF) == 0xFF) {
                            REG_JOY_TRANS = ~gTransWork.packet_checksum;
                            gTransWork.packet_checksum = status;
                        } else {
                            u32 word = gTransWork.buffer[gTransWork.word_index];
                            gTransWork.packet_checksum += word;
                            gTransWork.total_checksum += word;
                            REG_JOY_TRANS = word;
                            gTransWork.word_index++;
                        }
                        gTransWork.packet_index++;
                    }
                } else if (gTransWork.enabled == TRUE) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        REG_JOY_TRANS = 0xFFFE0204;
                        gTransWork.packet_index = status;
                    }
                } else {
                    REG_JOY_TRANS = 0xFFFE0205;
                }
                break;
            }
            case 0xFFFE0202:
            {
                if (gTransWork.word_index > gTransWork.transfer_size / 4) {
                    if (!(REG_JOYSTAT & 8)) {
                        if (gTransWork.total_checksum == -1) {
                            REG_JOY_TRANS = 0xFFFE0208;
                            gTransWork.result = 1;
                        } else {
                            REG_JOY_TRANS = 0xFFFE0209;
                            gTransWork.result = 2;
                        }
                        gTransWork.connected = FALSE;
                        gTransWork.command = 0;
                    }
                } else if (gTransWork.packet_index > -1) {
                    s32 swapped = Swap32(&received);
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        if (gTransWork.word_index == gTransWork.transfer_size / 4) {
                            gTransWork.buffer[gTransWork.word_index] = received;
                            gTransWork.total_checksum += swapped;
                            gTransWork.word_index++;
                        } else if ((u8)gTransWork.packet_index == 0xFF) {
                            gTransWork.packet_checksum += swapped;
                            if (gTransWork.packet_checksum != -1) {
                                gTransWork.result = 2;
                            }
                            gTransWork.packet_checksum = status;
                        } else {
                            gTransWork.buffer[gTransWork.word_index] = received;
                            gTransWork.packet_checksum += swapped;
                            gTransWork.total_checksum += swapped;
                            gTransWork.word_index++;
                        }
                        gTransWork.packet_index++;
                    }
                } else if (gTransWork.enabled == TRUE) {
                    u16 status = REG_JOYSTAT & 8;
                    if (status == 0) {
                        REG_JOY_TRANS = 0xFFFE0104;
                        gTransWork.packet_index = status;
                    }
                } else {
                    REG_JOY_TRANS = 0xFFFE0205;
                }
                break;
            }
            default:
                gTransWork.command = received;
                switch (received) {
                case 0xFFFE0101:
                case 0xFFFE0102:
                case 0xFFFE0202:
                    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
                    gTransWork.packet_index = -1;
                    gTransWork.command = received;
                    gTransWork.connected = TRUE;
                    break;
                }
                break;
            }
        } else if (Swap32(&received) == sJoybootGameCubeHandshake) {
            gTransWork.connected = TRUE;
        }
    }

    REG_JOYCNT = joycnt;
    gTransWork.interrupt_count = 0;
}

/* Original address: 0x0201A620 */
void Joybus_Reset(void) {
    u16 saved_ime = REG_IME;

    REG_IME = 0;
    REG_RCNT = 0x8000;
    REG_RCNT = 0xC000;
    REG_JOYSTAT = 0;
    (void)REG_JOY_RECV;
    REG_JOY_TRANS = 0;
    REG_JOYCNT = 0x47;
    REG_IF = 0x80;
    CpuFastFill(0, &gTransWork, sizeof(gTransWork));
    REG_IME = saved_ime;
}

/* Original address: 0x0201A688 */
s32 Joybus_CheckTimeout(u8 reset_on_timeout) {
    s32 timed_out = FALSE;

    if (gTransWork.interrupt_count <= 10U) {
        REG_IME = 0;
        gTransWork.interrupt_count++;
        REG_IME = 1;
    } else {
        if (reset_on_timeout) {
            Joybus_Reset();
        }
        timed_out = TRUE;
    }
    return timed_out;
}
