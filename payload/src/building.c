#include "building.h"
#include "game.h"
#include "islander.h"


/* Original address: 0x0202FD40 */
extern IslandBuildingSprite sIslandBuildingSprites[6];

/* Original address: 0x0201DF9C */
void InitIslandBuilding(s32 index, u8 type, s32 tile, u8 acre) {
    IslandBuilding *building = &gIslandBuildings[index];
    Islander_AGB *islander = &gIslander;

    if (type == 0) {
        building->y = (tile & 0xFFF0) + 16;
        building->x = (tile & 0xF) * 16 + 16;
    } else {
        building->y = (tile & 0xFFF0) + 8;
        if (acre == 0) {
            building->x = (tile & 0xF) * 16 + 8;
        } else {
            building->x = (tile & 0xF) * 16 + 0x108;
        }
        islander->x = building->x << 8;
        islander->y = (building->y << 8) + 0x100;
        islander->accepted_x = islander->x;
        islander->accepted_y = islander->y;
        building->interaction_x = building->x - 8;
        building->interaction_y = building->y - 4;
    }
    building->tile_idx = tile;
    building->state = 1;
}

void sub_0201E030(void) {

}

void sub_0201E034(void) {

}

typedef void (*IslandBuilding_PROC)(void);

// Original address: 0x0202FD38
extern IslandBuilding_PROC gIslandBuildingProcs[2];

/* Original address: 0x0201E038 */
void IslandBuilding_Update(u8 arg0, u8 arg1) {
    IslandBuilding *building = &gIslandBuildings[1];

    if (arg1 == 2) {
        gIslandBuildingProcs[building->state]();
    }
}

/* Original address: 0x0201E060 */
void IslandBuilding_DrawSprite(IslandBuildingSprite *sprite, s32 building_index, u8 sprite_index) {
    IslandBuilding *building = &gIslandBuildings[building_index];
    OAMData *oam = &((OAMData *)gUnk3002410)[gGameState.oam_count];

    if (sprite_index != 5 || building->state == 1) {
        oam->shape = (sprite->oam_attributes >> 14) & 3;
        oam->size = (sprite->oam_attributes >> 30) & 0xF;
        oam->h_flip = sprite->h_flip;
        oam->v_flip = sprite->v_flip;
        oam->palette_num = sprite->palette_num;
        oam->priority = 1;
        oam->x = sprite->x_offset + (building->x - gGameState.bg2_hofs);
        oam->y = sprite->y_offset + (building->y - (u8)gGameState.bg2_vofs);
        oam->tile_num = sprite->tile_num;
        oam->mosaic = 1;
    }
    gGameState.oam_count++;
}

/* Original address: 0x0201E178 */
void IslandBuilding_Draw(s32 building_index, u8 part) {
    s32 first = 0;
    s32 end = 0;
    s32 i;

    switch (part) {
    case 0:
        first = 0;
        end = 3;
        break;
    case 2:
        first = 3;
        end = 5;
        break;
    case 1:
        first = 5;
        end = 6;
        break;
    }
    for (i = first; i < end; i++) {
        IslandBuilding_DrawSprite(&sIslandBuildingSprites[i], building_index, i);
    }
}

