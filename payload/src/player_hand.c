#include "player_hand.h"
#include "sound.h"
#include "anim.h"
#include "game.h"
#include "island_field.h"
#include "building.h"
#include "islander.h"
#include "entity.h"

/* Original address: 0x02034ED4 */
extern AnimFrameData** sPlayerHandAnimations[4];

static inline u16 PlayerHand_GetTerrainTile(u16 *tilemap) {
    return *tilemap & 0x3FF;
}

/* Original address: 0x020259C8 */
s32 PlayerHand_IsItemPlacementBlocked(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 *tilemap = NULL;
    u16 item = 0;
    u16 terrain;
    u16 tmp;

    player->tile_idx = (player->work_y & ~0xF) | ((player->work_x & 0xF0) >> 4);
    if (!(player->work_x & 0xFF00)) {
        if (field->fg_tiles[0][player->tile_idx] != 0xFFF &&
            field->fg_tiles[0][player->tile_idx] != 0x7777) {
            return 1;
        }
        if (islander->dig_target_layer == 0 && player->tile_idx == islander->dig_target_tile_idx) {
            return 1;
        }
        if (field->fg_tiles[0][player->tile_idx] == 0xFFF ||
            (player->held_item_layer == 0 && player->tile_idx == player->held_item_tile_idx)) {
            field->fg_tiles[0][player->tile_idx] = 0xFFF;
            item = field->fg_tiles[0][player->tile_idx];
            tilemap = (u16 *)BG_SCREEN_ADDR(20);
            tilemap += (player->tile_idx & 0xF0) * 4;
            tilemap += (player->tile_idx & 0xF) * 2;
        }
    } else {
        if (field->fg_tiles[1][player->tile_idx] != 0xFFF &&
            field->fg_tiles[1][player->tile_idx] != 0x7777) {
            return 1;
        }
        if (islander->dig_target_layer != 0 && player->tile_idx == islander->dig_target_tile_idx) {
            return 1;
        }
        if (field->fg_tiles[1][player->tile_idx] == 0xFFF ||
            (player->held_item_layer != 0 && player->tile_idx == player->held_item_tile_idx)) {
            field->fg_tiles[1][player->tile_idx] = 0xFFF;
            item = field->fg_tiles[1][player->tile_idx];
            tilemap = (u16 *)BG_SCREEN_ADDR(21);
            tilemap += (player->tile_idx & 0xF0) * 4;
            tilemap += (player->tile_idx & 0xF) * 2;
        }
    }
    tmp = 0x3FF;
    if (CheckSurroundingCollision(item, tilemap) == 0) {
        if (((*tilemap & tmp) > 5 && ((*tilemap & tmp) > 0x15 || (*tilemap & tmp) < 0x10) && (*tilemap & tmp) != 0x82 && (*tilemap & tmp) <= 0xAF) ||
            ((*tilemap & 0x3FF) == 0x13)) {
            IslandBuilding *building = &gIslandBuildings[1];
            s32 cursor_x = (player->x >> 8) - 8;
            player->work_x = building->interaction_x - cursor_x;
            player->work_y = building->interaction_y - (player->y >> 8);
            if (player->work_x < 0) {
                player->work_x = -player->work_x;
            }
            if (player->work_y < 0) {
                player->work_y = -player->work_y;
            }
            if (player->work_x > 0x20 || player->work_y > 0x20) {
                return 0;
            }
        }
    } else {
        terrain = PlayerHand_GetTerrainTile(tilemap);
        if (terrain >= 0xBC && terrain <= 0xBF) {
            return 0;
        }
        if (terrain >= 0xC6 && terrain <= 0xCB) {
            return 0;
        }
    }
    return 1;
}

/* Original address: 0x02025B94 */
s32 PlayerHand_IsNearInteractionTarget(s32 x, s32 y, u16 range) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    s32 dx = player->x - islander->x;
    s32 dy;

    if (dx < 0) {
        dx = -dx;
    }
    if (dx <= 0x2FFF) {
        dx = player->x - x;
        dy = player->y - y;
        if (dx < 0) {
            dx = -dx;
        }
        if (dy < 0) {
            dy = -dy;
        }
        dx >>= 8;
        dy >>= 8;
        if (dx <= range && dy <= range) {
            return 1;
        }
    }
    return 0;
}

