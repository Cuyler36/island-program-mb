#include "field_obj.h"
#include "lib.h"
#include "sound.h"
#include "island_field.h"
#include "entity.h"
#include "falling_fruit.h"

typedef void (*FieldObject_PROC)(int);

/* Original address: 0x0202FECC */
FieldObject_PROC gFieldObjectProcs[FIELD_OBJECT_ACTION_NUM] = {
    FieldObject_Idle,
    FieldObject_HandleHit,
    FieldObject_UpdateShake,
    FieldObject_UpdateTopple,
    FieldObject_Deactivate,
};

/* Original address: 0x0202FEE0 */
u8 gFieldObjectSpriteFrameIndices[FIELD_OBJECT_TYPE_NUM * 8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0D, 0x0E, 0x0D, 0x0C, 0x0E, 0x0C, 0x0C,
    0x0F, 0x10, 0x11, 0x10, 0x0F, 0x11, 0x0F, 0x0F, 0x12, 0x13, 0x14, 0x13, 0x12, 0x14, 0x12, 0x12,
    0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15, 0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15,
    0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15, 0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15,
    0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15, 0x15, 0x16, 0x17, 0x16, 0x15, 0x17, 0x15, 0x15,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x00, 0x00, 0x03, 0x04, 0x05, 0x04, 0x03, 0x05, 0x03, 0x03,
    0x06, 0x07, 0x08, 0x07, 0x06, 0x08, 0x06, 0x06, 0x09, 0x0A, 0x0B, 0x0A, 0x09, 0x0B, 0x09, 0x09,
    0x09, 0x0A, 0x0B, 0x0A, 0x09, 0x0B, 0x09, 0x09,
};

/* Original address: 0x0202FF78 */
FieldObjectSpriteFrame gFieldObjectSpriteFrames[24] = {
    { 0x80000000, -24, -16, 0x01A9, 0x0000 },
    { 0x80000000, -24, -15, 0x01A9, 0x0000 },
    { 0x80000000, -24, -17, 0x01A9, 0x0000 },
    { 0xC0000000, -64, -32, 0x0152, 0x0000 },
    { 0xC0000000, -64, -31, 0x0152, 0x0000 },
    { 0xC0000000, -64, -33, 0x0152, 0x0000 },
    { 0xC0000000, -67, -32, 0x01D8, 0x0000 },
    { 0xC0000000, -67, -31, 0x01D8, 0x0000 },
    { 0xC0000000, -67, -33, 0x01D8, 0x0000 },
    { 0xC0000000, -67, -32, 0x0286, 0x0000 },
    { 0xC0000000, -67, -31, 0x0286, 0x0000 },
    { 0xC0000000, -67, -33, 0x0286, 0x0000 },
    { 0x40000000, -14, -8, 0x01C7, 0x0000 },
    { 0x40000000, -14, -7, 0x01C7, 0x0000 },
    { 0x40000000, -14, -9, 0x01C7, 0x0000 },
    { 0x80000000, -32, -16, 0x0254, 0x0000 },
    { 0x80000000, -32, -17, 0x0254, 0x0000 },
    { 0x80000000, -32, -15, 0x0254, 0x0000 },
    { 0xC0000000, -66, -32, 0x01CC, 0x0000 },
    { 0xC0000000, -66, -31, 0x01CC, 0x0000 },
    { 0xC0000000, -66, -33, 0x01CC, 0x0000 },
    { 0xC0000000, -68, -32, 0x00CB, 0x0000 },
    { 0xC0000000, -68, -31, 0x00CB, 0x0000 },
    { 0xC0000000, -68, -33, 0x00CB, 0x0000 },
};

/* Original address: 0x020300F8 */
u8 sFruitDropOffsetsX[3*4] = {
    0x0F, 0x0F, 0x0E, 0x0F,
    0x01, 0x01, 0x02, 0x01,
    0x00, 0x00, 0x0F, 0x01,
};

/* Original address: 0x02030104 */
u8 sFruitDropOffsetsY[3*4] = {
    0x00, 0x0F, 0x00, 0x01,
    0x00, 0x0F, 0x00, 0x01,
    0x01, 0x02, 0x01, 0x01,
};

