#include "m_msg.h"
#include "audio.h"
#include "game.h"
#include "global.h"
#include <string.h>

extern int sMsgDirtyTileOffset;
extern int sMsgDirtyTileCount;
extern int _03000018; // ??
extern u8 sMsgPreviousTextRow;
extern u8 sMsgPreviousTextX;

/* Original address: 0x0201836C */
void mFont_GetGlyphRows(void* lower_rows, void* upper_rows, u8 character) {
    union {
        u64 packed;
        u8 rows[8];
    } lower, upper;
    u8* lower_dest;
    u32 glyph_offset;
    s32 i;

    lower.packed = *(u64*)lower_rows;
    upper.packed = *(u64*)upper_rows;

    if ((character == CHAR_CONTROL_CODE) || (character == 0x80) ||
        (character == CHAR_NEW_LINE)) {
        *(u64*)lower_rows = 0;
        *(u64*)upper_rows = 0;
        return;
    }

    /* Each 16-character block stores the upper tiles before the lower tiles. */
    glyph_offset = ((character >> 4) * 32 + (character & 0xF)) * 8;
    lower_dest = lower.rows;
    for (i = 0; i < 8; i++) {
        if (character != 0x20) {
            upper.rows[i] = ((u8*)sMsgFontGlyphs)[glyph_offset + i];
            lower_dest[i] = ((u8*)sMsgFontGlyphs + sizeof(sMsgFontGlyphs[0][0]))[glyph_offset + i];
        } else {
            upper.rows[i] = sMsgSpaceGlyph[0][i];
            lower_dest[i] = sMsgSpaceGlyph[1][i];
        }
    }

    *(u64*)lower_rows = lower.packed;
    *(u64*)upper_rows = upper.packed;
}

int mFont_GetGlyphWidth(u32 c) {
    if (c < 0x100) {
        return sMsgGlyphWidths[c];
    }
    return -1;
}

int mFont_GetCodeWidth(u32 c) {
    if (c < 0x100) {
        return sFontCodeWidths[c];
    }
    return -1;
}

void mMsg_MainSetup_Hide(mMsg_Window_c* msg) {
    mMsg_InitWindow(msg, msg->text, msg->tile_data);
}

void mMsg_Main_Hide(mMsg_Window_c* msg) {
    mMsg_MainSetup_Window(msg);
}

void mMsg_MainSetup_Appear(mMsg_Window_c* msg) {
    msg->message_length = mMsg_LoadMessage(msg->text, msg->next_message_id);
    if (msg->message_length > 0) {
        msg->draw_enabled = 1;
        msg->message_id = msg->next_message_id;
        msg->next_message_id = -1;
        msg->current_mode = msg->requested_mode;
        msg->requested_mode = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        GameAudio_PlayEffect0(0x1F);
    }
}

void mMsg_Main_Appear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);

    if (msg->transition_frame > 10 && mMsg_RequestCursor(msg) != 0) {
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame++;
    }
}

int mMsg_Cont_SetNextMessage(mMsg_Window_c* msg, s16* offset, int choice) {
    u32 message_id = (*(msg->text + *offset + 2) << 8) | *(msg->text + *offset + 3);

    if (choice == 0xFF || choice == msg->choice_index) {
        if (message_id <= 30) {
            msg->next_message_id = message_id;
        } else {
            msg->cancel_continue = 1;
        }
    }

    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_SetChoiceCount(mMsg_Window_c* msg, s16* offset, int count) {
    msg->choice_count = count;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 4;
}

int mMsg_Cont_SetChoiceText(mMsg_Window_c* msg, s16* offset, int index) {
    mMsg_ChoiceEntry_c* choice = &msg->choices[index];

    choice->length = *(msg->text + *offset + 2);
    mMsg_Copy(msg->text + *offset + 3, choice->text, choice->length);
    choice->line = msg->text_row;
    choice->x = msg->text_x;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_Last(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Continue(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Clear(mMsg_Window_c* msg, s16* offset) {
    mMsg_ClearText(msg);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Button(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        *offset += mFont_CodeSize_get(msg->text + *offset);
        return 2;
    }
}

int mMsg_Cont_SetNextMessageF(mMsg_Window_c* msg, s16* offset) {
    msg->force_next = 1;
    return mMsg_Cont_SetNextMessage(msg, offset, 0xFF);
}

int mMsg_Cont_SetNextMessage0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 0);
}

int mMsg_Cont_SetNextMessage1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 1);
}

