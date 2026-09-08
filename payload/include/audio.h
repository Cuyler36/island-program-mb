#ifndef AUDIO_H
#define AUDIO_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void GameAudio_VBlank(void);
void GameAudio_Init(void);
void GameAudio_UpdateDriver(void);
void GameAudio_Update(void);
void GameAudio_PlayEffect2(u16 value);
void GameAudio_StopEffect2(u16 value);
void GameAudio_PlayEffect0(u16 value);
void GameAudio_PlayMusic(u16 value);
void GameAudio_StopMusic(u16 value);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_H