/* Original address: 0x02025BEC */
s32 PlayerHand_CheckHouseDoorInteraction(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandBuilding *building = &gIslandBuildings[1];

    player->near_house_door = 0;
    if (PlayerHand_IsNearInteractionTarget(building->interaction_x << 8, building->interaction_y << 8, 0x10U) != 0) {
        player->near_house_door = 1;
    }
    if (islander->move_action == 1) {
        if ((player->near_house_door != 0) && (islander->anim_timer == 0xFE)) {
            islander->anim_timer = 4;
            building->state = 0;
            player->near_house_door = 0;
        }
        return 1;
    }
    return 0;
}

/* Original address: 0x02025C4C */
s32 PlayerHand_TryInteractWithIslander(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;

    if (islander->collision_bypass_timer == 0 && islander->move_action == 3) {
        islander->target_x = player->x;
        islander->target_y = player->y;
    }
    if (islander->move_action == 3) {
        if (PlayerHand_IsNearInteractionTarget(islander->x, islander->y, 8)) {
            islander->reaction_anim_id = 1;
            Islander_SpawnReactionEffect(2, 0x30);
            if (islander->equipped_tool_state != 0) {
                islander->equipped_tool_state |= 0x40;
                islander->reaction_anim_id = 0;
            }
            player->near_house_door = 0;
            islander->move_action = 10;
            islander->click_cooldown_timer = 0x30;
            player->action_state = 0;
            PlayerHand_ResetToIdle();
            return 1;
        }
    } else if (islander->move_action == 20 && islander->action_state == 0 &&
               PlayerHand_IsNearInteractionTarget(islander->x, islander->y, 16)) {
        Sound_PlayEffect0(3);
        islander->carry_state = 2;
        player->action_state = 2;
        PlayerHand_BeginCarrying();
        return 1;
    }
    return 0;
}

/* Original address: 0x02025D1C */
s32 PlayerHand_TrySelectIslanderTarget(void) {
    u8 temp_r0_29010;

    if ((gIslander.move_action == 3) && ((temp_r0_29010 = gIslander.equipped_tool_state, (temp_r0_29010 == 1)) || (temp_r0_29010 == 5)) && (PlayerHand_IsNearInteractionTarget(gIslander.flying_item_x, gIslander.flying_item_y, 0x10U) != 0)) {
        gIslander.move_action = 9;
        gIslander.target_x = (s32) gIslander.flying_item_x;
        gIslander.target_y = (s32) gIslander.flying_item_y;
        gIslander.reaction_anim_id = 0;
        gIslander.interaction_target_is_islander = 1;
        return 1;
    }
    return 0;
}

/* Original address: 0x02025D70 */
void PlayerHand_Init(void) {
    Player *player = &gPlayer;

    player->x = 0xF800;
    player->y = 0x8800;
    player->saved_x = 0xF800;
    player->saved_y = 0x8800;
    player->anim_frame = 0;
    player->anim_timer = 0;
    player->anim_id = 0;
    player->interaction_attempt_active = 0;
    player->held_item_oam_attr2 = 0;
    player->tile_idx = 0;
    player->held_item = 0;
    player->held_item_type_idx = 0;
    player->placement_input_delay = 0;
    player->near_house_door = 0;
    player->interaction_cooldown_timer = 0;
    player->work_y = 0;
    player->work_x = 0;
    player->held_item_layer = 0;
    player->held_item_tile_idx = 0;
    player->left_neighbor_tile_idx = 0;
    player->right_neighbor_tile_idx = 0;
    player->action_state = 0;
}

static inline void PlayerHand_UpdateCamera(Player *player) {
    GameState *camera = &gGameState;
    s32 camera_y;
    camera->bg1_hofs = ((s32) player->x >> 8) - 0x80;
    camera_y = ((s32) player->y >> 8) - 0x50;
    camera->bg1_vofs = camera_y;
    if (camera_y & 0x800) {
        camera->bg1_vofs = 0;
    }
    if ((u32) camera->bg1_vofs > 0x60U) {
        camera->bg1_vofs = 0x60;
    }
    if (0x800 & camera->bg1_hofs) {
        camera->bg1_hofs = 0;
    }
    if ((u32) camera->bg1_hofs > 0x100U) {
        camera->bg1_hofs = 0x100;
    }
    camera->bg2_hofs = camera->bg1_hofs;
    camera->bg2_vofs = camera->bg1_vofs;
}