int mMsg_Cont_SetTemporaryColor(mMsg_Window_c* msg, s16* offset) {
    msg->temporary_color_length = *(msg->text + *offset + 3);
    msg->temporary_color = *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Space(mMsg_Window_c* msg, s16* offset) {
    msg->text_x += *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_MoveDown(mMsg_Window_c* msg, s16* offset) {
    msg->text_row++;
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_RestoreCachedMessage(mMsg_Window_c* msg, s16* offset) {
    int i;
    for (i = 0; i < ARRAY_COUNT(sCachedMessageIds); i++) {
        if (sCachedMessageIds[i] == msg->message_id && &sMsgWindows[i] != msg) {
            u8* tile_data = msg->tile_data;
            u8* text = msg->text;
            u8 selected_choice = msg->selected_choice;

            CpuFastCopy(&sMsgWindows[i], msg, sizeof(mMsg_Window_c));
            msg->tile_data = tile_data;
            msg->text = text;
            msg->selected_choice = selected_choice;
            msg->draw_enabled = 1;
            mMsg_Copy(sMsgWindows[i].text, msg->text, msg->message_length);
            CpuFastCopy(sMsgWindows[i].tile_data, msg->tile_data, 0x1200);
            mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
            break;
        }
    }

    if (i == ARRAY_COUNT(sCachedMessageIds)) {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return 1;
}

int mMsg_Cont_SetChoiceCount2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 2);
}

int mMsg_Cont_SetChoiceCount3(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 3);
}

int mMsg_Cont_SetChoiceText0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 0);
}

int mMsg_Cont_SetChoiceText1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 1);
}

int mMsg_Cont_SetChoiceText2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 2);
}

