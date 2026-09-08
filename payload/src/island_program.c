#include "island_program.h"
#include "game.h"
#include "lib.h"
#include "multisio.h"
#include "joyboot.h"
#include "sound.h"
#include "audio.h"
#include "island_field.h"
#include "global.h"

/* Original address: 0x0203E9A0 */
extern u16 gIslandDataReceived;

/* Original address: 0x0202B014 */
extern const u16 sTimeOfDayPalette2Table[24][8];
/* Original address: 0x0202B194 */
extern const u16 sTimeOfDayPalette3Table[24][5];

/* Interworking trampoline used to enter the ARM startup code. */
/* Original address: 0x02029308 */
void _call_via_r0(void (*entry)(void));

/* Original address: 0x0201A6C8 */
void IslandProgram_Restart(void) {
    void (*entry)(void) = _start;

    gIslandDataReceived = 0;
    REG_IME = 0;
    REG_DISPSTAT = 0;
    REG_IE = 0;
    REG_IF = 0xFFFF;
    REG_DISPCNT = 0x80;
    _call_via_r0(entry);
}

/* Original address: 0x0201A714 */
s32 IslandProgram_PrepareDialogTransition(IslandProgramWork *work, s8 arg1) {
    s32 var_r7_4955;

    var_r7_4955 = 0;
    if (work->window_ready[arg1] == TRUE) {
        if ((!work->current_window->draw_enabled) && (mMsg_RequestAppearWait(work->current_window) == 1)) {
            mMsg_MainSetup_Window(work->current_window);
            var_r7_4955 = 1;
        }
    } else if ((work->current_window == NULL) || (work->current_window->current_mode == mMsg_MODE_HIDE)) {
        var_r7_4955 = 1;
    } else if (mMsg_RequestDisappearWait(work->current_window) == 1) {
        mMsg_MainSetup_Window(work->current_window);
        work->window_ready[arg1] = TRUE;
    }

    return var_r7_4955;
}

/* Original address: 0x0201A780 */
s32 IslandProgram_CheckWindowResumed(IslandProgramWork *work, s8 arg1) {
    s32 var_r5_5036 = 0;

    if (work->current_window == NULL) {
        return 1;
    }

    if (work->current_window->draw_enabled == TRUE) {
        work->window_ready[arg1] = 0;
        if (arg1 == 1) {
            work->transfer_succeeded = 0;
        }
    }

    var_r5_5036 = 0;
    if (work->window_ready[arg1] == 0) {
        var_r5_5036 = 1;
    }
    return var_r5_5036;
}

/* Original address: 0x0201A7C8 */
u8 IslandProgram_CheckSleepRequest(IslandProgramWork* work) {
    u8 var_r4_5054 = 0;

    if (gGameState.sleep_requested == 1) {
        var_r4_5054 = 1;
    } else if (gGameState.keys.buttons.pressed & SELECT_BUTTON) {
        var_r4_5054 = 1;
    } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 18000) == 1) {
        var_r4_5054 = 1;
    }
    return var_r4_5054;
}

/* Original address: 0x0201A810 */
s32 IslandProgram_UpdateInputTimeout(s16 *arg0, s32 arg1) {
    s32 var_r3_5091;

    var_r3_5091 = 0;
    if (arg1 <= *arg0) {
        var_r3_5091 = 1;
    } else if (KEYS_MASK & gGameState.keys.buttons.held) {
        *arg0 = 0;
    } else {
        *arg0 = (u16) *arg0 + 1;
    }
    return var_r3_5091;
}

/* Original address: 0x0201A854 */
void IslandProgram_SetDialogPalette(IslandProgramWork *work, s8 arg1) {
    u8 r;
    u8 g;
    u8 b;
    s32 i;

    switch (arg1) {
        case 4:
            SetPaletteColor(0, 7, 1, 0x10, 0x17, 0x11);
            SetPaletteColor(0, 7, 2, 0x15, 0x1B, 0x13);
            SetPaletteColor(0, 7, 3, 0x1A, 0x1F, 0x1A);
            SetPaletteColor(0, 7, 4, 0x17, 0x1E, 0x14);
            SetPaletteColor(0, 7, 5, 0x16, 0x1D, 0x16);
            break;
        case 3:
            SetPaletteColor(0, 7, 1, 0x17, 0x17, 0x11);
            SetPaletteColor(0, 7, 2, 0x1B, 0x1B, 0x13);
            SetPaletteColor(0, 7, 3, 0x1F, 0x1F, 0x1A);
            SetPaletteColor(0, 7, 4, 0x1D, 0x1D, 0x15);
            SetPaletteColor(0, 7, 5, 0x1E, 0x1F, 9);
            SetPaletteColor(0, 7, 6, 0xA, 0xB, 8);
            break;
        case 1:
            if (work->use_warm_dialog_palette == 1) {
                SetPaletteColor(0, 7, 1, 0x16, 0xA, 4);
                SetPaletteColor(0, 7, 2, 0x1A, 0xE, 6);
                SetPaletteColor(0, 7, 3, 0x1E, 0xD, 3);
                SetPaletteColor(0, 7, 4, 0x1D, 0x15, 0xC);
                SetPaletteColor(0, 7, 5, 0x1F, 0x1F, 0x15);
                break;
            } else if (work->use_cool_dialog_palette == 1) {
                SetPaletteColor(0, 7, 1, 8, 0x10, 0x14);
                SetPaletteColor(0, 7, 2, 0xA, 0x14, 0x1B);
                SetPaletteColor(0, 7, 3, 0x15, 0x19, 0x1F);
                SetPaletteColor(0, 7, 4, 0x10, 0x17, 0x1D);
                SetPaletteColor(0, 7, 5, 7, 0xF, 0x1F);
                SetPaletteColor(0, 7, 6, 0x1F, 0x1F, 0x1F);
                break;
            }
        // fallthrough 1 -> 2/default
        case 2:
        default:
            for (i = 1; i <= 6; i++) {
                GetPaletteColor(sBgPalettes[0], 7, i, &r, &g, &b);
                SetPaletteColor(0, 7, i, r, g, b);
            }
            break;
    }
    CpuFastSet(&gFieldPaletteBuffer[7 * 16], (void *)(BG_PLTT + PLTT_OFFSET_4BPP(7)), 8U);
}

