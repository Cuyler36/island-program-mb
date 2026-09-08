#include "falling_fruit.h"
#include "lib.h"
#include "sound.h"
#include "island_field.h"
#include "field_obj.h"

/* Original address: 0x020344E8 */
extern void (*sFallingFruitUpdateProcs[4])(s32);
/* Original address: 0x020344F8 */
extern FallingFruitProfile sFallingFruitProfiles[23];

/* Original address: 0x02024B08 */
void FallingFruit_Init(s32 object_index, u16 fruit_index, u8 type, u8 acre) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    FallingFruitProfile *profile;
    FieldObject *object;

    fruit->type = type;
    fruit->acre = acre;
    fruit->sound_played = 0;
    fruit->landing_x = 0;
    fruit->origin_y = 0;
    fruit->landing_y = 0;
    fruit->tile_idx = 0;
    fruit->can_land = 0;
    profile = &sFallingFruitProfiles[fruit->type];
    object = &gFieldObjects[object_index];
    fruit->state = 1;
    switch (fruit->type) {
    case 1: case 2:
    case 4: case 5: case 6:
    case 8: case 9: case 10:
    case 12: case 13: case 14:
    case 16: case 17: case 18:
    case 20: case 21: case 22:
        fruit->state = 2;
        /* fallthrough */
    case 0: case 3: case 7: case 11: case 15: case 19:
        fruit->y = object->y + profile->y_offset;
        fruit->origin_y = fruit->y;
        fruit->x = object->x + profile->x_offset;
        fruit->anim_frame = profile->h_flip;
        break;
    }
}

void sub_02024C00(void) {

}

void sub_02024C04(void) {

}

/* Original address: 0x02024C08 */
void FallingFruit_BeginFall(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];

    rand_u16(&gGameState);
    fruit->height = 0;
    fruit->velocity_y = 0x200;
    fruit->gravity = 0x20;
    fruit->timer = 16;
    fruit->state = 3;
}

/* Original address: 0x02024C44 */
void FallingFruit_UpdateFall(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    IslandFieldWork *field = &gIslandFieldWork;

    fruit->timer--;
    fruit->x += (fruit->landing_x - fruit->x) >> 1;
    fruit->y = fruit->origin_y - (fruit->height >> 8);
    fruit->height += fruit->velocity_y;
    fruit->velocity_y -= fruit->gravity;
    if (fruit->timer == 12 && fruit->sound_played == 0) {
        Sound_PlayEffect0(0x17);
        fruit->sound_played = 1;
    }
    if ((fruit->timer & 0x80) && fruit->landing_y < fruit->y) {
        if (fruit->can_land == 1) {
            FallingFruitProfile *profile = &sFallingFruitProfiles[fruit->type];
            s32 row_offset;
            u16 tile_offset;
            row_offset = 0;
            tile_offset = 0;
            do {
                u16 *tilemap;
                if (fruit->acre == 0) {
                    tilemap = (u16 *)((0xFF0 & fruit->tile_idx) * 8 + BG_SCREEN_ADDR(24));
                    tilemap = (u16 *)((u8 *)tilemap + row_offset);
                    tilemap += (0xF & fruit->tile_idx) * 2;
                } else {
                    tilemap = (u16 *)((0xFF0 & fruit->tile_idx) * 8 + BG_SCREEN_ADDR(25));
                    tilemap = (u16 *)((u8 *)tilemap + row_offset);
                    tilemap += (0xF & fruit->tile_idx) * 2;
                }
                tilemap[0] = tile_offset + profile->ground_tile;
                tilemap[1] = tile_offset + profile->ground_tile + 1;
                row_offset += 64;
                tile_offset = 2;
            } while (row_offset < 80);
            if (fruit->acre == 0) {
                gIslandData->fgblock[0][0].items[(fruit->tile_idx >> 4) % 16][fruit->tile_idx & 0xF] = profile->item;
                field->fg_tiles[0][fruit->tile_idx] = profile->field_tile;
            } else {
                gIslandData->fgblock[0][1].items[(fruit->tile_idx >> 4) % 16][fruit->tile_idx & 0xF] = profile->item;
                field->fg_tiles[1][fruit->tile_idx] = profile->field_tile;
            }
        }
        fruit->state = 0;
        field->entity_active[fruit_index + 21] = 0;
    }
}

/* Original address: 0x02024DD0 */
void FallingFruit_Update(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    sFallingFruitUpdateProcs[fruit->state](fruit_index);
}

/* Original address: 0x02024DF8 */
void FallingFruit_Draw(s32 fruit_index) {
    FallingFruit *fruit = &gFallingFruit[fruit_index];
    FallingFruitProfile *profile = &sFallingFruitProfiles[fruit->type];
    GameState *game = &gGameState;
    OAMData *oam = &((OAMData *)gUnk3002410)[game->oam_count];

    oam->shape = (profile->oam_attributes >> 14) & 3;
    oam->size = (profile->oam_attributes >> 30) & 0xF;
    oam->tile_num = profile->sprite_tile;
    oam->mosaic = 1;
    oam->h_flip = fruit->anim_frame;
    oam->priority = 1;
    oam->palette_num = profile->palette;
    oam->x = fruit->x - game->bg2_hofs;
    oam->y = fruit->y - (u8)game->bg2_vofs;
    game->oam_count++;
}
