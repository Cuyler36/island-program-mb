#ifndef M_MSG_H
#define M_MSG_H

#include "gba/types.h"
#include "charmap.h"
#include "anim.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    mFont_CONT_CODE_BEGIN = 0,
    mFont_CONT_CODE_LAST = mFont_CONT_CODE_BEGIN,
    mFont_CONT_CODE_CONTINUE,
    mFont_CONT_CODE_CLEAR,
    mFont_CONT_CODE_CURSOR_SET_TIME,
    mFont_CONT_CODE_BUTTON,
    mFont_CONT_CODE_COLOR,
    mFont_CONT_CODE_ABLE_CANCEL,
    mFont_CONT_CODE_UNABLE_CANCEL,
    mFont_CONT_CODE_SET_DEMO_ORDER_PLAYER,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC0,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC1,
    mFont_CONT_CODE_SET_DEMO_ORDER_NPC2,
    mFont_CONT_CODE_SET_DEMO_ORDER_QUEST,
    mFont_CONT_CODE_SET_SELECT_WINDOW,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_F,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_0,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_1,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_2,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_3,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_2,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_3,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_4,
    mFont_CONT_CODE_SET_SELECT_STRING_2,
    mFont_CONT_CODE_SET_SELECT_STRING_3,
    mFont_CONT_CODE_SET_SELECT_STRING_4,
    mFont_CONT_CODE_SET_FORCE_NEXT,
    mFont_CONT_CODE_PUT_STRING_PLAYER_NAME,
    mFont_CONT_CODE_PUT_STRING_TALK_NAME,
    mFont_CONT_CODE_PUT_STRING_TAIL,
    mFont_CONT_CODE_PUT_STRING_YEAR,
    mFont_CONT_CODE_PUT_STRING_MONTH,
    mFont_CONT_CODE_PUT_STRING_WEEK,
    mFont_CONT_CODE_PUT_STRING_DAY,
    mFont_CONT_CODE_PUT_STRING_HOUR,
    mFont_CONT_CODE_PUT_STRING_MIN,
    mFont_CONT_CODE_PUT_STRING_SEC,
    mFont_CONT_CODE_PUT_STRING_FREE0,
    mFont_CONT_CODE_PUT_STRING_FREE1,
    mFont_CONT_CODE_PUT_STRING_FREE2,
    mFont_CONT_CODE_PUT_STRING_FREE3,
    mFont_CONT_CODE_PUT_STRING_FREE4,
    mFont_CONT_CODE_PUT_STRING_FREE5,
    mFont_CONT_CODE_PUT_STRING_FREE6,
    mFont_CONT_CODE_PUT_STRING_FREE7,
    mFont_CONT_CODE_PUT_STRING_FREE8,
    mFont_CONT_CODE_PUT_STRING_FREE9,
    mFont_CONT_CODE_PUT_STRING_DETERMINATION,
    mFont_CONT_CODE_PUT_STRING_COUNTRY_NAME,
    mFont_CONT_CODE_PUT_STRING_RANDOM_NUMBER_2,
    mFont_CONT_CODE_PUT_STRING_ITEM0,
    mFont_CONT_CODE_PUT_STRING_ITEM1,
    mFont_CONT_CODE_PUT_STRING_ITEM2,
    mFont_CONT_CODE_PUT_STRING_ITEM3,
    mFont_CONT_CODE_PUT_STRING_ITEM4,
    mFont_CONT_CODE_PUT_STRING_FREE10,
    mFont_CONT_CODE_PUT_STRING_FREE11,
    mFont_CONT_CODE_PUT_STRING_FREE12,
    mFont_CONT_CODE_PUT_STRING_FREE13,
    mFont_CONT_CODE_PUT_STRING_FREE14,
    mFont_CONT_CODE_PUT_STRING_FREE15,
    mFont_CONT_CODE_PUT_STRING_FREE16,
    mFont_CONT_CODE_PUT_STRING_FREE17,
    mFont_CONT_CODE_PUT_STRING_FREE18,
    mFont_CONT_CODE_PUT_STRING_FREE19,
    mFont_CONT_CODE_PUT_STRING_MAIL,
    mFont_CONT_CODE_SET_PLAYER_DESTINY0,
    mFont_CONT_CODE_SET_PLAYER_DESTINY1,
    mFont_CONT_CODE_SET_PLAYER_DESTINY2,
    mFont_CONT_CODE_SET_PLAYER_DESTINY3,
    mFont_CONT_CODE_SET_PLAYER_DESTINY4,
    mFont_CONT_CODE_SET_PLAYER_DESTINY5,
    mFont_CONT_CODE_SET_PLAYER_DESTINY6,
    mFont_CONT_CODE_SET_PLAYER_DESTINY7,
    mFont_CONT_CODE_SET_PLAYER_DESTINY8,
    mFont_CONT_CODE_SET_PLAYER_DESTINY9,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_NORMAL,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_ANGRY,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SAD,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_FUN,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SLEEPY,
    mFont_CONT_CODE_SET_COLOR_CHAR,
    mFont_CONT_CODE_SOUND_CUT,
    mFont_CONT_CODE_SET_LINE_OFFSET,
    mFont_CONT_CODE_SET_LINE_TYPE,
    mFont_CONT_CODE_SET_CHAR_SCALE,
    mFont_CONT_CODE_BUTTON2,
    mFont_CONT_CODE_BGM_MAKE,
    mFont_CONT_CODE_BGM_DELETE,
    mFont_CONT_CODE_MSG_TIME_END,
    mFont_CONT_CODE_SOUND_TRG_SYS,
    mFont_CONT_CODE_SET_LINE_SCALE,
    mFont_CONT_CODE_SOUND_NO_PAGE,
    mFont_CONT_CODE_VOICE_TRUE,
    mFont_CONT_CODE_VOICE_FALSE,
    mFont_CONT_CODE_SELECT_NO_B,
    mFont_CONT_CODE_GIVE_OPEN,
    mFont_CONT_CODE_GIVE_CLOSE,
    mFont_CONT_CODE_SET_MESSAGE_CONTENTS_GLOOMY,
    mFont_CONT_CODE_SELECT_NO_B_CLOSE,
    mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_SECTION,
    mFont_CONT_CODE_UNKNOWN_100,
    mFont_CONT_CODE_UNKNOWN_101,
    mFont_CONT_CODE_SET_TEMPORARY_COLOR,
    mFont_CONT_CODE_SPACE,
    mFont_CONT_CODE_MOVE_DOWN,
    mFont_CONT_CODE_RESTORE_CACHED_MESSAGE,
    mFont_CONT_CODE_MALE_FEMALE_CHECK,
    mFont_CONT_CODE_SET_CHOICE_COUNT_2,
    mFont_CONT_CODE_SET_CHOICE_COUNT_3,
    mFont_CONT_CODE_SET_CHOICE_TEXT_0,
    mFont_CONT_CODE_SET_CHOICE_TEXT_1,
    mFont_CONT_CODE_SET_CHOICE_TEXT_2,
    mFont_CONT_CODE_CHECK_CHOICE,
  
    mFont_CONT_CODE_NUM,
    mFont_CONT_CODE_END = 256
};

