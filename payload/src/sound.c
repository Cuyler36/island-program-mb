#include "global.h"
#include "sound.h"

/* Original address: 0x02029004 */
extern u8 sub_02029004[];
/* Original address: 0x020290C4 */
extern u8 sub_020290C4[];
/* Original address: 0x020291E4 */
extern u8 sub_020291E4[];

/* Original address: 0x02035BF4 */
extern const SoundBank sSoundBank;

/* Original address: 0x020269C8 */
void Audio_Init(void) {
    SoundDriver_Init(&sSoundBank);
    Sound_InitMusic();
    Sound_InitEffects();
}

/* Original address: 0x020269E0 */
void Audio_Update(void) {
    sub_02026A34();
    Sound_CommitCommands();
}

/* Original address: 0x03000028 */
extern s16 sCurrentSoundEffects[5];
/* Original address: 0x03000038 */
extern SoundEffectState sSoundEffectStates[3];
/* Original address: 0x03000050 */
extern u16 sCurrentMusic;
/* Original address: 0x03000052 */
extern u8 sMusicEmotion;
/* Original address: 0x03001918 */
extern SoundPlayer gSoundPlayers[8] __attribute__((aligned(1)));
/* Original address: 0x02035C10 */
extern const u32 sSoundEffectTable[43];
/* Original address: 0x02035CBC */
extern const u8 sMusicTable[2][2];

/* Original address: 0x020269F0 */
void Sound_InitEffects(void) {
    s16 *current = sCurrentSoundEffects;
    s32 i;

    for (i = 0; i < 3; i++) {
        sSoundEffectStates[i].sound_id = -1;
        sSoundEffectStates[i].active = 0;
    }
    CpuFill16(0xFFFF, current, sizeof(sCurrentSoundEffects));
}

void sub_02026A34(void) {

}

/* Original address: 0x02026A38 */
void Sound_PlayEffect0(u16 value) {
    u16 player = 0;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026AB8 */
void Sound_PlayEffect1(u16 value) {
    u16 player = 1;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026B38 */
void Sound_StopEffect1(u8 arg0) {
    Sound_QueueFadeOutPlayer(1U, 0U);
}

/* Original address: 0x02026B48 */
void Sound_PlayEffect2(u16 value) {
    u16 player = 2;
    u32 sound = sSoundEffectTable[value];

    if (Sound_GetPlayerStatus(player) != 0) {
        u32 current = sSoundEffectTable[sCurrentSoundEffects[player]];
        s32 priority;
        if (!(sound & 0x04000000))
            priority = !(sound & 0x02000000);
        else
            priority = 2;
        if (!(current & 0x04000000)) {
            if (priority < (s32)(!(current & 0x02000000)))
                return;
        } else if (priority <= 1) {
            return;
        }
    }
    Sound_QueueStartEffect(player, 0, (u16)sound);
    sCurrentSoundEffects[player] = value;
}

/* Original address: 0x02026BC8 */
void Sound_StopEffect2(u16 value) {
    Sound_QueueFadeOutPlayer(2U, 0U);
}

/* Original address: 0x02026BD8 */
void Sound_InitMusic(void) {
    Sound_QueueSetNoteCallback(Sound_PlayEmotionNote);
    Sound_QueueSetControlCallback(Sound_ApplyEmotionTrackDelay);
    sCurrentMusic = 0xFFFF;
    sMusicEmotion = SOUND_EMOTION_NONE;
}

void sub_02026C0C(void) {

}

/* Original address: 0x02026C10 */
void Sound_PlayMusic(u16 value) {
    if (Sound_GetPlayerStatus(4) == 0 || sCurrentMusic != value) {
        Sound_QueueStartMusic(4, sMusicTable[value][0]);
        if (value == 1) {
            Sound_SetEmotion(sMusicEmotion);
        } else {
            Sound_QueueSetTracksMuted(4, 0, 0);
        }
        sCurrentMusic = value;
    }
}

/* Original address: 0x02026C68 */
void Sound_StopMusic(u16 value) {
    Sound_QueueFadeOutPlayer(4U, value);
}

/* Original address: 0x02026C7C */
void Sound_SetEmotion(u8 emotion) {
    u8 tempo_mode;
    u16 tempo_adjust;

    if (emotion == sMusicEmotion)
        return;
    sMusicEmotion = emotion;
    if (Sound_GetPlayerStatus(4) == 0 || sCurrentMusic != 1)
        return;

    tempo_mode = 0;
    tempo_adjust = 0;
    switch (emotion) {
    case SOUND_EMOTION_NEUTRAL:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0, 1);
        break;
    case SOUND_EMOTION_ANGRY:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0x94, 1);
        tempo_adjust = 30;
        tempo_mode = 1;
        break;
    case SOUND_EMOTION_SAD:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0x210, 1);
        tempo_adjust = -16;
        tempo_mode = 1;
        break;
    case SOUND_EMOTION_HAPPY:
        Sound_QueueSetTracksMuted(4, 0xFFFF, 0);
        Sound_QueueSetTracksMuted(4, 0, 1);
        {
            u8 tempo_low = gSoundPlayers[4].timing.bytes.tempo[0];
            u8 tempo_high = gSoundPlayers[4].timing.bytes.tempo[1];
            tempo_adjust = (s16)((tempo_high << 8) | tempo_low) >> 1;
        }
        break;
    default:
        return;
    }
    Sound_QueueSetPlayerTempoMode(4, tempo_mode);
    Sound_QueueSetPlayerTempoAdjust(4, (s16)tempo_adjust);
}

/* Original address: 0x03000B24 */
extern SoundTrack gSoundTracks[16];

/* Original address: 0x03000268 */
extern SoundInstrument sSoundKeySampleInstrument;
/* Original address: 0x02035CD4 */
extern const SoundEnvelopePoint sSoundKeySampleEnvelope[3];

/* Original address: 0x02035CCC */
extern const u8 sSoundInstrumentChannelTypes[5];

/* Original address: 0x03000058 */
extern s8 *gPcmOutputBuffers[2];
/* Original address: 0x03000060 */
extern s8 *gPcmRightOutputBuffers[2];
/* Original address: 0x03000068 */
extern u16 gSoundTimerReload;
/* Original address: 0x0300006A */
extern u8 gPcmOutputBufferIndex;
/* Original address: 0x0300006B */
extern u8 gSoundDmaEnabled;
/* Original address: 0x03000070 */
extern SoundChannelLists gSoundChannelLists;
/* Original address: 0x03000594 */
extern const SoundBank *gSoundBank;
/* Original address: 0x03000598 */
extern void (*gPcmOutputMixer)(s32 *, s8 *, s32 *);
/* Original address: 0x0300059C */
extern PcmChannelMixer gPcmChannelMixer;
/* Original address: 0x030005A0 */
extern void (*gPcmResampleMixer)(void);
/* Original address: 0x030005A4 */
extern s8 gSoundPcmBuffers[2][2][176];
/* Original address: 0x03001064 */
extern u32 gSoundMixerCode[0xD8];
/* The channel pools have byte alignment in the sound driver ABI. */
/* Original address: 0x030013C4 */
extern SoundChannel gPcmChannels[7] __attribute__((aligned(1)));
/* Original address: 0x03001728 */
extern SoundChannel gPsgChannels[4] __attribute__((aligned(1)));

/* Disabling DMA requires a readback before the channel is reprogrammed. */
#define SOUND_DMA_DISABLE(n) do { \
    vu16 *regs = (vu16 *)REG_ADDR_DMA##n; \
    regs[5] = ((u32)regs[5] << 17) >> 17; \
    regs[5]; \
} while (0)

/* Original address: 0x02026D74 */
void Sound_PlayEmotionNote(SoundTrack *arg0, u8 note, u8 velocity, u16 duration) {
    SoundTrack *track = (SoundTrack *)arg0;
    if (track != track->player->tracks[9]) {
        if (sMusicEmotion == SOUND_EMOTION_ANGRY) {
            switch ((u8)(note % 12U)) {
            case 0: note += 2; break;
            case 1:
            case 3:
            case 5: note++; break;
            }
        } else {
            switch ((u8)(note % 12U)) {
            case 0:
            case 5:
            case 7: note--; break;
            }
        }
    }
    Sound_PlayNote((SoundTrack *)arg0, note, velocity, duration);
}