/* Original address: 0x02030110 */
u8 sFieldObjectInitialTimers[FIELD_OBJECT_TYPE_NUM] = {
    0xFF, 0xFF, 0xFF, 0x01, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x01, 0x02,
    0x03, 0x03, 0x03,
};

/* Original address: 0x02030123 */
u8 sFieldObjectShakeFrames[9] = {
    0x01, 0x02, 0x01, 0x00, 0x02, 0x01, 0x02, 0x01, 0x03,
};

/**
 * Allocates a falling-fruit slot and attaches it to a field object.
 *
 * Original address: 0x0201E3DC
 */
void FieldObject_AttachEntity(s32 object_index, s32 fruit_type) {
    FieldObject *object;
    IslandFieldWork *field;
    s32 slot;

    object = gFieldObjects + object_index;
    field = &gIslandFieldWork;
    for (slot = 3; slot < 30; slot++) {
        if (field->entity_active[slot + 24] == 0) {
            field->entity_active[slot + 24] = 1;
            FallingFruit_Init(object_index, slot, fruit_type, object->layer);
            do {
            object->falling_fruit_id = slot + 1;
            } while(0);
            break;
        }
    }
}

/**
 * Initializes a field object from its field-entity type, tile, and acre layer.
 *
 * Fruit-bearing trees also receive an attached fruit entity.
 *
 * Original address: 0x0201E430
 */
void FieldObject_Init(s32 object_index, u16 type, s32 tile, u8 layer) {
    FieldObject *object;
    s32 tile_x;

    object = &gFieldObjects[object_index];
    object->type = type;
    object->x_flip = 0;
    object->rotation = 0;
    object->topple_x_offset = 0;
    object->topple_y_offset = 0;
    object->topple_extra_x_offset = 0;
    object->action_state = FIELD_OBJECT_ACTION_IDLE;
    object->anim_counter = 0;
    object->anim_frame = 0;
    object->anim_timer = 0;
    object->hits_remaining = 0;
    object->falling_fruit_id = 0;
    object->fruit_drop_processed = 0;
    object->drop_tile_x = 0;
    object->drop_tile_y = 0;
    object->drop_existing_item = 0;
    object->shake_animation_paused = 0;
    object->favorite_hour_item_eligible = 0;
    object->y = (0xF0 & tile) + 8;
    tile_x = (0xF & tile) * 0x10;
    object->x = tile_x + 8;
    object->tile_idx = tile & 0xFF;
    if (layer != 0) {
        object->x = tile_x + 0x108;
    }
    object->hits_remaining = sFieldObjectInitialTimers[object->type];
    object->layer = layer;
    if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE) {
        FieldObject_AttachEntity(object_index, 0U);
    }
    if (object->type == FIELD_OBJECT_TYPE_APPLE_TREE) {
        FieldObject_AttachEntity(object_index, 3U);
    }
    if (object->type == FIELD_OBJECT_TYPE_ORANGE_TREE) {
        FieldObject_AttachEntity(object_index, 7U);
    }
    if (object->type == FIELD_OBJECT_TYPE_PEACH_TREE) {
        FieldObject_AttachEntity(object_index, 0xBU);
    }
    if (object->type == FIELD_OBJECT_TYPE_PEAR_TREE) {
        FieldObject_AttachEntity(object_index, 0xFU);
    }
    if (object->type == FIELD_OBJECT_TYPE_CHERRY_TREE) {
        FieldObject_AttachEntity(object_index, 0x13U);
    }
    if (object->type == FIELD_OBJECT_TYPE_FULLY_GROWN_TREE) {
        object->favorite_hour_item_eligible = 1;
    }
}

/**
 * Dispatches the current update state for a field object.
 *
 * Original address: 0x0201E538
 */
void FieldObject_Update(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    gFieldObjectProcs[object->action_state](object_index);
}

/**
 * Leaves an inactive field object unchanged until another system reports a hit.
 *
 * Original address: 0x0201E560
 */
void FieldObject_Idle(s32 object_index) {

}

/**
 * Spawns one debris effect near a tree as it begins to topple.
 *
 * Original address: 0x0201E564
 */
