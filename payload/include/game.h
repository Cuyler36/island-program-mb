#ifndef GAME_H
#define GAME_H

#include "gba/types.h"
#include "global.h"
#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GameState {
    /* 0x000 */ u32 reserved_000;
    /* 0x004 */ s32 reserved_004;
    /* 0x008 */ s32 sleep_timer;
    /* 0x00C */ u32 rng_state;
    /* 0x010 */ u32 game_time_frames;
    /* 0x014 */ u32 interrupt_code[0x200];
    /* 0x814 */ vu16 vblank_flags;
    /* 0x816 */ u16 current_music_id;
    /* 0x818 */
    union {
        struct {
            u16 held;
            u16 pressed;
        } buttons;
        /* 0x818: held and newly pressed keys, accessed together. */
        u32 combined;
    } keys;
    /* 0x81C */ u16 bldalpha;
    /* 0x81E */ u16 bldy;
    /* 0x820 */ u16 bldcnt;
    /* 0x822 */ u16 bg0cnt;
    /* 0x824 */ u16 bg1cnt;
    /* 0x826 */ u16 bg2cnt;
    /* 0x828 */ u16 bg3cnt;
    /* 0x82A */ u16 dispcnt;
    /* 0x82C */ u8 reserved_82C[0x10];
    /* 0x83C */ u16 bg0_hofs;
    /* 0x83E */ u16 bg0_vofs;
    /* 0x840 */ u16 bg1_hofs;
    /* 0x842 */ u16 bg1_vofs;
    /* 0x844 */ u16 bg2_hofs;
    /* 0x846 */ u16 bg2_vofs;
    /* 0x848 */ u16 bg3_hofs;
    /* 0x84A */ u16 bg3_vofs;
    /* 0x84C */ u8 transfer_requested;
    /* 0x84D */ u8 transfer_dialog_active;
    /* 0x84E */ u8 sleep_requested;
    /* 0x84F */ u8 sleep_dialog_active;
    /* 0x850 */ u8 sleep_mode_active;
    /* 0x851 */ u8 sleep_ready;
    /* 0x852 */ u8 palette_dirty;
    /* 0x853 */ u8 reserved_853[3];
    /* 0x856 */ u8 joybus_notice_requested;
    /* 0x857 */ u8 joybus_notice_active;
    /* 0x858 */ u8 reserved_858;
    /* 0x859 */ u8 vblank_latch; /* cleared after a committed frame; producer unknown */
    /* 0x85A */ u8 pcm_disable_pending;
    /* 0x85B */ u8 vblank_counter;
    /* 0x85C */ u8 reserved_85C[3];
    /* 0x85F */ u8 frame_committed;
    /* 0x860 */ u8 oam_count;
    /* 0x861 */ u8 _861[0x870-0x861];
} GameState;

void InitializeHardware(void);
void sub_02019F08(void);
void InitializeIsland(void);
void Game_Update(void);
void Game_Main(void);

/* Original address: 0x020359F4 */
extern const u16 sInitialObjPalette[256];
/* Original address: 0x0203B000 */
extern Island_agb_c gInitialIsland;
#ifdef DEBUG_TEST
/* Original address: 0x0203B000 */
extern Island_agb_c gDebugTestIsland;
#define INITIAL_ISLAND gDebugTestIsland
#else
#define INITIAL_ISLAND gInitialIsland
#endif
/* Original address: 0x020102A0 */
extern Island_agb_c gIsland;
/* Original address: 0x03002810 */
extern u32 gFontGlyphBlitterCode[0x58];

/* Original address: 0x03001B50 */
extern GameState gGameState;

extern INTERRUPT_HANDLER_PROC gIntrTable[];

/* Original address: 0x03002400 */
extern mISL_landinfo_agb_c gIslandLandInfo;

#ifdef __cplusplus
}
#endif

#endif // GAME_H