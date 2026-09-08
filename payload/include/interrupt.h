#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

void UnusedInterruptHandler(void);
void VBlankInterruptHandler(void);
void HBlankInterruptHandler(void);
void VCountInterruptHandler(void);

#ifdef __cplusplus
}
#endif

#endif // INTERRUPT_H