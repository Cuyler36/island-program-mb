#ifndef ANIM_H
#define ANIM_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* OAM layout used by the islander animation data. */
typedef struct oam_data_s {
    /* 0x00 */ u32 y : 8;
    /* 0x01 */ u32 affine_mode : 2;
    /* 0x01 */ u32 obj_mode : 2;
    /* 0x01 */ u32 mosaic : 1;
    /* 0x01 */ u32 bpp : 1;
    /* 0x01 */ u32 shape : 2;
    /* 0x02 */ u32 x : 9;
    /* 0x03 */ u32 matrix_num : 3;
    /* 0x03 */ u32 h_flip : 1;
    /* 0x03 */ u32 v_flip : 1;
    /* 0x03 */ u32 size : 2;
    /* 0x04 */ u16 tile_num : 10;
    /* 0x05 */ u16 priority : 2;
    /* 0x05 */ u16 palette_num : 4;
    /* 0x06 */ u16 affine_param;
} OAMData;

/* sizeof(AnimFrameData) == 8 */
typedef struct AnimFrameData {
    /* 0x00 */ OAMData* sprite_gfx_p;
    /* 0x04 */ u16 duration;
    /* 0x06 */ s8 action_flag;
    /* 0x07 */ u8 pad;
} AnimFrameData;

#ifdef __cplusplus
}
#endif

#endif // ANIM_H