/* Original address: 0x02026DFC */
void Sound_ApplyEmotionTrackDelay(SoundTrack *arg0, u8 event) {
    SoundPlayer *player = ((SoundTrack *)arg0)->player;
    if ((sMusicEmotion == SOUND_EMOTION_HAPPY && event != 0) ||
        (sMusicEmotion == SOUND_EMOTION_ANGRY && (*(vu8 *)REG_ADDR_TM0CNT_L & 15U) <= 4)) {
        int i;
        for (i = 0; i < 10; i++) {
            SoundTrack *track = player->tracks[i];
            if (track != NULL)
                track->tick_accumulator += 1800;
        }
    }
}

/* Original address: 0x02026E4C */
void SoundDriver_Init(const SoundBank *bank) {
    gSoundBank = bank;
    *(vu8 *)REG_ADDR_SOUNDCNT_X = 0;
    *(vu8 *)REG_ADDR_SOUNDCNT_X = 0x80;
    REG_SOUNDCNT_L = 0xFF77;
    *(vu8 *)REG_ADDR_SOUNDCNT_H = 0x0D;
    REG_SOUNDBIAS = (REG_SOUNDBIAS & 0x3FFF) | 0x4000;
    REG_SOUND1CNT_L = 8;
    REG_SOUND1CNT_H = 0xF000;
    CpuFastCopy(sub_02029004, gSoundMixerCode, sizeof(gSoundMixerCode));
    gPcmOutputMixer = (void (*)(s32 *, s8 *, s32 *))gSoundMixerCode;
    gPcmChannelMixer = (PcmChannelMixer)((u8 *)gSoundMixerCode + (sub_020290C4 - sub_02029004));
    gPcmResampleMixer = (void (*)(void))((u8 *)gSoundMixerCode + (sub_020291E4 - sub_02029004));
    SoundDriver_InitPcmBuffers(&gSoundPcmBuffers[0][0][0]);
    Sound_InitCommandQueue();
    Sound_InitKeySampleInstrument();
    SoundDriver_InitChannelLists();
    Sound_InitTracks();
    Sound_InitPlayers();
}

/* Original address: 0x02026F0C */
void SoundDriver_VBlank(void) {
    SoundDriver_SwapPcmBuffers();
}

/* Original address: 0x02026F18 */
void SoundDriver_Update(void) {
    Sound_ProcessCommands();
    Sound_UpdatePlayers();
    Sound_UpdatePsgChannels();
    if (gSoundDmaEnabled != 0) {
        Sound_UpdatePcmChannels();
    }
}

/* Original address: 0x02026F3C */
void SoundDriver_InitPcmBuffers(s8 *buffers) {
    vu8 a;

    gSoundDmaEnabled = 1;
    gPcmOutputBuffers[0] = buffers;
    gPcmRightOutputBuffers[0] = buffers + 176;
    gPcmOutputBuffers[1] = buffers + 352;
    gPcmRightOutputBuffers[1] = buffers + 528;
    gSoundTimerReload = 0xF9C4;
    gPcmOutputBufferIndex = 0;
    *(vu8 *)(REG_ADDR_SOUNDCNT_H + 1) = 0x9A;
    REG_FIFO_A = 0;
    REG_FIFO_B = 0;
}

/* Original address: 0x02026FAC */
void SoundDriver_SwapPcmBuffers(void) {
    REG_TM0CNT = gSoundTimerReload | 0x800000;
    if (gSoundDmaEnabled) {
        SOUND_DMA_DISABLE(1);
        SOUND_DMA_DISABLE(2);
        DmaSet(1, gPcmOutputBuffers[gPcmOutputBufferIndex], REG_ADDR_FIFO_A, 0xB6400004);
        DmaSet(2, gPcmRightOutputBuffers[gPcmOutputBufferIndex], REG_ADDR_FIFO_B, 0xB6400004);
        gPcmOutputBufferIndex = 1 - gPcmOutputBufferIndex;
    }
}

/* Original address: 0x02027040 */
void SoundDriver_DisablePcm(void) {
    gSoundDmaEnabled = 0;
    SOUND_DMA_DISABLE(1);
    SOUND_DMA_DISABLE(2);
}

/* Original address: 0x02027068 */
void SoundDriver_EnablePcm(void) {
    gSoundDmaEnabled = 1;
}

/* Original address: 0x02027074 */
void SoundDriver_InitChannelLists(void) {
    SoundChannelLists *lists;
    SoundChannel *tail;
    int i;
    gSoundChannelLists.wave = NULL;

    for (i = 0; i < 4; i++)
        gPsgChannels[i].state = 0;
    gPsgChannels[0].type = 1;
    gPsgChannels[1].type = 2;
    gPsgChannels[2].type = 3;
    gPsgChannels[3].type = 4;
    for (i = 0; i < 7; i++) {
        gPcmChannels[i].state = 0;
        gPcmChannels[i].type = 0;
    }
    gSoundChannelLists.free_head.next = gPcmChannels;
    gPcmChannels[0].next = &gPcmChannels[1];
    gPcmChannels[0].prev = &gSoundChannelLists.free_head;
    for (i = 1; i < 6; i++) {
        gPcmChannels[i].next = &gPcmChannels[i + 1];
        gPcmChannels[i].prev = &gPcmChannels[i - 1];
    }
    tail = &gSoundChannelLists.free_tail;
    gPcmChannels[6].next = tail;
    gPcmChannels[6].prev = &gPcmChannels[5];
    lists = &gSoundChannelLists;
    tail->prev = &gPcmChannels[6];
    lists->active_head.next = &lists->active_tail;
    lists->active_tail.prev = &lists->active_head;
}

/* Original address: 0x020271FC */
void Sound_UnlinkChannel(SoundChannel *channel) {
    channel->prev->next = channel->next;
    channel->next->prev = channel->prev;
}

/* Original address: 0x03000864 */
extern PcmMixBuffer gPcmMixBuffer;
/* Original address: 0x02035CC4 */
extern const u8 sPsgWaveVolume[5];
/* Original address: 0x02035CE0 */
extern const u16 sPsgPitchTable[];
/* Original address: 0x02035DD0 */
extern const u8 sNoisePitchTable[120];
/* Original address: 0x02035E48 */
extern const u32 sPcmPitchTable[];
/* Original address: 0x02036028 */
extern const u8 sSoundVibratoWave[256];

/* Original address: 0x0202720C */
void Sound_InsertPcmChannelByPriority(SoundChannel *channel) {
    SoundChannel *next = gSoundChannelLists.active_head.next;

    if (channel->state == 1) {
        while (next != &gSoundChannelLists.active_tail) {
            if (next->state == 1 && channel->priority < next->priority)
                break;
            next = next->next;
        }
    } else if (channel->state == 2) {
        while (next != &gSoundChannelLists.active_tail && next->state != 1 &&
               channel->priority >= next->priority)
            next = next->next;
    } else {
        return;
    }
    channel->next = next;
    channel->prev = next->prev;
    next->prev->next = channel;
    next->prev = channel;
}

/* Original address: 0x02027294 */
s32 Sound_NoteToPitch(SoundChannel *channel, u8 key, u8 root_key) {
    s16 note = key + 48 - root_key;
    if (note < 0)
        note = 0;
    else if (note > 119)
        note = 120;
    if (channel->type == 0)
        return sPcmPitchTable[note];
    else if (channel->type == 4)
        return note;
    else
        return sPsgPitchTable[note];
}

/* Original address: 0x020272E8 */
u8 Sound_NoteToNoiseControl(u16 note) {
    if (note > 119)
        note = 119;
    return sNoisePitchTable[note];
}

