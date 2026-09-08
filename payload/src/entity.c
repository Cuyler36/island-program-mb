#include "entity.h"
#include "lib.h"
#include "sound.h"
#include "anim.h"
#include "game.h"
#include "island_field.h"
#include "islander.h"

/* Original address: 0x02034C24 */
extern AnimFrameData *sEntityToppleFrames[8];
/* Original address: 0x02034C44 */
extern AnimFrameData *sEntityLeafFrames[20];
/* Original address: 0x02034CE0 */
extern AnimFrameData **sEntityReactionAnimations[5];

/* Original address: 0x020347E0 */
extern void (*sEntityUpdateProcs[11])(s32);
/* Original address: 0x0202AD34 */
extern const s16 sSineTable[320];

/* Original address: 0x02024F08 */
void Entity_Reset(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    s32 i;

    entity->x = 0;
    entity->y = 0;
    entity->height_offset = 0;
    entity->precise_x = 0;
    entity->base_y = 0;
    entity->vertical_velocity_or_x_limit = 0;
    entity->horizontal_velocity = 0;
    entity->reserved_1C = 0;
    entity->vertical_acceleration_or_bob_velocity = 0;
    entity->depth_offset = 0;
    entity->anim_timer = 0;
    entity->frame_index = 0;
    entity->update_type = 0;
    entity->anim_id = 0;
    entity->lifetime = 10;
    entity->sprite_tile = 0;
    entity->palette = 0;
    entity->reaction_type = 0;
    entity->h_flip = 0;
    entity->affine_scale = 0;
    entity->rotation = 0;
    for (i = 0; i < 5; i++) {
        entity->item_type_indices[i] = 0;
        entity->item_ids[i] = 0;
    }
    entity->landing_delay_timer = 0;
    entity->bob_phase = 0;
    entity->reserved_48 = 0;
    entity->landing_tile = 0;
}

/* Original address: 0x02024F8C */
void Entity_PlaceLandedItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item = entity->item_ids[0];
    u8 tile_idx;
    u16 *tilemap;
    ItemGroupStruct *definition;

    if (entity->items_are_resolved == 0) {
        ItemGeneratorDef *generator = &gItemGeneratorDefs[item];
        if (generator->use_island_id == 0) {
            item = generator->item;
        } else {
            item = Item_TypeToIslandItem(generator->item);
        }
    }
    tile_idx = entity->landing_tile;
    if (!(entity->landing_tile & 0x1000)) {
        field->fg_tiles[0][tile_idx] = entity->item_type_indices[0] | 0x8000;
        tilemap = (u16 *)BG_SCREEN_ADDR(24);
        tilemap += (tile_idx & 0xF0) * 4;
        tilemap += (tile_idx & 0xF) * 2;
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
    } else {
        field->fg_tiles[1][tile_idx] = entity->item_type_indices[0] | 0x8000;
        tilemap = (u16 *)BG_SCREEN_ADDR(25);
        tilemap += (tile_idx & 0xF0) * 4;
        tilemap += (tile_idx & 0xF) * 2;
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
    }
    definition = &g_ItemDefinitions[entity->item_type_indices[0]];
    *tilemap++ = definition->field_tile_id;
    *tilemap = definition->field_tile_id + 1;
    tilemap += 31;
    tilemap[0] = definition->field_tile_id + 2;
    tilemap[1] = definition->field_tile_id + 3;
    field->entity_active[entity_index + 3] = 0;
}

/* Original address: 0x020250B0 */
void Entity_UpdateLifetime(s32 entity_index) {
    IslandFieldWork *field = &gIslandFieldWork;
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->lifetime == 0) {
        field->entity_active[entity_index + 3] = 0;
    } else {
        entity->lifetime--;
    }
}

/* Original address: 0x020250EC */
void Entity_BeginToppleEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityToppleFrames[0]->duration;
    entity->anim_id = 1;
    entity->update_type = 2;
}

/* Original address: 0x02025118 */
void Entity_UpdateToppleEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        if ((entity->frame_index & 7) == 0) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = sEntityToppleFrames[entity->frame_index]->duration;
    }
}

/* Original address: 0x02025180 */
void Entity_BeginLeafEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityLeafFrames[0]->duration;
    entity->anim_id = 2;
    entity->update_type = 4;
}

/* Original address: 0x020251AC */
void Entity_UpdateLeafEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        if (entity->frame_index > 19) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = sEntityLeafFrames[entity->frame_index]->duration;
    }
}

