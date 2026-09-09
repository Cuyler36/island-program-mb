#include "islander.h"
#include "lib.h"
#include "sound.h"
#include "island_field.h"
#include "building.h"
#include "entity.h"
#include "player_hand.h"

/* Maps an item type and Islander emotion to a base in the buried-item RNG table. */
typedef struct BuriedItemRngTileGroup {
    u16 item_type;
    u16 generator_table_offsets[4];
} __attribute__((packed, aligned(2))) BuriedItemRngTileGroup;

typedef struct BuriedItemUpdateGroup {
    u16 item_type;
    mActor_name_t buried_item;
} BuriedItemUpdateGroup;

/* Original address: 0x02033DC8 */
extern u8 sFloatingItemHourOffsets[24];
/* Original address: 0x02033DE4 */
extern u16 sFloatingItemBaseIndices[18 * 7];
/* Original address: 0x02033F92 */
extern u8 sIslanderRewardAdjust[18];
/* Original address: 0x03000020 */
extern s32 sFloatingItemIndex;
/* Original address: 0x02033FA4 */
extern u8 gIslanderFavoriteHours[18];
extern BuriedItemUpdateGroup gBuriedItemUpdateGroups[6];
/* Original address: 0x020338C4 */
extern u16 sIslanderMoodEmotions[7];
extern BuriedItemRngTileGroup gBuriedItemRngTileGroups[13];
extern u8 gBuriedItemGeneratorIndices[0x120];
/* Original address: 0x02033F80 */
extern mActor_name_t sIslanderFlowerItems[9];

extern EntitySpawnParams gMoveAction11EntitySpawnParams[39];
extern u8 gMoveAction11ObjectAnimFrames[9];
extern u8 gMoveAction11EmotionSpawnOffsets[4];

/* Original address: 0x0201EFB8 */
s32 Islander_StoreItem(u16 item_type, u16 generator_idx) {
    Islander_AGB *islander = &gIslander;
    ItemGroupStruct *definition = &g_ItemDefinitions[item_type];
    mActor_name_t *stored_item;
    u16 *stored_type_plus_one;
    s32 slot;
    ItemGeneratorDef *generator;

    islander->held_item_sprite = 0x800000;
    islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;
    if (definition->interaction_type != 4) {
        slot = 0;
        stored_item = islander->stored_item_ids;
        stored_type_plus_one = islander->stored_item_type_plus_one;
        do {
            if (*stored_type_plus_one == 0) {
                *stored_type_plus_one = item_type + 1;
                generator = &gItemGeneratorDefs[generator_idx];
                if (generator->use_island_id == 0) {
                    *stored_item = generator->item;
                } else {
                    *stored_item = Item_TypeToIslandItem(generator->item);
                }
                return 1;
            }
            stored_item++;
            stored_type_plus_one++;
            slot++;
        } while (slot < 5);
    }
    return 0;
}

/* Original address: 0x020338FC */
extern u16 sFishingRewardGeneratorIndices[64];

/* Original address: 0x0203397C */
extern u16 sFishingRewardItemTypes[64];

static inline u16 FishingSpecialCatchAttr2(u16 generator_idx) {
    if (generator_idx == 0x7F) {
        return 0x434E;
    } else {
        return 0x4350;
    }
}

/* Original address: 0x0201F030 */
s16 Islander_GetFishingItem(void) {
    Islander_AGB *islander = &gIslander;
    ItemGroupStruct *definition;
    s32 reward_idx;
    u16 generator_idx;
    u16 item_attr2;
    u32 item_flags;

    reward_idx = (islander->emotion & 3) * 16;
    if ((islander->equipped_tool_state & 0xF) == 8) {
        reward_idx += 8;
    }
    reward_idx = (reward_idx + rand_u16(&gGameState) % 8) & 0x3F;
    generator_idx = sFishingRewardGeneratorIndices[reward_idx];
    if ((u16)(generator_idx - 0x7E) > 1) {
        if (generator_idx != 0x25 && islander->stored_item_type_plus_one[4] != 0) {
            definition = &g_ItemDefinitions[sFishingRewardItemTypes[reward_idx]];
            item_flags = 0x800000;
            islander->held_item_sprite = item_flags;
            item_attr2 = definition->held_item_oam_attr2;
        } else {
            Islander_StoreItem(sFishingRewardItemTypes[reward_idx], sFishingRewardGeneratorIndices[reward_idx]);
            return 0;
        }
    } else {
        item_flags = 0x800000;
        islander->held_item_sprite = item_flags;
        item_attr2 = FishingSpecialCatchAttr2(generator_idx);
    }
    islander->held_item_sprite = item_attr2 | item_flags;
    return 0xFE;
}

/* Try mirrored approach tiles; save the dig tile and both movement waypoints. */
/* Original address: 0x0201F0FC */
s32 Islander_SetupDigApproach(u8 tile_offset) {
    u16 *right_tiles;
    u16 *left_tiles;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 items[2];
    u8 tile = islander->tile_idx;
    u8 row = (tile & 0xF0) + (tile_offset & 0xF0);
    u32 right_tile = row;
    u32 left_tile = row;
    u16 *right_info;
    u16 *left_info;
    u32 right_row;
    u32 right_col;
    u16 tile_id;

    right_tile |= ((tile & 0xF) + (tile_offset & 0xF)) & 0xF;
    left_tile |= ((tile & 0xF) - (tile_offset & 0xF)) & 0xF;
    islander->interaction_tile = 0;
    islander->next_target_x = 0;
    if ((islander->x & 0xFF0000) == 0) {
        right_tiles = (u16 *)BG_SCREEN_ADDR(20);
        items[0] = field->fg_tiles[0][right_tile];
        if ((tile & 0xF) > (right_tile & 0xF)) {
            right_tiles = (u16 *)BG_SCREEN_ADDR(21);
            items[0] = field->fg_tiles[1][right_tile];
        }
        left_tiles = (u16 *)BG_SCREEN_ADDR(20);
        items[1] = field->fg_tiles[0][left_tile];
    } else {
        islander->interaction_tile = 0x8000;
        right_tiles = (u16 *)BG_SCREEN_ADDR(21);
        items[0] = field->fg_tiles[1][right_tile];
        left_tiles = (u16 *)BG_SCREEN_ADDR(21);
        items[1] = field->fg_tiles[1][left_tile];
        if ((tile & 0xF) < (left_tile & 0xF)) {
            left_tiles = (u16 *)BG_SCREEN_ADDR(20);
            items[1] = field->fg_tiles[0][left_tile];
        }
    }
    islander->interaction_tile |= islander->tile_idx;
    right_row = right_tile & 0xF0;
    right_col = right_tile & 0xF;
    right_tiles += right_row * 4;
    right_tiles += right_col * 2;
    right_info = right_tiles;
    left_tiles += (left_tile & 0xF0) * 4;
    left_info = left_tiles + (left_tile & 0xF) * 2;
    if (CheckSurroundingCollision(items[0], right_info) != 0 ||
        (tile_id = *right_info & 0x3FF) <= 5 ||
        (u16)(tile_id - 0x10) <= 5 || tile_id > 0xAF) {
        if (CheckSurroundingCollision(items[1], left_info) != 0 ||
            (tile_id = *left_info & 0x3FF) <= 5 ||
            (u16)(tile_id - 0x10) <= 5 || tile_id > 0xAF) {
            islander->interaction_tile = 0;
            return 0;
        }
        if ((u32)left_info & 0x800) {
            islander->next_target_x = 0x10000;
        }
        islander->target_action = 0x70;
        islander->target_x = islander->x & 0xFF0000;
        islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
        islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
        islander->next_target_x |= ((left_tile & 0xF) << 12) + 0x800;
        islander->next_target_y = ((left_tile & 0xF0) << 8) + 0x800;
        return left_tile;
    }
    if ((u32)right_info & 0x800) {
        islander->next_target_x = 0x10000;
    }
    islander->target_action = 0x60;
    islander->target_x = islander->x & 0xFF0000;
    islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
    islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
    islander->next_target_x |= (right_col << 12) + 0x800;
    islander->next_target_y = (right_row << 8) + 0x800;
    return right_tile;
}

/* Original address: 0x02033A1C */
extern int collision_check_offsets[4];

/* Original address: 0x0201F368 */
s32 Islander_CanDigHere(void) {
    Islander_AGB *islander = &gIslander;
    u8 *tilemap;
    u32 row_address;
    s32 i;

    Islander_UpdateCollisionTiles(islander->direction);
    for (i = 0; i < 4; i++) {
        if (CheckSurroundingCollision(islander->surrounding_item_types[i], islander->collision_tilemap) != 0) {
            return 0;
        }
        if ((islander->x & 0xFF0000) == 0) {
            tilemap = (u8 *)BG_SCREEN_ADDR(20);
            row_address = (islander->tile_idx & 0xF0) * 8;
            row_address += (u32)tilemap;
            tilemap = (u8 *)row_address;
            tilemap += (islander->tile_idx & 0xF) * 4;
        } else {
            tilemap = (u8 *)BG_SCREEN_ADDR(21);
            row_address = (islander->tile_idx & 0xF0) * 8;
            row_address += (u32)tilemap;
            tilemap = (u8 *)row_address;
            tilemap += (islander->tile_idx & 0xF) * 4;
        }
        if ((u16)((*(u16 *)(tilemap + collision_check_offsets[i]) & 0x3FF) - 0x20) > 0x5E) {
            return 0;
        }
    }
    return 1;
}

static inline IslanderDirectionSector *Islander_GetDirectionSector(u16 angle) {
    IslanderDirectionSector *sectors = &gIslanderDirectionSectors[7];
    s32 sector_idx;
    if (angle < sectors->max_angle) {
        sector_idx = 0;
        sectors -= 7;
        for (sector_idx = 0; sector_idx < 7; sector_idx++) {
            if (angle <= sectors[sector_idx].max_angle) {
                break;
            }
        }
    } else {
        sector_idx = 0;
        sectors -= 7;
    }
    return &sectors[sector_idx];
}

/* Original address: 0x0201F3F8 */
s32 Islander_ChangeMoveDir(s32 target_x, s32 target_y, u8 move_mode) {
    Islander_AGB *islander = &gIslander;
    u8 old_direction;
    u16 angle;
    u8 direction;
    u8 direction_diff;
    IslanderDirectionSector *sectors;

    islander->work_x = target_x - islander->x;
    islander->work_y = target_y - islander->y;
    if (islander->work_x < 0) {
        islander->work_x = -islander->work_x;
    }
    if (islander->work_y < 0) {
        islander->work_y = -islander->work_y;
    }
    if (islander->work_x <= 0x100 && islander->work_y <= 0x100) {
        return 1;
    }

    islander->work_x = (target_x - islander->x) >> 8;
    islander->work_y = (target_y - islander->y) >> 8;
    old_direction = islander->direction;
    switch (move_mode) {
    case 0:
        if (Islander_MoveTowardX(0, target_x)) {
            Islander_MoveTowardY(0, target_y);
            islander->work_x = 0;
        } else {
            islander->work_y = 0;
        }
        break;
    case 1:
        if (Islander_MoveTowardY(0, target_y)) {
            Islander_MoveTowardX(0, target_x);
            islander->work_y = 0;
        } else {
            islander->work_x = 0;
        }
        break;
    default:
        Islander_MoveTowardX(1, target_x);
        Islander_MoveTowardY(1, target_y);
        angle = ArcTan2((s16)islander->work_x, (s16)islander->work_y);
        sectors = Islander_GetDirectionSector(angle);
        direction_diff = islander->direction - sectors->direction;
        direction = sectors->direction;
        if (direction_diff & 0x80) {
            direction_diff = ~direction_diff;
            direction_diff++;
        }
        if ((u8)(direction_diff - 2) <= 4) {
            islander->direction = direction;
        }
    }
    if (islander->direction != old_direction) {
        Islander_AdjustAnimForTool();
    }
    return 0;
}

/* Original address: 0x020339FC */
extern s32 sIslanderCollisionSampleOffsets[8];

/* Original address: 0x0201F538 */
void Islander_UpdateCollisionTiles(u8 direction) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 y = (islander->y >> 8) & 0xFF0;
    s32 x = (islander->x >> 8) & 0xFF0;
    s32 i;
    u8 tile_idx;
    s32 terrain_tile_idx;
    u16 *tilemap;
    u32 row_address;

    /* The direction argument is unused in the original routine. */
    tile_idx = y;
    tile_idx |= (x & 0xF0) >> 4;
    islander->tile_idx = tile_idx;
    for (i = 0; i < 4; i++) {
        x = islander->x + sIslanderCollisionSampleOffsets[(u8)(i * 2)];
        y = islander->y + sIslanderCollisionSampleOffsets[(u8)(i * 2 + 1)];
        tile_idx = (y >> 8) & ~0xF;
        tile_idx |= ((x >> 8) & 0xF0) >> 4;
        if ((x & 0xFF0000) == 0) {
            islander->surrounding_tile_indices[i] = tile_idx;
            islander->surrounding_item_types[i] = field->fg_tiles[0][tile_idx];
        } else {
            islander->surrounding_tile_indices[i] = tile_idx;
            islander->surrounding_item_types[i] = field->fg_tiles[1][tile_idx];
        }
    }
    islander->work_x = islander->x - 0x200;
    islander->work_y = islander->y + 0x200;
    y = (islander->work_y >> 8) & 0xFF0;
    x = (islander->work_x >> 8) & 0xFF0;
    terrain_tile_idx = y | ((x & 0xF0) >> 4);
    islander->terrain_tile_idx = terrain_tile_idx;
    if ((islander->work_x & 0xFF0000) == 0) {
        tilemap = (u16 *)BG_SCREEN_ADDR(20);
        row_address = (terrain_tile_idx & 0xF0) * 8;
        row_address += (u32)tilemap;
        tilemap = (u16 *)row_address;
        tilemap += (terrain_tile_idx & 0xF) * 2;
    } else {
        tilemap = (u16 *)BG_SCREEN_ADDR(21);
        row_address = (terrain_tile_idx & 0xF0) * 8;
        row_address += (u32)tilemap;
        tilemap = (u16 *)row_address;
        tilemap += (terrain_tile_idx & 0xF) * 2;
    }
    islander->collision_tilemap = tilemap;
}