/* Original address: 0x02027300 */
s32 Sound_UpdateChannelEnvelope(SoundChannel *channel) {
    SoundEnvelope *envelope = &channel->envelope;
    if (envelope->timer == 0) {
        channel->envelope.volume = envelope->target_volume;
        envelope->index++;
        if (envelope->points[envelope->index].duration < 0)
            envelope->index--;
        envelope->target_volume = envelope->points[envelope->index].volume;
        envelope->timer = envelope->points[envelope->index].duration;
        envelope->step = envelope->target_volume;
        envelope->step -= channel->envelope.volume;
        envelope->step /= envelope->timer;
    }
    envelope->volume += envelope->step;
    envelope->timer--;
    return envelope->volume;
}

void sub_02027370(u8 arg0) {
}

/* Original address: 0x02027374 */
u32 Sound_UpdatePcmChannelVolume(SoundChannel *channel) {
    u32 volume;
    if (channel->state == 1) {
        SoundTrack *track;
        SoundPlayer *player;
        volume = channel->velocity;
        volume <<= 8;
        track = channel->track;
        player = track->player;
        volume *= player->volume;
        volume >>= 7;
        volume *= player->master_volume;
        volume >>= 7;
        volume *= track->volume;
        volume >>= 15;
        volume *= track->expression;
        volume >>= 7;
        volume *= Sound_UpdateChannelEnvelope(channel);
        volume >>= 15;
        channel->volume = volume;
    } else {
        channel->volume = (channel->volume * (channel->release + 230)) >> 9;
        volume = channel->volume;
    }
    volume >>= 8;
    return volume;
}

/* Original address: 0x020273D0 */
u8 Sound_GetPsgEnvelopeControl(SoundChannel *channel, u8 boost) {
    u8 control = 0;
    u32 volume = channel->velocity;
    u32 target;
    u16 period;
    s32 difference;
    SoundTrack *track;
    SoundPlayer *player;

    if (channel->envelope.timer == 0)
        control = 1;
    Sound_UpdateChannelEnvelope(channel);
    if (control == 0)
        return 8;
    if (boost)
        volume *= 2;
    volume <<= 15;
    track = channel->track;
    volume *= track->volume;
    volume >>= 14;
    volume *= track->expression;
    volume >>= 7;
    player = track->player;
    volume *= player->master_volume;
    volume >>= 8;
    volume *= player->volume;
    if (channel->type == 3) {
        volume >>= 22;
        channel->volume = volume;
        volume *= 5;
        volume >>= 7;
        if (volume > 4)
            volume = 4;
        return volume;
    }
    volume >>= 15;
    channel->volume = volume;
    volume *= channel->envelope.volume;
    volume >>= 25;
    if (volume & ~15)
        volume = 15;
    channel->volume = (channel->volume * channel->envelope.target_volume) >> 25;
    if (channel->volume & ~15)
        channel->volume = 15;
    target = channel->volume;
    if (target == volume) {
        period = 0;
    } else {
        period = channel->envelope.timer;
        period += 15;
        difference = target - volume;
        if (difference < 0)
            difference = -difference;
        period /= difference;
    }
    if (period == 0) {
        control = (u8)((volume << 4) | 8);
    } else {
        if (period & 0xFFF8)
            period = 7;
        control = (u8)((volume << 4) | period);
        if (volume < target)
            control |= 8;
    }
    return control;
}

/* Original address: 0x020274D0 */
u32 Sound_UpdateChannelPitch(SoundChannel *channel) {
    u32 pitch = channel->base_pitch;
    SoundTrack *track = channel->track;
    SoundPitchSlide *slide = &channel->slide;
    SoundVibrato *vibrato;
    s32 depth;
    if (slide->delay != 0) {
        slide->delay--;
    } else if (slide->timer != 0) {
        slide->offset += slide->step;
        if (--slide->timer == 0)
            slide->offset = slide->target;
    }
    pitch += slide->offset;
    if (track->pitch_bend != 0) {
        s32 bend = sPcmPitchTable[track->pitch_bend_range + 48];
        bend -= 0x8000;
        bend *= track->pitch_bend;
        bend += 0x400000;
        bend >>= 14;
        if (channel->type == 0) {
            pitch *= bend;
            pitch >>= 8;
        } else {
            pitch = 0x800 - pitch;
            pitch <<= 8;
            pitch /= (u32)bend;
            pitch = 0x800 - pitch;
        }
    }
    vibrato = &channel->vibrato;
    depth = vibrato->params->depth;
    if (depth != 0) {
        if (vibrato->delay == 0) {
            u8 wave = sSoundVibratoWave[vibrato->phase >> 1];
            if (channel->type == 0) {
                if ((s8)wave >= 0)
                    pitch += (depth * (pitch * (s8)wave)) >> 19;
                else {
                    pitch <<= 12;
                    pitch /= ((u32)(-(s8)wave * depth) >> 3) + 0x10000;
                    pitch <<= 4;
                }
            } else {
                u32 period;
                s32 amplitude = (s8)wave;
                if (amplitude >= 0)
                    period = ((0x800 - pitch) << 19) / (u32)(depth * amplitude + 0x80000);
                else {
                    u32 base_period = 0x800;
                    amplitude = -amplitude;
                    base_period -= pitch;
                    period = (base_period * (amplitude * depth + 0x80000)) >> 19;
                }
                pitch = 0x800;
                pitch -= period;
            }
            vibrato->phase += vibrato->params->speed;
            if ((vibrato->phase >> 1) > 255)
                vibrato->phase -= 512;
        } else {
            vibrato->delay--;
        }
    }
    return pitch;
}

/* Original address: 0x02027610 */
void Sound_UpdatePcmChannels(void) {
    SoundChannel *channel = gSoundChannelLists.active_head.next;
    s32 zero = 0;
    s32 i;
    SoundChannel *expired;
    CpuFastSet(&zero, &gPcmMixBuffer, 0x010000B0);
    while (channel != &gSoundChannelLists.active_tail) {
        u32 volume = Sound_UpdatePcmChannelVolume(channel);
        u32 pitch;
        u8 pan;
        if (channel->state == 1) {
            SoundTrack *track;
            channel->gate_timer--;
            track = channel->track;
            pan = channel->fixed_pan ? channel->pan : track->pan;
            pitch = Sound_UpdateChannelPitch(channel);
            channel->pitch = pitch;
            channel->unk_1A = track->unk_4C;
        } else {
            if (volume == 0) {
                channel = channel->next;
                Sound_StopChannel(channel->prev);
                continue;
            }
            pan = channel->pan;
            pitch = channel->pitch;
        }
        pitch >>= 2;
        pitch *= channel->sample->frequency;
        pitch /= 10512;
        pitch *= 176;
        pitch /= 176;
        pitch >>= 5;
        if (Sound_MixPcmChannel(channel, volume, pitch, pan) == 1) {
            channel = channel->next;
            Sound_StopChannel(channel->prev);
        } else {
            channel = channel->next;
        }
    }
    for (i = 0; i < 7; i++) {
        expired = &gPcmChannels[i];
        if (expired->state == 1 && expired->gate_timer == 0)
            Sound_ReleaseChannel(expired);
    }
    gPcmOutputMixer(gPcmMixBuffer.words, gPcmOutputBuffers[gPcmOutputBufferIndex], gPcmMixBuffer.words + 176);
}