/* Original address: 0x0201AA98 */
void IslandProgram_SetupDialogDisplay(IslandProgramWork *work, u8 arg1) {
    if (work->dialog_display_owner == 0 && arg1 != 1) {
        work->saved_bg3cnt = gGameState.bg3cnt;
        work->saved_dispcnt = gGameState.dispcnt;
        work->saved_bldy = gGameState.bldy;
        work->saved_bg3_vofs = gGameState.bg3_vofs;
        work->saved_bg3_hofs = gGameState.bg3_hofs;
        work->dialog_display_owner = arg1;
    }
    gGameState.bg3cnt &= 0xFFFC;
    gGameState.dispcnt |= 0x1800;
    gGameState.bldy = 0;
    gGameState.bg3_vofs = 0;
    gGameState.bg3_hofs = 0;
}

/* Original address: 0x0201AB3C */
void IslandProgram_RestoreDialogDisplay(IslandProgramWork *work, s8 arg1) {
    u16 temp_r1_5496;

    if (arg1 == work->dialog_display_owner) {
        gGameState.bg3cnt = work->saved_bg3cnt;
        gGameState.dispcnt = work->saved_dispcnt;
        if (gIslandDataReceived == 1) {
            gGameState.dispcnt &= 0xFDFF;
        }
        gGameState.bldy = work->saved_bldy;
        gGameState.bg3_vofs = work->saved_bg3_vofs;
        gGameState.bg3_hofs = work->saved_bg3_hofs;
        work->dialog_display_owner = 0;
    }
}

/* Original address: 0x0201ABBC */
void IslandProgram_UpdateMessages(IslandProgramWork *work) {
    mMsg_Window_c *temp_r1_5544;

    temp_r1_5544 = work->current_window;
    if ((temp_r1_5544 != NULL) && (gGameState.sleep_mode_active == 0)) {
        mMsg_Main_Window(temp_r1_5544);
    }
    mMsg_UpdateAndDrawSprites();
}

/* Original address: 0x0201ABE4 */
s32 IslandProgram_TryOpenTransferDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5569;

    var_r1_5569 = 0;
    if ((gGameState.sleep_mode_active == 0) && (work->pending_transfer_state != 0)) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->transfer_return_window_id = arg1;
            work->transfer_saved_window = work->current_window;
            IslandProgram_ApplyPendingTransferState(work);
        }
        var_r1_5569 = 1;
    }
    return var_r1_5569;
}

/* Original address: 0x0201AC38 */
s32 IslandProgram_TryOpenNoticeDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5613;

    var_r1_5613 = 0;
    if ((gGameState.sleep_mode_active == 0) && (work->pending_notice_state != 0)) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->notice_return_window_id = arg1;
            work->notice_saved_window = work->current_window;
            IslandProgram_ApplyPendingNoticeState(work);
        }
        var_r1_5613 = 1;
    }
    return var_r1_5613;
}

/* Original address: 0x0201AC8C */
s32 IslandProgram_TryOpenSleepDialog(IslandProgramWork *work, u8 arg1) {
    s32 var_r1_5657;

    var_r1_5657 = 0;
    if (work->pending_sleep_state != 0) {
        if (IslandProgram_PrepareDialogTransition(work, arg1) == 1) {
            work->sleep_return_window_id = arg1;
            work->sleep_saved_window = work->current_window;
            IslandProgram_ApplyPendingSleepState(work);
        }
        var_r1_5657 = 1;
    }
    return var_r1_5657;
}

/* Original address: 0x0201ACCC */
void IslandProgram_BeginJoybusReceive(IslandProgramWork *work) {
    Island_agb_c* island = gIslandTransferData;
    s32 transfer_size = sizeof(*island);

    gTransWork.transfer_size = transfer_size;
    gTransWork.buffer = (u32*)island;
    gTransWork.enabled = TRUE;
    work->joybus_transfer_mode = 2;
    work->joybus_sending = 0;
}

/* Original address: 0x0201ACF8 */
s8 IslandProgram_PollJoybusReceive(IslandProgramWork *work) {
    s32 var_r1_5714;

    var_r1_5714 = 0;
    if (gTransWork.result != 0) {
        var_r1_5714 = gTransWork.result;
    } else if (!gTransWork.connected) {
        var_r1_5714 = 2;
    }

    if (var_r1_5714 == 1) {
        work->transfer_succeeded = var_r1_5714;
    }

    return var_r1_5714;
}

/* Original address: 0x0201AD34 */
void IslandProgram_BeginJoybusSend(IslandProgramWork *work) {
    Island_agb_c* island = gIslandData;
    s32 transfer_size = sizeof(*island);

    gTransWork.transfer_size = transfer_size;
    gTransWork.buffer = (u32*)island;
    gTransWork.enabled = TRUE;
    
    if (gTransWork.command == 0xFFFE0101) {
        work->notice_send_active = 1;
    } else {
        work->notice_send_active = 0;
    }

    work->joybus_transfer_mode = 1;
    work->joybus_sending = 1;
}

/* Original address: 0x0201AD84 */
s16 IslandProgram_PollJoybusSend(IslandProgramWork *work) {
    s32 var_r3_5792;

    var_r3_5792 = 0;
    if (gTransWork.result != 0) {
        var_r3_5792 = gTransWork.result;
    } else if (gTransWork.connected == 0) {
        var_r3_5792 = 2;
    }

    if (work->notice_send_active == 0 && work->joybus_sending == 1 && (var_r3_5792 == 1)) {
        gIslandDataReceived = (u16) var_r3_5792;
        gIslandData->in_use = TRUE;
    }
    return var_r3_5792;
}

