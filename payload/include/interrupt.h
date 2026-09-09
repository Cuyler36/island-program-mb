#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*INTERRUPT_HANDLER_PROC)(void);

void UnusedInterruptHandler(void);
void VBlankInterruptHandler(void);
void HBlankInterruptHandler(void);
void VCountInterruptHandler(void);

/* Original address: 0x02029698 */
extern INTERRUPT_HANDLER_PROC sInitialIntrTable[14];

#ifdef __cplusplus
}
#endif

#endif // INTERRUPT_H