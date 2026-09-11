#include "multisio.h"
#include "gba/io_reg.h"
#include "audio.h"
#include "global.h"

/* Original address: 0x0202B3E0 */
static char multi_sio_ver[] = "MultiSio4Sio32Load010918";

/* Word access also includes the adjacent multiplayer send register. */
#define ISLAND_SERIAL_STATUS (*(SioMultiCnt*)REG_ADDR_SIOCNT)
#define ISLAND_LINK_HALFWORDS (int)((sizeof(Island_agb_c) + 1) >> 1)

typedef enum IslandLinkState {
    ISLAND_LINK_STATE_WAITING_FOR_CONNECTION = 0,
    ISLAND_LINK_STATE_DISCOVERING_PEERS = 2,
    ISLAND_LINK_STATE_TRANSFERRING_DATA,
    ISLAND_LINK_STATE_EXCHANGING_RESULTS,
    ISLAND_LINK_STATE_FINISHED,
} IslandLinkState;

typedef enum IslandLinkPeerResult {
    ISLAND_LINK_PEER_RESULT_REJECTED = -1,
    ISLAND_LINK_PEER_RESULT_PENDING = 0,
    ISLAND_LINK_PEER_RESULT_ACCEPTED = 1,
} IslandLinkPeerResult;

typedef enum IslandLinkControlWord {
    ISLAND_LINK_CONTROL_REJECT = 0xFEFC,
    ISLAND_LINK_CONTROL_ACCEPT = 0xFEFD,
    ISLAND_LINK_CONTROL_HANDSHAKE = 0xFEFE,
} IslandLinkControlWord;

enum {
    ISLAND_LINK_PARENT_FLAG = 8,
    ISLAND_LINK_CONNECTION_TIMEOUT = 600,
    ISLAND_LINK_HANDSHAKE_DELAY = 7,
    ISLAND_LINK_PACKET_CHECKSUM_INTERVAL = 32,
    ISLAND_LINK_LAST_PAYLOAD_SLOT = 0x1DAD,
    ISLAND_LINK_TOTAL_CHECKSUM_SLOT = 0x1DAE,
    ISLAND_LINK_TIMER_RELOAD = 0xA4FB,
};

/* Serial island exchange work; sizeof(IslandLinkWork) == 0x38. */
typedef struct IslandLinkWork {
    /* 0x00 */ u8 master;                  /* ISLAND_LINK_PARENT_FLAG for the clock source */
    /* 0x01 */ u8 state;                   /* IslandLinkState */
    /* 0x02 */ u8 connected_players;       /* bitmask of IDs that sent the handshake word */
    /* 0x03 */ u8 checksum_ok;             /* received payload passed its total checksum */
    /* 0x04 */ u8 checksum_bad;            /* received payload failed its total checksum */
    /* 0x05 */ u8 reserved_05[3];
    /* 0x08 */ u16* send_data;              /* local island payload */
    /* 0x0C */ u16* receive_data;           /* remote island payload */
    /* 0x10 */ s32 send_index;              /* next payload halfword to send */
    /* 0x14 */ s32 receive_index;           /* number of payload halfwords received */
    /* 0x18 */ s32 send_packet_index;       /* outgoing slot, including packet checksums */
    /* 0x1C */ s32 receive_packet_index;    /* incoming slot, including packet checksums */
    /* 0x20 */ s32 timeout;                 /* polls since the last state progress */
    /* 0x24 */ u16 received_checksum;       /* remote total-checksum word */
    /* 0x26 */ u16 receive_packet_checksum; /* rolling checksum for one incoming packet */
    /* 0x28 */ u16 send_packet_checksum;    /* rolling checksum for one outgoing packet */
    /* 0x2A */ u16 send_checksum;           /* complement of the local payload sum */
    /* 0x2C */ u16 receive_checksum;        /* sum of received payload halfwords */
    /* 0x2E */ s16 checksum_index;          /* next received halfword to add to the total */
    /* 0x30 */ s8 result;                   /* IslandLinkPeerResult */
    /* 0x31 */ u8 packet_error;             /* an incoming packet checksum failed */
    /* 0x32 */ u8 serial_error;             /* SIOCNT error bit from the latest transfer */
    /* 0x33 */ u8 handshake_delay;          /* delay before advertising local readiness */
    /* 0x34 */ u8 send_handshake;           /* begin sending the handshake control word */
    /* 0x35 */ u8 reserved_35[3];
} IslandLinkWork;

/* Original address: 0x030036D0 */
extern IslandLinkWork gIslandLinkWork;

/**
 * Configures multiplayer SIO and clears the island-transfer state.
 *
 * Packet indices start at -1 so the serial interrupt exchanges handshake
 * words before advancing to payload data. The argument is retained for the
 * original interface but is unused.
 *
 * Original address: 0x0201C7E0
 */
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