/* Original address: 0x02027728 */
void Sound_UpdatePsgChannels(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        SoundChannel *channel = &gPsgChannels[i];
        u32 pitch;
        u8 pan;
        u8 envelope;
        u8 sound_index;
        u32 stereo_mask;
        u8 clear_mask;
        u8 duty;
        vu8 *routing;
        vu8 *duty_register;
        if (channel->state == 1 && channel->gate_timer == 0)
            Sound_ReleaseChannel(channel);
        if (channel->state == 0)
            continue;
        if (channel->state == 1) {
            pitch = Sound_UpdateChannelPitch(channel);
            channel->pitch = pitch;
            pan = channel->fixed_pan ? channel->pan : channel->track->pan;
        } else {
            pitch = channel->pitch;
            pan = channel->pan;
        }
        envelope = Sound_GetPsgEnvelopeControl(channel, pan != 64);
        routing = (vu8 *)REG_ADDR_NR51;
        sound_index = channel->type - 1;
        stereo_mask = 0x11 << sound_index;
        clear_mask = ~stereo_mask;
        if (pan == 64)
            *routing = (clear_mask & *routing) | stereo_mask;
        else if (pan < 64)
            *routing = (clear_mask & *routing) | (0x10 << sound_index);
        else
            *routing = (clear_mask & *routing) | (1 << sound_index);

        if (channel->state == 1) {
            if (channel->age == 0) {
                Sound_StartPsgChannel(channel, envelope);
                channel->age = 1;
                channel->gate_timer--;
                continue;
            }
            channel->age++;
            channel->gate_timer--;
        } else if (channel->type == 3) {
            u32 volume;
            u8 wave_volume;
            channel->volume = (channel->volume * (channel->release + 230)) >> 9;
            volume = channel->volume;
            if (pan != 64)
                volume *= 2;
            volume *= 5;
            volume >>= 7;
            if (volume != 0) {
                if (volume > 4)
                    volume = 4;
                wave_volume = volume;
                REG_NR32 = sPsgWaveVolume[wave_volume];
            } else {
                Sound_StopChannel(channel);
            }
            continue;
        }

        if (channel->instrument->flags & 1) {
            SoundDutySequence *sequence = channel->psg.sequence;
            u16 length = sequence->length;
            u32 age = channel->age;
            if (age < length)
                duty = sequence->values[age];
            else
                duty = sequence->values[length - 1];
        } else {
            duty = 0xFF;
        }
        switch (channel->type) {
        case 1:
            if (envelope != 8) {
                REG_NR12 = envelope;
                REG_SOUND1CNT_X = pitch | 0x8000;
            } else if (((SoundSquareInstrument *)channel->instrument)->sweep == 8) {
                REG_SOUND1CNT_X = pitch;
            }
            duty_register = (vu8 *)REG_ADDR_NR11;
            *duty_register &= 0xC0;
            if (duty != 0xFF)
                *duty_register = duty << 6;
            break;
        case 2:
            if (envelope != 8) {
                REG_NR22 = envelope;
                REG_SOUND2CNT_H = pitch | 0x8000;
            } else {
                REG_SOUND2CNT_H = pitch;
            }
            duty_register = (vu8 *)REG_ADDR_NR21;
            *duty_register &= 0xC0;
            if (duty != 0xFF)
                *duty_register = duty << 6;
            break;
        case 3:
            REG_SOUND3CNT_X = (REG_SOUND3CNT_X & 0x4000) | pitch;
            if (envelope != 8)
                REG_NR32 = sPsgWaveVolume[envelope];
            break;
        case 4:
            if (envelope != 8) {
                REG_NR42 = envelope;
                REG_NR44 = 0x80;
            }
            if (duty != 0xFF) {
                vu8 *noise_register = (vu8 *)REG_ADDR_NR43;
                u8 noise = Sound_NoteToNoiseControl(pitch);
                if (duty != 0)
                    noise |= 8;
                *noise_register = noise;
            } else {
                REG_NR43 = Sound_NoteToNoiseControl(pitch) | (REG_NR43 & 8);
            }
            break;
        }
    }
}

/* Original address: 0x020279BC */
void Sound_PlayNote(SoundTrack *track, u8 key, u8 velocity, u16 duration) {
    SoundInstrumentResult result;
    SoundPlayer *player = track->player;
    SoundInstrument *instrument;
    SoundChannel *channel;
    if (track->muted)
        return;
    key += track->transpose;
    Sound_ResolveInstrument(track, key, &result);
    instrument = result.instrument;
    if (instrument->flags & 0x10)
        duration = (u32)duration / player->timing.values.tempo;
    else
        duration = duration / (player->timing.values.tempo_adjust + player->timing.values.tempo);
    if (track->tie && track->channel != NULL) {
        channel = track->channel;
    } else {
        channel = Sound_AllocateChannel(sSoundInstrumentChannelTypes[instrument->type], track, track->priority);
        if (channel == NULL)
            return;
        Sound_AttachChannelToTrack(track, channel);
        channel->age = 0;
        channel->vibrato.params = &track->vibrato;
        channel->vibrato.phase = 0;
        channel->vibrato.delay = track->vibrato.delay;
        channel->envelope.points = result.envelope;
        channel->envelope.volume = 0;
        channel->envelope.target_volume = 0;
        channel->envelope.timer = 0;
        channel->envelope.index = -1;
        channel->release = instrument->release;
        channel->instrument = instrument;
    }
    channel->fixed_pan = result.fixed_pan;
    if (channel->fixed_pan) {
        key = 48;
        channel->pan = result.pan;
    } else if (result.fixed_pitch) {
        key = 48;
    }
    channel->velocity = velocity;
    channel->volume = 0;
    channel->gate_timer = duration;
    channel->unk_1A = track->unk_4C;
    channel->base_pitch = Sound_NoteToPitch(channel, key, instrument->root_key);
    channel->slide.params = &track->slide;
    if (track->slide.enabled) {
        s32 pitch = Sound_NoteToPitch(channel, track->slide.key, instrument->root_key);
        channel->slide.delay = track->slide.delay;
        channel->slide.timer = ((u32)track->slide.duration * duration) >> 8;
        if (track->slide.flags & 2) {
            channel->slide.target = pitch - channel->base_pitch;
        } else {
            channel->slide.target = channel->base_pitch - pitch;
            channel->base_pitch = pitch;
        }
        channel->slide.step = channel->slide.target;
        channel->slide.step /= channel->slide.timer;
        if ((u8)(track->slide.flags & 4))
            track->slide.key = key;
        else
            track->slide.enabled = 0;
        channel->slide.offset = 0;
    } else {
        channel->slide.delay = 0;
        channel->slide.timer = 0;
        channel->slide.offset = 0;
        channel->slide.target = 0;
        channel->slide.step = 0;
    }
    if (channel->type == 0) {
        channel->sample = (SoundSample *)((u8 *)track->sample_offsets + track->sample_offsets[instrument->sample]);
    } else if (channel->type != 3) {
        if (instrument->flags & 1)
            channel->psg.sequence = result.duty_sequence;
        else
            channel->psg.duty = instrument->sample;
    } else {
        channel->psg.wave = result.wave;
    }
    if (duration == 0)
        Sound_ReleaseChannel(channel);
}

/* Original address: 0x02027B94 */
void Sound_ReleaseChannel(SoundChannel *channel) {
    if (channel->state == 1 && channel->track->tie == 0) {
        if (channel->type == 0) {
            Sound_UnlinkChannel(channel);
            channel->state = 2;
            Sound_InsertPcmChannelByPriority(channel);
        } else {
            u16 pitch = channel->pitch;
            u32 release = channel->release;
            if (channel->type == 3) {
                channel->state = 2;
            } else {
                u8 envelope;
                release >>= 5;
                if (release == 0)
                    envelope = 0;
                else
                    envelope = release | (channel->volume << 4);
                switch (channel->type) {
                case 1:
                    REG_NR12 = envelope;
                    REG_SOUND1CNT_X = pitch | 0x8000;
                    REG_NR11 &= 0xC0;
                    break;
                case 2:
                    REG_NR22 = envelope;
                    REG_SOUND2CNT_H = pitch | 0x8000;
                    REG_NR21 &= 0xC0;
                    break;
                case 4:
                    REG_NR42 = envelope;
                    REG_NR44 = 0x80;
                    break;
                }
                channel->state = 0;
            }
        }
        if (channel->fixed_pan == 0)
            channel->pan = channel->track->pan;
        Sound_DetachChannelFromTrack(channel->track, channel);
    }
}

