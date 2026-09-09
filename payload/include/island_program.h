#ifndef ISLAND_PROGRAM_H
#define ISLAND_PROGRAM_H

#include "gba/types.h"
#include "m_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Result message IDs indexed by joybus_result - 1. sizeof == 8. */
typedef struct {
    s32 message_ids[2];
} IslandProgramNoticeResultMessages;

/* Main menu/message state used by the island program. */
/* sizeof(IslandProgramWork) == 0x80 */
typedef struct IslandProgramWork {
    /* 0x00 */ u8 reserved_00[8];
    /* 0x08 */ mMsg_Window_c* notice_saved_window;
    /* 0x0C */ mMsg_Window_c* sleep_saved_window;
    /* 0x10 */ mMsg_Window_c* transfer_saved_window;
    /* 0x14 */ mMsg_Window_c* current_window;
    /* 0x18 */ s32 elapsed_milliseconds; /* producer is outside the recovered code */
    /* 0x1C */ u8 reserved_1C[0xC];
    /* 0x28 */ s32 notice_result_wait_timer;
    /* 0x2C */ s16 input_idle_timer;
    /* 0x2E */ u8 reserved_2E[6];
    /* 0x34 */ u16 saved_bg3cnt;
    /* 0x36 */ u16 saved_dispcnt;
    /* 0x38 */ u8 reserved_38[0xC];
    /* 0x44 */ u16 saved_bg3_vofs;
    /* 0x46 */ u16 saved_bg3_hofs;
    /* 0x48 */ u16 saved_bldy;
    /* 0x4A */ u8 reserved_4A[6];
    /* 0x50 */ s8 dialog_display_owner;
    /* 0x51 */ u8 reserved_51;
    /* 0x52 */ s8 mode;
    /* 0x53 */ s8 notice_state;
    /* 0x54 */ s8 sleep_state;
    /* 0x55 */ s8 transfer_state;
    /* 0x56 */ u8 reserved_56;
    /* 0x57 */ s8 pending_mode;
    /* 0x58 */ s8 pending_notice_state;
    /* 0x59 */ s8 pending_sleep_state;
    /* 0x5A */ s8 pending_transfer_state;
    /* 0x5B */ u8 reserved_5B[2];
    /* 0x5D */ s8 notice_return_window_id;
    /* 0x5E */ s8 sleep_return_window_id;
    /* 0x5F */ s8 transfer_return_window_id;
    /* 0x60 */ s8 joybus_result;
    /* 0x61 */ u8 reserved_61;
    /* 0x62 */ s8 notice_result_state; /* cleared when a notice result opens; consumer unknown */
    /* 0x63 */ s8 time_of_day;
    /* 0x64 */ u8 window_ready[5]; /* dialog transition/resume latches, indexed by window ID */
    /* 0x69 */ u8 link_transfer_started;
    /* 0x6A */ s8 joybus_transfer_mode; /* 1: send, 2: receive; consumer unknown */
    /* 0x6B */ u8 reserved_6B[2];
    /* 0x6D */ u8 transfer_succeeded;
    /* 0x6E */ u8 use_cool_dialog_palette; /* producer unknown */
    /* 0x6F */ u8 use_warm_dialog_palette; /* producer unknown */
    /* 0x70 */ u8 notice_send_active; /* command 0xFFFE0101 */
    /* 0x71 */ u8 joybus_sending;
    /* 0x72 */ u8 transition_requested;
    /* 0x73 */ u8 weather_scroll;
    /* 0x74 */ u8 retry_timer;
    /* 0x75 */ u8 retry_result;
    /* 0x76 */ u8 reserved_76[0xA];
} IslandProgramWork;

typedef void (*IslandProgramModeProc)(IslandProgramWork *work);

/* Original address: 0x030031D0 */
extern IslandProgramWork gIslandProgramWork;

/* Original address: 0x0202B00C */
extern IslandProgramNoticeResultMessages sNoticeResultMessages;

