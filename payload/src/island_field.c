#include "island_field.h"
#include "gba/io_reg.h"
#include "sound.h"
#include "game.h"
#include "animated_field_obj.h"
#include "field_obj.h"
#include "building.h"
#include "entity.h"
#include "falling_fruit.h"
#include "islander.h"
#include "player_hand.h"

/* Original address: 0x0202B3FC */
extern const u16 sIslandRightAcreTilemaps[4][1024];
/* Original address: 0x0202D3FC */
extern const u16 sIslandLeftAcreTilemaps[4][1024];
/* Original address: 0x0202FC1C */
extern const u16 sCabanaTilemap[64];
/* Original address: 0x0202FC9C */
extern const u16 sIslanderHouseTilemap[48];
/* Original address: 0x0202FCFC */
extern const u8 sCabanaFootprint[16];
/* Original address: 0x0202FD0C */
extern const u8 sIslanderHouseFootprint[9];
/* Original address: 0x0202FD16 */
extern const u16 sFieldEntityBaseTiles[9];

/* Original address: 0x0201CDA0 */
s32 LoadIslandBuildingTiles(u16 tile_id, s32 pos, u8 acre) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 origin;
    s32 i;
    u32 tilemap;
    const u16 *source;
    const u8 *offset;
    s32 tile;
    u16 *dest;
    u16 *field_tile;

    switch (tile_id) {
    case 1:
        origin = pos - 0x11;
        tilemap = ((u32)BG_SCREEN_ADDR(24) + ((origin & 0xFF0) << 3));
        tilemap += (origin & 15) * 4;
        i = 0;
        source = sCabanaTilemap;
        do {
            tile = *source;
            if (tile != 0) {
                dest = (u16 *)(tilemap + ((i & 0xFF8) << 3));
                dest += i & 7;
                *dest = tile;
            }
            source++;
            i++;
        } while (i <= 63);
        for (i = 0; i <= 15; i++) {
            field->fg_tiles[0][(u8)(origin + sCabanaFootprint[i])] = ITEM_TYPE_CABANA;
        }
        field->entity_active[15] = 1;
        InitIslandBuilding(0, 0, pos, 0);
        break;
    case 2:
        origin = pos - 0x11;
        if (acre == 0) {
            tilemap = ((u32)BG_SCREEN_ADDR(24) + ((origin & 0xFF0) << 3));
        } else {
            tilemap = ((u32)BG_SCREEN_ADDR(25) + ((origin & 0xFF0) << 3));
        }
        tilemap += (origin & 15) * 4;
        i = 0;
        source = sIslanderHouseTilemap;
        do {
            tile = *source;
            if (tile != 0) {
                dest = (u16 *)(tilemap + ((i & 0xFF8) << 3));
                dest += i & 7;
                *dest = tile;
            }
            source++;
            i++;
        } while (i <= 47);
        offset = sIslanderHouseFootprint;
        do {
            if (acre == 0) {
                field_tile = &field->fg_tiles[0][(u8)(*offset + origin)];
            } else {
                field_tile = &field->fg_tiles[1][(u8)(*offset + origin)];
            }
            *field_tile = ITEM_TYPE_ISLANDER_HOUSE;
            offset++;
        } while (offset <= &sIslanderHouseFootprint[8]);
        field->special_tile_idx = origin + 0x21;
        field->entity_active[18] = 1;
        InitIslandBuilding(1, 2, pos, acre);
        break;
    default:
        return 1;
    }
    return 0;
}