/* Original address: 0x02027C78 */
void Sound_StopChannel(SoundChannel *channel) {
    if (channel->state != 0) {
        switch (channel->type) {
        case 0:
            Sound_UnlinkChannel(channel);
            channel->next = gSoundChannelLists.free_head.next;
            channel->prev = &gSoundChannelLists.free_head;
            gSoundChannelLists.free_head.next->prev = channel;
            gSoundChannelLists.free_head.next = channel;
            break;
        case 1:
            REG_NR12 = 8;
            REG_NR14 = 0xC0;
            break;
        case 2:
            REG_NR22 = 8;
            REG_NR24 = 0xC0;
            break;
        case 3:
            REG_NR30 = 0;
            break;
        case 4:
            REG_NR42 = 8;
            REG_NR44 = 0xC0;
            break;
        }
        Sound_DetachChannelFromTrack(channel->track, channel);
        channel->state = 0;
    }
}

/* Original address: 0x02027D14 */
void Sound_StartPsgChannel(SoundChannel *channel, u8 envelope) {
    u8 duty;
    u8 noise;
    switch (channel->type) {
    case 1:
        REG_NR10 = ((SoundSquareInstrument *)channel->instrument)->sweep;
        REG_SOUND1CNT_X = channel->base_pitch | 0x8000;
        REG_NR12 = envelope;
        if (channel->instrument->flags & 1)
            REG_NR11 = channel->psg.sequence->values[0] << 6;
        else
            REG_NR11 = channel->psg.duty << 6;
        REG_SOUND1CNT_X = channel->base_pitch | 0x8000;
        break;
    case 2:
        REG_NR22 = envelope;
        REG_SOUND2CNT_H = channel->base_pitch | 0x8000;
        REG_NR21 = channel->psg.duty << 6;
        break;
    case 3:
        if (channel->psg.wave != gSoundChannelLists.wave) {
            REG_NR30 = 0;
            CpuSet(channel->psg.wave, (void *)REG_ADDR_WAVE_RAM0, 8);
            gSoundChannelLists.wave = (void *)channel->psg.wave;
        }
        REG_NR30 = 0xC0;
        REG_SOUND3CNT_X = channel->base_pitch | 0x8000;
        REG_NR32 = sPsgWaveVolume[envelope];
        REG_NR31 = 0;
        break;
    case 4:
        REG_NR42 = envelope;
        if (channel->instrument->flags & 1) {
            noise = Sound_NoteToNoiseControl(channel->base_pitch);
            duty = channel->psg.sequence->values[0];
        } else {
            noise = Sound_NoteToNoiseControl(channel->base_pitch);
            duty = channel->psg.duty;
        }
        if (duty != 0)
            noise |= 8;
        REG_NR43 = noise;
        REG_NR44 = 0x80;
        REG_NR41 = 0;
        break;
    }
}

/* Original address: 0x02027E74 */
SoundChannel *Sound_AllocateChannel(u8 type, SoundTrack *track, u8 priority) {
    SoundChannel *channel;
    if (type == 0) {
        SoundChannel *next = gSoundChannelLists.free_head.next;
        if (next != &gSoundChannelLists.free_tail) {
            channel = next;
        } else {
            SoundChannel *active = gSoundChannelLists.active_head.next;
            if (active == &gSoundChannelLists.active_tail ||
                (active->state == 1 && priority < active->priority))
                return NULL;
            channel = active;
            Sound_StopChannel(channel);
        }
        Sound_UnlinkChannel(channel);
        channel->state = 1;
        channel->priority = priority;
        Sound_InsertPcmChannelByPriority(channel);
    } else {
        channel = &gPsgChannels[type - 1];
        if (channel->state == 1 && priority < channel->priority)
            return NULL;
        if (channel->state != 0)
            Sound_StopChannel(channel);
        channel->state = 1;
        channel->priority = priority;
    }
    return channel;
}

/* Original address: 0x02027F0C */
u8 Sound_MixPcmChannel(SoundChannel *channel, u32 volume, u32 pitch, u8 pan) {
    s32 position = channel->age;
    u32 gain = (u16)volume;
    s32 reached_end = 0;
    s32 remaining = 176;
    s16 *left;
    s16 *right;
    u32 left_gain;
    const s8 *samples = (const s8 *)(channel->sample + 1);
    u32 end;
    s16 *stop;

    left = gPcmMixBuffer.samples;
    right = left + 176;
    left_gain = (u16)((127 - pan) * gain) >> 7;
    gain = (u16)(pan * gain) >> 7;
    end = channel->sample->loop_end;
    if (end == 0)
        end = channel->sample->length;
    if ((position + pitch * remaining) >> 8 < end) {
        stop = right;
    } else {
        u32 count = (end << 8) - position - 1;
        count = (count + pitch) / pitch;
        stop = left + count;
        reached_end = 1;
    }

    if (channel->sample->loop_end == 0 || reached_end == 0) {
        position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
        if (reached_end)
            return 1;
    } else {
        s32 loop_length = channel->sample->loop_end - channel->sample->loop_start;
        loop_length <<= 8;
        position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
        position -= loop_length;
        remaining -= stop - left;
        while (remaining != 0) {
            left = stop;
            right = left + 176;
            if ((position + pitch * remaining) >> 8 < end) {
                stop += remaining;
                reached_end = 0;
            } else {
                u32 count = (end << 8) - position - 1;
                count = (count + pitch) / pitch;
                stop += count;
                reached_end = 1;
            }
            position = gPcmChannelMixer(samples, left, right, stop, position, pitch, left_gain, gain);
            if (reached_end)
                position -= loop_length;
            remaining -= stop - left;
        }
    }
    channel->age = position;
    return 0;
}

/* Original address: 0x02028098 */
void Sound_InitKeySampleInstrument(void) {
    sSoundKeySampleInstrument.type = 0;
    sSoundKeySampleInstrument.flags = 0;
    sSoundKeySampleInstrument.sample = 0;
    sSoundKeySampleInstrument.envelope = 0;
    sSoundKeySampleInstrument.release = 0;
    sSoundKeySampleInstrument.root_key = 48;
}

/* Original address: 0x020280B4 */
void Sound_ResolveInstrument(SoundTrack *track, u8 key, SoundInstrumentResult *result) {
    const SoundBank *sound_bank = gSoundBank;
    u32 bank_index = track->player->bank[track->bank];
    const u32 *offsets = sound_bank->instrument_offsets;
    const u8 *bank = (const u8 *)offsets + offsets[bank_index];
    const u16 *program = (const u16 *)bank + track->program;
    SoundInstrument *instrument = (SoundInstrument *)(bank + *program);
    SoundInstrument *resolved;

    result->fixed_pan = 0;
    result->fixed_pitch = 0;
    if (instrument->type & 0xF0) {
        if (instrument->type == 0x10) {
            const SoundKeyInstrument *keys = (const SoundKeyInstrument *)(bank + instrument->sample);
            u8 index = key - ((SoundInstrumentMap *)instrument)->first_key;
            result->fixed_pan = 1;
            result->pan = keys[index].pan;
            result->instrument = (SoundInstrument *)(bank + keys[index].instrument);
            result->envelope = (const SoundEnvelopePoint *)(bank + result->instrument->envelope);
        } else if (instrument->type == 0x11) {
            const u16 *samples = (const u16 *)(bank + instrument->sample);
            sSoundKeySampleInstrument.sample = samples[key];
            result->instrument = &sSoundKeySampleInstrument;
            result->envelope = sSoundKeySampleEnvelope;
            result->fixed_pitch = 1;
        } else if (instrument->type == 0x12) {
            const SoundInstrumentSplit *split = (const SoundInstrumentSplit *)(bank + instrument->sample);
            while (key > split->last_key)
                split++;
            result->instrument = (SoundInstrument *)(bank + split->instrument);
            result->envelope = (const SoundEnvelopePoint *)(bank + result->instrument->envelope);
        }
    } else {
        result->instrument = instrument;
        result->envelope = (const SoundEnvelopePoint *)(bank + instrument->envelope);
    }
    resolved = result->instrument;
    if (resolved->type == 3)
        result->wave = (const u16 *)(bank + instrument->sample);
    if (resolved->flags & 1)
        result->duty_sequence = (SoundDutySequence *)(bank + resolved->sample);
}

