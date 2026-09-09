#ifndef GUARD_SOUND_H
#define GUARD_SOUND_H

#include "gba/types.h"

#define SOUND_SEQUENCE_COMMAND_GROUP_MASK 0xF0
#define SOUND_SEQUENCE_COMMAND_ARGUMENT_MASK 0x0F

enum SoundSequenceCommand {
    SOUND_SEQUENCE_NOTE_WITH_PREVIOUS_PARAMS_MAX = 0x5F,
    SOUND_SEQUENCE_NOTE_WITH_PARAMS_MIN = 0x60,
    SOUND_SEQUENCE_NOTE_WITH_PARAMS_MAX = 0xBF,
    SOUND_SEQUENCE_REST_WITH_PREVIOUS_DURATION = 0xC0,
    SOUND_SEQUENCE_REST = 0xC1,
    SOUND_SEQUENCE_SET_PROGRAM = 0xC2,
    SOUND_SEQUENCE_SET_PAN = 0xC3,
    SOUND_SEQUENCE_SET_PRIORITY = 0xC4,
    SOUND_SEQUENCE_TIE_ON = 0xC5,
    SOUND_SEQUENCE_TIE_OFF = 0xC6,
    SOUND_SEQUENCE_SET_INSTRUMENT_BANK = 0xC7,
    SOUND_SEQUENCE_NOTE_WAIT_ON = 0xC8,
    SOUND_SEQUENCE_NOTE_WAIT_OFF = 0xC9,
    SOUND_SEQUENCE_CONTROL_CALLBACK = 0xCA,
    SOUND_SEQUENCE_SLIDE = 0xD0,
    SOUND_SEQUENCE_SET_VOLUME = 0xE0,
    SOUND_SEQUENCE_SET_PITCH_BEND = 0xE1,
    SOUND_SEQUENCE_SET_PITCH_BEND_RANGE = 0xE2,
    SOUND_SEQUENCE_SET_REVERB_VOLUME = 0xE3, /* Inferred from the analogous jaudio_NES track parameter. */
    SOUND_SEQUENCE_SET_TEMPO = 0xE4,
    SOUND_SEQUENCE_SET_VIBRATO_DELAY = 0xE5,
    SOUND_SEQUENCE_SET_VIBRATO_SPEED = 0xE6,
    SOUND_SEQUENCE_SET_VIBRATO_DEPTH = 0xE7,
    SOUND_SEQUENCE_SLIDE_OFF = 0xE8,
    SOUND_SEQUENCE_SET_TRANSPOSITION = 0xE9,
    SOUND_SEQUENCE_JUMP = 0xF0,
    SOUND_SEQUENCE_CALL = 0xF4,
    SOUND_SEQUENCE_START_TRACK = 0xF8,
    SOUND_SEQUENCE_RETURN_OR_END = 0xFF,
};

enum SoundEmotion {
    SOUND_EMOTION_NONE = 0,
    SOUND_EMOTION_NEUTRAL = 1,
    SOUND_EMOTION_ANGRY = 2,
    SOUND_EMOTION_SAD = 3,
    SOUND_EMOTION_HAPPY = 4,
};

/* Each command is 0x0C bytes; the ring occupies 0x03000278..0x03000577. */
enum SoundCommandType {
    SOUND_COMMAND_START_MUSIC = 0,
    SOUND_COMMAND_START_EFFECT = 1,
    SOUND_COMMAND_FADE_OUT_PLAYER = 2,
    SOUND_COMMAND_SET_PLAYER_PAUSED = 3,
    SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST = 4,
    SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME = 5,
    SOUND_COMMAND_SET_PLAYER_TEMPO_MODE = 6,
    SOUND_COMMAND_SET_TRACKS_MUTED = 7,
    SOUND_COMMAND_SET_TRACKS_EXPRESSION = 9,
    SOUND_COMMAND_SET_TRACKS_PAN = 8,
    SOUND_COMMAND_COMMAND_10 = 10,
    SOUND_COMMAND_CALLBACK = 11,
    SOUND_COMMAND_SET_CONTROL_CALLBACK = 12,
    SOUND_COMMAND_SET_NOTE_CALLBACK = 13,
};

typedef struct SoundChannel SoundChannel;
typedef struct SoundBank SoundBank;
typedef struct SoundTrack SoundTrack;
typedef struct SoundInstrumentResult SoundInstrumentResult;
typedef struct SoundPlayer SoundPlayer;
typedef struct SoundCommand SoundCommand;
typedef void (*SoundNoteCallback)(SoundTrack *track, u8 key, u8 velocity, u16 duration);
typedef void (*SoundControlCallback)(SoundTrack *track, u8 code);