enum {
    mMsg_MODE_HIDE = 1,
    mMsg_MODE_APPEAR,
    mMsg_MODE_CURSOR,
    mMsg_MODE_NORMAL,
    mMsg_MODE_CHOICE,
    mMsg_MODE_DISAPPEAR,
    mMsg_MODE_DISAPPEAR_WAIT,
    mMsg_MODE_APPEAR_WAIT,
};

#define mMsg_STATUS_KEEP_OPEN (1 << 1)
#define mMsg_STATUS_END_REACHED (1 << 2)
#define mMsg_STATUS_LAST_DELAY (1 << 8)

typedef struct m_msg_choice_entry_s {
    int line;
    int x;
    u8 text[10];
    u8 length;
    u8 _13[5];
} mMsg_ChoiceEntry_c;

/*
 * Objects allocated by mMsg_CreateSprite for the message UI.  Only the fields
 * touched by the message code are known so far; the allocation is 0x60 bytes.
 */
typedef struct m_msg_sprite_s {
    void (*init)(struct m_msg_sprite_s*);
    void (*destroy)(struct m_msg_sprite_s*);
    void (*update)(struct m_msg_sprite_s*);
    void (*draw)(struct m_msg_sprite_s*);
    void (*state_proc)(struct m_msg_sprite_s*);
    s32 _14;
    /* 0x18 */ s32 color_phase;
    /* 0x1C */ s32 color_timer;
    s32 offset_x;
    s32 offset_y;
    s32 _28;
    s32 _2C;
    s32 _30;
    s16 frame_timer;
    s16 frame_index;
    s16 animation_index;
    u8 _3A[0x1D];
    u8 _57;
    u8 _58[8];
} m_msg_sprite_c;