void IslandProgram_Restart(void);
s32 IslandProgram_PrepareDialogTransition(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_CheckWindowResumed(IslandProgramWork *work, s8 arg1);
u8 IslandProgram_CheckSleepRequest(IslandProgramWork *work);
s32 IslandProgram_UpdateInputTimeout(s16 *arg0, s32 arg1);
void IslandProgram_SetDialogPalette(IslandProgramWork *work, s8 arg1);
void IslandProgram_SetupDialogDisplay(IslandProgramWork *work, u8 arg1);
void IslandProgram_RestoreDialogDisplay(IslandProgramWork *work, s8 arg1);
void IslandProgram_UpdateMessages(IslandProgramWork *work);
s32 IslandProgram_TryOpenTransferDialog(IslandProgramWork *work, u8 arg1);
s32 IslandProgram_TryOpenNoticeDialog(IslandProgramWork *work, u8 arg1);
s32 IslandProgram_TryOpenSleepDialog(IslandProgramWork *work, u8 arg1);
void IslandProgram_BeginJoybusReceive(IslandProgramWork *work);
s8 IslandProgram_PollJoybusReceive(IslandProgramWork *work);
void IslandProgram_BeginJoybusSend(IslandProgramWork *work);
s16 IslandProgram_PollJoybusSend(IslandProgramWork *work);
void sub_0201ADDC(void);
s32 IslandProgram_RequestNoticeState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestNoticeTransfer(IslandProgramWork *work);
s32 IslandProgram_RequestNoticeResult(IslandProgramWork *work);
s32 IslandProgram_RequestNoticeRestart(IslandProgramWork *work);
void IslandProgram_ApplyPendingNoticeState(IslandProgramWork *work);
void IslandProgram_EnterNoticeTransfer(IslandProgramWork *work);
void IslandProgram_UpdateNoticeTransfer(IslandProgramWork *work);
void IslandProgram_EnterNoticeResult(IslandProgramWork *work);
void IslandProgram_UpdateNoticeResult(IslandProgramWork *work);
void IslandProgram_EnterNoticeRestart(IslandProgramWork *work);
void IslandProgram_UpdateNoticeRestart(IslandProgramWork *work);
s32 IslandProgram_RequestSleepState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestSleepPrompt(IslandProgramWork *work);
s32 IslandProgram_RequestSleepMode(IslandProgramWork *work);
s32 IslandProgram_RequestSleepCleanup(IslandProgramWork *work);
void IslandProgram_ApplyPendingSleepState(IslandProgramWork *work);
void IslandProgram_EnterSleepPrompt(IslandProgramWork *work);
void IslandProgram_UpdateSleepPrompt(IslandProgramWork *work);
void IslandProgram_EnterSleepMode(IslandProgramWork *work);
void IslandProgram_UpdateSleepMode(IslandProgramWork *work);
void IslandProgram_EnterSleepCleanup(IslandProgramWork *work);
void IslandProgram_UpdateSleepCleanup(IslandProgramWork *work);
void IslandProgram_SetupOverviewDisplay(void);
void IslandProgram_UpdateTimeOfDayPalette(IslandProgramWork *work);
s32 IslandProgram_RequestTransferState(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestTransferPrompt(IslandProgramWork *work);
s32 IslandProgram_RequestTransferProgress(IslandProgramWork *work);
s32 IslandProgram_RequestTransferRetry(IslandProgramWork *work);
s32 IslandProgram_RequestTransferComplete(IslandProgramWork *work);
s32 IslandProgram_RequestTransferCleanup(IslandProgramWork *work);
s32 IslandProgram_RequestTransferRestart(IslandProgramWork *work);
void IslandProgram_ApplyPendingTransferState(IslandProgramWork *work);
void IslandProgram_EnterTransferPrompt(IslandProgramWork *work);
void IslandProgram_UpdateTransferPrompt(IslandProgramWork *work);
void IslandProgram_EnterTransferProgress(IslandProgramWork *work);
void IslandProgram_UpdateTransferProgress(IslandProgramWork *work);
void IslandProgram_EnterTransferRetry(IslandProgramWork *work);
void IslandProgram_UpdateTransferRetry(IslandProgramWork *work);
void IslandProgram_EnterTransferComplete(IslandProgramWork *work);
void IslandProgram_UpdateTransferComplete(IslandProgramWork *work);
void IslandProgram_EnterTransferCleanup(IslandProgramWork *work);
void IslandProgram_UpdateTransferCleanup(IslandProgramWork *work);
void IslandProgram_EnterTransferRestart(IslandProgramWork *work);
void IslandProgram_UpdateTransferRestart(IslandProgramWork *work);
s32 IslandProgram_RequestMode(IslandProgramWork *work, s8 arg1);
s32 IslandProgram_RequestNormalMode(IslandProgramWork *work);
s32 IslandProgram_RequestFieldLoadMode(IslandProgramWork *work);
s32 IslandProgram_RequestMosaicCoverMode(IslandProgramWork *work);
s32 IslandProgram_RequestMosaicRevealMode(IslandProgramWork *work);
s32 IslandProgram_RequestMessageMode(IslandProgramWork *work);
void IslandProgram_ApplyPendingMode(IslandProgramWork *work);
void IslandProgram_EnterNormalMode(IslandProgramWork *work);
void IslandProgram_UpdateNormalMode(IslandProgramWork *work);
void IslandProgram_EnterFieldLoadMode(IslandProgramWork *work);
void IslandProgram_UpdateFieldLoadMode(IslandProgramWork *work);
void IslandProgram_EnterMosaicCoverMode(IslandProgramWork *work);
void IslandProgram_UpdateMosaicCoverMode(IslandProgramWork *work);
void IslandProgram_EnterMosaicRevealMode(IslandProgramWork *work);
void IslandProgram_UpdateMosaicRevealMode(IslandProgramWork *work);
void IslandProgram_EnterMessageMode(IslandProgramWork *work);
void IslandProgram_UpdateMessageMode(IslandProgramWork *work);
void IslandProgram_InitWork(void);
void IslandProgram_Update(void);
void sub_0201C198(void);
u16 IslandProgram_GetElapsedSeconds(void);
s32 IslandProgram_UpdateLinkTransfer(void);
void IslandProgram_TryOpenPendingDialog(IslandProgramWork *work, u8 window, u8 allow_notice, u8 allow_transfer, u8 allow_prompt);

#ifdef __cplusplus
}
#endif

#endif // ISLAND_PROGRAM_H