/**
 * Disables island-transfer interrupts and returns SIO and timer 3 to idle.
 *
 * Original address: 0x0201C870
 */
void StopIslandLinkTransfer(void) {
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE | SIO_115200_BPS;
    REG_TM3CNT = ISLAND_LINK_TIMER_RELOAD;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

/**
 * Advances the cable-transfer state machine and reports UI-facing progress.
 *
 * This routine discovers the link role, prepares the payload buffers and
 * checksum, monitors interrupt-driven packet transfer, validates the received
 * payload incrementally, and stops the hardware after a terminal result.
 *
 * @return An IslandLinkResult. ISLAND_LINK_RESULT_PENDING means no UI update
 *         is required during this poll.
 *
 * Original address: 0x0201C8C0
 */
IslandLinkResult UpdateIslandLinkTransfer(void) {
    struct SioMultiCnt serial;
    IslandLinkResult result;

    serial = ISLAND_SERIAL_STATUS;
    result = ISLAND_LINK_RESULT_PENDING;
    switch (gIslandLinkWork.state) {
    case ISLAND_LINK_STATE_WAITING_FOR_CONNECTION:
        if (gIslandLinkWork.timeout > ISLAND_LINK_CONNECTION_TIMEOUT) {
            if (!serial.sd || serial.enable) {
                result = ISLAND_LINK_RESULT_CONNECTION_ERROR;
            } else {
                result = ISLAND_LINK_RESULT_PEER_NOT_RESPONDING;
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
                REG_TM3CNT = ISLAND_LINK_TIMER_RELOAD;
                gIslandLinkWork.master = ISLAND_LINK_PARENT_FLAG;
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
            gIslandLinkWork.state = ISLAND_LINK_STATE_DISCOVERING_PEERS;
        }
        break;
    case ISLAND_LINK_STATE_DISCOVERING_PEERS:
        if (gIslandLinkWork.serial_error != 0) {
            result = ISLAND_LINK_RESULT_CONNECTION_ERROR;
        } else if ((gIslandLinkWork.connected_players & 1) && (gIslandLinkWork.connected_players & 0xE)) {
            if (serial.id > 1) {
                result = ISLAND_LINK_RESULT_CONNECTION_ERROR;
            } else {
                result = ISLAND_LINK_RESULT_IN_PROGRESS;
                gIslandLinkWork.timeout = 0;
                gIslandLinkWork.state = ISLAND_LINK_STATE_TRANSFERRING_DATA;
                GameAudio_PlayEffect2(0x29);
            }
        } else if (gIslandLinkWork.timeout > ISLAND_LINK_CONNECTION_TIMEOUT) {
            result = ISLAND_LINK_RESULT_PEER_NOT_RESPONDING;
        } else if (!((gIslandLinkWork.connected_players >> serial.id) & 1)) {
            if (gIslandLinkWork.handshake_delay <= ISLAND_LINK_HANDSHAKE_DELAY) {
                gIslandLinkWork.handshake_delay++;
            } else {
                gIslandLinkWork.send_handshake = 1;
            }
        } else {
            gIslandLinkWork.handshake_delay = 0;
        }
        break;
    case ISLAND_LINK_STATE_TRANSFERRING_DATA: {
        s32 received = gIslandLinkWork.receive_index;
        s32 count = received;

        if (gIslandLinkWork.serial_error != 0 || gIslandLinkWork.timeout > 1 || gIslandLinkWork.packet_error != 0) {
            result = ISLAND_LINK_RESULT_CANCELED;
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
                gIslandLinkWork.state = ISLAND_LINK_STATE_EXCHANGING_RESULTS;
            }
        }
        break;
    }
    case ISLAND_LINK_STATE_EXCHANGING_RESULTS:
        if (gIslandLinkWork.result == ISLAND_LINK_PEER_RESULT_ACCEPTED) {
            result = ISLAND_LINK_RESULT_SUCCESS;
        } else if (gIslandLinkWork.result == ISLAND_LINK_PEER_RESULT_REJECTED ||
                   gIslandLinkWork.serial_error != 0 ||
                   gIslandLinkWork.timeout > 6) {
            result = ISLAND_LINK_RESULT_CANCELED;
        }
        if (result != ISLAND_LINK_RESULT_PENDING) {
            gIslandLinkWork.state = ISLAND_LINK_STATE_FINISHED;
        }
        break;
    }
    gIslandLinkWork.timeout++;
    if (result != ISLAND_LINK_RESULT_PENDING && result != ISLAND_LINK_RESULT_IN_PROGRESS) {
        u16 sound;

        GameAudio_StopEffect2(0x29);
        if (result == ISLAND_LINK_RESULT_SUCCESS) {
            sound = 0x27;
        } else {
            sound = 0x28;
        }
        GameAudio_PlayEffect0(sound);
        StopIslandLinkTransfer();
    }
    return result;
}

/**
 * Services one completed multiplayer-SIO exchange.
 *
 * The interrupt first discovers participating systems, then transfers island
 * data with a checksum word in every 32nd link slot. After the payload it
 * exchanges a total checksum and an accept/reject control word. The parent
 * system also restarts each transfer using timer 3.
 *
 * Original address: 0x0201CB50
 */
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
            if (received[player] == ISLAND_LINK_CONTROL_HANDSHAKE) {
                gIslandLinkWork.connected_players |= 1 << player;
            }
        }
        if ((gIslandLinkWork.connected_players & 3) == 3) {
            gIslandLinkWork.send_packet_index++;
            gIslandLinkWork.receive_packet_index++;
            gIslandLinkWork.send_packet_checksum = 0;
            gIslandLinkWork.receive_packet_checksum = 0;
        }
    } else if (gIslandLinkWork.receive_packet_index <= ISLAND_LINK_LAST_PAYLOAD_SLOT) {
        gIslandLinkWork.receive_packet_checksum += received[serial.id ^ 1];
        if ((gIslandLinkWork.receive_packet_index &
             (ISLAND_LINK_PACKET_CHECKSUM_INTERVAL - 1)) ==
            (ISLAND_LINK_PACKET_CHECKSUM_INTERVAL - 1)) {
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
    } else if (gIslandLinkWork.receive_packet_index == ISLAND_LINK_TOTAL_CHECKSUM_SLOT) {
        gIslandLinkWork.received_checksum = received[1 ^ serial.id];
        gIslandLinkWork.receive_packet_index = gIslandLinkWork.receive_packet_index + 1;
        gIslandLinkWork.receive_index++;
    } else {
        if (received[0] >= ISLAND_LINK_CONTROL_REJECT && received[0] <= ISLAND_LINK_CONTROL_ACCEPT) {
            if (received[1] >= ISLAND_LINK_CONTROL_REJECT && received[1] <= ISLAND_LINK_CONTROL_ACCEPT) {
                if (received[0] == ISLAND_LINK_CONTROL_ACCEPT && received[1] == received[0]) {
                    gIslandLinkWork.result = ISLAND_LINK_PEER_RESULT_ACCEPTED;
                } else {
                    gIslandLinkWork.result = ISLAND_LINK_PEER_RESULT_REJECTED;
                }
            }
        }
    }
    if (gIslandLinkWork.send_packet_index < 0) {
        if (gIslandLinkWork.send_handshake) {
            ISLAND_SERIAL_STATUS.data = ISLAND_LINK_CONTROL_HANDSHAKE;
        }
        gIslandLinkWork.send_packet_checksum = 0;
    } else if (gIslandLinkWork.send_packet_index <= ISLAND_LINK_LAST_PAYLOAD_SLOT) {
        if ((gIslandLinkWork.send_packet_index &
             (ISLAND_LINK_PACKET_CHECKSUM_INTERVAL - 1)) ==
            (ISLAND_LINK_PACKET_CHECKSUM_INTERVAL - 1)) {
            ISLAND_SERIAL_STATUS.data = ~gIslandLinkWork.send_packet_checksum;
            gIslandLinkWork.send_packet_checksum = 0;
        } else {
            ISLAND_SERIAL_STATUS.data = gIslandLinkWork.send_data[gIslandLinkWork.send_index];
            gIslandLinkWork.send_packet_checksum += gIslandLinkWork.send_data[gIslandLinkWork.send_index];
            gIslandLinkWork.send_index++;
        }
        gIslandLinkWork.send_packet_index++;
    } else if (gIslandLinkWork.send_packet_index == ISLAND_LINK_TOTAL_CHECKSUM_SLOT) {
        ISLAND_SERIAL_STATUS.data = gIslandLinkWork.send_checksum;
        gIslandLinkWork.send_packet_index++;
    } else if (gIslandLinkWork.send_packet_index > ISLAND_LINK_TOTAL_CHECKSUM_SLOT &&
               (gIslandLinkWork.checksum_ok || gIslandLinkWork.checksum_bad)) {
        ISLAND_SERIAL_STATUS.data = gIslandLinkWork.checksum_ok
                                        ? ISLAND_LINK_CONTROL_ACCEPT
                                        : ISLAND_LINK_CONTROL_REJECT;
    }
    if (gIslandLinkWork.master == ISLAND_LINK_PARENT_FLAG) {
        REG_TM3CNT_H = 0;
        REG_SIOCNT |= SIO_ENABLE;
        REG_TM3CNT_H = 0xC0;
    }
}