/* Original address: 0x02028190 */
void Sound_InitPlayers(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 8; i++) {
        SoundPlayer *player = &gSoundPlayers[i];
        player->status = 0;
        for (j = 0; j < 10; j++) {
            player->tracks[j] = NULL;
        }
    }
}

/* Original address: 0x020281C4 */
void Sound_ResetPlayerParameters(SoundPlayer *player) {
    player->control.bits.paused = 0;
    player->timing.values.tempo = 150;
    player->timing.values.tempo_adjust = 0;
    player->master_volume = 128;
    player->volume = 0x8000;
    player->volume_step = 0;
    player->fade_timer = 0;
    player->target_volume = 0;
    player->tempo_mode = 0;
}

/* Original address: 0x020281FC */
void Sound_UpdatePlayers(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        SoundPlayer *player = &gSoundPlayers[i];

        if (player->status != 0) {
            if (player->fade_timer == 0 && player->status == 2) {
                Sound_StopPlayer(i);
            } else {
                s32 active;
                SoundTrack **track;
                s32 j;

                if (player->fade_timer != 0) {
                    player->volume += player->volume_step;
                    if (--player->fade_timer == 0)
                        player->volume = player->target_volume;
                }
                active = 0;
                track = player->tracks;
                for (j = 0; j < 10; j++) {
                    if (player->tracks[j] != NULL) {
                        if ((u8)Sound_UpdateTrack(player->tracks[j]) == 0) {
                            active = 1;
                        } else {
                            player->tracks[j] = NULL;
                        }
                    }
                }

                if (!active) {
                    Sound_StopPlayer(i);
                }
            }
        }
    }
}
/* Original address: 0x0202828C */
void Sound_StartMusic(s32 player, u32 music) {
    const SoundBank *bank = gSoundBank;
    const u32 *sequences = bank->music_sequence_offsets;
    const u8 *sequence = (const u8 *)sequences + sequences[music];
    const u32 *banks = bank->music_bank_offsets;

    Sound_StartMusicSequence(player, sequence, (const u16 *)((const u8 *)banks + banks[music]));
}
/* Original address: 0x020282B4 */
void Sound_StartEffect(s32 player, u32 group, u32 effect) {
    const SoundBank *bank = gSoundBank;
    const u32 *sequences = bank->effect_sequence_offsets;
    const u8 *sequence = (const u8 *)sequences + sequences[group];
    const u32 *banks = bank->effect_bank_offsets;

    Sound_StartEffectSequence(player, sequence, (const u16 *)((const u8 *)banks + banks[group]), effect);
}

/* Original address: 0x020282E0 */
void Sound_StartMusicSequence(s32 index, const u8 *sequence, const u16 *bank) {
    SoundPlayer *player = &gSoundPlayers[index];
    const SoundMusicSequence *header;
    const u16 *offsets;
    const u16 *offset;
    s32 count;
    s32 i;

    if (player->status != 0)
        Sound_StopPlayer(index);
    player->sequence = sequence;
    player->bank = bank;
    player->is_sound_effect = 0;
    Sound_ResetPlayerParameters(player);
    header = (const SoundMusicSequence *)player->sequence;
    count = header->track_count;
    offsets = header->track_offsets;
    i = 0;
    if (i < count) {
        offset = offsets;
        do {
            if (*offset != 0) {
                SoundTrack *track = Sound_FindFreeTrack();
                player->tracks[i] = track;
                Sound_StartTrack(track, player, (void *)(player->sequence + *offset));
            }
            offset++;
            i++;
        } while (i < count);
    }
    player->status = 1;
}

/* Original address: 0x02028368 */
void Sound_StartEffectSequence(s32 index, const u8 *sequence, const u16 *bank, u32 effect) {
    SoundPlayer *player = &gSoundPlayers[index];
    SoundTrack *track;

    if (player->status != 0)
        Sound_StopPlayer(index);
    player->sequence = sequence;
    player->bank = bank;
    player->is_sound_effect = 1;
    Sound_ResetPlayerParameters(player);
    track = Sound_FindFreeTrack();
    player->tracks[0] = track;
    Sound_StartTrack(track, player, (void *)(player->sequence + ((const u16 *)player->sequence)[effect]));
    player->status = 1;
}

/* Original address: 0x020283D4 */
void Sound_StopPlayer(s32 index) {
    SoundPlayer *player = &gSoundPlayers[index];
    s32 i;

    if (player->status != 0) {
        for (i = 0; i < 10; i++) {
            Sound_StopTrack(player->tracks[i]);
            player->tracks[i] = NULL;
        }
        player->status = 0;
    }
}

/* Original address: 0x02028410 */
void Sound_FadeOutPlayer(s32 index, s32 frames) {
    SoundPlayer *player = &gSoundPlayers[index];

    if (player->status != 0) {
        player->status = 2;
        player->target_volume = 0;
        player->fade_timer = frames;
        player->volume_step = -player->volume / frames;
    }
}

/* Original address: 0x02028448 */
void Sound_SetPlayerPaused(s32 index, u8 paused) {
    SoundPlayer *players = gSoundPlayers;

    players[index].control.bits.paused = paused;
}

/* Original address: 0x0202846C */
u32 Sound_GetPlayerStatus(s32 index) {
    return gSoundPlayers[index].status;
}

static inline void Sound_ClearTrackOwners(SoundTrack *tracks) {
    u8 zero = 0;
    u8 *owner = (u8 *)&tracks->player;
    s32 i;

    for (i = 15; i >= 0; i--) {
        owner[0] = zero;
        owner[1] = zero;
        owner[2] = zero;
        owner[3] = zero;
        owner += sizeof(SoundTrack);
    }
}

/* Original address: 0x02028480 */
void Sound_InitTracks(void) {
    Sound_ClearTrackOwners(gSoundTracks);
}

static inline SoundTrack *Sound_FindFreeTrackInPool(SoundTrack *track, SoundTrack *last) {
    do {
        if (track->player == NULL)
            return track;
        track++;
    } while ((s32)track <= (s32)last);
    return NULL;
}

/* Original address: 0x020284A0 */
SoundTrack *Sound_FindFreeTrack(void) {
    return Sound_FindFreeTrackInPool(gSoundTracks, &gSoundTracks[15]);
}

/* Original address: 0x020284C4 */
void Sound_StartTrack(SoundTrack *track, SoundPlayer *player, const u8 *sequence) {
    if (track != NULL) {
        if (track->player != NULL)
            Sound_StopTrack(track);
        track->tick_accumulator = 0;
        track->tie = 0;
        track->muted = 0;
        track->sequence = sequence;
        track->player = player;
        track->channel = NULL;
        Sound_SetTrackBank(track, 0);
        track->pan = 64;
        track->vibrato.delay = 0;
        track->vibrato.speed = 34;
        track->vibrato.depth = 0;
        track->slide.enabled = 0;
        track->slide.flags = 0;
        track->slide.key = 0;
        track->slide.delay = 0;
        track->slide.duration = 0;
        track->volume = 128;
        track->expression = 128;
        track->pitch_bend = 0;
        track->pitch_bend_range = 2;
        track->transpose = 0;
        if (player->is_sound_effect == 1) {
            track->priority = 12;
            track->unk_4C = 127;
            track->unk_53 = 1;
        } else {
            track->priority = 3;
            track->unk_4C = 0;
            track->unk_53 = 0;
        }
        track->note_duration = 127;
        track->velocity = 127;
        track->rest_duration = 0;
        track->stack_pointer = track->return_stack;
    }
}

