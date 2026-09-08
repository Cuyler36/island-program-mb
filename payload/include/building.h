#ifndef BUILDING_H
#define BUILDING_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum IslandBuildingType {
    ISLAND_BUILDING_CABANA = 0,
    ISLAND_BUILDING_ISLANDER_HOUSE,
    ISLAND_BUILDING_COUNT
} IslandBuildingType;

/* Runtime position and draw state for the cabana and Islander house. */
/* sizeof(IslandBuilding) == 0x14 */
typedef struct IslandBuilding {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 interaction_x;
    /* 0x0C */ s32 interaction_y;
    /* 0x10 */ u8 tile_idx;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 pad_12[2];
} IslandBuilding;

/* sizeof(IslandBuildingSprite) == 0x14. */
typedef struct IslandBuildingSprite {
    /* 0x00 */ u32 oam_attributes;
    /* 0x04 */ s32 y_offset;
    /* 0x08 */ s32 x_offset;
    /* 0x0C */ u16 tile_num;
    /* 0x0E */ u8 palette_num;
    /* 0x0F */ u8 h_flip;
    /* 0x10 */ u8 v_flip;
    /* 0x11 */ u8 pad_11[3];
} IslandBuildingSprite;

void InitIslandBuilding(s32 index, u8 type, s32 tile, u8 acre);
void sub_0201E030(void);
void sub_0201E034(void);
void IslandBuilding_Update(u8 arg0, u8 arg1);
void IslandBuilding_DrawSprite(IslandBuildingSprite *sprite, s32 building_index, u8 sprite_index);
void IslandBuilding_Draw(s32 arg0, u8 arg1);

extern IslandBuilding gIslandBuildings[ISLAND_BUILDING_COUNT];

#ifdef __cplusplus
}
#endif

#endif // BUILDING_H