void FieldObject_SpawnToppleEffect(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 slot;
    Entity *entity;
    s32 offset_x;
    s32 offset_y;

    if (object->type != FIELD_OBJECT_TYPE_SMALL_TREE && object->type != FIELD_OBJECT_TYPE_SMALL_PALM_TREE) {
        for (slot = 3; slot < 10; slot++) {
            if (field->entity_active[slot + 3] == 0) {
                entity = &g_EntityTable[slot];
                field->entity_active[slot + 3] = 1;
                Entity_Reset(slot);
                offset_x = 16 - rand_u16(&gGameState) % 33;
                offset_y = rand_u16(&gGameState) % 17 + 16;
                if (object->type == FIELD_OBJECT_TYPE_MEDIUM_TREE) {
                    offset_y = 16;
                }
                entity->x = object->x + offset_x;
                entity->y = object->y - offset_y;
                entity->update_type = 1;
                break;
            }
        }
    }
}

/**
 * Writes a toppled tree's stump or a shaken tree's fruitless form to field data.
 *
 * Original address: 0x0201E608
 */
void FieldObject_UpdateForegroundItem(s32 object_index) {
    FieldObject *object;
    s16 item;

    object = &gFieldObjects[object_index];
    item = 0;
    if (object->action_state == FIELD_OBJECT_ACTION_TOPPLE) {
        if (object->type == FIELD_OBJECT_TYPE_SMALL_TREE) {
            item = TREE_STUMP001;
        }
        if (object->type == FIELD_OBJECT_TYPE_MEDIUM_TREE) {
            item = TREE_STUMP002;
        }
        if (object->type == FIELD_OBJECT_TYPE_LARGE_TREE) {
            item = TREE_STUMP003;
        }
        if (object->type == FIELD_OBJECT_TYPE_FULLY_GROWN_TREE) {
            item = TREE_STUMP004;
        }
        if (object->type == FIELD_OBJECT_TYPE_SMALL_PALM_TREE) {
            item = TREE_PALM_STUMP001;
        }
        if (object->type == FIELD_OBJECT_TYPE_MEDIUM_PALM_TREE) {
            item = TREE_PALM_STUMP002;
        }
        if (object->type == FIELD_OBJECT_TYPE_LARGE_PALM_TREE) {
            item = TREE_PALM_STUMP003;
        }
        if (object->type == FIELD_OBJECT_TYPE_FULLY_GROWN_PALM_TREE) {
            item = TREE_PALM_STUMP004;
        }
    } else {
        if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE) {
            item = TREE_PALM_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_PALM_TREE;
        }
        if (object->type == FIELD_OBJECT_TYPE_APPLE_TREE) {
            item = TREE_APPLE_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_TREE;
        }
        if (object->type == FIELD_OBJECT_TYPE_ORANGE_TREE) {
            item = TREE_ORANGE_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_TREE;
        }
        if (object->type == FIELD_OBJECT_TYPE_PEACH_TREE) {
            item = TREE_PEACH_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_TREE;
        }
        if (object->type == FIELD_OBJECT_TYPE_PEAR_TREE) {
            item = TREE_PEAR_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_TREE;
        }
        if (object->type == FIELD_OBJECT_TYPE_CHERRY_TREE) {
            item = TREE_CHERRY_NOFRUIT_0;
            object->type = FIELD_OBJECT_TYPE_FULLY_GROWN_TREE;
        }
    }
    if (!(object->x & 0x100)) {
        gIslandData->fgblock[0][0].items[(object->tile_idx >> 4) & 0xF][object->tile_idx & 0xF] = item;
    } else {
        gIslandData->fgblock[0][1].items[(object->tile_idx >> 4) & 0xF][object->tile_idx & 0xF] = item;
    }
}

/**
 * Processes a hit, selecting shake or topple state and dropping attached fruit.
 *
 * Drop positions are chosen around the tree and may cross the acre boundary.
 *
 * Original address: 0x0201E710
 */