int mMsg_Cont_CheckChoice(mMsg_Window_c* msg, s16* offset) {
    int ret = 3;

    if (*(msg->text + *offset + 2) == msg->choice_index + 1) {
        ret = 2;
    } else {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return ret;
}

int mMsg_Cont_SoundTrgSys(mMsg_Window_c* msg, s16* offset) {
    u8 sound = *(msg->text + *offset + 2);

    if (sound == 7 || sound == 8) {
        GameAudio_PlayEffect0(sound == 7 ? 0x10 : 0x02);
    }

    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 3;
}

/**
 * @brief Dummy procedure for control codes that don't do anything on GBA.
 * @param msg Pointer to the message structure.
 * @param ofs_p Pointer to the offset in the message code.
 * @return 1.
 */
int mMsg_Cont_Noop(mMsg_Window_c* msg, s16* offset) {
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

typedef int (*mMsg_CONTROL_CODE_PROC)(mMsg_Window_c* msg, s16* offset);

extern mMsg_CONTROL_CODE_PROC sMsgControlCodeHandlers[];

// @0x0201892c
/* Ghidra name: Msg_ProcessControlCode (differs from the existing contextual name). */
int mMsg_ProcessControlCode(mMsg_Window_c* msg, s16* offset) {
    int ret = 1;
    u8 code = msg->text[*offset];
    u8 type = msg->text[*offset + 1];
    
    if (code == CHAR_CONTROL_CODE && type <= mFont_CONT_CODE_CHECK_CHOICE) {
        ret = sMsgControlCodeHandlers[type](msg, offset);
    }

    return ret;
}

void mMsg_MainSetup_Cursor(mMsg_Window_c* msg) {
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Cursor(mMsg_Window_c* msg) {
    int process_res;
    u8 res;
    int i;

    sMsgPreviousTextRow = msg->text_row;
    sMsgPreviousTextX = msg->text_x;
    
    process_res = mMsg_ProcessText(msg, msg->tile_data, 1);
    switch (process_res) {
        case 4:
            res = mMsg_RequestChoice(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
        case 2:
            res = mMsg_RequestNormal(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
    }

    for (i = sMsgPreviousTextRow; sMsgPreviousTextRow < msg->text_row; i++) {
        int temp;

        sMsgDirtyTileOffset = sMsgPreviousTextRow * msg->tile_stride + sMsgPreviousTextX / 8;
        temp = msg->tile_stride * 8 - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }
        sMsgDirtyTileCount = temp >> 3;

        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
        sMsgPreviousTextX = msg->text_start_x;
        sMsgPreviousTextRow += 2;
        sMsgPreviousTextRow &= 0xFE;
    }

    if (sMsgPreviousTextX != msg->text_x) {
        int temp;

        sMsgDirtyTileOffset = msg->text_row * msg->tile_stride + sMsgPreviousTextX / 8;
        sMsgDirtyTileCount = MIN(msg->tile_stride * 8, msg->text_x);

        temp = sMsgDirtyTileCount - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }

        sMsgDirtyTileCount = temp >> 3;
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
    }
}

static int mMsg_CheckAdvanceInput(void) {
    return gGameState.keys.buttons.pressed & (u16)(A_BUTTON | B_BUTTON);
}

void mMsg_MainSetup_Normal(mMsg_Window_c* msg) {
    msg->status_flags &= ~mMsg_STATUS_END_REACHED;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Normal(mMsg_Window_c* msg) {
    int is_terminal_code = 0;

    if (mMsg_EndTimerDec(msg) == 1) {
        if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
            if (mMsg_RequestDisappear(msg) != 0) {
                mMsg_MainSetup_Window(msg);
            }
            return;
        }
    }

    if (mMsg_CheckAdvanceInput() || msg->force_next == 1) {
        if (msg->lock_continue == 0) {

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 0) {
                if ((u32)msg->next_message_id <= 30 &&
                    mMsg_ChangeMsgData(msg, msg->next_message_id) == 1) {
                    if (mMsg_RequestCursor(msg) != 0) {
                        mMsg_MainSetup_Window(msg);
                        msg->force_next = 0;
                        msg->next_message_id = -1;
                    }
                }
                return;
            }

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 1) {
                goto here;
            } else {
                is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CHECK_CHOICE,
                                                        msg->text_offset);
                if (!is_terminal_code) {
                    is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_LAST,
                                                            msg->text_offset);
                }
            }
            if (is_terminal_code || mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
                here:
                if (is_terminal_code && (msg->status_flags & (1 << 1))) {
                    msg->status_flags |= (1 << 2);
                } else if (mMsg_RequestDisappear(msg) != 0) {
                    mMsg_MainSetup_Window(msg);
                }
            } else if (mMsg_RequestCursor(msg) != 0) {
                mMsg_MainSetup_Window(msg);
                msg->force_next = 0;
            }
            return;
        }
    }

    if (!mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
        msg->lock_continue == 0 && msg->continue_prompt == ((void *)0)) {
        if (msg->message_id == 1 || msg->message_id == 2)
            msg->continue_prompt = mMsg_CreateSprite(0xA, 0xC8, 0x68, 1);
        else
            msg->continue_prompt = mMsg_CreateSprite(0xA, 0xC8, 0x68, 0);
    }
}

void mMsg_MainSetup_Disappear(mMsg_Window_c* msg) {
    msg->transition_frame = 12;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x20);
}

static void mMsg_Main_Disappear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if (msg->transition_frame == 0 && mMsg_RequestHide(msg) != 0) {
        gGameState.sleep_requested = 0;
        gGameState.sleep_dialog_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame--;
    }
}

/* Original address: 0x02018D10 */
s32 mMsg_CheckChoiceNext(mMsg_Window_c *msg) {
    s32 result;

    if (msg->message_id == 0x19) {
        result = 0;
        if ((gGameState.keys.buttons.pressed & DPAD_DOWN) &&
            msg->choice_count - 1 > msg->choice_index) {
            result = 1;
        }
    } else {
        result = 0;
        if ((gGameState.keys.buttons.pressed & DPAD_RIGHT) &&
            msg->choice_count - 1 > msg->choice_index) {
            result = 1;
        }
    }
    return result;
}