/* Original address: 0x0201CF3C */
void LoadIslandFieldEntity(u16 type, s32 pos, u8 acre) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 right_acre = 0;
    s32 left_pos;
    u32 tilemap;
    u16 *dest;
    u16 tile;
    s32 next_tile;
    s32 remaining;
    s32 slot;
    u8 *active;
    u16 ground_tile;
    s32 column_offset;
    u16 *ground;

    switch (type) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        left_pos = (((pos & 15) - 1) & 15) | (pos & 0xF0);
        if (acre == 0 || (left_pos & 15) == 15) {
            dest = (u16 *)BG_SCREEN_ADDR(24);
            field->tile_id_scratch = field->fg_tiles[0][left_pos];
        } else {
            dest = (u16 *)BG_SCREEN_ADDR(25);
            field->tile_id_scratch = field->fg_tiles[1][left_pos];
            right_acre = 1;
        }
        dest = (u16 *)((u32)dest + ((left_pos & 0xFF0) << 3));
        dest += (left_pos & 15) * 2;
        tile = sFieldEntityBaseTiles[type - 5];
        dest += 33;
        if (field->tile_id_scratch == 0xFFF) {
            *dest = tile;
        }
        dest++;
        next_tile = tile + 1;
        remaining = 2;
        do {
            /* Continue the row in the next screen block at an acre boundary. */
            if (right_acre == 0 && (((u32)dest & 0xFF) == 0 || ((u32)dest & 0xFF) == 0x40 ||
                                    ((u32)dest & 0xFF) == 0x80 || ((u32)dest & 0xFF) == 0xC0)) {
                dest += 0x3E0;
            }
            *dest = next_tile;
            remaining--;
            dest++;
            next_tile++;
        } while (remaining >= 0);
        if (type >= 12 && type <= 13) {
            return;
        }
        slot = 0;
        active = &field->entity_active[54];
        do {
            if (*active == 0) {
                *active = 1;
                FieldObject_Init(slot, type, pos, acre);
                return;
            }
            active++;
            slot++;
        } while (slot <= 29);
        break;
    case 19:
        AnimatedFieldObject_Init(84, pos, acre);
        break;
    case 20:
        if (acre == 0) {
            ground = (u16 *)(BG_SCREEN_ADDR(20) + ((pos & 0xFF0) << 3));
            column_offset = (pos & 15) << 2;
            ground = (u16 *)((u32)ground + column_offset);
            tilemap = BG_SCREEN_ADDR(24) + ((pos & 0xFF0) << 3);
        } else {
            ground = (u16 *)(BG_SCREEN_ADDR(21) + ((pos & 0xFF0) << 3));
            column_offset = (pos & 15) << 2;
            ground = (u16 *)((u32)ground + column_offset);
            tilemap = BG_SCREEN_ADDR(25) + ((pos & 0xFF0) << 3);
        }
        dest = (u16 *)(tilemap + column_offset);
        ground_tile = *ground & 0x3FF;
        field->tile_render_scratch = ground_tile;
        if ((ground_tile >= 10 && ground_tile <= 15) || (ground_tile >= 0xC6 && ground_tile <= 0xCB)) {
            *dest++ = 0x22AC;
            *dest = 0x22AD;
            dest += 31;
            *dest = 0x22AE;
            dest[1] = 0x22AF;
        }
        break;
    case 3:
    case 4:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        slot = 0;
        active = &field->entity_active[54];
        do {
            if (*active == 0) {
                *active = 1;
                FieldObject_Init(slot, type, pos, acre);
                return;
            }
            active++;
            slot++;
        } while (slot <= 29);
        break;
    }
}