/* Original address: 0x0201F660 */
void WriteItemToTile(s32 x, u8 tile_idx, u16 item, u16 item_tile) {
    u16 *tilemap_vram;

    if ((x & 0xFF0000) == 0) {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
    } else {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
    }

    tilemap_vram += (tile_idx & 0xF0) * 4;
    tilemap_vram += (tile_idx & 0xF) * 2;
    WriteItemTileToVRAM(tilemap_vram, item_tile);
}

static inline s32 HasSurroundingTileCollision(u16 *tile_info) {
    int i;

    for (i = 0; i < ARRAY_COUNT(collision_check_offsets); i++) {
        u32 tile = *(u16*)((u8*)tile_info + collision_check_offsets[i]) & 0x3FF;

        if ((i == 1 && tile == 0x096) || (u16)(tile - 0xB0) < 6 || (u16)(tile - 0xC0) < 0x16 || (u16)(tile - 0xE0) < 0x320) {
            return 1;
        }
    }

    return 0;
}

/* Original address: 0x0201F6DC */
s32 CheckSurroundingCollision(u16 main_tile, u16 *tile_info) {
    if (!HasSurroundingTileCollision(tile_info)) {
        if ((u16)(main_tile - 0x1F) < 2 || (u16)(main_tile - 0x22) < 4 || (u16)(main_tile - 0x27) < 9 || (u16)(main_tile - 0x31) < 4 || (u16)(main_tile - 0x36) < 7 || main_tile == 0x41) {
            return 1;
        }
    } else {
        return 2;
    }

    return 0;
}

/* Original address: 0x0201F78C */
s32 Islander_ChooseNewMoveDirection(u8 allow_reverse) {
    Islander_AGB *islander = &gIslander;
    s32 direction;
    s32 count;

    for (direction = 0; direction < 8; direction++) {
        islander->blocked_directions[direction] = 0;
        islander->direction_candidates[direction] = 0xFF;
    }

    islander->blocked_directions[islander->direction] = 1;
    if (allow_reverse == 0) {
        direction = islander->direction + 4;
        if (direction > 7) {
            direction = islander->direction - 4;
        }
        islander->blocked_directions[direction] = 1;
    }

    for (direction = 0; direction < 8; direction++) {
        if (islander->blocked_directions[direction] == 0 && Islander_CanMoveInDirection(direction) == 0) {
            islander->blocked_directions[direction] = 1;
        }
    }

    direction = 0;
    count = 0;
    for (; direction < 8; direction++) {
        if (islander->blocked_directions[direction] == 0) {
            islander->direction_candidates[count] = direction;
            count++;
        }
    }

    if (count == 0) {
        return 0x777;
    } else {
        direction = islander->direction_candidates[rand_u16(&gGameState) % count];
        return direction;
    }
}

/* Original address: 0x02033A2C */
extern s32 gIslanderMoveCollisionOffsets[16];

/* Original address: 0x0201F844 */
s32 Islander_CanMoveInDirection(u8 direction) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 offset_idx;
    s32 x = islander->x + gIslanderMoveCollisionOffsets[offset_idx = direction * 2];
    s32 y_offset = gIslanderMoveCollisionOffsets[offset_idx + 1] + 0x800;
    s32 y = islander->y + y_offset;
    u8 tile = (y >> 8) & ~0xF;
    u16 *tilemap;
    u32 row_address;

    tile |= (x >> 12) & 0xF;
    if ((x & 0xFF0000) == 0) {
        islander->surrounding_item_types[0] = field->fg_tiles[0][tile];
        tilemap = (u16 *)BG_SCREEN_ADDR(20);
    } else {
        islander->surrounding_item_types[0] = field->fg_tiles[1][tile];
        tilemap = (u16 *)BG_SCREEN_ADDR(21);
    }
    row_address = (tile & 0xF0) * 8;
    row_address += (u32)tilemap;
    tilemap = (u16 *)row_address;
    tilemap += (tile & 0xF) * 2;
    islander->collision_tilemap = tilemap;
    if (CheckSurroundingCollision(islander->surrounding_item_types[0], tilemap) != 0) {
        return 0;
    } else {
        return 1;
    }
}

