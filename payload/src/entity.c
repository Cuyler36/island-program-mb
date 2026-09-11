#include "entity.h"
#include "lib.h"
#include "sound.h"
#include "anim.h"
#include "game.h"
#include "island_field.h"
#include "islander.h"

/* Original address: 0x02034720 */
OAMData sEntityReactionOamData[12][2] = {
    { OAM_ENTRY(0x00E9, 0x01FD, 0x7359, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E8, 0x01FD, 0x7359, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EA, 0x01FC, 0x735A, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E9, 0x01FC, 0x735A, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E8, 0x01FC, 0x735A, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EC, 0x01F5, 0x735B, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EC, 0x01F5, 0x735B, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EB, 0x01FC, 0x735C, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EA, 0x01FB, 0x735C, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E9, 0x01FB, 0x735C, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E8, 0x01FC, 0x735C, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00E3, 0x41EC, 0x72D6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
};

/* Original address: 0x020347E0 */
void (*sEntityUpdateProcs[11])(s32) = {
    Entity_UpdateLifetime,
    Entity_BeginToppleEffect,
    Entity_UpdateToppleEffect,
    Entity_BeginLeafEffect,
    Entity_UpdateLeafEffect,
    Entity_BeginReactionEffect,
    Entity_UpdateReactionEffect,
    Entity_BeginItemDrop,
    Entity_UpdateItemDrop,
    Entity_BeginFloatingItem,
    Entity_UpdateFloatingItem,
};

/* Original address: 0x0203480C */
OAMData sEntityToppleOamData[8][6] = {
    { OAM_ENTRY(0x00F8, 0x11FE, 0x01C6, 0), OAM_ENTRY(0x00FA, 0x01F9, 0x01C6, 0), OAM_ENTRY(0x0000, 0x21F7, 0x01E6, 0), OAM_ENTRY(0x0003, 0x31FC, 0x01C6, 0), OAM_ENTRY(0x00FE, 0x3000, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0004, 0x31FE, 0x01C6, 0), OAM_ENTRY(0x00F8, 0x01F7, 0x01C6, 0), OAM_ENTRY(0x00F5, 0x11FF, 0x01C6, 0), OAM_ENTRY(0x0001, 0x21F4, 0x01E6, 0), OAM_ENTRY(0x00FF, 0x3003, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0005, 0x3000, 0x01E6, 0), OAM_ENTRY(0x0000, 0x3006, 0x01E6, 0), OAM_ENTRY(0x0001, 0x21F1, 0x01E6, 0), OAM_ENTRY(0x00F6, 0x01F5, 0x01C6, 0), OAM_ENTRY(0x00F2, 0x1000, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0005, 0x1001, 0x01E6, 0), OAM_ENTRY(0x0000, 0x01EF, 0x01E6, 0), OAM_ENTRY(0x00F4, 0x01F4, 0x01C6, 0), OAM_ENTRY(0x00EF, 0x1000, 0x01C6, 0), OAM_ENTRY(0x0000, 0x1008, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00F2, 0x01F3, 0x01C6, 0), OAM_ENTRY(0x00FF, 0x01EE, 0x01E6, 0), OAM_ENTRY(0x00ED, 0x1000, 0x01C6, 0), OAM_ENTRY(0x0004, 0x1002, 0x01C6, 0), OAM_ENTRY(0x00FF, 0x100A, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00FE, 0x100B, 0x01C6, 0), OAM_ENTRY(0x00FE, 0x01ED, 0x01C6, 0), OAM_ENTRY(0x00F1, 0x01F3, 0x01C6, 0), OAM_ENTRY(0x00EC, 0x0000, 0x01C6, 0), OAM_ENTRY(0x0003, 0x1003, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00FD, 0x01ED, 0x01C6, 0), OAM_ENTRY(0x00FD, 0x100C, 0x01C6, 0), OAM_ENTRY(0x00EB, 0x0000, 0x01C6, 0), OAM_ENTRY(0x00F0, 0x01F2, 0x01C6, 0), OAM_ENTRY(0x0002, 0x0004, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00EF, 0x01F3, 0x01C6, 0), OAM_ENTRY(0x00EB, 0x01FF, 0x01C6, 0), OAM_ENTRY(0x00FD, 0x01ED, 0x01C6, 0), OAM_ENTRY(0x00FC, 0x000D, 0x01C6, 0), OAM_ENTRY(0x0002, 0x0003, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
};

/* Original address: 0x0203498C */
OAMData sEntityLeafOamData[20][2] = {
    { OAM_ENTRY(0x00FC, 0x01FC, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00FE, 0x01FD, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x00FF, 0x01FF, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0000, 0x0001, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0000, 0x1002, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0001, 0x1001, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0002, 0x11FF, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0003, 0x11FC, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0004, 0x11F8, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0004, 0x01F6, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0004, 0x01F5, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0005, 0x01F5, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0006, 0x01F6, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x0008, 0x01F8, 0x01C6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000A, 0x01FB, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000B, 0x01FF, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000C, 0x0004, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000C, 0x0007, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000C, 0x1009, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
    { OAM_ENTRY(0x000B, 0x100A, 0x01E6, 0), OAM_ENTRY(0, 0, 0, 0xFFFF) },
};

/* Original address: 0x02034ACC */
AnimFrameData sEntityMainAnimFrames[28] = {
    { sEntityToppleOamData[0], 2, 0, 0 }, { sEntityToppleOamData[1], 2, 0, 0 },
    { sEntityToppleOamData[2], 2, 0, 0 }, { sEntityToppleOamData[3], 2, 0, 0 },
    { sEntityToppleOamData[4], 2, 0, 0 }, { sEntityToppleOamData[5], 2, 0, 0 },
    { sEntityToppleOamData[6], 2, 0, 0 }, { sEntityToppleOamData[7], 2, 0, 0 },
    { sEntityLeafOamData[0], 2, 0, 0 }, { sEntityLeafOamData[1], 2, 0, 0 },
    { sEntityLeafOamData[2], 2, 0, 0 }, { sEntityLeafOamData[3], 3, 0, 0 },
    { sEntityLeafOamData[4], 5, 0, 0 }, { sEntityLeafOamData[5], 2, 0, 0 },
    { sEntityLeafOamData[6], 2, 0, 0 }, { sEntityLeafOamData[7], 2, 0, 0 },
    { sEntityLeafOamData[8], 2, 0, 0 }, { sEntityLeafOamData[9], 3, 0, 0 },
    { sEntityLeafOamData[10], 5, 0, 0 }, { sEntityLeafOamData[11], 2, 0, 0 },
    { sEntityLeafOamData[12], 2, 0, 0 }, { sEntityLeafOamData[13], 2, 0, 0 },
    { sEntityLeafOamData[14], 2, 0, 0 }, { sEntityLeafOamData[15], 2, 0, 0 },
    { sEntityLeafOamData[16], 2, 0, 0 }, { sEntityLeafOamData[17], 2, 0, 0 },
    { sEntityLeafOamData[18], 2, 0, 0 }, { sEntityLeafOamData[19], 2, 0, 0 },
};

/* Original address: 0x02034BAC */
AnimFrameData sEntityReactionAnimFrames[15] = {
    { sEntityReactionOamData[0], 2, 0, 0 },
    { sEntityReactionOamData[1], 2, 0, 0 },
    { sEntityReactionOamData[0], 4, 0, 0 },
    { sEntityReactionOamData[1], 22, 0, 0 },
    { sEntityReactionOamData[2], 2, 0, 0 },
    { sEntityReactionOamData[3], 2, 0, 0 },
    { sEntityReactionOamData[4], 24, 0, 0 },
    { sEntityReactionOamData[5], 2, 0, 0 },
    { sEntityReactionOamData[6], 28, 0, 0 },
    { sEntityReactionOamData[7], 2, 0, 0 },
    { sEntityReactionOamData[8], 2, 0, 0 },
    { sEntityReactionOamData[9], 4, 0, 0 },
    { sEntityReactionOamData[10], 24, 0, 0 },
    { sEntityReactionOamData[11], 20, 0, 0 },
    { (OAMData *)0x0000FFFF, 0xFFFF, -1, 0 },
};

/* Original address: 0x02034C24 */
AnimFrameData *sEntityToppleFrames[8] = {
    &sEntityMainAnimFrames[0], &sEntityMainAnimFrames[1],
    &sEntityMainAnimFrames[2], &sEntityMainAnimFrames[3],
    &sEntityMainAnimFrames[4], &sEntityMainAnimFrames[5],
    &sEntityMainAnimFrames[6], &sEntityMainAnimFrames[7],
};

/* Original address: 0x02034C44 */
AnimFrameData *sEntityLeafFrames[20] = {
    &sEntityMainAnimFrames[8], &sEntityMainAnimFrames[9],
    &sEntityMainAnimFrames[10], &sEntityMainAnimFrames[11],
    &sEntityMainAnimFrames[12], &sEntityMainAnimFrames[13],
    &sEntityMainAnimFrames[14], &sEntityMainAnimFrames[15],
    &sEntityMainAnimFrames[16], &sEntityMainAnimFrames[17],
    &sEntityMainAnimFrames[18], &sEntityMainAnimFrames[19],
    &sEntityMainAnimFrames[20], &sEntityMainAnimFrames[21],
    &sEntityMainAnimFrames[22], &sEntityMainAnimFrames[23],
    &sEntityMainAnimFrames[24], &sEntityMainAnimFrames[25],
    &sEntityMainAnimFrames[26], &sEntityMainAnimFrames[27],
};

/* Original address: 0x02034C94 */
AnimFrameData *sEntityReactionAnimation0[5] = {
    &sEntityReactionAnimFrames[0], &sEntityReactionAnimFrames[1],
    &sEntityReactionAnimFrames[2], &sEntityReactionAnimFrames[3],
    &sEntityReactionAnimFrames[14],
};

/* Original address: 0x02034CA8 */
AnimFrameData *sEntityReactionAnimation1[4] = {
    &sEntityReactionAnimFrames[4], &sEntityReactionAnimFrames[5],
    &sEntityReactionAnimFrames[6], &sEntityReactionAnimFrames[14],
};

/* Original address: 0x02034CB8 */
AnimFrameData *sEntityReactionAnimation2[3] = {
    &sEntityReactionAnimFrames[7], &sEntityReactionAnimFrames[8],
    &sEntityReactionAnimFrames[14],
};

/* Original address: 0x02034CC4 */
AnimFrameData *sEntityReactionAnimation3[5] = {
    &sEntityReactionAnimFrames[9], &sEntityReactionAnimFrames[10],
    &sEntityReactionAnimFrames[11], &sEntityReactionAnimFrames[12],
    &sEntityReactionAnimFrames[14],
};

/* Original address: 0x02034CD8 */
AnimFrameData *sEntityReactionAnimation4[2] = {
    &sEntityReactionAnimFrames[13], &sEntityReactionAnimFrames[14],
};

/* Original address: 0x02034CE0 */
AnimFrameData **sEntityReactionAnimations[ENTITY_REACTION_COUNT] = {
    sEntityReactionAnimation0,
    sEntityReactionAnimation1,
    sEntityReactionAnimation2,
    sEntityReactionAnimation3,
    sEntityReactionAnimation4,
};

/* Original address: 0x02034CF4 */
ItemGeneratorDef gItemGeneratorDefs[ITEM_GENERATOR_COUNT] = {
    { ITM_FOOD_APPLE,      ITEM_TYPE_APPLE, 0 }, // ITEM_GENERATOR_APPLE
    { ITM_FOOD_ORANGE,     ITEM_TYPE_ORANGE, 0 }, // ITEM_GENERATOR_ORANGE
    { ITM_FOOD_PEACH,      ITEM_TYPE_PEACH, 0 }, // ITEM_GENERATOR_PEACH
    { ITM_FOOD_PEAR,       ITEM_TYPE_PEAR, 0 }, // ITEM_GENERATOR_PEAR
    { ITM_FOOD_CHERRY,     ITEM_TYPE_CHERRY, 0 }, // ITEM_GENERATOR_CHERRY
    { ITM_FOOD_COCONUT,    ITEM_TYPE_COCONUT, 0 }, // ITEM_GENERATOR_COCONUT
    { ITM_FOOD_MUSHROOM,   ITEM_TYPE_MUSHROOM, 0 }, // ITEM_GENERATOR_MUSHROOM
    { ITM_FOOD_CANDY,      ITEM_TYPE_CANDY, 0 }, // ITEM_GENERATOR_CANDY
    { ITM_MONEY_100,       ITEM_TYPE_100_BELLS, 0 }, // ITEM_GENERATOR_100_BELLS
    { ITM_MONEY_1000,      ITEM_TYPE_1K_BELLS, 0 }, // ITEM_GENERATOR_1K_BELLS
    { ITM_MONEY_10000,     ITEM_TYPE_10K_BELLS, 0 }, // ITEM_GENERATOR_10K_BELLS
    { ITM_MONEY_30000,     ITEM_TYPE_30K_BELLS, 0 }, // ITEM_GENERATOR_30K_BELLS
    { ITM_PITFALL,         ITEM_TYPE_PITFALL, 0 }, // ITEM_GENERATOR_PITFALL
    { FLOWER_COSMOS1,      ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_PURPLE_COSMOS
    { FLOWER_COSMOS2,      ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_BLUE_COSMOS
    { FLOWER_COSMOS0,      ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_YELLOW_COSMOS
    { FLOWER_TULIP0,       ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_RED_TULIPS
    { FLOWER_TULIP1,       ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_WHITE_TULIPS
    { FLOWER_TULIP2,       ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_YELLOW_TULIPS
    { FLOWER_PANSIES0,     ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_WHITE_PANSIES
    { FLOWER_PANSIES1,     ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_PURPLE_PANSIES
    { FLOWER_PANSIES2,     ITEM_TYPE_FLOWER_BAG, 0 }, // ITEM_GENERATOR_YELLOW_PANSIES
    { 0x0000,              ITEM_TYPE_FURNITURE, 1 }, // ITEM_GENERATOR_FURNITURE_COMMON
    { 0x0001,              ITEM_TYPE_FURNITURE, 1 }, // ITEM_GENERATOR_FURNITURE_RARE
    { 0x0002,              ITEM_TYPE_FURNITURE, 1 }, // ITEM_GENERATOR_FURNITURE_EVENT
    { 0x0003,              ITEM_TYPE_FURNITURE, 1 }, // ITEM_GENERATOR_FURNITURE_ISLAND
    { 0x0009,              ITEM_TYPE_CARPET, 1 }, // ITEM_GENERATOR_CARPET_COMMON
    { 0x000A,              ITEM_TYPE_CARPET, 1 }, // ITEM_GENERATOR_CARPET_RARE
    { 0x000B,              ITEM_TYPE_WALLPAPER, 1 }, // ITEM_GENERATOR_WALLPAPER_COMMON
    { 0x000C,              ITEM_TYPE_WALLPAPER, 1 }, // ITEM_GENERATOR_WALLPAPER_RARE
    { 0x000D,              ITEM_TYPE_SHIRT, 1 }, // ITEM_GENERATOR_SHIRT_COMMON
    { 0x000E,              ITEM_TYPE_SHIRT, 1 }, // ITEM_GENERATOR_SHIRT_RARE
    { 0x0005,              ITEM_TYPE_FOSSIL, 1 }, // ITEM_GENERATOR_FOSSIL
    { 0x0007,              ITEM_TYPE_GYROID, 1 }, // ITEM_GENERATOR_GYROID
    { 0x0008,              ITEM_TYPE_UMBRELLA, 1 }, // ITEM_GENERATOR_UMBRELLA
    { 0x0006,              ITEM_TYPE_AIR_CHECK, 1 }, // ITEM_GENERATOR_AIR_CHECK
    { 0x0004,              ITEM_TYPE_NES, 1 }, // ITEM_GENERATOR_NES
    { 0x0011,              ITEM_TYPE_TRASH, 1 }, // ITEM_GENERATOR_TRASH
};

/**
 * Restores an entity slot to its default inactive state.
 *
 * Original address: 0x02024F08
 */
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
    entity->anim_id = ENTITY_ANIM_ITEM;
    entity->lifetime = 10;
    entity->sprite_tile = 0;
    entity->palette = 0;
    entity->reaction_type = ENTITY_REACTION_QUESTION;
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

/**
 * Resolves a dropped item and writes it to the field and tilemap.
 *
 * Original address: 0x02024F8C
 */
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
        field->fg_tiles[0][tile_idx] = entity->item_type_indices[0] | FIELD_ITEM_TYPE_SPECIAL_FLAG;
        tilemap = (u16 *)BG_SCREEN_ADDR(24);
        tilemap += (tile_idx & 0xF0) * 4;
        tilemap += (tile_idx & 0xF) * 2;
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
    } else {
        field->fg_tiles[1][tile_idx] = entity->item_type_indices[0] | FIELD_ITEM_TYPE_SPECIAL_FLAG;
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

/**
 * Counts down an entity's lifetime and deactivates it at zero.
 *
 * Original address: 0x020250B0
 */
void Entity_UpdateLifetime(s32 entity_index) {
    IslandFieldWork *field = &gIslandFieldWork;
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->lifetime == 0) {
        field->entity_active[entity_index + 3] = 0;
    } else {
        entity->lifetime--;
    }
}

/**
 * Starts the eight-frame topple animation.
 *
 * Original address: 0x020250EC
 */
void Entity_BeginToppleEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityToppleFrames[0]->duration;
    entity->anim_id = ENTITY_ANIM_TOPPLE;
    entity->update_type = 2;
}

/**
 * Advances the topple animation and deactivates it after its last frame.
 *
 * Original address: 0x02025118
 */
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

/**
 * Starts the leaf particle animation.
 *
 * Original address: 0x02025180
 */
void Entity_BeginLeafEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->anim_timer = sEntityLeafFrames[0]->duration;
    entity->anim_id = ENTITY_ANIM_LEAF;
    entity->update_type = 4;
}

/**
 * Advances the leaf animation and deactivates it after its last frame.
 *
 * Original address: 0x020251AC
 */
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

/**
 * Starts the selected reaction glyph animation and its sound effect.
 *
 * Original address: 0x02025210
 */
void Entity_BeginReactionEffect(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];
    AnimFrameData *frame = sEntityReactionAnimations[entity->reaction_type][0];

    switch (entity->reaction_type) {
    case ENTITY_REACTION_QUESTION:
        Sound_PlayEffect0(5);
        break;
    case ENTITY_REACTION_SWEAT:
        Sound_PlayEffect0(6);
        break;
    case ENTITY_REACTION_EXCLAMATION:
        Sound_PlayEffect0(7);
        break;
    case ENTITY_REACTION_MUSIC_NOTE:
        Sound_PlayEffect0(8);
        break;
    case ENTITY_REACTION_SLEEP:
        break;
    }
    entity->anim_timer = frame->duration;
    entity->frame_index = 0;
    entity->anim_id = ENTITY_ANIM_REACTION;
    entity->update_type = 6;
}

/**
 * Advances a reaction glyph animation until its sentinel frame.
 *
 * Original address: 0x0202529C
 */
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

/**
 * Initializes an item dropped onto the field with an upward velocity.
 *
 * Original address: 0x02025310
 */
void Entity_BeginItemDrop(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    entity->precise_x = entity->x << 8;
    entity->base_y = entity->y << 8;
    entity->height_offset = 0;
    entity->vertical_velocity_or_x_limit = 0x200;
    entity->vertical_acceleration_or_bob_velocity = 0x20;
    Sound_PlayEffect0(30);
    entity->anim_id = ENTITY_ANIM_ITEM;
    entity->update_type = 8;
}

/**
 * Applies gravity to a dropped item and places it after it lands.
 *
 * Original address: 0x02025354
 */
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

/**
 * Initializes a rotating, bobbing floating-item entity.
 *
 * Original address: 0x020253A8
 */
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
    entity->anim_id = ENTITY_ANIM_ITEM;
    entity->update_type = 10;
}

/**
 * Moves and animates a floating item until it is collected or leaves view.
 *
 * Original address: 0x02025400
 */
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
    wave = gSineTable[entity->bob_phase];
    entity->vertical_acceleration_or_bob_velocity = wave >> 2;
    if (wave & 0x8000) {
        entity->vertical_acceleration_or_bob_velocity |= 0xFFFF0000;
    }
    entity->bob_phase = (entity->bob_phase + 4) & 0xFF;
    if (entity->bob_phase == 0) {
        entity->vertical_acceleration_or_bob_velocity = 0;
    }
}

/**
 * Dispatches the current update procedure for an entity slot.
 *
 * Original address: 0x020255F0
 */
void Entity_Update(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    sEntityUpdateProcs[entity->update_type](entity_index);
}

/**
 * Draws the small shadow beneath a floating item.
 *
 * Original address: 0x02025618
 */
void Entity_DrawFloatingItemShadow(s32 entity_index) {
    Entity *entity = &g_EntityTable[entity_index];

    if (entity->update_type == 10) {
        GameState *game = &gGameState;
        OAMData *oam = &GameOAMData[game->oam_count];
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

/**
 * Draws an entity as either an animation frame or an item sprite.
 *
 * Original address: 0x020256D0
 */
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
    case ENTITY_ANIM_TOPPLE:
        frame = sEntityToppleFrames[entity->frame_index];
        break;
    case ENTITY_ANIM_LEAF:
        frame = sEntityLeafFrames[entity->frame_index];
        break;
    case ENTITY_ANIM_REACTION:
        frame = sEntityReactionAnimations[entity->reaction_type][entity->frame_index];
        break;
    }
    if (entity->anim_id != ENTITY_ANIM_ITEM) {
        sprite = frame->sprite_gfx_p;
        for (i = 0; i < 12 && sprite->affine_param != 0xFFFF; i++, sprite++) {
            oam = &GameOAMData[gGameState.oam_count];
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
        oam = &GameOAMData[gGameState.oam_count];
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
            GameOAMData[4].affine_param = matrix.pa;
            GameOAMData[5].affine_param = matrix.pb;
            GameOAMData[6].affine_param = matrix.pc;
            GameOAMData[7].affine_param = matrix.pd;
        }
    }
}
