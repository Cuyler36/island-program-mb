#ifndef FIELD_OBJ_H
#define FIELD_OBJ_H

#include "gba/types.h"
#include "global.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    FIELD_OBJECT_COUNT = 30
};

/* Runtime state for a field object such as a tree, flower, or rock. */
/* sizeof(FieldObject) == 0x30 */
typedef struct FieldObject {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u16 *drop_tilemap;
    /* 0x0C */ u16 type;
    /* 0x0E */ u16 tile_idx;
    /* 0x10 */ u16 rotation;
    /* 0x12 */ u16 rotation_speed;
    /* 0x14 */ u16 rotation_threshold;
    /* 0x16 */ u16 topple_x_offset;
    /* 0x18 */ u16 topple_y_offset;
    /* 0x1A */ u16 topple_extra_x_offset;
    /* 0x1C */ u16 falling_fruit_id; /* slot plus one; 0xFFFF means multiple fruits */
    /* 0x1E */ u16 drop_tile_x;
    /* 0x20 */ u16 drop_tile_y;
    /* 0x22 */ mActor_name_t drop_existing_item;
    /* 0x24 */ u8 layer;
    /* 0x25 */ u8 anim_frame;
    /* 0x26 */ u8 anim_counter;
    /* 0x27 */ u8 anim_timer;
    /* 0x28 */ u8 action_state;
    /* 0x29 */ u8 x_flip;
    /* 0x2A */ u8 hits_remaining;
    /* 0x2B */ u8 fruit_drop_processed;
    /* 0x2C */ u8 shake_animation_paused;
    /* 0x2D */ u8 favorite_hour_item_eligible;
    /* 0x2E */ u8 reserved_2E[2];
} FieldObject;

/* sizeof(FieldObjectSpriteFrame) == 0x10; records at 0x0202FF78. */
typedef struct FieldObjectSpriteFrame {
    /* 0x00 */ u32 oam_attributes;
    /* 0x04 */ s32 y_offset;
    /* 0x08 */ s32 x_offset;
    /* 0x0C */ u16 tile_num;
    /* 0x0E */ u16 unused;
} FieldObjectSpriteFrame;

void FieldObject_AttachEntity(s32 arg0, s32 arg1);
void FieldObject_Init(s32 arg0, u16 arg1, s32 arg2, u8 arg3);
void FieldObject_Update(s32 arg0);
void FieldObject_Idle(s32 idx);
void FieldObject_SpawnToppleEffect(s32 arg0);
void FieldObject_UpdateForegroundItem(s32 arg0);
void FieldObject_HandleHit(s32 arg0);
void FieldObject_UpdateShake(s32 arg0);
void FieldObject_UpdateTopple(s32 object_index);
void FieldObject_Deactivate(s32 arg0);
void FieldObject_DrawSprite(FieldObjectSpriteFrame *frame, s32 object_index);
void FieldObject_Draw(s32 object_index);

extern FieldObject gFieldObjects[FIELD_OBJECT_COUNT]; // @0x03003C00

#ifdef __cplusplus
}
#endif

#endif // FIELD_OBJ_H