void sub_0201ADDC(void) {

}

/* Original address: 0x0201ADE0 */
s32 IslandProgram_RequestNoticeState(IslandProgramWork *work, s8 arg1) {
    work->pending_notice_state = arg1;
    return 1;
}

/* Original address: 0x0201ADE8 */
s32 IslandProgram_RequestNoticeTransfer(IslandProgramWork *work) {
    work->pending_notice_state = 1;
    return 1;
}

/* Original address: 0x0201ADF4 */
s32 IslandProgram_RequestNoticeResult(IslandProgramWork *work) {
    work->pending_notice_state = 2;
    return 1;
}

/* Original address: 0x0201AE00 */
s32 IslandProgram_RequestNoticeRestart(IslandProgramWork *work) {
    work->pending_notice_state = 3;
    return 1;
}

/* Original address: 0x0201AE0C */
void IslandProgram_ApplyPendingNoticeState(IslandProgramWork *work) {
    extern const IslandProgramModeProc sIslandProgramNoticeEnterProcs[];

    IslandProgramModeProc proc;

    if ((u8)work->pending_notice_state <= 3) {
        proc = sIslandProgramNoticeEnterProcs[work->pending_notice_state];
        if (proc != NULL) {
            proc(work);
            work->input_idle_timer = 0;
        }
    }
}

/* Original address: 0x0201AE40 */
void IslandProgram_EnterNoticeTransfer(IslandProgramWork *work) {
    int msg_id = gTransWork.command == 0xFFFE0101 ? 30 : 11;

    if (mMsg_RequestAppear(&gMsgWindowNotice, msg_id) == 1) {
        if (gTransWork.command == 0xFFFE0202) {
            IslandProgram_BeginJoybusReceive(work);
        } else {
            IslandProgram_BeginJoybusSend(work);
        }
        IslandProgram_SetDialogPalette(work, 2);
        IslandProgram_SetupDialogDisplay(work, 2);

        work->notice_state = work->pending_notice_state;
        work->current_window = &gMsgWindowNotice;
    }

    work->pending_notice_state = 0;
}

/* Original address: 0x0201AEBC */
void IslandProgram_UpdateNoticeTransfer(IslandProgramWork *work) {
    if (work->joybus_sending == 0) {
        work->joybus_result = IslandProgram_PollJoybusReceive(work);
    } else {
        if (work->retry_timer == 0) {
            work->retry_result = IslandProgram_PollJoybusSend(work);
            if (work->retry_result != 0) {
                work->retry_timer = 60;
            } else {
                work->joybus_result = 0;
            }
        } else {
            work->retry_timer--;
            if (work->retry_timer == 0) {
                work->joybus_result = work->retry_result;
            }
        }
    }
    if ((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE) && (work->joybus_result != 0) && (IslandProgram_RequestNoticeResult(work) != 0)) {
        IslandProgram_ApplyPendingNoticeState(work);
    }
}

/* Original address: 0x0201AF48 */
void IslandProgram_EnterNoticeResult(IslandProgramWork *work) {
    IslandProgramNoticeResultMessages result_messages = sNoticeResultMessages;

    if (work->notice_send_active == 1) {
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.sleep_requested = 0;
        gGameState.sleep_dialog_active = 0;
        if (work->joybus_result != 2) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
            work->notice_result_wait_timer = 0;
        } else {
            work->notice_result_wait_timer = 60;
            GameAudio_PlayEffect0(0x28U);
        }
        work->notice_state = work->pending_notice_state;
        work->notice_result_state = 0;
    } else {
        if ((mMsg_ChangeMsgData(work->current_window, result_messages.message_ids[work->joybus_result - 1]) == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
            GameAudio_PlayEffect0(work->joybus_result == 1 ? 0x27 : 0x28);
            gGameState.joybus_notice_requested = 0;
            gGameState.joybus_notice_active = 0;
            mMsg_MainSetup_Window(work->current_window);
            work->notice_state = work->pending_notice_state;
            work->notice_result_state = 0;
        }
    }
    work->pending_notice_state = 0;
}

/* Original address: 0x0201B04C */
void IslandProgram_UpdateNoticeResult(IslandProgramWork *work) {
    s32 temp_r0_6172;
    s32 temp_r0_6175;
    s8 temp_r0_6232;
    u8 temp_r1_6169;
    u8 temp_r2_6190;
    void *temp_r0_6223;
    void *temp_r1_6187;

    if ((work->notice_send_active == 1) && work->notice_result_wait_timer != 0) {
        work->notice_result_wait_timer--;
        if (work->notice_result_wait_timer == 0) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
        }
    } else {
        if (!work->current_window->draw_enabled) {
            if (work->transfer_succeeded == 1) {
                work->notice_state = 3;
                GameState_SetBrightnessFade(&gGameState, 0x80U, 0x3FU, 0U);
                gGameState.dispcnt &= 0xFEFF;
                work->transfer_succeeded = 0;
                return;
            }
            work->notice_state = 0;
            work->input_idle_timer = 0;
            work->notice_send_active = 0;
            switch (work->notice_return_window_id) {
                case 1:
                    IslandProgram_SetDialogPalette(work, 1);
                    break;
                case 3:
                    IslandProgram_SetDialogPalette(work, 3);
                    break;
            }
            work->current_window = work->notice_saved_window;
            IslandProgram_RestoreDialogDisplay(work, 2);
            mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
            if (gGameState.joybus_notice_requested == 1) {
                work->transition_requested = 1;
            }
        } else if (((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE)) && (work->notice_send_active == 0) && (gGameState.joybus_notice_requested == 1)) {
            work->current_window->cancel_continue = TRUE;
            work->current_window->force_next = TRUE;
        }
    }
}

/* Original address: 0x0201B168 */
void IslandProgram_EnterNoticeRestart(IslandProgramWork *work) {

}