/* Original address: 0x0201F8FC */
void Islander_BuryRandomItem(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    BuriedItemUpdateGroup *buried_item_update;
    ItemGeneratorDef *generator_def;
    ItemGroupStruct *item_definition;
    mActor_name_t buried_item;
    u8 tile_idx = islander->interaction_tile;
    s32 group_idx;

    for (group_idx = 0; group_idx < ARRAY_COUNT(gBuriedItemRngTileGroups); group_idx++) {
        if (item_type == ((u16 *)gBuriedItemRngTileGroups)[(u8)(group_idx * 5)]) {
            item_type = ((u16 *)gBuriedItemRngTileGroups)[(u8)((group_idx * 5) + 1 + islander->emotion)];
            break;
        }
    }

    if (group_idx >= ARRAY_COUNT(gBuriedItemRngTileGroups)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }
    if ((islander->equipped_tool_state & 0xF) == 7) {
        item_type += 0x10;
    }

    item_type += rand_u16(&gGameState) % 4;
    if (item_type >= 0x120) {
        item_type = 0;
    }

    item_type = gBuriedItemGeneratorIndices[item_type];
    generator_def = &gItemGeneratorDefs[item_type];
    item_definition = &g_ItemDefinitions[generator_def->item_type];

    if ((item_definition->default_generator_idx == 0xFFF) || (item_type == 0xD)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }

    islander->held_item_sprite = item_definition->held_item_oam_attr2 | 0x800000;

    if (IS_ITEM_TYPE_FRUIT(generator_def->item_type)) {
        islander->buried_item_tile_base = 0x3260;
        if (generator_def->item_type == ITEM_TYPE_COCONUT) {
            islander->buried_item_tile_base = 0x3268;
        }

        for (group_idx = 0; group_idx < 6; group_idx++) {
            buried_item_update = &gBuriedItemUpdateGroups[group_idx];
            if (buried_item_update->item_type == generator_def->item_type) {
                break;
            }
        }

        if ((islander->interaction_tile & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = 0x7777;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[0][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = 0x7777;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[1][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        }
    } else {
        islander->buried_item_tile_base = 0x1270;
        if (generator_def->use_island_id == 0) {
            buried_item = generator_def->item;
        } else {
            buried_item = Item_TypeToIslandItem(generator_def->item);
        }

        if ((islander->interaction_tile & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[0][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[1][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        }
    }
}

/* Original address: 0x0201FB9C */
void Islander_PlantRandomFlower(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 tile_idx = islander->interaction_tile;
    u8 flower;

    islander->held_item_sprite = 0x800000;
    flower = rand_u16(&gGameState) % 9;
    islander->held_item_sprite |= 0x5344;
    if ((islander->interaction_tile & 0x8000) == 0) {
        field->fg_tiles[0][tile_idx] = 0x7777;
        gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = sIslanderFlowerItems[flower];
        gIslandData->deposit[0][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
    } else {
        field->fg_tiles[1][tile_idx] = 0x7777;
        gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = sIslanderFlowerItems[flower];
        gIslandData->deposit[1][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
    }
    islander->buried_item_tile_base = (g_ItemDefinitions + ITEM_TYPE_PURPLE_COSMOS)[flower].field_tile_id;
}

/* Original address: 0x0201FCB0 */
void Islander_UpdateBlink(void) {
    Islander_AGB *islander = &gIslander;
    u8 direction = islander->direction;

    if ((direction == 0 || direction == 2 || direction == 1 || direction == 6 || direction == 7) && islander->emotion == 0) {
        if (islander->blink_timer == 0) {
            islander->blink_frame = (islander->blink_frame + 1) & 1;
            if (islander->blink_frame == 0) {
                islander->blink_timer = rand_u16(&gGameState) % 65 + 0x20;
            } else {
                islander->blink_timer = 4;
            }
        }
        islander->blink_timer--;
    }
}

static inline s32 Islander_FindDirectionSector(u16 angle) {
    s32 sector;
    IslanderDirectionSector *sectors = &gIslanderDirectionSectors[7];

    if (angle < sectors->max_angle) {
        sectors = gIslanderDirectionSectors;
        for (sector = 0; sector < 7; sector++) {
            if (angle <= sectors[sector].max_angle) {
                break;
            }
        }
    } else {
        sector = 0;
    }
    return sector;
}

/* Original address: 0x0201FD1C */
s32 Islander_FaceTargetAndCheckArrival(s32 target_x, s32 target_y) {
    Islander_AGB *islander = &gIslander;
    u16 angle;
    s32 sector;
    s32 tile_y;

    islander->work_x = (target_x - islander->x) >> 8;
    islander->work_y = (target_y - islander->y) >> 8;
    angle = ArcTan2(islander->work_x, islander->work_y);
    sector = Islander_FindDirectionSector(angle);
    if (islander->direction_change_cooldown_timer == 0) {
        if (gIslanderDirectionSectors[sector].direction != islander->direction) {
            islander->direction = gIslanderDirectionSectors[sector].direction;
            Islander_AdjustAnimForTool();
            islander->direction_change_cooldown_timer = 0x20;
        }
    }
    if (islander->work_x < 0) {
        islander->work_x = -islander->work_x;
    }
    if (islander->work_y < 0) {
        islander->work_y = -islander->work_y;
    }
    if (islander->work_x <= 1 && islander->work_y <= 1) {
        tile_y = (islander->y >> 8) & 0xFF0;
        islander->work_y = tile_y;
        islander->work_x = (islander->x >> 8) & 0xFF0;
        islander->tile_idx = tile_y;
        islander->tile_idx = ((islander->work_x & 0xF0) >> 4) | tile_y;
        return 1;
    }
    return 0;
}

/* Original address: 0x0201FDF4 */
s32 Islander_PlayAnim(u8 stop_at_end) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *frame;

    islander->anim_timer--;
    if (islander->anim_timer & 0x80) {
        islander->anim_frame++;
        frame = gIslanderAnimData[islander->anim_id][islander->anim_frame];
        if ((u8)frame->action_flag == 0xFF) {
            islander->anim_frame = 0;
            if (stop_at_end == 1) {
                return 1;
            }
        }
        frame = gIslanderAnimData[islander->anim_id][islander->anim_frame];
        islander->anim_timer = frame->duration;
    }
    return 0;
}

/* Original address: 0x0201FE6C */
void Islander_ClearStoredItem(s32 index) {
    Islander_AGB *islander = &gIslander;
    s32 i;

    islander->stored_item_type_plus_one[index] = 0;
    islander->stored_item_ids[index] = 0;
    for (i = index; i < 4; i++) {
        if (islander->stored_item_type_plus_one[i] == 0 && islander->stored_item_ids[i] == 0) {
            islander->stored_item_type_plus_one[i] = islander->stored_item_type_plus_one[i + 1];
            islander->stored_item_ids[i] = islander->stored_item_ids[i + 1];
            islander->stored_item_type_plus_one[i + 1] = 0;
            islander->stored_item_ids[i + 1] = 0;
        }
    }
}

/* Original address: 0x0201FED4 */
s32 Islander_SpawnReactionEffect(u8 effect, u8 duration) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    Entity *entity;

    for (i = 3; i < 12; i++) {
        if (field->entity_active[i + 3] == 0) {
            entity = &g_EntityTable[i];
            field->entity_active[i + 3] = 1;
            Entity_Reset(i);
            entity->lifetime = duration;
            entity->reaction_type = effect;
            entity->update_type = 5;
            entity->x = islander->x >> 8;
            entity->y = islander->y >> 8;
            return 1;
        }
    }
    return 0;
}

static inline u16 Islander_GetTerrainTile(u16 *tilemap) {
    return *tilemap & 0x3FF;
}

/* Original address: 0x0201FF48 */
s32 SpawnEntity(u8 spawn_flag, u8 spawn_mode, u16 item_type, u16 item) {
    s32 active_idx;
    s32 entity_idx;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 *tilemap;
    u16 tile;
    u16 terrain_tile;
    u8 tile_idx;
    Entity *entity;
    ItemGroupStruct *definition;

    if (spawn_mode == 0) {
        if (!(islander->x & 0xFF0000)) {
            tile = field->fg_tiles[0][islander->tile_idx];
            if (tile != 0xFFF && tile != 0x3333) {
                return 0;
            }
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
        } else {
            tile = field->fg_tiles[1][islander->tile_idx];
            if (tile != 0xFFF && tile != 0x3333) {
                return 0;
            }
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
        }
        tilemap += (0xF0 & islander->tile_idx) * 4;
        tilemap += (0xF & islander->tile_idx) * 2;
        if (CheckSurroundingCollision(0, tilemap) != 0) {
            return 0;
        }
        terrain_tile = Islander_GetTerrainTile(tilemap);
        if (terrain_tile <= 5U || (u16)(terrain_tile - 0x10) <= 5U || terrain_tile > 0xAFU) {
            return 0;
        }
    }
    if (spawn_mode == 2) {
        spawn_mode = 0;
    }
    for (entity_idx = 3, active_idx = 6; entity_idx < 12; active_idx++, entity_idx++) {
        if (field->entity_active[active_idx] == 0) {
            entity = &g_EntityTable[entity_idx];
            definition = &g_ItemDefinitions[item_type];
            Entity_Reset(entity_idx);
            entity->x = (islander->x >> 8) - 8;
            entity->y = (islander->y >> 8) - 0x10;
            if (spawn_mode == 0) {
                entity->update_type = 7;
            } else {
                entity->update_type = 9;
                islander->floating_balloon_target_entity_id = entity_idx;
            }
            field->entity_active[active_idx] = 1;
            entity->item_type_indices[0] = item_type;
            entity->item_ids[0] = item;
            entity->items_are_resolved = spawn_flag;
            tile_idx = islander->tile_idx;
            entity->landing_tile = tile_idx;
            if (islander->x & 0xFF0000) {
                entity->landing_tile = tile_idx | 0x1000;
            }
            entity->sprite_tile = definition->held_item_oam_attr2 & 0x3FF;
            entity->palette = definition->held_item_oam_attr2 >> 12;
            return entity_idx;
        }
    }
    return 0;
}

/* Original address: 0x02020118 */
s32 Islander_SelectTreeApproach(FieldObject *object, s32 right_x, s32 left_x) {
    Islander_AGB *islander = &gIslander;
    s32 i;
    u8 tile_idx;

    islander->tree_approach_x[0] = right_x;
    islander->tree_approach_x[1] = left_x;
    if (right_x == 0 && left_x == 0) {
        return 0;
    }
    islander->target_y = ((0xF0 & object->tile_idx) << 8) + 0x800;
    islander->item_work.held_item.type_idx = 0;
    if (islander->tree_approach_x[0] != 0 && islander->tree_approach_x[1] != 0) {
        for (i = 0; i < 2; i++) {
            islander->tree_approach_eval[i] = islander->tree_approach_x[i] - islander->x;
            if (islander->tree_approach_eval[i] < 0) {
                islander->tree_approach_eval[i] = 0;
            }
        }
        islander->target_x = islander->tree_approach_x[0] + 0x500;
        islander->target_action = 0x40;
        if (islander->tree_approach_eval[0] > islander->tree_approach_eval[1]) {
            islander->target_x = islander->tree_approach_x[1];
            islander->target_action = 0x30;
            islander->target_x = islander->tree_approach_x[1] + 0xA00;
        }
        islander->next_target_x = 0;
        islander->next_target_y = 0;
    } else {
        islander->target_x = islander->tree_approach_x[0] + 0x500;
        islander->target_action = 0x40;
        if (islander->tree_approach_x[1] != 0) {
            islander->target_x = islander->tree_approach_x[1];
            islander->target_action = 0x30;
            islander->target_x = islander->tree_approach_x[1] + 0xA00;
        }
        islander->next_target_x = islander->target_x;
        islander->next_target_y = islander->target_y;
        islander->target_x -= islander->x;
        if (islander->target_x < 0) {
            islander->target_x = -islander->target_x;
        }
        islander->target_y = islander->next_target_y - islander->y;
        if (islander->target_y < 0) {
            islander->target_y = -islander->target_y;
        }
        if (islander->target_x <= 0xFFF && islander->target_y <= 0xFFF) {
            islander->target_x = islander->next_target_x;
            islander->target_y = islander->next_target_y;
            islander->next_target_x = 0;
            islander->next_target_y = 0;
        } else {
            islander->target_x = 0;
            islander->target_y = 0;
            if (object->layer != 0) {
                islander->target_x = 0x10000;
            }
            if ((object->y << 8) > islander->y) {
                tile_idx = object->tile_idx - 0x10;
                islander->target_x |= ((0xF & tile_idx) << 12) + 0x800;
                islander->target_y = ((tile_idx & 0xF0) << 8) + 0x0FFFF400;
            } else {
                tile_idx = object->tile_idx + 0x10;
                islander->target_x |= ((0xF & tile_idx) << 12) + 0x800;
                islander->target_y = ((tile_idx & 0xF0) << 8) + 0x800;
            }
        }
    }
    return 1;
}

/* Original address: 0x0202029C */
s32 Islander_SetupTreeApproach(FieldObject *object) {
    u16 tile_ids[2];
    u32 tilemap_addresses[2];
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 side;

    islander->tree_approach_eval[0] = (0xF & object->tile_idx) + 1;
    islander->tree_approach_x[0] = islander->tree_approach_eval[0] << 12;
    if (object->layer == 0) {
        tilemap_addresses[0] = BG_SCREEN_ADDR(20);
        tile_ids[0] = field->fg_tiles[0][(0xF0 & object->tile_idx) + islander->tree_approach_eval[0]];
        if (islander->tree_approach_eval[0] == 0x10) {
            islander->tree_approach_eval[0] = 0;
            tilemap_addresses[0] = BG_SCREEN_ADDR(21);
            tile_ids[0] = field->fg_tiles[1][0xF0 & object->tile_idx];
            islander->tree_approach_x[0] = 0x10000;
        }
        islander->tree_approach_eval[0] = (0xF0 & object->tile_idx) + islander->tree_approach_eval[0];
        islander->tree_approach_eval[1] = (0xF & object->tile_idx) - 1;
        islander->tree_approach_x[1] = islander->tree_approach_eval[1] << 12;
        tilemap_addresses[1] = BG_SCREEN_ADDR(20);
        tile_ids[1] = field->fg_tiles[0][(0xF0 & object->tile_idx) + islander->tree_approach_eval[1]];
        islander->tree_approach_eval[1] = (0xF0 & object->tile_idx) + islander->tree_approach_eval[1];
    } else {
        islander->tree_approach_x[0] |= 0x10000;
        islander->tree_approach_x[1] = 0x10000;
        tilemap_addresses[0] = BG_SCREEN_ADDR(21);
        tile_ids[0] = field->fg_tiles[1][(object->tile_idx & 0xF0) + islander->tree_approach_eval[0]];
        islander->tree_approach_eval[0] = (object->tile_idx & 0xF0) + islander->tree_approach_eval[0];
        islander->tree_approach_eval[1] = (0xF & object->tile_idx) - 1;
        islander->tree_approach_x[1] = (islander->tree_approach_eval[1] << 12) | 0x10000;
        tilemap_addresses[1] = BG_SCREEN_ADDR(21);
        tile_ids[1] = field->fg_tiles[1][(object->tile_idx & 0xF0) + islander->tree_approach_eval[1]];
        if ((islander->tree_approach_eval[1] & 0xFF) == 0xFF) {
            islander->tree_approach_eval[1] = 0xF;
            islander->tree_approach_x[1] = 0;
            tilemap_addresses[1] = BG_SCREEN_ADDR(20);
            tile_ids[1] = field->fg_tiles[0][(0xF0 & object->tile_idx) + islander->tree_approach_eval[1]];
            islander->tree_approach_x[1] = islander->tree_approach_eval[1] << 12;
        }
        islander->tree_approach_eval[1] += object->tile_idx & 0xF0;
    }
    for (side = 0; side < 2; side++) {
        tilemap_addresses[side] += (islander->tree_approach_eval[side] & 0xF0) * 8;
        tilemap_addresses[side] += (islander->tree_approach_eval[side] & 0xF) * 4;
        if ((*(u16 *)tilemap_addresses[side] & 0x3FF) > 0x7F) {
            islander->tree_approach_x[side] = 0;
        }
        if (tile_ids[side] == 0x7777 || tile_ids[side] == 0x1F || tile_ids[side] == 0x20) {
            islander->tree_approach_x[side] = 0;
        }
    }
    return Islander_SelectTreeApproach(object, islander->tree_approach_x[0], islander->tree_approach_x[1]);
}

/* Original address: 0x020338D2 */
extern u8 sIslanderTreeActionChances[8];

/* Original address: 0x02020480 */
s32 Islander_DecideTreeAction(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 tree;
    s32 state;
    s32 i;
    u8 chance;
    u8 chance_idx;
    s32 approach;
    FieldObject *object;

    if (islander->tree_action_cooldown_timer != 0) {
        islander->tree_action_skipped = 0;
        return 0;
    }
    tree = Islander_FindNearbyTree();
    if (tree == 0) {
        islander->tree_action_skipped = tree;
        return 0;
    }
    state = islander->equipped_tool_state & 0xF;
    if (state == 0 || state == 2 || state == 6) {
        for (i = 0; i < FIELD_OBJECT_COUNT; i++) {
            if (field->entity_active[0x36 + i] == 1) {
                object = &gFieldObjects[i];
                if (object->tile_idx == islander->surrounding_tile_indices[(u8)(tree - 1)] &&
                    object->layer == (islander->x & 0x10000) >> 16) {
                    break;
                }
            }
        }
        if (i == FIELD_OBJECT_COUNT) {
            islander->tree_action_skipped = 0;
            return 0;
        }
        if (islander->tree_action_skipped == 0) {
            chance_idx = islander->emotion * 2 + islander->reward_adjust;
            chance = sIslanderTreeActionChances[chance_idx];
            if (chance < (s32)rand_u16(&gGameState) % 101) {
                islander->tree_action_skipped = 1;
            } else {
                islander->target_field_object_idx = i;
                islander->item_work.held_item.type_idx = 0;
                object = &gFieldObjects[islander->target_field_object_idx];
                approach = Islander_SetupTreeApproach(object);
                if (approach != 0) {
                    islander->previous_direction = islander->direction;
                    islander->move_action = 4;
                    IslanderMoveAction_MoveToTarget();
                    return 1;
                }
                islander->target_x = approach;
                islander->target_y = approach;
                islander->tree_action_cooldown_timer = 0x50;
            }
        }
    }
    return 0;
}

/* Original address: 0x02033A84 */
extern s32 sIslanderMoveSteps[8][2];


/* Original address: 0x020205E0 */
void Islander_MoveWithCollision(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 collision;
    s32 i;
    s32 *step = sIslanderMoveSteps[islander->direction];

    islander->x += step[0];
    islander->y += step[1];
    if (islander->collision_bypass_timer != 0) {
        islander->collision_bypass_timer--;
        if ((islander->accepted_x & 0xFFF00) != (islander->x & 0xFFF00)) {
            islander->accepted_x = islander->x & 0xFFF00;
        }
        if ((islander->accepted_y & 0xFFF00) != (islander->y & 0xFFF00)) {
            islander->accepted_y = islander->y & 0xFFF00;
        }
        return;
    }

    Islander_UpdateCollisionTiles(islander->direction);
    collision = 0;
    for (i = 0; i < 4; i++) {
        collision = CheckSurroundingCollision(islander->surrounding_item_types[i], islander->collision_tilemap);
        if (collision != 0) {
            break;
        }
    }
    if (i == 4) {
        if ((islander->accepted_x & 0xFFF00) != (islander->x & 0xFFF00)) {
            islander->accepted_x = islander->x & 0xFFF00;
        }
        if ((islander->accepted_y & 0xFFF00) != (islander->y & 0xFFF00)) {
            islander->accepted_y = islander->y & 0xFFF00;
        }
        islander->tree_action_skipped = 0;
        if (islander->collision_retry_count != 0) {
            islander->collision_recovery_timer++;
            if (islander->collision_recovery_timer > 0x20) {
                islander->collision_retry_count = 0;
                islander->collision_recovery_timer = 0;
            }
        }
    } else {
        if (collision != 1 || (!(islander->direction >= 3 && islander->direction <= 5) ||
            field->special_tile_idx != islander->tile_idx || gPlayer.near_house_door != 1)) {
            if (collision == 1 && Islander_DecideTreeAction() != 0) {
                return;
            }
            islander->x = islander->accepted_x;
            islander->y = islander->accepted_y;
            collision = Islander_ChooseNewMoveDirection(1);
            islander->target_x = 0;
            islander->target_y = 0;
            islander->collision_retry_count++;
            if (collision != 0x777 && islander->collision_retry_count <= 6) {
                islander->direction = collision;
                islander->move_action = 2;
                Islander_StartWandering();
                return;
            }
        } else {
            IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];

            islander->target_x = house->x << 8;
            islander->target_y = (house->y << 8) + 0x1000;
            islander->target_action = 0x20;
            islander->item_work.held_item.type_idx = 0;
            islander->move_action = 4;
            IslanderMoveAction_MoveToTarget();
            return;
        }
        islander->collision_retry_count = 0;
        islander->move_action = 0x13;
        Islander_MoveAction20_Init();
    }
}

/* Original address: 0x02020790 */
void Islander_AdjustAnimForTool(void) {
    u32 var_r1_17464;

    var_r1_17464 = 0xF & gIslander.equipped_tool_state;
    if (var_r1_17464 > 4U) {
        var_r1_17464 = (u32) (u16) (var_r1_17464 - 4);
    }
    gIslander.anim_id = (var_r1_17464 * 8) + gIslander.direction;
}

/* Original address: 0x020207C0 */
s32 Islander_MoveTowardX(u8 keep_facing, s32 target) {
    Islander_AGB *islander = &gIslander;
    s32 x = islander->x;
    s32 distance = target - x;

    if (distance < 0) {
        distance = -distance;
    }
    if (distance > 0x100) {
        if (target > x) {
            islander->x = x + 0x40;
            if (keep_facing == 0) {
                islander->direction = 6;
            }
        } else {
            islander->x = x - 0x40;
            if (keep_facing == 0) {
                islander->direction = 2;
            }
        }
        return 0;
    }
    return 1;
}

/* Original address: 0x02020814 */
s32 Islander_MoveTowardY(u8 keep_facing, s32 target) {
    Islander_AGB *islander = &gIslander;
    s32 y = islander->y;
    s32 distance = target - y;

    if (distance < 0) {
        distance = -distance;
    }
    if (distance > 0x100) {
        if (target > y) {
            islander->y = y + 0x40;
            if (keep_facing == 0) {
                islander->direction = 0;
            }
        } else {
            islander->y = y - 0x40;
            if (keep_facing == 0) {
                islander->direction = 4;
            }
        }
        return 0;
    }
    return 1;
}

/* Original address: 0x0202086C */
s32 Islander_FindNearbyTree(void) {
    Islander_AGB *islander = &gIslander;
    s32 i;
    u16 item_type;

    for (i = 0; i < 4; i++) {
        item_type = islander->surrounding_item_types[i];
        if ((item_type >= ITEM_TYPE_SMALL_TREE && item_type <= ITEM_TYPE_FULLY_GROWN_TREE) ||
            (item_type >= ITEM_TYPE_FRUIT_APPLE_TREE && item_type <= ITEM_TYPE_FRUIT_CHERRY_TREE) ||
            (item_type >= ITEM_TYPE_SMALL_PALM_TREE && item_type <= ITEM_TYPE_PALM_TREE) ||
            item_type == ITEM_TYPE_FRUIT_PALM_TREE) {
            return ++i;
        }
    }
    return 0;
}

/* Original address: 0x020208BC */
s32 Islander_TryInteractWithBuriedItem(u8 layer) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Island_agb_c *island = gIslandData;
    u32 tile;
    ItemGroupStruct *definition;
    u16 special_tile;
    s32 chance;
    s32 state;

    if ((island->deposit[layer][islander->tile_idx >> 4] >> (0xF & islander->tile_idx)) & 1) {
        if (islander->digging_cooldown_timer == 0 &&
            ((state = 0xF & islander->equipped_tool_state) == 3 || state == 7)) {
            if (!(islander->x & 0xFF0000)) {
                tile = field->fg_tiles[0][islander->tile_idx];
            } else {
                tile = field->fg_tiles[1][islander->tile_idx];
            }
            definition = &g_ItemDefinitions[tile];
            if (tile != 0xFFF) {
                special_tile = tile & 0x8000;
                if (special_tile == 0 && tile != 0x3333 && tile != 0x7777 &&
                    definition->interaction_type != 0xFFF) {
                    chance = 50;
                    switch (islander->reward_adjust) {
                    case 1:
                        chance = 25;
                        break;
                    }
                    if (chance >= (s32)rand_u16(&gGameState) % 101 &&
                        (u16)Islander_SetupDigApproach(0xF1) != 0) {
                        islander->accepted_x = islander->target_x;
                        islander->accepted_y = islander->target_y;
                        islander->buried_item_tile_base = 0;
                        islander->item_work.held_item.type_idx = 2;
                        islander->move_action = 4;
                        IslanderMoveAction_MoveToTarget();
                        return 2;
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x020209E0 */
void Islander_OnMoodChanged(void) {
    Islander_AGB *islander = &gIslander;
    u16 *emotions = sIslanderMoodEmotions;
    u16 emotion = emotions[islander->mood_level];

    islander->emotion = emotion;
    Sound_SetEmotion(emotion + SOUND_EMOTION_NEUTRAL);
}

/* Original address: 0x02020A0C */
void WriteItemTileToVRAM(u16 *tilemap, u16 tile_base) {
    *tilemap++ = tile_base;
    *tilemap = tile_base + 1;
    tilemap += 31;
    tilemap[0] = tile_base + 2;
    tilemap[1] = tile_base + 3;
}

/* Original address: 0x02020A24 */
u16 Item_GetItemIdFromTileId(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    BuriedItemUpdateGroup *buried_item_update;
    int i;

    if (IS_ITEM_TYPE_FRUIT(item_type)) {
        islander->buried_item_tile_base = 0x3260;
        if (item_type == ITEM_TYPE_COCONUT) {
            islander->buried_item_tile_base = 0x3268;
        }

        for (i = 0; i < ARRAY_COUNT(gBuriedItemUpdateGroups); i++) {
            buried_item_update = &gBuriedItemUpdateGroups[i];
            if (buried_item_update->item_type == item_type) {
                break;
            }
        }

        return buried_item_update->buried_item;
    }

    return EMPTY_NO;
}

/* Original address: 0x02020A78 */
s32 Islander_TryDropTool(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 placed = 0;
    u16 tile = islander->equipped_tool_state & 0xF;
    u32 tool = tile;
    s32 collision;

    if (tile > 4) {
        tile -= 4;
    }
    tile = tile * 2 + 0x8043;
    if (tool > 4) {
        tile++;
    }
    if (Islander_CanDigHere() != 0) {
        Islander_UpdateCollisionTiles(islander->direction);
        collision = CheckSurroundingCollision(islander->tile_idx, islander->collision_tilemap);
        if ((islander->x & 0xFF0000) == 0) {
            if (collision == 0) {
                if (field->fg_tiles[0][islander->tile_idx] == 0xFFF) {
                    field->fg_tiles[0][islander->tile_idx] = tile;
                    placed = 1;
                }
            }
        } else if (collision == 0) {
            if (field->fg_tiles[1][islander->tile_idx] == 0xFFF) {
                field->fg_tiles[1][islander->tile_idx] = tile;
                placed = 1;
            }
        }
        if (placed == 1) {
            WriteItemToTile(islander->x, islander->tile_idx, islander->removed_tool_item, 0x6234);
            if (islander->removed_tool_layer == 0) {
                field->fg_tiles[0][islander->removed_tool_tile_idx] = 0xFFF;
            } else {
                field->fg_tiles[1][islander->removed_tool_tile_idx] = 0xFFF;
            }
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->equipped_tool_state = 0;
            islander->removed_tool_item = 0;
            Islander_AdjustAnimForTool();
            return 1;
        }
    }
    return 0;
}

/* Original address: 0x02020B88 */
void Islander_Init(void) {
    Islander_AGB *islander = &gIslander;
    s32 i;

    islander->x = 0;
    islander->y = 0;
    islander->accepted_x = 0;
    islander->accepted_y = 0;
    islander->target_x = 0;
    islander->target_y = 0;
    islander->next_target_x = 0;
    islander->next_target_y = 0;
    islander->flying_item_x = 0;
    islander->flying_item_y = 0;
    islander->work_x = 0;
    islander->work_y = 0;
    islander->surrounding_item_types[0] = 0;
    islander->collision_tilemap = 0;
    islander->removed_tool_layer = 0;
    islander->removed_tool_tile_idx = 0;
    islander->held_item_sprite = 0;
    islander->wander_timer = 0;
    islander->move_action = 0;
    islander->anim_id = 0;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->direction = 0;
    islander->previous_direction = 0;
    islander->equipped_tool_state = 0;
    islander->removed_tool_item = 0;
    islander->tile_idx = 0;
    islander->interaction_tile = 0;
    islander->terrain_tile_idx = 0;
    islander->emotion = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->mood_level = 0;
    islander->direction_change_cooldown_timer = 0;
    islander->stored_item_slot = 0;
    islander->islander_npc_idx = 0;
    islander->reaction_anim_id = 0;
    islander->click_cooldown_timer = 0;
    islander->target_action = 0;
    islander->collision_bypass_timer = 0;
    islander->target_field_object_idx = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->item_work.held_item.tile_no = 0;
    islander->action_state = 0;
    islander->player_interaction_tile_idx = 0;
    islander->fishing_cooldown_timer = 0;
    islander->floating_balloon_target_entity_id = 0;
    islander->interaction_target_is_islander = 0;
    islander->buried_item_tile_base = 0;
    islander->carry_wait_timer = 0;
    islander->carry_state = 0;
    islander->immediate_item_type_plus_one = 0;
    islander->reward_adjust = 0;
    islander->equipped_tool_timer = 0;
    islander->collision_retry_count = 0;
    islander->favorite_hour_item_spawned = 0;
    islander->tree_action_skipped = 0;
    islander->collision_recovery_timer = 0;
    islander->removed_field_item_type = 0;
    islander->dig_target_layer = 0;
    islander->dig_target_tile_idx = 0;

    islander->digging_cooldown_timer = 0x78;
    islander->flying_item_spawn_timer = 0x2A30;
    islander->islander_npc_idx = gIslandData->npc_idx;
    islander->reward_adjust = sIslanderRewardAdjust[islander->islander_npc_idx];
    for (i = 0; i < 4; i++) {
        islander->surrounding_item_types[i] = 0;
        islander->surrounding_tile_indices[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        islander->stored_item_type_plus_one[i] = 0;
        islander->stored_item_ids[i] = 0;
    }
    islander->mood_level = 3;
    Islander_OnMoodChanged();
    Sound_SetEmotion(islander->emotion + SOUND_EMOTION_NEUTRAL);
    Sound_InitMusic();
    islander->anim_timer = 0xFE;
    islander->anim_id = ISLANDER_ANIM_60;
    islander->move_action = 0;
}

/* Original address: 0x02020D20 */
s32 Island_GetFloatingItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 *index = &sFloatingItemIndex;

    *index = islander->islander_npc_idx * 7;
    *index += sFloatingItemHourOffsets[field->last_palette_hour];
    *index = sFloatingItemBaseIndices[*index];
    *index += gMoveAction11EmotionSpawnOffsets[islander->emotion];
    if ((islander->equipped_tool_state & 0xF) == 5) {
        *index += 20;
    }
    if (*index >= 160) {
        return 0;
    }
    if (*index > 160) {
        *index = 0;
    }
    return *index;
}

/* Original address: 0x02033B30 */
extern EntitySpawnParams sFlyingItemFruitParams[6];
/* Original address: 0x02033B48 */
extern EntitySpawnParams sFlyingItemParams[160];

/* Original address: 0x02020DA8 */
void Islander_StepFlyingItem(void) {
    Islander_AGB *islander = &gIslander;
    Entity *balloon;
    s32 i;
    u16 *items;
    EntitySpawnParams *params;
    u16 *tile_ids;
    u16 tile;
    u16 item;
    s32 chance;

    if (islander->move_action == 16) {
        return;
    }
    if (islander->flying_item_spawn_timer != 0) {
        islander->flying_item_spawn_timer--;
        return;
    }
    if (islander->stored_item_type_plus_one[4] == 0 && islander->flying_item_x == 0 && islander->flying_item_y == 0) {
        i = Island_GetFloatingItem();
        params = &sFlyingItemParams[i];
        i = SpawnEntity(0, 1, params->type, params->param);
        if (i == 0) {
            return;
        }
        balloon = &g_EntityTable[i];
        if ((rand_u16(&gGameState) & 1) == 0) {
            balloon->x = 16;
            balloon->horizontal_velocity = 24;
            balloon->vertical_velocity_or_x_limit = 465;
        } else {
            balloon->x = 464;
            balloon->horizontal_velocity = -24;
            balloon->vertical_velocity_or_x_limit = 15;
        }
        balloon->y = (rand_u16(&gGameState) % 5) * 16 + 80;
        islander->flying_item_x = balloon->x;
        islander->flying_item_y = balloon->y;
        params++;
        items = &balloon->item_ids[1];
        tile_ids = &balloon->item_type_indices[1];
        i = 0;
        while (i < 4) {
            tile = params->type;
            item = params->param;
            if (item == 4) {
                EntitySpawnParams *fruit = &sFlyingItemFruitParams[rand_u16(&gGameState) % 6];
                tile = fruit->type;
                item = fruit->param;
            }
            *tile_ids = tile;
            *items = item;
            items++;
            tile_ids++;
            i++;
            params++;
        }
    } else if (islander->move_action == 3) {
        if (islander->stored_item_type_plus_one[4] != 0) {
            islander->floating_balloon_target_entity_id = 0;
            return;
        }
        if ((islander->equipped_tool_state & 0xF) == 1 || (islander->equipped_tool_state & 0xF) == 5) {
            islander->work_x = islander->flying_item_x - islander->x;
            islander->work_y = islander->flying_item_y - islander->y;
            if (islander->work_x < 0) {
                islander->work_x = -islander->work_x;
            }
            if (islander->work_y < 0) {
                islander->work_y = -islander->work_y;
            }
            if (islander->work_x <= 0x1000 && islander->work_y <= 0x1000) {
                chance = 100;
                if (islander->reward_adjust == 1) {
                    chance = 50;
                }
                if (chance >= rand_u16(&gGameState) % 101) {
                    if (islander->x > islander->flying_item_x) {
                        islander->direction = 0;
                    } else {
                        islander->direction = 1;
                    }
                    islander->move_action = MoveActionReceiveItemInit;
                    Islander_ReceiveItem_Init();
                }
            }
        }
    }
}

/* Original address: 0x02020F54 */
s32 Islander_TryStartFishing(void) {
    u16 tile;
    u16 *tilemap;
    s32 i;
    s32 water_tiles;
    s32 chance;
    Islander_AGB *islander = &gIslander;
    s32 can_fish = 0;

    if (islander->fishing_cooldown_timer == 0 && ((islander->equipped_tool_state & 0xF) == 4 || (islander->equipped_tool_state & 0xF) == 8)) {
        if (!(islander->x & 0xFF0000)) {
            tile = islander->tile_idx - 2;
            tile += 16;
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
        } else {
            tile = islander->tile_idx + 18;
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
        }
        tilemap += (tile & 0xF0) * 4;
        tilemap += (tile & 0xF) * 2;
        i = 0;
        water_tiles = 0;
        do {
            tile = *tilemap & 0x3FF;
            if (tile == 0xF6) {
                water_tiles++;
            }
            if (i == 0 || i == 2) {
                tilemap++;
            } else if (i == 1) {
                tilemap += 31;
            }
            i++;
        } while (i < 4);
        if (water_tiles > 3) {
            can_fish = 1;
        }
        if (can_fish != 0) {
            chance = 25;
            if (islander->reward_adjust == 1) {
                chance = 50;
            }
            if (chance > rand_u16(&gGameState) % 101) {
                if (!(islander->x & 0xFF0000)) {
                    islander->direction = 0;
                } else {
                    islander->direction = 1;
                }
                islander->move_action = MoveAction13;
                Islander_Fishing_Init();
                return 1;
            }
        }
    }
    return 0;
}

/* Original address: 0x02021050 */
u16 Islander_TakeCurrentTileItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item;

    if (!(islander->x & 0xFF0000)) {
        field->fg_tiles[0][islander->tile_idx] = 0x7777;
        item = gIslandData->fgblock[0][0].items[islander->tile_idx >> 4][islander->tile_idx & 0xF];
    } else {
        field->fg_tiles[1][islander->tile_idx] = 0x7777;
        item = gIslandData->fgblock[0][1].items[islander->tile_idx >> 4][islander->tile_idx & 0xF];
    }
    return item;
}

/* Original address: 0x020210D4 */
s32 Islander_TryInteractWithCurrentTile(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item = 0;
    u16 tile;
    ItemGroupStruct *definition;
    s32 state;
    s32 result;
    s32 slot;

    state = islander->equipped_tool_state & 0xF;
    if (state != 0 && state != 3 && state != 7) {
        return 0;
    }
    if (!(islander->x & 0xFF0000)) {
        tile = field->fg_tiles[0][islander->tile_idx];
    } else {
        tile = field->fg_tiles[1][islander->tile_idx];
    }
    if (tile == 0xFFF) {
        return 0;
    }
    if (tile & 0x8000) {
        return 0;
    }
    if (tile == 0x7777) {
        return 0;
    }
    if (tile == 0x3333) {
        return 0;
    }
    definition = &g_ItemDefinitions[tile];
    if (definition->held_item_oam_attr2 == 0xFFF) {
        return 0;
    }
    if (!(islander->x & 0xFF0000)) {
        result = Islander_TryInteractWithBuriedItem(0);
    } else {
        result = Islander_TryInteractWithBuriedItem(1);
    }
    if (result == 2) {
        return 1;
    }
    if (result == 1) {
        return 0;
    }

    islander->removed_field_item_type = 0;
    if ((islander->equipped_tool_state & 0xF) == 3 || (islander->equipped_tool_state & 0xF) == 7) {
        if (islander->stored_item_type_plus_one[4] != 0 ||
            (definition->interaction_type >= 7 && definition->interaction_type <= 14)) {
            return 0;
        }
        item = Islander_TakeCurrentTileItem();
    } else if (!(definition->interaction_type >= 5 && definition->interaction_type <= 6)) {
        if (definition->interaction_type >= 7 && definition->interaction_type <= 14) {
            islander->removed_tool_item = Islander_TakeCurrentTileItem();
            islander->removed_field_item_type = tile;
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->removed_tool_tile_idx = islander->tile_idx;
            if (islander->x & 0xFF0000) {
                islander->removed_tool_layer = 1;
            }
        } else {
            if (islander->stored_item_type_plus_one[4] != 0) {
                return 0;
            }
            item = Islander_TakeCurrentTileItem();
        }
    }

    if (!(islander->x & 0xFF0000)) {
        field->fg_tiles[0][islander->tile_idx] = 0x7777;
    } else {
        field->fg_tiles[1][islander->tile_idx] = 0x7777;
    }
    islander->target_x = islander->x & 0xFF0000;
    islander->target_x |= ((islander->tile_idx & 0xF) << 12) + 0x800;
    islander->target_y = ((islander->tile_idx & 0xF0) << 8) + 0x800;
    islander->item_work.held_item.type_idx = 2;
    islander->target_action = 0x10;
    islander->move_action = 4;
    islander->immediate_item_type_plus_one = 0;
    if (item != 0) {
        for (slot = 0; slot < 5; slot++) {
            if (islander->stored_item_type_plus_one[slot] == 0) {
                islander->stored_item_type_plus_one[slot] = tile + 1;
                islander->stored_item_ids[slot] = item;
                islander->stored_item_slot = slot;
                return 1;
            }
        }
    } else {
        if (islander->removed_field_item_type == 0) {
            islander->immediate_item_type_plus_one = tile + 1;
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x020212F4 */
s32 Islander_TryStartDigging(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 tile;
    u8 *standing_tile;

    if ((islander->emotion == ISLANDER_EMOTION_HAPPY || islander->emotion == ISLANDER_EMOTION_ANGRY) &&
        ((islander->equipped_tool_state & 0xF) == 3 || (islander->equipped_tool_state & 0xF) == 7) && islander->digging_cooldown_timer == 0) {
        if (!(islander->x & 0xFF0000)) {
            standing_tile = &islander->tile_idx;
            tile = field->fg_tiles[0][*standing_tile];
        } else {
            standing_tile = &islander->tile_idx;
            tile = field->fg_tiles[1][*standing_tile];
        }
        if (tile == 0xFFF && rand_u16(&gGameState) % 101 <= 5 &&
            Islander_CanDigHere() != 0 && (u16)Islander_SetupDigApproach(0xF1) != 0) {
            islander->accepted_x = islander->target_x;
            islander->accepted_y = islander->target_y;
            islander->dig_target_layer = 0;
            islander->dig_target_tile_idx = *standing_tile;
            if (islander->x & 0xFF0000) {
                islander->dig_target_layer = 1;
            }
            islander->buried_item_tile_base = 0;
            islander->item_work.held_item.type_idx = 2;
            islander->move_action = MoveAction4;
            IslanderMoveAction_MoveToTarget();
            return 2;
        }
    }
    return 0;
}

/* Original address: 0x020213DC */
void RestoreHeldItemsToField(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Player *player = &gPlayer;
    u32 tool;
    u16 tile;
    u16 *tilemap_vram;

    if (player->held_item_layer != 0 || player->held_item_tile_idx != 0) {
        ItemGroupStruct *definition = &g_ItemDefinitions[player->held_item_type_idx];
        WriteItemToTile(player->held_item_layer << 16, player->held_item_tile_idx,
                        player->held_item, definition->field_tile_id);
        if (player->held_item_layer == 0) {
            field->fg_tiles[0][player->held_item_tile_idx] = player->held_item_type_idx;
        } else {
            field->fg_tiles[1][player->held_item_tile_idx] = player->held_item_type_idx;
        }
        player->held_item_layer = 0;
        player->held_item_tile_idx = 0;
        field->entity_active[2] = 0;
    }

    tool = islander->equipped_tool_state & 0xF;
    if (tool != 0) {
        tile = tool;
        if (tile > 4) {
            tile -= 4;
        }
        tile = tile * 2 + 0x8043;
        if (tool > 4) {
            tile++;
        }
        if (islander->removed_tool_layer != 0 || islander->removed_tool_tile_idx != 0) {
            if (islander->removed_tool_layer == 0) {
                field->fg_tiles[0][islander->removed_tool_tile_idx] = tile;
                tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF0) * 4;
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF) * 2;
                gIslandData->fgblock[0][0].items[(islander->removed_tool_tile_idx >> 4) & 0xF][islander->removed_tool_tile_idx & 0xF] = islander->removed_tool_item;
            } else {
                field->fg_tiles[1][islander->removed_tool_tile_idx] = tile;
                tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF0) * 4;
                tilemap_vram += (islander->removed_tool_tile_idx & 0xF) * 2;
                gIslandData->fgblock[0][1].items[(islander->removed_tool_tile_idx >> 4) & 0xF][islander->removed_tool_tile_idx & 0xF] = islander->removed_tool_item;
            }
            WriteItemTileToVRAM(tilemap_vram, 0x6234);
            islander->removed_tool_tile_idx = 0;
            islander->removed_tool_layer = 0;
            islander->equipped_tool_state = 0;
            islander->removed_tool_item = 0;
            if (islander->move_action == MoveAction3) {
                Islander_AdjustAnimForTool();
            }
        }
    }
}
/* Original address: 0x02021574 */
void Islander_UpdateMovement(void) {
    Islander_AGB *islander = &gIslander;

    if (gIslandFieldWork.gameplay_active != 0) {
        Islander_StepFlyingItem();
        if ((islander->move_action >= MoveAction9 && islander->move_action <= CheckClickedOnTimer) ||
            islander->click_cooldown_timer == 0) {
            if (islander->move_action == MoveAction3) {
                Islander_MoveWithCollision();
            }
            IslanderMoveProcTable[islander->move_action]();
        }
    }
}

/* Original address: 0x020215D0 */
void Islander_StartHouseTransition(void) {
    gIslander.anim_timer = 0;
    gIslander.anim_frame = 0;
    gIslander.target_x = 0;
    gIslander.target_y = 0;
    gIslander.direction = 0;
    if (gIslander.anim_id == 0x60) {
        gIslander.anim_timer = 0xFE;
    }
    gIslander.move_action = 1;
}

/* Original address: 0x02021608 */
void Islander_MoveIndoorsOrOutdoors(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    s32 i;
    u8 anim_id;

    if (islander->anim_timer != 0xFE) {
        if (islander->anim_timer == 0) {
            if (islander->anim_id == ISLANDER_ANIM_5F) {
                if (islander->anim_frame == 8) {
                    Sound_PlayEffect0(1);
                }
                if (islander->anim_frame == 0x13) {
                    Sound_PlayEffect0(0xE);
                }
            } else {
                if (islander->anim_frame == 1) {
                    Sound_PlayEffect0(1);
                }
                if (islander->anim_frame == 0xB) {
                    Sound_PlayEffect0(0xE);
                }
            }
        }
        if (Islander_PlayAnim(1) != 0) {
            anim_id = islander->anim_id;
            if (anim_id == ISLANDER_ANIM_60) {
                house->state = 1;
                islander->y += 0x1200;
                islander->accepted_y = islander->y;
                islander->direction_change_cooldown_timer = anim_id;
                islander->move_action = ActionOutside;
                Islander_StartWandering();
                islander->collision_bypass_timer = 0x40;
                islander->wander_timer = 0x60;
            } else {
                for (i = 0; i < 5; i++) {
                    if (islander->stored_item_type_plus_one[0] != 0) {
                        islander->mood_level++;
                        if (islander->mood_level > 6) {
                            islander->mood_level = 6;
                        }
                        Islander_OnMoodChanged();
                        Islander_ClearStoredItem(0);
                    }
                }
                islander->anim_timer = 0xFE;
                islander->anim_id = ISLANDER_ANIM_60;
                islander->move_action = ActionInside;
                house->state = 1;
            }
        }
    }
}
/* Original address: 0x02021720 */
void Islander_StartWandering(void) {
    Islander_AGB *islander = &gIslander;
    s32 base_duration = 0;
    AnimFrameData *anim;

    islander->anim_id = ISLANDER_ANIM_00;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->reaction_anim_id = ISLANDER_ANIM_00;
    Islander_AdjustAnimForTool();
    anim = *gIslanderAnimData[islander->anim_id];
    switch (islander->emotion) {
    case ISLANDER_EMOTION_NEUTRAL:
    case ISLANDER_EMOTION_HAPPY:
        base_duration = 0x180;
        break;
    case ISLANDER_EMOTION_ANGRY:
    case ISLANDER_EMOTION_SAD:
        base_duration = 0x100;
        break;
    }
    islander->wander_timer = base_duration + rand_u16(&gGameState) % 337;
    islander->anim_timer = anim->duration;
    islander->move_action = MoveAction3;
}

/* Original address: 0x020217AC */
void Islander_UpdateWandering(void) {
    Islander_AGB *islander = &gIslander;
    s32 direction = 0;

    Islander_UpdateBlink();
    if (islander->tree_action_cooldown_timer != 0) {
        islander->tree_action_cooldown_timer--;
    }
    if (islander->digging_cooldown_timer != 0) {
        islander->digging_cooldown_timer--;
    }
    if (islander->direction_change_cooldown_timer != 0) {
        islander->direction_change_cooldown_timer--;
    }
    if (islander->fishing_cooldown_timer != 0) {
        islander->fishing_cooldown_timer--;
    }
    if (islander->equipped_tool_state & 0xF) {
        if (islander->equipped_tool_timer > 0x1C20) {
            if (Islander_TryDropTool() != 0) {
                islander->equipped_tool_timer = 0;
            }
        } else {
            islander->equipped_tool_timer++;
        }
    }
    if (Islander_TryInteractWithCurrentTile() == 0 && Islander_TryStartFishing() == 0 && Islander_TryStartDigging() == 0) {
        if (islander->target_x != 0 && islander->target_y != 0 &&
            Islander_FaceTargetAndCheckArrival(islander->target_x, islander->target_y) != 0) {
            if (islander->wander_timer < 0x60) {
                islander->wander_timer = 0x60;
            }
            islander->target_x = 0;
            islander->target_y = 0;
        }
        if (islander->emotion != ISLANDER_EMOTION_HAPPY || islander->target_y == 0) {
            if (islander->wander_timer == 0) {
                direction = Islander_ChooseNewMoveDirection(0);
                if (direction != 0x777) {
                    islander->direction = direction;
                    islander->move_action = ActionOutside;
                    Islander_StartWandering();
                    return;
                }
            } else {
                islander->wander_timer--;
            }
        }
        Islander_PlayAnim(0);
    }
}

/* Original address: 0x020218B0 */
void IslanderMoveAction_MoveToTarget(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    FieldObject *object = NULL;
    s32 continue_moving = 0;

    Islander_UpdateBlink();
    if (islander->target_y & 0xFFFF0000) {
        islander->target_y &= 0xFFFF;
    }
    if (islander->next_target_y & 0xFFFF0000) {
        islander->next_target_y &= 0xFFFF;
    }
    if (Islander_ChangeMoveDir(islander->target_x, islander->target_y,
                             (u8)islander->item_work.held_item.type_idx)) {
        if (islander->target_action == 0x30 || islander->target_action == 0x40) {
            object = &gFieldObjects[islander->target_field_object_idx];
        }
        switch (islander->target_action) {
        case 0x10:
            islander->move_action = MoveAction5;
            Islander_StartFoodProcessing();
            break;
        case 0x20:
            islander->x = islander->target_x;
            islander->y = islander->target_y - 0x1000;
            house->state = 0;
            islander->anim_id = ISLANDER_ANIM_5F;
            islander->move_action = ActionInside;
            Islander_StartHouseTransition();
            islander->anim_timer = 4;
            break;
        case 0x30:
            object->x_flip = 0;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                if ((islander->equipped_tool_state & 0xF) != 2 && (islander->equipped_tool_state & 0xF) != 6) {
                    islander->anim_id = 0x62;
                } else {
                    islander->anim_id = ISLANDER_ANIM_55;
                }
                islander->x = islander->target_x;
                islander->y = islander->target_y;
                islander->move_action = MoveAction11;
                Islander_StartFieldObjectInteraction();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x40:
            object->x_flip = 1;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                if ((islander->equipped_tool_state & 0xF) != 2 && (islander->equipped_tool_state & 0xF) != 6) {
                    islander->anim_id = ISLANDER_ANIM_61;
                } else {
                    islander->anim_id = ISLANDER_ANIM_54;
                }
                islander->x = islander->target_x;
                islander->y = islander->target_y;
                islander->move_action = MoveAction11;
                Islander_StartFieldObjectInteraction();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x50:
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            Islander_ChooseNewMoveDirection(1);
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            break;
        case 0x60:
            islander->direction = 0;
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                islander->item_work.held_item.type_idx = 0;
                islander->target_action = 0;
                islander->move_action = MoveActionDig;
                IslanderMoveAction_Dig();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        case 0x70:
            islander->direction = 1;
            islander->x = islander->target_x;
            islander->y = islander->target_y;
            if (islander->next_target_x == 0 && islander->next_target_y == 0) {
                islander->item_work.held_item.type_idx = 0;
                islander->target_action = 0;
                islander->move_action = MoveActionDig;
                IslanderMoveAction_Dig();
            } else {
                islander->target_x = islander->next_target_x;
                islander->target_y = islander->next_target_y;
                islander->next_target_x = 0;
                islander->next_target_y = 0;
                continue_moving = 1;
            }
            break;
        }
        if (!continue_moving) {
            islander->item_work.held_item.type_idx = 0;
            islander->target_action = 0;
            islander->target_x = 0;
            islander->target_y = 0;
            return;
        }
    }
    Islander_PlayAnim(0);
}


/* Original address: 0x02021AD8 */
void Islander_StartFoodProcessing(void) {
    Islander_AGB *islander = &gIslander;
    u8 *anim_id = &islander->anim_id;
    u8 *tilemap;
    u8 initial_frame = 0;
    u32 item_type_idx;

    islander->anim_frame = initial_frame;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->anim_id = ISLANDER_ANIM_56;
    islander->anim_timer = gIslanderAnimData[*anim_id][0]->duration;
    if (islander->removed_tool_layer == 0 && islander->removed_tool_tile_idx == 0) {
        WriteItemToTile(islander->x, islander->tile_idx, 0, 0x200);
    } else {
        if ((islander->x & 0xFF0000) == 0) {
            tilemap = (u8 *)BG_SCREEN_ADDR(24);
        } else {
            tilemap = (u8 *)BG_SCREEN_ADDR(25);
        }
        tilemap = (0xF0 & islander->tile_idx) * 8 + tilemap;
        tilemap = (0xF & islander->tile_idx) * 4 + tilemap;
        WriteItemTileToVRAM((u16*)tilemap, 0x200);
    }
    Field_RestoreAdjacentTreeTiles(islander->tile_idx, islander->x);

    if (islander->immediate_item_type_plus_one == 0) {
        if (islander->removed_field_item_type == 0) {
            item_type_idx = islander->stored_item_type_plus_one[islander->stored_item_slot] - 1;
        } else {
            item_type_idx = islander->removed_field_item_type;
        }
    } else {
        item_type_idx = islander->immediate_item_type_plus_one - 1;
    }
    islander->held_item_sprite = (item_type_idx + g_ItemDefinitions)->held_item_oam_attr2 | 0x800000;
    islander->move_action = ProcessFood;
}

/* Original address: 0x02021BCC */
void Islander_ProcessFood(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    ItemGroupStruct *definition;
    u32 item_type_idx;
    s32 result;
    s32 i;

    if (islander->anim_id == ISLANDER_ANIM_56) {
        if (islander->anim_timer == 0) {
            if (islander->anim_frame == 2) {
                Sound_PlayEffect0(0x1D);
            }
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    result = 0;
    if (islander->immediate_item_type_plus_one == 0) {
        if (islander->removed_field_item_type == 0) {
            item_type_idx = islander->stored_item_type_plus_one[islander->stored_item_slot] - 1;
        } else {
            item_type_idx = islander->removed_field_item_type;
        }
    } else {
        item_type_idx = islander->immediate_item_type_plus_one - 1;
    }

    definition = g_ItemDefinitions + item_type_idx;
    islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;

    switch (islander->anim_id) {
    case ISLANDER_ANIM_56:
        islander->anim_id = ISLANDER_ANIM_58;
        if (islander->immediate_item_type_plus_one != 0) {
            islander->anim_id = ISLANDER_ANIM_57;
            Sound_PlayEffect0(0x19);
        }
        break;

    case ISLANDER_ANIM_57: {
        u8 *food_preferences;
        u8 *food_preference_layout;

        islander->held_item_sprite = 0;
        if ((islander->x & 0xFF0000) == 0) {
            field->fg_tiles[0][islander->tile_idx] = 0xFFF;
        } else {
            field->fg_tiles[1][islander->tile_idx] = 0xFFF;
        }

        i = 0;
        food_preferences = (u8 *)&ISLANDER_FOOD_PREFERENCES;
        food_preference_layout = food_preferences + sizeof(ISLANDER_FOOD_PREFERENCES.preferences);
        for (; i < 9; i++) {
            if (item_type_idx == food_preference_layout[i]) {
                u8 preference_idx = islander->islander_npc_idx * 9 + i;
                u8 preference = food_preferences[preference_idx];

                islander->mood_level += preference;
                if ((preference & 0x80) == 0) {
                    islander->reaction_anim_id = ISLANDER_ANIM_59;
                } else {
                    islander->reaction_anim_id = ISLANDER_ANIM_5D;
                }
                break;
            }
        }

        result = 3;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        } else if (islander->mood_level > 5) {
            if ((islander->x & 0xFF0000) == 0) {
                field->fg_tiles[0][islander->tile_idx] = 0x3333;
            } else {
                field->fg_tiles[1][islander->tile_idx] = 0x3333;
            }
            islander->mood_level = 6;
            break;
        }
        islander->immediate_item_type_plus_one = 0;
        break;
    }

    case ISLANDER_ANIM_58:
        islander->held_item_sprite = 0;
        if ((islander->x & 0xFF0000) == 0) {
            if (islander->removed_tool_tile_idx != islander->tile_idx) {
                field->fg_tiles[0][islander->tile_idx] = 0xFFF;
            }
        } else if (islander->removed_tool_tile_idx != islander->tile_idx) {
            field->fg_tiles[1][islander->tile_idx] = 0xFFF;
        }

        switch (definition->interaction_type) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            islander->reaction_anim_id = ISLANDER_ANIM_59;
            result = 3;
            break;
        case 4:
            islander->mood_level = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
            result = 1;
            break;
        case 8:
            islander->equipped_tool_state = 5;
            result = 2;
            break;
        case 7:
            islander->equipped_tool_state = 1;
            result = 2;
            break;
        case 10:
            islander->equipped_tool_state = 6;
            result = 2;
            break;
        case 9:
            islander->equipped_tool_state = 2;
            result = 2;
            break;
        case 12:
            islander->equipped_tool_state = 7;
            result = 2;
            break;
        case 11:
            islander->equipped_tool_state = 3;
            result = 2;
            break;
        case 14:
            islander->equipped_tool_state = 8;
            result = 2;
            break;
        case 13:
            islander->equipped_tool_state = 4;
            result = 2;
            break;
        default:
            break;
        }
        break;
    }

    switch (result) {
    case 1:
        Islander_ClearStoredItem(islander->stored_item_slot);
        /* fallthrough */
    case 3:
        if (result != 1) {
            Islander_OnMoodChanged();
            if ((islander->emotion == ISLANDER_EMOTION_SAD) && (islander->reward_adjust == 0)) {
                islander->emotion = ISLANDER_EMOTION_ANGRY;
                Sound_SetEmotion(SOUND_EMOTION_ANGRY);
            }
        }
        islander->item_work.held_item.type_idx = 2;
        islander->target_action = 0x50;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case 2:
        WriteItemToTile(islander->x, islander->tile_idx, 0, 0x200);
        islander->equipped_tool_timer = 0;
        islander->direction_change_cooldown_timer = 0x20;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
        break;
    }

    islander->anim_timer = gIslanderAnimData[islander->anim_id][islander->anim_frame]->duration;
}

void IslanderMoveAction_UpdateEmotion(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->blink_frame = 0;
    islander->blink_timer = 0;
    islander->anim_id = islander->reaction_anim_id;
    anim_data = *gIslanderAnimData[islander->anim_id];

    switch (islander->reaction_anim_id) {
    case ISLANDER_ANIM_59:
        Sound_PlayEffect0(9);
        break;
    case ISLANDER_ANIM_5A:
        Sound_PlayEffect0(10);
        break;
    case ISLANDER_ANIM_ANGRY:
        Sound_PlayEffect0(11);
        break;
    case ISLANDER_ANIM_SAD:
        Sound_PlayEffect0(12);
        break;
    case ISLANDER_ANIM_5D:
        Sound_PlayEffect0(13);
        break;
    case ISLANDER_ANIM_5E:
        break;
    }

    Sound_SetEmotion(islander->emotion + SOUND_EMOTION_NEUTRAL);
    islander->anim_timer = anim_data->duration;
    islander->move_action = MoveAction8;
}

/* Original address: 0x02022054 */
void Islander_UpdateEmotionAnimation(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    mActor_name_t *stored_item;
    u16 *stored_type_plus_one;
    s32 i;
    u16 random = 0;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->direction_change_cooldown_timer = 0x20;
    if ((islander->immediate_item_type_plus_one != 0) && (islander->reaction_anim_id == ISLANDER_ANIM_59)) {
        islander->immediate_item_type_plus_one = random;
        if (islander->mood_level == 6) {
            if (islander->stored_item_type_plus_one[0] != 0) {
                if (SpawnEntity(1, 0, islander->stored_item_type_plus_one[0] - 1,
                                islander->stored_item_ids[0]) != 0) {
                    Islander_ClearStoredItem(0);
                }
            } else {
                random = rand_u16(&gGameState) % 101;
                if (random < 60) {
                    SpawnEntity(0, 0, 0xB, 8);
                } else if (random < 90) {
                    SpawnEntity(0, 0, 0x42, 9);
                } else if (random < 98) {
                    SpawnEntity(0, 0, 0x43, 10);
                } else {
                    SpawnEntity(0, 0, 0x44, 11);
                }
            }
        }
    }

    if (islander->target_action == 0x50) {
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->anim_frame = 0;
        Islander_AdjustAnimForTool();
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->move_action = MoveAction4;
        IslanderMoveAction_MoveToTarget();
        return;
    }

    if (islander->target_action == 0x80) {
        house->state = 0;
        islander->x = house->x << 8;
        islander->y = house->y << 8;
        islander->target_action = 0;
        islander->anim_id = ISLANDER_ANIM_5F;
        islander->move_action = ActionInside;
        Islander_StartHouseTransition();
        islander->anim_timer = 4;
        {
            u16 empty_item = 0;

            stored_item = islander->stored_item_ids;
            stored_type_plus_one = islander->stored_item_type_plus_one;
            i = 4;
            do {
                *stored_type_plus_one = empty_item;
                *stored_item = empty_item;
                stored_item++;
                stored_type_plus_one++;
                i--;
            } while (i >= 0);
        }
        return;
    }

    Islander_ChooseNewMoveDirection(1);
    islander->move_action = ActionOutside;
    Islander_StartWandering();
}

/* Original address: 0x020221C0 */
void Islander_StartClickReaction(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 index;
    u16 angle;
    IslanderDirectionSector* sector;

    if (islander->interaction_target_is_islander == 0) {
        if ((islander->target_x & 0xFF0000) == 0) {
            index = field->fg_tiles[0][islander->player_interaction_tile_idx];
        } else {
            index = field->fg_tiles[1][islander->player_interaction_tile_idx];
        }

        if (((u16)index == 0xFFF) || (index == 0x3333) || (index == 0x7777) ||
            ((&g_ItemDefinitions[index])->held_item_oam_attr2 == 0xFFF)) {
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            return;
        }
    }

    Islander_SpawnReactionEffect(0, 0x30);
    islander->click_cooldown_timer = 0x30;
    islander->direction_change_cooldown_timer = 0x60;
    islander->work_x = (islander->target_x - islander->x) >> 8;
    islander->work_y = (islander->target_y - islander->y) >> 8;
    angle = ArcTan2((s16)islander->work_x, (s16)islander->work_y);

    /* Preserve agbcc's loop weighting for the r6/r7 allocation. */
    do {
        if (angle < (&gIslanderDirectionSectors[7])->max_angle) {
            for (index = 0; index < 7; index++) {
                if (angle <= gIslanderDirectionSectors[index].max_angle) {
                    break;
                }
            }
        } else {
            index = 0;
        }
    } while (0);

    islander->direction = gIslanderDirectionSectors[index].direction;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    Islander_AdjustAnimForTool();
    islander->move_action = CheckClickedOnTimer;
}

void Islander_CheckClickedOnTimer(void) {
    Islander_AGB *islander = &gIslander;
    u8 timer;
    u8 state;

    timer = --islander->click_cooldown_timer;
    if (timer == 0) {
        if (islander->reaction_anim_id == ISLANDER_ANIM_00) {
            state = islander->equipped_tool_state;
            if (state & 0x40) {
                islander->equipped_tool_state = state - 0x40;
                Islander_TryDropTool();
            }
            islander->move_action = ActionOutside;
            Islander_StartWandering();
            return;
        }

        islander->reaction_anim_id = 0;
        islander->mood_level--;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        }
        Islander_OnMoodChanged();

        if ((islander->emotion == ISLANDER_EMOTION_NEUTRAL) ||
            (islander->emotion == ISLANDER_EMOTION_HAPPY)) {
            islander->direction = 0;
            Islander_SpawnReactionEffect(1, 0x30);
            islander->click_cooldown_timer = 0x30;
            return;
        }

        if (islander->reward_adjust == 0) {
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
        } else {
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
        }
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
}

/* Original address: 0x020223AC */
void Islander_StartFieldObjectInteraction(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];

    islander->anim_frame = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->item_work.held_item.type_idx = 0;
    islander->tree_action_cooldown_timer = 0;
    if (((islander->equipped_tool_state & 0xF) != 2) && ((islander->equipped_tool_state & 0xF) != 6)) {
        islander->action_state = 0;
        field_object->shake_animation_paused = 1;
        field_object->action_state = 1;
    } else {
        field_object->shake_animation_paused = 0;
        islander->action_state = 1;
    }
    islander->move_action = MoveAction12;
}

void Islander_MoveAction11_State0(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];

    if ((islander->anim_frame != 0) && (islander->anim_timer == 1)) {
        field_object->anim_frame = gMoveAction11ObjectAnimFrames[islander->anim_frame - 1];
    }
    if (Islander_PlayAnim(1) != 0) {
        islander->tree_action_cooldown_timer = 600;
        islander->action_state = 0;
        field_object->anim_frame = 3;
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->item_work.held_item.type_idx = 1;
        islander->target_field_object_idx = 0;
        Islander_AdjustAnimForTool();
        islander->item_work.held_item.type_idx = 1;
        islander->target_action = 0x50;
        islander->move_action = MoveAction4;
        IslanderMoveAction_MoveToTarget();
    }
}

/* Original address: 0x020224D8 */
void Islander_MoveAction11_State1(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->target_field_object_idx];
    Entity *entity;
    EntitySpawnParams *spawn_params;
    u16 *tiles;
    s32 spawn_idx;
    s32 random;
    s32 entity_tile_idx;
    s32 map_tile_offset;
    s32 tile_marker;
    u32 tile;

    if (Islander_PlayAnim(1) != 0) {
        if ((field_object->hits_remaining == 0) || (field_object->hits_remaining & 0x80)) {
            islander->tree_action_cooldown_timer = 0x20;
            islander->action_state = 2;
        } else {
            islander->move_action = MoveAction11;
            Islander_StartFieldObjectInteraction();
        }
    }

    if ((islander->anim_frame != 3) || (islander->anim_timer != 1)) {
        return;
    }

    if ((field_object->favorite_hour_item_eligible == 1) && (islander->favorite_hour_item_spawned == 0) &&
        (islander->item_work.held_item.type_idx == 0) &&
        (field->last_palette_hour == gIslanderFavoriteHours[islander->islander_npc_idx]) &&
        ((rand_u16(&gGameState) % 101) <= 24)) {
        if (field_object->layer == 0) {
            tile = field->fg_tiles[0][field_object->tile_idx + 0x10];
        } else {
            tile = field->fg_tiles[1][field_object->tile_idx + 0x10];
        }
        if (tile == 0xFFF) {
            islander->item_work.held_item.type_idx = 1;
            spawn_idx = 0;
            if ((islander->equipped_tool_state & 0xF) == 6) {
                spawn_idx = 0x14;
            }
            spawn_idx += gMoveAction11EmotionSpawnOffsets[islander->emotion];
            spawn_idx += rand_u16(&gGameState) % 4;
            spawn_params = &gMoveAction11EntitySpawnParams[spawn_idx];
            spawn_idx = SpawnEntity(0, 2, spawn_params->type, spawn_params->param);
            if (spawn_idx != 0) {
                if (field_object->layer == 0) {
                    field->fg_tiles[0][islander->tile_idx] = 0x3333;
                } else {
                    field->fg_tiles[1][islander->tile_idx] = 0x3333;
                }
                entity = &g_EntityTable[spawn_idx];
                entity->base_y = (entity->y + 0x20) << 8;
                entity->landing_tile = field_object->tile_idx + 0x10;
                if (field_object->layer != 0) {
                    entity->landing_tile |= 0x1000;
                }
                entity->landing_delay_timer = 0x35;
                entity->y -= 0x20;
                entity->x = field_object->x - 8;
                islander->favorite_hour_item_spawned = 1;
            }
        }
    }
    field_object->action_state = 1;
    field_object->hits_remaining--;
    Sound_PlayEffect0(0);
}
void Islander_MoveAction11_State2(void) {
    Islander_AGB *islander = &gIslander;
    u16 next_timer;

    next_timer = (islander->tree_action_cooldown_timer = islander->tree_action_cooldown_timer - 1);
    if (next_timer == 0) {
        islander->tree_action_cooldown_timer = 600;
        islander->item_work.held_item.type_idx = next_timer;
        islander->action_state = 0;
        if (islander->emotion == ISLANDER_EMOTION_ANGRY) {
            islander->mood_level++;
            if (islander->mood_level > 6) {
                islander->mood_level = 6;
            }
            Islander_OnMoodChanged();
        }
        islander->target_x = islander->accepted_x;
        islander->target_y = islander->accepted_y;
        islander->item_work.held_item.type_idx = 1;
        islander->target_action = 0x50;
        islander->reaction_anim_id = ISLANDER_ANIM_59;
        IslanderMoveAction_UpdateEmotion();
    }
}

extern Islander_SUB_MOVE_PROC sIslanderMoveAction11SubMoveProcs[];

/* Original address: 0x0202275C */
void Islander_UpdateFieldObjectInteraction(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderMoveAction11SubMoveProcs[islander->action_state]();
}

void Islander_Fishing_Init(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_38;
    } else {
        islander->anim_id = ISLANDER_ANIM_41;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->action_state = 0;
    islander->move_action = MoveActionFishing;
}

void Islander_Fishing_State0(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;
    u8 *anim_timer;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_39;
        } else {
            islander->anim_id = ISLANDER_ANIM_42;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_timer = anim_data->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->item_work.held_item.tile_no = 0x20;
        islander->action_state = 1;
    }
    anim_timer = &islander->anim_timer;
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        Sound_PlayEffect0(0x14);
    }
}

void Islander_Fishing_State1(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->anim_frame = 0;
        islander->item_work.held_item.tile_no = 0x30;
        islander->item_work.held_item.type_idx = timer;
        Islander_SpawnReactionEffect(0, 0x30);
        islander->action_state = 2;
    }
}

void Islander_Fishing_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (--islander->item_work.held_item.tile_no == 0) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_3A;
        } else {
            islander->anim_id = ISLANDER_ANIM_43;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->action_state = 3;
        Sound_PlayEffect1(0x15);
        islander->item_work.held_item.tile_no = 0x51;
    }
}

void Islander_Fishing_State3(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->item_work.held_item.tile_no = timer;
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_3B;
        } else {
            islander->anim_id = ISLANDER_ANIM_44;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = Islander_GetFishingItem();
        islander->action_state = 4;
        Sound_StopEffect1(0x15);
        Sound_PlayEffect0(0x16);
    }
}

