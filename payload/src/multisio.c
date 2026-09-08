#include "multisio.h"
#include "gba/io_reg.h"
#include "audio.h"
#include "global.h"

/* Word access also includes the adjacent multiplayer send register. */
#define ISLAND_SERIAL_STATUS (*(SioMultiCnt*)REG_ADDR_SIOCNT)
#define ISLAND_LINK_HALFWORDS (int)((sizeof(Island_agb_c) + 1) >> 1)

/* Serial island exchange work; sizeof(IslandLinkWork) == 0x38. */
typedef struct IslandLinkWork {
    /* 0x00 */ u8 master;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 connected_players;
    /* 0x03 */ u8 checksum_ok;
    /* 0x04 */ u8 checksum_bad;
    /* 0x05 */ u8 _05[3];
    /* 0x08 */ u16* send_data;
    /* 0x0C */ u16* receive_data;
    /* 0x10 */ s32 send_index;
    /* 0x14 */ s32 receive_index;
    /* 0x18 */ s32 send_packet_index;
    /* 0x1C */ s32 receive_packet_index;
    /* 0x20 */ s32 timeout;
    /* 0x24 */ u16 received_checksum;
    /* 0x26 */ u16 receive_packet_checksum;
    /* 0x28 */ u16 send_packet_checksum;
    /* 0x2A */ u16 send_checksum;
    /* 0x2C */ u16 receive_checksum;
    /* 0x2E */ s16 checksum_index;
    /* 0x30 */ s8 result;
    /* 0x31 */ u8 packet_error;
    /* 0x32 */ u8 serial_error;
    /* 0x33 */ u8 handshake_delay;
    /* 0x34 */ u8 send_handshake;
    /* 0x35 */ u8 _35[3];
} IslandLinkWork;

/* Original address: 0x030036D0 */
extern IslandLinkWork gIslandLinkWork;

/* Original address: 0x0201C7E0 */
void InitIslandLinkTransfer(s32 unused) {
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    *(vu32 *)REG_ADDR_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_115200_BPS | SIO_INTR_ENABLE;
    CpuFill32(0, &gIslandLinkWork, sizeof(gIslandLinkWork));
    gIslandLinkWork.send_packet_index = -1;
    gIslandLinkWork.receive_packet_index = -1;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;
}

