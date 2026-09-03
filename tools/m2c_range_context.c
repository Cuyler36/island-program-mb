/*
 * Additional context for tools/generate_m2c.py.
 *
 * m2c parses this after payload/build/payload/src/all.i, so the project types
 * used below are already available.  These declarations add types for the
 * absolute-address symbols inserted into the assembly used by m2c.
 */

extern mFont_GlyphDraw_c gMsgGlyph;

typedef struct m2c_dma_s {
    volatile u32 src;
    volatile u32 dest;
    volatile u32 control;
} m2c_dma_c;

typedef struct m2c_irq_s {
    volatile u16 enable;
    volatile u16 request;
} m2c_irq_c;

extern volatile m2c_dma_c REG_DMA3;
extern volatile u16 REG_KEYINPUT;
extern volatile m2c_irq_c REG_IRQ;
extern volatile u16 REG_WAITCNT;
extern volatile u16 REG_IME;
extern u32 gIntrTable[0x1C];
extern const u32 gIntrTableTemplate[0x1C];
extern void (*gIntrMain)(void);
extern u8 gMsgVram[];
extern u8 gMsgCodeBuffers[0x1320];
extern u8 gMsgTileBuffers[0xA200];
extern u8 gMsgWindowTileData[0x900];
extern u16 gObjPaletteBuffer[0x100];

extern const void* gMsgTwoChoiceHighlightTiles[2];
extern const void* gMsgThreeChoiceHighlightTiles[3];
extern const s32 gMsgWindowScrollOffsets[];
extern const u8 gMsgChoiceTemplateParams[4];
extern mMsg_Callback gMsgModeSetupCallbacks[];
extern mMsg_Callback gMsgModeCallbacks[];
extern const void* gUnk_0202AD1C[3];
extern const u32 gUnk_0202AD28[3];
extern const u32 gUnk_0202AFB4[2];
extern u8 gMsgTextData[];
extern const u32 sMsgOffsetsBase;

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
s8 mMsg_GetMessageBody(u32 index, u8** data, u16* size);
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
s32 mFont_DrawStringToTiles(u8* tile_data, u16* cursor,
                            u32 packed_position, u16 glyph_height, u8* text,
                            s32 length, u8 palette, u8 stop_at_newline,
                            u8 fixed_width);
void mFont_DrawCharToTiles(u8* tile_data, u16 tile_offset, u16 row,
                           u16 tile_stride, u8 character, u8 palette,
                           s32 width);
void sub_020198B8(s8 index);
void sub_02019910(u8 value, s8 index);
void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c* glyph, s32 width);
s16 sub_02019ABC(s16 lhs, s16 rhs);
s16 sub_02019AD8(s16 numerator, s16 denominator);
u16 sub_02019AF0(GameState* state);
void sub_02019B18(GameState* state, u32 seed);
void sub_02019B1C(GameState* state, u16 target, u16 blend_control,
                  u16 intensity);
u16 sub_02019B58(GameState* state, u8 direction, u8 amount);
void sub_02019BA8(u16* palette, u8 x, u8 y, u8* red, u8* green,
                  u8* blue);
void sub_02019BD8(u8 palette, u8 x, u8 y, u8 red, u8 green, u8 blue);
void sub_02019C3C(void);
void sub_02019C88(void);
void sub_02019CC0(void);
void sub_02019CFC(void);
void sub_02019D28(void);
void sub_02019D34(void);
void sub_02019D40(void);
void sub_02019D4C(void);
void sub_02019D58(u16 value);
void sub_02019D68(u16 value);
void sub_02019D78(u16 value);
void sub_02019D88(u16 value);
void sub_02019D98(u16 value);
void mMsg_ReplaceChar(u8* data, u8 from, u8 to, s32 length);
s32 mMsg_TrimTrailingSpaces(u8* data, s32 length);
s32 mMsg_StringsDiffer(u8* lhs, u8* rhs, s32 length);
void mMsg_Copy(u8* src, u8* dest, s32 length);
void mMsg_Fill(u8 value, u8* dest, s32 length);
void sub_02019E88(void);

void CpuFastSet(const void* src, void* dest, u32 control);
void RegisterRamReset(u32 flags);
void _call_via_r0();
void _call_via_r1();
void _call_via_r2();
void _call_via_r3();
void _call_via_r4();
void _call_via_r5();
void _call_via_r6();
void _call_via_r7();
void _call_via_r8();
void _call_via_r9();
void _call_via_sl();
void _call_via_fp();
void _call_via_ip();
void _call_via_sp();
void _call_via_lr();
s32 __divsi3(s32 numerator, s32 denominator);
void __div0(void);
s32 __modsi3(s32 numerator, s32 denominator);
u32 __udivsi3(u32 numerator, u32 denominator);
u32 __umodsi3(u32 numerator, u32 denominator);
void* memcpy(void* dest, const void* src, u32 size);
void* memset(void* dest, s32 value, u32 size);
m_msg_sprite_c* sub_0201C310(u8 type, s32 x, s32 y, s32 param);
void sub_0201C300(m_msg_sprite_c* sprite);
void sub_020269C8(void);
void sub_020269E0(void);
void sub_02026A38(u16 value);
void sub_02026B48(u16 value);
void sub_02026BC8(u16 value);
void sub_02026C10(u16 value);
void sub_02026C68(u16 value);
void sub_02026F0C(void);
void sub_02026F18(void);
void _intr(void);