typedef struct m_msg_sprite_profile_s {
    void (*init)(m_msg_sprite_c*);
    void (*destroy)(m_msg_sprite_c*);
    void (*update)(m_msg_sprite_c*);
    void (*draw)(m_msg_sprite_c*);
} mMsg_SpriteProfile;

/* Scratch description used while drawing one eight-row message glyph. */
typedef struct mFont_GlyphDraw_s {
    u8* tile_data;
    u16 tile_offset;
    u16 row;
    u16 tile_stride;
    u8 _0A[4];
    u8 palette;
    u8 _0F;
    u8 glyph_lower_rows[8];
    u8 glyph_upper_rows[8];
} mFont_GlyphDraw_c;

typedef struct mFont_ControlCodeInfo_s {
    u8 size;
    u8 _01;
    u8 _02;
    u8 _03;
} mFont_ControlCodeInfo_c;

typedef union mMsg_U32Bytes_u {
    u32 word;
    u8 bytes[4];
} mMsg_U32Bytes_c;

typedef struct mMsg_Window_s {
    mMsg_ChoiceEntry_c choices[3];
    m_msg_sprite_c* choice_cursor;
    m_msg_sprite_c* continue_prompt;
    u8* tile_data;
    u8* text;
    int next_message_id;
    int message_id;
    int text_delay_timer;
    int end_timer;
    u32 status_flags;
    s16 text_offset;
    s16 message_length;
    s8 current_mode;
    s8 requested_mode;
    u8 saved_mode;
    s8 tile_stride;
    s8 text_row;
    u8 text_start_x;
    s8 transition_frame;
    s8 selected_choice;
    u8 text_x;
    u8 force_next;
    u8 lock_continue;
    u8 cancel_continue;
    u8 draw_enabled;
    u8 temporary_color;
    u8 temporary_color_length;
    u8 choice_count;
    u8 choice_index;
    u8 _81[0xA0 - 0x81];
} mMsg_Window_c;

typedef void (*mMsg_Callback)(mMsg_Window_c*);
typedef void (*mMsg_SETUP_PROC)(mMsg_Window_c*);
typedef void (*mMsg_MAIN_PROC)(mMsg_Window_c*);

