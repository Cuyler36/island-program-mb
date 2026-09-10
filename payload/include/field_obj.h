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

/* Runtime field-object types derived from ItemGroupStruct.field_entity_type. */
typedef enum FieldObjectType {
    FIELD_OBJECT_TYPE_NONE,
    FIELD_OBJECT_TYPE_MY_COTTAGE,
    FIELD_OBJECT_TYPE_NPC_COTTAGE,
    FIELD_OBJECT_TYPE_SMALL_TREE,
    FIELD_OBJECT_TYPE_MEDIUM_TREE,
    FIELD_OBJECT_TYPE_LARGE_TREE,
    FIELD_OBJECT_TYPE_FULLY_GROWN_TREE,
    FIELD_OBJECT_TYPE_APPLE_TREE,
    FIELD_OBJECT_TYPE_ORANGE_TREE,
    FIELD_OBJECT_TYPE_PEACH_TREE,
    FIELD_OBJECT_TYPE_PEAR_TREE,
    FIELD_OBJECT_TYPE_CHERRY_TREE,
    FIELD_OBJECT_TYPE_LARGE_STUMP,
    FIELD_OBJECT_TYPE_FULLY_GROWN_STUMP,
    FIELD_OBJECT_TYPE_SMALL_PALM_TREE,
    FIELD_OBJECT_TYPE_MEDIUM_PALM_TREE,
    FIELD_OBJECT_TYPE_LARGE_PALM_TREE,
    FIELD_OBJECT_TYPE_FULLY_GROWN_PALM_TREE,
    FIELD_OBJECT_TYPE_FRUIT_PALM_TREE,

    FIELD_OBJECT_TYPE_NUM,

    FIELD_OBJECT_TYPE_FLAG = FIELD_OBJECT_TYPE_NUM,
    FIELD_OBJECT_TYPE_HOLE,

    FIELD_OBJECT_TYPE_ALL_NUM
} FieldObjectType;

/* Indices into gFieldObjectProcs. */
typedef enum FieldObjectActionState {
    FIELD_OBJECT_ACTION_IDLE = 0,
    FIELD_OBJECT_ACTION_HANDLE_HIT,
    FIELD_OBJECT_ACTION_SHAKE,
    FIELD_OBJECT_ACTION_TOPPLE,
    FIELD_OBJECT_ACTION_DEACTIVATE,

    FIELD_OBJECT_ACTION_NUM
} FieldObjectActionState;

/* Runtime state for a field object such as a tree, flower, or rock. */
/* sizeof(FieldObject) == 0x30 */
typedef struct FieldObject {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u16 *drop_tilemap;
    /* 0x0C */ u16 type; /* FieldObjectType */
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
    /* 0x28 */ u8 action_state; /* FieldObjectActionState */
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

void FieldObject_AttachEntity(s32 object_index, s32 fruit_type);
void FieldObject_Init(s32 object_index, u16 type, s32 tile, u8 layer);
void FieldObject_Update(s32 object_index);
void FieldObject_Idle(s32 object_index);
void FieldObject_SpawnToppleEffect(s32 object_index);
void FieldObject_UpdateForegroundItem(s32 object_index);
void FieldObject_HandleHit(s32 object_index);
void FieldObject_UpdateShake(s32 object_index);
void FieldObject_UpdateTopple(s32 object_index);
void FieldObject_Deactivate(s32 object_index);
void FieldObject_DrawSprite(FieldObjectSpriteFrame *frame, s32 object_index);
void FieldObject_Draw(s32 object_index);

extern FieldObject gFieldObjects[FIELD_OBJECT_COUNT]; // @0x03003C00

#ifdef __cplusplus
}
#endif

#endif // FIELD_OBJ_H