/* Original address: 0x0201B16C */
void IslandProgram_UpdateNoticeRestart(IslandProgramWork *work) {
    if (GameState_StepBrightnessFade(&gGameState, 1, 1) == 0x10) {
        IslandProgram_Restart();
    }
}

/* Original address: 0x0201B18C */
s32 IslandProgram_RequestSleepState(IslandProgramWork *work, s8 arg1) {
    work->pending_sleep_state = arg1;
    return 1;
}

/* Original address: 0x0201B194 */
s32 IslandProgram_RequestSleepPrompt(IslandProgramWork *work) {
    work->pending_sleep_state = 1;
    return 1;
}

/* Original address: 0x0201B1A0 */
s32 IslandProgram_RequestSleepMode(IslandProgramWork *work) {
    work->pending_sleep_state = 2;
    return 1;
}

/* Original address: 0x0201B1AC */
s32 IslandProgram_RequestSleepCleanup(IslandProgramWork *work) {
    work->pending_sleep_state = 3;
    return 1;
}

/* Original address: 0x0201B1B8 */
void IslandProgram_ApplyPendingSleepState(IslandProgramWork *work) {
    extern const IslandProgramModeProc sIslandProgramSleepEnterProcs[];
    IslandProgramModeProc proc;

    if ((u8)work->pending_sleep_state <= 3) {
        proc = sIslandProgramSleepEnterProcs[work->pending_sleep_state];
        if (proc != NULL) {
            proc(work);
            work->input_idle_timer = 0;
        }
    }
}

/* Original address: 0x0201B1EC */
void IslandProgram_EnterSleepPrompt(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&gMsgWindowPrompt, 21) == 1) {
        IslandProgram_SetDialogPalette(work, 3);
        IslandProgram_SetupDialogDisplay(work, 3);
        work->sleep_state = work->pending_sleep_state;
        work->input_idle_timer = 0;
        work->current_window = &gMsgWindowPrompt;
    }
    work->pending_sleep_state = 0;
}

/* Original address: 0x0201B238 */
void IslandProgram_UpdateSleepPrompt(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestSleepCleanup(work) == 1) {
            IslandProgram_ApplyPendingSleepState(work);
        }
    } else if (work->current_window->current_mode >= mMsg_MODE_CURSOR && work->current_window->current_mode <= mMsg_MODE_CHOICE) {
        if (work->current_window->selected_choice != -1) {
            if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) == 0) || (work->current_window->message_id != 22)) {
                if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
                    if (IslandProgram_RequestSleepMode(work) != 0) {
                        IslandProgram_ApplyPendingSleepState(work);
                    }
                }
            } else {
                if (IslandProgram_RequestSleepMode(work) != 0) {
                    IslandProgram_ApplyPendingSleepState(work);
                }
            }
        } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
            if (IslandProgram_RequestSleepMode(work) != 0) {
                IslandProgram_ApplyPendingSleepState(work);
            }
        } else if (gGameState.joybus_notice_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201B2E8 */
void IslandProgram_EnterSleepMode(IslandProgramWork *work) {
    work->sleep_state = work->pending_sleep_state;
    work->pending_sleep_state = 0;
    work->input_idle_timer = 0;
    gGameState.sleep_timer = 0;
    gGameState.sleep_mode_active = 1;
    gGameState.pcm_disable_pending = 1;
    GameAudio_StopMusic(0x14U);
}

/* Original address: 0x0201B328 */
void IslandProgram_UpdateSleepMode(IslandProgramWork *work) {

    if (gGameState.sleep_mode_active == 1) {
        if (gGameState.sleep_timer > 120) {
            int result = mMsg_ChangeMsgData(work->current_window, 23);
            if ((result == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
                work->input_idle_timer = 0;
                work->current_window->text_delay_timer = 0;
                mMsg_MainSetup_Window(work->current_window);
                gGameState.sleep_ready = result;
            }
        }
        gGameState.sleep_timer++;
        return;
    }

    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestSleepCleanup(work) == 1) {
            IslandProgram_ApplyPendingSleepState(work);
        }
    } else if (work->current_window->current_mode >= mMsg_MODE_CURSOR && work->current_window->current_mode <= mMsg_MODE_CHOICE) {
        if (work->current_window->selected_choice != -1) {
            if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) && (work->current_window->message_id == 23)) {
                if (IslandProgram_RequestSleepMode(work) != 0) {
                    IslandProgram_ApplyPendingSleepState(work);
                    gGameState.sleep_timer = 120;
                }
            }
        } else if (IslandProgram_UpdateInputTimeout(&work->input_idle_timer, 600) == 1) {
            if (IslandProgram_RequestSleepMode(work) != 0) {
                IslandProgram_ApplyPendingSleepState(work);
                gGameState.sleep_timer = 120;
            }
        } else if (gGameState.joybus_notice_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201B420 */
void IslandProgram_EnterSleepCleanup(IslandProgramWork *work) {
    work->sleep_state = work->pending_sleep_state;
    work->pending_sleep_state = 0;
    if (gGameState.sleep_timer != 0) {
        if ((s16) gGameState.current_music_id != -1) {
            GameAudio_PlayMusic(gGameState.current_music_id);
        }
        SoundDriver_EnablePcm();
        gGameState.sleep_timer = 0;
    }
}

/* Original address: 0x0201B464 */
void IslandProgram_UpdateSleepCleanup(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        work->sleep_state = 0;
        if (work->sleep_return_window_id == 1) {
            IslandProgram_SetDialogPalette(work, 1);
        }
        work->sleep_return_window_id = 0;
        work->current_window = work->sleep_saved_window;
        IslandProgram_RestoreDialogDisplay(work, 3);
        mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
        work->input_idle_timer = 0;
    }
}