void mFont_GetGlyphRows(void* lower_rows, void* upper_rows, u8 character);
int mFont_GetGlyphWidth(u32 character);
int mFont_GetCodeWidth(u32 character);
int mMsg_ProcessControlCode(mMsg_Window_c* msg, s16* offset);
s32 mMsg_CheckChoiceNext(mMsg_Window_c* msg);
s32 mMsg_CheckChoicePrevious(mMsg_Window_c* msg);
void mMsg_UpdateChoiceCursorPosition(mMsg_Window_c* msg);
void mMsg_UpdateChoiceHighlight(mMsg_Window_c* msg);
void mMsg_MainSetup_Choice(mMsg_Window_c* msg);
void mMsg_Main_Choice(mMsg_Window_c* msg);
void mMsg_MainSetup_DisappearWait(mMsg_Window_c* msg);
void mMsg_Main_DisappearWait(mMsg_Window_c* msg);
void mMsg_MainSetup_AppearWait(mMsg_Window_c* msg);
void mMsg_Main_AppearWait(mMsg_Window_c* msg);
void mMsg_CopyTilesToVram(s32 tile, s32 count, u8* tile_data);
s32 mMsg_GetWindowScrollOffset(s8* frame);
s8 mMsg_RequestMode(mMsg_Window_c* msg, s8 mode);
s8 mMsg_RequestDisappear(mMsg_Window_c* msg);
s8 mMsg_RequestAppear(mMsg_Window_c* msg, s32 message_id);
s8 mMsg_RequestCursor(mMsg_Window_c* msg);
s8 mMsg_RequestNormal(mMsg_Window_c* msg);
s8 mMsg_RequestHide(mMsg_Window_c* msg);
s8 mMsg_RequestChoice(mMsg_Window_c* msg);
s8 mMsg_RequestDisappearWait(mMsg_Window_c* msg);
s8 mMsg_RequestAppearWait(mMsg_Window_c* msg);
s32 mMsg_GetMessageBody(u32 index, u8** data, s16* size);
s16 mMsg_GetMessageLength(u8* text);
s8 mFont_CodeSize_get(u8* code);
s16 mMsg_LoadMessage(u8* text, s32 index);
void mMsg_ClearText(mMsg_Window_c* msg);
s32 mMsg_ChangeMsgData(mMsg_Window_c* msg, s32 index);
void mMsg_SetTimer(mMsg_Window_c* msg, s32 frames);
s32 mMsg_TimerDec(mMsg_Window_c* msg);
void mMsg_SetEndTimer(mMsg_Window_c* msg, s32 frames);
s32 mMsg_EndTimerDec(mMsg_Window_c* msg);
void mMsg_DestroySprites(mMsg_Window_c* msg);
s32 mMsg_CheckControlCode(u8* text, u8 type, s16 offset);
s32 mMsg_ProcessText(mMsg_Window_c* msg, u8* tile_data, s32 max_characters);
void mMsg_Init(void);
void mMsg_MainSetup_Window(mMsg_Window_c* msg);
void mMsg_InitWindow(mMsg_Window_c* msg, u8* text, u8* tile_data);
void mMsg_Main_Window(mMsg_Window_c* msg);
s32 mFont_DrawStringToTiles(u8* tile_data, u16* cursor, u16 y,
                            u16 tile_stride, u8* text, s32 length, u8 palette,
                            u8 stop_at_newline, u8 fixed_width);
void mFont_DrawCharToTiles(u8* tile_data, s32 tile_offset, s32 row,
                           s32 tile_stride, s32 character, s32 palette, s32 width);