/* Original address: 0x02025DC8 */
void PlayerHand_UpdateMovement(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    GameState *game = &gGameState;

    s32 previous_y;
    s32 previous_y_down;
    s32 previous_x;
    s32 previous_x_right;

    if (0x400040 & game->keys.combined) {
        previous_y = player->y;
        player->y = previous_y - 0x180;
        if (0x100 & game->keys.buttons.held) {
            player->y = previous_y - 0x300;
        }
        if (player->y <= 0xE00) {
            player->y = 0xE00;
        }
    } else if (game->keys.combined & 0x800080) {
        previous_y_down = player->y;
        player->y = previous_y_down + 0x180;
        if (0x100 & game->keys.buttons.held) {
            player->y = previous_y_down + 0x300;
        }
        if (islander->carry_state == 0) {
            if (player->y > 0xF7FF) {
                player->y = 0xF800;
            }
        } else {
            if (player->y > 0xE7FF) {
                player->y = 0xE800;
            }
        }
    }
    if (0x200020 & gGameState.keys.combined) {
        previous_x = player->x;
        player->x = previous_x - 0x180;
        if (0x100 & gGameState.keys.buttons.held) {
            player->x = previous_x - 0x300;
        }
        if (player->x <= 0x600) {
            player->x = 0x600;
        }
    } else if (gGameState.keys.combined & 0x100010) {
        previous_x_right = player->x;
        player->x = previous_x_right + 0x180;
        if (0x100 & gGameState.keys.buttons.held) {
            player->x = previous_x_right + 0x300;
        }
        if (player->x > 0x1DFFF) {
            player->x = 0x1E000;
        }
    }
    PlayerHand_UpdateCamera(player);
}

/* Original address: 0x02025F60 */
void PlayerHand_ResetToIdle(void) {
    Player *player = &gPlayer;
    AnimFrameData *frame;

    player->anim_id = 0;
    frame = sPlayerHandAnimations[0][0];
    player->interaction_attempt_active = 0;
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    player->action_state = 1;
}

/* Original address: 0x02025F90 */
void PlayerHand_UpdateIdle(void) {
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item_type;
    ItemGroupStruct *definition;
    mActor_name_t item;
    AnimFrameData *frame;

    if ((player->interaction_cooldown_timer == 0 || --player->interaction_cooldown_timer == 0) && (gGameState.keys.buttons.pressed & 1)) {
        player->work_y = (player->y >> 8) & 0xFF0;
        player->work_x = (player->x >> 8) & 0xFF0;
        player->tile_idx = player->work_y | ((player->work_x & 0xF0) >> 4);
        if (!(player->work_x & 0xFF00)) {
            item_type = field->fg_tiles[0][player->tile_idx];
        } else {
            item_type = field->fg_tiles[1][player->tile_idx];
        }
        definition = &g_ItemDefinitions[item_type];
        if (item_type == 0xFFF || item_type == 0x7777 || item_type == 0x3333 ||
            definition->interaction_type == 0xFFF) {
            player->interaction_attempt_active = 1;
        } else {
            s32 buried = 0;
            if (!(player->work_x & 0xFF00)) {
                if ((gIslandData->deposit[0][player->tile_idx >> 4] >> (player->tile_idx & 0xF)) & 1) {
                    buried = 1;
                }
            } else {
                if ((gIslandData->deposit[1][player->tile_idx >> 4] >> (player->tile_idx & 0xF)) & 1) {
                    buried = 1;
                }
            }
            if (!buried) {
                item_type &= 0xFFF;
                definition = &g_ItemDefinitions[item_type];
                if (definition->held_item_oam_attr2 != 0xFFF) {
                    if (!((player->x >> 8) & 0xFF00)) {
                        field->fg_tiles[0][player->tile_idx] = 0x7777;
                        item = gIslandData->fgblock[0][0].items[player->tile_idx >> 4][player->tile_idx & 0xF];
                        gIslandData->fgblock[0][0].items[player->tile_idx >> 4][player->tile_idx & 0xF] = 0;
                        player->held_item_layer = 0;
                    } else {
                        field->fg_tiles[1][player->tile_idx] = 0x7777;
                        item = gIslandData->fgblock[0][1].items[player->tile_idx >> 4][player->tile_idx & 0xF];
                        gIslandData->fgblock[0][1].items[player->tile_idx >> 4][player->tile_idx & 0xF] = 0;
                        player->held_item_layer = 1;
                    }
                    player->held_item_tile_idx = player->tile_idx;
                    player->held_item_type_idx = item_type;
                    player->held_item_oam_attr2 = definition->held_item_oam_attr2;
                    player->held_item = item;
                    Sound_PlayEffect0(3);
                    player->action_state = 2;
                    PlayerHand_BeginCarrying();
                    return;
                }
            }
            player->interaction_attempt_active = 1;
        }
    }
    if (player->interaction_attempt_active == 0) {
        PlayerHand_UpdateMovement();
    } else if (player->anim_timer == 0) {
        player->anim_timer--;
    } else {
        player->anim_frame++;
        frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
        if ((u8)frame->action_flag != 0xFF) {
            player->anim_timer = frame->duration;
        } else if (PlayerHand_CheckHouseDoorInteraction() != 0) {
            Sound_PlayEffect0(2);
            player->action_state = 0;
            PlayerHand_ResetToIdle();
        } else if (PlayerHand_TryInteractWithIslander() == 0) {
            if (PlayerHand_TrySelectIslanderTarget() != 0) {
                player->action_state = 0;
                PlayerHand_ResetToIdle();
            } else {
                Sound_PlayEffect0(2);
                player->action_state = 0;
                PlayerHand_ResetToIdle();
            }
        }
    }
}