void FieldObject_HandleHit(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 fruit_index;
    s32 candidate;
    u32 fg_tile;
    u8 acre;
    FallingFruit *fruit;
    u16 x, y = 0;

    if (object->hits_remaining == 0 || (object->hits_remaining & 0x80)) {
        FieldObject_SpawnToppleEffect(object_index);
        object->anim_timer = 8;
        object->anim_counter = 0;
        object->rotation_threshold = 0xFFFF;
        object->action_state = FIELD_OBJECT_ACTION_TOPPLE;
        FieldObject_UpdateForegroundItem(object_index);
        Sound_PlayEffect0(0x13);
    } else {
        Sound_PlayEffect0(0x18);
        object->anim_timer = 2;
        object->anim_counter = 0;
        object->anim_frame = 0;
        object->action_state = FIELD_OBJECT_ACTION_SHAKE;
    }
    if (object->falling_fruit_id == 0) {
        return;
    }
    if (object->fruit_drop_processed != 0) {
        return;
    }
    for (fruit_index = 0; fruit_index < 3; fruit_index++) {
        if (field->entity_active[fruit_index + 21] == 1 && object->falling_fruit_id != 0) {
            field->entity_active[object->falling_fruit_id + 23] = 0;
            object->falling_fruit_id = 0;
            return;
        }
        for (candidate = 0; candidate < 4; candidate++) {
            // Odd variable assignment needed to match
            y = sFruitDropOffsetsY[fruit_index * 4 + candidate];
            object->drop_tile_y = y = y * 16 + object->tile_idx;
            object->drop_tile_y &= 0xF0;
            x = sFruitDropOffsetsX[fruit_index * 4 + candidate];
            object->drop_tile_x = x = x + (object->tile_idx & 0xF);
            object->drop_tile_x &= 0xF;
            acre = 0;
            if (object->layer == 0) {
                object->drop_existing_item = gIslandData->fgblock[0][0].items[object->drop_tile_y >> 4][object->drop_tile_x];
                fg_tile = field->fg_tiles[0][(u8)(object->drop_tile_y + object->drop_tile_x)];
                if (object->drop_tile_x <= 1) {
                    acre = 1;
                    object->drop_existing_item = gIslandData->fgblock[0][1].items[object->drop_tile_y >> 4][object->drop_tile_x];
                    fg_tile = field->fg_tiles[1][(u8)(object->drop_tile_y + object->drop_tile_x)];
                }
            }
            if (object->layer != 0) {
                acre = 1;
                object->drop_existing_item = gIslandData->fgblock[0][1].items[object->drop_tile_y >> 4][object->drop_tile_x & 0xF];
                fg_tile = field->fg_tiles[1][(u8)(object->drop_tile_y + object->drop_tile_x)];
                if (object->drop_tile_x > 13) {
                    acre = 0;
                    object->drop_existing_item = gIslandData->fgblock[0][0].items[object->drop_tile_y >> 4][object->drop_tile_x & 0xF];
                    fg_tile = field->fg_tiles[0][(u8)(object->drop_tile_y + object->drop_tile_x)];
                }
            }
            if (acre == 0) {
                object->drop_tilemap = (u16 *)BG_SCREEN_ADDR(20);
            } else {
                object->drop_tilemap = (u16 *)BG_SCREEN_ADDR(21);
            }
            object->drop_tilemap = object->drop_tilemap + ((u8)(object->drop_tile_y + object->drop_tile_x) & 0xF0) * 4 +
                                   ((u8)(object->drop_tile_y + object->drop_tile_x) & 0xF) * 2;
            if ((object->drop_existing_item == 0 && fg_tile == 0xFFF &&
                 ((*object->drop_tilemap & 0x3FF) >= 0x20 && (*object->drop_tilemap & 0x3FF) <= 0x7E)) || candidate == 3) {
                field->entity_active[fruit_index + 21] = 1;
                if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 1, acre);
                }
                if (object->type == FIELD_OBJECT_TYPE_APPLE_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 4, acre);
                }
                if (object->type == FIELD_OBJECT_TYPE_ORANGE_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 8, acre);
                }
                if (object->type == FIELD_OBJECT_TYPE_PEACH_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 12, acre);
                }
                if (object->type == FIELD_OBJECT_TYPE_PEAR_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 16, acre);
                }
                if (object->type == FIELD_OBJECT_TYPE_CHERRY_TREE) {
                    FallingFruit_Init(object_index, fruit_index, fruit_index + 20, acre);
                }
                if (acre == 0) {
                    field->fg_tiles[0][(u8)(object->drop_tile_y + object->drop_tile_x)] = 0x7777;
                } else {
                    field->fg_tiles[1][(u8)(object->drop_tile_y + object->drop_tile_x)] = 0x7777;
                }
                fruit = &gFallingFruit[fruit_index];
                fruit->landing_x = object->drop_tile_x << 4;
                if (acre != 0) {
                    fruit->landing_x |= 0x100;
                }
                fruit->landing_y = object->drop_tile_y;
                fruit->tile_idx = object->drop_tile_y + object->drop_tile_x;
                if (object->drop_existing_item == 0 && fg_tile == 0xFFF) {
                    fruit->can_land = 1;
                }
                break;
            }
        }
        if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE && fruit_index == 1) {
            break;
        }
    }
    FieldObject_UpdateForegroundItem(object_index);
    if (object->action_state == FIELD_OBJECT_ACTION_TOPPLE) {
        if (object->layer == 0) {
            if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE) {
                field->fg_tiles[0][object->tile_idx] = ITEM_TYPE_FULLY_GROWN_TREE;
            } else {
                field->fg_tiles[0][object->tile_idx] = ITEM_TYPE_PALM_TREE;
            }
        }
        if (object->layer != 0) {
            if (object->type == FIELD_OBJECT_TYPE_FRUIT_PALM_TREE) {
                field->fg_tiles[1][object->tile_idx] = ITEM_TYPE_FULLY_GROWN_TREE;
            } else {
                field->fg_tiles[1][object->tile_idx] = ITEM_TYPE_PALM_TREE;
            }
        }
    }
    object->fruit_drop_processed = 1;
    field->entity_active[object->falling_fruit_id + 23] = 0;
    object->falling_fruit_id = 0xFFFF;
}