/* Original address: 0x02018D64 */
s32 mMsg_CheckChoicePrevious(mMsg_Window_c *msg) {
    s32 result;

    if (msg->message_id == 0x19) {
        result = 0;
        if (gGameState.keys.buttons.pressed & DPAD_UP) {
            result = msg->choice_index != 0;
        }
    } else {
        result = 0;
        if (gGameState.keys.buttons.pressed & DPAD_LEFT) {
            result = msg->choice_index != 0;
        }
    }
    return result;
}

void mMsg_UpdateChoiceCursorPosition(mMsg_Window_c *msg) {
    m_msg_sprite_c *cursor;

    cursor = msg->choice_cursor;
    if (cursor != NULL) {
        cursor->_30 = (msg->choices[msg->choice_index].line + 7) * 8;
        cursor->_2C = msg->choices[msg->choice_index].x + 0x2F;
    }
}

/* Original address: 0x02018DE8 */
void mMsg_UpdateChoiceHighlight(mMsg_Window_c *msg) {
    mMsg_TwoChoiceHighlights two_choice_tiles = gMsgTwoChoiceHighlightTiles;
    mMsg_ThreeChoiceHighlights three_choice_tiles = gMsgThreeChoiceHighlightTiles;
    u16 first_choice_tile;

    first_choice_tile = msg->tile_stride * msg->choices[0].line;

    if (msg->message_id == 0x19) {
        CpuFastSet(three_choice_tiles.tiles[msg->choice_index],
                   (void *)(BG_VRAM + TILE_OFFSET_4BPP(first_choice_tile + 0x100)),
                   (msg->tile_stride * 0x30) & 0x1FFFFF);
        CpuFastSet(three_choice_tiles.tiles[msg->choice_index],
                   msg->tile_data + TILE_OFFSET_4BPP(first_choice_tile),
                   (msg->tile_stride * 0x30) & 0x1FFFFF);
    } else {
        CpuFastSet(two_choice_tiles.tiles[msg->choice_index],
                   (void *)(BG_VRAM + TILE_OFFSET_4BPP(first_choice_tile + 0x100)),
                   (msg->tile_stride * 0x10) & 0x1FFFFF);
        CpuFastSet(two_choice_tiles.tiles[msg->choice_index],
                   msg->tile_data + TILE_OFFSET_4BPP(first_choice_tile),
                   (msg->tile_stride * 0x10) & 0x1FFFFF);
    }
}

void mMsg_MainSetup_Choice(mMsg_Window_c *msg) {
    msg->choice_cursor = mMsg_CreateSprite(0xBU, 0, 0, 0);
    mMsg_UpdateChoiceCursorPosition(msg);
    mMsg_UpdateChoiceHighlight(msg);
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
}

void mMsg_Main_Choice(mMsg_Window_c *msg) {
    u16 sound;
    s8 choice_index;

    if (msg->selected_choice != -1) {
        if (mMsg_TimerDec(msg) != 0) {
            mMsg_MainSetup_Window(msg);
        }
    } else {
        if (msg->choice_cursor == NULL) {
            msg->choice_cursor = mMsg_CreateSprite(0xBU, 0, 0, 0);
            mMsg_UpdateChoiceCursorPosition(msg);
            mMsg_UpdateChoiceHighlight(msg);
            return;
        }
        if ((A_BUTTON & gGameState.keys.buttons.pressed) && (mMsg_RequestCursor(msg) != 0)) {
            msg->force_next = 1;
            choice_index = msg->choice_index;
            msg->selected_choice = choice_index;
            __asm__("" : "+r" (choice_index)); // @HACK
            sound = choice_index == 0 ? 0x10 : 0x11;
            mMsg_SetTimer(msg, 0x14);
            GameAudio_PlayEffect0(sound);
            return;
        }
        if (mMsg_CheckChoiceNext(msg) != 0) {
            msg->choice_index += 1;
            GameAudio_PlayEffect0(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        if (mMsg_CheckChoicePrevious(msg) != 0) {
            msg->choice_index -= 1;
            GameAudio_PlayEffect0(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        mMsg_UpdateChoiceCursorPosition(msg);
    }
}

void mMsg_MainSetup_DisappearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 12;
    msg->saved_mode = msg->current_mode;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x20U);
}

void mMsg_Main_DisappearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0) {
        msg->transition_frame = (u8) msg->transition_frame - 1;
        return;
    }
    msg->draw_enabled = 0;
}

