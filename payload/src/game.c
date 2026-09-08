#include "game.h"
#include "m_msg.h"
#include "island_program.h"
#include "audio.h"
#include "joyboot.h"
#include "lib.h"
#include "global.h"

/* Original address: 0x02029698 */
extern const u32 sInitialIntrTable[14];

/* Original address: 0x02019E88 */
void InitializeHardware(void) {
    RegisterRamReset(RESET_SOUND_REGS | RESET_REGS);
    DmaFill32(3, 0, IWRAM_START, 0x7800);
    REG_WAITCNT = 0x4014;
    DmaCopy16(3, sInitialIntrTable, gIntrTable, sizeof(sInitialIntrTable));
    DmaCopy16(3, _intr, gGameState.interrupt_code, sizeof(gGameState.interrupt_code));
    INTR_VECTOR = gGameState.interrupt_code;
    GameAudio_Init();
}

void sub_02019F08(void) {

}

/* Original address: 0x02019F0C */
void InitializeIsland(void) {
    s32 i;

    DmaCopy16(3, sBgPalettes, gBgPaletteBuffer, BG_PLTT_SIZE);
    DmaCopy16(3, sInitialObjPalette, gObjPaletteBuffer, OBJ_PLTT_SIZE);
    DmaCopy16(3, gBgPaletteBuffer, PLTT, PLTT_SIZE);
    gIslandTransferData = &INITIAL_ISLAND;
    gIslandData = &gIsland;
    CpuCopy32(&INITIAL_ISLAND, &gIsland, sizeof(gIsland));
    for (i = 0; i < (s32)(sizeof(gIslandLandInfo) / sizeof(u32)); i++) {
        ((u32 *)&gIslandLandInfo)[i] = ((u32 *)&gIslandTransferData->landinfo)[i];
    }
    gGameState.game_time_frames = gIslandTransferData->renew_time.hour * 3600;
    gGameState.game_time_frames += gIslandTransferData->renew_time.min * 60;
    gGameState.game_time_frames = (gGameState.game_time_frames + gIslandTransferData->renew_time.sec) * 60;
    gGameState.bg0cnt = 0x1C00;
    gGameState.bg1cnt = 0xD801;
    gGameState.bg2cnt = 0xD402;
    gGameState.bg3cnt = 0xD003;
    CpuFastCopy(gIslandTransferData->earth_tex, (void *)BG_VRAM, sizeof(gIslandTransferData->earth_tex));
    CpuFastCopy(gIslandTransferData->npc_tex, (void *)OBJ_VRAM0, sizeof(gIslandTransferData->npc_tex));
    CpuFastCopy(gIslandTransferData->npc_pal, &gObjPaletteBuffer[16], sizeof(gIslandTransferData->npc_pal));
    CpuFastCopy(&gObjPaletteBuffer[16], (void *)(OBJ_PLTT + PLTT_OFFSET_4BPP(1)), PLTT_SIZE_4BPP);
    gGameState.dispcnt = 0;
    Joybus_Init();
    mMsg_InitSprites();
    mMsg_InitWindow(&gMsgWindowMain, gMsgMainText, gMsgMainTiles);
    mMsg_InitWindow(&gMsgWindowPrompt, gMsgPromptText, gMsgPromptTiles);
    mMsg_InitWindow(&gMsgWindowNotice, gMsgNoticeText, gMsgNoticeTiles);
    IslandProgram_InitWork();
}

/* Original address: 0x0201A0C8 */
void Game_Update(void) {
    IslandProgram_Update();
}

#ifdef DEBUG_TESTING
/* Original address: 0x02021A30 (island loader) */
extern const u32 sDebugObjTiles[0x2000];
/* Original address: 0x02029A30 (island loader) */
extern const u32 sDebugBgTiles[0x2000];
/* Original address: 0x0201B1E0 (island loader) */
extern const u32 sDebugBg0Tilemap[0x800];
/* Original address: 0x02031C30 (island loader) */
extern const u32 sDebugBg1Tilemap[0x800];
/* Original address: 0x0201D1E0 (island loader) */
extern const u32 sDebugBg2Tilemap[0x800];
/* Original address: 0x0201F1E0 (island loader) */
extern const u32 sDebugBg3Tilemap[0x800];

/* Reproduce the loader's base graphics uploads for standalone debug boots. */
static void DebugTesting_SetupGraphics(void) {
    DmaCopy32(3, sDebugObjTiles, (void *)OBJ_VRAM0, sizeof(sDebugObjTiles));
    DmaCopy32(3, sDebugBgTiles, (void *)BG_VRAM, sizeof(sDebugBgTiles));
    DmaCopy32(3, sDebugBg0Tilemap, BG_SCREEN_ADDR(28), sizeof(sDebugBg0Tilemap));
    DmaCopy32(3, sDebugBg1Tilemap, BG_SCREEN_ADDR(24), sizeof(sDebugBg1Tilemap));
    DmaCopy32(3, sDebugBg2Tilemap, BG_SCREEN_ADDR(20), sizeof(sDebugBg2Tilemap));
    DmaCopy32(3, sDebugBg3Tilemap, BG_SCREEN_ADDR(16), sizeof(sDebugBg3Tilemap));
}
#endif

/* Original address: 0x0201A0D4 */
void Game_Main(void) {
    CpuFastCopy(mFont_BlitGlyphToTiles, gFontGlyphBlitterCode, sizeof(gFontGlyphBlitterCode));
    mMsg_Init();
    EnableVBlankInterrupt();
    gGameState.frame_committed = 1;
    gGameState.current_music_id = 0xFFFF;
    sub_02019F08();
#ifdef DEBUG_TESTING
    DebugTesting_SetupGraphics();
#endif
    InitializeIsland();
    for (;;) {
        GameState_ReadKeys();
        if (gGameState.sleep_mode_active == 1 && gGameState.sleep_ready == 1) {
            vu16 saved_interrupt_enable;
            vu16 saved_display_control;

            saved_interrupt_enable = REG_IE;
            /* The original reads DISPCNT here without restoring it directly. */
            saved_display_control = REG_DISPCNT;
            REG_DISPCNT = 0x80;
            REG_KEYCNT = 0x8204;
            REG_IE = 0x1000;
            SoundBiasReset();
            asm("swi 0x3"); /* BIOS Stop */
            SoundBiasSet();
            REG_IE = saved_interrupt_enable;
            REG_KEYCNT = 0;
            gGameState.joybus_notice_requested = 0;
            gGameState.joybus_notice_active = 0;
            gGameState.sleep_ready = 0;
            gGameState.sleep_mode_active = 0;
            Joybus_Reset();
        }
        ClearOamBuffer();
        if ((gTransWork.command >= 0xFFFE0101 && gTransWork.command <= 0xFFFE0102) ||
            gTransWork.command == 0xFFFE0202) {
            gGameState.joybus_notice_requested = 1;
        }
        Game_Update();
        gGameState.game_time_frames++;
        if (gGameState.game_time_frames >= 24 * 60 * 60 * 60) {
            gGameState.game_time_frames -= 24 * 60 * 60 * 60;
        }
        GameAudio_Update();
        gGameState.frame_committed = 0;
        WaitForVBlank();
    }
}