/* Original address: 0x02025210 */
void Entity_BeginReactionEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    AnimFrameData *frame = sEntityReactionAnimations[entity->reaction_type][0];

    switch (entity->reaction_type) {
    case 0:
        Sound_PlayEffect0(5);
        break;
    case 1:
        Sound_PlayEffect0(6);
        break;
    case 2:
        Sound_PlayEffect0(7);
        break;
    case 3:
        Sound_PlayEffect0(8);
        break;
    case 4:
        break;
    }
    entity->anim_timer = frame->duration;
    entity->frame_index = 0;
    entity->anim_id = 3;
    entity->update_type = 6;
}

/* Original address: 0x0202529C */
void Entity_UpdateReactionEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    IslandFieldWork *field = &gIslandFieldWork;
    AnimFrameData *frame;

    entity->anim_timer--;
    if (entity->anim_timer == 0) {
        entity->frame_index++;
        frame = sEntityReactionAnimations[entity->reaction_type][entity->frame_index];
        if ((u8)frame->action_flag == 0xFF) {
            field->entity_active[entity_index + 3] = 0;
            return;
        }
        entity->anim_timer = frame->duration;
    }
}

/* Original address: 0x02025310 */
void Entity_BeginItemDrop(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->precise_x = entity->x << 8;
    entity->base_y = entity->y << 8;
    entity->height_offset = 0;
    entity->vertical_velocity_or_x_limit = 0x200;
    entity->vertical_acceleration_or_bob_velocity = 0x20;
    Sound_PlayEffect0(30);
    entity->anim_id = 0;
    entity->update_type = 8;
}

/* Original address: 0x02025354 */
void Entity_UpdateItemDrop(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    s32 landing_y;

    entity->x = entity->precise_x >> 8;
    landing_y = entity->base_y >> 8;
    entity->y = landing_y - (entity->height_offset >> 8);
    entity->height_offset += entity->vertical_velocity_or_x_limit;
    entity->vertical_velocity_or_x_limit -= entity->vertical_acceleration_or_bob_velocity;
    if (entity->landing_delay_timer == 0) {
        if (entity->y > landing_y + 8) {
            Entity_PlaceLandedItem(entity_index);
        }
    } else {
        entity->landing_delay_timer--;
    }
}

/* Original address: 0x020253A8 */
void Entity_BeginFloatingItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->precise_x = entity->x << 8;
    entity->base_y = entity->y << 8;
    entity->height_offset = 0;
    entity->vertical_acceleration_or_bob_velocity = 0x20;
    entity->depth_offset = 0;
    entity->anim_timer = 16;
    entity->frame_index = 0;
    entity->affine_scale = 0x300;
    entity->bob_phase = 0;
    entity->reserved_48 = 0;
    entity->anim_id = 0;
    entity->update_type = 10;
}

/* Original address: 0x02025400 */
void Entity_UpdateFloatingItem(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 offscreen = 0;
    ItemGroupStruct *definition;
    s32 wave;

    entity->precise_x += entity->horizontal_velocity;
    entity->x = entity->precise_x >> 8;
    entity->y = (entity->base_y >> 8) - entity->depth_offset + (entity->height_offset >> 8);
    islander->flying_item_x = entity->precise_x;
    islander->flying_item_y = entity->base_y;
    entity->height_offset += entity->vertical_acceleration_or_bob_velocity;
    if (entity->horizontal_velocity >= 0) {
        if (entity->x > entity->vertical_velocity_or_x_limit) {
            offscreen = 1;
        }
    } else if (entity->x < entity->vertical_velocity_or_x_limit) {
        offscreen = 1;
    }
    if (islander->stored_item_type_plus_one[4] != 0 || offscreen != 0) {
        entity->rotation -= 0x700;
        entity->affine_scale += 0x10;
        if (entity->depth_offset > 0 && !(entity->affine_scale & 0x10)) {
            entity->depth_offset--;
        }
        if (entity->affine_scale <= 0x300) {
            return;
        }
        entity->affine_scale = 0x300;
        entity->rotation = 0;
        islander->flying_item_spawn_timer = 10800;
        islander->flying_item_spawn_timer += (rand_u16(&gGameState) % 109) * 100;
        islander->flying_item_x = 0;
        islander->flying_item_y = 0;
        field->entity_active[entity_index + 3] = 0;
        return;
    }
    if (entity->depth_offset < 24) {
        entity->depth_offset++;
    }
    entity->rotation += 0x700;
    entity->affine_scale -= 0x10;
    if (entity->affine_scale < 0x100) {
        entity->affine_scale = 0x100;
        entity->rotation = 0;
        if (entity->anim_timer == 0) {
            entity->anim_timer = 16;
            entity->frame_index++;
            if (entity->frame_index > 4) {
                entity->frame_index = 0;
            }
            if (entity->item_ids[entity->frame_index] == 0 &&
                entity->item_type_indices[entity->frame_index] == 0) {
                entity->frame_index = 0;
            }
            definition = &g_ItemDefinitions[entity->item_type_indices[entity->frame_index]];
            entity->sprite_tile = definition->held_item_oam_attr2 & 0x3FF;
            entity->palette = definition->held_item_oam_attr2 >> 12;
        }
        entity->anim_timer--;
    }
    wave = sSineTable[entity->bob_phase];
    entity->vertical_acceleration_or_bob_velocity = wave >> 2;
    if (wave & 0x8000) {
        entity->vertical_acceleration_or_bob_velocity |= 0xFFFF0000;
    }
    entity->bob_phase = (entity->bob_phase + 4) & 0xFF;
    if (entity->bob_phase == 0) {
        entity->vertical_acceleration_or_bob_velocity = 0;
    }
}