/* Original address: 0x0201B4B0 */
void IslandProgram_SetupOverviewDisplay(void) {
    gGameState.dispcnt = (gGameState.dispcnt & 0xE0FF) | 0x700;
    gGameState.bg3cnt &= 0xFFFC;
    gGameState.bg1cnt = (gGameState.bg1cnt & 0xFFFC) | 1;
    gGameState.bg0cnt = (gGameState.bg0cnt & 0xFFFC) | 2;
    gGameState.bg2cnt = (gGameState.bg2cnt & 0xFFFC) | 3;
    if (gIslandData->weather != mEnv_WEATHER_CLEAR) {
        gGameState.bg0cnt |= 0x100; // rain flag
    } else {
        gGameState.bg0cnt |= 0x000; // clear flag
    }
    if (gIslandDataReceived == 1) {
        gGameState.dispcnt &= 0xFDFF;
    }
    gGameState.bg1_vofs = 0x100;
    gGameState.bg1_hofs = 0x100;
    gGameState.bg2_vofs = 0x100;
    gGameState.bg2_hofs = 0;
}

/* Original address: 0x0201B594 */
void IslandProgram_UpdateTimeOfDayPalette(IslandProgramWork *work) {
    u8 time_of_day = (u8)(gGameState.game_time_frames / 216000U);

    if (time_of_day != work->time_of_day) {
        u16 *palette;

        CpuCopy16(sTimeOfDayPalette2Table[time_of_day], current_time_of_day_palette2,
                  sizeof(sTimeOfDayPalette2Table[time_of_day]));
        CpuCopy16(sTimeOfDayPalette3Table[time_of_day], current_time_of_day_palette3,
                  sizeof(sTimeOfDayPalette3Table[time_of_day]));
        CpuFastCopy(time_of_day_palette_buffer2, (void *)(BG_PLTT + 0x180), PLTT_SIZE_4BPP);
        CpuFastCopy(time_of_day_palette_buffer3, (void *)(BG_PLTT + 0x1C0), PLTT_SIZE_4BPP);

        palette = &time_of_day_palettes[time_of_day * 4];
        /* Update only lighting colors; preserve the building material colors. */
        CpuCopy16(palette, current_time_of_day_palette0, 4 * sizeof(*palette));
        CpuCopy16(palette, current_time_of_day_palette1, 4 * sizeof(*palette));
        CpuFastCopy(time_of_day_palette_buffer0, (void *)(BG_PLTT + 0x100), PLTT_SIZE_4BPP);
        CpuFastCopy(time_of_day_palette_buffer1, (void *)(BG_PLTT + 0x120), PLTT_SIZE_4BPP);
        work->time_of_day = time_of_day;
    }
    gGameState.bldcnt = 0x2441;
    gGameState.bldalpha = 0x1006;
}

/* Original address: 0x0201B680 */
s32 IslandProgram_RequestTransferState(IslandProgramWork *work, s8 arg1) {
    work->pending_transfer_state = arg1;
    return 1;
}

/* Original address: 0x0201B688 */
s32 IslandProgram_RequestTransferPrompt(IslandProgramWork *work) {
    work->pending_transfer_state = 1;
    return 1;
}

/* Original address: 0x0201B694 */
s32 IslandProgram_RequestTransferProgress(IslandProgramWork *work) {
    work->pending_transfer_state = 2;
    return 1;
}

/* Original address: 0x0201B6A0 */
s32 IslandProgram_RequestTransferRetry(IslandProgramWork *work) {
    work->pending_transfer_state = 3;
    return 1;
}

/* Original address: 0x0201B6AC */
s32 IslandProgram_RequestTransferComplete(IslandProgramWork *work) {
    work->pending_transfer_state = 4;
    return 1;
}

/* Original address: 0x0201B6B8 */
s32 IslandProgram_RequestTransferCleanup(IslandProgramWork *work) {
    work->pending_transfer_state = 5;
    return 1;
}

/* Original address: 0x0201B6C4 */
s32 IslandProgram_RequestTransferRestart(IslandProgramWork *work) {
    work->pending_transfer_state = 6;
    return 1;
}

/* Original address: 0x0201B6D0 */
void IslandProgram_ApplyPendingTransferState(IslandProgramWork *work) {
    IslandProgramModeProc proc;

    if ((u8)work->pending_transfer_state <= 6) {
        extern const IslandProgramModeProc sIslandProgramTransferEnterProcs[];

        proc = sIslandProgramTransferEnterProcs[work->pending_transfer_state];
        if (proc != NULL) {
            proc(work);
        }
    }
}

/* Original address: 0x0201B6FC */
void IslandProgram_EnterTransferPrompt(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&gMsgWindowNotice, 4) == 1) {
        IslandProgram_SetDialogPalette(work, 4);
        IslandProgram_SetupDialogDisplay(work, 4U);
        InitIslandLinkTransfer(0);
        StopIslandLinkTransfer();
        *gIntrTable = (u32) IslandLinkSerialInterrupt;
        work->transfer_state = work->pending_transfer_state;
        work->current_window = &gMsgWindowNotice;
    }
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B75C */
void IslandProgram_UpdateTransferPrompt(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        if (IslandProgram_RequestTransferCleanup(work) == 1) {
            IslandProgram_ApplyPendingTransferState(work);
        }
    } else if ((mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) && (work->current_window->message_id == 6) && (IslandProgram_RequestTransferProgress(work) == 1)) {
        IslandProgram_ApplyPendingTransferState(work);
    }
}