/* Original address: 0x02028580 */
void Sound_ReleaseTrackChannels(SoundTrack *track) {
    u8 tie;
    SoundChannel *next;
    SoundChannel *channel;

    if (track != NULL) {
        tie = track->tie;
        track->tie = 0;
        channel = track->channel;
        while (channel != NULL) {
            next = channel->track_next;
            Sound_ReleaseChannel(channel);
            channel = next;
        }
        track->tie = tie;
    }
}

/* Original address: 0x020285B0 */
void Sound_StopTrack(SoundTrack *track) {
    if (track != NULL) {
        Sound_ReleaseTrackChannels(track);
        track->player = NULL;
    }
}


/* Original address: 0x03000270 */
extern SoundNoteCallback gSoundNoteCallback;
/* Original address: 0x03000274 */
extern SoundControlCallback gSoundControlCallback;

/* Original address: 0x020285C8 */
s32 Sound_UpdateTrack(SoundTrack *track) {
    SoundPlayer *player;
    u8 command;
    u32 duration;
    u8 velocity;
    u16 offset;

    if (track == NULL || track->player == NULL)
        return 1;
    player = track->player;
    if (player->control.flags & 1) {
        Sound_ReleaseTrackChannels(track);
    } else {
        while (track->tick_accumulator <= 0) {
            command = *track->sequence++;
            if (command <= SOUND_SEQUENCE_NOTE_WITH_PARAMS_MAX) {
                if (command <= SOUND_SEQUENCE_NOTE_WITH_PREVIOUS_PARAMS_MAX) {
                    duration = track->note_duration;
                    velocity = track->velocity;
                } else {
                    duration = Sound_ReadSequenceDuration(track);
                    track->note_duration = duration;
                    velocity = *track->sequence++;
                    track->velocity = velocity;
                    command -= SOUND_SEQUENCE_NOTE_WITH_PARAMS_MIN;
                }
                duration *= 150;
                if (gSoundNoteCallback != NULL && (player->tempo_mode & 1))
                    gSoundNoteCallback(track, command, velocity, duration);
                else
                    Sound_PlayNote(track, command, velocity, duration);
                if (track->unk_53 == 1)
                    track->tick_accumulator += duration;
            } else if (command == SOUND_SEQUENCE_REST_WITH_PREVIOUS_DURATION) {
                duration = track->rest_duration;
                duration *= 150;
                track->tick_accumulator += duration;
            } else if (command == SOUND_SEQUENCE_REST) {
                duration = Sound_ReadSequenceDuration(track);
                track->rest_duration = duration;
                duration *= 150;
                track->tick_accumulator += duration;
            } else if ((command & SOUND_SEQUENCE_COMMAND_GROUP_MASK) == SOUND_SEQUENCE_SLIDE) {
                track->slide.flags = command & SOUND_SEQUENCE_COMMAND_ARGUMENT_MASK;
                track->slide.key = *track->sequence + track->transpose;
                track->sequence++;
                track->slide.duration = *track->sequence++;
                if (track->slide.flags & 1) {
                    track->slide.delay = *track->sequence++;
                } else {
                    track->slide.delay = 0;
                }
                track->slide.enabled = 1;
            } else {
                switch (command) {
                case SOUND_SEQUENCE_RETURN_OR_END: /* Return from a pattern, or end the track. */
                    if (track->stack_pointer == track->return_stack) {
                        Sound_StopTrack(track);
                        return 2;
                    }
                    track->sequence = *--track->stack_pointer;
                    break;
                case SOUND_SEQUENCE_SLIDE_OFF:
                    track->slide.enabled = 0;
                    break;
                case SOUND_SEQUENCE_JUMP: /* Jump to an offset in the player's sequence. */
                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    track->sequence = player->sequence;
                    track->sequence += offset;
                    break;
                case SOUND_SEQUENCE_CALL: /* Call a pattern. */
                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    *track->stack_pointer++ = track->sequence;
                    track->sequence = player->sequence;
                    track->sequence += offset;
                    break;
                case SOUND_SEQUENCE_SET_PROGRAM:
                    track->program = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_INSTRUMENT_BANK:
                    Sound_SetTrackBank(track, *track->sequence++);
                    break;
                case SOUND_SEQUENCE_SET_PAN:
                    track->pan = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_PRIORITY:
                    track->priority = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_VOLUME:
                    track->volume = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_PITCH_BEND:
                    track->pitch_bend = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_PITCH_BEND_RANGE:
                    track->pitch_bend_range = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_TRANSPOSITION:
                    track->transpose = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_REVERB_VOLUME:
                    track->unk_4C = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_TIE_ON:
                case SOUND_SEQUENCE_TIE_OFF:
                    Sound_ReleaseTrackChannels(track);
                    track->tie = command == SOUND_SEQUENCE_TIE_ON;
                    break;
                case SOUND_SEQUENCE_NOTE_WAIT_ON:
                    track->unk_53 = 1;
                    break;
                case SOUND_SEQUENCE_NOTE_WAIT_OFF:
                    track->unk_53 = 0;
                    break;
                case SOUND_SEQUENCE_CONTROL_CALLBACK:
                    if (gSoundControlCallback != NULL)
                        gSoundControlCallback(track, *track->sequence++);
                    else
                        track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_TEMPO:
                    player->timing.values.tempo = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_VIBRATO_DELAY:
                    track->vibrato.delay = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_VIBRATO_DEPTH:
                    track->vibrato.depth = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_SET_VIBRATO_SPEED:
                    track->vibrato.speed = *track->sequence++;
                    break;
                case SOUND_SEQUENCE_START_TRACK: { /* Start another track with the current instrument settings. */
                    u8 index = *track->sequence++;
                    SoundTrack *child;

                    ((u8 *)&offset)[0] = *track->sequence++;
                    ((u8 *)&offset)[1] = *track->sequence++;
                    if (player->tracks[index] == NULL) {
                        child = Sound_FindFreeTrack();
                        player->tracks[index] = child;
                    } else {
                        child = player->tracks[index];
                        Sound_StopTrack(child);
                    }
                    Sound_StartTrack(child, player, player->sequence + offset);
                    child->sample_offsets = track->sample_offsets;
                    child->bank = track->bank;
                    child->program = track->program;
                    child->pan = track->pan;
                    child->unk_4C = track->unk_4C;
                    child->volume = track->volume;
                    child->expression = track->expression;
                    child->priority = track->priority;
                    child->pitch_bend = track->pitch_bend;
                    child->pitch_bend_range = track->pitch_bend_range;
                    child->transpose = track->transpose;
                    break;
                }
                }
            }
        }
        track->tick_accumulator -= player->timing.values.tempo;
        track->tick_accumulator -= player->timing.values.tempo_adjust;
    }
    return 0;
}

/* Original address: 0x02028A34 */
void Sound_AttachChannelToTrack(SoundTrack *track, SoundChannel *channel) {
    if (channel->track == NULL) {
        SoundChannel *next;

        channel->track = track;
        channel->track_prev = NULL;
        next = track->channel;
        channel->track_next = next;
        track->channel = channel;
        if (next != NULL)
            next->track_prev = channel;
    }
}

/* Original address: 0x02028A4C */
void Sound_DetachChannelFromTrack(SoundTrack *track, SoundChannel *channel) {
    if (channel->track != NULL) {
        channel->track = NULL;
        if (channel->track_next != NULL)
            channel->track_next->track_prev = channel->track_prev;
        if (channel->track_prev != NULL)
            channel->track_prev->track_next = channel->track_next;
        else
            track->channel = channel->track_next;
    }
}

/* Original address: 0x02028A74 */
u16 Sound_ReadSequenceDuration(SoundTrack *track) {
    u32 duration = *track->sequence++;

    if (duration & 0x80)
        duration = ((duration & 0x7F) << 8) | *track->sequence++;
    return duration;
}

/* Original address: 0x02028A98 */
void Sound_SetTrackBank(SoundTrack *track, u32 bank) {
    const SoundBank *sound_bank;
    u32 sample;
    const u32 *offsets;

    track->bank = bank;
    track->program = 0;
    sound_bank = gSoundBank;
    sample = sound_bank->sample_indices[track->player->bank[bank]];
    offsets = sound_bank->sample_offsets;
    track->sample_offsets = (const u32 *)((const u8 *)offsets + offsets[sample]);
}

