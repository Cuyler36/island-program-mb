#include "interrupt.h"
#include "gba/types.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "sound.h"
#include "audio.h"
#include "game.h"

/* Original address: 0x02018228 */
void UnusedInterruptHandler(void) {
    // nothing
}

/* Original address: 0x0201822C */
void VBlankInterruptHandler(void) {
    u8 temp_r5;
    u16 temp;

    GameAudio_VBlank();
    if (gGameState.pcm_disable_pending == 1) {
        gGameState.pcm_disable_pending = 0;
        SoundDriver_DisablePcm();
    }
    temp_r5 = gGameState.frame_committed;
    if (temp_r5 == 0) {
        CpuFastCopy(gUnk3002410, (void*)OAM, sizeof(gUnk3002410));
        REG_DISPCNT = gGameState.dispcnt;
        REG_BG0HOFS = gGameState.bg0_hofs;
        REG_BG0VOFS = gGameState.bg0_vofs;
        REG_BG1HOFS = gGameState.bg1_hofs;
        REG_BG1VOFS = gGameState.bg1_vofs;
        REG_BG2HOFS = gGameState.bg2_hofs;
        REG_BG2VOFS = gGameState.bg2_vofs;
        REG_BG3HOFS = gGameState.bg3_hofs;
        REG_BG3VOFS = gGameState.bg3_vofs;
        REG_BLDALPHA = gGameState.bldalpha;
        REG_BLDY = gGameState.bldy;
        REG_BLDCNT = gGameState.bldcnt;
        REG_BG0CNT = gGameState.bg0cnt;
        REG_BG1CNT = gGameState.bg1cnt;
        REG_BG2CNT = gGameState.bg2cnt;
        REG_BG3CNT = gGameState.bg3cnt;

        if (gGameState.vblank_latch == 1) {
            gGameState.vblank_latch = temp_r5;
        }

        gGameState.vblank_counter++;
        gGameState.frame_committed = 1;
    }

    REG_IF = gGameState.vblank_flags = 1;
    REG_DISPSTAT = 8;
    GameAudio_UpdateDriver();
}

/* Original address: 0x02018364 */
void HBlankInterruptHandler(void) {
    // nothing
}

/* Original address: 0x02018368 */
void VCountInterruptHandler(void) {
    // nothing
}