/* Original address: 0x0201B7B0 */
void IslandProgram_EnterTransferProgress(IslandProgramWork *work) {
    s32 var_r2_7139;
    int i;

    if ((mMsg_ChangeMsgData(work->current_window, 15) == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
        mMsg_MainSetup_Window(work->current_window);
        var_r2_7139 = 0;
        work->transfer_state = work->pending_transfer_state;
        gIslandData->checksum = 0;

        // clear the land info? I don't know why they didn't use memset here.
        for (i = 0; i < (s32)(sizeof(gIslandData->landinfo) / sizeof(s32)); i++) {
            ((s32*)&gIslandData->landinfo)[i] = 0;
        }
        work->link_transfer_started = 1;
        InitIslandLinkTransfer(0);
    }
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B824 */
void IslandProgram_UpdateTransferProgress(IslandProgramWork *work) {
    s32 temp_r0_7180;
    s32 temp_r0_7232;
    u32 temp_r0_7182;

    temp_r0_7180 = IslandProgram_UpdateLinkTransfer();
    temp_r0_7182 = temp_r0_7180 - 7;
    switch (temp_r0_7182) {
    case 1:
    case 3:
    case 9:
        if ((IslandProgram_RequestTransferRetry(work) == 1) && (mMsg_ChangeMsgData(work->current_window, temp_r0_7180) == 1) && ((mMsg_RequestCursor(work->current_window)) != 0)) {
            mMsg_MainSetup_Window(work->current_window);
            mMsg_ClearText(work->current_window);
            IslandProgram_ApplyPendingTransferState(work);
            return;
        }
    default:
        return;
    case 2:
        if (IslandProgram_RequestTransferComplete(work) == 1) {
            temp_r0_7232 = mMsg_ChangeMsgData(work->current_window, temp_r0_7180);
            if ((temp_r0_7232 == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
                mMsg_MainSetup_Window(work->current_window);
                mMsg_ClearText(work->current_window);
                IslandProgram_ApplyPendingTransferState(work);
                work->transfer_succeeded = temp_r0_7232;
                return;
            }
        }
        break;
    case 0:
        if ((mMsg_ChangeMsgData(work->current_window, temp_r0_7180) == 1) && ((mMsg_RequestCursor(work->current_window) << 0x18) != 0)) {
            mMsg_MainSetup_Window(work->current_window);
            mMsg_ClearText(work->current_window);
        }
        break;
    }
}

/* Original address: 0x0201B90C */
void IslandProgram_EnterTransferRetry(IslandProgramWork *work) {
    work->transfer_state = work->pending_transfer_state;
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B91C */
void IslandProgram_UpdateTransferRetry(IslandProgramWork *work) {
    s32 temp_r0_7298;

    if (mMsg_CheckControlCode(work->current_window->text, 1, work->current_window->text_offset) != 0) {
        temp_r0_7298 = mMsg_ChangeMsgData(work->current_window, 0x11);
        if ((temp_r0_7298 == 1) && (mMsg_RequestCursor(work->current_window) != 0)) {
            work->transfer_state = temp_r0_7298;
            mMsg_MainSetup_Window(work->current_window);
        }
    }
}

/* Original address: 0x0201B960 */
void IslandProgram_EnterTransferComplete(IslandProgramWork *work) {
    work->transfer_state = work->pending_transfer_state;
    work->pending_transfer_state = 0;
}

/* Original address: 0x0201B970 */
void IslandProgram_UpdateTransferComplete(IslandProgramWork* work) {
    if (!work->current_window->draw_enabled && IslandProgram_RequestTransferCleanup(work) == 1) {
        IslandProgram_ApplyPendingTransferState(work);
    }
}

/* Original address: 0x0201B994 */
void IslandProgram_EnterTransferCleanup(IslandProgramWork *work) {
    s32 *var_r7_7399;
    s32 temp_r0_7404;
    s32 var_r3_7393;
    s8 *var_r2_7359;
    u8 temp_r3_7355;
    int i;

    temp_r3_7355 = work->link_transfer_started;
    if (work->link_transfer_started == 0) {
        work->transfer_state = work->pending_transfer_state;
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
    } else if (mMsg_RequestAppear(&gMsgWindowNotice, 18) == 1) {
        // Again, why not use memcpy here?
        for (i = 0; i < (s32)(sizeof(gIslandTransferData->landinfo) / sizeof(s32)); i++) {
            ((s32*)&gIslandTransferData->landinfo)[i] = ((s32*)&gIslandLandInfo)[i];
        }
        work->transfer_state = work->pending_transfer_state;
        work->current_window = &gMsgWindowNotice;
        gGameState.joybus_notice_requested = 0;
        gGameState.joybus_notice_active = 0;
        gGameState.transfer_requested = 0;
        gGameState.transfer_dialog_active = 0;
    }

    work->pending_transfer_state = 0;
}

/* Original address: 0x0201BA54 */
void IslandProgram_UpdateTransferCleanup(IslandProgramWork *work) {
    s8 temp_r2_7459;
    s8 var_r1_7472;
    u8 temp_r0_7450;

    if (!work->current_window->draw_enabled) {
        work->transfer_state = 0;

        switch (work->transfer_return_window_id) {
            case 1:
                IslandProgram_SetDialogPalette(work, 1);
                break;
            case 3:
                IslandProgram_SetDialogPalette(work, 3);
                break;
            default:
                IslandProgram_RestoreDialogDisplay(work, 4);
                break;
        }

        work->transfer_return_window_id = 0;
        work->current_window = work->transfer_saved_window;
        IslandProgram_RestoreDialogDisplay(work, 4);
        mMsg_CopyTilesToVram(0, 0x90, work->current_window->tile_data);
        if (work->transfer_succeeded == 1) {
            work->transfer_state = 6;
            GameState_SetBrightnessFade(&gGameState, 0x80U, 0x3FU, 0U);
            gGameState.dispcnt &= 0xFEFF;
            GameAudio_StopMusic(0x14U);
            work->transfer_succeeded = 0;
        }
        work->link_transfer_started = 0;
        work->input_idle_timer = 0;
        *gIntrTable = (u32)JoybootHandler;
        Joybus_Init();
    }
}

/* Original address: 0x0201BB20 */
void IslandProgram_EnterTransferRestart(IslandProgramWork *work) {

}

/* Original address: 0x0201BB24 */
void IslandProgram_UpdateTransferRestart(IslandProgramWork *work) {
    if (GameState_StepBrightnessFade(&gGameState, 1U, 1U) == 0x10) {
        IslandProgram_Restart();
    }
}

/* Original address: 0x0201BB44 */
s32 IslandProgram_RequestMode(IslandProgramWork *work, s8 arg1) {
    work->pending_mode = arg1;
    return 1;
}

/* Original address: 0x0201BB4C */
s32 IslandProgram_RequestNormalMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 1);
}

/* Original address: 0x0201BB58 */
s32 IslandProgram_RequestFieldLoadMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 2);
}