/* Music sequences begin with a signed track count and a halfword offset table. */
typedef struct SoundMusicSequence {
    /* 0x00 */ s8 track_count;
    /* 0x01 */ u8 reserved;
    /* 0x02 */ u16 track_offsets[1];
} SoundMusicSequence;

/* sizeof(SoundEffectState) == 0x08. */
typedef struct SoundEffectState {
    /* 0x00 */ s32 sound_id;
    /* 0x04 */ u8 active;
    /* 0x05 */ u8 unk_05[3];
} SoundEffectState;

/* sizeof(SoundPlayer) == 0x44; eight players at 0x03001918. */
struct SoundPlayer {
    /* 0x00 */ const u16 *bank;
    /* 0x04 */ const u8 *sequence;
    /* 0x08 */ SoundTrack *tracks[10];
    /* 0x30 */ union {
        struct { u8 tempo[2]; u8 tempo_adjust[2]; } bytes;
        struct { u16 tempo; s16 tempo_adjust; } values;
    } timing;
    /* 0x34 */ u16 volume;
    /* 0x36 */ s16 volume_step;
    /* 0x38 */ u16 target_volume;
    /* 0x3A */ u16 fade_timer;
    /* 0x3C */ union {
        s8 flags;
        struct { u8 paused : 1; u8 reserved : 7; } __attribute__((packed)) bits;
    } __attribute__((packed)) control;
    /* 0x3D */ u8 unk_3D[3];
    /* 0x40 */ u8 master_volume;
    /* 0x41 */ u8 status;
    /* 0x42 */ u8 is_sound_effect;
    /* 0x43 */ u8 tempo_mode;
};

typedef struct SoundEnvelopePoint {
    s16 duration;
    s16 volume;
} SoundEnvelopePoint;

/* sizeof(SoundEnvelope) == 0x14. */
typedef struct SoundEnvelope {
    s32 volume;
    s32 target_volume;
    u16 timer;
    s16 step;
    const SoundEnvelopePoint *points;
    s8 index;
    u8 unk_11[3];
} SoundEnvelope;

typedef struct SoundVibratoParams {
    u16 delay;
    u16 unk_02;
    s32 speed;
    s32 depth;
} SoundVibratoParams;

typedef struct SoundVibrato {
    u32 phase;
    s32 delay;
    SoundVibratoParams *params;
} SoundVibrato;

typedef struct SoundPitchSlide {
    s32 delay;
    s32 timer;
    s32 offset;
    s32 target;
    s32 step;
    struct SoundPitchSlideParams *params;
} SoundPitchSlide;

/* sizeof(SoundPitchSlideParams) == 8. */
typedef struct SoundPitchSlideParams {
    u8 enabled;
    u8 flags;
    u8 key;
    u8 unk_03;
    u16 delay;
    u16 duration;
} SoundPitchSlideParams;

/* sizeof(SoundTrack) == 0x54. Unrecovered fields retain their offsets. */
struct SoundTrack {
    const u8 *sequence;
    const u32 *sample_offsets;
    SoundPlayer *player;
    SoundChannel *channel;
    SoundVibratoParams vibrato;
    SoundPitchSlideParams slide;
    /* 0x24 */ const u8 *return_stack[3];
    /* 0x30 */ const u8 **stack_pointer;
    /* 0x34 */ s32 tick_accumulator;
    u8 unk_38[8];
    /* 0x40 */ u16 bank;
    /* 0x42 */ u16 program;
    /* 0x44 */ u16 note_duration;
    /* 0x46 */ u16 rest_duration;
    /* 0x48 */ u8 velocity;
    /* 0x49 */ u8 tie;
    /* 0x4A */ u8 muted;
    u8 pan;
    u8 unk_4C;
    u8 volume;
    u8 expression;
    s8 pitch_bend;
    u8 pitch_bend_range;
    u8 transpose;
    u8 priority;
    u8 unk_53;
};

typedef struct SoundInstrument {
    u8 type;
    u8 flags;
    u16 sample;
    u16 envelope;
    u8 release;
    u8 root_key;
} SoundInstrument;

typedef struct SoundInstrumentMap {
    u8 type;
    u8 flags;
    u16 table;
    u8 first_key;
    u8 unk_05;
} SoundInstrumentMap;

/* The square-wave instrument extends the common eight-byte header. */
typedef struct SoundSquareInstrument {
    SoundInstrument instrument;
    u8 sweep;
} SoundSquareInstrument;

typedef struct SoundKeyInstrument {
    u16 instrument;
    u8 pan;
    u8 unk_03;
} SoundKeyInstrument;

