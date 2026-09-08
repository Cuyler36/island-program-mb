#include "m_msg.h"
#include "lib.h"
#include "global.h"
#include <string.h>

/* Original address: 0x0201C2E0 */
void mMsg_InitSprites(void) {
    s32 sp0;

    sp0 = 0;
    CpuFastSet(&sp0, gMsgSprites, 0x01000120U);
}

/* Original address: 0x0201C300 */
void mMsg_DeactivateSprite(m_msg_sprite_c *sprite) {
    sprite->_57 = 0;
    sprite->update = NULL;
    sprite->draw = NULL;
}

/* Original address: 0x0201C310 */
m_msg_sprite_c *mMsg_CreateSprite(u8 type, s32 x, s32 y, s32 param) {
    u32 zero;
    m_msg_sprite_c *result = NULL;
    s32 index = mMsg_FindSpriteByType(0);

    if (index >= 0) {
        const mMsg_SpriteProfile *profile = sMsgSpriteProfiles[type];
        m_msg_sprite_c *sprite;

        zero = 0;
        sprite = &gMsgSprites[index];
        CpuFastSet(&zero, sprite, 0x01000018);
        gMsgSprites[index].init = profile->init;
        gMsgSprites[index].destroy = profile->destroy;
        gMsgSprites[index].update = profile->update;
        gMsgSprites[index].draw = profile->draw;
        sprite->_57 = type;
        gMsgSprites[index]._2C = x;
        gMsgSprites[index]._30 = y;
        gMsgSprites[index]._14 = param;
        if (sprite->init != NULL) {
            sprite->init(sprite);
        }
        result = sprite;
    }
    return result;
}

static inline s32 mMsg_ScanSpriteType(u8 type) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 == type) {
            break;
        }
    }
    return i;
}

/* Original address: 0x0201C3C8 */
s32 mMsg_FindSpriteByType(u8 type) {
    s32 index = mMsg_ScanSpriteType(type);

    if (index >= 12) {
        index = -1;
    }
    return index;
}

/* Original address: 0x0201C3F8 */
s32 mMsg_IsSpriteAnimationFinished(m_msg_sprite_c *sprite, AnimFrameData *const *animations) {
    s32 finished = 0;
    AnimFrameData *frames = animations[sprite->animation_index];

    if (sprite->frame_timer == 0 && frames[sprite->frame_index + 1].sprite_gfx_p == NULL) {
        finished = 1;
    }
    return finished;
}

/* Original address: 0x0201C428 */
void mMsg_StartSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations, s16 animation) {
    sprite->animation_index = animation;
    sprite->frame_timer = animations[sprite->animation_index][0].duration;
    sprite->frame_index = 0;
}

/* Original address: 0x0201C444 */
void mMsg_UpdateSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations) {
    AnimFrameData *frames = animations[sprite->animation_index];

    if (sprite->frame_timer - 1 <= 0) {
        u8 action_flag;

        if (frames[sprite->frame_index + 1].sprite_gfx_p == NULL) {
            action_flag = (u8)frames[sprite->frame_index].action_flag;
            if (action_flag != 0) {
                sprite->frame_index = 0;
            } else {
                sprite->frame_timer = 0;
                return;
            }
        } else {
            sprite->frame_index++;
        }
        sprite->frame_timer = frames[sprite->frame_index].duration;
    } else {
        sprite->frame_timer--;
    }
}

/* Original address: 0x0201C490 */
void mMsg_CopySpriteOam(m_msg_sprite_c *sprite, OAMData *source, OAMData *dest) {
    dest->y = source->y + sprite->_30 + sprite->offset_y;
    dest->affine_mode = source->affine_mode;
    dest->obj_mode = source->obj_mode;
    dest->mosaic = source->mosaic;
    dest->bpp = source->bpp;
    dest->shape = source->shape;
    dest->x = source->x + sprite->_2C + sprite->offset_x;
    dest->matrix_num = source->matrix_num;
    dest->h_flip = source->h_flip;
    dest->v_flip = source->v_flip;
    dest->size = source->size;
    dest->tile_num = source->tile_num;
    dest->priority = source->priority;
    dest->palette_num = source->palette_num;
    dest->affine_param = source->affine_param;
}

/* Original address: 0x0201C5A0 */
void mMsg_UpdateAndDrawSprites(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 != 0 && gMsgSprites[i].update != NULL) {
            gMsgSprites[i].update(&gMsgSprites[i]);
        }
    }
    for (i = 0; i < 12; i++) {
        if (gMsgSprites[i]._57 != 0 && gMsgSprites[i].draw != NULL) {
            gMsgSprites[i].draw(&gMsgSprites[i]);
        }
    }
}