/**
 * Advances the shake animation, emits debris, and returns the object to idle.
 *
 * Original address: 0x0201EB48
 */
void FieldObject_UpdateShake(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    IslandFieldWork *field = &gIslandFieldWork;
    s32 count;
    s32 slot;
    Entity *entity;
    s32 random;
    s32 x;
    s32 y;

    if (object->shake_animation_paused == 0) {
        object->anim_timer--;
        if (object->anim_timer == 0) {
            object->anim_timer = 2;
            object->anim_counter++;
            object->anim_frame = sFieldObjectShakeFrames[object->anim_counter];
        }
    }
    if (object->anim_counter & 1) {
        if (object->type != FIELD_OBJECT_TYPE_SMALL_TREE && object->type != FIELD_OBJECT_TYPE_SMALL_PALM_TREE) {
            for (count = 0; count < 3; count++) {
                for (slot = 3; slot < 10; slot++) {
                    if (field->entity_active[slot + 3] == 0) {
                        entity = &g_EntityTable[slot];
                        field->entity_active[slot + 3] = 1;
                        Entity_Reset(slot);
                        random = rand_u16(&gGameState);
                        x = object->x + 16;
                        entity->x = x - random % 33;
                        random = rand_u16(&gGameState);
                        y = object->y - 16;
                        entity->y = y - random % 17;
                        entity->update_type = 3;
                        break;
                    }
                }
            }
        }
    }
    if (object->anim_frame > 2) {
        object->anim_timer = 0;
        object->anim_counter = 0;
        object->anim_frame = 0;
        object->shake_animation_paused = 0;
        object->action_state = FIELD_OBJECT_ACTION_IDLE;
    }
}

/**
 * Accelerates a chopped tree's rotation until it finishes falling and deactivates.
 *
 * Original address: 0x0201EC6C
 */
void FieldObject_UpdateTopple(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    u32 rotation_step;
    u32 drop_angle;
    u32 rotation_speed;
    u32 rotation_threshold;

    if (object->anim_timer != 0) {
        object->anim_timer--;
        if (!(object->anim_timer & 1)) {
            object->topple_x_offset++;
        }
    } else {
        rotation_step = 0x200;
        drop_angle = 0xF200;
        switch (object->type) {
        case FIELD_OBJECT_TYPE_SMALL_PALM_TREE:
        case FIELD_OBJECT_TYPE_SMALL_TREE:
            rotation_step = 0x800;
            drop_angle = 0xE800;
            break;
        case FIELD_OBJECT_TYPE_MEDIUM_TREE:
            rotation_step = 0x400;
            drop_angle = 0xF800;
            break;
        }
        rotation_speed = rotation_step + object->rotation_speed;
        object->rotation_speed = rotation_speed;
        if ((u16)rotation_speed > rotation_step) {
            object->rotation_speed = rotation_step;
        }
        object->rotation -= object->rotation_speed;
        if (object->rotation <= object->rotation_threshold) {
            rotation_threshold = (object->rotation_threshold & 0xFF00) - rotation_step;
            object->rotation_threshold = rotation_threshold;
            object->topple_x_offset++;
            if ((u16)rotation_threshold < drop_angle) {
                object->topple_y_offset++;
            }
            if (object->type != FIELD_OBJECT_TYPE_SMALL_TREE && object->type != FIELD_OBJECT_TYPE_SMALL_PALM_TREE) {
                if (object->topple_extra_x_offset <= 5) {
                    object->topple_extra_x_offset++;
                }
            }
        }
        if (object->rotation <= 0xD000) {
            object->rotation = 0xD000;
            object->anim_counter++;
            if (object->anim_counter > 0x20) {
                object->action_state = FIELD_OBJECT_ACTION_DEACTIVATE;
                object->falling_fruit_id = 0;
            }
        }
    }
}