void mMsg_MainSetup_AppearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 0;
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    GameAudio_PlayEffect0(0x1FU);
}

void mMsg_Main_AppearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0xA) {
        msg->current_mode = msg->saved_mode;
        msg->draw_enabled = 1;
        return;
    }
    msg->transition_frame = (u8) msg->transition_frame + 1;
}

void mMsg_CopyTilesToVram(s32 tile, s32 count, u8 *tile_data) {
    if (count > 0) {
        CpuFastCopy(tile_data + (tile * 32), gMsgVram + (tile * 16) + (tile * 16), count * 32);
    }
}

s32 mMsg_GetWindowScrollOffset(s8 *frame) {
    if (*frame >= 12) {
        *frame = 11;
    }
    if (*frame < 0) {
        *frame = 0;
    }

    return gMsgWindowScrollOffsets[(s8) (u8) *frame];
}

s8 mMsg_RequestMode(mMsg_Window_c *msg, s8 mode) {
    msg->requested_mode = mode;
    return 1;
}

s8 mMsg_RequestDisappear(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR);
}

s8 mMsg_RequestAppear(mMsg_Window_c *msg, s32 message_id) {
    s8 result;

    result = mMsg_RequestMode(msg, mMsg_MODE_APPEAR);
    if (result == 1) {
        msg->next_message_id = message_id;
    }
    return result;
}

s8 mMsg_RequestCursor(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CURSOR);
}

s8 mMsg_RequestNormal(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_NORMAL);
}

s8 mMsg_RequestHide(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_HIDE);
}

s8 mMsg_RequestChoice(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CHOICE);
}

s8 mMsg_RequestDisappearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_CURSOR || msg->current_mode == mMsg_MODE_NORMAL || msg->current_mode == mMsg_MODE_CHOICE) {
        return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR_WAIT);
    }

    return 0;
}

s8 mMsg_RequestAppearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_DISAPPEAR_WAIT) {
        return mMsg_RequestMode(msg, mMsg_MODE_APPEAR_WAIT);
    }

    return 0;
}

/* Original address: 0x020191E8 */
s32 mMsg_GetMessageBody(u32 index, u8 **data, s16 *size) {
    u8 encoded[4];
    u8 decoded[4];
    u32 message_offset;
    u32 message_size;

    if (index >= ARRAY_COUNT(sMsgOffsets)) {
        *data = NULL;
        *size = 0;
        return 0;
    }
    if (index != 0) {
        *(u32*)encoded = (sMsgOffsets - 1)[index];
        decoded[3] = encoded[0];
        decoded[2] = encoded[1];
        decoded[1] = encoded[2];
        decoded[0] = encoded[3];
        message_offset = *(u32*)decoded;
    } else {
        message_offset = 0;
    }
    *(u32*)encoded = sMsgOffsets[index];
    decoded[3] = encoded[0];
    decoded[2] = encoded[1];
    decoded[1] = encoded[2];
    decoded[0] = encoded[3];
    message_size = *(u32*)decoded - message_offset;
    if (message_size < 0x200) {
        *data = &gMsgTextData[message_offset];
        *size = message_size;
    } else {
        *size = 0;
        *data = NULL;
    }
    return 1;
}

/* Ghidra name: mMsg_GetStrLenWithEndContCodes (differs from the existing contextual name). */
s16 mMsg_GetMessageLength(u8 *text) {
    s32 offset;
    u8 *next;
    u8 control_code;

    offset = 0;
loop_1:
    offset += mFont_CodeSize_get(&text[offset]);
    next = &text[offset];
    if ((next[0] != CHAR_CONTROL_CODE) ||
        ((control_code = next[1], (control_code != mFont_CONT_CODE_MSG_TIME_END)) &&
         (control_code != mFont_CONT_CODE_LAST) && (control_code != mFont_CONT_CODE_CONTINUE))) {
        if (offset <= 0x1FF) {
            goto loop_1;
        }
    }
    return (s16) offset;
}

/* Ghidra name: ControlCode_GetSize (differs from the existing contextual name). */
s8 mFont_CodeSize_get(u8 *code) {
    u8 size;

    if (code[0] == CHAR_CONTROL_CODE) {
        size = sMsgControlCodeInfo[code[1]].size;
    } else {
        size = 1;
    }
    return (s8) size;
}