/* Original address: 0x0201D19C */
void LoadIslandForeground(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    ItemGroupStruct *definition;
    u16 *fg0_tile;
    u16 *fg1_tile;
    u16 *vram_tile;
    u16 tile_id;
    s32 render_offset;
    s32 item_type;
    s32 result;
    s32 pos;

    field->tile_render_scratch = 0x5851;
    pos = 0;
    vram_tile = (u16 *)BG_SCREEN_ADDR(24);
    do {
        *vram_tile = 0x200;
        pos += 2;
        vram_tile++;
    } while (pos <= 0xFFF);

    fg0_tile = field->fg_tiles[0];
    fg1_tile = field->fg_tiles[1];
    pos = 0xFF;
    do {
        *fg0_tile = 0xFFF;
        *fg1_tile = 0xFFF;
        fg1_tile++;
        fg0_tile++;
        pos--;
    } while (pos >= 0);

    for (pos = 0; pos <= 0xFF; pos++) {
        if ((Item_GetTypeIndex(gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF]) & 0x8000) == 0) {
            item_type = Item_GetTypeIndex(gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF]);
            if (item_type <= ITEM_TYPE_RESERVED) {
                definition = &g_ItemDefinitions[item_type];
                if (item_type == ITEM_TYPE_RESERVED) {
                    if (field->fg_tiles[0][pos] == 0xFFF) {
                        field->fg_tiles[0][pos] = 0x7777;
                    }
                } else {
                    field->fg_tiles[0][pos] = item_type;
                }

                if (definition->field_tile_id == 0x270) {
                    gIslandData->deposit[0][(pos >> 4) & 0xF] |= 1 << (pos & 0xF);
                    gIslandData->fgblock[0][0].items[(pos >> 4) & 0xF][pos & 0xF] = ITM_PITFALL;
                    field->fg_tiles[0][pos] = 0x10;
                }

                if (item_type != ITEM_TYPE_RESERVED) {
                    result = LoadIslandBuildingTiles(definition->field_tile_id, pos, 0);
                    if (result == 1) {
                        tile_id = definition->field_tile_id;
                        field->tile_id_scratch = tile_id;
                        if ((gIslandData->deposit[0][(pos >> 4) & 0xF] >> (pos & 0xF)) & result) {
                            field->tile_id_scratch = 0x1270;
                        }

                        render_offset = 0;
                        field->tile_render_scratch = 0;
                        do {
                            vram_tile = (u16 *)((u32)BG_SCREEN_ADDR(24) + render_offset +
                                                ((pos & 0xFF0) << 3) + ((pos & 0xF) << 2));
                            vram_tile[0] = field->tile_render_scratch +
                                           field->tile_id_scratch;
                            vram_tile[1] = field->tile_render_scratch +
                                           field->tile_id_scratch + 1;
                            render_offset += 0x40;
                            field->tile_render_scratch = 2;
                        } while (render_offset <= 0x4F);

                        LoadIslandFieldEntity(definition->field_entity_type, pos, 0);
                    }
                }
            }
        }

        if ((Item_GetTypeIndex(gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF]) & 0x8000) == 0) {
            item_type = Item_GetTypeIndex(gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF]);
            if (item_type <= ITEM_TYPE_RESERVED) {
                definition = &g_ItemDefinitions[item_type];
                if (item_type == ITEM_TYPE_RESERVED) {
                    if (field->fg_tiles[1][pos] == 0xFFF) {
                        field->fg_tiles[1][pos] = 0x7777;
                    }
                } else {
                    field->fg_tiles[1][pos] = item_type;
                }

                if (definition->field_tile_id == 0x270) {
                    gIslandData->deposit[1][(pos >> 4) & 0xF] |= 1 << (pos & 0xF);
                    gIslandData->fgblock[0][1].items[(pos >> 4) & 0xF][pos & 0xF] = 0x2512;
                    field->fg_tiles[1][pos] = 0x10;
                }

                if (item_type != ITEM_TYPE_RESERVED) {
                    result = LoadIslandBuildingTiles(definition->field_tile_id, pos, 1);
                    if (result == 1) {
                        tile_id = definition->field_tile_id;
                        field->tile_id_scratch = tile_id;
                        if ((gIslandData->deposit[1][(pos >> 4) & 0xF] >> (pos & 0xF)) & result) {
                            field->tile_id_scratch = 0x1270;
                        }

                        render_offset = 0;
                        field->tile_render_scratch = 0;
                        do {
                            vram_tile = (u16 *)((u32)BG_SCREEN_ADDR(25) + render_offset +
                                                ((pos & 0xFF0) << 3) + ((pos & 0xF) << 2));
                            vram_tile[0] = field->tile_render_scratch +
                                           field->tile_id_scratch;
                            vram_tile[1] = field->tile_render_scratch +
                                           field->tile_id_scratch + 1;
                            render_offset += 0x40;
                            field->tile_render_scratch = 2;
                        } while (render_offset <= 0x4F);

                        LoadIslandFieldEntity(definition->field_entity_type, pos, 1);
                    }
                }
            }
        }
    }
}