/* Original address: 0x0201BB64 */
s32 IslandProgram_RequestMosaicCoverMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 4);
}

/* Original address: 0x0201BB70 */
s32 IslandProgram_RequestMosaicRevealMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 3);
}

/* Original address: 0x0201BB7C */
s32 IslandProgram_RequestMessageMode(IslandProgramWork *work) {
    return IslandProgram_RequestMode(work, 5);
}

/* Original address: 0x0201BB88 */
void IslandProgram_ApplyPendingMode(IslandProgramWork *work) {
    IslandProgramModeProc proc;

    if ((u32)work->pending_mode <= 5U) {
        proc = sIslandProgramModeEnterProcs[work->pending_mode];
        if (proc != NULL) {
            proc(work);
        }
    }
}

/* Original address: 0x0201BBB4 */
void IslandProgram_EnterNormalMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    work->current_window = NULL;
    gGameState.current_music_id = 0;
    GameAudio_PlayMusic(0);
    gGameState.pcm_disable_pending = 1;
    IslandProgram_SetupOverviewDisplay();
}

/* Original address: 0x0201BBF8 */
void IslandProgram_UpdateNormalMode(IslandProgramWork *work) {
    if (gIslandDataReceived == 0) {
        if ((gGameState.keys.buttons.pressed & 9) && IslandProgram_RequestMosaicCoverMode(work) == 1) {
            IslandProgram_ApplyPendingMode(work);
            return;
        }
        if (gGameState.joybus_notice_requested != 0 ||
            (gGameState.transfer_requested != 0 || gGameState.sleep_requested != 0)) {
            work->transition_requested = 1;
        }
    } else {
        if ((gGameState.keys.buttons.pressed & 1) && IslandProgram_RequestMessageMode(work) == 1) {
            IslandProgram_ApplyPendingMode(work);
            return;
        }
        if (gGameState.joybus_notice_requested != 0 || gGameState.sleep_requested != 0) {
            work->transition_requested = 1;
        }
    }
}

/* Original address: 0x0201BCA4 */
void IslandProgram_EnterFieldLoadMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    gGameState.current_music_id = 1;
    GameAudio_PlayMusic(gGameState.current_music_id);
    SoundDriver_EnablePcm();
    gGameState.dispcnt = (0xE0FF & gGameState.dispcnt) | 0x1F00;
    gGameState.bg0cnt &= 0xFFFC;
    gGameState.bg1cnt = (0xFFFC & gGameState.bg1cnt) | 1;
    gGameState.bg2cnt = (0xFFFC & gGameState.bg2cnt) | 2;
    gGameState.bg3cnt = (0xFFFC & gGameState.bg3cnt) | 3;
    gGameState.bg0_vofs = 0;
    gGameState.bg0_hofs = 0;
    gGameState.bg1_vofs = 0;
    gGameState.bg1_hofs = 0;
    gGameState.bg2_vofs = 0;
    gGameState.bg2_hofs = 0;
    gGameState.bg3_vofs = 0x100;
    gGameState.bg3_hofs = 0x100;
}

/* Original address: 0x0201BD7C */
void IslandProgram_UpdateFieldLoadMode(IslandProgramWork *work) {
    u8 temp_r4_7859;

    temp_r4_7859 = UpdateIslandField();
    DrawIslandField();
    if ((temp_r4_7859 == 1) && ((s32) IslandProgram_RequestMosaicRevealMode(work) == 1)) {
        IslandProgram_ApplyPendingMode(work);
    }
}

/* Original address: 0x0201BDA8 */
void IslandProgram_EnterMosaicCoverMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    GameAudio_StopMusic(0x14U);
}

/* Original address: 0x0201BDC4 */
void IslandProgram_UpdateMosaicCoverMode(IslandProgramWork *work) {
    if (UpdateIslandMosaic(1U) == 1 && IslandProgram_RequestFieldLoadMode(work) == 1) {
        IslandProgram_ApplyPendingMode(work);
    }
}

/* Original address: 0x0201BDE8 */
void IslandProgram_EnterMosaicRevealMode(IslandProgramWork *work) {
    s8 prev = work->pending_mode;

    work->mode = prev;
    work->pending_mode = 0;
    gGameState.current_music_id = 0;
    GameAudio_PlayMusic(0U);
    IslandProgram_SetupOverviewDisplay();
    gGameState.bg1_vofs = 0x100;
    gGameState.bg1_hofs = 0x100;
    gGameState.bg2_vofs = 0x100;
    gGameState.bg2_hofs = 0;
}

/* Original address: 0x0201BE3C */
void IslandProgram_UpdateMosaicRevealMode(IslandProgramWork *work) {
    s32 transition_complete;

    transition_complete = UpdateIslandMosaic(0U);
    if (transition_complete == 1) {
        work->mode = transition_complete;
        gGameState.pcm_disable_pending = transition_complete;
    }
}

/* Original address: 0x0201BE68 */
void IslandProgram_EnterMessageMode(IslandProgramWork *work) {
    if (mMsg_RequestAppear(&gMsgWindowMain, 0x1A) == 1) {
        s8 prev;

        IslandProgram_SetDialogPalette(work, 1);
        IslandProgram_SetupDialogDisplay(work, 1U);
        prev = work->pending_mode;
        work->mode = prev;
        work->current_window = &gMsgWindowMain;
    }
    work->pending_mode = 0;
}