/* Original address: 0x020192E8 */
s16 mMsg_LoadMessage(u8 *text, s32 index) {
    s16 size;
    u8 *source;

    if ((mMsg_GetMessageBody((u32) index, &source, &size) == 1) && (source != NULL) && (size != 0)) {
        mMsg_Copy(source, text, size);
        return mMsg_GetMessageLength(text);
    }
    return 0;
}

void mMsg_ClearText(mMsg_Window_c *msg) {
    CpuFastFill(0x55555555, msg->tile_data, 0x1200);
    mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
    msg->text_x = msg->text_start_x;
    msg->text_row = 0;
    msg->temporary_color_length = 0;
}

s32 mMsg_ChangeMsgData(mMsg_Window_c *msg, s32 index) {
    s32 result;

    result = 0;
    if (((u32) index <= 0x1EU) && ((mMsg_LoadMessage(msg->text, index) << 0x10) != 0)) {
        msg->message_id = index;
        msg->next_message_id = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        mMsg_SetTimer(msg, 0x14);
        result = 1;
    }
    return result;
}

void mMsg_SetTimer(mMsg_Window_c *msg, s32 frames) {
    msg->text_delay_timer = frames;
}

/* Ghidra name: Msg_DecrementCodeSize (differs; this decrements the text-delay timer). */
s32 mMsg_TimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->text_delay_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->text_delay_timer = next_timer;
    return expired;
}

void mMsg_SetEndTimer(mMsg_Window_c *msg, s32 frames) {
    msg->end_timer = frames;
}

s32 mMsg_EndTimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->end_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->end_timer = next_timer;
    return expired;
}

void mMsg_DestroySprites(mMsg_Window_c *msg) {
    m_msg_sprite_c *sprite;

    sprite = msg->choice_cursor;
    if (sprite != NULL) {
        mMsg_DeactivateSprite(sprite);
        msg->choice_cursor = NULL;
    }
    sprite = msg->continue_prompt;
    if (sprite != NULL) {
        mMsg_DeactivateSprite(sprite);
        msg->continue_prompt = NULL;
    }
}

s32 mMsg_CheckControlCode(u8 *text, u8 type, s16 offset) {
    s32 result;
    u8 *code;

    result = 0;
    code = &text[offset];
    if ((code[0] == CHAR_CONTROL_CODE) && (code[1] == type)) {
        result = 1;
    }
    return result;
}

/* Ghidra name: Msg_ProcessLines (differs from the existing contextual name). */
/* Original address: 0x02019440 */
s32 mMsg_ProcessText(mMsg_Window_c *msg, u8 *tile_data, s32 max_characters) {
    u8 *destination;
    s32 result;
    u8 palette;
    s32 glyph_width;
    s32 characters_processed;
    s8 tile_stride;
    u8 *code;
    u8 temporary_color_length;
    u8 character;

    result = 1;
    palette = 6;
    if (mMsg_TimerDec(msg) != 0) {
        return 1;
    }
    characters_processed = 0;
    while ((characters_processed < max_characters) && (msg->text_delay_timer == 0)) {
        code = &msg->text[msg->text_offset];
        character = *code;
        if (character == CHAR_NEW_LINE) {
            msg->text_offset += mFont_CodeSize_get(code);
            msg->text_x = msg->text_start_x;
            msg->text_row += 2;
            msg->text_row &= ~1;
            break;
        } else {
            if (character == CHAR_CONTROL_CODE) {
                result = mMsg_ProcessControlCode(msg, &msg->text_offset);
                if ((result >= 2) && (result <= 4)) {
                    break;
                }
            } else {
                glyph_width = mFont_GetGlyphWidth(character);
                tile_stride = msg->tile_stride;
                if (tile_stride * 8 >= (s16) (msg->text_x - 1) + glyph_width) {
                    destination = tile_data + ((tile_stride * msg->text_row) << 5);
                    temporary_color_length = msg->temporary_color_length;
                    if (temporary_color_length != 0) {
                        palette = msg->temporary_color;
                        msg->temporary_color_length = temporary_color_length - 1;
                    }
                    if (character == CHAR_SPACE) {
                        character = CHAR_SPACE_GBA;
                    }
                    mFont_DrawCharToTiles(destination, msg->text_x, 0, (u16)msg->tile_stride, character, palette, glyph_width - 1);
                    msg->text_x += glyph_width;
                }
                msg->text_offset += mFont_CodeSize_get(&msg->text[msg->text_offset]);
                characters_processed += 1;
            }
        }
    }
    return result;
}

