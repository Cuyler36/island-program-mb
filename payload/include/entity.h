#ifndef ENTITY_H
#define ENTITY_H

#include "gba/types.h"
#include "global.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sizeof(Entity) == 0x54. Shared item and transient-effect state. */
typedef struct Entity {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 height_offset;
    /* 0x0C */ s32 precise_x;
    /* 0x10 */ s32 base_y;
    /* 0x14 */ s32 vertical_velocity_or_x_limit;
    /* 0x18 */ s32 horizontal_velocity;
    /* 0x1C */ s32 reserved_1C;
    /* 0x20 */ s32 vertical_acceleration_or_bob_velocity;
    /* 0x24 */ s32 depth_offset;
    /* 0x28 */ u16 item_type_indices[5];
    /* 0x32 */ mActor_name_t item_ids[5]; /* unresolved entries are item-generator indices */
    /* 0x3C */ u16 landing_tile; /* layer is encoded in bit 0x1000 */
    /* 0x3E */ u16 sprite_tile;
    /* 0x40 */ u16 lifetime;
    /* 0x42 */ u16 rotation;
    /* 0x44 */ u16 affine_scale;
    /* 0x46 */ u16 bob_phase;
    /* 0x48 */ u16 reserved_48;
    /* 0x4A */ u8 items_are_resolved;
    /* 0x4B */ u8 reaction_type;
    /* 0x4C */ u8 frame_index;
    /* 0x4D */ u8 anim_timer;
    /* 0x4E */ u8 update_type;
    /* 0x4F */ u8 anim_id;
    /* 0x50 */ u8 palette;
    /* 0x51 */ u8 h_flip;
    /* 0x52 */ u8 landing_delay_timer;
    /* 0x53 */ u8 reserved_53;
} Entity;

typedef struct EntitySpawnParams {
    u16 type;
    u16 param;
} EntitySpawnParams;

void Entity_Reset(s32 arg0);
void Entity_PlaceLandedItem(s32 arg0);
void Entity_UpdateLifetime(s32 arg0);
void Entity_BeginToppleEffect(s32 arg0);
void Entity_UpdateToppleEffect(s32 arg0);
void Entity_BeginLeafEffect(s32 arg0);
void Entity_UpdateLeafEffect(s32 arg0);
void Entity_BeginReactionEffect(s32 arg0);
void Entity_UpdateReactionEffect(s32 arg0);
void Entity_BeginItemDrop(s32 arg0);
void Entity_UpdateItemDrop(s32 arg0);
void Entity_BeginFloatingItem(s32 arg0);
void Entity_UpdateFloatingItem(s32 arg0);
void Entity_Update(s32 arg0);
void Entity_DrawFloatingItemShadow(s32 arg0);
void Entity_DrawSprite(s32 arg0);

/* Original address: 0x03004790 */
extern Entity g_EntityTable[12];

#ifdef __cplusplus
}
#endif

#endif // ENTITY_H