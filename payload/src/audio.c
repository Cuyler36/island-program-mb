#include "audio.h"
#include "gba/macro.h"
#include "game.h"
#include "sound.h"
#include "global.h"

/* Original address: 0x02019D28 */
void GameAudio_VBlank(void) {
    SoundDriver_VBlank();
}

/* Original address: 0x02019D34 */
void GameAudio_Init(void) {
    Audio_Init();
}

/* Original address: 0x02019D40 */
void GameAudio_UpdateDriver(void) {
    SoundDriver_Update();
}

/* Original address: 0x02019D4C */
void GameAudio_Update(void) {
    Audio_Update();
}

/* Original address: 0x02019D58 */
void GameAudio_PlayEffect2(u16 value) {
    Sound_PlayEffect2(value);
}

/* Original address: 0x02019D68 */
void GameAudio_StopEffect2(u16 value) {
    Sound_StopEffect2(value);
}

/* Original address: 0x02019D78 */
void GameAudio_PlayEffect0(u16 value) {
    Sound_PlayEffect0(value);
}

/* Original address: 0x02019D88 */
void GameAudio_PlayMusic(u16 value) {
    Sound_PlayMusic(value);
}

/* Original address: 0x02019D98 */
void GameAudio_StopMusic(u16 value) {
    Sound_StopMusic(value);
}
