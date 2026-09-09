#ifndef LIB_H
#define LIB_H

#include "gba/types.h"
#include "game.h"

#ifdef __cplusplus
extern "C" {
#endif

s16 FixedMul8(s16 lhs, s16 rhs);
s16 FixedDiv8(s16 numerator, s16 denominator);
s32 rand_u16(GameState* state);
void GameState_SeedRandom(GameState* state, u32 seed);
void GameState_SetBrightnessFade(GameState* state, u16 darken, u16 blend_control,
                  u16 intensity);
u16 GameState_StepBrightnessFade(GameState* state, u8 direction, u8 amount);
void GetPaletteColor(u16* palette, u8 x, u8 y, u8* red, u8* green, u8* blue);
void SetPaletteColor(u8 palette, u8 x, u8 y, u8 red, u8 green, u8 blue);
void WaitForVBlank(void);
void ClearOamBuffer(void);
void GameState_ReadKeys(void);
void EnableVBlankInterrupt(void);

extern u8 gSineTable[640];

#ifdef __cplusplus
}
#endif

#endif // LIB_H