/* Original address: 0x0201D550 */
void UpdateHourlyPalette(void) {
    u16 *palette0;
    u16 *palette1;
    s32 i;
    u16 color;
    u16 palette_index;
    u8 hour;
    IslandFieldWork *field = &gIslandFieldWork;

    hour = gGameState.game_time_frames / (60 * 60 * 60);
    if (field->last_palette_hour != hour) {
        do { i = 0; } while (0);
        palette0 = current_time_of_day_palette0;
        palette1 = current_time_of_day_palette1;
        do {
            palette_index = (hour << 2) + i;
            color = time_of_day_palettes[palette_index];
            *palette0 = color;
            *palette1 = color;
            i++;
            palette0++;
            palette1++;
        } while (i < 4);

        field->last_palette_hour = hour;
    }
}

static inline void LoadAcreTilemap(s32 terrain, s32 acre) {
    switch (terrain) {
    case 0:
        DmaCopy32(3, sIslandLeftAcreTilemaps[0], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 1:
        DmaCopy32(3, sIslandLeftAcreTilemaps[1], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 2:
        DmaCopy32(3, sIslandLeftAcreTilemaps[2], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    case 3:
        DmaCopy32(3, sIslandLeftAcreTilemaps[3], BG_SCREEN_ADDR(20 + acre), 0x800);
        break;
    }
}

static inline void LoadRightAcreTilemap(s32 terrain) {
    switch (terrain) {
    case 0:
        DmaCopy32(3, sIslandRightAcreTilemaps[0], BG_SCREEN_ADDR(21), 0x800);
        break;
    case 1:
        DmaCopy32(3, sIslandRightAcreTilemaps[1], BG_SCREEN_ADDR(21), 0x800);
        break;
    case 2:
        DmaCopy32(3, sIslandRightAcreTilemaps[2], BG_SCREEN_ADDR(21), 0x800);
        break;
    case 3:
        DmaCopy32(3, sIslandRightAcreTilemaps[3], BG_SCREEN_ADDR(21), 0x800);
        break;
    }
}

/* Original address: 0x0201D5C4 */
void InitIslandField(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    s32 terrain;
    s32 i;
    u8 hour = gGameState.game_time_frames / (60 * 60 * 60);

    if (field->last_palette_hour != hour) {
        {
            u16 *palette0;
            u16 *palette1;
            u16 color;
            u16 palette_index;
        
        
            i = 0;
            palette0 = current_time_of_day_palette0;
            palette1 = current_time_of_day_palette1;
            do {
                palette_index = (hour << 2) + i;
                color = time_of_day_palettes[palette_index];
                *palette0 = color;
                *palette1 = color;
                i++;
                palette0++;
                palette1++;
            } while (i < 4);
        }
        field->last_palette_hour = hour;
    }
    field->last_palette_hour = 0xFF;
    field->entity_active[0] = 1;
    PlayerHand_Init();
    Islander_Init();
    field->palette_anim_timer = 4;
    field->palette_anim_frame = 0;
    field->unk_499 = 0;
    field->special_tile_idx = 0;
    field->entity_dist_x = 0;
    field->entity_dist_y = 0;
    field->bg3_scroll_y = 0;
    field->unk_004 = 0;
    field->transition_state = 0;
    field->mosaic = 0;
    field->unk_49D = 0;
    terrain = gIslandData->bg_data[0] & 3;
    field->transition_proc_idx = 0;
    LoadAcreTilemap(terrain, 0);
    terrain = gIslandData->bg_data[1] & 3;
    LoadRightAcreTilemap(terrain);

    for (i = 0; i < ARRAY_COUNT(field->entity_active); i++) {
        field->entity_active[i] = 0;
    }
    LoadIslandForeground();
}

/* Original address: 0x0201D7AC */
void ExpandIslandBg3(void) {
    if (!(0xC000 & REG_BG3CNT)) {
        gGameState.bg3cnt = (0xC000 | gGameState.bg3cnt) ^ 0x300;
        if (gIslandData->weather != 0) {
            Sound_StopEffect2(0x26U);
        }
    }
}

/* Original address: 0x0201D800 */
s32 UpdateIslandMosaic(u8 cover) {
    IslandFieldWork *field = &gIslandFieldWork;

    if (cover != 0) {
        gGameState.bg1cnt |= 0x40;
        gGameState.bg2cnt |= 0x40;
        gGameState.bg3cnt |= 0x40;
        field->mosaic += 0x1111;
        if (field->mosaic == 0xFFFF) {
            field->transition_state = 2;
            REG_MOSAIC = field->mosaic;
            return 1;
        } else {
            REG_MOSAIC = field->mosaic;
            return 0;
        }
    } else if (gGameState.bg1cnt & 0x40) {
        if (field->mosaic == 0) {
            field->mosaic = 0xFFFF;
        }
        field->transition_state = 0;
        field->transition_proc_idx = 0;
        field->mosaic -= 0x1111;
        if (field->mosaic == 0) {
            gGameState.bg1cnt ^= 0x40;
            gGameState.bg2cnt ^= 0x40;
            gGameState.bg3cnt ^= 0x40;
            REG_MOSAIC = field->mosaic;
            return 1;
        } else {
            REG_MOSAIC = field->mosaic;
            return 0;
        }
    }
    return 1;
}

/* Original address: 0x0202FD28 */
extern void (*const sIslandFieldUpdateProcs[4])(void);

/* Original address: 0x0201D904 */
s32 UpdateIslandField(void) {
    IslandFieldWork *field = &gIslandFieldWork;

    REG_MOSAIC = 0;
    sIslandFieldUpdateProcs[field->transition_proc_idx]();
    if (field->transition_state == 3) {
        return 1;
    }
    return 0;
}

/* Original address: 0x0202F3FC */
extern const u16 sFieldPaletteAnimation0[256];
/* Original address: 0x0202F5FC */
extern const u16 sFieldPaletteAnimation2[256];

/* Original address: 0x0201D94C */
void IslandField_UpdateNormal(void) {
    Islander_AGB *islander = &gIslander;
    Player *player = &gPlayer;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    u16 palette_index;
    u8 frame;
    s32 scroll_y;
    u16 *palette2;
    u16 *palette0;
    s32 camera_y;
    u16 mosaic_enabled;
    s32 mosaic_complete;
    u8 joybus_notice_requested;
    u8 sleep_requested;

    UpdateHourlyPalette();
    gGameState.bldcnt = 0x3E41;
    gGameState.bldalpha = 0x1006;
    if (islander->carry_state != 1) {
        mosaic_complete = UpdateIslandMosaic(0U);
        if (mosaic_complete == 0) {
            gGameState.bg1_hofs = ((s32) player->x >> 8) - 0x80;
            camera_y = ((s32) player->y >> 8) - 0x50;
            gGameState.bg1_vofs = camera_y;
            if (camera_y & 0x800) {
                gGameState.bg1_vofs = 0;
            }
            if ((u32) gGameState.bg1_vofs > 0x60U) {
                gGameState.bg1_vofs = 0x60;
            }
            if (0x800 & gGameState.bg1_hofs) {
                gGameState.bg1_hofs = 0;
            }
            if ((u32) gGameState.bg1_hofs > 0x100U) {
                gGameState.bg1_hofs = 0x100;
            }
            Sound_SetEmotion((u8) (islander->emotion + SOUND_EMOTION_NEUTRAL));
            gGameState.bg2_hofs = gGameState.bg1_hofs;
            gGameState.bg2_vofs = gGameState.bg1_vofs;
            field->gameplay_active = 1;
            return;
        }
    }
    joybus_notice_requested = gGameState.joybus_notice_requested;
    if ((joybus_notice_requested == 1) && (islander->carry_state != 1)) {
        Sound_StopMusic(0x14U);
        Sound_InitMusic();
        field->mosaic = 0;
        field->unk_49D = 0;
        field->gameplay_active = 0;
        field->transition_state = joybus_notice_requested;
        field->transition_proc_idx = joybus_notice_requested;
        return;
    }
    sleep_requested = gGameState.sleep_requested;
    if ((sleep_requested == 1) && (islander->carry_state != 1)) {
        Sound_StopMusic(0x14U);
        Sound_InitMusic();
        field->mosaic = 0U;
        field->unk_49D = 0;
        field->gameplay_active = 0;
        field->transition_state = sleep_requested;
        field->transition_proc_idx = 2U;
        return;
    }
    if ((2 & gGameState.keys.buttons.pressed) && (islander->carry_state != 1)) {
        mosaic_enabled = 0x40 & gGameState.bg1cnt;
        if (mosaic_enabled == 0) {
            Sound_StopMusic(0x14U);
            Sound_InitMusic();
            field->mosaic = mosaic_enabled;
            field->unk_49D = 0;
            field->gameplay_active = 0;
            field->transition_state = 1U;
            field->transition_proc_idx = 3U;
            return;
        }
    }
    if ((0xC000 & REG_BG3CNT) && (0xC000 & gGameState.bg3cnt)) {
        gGameState.bg3cnt = (0xC000 ^ gGameState.bg3cnt) | 0x300;
        if (gIslandData->weather != 0) {
            Sound_PlayEffect2(0x26U);
        }
    }
    if (--field->palette_anim_timer == 0) {
        field->palette_anim_timer = 8;
        palette0 = gFieldPaletteBuffer;
        palette2 = gFieldPaletteBuffer2;
        frame = field->palette_anim_frame;
        i = 0;
        do {
            palette_index = frame * 16 + i;
            *palette0 = sFieldPaletteAnimation0[palette_index];
            *palette2 = sFieldPaletteAnimation2[palette_index];
            i += 1;
            palette0++;
            palette2++;
        } while (i <= 0xF);
        if (++field->palette_anim_frame > 13) {
            field->palette_anim_frame = 0U;
        }
    }
    CpuSet(gFieldPaletteBuffer, (void *)PLTT, 0x200U);
    gGameState.bg3_hofs = gGameState.bg1_hofs;
    scroll_y = field->bg3_scroll_y + 0x40;
    field->bg3_scroll_y = scroll_y;
    gGameState.bg3_vofs = (u16) ((s32) (gGameState.bg1_vofs + scroll_y) >> 8);
    PlayerHand_Update();
    Islander_UpdateMovement();
    i = 0;
    do {
        if (field->entity_active[i + 21] == 1) {
            FallingFruit_Update(i);
        }
        i += 1;
    } while (i <= 0x1D);
    i = 0;
    do {
        if (field->entity_active[i + 54] == 1) {
            FieldObject_Update(i);
        }
        i += 1;
    } while (i <= 0x1D);
    if (field->entity_active[2] == 1) {
        Entity_Update(2);
    }
    i = 3;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_Update(i);
        }
        i += 1;
    } while (i <= 0xB);
    IslandBuilding_Update(1U, 2);
    AnimatedFieldObject_Update(0x54);
}

/* Original address: 0x0201DCE4 */
void IslandField_UpdateJoybusExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gGameState.joybus_notice_active = 1;
        gIslandFieldWork.transition_state = 3;
    }
}