/* Original address: 0x02019580 */
void mMsg_Init(void) {
    u8 init_data[4];
    s32 i;

    memcpy(init_data, gMsgChoiceTemplateParams, sizeof(init_data));

    for (i = 0; i < 2; i++) {
        u8 *codeBuf = gMsgCodeBuffers[i];
        u8 *tileBuf = gMsgTileBuffers[i];
        u8 *windowTileBuf = gMsgWindowTileData[i];

        mMsg_InitWindow(&sMsgWindows[i], gMsgCodeBuffers[i], gMsgTileBuffers[i]);
        sMsgWindows[i].text_x = sMsgWindows[i].text_start_x;
        sMsgWindows[i].text_row = 0;
        sMsgWindows[i].message_length = mMsg_LoadMessage(sMsgWindows[i].text, 0x18);
        sMsgWindows[i].text[5] = init_data[i * 2];
        sMsgWindows[i].text[0xF] = init_data[i * 2 + 1];
        sMsgWindows[i].tile_data = gMsgWindowTileData[i];
        CpuFastFill(0x55555555, sMsgWindows[i].tile_data, 0x480);

        while (mMsg_ProcessText(&sMsgWindows[i], sMsgWindows[i].tile_data, 1) == 1) {
        }
    }

    for (i = 0; i < ARRAY_COUNT(sMsgWindows); i++) {
        mMsg_Window_c* msg = &sMsgWindows[i];
        u8 *codeBuf = gMsgCodeBuffers[i];
        u8 *tileBuf = gMsgTileBuffers[i];
        u16 saved_text_offset;

        mMsg_InitWindow(msg, codeBuf, tileBuf);
        mMsg_ClearText(msg);
        sMsgWindows[i].message_id = sCachedMessageIds[i];
        sMsgWindows[i].message_length = mMsg_LoadMessage(sMsgWindows[i].text, sMsgWindows[i].message_id);
        sMsgWindows[i].current_mode = mMsg_MODE_CURSOR;

        do {
            saved_text_offset = sMsgWindows[i].text_offset;
        } while (mMsg_ProcessText(&sMsgWindows[i], sMsgWindows[i].tile_data, 1) == 1);
        sMsgWindows[i].text_offset = saved_text_offset;
    }
}

void mMsg_MainSetup_Window(mMsg_Window_c *msg) {
    // TODO: chained conditional comparison that got optimized
    if (((u8)(msg->requested_mode - 1) <= 8U) && (gMsgModeSetupCallbacks[msg->requested_mode] != NULL)) {
        mMsg_DestroySprites(msg);
        gMsgModeSetupCallbacks[msg->requested_mode](msg);
    }
}

void mMsg_InitWindow(mMsg_Window_c *msg, u8 *text, u8 *tile_data) {
    CpuFastFill(0, msg, sizeof(*msg));
    msg->tile_data = tile_data;
    msg->text = text;
    msg->next_message_id = -1;
    msg->message_id = -1;
    msg->current_mode = mMsg_MODE_HIDE;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
    msg->tile_stride = 0x12;
    msg->text_start_x = 1;
    msg->draw_enabled = 0;
}

void mMsg_Main_Window(mMsg_Window_c *msg) {
    void (*main)(mMsg_Window_c *);

    main = gMsgModeCallbacks[(s8) (u8) msg->current_mode];
    if (main != NULL) {
        main(msg);
    }
}

