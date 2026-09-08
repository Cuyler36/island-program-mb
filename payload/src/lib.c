#include "lib.h"
#include "global.h"

/* Original address: 0x02019ABC */
s16 FixedMul8(s16 lhs, s16 rhs) {
    return (lhs * rhs) / 256;
}

/* Original address: 0x02019AD8 */
s16 FixedDiv8(s16 numerator, s16 denominator) {
    return (numerator * 256) / denominator;
}

s32 rand_u16(GameState *state) {
    u32 m = state->rng_state * 0x41C64E6D;
    u32 a = state->vblank_counter + 0x3039;
    state->rng_state = m + a;
    return (s32)((u32)(state->rng_state << 1) >> 0x11);
}

/* Original address: 0x02019B18 */
void GameState_SeedRandom(GameState *state, u32 seed) {
    state->rng_state = seed;
}

/* Original address: 0x02019B1C */
void GameState_SetBrightnessFade(GameState *state, u16 darken, u16 blend_control, u16 intensity) {
    if (darken == 1) {
        state->bldcnt = blend_control | 0xC0;
    } else {
        state->bldcnt = blend_control | 0x80;
    }
    if (intensity > 16) {
        intensity = 16;
    }
    state->bldy = intensity;
}

/* Original address: 0x02019B58 */
u16 GameState_StepBrightnessFade(GameState *state, u8 direction, u8 amount) {
    u16 intensity = state->bldy;

    if (direction == 1) {
        intensity += amount;
        if ((s16)intensity > 16) {
            intensity = 16;
        }
    } else if (direction == 0) {
        intensity -= amount;
        if ((s16)intensity < 0) {
            intensity = 0;
        }
    }
    state->bldy = intensity;
    return state->bldy;
}

/* Original address: 0x02019BA8 */
void GetPaletteColor(u16 *palette, u8 x, u8 y, u8 *red, u8 *green, u8 *blue) {
    u16 temp_r1_3514;

    temp_r1_3514 = palette[((0xF & x) * 0x10) + (y & 0xF)];
    *blue = (temp_r1_3514 >> 0xA) & 0x1F;
    *green = (temp_r1_3514 >> 5) & 0x1F;
    *red = temp_r1_3514 & 0x1F;
}

/* Original address: 0x02019BD8 */
void SetPaletteColor(u8 palette, u8 bank, u8 color, u8 red, u8 green, u8 blue) {
    u16 *buffer;
    u16 packed_color;

    if (palette == 1) {
        buffer = gObjPaletteBuffer;
        // buffer = (u16*)0x02000200;
    } else {
        buffer = gBgPaletteBuffer;
        // buffer = (u16*)0x02000000;
    }
    packed_color = RGB(red, green, blue);
    buffer[(bank & 0xF) * 16 + (color & 0xF)] = packed_color;
    gGameState.palette_dirty = 1;
}

/* Original address: 0x02019C3C */
void WaitForVBlank(void) {
    gGameState.vblank_flags &= ~1;
    while (!(gGameState.vblank_flags & 1)) {
    }
    gGameState.vblank_flags &= ~1;
}

/* Original address: 0x0202AFB4 */
extern const OAMData sHiddenOamAttributes;

/* Original address: 0x02019C88 */
void ClearOamBuffer(void) {
    OAMData *oam = (OAMData *)gUnk3002410;
    OAMData *end = (OAMData *)(gUnk3002410 + sizeof(gUnk3002410));

    while (oam < end) {
        *oam++ = sHiddenOamAttributes;
    }
    gGameState.oam_count = 0;
}

/* Original address: 0x02019CC0 */
void GameState_ReadKeys(void) {
    u16 temp_r2_3660;

    temp_r2_3660 = 0x3FF ^ REG_KEYINPUT;
    gGameState.keys.buttons.pressed = temp_r2_3660 & ~gGameState.keys.buttons.held;
    gGameState.keys.buttons.held = temp_r2_3660;
}

/* Original address: 0x02019CFC */
void EnableVBlankInterrupt(void) {
    REG_IME = 0;
    REG_DISPCNT = 0x80;
    REG_DISPSTAT = 8;
    REG_IE = 1;
    REG_IF = 1;
    REG_IME = 1;
}