/* Original address: 0x0202622C */
void Field_RestoreNeighborTreeTile(u16 tile_idx, s32 x, u8 neighbor_tile, u8 acre, u8 right_side) {
    IslandFieldWork *field = &gIslandFieldWork;
    u16 item_type;
    u16 *tilemap;

    if (acre == 0) {
        item_type = field->fg_tiles[0][neighbor_tile];
    } else {
        item_type = field->fg_tiles[1][neighbor_tile];
    }
    if (!(x & 0xFF0000)) {
        tilemap = (u16*)BG_SCREEN_ADDR(24);
    } else {
        tilemap = (u16*)BG_SCREEN_ADDR(25);
    }
    tilemap += (tile_idx & 0xF0) * 4;
    tilemap += (tile_idx & 0xF) * 2;
    if (item_type == ITEM_TYPE_LARGE_TREE || item_type == ITEM_TYPE_LARGE_STUMP) {
        if (right_side == 0) {
            tilemap += 0x20;
            *tilemap = 0x328F;
        } else {
            tilemap += 0x21;
            *tilemap = 0x328C;
        }
    }
    if (item_type == ITEM_TYPE_FULLY_GROWN_TREE ||
        (u16)(item_type - ITEM_TYPE_FRUIT_APPLE_TREE) <= ITEM_TYPE_FRUIT_CHERRY_TREE - ITEM_TYPE_FRUIT_APPLE_TREE ||
        item_type == ITEM_TYPE_FULLY_GROWN_STUMP) {
        if (right_side == 0) {
            tilemap += 0x20;
            *tilemap = 0x3297;
        } else {
            tilemap += 0x21;
            *tilemap = 0x3294;
        }
    }
}

/* Original address: 0x020262DC */
void Field_RestoreAdjacentTreeTiles(u16 tile_idx, s32 x) {
    Player *player = &gPlayer;
    player->left_neighbor_tile_idx = (tile_idx & 0xF) - 1;
    player->right_neighbor_tile_idx = (tile_idx & 0xF) + 1;
    player->left_neighbor_tile_idx &= 0xF;
    player->right_neighbor_tile_idx &= 0xF;
    player->left_neighbor_tile_idx |= tile_idx & 0xF0;
    player->right_neighbor_tile_idx |= tile_idx & 0xF0;
    if (!(player->x & 0xFF0000)) {
        Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 0, 0);
        if (!(player->right_neighbor_tile_idx & 0xF)) {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 1, 1);
        } else {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 0, 1);
        }
    } else {
        Field_RestoreNeighborTreeTile(tile_idx, x, player->right_neighbor_tile_idx, 1, 1);
        if ((player->left_neighbor_tile_idx & 0xF) == 0xF) {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 0, 0);
        } else {
            Field_RestoreNeighborTreeTile(tile_idx, x, player->left_neighbor_tile_idx, 1, 0);
        }
    }
}

