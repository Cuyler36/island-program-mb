#ifndef MULTISIO_H
#define MULTISIO_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SioMultiCnt SioMultiCnt;

// Multi-player SIO Control Structure
struct SioMultiCnt
{
    u16 baudRate:2;    // baud rate
    u16 si:1;          // SI terminal
    u16 sd:1;          // SD terminal
    u16 id:2;          // ID
    u16 error:1;       // error flag
    u16 enable:1;      // SIO enable
    u16 unused_11_8:4;
    u16 mode:2;        // communication mode (should equal 2)
    u16 intrEnable:1;  // IRQ enable
    u16 unused_15:1;
    u16 data;          // data
};

#define ST_SIO_MULTI_MODE 2 // Multi-player communication mode

// baud rate
#define ST_SIO_9600_BPS   0 //   9600 bps
#define ST_SIO_38400_BPS  1 //  38400 bps
#define ST_SIO_57600_BPS  2 //  57600 bps
#define ST_SIO_115200_BPS 3 // 115200 bps

void InitIslandLinkTransfer(s32 arg0);
void StopIslandLinkTransfer(void);
s32 UpdateIslandLinkTransfer(void);
void IslandLinkSerialInterrupt(void);

#ifdef __cplusplus
}
#endif

#endif // MULTISIO_H