void Islander_Fishing_State4(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }
    Sound_PlayEffect0(0x1C);
    if (islander->item_work.held_item.type_idx == 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
    } else {
        if ((islander->held_item_sprite & 0xFFFF) == 0x434E) {
            islander->mood_level--;
            if (islander->mood_level & 0x80) {
                islander->mood_level = 0;
            }
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if ((islander->held_item_sprite & 0xFFFF) == 0x4350) {
            islander->mood_level++;
            if (islander->mood_level > 6) {
                islander->mood_level = 6;
            }
            Islander_SpawnReactionEffect(3, 0x30);
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3F;
            } else {
                islander->anim_id = ISLANDER_ANIM_48;
            }
        } else if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
        Islander_OnMoodChanged();
    }
    anim_data = *gIslanderAnimData[islander->anim_id];
    islander->action_state = 6;
    islander->item_work.held_item.tile_no = 0;
    islander->anim_frame = 0;
    islander->anim_timer = anim_data->duration;
}

void Islander_Fishing_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            islander->mood_level = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->move_action = ActionOutside;
            Islander_StartWandering();
        }
        islander->held_item_sprite = 0;
    }
}

void Islander_Fishing_State6(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        islander->fishing_cooldown_timer = 0x708;
        if (islander->item_work.held_item.type_idx == 0) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3C;
            } else {
                islander->anim_id = ISLANDER_ANIM_45;
            }
            islander->action_state = 5;
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_3D;
            } else {
                islander->anim_id = ISLANDER_ANIM_46;
            }
            islander->action_state = 7;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->item_work.held_item.tile_no = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
    }
}