void mFont_CopyTileBufferToVram(s8 index);
void mFont_FillTileBuffer(u8 value, s8 index);
void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c* glyph, s32 width);
void mMsg_ContinuePromptInit(m_msg_sprite_c *sprite);
void mMsg_ContinuePromptDestroy(m_msg_sprite_c* sprite);
void mMsg_ContinuePromptUpdate(m_msg_sprite_c* sprite);
void mMsg_ContinuePromptDraw(m_msg_sprite_c* sprite);
void mMsg_ChoiceCursorInit(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorIdle(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorDestroy(m_msg_sprite_c *sprite);
void mMsg_ChoiceCursorUpdate(m_msg_sprite_c* sprite);
void mMsg_ChoiceCursorDraw(m_msg_sprite_c* sprite);
void mMsg_ContinuePromptSetColor(s32 arg0);
void mMsg_ContinuePromptCycleColor(m_msg_sprite_c *sprite);
void mMsg_InitSprites(void);
void mMsg_DeactivateSprite(m_msg_sprite_c *sprite);
m_msg_sprite_c *mMsg_CreateSprite(u8 type, s32 x, s32 y, s32 param);
s32 mMsg_FindSpriteByType(u8 arg0);
s32 mMsg_IsSpriteAnimationFinished(m_msg_sprite_c *sprite, AnimFrameData *const *animations);
void mMsg_StartSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations, s16 animation);
void mMsg_UpdateSpriteAnimation(m_msg_sprite_c *sprite, AnimFrameData *const *animations);
void mMsg_CopySpriteOam(m_msg_sprite_c *sprite, OAMData *source, OAMData *dest);
void mMsg_UpdateAndDrawSprites(void);
void sub_0201C5F8(m_msg_sprite_c *sprite);

// m_msg_util.c
void mMsg_ReplaceChar(u8 *data, u8 from, u8 to, s32 length);
s32 mMsg_TrimTrailingSpaces(u8 *data, s32 length);
s32 mMsg_StringsDiffer(u8 *lhs, u8 *rhs, s32 length);
void mMsg_Copy(u8 *src, u8 *dest, s32 length);
void mMsg_Fill(u8 value, u8 *dest, s32 length);

typedef struct {
    void *tiles[2];
} mMsg_TwoChoiceHighlights;

typedef struct {
    void *tiles[3];
} mMsg_ThreeChoiceHighlights;

extern u8 sMsgGlyphWidths[256];
extern u8 sFontCodeWidths[256];
extern u8 sMsgFontGlyphs[16][2][16][8];
extern u8 sMsgSpaceGlyph[2][8];

extern int sCachedMessageIds[9];
extern mMsg_Window_c gMsgWindowNotice; // @0x03002980
extern mMsg_Window_c sMsgWindows[9]; // @0x03002A20
extern mMsg_Window_c gMsgWindowMain; // @0x03002FC0
extern mMsg_Window_c gMsgWindowPrompt; // @0x03003060

/* Original address: 0x02000400 */
extern u8 gMsgCodeBuffers[9][0x220];
/* Original address: 0x02001D80 */
extern u8 gMsgTileBuffers[9][0x1200];
/* Original address: 0x02001720 */
extern u8 gMsgMainText[0x220];
/* Original address: 0x02001940 */
extern u8 gMsgPromptText[0x220];
/* Original address: 0x02001B60 */
extern u8 gMsgNoticeText[0x220];
/* Original address: 0x0200BF80 */
extern u8 gMsgMainTiles[0x1200];
/* Original address: 0x0200D180 */
extern u8 gMsgPromptTiles[0x1200];
/* Original address: 0x0200E380 */
extern u8 gMsgNoticeTiles[0x1200];
/* Original address: 0x0200F580 */
extern u8 gMsgWindowTileData[2][0x480];
/* Original address: 0x020147E0 */
extern u8 gMsgThreeChoiceTileData[3][0xD80];
#define gMsgVram ((u8 *)(BG_VRAM + TILE_OFFSET_4BPP(0x100)))

// @0x0202AADC
extern mMsg_SETUP_PROC gMsgModeSetupCallbacks[];

// @0x0202AB24
extern int gMsgWindowScrollOffsets[12];

// @0x02034EE4
extern u16 time_of_day_palettes[24 * 4];

// @0x02034FA4 - CHAR_* plus control codes
extern u8 gMsgTextData[2002];

/* Original address: 0x02035778; big-endian message end offsets. */
extern u32 sMsgOffsets[31];

extern mMsg_SpriteProfile mMsg_null_sprite_profile;
extern mMsg_SpriteProfile mMsg_continue_prompt_sprite_profile;
extern mMsg_SpriteProfile mMsg_choice_cursor_sprite_profile;

#ifdef __cplusplus
}
#endif

#endif // M_MSG_H