/* Original address: 0x0201BEB0 */
void IslandProgram_UpdateMessageMode(IslandProgramWork *work) {
    if (!work->current_window->draw_enabled) {
        work->mode = 1;
    } else if ((work->current_window->current_mode >= mMsg_MODE_CURSOR) && (work->current_window->current_mode <= mMsg_MODE_CHOICE) && (work->current_window->selected_choice == -1) && ((gGameState.joybus_notice_requested != 0) || (gGameState.sleep_requested != 0))) {
        work->transition_requested = 1;
    }
}

/* Original address: 0x0201BF10 */
void IslandProgram_InitWork(void) {
    CpuFastFill(0, &gIslandProgramWork, sizeof(IslandProgramWork));
    gIslandProgramWork.time_of_day = -1;
    InitIslandField();
    if (IslandProgram_RequestNormalMode(&gIslandProgramWork) == 1) {
        IslandProgram_ApplyPendingMode(&gIslandProgramWork);
    }
    IslandProgram_UpdateTimeOfDayPalette(&gIslandProgramWork);
}

/* Original address: 0x0202AFDC */
extern IslandProgramModeProc const sIslandProgramNoticeUpdateProcs[4];

/* Original address: 0x0202AFFC */
extern IslandProgramModeProc const sIslandProgramPromptUpdateProcs[4];

/* Original address: 0x0202B2A0 */
extern IslandProgramModeProc const sIslandProgramTransferUpdateProcs[7];

/* Original address: 0x0202B2D4 */
extern IslandProgramModeProc const sIslandProgramModeUpdateProcs[6];

/* Original address: 0x0201BF58 */
void IslandProgram_Update(void) {
    u8 transition_requested;
    u8 allow_link_reset;
    IslandProgramWork *work = &gIslandProgramWork;

    allow_link_reset = 1;
    if ((work->notice_state != 3) && (work->transfer_state != 6) && (work->mode != 2)) {
        IslandProgram_UpdateTimeOfDayPalette(work);
    }
    if (gIslandData->weather != 0) {
        gGameState.bg0_hofs = work->weather_scroll + ((u16)gGameState.bg2_hofs >> 1);
        gGameState.bg0_vofs -= 4;
        work->weather_scroll += 1;
    }
    IslandProgram_UpdateMessages(work);
    if (work->notice_state != 0) {
        sIslandProgramNoticeUpdateProcs[work->notice_state](work);
        transition_requested = work->transition_requested;
        if (transition_requested == 1) {
            IslandProgram_RequestNoticeTransfer(work);
            work->transition_requested = 0;
            IslandProgram_ApplyPendingNoticeState(work);
            gGameState.joybus_notice_active = transition_requested;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        }
    } else if (work->transfer_state != 0) {
        sIslandProgramTransferUpdateProcs[work->transfer_state](work);
        allow_link_reset = 0;
    } else if (work->sleep_state != 0) {
        if (work->transition_requested == 0) {
            if (work->window_ready[3] == 0) {
                sIslandProgramPromptUpdateProcs[work->sleep_state](work);
            } else if ((work->current_window == NULL) || (work->current_window->draw_enabled == 1)) {
                work->window_ready[3] = 0;
            }
        }
        if (work->transition_requested == 1) {
            IslandProgram_TryOpenPendingDialog(work, 3U, 1U, 1U, 0);
        }
    } else if (work->mode != 0) {
        if ((work->mode == 1) && (gIslandDataReceived == 0) && (gGameState.keys.buttons.pressed & B_BUTTON)) {
            gGameState.transfer_requested = 1;
        }
        gGameState.sleep_requested = IslandProgram_CheckSleepRequest(work);
        if (work->transition_requested == 0) {
            if (work->window_ready[1] == 0) {
                sIslandProgramModeUpdateProcs[gIslandProgramWork.mode](&gIslandProgramWork);
            } else if ((work->current_window == NULL) || (work->current_window->draw_enabled == 1)) {
                work->window_ready[1] = 0;
                work->input_idle_timer = 0;
            }
        }
        if (work->transition_requested == 1) {
            IslandProgram_TryOpenPendingDialog(work, 1U, 1U, 1U, (s32) work->transition_requested);
        }
    }
    Joybus_CheckTimeout(allow_link_reset);
}

void sub_0201C198(void) {

}

/* Original address: 0x0201C19C */
u16 IslandProgram_GetElapsedSeconds(void) {
    return (u16) (gIslandProgramWork.elapsed_milliseconds / 1000);
}

/* Original address: 0x0201C1B8 */
s32 IslandProgram_UpdateLinkTransfer(void) {
    return UpdateIslandLinkTransfer();
}

/* Original address: 0x0201C1C4 */
void IslandProgram_TryOpenPendingDialog(IslandProgramWork *work, u8 window, u8 allow_notice, u8 allow_transfer, u8 allow_prompt) {
    s32 ready = IslandProgram_PrepareDialogTransition(work, (s8)window);

    if (ready == 1) {
        if (allow_notice != 0 && gGameState.joybus_notice_requested != 0) {
            IslandProgram_RequestNoticeTransfer(work);
            work->transition_requested = 0;
            work->notice_return_window_id = window;
            work->notice_saved_window = work->current_window;
            IslandProgram_ApplyPendingNoticeState(work);
            gGameState.joybus_notice_active = ready;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        } else if (allow_transfer != 0 && gGameState.transfer_requested != 0) {
            IslandProgram_RequestTransferPrompt(work);
            work->transition_requested = 0;
            work->transfer_return_window_id = window;
            work->transfer_saved_window = work->current_window;
            IslandProgram_ApplyPendingTransferState(work);
            gGameState.transfer_dialog_active = 1;
            gGameState.sleep_requested = 0;
            gGameState.sleep_dialog_active = 0;
        } else if (allow_prompt != 0 && gGameState.sleep_requested != 0) {
            IslandProgram_RequestSleepPrompt(work);
            work->transition_requested = 0;
            work->sleep_return_window_id = window;
            work->sleep_saved_window = work->current_window;
            IslandProgram_ApplyPendingSleepState(work);
            gGameState.sleep_dialog_active = 1;
        }
    }
}