void Islander_Fishing_State7(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        Islander_ChooseNewMoveDirection(1);
        islander->held_item_sprite = 0;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
    }
}

void IslanderMoveAction_Fishing(void) {
    extern Islander_SUB_MOVE_PROC sIslanderFishingSubMoveProcs[];

    Islander_AGB *islander = &gIslander;

    sIslanderFishingSubMoveProcs[islander->action_state]();
}

void Islander_ReceiveItem_Init(void) {
    Islander_AGB *islander = &gIslander;

    islander->anim_frame = 0;
    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_4A;
    } else {
        islander->anim_id = ISLANDER_ANIM_4F;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->held_item_sprite = 0x800000;
    islander->action_state = 0;
    islander->move_action = MoveActionReceiveItem;
}

extern Islander_SUB_MOVE_PROC sIslanderReceiveItemSubMoveProcs[];

void IslanderMoveAction_ReceiveItem(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderReceiveItemSubMoveProcs[islander->action_state]();
}

void Islander_DespawnFlyingItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 *anim_timer;
    u8 anim_timer_value;
    Entity *entity;
    AnimFrameData *anim_data;
    s32 anim_finished;

    if (islander->held_item_sprite == 0) {
        islander->move_action = ActionOutside;
        Islander_StartWandering();
        return;
    }
    anim_timer_value = islander->anim_timer;
    anim_timer = &islander->anim_timer;
    if (anim_timer_value == 0) {
        if (islander->anim_frame == 2) {
            Sound_PlayEffect0(0x1A);
        }
        if (islander->anim_frame == 4) {
            Sound_PlayEffect0(0x1B);
        }
        if (islander->anim_frame == 8) {
            Sound_PlayEffect0(0x1C);
        }
    }
    anim_finished = Islander_PlayAnim(1);
    if (anim_finished != 0) {
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_4C;
            } else {
                islander->anim_id = ISLANDER_ANIM_51;
            }
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_4D;
            } else {
                islander->anim_id = ISLANDER_ANIM_52;
            }
            Islander_SpawnReactionEffect(3, 0x30);
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        *anim_timer = anim_data->duration;
        islander->action_state = 1;
        return;
    }

    entity = &g_EntityTable[islander->floating_balloon_target_entity_id];
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        islander->held_item_sprite = 0x800000;
        field->entity_active[islander->floating_balloon_target_entity_id + 3] = anim_finished;
        islander->item_work.held_item.tile_no = entity->item_type_indices[entity->frame_index];
        islander->item_work.held_item.type_idx = entity->item_ids[entity->frame_index];
        islander->flying_item_spawn_timer = 0x2A30;
        islander->flying_item_spawn_timer += (rand_u16(&gGameState) % 109) * 100;
        islander->flying_item_x = anim_finished;
        islander->flying_item_y = anim_finished;
        islander->floating_balloon_target_entity_id = 0;
        islander->held_item_sprite |= (g_ItemDefinitions + islander->item_work.held_item.tile_no)->held_item_oam_attr2;
    }
}