/* Original address: 0x0201DD24 */
void IslandField_UpdateSleepExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gGameState.sleep_dialog_active = 1;
        gIslandFieldWork.transition_state = 3;
    }
}

/* Original address: 0x0201DD64 */
void IslandField_UpdateOverviewExit(void) {
    UpdateIslandMosaic(gIslandFieldWork.transition_state);
    if (gIslandFieldWork.transition_state == 2) {
        ExpandIslandBg3();
        RestoreHeldItemsToField();
        gIslandFieldWork.transition_state = 3;
    }
}

static inline void DrawIslanderBehindFieldObjects(Islander_AGB *islander) {
    if (islander->move_action == 0x14) {
        if (islander->carry_state == 2) {
            Islander_Draw();
        }
    }
}

/* Original address: 0x0201DD94 */
void DrawIslandField(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    s32 i;
    s32 house_drawn;
    s32 islander_drawn;
    s32 distance_y;
    s32 distance_x;
    s32 islander_y;
    s32 entity;
    s32 cabana_drawn;
    u32 entity_id;

    gGameState.oam_count = 0;
    if (field->entity_active[2] == 1) {
        Entity_DrawSprite(2);
    }
    DrawIslanderBehindFieldObjects(islander);
    i = 0;
    do {
        if (field->entity_active[i] == 1) {
            PlayerHand_Draw();
        }
        i += 1;
    } while (i <= 1);
    i = 3;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_DrawSprite(i);
        }
        i += 1;
    } while (i <= 0xB);
    AnimatedFieldObject_Draw(0x54);
    cabana_drawn = 0;
    house_drawn = 0;
    islander_drawn = 0;
    for (i = 0x1E; i >= 0; i--) {
        if (field->entity_active[i + 54] == 1) {
            FieldObject *object = &gFieldObjects[i];
            if ((cabana_drawn == 0) && ((u32) gIslandBuildings[0].tile_idx > (u32) object->tile_idx)) {
                IslandBuilding_Draw(0, 0U);
                cabana_drawn = 1;
            }
            if ((house_drawn == 0) && ((u32) gIslandBuildings[1].tile_idx > (u32) object->tile_idx)) {
                IslandBuilding_Draw(1, 2U);
                house_drawn = 1;
            }
            entity_id = object->falling_fruit_id;
            if (entity_id != 0) {
                if (entity_id != 0xFFFF) {
                    FallingFruit_Draw(entity_id - 1);
                } else {
                    entity = 0;
                    do {
                        if (field->entity_active[entity + 21] == 1) {
                            FallingFruit_Draw(entity);
                        }
                        entity += 1;
                    } while (entity <= 2);
                }
            }
            distance_x = object->x - (islander->x >> 8);
            field->entity_dist_x = distance_x;
            islander_y = islander->y;
            field->entity_dist_y = object->y - (islander_y >> 8);
            if (distance_x < 0) {
                field->entity_dist_x = -distance_x;
            }
            distance_y = field->entity_dist_y;
            if (distance_y < 0) {
                field->entity_dist_y = -distance_y;
            }
            if (field->entity_dist_x <= 0x10 && field->entity_dist_y <= 0x10 &&
                (object->tile_idx & 0xF0) < (((islander_y + 0xD00) >> 8) & 0xF0) &&
                islander_drawn == 0) {
                Islander_Draw();
                islander_drawn = 1;
            }
            FieldObject_Draw(i);
        }
    }
    if (cabana_drawn == 0) {
        IslandBuilding_Draw(0, 0U);
    }
    if (house_drawn == 0) {
        IslandBuilding_Draw(1, 2U);
    }
    if (islander_drawn == 0) {
        Islander_Draw();
    }
    IslandBuilding_Draw(1, 1U);
    i = 0;
    do {
        if (field->entity_active[i + 3] == 1) {
            Entity_DrawFloatingItemShadow(i);
        }
        i += 1;
    } while (i <= 0xB);
}