/* Original address: 0x020255F0 */
void Entity_Update(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    sEntityUpdateProcs[entity->update_type](entity_index);
}

/* Original address: 0x02025618 */
void Entity_DrawFloatingItemShadow(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->update_type == 10) {
        GameState *game = &gGameState;
        OAMData *oam = &((OAMData *)gUnk3002410)[game->oam_count];
        s32 camera_x;

        oam->y = (entity->base_y >> 8) + (entity->height_offset >> 8) - (u8)game->bg2_vofs;
        camera_x = game->bg2_hofs - 8;
        oam->x = entity->x - camera_x;
        oam->shape = 0;
        oam->size = 0;
        oam->tile_num = 0x200;
        oam->palette_num = 1;
        oam->priority = 1;
        game->oam_count++;
    }
}

/* Original address: 0x020256D0 */
void Entity_DrawSprite(s32 entity_index) {
    /* The BIOS reads the affine source as words. */
    struct ObjAffineSrcData transform __attribute__((aligned(4)));
    struct { s16 pa, pb, pc, pd; } matrix;
    Entity *entity = &g_EntityTable[entity_index];
    AnimFrameData *frame = NULL;
    OAMData *sprite;
    OAMData *oam;
    s32 i;

    switch (entity->anim_id) {
    case 1:
        frame = sEntityToppleFrames[entity->frame_index];
        break;
    case 2:
        frame = sEntityLeafFrames[entity->frame_index];
        break;
    case 3:
        frame = sEntityReactionAnimations[entity->reaction_type][entity->frame_index];
        break;
    }
    if (entity->anim_id != 0) {
        sprite = frame->sprite_gfx_p;
        for (i = 0; i < 12 && sprite->affine_param != 0xFFFF; i++, sprite++) {
            oam = &((OAMData *)gUnk3002410)[gGameState.oam_count];
            oam->y = sprite->y + entity->y - (u8)gGameState.bg2_vofs;
            oam->obj_mode = sprite->obj_mode;
            oam->bpp = sprite->bpp;
            oam->shape = sprite->shape;
            oam->x = sprite->x + entity->x - gGameState.bg2_hofs;
            oam->h_flip = entity->h_flip;
            oam->v_flip = sprite->v_flip;
            oam->size = sprite->size;
            oam->tile_num = sprite->tile_num;
            oam->priority = 1;
            if (entity->update_type == 6) {
                oam->priority = 0;
            }
            oam->palette_num = sprite->palette_num;
            oam->mosaic = 1;
            gGameState.oam_count++;
        }
    } else {
        oam = &((OAMData *)gUnk3002410)[gGameState.oam_count];
        oam->y = entity->y - (u8)gGameState.bg2_vofs;
        oam->x = entity->x - gGameState.bg2_hofs;
        oam->shape = 0;
        oam->size = 1;
        oam->tile_num = entity->sprite_tile;
        oam->palette_num = entity->palette;
        oam->mosaic = 1;
        oam->priority = 1;
        gGameState.oam_count++;
        if (entity->update_type == 10) {
            oam->affine_mode = 1;
            oam->matrix_num = 1;
            oam->obj_mode = 0;
            transform.xScale = entity->affine_scale;
            transform.yScale = entity->affine_scale;
            transform.rotation = entity->rotation;
            ObjAffineSet(&transform, &matrix, 1, 2);
            ((OAMData *)gUnk3002410)[4].affine_param = matrix.pa;
            ((OAMData *)gUnk3002410)[5].affine_param = matrix.pb;
            ((OAMData *)gUnk3002410)[6].affine_param = matrix.pc;
            ((OAMData *)gUnk3002410)[7].affine_param = matrix.pd;
        }
    }
}
