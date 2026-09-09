#ifndef FALLING_FRUIT_H
#define FALLING_FRUIT_H

#include "gba/types.h"
#include "global.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sizeof(FallingFruit) == 0x2C. */
typedef struct FallingFruit {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 height;
    /* 0x0C */ s32 landing_y;
    /* 0x10 */ s32 landing_x;
    /* 0x14 */ s32 origin_y;
    /* 0x18 */ s32 velocity_y;
    /* 0x1C */ s32 gravity;
    /* 0x20 */ u16 tile_idx;
    /* 0x22 */ u8 state;
    /* 0x23 */ u8 type;
    /* 0x24 */ u8 anim_frame;
    /* 0x25 */ u8 acre;
    /* 0x26 */ u8 timer;
    /* 0x27 */ u8 sound_played;
    /* 0x28 */ u8 can_land;
    /* 0x29 */ u8 pad_29[3];
} FallingFruit;

/* Original address: 0x03004260 */
extern FallingFruit gFallingFruit[30];
/* sizeof(FallingFruitProfile) == 0x18. */
typedef struct FallingFruitProfile {
    /* 0x00 */ u32 oam_attributes;
    /* 0x04 */ s32 y_offset;
    /* 0x08 */ s32 x_offset;
    /* 0x0C */ u16 sprite_tile;
    /* 0x0E */ u16 ground_tile;
    /* 0x10 */ mActor_name_t item;
    /* 0x12 */ u8 palette;
    /* 0x13 */ u8 h_flip;
    /* 0x14 */ u8 field_tile;
    /* 0x15 */ u8 pad_15[3];
} FallingFruitProfile;

void FallingFruit_Init(s32 fruit_index, u16 arg1, u8 arg2, u8 arg3);
void sub_02024C00(s32 fruit_index);
void sub_02024C04(s32 fruit_index);
void FallingFruit_BeginFall(s32 fruit_index);
void FallingFruit_UpdateFall(s32 fruit_index);
void FallingFruit_Update(s32 fruit_index);
void FallingFruit_Draw(s32 fruit_index);

#ifdef __cplusplus
}
#endif

#endif // FALLING_FRUIT_H