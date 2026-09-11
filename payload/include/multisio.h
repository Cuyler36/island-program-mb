#ifndef MULTISIO_H
#define MULTISIO_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SioMultiCnt SioMultiCnt;

/* Multiplayer SIO control and send-data registers viewed as one word. */
struct SioMultiCnt
{
    u16 baudRate:2;    /* transfer rate */
    u16 si:1;          /* SI terminal level */
    u16 sd:1;          /* SD terminal level */
    u16 id:2;          /* local multiplayer ID (0-3) */
    u16 error:1;       /* transfer error */
    u16 enable:1;      /* transfer start/busy */
    u16 unused_11_8:4;
    u16 mode:2;        /* communication mode; 2 selects multiplayer */
    u16 intrEnable:1;  /* serial IRQ enable */
    u16 unused_15:1;
    u16 data;          /* outgoing multiplayer halfword */
};

#define ST_SIO_MULTI_MODE 2 // Multi-player communication mode

// baud rate
#define ST_SIO_9600_BPS   0 //   9600 bps
#define ST_SIO_38400_BPS  1 //  38400 bps
#define ST_SIO_57600_BPS  2 //  57600 bps
#define ST_SIO_115200_BPS 3 // 115200 bps

/* Values returned while polling an island-data cable transfer. */
typedef enum IslandLinkResult {
    ISLAND_LINK_RESULT_PENDING = -1,
    ISLAND_LINK_RESULT_IN_PROGRESS = 7,
    ISLAND_LINK_RESULT_CONNECTION_ERROR = 8,
    ISLAND_LINK_RESULT_SUCCESS = 9,
    ISLAND_LINK_RESULT_CANCELED = 10,
    ISLAND_LINK_RESULT_PEER_NOT_RESPONDING = 16,
} IslandLinkResult;

void InitIslandLinkTransfer(s32 arg0);
void StopIslandLinkTransfer(void);
IslandLinkResult UpdateIslandLinkTransfer(void);
void IslandLinkSerialInterrupt(void);

#ifdef __cplusplus
}
#endif

#endif // MULTISIO_H