/* Original address: 0x020197CC */
s32 mFont_DrawStringToTiles(u8 *tile_data, u16 *cursor, u16 y, u16 tile_stride, u8 *text, s32 length, u8 palette, u8 stop_at_newline, u8 fixed_width) {
    s32 characters_drawn;
    u32 character;
    s32 character_width;
    u16 current_x;

    for (characters_drawn = 0; characters_drawn < length; characters_drawn++) {
        character = text[characters_drawn];
        if ((stop_at_newline == 1 && character == CHAR_NEW_LINE) || character == CHAR_CONTROL_CODE) {
            break;
        }
        character++,character--; // Required to match
        if (fixed_width != 1) {
            character_width = mFont_GetGlyphWidth(character);
        } else {
            character_width = 8;
        }
        current_x = *cursor;
        if (character_width + current_x > tile_stride * 8) {
            break;
        }
        mFont_DrawCharToTiles(tile_data + (((y >> 3) * tile_stride) << 5),
                              current_x, y & 7, tile_stride, character, palette,
                              character_width - 1);
        *cursor += character_width;
    }
    return characters_drawn;
}

/* Original address: 0x02019880 */
void mFont_DrawCharToTiles(u8 *tile_data, s32 tile_offset, s32 row, s32 tile_stride, s32 character, s32 palette, s32 width) {
    mFont_GlyphDraw_c* glyph = &gMsgGlyph;

    glyph->tile_data = tile_data;
    glyph->tile_offset = tile_offset;
    glyph->row = row;
    glyph->tile_stride = tile_stride;
    glyph->palette = palette;
    mFont_GetGlyphRows(glyph->glyph_lower_rows, glyph->glyph_upper_rows, character);
    mFont_BlitGlyphToTiles(glyph, width);
}

/* Original address: 0x020198B8 */
void mFont_CopyTileBufferToVram(s8 index) {
    void* dest[3];
    void* src[3];
    u32 size[3];

    memcpy(dest, sFontTileBufferVramDestinations, sizeof(dest));
    memset(src, 0, sizeof(src));
    memcpy(size, sFontTileBufferSizes, sizeof(size));

    if (index >= 0) {
        CpuFastCopy(src[index], dest[index], size[index]);
    }
}

/* Original address: 0x02019910 */
void mFont_FillTileBuffer(u8 value, s8 index) {
    void* dest[3];
    u32 size[3];
    u32 pixels;
    s32 i;

    memset(dest, 0, sizeof(dest));
    memcpy(size, sFontTileBufferSizes, sizeof(size));

    if (index >= 0) {
        pixels = 0;
        for (i = 0; i < 8; i++) {
            pixels |= (value & 0xF) << (i * 4);
        }
        CpuFastFill(pixels, dest[index], size[index]);
    }
}

/* Original address: 0x02019980 */
void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c *glyph, s32 width) {
    s32 glyph_row;
    u16 y;
    s32 column;
    u16 x;
    u16 tile_index;
    u16 byte_offset;
    u8 packed_pixels;

    for (glyph_row = 0, y = glyph->row; glyph_row < 8; glyph_row++, y++) {
        for (column = 0, x = glyph->tile_offset; column < width; column++, x++) {
            tile_index = (y >> 3) * glyph->tile_stride + (x >> 3);
            if ((glyph->glyph_upper_rows[glyph_row] >> column) & 1) {
                byte_offset = (tile_index << 5) + (y & 7) * 4 + ((x & 7) >> 1);
                packed_pixels = glyph->tile_data[byte_offset];

                if (x & 1) {
                    packed_pixels = (packed_pixels & 0xF) | ((glyph->palette & 0xF) << 4);
                } else {
                    packed_pixels = (packed_pixels & 0xF0) | (glyph->palette & 0xF);
                }
                glyph->tile_data[byte_offset] = packed_pixels;
            }
            tile_index += glyph->tile_stride;
            if ((glyph->glyph_lower_rows[glyph_row] >> column) & 1) {
                byte_offset = (tile_index << 5) + (y & 7) * 4 + ((x & 7) >> 1);
                packed_pixels = glyph->tile_data[byte_offset];

                if (x & 1) {
                    packed_pixels &= 0xF;
                    packed_pixels |= (glyph->palette & 0xF) << 4;
                } else {
                    packed_pixels &= 0xF0;
                    packed_pixels |= glyph->palette & 0xF;
                }
                glyph->tile_data[byte_offset] = packed_pixels;
            }
        }
    }
}