/* Original address: 0x03000278 */
extern SoundCommand gSoundCommands[64];
/* Original address: 0x03000584 */
extern SoundCommand *gSoundCommandRead;
/* Original address: 0x03000588 */
extern SoundCommand *gSoundCommandWrite;
/* Original address: 0x0300058C */
extern SoundCommand *gSoundCommandCommitted;
/* Original address: 0x03000590 */
extern SoundCommand *gSoundCommandEnd;

/* Original address: 0x02028ACC */
void Sound_InitCommandQueue(void) {
    gSoundCommandRead = gSoundCommands;
    gSoundCommandWrite = gSoundCommands;
    gSoundCommandCommitted = gSoundCommands;
    gSoundCommandEnd = gSoundCommands + 64;
    gSoundNoteCallback = NULL;
    gSoundControlCallback = NULL;
}

static inline void Sound_AdvanceCommandPointer(SoundCommand **cursor) {
    (*cursor)++;
    if (*cursor == gSoundCommandEnd) {
        *cursor = gSoundCommands;
    }
}

/* Original address: 0x02028B0C */
SoundCommand *Sound_ReadCommand(void) {
    SoundCommand *command = gSoundCommandRead;

    if (command == gSoundCommandCommitted) {
        return NULL;
    } else {
        Sound_AdvanceCommandPointer(&gSoundCommandRead);
        return command;
    }
}

/* Original address: 0x02028B44 */
void Sound_CommitCommands(void) {
    gSoundCommandCommitted = gSoundCommandWrite;
}

/* Original address: 0x02028B58 */
void Sound_QueueStartMusic(u16 player, u16 music) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_START_MUSIC;
    command->arg0.value = player;
    command->arg1 = music;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028B90 */
void Sound_QueueStartEffect(u32 player, u16 group, u16 effect) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_START_EFFECT;
    command->arg0.value = (player << 16) | group;
    command->arg1 = effect;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028BCC */
void Sound_QueueFadeOutPlayer(u16 player, u16 frames) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_FADE_OUT_PLAYER;
    command->arg0.value = player;
    command->arg1 = frames;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C04 */
void Sound_QueueSetPlayerPaused(u16 player, u8 paused) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_PAUSED;
    command->arg0.value = player;
    command->arg1 = paused;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C3C */
void Sound_QueueSetPlayerTempoAdjust(u16 player, s16 adjustment) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST;
    command->arg0.value = player;
    command->arg1 = adjustment;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028C74 */
void Sound_QueueSetPlayerMasterVolume(u16 player, u8 volume) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME;
    command->arg0.value = player;
    command->arg1 = volume;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028CAC */
void Sound_QueueSetPlayerTempoMode(u16 player, u8 mode) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_PLAYER_TEMPO_MODE;
    command->arg0.value = player;
    command->arg1 = mode;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028CE4 */
void Sound_QueueSetTracksMuted(u32 player, u32 tracks, u8 muted) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_MUTED;
    command->arg0.value = (player << 16) | muted;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D1C */
void Sound_QueueSetTracksExpression(u32 player, u32 tracks, u8 expression) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_EXPRESSION;
    command->arg0.value = (player << 16) | expression;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D54 */
void Sound_QueueSetTracksPan(u32 player, u32 tracks, u8 pan) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_SET_TRACKS_PAN;
    command->arg0.value = (player << 16) | pan;
    command->arg1 = tracks;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028D8C */
void Sound_QueueCommand10(u8 value) {
    gSoundCommandWrite->type = SOUND_COMMAND_COMMAND_10;
    gSoundCommandWrite->arg0.value = value;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028DB8 */
void Sound_QueueCallback(void (*callback)(u32), u32 argument) {
    SoundCommand *command = gSoundCommandWrite;

    command->type = SOUND_COMMAND_CALLBACK;
    command->arg0.callback = callback;
    command->arg1 = argument;
    gSoundCommandWrite = command + 1;
    if (gSoundCommandWrite == gSoundCommandEnd) {
        gSoundCommandWrite = gSoundCommands;
    }
}

/* Original address: 0x02028DE8 */
void Sound_QueueSetControlCallback(SoundControlCallback callback) {
    gSoundCommandWrite->type = SOUND_COMMAND_SET_CONTROL_CALLBACK;
    gSoundCommandWrite->arg0.control_callback = callback;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028E10 */
void Sound_QueueSetNoteCallback(SoundNoteCallback callback) {
    gSoundCommandWrite->type = SOUND_COMMAND_SET_NOTE_CALLBACK;
    gSoundCommandWrite->arg0.note_callback = callback;
    Sound_AdvanceCommandPointer(&gSoundCommandWrite);
}

/* Original address: 0x02028E38 */
void Sound_ProcessCommands(void) {
    SoundCommand *command;

    while ((command = Sound_ReadCommand()) != NULL) {
        switch (command->type) {
        case SOUND_COMMAND_START_MUSIC:
            Sound_StartMusic(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_START_EFFECT:
            Sound_StartEffect(command->arg0.value >> 16, command->arg0.value & 0xFFFF, command->arg1);
            break;
        case SOUND_COMMAND_FADE_OUT_PLAYER:
            Sound_FadeOutPlayer(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_SET_PLAYER_PAUSED:
            Sound_SetPlayerPaused(command->arg0.value, command->arg1);
            break;
        case SOUND_COMMAND_SET_PLAYER_TEMPO_MODE: {
            SoundPlayer *players = gSoundPlayers;
            u32 player_offset = command->arg0.value * sizeof(*players);
            u8 *tempo_mode = &players->tempo_mode;

            tempo_mode[player_offset] = command->arg1;
            break;
        }
        case SOUND_COMMAND_SET_PLAYER_TEMPO_ADJUST: {
            SoundPlayer *players = gSoundPlayers;
            SoundPlayer *player = &players[command->arg0.value];
            u32 adjustment = command->arg1;

            player->timing.bytes.tempo_adjust[0] = adjustment;
            player->timing.bytes.tempo_adjust[1] = adjustment >> 8;
            break;
        }
        case SOUND_COMMAND_SET_PLAYER_MASTER_VOLUME: {
            SoundPlayer *players = gSoundPlayers;
            u32 player_offset = command->arg0.value * sizeof(*players);
            u8 *master_volume = &players->master_volume;

            master_volume[player_offset] = command->arg1;
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_MUTED: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                u32 track_mask = 1;
                track = player->tracks;
                do {
                    if ((command->arg1 & track_mask) && *track != NULL) {
                        (*track)->muted = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_EXPRESSION: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                u32 track_mask = 1;
                track = player->tracks;
                do {
                    if ((command->arg1 & track_mask) && *track != NULL) {
                        (*track)->expression = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_SET_TRACKS_PAN: {
            SoundPlayer *player = &gSoundPlayers[command->arg0.parts.player];
            SoundTrack **track;

            if (command->arg1 != 0) {
                u32 track_mask = 1;
                track = player->tracks;
                do {
                    if ((command->arg1 & track_mask) && *track != NULL) {
                        (*track)->pan = command->arg0.value;
                    }
                    track++;
                    command->arg1 >>= 1;
                } while (command->arg1 != 0);
            }
            break;
        }
        case SOUND_COMMAND_CALLBACK:
            command->arg0.callback(command->arg1);
            break;
        case SOUND_COMMAND_SET_CONTROL_CALLBACK:
            gSoundControlCallback = command->arg0.control_callback;
            break;
        case SOUND_COMMAND_SET_NOTE_CALLBACK:
            gSoundNoteCallback = command->arg0.note_callback;
            break;
        case SOUND_COMMAND_COMMAND_10:
            sub_02027370(command->arg0.value);
            break;
        }
    }
}

/* ARM-state mixer routines copied to IWRAM by SoundDriver_Init. */
asm(".include \"asm/all_arm.inc\"");