void Islander_StoreHeldItem(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        Islander_StoreItem(islander->item_work.held_item.tile_no,
                           islander->item_work.held_item.type_idx);
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_4B;
        } else {
            islander->anim_id = ISLANDER_ANIM_50;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
        islander->action_state = 2;
    }
}

void Islander_ProcessFishReceived(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        Islander_ChooseNewMoveDirection(1);
        if ((islander->held_item_sprite & 0xFFFF) == 0x609E) {
            islander->mood_level = 0;
            islander->held_item_sprite = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
            return;
        }
        islander->held_item_sprite = 0;
        islander->move_action = ActionOutside;
        Islander_StartWandering();
    }
}

void IslanderMoveAction_Dig(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_28;
    } else {
        islander->anim_id = ISLANDER_ANIM_30;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->action_state = 0;
    islander->move_action = MoveActionBury;
}

void Islander_BuryItem_State0(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 tile_idx = islander->interaction_tile;
    bool32 dug_empty = FALSE;
    u16 *tilemap_vram;
    ItemGroupStruct *definition;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 3) {
            Sound_PlayEffect0(0x21);
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->item_work.held_item.type_idx = 0;
    if (islander->interaction_tile & 0x8000) {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
        if (field->fg_tiles[1][tile_idx] == 0xFFF) {
            dug_empty = 1;
        } else {
            islander->item_work.held_item.type_idx = field->fg_tiles[1][tile_idx];
            if (islander->item_work.held_item.type_idx > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[1][tile_idx] = 0x7777;
    } else {
        tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
        if (field->fg_tiles[0][tile_idx] == 0xFFF) {
            dug_empty = 1;
        } else {
            islander->item_work.held_item.type_idx = field->fg_tiles[0][tile_idx];
            if (islander->item_work.held_item.type_idx > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[0][tile_idx] = 0x7777;
    }

    tilemap_vram += (tile_idx & 0xF0) * 4;
    tilemap_vram += (tile_idx & 0xF) * 2;
    WriteItemTileToVRAM(tilemap_vram, 0x12AC);
    if (dug_empty == FALSE) {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_2B;
        } else {
            islander->anim_id = ISLANDER_ANIM_33;
        }
        definition = g_ItemDefinitions + islander->item_work.held_item.type_idx;

        islander->held_item_sprite = 0x800000;
        islander->held_item_sprite |= definition->held_item_oam_attr2;
        islander->action_state = 2;
    } else {
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_2A;
        } else {
            islander->anim_id = ISLANDER_ANIM_32;
        }
        islander->action_state = 1;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
}

void Islander_BuryItem_State1(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Island_agb_c *island;
    mActor_name_t item;
    u8 tile_idx = islander->interaction_tile;
    s32 is_tree;
    s32 item_type;
    ItemGroupStruct *definition;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    is_tree = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    if (islander->direction == 0) {
        islander->anim_id = ISLANDER_ANIM_29;
    } else {
        islander->anim_id = ISLANDER_ANIM_31;
    }
    islander->action_state = 4;
    islander->buried_item_tile_base = 0x1270;

    if (islander->emotion == ISLANDER_EMOTION_HAPPY) {
        islander->mood_level--;
        if (islander->mood_level & 0x80) {
            islander->mood_level = 0;
        }
        Islander_OnMoodChanged();

        if (islander->stored_item_type_plus_one[0] != 0) {
            item_type = islander->stored_item_type_plus_one[0];
            item_type--;
            definition = &g_ItemDefinitions[item_type];
            islander->held_item_sprite = definition->held_item_oam_attr2 | 0x800000;
            item = islander->stored_item_ids[0];
            if (Item_GetItemIdFromTileId(item_type) != 0) {
                item = Item_GetItemIdFromTileId(item_type);
                is_tree = 1;
            }
            Islander_ClearStoredItem(0);
        } else {
            Islander_PlantRandomFlower();
            return;
        }
    } else if ((s32)rand_u16(&gGameState) % 101 <= 49) {
        islander->held_item_sprite = 0x80609E;
        item = Item_TypeToIslandItem(0x11);
    } else {
        islander->held_item_sprite = 0x8050C0;
        item = 0x2512;
        islander->mood_level++;
        if (islander->mood_level > 6) {
            islander->mood_level = 6;
        }
        Islander_OnMoodChanged();
    }

    if (!(islander->interaction_tile & 0x8000)) {
        field->fg_tiles[0][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[0][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    } else {
        field->fg_tiles[1][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[1][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    }
}

void Islander_BuryItem_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2D;
            } else {
                islander->anim_id = ISLANDER_ANIM_35;
            }
            islander->mood_level = 0;
            islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
        } else if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FOSSIL) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_SEEDLING_DIARY_TICKET_GRAB_BAG) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_PITFALL) ||
                   IS_ITEM_TYPE_TOOL(islander->item_work.held_item.type_idx) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_AIR_CHECK) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_FLOWER_BAG)) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2F;
            } else {
                islander->anim_id = ISLANDER_ANIM_37;
            }
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2E;
            } else {
                islander->anim_id = ISLANDER_ANIM_36;
            }
            Islander_SpawnReactionEffect(3, 0x30);
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->action_state = 5;
        Sound_PlayEffect0(0x1C);
    }
}

