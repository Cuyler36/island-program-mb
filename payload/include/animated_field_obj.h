#ifndef ANIMATED_FIELD_OBJ_H
#define ANIMATED_FIELD_OBJ_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sizeof(AnimatedFieldObject) == 0x0C. */
typedef struct AnimatedFieldObject {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u8 anim_timer;
    /* 0x09 */ u8 anim_frame;
    /* 0x0A */ u8 pad_0A[2];
} AnimatedFieldObject;

void AnimatedFieldObject_Init(s32 arg0, s32 arg1, u8 arg2);
void AnimatedFieldObject_Update(s32 arg0);
void AnimatedFieldObject_Draw(s32 arg0);

#ifdef __cplusplus
}
#endif

#endif // ANIMATED_FIELD_OBJ_H