/* Original address: 0x020263A0 */
void PlayerHand_BeginCarrying(void) {
    Player *player = &gPlayer;
    Entity *entity = &g_EntityTable[2];
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    AnimFrameData *frame;

    player->anim_id = 1;
    frame = sPlayerHandAnimations[1][0];
    player->interaction_attempt_active = 0;
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    if (islander->carry_state == 0) {
        field->entity_active[2] = 1;
        Entity_Reset(2);
        entity->lifetime = 0x30;
        entity->x = (player->x >> 8) - 8;
        entity->y = (player->y >> 8) - 2;
        entity->sprite_tile = player->held_item_oam_attr2 & 0x3FF;
        entity->palette = player->held_item_oam_attr2 >> 12;
        entity->anim_id = 0;
        WriteItemToTile(player->x, player->tile_idx, 0, 0x200);
        Field_RestoreAdjacentTreeTiles(player->tile_idx, player->x);
    } else {
        islander->x = player->x;
        islander->y = player->y + 0x1200;
    }
    player->placement_input_delay = 0x20;
    player->action_state = 3;
}

/* Original address: 0x02026464 */
void PlayerHand_UpdateCarrying(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    Entity *entity = &g_EntityTable[2];
    AnimFrameData *frame;
    AnimFrameData *blocked_frame;

    if (islander->carry_state == 0) {
        if (player->held_item_layer == 0 && player->held_item_tile_idx == 0) {
            player->action_state = 0;
            PlayerHand_ResetToIdle();
            return;
        }
    }
    if ((player->placement_input_delay == 0 || --player->placement_input_delay == 0) &&
        (gGameState.keys.buttons.pressed & 1)) {
        if (islander->carry_state != 0) {
            player->work_x = ((player->x >> 8) - 8) & 0xFF0;
            player->work_y = ((player->y >> 8) + 0x18) & 0xFF0;
        } else {
            player->work_x = entity->x + 8;
            player->work_y = entity->y + 8;
        }
        if (PlayerHand_IsItemPlacementBlocked() == 0) {
            Sound_PlayEffect0(4);
            player->action_state = 4;
            PlayerHand_BeginPlacing();
            return;
        }
        player->anim_id = 3;
        blocked_frame = sPlayerHandAnimations[3][0];
        player->anim_frame = 0;
        player->anim_timer = blocked_frame->duration;
        Sound_PlayEffect0(0x12);
    }
    PlayerHand_UpdateMovement();
    if (islander->carry_state == 0) {
        entity->lifetime = 0x30;
        entity->x = (player->x >> 8) - 8;
        entity->y = (player->y >> 8) - 2;
    } else {
        islander->x = player->x;
        islander->y = player->y + 0x1200;
    }
    if (player->anim_timer == 0) {
        player->anim_frame++;
        frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
        if ((u8)frame->action_flag == 0xFF) {
            player->anim_frame--;
            return;
        }
        player->anim_timer = frame->duration;
    } else {
        player->anim_timer--;
    }
}

/* Original address: 0x020265A8 */
void PlayerHand_BeginPlacing(void) {
    Player *player = &gPlayer;
    AnimFrameData *frame;
    player->anim_id = 2;
    frame = sPlayerHandAnimations[2][0];
    player->anim_frame = 0;
    player->anim_timer = frame->duration;
    player->action_state = 5;
}