/* Original address: 0x0201C870 */
void StopIslandLinkTransfer(void) {
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE | SIO_115200_BPS;
    REG_TM3CNT = (0xA4 << 8) | 0xFB; // Did they mean ~0xFB?
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

/* Original address: 0x0201C8C0 */
s32 UpdateIslandLinkTransfer(void) {
    struct SioMultiCnt serial;
    s32 result;

    serial = ISLAND_SERIAL_STATUS;
    result = -1;
    switch (gIslandLinkWork.state) {
    case 0:
        if (gIslandLinkWork.timeout > 600) {
            if (!serial.sd || serial.enable) {
                result = 8;
            } else {
                result = 16;
            }
        } else if (serial.sd && !serial.enable) {
            u16* data;
            s32 remaining;
            u16 checksum;

            if (serial.si == 0) {
                REG_IME = 0;
                REG_IE &= ~INTR_FLAG_SERIAL;
                REG_IE |= INTR_FLAG_TIMER3;
                REG_IME = 1;
                ISLAND_SERIAL_STATUS.intrEnable = 0;
                REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
                REG_TM3CNT = (0xA4 << 8) | 0xFB; // Did they mean ~0xFB?
                gIslandLinkWork.master = 8;
                ISLAND_SERIAL_STATUS.enable = 1;
            }
            data = (u16*)gIslandData;
            gIslandLinkWork.send_data = data;
            gIslandLinkWork.receive_data = (u16*)gIslandTransferData;
            checksum = 0;
            remaining = ISLAND_LINK_HALFWORDS;
            do {
                checksum += *data++;
            } while (--remaining != 0);
            gIslandLinkWork.send_checksum = ~checksum;
            if (gIslandLinkWork.master != 0) {
                REG_TM3CNT_H = 0xC0;
            }
            gIslandLinkWork.timeout = 0;
            gIslandLinkWork.state = 2;
        }
        break;
    case 2:
        if (gIslandLinkWork.serial_error != 0) {
            result = 8;
        } else if ((gIslandLinkWork.connected_players & 1) && (gIslandLinkWork.connected_players & 0xE)) {
            if (serial.id > 1) {
                result = 8;
            } else {
                result = 7;
                gIslandLinkWork.timeout = 0;
                gIslandLinkWork.state = 3;
                GameAudio_PlayEffect2(0x29);
            }
        } else if (gIslandLinkWork.timeout > 600) {
            result = 16;
        } else if (!((gIslandLinkWork.connected_players >> serial.id) & 1)) {
            if (gIslandLinkWork.handshake_delay <= 7) {
                gIslandLinkWork.handshake_delay++;
            } else {
                gIslandLinkWork.send_handshake = 1;
            }
        } else {
            gIslandLinkWork.handshake_delay = 0;
        }
        break;
    case 3: {
        s32 received = gIslandLinkWork.receive_index;
        s32 count = received;

        if (gIslandLinkWork.serial_error != 0 || gIslandLinkWork.timeout > 1 || gIslandLinkWork.packet_error != 0) {
            result = 10;
        } else {
            if (received > ISLAND_LINK_HALFWORDS) {
                count = ISLAND_LINK_HALFWORDS;
            } else if (received < 0) {
                count = 0;
            }
            if (gIslandLinkWork.checksum_index < count) {
                IslandLinkWork* work = &gIslandLinkWork;

                do {
                    work->receive_checksum += work->receive_data[work->checksum_index++];
                } while (work->checksum_index < count);
                work->timeout = 0;
            }
            if (received > ISLAND_LINK_HALFWORDS) {
                if ((s16)(gIslandLinkWork.received_checksum + gIslandLinkWork.receive_checksum) == -1) {
                    gIslandLinkWork.checksum_ok = 1;
                } else {
                    gIslandLinkWork.checksum_bad = 1;
                }
                gIslandLinkWork.timeout = 0;
                gIslandLinkWork.state = 4;
            }
        }
        break;
    }
    case 4:
        if (gIslandLinkWork.result == 1) {
            result = 9;
        } else if (gIslandLinkWork.result == -1 || gIslandLinkWork.serial_error != 0 || gIslandLinkWork.timeout > 6) {
            result = 10;
        }
        if (result != -1) {
            gIslandLinkWork.state = 5;
        }
        break;
    }
    gIslandLinkWork.timeout++;
    if (result != -1 && result != 7) {
        u16 sound;

        GameAudio_StopEffect2(0x29);
        if (result == 9) {
            sound = 0x27;
        } else {
            sound = 0x28;
        }
        GameAudio_PlayEffect0(sound);
        StopIslandLinkTransfer();
    }
    return result;
}

/* Original address: 0x0201CB50 */
void IslandLinkSerialInterrupt(void) {
    u16 received[4];
    IslandLinkWork *work;
    struct SioMultiCnt serial;
    s32 player;
    u16 *data;

    *(u64*)received = REG_SIOMLT_RECV;
    work = &gIslandLinkWork;
    serial = ISLAND_SERIAL_STATUS;
    work->serial_error = serial.error;
    if (gIslandLinkWork.receive_packet_index < 0) {
        for (player = 0; player < 4; player++) {
            if (received[player] == 0xFEFE) {
                gIslandLinkWork.connected_players |= 1 << player;
            }
        }
        if ((gIslandLinkWork.connected_players & 3) == 3) {
            gIslandLinkWork.send_packet_index++;
            gIslandLinkWork.receive_packet_index++;
            gIslandLinkWork.send_packet_checksum = 0;
            gIslandLinkWork.receive_packet_checksum = 0;
        }
    } else if (gIslandLinkWork.receive_packet_index <= 0x1DAD) {
        gIslandLinkWork.receive_packet_checksum += received[serial.id ^ 1];
        if ((gIslandLinkWork.receive_packet_index & 31) == 31) {
            if ((s16)gIslandLinkWork.receive_packet_checksum != -1) {
                gIslandLinkWork.packet_error |= 1;
            }
            gIslandLinkWork.receive_packet_checksum = 0;
        } else {
            if (gIslandLinkWork.receive_index < ISLAND_LINK_HALFWORDS) {
                gIslandLinkWork.receive_data[gIslandLinkWork.receive_index] = received[serial.id ^ 1];
                gIslandLinkWork.receive_index++;
            }
        }
        gIslandLinkWork.receive_packet_index++;
    } else if (gIslandLinkWork.receive_packet_index == 0x1DAE) {
        gIslandLinkWork.received_checksum = received[1 ^ serial.id];
        gIslandLinkWork.receive_packet_index = gIslandLinkWork.receive_packet_index + 1;
        gIslandLinkWork.receive_index++;
    } else {
        if (received[0] >= 0xFEFC && received[0] <= 0xFEFD) {
            if (received[1] >= 0xFEFC && received[1] <= 0xFEFD) {
                if (received[0] == 0xFEFD && received[1] == received[0]) {
                    gIslandLinkWork.result = 1;
                } else {
                    gIslandLinkWork.result = -1;
                }
            }
        }
    }
    if (gIslandLinkWork.send_packet_index < 0) {
        if (gIslandLinkWork.send_handshake) {
            ISLAND_SERIAL_STATUS.data = 0xFEFE;
        }
        gIslandLinkWork.send_packet_checksum = 0;
    } else if (gIslandLinkWork.send_packet_index <= 0x1DAD) {
        if ((gIslandLinkWork.send_packet_index & 31) == 31) {
            ISLAND_SERIAL_STATUS.data = ~gIslandLinkWork.send_packet_checksum;
            gIslandLinkWork.send_packet_checksum = 0;
        } else {
            ISLAND_SERIAL_STATUS.data = gIslandLinkWork.send_data[gIslandLinkWork.send_index];
            gIslandLinkWork.send_packet_checksum += gIslandLinkWork.send_data[gIslandLinkWork.send_index];
            gIslandLinkWork.send_index++;
        }
        gIslandLinkWork.send_packet_index++;
    } else if (gIslandLinkWork.send_packet_index == 0x1DAE) {
        ISLAND_SERIAL_STATUS.data = gIslandLinkWork.send_checksum;
        gIslandLinkWork.send_packet_index++;
    } else if (gIslandLinkWork.send_packet_index > 0x1DAE && (gIslandLinkWork.checksum_ok || gIslandLinkWork.checksum_bad)) {
        ISLAND_SERIAL_STATUS.data = (gIslandLinkWork.checksum_ok) ? 0xFEFD : 0xFEFC;
    }
    if (gIslandLinkWork.master == 8) {
        REG_TM3CNT_H = 0;
        REG_SIOCNT |= SIO_ENABLE;
        REG_TM3CNT_H = 0xC0;
    }
}
