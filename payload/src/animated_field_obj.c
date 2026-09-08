#include "animated_field_obj.h"
#include "anim.h"
#include "game.h"
#include "global.h"

/* Original address: 0x03003BF0 */
extern AnimatedFieldObject gAnimatedFieldObjects[];

/* Original address: 0x0202FEB0 */
extern AnimFrameData *sFieldAnimationFrames[7];

/* Original address: 0x0201E1E0 */
void AnimatedFieldObject_Init(s32 index, s32 tile, u8 acre) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];

    object->x = 0;
    if (acre != 0) {
        object->x = 0x100;
    }
    object->x |= (tile & 0xF) * 16 + 12;
    object->y = (tile & 0xF0) + 8;
    object->anim_timer = 0;
    object->anim_frame = 0;
    object->anim_timer = sFieldAnimationFrames[0]->duration;
}

/* Original address: 0x0201E230 */
void AnimatedFieldObject_Update(s32 index) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];

    object->anim_timer--;
    if (object->anim_timer == 0) {
        object->anim_frame++;
        if ((u8)sFieldAnimationFrames[object->anim_frame]->action_flag == 0xFF) {
            object->anim_frame = 0;
        }
        object->anim_timer = sFieldAnimationFrames[object->anim_frame]->duration;
    }
}

/* Original address: 0x0201E27C */
void AnimatedFieldObject_Draw(s32 index) {
    AnimatedFieldObject *object = &gAnimatedFieldObjects[index];
    OAMData *source = sFieldAnimationFrames[object->anim_frame]->sprite_gfx_p;

    while (source->affine_param != 0xFFFF) {
        OAMData *oam = &((OAMData *)gUnk3002410)[gGameState.oam_count];

        oam->y = source->y + object->y - (u8)gGameState.bg2_vofs;
        oam->obj_mode = source->obj_mode;
        oam->bpp = source->bpp;
        oam->shape = source->shape;
        oam->h_flip = source->h_flip;
        oam->v_flip = source->v_flip;
        oam->size = source->size;
        oam->x = source->x + object->x - gGameState.bg2_hofs;
        oam->tile_num = source->tile_num;
        oam->mosaic = 1;
        oam->priority = 1;
        oam->palette_num = source->palette_num;
        gGameState.oam_count++;
        source++;
    }
}