/* Original address: 0x020265D4 */
void PlayerHand_UpdatePlacing(void) {
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    s32 attract_islander = 0;
    AnimFrameData *frame;
    ItemGroupStruct *definition;
    s32 dx, dy;

    if (islander->carry_state == 0 && player->held_item_layer == 0 && player->held_item_tile_idx == 0) {
        player->action_state = 0;
        PlayerHand_ResetToIdle();
        return;
    }
    if (player->anim_timer != 0) {
        player->anim_timer--;
        if (player->anim_frame == 3 && player->anim_timer == 0) {
            field->entity_active[2] = 0;
        }
        return;
    }
    player->anim_frame++;
    frame = sPlayerHandAnimations[player->anim_id][player->anim_frame];
    if ((u8)frame->action_flag != 0xFF) {
        player->anim_timer = frame->duration;
        return;
    }
    if (islander->carry_state == 0) {
        definition = &g_ItemDefinitions[player->held_item_type_idx];
        WriteItemToTile(player->x, player->tile_idx, player->held_item, definition->field_tile_id);
        if (player->held_item_layer == 0) {
            field->fg_tiles[0][player->held_item_tile_idx] = 0xFFF;
        } else {
            field->fg_tiles[1][player->held_item_tile_idx] = 0xFFF;
        }
        if (!(player->x & 0xFF0000)) {
            field->fg_tiles[0][player->tile_idx] = player->held_item_type_idx;
        } else {
            field->fg_tiles[1][player->tile_idx] = player->held_item_type_idx;
        }
        player->held_item_layer = 0;
        player->held_item_tile_idx = 0;
        if (islander->move_action == 3) {
            if (islander->stored_item_type_plus_one[4] == 0) {
                if (islander->equipped_tool_state == 0) {
                    attract_islander = 1;
                } else if (islander->equipped_tool_state == 3 || islander->equipped_tool_state == 7) {
                    if (definition->interaction_type <= 3 || definition->interaction_type == 5 ||
                        definition->interaction_type == 6) {
                        attract_islander = 1;
                    }
                }
            } else if (islander->equipped_tool_state == 0 && (u16)(definition->interaction_type - 5) <= 9) {
                attract_islander = 1;
            }
        }
        dx = player->x - islander->x;
        if (dx < 0) dx = -dx;
        dy = player->y - islander->y;
        if (dy < 0) dy = -dy;
        if (dx <= 0x2FFF && dy <= 0x2FFF && attract_islander == 1) {
            islander->target_x = (player->x & 0xFF0000) | (((player->tile_idx & 0xF) << 12) + 0x800);
            islander->target_y = ((player->tile_idx & 0xF0) << 8) + 0x800;
            islander->move_action = 9;
        }
    } else {
        islander->carry_state = 1;
    }
    player->interaction_cooldown_timer = 0x20;
    islander->player_interaction_tile_idx = player->tile_idx;
    player->action_state = 0;
    PlayerHand_ResetToIdle();
}

/* Original address: 0x02034E0C */
extern void (*sPlayerHandUpdateProcs[6])(void);

/* Original address: 0x020267D0 */
void PlayerHand_Update(void) {
    Player *player = &gPlayer;
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    field->entity_active[0] = 1;
    field->entity_active[1] = 1;
    if (islander->move_action != 0x14 || islander->action_state == 0 || islander->carry_state == 2) {
        sPlayerHandUpdateProcs[player->action_state]();
    }
}

/* Original address: 0x02026830 */
void PlayerHand_Draw(void) {
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    OAMData *sprite;
    OAMData *oam;
    u32 i;

    player->work_y = player->y >> 8;
    player->work_x = player->x >> 8;
    sprite = sPlayerHandAnimations[player->anim_id][player->anim_frame]->sprite_gfx_p;
    field->entity_active[0] = 0;
    field->entity_active[1] = 0;
    i = 0;
    while (sprite->affine_param != 0xFFFF) {
        oam = &((OAMData *)gUnk3002410)[gGameState.oam_count];
        oam->obj_mode = sprite->obj_mode;
        oam->bpp = sprite->bpp;
        oam->shape = sprite->shape;
        oam->h_flip = sprite->h_flip;
        oam->v_flip = sprite->v_flip;
        oam->size = sprite->size;
        oam->y = sprite->y + player->work_y - (u8)gGameState.bg2_vofs;
        oam->x = sprite->x + player->work_x - gGameState.bg2_hofs;
        oam->tile_num = sprite->tile_num;
        oam->mosaic = 1;
        oam->priority = 0;
        oam->palette_num = sprite->palette_num;
        field->entity_active[i] = 1;
        gGameState.oam_count++;
        i++;
        sprite++;
    }
}