typedef struct SoundInstrumentSplit {
    u8 last_key;
    u8 unk_01;
    u16 instrument;
} SoundInstrumentSplit;

/* sizeof(SoundBank) == 0x1C; table offsets are relative to each table. */
struct SoundBank {
    /* 0x00 */ const u32 *sample_offsets;
    /* 0x04 */ const u32 *instrument_offsets;
    /* 0x08 */ const u32 *music_sequence_offsets;
    /* 0x0C */ const u32 *effect_sequence_offsets;
    /* 0x10 */ const u16 *sample_indices;
    /* 0x14 */ const u32 *music_bank_offsets;
    /* 0x18 */ const u32 *effect_bank_offsets;
};

typedef struct SoundSample {
    u32 length;
    u32 frequency;
    u32 loop_start;
    u32 loop_end;
} SoundSample;

typedef struct SoundDutySequence {
    u16 length;
    u8 values[1];
} SoundDutySequence;

/* sizeof(SoundInstrumentResult) == 0x14; filled by Sound_ResolveInstrument. */
struct SoundInstrumentResult {
    SoundInstrument *instrument;
    const SoundEnvelopePoint *envelope;
    SoundDutySequence *duty_sequence;
    const u16 *wave;
    u8 pan;
    u8 fixed_pan;
    u8 fixed_pitch;
};

/* sizeof(SoundChannel) == 0x7C, confirmed by both channel pool strides. */
struct SoundChannel {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 unk_02[2];
    /* 0x04 */ SoundTrack *track;
    /* 0x08 */ u8 priority;
    /* 0x09 */ u8 velocity;
    /* 0x0A */ u8 unk_0A[2];
    /* 0x0C */ u32 base_pitch;
    /* 0x10 */ u32 pitch;
    /* 0x14 */ u32 volume;
    /* 0x18 */ u16 gate_timer;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 fixed_pan;
    /* 0x1C */ u8 pan;
    /* 0x1D */ u8 unk_1D[3];
    /* 0x20 */ SoundVibrato vibrato;
    /* 0x2C */ SoundPitchSlide slide;
    /* 0x44 */ SoundEnvelope envelope;
    /* 0x58 */ SoundInstrument *instrument;
    /* 0x5C */ u8 release;
    /* 0x5D */ u8 unk_5D[3];
    /* 0x60 */ SoundSample *sample;
    /* 0x64 */ u32 age;
    /* 0x68 */ union {
        SoundDutySequence *sequence;
        const u16 *wave;
        u8 duty;
    } psg;
    /* 0x6C */ SoundChannel *prev;
    /* 0x70 */ SoundChannel *next;
    /* 0x74 */ SoundChannel *track_prev;
    /* 0x78 */ SoundChannel *track_next;
};

/* sizeof(SoundChannelLists) == 0x1F4; sentinel offsets 0x04/0x80/0xFC/0x178. */
typedef struct SoundChannelLists {
    void *wave;
    SoundChannel active_head;
    SoundChannel active_tail;
    SoundChannel free_head;
    SoundChannel free_tail;
} SoundChannelLists;

typedef u32 (*PcmChannelMixer)(const s8 *, s16 *, s16 *, s16 *, u32, u32, u32, u32);

struct SoundCommand {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 reserved;
    /* 0x04 */ union {
        u32 value;
        struct { u16 value; u16 player; } parts;
        void (*callback)(u32);
        SoundControlCallback control_callback;
        SoundNoteCallback note_callback;
    } arg0;
    /* 0x08 */ u32 arg1;
};

/* The channel mixer accumulates halfwords; the output mixer packs them as words. */
typedef union PcmMixBuffer {
    s16 samples[352];
    s32 words[176];
} PcmMixBuffer;

void Audio_Init(void);
void Audio_Update(void);
void Sound_InitEffects(void);
void sub_02026A34(void);
void Sound_PlayEffect0(u16 value);
void Sound_PlayEffect1(u16 arg0);
void Sound_StopEffect1(u8 arg0);
void Sound_PlayEffect2(u16 value);
void Sound_StopEffect2(u16 value);
void Sound_InitMusic(void);
void sub_02026C0C(void);
void Sound_PlayMusic(u16 value);
void Sound_StopMusic(u16 value);
void Sound_SetEmotion(u8 arg0);
void Sound_PlayEmotionNote(SoundTrack *arg0, u8 arg1, u8 arg2, u16 arg3);
void Sound_ApplyEmotionTrackDelay(SoundTrack *arg0, u8 arg1);
void SoundDriver_Init(const SoundBank *bank);
void SoundDriver_VBlank(void);
void SoundDriver_Update(void);
void SoundDriver_InitPcmBuffers(s8 *buffers);
void SoundDriver_SwapPcmBuffers(void);
void SoundDriver_DisablePcm(void);
void SoundDriver_EnablePcm(void);
void SoundDriver_InitChannelLists(void);
void Sound_UnlinkChannel(SoundChannel *channel);