/* Ghidra name: Islander_BuryItem (differs; duplicate label, state 3 of the bury action). */
void Islander_BuryItem_State3(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FURNITURE) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_GYROID) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_TURNIP) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_MUSHROOM) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CANDY) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_100_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_SHIRT) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_1K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_10K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_30K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CARPET) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_WALLPAPER) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_NES)) {
            Islander_BuryRandomItem(islander->item_work.held_item.type_idx);
        }
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            Islander_PlantRandomFlower();
        } else {
            if ((islander->buried_item_tile_base != 0x3260) && (islander->buried_item_tile_base != 0x3268)) {
                islander->buried_item_tile_base = 0x1270;
            }
        }
        if (islander->direction == 0) {
            islander->anim_id = ISLANDER_ANIM_29;
        } else {
            islander->anim_id = ISLANDER_ANIM_31;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->action_state = 4;
    }
}

/* Original address: 0x020234B0 */
void Islander_BuryItem_State4(void) {
    Islander_AGB *islander = &gIslander;
    u8 tile_idx = islander->interaction_tile;
    u8 *tilemap_vram;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 0xE) {
            if (!(islander->interaction_tile & 0x8000)) {
                tilemap_vram = (u8 *)BG_SCREEN_ADDR(24);
            } else {
                
                tilemap_vram = (u8 *)BG_SCREEN_ADDR(25);
            }
            tilemap_vram += (tile_idx & 0xF0) * 8;
            tilemap_vram += (tile_idx & 0xF) * 4;
            WriteItemTileToVRAM((u16*)tilemap_vram, 0x200);
        }
    }
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 1) {
            Sound_PlayEffect0(0x1E);
        }
        if (islander->anim_frame == 0xA) {
            Sound_PlayEffect0(0x22);
        }
        if (islander->anim_frame == 0x11) {
            Sound_PlayEffect0(0x23);
        }
    }

    if (Islander_PlayAnim(1) != 0) {
        islander->held_item_sprite = 0;
        islander->dig_target_layer = 0;
        islander->dig_target_tile_idx = 0;
        if (!(islander->interaction_tile & 0x8000)) {
            tilemap_vram = (u8 *)BG_SCREEN_ADDR(24);
        } else {
            
            tilemap_vram = (u8 *)BG_SCREEN_ADDR(25);
        }
        tilemap_vram += (tile_idx & 0xF0) * 8;
        tilemap_vram += (tile_idx & 0xF) * 4;
        WriteItemTileToVRAM((u16*)tilemap_vram, islander->buried_item_tile_base);
        islander->digging_cooldown_timer = 0x78;
        if (islander->buried_item_tile_base != 0x1270) {
            Sound_PlayEffect0(0x24);
        }

        if (islander->reaction_anim_id == ISLANDER_ANIM_ANGRY) {
            islander->collision_retry_count = 0;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->target_action = 0x50;
            islander->mood_level = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->move_action = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->target_action = 0x50;
            islander->collision_retry_count = 0;
            islander->anim_frame = 0;
            islander->anim_timer = 0;
            Islander_AdjustAnimForTool();
            islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
            islander->target_x = islander->accepted_x;
            islander->target_y = islander->accepted_y;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->move_action = MoveAction4;
            IslanderMoveAction_MoveToTarget();
        }
        islander->interaction_tile = 0;
    }
}

