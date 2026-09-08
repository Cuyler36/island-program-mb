#ifndef ISLAND_FIELD_H
#define ISLAND_FIELD_H

#include "gba/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Island field tile data and scene-wide runtime state. */
/* sizeof(IslandFieldWork) == 0x4A0 */
typedef struct IslandFieldWork {
    /* 0x000 */ s32 bg3_scroll_y;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ s32 entity_dist_x;
    /* 0x00C */ s32 entity_dist_y;
    /* 0x010 */ u16 fg_tiles[2][256];
    /* 0x410 */ u16 mosaic;
    /* 0x412 */ u16 tile_render_scratch;
    /* 0x414 */ u16 tile_id_scratch;
    /* 0x416 */ u8 last_palette_hour;
    /* 0x417 */ u8 entity_active[0x80];
    /* 0x497 */ u8 palette_anim_timer;
    /* 0x498 */ u8 palette_anim_frame;
    /* 0x499 */ u8 unk_499;
    /* 0x49A */ u8 special_tile_idx;
    /* 0x49B */ u8 transition_state;
    /* 0x49C */ u8 transition_proc_idx;
    /* 0x49D */ u8 unk_49D;
    /* 0x49E */ u8 gameplay_active;
    /* 0x49F */ u8 pad_49F;
} IslandFieldWork;

s32 LoadIslandBuildingTiles(u16 arg0, s32 arg1, u8 arg2);
void LoadIslandFieldEntity(u16 arg0, s32 arg1, u8 arg2);
void LoadIslandForeground(void);
void UpdateHourlyPalette(void);
void InitIslandField(void);
void ExpandIslandBg3(void);
s32 UpdateIslandMosaic(u8 cover);
s32 UpdateIslandField(void);
void IslandField_UpdateNormal(void);
void IslandField_UpdateJoybusExit(void);
void IslandField_UpdateSleepExit(void);
void IslandField_UpdateOverviewExit(void);
void DrawIslandField(void);

/* Original address: 0x03003710 */
extern IslandFieldWork gIslandFieldWork;

#ifdef __cplusplus
}
#endif

#endif // ISLAND_FIELD_H