void Sound_InsertPcmChannelByPriority(SoundChannel *arg0);
s32 Sound_NoteToPitch(SoundChannel *arg0, u8 arg1, u8 arg2);
u8 Sound_NoteToNoiseControl(u16 arg0);
s32 Sound_UpdateChannelEnvelope(SoundChannel *arg0);
void sub_02027370(u8 arg0);
u32 Sound_UpdatePcmChannelVolume(SoundChannel *arg0);
u8 Sound_GetPsgEnvelopeControl(SoundChannel *arg0, u8 arg1);
u32 Sound_UpdateChannelPitch(SoundChannel *arg0);
void Sound_UpdatePcmChannels(void);
void Sound_UpdatePsgChannels(void);
void Sound_PlayNote(SoundTrack *track, u8 key, u8 velocity, u16 duration);
void Sound_ReleaseChannel(SoundChannel *channel);
void Sound_StopChannel(SoundChannel *channel);
void Sound_StartPsgChannel(SoundChannel *channel, u8 envelope);
SoundChannel *Sound_AllocateChannel(u8 type, SoundTrack *track, u8 priority);
u8 Sound_MixPcmChannel(SoundChannel *channel, u32 volume, u32 pitch, u8 pan);
void Sound_InitKeySampleInstrument(void);
void Sound_ResolveInstrument(SoundTrack *track, u8 key, SoundInstrumentResult *result);
void Sound_InitPlayers(void);
void Sound_ResetPlayerParameters(SoundPlayer *player);
void Sound_UpdatePlayers(void);
void Sound_StartMusic(s32 player, u32 music);
void Sound_StartEffect(s32 player, u32 group, u32 effect);
void Sound_StartMusicSequence(s32 index, const u8 *sequence, const u16 *bank);
void Sound_StartEffectSequence(s32 index, const u8 *sequence, const u16 *bank, u32 effect);
void Sound_StopPlayer(s32 arg0);
void Sound_FadeOutPlayer(s32 index, s32 frames);
void Sound_SetPlayerPaused(s32 arg0, u8 arg1);
u32 Sound_GetPlayerStatus(s32 arg0);
void Sound_InitTracks(void);
SoundTrack *Sound_FindFreeTrack(void);
void Sound_StartTrack(SoundTrack *track, SoundPlayer *player, const u8 *sequence);
void Sound_ReleaseTrackChannels(SoundTrack *track);
void Sound_StopTrack(SoundTrack *track);
s32 Sound_UpdateTrack(SoundTrack *track);
void Sound_AttachChannelToTrack(SoundTrack *track, SoundChannel *channel);
void Sound_DetachChannelFromTrack(SoundTrack *track, SoundChannel *channel);
u16 Sound_ReadSequenceDuration(SoundTrack *track);
void Sound_SetTrackBank(SoundTrack *track, u32 bank);
void Sound_InitCommandQueue(void);
SoundCommand *Sound_ReadCommand(void);
void Sound_CommitCommands(void);
void Sound_QueueStartMusic(u16 player, u16 music);
void Sound_QueueStartEffect(u32 player, u16 group, u16 effect);
void Sound_QueueFadeOutPlayer(u16 player, u16 frames);
void Sound_QueueSetPlayerPaused(u16 player, u8 paused);
void Sound_QueueSetPlayerTempoAdjust(u16 player, s16 adjustment);
void Sound_QueueSetPlayerMasterVolume(u16 player, u8 volume);
void Sound_QueueSetPlayerTempoMode(u16 player, u8 mode);
void Sound_QueueSetTracksMuted(u32 player, u32 tracks, u8 muted);
void Sound_QueueSetTracksExpression(u32 player, u32 tracks, u8 expression);
void Sound_QueueSetTracksPan(u32 player, u32 tracks, u8 pan);
void Sound_QueueCommand10(u8 value);
void Sound_QueueCallback(void (*callback)(u32), u32 argument);
void Sound_QueueSetControlCallback(SoundControlCallback callback);
void Sound_QueueSetNoteCallback(SoundNoteCallback callback);
void Sound_ProcessCommands(void);

extern u8 sound_data[];

#endif /* GUARD_SOUND_H */