void sub_0201C5F8(m_msg_sprite_c *sprite) {

}

/* Original address: 0x0202B37C */
extern const u8 sMsgContinuePromptRed[8];
/* Original address: 0x0202B384 */
extern const u8 sMsgContinuePromptGreen[8];
/* Original address: 0x0202B38C */
extern const u8 sMsgContinuePromptBlue[8];

/* Original address: 0x0201C5FC */
void mMsg_ContinuePromptSetColor(s32 arg0) {
    u8 red[8];
    u8 green[8];
    u8 blue[8];

    memcpy(red, sMsgContinuePromptRed, sizeof(red));
    memcpy(green, sMsgContinuePromptGreen, sizeof(green));
    memcpy(blue, sMsgContinuePromptBlue, sizeof(blue));
    SetPaletteColor(1U, 7U, 6U, red[arg0], green[arg0], blue[arg0]);
    CpuFastSet(&gObjPaletteBuffer[7 * 16], (void *)(OBJ_PLTT + PLTT_OFFSET_4BPP(7)), 8U);
}

/* Original address: 0x0201C668 */
void mMsg_ContinuePromptCycleColor(m_msg_sprite_c *sprite) {
    mMsg_ContinuePromptSetColor((sprite->color_phase & 3) + sprite->_14 * 4);
    sprite->color_timer++;
    if (sprite->color_timer > 10) {
        sprite->color_phase++;
        sprite->color_timer = 0;
    }
    sub_0201C5F8(sprite);
}

/* Original address: 0x0201C69C */
void mMsg_ContinuePromptInit(m_msg_sprite_c *sprite) {
    mMsg_StartSpriteAnimation(sprite, sMsgContinuePromptAnimations, 0);
    sub_0201C5F8(sprite);
    sprite->state_proc = mMsg_ContinuePromptCycleColor;
    sprite->state_proc(sprite);
}

/* Original address: 0x0201C6C8 */
void mMsg_ContinuePromptDestroy(m_msg_sprite_c* sprite) {

}

/* Original address: 0x0201C6CC */
void mMsg_ContinuePromptUpdate(m_msg_sprite_c* sprite) {
    if (sprite->state_proc != NULL) {
        sprite->state_proc(sprite);
    }
    mMsg_UpdateSpriteAnimation(sprite, sMsgContinuePromptAnimations);
}

/* Original address: 0x0201C6EC */
void mMsg_ContinuePromptDraw(m_msg_sprite_c* sprite) {
    OAMData* oam = sMsgContinuePromptAnimations[sprite->animation_index]->sprite_gfx_p;

    while (oam->affine_param != 0xFFFF) {
        mMsg_CopySpriteOam(sprite, oam, (OAMData *)gUnk3002410 + gGameState.oam_count);
        gGameState.oam_count++;
        oam++;
    }
}

/* Original address: 0x0201C740 */
void mMsg_ChoiceCursorIdle(m_msg_sprite_c *sprite) {

}

/* Original address: 0x0201C744 */
void mMsg_ChoiceCursorInit(m_msg_sprite_c *sprite) {
    mMsg_StartSpriteAnimation(sprite, sMsgChoiceCursorAnimations, 0);
    sprite->state_proc = mMsg_ChoiceCursorIdle;
    sprite->state_proc(sprite);
}

/* Original address: 0x0201C768 */
void mMsg_ChoiceCursorDestroy(m_msg_sprite_c *sprite) {

}

/* Original address: 0x0201C76C */
void mMsg_ChoiceCursorUpdate(m_msg_sprite_c* sprite) {
    if (sprite->state_proc != NULL) {
        sprite->state_proc(sprite);
    }
    mMsg_UpdateSpriteAnimation(sprite, sMsgChoiceCursorAnimations);
}

/* Original address: 0x0201C78C */
void mMsg_ChoiceCursorDraw(m_msg_sprite_c* sprite) {
    OAMData* oam = sMsgChoiceCursorAnimations[sprite->animation_index]->sprite_gfx_p;

    while (oam->affine_param != 0xFFFF) {
        mMsg_CopySpriteOam(sprite, oam, (OAMData *)gUnk3002410 + gGameState.oam_count);
        gGameState.oam_count++;
        oam++;
    }
}