void Islander_BuryItem_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->anim_id == ISLANDER_ANIM_2F) ||
            (islander->anim_id == ISLANDER_ANIM_37)) {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_29;
            } else {
                islander->anim_id = ISLANDER_ANIM_31;
            }
            islander->action_state = 4;
            islander->buried_item_tile_base = 0x1270;
        } else {
            if (islander->direction == 0) {
                islander->anim_id = ISLANDER_ANIM_2C;
            } else {
                islander->anim_id = ISLANDER_ANIM_34;
            }
            islander->action_state = 3;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
    }
}

void IslanderMoveAction_Bury(void) {
    Islander_AGB* islander = &gIslander;

    IslanderSubMoveAction_BuryProcTbl[islander->action_state]();
}

void Islander_MoveAction20_Init(void) {
    Islander_AGB* islander = &gIslander;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->item_work.move_action20.phase = 0;
    islander->item_work.move_action20.timer = 0;
    islander->anim_id = ISLANDER_ANIM_5E;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->carry_wait_timer = 0x2A30;
    islander->target_x = 0;
    islander->target_y = 0;
    islander->accepted_x = islander->x;
    islander->accepted_y = islander->y;
    islander->action_state = 0;
    islander->move_action = MoveAction20;
}

void Islander_MoveAction20_State0(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->carry_state == 2) {
        islander->item_work.move_action20.phase = 0;
        islander->item_work.move_action20.timer = 0;
        islander->action_state = 3;
        return;
    }

    Islander_PlayAnim(0);
    islander->carry_wait_timer--;
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 2) {
            Islander_SpawnReactionEffect(4, 0x20);
            Sound_PlayEffect0(0x25);
        }
    }

    if (islander->carry_wait_timer & 0x8000) {
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        islander->carry_state = 1;
        islander->item_work.move_action20.phase = 0;
        islander->action_state = 1;
    }
}

void Islander_MoveAction20_State1(void) {
    Islander_AGB* islander = &gIslander;
    IslandBuilding* house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    Player* player = &gPlayer;
    s32 player_y;
    u16 phase;

    phase = (islander->item_work.move_action20.phase += 0x1111);
    if (phase == 0xFFFF) {
        islander->x = house->x << 8;
        player_y = house->y << 8;
        islander->y = player_y + 0x1000;
        player->y = player_y;
        player->x = islander->x + 0x1000;
        gGameState.bg1_hofs = (player->x >> 8) - 0x80;
        gGameState.bg1_vofs = (player->y >> 8) - 0x50;
        if (gGameState.bg1_vofs & 0x800) {
            gGameState.bg1_vofs = 0;
        }
        if (gGameState.bg1_vofs > 0x60) {
            gGameState.bg1_vofs = 0x60;
        }
        if (gGameState.bg1_hofs & 0x800) {
            gGameState.bg1_hofs = 0;
        }
        if (gGameState.bg1_hofs > 0x100) {
            gGameState.bg1_hofs = 0x100;
        }
        gGameState.bg2_hofs = gGameState.bg1_hofs;
        gGameState.bg2_vofs = gGameState.bg1_vofs;
        islander->action_state = 2;
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State2(void) {
    Islander_AGB* islander = &gIslander;
    IslandFieldWork* island_field = &gIslandFieldWork;
    u32 mosaic;

    mosaic = (islander->item_work.move_action20.phase -= 0x1111);
    if (mosaic == 0) {
        gGameState.bg1cnt ^= 0x40;
        gGameState.bg2cnt ^= 0x40;
        gGameState.bg3cnt ^= 0x40;
        islander->carry_state = 0;
        islander->target_x = mosaic;
        islander->target_y = mosaic;
        islander->tile_idx = island_field->special_tile_idx;
        islander->mood_level = 0;
        islander->target_action = 0x80;
        islander->reaction_anim_id = ISLANDER_ANIM_ANGRY;
        islander->emotion = ISLANDER_EMOTION_ANGRY;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State3(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->carry_state == 1) {
        islander->item_work.move_action20.timer = 0x10;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->action_state = 4;
    }
}
void Islander_MoveAction20_State4(void) {
    Islander_AGB* islander = &gIslander;
    s32 collision;
    s32 i;

    islander->item_work.move_action20.timer--;
    if ((islander->item_work.move_action20.timer & 0x8000) == 0) {
        return;
    }

    switch ((IslanderMoveAction20Phase)islander->item_work.move_action20.phase) {
    case ISLANDER_MOVE_ACTION20_PHASE_BEGIN:
        Islander_SpawnReactionEffect(1, 0x30);
        islander->anim_frame = 0;
        islander->anim_timer = 0;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x30;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_02:
        islander->anim_id = ISLANDER_ANIM_02;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_06:
        islander->anim_id = ISLANDER_ANIM_06;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_00:
        islander->anim_id = ISLANDER_ANIM_00;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x10;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_CHECK_POSITION:
        islander->work_x = islander->accepted_x - islander->x;
        islander->work_y = islander->accepted_y - islander->y;
        if (islander->work_x < 0) {
            islander->work_x = -islander->work_x;
        }
        if (islander->work_y < 0) {
            islander->work_y = -islander->work_y;
        }
        if (islander->work_x <= 0x2000 && islander->work_y <= 0x2000) {
            islander->item_work.move_action20.timer = 2;
            islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
            return;
        }

        Islander_UpdateCollisionTiles(islander->direction);
        for (i = 0; i < 4; i++) {
            collision = CheckSurroundingCollision(islander->surrounding_item_types[i], (u16*)islander->collision_tilemap);
            if (collision != 0) {
                islander->item_work.move_action20.timer = 2;
                islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
                return;
            }
        }

        islander->reaction_anim_id = ISLANDER_ANIM_59;
        if (islander->mood_level < 3) {
            islander->mood_level = 3;
            Islander_OnMoodChanged();
        }
        islander->target_action = collision;
        islander->carry_state = collision;
        islander->move_action = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_RESTART:
        islander->accepted_x = islander->x;
        islander->accepted_y = islander->y;
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->action_state = 1;
        break;
    }
}

void Islander_MoveAction20_Move(void) {
    extern Islander_SUB_MOVE_PROC sIslanderMoveAction20SubMoveProcs[];

    Islander_AGB* islander = &gIslander; // I don't know why I have to pull this out to match, but I do
    sIslanderMoveAction20SubMoveProcs[(u8)islander->action_state]();
}

/* Original address: 0x02023B58 */
void Islander_Draw(void) {
    Islander_AGB* islander = &gIslander;
    OAMData* source;
    s32 sprite_count;

    islander->work_y = islander->y >> 8;
    islander->work_x = islander->x >> 8;
    source = gIslanderAnimData[islander->anim_id][islander->anim_frame]->sprite_gfx_p;

    if (islander->anim_timer == 0xFE) {
        return;
    }

    sprite_count = 0;
    if (source->affine_param == 0xFFFF) {
        return;
    }

    do {
        OAMData* oam = &((OAMData*)gUnk3002410)[gGameState.oam_count];
        u32 x;
        u8 state;

        oam->y = source->y + islander->work_y - gGameState.bg2_vofs;
        oam->obj_mode = source->obj_mode;
        oam->bpp = source->bpp;
        oam->shape = source->shape;
        oam->h_flip = source->h_flip;
        oam->v_flip = source->v_flip;
        oam->size = source->size;
        oam->mosaic = TRUE;

        x = source->x;
        if (gIslanderAnimMirrorFlags[islander->anim_id] != FALSE) {
            oam->h_flip = source->h_flip ^ TRUE;
            x = ~x;
            x++;
            if (oam->shape == 0 && oam->size == 1) {
                x -= 16;
            } else {
                x -= 8;
            }
        }

        oam->x = x + islander->work_x - gGameState.bg2_hofs;
        oam->priority = 1;
        oam->palette_num = source->palette_num;
        oam->tile_num = source->tile_num;

        {
            u32 tile_override = islander->held_item_sprite;

            if ((tile_override & 0xFFFF0000) != 0 && (tile_override & 0xFFFF) != 0 &&
                oam->tile_num == ((tile_override >> 16) & 0xFFFF)) {
                tile_override &= 0xFFF;
                oam->tile_num = tile_override;
                oam->palette_num = (islander->held_item_sprite & 0xF000) >> 12;
            }
        }

        state = islander->equipped_tool_state & 0xF;
        if ((state == 6 || state == 8 || state == 5 || state == 7) && oam->palette_num == 2) {
            oam->palette_num = 8;
        }

        if ((u8)(islander->move_action - ISLANDER_MOVE_ACTION_UPDATE_WANDERING) <= 1) {
            if (islander->direction == 0) {
                if (source->tile_num == 0x40 || source->tile_num == 0x42) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->blink_frame == 0) {
                            oam->tile_num = 0x40;
                        } else {
                            oam->tile_num = 0x42;
                        }
                        break;
                    case 1:
                        oam->tile_num = 0x44;
                        break;
                    case 2:
                        oam->tile_num = 0x46;
                        break;
                    case 3:
                        oam->tile_num = 0x48;
                        break;
                    }
                }
            } else {
                if (((islander->direction >= 1 && islander->direction <= 2) || islander->direction == 6 || islander->direction == 7) &&
                    (source->tile_num == 0 || source->tile_num == 2)) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->blink_frame == 0) {
                            oam->tile_num = 0;
                        } else {
                            oam->tile_num = 2;
                        }
                        break;
                    case 1:
                        oam->tile_num = 4;
                        break;
                    case 2:
                        oam->tile_num = 6;
                        break;
                    case 3:
                        oam->tile_num = 8;
                        break;
                    }
                }
            }
        }

        gGameState.oam_count++;
        sprite_count++;
        source++;
        if (sprite_count > 0x21) {
            return;
        }
    } while (source->affine_param != 0xFFFF);
}