/**
 * Releases the field object's active slot.
 *
 * Original address: 0x0201ED50
 */
void FieldObject_Deactivate(s32 object_index) {
    gIslandFieldWork.entity_active[object_index + 54] = 0;
}

/**
 * Appends one field-object sprite to OAM, applying topple rotation and offsets.
 *
 * Original address: 0x0201ED68
 */
void FieldObject_DrawSprite(FieldObjectSpriteFrame *frame, s32 object_index) {
    /* The BIOS reads the affine source as words. */
    struct ObjAffineSrcData transform __attribute__((aligned(4)));
    struct { s16 pa, pb, pc, pd; } matrix;
    FieldObject *object = &gFieldObjects[object_index];
    OAMData *oam = &GameOAMData[gGameState.oam_count];

    oam->shape = (frame->oam_attributes >> 14) & 3;
    oam->size = (frame->oam_attributes >> 30) & 0xF;
    oam->tile_num = frame->tile_num;
    oam->h_flip = 0;
    oam->priority = 1;
    oam->palette_num = 0;
    oam->mosaic = 1;
    if ((u8)(object->action_state - FIELD_OBJECT_ACTION_TOPPLE) <=
        FIELD_OBJECT_ACTION_DEACTIVATE - FIELD_OBJECT_ACTION_TOPPLE) {
        oam->affine_mode = 1;
        oam->matrix_num = 0;
        oam->obj_mode = 0;
        transform.xScale = 0x100;
        transform.yScale = 0x100;
        if (object->x_flip == 0) {
            transform.rotation = object->rotation;
        } else {
            transform.rotation = -object->rotation;
        }
        ObjAffineSet(&transform, &matrix, 1, 2);
        oam = (OAMData *)GameOAMData;
        oam->affine_param = matrix.pa;
        oam++;
        oam->affine_param = matrix.pb;
        oam++;
        oam->affine_param = matrix.pc;
        oam[1].affine_param = matrix.pd;
        oam = &GameOAMData[gGameState.oam_count];
    }
    if (object->x_flip == 0) {
        oam->x = frame->x_offset + (object->x - gGameState.bg2_hofs) + object->topple_x_offset + object->topple_extra_x_offset;
    } else {
        oam->x = frame->x_offset + (object->x - gGameState.bg2_hofs) - object->topple_x_offset - object->topple_extra_x_offset;
    }
    oam->y = frame->y_offset + (object->y - (u8)gGameState.bg2_vofs) + (u8)object->topple_y_offset;
    gGameState.oam_count++;
}

/**
 * Draws a visible field object using its type and current animation frame.
 *
 * Original address: 0x0201EF44
 */
void FieldObject_Draw(s32 object_index) {
    FieldObject *object = &gFieldObjects[object_index];
    u16 camera_y = gGameState.bg2_vofs;
    s32 y = object->y;

    if (y >= camera_y && y <= camera_y + 200 &&
        (object->action_state != FIELD_OBJECT_ACTION_TOPPLE || !(object->anim_counter & 2))) {
        u8 *frame_indices = gFieldObjectSpriteFrameIndices;
        u16 type = object->type;
        u8 anim_frame = object->anim_frame;
        u8 frame_index = frame_indices[type * 8 + anim_frame];

        FieldObject_DrawSprite(&gFieldObjectSpriteFrames[frame_index], object_index);
    }
}
