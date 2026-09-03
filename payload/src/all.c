#include "global.h"
#include <string.h>

void sub_0201A0D4();                                   /* extern */
void sub_02027040();                                   /* extern */

static int transfer_size;
static int sMsgDirtyTileOffset;
static int sMsgDirtyTileCount;
static int _03000018; // ??
static u8 sMsgPreviousTextRow;
static u8 sMsgPreviousTextX;

GameState gGameState;

void AgbMain(void) {
    sub_02019E88();
    transfer_size = sizeof(Island_agb_c);
    sub_0201A0D4();
}

void sub_02018228(void) {
    // nothing
}

static u8 gUnk3002410[0x400];

void sub_0201822C(void) {
    u8 temp_r5;
    u16 temp;

    sub_02019D28();
    if (gGameState.unk_85A == 1) {
        gGameState.unk_85A = 0;
        sub_02027040();
    }
    temp_r5 = gGameState.unk_85F;
    if (temp_r5 == 0) {
        CpuFastCopy(gUnk3002410, (void*)OAM, sizeof(gUnk3002410));
        REG_DISPCNT = gGameState.unk_82A;
        REG_BG0HOFS = gGameState.unk_83C;
        REG_BG0VOFS = gGameState.unk_83E;
        REG_BG1HOFS = gGameState.unk_840;
        REG_BG1VOFS = gGameState.unk_842;
        REG_BG2HOFS = gGameState.unk_844;
        REG_BG2VOFS = gGameState.unk_846;
        REG_BG3HOFS = gGameState.unk_848;
        REG_BG3VOFS = gGameState.bg3_vofs;
        REG_BLDALPHA = gGameState.unk_81C;
        REG_BLDY = gGameState.unk_81E;
        REG_BLDCNT = gGameState.unk_820;
        REG_BG0CNT = gGameState.unk_822;
        REG_BG1CNT = gGameState.unk_824;
        REG_BG2CNT = gGameState.unk_826;
        REG_BG3CNT = gGameState.unk_828;

        if (gGameState.unk_859 == 1) {
            gGameState.unk_859 = temp_r5;
        }

        gGameState.unk_85B++;
        gGameState.unk_85F = 1;
    }

    REG_IF = gGameState.unk_814 = 1;
    REG_DISPSTAT = 8;
    sub_02019D40();
}

void sub_02018364(void) {
    // nothing
}

void sub_02018368(void) {
    // nothing
}

static u8 sMsgGlyphWidths[256] = {
    0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x05, 0x06,
    0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x04, 0x04, 0x06, 0x06, 0x06, 0x08, 0x08, 0x03,
    0x05, 0x05, 0x08, 0x08, 0x03, 0x06, 0x03, 0x08,
    0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x03, 0x08, 0x06, 0x06, 0x06, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x04, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x06, 0x08, 0x06, 0x06, 0x07,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x06,
    0x06, 0x03, 0x04, 0x06, 0x03, 0x07, 0x06, 0x06,
    0x06, 0x06, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08,
    0x04, 0x05, 0x05, 0x06, 0x06, 0x04, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x06, 0x06,
    0x08, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03,
    0x06, 0x06, 0x06, 0x05, 0x07, 0x06, 0x06, 0x04,
    0x07, 0x06, 0x07, 0x06, 0x06, 0x07, 0x07, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x06, 0x06, 0x06, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x06, 0x07, 0x07, 0x07,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x06, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06,
    0x03, 0x07, 0x03, 0x05, 0x06, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
};

static u8 sFontCodeWidths[256] = {
    0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06,
    0x06, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x06, 0x07, 0x07, 0x07, 0x0B, 0x08, 0x04,
    0x06, 0x06, 0x0B, 0x0C, 0x04, 0x08, 0x04, 0x0C,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x04, 0x0B, 0x08, 0x09, 0x08, 0x08,
    0x0A, 0x09, 0x07, 0x08, 0x08, 0x07, 0x07, 0x08,
    0x08, 0x06, 0x06, 0x07, 0x07, 0x0A, 0x08, 0x09,
    0x07, 0x09, 0x07, 0x07, 0x07, 0x08, 0x08, 0x0A,
    0x07, 0x07, 0x06, 0x07, 0x0C, 0x07, 0x07, 0x09,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x05, 0x07,
    0x08, 0x05, 0x05, 0x06, 0x05, 0x09, 0x07, 0x07,
    0x07, 0x08, 0x06, 0x06, 0x08, 0x07, 0x06, 0x09,
    0x06, 0x06, 0x05, 0x07, 0x07, 0x07, 0x07, 0x0C,
    0x07, 0x06, 0x06, 0x06, 0x06, 0x04, 0x08, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x09, 0x07, 0x07,
    0x0C, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
    0x05, 0x07, 0x07, 0x08, 0x07, 0x06, 0x06, 0x06,
    0x09, 0x08, 0x0A, 0x09, 0x07, 0x0A, 0x0A, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x07, 0x07, 0x07, 0x0C,
    0x0B, 0x0B, 0x0B, 0x0C, 0x09, 0x0A, 0x0A, 0x0A,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x08, 0x08, 0x0C, 0x0B, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0B, 0x0C, 0x08,
    0x04, 0x09, 0x04, 0x06, 0x0A, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
};

static u8 sMsgFontGlyphs[16][2][16][8] = {
    {{{0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x02}, {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x08, 0x08}, {0x33, 0x33, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x0E, 0x1C, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x1C, 0x0E, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x1C, 0x36, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x1D, 0x36, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x01}, {0x0E, 0x1C, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x1F}, {0x1C, 0x0E, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x1F}, {0x1C, 0x36, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x1F}, {0x33, 0x33, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x1F}, {0x07, 0x0E, 0x00, 0x0E, 0x0E, 0x04, 0x04, 0x04}, {0x0E, 0x07, 0x00, 0x07, 0x07, 0x02, 0x02, 0x02}, {0x0E, 0x1B, 0x00, 0x0E, 0x0E, 0x04, 0x04, 0x04}}, {{0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00}, {0x0E, 0x07, 0x21, 0x31, 0x1F, 0x0E, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x01, 0x01, 0x21, 0x31, 0x1F, 0x0E, 0x04, 0x06}, {0x1F, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x00, 0x00}, {0x1F, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x00, 0x00}, {0x1F, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x00, 0x00}, {0x1F, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x0E, 0x0E, 0x00, 0x00}, {0x02, 0x02, 0x02, 0x02, 0x07, 0x07, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x0E, 0x0E, 0x00, 0x00}}},
    {{{0x1B, 0x1B, 0x00, 0x0E, 0x0E, 0x04, 0x04, 0x04}, {0x00, 0x00, 0x00, 0x0E, 0x1E, 0x32, 0x22, 0x27}, {0x1D, 0x36, 0x00, 0x21, 0x23, 0x23, 0x27, 0x25}, {0x0E, 0x1C, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x1C, 0x0E, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x1C, 0x36, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x1D, 0x36, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x33, 0x33, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x00, 0x00, 0x20, 0x3C, 0x1E, 0x33, 0x39, 0x29}, {0x0E, 0x1C, 0x00, 0x21, 0x21, 0x21, 0x21, 0x21}, {0x1C, 0x0E, 0x00, 0x21, 0x21, 0x21, 0x21, 0x21}, {0x1C, 0x36, 0x00, 0x21, 0x21, 0x21, 0x21, 0x21}, {0x33, 0x33, 0x00, 0x21, 0x21, 0x21, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x11, 0x11, 0x19}, {0x00, 0x00, 0x01, 0x01, 0x1F, 0x3F, 0x21, 0x21}, {0x00, 0x00, 0x0E, 0x1C, 0x00, 0x0E, 0x1E, 0x18}}, {{0x04, 0x04, 0x04, 0x04, 0x0E, 0x0E, 0x00, 0x00}, {0x27, 0x32, 0x12, 0x1A, 0x0E, 0x06, 0x00, 0x00}, {0x29, 0x39, 0x31, 0x31, 0x21, 0x21, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x2D, 0x25, 0x27, 0x33, 0x1E, 0x0F, 0x01, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x3D, 0x31, 0x21, 0x33, 0x1F, 0x0D, 0x01, 0x00}, {0x31, 0x1D, 0x0F, 0x03, 0x01, 0x01, 0x01, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x02}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x1B, 0x09, 0x00}, {0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x0E, 0x18}, {0x00, 0x00, 0x00, 0x0E, 0x1B, 0x00, 0x0E, 0x18}, {0x00, 0x00, 0x00, 0x46, 0x67, 0x25, 0x37, 0x1B}, {0x00, 0x00, 0x00, 0x0C, 0x1E, 0x12, 0x1A, 0x0E}, {0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01, 0x00}, {0x00, 0x00, 0x00, 0x18, 0x0C, 0x04, 0x06, 0x02}, {0x00, 0x00, 0x00, 0x03, 0x06, 0x04, 0x0C, 0x08}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06}, {0x00, 0x00, 0x00, 0x36, 0x7F, 0x7F, 0x7F, 0x7F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x10, 0x30, 0x30, 0x70, 0x50, 0x50}}, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x02, 0x02, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x08, 0x6C, 0x76, 0x52, 0x73, 0x31, 0x00, 0x00}, {0x36, 0x1F, 0x09, 0x1B, 0x3F, 0x2E, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x02, 0x02, 0x06, 0x04, 0x0C, 0x18, 0x00, 0x00}, {0x08, 0x08, 0x0C, 0x04, 0x06, 0x03, 0x00, 0x00}, {0x4F, 0x79, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x3E, 0x3E, 0x3E, 0x1C, 0x1C, 0x08, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x01}, {0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00}, {0x50, 0x1E, 0x1F, 0x1F, 0x0F, 0x06, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x04, 0x07, 0x07, 0x04, 0x04}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x30}, {0x00, 0x00, 0x00, 0x10, 0x18, 0x18, 0x1C, 0x14}, {0x00, 0x00, 0x00, 0x3E, 0x3E, 0x02, 0x02, 0x1F}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x01, 0x1D}, {0x00, 0x00, 0x00, 0x3F, 0x3F, 0x21, 0x31, 0x11}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x33}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00}, {0x00, 0x00, 0x00, 0x08, 0x08, 0x1C, 0x1C, 0x3E}, {0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x0C, 0x06}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F}, {0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0C}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x38}}, {{0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x1F, 0x1F, 0x00, 0x00}, {0x30, 0x1C, 0x06, 0x03, 0x3F, 0x3F, 0x00, 0x00}, {0x1C, 0x30, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x16, 0x12, 0x3F, 0x3F, 0x10, 0x10, 0x00, 0x00}, {0x3F, 0x21, 0x20, 0x31, 0x1F, 0x0E, 0x00, 0x00}, {0x3F, 0x23, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x18, 0x08, 0x0C, 0x04, 0x04, 0x04, 0x00, 0x00}, {0x1E, 0x33, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x3F, 0x2E, 0x20, 0x31, 0x1F, 0x0E, 0x00, 0x00}, {0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00}, {0x3E, 0x7F, 0x7F, 0x7F, 0x3E, 0x1C, 0x00, 0x00}, {0x03, 0x06, 0x0C, 0x18, 0x10, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00}, {0x18, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00}, {0x1C, 0x04, 0x04, 0x00, 0x06, 0x06, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x1C, 0x36, 0x23, 0x29, 0x3D}, {0x00, 0x00, 0x00, 0x0C, 0x0C, 0x1E, 0x12, 0x12}, {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x11, 0x11, 0x19}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x01}, {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x31, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x1F}, {0x00, 0x00, 0x00, 0x3F, 0x3F, 0x01, 0x01, 0x01}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x01, 0x01}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x21, 0x21, 0x3F}, {0x00, 0x00, 0x00, 0x07, 0x07, 0x02, 0x02, 0x02}, {0x00, 0x00, 0x00, 0x38, 0x38, 0x10, 0x10, 0x10}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x31, 0x11, 0x19}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x31, 0x33, 0x3B}, {0x00, 0x00, 0x00, 0x21, 0x23, 0x23, 0x27, 0x25}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}}, {{0x35, 0x35, 0x2D, 0x21, 0x33, 0x1E, 0x00, 0x00}, {0x12, 0x3F, 0x3F, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x3F, 0x31, 0x21, 0x31, 0x1F, 0x0F, 0x00, 0x00}, {0x01, 0x01, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x21, 0x31, 0x11, 0x19, 0x0F, 0x07, 0x00, 0x00}, {0x1F, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x00, 0x00}, {0x1F, 0x1F, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00}, {0x39, 0x39, 0x21, 0x23, 0x3F, 0x2E, 0x00, 0x00}, {0x3F, 0x21, 0x21, 0x21, 0x21, 0x21, 0x00, 0x00}, {0x02, 0x02, 0x02, 0x02, 0x07, 0x07, 0x00, 0x00}, {0x10, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x0D, 0x1F, 0x13, 0x33, 0x21, 0x21, 0x00, 0x00}, {0x01, 0x01, 0x01, 0x01, 0x1F, 0x1F, 0x00, 0x00}, {0x2F, 0x2D, 0x25, 0x25, 0x21, 0x21, 0x00, 0x00}, {0x29, 0x39, 0x31, 0x31, 0x21, 0x21, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x1F, 0x3F, 0x21, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x1F, 0x3F, 0x21, 0x21, 0x31}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x23, 0x01, 0x03}, {0x00, 0x00, 0x00, 0x3F, 0x3F, 0x08, 0x08, 0x08}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x21, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x21, 0x21, 0x33}, {0x00, 0x00, 0x00, 0x21, 0x29, 0x29, 0x29, 0x2D}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x33, 0x12, 0x1E}, {0x00, 0x00, 0x00, 0x21, 0x21, 0x23, 0x32, 0x16}, {0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x10, 0x18}, {0x00, 0x00, 0x00, 0x0D, 0x16, 0x00, 0x0E, 0x18}, {0x00, 0x00, 0x00, 0x00, 0x14, 0x14, 0x77, 0x77}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x0E, 0x18}, {0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0E, 0x18}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, {{0x31, 0x1F, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00}, {0x21, 0x21, 0x31, 0x19, 0x3F, 0x36, 0x00, 0x00}, {0x1F, 0x0F, 0x09, 0x19, 0x11, 0x31, 0x00, 0x00}, {0x3E, 0x20, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, {0x21, 0x21, 0x21, 0x33, 0x1F, 0x0E, 0x00, 0x00}, {0x12, 0x12, 0x1E, 0x0C, 0x0C, 0x0C, 0x00, 0x00}, {0x2D, 0x3F, 0x37, 0x16, 0x12, 0x12, 0x00, 0x00}, {0x0C, 0x1E, 0x12, 0x33, 0x21, 0x21, 0x00, 0x00}, {0x14, 0x1C, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, {0x0C, 0x04, 0x06, 0x02, 0x3F, 0x3F, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x00, 0x00, 0x77, 0x77, 0x14, 0x14, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x1E, 0x10}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x1C, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x0C, 0x0E, 0x02, 0x02, 0x02}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1E}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03}, {0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x06, 0x06}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x11, 0x19}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x3F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E}}, {{0x13, 0x01, 0x01, 0x11, 0x1F, 0x0E, 0x04, 0x06}, {0x1C, 0x1E, 0x13, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x11, 0x1F, 0x0F, 0x00, 0x00}, {0x13, 0x01, 0x01, 0x11, 0x1F, 0x0E, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x13, 0x19, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00}, {0x0F, 0x0F, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00}, {0x1B, 0x11, 0x19, 0x1F, 0x16, 0x10, 0x1E, 0x0E}, {0x13, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00}, {0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x03}, {0x0D, 0x07, 0x03, 0x07, 0x0D, 0x19, 0x00, 0x00}, {0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00}, {0x2F, 0x25, 0x25, 0x25, 0x25, 0x25, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x13}, {0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x0F, 0x0F}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x29}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1B}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F}, {0x00, 0x00, 0x00, 0x0E, 0x1C, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x0E, 0x1B, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, {{0x13, 0x11, 0x11, 0x19, 0x0F, 0x07, 0x01, 0x01}, {0x13, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x10, 0x10}, {0x13, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00}, {0x07, 0x0E, 0x1C, 0x19, 0x1B, 0x0E, 0x00, 0x00}, {0x02, 0x02, 0x02, 0x02, 0x0E, 0x0C, 0x00, 0x00}, {0x11, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x11, 0x1B, 0x0B, 0x0E, 0x06, 0x06, 0x00, 0x00}, {0x29, 0x2D, 0x2D, 0x3D, 0x17, 0x13, 0x00, 0x00}, {0x0E, 0x0C, 0x06, 0x0E, 0x1B, 0x11, 0x00, 0x00}, {0x1B, 0x0A, 0x0A, 0x0E, 0x04, 0x06, 0x03, 0x03}, {0x18, 0x0C, 0x06, 0x03, 0x1F, 0x1F, 0x00, 0x00}, {0x13, 0x19, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00}, {0x13, 0x19, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00}, {0x13, 0x19, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00}, {0x13, 0x19, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x07, 0x0E, 0x00, 0x06, 0x06}, {0x00, 0x00, 0x00, 0x0E, 0x07, 0x00, 0x06, 0x06}, {0x00, 0x00, 0x00, 0x0E, 0x1B, 0x00, 0x06, 0x06}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x06, 0x06}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02}, {0x00, 0x00, 0x11, 0x1B, 0x0E, 0x0E, 0x0B, 0x18}, {0x00, 0x00, 0x00, 0x0D, 0x16, 0x00, 0x0D, 0x1F}, {0x00, 0x00, 0x00, 0x0E, 0x1C, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x0E, 0x1B, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x0D, 0x16, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0C, 0x1E}, {0x00, 0x00, 0x00, 0x0E, 0x1C, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x11, 0x11}}, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00}, {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00}, {0x07, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x1E, 0x13, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x13, 0x11, 0x11, 0x19, 0x0F, 0x06, 0x00, 0x00}, {0x1B, 0x1D, 0x17, 0x1B, 0x0F, 0x06, 0x02, 0x00}, {0x11, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x11, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x0E, 0x1B, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x1C, 0x0E, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x01, 0x01, 0x0F, 0x1F, 0x11}, {0x1C, 0x0E, 0x00, 0x21, 0x21, 0x23, 0x32, 0x16}, {0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03}, {0x00, 0x00, 0x00, 0x1E, 0x1F, 0x03, 0x0E, 0x1F}, {0x00, 0x00, 0x00, 0x0E, 0x18, 0x1E, 0x13, 0x19}, {0x00, 0x00, 0x00, 0x0C, 0x1E, 0x13, 0x11, 0x19}, {0x00, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11}, {0x00, 0x00, 0x00, 0x0E, 0x1F, 0x11, 0x1C, 0x11}, {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x18, 0x0C, 0x06}, {0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x02}}, {{0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x11, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x11, 0x11, 0x11, 0x19, 0x1F, 0x16, 0x00, 0x00}, {0x1B, 0x0A, 0x0A, 0x0E, 0x04, 0x06, 0x03, 0x03}, {0x1B, 0x0A, 0x0A, 0x0E, 0x04, 0x06, 0x03, 0x03}, {0x19, 0x0D, 0x07, 0x03, 0x01, 0x01, 0x01, 0x00}, {0x14, 0x1C, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, {0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00}, {0x11, 0x1F, 0x1E, 0x10, 0x1F, 0x0E, 0x00, 0x00}, {0x1F, 0x16, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00}, {0x0F, 0x06, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00}, {0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x00, 0x00}, {0x11, 0x11, 0x19, 0x1F, 0x37, 0x01, 0x01, 0x00}, {0x1F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F}, {0x00, 0x00, 0x00, 0x3C, 0x3C, 0x0E, 0x0A, 0x0A}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x1F, 0x14}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x36, 0x12}, {0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x1B, 0x12}, {0x00, 0x00, 0x00, 0x08, 0x2A, 0x22, 0x08, 0x5D}, {0x00, 0x00, 0x00, 0x00, 0x0C, 0x3E, 0x7F, 0x7F}, {0x00, 0x00, 0x00, 0x08, 0x08, 0x3E, 0x7F, 0x7F}, {0x00, 0x00, 0x00, 0x38, 0x7C, 0x46, 0x42, 0x52}, {0x00, 0x00, 0x00, 0x3E, 0x7F, 0x5D, 0x7F, 0x63}, {0x00, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x18, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x18, 0x1F, 0x03, 0x00}, {0x00, 0x00, 0x00, 0x18, 0x18, 0x08, 0x0C, 0x0C}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x7F, 0x59}}, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x1F, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x3E, 0x3F, 0x09, 0x09, 0x39, 0x39, 0x00, 0x00}, {0x16, 0x1F, 0x05, 0x05, 0x1F, 0x1B, 0x00, 0x00}, {0x00, 0x00, 0x09, 0x1B, 0x1B, 0x1B, 0x00, 0x00}, {0x1B, 0x12, 0x36, 0x24, 0x24, 0x00, 0x00, 0x00}, {0x36, 0x12, 0x1B, 0x09, 0x09, 0x00, 0x00, 0x00}, {0x5D, 0x5D, 0x08, 0x22, 0x2A, 0x08, 0x00, 0x00}, {0x67, 0x5B, 0x5B, 0x5F, 0x2E, 0x00, 0x00, 0x00}, {0x7F, 0x08, 0x08, 0x48, 0x78, 0x30, 0x00, 0x00}, {0x5E, 0x4C, 0x60, 0x31, 0x1F, 0x0E, 0x00, 0x00}, {0x3E, 0x7F, 0x7F, 0x7F, 0x7F, 0x3E, 0x00, 0x00}, {0x1F, 0x1F, 0x00, 0x18, 0x1F, 0x03, 0x00, 0x00}, {0x1F, 0x1F, 0x00, 0x03, 0x1F, 0x18, 0x00, 0x00}, {0x04, 0x06, 0x06, 0x02, 0x03, 0x03, 0x00, 0x00}, {0x49, 0x4D, 0x7F, 0x33, 0x00, 0x00, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x1C, 0x3E, 0x63, 0x41}, {0x00, 0x00, 0x00, 0x00, 0x41, 0x63, 0x36, 0x1C}, {0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x41, 0x41}, {0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x1C, 0x14}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04}, {0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x1C, 0x0E}, {0x00, 0x00, 0x08, 0x1C, 0x3E, 0x2A, 0x08, 0x1E}, {0x00, 0x00, 0x00, 0x1E, 0x3F, 0x21, 0x21, 0x21}, {0x00, 0x00, 0x00, 0x22, 0x77, 0x77, 0x77, 0x2A}, {0x00, 0x00, 0x00, 0x08, 0x08, 0x1C, 0x1C, 0x7F}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x6B, 0x49, 0x49}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x5D, 0x7F, 0x63}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0x5D, 0x2A}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0x6B, 0x5D}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0x5D, 0x6B}, {0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0x5D, 0x7F}}, {{0x41, 0x41, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00}, {0x08, 0x08, 0x1C, 0x36, 0x63, 0x41, 0x00, 0x00}, {0x41, 0x41, 0x41, 0x41, 0x7F, 0x7F, 0x00, 0x00}, {0x14, 0x36, 0x22, 0x22, 0x7F, 0x7F, 0x00, 0x00}, {0x1F, 0x1F, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00}, {0x3F, 0x3F, 0x1C, 0x0E, 0x06, 0x03, 0x00, 0x00}, {0x3F, 0x21, 0x21, 0x21, 0x3F, 0x1E, 0x00, 0x00}, {0x3F, 0x1E, 0x04, 0x1F, 0x1F, 0x04, 0x00, 0x00}, {0x1C, 0x2A, 0x77, 0x77, 0x77, 0x22, 0x00, 0x00}, {0x3E, 0x1C, 0x1C, 0x3E, 0x36, 0x22, 0x00, 0x00}, {0x49, 0x7F, 0x6B, 0x3E, 0x3E, 0x2A, 0x00, 0x00}, {0x63, 0x63, 0x63, 0x63, 0x3E, 0x1C, 0x00, 0x00}, {0x7F, 0x7F, 0x41, 0x41, 0x3E, 0x1C, 0x00, 0x00}, {0x7F, 0x7F, 0x63, 0x6B, 0x3E, 0x1C, 0x00, 0x00}, {0x7F, 0x7F, 0x63, 0x5D, 0x3E, 0x1C, 0x00, 0x00}, {0x41, 0x41, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1B, 0x0E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00}, {0x00, 0x00, 0x00, 0x18, 0x67, 0x7F, 0x7F, 0x7F}, {0x00, 0x00, 0x00, 0x63, 0x77, 0x77, 0x6B, 0x14}, {0x00, 0x00, 0x00, 0x00, 0x7F, 0x41, 0x63, 0x55}, {0x00, 0x00, 0x00, 0x3E, 0x1C, 0x08, 0x1C, 0x32}, {0x00, 0x00, 0x00, 0x18, 0x1B, 0x63, 0x60, 0x1C}, {0x00, 0x00, 0x00, 0x22, 0x36, 0x3E, 0x7F, 0x5D}, {0x00, 0x00, 0x00, 0x41, 0x63, 0x7F, 0x7F, 0x7F}, {0x00, 0x00, 0x36, 0x36, 0x36, 0x36, 0x3E, 0x7F}, {0x00, 0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0x5D}, {0x00, 0x00, 0x00, 0x41, 0x7F, 0x3E, 0x2A, 0x2A}, {0x00, 0x00, 0x00, 0x41, 0x63, 0x3E, 0x2A, 0x6B}, {0x00, 0x00, 0x7F, 0x5F, 0x5F, 0x5F, 0x5F, 0x57}, {0x00, 0x00, 0x00, 0x2C, 0x2E, 0x6B, 0x7F, 0x41}, {0x00, 0x00, 0x00, 0x11, 0x0A, 0x0E, 0x1F, 0x1F}}, {{0x04, 0x04, 0x0E, 0x1B, 0x11, 0x00, 0x00, 0x00}, {0x1F, 0x1F, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00}, {0x7F, 0x08, 0x08, 0x0C, 0x0C, 0x0C, 0x00, 0x00}, {0x14, 0x36, 0x36, 0x63, 0x63, 0x41, 0x00, 0x00}, {0x49, 0x41, 0x41, 0x41, 0x7F, 0x00, 0x00, 0x00}, {0x6B, 0x73, 0x6B, 0x6B, 0x73, 0x3E, 0x00, 0x00}, {0x3E, 0x3E, 0x3E, 0x3E, 0x1E, 0x0C, 0x00, 0x00}, {0x5D, 0x7F, 0x77, 0x7F, 0x7F, 0x36, 0x00, 0x00}, {0x5D, 0x6B, 0x7F, 0x77, 0x7F, 0x36, 0x00, 0x00}, {0x5D, 0x5D, 0x7F, 0x77, 0x7F, 0x3E, 0x00, 0x00}, {0x5D, 0x77, 0x6B, 0x5D, 0x63, 0x3E, 0x00, 0x00}, {0x3E, 0x7F, 0x49, 0x49, 0x7F, 0x3E, 0x00, 0x00}, {0x7F, 0x63, 0x55, 0x55, 0x63, 0x3E, 0x00, 0x00}, {0x53, 0x41, 0x41, 0x73, 0x77, 0x7F, 0x00, 0x00}, {0x7F, 0x7F, 0x7F, 0x3E, 0x18, 0x3C, 0x00, 0x00}, {0x00, 0x15, 0x1B, 0x1B, 0x1B, 0x0A, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00}, {0x00, 0x00, 0x00, 0x10, 0x12, 0x3A, 0x3F, 0x17}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x0E, 0x1F, 0x1F, 0x1F, 0x0E}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, {{0x00, 0x00, 0x03, 0x03, 0x02, 0x01, 0x00, 0x00}, {0x12, 0x3A, 0x3F, 0x17, 0x12, 0x02, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x04, 0x04, 0x1C, 0x04, 0x1C, 0x1C, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
    {{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}, {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}},
};

static u8 sMsgSpaceGlyph[2][8] = {
    {0x00, 0x00, 0x7F, 0x49, 0x08, 0x2E, 0x2E, 0x2C},
    {0x09, 0x4B, 0x6B, 0x68, 0x6C, 0x7F, 0x00, 0x00},
};

static int sCachedMessageIds[9] = { 0x15, 0x16, 0x17, 0x04, 0x05, 0x06, 0x11, 0x12, 0x19 };
static mMsg_Window_c sMsgWindows[9];

// @non-matching
void mFont_GetGlyphRows(void* lower_rows, void* upper_rows, u8 character) {
    u8 lower[8];
    u8 upper[8];
    u8* upper_source;
    u8* lower_source;
    s32 i;

    if ((character == CHAR_CONTROL_CODE) || (character == 0x80) ||
        (character == CHAR_NEW_LINE)) {
        ((u32*)lower_rows)[0] = 0;
        ((u32*)lower_rows)[1] = 0;
        ((u32*)upper_rows)[0] = 0;
        ((u32*)upper_rows)[1] = 0;
        return;
    }

    if (character == 0x20) {
        upper_source = sMsgSpaceGlyph[0];
        lower_source = sMsgSpaceGlyph[1];
    } else {
        upper_source = sMsgFontGlyphs[character >> 4][0][character & 0xF];
        lower_source = sMsgFontGlyphs[character >> 4][1][character & 0xF];
    }

    for (i = 0; i < 8; i++) {
        upper[i] = upper_source[i];
        lower[i] = lower_source[i];
    }

    ((u32*)lower_rows)[0] = ((u32*)lower)[0];
    ((u32*)lower_rows)[1] = ((u32*)lower)[1];
    ((u32*)upper_rows)[0] = ((u32*)upper)[0];
    ((u32*)upper_rows)[1] = ((u32*)upper)[1];
}

int mFont_GetGlyphWidth(u32 c) {
    if (c < 0x100) {
        return sMsgGlyphWidths[c];
    }
    return -1;
}

int mFont_GetCodeWidth(u32 c) {
    if (c < 0x100) {
        return sFontCodeWidths[c];
    }
    return -1;
}

void mMsg_MainSetup_Hide(mMsg_Window_c* msg) {
    mMsg_InitWindow(msg, msg->text, msg->tile_data);
}

void mMsg_Main_Hide(mMsg_Window_c* msg) {
    mMsg_MainSetup_Window(msg);
}

void mMsg_MainSetup_Appear(mMsg_Window_c* msg) {
    msg->message_length = mMsg_LoadMessage(msg->text, msg->next_message_id);
    if (msg->message_length > 0) {
        msg->draw_enabled = 1;
        msg->message_id = msg->next_message_id;
        msg->next_message_id = -1;
        msg->current_mode = msg->requested_mode;
        msg->requested_mode = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        sub_02019D78(0x1F);
    }
}

void mMsg_Main_Appear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);

    if (msg->transition_frame > 10 && mMsg_RequestCursor(msg) != 0) {
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame++;
    }
}

int mMsg_Cont_SetNextMessage(mMsg_Window_c* msg, s16* offset, int choice) {
    u32 message_id = (*(msg->text + *offset + 2) << 8) | *(msg->text + *offset + 3);

    if (choice == 0xFF || choice == msg->choice_index) {
        if (message_id <= 30) {
            msg->next_message_id = message_id;
        } else {
            msg->cancel_continue = 1;
        }
    }

    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_SetChoiceCount(mMsg_Window_c* msg, s16* offset, int count) {
    msg->choice_count = count;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 4;
}

int mMsg_Cont_SetChoiceText(mMsg_Window_c* msg, s16* offset, int index) {
    mMsg_ChoiceEntry_c* choice = &msg->choices[index];

    choice->length = *(msg->text + *offset + 2);
    mMsg_Copy(msg->text + *offset + 3, choice->text, choice->length);
    choice->line = msg->text_row;
    choice->x = msg->text_x;
    *offset += mFont_CodeSize_get(&msg->text[*offset]);
    return 1;
}

int mMsg_Cont_Last(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Continue(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        return 2;
    }
}

int mMsg_Cont_Clear(mMsg_Window_c* msg, s16* offset) {
    mMsg_ClearText(msg);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Button(mMsg_Window_c* msg, s16* offset) {
    if ((msg->status_flags & mMsg_STATUS_LAST_DELAY) == 0) {
        msg->status_flags |= mMsg_STATUS_LAST_DELAY;
        return 3;
    } else {
        msg->status_flags &= ~mMsg_STATUS_LAST_DELAY;
        *offset += mFont_CodeSize_get(msg->text + *offset);
        return 2;
    }
}

int mMsg_Cont_SetNextMessageF(mMsg_Window_c* msg, s16* offset) {
    msg->force_next = 1;
    return mMsg_Cont_SetNextMessage(msg, offset, 0xFF);
}

int mMsg_Cont_SetNextMessage0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 0);
}

int mMsg_Cont_SetNextMessage1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetNextMessage(msg, offset, 1);
}

int mMsg_Cont_SetTemporaryColor(mMsg_Window_c* msg, s16* offset) {
    msg->temporary_color_length = *(msg->text + *offset + 3);
    msg->temporary_color = *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_Space(mMsg_Window_c* msg, s16* offset) {
    msg->text_x += *(msg->text + *offset + 2);
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_MoveDown(mMsg_Window_c* msg, s16* offset) {
    msg->text_row++;
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

int mMsg_Cont_RestoreCachedMessage(mMsg_Window_c* msg, s16* offset) {
    int i;
    for (i = 0; i < ARRAY_COUNT(sCachedMessageIds); i++) {
        if (sCachedMessageIds[i] == msg->message_id && &sMsgWindows[i] != msg) {
            u8* tile_data = msg->tile_data;
            u8* text = msg->text;
            u8 selected_choice = msg->selected_choice;

            CpuFastCopy(&sMsgWindows[i], msg, sizeof(mMsg_Window_c));
            msg->tile_data = tile_data;
            msg->text = text;
            msg->selected_choice = selected_choice;
            msg->draw_enabled = 1;
            mMsg_Copy(sMsgWindows[i].text, msg->text, msg->message_length);
            CpuFastCopy(sMsgWindows[i].tile_data, msg->tile_data, 0x1200);
            mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
            break;
        }
    }

    if (i == ARRAY_COUNT(sCachedMessageIds)) {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return 1;
}

int mMsg_Cont_SetChoiceCount2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 2);
}

int mMsg_Cont_SetChoiceCount3(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceCount(msg, offset, 3);
}

int mMsg_Cont_SetChoiceText0(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 0);
}

int mMsg_Cont_SetChoiceText1(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 1);
}

int mMsg_Cont_SetChoiceText2(mMsg_Window_c* msg, s16* offset) {
    return mMsg_Cont_SetChoiceText(msg, offset, 2);
}

int mMsg_Cont_CheckChoice(mMsg_Window_c* msg, s16* offset) {
    int ret = 3;

    if (*(msg->text + *offset + 2) == msg->choice_index + 1) {
        ret = 2;
    } else {
        *offset += mFont_CodeSize_get(msg->text + *offset);
    }

    return ret;
}

int mMsg_Cont_SoundTrgSys(mMsg_Window_c* msg, s16* offset) {
    u8 sound = *(msg->text + *offset + 2);

    if (sound == 7 || sound == 8) {
        sub_02019D78(sound == 7 ? 0x10 : 0x02);
    }

    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 3;
}

/**
 * @brief Dummy procedure for control codes that don't do anything on GBA.
 * @param msg Pointer to the message structure.
 * @param ofs_p Pointer to the offset in the message code.
 * @return 1.
 */
int mMsg_Cont_Noop(mMsg_Window_c* msg, s16* offset) {
    *offset += mFont_CodeSize_get(msg->text + *offset);
    return 1;
}

typedef int (*mMsg_CONTROL_CODE_PROC)(mMsg_Window_c* msg, s16* offset);

static mMsg_CONTROL_CODE_PROC sMsgControlCodeHandlers[] = {
    mMsg_Cont_Last, // mFont_CONT_CODE_LAST
    mMsg_Cont_Continue, // mFont_CONT_CODE_CONTINUE
    mMsg_Cont_Clear, // mFont_CONT_CODE_CLEAR
    mMsg_Cont_Noop, // mFont_CONT_CODE_CURSOR_SET_TIME
    mMsg_Cont_Button, // mFont_CONT_CODE_BUTTON
    mMsg_Cont_Noop, // mFont_CONT_CODE_COLOR
    mMsg_Cont_Noop, // mFont_CONT_CODE_ABLE_CANCEL
    mMsg_Cont_Noop, // mFont_CONT_CODE_UNABLE_CANCEL
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_DEMO_ORDER_PLAYER
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC0
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC1
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC2
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_DEMO_ORDER_QUEST
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_SELECT_WINDOW
    mMsg_Cont_SetNextMessageF, // mFont_CONT_CODE_SET_NEXT_MESSAGE_F
    mMsg_Cont_SetNextMessage0, // mFont_CONT_CODE_SET_NEXT_MESSAGE_0
    mMsg_Cont_SetNextMessage1, // mFont_CONT_CODE_SET_NEXT_MESSAGE_1
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_2
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_3
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_2
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_3
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_4
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_SELECT_STRING_2
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_SELECT_STRING_3
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_SELECT_STRING_4
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_FORCE_NEXT
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_PLAYER_NAME
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_TALK_NAME
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_TAIL
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_YEAR
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_MONTH
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_WEEK
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_DAY
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_HOUR
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_MIN
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_SEC
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE0
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE1
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE2
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE3
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE4
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE5
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE6
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE7
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE8
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE9
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_DETERMINATION
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_COUNTRY_NAME
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_RANDOM_NUMBER_2
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_ITEM0
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_ITEM1
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_ITEM2
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_ITEM3
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_ITEM4
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE10
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE11
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE12
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE13
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE14
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE15
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE16
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE17
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE18
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_FREE19
    mMsg_Cont_Noop, // mFont_CONT_CODE_PUT_STRING_MAIL
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY0
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY1
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY2
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY3
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY4
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY5
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY6
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY7
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY8
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_PLAYER_DESTINY9
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_NORMAL
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_ANGRY
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SAD
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_FUN
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SLEEPY
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_COLOR_CHAR
    mMsg_Cont_Noop, // mFont_CONT_CODE_SOUND_CUT
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_LINE_OFFSET
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_LINE_TYPE
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_CHAR_SCALE
    mMsg_Cont_Noop, // mFont_CONT_CODE_BUTTON2
    mMsg_Cont_Noop, // mFont_CONT_CODE_BGM_MAKE
    mMsg_Cont_Noop, // mFont_CONT_CODE_BGM_DELETE
    mMsg_Cont_Noop, // mFont_CONT_CODE_MSG_TIME_END
    mMsg_Cont_SoundTrgSys, // mFont_CONT_CODE_SOUND_TRG_SYS
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_LINE_SCALE
    mMsg_Cont_Noop, // mFont_CONT_CODE_SOUND_NO_PAGE
    mMsg_Cont_Noop, // mFont_CONT_CODE_VOICE_TRUE
    mMsg_Cont_Noop, // mFont_CONT_CODE_VOICE_FALSE
    mMsg_Cont_Noop, // mFont_CONT_CODE_SELECT_NO_B
    mMsg_Cont_Noop, // mFont_CONT_CODE_GIVE_OPEN
    mMsg_Cont_Noop, // mFont_CONT_CODE_GIVE_CLOSE
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_GLOOMY
    mMsg_Cont_Noop, // mFont_CONT_CODE_SELECT_NO_B_CLOSE
    mMsg_Cont_Noop, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_SECTION
    mMsg_Cont_Noop, // mFont_CONT_CODE_UNKNOWN_100
    mMsg_Cont_Noop, // mFont_CONT_CODE_UNKNOWN_101
    mMsg_Cont_SetTemporaryColor, // mFont_CONT_CODE_SET_TEMPORARY_COLOR
    mMsg_Cont_Space, // mFont_CONT_CODE_SPACE
    mMsg_Cont_MoveDown, // mFont_CONT_CODE_MOVE_DOWN
    mMsg_Cont_RestoreCachedMessage, // mFont_CONT_CODE_RESTORE_CACHED_MESSAGE
    mMsg_Cont_Noop, // mFont_CONT_CODE_MALE_FEMALE_CHECK
    mMsg_Cont_SetChoiceCount2, // mFont_CONT_CODE_SET_CHOICE_COUNT_2
    mMsg_Cont_SetChoiceCount3, // mFont_CONT_CODE_SET_CHOICE_COUNT_3
    mMsg_Cont_SetChoiceText0, // mFont_CONT_CODE_SET_CHOICE_TEXT_0
    mMsg_Cont_SetChoiceText1, // mFont_CONT_CODE_SET_CHOICE_TEXT_1
    mMsg_Cont_SetChoiceText2, // mFont_CONT_CODE_SET_CHOICE_TEXT_2
    mMsg_Cont_CheckChoice, // mFont_CONT_CODE_CHECK_CHOICE
};

// @0x0201892c
int mMsg_ProcessControlCode(mMsg_Window_c* msg, s16* offset) {
    int ret = 1;
    u8 code = msg->text[*offset];
    u8 type = msg->text[*offset + 1];
    
    if (code == CHAR_CONTROL_CODE && type <= mFont_CONT_CODE_CHECK_CHOICE) {
        ret = sMsgControlCodeHandlers[type](msg, offset);
    }

    return ret;
}

static void mMsg_MainSetup_Cursor(mMsg_Window_c* msg) {
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Cursor(mMsg_Window_c* msg) {
    int process_res;
    u8 res;
    int i;

    sMsgPreviousTextRow = msg->text_row;
    sMsgPreviousTextX = msg->text_x;
    
    process_res = mMsg_ProcessText(msg, msg->tile_data, 1);
    switch (process_res) {
        case 4:
            res = mMsg_RequestChoice(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
        case 2:
            res = mMsg_RequestNormal(msg);
            if (res) {
                mMsg_MainSetup_Window(msg);
            }
            return;
    }

    for (i = sMsgPreviousTextRow; sMsgPreviousTextRow < msg->text_row; i++) {
        int temp;

        sMsgDirtyTileOffset = sMsgPreviousTextRow * msg->tile_stride + sMsgPreviousTextX / 8;
        temp = msg->tile_stride * 8 - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }
        sMsgDirtyTileCount = temp >> 3;

        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
        sMsgPreviousTextX = msg->text_start_x;
        sMsgPreviousTextRow += 2;
        sMsgPreviousTextRow &= 0xFE;
    }

    if (sMsgPreviousTextX != msg->text_x) {
        int temp;

        sMsgDirtyTileOffset = msg->text_row * msg->tile_stride + sMsgPreviousTextX / 8;
        sMsgDirtyTileCount = MIN(msg->tile_stride * 8, msg->text_x);

        temp = sMsgDirtyTileCount - sMsgPreviousTextX + 7;
        if (temp < 0) {
            temp += 7;
        }

        sMsgDirtyTileCount = temp >> 3;
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset, sMsgDirtyTileCount, msg->tile_data);
        mMsg_CopyTilesToVram(sMsgDirtyTileOffset + msg->tile_stride, sMsgDirtyTileCount, msg->tile_data);
    }
}

static int mMsg_CheckAdvanceInput(void) {
    return gGameState.keys_pressed & (u16)(A_BUTTON | B_BUTTON);
}

static void mMsg_MainSetup_Normal(mMsg_Window_c* msg) {
    msg->status_flags &= ~mMsg_STATUS_END_REACHED;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
}

static void mMsg_Main_Normal(mMsg_Window_c* msg) {
    int is_terminal_code = 0;

    if (mMsg_EndTimerDec(msg) == 1 && mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
        if (mMsg_CheckAdvanceInput() || msg->force_next == 1) {
            if (msg->lock_continue != 0) {
                return;
            }

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 0) {
                if (msg->next_message_id <= 30 &&
                    mMsg_ChangeMsgData(msg, msg->next_message_id) == 1) {
                    if (mMsg_RequestCursor(msg) == 1) {
                        mMsg_MainSetup_Window(msg);
                        msg->force_next = 0;
                        msg->next_message_id = -1;
                    }
                }
                return;
            }

            if (mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
                msg->cancel_continue == 1) {
                mMsg_RequestDisappear(msg);
                mMsg_MainSetup_Window(msg);
                return;
            }

            is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CHECK_CHOICE,
                                                    msg->text_offset);
            if (!is_terminal_code) {
                is_terminal_code = mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_LAST,
                                                        msg->text_offset);
            }

            if (is_terminal_code ||
                mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_MSG_TIME_END, msg->text_offset)) {
                if (is_terminal_code && (msg->status_flags & mMsg_STATUS_KEEP_OPEN)) {
                    msg->status_flags |= mMsg_STATUS_END_REACHED;
                } else {
                    mMsg_RequestDisappear(msg);
                    mMsg_MainSetup_Window(msg);
                }
            } else if (mMsg_RequestCursor(msg) == 1) {
                mMsg_MainSetup_Window(msg);
                msg->force_next = 0;
            }
            return;
        }

        if (!mMsg_CheckControlCode(msg->text, mFont_CONT_CODE_CONTINUE, msg->text_offset) &&
            msg->lock_continue == 0 && msg->continue_prompt == NULL) {
            int alternate = (u32)(msg->message_id - 1) <= 1;
            msg->continue_prompt = sub_0201C310(0xA, 0xC8, 0x68, alternate);
        }
    }
}

static void mMsg_MainSetup_Disappear(mMsg_Window_c* msg) {
    msg->transition_frame = 12;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    sub_02019D78(0x20);
}

static void mMsg_Main_Disappear(mMsg_Window_c* msg) {
    gGameState.bg3_vofs = mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if (msg->transition_frame == 0 && mMsg_RequestHide(msg) != 0) {
        gGameState.unk_84E = 0;
        gGameState.unk_84F = 0;
        gGameState.unk_84C = 0;
        gGameState.unk_84D = 0;
        mMsg_MainSetup_Window(msg);
    } else {
        msg->transition_frame--;
    }
}

#define gMsgGlyph (*(mFont_GlyphDraw_c*)0x03003100)
#define gMsgCodeBuffers ((u8*)0x02000400)
#define gMsgTileBuffers ((u8*)0x02001D80)
#define gMsgWindowTileData ((u8*)0x0200F580)
#define gMsgVram ((u8*)0x06002000)
#define gObjPaletteBuffer ((u16*)0x02000200)

#define gMsgTwoChoiceHighlightTiles ((void**)0x0202AAC8)
#define gMsgThreeChoiceHighlightTiles ((void**)0x0202AAD0)
/* These tables are indexed by the one-based mMsg_MODE_* values. */
// #define gMsgModeSetupCallbacks ((mMsg_Callback*)0x0202AADC)
#define gMsgModeCallbacks ((mMsg_Callback*)0x0202AB00)
#define gMsgChoiceTemplateParams ((u8*)0x0202AD18)
#define gUnk_0202AD1C ((void**)0x0202AD1C)
#define gUnk_0202AD28 ((u32*)0x0202AD28)
#define gUnk_0202AFB4 ((u32*)0x0202AFB4)

typedef void (*mMsg_SETUP_PROC)(mMsg_Window_c*);
typedef void (*mMsg_MAIN_PROC)(mMsg_Window_c*);

// @0x0202AADC
static mMsg_SETUP_PROC gMsgModeSetupCallbacks[] = {
    NULL,
    mMsg_MainSetup_Hide,
    mMsg_MainSetup_Appear,
    mMsg_MainSetup_Cursor,
    mMsg_MainSetup_Normal,
    mMsg_MainSetup_Choice,
    mMsg_MainSetup_Disappear,
    mMsg_MainSetup_DisappearWait,
    mMsg_MainSetup_AppearWait,
};

// @0x0202AB24
static int gMsgWindowScrollOffsets[12] = {
    0x00000000, 0x4A000000, 0x92000000, 0xBE000000, 0xD8000000, 0xE8000000, 0xF1000000, 0xF7000000,
    0xFA000000, 0xFD000000, 0xFF000000, 0x00010000
};

// @0x02034FA4 - CHAR_* plus control codes
static u8 gMsgTextData[2002] = {
    0x44, 0x6F, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x74,
    0x75, 0x72, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20,
    0x70, 0x6F, 0x77, 0x65, 0x72, 0x20, 0x6F, 0x66,
    0x66, 0x2E, 0xCD, 0x54, 0x6F, 0x20, 0x71, 0x75,
    0x69, 0x74, 0x20, 0x77, 0x69, 0x74, 0x68, 0x6F,
    0x75, 0x74, 0x20, 0x6C, 0x6F, 0x73, 0x69, 0x6E,
    0x67, 0x20, 0x79, 0x6F, 0x75, 0x72, 0xCD, 0x64,
    0x65, 0x73, 0x69, 0x67, 0x6E, 0x20, 0x64, 0x61,
    0x74, 0x61, 0x2C, 0x20, 0x70, 0x72, 0x65, 0x73,
    0x73, 0x20, 0x7F, 0x66, 0x0A, 0x06, 0x53, 0x45,
    0x4C, 0x45, 0x43, 0x54, 0xCD, 0x61, 0x6E, 0x64,
    0x20, 0x63, 0x68, 0x6F, 0x6F, 0x73, 0x65, 0x20,
    0x7F, 0x66, 0x0B, 0x0A, 0x53, 0x6C, 0x65, 0x65,
    0x70, 0x20, 0x4D, 0x6F, 0x64, 0x65, 0x2E, 0xCD,
    0x7F, 0x00, 0x54, 0x6F, 0x20, 0x73, 0x61, 0x76,
    0x65, 0x20, 0x79, 0x6F, 0x75, 0x72, 0x20, 0x63,
    0x6F, 0x6D, 0x70, 0x6C, 0x65, 0x74, 0x65, 0x64,
    0xCD, 0x64, 0x65, 0x73, 0x69, 0x67, 0x6E, 0x2C,
    0x20, 0x63, 0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74,
    0x20, 0x74, 0x6F, 0x20, 0x74, 0x68, 0x65, 0xCD,
    0x4E, 0x69, 0x6E, 0x74, 0x65, 0x6E, 0x64, 0x6F,
    0x20, 0x47, 0x61, 0x6D, 0x65, 0x43, 0x75, 0x62,
    0x65, 0x20, 0x61, 0x6E, 0x64, 0xCD, 0x67, 0x65,
    0x74, 0x20, 0x69, 0x74, 0x20, 0x74, 0x68, 0x65,
    0x20, 0x74, 0x61, 0x69, 0x6C, 0x6F, 0x72, 0x20,
    0x73, 0x68, 0x6F, 0x70, 0x2E, 0xCD, 0x7F, 0x04,
    0x7F, 0x02, 0x57, 0x68, 0x65, 0x72, 0x65, 0x20,
    0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x79, 0x6F,
    0x75, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0xCD, 0x74,
    0x6F, 0x20, 0x73, 0x61, 0x76, 0x65, 0x20, 0x79,
    0x6F, 0x75, 0x72, 0x20, 0x64, 0x65, 0x73, 0x69,
    0x67, 0x6E, 0x3F, 0xCD, 0x7F, 0x00, 0xCD, 0x45,
    0x6E, 0x74, 0x65, 0x72, 0x20, 0x61, 0x20, 0x6E,
    0x61, 0x6D, 0x65, 0x20, 0x66, 0x6F, 0x72, 0xCD,
    0x74, 0x68, 0x69, 0x73, 0x20, 0x64, 0x65, 0x73,
    0x69, 0x67, 0x6E, 0x2E, 0xCD, 0x7F, 0x00, 0x7F,
    0x68, 0x7F, 0x65, 0x0D, 0x54, 0x72, 0x61, 0x6E,
    0x73, 0x6D, 0x69, 0x74, 0x74, 0x69, 0x6E, 0x67,
    0x20, 0x64, 0x61, 0x74, 0x61, 0x2E, 0x2E, 0x2E,
    0xCD, 0x7F, 0x68, 0x7F, 0x65, 0x0D, 0x44, 0x6F,
    0x20, 0x6E, 0x6F, 0x74, 0x20, 0x72, 0x65, 0x6D,
    0x6F, 0x76, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20,
    0x63, 0x61, 0x62, 0x6C, 0x65, 0x21, 0xCD, 0x7F,
    0x68, 0x7F, 0x65, 0x0D, 0x44, 0x6F, 0x20, 0x6E,
    0x6F, 0x74, 0x20, 0x74, 0x75, 0x72, 0x6E, 0x20,
    0x74, 0x68, 0x65, 0x20, 0x70, 0x6F, 0x77, 0x65,
    0x72, 0x20, 0x4F, 0x46, 0x46, 0x21, 0xCD, 0x7F,
    0x00, 0x7F, 0x69, 0x7F, 0x68, 0x7F, 0x67, 0x0D,
    0x54, 0x72, 0x61, 0x64, 0x65, 0x20, 0x69, 0x73,
    0x6C, 0x61, 0x6E, 0x64, 0x73, 0x3F, 0xCD, 0xCD,
    0x7F, 0x67, 0x28, 0x7F, 0x6D, 0x03, 0x59, 0x65,
    0x73, 0x7F, 0x67, 0x1B, 0x7F, 0x6E, 0x02, 0x4E,
    0x6F, 0x7F, 0x6B, 0x7F, 0x70, 0x02, 0x7F, 0x0F,
    0x00, 0x05, 0xCD, 0x7F, 0x01, 0x55, 0x73, 0x65,
    0x20, 0x74, 0x68, 0x65, 0x20, 0x7F, 0x66, 0x09,
    0x10, 0x47, 0x61, 0x6D, 0x65, 0x20, 0x42, 0x6F,
    0x79, 0x20, 0x41, 0x64, 0x76, 0x61, 0x6E, 0x63,
    0x65, 0xCD, 0x7F, 0x65, 0x09, 0x47, 0x61, 0x6D,
    0x65, 0x20, 0x4C, 0x69, 0x6E, 0x6B, 0x20, 0x63,
    0x61, 0x62, 0x6C, 0x65, 0xCD, 0x74, 0x6F, 0x20,
    0x63, 0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74, 0x20,
    0x79, 0x6F, 0x75, 0x72, 0x20, 0x7F, 0x66, 0x09,
    0x08, 0x47, 0x61, 0x6D, 0x65, 0x20, 0x42, 0x6F,
    0x79, 0xCD, 0x7F, 0x66, 0x09, 0x07, 0x41, 0x64,
    0x76, 0x61, 0x6E, 0x63, 0x65, 0x20, 0x73, 0x79,
    0x73, 0x74, 0x65, 0x6D, 0x73, 0x2E, 0x7F, 0x04,
    0x7F, 0x0E, 0x00, 0x06, 0xCD, 0x7F, 0x01, 0xCD,
    0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x74, 0x68,
    0x65, 0x20, 0x7F, 0x66, 0x0E, 0x08, 0x41, 0x20,
    0x42, 0x75, 0x74, 0x74, 0x6F, 0x6E, 0xCD, 0x77,
    0x68, 0x65, 0x6E, 0x20, 0x79, 0x6F, 0x75, 0x27,
    0x72, 0x65, 0x20, 0x72, 0x65, 0x61, 0x64, 0x79,
    0x2E, 0x7F, 0x04, 0xCD, 0x7F, 0x01, 0x7F, 0x65,
    0x0D, 0x54, 0x72, 0x61, 0x64, 0x69, 0x6E, 0x67,
    0x20, 0x69, 0x73, 0x6C, 0x61, 0x6E, 0x64, 0x20,
    0x64, 0x61, 0x74, 0x61, 0x2E, 0x2E, 0x2E, 0xCD,
    0x7F, 0x65, 0x0D, 0x44, 0x6F, 0x20, 0x6E, 0x6F,
    0x74, 0x20, 0x64, 0x69, 0x73, 0x63, 0x6F, 0x6E,
    0x6E, 0x65, 0x63, 0x74, 0x20, 0x74, 0x68, 0x65,
    0xCD, 0x7F, 0x65, 0x0D, 0x63, 0x61, 0x62, 0x6C,
    0x65, 0x21, 0x20, 0x44, 0x6F, 0x20, 0x6E, 0x6F,
    0x74, 0x20, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x79,
    0x6F, 0x75, 0x72, 0xCD, 0x7F, 0x65, 0x0D, 0x7F,
    0x66, 0x09, 0x10, 0x47, 0x61, 0x6D, 0x65, 0x20,
    0x42, 0x6F, 0x79, 0x20, 0x41, 0x64, 0x76, 0x61,
    0x6E, 0x63, 0x65, 0x20, 0x6F, 0x66, 0x66, 0x21,
    0xCD, 0x7F, 0x01, 0x54, 0x68, 0x65, 0x20, 0x73,
    0x79, 0x73, 0x74, 0x65, 0x6D, 0x73, 0x20, 0x61,
    0x72, 0x65, 0x20, 0x6E, 0x6F, 0x74, 0xCD, 0x63,
    0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74, 0x65, 0x64,
    0x20, 0x70, 0x72, 0x6F, 0x70, 0x65, 0x72, 0x6C,
    0x79, 0x2E, 0x20, 0x50, 0x6C, 0x65, 0x61, 0x73,
    0x65, 0xCD, 0x63, 0x68, 0x65, 0x63, 0x6B, 0x20,
    0x74, 0x68, 0x65, 0x20, 0x63, 0x6F, 0x6E, 0x6E,
    0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x73, 0x20,
    0x61, 0x6E, 0x64, 0xCD, 0x74, 0x72, 0x79, 0x20,
    0x61, 0x67, 0x61, 0x69, 0x6E, 0x2E, 0x7F, 0x04,
    0xCD, 0x7F, 0x01, 0x7F, 0x68, 0x54, 0x68, 0x61,
    0x6E, 0x6B, 0x20, 0x79, 0x6F, 0x75, 0x20, 0x66,
    0x6F, 0x72, 0x20, 0x77, 0x61, 0x69, 0x74, 0x69,
    0x6E, 0x67, 0x2E, 0xCD, 0x7F, 0x68, 0xCD, 0x7F,
    0x68, 0x54, 0x68, 0x65, 0x20, 0x74, 0x72, 0x61,
    0x64, 0x65, 0x20, 0x69, 0x73, 0x20, 0x63, 0x6F,
    0x6D, 0x70, 0x6C, 0x65, 0x74, 0x65, 0x2E, 0xCD,
    0x7F, 0x00, 0x54, 0x68, 0x65, 0x20, 0x74, 0x72,
    0x61, 0x64, 0x65, 0x20, 0x77, 0x61, 0x73, 0x20,
    0x63, 0x61, 0x6E, 0x63, 0x65, 0x6C, 0x65, 0x64,
    0x2E, 0xCD, 0x50, 0x6C, 0x65, 0x61, 0x73, 0x65,
    0x20, 0x73, 0x74, 0x61, 0x72, 0x74, 0x20, 0x74,
    0x68, 0x65, 0x20, 0x74, 0x72, 0x61, 0x64, 0x65,
    0xCD, 0x61, 0x67, 0x61, 0x69, 0x6E, 0x20, 0x66,
    0x72, 0x6F, 0x6D, 0x20, 0x74, 0x68, 0x65, 0x20,
    0x62, 0x65, 0x67, 0x69, 0x6E, 0x6E, 0x69, 0x6E,
    0x67, 0x2E, 0x7F, 0x04, 0xCD, 0x7F, 0x01, 0x7F,
    0x65, 0x0D, 0x54, 0x72, 0x61, 0x6E, 0x73, 0x6D,
    0x69, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x64,
    0x61, 0x74, 0x61, 0x2E, 0x2E, 0x2E, 0xCD, 0x7F,
    0x65, 0x0D, 0x44, 0x6F, 0x20, 0x6E, 0x6F, 0x74,
    0x20, 0x64, 0x69, 0x73, 0x63, 0x6F, 0x6E, 0x6E,
    0x65, 0x63, 0x74, 0x20, 0x74, 0x68, 0x65, 0xCD,
    0x7F, 0x65, 0x0D, 0x63, 0x61, 0x62, 0x6C, 0x65,
    0x21, 0x20, 0x44, 0x6F, 0x20, 0x6E, 0x6F, 0x74,
    0x20, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x79, 0x6F,
    0x75, 0x72, 0xCD, 0x7F, 0x65, 0x0D, 0x7F, 0x66,
    0x09, 0x10, 0x47, 0x61, 0x6D, 0x65, 0x20, 0x42,
    0x6F, 0x79, 0x20, 0x41, 0x64, 0x76, 0x61, 0x6E,
    0x63, 0x65, 0x20, 0x6F, 0x66, 0x66, 0x21, 0xCD,
    0x7F, 0x01, 0x41, 0x6E, 0x20, 0x65, 0x72, 0x72,
    0x6F, 0x72, 0x20, 0x68, 0x61, 0x73, 0x20, 0x6F,
    0x63, 0x63, 0x75, 0x72, 0x72, 0x65, 0x64, 0x2E,
    0xCD, 0x50, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x20,
    0x63, 0x68, 0x65, 0x63, 0x6B, 0x20, 0x74, 0x68,
    0x65, 0xCD, 0x63, 0x61, 0x62, 0x6C, 0x65, 0x20,
    0x63, 0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74, 0x69,
    0x6F, 0x6E, 0x73, 0x2E, 0x7F, 0x04, 0xCD, 0x7F,
    0x01, 0xCD, 0x7F, 0x68, 0x54, 0x72, 0x61, 0x6E,
    0x73, 0x6D, 0x69, 0x73, 0x73, 0x69, 0x6F, 0x6E,
    0x20, 0x63, 0x6F, 0x6D, 0x70, 0x6C, 0x65, 0x74,
    0x65, 0x2E, 0xCD, 0x7F, 0x00, 0xCD, 0x44, 0x61,
    0x74, 0x61, 0x20, 0x74, 0x72, 0x61, 0x6E, 0x73,
    0x6D, 0x69, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0xCD,
    0x63, 0x61, 0x6E, 0x63, 0x65, 0x6C, 0x65, 0x64,
    0x2E, 0x7F, 0x04, 0xCD, 0x7F, 0x01, 0xCD, 0x7F,
    0x68, 0x7F, 0x65, 0x0D, 0x50, 0x6C, 0x65, 0x61,
    0x73, 0x65, 0x20, 0x77, 0x61, 0x69, 0x74, 0x20,
    0x61, 0x20, 0x6D, 0x6F, 0x6D, 0x65, 0x6E, 0x74,
    0x2E, 0x2E, 0x2E, 0xCD, 0xCD, 0x7F, 0x01, 0xCD,
    0x54, 0x68, 0x65, 0x20, 0x6F, 0x74, 0x68, 0x65,
    0x72, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D,
    0x20, 0x69, 0x73, 0xCD, 0x6E, 0x6F, 0x74, 0x20,
    0x72, 0x65, 0x73, 0x70, 0x6F, 0x6E, 0x64, 0x69,
    0x6E, 0x67, 0x2E, 0x7F, 0x04, 0xCD, 0x7F, 0x01,
    0x7F, 0x69, 0x7F, 0x68, 0x44, 0x6F, 0x20, 0x79,
    0x6F, 0x75, 0x20, 0x77, 0x61, 0x6E, 0x74, 0x20,
    0x74, 0x6F, 0x20, 0x74, 0x72, 0x79, 0x20, 0x61,
    0x67, 0x61, 0x69, 0x6E, 0x3F, 0xCD, 0x7F, 0x68,
    0xCD, 0x7F, 0x68, 0x7F, 0x67, 0x28, 0x7F, 0x6D,
    0x03, 0x59, 0x65, 0x73, 0x7F, 0x67, 0x1B, 0x7F,
    0x6E, 0x02, 0x4E, 0x6F, 0x7F, 0x6B, 0x7F, 0x70,
    0x02, 0x7F, 0x0F, 0x00, 0x05, 0xCD, 0x7F, 0x01,
    0x50, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x20, 0x72,
    0x65, 0x6D, 0x6F, 0x76, 0x65, 0x20, 0x74, 0x68,
    0x65, 0xCD, 0x7F, 0x66, 0x09, 0x15, 0x47, 0x61,
    0x6D, 0x65, 0x20, 0x42, 0x6F, 0x79, 0x20, 0x41,
    0x64, 0x76, 0x61, 0x6E, 0x63, 0x65, 0x20, 0x47,
    0x61, 0x6D, 0x65, 0xCD, 0x7F, 0x66, 0x09, 0x0A,
    0x4C, 0x69, 0x6E, 0x6B, 0x20, 0x63, 0x61, 0x62,
    0x6C, 0x65, 0x2E, 0xCD, 0x7F, 0x00, 0xCD, 0x7F,
    0x68, 0x54, 0x72, 0x61, 0x6E, 0x73, 0x6D, 0x69,
    0x73, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x63, 0x6F,
    0x6D, 0x70, 0x6C, 0x65, 0x74, 0x65, 0x2E, 0xCD,
    0x7F, 0x00, 0xCD, 0x44, 0x61, 0x74, 0x61, 0x20,
    0x74, 0x72, 0x61, 0x6E, 0x73, 0x6D, 0x69, 0x73,
    0x73, 0x69, 0x6F, 0x6E, 0xCD, 0x63, 0x61, 0x6E,
    0x63, 0x65, 0x6C, 0x65, 0x64, 0x2E, 0xCD, 0x7F,
    0x00, 0x7F, 0x69, 0x7F, 0x68, 0x45, 0x6E, 0x61,
    0x62, 0x6C, 0x65, 0x20, 0x7F, 0x66, 0x0B, 0x0A,
    0x53, 0x6C, 0x65, 0x65, 0x70, 0x20, 0x4D, 0x6F,
    0x64, 0x65, 0x3F, 0xCD, 0xCD, 0x7F, 0x67, 0x28,
    0x7F, 0x6D, 0x03, 0x59, 0x65, 0x73, 0x7F, 0x67,
    0x1B, 0x7F, 0x6E, 0x02, 0x4E, 0x6F, 0x7F, 0x6B,
    0x7F, 0x70, 0x02, 0x7F, 0x0F, 0x00, 0x16, 0xCD,
    0x7F, 0x01, 0x54, 0x6F, 0x20, 0x64, 0x69, 0x73,
    0x61, 0x62, 0x6C, 0x65, 0x20, 0x7F, 0x66, 0x0B,
    0x0A, 0x53, 0x6C, 0x65, 0x65, 0x70, 0x20, 0x4D,
    0x6F, 0x64, 0x65, 0x2C, 0xCD, 0x70, 0x72, 0x65,
    0x73, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x7F,
    0x66, 0x0A, 0x08, 0x4C, 0x20, 0x42, 0x75, 0x74,
    0x74, 0x6F, 0x6E, 0x20, 0x61, 0x6E, 0x64, 0xCD,
    0x7F, 0x66, 0x0A, 0x06, 0x53, 0x45, 0x4C, 0x45,
    0x43, 0x54, 0x20, 0x73, 0x69, 0x6D, 0x75, 0x6C,
    0x74, 0x61, 0x6E, 0x65, 0x6F, 0x75, 0x73, 0x6C,
    0x79, 0x2E, 0x7F, 0x04, 0xCD, 0x7F, 0x01, 0x7F,
    0x69, 0x7F, 0x68, 0x44, 0x69, 0x73, 0x61, 0x62,
    0x6C, 0x65, 0x20, 0x7F, 0x66, 0x0B, 0x0A, 0x53,
    0x6C, 0x65, 0x65, 0x70, 0x20, 0x4D, 0x6F, 0x64,
    0x65, 0x3F, 0xCD, 0xCD, 0x7F, 0x67, 0x28, 0x7F,
    0x6D, 0x03, 0x59, 0x65, 0x73, 0x7F, 0x67, 0x1B,
    0x7F, 0x6E, 0x02, 0x4E, 0x6F, 0x7F, 0x6B, 0x7F,
    0x70, 0x01, 0xCD, 0x7F, 0x01, 0x7F, 0x67, 0x28,
    0x7F, 0x66, 0x07, 0x03, 0x59, 0x65, 0x73, 0x7F,
    0x67, 0x1B, 0x7F, 0x66, 0x07, 0x02, 0x4E, 0x6F,
    0xCD, 0x7F, 0x00, 0x7F, 0x69, 0x7F, 0x66, 0x0E,
    0x0B, 0x49, 0x73, 0x20, 0x74, 0x68, 0x69, 0x73,
    0x20, 0x4F, 0x4B, 0x3F, 0xCD, 0x7F, 0x67, 0x21,
    0x7F, 0x6D, 0x03, 0x59, 0x65, 0x73, 0xCD, 0x7F,
    0x67, 0x21, 0x7F, 0x6E, 0x08, 0x52, 0x65, 0x64,
    0x65, 0x73, 0x69, 0x67, 0x6E, 0xCD, 0x7F, 0x67,
    0x21, 0x7F, 0x6F, 0x0C, 0x54, 0x68, 0x72, 0x6F,
    0x77, 0x20, 0x69, 0x74, 0x20, 0x6F, 0x75, 0x74,
    0x7F, 0x6C, 0x7F, 0x70, 0x02, 0x7F, 0x0F, 0x00,
    0x02, 0xCD, 0x7F, 0x00, 0x7F, 0x68, 0x59, 0x6F,
    0x75, 0x20, 0x63, 0x61, 0x6E, 0x27, 0x74, 0x20,
    0x75, 0x73, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20,
    0x7F, 0x66, 0x09, 0x04, 0x47, 0x61, 0x6D, 0x65,
    0xCD, 0x7F, 0x68, 0x7F, 0x66, 0x09, 0x0B, 0x42,
    0x6F, 0x79, 0x20, 0x41, 0x64, 0x76, 0x61, 0x6E,
    0x63, 0x65, 0x20, 0x69, 0x73, 0x6C, 0x61, 0x6E,
    0x64, 0x20, 0x6F, 0x6E, 0x20, 0x74, 0x68, 0x65,
    0xCD, 0x7F, 0x68, 0x7F, 0x66, 0x09, 0x11, 0x4E,
    0x69, 0x6E, 0x74, 0x65, 0x6E, 0x64, 0x6F, 0x20,
    0x47, 0x61, 0x6D, 0x65, 0x43, 0x75, 0x62, 0x65,
    0x20, 0x69, 0x73, 0x6C, 0x61, 0x6E, 0x64, 0x2E,
    0x7F, 0x04, 0x7F, 0x0E, 0x00, 0x1B, 0xCD, 0x7F,
    0x01, 0x59, 0x6F, 0x75, 0x20, 0x6D, 0x61, 0x79,
    0x20, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x74, 0x68,
    0x65, 0x20, 0x70, 0x6F, 0x77, 0x65, 0x72, 0xCD,
    0x6F, 0x66, 0x66, 0x2C, 0x20, 0x62, 0x75, 0x74,
    0x20, 0x62, 0x65, 0x20, 0x73, 0x75, 0x72, 0x65,
    0x20, 0x74, 0x6F, 0x20, 0x74, 0x75, 0x72, 0x6E,
    0xCD, 0x79, 0x6F, 0x75, 0x72, 0x20, 0x7F, 0x66,
    0x09, 0x04, 0x47, 0x61, 0x6D, 0x65, 0x20, 0x7F,
    0x66, 0x09, 0x0B, 0x42, 0x6F, 0x79, 0x20, 0x41,
    0x64, 0x76, 0x61, 0x6E, 0x63, 0x65, 0x20, 0x6F,
    0x6E, 0xCD, 0x77, 0x68, 0x65, 0x6E, 0x20, 0x79,
    0x6F, 0x75, 0x20, 0x77, 0x61, 0x6E, 0x74, 0x20,
    0x74, 0x6F, 0x20, 0x6C, 0x65, 0x61, 0x76, 0x65,
    0x2E, 0xCD, 0x7F, 0x00, 0xCD, 0x7F, 0x68, 0x7F,
    0x66, 0x0D, 0x15, 0x54, 0x72, 0x61, 0x6E, 0x73,
    0x6D, 0x69, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0x20,
    0x63, 0x6F, 0x6D, 0x70, 0x6C, 0x65, 0x74, 0x65,
    0x2E, 0xCD, 0x7F, 0x00, 0x7F, 0x67, 0x21, 0x7F,
    0x66, 0x09, 0x03, 0x59, 0x65, 0x73, 0xCD, 0x7F,
    0x67, 0x21, 0x7F, 0x66, 0x09, 0x08, 0x52, 0x65,
    0x64, 0x65, 0x73, 0x69, 0x67, 0x6E, 0xCD, 0x7F,
    0x67, 0x21, 0x7F, 0x66, 0x09, 0x0C, 0x54, 0x68,
    0x72, 0x6F, 0x77, 0x20, 0x69, 0x74, 0x20, 0x6F,
    0x75, 0x74, 0xCD, 0x7F, 0x00, 0xCD, 0x7F, 0x68,
    0x7F, 0x66, 0x0D, 0x0B, 0x43, 0x68, 0x65, 0x63,
    0x6B, 0x69, 0x6E, 0x67, 0x2E, 0x2E, 0x2E, 0xCD,
    0x7F, 0x01
};

// @0x02035778 - big endian byte array
static u8 sMsgOffsets[31][4] = {
    {0x00, 0x00, 0x00, 0x72},
    {0x00, 0x00, 0x00, 0xFE},
    {0x00, 0x00, 0x01, 0x1F},
    {0x00, 0x00, 0x01, 0x79},
    {0x00, 0x00, 0x01, 0xAD},
    {0x00, 0x00, 0x02, 0x17},
    {0x00, 0x00, 0x02, 0x46},
    {0x00, 0x00, 0x02, 0xB3},
    {0x00, 0x00, 0x03, 0x0B},
    {0x00, 0x00, 0x03, 0x42},
    {0x00, 0x00, 0x03, 0x8F},
    {0x00, 0x00, 0x03, 0xFA},
    {0x00, 0x00, 0x04, 0x39},
    {0x00, 0x00, 0x04, 0x55},
    {0x00, 0x00, 0x04, 0x76},
    {0x00, 0x00, 0x04, 0x97},
    {0x00, 0x00, 0x04, 0xC0},
    {0x00, 0x00, 0x05, 0x00},
    {0x00, 0x00, 0x05, 0x3E},
    {0x00, 0x00, 0x05, 0x5A},
    {0x00, 0x00, 0x05, 0x79},
    {0x00, 0x00, 0x05, 0xB2},
    {0x00, 0x00, 0x06, 0x07},
    {0x00, 0x00, 0x06, 0x3D},
    {0x00, 0x00, 0x06, 0x53},
    {0x00, 0x00, 0x06, 0x9C},
    {0x00, 0x00, 0x07, 0x01},
    {0x00, 0x00, 0x07, 0x6C},
    {0x00, 0x00, 0x07, 0x8C},
    {0x00, 0x00, 0x07, 0xBD},
    {0x00, 0x00, 0x07, 0xD2},
};

// @0x0202AB54
static mFont_ControlCodeInfo_c sMsgControlCodeInfo[] = {
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_LAST
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_CONTINUE
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_CLEAR
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_CURSOR_SET_TIME
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_BUTTON
    {5, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_COLOR
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_ABLE_CANCEL
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_UNABLE_CANCEL
    {5, 0x01, 0x00, 0x00}, // mFont_CONT_CODE_SET_DEMO_ORDER_PLAYER
    {5, 0x01, 0x00, 0x00}, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC0
    {5, 0x01, 0x00, 0x00}, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC1
    {5, 0x01, 0x00, 0x00}, // mFont_CONT_CODE_SET_DEMO_ORDER_NPC2
    {5, 0x01, 0x00, 0x00}, // mFont_CONT_CODE_SET_DEMO_ORDER_QUEST
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_SELECT_WINDOW
    {4, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_F
    {4, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_0
    {4, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_1
    {4, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_2
    {4, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_3
    {6, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_2
    {8, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_3
    {10, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_4
    {6, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_SELECT_STRING_2
    {8, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_SELECT_STRING_3
    {10, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_SELECT_STRING_4
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_FORCE_NEXT
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_PLAYER_NAME
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_TALK_NAME
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_TAIL
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_YEAR
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_MONTH
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_WEEK
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_DAY
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_HOUR
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_MIN
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_SEC
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE0
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE1
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE2
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE3
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE4
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE5
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE6
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE7
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE8
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE9
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_DETERMINATION
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_COUNTRY_NAME
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_RANDOM_NUMBER_2
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_ITEM0
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_ITEM1
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_ITEM2
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_ITEM3
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_ITEM4
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE10
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE11
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE12
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE13
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE14
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE15
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE16
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE17
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE18
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_FREE19
    {2, 0x02, 0x00, 0x00}, // mFont_CONT_CODE_PUT_STRING_MAIL
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY0
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY1
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY2
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY3
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY4
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY5
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY6
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY7
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY8
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_PLAYER_DESTINY9
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_NORMAL
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_ANGRY
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SAD
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_FUN
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_SLEEPY
    {6, 0x05, 0x00, 0x00}, // mFont_CONT_CODE_SET_COLOR_CHAR
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SOUND_CUT
    {3, 0x04, 0x00, 0x00}, // mFont_CONT_CODE_SET_LINE_OFFSET
    {3, 0x04, 0x00, 0x00}, // mFont_CONT_CODE_SET_LINE_TYPE
    {3, 0x05, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHAR_SCALE
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_BUTTON2
    {4, 0x06, 0x00, 0x00}, // mFont_CONT_CODE_BGM_MAKE
    {4, 0x06, 0x00, 0x00}, // mFont_CONT_CODE_BGM_DELETE
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_MSG_TIME_END
    {3, 0x07, 0x00, 0x00}, // mFont_CONT_CODE_SOUND_TRG_SYS
    {3, 0x04, 0x00, 0x00}, // mFont_CONT_CODE_SET_LINE_SCALE
    {2, 0x07, 0x00, 0x00}, // mFont_CONT_CODE_SOUND_NO_PAGE
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_VOICE_TRUE
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_VOICE_FALSE
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SELECT_NO_B
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_GIVE_OPEN
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_GIVE_CLOSE
    {2, 0x03, 0x00, 0x00}, // mFont_CONT_CODE_SET_MESSAGE_CONTENTS_GLOOMY
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SELECT_NO_B_CLOSE
    {6, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_NEXT_MESSAGE_RANDOM_SECTION
    {3, 0x08, 0x00, 0x00}, // mFont_CONT_CODE_UNKNOWN_100
    {3, 0x08, 0x00, 0x00}, // mFont_CONT_CODE_UNKNOWN_101
    {4, 0x08, 0x00, 0x00}, // mFont_CONT_CODE_SET_TEMPORARY_COLOR
    {3, 0x04, 0x00, 0x00}, // mFont_CONT_CODE_SPACE
    {2, 0x08, 0x00, 0x00}, // mFont_CONT_CODE_MOVE_DOWN
    {2, 0x08, 0x00, 0x00}, // mFont_CONT_CODE_RESTORE_CACHED_MESSAGE
    {6, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_MALE_FEMALE_CHECK
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHOICE_COUNT_2
    {2, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHOICE_COUNT_3
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHOICE_TEXT_0
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHOICE_TEXT_1
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_SET_CHOICE_TEXT_2
    {3, 0x00, 0x00, 0x00}, // mFont_CONT_CODE_CHECK_CHOICE
};

/* Message and font routines recovered from the m2c seed output. */
s32 mMsg_CheckChoiceNext(mMsg_Window_c *msg) {
    s32 result;
    s32 button;

    if (msg->message_id == 0x19) {
        result = 0;
        button = DPAD_DOWN;
    } else {
        result = 0;
        button = DPAD_RIGHT;
    }
    if ((button & gGameState.keys_pressed) && ((s32) (msg->choice_count - 1) > (s32) msg->choice_index)) {
        result = 1;
    }
    return result;
}

s32 mMsg_CheckChoicePrevious(mMsg_Window_c *msg) {
    s32 button;
    u32 result;

    if (msg->message_id == 0x19) {
        result = 0;
        button = DPAD_UP;
    } else {
        result = 0;
        button = DPAD_LEFT;
    }
    if (button & gGameState.keys_pressed) {
        u8 choice_index = msg->choice_index;
        result = (u32) ((0 - choice_index) | choice_index) >> 0x1F;
    }
    return (s32) result;
}

void mMsg_UpdateChoiceCursorPosition(mMsg_Window_c *msg) {
    m_msg_sprite_c *cursor;

    cursor = msg->choice_cursor;
    if (cursor != NULL) {
        cursor->_30 = (msg->choices[msg->choice_index].line + 7) * 8;
        cursor->_2C = msg->choices[msg->choice_index].x + 0x2F;
    }
}

void mMsg_UpdateChoiceHighlight(mMsg_Window_c *msg) {
    void *choice_tiles[5];
    s8 tile_stride;
    u16 first_choice_tile;

    choice_tiles[0] = gMsgThreeChoiceHighlightTiles[0];
    choice_tiles[1] = gMsgThreeChoiceHighlightTiles[1];
    choice_tiles[2] = gMsgThreeChoiceHighlightTiles[2];
    choice_tiles[3] = gMsgTwoChoiceHighlightTiles[0];
    choice_tiles[4] = gMsgTwoChoiceHighlightTiles[1];
    tile_stride = msg->tile_stride;
    first_choice_tile = tile_stride * msg->choices[0].line;
    if (msg->message_id == 0x19) {
        CpuFastSet(choice_tiles[msg->choice_index], gMsgVram + (first_choice_tile << 5), (tile_stride * 0x30) & 0x1FFFFF);
        CpuFastSet(choice_tiles[msg->choice_index], msg->tile_data + (first_choice_tile << 5), (msg->tile_stride * 0x30) & 0x1FFFFF);
        return;
    }
    CpuFastSet(choice_tiles[msg->choice_index + 3], gMsgVram + (first_choice_tile << 5), (tile_stride * 0x10) & 0x1FFFFF);
    CpuFastSet(choice_tiles[msg->choice_index + 3], msg->tile_data + (first_choice_tile << 5), (msg->tile_stride * 0x10) & 0x1FFFFF);
}

void mMsg_MainSetup_Choice(mMsg_Window_c *msg) {
    msg->choice_cursor = sub_0201C310(0xBU, 0, 0, 0);
    mMsg_UpdateChoiceCursorPosition(msg);
    mMsg_UpdateChoiceHighlight(msg);
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
}

void mMsg_Main_Choice(mMsg_Window_c *msg) {
    u16 sound;
    s8 choice_index;

    if (msg->selected_choice != -1) {
        if (mMsg_TimerDec(msg) != 0) {
            mMsg_MainSetup_Window(msg);
        }
    } else {
        if (msg->choice_cursor == NULL) {
            msg->choice_cursor = sub_0201C310(0xBU, 0, 0, 0);
            mMsg_UpdateChoiceCursorPosition(msg);
            mMsg_UpdateChoiceHighlight(msg);
            return;
        }
        if ((A_BUTTON & gGameState.keys_pressed) && (mMsg_RequestCursor(msg) != 0)) {
            msg->force_next = 1;
            choice_index = msg->choice_index;
            msg->selected_choice = choice_index;
            __asm__("" : "+r" (choice_index)); // @HACK
            sound = choice_index == 0 ? 0x10 : 0x11;
            mMsg_SetTimer(msg, 0x14);
            sub_02019D78(sound);
            return;
        }
        if (mMsg_CheckChoiceNext(msg) != 0) {
            msg->choice_index += 1;
            sub_02019D78(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        if (mMsg_CheckChoicePrevious(msg) != 0) {
            msg->choice_index -= 1;
            sub_02019D78(0xFU);
            mMsg_UpdateChoiceHighlight(msg);
        }
        mMsg_UpdateChoiceCursorPosition(msg);
    }
}

void mMsg_MainSetup_DisappearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 12;
    msg->saved_mode = msg->current_mode;
    msg->current_mode = msg->requested_mode;
    msg->requested_mode = -1;
    sub_02019D78(0x20U);
}

void mMsg_Main_DisappearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0) {
        msg->transition_frame = (u8) msg->transition_frame - 1;
        return;
    }
    msg->draw_enabled = 0;
}

void mMsg_MainSetup_AppearWait(mMsg_Window_c *msg) {
    msg->transition_frame = 0;
    msg->current_mode = (s8) (u8) msg->requested_mode;
    msg->requested_mode = -1;
    sub_02019D78(0x1FU);
}

void mMsg_Main_AppearWait(mMsg_Window_c *msg) {
    gGameState.bg3_vofs = (u16) mMsg_GetWindowScrollOffset(&msg->transition_frame);
    if ((s32) msg->transition_frame > 0xA) {
        msg->current_mode = msg->saved_mode;
        msg->draw_enabled = 1;
        return;
    }
    msg->transition_frame = (u8) msg->transition_frame + 1;
}

void mMsg_CopyTilesToVram(s32 tile, s32 count, u8 *tile_data) {
    if (count > 0) {
        CpuFastSet(tile_data + (s32)(tile << 5), gMsgVram + (s32)(tile << 5), (count * 8) & 0x1FFFFF);
    }
}

s32 mMsg_GetWindowScrollOffset(s8 *frame) {
    if (*frame >= 12) {
        *frame = 11;
    }
    if (*frame < 0) {
        *frame = 0;
    }

    return gMsgWindowScrollOffsets[(s8) (u8) *frame];
}

s8 mMsg_RequestMode(mMsg_Window_c *msg, s8 mode) {
    msg->requested_mode = mode;
    return 1;
}

s8 mMsg_RequestDisappear(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR);
}

s8 mMsg_RequestAppear(mMsg_Window_c *msg, s32 message_id) {
    s8 result;

    result = mMsg_RequestMode(msg, mMsg_MODE_APPEAR);
    if (result == 1) {
        msg->next_message_id = message_id;
    }
    return result;
}

s8 mMsg_RequestCursor(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CURSOR);
}

s8 mMsg_RequestNormal(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_NORMAL);
}

s8 mMsg_RequestHide(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_HIDE);
}

s8 mMsg_RequestChoice(mMsg_Window_c *msg) {
    return mMsg_RequestMode(msg, mMsg_MODE_CHOICE);
}

s8 mMsg_RequestDisappearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_CURSOR || msg->current_mode == mMsg_MODE_NORMAL || msg->current_mode == mMsg_MODE_CHOICE) {
        return mMsg_RequestMode(msg, mMsg_MODE_DISAPPEAR_WAIT);
    }

    return 0;
}

s8 mMsg_RequestAppearWait(mMsg_Window_c *msg) {
    if (msg->current_mode == mMsg_MODE_DISAPPEAR_WAIT) {
        return mMsg_RequestMode(msg, mMsg_MODE_APPEAR_WAIT);
    }

    return 0;
}

// @0x020191e8
s8 mMsg_GetMessageBody(u32 index, u8 **data, u16 *size) {
    s32 message_offset;
    u32 message_size;
    u32 msg_ofs;
    u8* msg_ofs_ptr;
    u8* message_offset_ptr;

    if (index >= 0x1F) {
        *data = NULL;
        *size = 0;
        return 0;
    }
    if (index != 0) {
        message_offset_ptr = (u8*)&message_offset;
        msg_ofs = *(u32*)sMsgOffsets[index - 1];
        msg_ofs_ptr = (u8*)&msg_ofs;

        message_offset_ptr[0] = msg_ofs_ptr[3];
        message_offset_ptr[1] = msg_ofs_ptr[2];
        message_offset_ptr[2] = msg_ofs_ptr[1];
        message_offset_ptr[3] = msg_ofs_ptr[0];
    } else {
        message_offset = 0;
    }
    message_offset_ptr = (u8*)&message_offset;
    msg_ofs = *(u32*)sMsgOffsets[index];
    msg_ofs_ptr = (u8*)&msg_ofs;

    message_offset_ptr[0] = msg_ofs_ptr[3];
    message_offset_ptr[1] = msg_ofs_ptr[2];
    message_offset_ptr[2] = msg_ofs_ptr[1];
    message_offset_ptr[3] = msg_ofs_ptr[0];

    message_size = msg_ofs - message_offset;
    if (message_size < 0x200) {
        *data = &gMsgTextData[message_offset];
        *size = (u16)message_size;
    } else {
        *size = 0;
        *data = NULL;
    }
    return 1;
}

s16 mMsg_GetMessageLength(u8 *text) {
    s32 offset;
    u8 *next;
    u8 control_code;

    offset = 0;
loop_1:
    offset += mFont_CodeSize_get(&text[offset]);
    next = &text[offset];
    if ((next[0] != CHAR_CONTROL_CODE) ||
        ((control_code = next[1], (control_code != mFont_CONT_CODE_MSG_TIME_END)) &&
         (control_code != mFont_CONT_CODE_LAST) && (control_code != mFont_CONT_CODE_CONTINUE))) {
        if (offset <= 0x1FF) {
            goto loop_1;
        }
    }
    return (s16) offset;
}

s8 mFont_CodeSize_get(u8 *code) {
    u8 size;

    if (code[0] == CHAR_CONTROL_CODE) {
        size = sMsgControlCodeInfo[code[1]].size;
    } else {
        size = 1;
    }
    return (s8) size;
}

s16 mMsg_LoadMessage(u8 *text, s32 index) {
    u16 size;
    u8 *source;

    if ((mMsg_GetMessageBody((u32) index, &source, &size) == 1) && (source != NULL) && ((s16) size != 0)) {
        mMsg_Copy(source, text, (s32) (s16) size);
        return mMsg_GetMessageLength(text);
    }
    return 0;
}

void mMsg_ClearText(mMsg_Window_c *msg) {
    CpuFastFill(0x55555555, msg->tile_data, 0x1200);
    mMsg_CopyTilesToVram(0, 0x90, msg->tile_data);
    msg->text_x = msg->text_start_x;
    msg->text_row = 0;
    msg->temporary_color_length = 0;
}

s32 mMsg_ChangeMsgData(mMsg_Window_c *msg, s32 index) {
    s32 result;

    result = 0;
    if (((u32) index <= 0x1EU) && ((mMsg_LoadMessage(msg->text, index) << 0x10) != 0)) {
        msg->message_id = index;
        msg->next_message_id = -1;
        msg->text_offset = 0;
        mMsg_ClearText(msg);
        mMsg_SetTimer(msg, 0x14);
        result = 1;
    }
    return result;
}

void mMsg_SetTimer(mMsg_Window_c *msg, s32 frames) {
    msg->text_delay_timer = frames;
}

s32 mMsg_TimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->text_delay_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->text_delay_timer = next_timer;
    return expired;
}

void mMsg_SetEndTimer(mMsg_Window_c *msg, s32 frames) {
    msg->end_timer = frames;
}

s32 mMsg_EndTimerDec(mMsg_Window_c *msg) {
    s32 timer;
    s32 next_timer;
    s32 expired;

    expired = 0;
    timer = msg->end_timer;
    if (timer == 1) {
        expired = 1;
    }
    next_timer = 0;
    if (timer > 0) {
        next_timer = timer - 1;
    }
    msg->end_timer = next_timer;
    return expired;
}

void mMsg_DestroySprites(mMsg_Window_c *msg) {
    m_msg_sprite_c *sprite;

    sprite = msg->choice_cursor;
    if (sprite != NULL) {
        sub_0201C300(sprite);
        msg->choice_cursor = NULL;
    }
    sprite = msg->continue_prompt;
    if (sprite != NULL) {
        sub_0201C300(sprite);
        msg->continue_prompt = NULL;
    }
}

s32 mMsg_CheckControlCode(u8 *text, u8 type, s16 offset) {
    s32 result;
    u8 *code;

    result = 0;
    code = &text[offset];
    if ((code[0] == CHAR_CONTROL_CODE) && (code[1] == type)) {
        result = 1;
    }
    return result;
}

s32 mMsg_ProcessText(mMsg_Window_c *msg, u8 *tile_data, s32 max_characters) {
    u8 *destination;
    s32 result;
    s32 palette;
    s32 control_result;
    s32 glyph_width;
    s32 characters_processed;
    s8 tile_stride;
    u8 *code;
    u8 temporary_color_length;
    u8 character;

    destination = tile_data;
    result = 1;
    palette = 6;
    if (mMsg_TimerDec(msg) != 0) {
        return 1;
    }
    characters_processed = 0;
    if ((max_characters > 0) && (msg->text_delay_timer == 0)) {
loop_6:
        code = &msg->text[msg->text_offset];
        character = *code;
        if (character != 0xCD) {
            if (character == CHAR_CONTROL_CODE) {
                control_result = mMsg_ProcessControlCode(msg, &msg->text_offset);
                result = control_result;
                if ((u32) (control_result - 2) > 2U) {
                    goto block_17;
                }
            } else {
                glyph_width = mFont_GetGlyphWidth((u32) character);
                tile_stride = msg->tile_stride;
                if ((s32) (tile_stride * 8) >= (s32) ((msg->text_x - 1) + glyph_width)) {
                    temporary_color_length = msg->temporary_color_length;
                    if (temporary_color_length != 0) {
                        palette = (s32) msg->temporary_color;
                        msg->temporary_color_length = temporary_color_length - 1;
                    }
                    if (character == 0x20) {
                        character = 0x80;
                    }
                    mFont_DrawCharToTiles(destination + ((tile_stride * (s8) (u8) msg->text_row) << 5), (u16) msg->text_x, 0U, (u16) (s8) (u8) msg->tile_stride, (u8) (s32) character, (u8) palette, glyph_width - 1);
                    msg->text_x += glyph_width;
                }
                msg->text_offset = mFont_CodeSize_get(&msg->text[msg->text_offset]) + (u16) msg->text_offset;
                characters_processed += 1;
block_17:
                if ((characters_processed < max_characters) && (msg->text_delay_timer == 0)) {
                    goto loop_6;
                }
            }
        } else {
            msg->text_offset = mFont_CodeSize_get(code) + (u16) msg->text_offset;
            msg->text_x = msg->text_start_x;
            msg->text_row = ((u8) msg->text_row + 2) & ~1;
        }
    }
    return result;
}

void mMsg_Init(void) {
    u8 init_data[4];
    s32 i;

    memcpy(init_data, gMsgChoiceTemplateParams, sizeof(init_data));

    for (i = 0; i < 2; i++) {
        mMsg_Window_c* msg = &sMsgWindows[i];

        mMsg_InitWindow(msg, gMsgCodeBuffers + i * 0x220,
                        gMsgTileBuffers + i * 0x1200);
        msg->text_x = msg->text_start_x;
        msg->text_row = 0;
        msg->message_length = mMsg_LoadMessage(msg->text, 0x18);
        msg->text[5] = init_data[i * 2];
        msg->text[0xF] = init_data[i * 2 + 1];
        msg->tile_data = gMsgWindowTileData + i * 0x480;
        CpuFastFill(0x55555555, msg->tile_data, 0x480);

        while (mMsg_ProcessText(msg, msg->tile_data, 1) == 1) {
        }
    }

    for (i = 0; i < ARRAY_COUNT(sMsgWindows); i++) {
        mMsg_Window_c* msg = &sMsgWindows[i];
        u16 saved_text_offset;

        mMsg_InitWindow(msg, gMsgCodeBuffers + i * 0x220,
                        gMsgTileBuffers + i * 0x1200);
        mMsg_ClearText(msg);
        msg->message_id = sCachedMessageIds[i];
        msg->message_length = mMsg_LoadMessage(msg->text, msg->message_id);
        msg->current_mode = mMsg_MODE_CURSOR;

        do {
            saved_text_offset = msg->text_offset;
        } while (mMsg_ProcessText(msg, msg->tile_data, 1) == 1);
        msg->text_offset = saved_text_offset;
    }
}

void mMsg_MainSetup_Window(mMsg_Window_c *msg) {
    // TODO: chained conditional comparison that got optimized
    if (((u8)(msg->requested_mode - 1) <= 8U) && (gMsgModeSetupCallbacks[msg->requested_mode] != NULL)) {
        mMsg_DestroySprites(msg);
        gMsgModeSetupCallbacks[msg->requested_mode](msg);
    }
}

void mMsg_InitWindow(mMsg_Window_c *msg, u8 *text, u8 *tile_data) {
    CpuFastFill(0, msg, sizeof(*msg));
    msg->tile_data = tile_data;
    msg->text = text;
    msg->next_message_id = -1;
    msg->message_id = -1;
    msg->current_mode = mMsg_MODE_HIDE;
    msg->requested_mode = -1;
    msg->selected_choice = -1;
    msg->tile_stride = 0x12;
    msg->text_start_x = 1;
    msg->draw_enabled = 0;
}

void mMsg_Main_Window(mMsg_Window_c *msg) {
    void (*main)(mMsg_Window_c *);

    main = gMsgModeCallbacks[(s8) (u8) msg->current_mode];
    if (main != NULL) {
        main(msg);
    }
}

s32 mFont_DrawStringToTiles(u8 *tile_data, u16 *cursor, u32 packed_position, u16 glyph_height, u8 *text, s32 length, u8 palette, u8 stop_at_newline, u8 fixed_width) {
    u8 *destination;
    s32 palette_index;
    s32 stop_on_newline;
    s32 use_fixed_width;
    s32 character_width;
    s32 characters_drawn;
    u16 current_x;
    u16 tile_stride;
    u32 position;
    u8 character;

    destination = tile_data;
    position = packed_position << 0x10;
    tile_stride = glyph_height;
    palette_index = (s32) (u8) (s32) palette;
    stop_on_newline = (s32) (u8) (s32) stop_at_newline;
    use_fixed_width = (s32) (u8) (s32) fixed_width;
    characters_drawn = 0;
loop_2:
    if ((characters_drawn < length) && ((character = text[characters_drawn], (stop_on_newline != 1)) || (character != CHAR_NEW_LINE)) && (character != CHAR_CONTROL_CODE)) {
        if (use_fixed_width != 1) {
            character_width = mFont_GetGlyphWidth((u32) character);
        } else {
            character_width = 8;
        }
        current_x = *cursor;
        if ((s32) (character_width + current_x) <= (s32) (tile_stride * 8)) {
            mFont_DrawCharToTiles(destination + (((position >> 0x13) * tile_stride) << 5), current_x, (u16) ((u32) (0x70000 & position) >> 0x10), tile_stride, (u8) (s32) character, (u8) palette_index, character_width - 1);
            *cursor += character_width;
            characters_drawn += 1;
            goto loop_2;
        }
    }
    return characters_drawn;
}

void mFont_DrawCharToTiles(u8 *tile_data, u16 tile_offset, u16 row, u16 tile_stride, u8 character, u8 palette, s32 width) {
    gMsgGlyph.tile_data = tile_data;
    gMsgGlyph.tile_offset = tile_offset;
    gMsgGlyph.row = row;
    gMsgGlyph.tile_stride = tile_stride;
    gMsgGlyph.palette = (u8) (s32) palette;
    mFont_GetGlyphRows(gMsgGlyph.glyph_lower_rows, gMsgGlyph.glyph_upper_rows, (u8) (s32) character);
    mFont_BlitGlyphToTiles(&gMsgGlyph, width);
}

void sub_020198B8(s8 index) {
    void* dest[3];
    void* src[3];
    u32 size[3];

    dest[0] = gUnk_0202AD1C[0];
    dest[1] = gUnk_0202AD1C[1];
    dest[2] = gUnk_0202AD1C[2];
    memset(src, 0, sizeof(src));
    size[0] = gUnk_0202AD28[0];
    size[1] = gUnk_0202AD28[1];
    size[2] = gUnk_0202AD28[2];

    if (index >= 0) {
        CpuFastSet(src[index], dest[index], (size[index] << 9) >> 11);
    }
}

void sub_02019910(u8 value, s8 index) {
    void* dest[3];
    u32 size[3];
    s32 sp18;
    s32 i;

    memset(dest, 0, sizeof(dest));
    size[0] = gUnk_0202AD28[0];
    size[1] = gUnk_0202AD28[1];
    size[2] = gUnk_0202AD28[2];

    if (index >= 0) {
        sp18 = 0;
        for (i = 0; i < 8; i++) {
            sp18 |= (value & 0xF) << (i * 4);
        }
        CpuFastFill(sp18, dest[index], size[index]);
    }
}

void mFont_BlitGlyphToTiles(mFont_GlyphDraw_c *glyph, s32 width) {
    s32 glyph_width;
    s32 glyph_row;
    s32 next_glyph_row;
    s32 next_y;
    s32 tile_row_byte_offset;
    s32 color_bits;
    s32 lower_color_bits;
    s32 preserved_bits;
    s32 lower_preserved_bits;
    s32 column;
    u16 byte_offset;
    u16 lower_byte_offset;
    u16 tile_index;
    u16 x;
    u16 y;
    u8 *destination;
    u8 *lower_destination;
    u8 packed_pixels;
    u8 lower_packed_pixels;

    glyph_width = width;
    glyph_row = 0;
    y = glyph->row;
loop_1:
    column = 0;
    x = glyph->tile_offset;
    next_glyph_row = glyph_row + 1;
    next_y = y + 1;
    if (glyph_width > 0) {
        tile_row_byte_offset = (y & 7) * 4;
        do {
            tile_index = ((y >> 3) * glyph->tile_stride) + (x >> 3);
            if (((s32) glyph->glyph_upper_rows[glyph_row] >> column) & 1) {
                byte_offset = (tile_index << 5) + tile_row_byte_offset + ((u32) (x & 7) >> 1);
                destination = glyph->tile_data;
                packed_pixels = destination[byte_offset];
                if (x & 1) {
                    preserved_bits = packed_pixels & 0xF;
                    color_bits = (0xF & glyph->palette) * 0x10;
                } else {
                    preserved_bits = packed_pixels & 0xF0;
                    color_bits = 0xF & glyph->palette;
                }
                destination[byte_offset] = preserved_bits | color_bits;
            }
            if (((s32) glyph->glyph_lower_rows[glyph_row] >> column) & 1) {
                lower_byte_offset = ((u16) (tile_index + glyph->tile_stride) << 5) + tile_row_byte_offset + ((u32) (x & 7) >> 1);
                lower_destination = glyph->tile_data;
                lower_packed_pixels = lower_destination[lower_byte_offset];
                if (x & 1) {
                    lower_preserved_bits = lower_packed_pixels & 0xF;
                    lower_color_bits = (0xF & glyph->palette) * 0x10;
                } else {
                    lower_preserved_bits = lower_packed_pixels & 0xF0;
                    lower_color_bits = 0xF & glyph->palette;
                }
                lower_destination[lower_byte_offset] = lower_preserved_bits | lower_color_bits;
            }
            column += 1;
            x += 1;
        } while (column < glyph_width);
    }
    glyph_row = next_glyph_row;
    y = (u16) next_y;
    if (next_glyph_row <= 7) {
        goto loop_1;
    }
}

s16 sub_02019ABC(s16 lhs, s16 rhs) {
    s32 var_r0_3371;

    var_r0_3371 = rhs * lhs;
    if (var_r0_3371 < 0) {
        var_r0_3371 += 0xFF;
    }
    return (s16) ((s32) (var_r0_3371 << 8) >> 0x10);
}

s16 sub_02019AD8(s16 numerator, s16 denominator) {
    return (s16) (((s32) (numerator << 0x10) >> 8) / (s32) denominator);
}

u16 sub_02019AF0(GameState *state) {
    u32 temp_r0_3407;

    temp_r0_3407 = (state->rngValue * 0x41C64E6D) + (state->unk_85B + 0x3039);
    state->rngValue = temp_r0_3407;
    return (u16) ((u32) (temp_r0_3407 * 2) >> 0x11);
}

void sub_02019B18(GameState *state, u32 seed) {
    state->rngValue = seed;
}

void sub_02019B1C(GameState *state, u16 target, u16 blend_control, u16 intensity) {
    s32 var_r0_3434;
    u16 var_r3_3431;

    var_r3_3431 = intensity;
    if (target == 1) {
        var_r0_3434 = 0xC0;
    } else {
        var_r0_3434 = 0x80;
    }
    state->unk_820 = blend_control | var_r0_3434;
    if ((u32) var_r3_3431 > 0x10U) {
        var_r3_3431 = 0x10;
    }
    state->unk_81E = var_r3_3431;
}

u16 sub_02019B58(GameState *state, u8 direction, u8 amount) {
    s32 temp_r0_3473;
    s32 temp_r0_3486;
    u16 temp_r0_3472;
    u16 temp_r0_3485;
    u16 var_r3_3469;
    u8 temp_r1_3463;
    u8 temp_r2_3465;

    temp_r1_3463 = direction;
    temp_r2_3465 = amount;
    var_r3_3469 = state->unk_81E;
    if (temp_r1_3463 == 1) {
        temp_r0_3472 = var_r3_3469 + temp_r2_3465;
        temp_r0_3473 = temp_r0_3472 << 0x10;
        var_r3_3469 = temp_r0_3472;
        if ((s32) (temp_r0_3473 >> 0x10) > 0x10) {
            var_r3_3469 = 0x10;
        }
    } else if (temp_r1_3463 == 0) {
        temp_r0_3485 = var_r3_3469 - temp_r2_3465;
        temp_r0_3486 = temp_r0_3485 << 0x10;
        var_r3_3469 = temp_r0_3485;
        if (temp_r0_3486 < 0) {
            var_r3_3469 = 0;
        }
    }
    state->unk_81E = var_r3_3469;
    return state->unk_81E;
}

void sub_02019BA8(u16 *palette, u8 x, u8 y, u8 *red, u8 *green, u8 *blue) {
    u16 temp_r1_3514;

    temp_r1_3514 = palette[((0xF & x) * 0x10) + (y & 0xF)];
    *blue = (temp_r1_3514 >> 0xA) & 0x1F;
    *green = (temp_r1_3514 >> 5) & 0x1F;
    *red = temp_r1_3514 & 0x1F;
}

void sub_02019BD8(u8 palette, u8 x, u8 y, u8 red, u8 green, u8 blue) {
    u16 *var_r5_3547;

    var_r5_3547 = (u16 *)0x02000000;
    if (palette == 1) {
        var_r5_3547 = gObjPaletteBuffer;
    }
    var_r5_3547[((x & 0xF) * 0x10) + (y & 0xF)] = (red & 0x1F) | ((((u8) (s32) blue & 0x1F) << 0xA) | (((u8) (s32) green & 0x1F) << 5));
    gGameState.unk_852 = 1;
}

void sub_02019C3C(void) {
    gGameState.unk_814 &= 0xFFFE;
    if (!(1 & gGameState.unk_814)) {
        do {

        } while (!(1 & gGameState.unk_814));
    }
    gGameState.unk_814 &= 0xFFFE;
}

void sub_02019C88(void) {
    u32 *end;
    u32 *oam;

    oam = (u32*)gUnk3002410;
    end = (u32*)(gUnk3002410 + sizeof(gUnk3002410));
    while (oam < end) {
        *oam++ = gUnk_0202AFB4[0];
        *oam++ = gUnk_0202AFB4[1];
    }
    gGameState.unk_860 = 0;
}

void sub_02019CC0(void) {
    u16 temp_r2_3660;

    temp_r2_3660 = 0x3FF ^ REG_KEYINPUT;
    gGameState.keys_pressed = temp_r2_3660 & ~gGameState.keys_held;
    gGameState.keys_held = temp_r2_3660;
}

void sub_02019CFC(void) {
    REG_IME = 0;
    REG_DISPCNT = 0x80;
    REG_DISPSTAT = 8;
    REG_IE = 1;
    REG_IF = 1;
    REG_IME = 1;
}

void sub_02019D28(void) {
    sub_02026F0C();
}

void sub_02019D34(void) {
    sub_020269C8();
}

void sub_02019D40(void) {
    sub_02026F18();
}

void sub_02019D4C(void) {
    sub_020269E0();
}

void sub_02019D58(u16 value) {
    sub_02026B48(value);
}

void sub_02019D68(u16 value) {
    sub_02026BC8(value);
}

void sub_02019D78(u16 value) {
    sub_02026A38(value);
}

void sub_02019D88(u16 value) {
    sub_02026C10(value);
}

void sub_02019D98(u16 value) {
    sub_02026C68(value);
}

void mMsg_ReplaceChar(u8 *data, u8 from, u8 to, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (data[i] == from) {
                data[i] = to;
            }
        }
    }
}

s32 mMsg_TrimTrailingSpaces(u8 *data, s32 length) {
    s32 trimmed_length;

    trimmed_length = 0;
    if (length > 0) {
        trimmed_length = length;
        while (trimmed_length > 0 && *(data + trimmed_length - 1) == 0x80) {
            trimmed_length--;
        }
    }
    return trimmed_length;
}

s32 mMsg_StringsDiffer(u8 *lhs, u8 *rhs, s32 length) {
    s32 i = 0;

    if (length > 0) {
        for (; i < length; i++) {
            if (lhs[i] != rhs[i]) {
                break;
            }
        }
    }

    return i != length;
}

void mMsg_Copy(u8 *src, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = src[i];
        }
    }
}

void mMsg_Fill(u8 value, u8 *dest, s32 length) {
    s32 i;

    if (length > 0) {
        for (i = 0; i < length; i++) {
            dest[i] = value;
        }
    }
}

void sub_02019E88(void) {
    s32 sp0;

    RegisterRamReset(RESET_SOUND_REGS | RESET_REGS);
    sp0 = 0;
    REG_DMA3SAD = (u32)&sp0;
    REG_DMA3DAD = 0x03000000;
    REG_DMA3CNT = 0x85001E00;
    REG_WAITCNT = 0x4014;
    REG_DMA3SAD = 0x02029698;
    REG_DMA3DAD = 0x030023C0;
    REG_DMA3CNT = 0x8000001C;
    REG_DMA3SAD = (u32)_intr;
    REG_DMA3DAD = 0x03001B64;
    REG_DMA3CNT = 0x80000400;
    *(u32*)0x03007FFC = 0x03001B64;
    sub_02019D34();
}

/* Initial m2c reconstructions after sub_02019E88. */

#if 0
/* These bodies require field typing before they can enter the build. */

/* Forward declarations retain m2c's current inferred signatures. */
void sub_02019F08(void);
void sub_02019F0C(void);
void sub_0201A0C8(void);
void sub_0201A0D4(void);
s32 sub_0201A1FC(u32 *arg0);
void sub_0201A218(void);
void sub_0201A288(void);
void sub_0201A620(void);
s32 sub_0201A688(u8 arg0);
void sub_0201A6C8(void);
u8 sub_0201A714(void *arg0, s8 arg1);
s32 sub_0201A780(void *arg0, u8 arg1);
u8 sub_0201A7C8(s32 arg0);
s32 sub_0201A810(s16 *arg0, s32 arg1);
void sub_0201A854(void *arg0, s8 arg1);
void sub_0201AA98(void *arg0, u8 arg1);
void sub_0201AB3C(void *arg0, s8 arg1);
void sub_0201ABBC(void *arg0);
s32 sub_0201ABE4(void *arg0, u8 arg1);
s32 sub_0201AC38(void *arg0, u8 arg1);
s32 sub_0201AC8C(void *arg0, u8 arg1);
void sub_0201ACCC(void *arg0);
s8 sub_0201ACF8(void *arg0);
void sub_0201AD34(void *arg0);
s16 sub_0201AD84(void *arg0);
void sub_0201ADDC(void);
s32 sub_0201ADE0(void *arg0, s8 arg1);
s32 sub_0201ADE8(void *arg0);
s32 sub_0201ADF4(void *arg0);
s32 sub_0201AE00(void *arg0);
void sub_0201AE0C(void *arg0);
void sub_0201AE40(void *arg0);
void sub_0201AEBC(void *arg0);
void sub_0201AF48(void *arg0);
void sub_0201B04C(void *arg0);
void sub_0201B168(void);
void sub_0201B16C(void);
s32 sub_0201B18C(void *arg0, s8 arg1);
s32 sub_0201B194(void *arg0);
s32 sub_0201B1A0(void *arg0);
s32 sub_0201B1AC(void *arg0);
void sub_0201B1B8(void *arg0);
void sub_0201B1EC(void *arg0);
void sub_0201B238(void *arg0);
void sub_0201B2E8(void *arg0);
void sub_0201B328(void *arg0);
void sub_0201B420(void *arg0);
void sub_0201B464(void *arg0);
void sub_0201B4B0(void);
void sub_0201B594(void *arg0);
s32 sub_0201B680(void *arg0, s8 arg1);
s32 sub_0201B688(void *arg0);
s32 sub_0201B694(void *arg0);
s32 sub_0201B6A0(void *arg0);
s32 sub_0201B6AC(void *arg0);
s32 sub_0201B6B8(void *arg0);
s32 sub_0201B6C4(void *arg0);
void sub_0201B6D0(void *arg0);
void sub_0201B6FC(void *arg0);
void sub_0201B75C(void *arg0);
void sub_0201B7B0(void *arg0);
void sub_0201B824(void *arg0);
void sub_0201B90C(void *arg0);
void sub_0201B91C(void *arg0);
void sub_0201B960(void *arg0);
void sub_0201B970(void *arg0);
void sub_0201B994(void *arg0);
void sub_0201BA54(void *arg0);
void sub_0201BB20(void);
void sub_0201BB24(void);
s32 sub_0201BB44(void *arg0, s8 arg1);
void sub_0201BB4C(void *arg0);
void sub_0201BB58(void *arg0);
void sub_0201BB64(void *arg0);
void sub_0201BB70(void *arg0);
void sub_0201BB7C(void *arg0);
void sub_0201BB88(void *arg0);
void sub_0201BBB4(void *arg0);
void sub_0201BBF8(void *arg0);
void sub_0201BCA4(void *arg0);
void sub_0201BD7C(void *arg0);
void sub_0201BDA8(void *arg0);
void sub_0201BDC4(void *arg0);
void sub_0201BDE8(void *arg0);
void sub_0201BE3C(void *arg0);
void sub_0201BE68(void *arg0);
void sub_0201BEB0(void *arg0);
void sub_0201BF10(void);
void sub_0201BF58(void);
void sub_0201C198(void);
u16 sub_0201C19C(void);
void sub_0201C1B8(void);
void sub_0201C1C4(void *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
void sub_0201C2E0(void);
void sub_0201C300(m_msg_sprite_c *sprite);
m_msg_sprite_c *sub_0201C310(u8 type, s32 x, s32 y, s32 param);
s32 sub_0201C3C8(u8 arg0);
s32 sub_0201C3F8(void *arg0, s32 arg1);
void sub_0201C428(void *arg0, s32 arg1, s16 arg2);
void sub_0201C444(void *arg0, s32 arg1);
void sub_0201C490(void *arg0, void *arg1, void *arg2);
void sub_0201C5A0(void);
void sub_0201C5F8(void);
void sub_0201C5FC(s32 arg0);
void sub_0201C668(void *arg0);
void sub_0201C69C(void *arg0);
void sub_0201C6C8(void);
void sub_0201C6CC(void *arg0);
void sub_0201C6EC(void *arg0);
void sub_0201C740(void);
void sub_0201C744(void *arg0);
void sub_0201C768(void);
void sub_0201C76C(void *arg0);
void sub_0201C78C(void *arg0);
void sub_0201C7E0(void);
void sub_0201C870(void);
s32 sub_0201C8C0(void);
void sub_0201CB50(void);
s32 sub_0201CDA0(u16 arg0, s32 arg1, u8 arg2, M2C_UNK arg3);
void sub_0201CF3C(u16 arg0, s32 arg1, u8 arg2, M2C_UNK arg3);
void sub_0201D19C(void);
void sub_0201D550(void);
void sub_0201D5C4(void);
void sub_0201D7AC(void);
u8 sub_0201D800(u8 arg0);
u8 sub_0201D904(void);
void sub_0201D94C(void);
void sub_0201DCE4(void);
void sub_0201DD24(void);
void sub_0201DD64(void);
void sub_0201DD94(void);
void sub_0201DF9C(s32 arg0, s32 arg1, s8 arg2, u8 arg3);
void sub_0201E030(void);
void sub_0201E034(void);
void sub_0201E038(u8 arg1);
void sub_0201E060(void *arg0, s32 arg1, u8 arg2);
void sub_0201E178(s32 arg0, u8 arg1);
void sub_0201E1E0(s32 arg0, s32 arg1, u8 arg2);
void sub_0201E230(s32 arg0);
void sub_0201E27C(s32 arg0, M2C_UNK arg3);
void sub_0201E3DC(s32 arg0, u8 arg1);
void sub_0201E430(s32 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_0201E538(s32 arg0);
void sub_0201E560(void);
void sub_0201E564(s32 arg0);
void sub_0201E608(s32 arg0);
void sub_0201E710(s32 arg0);
void sub_0201EB48(s32 arg0);
void sub_0201EC6C(s32 arg0);
void sub_0201ED50(s32 arg0);
void sub_0201ED68(void *arg0, s32 arg1);
void sub_0201EF44(s32 arg0);
s32 sub_0201EFB8(u16 arg0, u16 arg1);
s16 sub_0201F030(void);
s32 sub_0201F0FC(u8 arg0);
s32 sub_0201F368(void);
s32 sub_0201F3F8(s32 arg0, s32 arg1, u8 arg2, M2C_UNK arg3);
void sub_0201F538(void);
void sub_0201F660(s32 arg0, u8 arg1, u16 arg2, u16 arg3);
s8 sub_0201F6DC(u16 arg0, u16 *arg1);
u8 sub_0201F78C(u8 arg0);
s32 sub_0201F844(u8 arg0);
void sub_0201F8FC(u16 arg0);
void sub_0201FB9C(void);
void sub_0201FCB0(void);
s32 sub_0201FD1C(s32 arg0, s32 arg1);
s8 sub_0201FDF4(u8 arg0);
void sub_0201FE6C(s32 arg0);
s32 sub_0201FED4(u8 arg0, u8 arg1);
s32 sub_0201FF48(u8 arg0, u8 arg1, u16 arg2, u16 arg3);
s32 sub_02020118(void *arg0, s32 arg1, s32 arg2);
void sub_0202029C(void *arg0);
s32 sub_02020480(M2C_UNK arg3);
void sub_020205E0(void);
void sub_02020790(void);
s32 sub_020207C0(u8 arg0, s32 arg1);
s32 sub_02020814(u8 arg0, s32 arg1);
u8 sub_0202086C(void);
s32 sub_020208BC(s32 arg0);
void sub_020209E0(void);
void sub_02020A0C(void *arg0, u16 arg1);
u16 sub_02020A24(s32 arg0);
s32 sub_02020A78(void);
void sub_02020B88(void);
s32 sub_02020D20(void);
void sub_02020DA8(void);
s32 sub_02020F54(void);
u16 sub_02021050(void);
s32 sub_020210D4(void);
s32 sub_020212F4(void);
void sub_020213DC(void);
void sub_02021574(void);
void sub_020215D0(void);
void sub_02021608(void);
void sub_02021720(void);
void sub_020217AC(void);
void sub_020218B0(void);
void sub_02021AD8(void);
void sub_02021BCC(void);
void sub_02021FA4(void);
void sub_02022054(void);
void sub_020221C0(void);
void sub_020222F8(void);
void sub_020223AC(void);
void sub_0202243C(void);
void sub_020224D8(void);
void sub_020226E8(void);
void sub_0202275C(void);
void sub_0202277C(void);
void sub_020227D8(void);
void sub_02022858(void);
void sub_020228A0(void);
void sub_02022914(void);
void sub_02022994(void);
void sub_02022AE4(void);
void sub_02022B44(void);
void sub_02022BE0(void);
void sub_02022C10(void);
void sub_02022C30(void);
void sub_02022C8C(void);
void sub_02022CAC(void);
void sub_02022E54(void);
void sub_02022EC0(void);
void sub_02022F28(void);
void sub_02022F84(void);
void sub_02023120(void);
void sub_02023304(void);
void sub_020233E4(void);
void sub_020234B0(void);
void sub_02023628(void);
void sub_020236B0(void);
void sub_020236D0(void);
void sub_02023738(void);
void sub_020237E8(void);
void sub_020238BC(void);
void sub_02023968(void);
void sub_02023994(M2C_UNK arg3);
void sub_02023B38(void);
void sub_02023B58(M2C_UNK arg3);
s32 sub_02023ED8(u16 arg0);
s32 sub_02023F0C(u16 arg0);
s32 sub_02023F38(u16 arg0);
s32 sub_02023F60(u16 arg0);
s32 sub_02024000(s32 arg0);
s32 sub_02024018(s32 arg0);
s32 sub_02024030(s32 arg0);
s32 sub_02024048(s32 arg0);
s32 sub_02024060(s32 arg0);
s32 sub_02024078(s32 arg0);
s32 sub_020240A0(s32 arg0);
s32 sub_020240B8(s32 arg0);
s32 sub_020240D0(s32 arg0);
s32 sub_020240E8(s32 arg0);
s32 sub_02024100(s32 arg0);
s32 sub_02024118(s32 arg0);
s32 sub_02024130(u16 arg0);
s32 sub_0202415C(u16 arg0);
s32 sub_020241A0(s32 arg0);
s32 sub_020241B8(s32 arg0);
s32 sub_020241D0(u16 arg0);
s32 sub_02024214(s32 arg0);
s32 sub_0202422C(s32 arg0);
s32 sub_02024244(s32 arg0);
s32 sub_0202425C(s32 arg0);
s32 sub_02024274(s32 arg0);
s32 sub_0202428C(u16 arg0);
s32 sub_020242B4(s32 arg0);
s32 sub_020242D0(s32 arg0);
s32 sub_020242EC(s32 arg0);
s32 sub_02024308(s32 arg0);
s32 sub_02024324(s32 arg0);
s32 sub_0202433C(u16 arg0);
s32 sub_02024378(u16 arg0);
s32 sub_020243B4(u16 arg0);
s32 sub_020243F0(u16 arg0);
s32 sub_02024428(u16 arg0);
s32 sub_02024450(s32 arg0);
s32 sub_02024468(u16 arg0);
s32 sub_02024490(u16 arg0);
s32 sub_020244B8(s32 arg0);
s32 sub_020244D0(s32 arg0);
s32 sub_020244EC(s32 arg0);
s32 sub_02024504(s32 arg0);
s32 sub_0202451C(s32 arg0);
s32 sub_02024534(s32 arg0);
s32 sub_0202454C(s32 arg0);
s32 sub_02024564(s32 arg0);
s32 sub_0202457C(s32 arg0);
s32 sub_02024594(s32 arg0);
s32 sub_020245AC(s32 arg0);
s32 sub_020245C4(s32 arg0);
s32 sub_020245DC(s32 arg0);
s32 sub_020245F4(s32 arg0);
s32 sub_0202460C(u16 arg0);
s32 sub_0202465C(u16 arg0);
s32 sub_020246AC(u16 arg0);
s32 sub_020246FC(u16 arg0);
s32 sub_0202474C(u16 arg0);
s32 sub_020247D4(s32 arg0);
s32 sub_020247EC(s32 arg0);
s32 sub_02024804(s32 arg0);
s32 sub_0202481C(s32 arg0);
s32 sub_02024834(s32 arg0);
s32 sub_0202484C(s32 arg0);
s32 sub_02024864(u16 arg0);
s32 sub_02024878(u16 arg0);
s32 sub_0202488C(u16 arg0);
s32 sub_020248A0(u16 arg0);
s32 sub_020248B4(s32 arg0);
s32 sub_020248CC(s32 arg0);
s32 sub_020248E4(s32 arg0);
s32 sub_020248FC(s32 arg0);
s32 sub_02024914(s32 arg0);
s32 sub_02024930(s32 arg0);
s32 sub_02024948(s32 arg0);
s32 sub_02024960(u16 arg0);
s32 sub_02024974(u16 arg0);
s32 sub_02024988(u16 arg0);
s32 sub_0202499C(u16 arg0);
s32 sub_020249B0(s32 arg0);
s32 sub_020249C8(u16 arg0);
s32 sub_020249F0(s32 arg0);
s32 sub_02024A0C(s32 arg0);
s32 sub_02024A24(s32 arg0);
s32 sub_02024A3C(s32 arg0);
s32 sub_02024A58(u16 arg0);
s32 sub_02024A84(s32 arg0);
s32 sub_02024A9C(u16 arg0);
u16 sub_02024AD0(u32 arg0);
u16 sub_02024AEC(u32 arg0);
void sub_02024B08(s32 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_02024C00(void);
void sub_02024C04(void);
void sub_02024C08(s32 arg0);
void sub_02024C44(s32 arg0);
void sub_02024DD0(s32 arg0);
void sub_02024DF8(s32 arg0);
void sub_02024F08(s32 arg0);
void sub_02024F8C(s32 arg0);
void sub_020250B0(s32 arg0);
void sub_020250EC(s32 arg0);
void sub_02025118(s32 arg0);
void sub_02025180(s32 arg0);
void sub_020251AC(s32 arg0);
void sub_02025210(s32 arg0);
void sub_0202529C(s32 arg0);
void sub_02025310(s32 arg0);
void sub_02025354(s32 arg0);
void sub_020253A8(s32 arg0);
void sub_02025400(s32 arg0);
void sub_020255F0(s32 arg0);
void sub_02025618(s32 arg0);
void sub_020256D0(s32 arg0);
s32 sub_020259C8(void);
s32 sub_02025B94(s32 arg0, s32 arg1, u16 arg2);
s32 sub_02025BEC(void);
s8 sub_02025C4C(void);
s8 sub_02025D1C(void);
void sub_02025D70(void);
void sub_02025DC8(void);
void sub_02025F60(void);
void sub_02025F90(void);
void sub_0202622C(u16 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4);
void sub_020262DC(u16 arg0, s32 arg1);
void sub_020263A0(void);
void sub_02026464(void);
void sub_020265A8(void);
void sub_020265D4(void);
void sub_020267D0(void);
void sub_02026830(void);
void sub_020269C8(void);
void sub_020269E0(void);
void sub_020269F0(void);
void sub_02026A34(void);
void sub_02026A38(u16 value);
void sub_02026AB8(u16 arg0);
void sub_02026B38(void);
void sub_02026B48(u16 value);
void sub_02026BC8(u16 value);
void sub_02026BD8(void);
void sub_02026C0C(void);
void sub_02026C10(u16 value);
void sub_02026C68(u16 value);
void sub_02026C7C(u8 arg0);
void sub_02026D74(void **arg0, u8 arg1, u8 arg2, u16 arg3);
void sub_02026DFC(void *arg0, u8 arg1);
void sub_02026E4C(s32 arg0);
void sub_02026F0C(void);
void sub_02026F18(void);
void sub_02026F3C(s32 arg0);
void sub_02026FAC(void);
void sub_02027040(void);
void sub_02027068(void);
void sub_02027074(void);
void sub_020271FC(u8 *arg0);
void sub_0202720C(u8 *arg0);
s32 sub_02027294(u8 *arg0, u8 arg1, u8 arg2);
u8 sub_020272E8(u16 arg0);
void sub_02027300(u8 *arg0);
void sub_02027370(void);
u32 sub_02027374(u8 *arg0);
u8 sub_020273D0(u8 *arg0, u8 arg1);
u32 sub_020274D0(u8 *arg0);
void sub_02027610(void);
void sub_02027728(void);
void sub_020279BC(void **arg0, u8 arg1, u8 arg2, u16 arg3);
void sub_02027B94(u8 *arg0);
void sub_02027C78(u8 *arg0);
void sub_02027D14(u8 *arg0, u8 arg1);
u8 *sub_02027E74(u8 arg0, u8 arg2);
u8 sub_02027F0C(u8 *arg0, u16 arg1, u32 arg2, u8 arg3);
void sub_02028098(void);
void sub_020280B4(void **arg0, u8 arg1, void **arg2);
void sub_02028190(void);
void sub_020281C4(void *arg0);
void sub_020281FC(void);
void sub_0202828C(s32 arg0, u32 arg1);
void sub_020282B4(s32 arg0, u16 arg1, u32 arg2);
void sub_020282E0(s32 arg0, s8 *arg1, s32 arg2);
void sub_02028368(s32 arg0, s32 arg1, s32 arg2, u32 arg3);
void sub_020283D4(s32 arg0);
void sub_02028410(s32 arg0, s16 arg1);
void sub_02028448(s32 arg0, u8 arg1);
u8 sub_0202846C(s32 arg0);
void sub_02028480(void);
void **sub_020284A0(void);
void sub_020284C4(void **arg0, void *arg1, void *arg2);
void sub_02028580(void **arg0);
void sub_020285B0(void **arg0);
s32 sub_020285C8(void **arg0, M2C_UNK arg3);
void sub_02028A34(void **arg0, u8 *arg1);
void sub_02028A4C(void *arg0, u8 *arg1);
u16 sub_02028A74(void **arg0);
void sub_02028A98(void **arg0, s16 arg1);
void sub_02028ACC(void);
void *sub_02028B0C(void);
void sub_02028B44(void);
void sub_02028B58(u16 arg0, u16 arg1);
void sub_02028B90(s32 arg0, u16 arg1, u16 arg2);
void sub_02028BCC(u16 arg0, u16 arg1);
void sub_02028C04(u16 arg0, u8 arg1);
void sub_02028C3C(u16 arg0, s16 arg1);
void sub_02028C74(u16 arg0, u8 arg1);
void sub_02028CAC(u16 arg0, u8 arg1);
void sub_02028CE4(s32 arg0, s32 arg1, u8 arg2);
void sub_02028D1C(s32 arg0, s32 arg1, u8 arg2);
void sub_02028D54(s32 arg0, s32 arg1, u8 arg2);
void sub_02028D8C(u8 arg0);
void sub_02028DB8(s32 arg0, s32 arg1);
void sub_02028DE8(void (*arg0)(void *, u8));
void sub_02028E10(void (*arg0)(void **, u8, u8, u16));
void sub_02028E38(void);

void sub_02019F08(void) {

}

void sub_02019F0C(void) {
    s32 *var_r4_4019;
    s32 var_r2_4016;
    u32 temp_r0_4038;
    u32 temp_r0_4046;
    void *temp_r3_4030;

    REG_DMA3.src = 0x020357F4;
    REG_DMA3.dest = 0x02000000;
    REG_DMA3.control = 0x80000100;
    REG_DMA3.src = 0x020359F4;
    REG_DMA3.dest = (u32) gObjPaletteBuffer;
    REG_DMA3.control = 0x80000100;
    REG_DMA3.src = 0x02000000;
    REG_DMA3.dest = 0x05000000;
    REG_DMA3.control = 0x80000200;
    *(void **)0x03002970 = (void *)0x0203B000;
    *(s32 *)0x03001B40 = 0x020102A0;
    CpuSet((void *)0x0203B000, (void *)0x020102A0, 0x04000E60U);
    var_r2_4016 = 0;
    var_r4_4019 = (s32 *)0x03002400;
    do {
        *var_r4_4019 = M2C_FIELD(((var_r2_4016 * 4) + *(void **)0x03002970), s32 *, 0x14);
        var_r4_4019 += 4;
        var_r2_4016 += 1;
    } while (var_r2_4016 <= 3);
    temp_r3_4030 = *(void **)0x03002970;
    temp_r0_4038 = M2C_FIELD(temp_r3_4030, u8 *, 0x193E) * 0xE10;
    gGameState.game_time_frames = temp_r0_4038;
    temp_r0_4046 = temp_r0_4038 + (M2C_FIELD(temp_r3_4030, u8 *, 0x193D) * 0x3C);
    gGameState.game_time_frames = temp_r0_4046;
    gGameState.game_time_frames = (temp_r0_4046 + M2C_FIELD(temp_r3_4030, u8 *, 0x193C)) * 0x3C;
    gGameState.unk_822 = 0x1C00;
    gGameState.unk_824 = 0xD801;
    gGameState.unk_826 = 0xD402;
    gGameState.unk_828 = 0xD003;
    CpuFastSet(*(void **)0x03002970 + 0x1948, (void *)0x06000000, 0x400U);
    CpuFastSet(*(void **)0x03002970 + 0x2948, (void *)0x06010000, 0x400U);
    CpuFastSet(*(void **)0x03002970 + 0x3948, (void *)0x02000220, 8U);
    CpuFastSet((void *)0x02000220, (void *)0x05000220, 8U);
    gGameState.unk_82A = 0;
    sub_0201A218();
    sub_0201C2E0();
    mMsg_InitWindow((mMsg_Window_c *)0x03002FC0, (u8 *)0x02001720, (u8 *)0x0200BF80);
    mMsg_InitWindow((mMsg_Window_c *)0x03003060, (u8 *)0x02001940, (u8 *)0x0200D180);
    mMsg_InitWindow((mMsg_Window_c *)0x03002980, (u8 *)0x02001B60, (u8 *)0x0200E380);
    sub_0201BF10();
}

void sub_0201A0C8(void) {
    sub_0201BF58();
}

void sub_0201A0D4(void) {
    M2C_UNK sp0;
    s32 temp_r1_4245;
    u32 temp_r1_4262;
    u32 temp_r2_4261;

    CpuFastSet(mFont_BlitGlyphToTiles, (void *)0x03002810, 0x58U);
    mMsg_Init();
    sub_02019CFC();
    gGameState.unk_85F = 1;
    gGameState.unk_816 = 0xFFFF;
    sub_02019F08();
    sub_02019F0C();
loop_1:
    sub_02019CC0();
    if (M2C_FIELD(&gGameState, u16 *, 0x850) == 0x101) {
        M2C_FIELD(&sp0, u16 *, 0) = (u16) REG_IRQ.enable;
        M2C_FIELD(&sp0, u16 *, 2) = (u16) *(u16 *)0x04000000;
        *(u16 *)0x04000000 = 0x80;
        *(s16 *)0x04000132 = 0x8204;
        REG_IRQ.enable = 0x1000;
        SoundBiasReset();
        M2C_ERROR(/* unknown instruction: svc 0x3 */);
        SoundBiasSet();
        REG_IRQ.enable = M2C_FIELD(&sp0, u16 *, 0);
        *(s16 *)0x04000132 = 0;
        gGameState.unk_856 = 0;
        gGameState.unk_857 = 0;
        gGameState.unk_851 = 0;
        gGameState.unk_850 = 0;
        sub_0201A620();
    }
    sub_02019C88();
    temp_r1_4245 = M2C_FIELD((void *)0x03003120, s32 *, 0x18);
    if (((u32) (temp_r1_4245 + 0x1FEFF) <= 1U) || (temp_r1_4245 == 0xFFFE0202)) {
        gGameState.unk_856 = 1;
    }
    sub_0201A0C8();
    temp_r2_4261 = gGameState.game_time_frames;
    temp_r1_4262 = temp_r2_4261 + 1;
    gGameState.game_time_frames = temp_r1_4262;
    if (temp_r1_4262 > 0x4F19FFU) {
        gGameState.game_time_frames = temp_r2_4261 + 0xFFB0E601;
    }
    sub_02019D4C();
    gGameState.unk_85F = 0;
    sub_02019C3C();
    goto loop_1;
}

s32 sub_0201A1FC(u32 *arg0) {
    s32 sp0;

    M2C_FIELD(&sp0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(&sp0, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(&sp0, u8 *, 2) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(&sp0, u8 *, 3) = (u8) M2C_FIELD(arg0, u8 *, 0);
    return sp0;
}

void sub_0201A218(void) {
    s32 sp0;
    u16 temp_r4_4318;

    temp_r4_4318 = REG_IME;
    REG_IME = 0;
    M2C_FIELD((void *)0x04000134, s16 *, 0) = 0xC000;
    *(s16 *)0x04000158 = 0;
    *(s32 *)0x04000154 = 0;
    M2C_FIELD((void *)0x04000134, s16 *, 0xC) = 0x47;
    *(s16 *)0x04000202 = 0x80;
    *(s16 *)0x04000202 = 0x80;
    REG_IRQ.enable |= 0x80;
    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03003120, 0x01000010U);
    REG_IME = temp_r4_4318;
}

void sub_0201A288(void) {
    s32 sp0;
    u32 sp4;
    s32 temp_r0_4706;
    s32 temp_r2_4526;
    s32 temp_r2_4690;
    s32 temp_r3_4673;
    s32 temp_r4_4545;
    s32 var_r0_4539;
    s32 var_r0_4606;
    s32 var_r0_4684;
    s32 var_r1_4440;
    s32 var_r1_4550;
    s32 var_r1_4613;
    s32 var_r3_4491;
    s8 temp_r4_4478;
    u16 temp_r1_4486;
    u16 temp_r1_4679;
    u16 temp_r5_4534;
    u16 var_r2_4600;
    u16 var_r8_4372;
    u32 temp_r1_4423;
    u8 temp_r2_4381;
    u8 temp_r2_4418;

    var_r8_4372 = *(u16 *)0x04000140;
    if (1 & var_r8_4372) {
        temp_r2_4381 = *(u8 *)0x03003149;
        if (temp_r2_4381 == 0) {
            sp4 = *(u32 *)0x04000150;
            *(s32 *)0x04000154 = *(s32 *)0x0202AFBC;
            *(u8 *)0x03003149 = temp_r2_4381;
        } else {
            var_r8_4372 |= 2;
        }
    }
    if (!(var_r8_4372 & 2)) {

    } else {
        sp4 = *(void *)0x04000150;
        temp_r2_4418 = *(void *)0x03003149;
        if (temp_r2_4418 != 1) {
            if (sub_0201A1FC(&sp4) == *(s32 *)0x0202AFC4) {
                *(void *)0x03003149 = 1U;
            }
        } else {
            temp_r1_4423 = M2C_FIELD((void *)0x03003120, u32 *, 0x18);
            if (temp_r1_4423 != 0xFFFE0105) {
                if (temp_r1_4423 <= 0xFFFE0105U) {
                    if (temp_r1_4423 > -0x1FEFEU) {
                        goto block_74;
                    }
                    if (temp_r1_4423 < -0x1FEFFU) {
                        goto block_74;
                    }
                    var_r1_4440 = M2C_FIELD((void *)0x03003120, s32 *, 8);
                    if (var_r1_4440 < 0) {
                        var_r1_4440 += 3;
                    }
                    if ((s32) M2C_FIELD((void *)0x03003120, s32 *, 4) > (s32) (var_r1_4440 >> 2)) {
                        temp_r4_4478 = (s8) *(u8 *)0x03003144;
                        if (temp_r4_4478 != 0) {
                            temp_r1_4486 = 8 & *(u16 *)0x04000158;
                            if (temp_r1_4486 != 0) {

                            } else {
                                var_r3_4491 = 0xFFFE0209;
                                if (temp_r4_4478 == 1) {
                                    var_r3_4491 = -0x1FDF8;
                                }
                                *(void *)0x04000154 = var_r3_4491;
                                M2C_FIELD((void *)0x03003145, u8 *, 0) = (u8) *(u8 *)0x03003144;
                                M2C_FIELD((void *)0x03003145, s8 *, 4) = (s8) temp_r1_4486;
                                M2C_FIELD((void *)0x03003120, u32 *, 0x18) = (u32) temp_r1_4486;
                            }
                        } else if (sp4 == 0xFFFE0106) {
                            *(u8 *)0x03003144 = 1;
                        } else {
                            *(u8 *)0x03003144 = 2;
                        }
                    } else {
                        temp_r2_4526 = M2C_FIELD((void *)0x03003120, s32 *, 0xC);
                        if (temp_r2_4526 >= 0) {
                            temp_r5_4534 = 8 & *(void *)0x04000158;
                            if (temp_r5_4534 != 0) {

                            } else {
                                var_r0_4539 = M2C_FIELD((void *)0x03003120, s32 *, 8);
                                if (var_r0_4539 < 0) {
                                    var_r0_4539 += 3;
                                }
                                temp_r4_4545 = M2C_FIELD((void *)0x03003120, s32 *, 4);
                                if (temp_r4_4545 == (var_r0_4539 >> 2)) {
                                    var_r1_4550 = ~M2C_FIELD((void *)0x03003120, s32 *, 0x20);
                                    goto block_40;
                                }
                                if ((u8) temp_r2_4526 == 0xFF) {
                                    *(void *)0x04000154 = (s32) ~M2C_FIELD((void *)0x03003120, s32 *, 0x1C);
                                    M2C_FIELD((void *)0x03003120, s32 *, 0x1C) = (s32) temp_r5_4534;
                                } else {
                                    var_r1_4550 = *((temp_r4_4545 * 4) + M2C_FIELD((void *)0x03003120, s32 *, 0));
                                    M2C_FIELD((void *)0x03003120, s32 *, 0x1C) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 0x1C) + var_r1_4550);
                                    M2C_FIELD((void *)0x03003120, s32 *, 0x20) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 0x20) + var_r1_4550);
block_40:
                                    *(void *)0x04000154 = var_r1_4550;
                                    M2C_FIELD((void *)0x03003120, s32 *, 4) = (s32) (temp_r4_4545 + 1);
                                }
                                goto block_68;
                            }
                        } else {
                            if (M2C_FIELD((void *)0x03003120, u8 *, 0x26) != 1) {
                                goto block_73;
                            }
                            var_r2_4600 = 8 & *(void *)0x04000158;
                            if (var_r2_4600 != 0) {

                            } else {
                                var_r0_4606 = 0xFFFE0204;
                                goto block_72;
                            }
                        }
                    }
                } else if (temp_r1_4423 == 0xFFFE0202) {
                    var_r1_4613 = M2C_FIELD((void *)0x03003120, s32 *, 8);
                    if (var_r1_4613 < 0) {
                        var_r1_4613 += 3;
                    }
                    if ((s32) M2C_FIELD((void *)0x03003120, s32 *, 4) > (s32) (var_r1_4613 >> 2)) {
                        if (8 & *(void *)0x04000158) {

                        } else {
                            if (M2C_FIELD((void *)0x03003120, s32 *, 0x20) == -1) {
                                *(void *)0x04000154 = 0xFFFE0208;
                                M2C_FIELD((void *)0x03003120, u8 *, 0x25) = temp_r2_4418;
                            } else {
                                *(void *)0x04000154 = 0xFFFE0209;
                                M2C_FIELD((void *)0x03003120, u8 *, 0x25) = 2U;
                            }
                            *(void *)0x03003149 = 0U;
                            M2C_FIELD((void *)0x03003120, u32 *, 0x18) = 0U;
                        }
                    } else if ((s32) M2C_FIELD((void *)0x03003120, s32 *, 0xC) > -1) {
                        temp_r3_4673 = sub_0201A1FC(&sp4);
                        temp_r1_4679 = 8 & *(void *)0x04000158;
                        if (temp_r1_4679 != 0) {

                        } else {
                            var_r0_4684 = M2C_FIELD((void *)0x03003120, s32 *, 8);
                            if (var_r0_4684 < 0) {
                                var_r0_4684 += 3;
                            }
                            temp_r2_4690 = M2C_FIELD((void *)0x03003120, s32 *, 4);
                            if (temp_r2_4690 == (var_r0_4684 >> 2)) {
                                *((temp_r2_4690 * 4) + M2C_FIELD((void *)0x03003120, s32 *, 0)) = sp4;
                                goto block_67;
                            }
                            if ((u8) M2C_FIELD((void *)0x03003120, s32 *, 0xC) == 0xFF) {
                                temp_r0_4706 = M2C_FIELD((void *)0x03003120, s32 *, 0x1C) + temp_r3_4673;
                                M2C_FIELD((void *)0x03003120, s32 *, 0x1C) = temp_r0_4706;
                                if (temp_r0_4706 != -1) {
                                    M2C_FIELD((void *)0x03003120, u8 *, 0x25) = 2U;
                                }
                                M2C_FIELD((void *)0x03003120, s32 *, 0x1C) = (s32) temp_r1_4679;
                            } else {
                                *((temp_r2_4690 * 4) + M2C_FIELD((void *)0x03003120, s32 *, 0)) = sp4;
                                M2C_FIELD((void *)0x03003120, s32 *, 0x1C) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 0x1C) + temp_r3_4673);
block_67:
                                M2C_FIELD((void *)0x03003120, s32 *, 0x20) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 0x20) + temp_r3_4673);
                                M2C_FIELD((void *)0x03003120, s32 *, 4) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 4) + 1);
                            }
block_68:
                            M2C_FIELD((void *)0x03003120, s32 *, 0xC) = (s32) (M2C_FIELD((void *)0x03003120, s32 *, 0xC) + 1);
                        }
                    } else if (M2C_FIELD((void *)0x03003120, u8 *, 0x26) == 1) {
                        var_r2_4600 = 8 & *(void *)0x04000158;
                        if (var_r2_4600 == 0) {
                            var_r0_4606 = 0xFFFE0104;
block_72:
                            *(void *)0x04000154 = var_r0_4606;
                            M2C_FIELD((void *)0x03003120, s32 *, 0xC) = (s32) var_r2_4600;
                        }
                    } else {
block_73:
                        *(void *)0x04000154 = 0xFFFE0205;
                    }
                } else {
block_74:
                    M2C_FIELD((void *)0x03003120, u32 *, 0x18) = sp4;
                    if ((sp4 >= 0xFFFE0101U) && ((sp4 <= 0xFFFE0102U) || (sp4 == 0xFFFE0202))) {
                        sp0 = 0;
                        CpuFastSet(&sp0, (void *)0x03003120, 0x01000010U);
                        M2C_FIELD((void *)0x03003120, s32 *, 0xC) = -1;
                        M2C_FIELD((void *)0x03003120, u32 *, 0x18) = sp4;
                        M2C_FIELD((void *)0x03003120, s8 *, 0x29) = 1;
                    }
                }
            } else {
                *(void *)0x04000154 = 0xFFFE0207;
                *(void *)0x03003149 = 0U;
                M2C_FIELD((void *)0x03003120, u32 *, 0x18) = 0U;
            }
        }
    }
    *(void *)0x04000140 = var_r8_4372;
    *(s8 *)0x0300314A = 0;
}

void sub_0201A620(void) {
    s32 sp0;
    u16 temp_r4_4840;

    temp_r4_4840 = REG_IME;
    REG_IME = 0;
    M2C_FIELD((void *)0x04000134, s16 *, 0) = 0x8000;
    M2C_FIELD((void *)0x04000134, s16 *, 0) = 0xC000;
    *(s16 *)0x04000158 = 0;
    *(s32 *)0x04000154 = 0;
    M2C_FIELD((void *)0x04000134, s16 *, 0xC) = 0x47;
    M2C_FIELD(((void *)0x04000134 + 0xC), s16 *, 0xC2) = 0x80;
    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03003120, 0x01000010U);
    REG_IME = temp_r4_4840;
}

s32 sub_0201A688(u8 arg0) {
    s32 var_r2_4888;
    u8 temp_r1_4892;

    var_r2_4888 = 0;
    temp_r1_4892 = *(u8 *)0x0300314A;
    if ((u32) temp_r1_4892 <= 0xAU) {
        REG_IME = 0;
        *(u8 *)0x0300314A = temp_r1_4892 + 1;
        REG_IME = 1;
    } else {
        if (arg0 != 0) {
            sub_0201A620();
        }
        var_r2_4888 = 1;
    }
    return var_r2_4888;
}

void sub_0201A6C8(void) {
    *(s16 *)0x0203E9A0 = 0;
    REG_IME = 0;
    *(s16 *)0x04000004 = 0;
    REG_IRQ.enable = 0;
    *(s16 *)0x04000202 = 0xFFFF;
    *(s16 *)0x04000000 = 0x80;
    _start();
}

u8 sub_0201A714(void *arg0, s8 arg1) {
    mMsg_Window_c *temp_r1_4963;
    mMsg_Window_c *temp_r1_4981;
    s8 temp_r4_4994;
    u8 *temp_r6_4959;
    u8 var_r7_4955;

    var_r7_4955 = 0;
    temp_r6_4959 = arg0 + 0x64 + arg1;
    if (*temp_r6_4959 == 1) {
        temp_r1_4963 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
        if ((temp_r1_4963->draw_enabled == 0) && (mMsg_RequestAppearWait(temp_r1_4963) == 1)) {
            mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
            goto block_4;
        }
    } else {
        temp_r1_4981 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
        if ((temp_r1_4981 != NULL) && ((s8) (u8) temp_r1_4981->current_mode != 1)) {
            temp_r4_4994 = mMsg_RequestDisappearWait(temp_r1_4981);
            if (temp_r4_4994 == 1) {
                mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
                *temp_r6_4959 = (u8) temp_r4_4994;
            }
        } else {
block_4:
            var_r7_4955 = 1;
        }
    }
    return var_r7_4955;
}

s32 sub_0201A780(void *arg0, u8 arg1) {
    s32 var_r5_5036;
    s8 temp_r1_5027;
    u8 temp_r1_5012;
    void *temp_r0_5014;
    void *temp_r3_5024;

    temp_r1_5012 = arg1;
    temp_r0_5014 = M2C_FIELD(arg0, void **, 0x14);
    if (temp_r0_5014 == NULL) {
        return 1;
    }
    temp_r3_5024 = arg0 + 0x64;
    if (M2C_FIELD(temp_r0_5014, u8 *, 0x7C) == 1) {
        temp_r1_5027 = (s8) temp_r1_5012;
        *(temp_r3_5024 + temp_r1_5027) = 0;
        if (temp_r1_5027 == 1) {
            M2C_FIELD(arg0, s8 *, 0x6D) = 0;
        }
    }
    var_r5_5036 = 0;
    if (*(temp_r3_5024 + (s8) temp_r1_5012) == 0) {
        var_r5_5036 = 1;
    }
    return var_r5_5036;
}

u8 sub_0201A7C8(s32 arg0) {
    u8 var_r4_5054;

    var_r4_5054 = 0;
    if ((gGameState.unk_84E == 1) || (4 & gGameState.keys_pressed) || (sub_0201A810(arg0 + 0x2C, 0x4650) == 1)) {
        var_r4_5054 = 1;
    }
    return var_r4_5054;
}

s32 sub_0201A810(s16 *arg0, s32 arg1) {
    s32 var_r3_5091;

    var_r3_5091 = 0;
    if (arg1 <= (s32) *arg0) {
        var_r3_5091 = 1;
    } else if (0x3FF & gGameState.keys_held) {
        *arg0 = 0;
    } else {
        *arg0 = (u16) *arg0 + 1;
    }
    return var_r3_5091;
}

void sub_0201A854(void *arg0, s8 arg1) {
    void *sp0;
    void *sp4;
    u8 sp8;
    s8 temp_r1_5130;
    u8 temp_r4_5365;
    u8 var_r2_5295;
    u8 var_r5_5356;

    temp_r1_5130 = arg1;
    switch (temp_r1_5130) {                         /* irregular */
    case 2:
    default:
block_15:
        var_r5_5356 = 1;
        do {
            temp_r4_5365 = var_r5_5356;
            sp0 = &sp0 + 9;
            sp4 = &sp0 + 0xA;
            sub_02019BA8((u16 *)0x020357F4, 7U, temp_r4_5365, &sp8, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *) M2C_FIELD(&sp0, u8 *, 9);
            sp4 = (void *) M2C_FIELD(&sp0, u8 *, 0xA);
            sub_02019BD8(0U, 7U, temp_r4_5365, sp8, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            var_r5_5356 += 1;
        } while ((s32) var_r5_5356 <= 6);
        break;
    case 4:
        sp0 = (void *)0x17;
        sp4 = (void *)0x11;
        sub_02019BD8(0U, 7U, 1U, 0x10U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1B;
        sp4 = (void *)0x13;
        sub_02019BD8(0U, 7U, 2U, 0x15U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1F;
        sp4 = (void *)0x1A;
        sub_02019BD8(0U, 7U, 3U, 0x1AU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1E;
        sp4 = (void *)0x14;
        sub_02019BD8(0U, 7U, 4U, 0x17U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1D;
        sp4 = (void *)0x16;
        sub_02019BD8(0U, 7U, 5U, 0x16U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        break;
    case 3:
        sp0 = (void *)0x17;
        sp4 = (void *)0x11;
        sub_02019BD8(0U, 7U, 1U, 0x17U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1B;
        sp4 = (void *)0x13;
        sub_02019BD8(0U, 7U, 2U, 0x1BU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1F;
        sp4 = (void *)0x1A;
        sub_02019BD8(0U, 7U, 3U, 0x1FU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1D;
        sp4 = (void *)0x15;
        sub_02019BD8(0U, 7U, 4U, 0x1DU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0x1F;
        sp4 = (void *)9;
        sub_02019BD8(0U, 7U, 5U, 0x1EU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        sp0 = (void *)0xB;
        sp4 = (void *)8;
        sub_02019BD8(0U, 7U, 6U, 0xAU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        break;
    case 1:
        if (M2C_FIELD(arg0, u8 *, 0x6F) == 1) {
            sp0 = (void *)0xA;
            sp4 = (void *)4;
            sub_02019BD8(0U, 7U, 1U, 0x16U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0xE;
            sp4 = (void *)6;
            sub_02019BD8(0U, 7U, 2U, 0x1AU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0xD;
            sp4 = (void *)3;
            sub_02019BD8(0U, 7U, 3U, 0x1EU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x15;
            sp4 = (void *)0xC;
            sub_02019BD8(0U, 7U, 4U, 0x1DU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x1F;
            sp4 = (void *)0x15;
            var_r2_5295 = 5;
            goto block_14;
        }
        if (M2C_FIELD(arg0, u8 *, 0x6E) == 1) {
            sp0 = (void *)0x10;
            sp4 = (void *)0x14;
            sub_02019BD8(0U, 7U, 1U, 8U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x14;
            sp4 = (void *)0x1B;
            sub_02019BD8(0U, 7U, 2U, 0xAU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x19;
            sp4 = (void *)0x1F;
            sub_02019BD8(0U, 7U, 3U, 0x15U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x17;
            sp4 = (void *)0x1D;
            sub_02019BD8(0U, 7U, 4U, 0x10U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0xF;
            sp4 = (void *)0x1F;
            sub_02019BD8(0U, 7U, 5U, 7U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
            sp0 = (void *)0x1F;
            sp4 = (void *)0x1F;
            var_r2_5295 = 6;
block_14:
            sub_02019BD8(0U, 7U, var_r2_5295, 0x1FU, M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
        } else {
            goto block_15;
        }
        break;
    }
    CpuFastSet((void *)0x020000E0, (void *)0x050000E0, 8U);
}

void sub_0201AA98(void *arg0, u8 arg1) {
    u8 temp_r5_5405;

    temp_r5_5405 = arg1;
    if ((M2C_FIELD(arg0, s8 *, 0x50) == 0) && (temp_r5_5405 != 1)) {
        M2C_FIELD(arg0, u16 *, 0x34) = (u16) gGameState.unk_828;
        M2C_FIELD(arg0, u16 *, 0x36) = (u16) gGameState.unk_82A;
        M2C_FIELD(arg0, u16 *, 0x48) = (u16) gGameState.unk_81E;
        M2C_FIELD(arg0, u16 *, 0x44) = (u16) gGameState.bg3_vofs;
        M2C_FIELD(arg0, u16 *, 0x46) = (u16) gGameState.unk_848;
        M2C_FIELD(arg0, s8 *, 0x50) = (s8) temp_r5_5405;
    }
    gGameState.unk_828 &= 0xFFFC;
    gGameState.unk_82A |= 0x1800;
    gGameState.unk_81E = 0;
    gGameState.bg3_vofs = 0;
    gGameState.unk_848 = 0;
}

void sub_0201AB3C(void *arg0, s8 arg1) {
    u16 temp_r1_5496;

    if (arg1 == M2C_FIELD(arg0, s8 *, 0x50)) {
        gGameState.unk_828 = M2C_FIELD(arg0, u16 *, 0x34);
        temp_r1_5496 = M2C_FIELD(arg0, u16 *, 0x36);
        gGameState.unk_82A = temp_r1_5496;
        if (*(u16 *)0x0203E9A0 == 1) {
            gGameState.unk_82A = 0xFDFF & temp_r1_5496;
        }
        gGameState.unk_81E = M2C_FIELD(arg0, u16 *, 0x48);
        gGameState.bg3_vofs = M2C_FIELD(arg0, u16 *, 0x44);
        gGameState.unk_848 = M2C_FIELD(arg0, u16 *, 0x46);
        M2C_FIELD(arg0, s8 *, 0x50) = 0;
    }
}

void sub_0201ABBC(void *arg0) {
    mMsg_Window_c *temp_r1_5544;

    temp_r1_5544 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
    if ((temp_r1_5544 != NULL) && (gGameState.unk_850 == 0)) {
        mMsg_Main_Window(temp_r1_5544);
    }
    sub_0201C5A0();
}

s32 sub_0201ABE4(void *arg0, u8 arg1) {
    s32 var_r1_5569;
    u8 temp_r5_5568;

    temp_r5_5568 = arg1;
    var_r1_5569 = 0;
    if ((gGameState.unk_850 == 0) && ((s8) M2C_FIELD(arg0, u8 *, 0x5A) != 0)) {
        if (sub_0201A714(arg0, (s8) temp_r5_5568) == 1) {
            M2C_FIELD(arg0, u8 *, 0x5F) = temp_r5_5568;
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201B6D0(arg0);
        }
        var_r1_5569 = 1;
    }
    return var_r1_5569;
}

s32 sub_0201AC38(void *arg0, u8 arg1) {
    s32 var_r1_5613;
    u8 temp_r5_5612;

    temp_r5_5612 = arg1;
    var_r1_5613 = 0;
    if ((gGameState.unk_850 == 0) && ((s8) M2C_FIELD(arg0, u8 *, 0x58) != 0)) {
        if (sub_0201A714(arg0, (s8) temp_r5_5612) == 1) {
            M2C_FIELD(arg0, u8 *, 0x5D) = temp_r5_5612;
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201AE0C(arg0);
        }
        var_r1_5613 = 1;
    }
    return var_r1_5613;
}

s32 sub_0201AC8C(void *arg0, u8 arg1) {
    s32 var_r1_5657;
    u8 temp_r5_5656;

    temp_r5_5656 = arg1;
    var_r1_5657 = 0;
    if ((s8) M2C_FIELD(arg0, u8 *, 0x59) != 0) {
        if (sub_0201A714(arg0, (s8) temp_r5_5656) == 1) {
            M2C_FIELD(arg0, u8 *, 0x5E) = temp_r5_5656;
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201B1B8(arg0);
        }
        var_r1_5657 = 1;
    }
    return var_r1_5657;
}

void sub_0201ACCC(void *arg0) {
    M2C_FIELD((void *)0x03003120, s32 *, 8) = 0x3980;
    M2C_FIELD((void *)0x03003120, s32 *, 0) = (s32) *(s32 *)0x03002970;
    M2C_FIELD((void *)0x03003120, s8 *, 0x26) = 1;
    M2C_FIELD(arg0, s8 *, 0x6A) = 2;
    M2C_FIELD(arg0, s8 *, 0x71) = 0;
}

s8 sub_0201ACF8(void *arg0) {
    s8 temp_r0_5719;
    s8 var_r1_5714;

    var_r1_5714 = 0;
    temp_r0_5719 = *(s8 *)0x03003145;
    if (temp_r0_5719 != 0) {
        var_r1_5714 = temp_r0_5719;
    } else if (*(u8 *)0x03003149 == 0) {
        var_r1_5714 = 2;
    }
    if (var_r1_5714 == 1) {
        M2C_FIELD(arg0, s8 *, 0x6D) = var_r1_5714;
    }
    return var_r1_5714;
}

void sub_0201AD34(void *arg0) {
    M2C_FIELD((void *)0x03003120, s32 *, 8) = 0x3980;
    M2C_FIELD((void *)0x03003120, s32 *, 0) = (s32) *(s32 *)0x03001B40;
    M2C_FIELD((void *)0x03003120, s8 *, 0x26) = 1;
    if (M2C_FIELD((void *)0x03003120, s32 *, 0x18) == 0xFFFE0101) {
        M2C_FIELD(arg0, s8 *, 0x70) = 1;
    } else {
        M2C_FIELD(arg0, s8 *, 0x70) = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x6A) = 1;
    M2C_FIELD((arg0 + 0x6A), s8 *, 7) = 1;
}

s16 sub_0201AD84(void *arg0) {
    s8 temp_r0_5797;
    s8 var_r3_5792;

    var_r3_5792 = 0;
    temp_r0_5797 = *(s8 *)0x03003145;
    if (temp_r0_5797 != 0) {
        var_r3_5792 = temp_r0_5797;
    } else if (*(u8 *)0x03003149 == 0) {
        var_r3_5792 = 2;
    }
    if ((M2C_FIELD(arg0, u16 *, 0x70) == 0x100) && (var_r3_5792 == 1)) {
        *(s16 *)0x0203E9A0 = (s16) var_r3_5792;
        M2C_FIELD(*(void **)0x03001B40, s8 *, 0x13) = 1;
    }
    return (s16) var_r3_5792;
}

void sub_0201ADDC(void) {

}

s32 sub_0201ADE0(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x58) = arg1;
    return 1;
}

s32 sub_0201ADE8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x58) = 1;
    return 1;
}

s32 sub_0201ADF4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x58) = 2;
    return 1;
}

s32 sub_0201AE00(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x58) = 3;
    return 1;
}

void sub_0201AE0C(void *arg0) {
    M2C_UNK (*temp_r1_5889)(void *);

    if ((u32) M2C_FIELD(arg0, u8 *, 0x58) <= 3U) {
        temp_r1_5889 = *(0x0202AFCC + ((s8) M2C_FIELD(arg0, u8 *, 0x58) * 4));
        if (temp_r1_5889 != NULL) {
            temp_r1_5889(arg0);
            M2C_FIELD(arg0, s16 *, 0x2C) = 0;
        }
    }
}

void sub_0201AE40(void *arg0) {
    s32 var_r2_5910;
    s8 *var_r1_5921;

    var_r2_5910 = 0xB;
    if (M2C_FIELD((void *)0x03003120, s32 *, 0x18) == 0xFFFE0101) {
        var_r2_5910 = 0x1E;
    }
    var_r1_5921 = arg0 + 0x58;
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03002980, var_r2_5910) == 1) {
        if (M2C_FIELD((void *)0x03003120, s32 *, 0x18) == 0xFFFE0202) {
            sub_0201ACCC(arg0);
        } else {
            sub_0201AD34(arg0);
        }
        sub_0201A854(arg0, 2);
        sub_0201AA98(arg0, 2U);
        var_r1_5921 = arg0 + 0x58;
        M2C_FIELD(arg0, u8 *, 0x53) = (u8) M2C_FIELD(arg0, u8 *, 0x58);
        M2C_FIELD(arg0, s32 *, 0x14) = 0x03002980;
    }
    *var_r1_5921 = 0;
}

void sub_0201AEBC(void *arg0) {
    u8 *var_r0_5997;
    u8 temp_r0_5980;
    u8 temp_r0_5984;
    u8 temp_r0_6000;
    u8 var_r1_5989;

    if (M2C_FIELD(arg0, u8 *, 0x71) == 0) {
        M2C_FIELD(arg0, s8 *, 0x60) = sub_0201ACF8(arg0);
    } else {
        temp_r0_5980 = M2C_FIELD(arg0, u8 *, 0x74);
        if (temp_r0_5980 == 0) {
            temp_r0_5984 = (u8) sub_0201AD84(arg0);
            M2C_FIELD(arg0, u8 *, 0x75) = temp_r0_5984;
            var_r1_5989 = temp_r0_5984;
            if (var_r1_5989 != 0) {
                M2C_FIELD(arg0, u8 *, 0x74) = 0x3CU;
            } else {
                var_r0_5997 = arg0 + 0x60;
                goto block_8;
            }
        } else {
            temp_r0_6000 = temp_r0_5980 - 1;
            M2C_FIELD(arg0, u8 *, 0x74) = temp_r0_6000;
            if ((temp_r0_6000 << 0x18) == 0) {
                var_r1_5989 = M2C_FIELD(arg0, u8 *, 0x75);
                var_r0_5997 = (arg0 + 0x75) - 0x15;
block_8:
                *var_r0_5997 = var_r1_5989;
            }
        }
    }
    if (((u32) (u8) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x70) - 3) <= 2U) && ((s8) (u8) M2C_FIELD(arg0, s8 *, 0x60) != 0) && (sub_0201ADF4(arg0) != 0)) {
        sub_0201AE0C(arg0);
    }
}

void sub_0201AF48(void *arg0) {
    s8 *var_r6_6104;
    u16 var_r1_6128;
    u8 temp_r2_6050;

    temp_r2_6050 = M2C_FIELD(arg0, u8 *, 0x70);
    if (temp_r2_6050 == 1) {
        gGameState.unk_856 = 0;
        gGameState.unk_857 = 0;
        gGameState.unk_84E = 0;
        gGameState.unk_84F = 0;
        if ((s8) M2C_FIELD(arg0, u8 *, 0x60) != 2) {
            M2C_FIELD(arg0, mMsg_Window_c **, 0x14)->cancel_continue = temp_r2_6050;
            M2C_FIELD(arg0, mMsg_Window_c **, 0x14)->force_next = temp_r2_6050;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 0x28) = 0x3C;
            sub_02019D78(0x28U);
        }
        M2C_FIELD(arg0, u8 *, 0x53) = (u8) M2C_FIELD(arg0, u8 *, 0x58);
        M2C_FIELD(arg0, s8 *, 0x62) = 0;
        var_r6_6104 = arg0 + 0x58;
    } else {
        var_r6_6104 = arg0 + 0x58;
        if ((mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), *((((s8) M2C_FIELD(arg0, u8 *, 0x60) - 1) * 4) + sp)) == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
            var_r1_6128 = 0x28;
            if ((s8) M2C_FIELD(arg0, u8 *, 0x60) == 1) {
                var_r1_6128 = 0x27;
            }
            sub_02019D78(var_r1_6128);
            gGameState.unk_856 = 0;
            gGameState.unk_857 = 0;
            mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
            M2C_FIELD(arg0, u8 *, 0x53) = (u8) M2C_FIELD(arg0, u8 *, 0x58);
            M2C_FIELD(arg0, s8 *, 0x62) = 0;
        }
    }
    *var_r6_6104 = 0;
}

void sub_0201B04C(void *arg0) {
    s32 temp_r0_6172;
    s32 temp_r0_6175;
    s8 temp_r0_6232;
    u8 temp_r1_6169;
    u8 temp_r2_6190;
    void *temp_r0_6223;
    void *temp_r1_6187;

    temp_r1_6169 = M2C_FIELD(arg0, u8 *, 0x70);
    if ((temp_r1_6169 == 1) && (temp_r0_6172 = M2C_FIELD(arg0, s32 *, 0x28), (temp_r0_6172 != 0))) {
        temp_r0_6175 = temp_r0_6172 - 1;
        M2C_FIELD(arg0, s32 *, 0x28) = temp_r0_6175;
        if (temp_r0_6175 == 0) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x7B) = temp_r1_6169;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x79) = temp_r1_6169;
        }
    } else {
        temp_r1_6187 = M2C_FIELD(arg0, void **, 0x14);
        temp_r2_6190 = M2C_FIELD(temp_r1_6187, u8 *, 0x7C);
        if (temp_r2_6190 == 0) {
            if (M2C_FIELD(arg0, u8 *, 0x6D) == 1) {
                M2C_FIELD(arg0, u8 *, 0x53) = 3U;
                sub_02019B1C(&gGameState, 0x80U, 0x3FU, 0U);
                gGameState.unk_82A &= 0xFEFF;
                M2C_FIELD(arg0, u8 *, 0x6D) = 0U;
                return;
            }
            temp_r0_6223 = arg0 + 0x53;
            M2C_FIELD(arg0, u8 *, 0x53) = temp_r2_6190;
            M2C_FIELD(arg0, s16 *, 0x2C) = (s16) temp_r2_6190;
            M2C_FIELD(temp_r0_6223, s8 *, 0x1D) = 0;
            temp_r0_6232 = (s8) *((temp_r0_6223 + 0x1D) - 0x13);
            switch (temp_r0_6232) {                 /* irregular */
            case 1:
                sub_0201A854(arg0, 1);
                break;
            case 3:
                sub_0201A854(arg0, 3);
                break;
            }
            M2C_FIELD(arg0, void **, 0x14) = (void *) M2C_FIELD(arg0, void **, 8);
            sub_0201AB3C(arg0, 2);
            mMsg_CopyTilesToVram(0, 0x90, M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 **, 0x50));
            if (gGameState.unk_856 == 1) {
                M2C_FIELD(arg0, u8 *, 0x72) = (u8) gGameState.unk_856;
            }
        } else if (((u32) (u8) (M2C_FIELD(temp_r1_6187, u8 *, 0x70) - 3) <= 2U) && (M2C_FIELD(arg0, u8 *, 0x70) == 0) && (gGameState.unk_856 == 1)) {
            M2C_FIELD(temp_r1_6187, u8 *, 0x7B) = (u8) gGameState.unk_856;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x79) = (u8) gGameState.unk_856;
        }
    }
}

void sub_0201B168(void) {

}

void sub_0201B16C(void) {
    if (sub_02019B58(&gGameState, 1U, 1U) == 0x10) {
        sub_0201A6C8();
    }
}

s32 sub_0201B18C(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
    return 1;
}

s32 sub_0201B194(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 1;
    return 1;
}

s32 sub_0201B1A0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 2;
    return 1;
}

s32 sub_0201B1AC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 3;
    return 1;
}

void sub_0201B1B8(void *arg0) {
    M2C_UNK (*temp_r1_6376)(void *);

    if ((u32) M2C_FIELD(arg0, u8 *, 0x59) <= 3U) {
        temp_r1_6376 = *(0x0202AFEC + ((s8) M2C_FIELD(arg0, u8 *, 0x59) * 4));
        if (temp_r1_6376 != NULL) {
            temp_r1_6376(arg0);
            M2C_FIELD(arg0, s16 *, 0x2C) = 0;
        }
    }
}

void sub_0201B1EC(void *arg0) {
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03003060, 0x15) == 1) {
        sub_0201A854(arg0, 3);
        sub_0201AA98(arg0, 3U);
        M2C_FIELD(arg0, u8 *, 0x54) = (u8) M2C_FIELD(arg0, u8 *, 0x59);
        M2C_FIELD(arg0, s16 *, 0x2C) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = 0x03003060;
    }
    M2C_FIELD(arg0, u8 *, 0x59) = 0U;
}

void sub_0201B238(void *arg0) {
    void *temp_r2_6432;

    temp_r2_6432 = M2C_FIELD(arg0, void **, 0x14);
    if (M2C_FIELD(temp_r2_6432, u8 *, 0x7C) == 0) {
        if (sub_0201B1AC(arg0) == 1) {
            goto block_11;
        }
    } else if ((u32) (u8) (M2C_FIELD(temp_r2_6432, u8 *, 0x70) - 3) <= 2U) {
        if (M2C_FIELD(temp_r2_6432, s8 *, 0x77) != -1) {
            if ((mMsg_CheckControlCode(M2C_FIELD(temp_r2_6432, u8 **, 0x54), 1U, M2C_FIELD(temp_r2_6432, s16 *, 0x6C)) == 0) || (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0x5C) != 0x16)) {
                if (sub_0201A810(arg0 + 0x2C, 0x258) == 1) {
                    goto block_10;
                }
            } else {
                goto block_10;
            }
        } else if (sub_0201A810(arg0 + 0x2C, 0x258) == 1) {
block_10:
            if (sub_0201B1A0(arg0) != 0) {
block_11:
                sub_0201B1B8(arg0);
            }
        } else if (gGameState.unk_856 != 0) {
            M2C_FIELD(arg0, s8 *, 0x72) = 1;
        }
    }
}

void sub_0201B2E8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x54) = (u8) M2C_FIELD(arg0, u8 *, 0x59);
    M2C_FIELD(arg0, u8 *, 0x59) = 0U;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0;
    M2C_FIELD(&gGameState, s32 *, 8) = 0;
    gGameState.unk_850 = 1;
    gGameState.unk_85A = 1;
    sub_02019D98(0x14U);
}

void sub_0201B328(void *arg0) {
    mMsg_Window_c *temp_r0_6578;
    mMsg_Window_c *temp_r2_6594;
    s32 temp_r0_6567;

    if (gGameState.unk_850 == 1) {
        if ((s32) M2C_FIELD(&gGameState, s32 *, 8) > 0x78) {
            temp_r0_6567 = mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), 0x17);
            if ((temp_r0_6567 == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
                M2C_FIELD(arg0, s16 *, 0x2C) = 0;
                temp_r0_6578 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
                temp_r0_6578->text_delay_timer = 0;
                mMsg_MainSetup_Window(temp_r0_6578);
                gGameState.unk_851 = (u8) temp_r0_6567;
            }
        }
        M2C_FIELD(&gGameState, s32 *, 8) = (s32) (M2C_FIELD(&gGameState, s32 *, 8) + 1);
        return;
    }
    temp_r2_6594 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
    if (temp_r2_6594->draw_enabled == 0) {
        if (sub_0201B1AC(arg0) == 1) {
            sub_0201B1B8(arg0);
        }
    } else if ((u32) (u8) ((u8) temp_r2_6594->current_mode - 3) <= 2U) {
        if (temp_r2_6594->selected_choice != -1) {
            if ((mMsg_CheckControlCode(temp_r2_6594->text, 1U, temp_r2_6594->text_offset) != 0) && (M2C_FIELD(arg0, mMsg_Window_c **, 0x14)->message_id == 0x17)) {
                goto block_15;
            }
        } else if (sub_0201A810(arg0 + 0x2C, 0x258) == 1) {
block_15:
            if (sub_0201B1A0(arg0) != 0) {
                sub_0201B1B8(arg0);
                M2C_FIELD(&gGameState, s32 *, 8) = 0x78;
            }
        } else if (gGameState.unk_856 != 0) {
            M2C_FIELD(arg0, s8 *, 0x72) = 1;
        }
    }
}

void sub_0201B420(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x54) = (u8) M2C_FIELD(arg0, u8 *, 0x59);
    M2C_FIELD(arg0, u8 *, 0x59) = 0U;
    if (M2C_FIELD(&gGameState, s32 *, 8) != 0) {
        if ((s16) gGameState.unk_816 != -1) {
            sub_02019D88(gGameState.unk_816);
        }
        sub_02027068();
        M2C_FIELD(&gGameState, s32 *, 8) = 0;
    }
}

void sub_0201B464(void *arg0) {
    u8 temp_r5_6714;

    temp_r5_6714 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x7C);
    if (temp_r5_6714 == 0) {
        M2C_FIELD(arg0, u8 *, 0x54) = temp_r5_6714;
        if (M2C_FIELD(arg0, s8 *, 0x5E) == 1) {
            sub_0201A854(arg0, 1);
        }
        M2C_FIELD(arg0, s8 *, 0x5E) = (s8) temp_r5_6714;
        M2C_FIELD(arg0, void **, 0x14) = (void *) M2C_FIELD(arg0, void **, 0xC);
        sub_0201AB3C(arg0, 3);
        mMsg_CopyTilesToVram(0, 0x90, M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 **, 0x50));
        M2C_FIELD(arg0, s16 *, 0x2C) = (s16) temp_r5_6714;
    }
}

void sub_0201B4B0(void) {
    s32 temp_r3_6782;
    u16 var_r3_6785;

    gGameState.unk_82A = (0xE0FF & gGameState.unk_82A) | 0x700;
    gGameState.unk_828 &= 0xFFFC;
    gGameState.unk_824 = (0xFFFC & gGameState.unk_824) | 1;
    temp_r3_6782 = 0xFFFC & gGameState.unk_822;
    var_r3_6785 = temp_r3_6782 | 2;
    gGameState.unk_822 = var_r3_6785;
    gGameState.unk_826 = (0xFFFC & gGameState.unk_826) | 3;
    if (M2C_FIELD(*(void **)0x03001B40, u8 *, 0x193A) != 0) {
        var_r3_6785 = temp_r3_6782 | 0x102;
    }
    gGameState.unk_822 = var_r3_6785;
    if (*(u16 *)0x0203E9A0 == 1) {
        gGameState.unk_82A &= 0xFDFF;
    }
    gGameState.unk_842 = 0x100;
    gGameState.unk_840 = 0x100;
    gGameState.unk_846 = 0x100;
    gGameState.unk_844 = 0;
}

void sub_0201B594(void *arg0) {
    u8 temp_r5_6862;
    void *temp_r4_6893;

    temp_r5_6862 = (u8) ((u32) gGameState.game_time_frames / 216000U);
    if (temp_r5_6862 != M2C_FIELD(arg0, s8 *, 0x63)) {
        CpuSet((temp_r5_6862 * 0x10) + 0x0202B014, (void *)0x02000190, 8U);
        CpuSet((temp_r5_6862 * 0xA) + 0x0202B194, (void *)0x020001D6, 5U);
        CpuFastSet((void *)0x02000180, (void *)0x05000180, 8U);
        CpuFastSet((void *)0x020001C0, (void *)0x050001C0, 8U);
        temp_r4_6893 = (temp_r5_6862 * 8) + 0x02034EE4;
        CpuSet(temp_r4_6893, (void *)0x02000102, 4U);
        CpuSet(temp_r4_6893, (void *)0x02000122, 4U);
        CpuFastSet((void *)0x02000100, (void *)0x05000100, 8U);
        CpuFastSet((void *)0x02000120, (void *)0x05000120, 8U);
        M2C_FIELD(arg0, s8 *, 0x63) = (s8) temp_r5_6862;
    }
    gGameState.unk_820 = 0x2441;
    gGameState.unk_81C = 0x1006;
}

s32 sub_0201B680(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
    return 1;
}

s32 sub_0201B688(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 1;
    return 1;
}

s32 sub_0201B694(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 2;
    return 1;
}

s32 sub_0201B6A0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 3;
    return 1;
}

s32 sub_0201B6AC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 4;
    return 1;
}

s32 sub_0201B6B8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 5;
    return 1;
}

s32 sub_0201B6C4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5A) = 6;
    return 1;
}

void sub_0201B6D0(void *arg0) {
    M2C_UNK (*temp_r1_7021)(void *);

    if ((u32) M2C_FIELD(arg0, u8 *, 0x5A) <= 6U) {
        temp_r1_7021 = *(0x0202B284 + ((s8) M2C_FIELD(arg0, u8 *, 0x5A) * 4));
        if (temp_r1_7021 != NULL) {
            temp_r1_7021(arg0);
        }
    }
}

void sub_0201B6FC(void *arg0) {
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03002980, 4) == 1) {
        sub_0201A854(arg0, 4);
        sub_0201AA98(arg0, 4U);
        sub_0201C7E0(0);
        sub_0201C870();
        *gIntrTable = (u32) sub_0201CB50;
        M2C_FIELD(arg0, u8 *, 0x55) = (u8) M2C_FIELD(arg0, u8 *, 0x5A);
        M2C_FIELD(arg0, s32 *, 0x14) = 0x03002980;
    }
    M2C_FIELD(arg0, u8 *, 0x5A) = 0U;
}

void sub_0201B75C(void *arg0) {
    void *temp_r1_7080;

    temp_r1_7080 = M2C_FIELD(arg0, void **, 0x14);
    if (M2C_FIELD(temp_r1_7080, u8 *, 0x7C) == 0) {
        if (sub_0201B6B8(arg0) == 1) {
            sub_0201B6D0(arg0);
        }
    } else if ((mMsg_CheckControlCode(M2C_FIELD(temp_r1_7080, u8 **, 0x54), 1U, M2C_FIELD(temp_r1_7080, s16 *, 0x6C)) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0x5C) == 6) && (sub_0201B694(arg0) == 1)) {
        sub_0201B6D0(arg0);
    }
}

void sub_0201B7B0(void *arg0) {
    s32 var_r2_7139;

    if ((mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), 0xF) == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
        mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
        var_r2_7139 = 0;
        M2C_FIELD(arg0, u8 *, 0x55) = (u8) M2C_FIELD(arg0, u8 *, 0x5A);
        M2C_FIELD(*(void **)0x03001B40, s8 *, 0x397F) = 0;
        do {
            M2C_FIELD(((var_r2_7139 * 4) + *(void **)0x03001B40), s32 *, 0x14) = 0;
            var_r2_7139 += 1;
        } while (var_r2_7139 <= 3);
        M2C_FIELD(arg0, s8 *, 0x69) = 1;
        sub_0201C7E0(0);
    }
    M2C_FIELD(arg0, u8 *, 0x5A) = 0U;
}

void sub_0201B824(void *arg0) {
    s32 temp_r0_7180;
    s32 temp_r0_7232;
    u32 temp_r0_7182;

    temp_r0_7180 = sub_0201C1B8();
    temp_r0_7182 = temp_r0_7180 - 7;
    switch (temp_r0_7182) {
    case 1:
    case 3:
    case 9:
        if ((sub_0201B6A0(arg0) == 1) && (mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), temp_r0_7180) == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
            mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
            mMsg_ClearText(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
            sub_0201B6D0(arg0);
            return;
        }
    default:
        return;
    case 2:
        if (sub_0201B6AC(arg0) == 1) {
            temp_r0_7232 = mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), temp_r0_7180);
            if ((temp_r0_7232 == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
                mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
                mMsg_ClearText(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
                sub_0201B6D0(arg0);
                M2C_FIELD(arg0, s8 *, 0x6D) = (s8) temp_r0_7232;
                return;
            }
        }
        break;
    case 0:
        if ((mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), temp_r0_7180) == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
            mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
            mMsg_ClearText(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
        }
        break;
    }
}

void sub_0201B90C(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x55) = (u8) M2C_FIELD(arg0, u8 *, 0x5A);
    M2C_FIELD(arg0, u8 *, 0x5A) = 0U;
}

void sub_0201B91C(void *arg0) {
    mMsg_Window_c *temp_r1_7287;
    s32 temp_r0_7298;

    temp_r1_7287 = M2C_FIELD(arg0, mMsg_Window_c **, 0x14);
    if (mMsg_CheckControlCode(temp_r1_7287->text, 1U, temp_r1_7287->text_offset) != 0) {
        temp_r0_7298 = mMsg_ChangeMsgData(M2C_FIELD(arg0, mMsg_Window_c **, 0x14), 0x11);
        if ((temp_r0_7298 == 1) && ((mMsg_RequestCursor(M2C_FIELD(arg0, mMsg_Window_c **, 0x14)) << 0x18) != 0)) {
            M2C_FIELD(arg0, s8 *, 0x55) = (s8) temp_r0_7298;
            mMsg_MainSetup_Window(M2C_FIELD(arg0, mMsg_Window_c **, 0x14));
        }
    }
}

void sub_0201B960(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x55) = (u8) M2C_FIELD(arg0, u8 *, 0x5A);
    M2C_FIELD(arg0, u8 *, 0x5A) = 0U;
}

void sub_0201B970(void *arg0) {
    if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x7C) == 0) && (sub_0201B6B8(arg0) == 1)) {
        sub_0201B6D0(arg0);
    }
}

void sub_0201B994(void *arg0) {
    s32 *var_r7_7399;
    s32 temp_r0_7404;
    s32 var_r3_7393;
    s8 *var_r2_7359;
    u8 temp_r3_7355;

    temp_r3_7355 = M2C_FIELD(arg0, u8 *, 0x69);
    if (temp_r3_7355 == 0) {
        var_r2_7359 = arg0 + 0x5A;
        *((arg0 + 0x69) - 0x14) = M2C_FIELD(arg0, u8 *, 0x5A);
        gGameState.unk_856 = temp_r3_7355;
        gGameState.unk_857 = temp_r3_7355;
        gGameState.unk_84C = temp_r3_7355;
        gGameState.unk_84D = temp_r3_7355;
    } else {
        var_r2_7359 = arg0 + 0x5A;
        if (mMsg_RequestAppear((mMsg_Window_c *)0x03002980, 0x12) == 1) {
            var_r3_7393 = 0;
            var_r7_7399 = (s32 *)0x03002400;
            do {
                temp_r0_7404 = *var_r7_7399;
                var_r7_7399 += 4;
                M2C_FIELD(((var_r3_7393 * 4) + *(s32 *)0x03002970), s32 *, 0x14) = temp_r0_7404;
                var_r3_7393 += 1;
            } while (var_r3_7393 <= 3);
            M2C_FIELD(arg0, u8 *, 0x55) = (u8) M2C_FIELD(arg0, u8 *, 0x5A);
            M2C_FIELD(arg0, s32 *, 0x14) = 0x03002980;
            gGameState.unk_856 = 0;
            gGameState.unk_857 = 0;
            gGameState.unk_84C = 0;
            gGameState.unk_84D = 0;
        }
    }
    *var_r2_7359 = 0;
}

void sub_0201BA54(void *arg0) {
    s8 temp_r2_7459;
    s8 var_r1_7472;
    u8 temp_r0_7450;

    temp_r0_7450 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 0x7C);
    if (temp_r0_7450 == 0) {
        M2C_FIELD(arg0, u8 *, 0x55) = temp_r0_7450;
        temp_r2_7459 = M2C_FIELD(arg0, s8 *, 0x5F);
        if (temp_r2_7459 != 1) {
            if (temp_r2_7459 != 3) {
                sub_0201AB3C(arg0, 4);
            } else {
                var_r1_7472 = 3;
                goto block_6;
            }
        } else {
            var_r1_7472 = 1;
block_6:
            sub_0201A854(arg0, var_r1_7472);
        }
        M2C_FIELD(arg0, s8 *, 0x5F) = 0;
        M2C_FIELD(arg0, void **, 0x14) = (void *) M2C_FIELD(arg0, void **, 0x10);
        sub_0201AB3C(arg0, 4);
        mMsg_CopyTilesToVram(0, 0x90, M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 **, 0x50));
        if (M2C_FIELD(arg0, u8 *, 0x6D) == 1) {
            M2C_FIELD(arg0, u8 *, 0x55) = 6U;
            sub_02019B1C(&gGameState, 0x80U, 0x3FU, 0U);
            gGameState.unk_82A &= 0xFEFF;
            sub_02019D98(0x14U);
            M2C_FIELD(arg0, u8 *, 0x6D) = 0U;
        }
        M2C_FIELD(arg0, s8 *, 0x69) = 0;
        M2C_FIELD(arg0, s16 *, 0x2C) = 0;
        *gIntrTable = (u32) sub_0201A288;
        sub_0201A218();
    }
}

void sub_0201BB20(void) {

}

void sub_0201BB24(void) {
    if (sub_02019B58(&gGameState, 1U, 1U) == 0x10) {
        sub_0201A6C8();
    }
}

s32 sub_0201BB44(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x57) = arg1;
    return 1;
}

void sub_0201BB4C(void *arg0) {
    sub_0201BB44(arg0, 1);
}

void sub_0201BB58(void *arg0) {
    sub_0201BB44(arg0, 2);
}

void sub_0201BB64(void *arg0) {
    sub_0201BB44(arg0, 4);
}

void sub_0201BB70(void *arg0) {
    sub_0201BB44(arg0, 3);
}

void sub_0201BB7C(void *arg0) {
    sub_0201BB44(arg0, 5);
}

void sub_0201BB88(void *arg0) {
    M2C_UNK (*temp_r1_7625)(void *);

    if ((u32) M2C_FIELD(arg0, u8 *, 0x57) <= 5U) {
        temp_r1_7625 = *(0x0202B2BC + ((s8) M2C_FIELD(arg0, u8 *, 0x57) * 4));
        if (temp_r1_7625 != NULL) {
            temp_r1_7625(arg0);
        }
    }
}

void sub_0201BBB4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(arg0, u8 *, 0x57);
    M2C_FIELD(arg0, u8 *, 0x57) = 0U;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    gGameState.unk_816 = 0;
    sub_02019D88(0U);
    gGameState.unk_85A = 1;
    sub_0201B4B0();
}

void sub_0201BBF8(void *arg0) {
    u8 var_r0_7699;

    if (*(u16 *)0x0203E9A0 == 0) {
        if (!(9 & gGameState.keys_pressed) || ((s32) sub_0201BB64(arg0) != 1)) {
            if (gGameState.unk_856 == 0) {
                var_r0_7699 = M2C_FIELD(&gGameState, s32 *, 0x84C) & 0xFF00FF;
                goto block_10;
            }
            goto block_11;
        }
        goto block_7;
    }
    if ((1 & gGameState.keys_pressed) && ((s32) sub_0201BB7C(arg0) == 1)) {
block_7:
        sub_0201BB88(arg0);
        return;
    }
    if (gGameState.unk_856 == 0) {
        var_r0_7699 = gGameState.unk_84E;
block_10:
        if (var_r0_7699 != 0) {
            goto block_11;
        }
    } else {
block_11:
        M2C_FIELD(arg0, s8 *, 0x72) = 1;
    }
}

void sub_0201BCA4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(arg0, u8 *, 0x57);
    M2C_FIELD(arg0, u8 *, 0x57) = 0U;
    gGameState.unk_816 = 1;
    sub_02019D88(gGameState.unk_816);
    sub_02027068();
    gGameState.unk_82A = (0xE0FF & gGameState.unk_82A) | 0x1F00;
    gGameState.unk_822 &= 0xFFFC;
    gGameState.unk_824 = (0xFFFC & gGameState.unk_824) | 1;
    gGameState.unk_826 = (0xFFFC & gGameState.unk_826) | 2;
    gGameState.unk_828 = (0xFFFC & gGameState.unk_828) | 3;
    gGameState.unk_83E = 0;
    gGameState.unk_83C = 0;
    gGameState.unk_842 = 0;
    gGameState.unk_840 = 0;
    gGameState.unk_846 = 0;
    gGameState.unk_844 = 0;
    gGameState.bg3_vofs = 0x100;
    gGameState.unk_848 = 0x100;
}

void sub_0201BD7C(void *arg0) {
    u8 temp_r4_7859;

    temp_r4_7859 = sub_0201D904();
    sub_0201DD94();
    if ((temp_r4_7859 == 1) && ((s32) sub_0201BB70(arg0) == 1)) {
        sub_0201BB88(arg0);
    }
}

void sub_0201BDA8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(arg0, u8 *, 0x57);
    M2C_FIELD(arg0, u8 *, 0x57) = 0U;
    sub_02019D98(0x14U);
}

void sub_0201BDC4(void *arg0) {
    if ((sub_0201D800(1U) == 1) && ((s32) sub_0201BB58(arg0) == 1)) {
        sub_0201BB88(arg0);
    }
}

void sub_0201BDE8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(arg0, u8 *, 0x57);
    M2C_FIELD(arg0, u8 *, 0x57) = 0U;
    gGameState.unk_816 = 0;
    sub_02019D88(0U);
    sub_0201B4B0();
    gGameState.unk_842 = 0x100;
    gGameState.unk_840 = 0x100;
    gGameState.unk_846 = 0x100;
    gGameState.unk_844 = 0;
}

void sub_0201BE3C(void *arg0) {
    u8 temp_r0_7954;

    temp_r0_7954 = sub_0201D800(0U);
    if (temp_r0_7954 == 1) {
        M2C_FIELD(arg0, u8 *, 0x52) = temp_r0_7954;
        gGameState.unk_85A = temp_r0_7954;
    }
}

void sub_0201BE68(void *arg0) {
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03002FC0, 0x1A) == 1) {
        sub_0201A854(arg0, 1);
        sub_0201AA98(arg0, 1U);
        M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(arg0, u8 *, 0x57);
        M2C_FIELD(arg0, s32 *, 0x14) = 0x03002FC0;
    }
    M2C_FIELD(arg0, u8 *, 0x57) = 0U;
}

void sub_0201BEB0(void *arg0) {
    s8 *var_r1_8020;
    void *temp_r1_8013;

    temp_r1_8013 = M2C_FIELD(arg0, void **, 0x14);
    if (M2C_FIELD(temp_r1_8013, u8 *, 0x7C) == 0) {
        var_r1_8020 = arg0 + 0x52;
        goto block_7;
    }
    if (((u32) (u8) (M2C_FIELD(temp_r1_8013, u8 *, 0x70) - 3) <= 2U) && (M2C_FIELD(temp_r1_8013, s8 *, 0x77) == -1) && ((gGameState.unk_856 != 0) || (gGameState.unk_84E != 0))) {
        var_r1_8020 = arg0 + 0x72;
block_7:
        *var_r1_8020 = 1;
    }
}

void sub_0201BF10(void) {
    s32 sp0;

    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x030031D0, 0x01000020U);
    *(s8 *)0x03003233 = 0xFF;
    sub_0201D5C4();
    if ((s32) sub_0201BB4C((void *)0x030031D0) == 1) {
        sub_0201BB88((void *)0x030031D0);
    }
    sub_0201B594((void *)0x030031D0);
}

void sub_0201BF58(void) {
    s8 temp_r2_8284;
    u8 temp_r0_8354;
    u8 temp_r1_8313;
    u8 temp_r2_8238;
    u8 temp_r7_8176;
    u8 var_r8_8104;
    void *temp_r0_8259;
    void *temp_r0_8343;

    var_r8_8104 = 1;
    if (((s8) *(u8 *)0x03003223 != 3) && ((s8) *(u8 *)0x03003225 != 6) && ((s8) *(u8 *)0x03003222 != 2)) {
        sub_0201B594((void *)0x030031D0);
    }
    if (M2C_FIELD(*(void **)0x03001B40, u8 *, 0x193A) != 0) {
        gGameState.unk_83C = ((u16) gGameState.unk_844 >> 1) + *(u8 *)0x03003243;
        gGameState.unk_83E -= 4;
        *(u8 *)0x03003243 += 1;
    }
    sub_0201ABBC((void *)0x030031D0);
    if ((s8) *(void *)0x03003223 != 0) {
        *(0x0202AFDC + ((s8) *(void *)0x03003223 * 4))(0x030031D0);
        temp_r7_8176 = *(u8 *)0x03003242;
        if (temp_r7_8176 != 1) {

        } else {
            sub_0201ADE8((void *)0x030031D0);
            *(u8 *)0x03003242 = 0;
            sub_0201AE0C((void *)0x030031D0);
            gGameState.unk_857 = temp_r7_8176;
            gGameState.unk_84E = 0;
            gGameState.unk_84F = 0;
        }
    } else if ((s8) *(void *)0x03003225 != 0) {
        *(0x0202B2A0 + ((s8) *(void *)0x03003225 * 4))(0x030031D0);
        var_r8_8104 = 0;
    } else if (*(s8 *)0x03003224 != 0) {
        temp_r2_8238 = *(void *)0x03003242;
        if (temp_r2_8238 == 0) {
            if (*(u8 *)0x03003237 == 0) {
                *(0x0202AFFC + (*(s8 *)0x03003224 * 4))(0x030031D0);
            } else {
                temp_r0_8259 = M2C_FIELD((void *)0x030031D0, void **, 0x14);
                if ((temp_r0_8259 == NULL) || (M2C_FIELD(temp_r0_8259, u8 *, 0x7C) == 1)) {
                    *(u8 *)0x03003237 = temp_r2_8238;
                }
            }
        }
        if (*(void *)0x03003242 == 1) {
            sub_0201C1C4((void *)0x030031D0, 3U, 1U, 1U, 0);
        }
    } else {
        temp_r2_8284 = M2C_FIELD((void *)0x030031D0, s8 *, 0x52);
        if (temp_r2_8284 != 0) {
            if ((temp_r2_8284 == 1) && (*(u16 *)0x0203E9A0 == 0) && (2 & gGameState.keys_pressed)) {
                gGameState.unk_84C = (u8) temp_r2_8284;
            }
            gGameState.unk_84E = sub_0201A7C8(0x030031D0);
            temp_r1_8313 = M2C_FIELD((void *)0x030031D0, u8 *, 0x72);
            if (temp_r1_8313 == 0) {
                if (M2C_FIELD((void *)0x030031D0, u8 *, 0x65) == 0) {
                    *(0x0202B2D4 + ((s8) *(void *)0x03003222 * 4))();
                } else {
                    temp_r0_8343 = M2C_FIELD((void *)0x030031D0, void **, 0x14);
                    if ((temp_r0_8343 == NULL) || (M2C_FIELD(temp_r0_8343, u8 *, 0x7C) == 1)) {
                        M2C_FIELD((void *)0x030031D0, u8 *, 0x65) = temp_r1_8313;
                        M2C_FIELD((void *)0x030031D0, s16 *, 0x2C) = (s16) temp_r1_8313;
                    }
                }
            }
            temp_r0_8354 = M2C_FIELD((void *)0x030031D0, u8 *, 0x72);
            if (temp_r0_8354 == 1) {
                sub_0201C1C4((void *)0x030031D0, 1U, 1U, 1U, (s32) temp_r0_8354);
            }
        }
    }
    sub_0201A688(var_r8_8104);
}

void sub_0201C198(void) {

}

u16 sub_0201C19C(void) {
    return (u16) ((s32) M2C_FIELD((void *)0x030031D0, s32 *, 0x18) / 1000);
}

void sub_0201C1B8(void) {
    sub_0201C8C0();
}

void sub_0201C1C4(void *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 temp_r0_8422;
    u8 temp_r7_8419;

    temp_r7_8419 = arg1;
    temp_r0_8422 = sub_0201A714(arg0, (s8) arg1);
    if (temp_r0_8422 == 1) {
        if ((arg2 != 0) && (gGameState.unk_856 != 0)) {
            sub_0201ADE8(arg0);
            M2C_FIELD(arg0, s8 *, 0x72) = 0;
            *((arg0 + 0x72) - 0x15) = temp_r7_8419;
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201AE0C(arg0);
            gGameState.unk_857 = temp_r0_8422;
            goto block_7;
        }
        if ((arg3 != 0) && (gGameState.unk_84C != 0)) {
            sub_0201B688(arg0);
            M2C_FIELD(arg0, s8 *, 0x72) = 0;
            *((arg0 + 0x72) - 0x13) = temp_r7_8419;
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201B6D0(arg0);
            gGameState.unk_84D = 1;
block_7:
            gGameState.unk_84E = 0;
            gGameState.unk_84F = 0;
            return;
        }
        if (((u8) arg4 != 0) && (gGameState.unk_84E != 0)) {
            sub_0201B194(arg0);
            M2C_FIELD(arg0, s8 *, 0x72) = 0;
            M2C_FIELD(arg0, u8 *, 0x5E) = temp_r7_8419;
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
            sub_0201B1B8(arg0);
            gGameState.unk_84F = 1;
        }
    }
}

void sub_0201C2E0(void) {
    s32 sp0;

    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03003250, 0x01000120U);
}

void sub_0201C300(m_msg_sprite_c *sprite) {
    sprite->_57 = 0;
    sprite->_08 = 0;
    sprite->_0C = 0;
}

m_msg_sprite_c *sub_0201C310(u8 type, s32 x, s32 y, s32 param) {
    s32 sp0;
    s32 sp4;
    M2C_UNK (*temp_r1_8632)(m_msg_sprite_c *);
    m_msg_sprite_c *temp_r7_8592;
    m_msg_sprite_c *var_r4_8576;
    s32 temp_r0_8578;
    s32 temp_r4_8590;
    u8 temp_r0_8574;
    void *temp_r5_8586;

    sp4 = param;
    temp_r0_8574 = type;
    var_r4_8576 = NULL;
    temp_r0_8578 = sub_0201C3C8(0U);
    if (temp_r0_8578 >= 0) {
        temp_r5_8586 = *(0x0202B2FC + (temp_r0_8574 * 4));
        sp0 = 0;
        temp_r4_8590 = temp_r0_8578 * 0x60;
        temp_r7_8592 = temp_r4_8590 + 0x03003250;
        CpuFastSet(&sp0, temp_r7_8592, 0x01000018U);
        *(0x03003250 + temp_r4_8590) = (M2C_UNK (*)(m_msg_sprite_c *)) M2C_FIELD(temp_r5_8586, M2C_UNK (**)(m_msg_sprite_c *), 0);
        *(0x03003254 + temp_r4_8590) = (s32) M2C_FIELD(temp_r5_8586, s32 *, 4);
        *(0x03003258 + temp_r4_8590) = (s32) M2C_FIELD(temp_r5_8586, s32 *, 8);
        *(0x0300325C + temp_r4_8590) = (s32) M2C_FIELD(temp_r5_8586, s32 *, 0xC);
        temp_r7_8592->_57 = temp_r0_8574;
        *(0x0300327C + temp_r4_8590) = x;
        *(0x03003280 + temp_r4_8590) = y;
        *(0x03003264 + temp_r4_8590) = sp4;
        temp_r1_8632 = *(0x03003250 + temp_r4_8590);
        if (temp_r1_8632 != NULL) {
            temp_r1_8632(temp_r7_8592);
        }
        var_r4_8576 = temp_r7_8592;
    }
    return var_r4_8576;
}

s32 sub_0201C3C8(u8 arg0) {
    s32 var_r0_8676;
    s32 var_r2_8659;
    u8 *var_r1_8662;

    var_r2_8659 = 0;
    var_r1_8662 = (u8 *)0x030032A7;
loop_2:
    if (*var_r1_8662 != arg0) {
        var_r1_8662 += 0x60;
        var_r2_8659 += 1;
        if (var_r2_8659 <= 0xB) {
            goto loop_2;
        }
    }
    var_r0_8676 = var_r2_8659;
    if (var_r0_8676 > 0xB) {
        var_r0_8676 = -1;
    }
    return var_r0_8676;
}

s32 sub_0201C3F8(void *arg0, s32 arg1) {
    s32 var_r3_8689;

    var_r3_8689 = 0;
    if ((M2C_FIELD(arg0, s16 *, 0x34) == 0) && (M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0x36) * 8) + *((M2C_FIELD(arg0, s16 *, 0x38) * 4) + arg1)), s32 *, 8) == 0)) {
        var_r3_8689 = 1;
    }
    return var_r3_8689;
}

void sub_0201C428(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x38) = arg2;
    M2C_FIELD(arg0, u16 *, 0x34) = (u16) M2C_FIELD(*((M2C_FIELD(arg0, s16 *, 0x38) * 4) + arg1), u16 *, 4);
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
}

void sub_0201C444(void *arg0, s32 arg1) {
    s32 temp_r1_8748;
    s32 temp_r3_8738;
    u8 var_r0_8751;
    void *temp_r0_8747;

    temp_r3_8738 = *((M2C_FIELD(arg0, s16 *, 0x38) * 4) + arg1);
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x34) - 1) <= 0) {
        temp_r0_8747 = (M2C_FIELD(arg0, s16 *, 0x36) * 8) + temp_r3_8738;
        temp_r1_8748 = M2C_FIELD(temp_r0_8747, s32 *, 8);
        if (temp_r1_8748 == 0) {
            var_r0_8751 = M2C_FIELD(temp_r0_8747, u8 *, 6);
            if (var_r0_8751 != 0) {
                M2C_FIELD(arg0, s16 *, 0x36) = (s16) temp_r1_8748;
                goto block_5;
            }
        } else {
            M2C_FIELD(arg0, s16 *, 0x36) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x36) + 1);
block_5:
            var_r0_8751 = (u8) M2C_FIELD(((M2C_FIELD(arg0, s16 *, 0x36) * 8) + temp_r3_8738), u16 *, 4);
        }
    } else {
        var_r0_8751 = (u16) M2C_FIELD(arg0, s16 *, 0x34) - 1;
    }
    M2C_FIELD(arg0, s16 *, 0x34) = (s16) var_r0_8751;
}

void sub_0201C490(void *arg0, void *arg1, void *arg2) {
    u8 temp_r3_8822;
    u8 temp_r3_8853;
    u8 temp_r4_8794;
    u8 temp_r4_8860;
    u8 temp_r5_8803;
    u8 temp_r5_8866;
    u8 temp_r5_8888;
    u8 temp_r6_8813;

    M2C_FIELD(arg2, s8 *, 0) = (s8) (M2C_FIELD(arg0, s32 *, 0x24) + (M2C_FIELD(arg1, u8 *, 0) + M2C_FIELD(arg0, s32 *, 0x30)));
    temp_r4_8794 = (-4 & M2C_FIELD(arg2, u8 *, 1)) | ((u32) (M2C_FIELD(arg1, u8 *, 1) << 0x1E) >> 0x1E);
    M2C_FIELD(arg2, u8 *, 1) = temp_r4_8794;
    temp_r5_8803 = (-0xD & temp_r4_8794) | (0xC & M2C_FIELD(arg1, u8 *, 1));
    M2C_FIELD(arg2, u8 *, 1) = temp_r5_8803;
    temp_r6_8813 = (-0x11 & temp_r5_8803) | (0x10 & M2C_FIELD(arg1, u8 *, 1));
    M2C_FIELD(arg2, u8 *, 1) = temp_r6_8813;
    temp_r3_8822 = (-0x21 & temp_r6_8813) | (0x20 & M2C_FIELD(arg1, u8 *, 1));
    M2C_FIELD(arg2, u8 *, 1) = temp_r3_8822;
    M2C_FIELD(arg2, u8 *, 1) = (u8) ((temp_r3_8822 & 0x3F) | (((u8) M2C_FIELD(arg1, u8 *, 1) >> 6) << 6));
    M2C_FIELD(arg2, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(arg2, u16 *, 2)) | ((((u32) (M2C_FIELD(arg1, u16 *, 2) << 0x17) >> 0x17) + M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x20)) & 0x1FF));
    temp_r3_8853 = (-0xF & M2C_FIELD(arg2, u8 *, 3)) | (0xE & M2C_FIELD(arg1, u8 *, 3));
    M2C_FIELD(arg2, u8 *, 3) = temp_r3_8853;
    temp_r4_8860 = (-0x11 & temp_r3_8853) | (0x10 & M2C_FIELD(arg1, u8 *, 3));
    M2C_FIELD(arg2, u8 *, 3) = temp_r4_8860;
    temp_r5_8866 = (-0x21 & temp_r4_8860) | (0x20 & M2C_FIELD(arg1, u8 *, 3));
    M2C_FIELD(arg2, u8 *, 3) = temp_r5_8866;
    M2C_FIELD(arg2, u8 *, 3) = (u8) ((temp_r5_8866 & 0x3F) | (((u8) M2C_FIELD(arg1, u8 *, 3) >> 6) << 6));
    M2C_FIELD(arg2, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(arg2, u16 *, 4)) | ((u32) (M2C_FIELD(arg1, u16 *, 4) << 0x16) >> 0x16));
    temp_r5_8888 = (-0xD & M2C_FIELD(arg2, u8 *, 5)) | (0xC & M2C_FIELD(arg1, u8 *, 5));
    M2C_FIELD(arg2, u8 *, 5) = temp_r5_8888;
    M2C_FIELD(arg2, u8 *, 5) = (u8) ((temp_r5_8888 & 0xF) | (((u8) M2C_FIELD(arg1, u8 *, 5) >> 4) * 0x10));
    M2C_FIELD(arg2, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 6);
}

void sub_0201C5A0(void) {
    M2C_UNK (*temp_r1_8924)(void *);
    M2C_UNK (*temp_r1_8944)(void *);
    s32 var_r5_8919;
    s32 var_r5_8939;
    u8 *var_r6_8917;
    u8 *var_r6_8937;
    void *var_r4_8918;
    void *var_r4_8938;

    var_r6_8917 = (u8 *)0x030032A7;
    var_r4_8918 = (void *)0x03003250;
    var_r5_8919 = 0xB;
    do {
        if (*var_r6_8917 != 0) {
            temp_r1_8924 = M2C_FIELD(var_r4_8918, M2C_UNK (**)(void *), 8);
            if (temp_r1_8924 != NULL) {
                temp_r1_8924(var_r4_8918);
            }
        }
        var_r6_8917 += 0x60;
        var_r4_8918 += 0x60;
        var_r5_8919 -= 1;
    } while (var_r5_8919 >= 0);
    var_r6_8937 = (u8 *)0x030032A7;
    var_r4_8938 = (void *)0x03003250;
    var_r5_8939 = 0xB;
    do {
        if (*var_r6_8937 != 0) {
            temp_r1_8944 = M2C_FIELD(var_r4_8938, M2C_UNK (**)(void *), 0xC);
            if (temp_r1_8944 != NULL) {
                temp_r1_8944(var_r4_8938);
            }
        }
        var_r6_8937 += 0x60;
        var_r4_8938 += 0x60;
        var_r5_8939 -= 1;
    } while (var_r5_8939 >= 0);
}

void sub_0201C5F8(void) {

}

void sub_0201C5FC(s32 arg0) {
    s32 sp0;
    s32 sp4;
    M2C_UNK sp8;
    M2C_UNK sp10;
    M2C_UNK sp18;

    memcpy(&sp8, (void *)0x0202B37C, 8U);
    memcpy(&sp10, (void *)0x0202B384, 8U);
    memcpy(&sp18, (void *)0x0202B38C, 8U);
    sp0 = (s32) *(&sp10 + arg0);
    sp4 = (s32) *(&sp18 + arg0);
    sub_02019BD8(1U, 7U, 6U, M2C_FIELD((&sp0 + arg0), u8 *, 8), M2C_ERROR(/* Unable to find stack arg 0x0 in block */), M2C_ERROR(/* Unable to find stack arg 0x4 in block */));
    CpuFastSet((void *)0x020002E0, (void *)0x050002E0, 8U);
}

void sub_0201C668(void *arg0) {
    s32 temp_r0_9026;

    sub_0201C5FC((M2C_FIELD(arg0, s32 *, 0x18) & 3) + (M2C_FIELD(arg0, s32 *, 0x14) * 4));
    temp_r0_9026 = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_r0_9026;
    if (temp_r0_9026 > 0xA) {
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + 1);
        M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    }
    sub_0201C5F8(arg0);
}

void sub_0201C69C(void *arg0) {
    sub_0201C428(arg0, 0x0202B378, 0);
    sub_0201C5F8(arg0);
    M2C_FIELD(arg0, void (**)(void *), 0x10) = sub_0201C668;
    sub_0201C668(arg0);
}

void sub_0201C6C8(void) {

}

void sub_0201C6CC(void *arg0) {
    M2C_UNK (*temp_r1_9071)();

    temp_r1_9071 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x10);
    if (temp_r1_9071 != NULL) {
        temp_r1_9071();
    }
    sub_0201C444(arg0, 0x0202B378);
}

void sub_0201C6EC(void *arg0) {
    void *var_r4_9095;

    var_r4_9095 = **(0x0202B378 + (M2C_FIELD(arg0, s16 *, 0x38) * 4));
    if (M2C_FIELD(var_r4_9095, u16 *, 6) != 0xFFFF) {
        do {
            sub_0201C490(arg0, var_r4_9095, (*(u8 *)0x030023B0 * 8) + gUnk3002410);
            *(u8 *)0x030023B0 += 1;
            var_r4_9095 += 8;
        } while (M2C_FIELD(var_r4_9095, u16 *, 6) != 0xFFFF);
    }
}

void sub_0201C740(void) {

}

void sub_0201C744(void *arg0) {
    sub_0201C428(arg0, 0x0202B3DC, 0);
    M2C_FIELD(arg0, void (**)(void *), 0x10) = sub_0201C740;
    sub_0201C740(arg0);
}

void sub_0201C768(void) {

}

void sub_0201C76C(void *arg0) {
    M2C_UNK (*temp_r1_9159)();

    temp_r1_9159 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x10);
    if (temp_r1_9159 != NULL) {
        temp_r1_9159();
    }
    sub_0201C444(arg0, 0x0202B3DC);
}

void sub_0201C78C(void *arg0) {
    void *var_r4_9183;

    var_r4_9183 = **(0x0202B3DC + (M2C_FIELD(arg0, s16 *, 0x38) * 4));
    if (M2C_FIELD(var_r4_9183, u16 *, 6) != 0xFFFF) {
        do {
            sub_0201C490(arg0, var_r4_9183, (*(u8 *)0x030023B0 * 8) + gUnk3002410);
            *(u8 *)0x030023B0 += 1;
            var_r4_9183 += 8;
        } while (M2C_FIELD(var_r4_9183, u16 *, 6) != 0xFFFF);
    }
}

void sub_0201C7E0(void) {
    s32 sp0;

    REG_IME = 0;
    REG_IRQ.enable &= 0xFF3F;
    REG_IME = 1;
    *(s16 *)0x04000134 = 0;
    *(s32 *)0x04000128 = 0x2000;
    *(s32 *)0x04000128 = (s16) ((u16) *(s32 *)0x04000128 | 0x4003);
    sp0 = 0;
    CpuSet(&sp0, (void *)0x030036D0, 0x0500000EU);
    M2C_FIELD((void *)0x030036D0, s32 *, 0x18) = -1;
    M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) = -1;
    REG_IME = 0;
    REG_IRQ.enable |= 0x80;
    REG_IME = 1;
}

void sub_0201C870(void) {
    REG_IME = 0;
    REG_IRQ.enable &= 0xFF3F;
    REG_IME = 1;
    *(s16 *)0x04000134 = 0;
    *(s16 *)0x04000128 = 0x2003;
    M2C_FIELD((void *)0x0400010C, s32 *, 0) = 0xA4FB;
    M2C_FIELD((void *)0x0400010C, s16 *, 0xF6) = 0xC0;
}

s32 sub_0201C8C0(void) {
    s32 temp_r2_9322;
    s32 temp_r5_9525;
    s32 var_r2_9419;
    s32 var_r4_9526;
    s32 var_r7_9324;
    s8 temp_r0_9612;
    u16 *var_r1_9411;
    u16 temp_r0_9562;
    u16 var_r0_9652;
    u16 var_r3_9417;
    u8 temp_r0_9327;
    u8 temp_r0_9376;
    u8 temp_r0_9506;
    u8 temp_r1_9460;
    u8 temp_r3_9456;
    u8 temp_r4_9368;

    temp_r2_9322 = M2C_FIELD((void *)0x04000128, s32 *, 0);
    var_r7_9324 = -1;
    temp_r0_9327 = M2C_FIELD((void *)0x030036D0, u8 *, 1);
    switch (temp_r0_9327) {                         /* irregular */
    case 3:
        temp_r5_9525 = M2C_FIELD((void *)0x030036D0, s32 *, 0x14);
        var_r4_9526 = temp_r5_9525;
        if ((M2C_FIELD((void *)0x030036D0, u8 *, 0x32) != 0) || ((s32) M2C_FIELD((void *)0x030036D0, s32 *, 0x20) > 1) || (M2C_FIELD((void *)0x030036D0, u8 *, 0x31) != 0)) {
            var_r7_9324 = 0xA;
        } else {
            if (temp_r5_9525 > 0x1CC0) {
                var_r4_9526 = 0x1CC0;
            } else if (temp_r5_9525 < 0) {
                var_r4_9526 = 0;
            }
            if ((s32) M2C_FIELD((void *)0x030036D0, s16 *, 0x2E) < var_r4_9526) {
                do {
                    temp_r0_9562 = (u16) M2C_FIELD((void *)0x030036D0, s16 *, 0x2E);
                    M2C_FIELD((void *)0x030036D0, s16 *, 0x2E) = (s16) (temp_r0_9562 + 1);
                    M2C_FIELD((void *)0x030036D0, u16 *, 0x2C) = (u16) (*(((s32) (temp_r0_9562 << 0x10) >> 0xF) + M2C_FIELD((void *)0x030036D0, s32 *, 0xC)) + M2C_FIELD((void *)0x030036D0, u16 *, 0x2C));
                } while ((s32) M2C_FIELD((void *)0x030036D0, s16 *, 0x2E) < var_r4_9526);
                M2C_FIELD((void *)0x030036D0, s32 *, 0x20) = 0;
            }
            if (temp_r5_9525 > 0x1CC0) {
                if ((s16) (M2C_FIELD((void *)0x030036D0, u16 *, 0x2C) + M2C_FIELD((void *)0x030036D0, u16 *, 0x24)) == -1) {
                    M2C_FIELD((void *)0x030036D0, s8 *, 3) = 1;
                } else {
                    M2C_FIELD((void *)0x030036D0, s8 *, 4) = 1;
                }
                M2C_FIELD((void *)0x030036D0, s32 *, 0x20) = 0;
                M2C_FIELD((void *)0x030036D0, u8 *, 1) = 4U;
            }
        }
        break;
    case 4:
        temp_r0_9612 = (s8) M2C_FIELD((void *)0x030036D0, u8 *, 0x30);
        if (temp_r0_9612 == 1) {
            var_r7_9324 = 9;
        } else if ((temp_r0_9612 == -1) || (M2C_FIELD((void *)0x030036D0, u8 *, 0x32) != 0) || ((s32) M2C_FIELD((void *)0x030036D0, s32 *, 0x20) > 6)) {
            var_r7_9324 = 0xA;
        }
        if (var_r7_9324 != -1) {
            M2C_FIELD((void *)0x030036D0, u8 *, 1) = 5U;
        }
        break;
    case 0:
        if ((s32) M2C_FIELD((void *)0x030036D0, s32 *, 0x20) > 0x258) {
            var_r7_9324 = 0x10;
            if ((temp_r2_9322 & 0x88) == 8) {

            } else {
block_12:
                var_r7_9324 = 8;
            }
        } else {
            temp_r4_9368 = temp_r2_9322 & 0x88;
            if (temp_r4_9368 != 8) {

            } else {
                temp_r0_9376 = temp_r2_9322 & 4;
                if (temp_r0_9376 == 0) {
                    REG_IME = (u16) temp_r0_9376;
                    REG_IRQ.enable &= 0xFF7F;
                    REG_IRQ.enable |= 0x40;
                    REG_IME = 1;
                    M2C_FIELD((void *)0x04000128, u8 *, 1) = (u8) (-0x41 & M2C_FIELD((void *)0x04000128, u8 *, 1));
                    *(s16 *)0x04000202 = 0xC0;
                    *(s32 *)0x0400010C = 0xA4FB;
                    M2C_FIELD((void *)0x030036D0, u8 *, 0) = temp_r4_9368;
                    M2C_FIELD((void *)0x04000128, s32 *, 0) = (s8) ((u8) M2C_FIELD((void *)0x04000128, s32 *, 0) | 0x80);
                }
                var_r1_9411 = *(u16 **)0x03001B40;
                M2C_FIELD((void *)0x030036D0, u16 **, 8) = var_r1_9411;
                M2C_FIELD((void *)0x030036D0, s32 *, 0xC) = (s32) *(s32 *)0x03002970;
                var_r3_9417 = 0;
                var_r2_9419 = 0x1CC0;
                do {
                    var_r3_9417 += *var_r1_9411;
                    var_r1_9411 += 2;
                    var_r2_9419 -= 1;
                } while (var_r2_9419 != 0);
                M2C_FIELD((void *)0x030036D0, u16 *, 0x2A) = (u16) ~var_r3_9417;
                if (M2C_FIELD((void *)0x030036D0, u8 *, 0) != 0) {
                    *(s16 *)0x0400010E = 0xC0;
                }
                M2C_FIELD((void *)0x030036D0, s32 *, 0x20) = var_r2_9419;
                M2C_FIELD((void *)0x030036D0, u8 *, 1) = 2U;
            }
        }
        break;
    case 2:
        temp_r3_9456 = M2C_FIELD((void *)0x030036D0, u8 *, 0x32);
        if (temp_r3_9456 == 0) {
            temp_r1_9460 = M2C_FIELD((void *)0x030036D0, u8 *, 2);
            if ((1 & temp_r1_9460) && (0xE & temp_r1_9460)) {
                var_r7_9324 = 8;
                if ((u32) ((u32) (temp_r2_9322 << 0x1A) >> 0x1E) > 1U) {

                } else {
                    var_r7_9324 = 7;
                    M2C_FIELD((void *)0x030036D0, s32 *, 0x20) = (s32) temp_r3_9456;
                    M2C_FIELD((void *)0x030036D0, u8 *, 1) = 3U;
                    sub_02019D58(0x29U);
                }
            } else if ((s32) M2C_FIELD((void *)0x030036D0, s32 *, 0x20) > 0x258) {
                var_r7_9324 = 0x10;
            } else if (!(((s32) M2C_FIELD((void *)0x030036D0, u8 *, 2) >> ((u32) (temp_r2_9322 << 0x1A) >> 0x1E)) & 1)) {
                temp_r0_9506 = M2C_FIELD((void *)0x030036D0, u8 *, 0x33);
                if ((u32) temp_r0_9506 <= 7U) {
                    M2C_FIELD((void *)0x030036D0, u8 *, 0x33) = (u8) (temp_r0_9506 + 1);
                } else {
                    M2C_FIELD((void *)0x030036D0, s8 *, 0x34) = 1;
                }
            } else {
                M2C_FIELD((void *)0x030036D0, u8 *, 0x33) = 0U;
            }
        } else {
            goto block_12;
        }
        break;
    }
    M2C_FIELD((void *)0x030036D0, s32 *, 0x20) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x20) + 1);
    if ((var_r7_9324 != -1) && (var_r7_9324 != 7)) {
        sub_02019D68(0x29U);
        var_r0_9652 = 0x28;
        if (var_r7_9324 == 9) {
            var_r0_9652 = 0x27;
        }
        sub_02019D78(var_r0_9652);
        sub_0201C870();
    }
    return var_r7_9324;
}

void sub_0201CB50(void) {
    s32 sp0;
    s32 sp4;
    s32 *var_r2_9691;
    s32 temp_r1_9678;
    s32 temp_r2_9772;
    s32 temp_r2_9853;
    s32 temp_r2_9895;
    s32 temp_r3_9684;
    s32 var_r3_9688;
    s8 *var_r1_9840;
    s8 var_r0_9841;
    u16 *temp_r0_9898;
    u16 temp_r1_9744;
    u16 temp_r1_9818;
    u16 temp_r2_9828;
    u16 var_r1_9941;
    u32 temp_r4_9735;
    u8 temp_r2_9933;

    sp0 = M2C_FIELD((void *)0x04000120, s32 *, 0);
    sp4 = M2C_FIELD((void *)0x04000120, s32 *, 4);
    temp_r1_9678 = M2C_FIELD((void *)0x04000128, s32 *, 0);
    *(s8 *)0x03003702 = (s8) ((u32) (temp_r1_9678 << 0x19) >> 0x1F);
    temp_r3_9684 = M2C_FIELD((void *)0x030036D0, s32 *, 0x1C);
    if (temp_r3_9684 < 0) {
        var_r3_9688 = 0;
        var_r2_9691 = &sp0;
        do {
            if (*var_r2_9691 == 0xFEFE) {
                M2C_FIELD((void *)0x030036D0, u8 *, 2) = (u8) ((1 << var_r3_9688) | M2C_FIELD((void *)0x030036D0, u8 *, 2));
            }
            var_r2_9691 += 2;
            var_r3_9688 += 1;
        } while (var_r3_9688 <= 3);
        if ((3 & M2C_FIELD((void *)0x030036D0, u8 *, 2)) != 3) {

        } else {
            M2C_FIELD((void *)0x030036D0, s32 *, 0x18) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x18) + 1);
            M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) + 1);
            M2C_FIELD((void *)0x030036D0, u16 *, 0x28) = 0U;
            M2C_FIELD((void *)0x030036D0, u16 *, 0x26) = 0U;
        }
    } else if (temp_r3_9684 <= 0x1DAD) {
        temp_r4_9735 = temp_r1_9678 << 0x1A;
        temp_r1_9744 = *((((temp_r4_9735 >> 0x1E) ^ 1) * 2) + sp) + M2C_FIELD((void *)0x030036D0, u16 *, 0x26);
        M2C_FIELD((void *)0x030036D0, u16 *, 0x26) = temp_r1_9744;
        if ((temp_r3_9684 & 0x1F) == 0x1F) {
            if ((s16) temp_r1_9744 != -1) {
                M2C_FIELD((void *)0x030036D0, u8 *, 0x31) = (u8) (M2C_FIELD((void *)0x030036D0, u8 *, 0x31) | 1);
            }
            M2C_FIELD((void *)0x030036D0, u16 *, 0x26) = 0U;
        } else {
            temp_r2_9772 = M2C_FIELD((void *)0x030036D0, s32 *, 0x14);
            if (temp_r2_9772 <= 0x1CBF) {
                *((temp_r2_9772 * 2) + M2C_FIELD((void *)0x030036D0, s32 *, 0xC)) = *((((temp_r4_9735 >> 0x1E) ^ 1) * 2) + sp);
                M2C_FIELD((void *)0x030036D0, s32 *, 0x14) = (s32) (temp_r2_9772 + 1);
            }
        }
        M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) + 1);
    } else if (temp_r3_9684 == 0x1DAE) {
        M2C_FIELD((void *)0x030036D0, u16 *, 0x24) = (u16) *(((1 ^ ((u32) (temp_r1_9678 << 0x1A) >> 0x1E)) * 2) + sp);
        M2C_FIELD((void *)0x030036D0, s32 *, 0x1C) = (s32) (temp_r3_9684 + 1);
        M2C_FIELD((void *)0x030036D0, s32 *, 0x14) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x14) + 1);
    } else {
        temp_r1_9818 = M2C_FIELD(&sp0, u16 *, 0);
        if ((u32) (u16) (temp_r1_9818 + 0x104) <= 1U) {
            temp_r2_9828 = M2C_FIELD(&sp0, u16 *, 2);
            if ((u32) (u16) (temp_r2_9828 + 0x104) <= 1U) {
                if ((temp_r1_9818 == 0xFEFD) && (temp_r2_9828 == temp_r1_9818)) {
                    var_r1_9840 = (void *)0x030036D0 + 0x30;
                    var_r0_9841 = 1;
                } else {
                    var_r1_9840 = (void *)0x030036D0 + 0x30;
                    var_r0_9841 = 0xFF;
                }
                *var_r1_9840 = var_r0_9841;
            }
        }
    }
    temp_r2_9853 = M2C_FIELD((void *)0x030036D0, s32 *, 0x18);
    if (temp_r2_9853 < 0) {
        if (M2C_FIELD((void *)0x030036D0, u8 *, 0x34) != 0) {
            M2C_FIELD((void *)0x04000128, u16 *, 2) = 0xFEFEU;
        }
        M2C_FIELD((void *)0x030036D0, u16 *, 0x28) = 0U;
    } else if (temp_r2_9853 <= 0x1DAD) {
        if ((temp_r2_9853 & 0x1F) == 0x1F) {
            M2C_FIELD((void *)0x04000128, u16 *, 2) = (u16) ~M2C_FIELD((void *)0x030036D0, u16 *, 0x28);
            M2C_FIELD((void *)0x030036D0, u16 *, 0x28) = 0U;
        } else {
            temp_r2_9895 = M2C_FIELD((void *)0x030036D0, s32 *, 0x10);
            temp_r0_9898 = (temp_r2_9895 * 2) + M2C_FIELD((void *)0x030036D0, s32 *, 8);
            M2C_FIELD((void *)0x04000128, u16 *, 2) = (u16) *temp_r0_9898;
            M2C_FIELD((void *)0x030036D0, u16 *, 0x28) = (u16) (*temp_r0_9898 + M2C_FIELD((void *)0x030036D0, u16 *, 0x28));
            M2C_FIELD((void *)0x030036D0, s32 *, 0x10) = (s32) (temp_r2_9895 + 1);
        }
        M2C_FIELD((void *)0x030036D0, s32 *, 0x18) = (s32) (M2C_FIELD((void *)0x030036D0, s32 *, 0x18) + 1);
    } else if (temp_r2_9853 == 0x1DAE) {
        M2C_FIELD((void *)0x04000128, u16 *, 2) = (u16) M2C_FIELD((void *)0x030036D0, u16 *, 0x2A);
        M2C_FIELD((void *)0x030036D0, s32 *, 0x18) = (s32) (temp_r2_9853 + 1);
    } else if ((temp_r2_9853 > 0x1DAE) && ((temp_r2_9933 = M2C_FIELD((void *)0x030036D0, u8 *, 3), (temp_r2_9933 != 0)) || (M2C_FIELD((void *)0x030036D0, u8 *, 4) != 0))) {
        var_r1_9941 = 0xFEFC;
        if (temp_r2_9933 != 0) {
            var_r1_9941 = 0xFEFD;
        }
        M2C_FIELD((void *)0x04000128, u16 *, 2) = var_r1_9941;
    }
    if (M2C_FIELD((void *)0x030036D0, u8 *, 0) == 8) {
        *(s16 *)0x0400010E = 0;
        M2C_FIELD((void *)0x04000128, s32 *, 0) = (s16) ((u16) M2C_FIELD((void *)0x04000128, s32 *, 0) | 0x80);
        *(s16 *)0x0400010E = 0xC0;
    }
}

s32 sub_0201CDA0(u16 arg0, s32 arg1, u8 arg2, M2C_UNK arg3) {
    s32 sp0;
    s16 *var_r0_10141;
    s32 temp_r1_10000;
    s32 temp_r1_10073;
    s32 var_r2_10011;
    s32 var_r2_10098;
    s32 var_r4_10082;
    u16 *var_r5_10018;
    u16 *var_r5_10101;
    u16 temp_r0_9985;
    u16 temp_r3_10021;
    u16 temp_r3_10105;
    u8 *var_r2_10129;
    u8 temp_r7_9987;
    void *var_r3_10039;

    temp_r0_9985 = arg0;
    temp_r7_9987 = arg2;
    switch (temp_r0_9985) {                         /* irregular */
    case 1:
        temp_r1_10000 = arg1 - 0x11;
        var_r2_10011 = 0;
        sp0 = temp_r1_10000;
        var_r5_10018 = (u16 *)0x0202FC1C;
        do {
            temp_r3_10021 = *var_r5_10018;
            if (temp_r3_10021 != 0) {
                *(((0xFF0 & temp_r1_10000) * 8) + 0x0600C000 + ((0xF & temp_r1_10000) * 4) + ((var_r2_10011 & 0xFF8) * 8) + ((var_r2_10011 & 7) * 2)) = temp_r3_10021;
            }
            var_r5_10018 += 2;
            var_r2_10011 += 1;
        } while (var_r2_10011 <= 0x3F);
        var_r3_10039 = NULL;
        do {
            *(0x03003720 + ((u32) ((sp0 + *(0x0202FCFC + (s32) var_r3_10039)) << 0x18) >> 0x17)) = 0x1F;
            var_r3_10039 += 1;
        } while ((s32) var_r3_10039 <= 0xF);
        *(s8 *)0x03003B36 = 1;
        sub_0201DF9C(0, 0, arg1, 0U);
block_23:
        return 0;
    case 2:
        temp_r1_10073 = arg1 - 0x11;
        sp0 = temp_r1_10073;
        if (temp_r7_9987 == 0) {
            var_r4_10082 = ((0xFF0 & temp_r1_10073) * 8) + 0x0600C000;
        } else {
            var_r4_10082 = ((0xFF0 & temp_r1_10073) * 8) + 0x0600C800;
        }
        var_r2_10098 = 0;
        var_r5_10101 = (u16 *)0x0202FC9C;
        do {
            temp_r3_10105 = *var_r5_10101;
            if (temp_r3_10105 != 0) {
                *(var_r4_10082 + ((0xF & temp_r1_10073) * 4) + ((var_r2_10098 & 0xFF8) * 8) + ((var_r2_10098 & 7) * 2)) = temp_r3_10105;
            }
            var_r5_10101 += 2;
            var_r2_10098 += 1;
        } while (var_r2_10098 <= 0x2F);
        var_r2_10129 = (u8 *)0x0202FD0C;
        do {
            if (temp_r7_9987 == 0) {
                var_r0_10141 = ((u32) ((*var_r2_10129 + sp0) << 0x18) >> 0x17) + 0x03003720;
            } else {
                var_r0_10141 = ((u32) ((*var_r2_10129 + sp0) << 0x18) >> 0x17) + 0x03003920;
            }
            *var_r0_10141 = 0x20;
            var_r2_10129 += 1;
        } while ((s32) var_r2_10129 <= 0x0202FD14);
        *(s8 *)0x03003BAA = sp0 + 0x21;
        *(s8 *)0x03003B39 = 1;
        sub_0201DF9C(1, 2, arg1, temp_r7_9987);
        goto block_23;
    default:
        return 1;
    }
}

void sub_0201CF3C(u16 arg0, s32 arg1, u8 arg2, M2C_UNK arg3) {
    s32 sp0;
    s16 temp_r2_10406;
    s16 var_r2_10303;
    s32 temp_r1_10376;
    s32 temp_r1_10393;
    s32 temp_r3_10243;
    s32 var_r0_10381;
    s32 var_r1_10384;
    s32 var_r2_10344;
    s32 var_r3_10312;
    s32 var_r4_10252;
    s32 var_sl_10202;
    u16 *var_r4_10382;
    u16 temp_r2_10292;
    u16 temp_r7_10196;
    u32 temp_r0_10203;
    u8 *var_r1_10462;
    u8 *var_r3_10346;
    u8 temp_r2_10198;
    u8 var_r4_10302;
    void *temp_r1_10403;
    void *temp_r1_10426;
    void *temp_r4_10287;

    temp_r7_10196 = arg0;
    temp_r2_10198 = arg2;
    var_sl_10202 = 0;
    temp_r0_10203 = temp_r7_10196 - 3;
    switch (temp_r0_10203) {                        /* irregular */
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        temp_r3_10243 = (((arg1 & 0xF) - 1) & 0xF) | (0xF0 & arg1);
        if ((temp_r2_10198 == 0) || ((temp_r3_10243 & 0xF) == 0xF)) {
            var_r4_10252 = 0x0600C000;
            *(void *)0x03003B24 = (u16) *(0x03003720 + (temp_r3_10243 * 2));
        } else {
            var_r4_10252 = 0x0600C800;
            *(u16 *)0x03003B24 = *(0x03003920 + (temp_r3_10243 * 2));
            var_sl_10202 = 1;
        }
        temp_r4_10287 = var_r4_10252 + ((0xFF0 & temp_r3_10243) * 8) + ((temp_r3_10243 & 0xF) * 4);
        temp_r2_10292 = *(0x0202FD16 + ((temp_r7_10196 - 5) * 2));
        if (*(void *)0x03003B24 == 0xFFF) {
            M2C_FIELD(temp_r4_10287, u16 *, 0x42) = temp_r2_10292;
        }
        var_r4_10302 = temp_r4_10287 + 0x42 + 2;
        var_r2_10303 = temp_r2_10292 + 1;
        sp0 = temp_r7_10196 - 0xC;
        var_r3_10312 = 2;
        do {
            if ((var_sl_10202 == 0) && ((var_r4_10302 == 0) || (var_r4_10302 == 0x40) || (var_r4_10302 == 0x80) || (var_r4_10302 == 0xC0))) {
                var_r4_10302 += 0x7C0;
            }
            *var_r4_10302 = var_r2_10303;
            var_r3_10312 -= 1;
            var_r4_10302 += 2;
            var_r2_10303 += 1;
        } while (var_r3_10312 >= 0);
        if ((u32) (u16) sp0 <= 1U) {
            return;
        }
        var_r2_10344 = 0;
        var_r3_10346 = (u8 *)0x03003B5D;
loop_20:
        if (*var_r3_10346 != 0) {
            var_r3_10346 += 1;
            var_r2_10344 += 1;
            if (var_r2_10344 > 0x1D) {
                return;
            }
            goto loop_20;
        }
        *var_r3_10346 = 1;
block_32:
        sub_0201E430(var_r2_10344, temp_r7_10196, arg1, temp_r2_10198);
        return;
    case 16:
        sub_0201E1E0(0x54, arg1, temp_r2_10198);
        return;
    case 17:
        if (temp_r2_10198 == 0) {
            temp_r1_10376 = (0xFF0 & arg1) * 8;
            var_r0_10381 = (0xF & arg1) * 4;
            var_r4_10382 = temp_r1_10376 + 0x0600A000 + var_r0_10381;
            var_r1_10384 = temp_r1_10376 + 0x0600C000;
        } else {
            temp_r1_10393 = (0xFF0 & arg1) * 8;
            var_r0_10381 = (0xF & arg1) * 4;
            var_r4_10382 = temp_r1_10393 + 0x0600A800 + var_r0_10381;
            var_r1_10384 = temp_r1_10393 + 0x0600C800;
        }
        temp_r1_10403 = var_r1_10384 + var_r0_10381;
        temp_r2_10406 = 0x3FF & *var_r4_10382;
        *(s16 *)0x03003B22 = temp_r2_10406;
        if (((u32) (u16) (temp_r2_10406 - 0xA) <= 5U) || ((u32) (u16) (temp_r2_10406 - 0xC6) <= 5U)) {
            M2C_FIELD(temp_r1_10403, s16 *, 0) = 0x22AC;
            temp_r1_10426 = temp_r1_10403 + 2;
            M2C_FIELD(temp_r1_10403, s16 *, 2) = 0x22AD;
            M2C_FIELD(temp_r1_10426, s16 *, 0x3E) = 0x22AE;
            M2C_FIELD((temp_r1_10426 + 0x3E), s16 *, 2) = 0x22AF;
            return;
        }
        return;
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        var_r2_10344 = 0;
        var_r1_10462 = (u8 *)0x03003B5D;
loop_34:
        if (*var_r1_10462 != 0) {
            var_r1_10462 += 1;
            var_r2_10344 += 1;
            if (var_r2_10344 > 0x1D) {

            } else {
                goto loop_34;
            }
        } else {
            *var_r1_10462 = 1;
            goto block_32;
        }
        break;
    }
}

void sub_0201D19C(void) {
    s32 sp0;
    s32 sp4;
    s16 *var_r0_10518;
    s16 *var_r1_10517;
    s16 *var_r2_10498;
    s32 temp_r0_10567;
    s32 temp_r0_10575;
    s32 temp_r0_10582;
    s32 temp_r0_10654;
    s32 temp_r0_10753;
    s32 temp_r0_10761;
    s32 temp_r0_10768;
    s32 temp_r0_10850;
    s32 temp_r1_10553;
    s32 temp_r1_10604;
    s32 temp_r1_10796;
    s32 temp_r2_10627;
    s32 temp_r2_10821;
    s32 temp_r4_10542;
    s32 temp_r4_10620;
    s32 temp_r4_10734;
    s32 temp_r4_10815;
    s32 temp_r5_10546;
    s32 temp_r5_10617;
    s32 temp_r5_10812;
    s32 var_r4_10683;
    s32 var_r4_10880;
    s32 var_r7_10586;
    s32 var_r7_10775;
    s32 var_r8_10497;
    s32 var_r8_10520;
    s32 var_r8_10533;
    u16 *temp_r2_10584;
    u16 *temp_r3_10624;
    u16 *temp_r3_10819;
    void *temp_r2_10704;
    void *temp_r2_10901;

    *(u16 *)0x03003B22 = 0x5851;
    var_r8_10497 = 0;
    var_r2_10498 = (s16 *)0x0600C000;
    do {
        *var_r2_10498 = 0x200;
        var_r8_10497 += 2;
        var_r2_10498 += 2;
    } while (var_r8_10497 <= 0xFFF);
    sp4 = 0x03003720;
    var_r1_10517 = (s16 *)0x03003920;
    var_r0_10518 = (s16 *)0x03003720;
    var_r8_10520 = 0xFF;
    do {
        *var_r0_10518 = 0xFFF;
        *var_r1_10517 = 0xFFF;
        var_r1_10517 += 2;
        var_r0_10518 += 2;
        var_r8_10520 -= 1;
    } while (var_r8_10520 >= 0);
    var_r8_10533 = 0;
loop_5:
    temp_r4_10542 = var_r8_10533 >> 4;
    temp_r5_10546 = ((var_r8_10533 & 0xF) * 2) + ((temp_r4_10542 & 0xF) << 5);
    temp_r1_10553 = 0x8000 & sub_02024A9C(*(*(s32 *)0x03001B40 + 0x24 + temp_r5_10546));
    sp0 = var_r8_10533 + 1;
    if (temp_r1_10553 != 0) {

    } else {
        temp_r0_10567 = sub_02024A9C(*(*(void *)0x03001B40 + 0x24 + temp_r5_10546));
        if (temp_r0_10567 > 0x57) {

        } else {
            temp_r0_10575 = temp_r0_10567 * 0xC;
            if (temp_r0_10567 == 0x57) {
                temp_r0_10582 = var_r8_10533 * 2;
                temp_r2_10584 = sp4 + temp_r0_10582;
                var_r7_10586 = temp_r0_10582;
                if (*temp_r2_10584 == 0xFFF) {
                    *temp_r2_10584 = 0x7777;
                }
            } else {
                temp_r1_10604 = var_r8_10533 * 2;
                *(sp4 + temp_r1_10604) = (s16) temp_r0_10567;
                var_r7_10586 = temp_r1_10604;
            }
            if (*(0x0202F7FC + temp_r0_10575) == 0x270) {
                temp_r5_10617 = *(void *)0x03001B40;
                temp_r4_10620 = temp_r4_10542 & 0xF;
                temp_r3_10624 = temp_r5_10617 + 0x18F8 + (temp_r4_10620 * 2);
                temp_r2_10627 = var_r8_10533 & 0xF;
                *temp_r3_10624 |= 1 << temp_r2_10627;
                *(temp_r5_10617 + 0x24 + ((temp_r2_10627 * 2) + (temp_r4_10620 << 5))) = 0x2512;
                *(sp4 + var_r7_10586) = 0x10;
            }
            sp0 = var_r8_10533 + 1;
            if (temp_r0_10567 != 0x57) {
                temp_r0_10654 = sub_0201CDA0(*(0x0202F7FC + temp_r0_10575), var_r8_10533, 0U);
                if (temp_r0_10654 == 1) {
                    *(u16 *)0x03003B24 = *(0x0202F7FC + temp_r0_10575);
                    if (((s32) *(*(void *)0x03001B40 + 0x18F8 + ((temp_r4_10542 & 0xF) * 2)) >> (var_r8_10533 & 0xF)) & temp_r0_10654) {
                        *(u16 *)0x03003B24 = 0x1270;
                    }
                    var_r4_10683 = 0;
                    *(void *)0x03003B22 = 0U;
                    do {
                        temp_r2_10704 = var_r4_10683 + 0x0600C000 + ((0xFF0 & var_r8_10533) * 8) + ((0xF & var_r8_10533) * 4);
                        M2C_FIELD(temp_r2_10704, s16 *, 0) = (s16) (*(void *)0x03003B22 + *(u16 *)0x03003B24);
                        M2C_FIELD(temp_r2_10704, s16 *, 2) = (s16) (*(void *)0x03003B22 + *(u16 *)0x03003B24 + 1);
                        var_r4_10683 += 0x40;
                        *(void *)0x03003B22 = 2U;
                    } while (var_r4_10683 <= 0x4F);
                    sub_0201CF3C(M2C_FIELD((temp_r0_10575 + 0x0202F7FC), u16 *, 2), var_r8_10533, 0U);
                }
            }
        }
    }
    temp_r4_10734 = ((var_r8_10533 & 0xF) * 2) + ((temp_r4_10542 & 0xF) << 5);
    if (0x8000 & sub_02024A9C(*(*(void *)0x03001B40 + 0x224 + temp_r4_10734))) {

    } else {
        temp_r0_10753 = sub_02024A9C(*(*(void *)0x03001B40 + 0x224 + temp_r4_10734));
        if (temp_r0_10753 > 0x57) {

        } else {
            temp_r0_10761 = temp_r0_10753 * 0xC;
            if (temp_r0_10753 == 0x57) {
                temp_r0_10768 = var_r8_10533 * 2;
                var_r7_10775 = temp_r0_10768;
                if (*(0x03003920 + temp_r0_10768) == 0xFFF) {
                    *(0x03003920 + temp_r0_10768) = 0x7777U;
                }
            } else {
                temp_r1_10796 = var_r8_10533 * 2;
                *(0x03003920 + temp_r1_10796) = (s16) temp_r0_10753;
                var_r7_10775 = temp_r1_10796;
            }
            if (*(0x0202F7FC + temp_r0_10761) == 0x270) {
                temp_r5_10812 = *(void *)0x03001B40;
                temp_r4_10815 = temp_r4_10542 & 0xF;
                temp_r3_10819 = temp_r5_10812 + 0x1918 + (temp_r4_10815 * 2);
                temp_r2_10821 = var_r8_10533 & 0xF;
                *temp_r3_10819 |= 1 << temp_r2_10821;
                *(temp_r5_10812 + 0x224 + ((temp_r2_10821 * 2) + (temp_r4_10815 << 5))) = 0x2512;
                *(0x03003920 + var_r7_10775) = 0x10;
            }
            if (temp_r0_10753 != 0x57) {
                temp_r0_10850 = sub_0201CDA0(*(0x0202F7FC + temp_r0_10761), var_r8_10533, 1U);
                if (temp_r0_10850 == 1) {
                    *(void *)0x03003B24 = (u16) *(0x0202F7FC + temp_r0_10761);
                    if (((s32) *(*(void *)0x03001B40 + 0x1918 + ((0xF & temp_r4_10542) * 2)) >> (var_r8_10533 & 0xF)) & temp_r0_10850) {
                        *(void *)0x03003B24 = 0x1270U;
                    }
                    var_r4_10880 = 0;
                    *(void *)0x03003B22 = 0U;
                    do {
                        temp_r2_10901 = var_r4_10880 + 0x0600C800 + ((0xFF0 & var_r8_10533) * 8) + ((0xF & var_r8_10533) * 4);
                        M2C_FIELD(temp_r2_10901, s16 *, 0) = (s16) (*(void *)0x03003B22 + *(void *)0x03003B24);
                        M2C_FIELD(temp_r2_10901, s16 *, 2) = (s16) (*(void *)0x03003B22 + *(void *)0x03003B24 + 1);
                        var_r4_10880 += 0x40;
                        *(void *)0x03003B22 = 2U;
                    } while (var_r4_10880 <= 0x4F);
                    sub_0201CF3C(M2C_FIELD((temp_r0_10761 + 0x0202F7FC), u16 *, 2), var_r8_10533, 1U);
                }
            }
        }
    }
    var_r8_10533 = sp0;
    if (sp0 <= 0xFF) {
        goto loop_5;
    }
}

void sub_0201D550(void) {
    s32 var_r2_10964;
    u16 *var_r3_10966;
    u16 *var_r4_10965;
    u16 temp_r0_10975;
    u32 var_r1_10968;
    u8 temp_r5_10958;

    temp_r5_10958 = (u8) ((u32) gGameState.game_time_frames / 216000U);
    if (*(u8 *)0x03003B26 != temp_r5_10958) {
        var_r2_10964 = 0;
        var_r4_10965 = (u16 *)0x02000102;
        var_r3_10966 = (u16 *)0x02000122;
        var_r1_10968 = temp_r5_10958 << 0x12;
        do {
            temp_r0_10975 = *(0x02034EE4 + ((var_r1_10968 >> 0x10) * 2));
            *var_r4_10965 = temp_r0_10975;
            *var_r3_10966 = temp_r0_10975;
            var_r1_10968 += 0x10000;
            var_r2_10964 += 1;
            var_r4_10965 += 2;
            var_r3_10966 += 2;
        } while (var_r2_10964 <= 3);
        *(void *)0x03003B26 = temp_r5_10958;
    }
}

void sub_0201D5C4(void) {
    s32 temp_r2_11087;
    s32 temp_r2_11156;
    s32 var_r2_11017;
    s32 var_r2_11210;
    s8 *var_r0_11212;
    u16 *var_r3_11019;
    u16 *var_r4_11018;
    u16 temp_r0_11029;
    u32 var_r0_11120;
    u32 var_r0_11179;
    u32 var_r1_11022;
    u8 temp_r5_11011;

    temp_r5_11011 = (u8) ((u32) gGameState.game_time_frames / 216000U);
    if (*(u8 *)0x03003B26 != temp_r5_11011) {
        var_r2_11017 = 0;
        var_r4_11018 = (u16 *)0x02000102;
        var_r3_11019 = (u16 *)0x02000122;
        var_r1_11022 = temp_r5_11011 << 0x12;
        do {
            temp_r0_11029 = *(0x02034EE4 + ((var_r1_11022 >> 0x10) * 2));
            *var_r4_11018 = temp_r0_11029;
            *var_r3_11019 = temp_r0_11029;
            var_r1_11022 += 0x10000;
            var_r2_11017 += 1;
            var_r4_11018 += 2;
            var_r3_11019 += 2;
        } while (var_r2_11017 <= 3);
        *(void *)0x03003B26 = temp_r5_11011;
    }
    *(void *)0x03003B26 = 0xFFU;
    *(s8 *)0x03003B27 = 1;
    sub_02025D70();
    sub_02020B88();
    *(s8 *)0x03003BA7 = 4;
    *(s8 *)0x03003BA8 = 0;
    *(s8 *)0x03003BA9 = 0;
    *(s8 *)0x03003BAA = 0;
    M2C_FIELD((void *)0x03003710, s32 *, 8) = 0;
    M2C_FIELD((void *)0x03003710, s32 *, 0xC) = 0;
    M2C_FIELD((void *)0x03003710, s32 *, 0) = 0;
    M2C_FIELD((void *)0x03003710, s32 *, 4) = 0;
    M2C_FIELD((void *)0x03003710, s8 *, 0x49B) = 0;
    M2C_FIELD((void *)0x03003710, s16 *, 0x410) = 0;
    M2C_FIELD((void *)0x03003710, s8 *, 0x49D) = 0;
    temp_r2_11087 = 3 & M2C_FIELD(*(void **)0x03001B40, u8 *, 0x1938);
    M2C_FIELD((void *)0x03003710, s8 *, 0x49C) = 0;
    switch (temp_r2_11087) {                        /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_r0_11120 = 0x0202D3FC;
block_15:
        REG_DMA3.src = var_r0_11120;
        REG_DMA3.dest = 0x0600A000;
        REG_DMA3.control = 0x84000200;
        break;
    case 1:                                         /* switch 1 */
        var_r0_11120 = 0x0202DBFC;
        goto block_15;
    case 2:                                         /* switch 1 */
        var_r0_11120 = 0x0202E3FC;
        goto block_15;
    case 3:                                         /* switch 1 */
        var_r0_11120 = 0x0202EBFC;
        goto block_15;
    }
    temp_r2_11156 = 3 & M2C_FIELD(*(void *)0x03001B40, u8 *, 0x1939);
    switch (temp_r2_11156) {                        /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        var_r0_11179 = 0x0202B3FC;
block_27:
        REG_DMA3.src = var_r0_11179;
        REG_DMA3.dest = 0x0600A800;
        REG_DMA3.control = 0x84000200;
        break;
    case 1:                                         /* switch 2 */
        var_r0_11179 = 0x0202BBFC;
        goto block_27;
    case 2:                                         /* switch 2 */
        var_r0_11179 = 0x0202C3FC;
        goto block_27;
    case 3:                                         /* switch 2 */
        var_r0_11179 = 0x0202CBFC;
        goto block_27;
    }
    var_r2_11210 = 0x7F;
    var_r0_11212 = (void *)0x03003710 + 0x496;
    do {
        *var_r0_11212 = 0;
        var_r0_11212 -= 1;
        var_r2_11210 -= 1;
    } while (var_r2_11210 >= 0);
    sub_0201D19C();
}

void sub_0201D7AC(void) {
    if (!(0xC000 & *(u16 *)0x0400000E)) {
        gGameState.unk_828 = (0xC000 | gGameState.unk_828) ^ 0x300;
        if (M2C_FIELD(*(void **)0x03001B40, u8 *, 0x193A) != 0) {
            sub_02026BC8(0x26U);
        }
    }
}

u8 sub_0201D800(u8 arg0) {
    u16 var_r2_11302;
    u8 temp_r2_11275;

    temp_r2_11275 = arg0;
    if (temp_r2_11275 != 0) {
        gGameState.unk_824 |= 0x40;
        gGameState.unk_826 |= 0x40;
        gGameState.unk_828 |= 0x40;
        var_r2_11302 = *(u16 *)0x03003B20 + 0x1111;
        *(u16 *)0x03003B20 = var_r2_11302;
        if ((var_r2_11302 << 0x10) == 0xFFFF0000) {
            *(u8 *)0x03003BAB = 2;
            goto block_3;
        }
        goto block_9;
    }
    if (0x40 & gGameState.unk_824) {
        if (*(void *)0x03003B20 == 0) {
            *(void *)0x03003B20 = 0xFFFFU;
        }
        *(void *)0x03003BAB = temp_r2_11275;
        *(u8 *)0x03003BAC = temp_r2_11275;
        var_r2_11302 = *(void *)0x03003B20 + 0xFFFFEEEF;
        *(void *)0x03003B20 = var_r2_11302;
        if ((var_r2_11302 << 0x10) == 0) {
            gGameState.unk_824 ^= 0x40;
            gGameState.unk_826 ^= 0x40;
            gGameState.unk_828 ^= 0x40;
block_3:
            *(u16 *)0x0400004C = var_r2_11302;
            goto block_10;
        }
block_9:
        *(void *)0x0400004C = var_r2_11302;
        return 0U;
    }
block_10:
    return 1U;
}

u8 sub_0201D904(void) {
    *(s16 *)0x0400004C = 0;
    *(0x0202FD28 + (*(u8 *)0x03003BAC * 4))();
    if (*(u8 *)0x03003BAB != 3) {
        return 0U;
    }
    return 1U;
}

void sub_0201D94C(void) {
    s32 temp_r1_11723;
    s32 temp_r1_11766;
    s32 var_r4_11712;
    s32 var_r4_11778;
    s32 var_r4_11792;
    s32 var_r4_11814;
    u16 *var_r3_11707;
    u16 *var_r5_11706;
    u16 temp_r0_11470;
    u16 temp_r4_11631;
    u32 var_r2_11717;
    u8 temp_r0_11457;
    u8 temp_r0_11698;
    u8 temp_r0_11741;
    u8 temp_r4_11537;
    u8 temp_r4_11576;

    sub_0201D550();
    gGameState.unk_820 = 0x3E41;
    gGameState.unk_81C = 0x1006;
    if (*(u8 *)0x03004224 != 1) {
        temp_r0_11457 = sub_0201D800(0U);
        if (temp_r0_11457 == 0) {
            gGameState.unk_840 = ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8) - 0x80;
            temp_r0_11470 = ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) - 0x50;
            gGameState.unk_842 = temp_r0_11470;
            if (temp_r0_11470 & 0x800) {
                gGameState.unk_842 = (u16) temp_r0_11457;
            }
            if ((u32) gGameState.unk_842 > 0x60U) {
                gGameState.unk_842 = 0x60;
            }
            if (0x800 & gGameState.unk_840) {
                gGameState.unk_840 = (u16) temp_r0_11457;
            }
            if ((u32) gGameState.unk_840 > 0x100U) {
                gGameState.unk_840 = 0x100;
            }
            sub_02026C7C((u8) (*(u8 *)0x03004230 + 1));
            gGameState.unk_844 = gGameState.unk_840;
            gGameState.unk_846 = gGameState.unk_842;
            *(s8 *)0x03003BAE = 1;
            return;
        }
    }
    temp_r4_11537 = gGameState.unk_856;
    if ((temp_r4_11537 == 1) && (*(void *)0x03004224 != 1)) {
        sub_02026C68(0x14U);
        sub_02026BD8();
        *(u16 *)0x03003B20 = 0;
        *(s8 *)0x03003BAD = 0;
        *(void *)0x03003BAE = 0;
        *(u8 *)0x03003BAB = temp_r4_11537;
        *(u8 *)0x03003BAC = temp_r4_11537;
        return;
    }
    temp_r4_11576 = gGameState.unk_84E;
    if ((temp_r4_11576 == 1) && (*(void *)0x03004224 != 1)) {
        sub_02026C68(0x14U);
        sub_02026BD8();
        *(void *)0x03003B20 = 0U;
        *(void *)0x03003BAD = 0;
        *(void *)0x03003BAE = 0;
        *(void *)0x03003BAB = temp_r4_11576;
        *(void *)0x03003BAC = 2U;
        return;
    }
    if ((2 & gGameState.keys_pressed) && (*(void *)0x03004224 != 1)) {
        temp_r4_11631 = 0x40 & gGameState.unk_824;
        if (temp_r4_11631 == 0) {
            sub_02026C68(0x14U);
            sub_02026BD8();
            *(void *)0x03003B20 = temp_r4_11631;
            *(void *)0x03003BAD = 0;
            *(void *)0x03003BAE = 0;
            *(void *)0x03003BAB = 1U;
            *(void *)0x03003BAC = 3U;
            return;
        }
    }
    if ((0xC000 & *(u16 *)0x0400000E) && (0xC000 & gGameState.unk_828)) {
        gGameState.unk_828 = (0xC000 ^ gGameState.unk_828) | 0x300;
        if (M2C_FIELD(*(void **)0x03001B40, u8 *, 0x193A) != 0) {
            sub_02026B48(0x26U);
        }
    }
    temp_r0_11698 = *(u8 *)0x03003BA7 - 1;
    *(u8 *)0x03003BA7 = temp_r0_11698;
    if ((temp_r0_11698 << 0x18) == 0) {
        *(u8 *)0x03003BA7 = 8;
        var_r5_11706 = (u16 *)0x02000000;
        var_r3_11707 = (u16 *)0x02000040;
        var_r4_11712 = 0;
        var_r2_11717 = *(u8 *)0x03003BA8 << 0x14;
        do {
            temp_r1_11723 = (var_r2_11717 >> 0x10) * 2;
            *var_r5_11706 = *(0x0202F3FC + temp_r1_11723);
            *var_r3_11707 = *(0x0202F5FC + temp_r1_11723);
            var_r2_11717 += 0x10000;
            var_r4_11712 += 1;
            var_r5_11706 += 2;
            var_r3_11707 += 2;
        } while (var_r4_11712 <= 0xF);
        temp_r0_11741 = *(void *)0x03003BA8 + 1;
        *(void *)0x03003BA8 = temp_r0_11741;
        if ((u32) temp_r0_11741 > 0xDU) {
            *(void *)0x03003BA8 = 0U;
        }
    }
    CpuSet((void *)0x02000000, (void *)0x05000000, 0x200U);
    gGameState.unk_848 = gGameState.unk_840;
    temp_r1_11766 = M2C_FIELD((void *)0x03003710, s32 *, 0) + 0x40;
    M2C_FIELD((void *)0x03003710, s32 *, 0) = temp_r1_11766;
    gGameState.bg3_vofs = (u16) ((s32) (gGameState.unk_842 + temp_r1_11766) >> 8);
    sub_020267D0();
    sub_02021574();
    var_r4_11778 = 0;
    do {
        if (M2C_FIELD((var_r4_11778 + 0x03003710), u8 *, 0x42C) == 1) {
            sub_02024DD0(var_r4_11778);
        }
        var_r4_11778 += 1;
    } while (var_r4_11778 <= 0x1D);
    var_r4_11792 = 0;
    do {
        if (M2C_FIELD((var_r4_11792 + 0x03003710), u8 *, 0x44D) == 1) {
            sub_0201E538(var_r4_11792);
        }
        var_r4_11792 += 1;
    } while (var_r4_11792 <= 0x1D);
    if (M2C_FIELD((void *)0x03003710, u8 *, 0x419) == 1) {
        sub_020255F0(2);
    }
    var_r4_11814 = 3;
    do {
        if (M2C_FIELD((var_r4_11814 + 0x03003710), u8 *, 0x41A) == 1) {
            sub_020255F0(var_r4_11814);
        }
        var_r4_11814 += 1;
    } while (var_r4_11814 <= 0xB);
    sub_0201E038(1U, 2);
    sub_0201E230(0x54);
}

void sub_0201DCE4(void) {
    sub_0201D800(*(u8 *)0x03003BAB);
    if (*(u8 *)0x03003BAB == 2) {
        sub_0201D7AC();
        sub_020213DC();
        gGameState.unk_857 = 1;
        *(u8 *)0x03003BAB = 3;
    }
}

void sub_0201DD24(void) {
    sub_0201D800(*(u8 *)0x03003BAB);
    if (*(u8 *)0x03003BAB == 2) {
        sub_0201D7AC();
        sub_020213DC();
        gGameState.unk_84F = 1;
        *(u8 *)0x03003BAB = 3;
    }
}

void sub_0201DD64(void) {
    sub_0201D800(*(u8 *)0x03003BAB);
    if (*(u8 *)0x03003BAB == 2) {
        sub_0201D7AC();
        sub_020213DC();
        *(u8 *)0x03003BAB = 3;
    }
}

void sub_0201DD94(void) {
    s32 sp0;
    s32 sp4;
    s32 temp_r0_12027;
    s32 temp_r0_12114;
    s32 temp_r2_12102;
    s32 temp_r3_12104;
    s32 var_r4_12083;
    s32 var_r6_11991;
    s32 var_r6_12013;
    s32 var_r6_12174;
    s32 var_r8_12020;
    s32 var_sl_12008;
    u16 temp_r1_12058;
    void *temp_r5_12029;
    void *var_r6_11978;

    gGameState.unk_860 = 0;
    if (*(u8 *)0x03003B29 == 1) {
        sub_020256D0(2);
    }
    if ((*(u8 *)0x03004227 == 0x14) && (*(u8 *)0x03004224 == 2)) {
        sub_02023B58();
    }
    var_r6_11978 = NULL;
    do {
        if (*(0x03003B27 + (s32) var_r6_11978) == 1) {
            sub_02026830();
        }
        var_r6_11978 += 1;
    } while ((s32) var_r6_11978 <= 1);
    var_r6_11991 = 3;
    do {
        if (M2C_FIELD((var_r6_11991 + 0x03003710), u8 *, 0x41A) == 1) {
            sub_020256D0(var_r6_11991);
        }
        var_r6_11991 += 1;
    } while (var_r6_11991 <= 0xB);
    sub_0201E27C(0x54);
    var_sl_12008 = 0;
    sp0 = 0;
    sp4 = 0;
    var_r6_12013 = 0x1E;
loop_14:
    var_r8_12020 = var_r6_12013 - 1;
    if (M2C_FIELD((var_r6_12013 + 0x03003710), u8 *, 0x44D) != 1) {

    } else {
        temp_r0_12027 = var_r6_12013 * 0x30;
        temp_r5_12029 = temp_r0_12027 + 0x03003C00;
        if ((var_sl_12008 == 0) && ((u32) M2C_FIELD((void *)0x03003BB0, u8 *, 0x10) > (u32) M2C_FIELD(temp_r5_12029, u16 *, 0xE))) {
            sub_0201E178(0, 0U);
            var_sl_12008 = 1;
        }
        if ((sp0 == 0) && ((u32) M2C_FIELD((void *)0x03003BC4, u8 *, 0x10) > (u32) M2C_FIELD(temp_r5_12029, u16 *, 0xE))) {
            sub_0201E178(1, 2U);
            sp0 = 1;
        }
        temp_r1_12058 = M2C_FIELD(temp_r5_12029, u16 *, 0x1C);
        var_r8_12020 = var_r6_12013 - 1;
        if (temp_r1_12058 != 0) {
            if (temp_r1_12058 != 0xFFFF) {
                sub_02024DF8(temp_r1_12058 - 1);
            } else {
                var_r4_12083 = 0;
                do {
                    if (M2C_FIELD((var_r4_12083 + 0x03003710), u8 *, 0x42C) == 1) {
                        sub_02024DF8(var_r4_12083);
                    }
                    var_r4_12083 += 1;
                } while (var_r4_12083 <= 2);
            }
        }
        temp_r2_12102 = *(0x03003C00 + temp_r0_12027) - ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8);
        M2C_FIELD((void *)0x03003710, s32 *, 8) = temp_r2_12102;
        temp_r3_12104 = M2C_FIELD((void *)0x030041A0, s32 *, 4);
        M2C_FIELD((void *)0x03003710, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r5_12029, s32 *, 4) - (temp_r3_12104 >> 8));
        if (temp_r2_12102 < 0) {
            M2C_FIELD((void *)0x03003710, s32 *, 8) = (s32) (0 - temp_r2_12102);
        }
        temp_r0_12114 = M2C_FIELD((void *)0x03003710, s32 *, 0xC);
        if (temp_r0_12114 < 0) {
            M2C_FIELD((void *)0x03003710, s32 *, 0xC) = (s32) (0 - temp_r0_12114);
        }
        if (((s32) M2C_FIELD((void *)0x03003710, s32 *, 8) <= 0x10) && ((s32) M2C_FIELD((void *)0x03003710, s32 *, 0xC) <= 0x10) && ((s32) (0xF0 & M2C_FIELD(temp_r5_12029, u16 *, 0xE)) < (s32) (((s32) (temp_r3_12104 + 0xD00) >> 8) & 0xF0)) && (sp4 == 0)) {
            sub_02023B58();
            sp4 = 1;
        }
        sub_0201EF44(var_r6_12013);
    }
    var_r6_12013 = var_r8_12020;
    if (var_r6_12013 >= 0) {
        goto loop_14;
    }
    if (var_sl_12008 == 0) {
        sub_0201E178(0, 0U);
    }
    if (sp0 == 0) {
        sub_0201E178(1, 2U);
    }
    if (sp4 == 0) {
        sub_02023B58();
    }
    sub_0201E178(1, 1U);
    var_r6_12174 = 0;
    do {
        if (M2C_FIELD((var_r6_12174 + 0x03003710), u8 *, 0x41A) == 1) {
            sub_02025618(var_r6_12174);
        }
        var_r6_12174 += 1;
    } while (var_r6_12174 <= 0xB);
}

void sub_0201DF9C(s32 arg0, s32 arg1, s8 arg2, u8 arg3) {
    s32 temp_r0_12259;
    s32 temp_r1_12253;
    s32 temp_r2_12209;
    s32 var_r0_12239;
    void *temp_r2_12211;

    temp_r2_12209 = arg0 * 0x14;
    temp_r2_12211 = temp_r2_12209 + 0x03003BB0;
    if ((arg1 << 0x18) == 0) {
        M2C_FIELD(temp_r2_12211, s32 *, 4) = (s32) ((0xFFF0 & arg2) + 0x10);
        *(0x03003BB0 + temp_r2_12209) = (s32) (((0xF & arg2) * 0x10) + 0x10);
    } else {
        M2C_FIELD(temp_r2_12211, s32 *, 4) = (s32) ((0xFFF0 & arg2) + 8);
        if (arg3 == 0) {
            var_r0_12239 = ((0xF & arg2) * 0x10) + 8;
        } else {
            var_r0_12239 = ((0xF & arg2) * 0x10) + 0x108;
        }
        *(0x03003BB0 + temp_r2_12209) = var_r0_12239;
        temp_r1_12253 = *(0x03003BB0 + temp_r2_12209) << 8;
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = temp_r1_12253;
        temp_r0_12259 = (M2C_FIELD(temp_r2_12211, s32 *, 4) << 8) + 0x100;
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = temp_r0_12259;
        M2C_FIELD((void *)0x030041A0, s32 *, 8) = temp_r1_12253;
        M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = temp_r0_12259;
        M2C_FIELD(temp_r2_12211, s32 *, 8) = (s32) (*(0x03003BB0 + temp_r2_12209) - 8);
        M2C_FIELD(temp_r2_12211, s32 *, 0xC) = (s32) (M2C_FIELD(temp_r2_12211, s32 *, 4) - 4);
    }
    M2C_FIELD(temp_r2_12211, s8 *, 0x10) = arg2;
    M2C_FIELD(temp_r2_12211, s8 *, 0x11) = 1;
}

void sub_0201E030(void) {

}

void sub_0201E034(void) {

}

void sub_0201E038(u8 arg1) {
    if (arg1 == 2) {
        *(0x0202FD38 + (M2C_FIELD((void *)0x03003BC4, u8 *, 0x11) * 4))();
    }
}

void sub_0201E060(void *arg0, s32 arg1, u8 arg2) {
    s32 temp_r0_12318;
    u8 temp_r0_12364;
    u8 temp_r2_12355;
    u8 temp_r4_12347;
    void *temp_r0_12320;
    void *temp_r6_12329;

    temp_r0_12318 = arg1 * 0x14;
    temp_r0_12320 = temp_r0_12318 + 0x03003BB0;
    temp_r6_12329 = (gGameState.unk_860 * 8) + gUnk3002410;
    if ((arg2 != 5) || (M2C_FIELD(temp_r0_12320, u8 *, 0x11) == 1)) {
        temp_r4_12347 = (0x3F & M2C_FIELD(temp_r6_12329, u8 *, 1)) | ((((u32) M2C_FIELD(arg0, u32 *, 0) >> 0xE) & 3) << 6);
        M2C_FIELD(temp_r6_12329, u8 *, 1) = temp_r4_12347;
        temp_r2_12355 = (0x3F & M2C_FIELD(temp_r6_12329, u8 *, 3)) | (((u32) M2C_FIELD(arg0, u32 *, 0) >> 0x1E) << 6);
        M2C_FIELD(temp_r6_12329, u8 *, 3) = temp_r2_12355;
        temp_r0_12364 = (-0x11 & temp_r2_12355) | ((M2C_FIELD(arg0, u8 *, 0xF) & 1) * 0x10);
        M2C_FIELD(temp_r6_12329, u8 *, 3) = temp_r0_12364;
        M2C_FIELD(temp_r6_12329, u8 *, 3) = (u8) ((temp_r0_12364 & ~0x20) | ((M2C_FIELD(arg0, u8 *, 0x10) & 1) << 5));
        M2C_FIELD(temp_r6_12329, u8 *, 5) = (u8) ((((0xF & M2C_FIELD(temp_r6_12329, u8 *, 5)) | (M2C_FIELD(arg0, u8 *, 0xE) * 0x10)) & ~0xC) | 4);
        M2C_FIELD(temp_r6_12329, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r6_12329, u16 *, 2)) | ((M2C_FIELD(arg0, s32 *, 8) + (*(0x03003BB0 + temp_r0_12318) - gGameState.unk_844)) & 0x1FF));
        M2C_FIELD(temp_r6_12329, s8 *, 0) = (s8) (M2C_FIELD(arg0, s32 *, 4) + (M2C_FIELD(temp_r0_12320, s32 *, 4) - M2C_FIELD(&gGameState, u8 *, 0x846)));
        M2C_FIELD(temp_r6_12329, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r6_12329, u16 *, 4)) | (0x3FF & M2C_FIELD(arg0, u16 *, 0xC)));
        M2C_FIELD(temp_r6_12329, u8 *, 1) = (u8) (temp_r4_12347 | 0x10);
    }
    gGameState.unk_860 += 1;
}

void sub_0201E178(s32 arg0, u8 arg1) {
    s32 var_r0_12453;
    s32 var_r4_12478;
    s32 var_r5_12483;
    s32 var_r6_12454;
    u8 temp_r1_12451;

    temp_r1_12451 = arg1;
    var_r0_12453 = 0;
    var_r6_12454 = 0;
    switch (temp_r1_12451) {                        /* irregular */
    case 0:
        var_r0_12453 = 0;
        var_r6_12454 = 3;
        break;
    case 2:
        var_r0_12453 = 3;
        var_r6_12454 = 5;
        break;
    case 1:
        var_r0_12453 = 5;
        var_r6_12454 = 6;
        break;
    }
    var_r4_12478 = var_r0_12453;
    if (var_r4_12478 < var_r6_12454) {
        var_r5_12483 = var_r4_12478 * 0x14;
        do {
            sub_0201E060(var_r5_12483 + 0x0202FD40, arg0, (u8) var_r4_12478);
            var_r5_12483 += 0x14;
            var_r4_12478 += 1;
        } while (var_r4_12478 < var_r6_12454);
    }
}

void sub_0201E1E0(s32 arg0, s32 arg1, u8 arg2) {
    s32 temp_r1_12511;
    void *temp_r3_12513;

    temp_r1_12511 = arg0 * 0xC;
    temp_r3_12513 = temp_r1_12511 + 0x03003BF0;
    *(0x03003BF0 + temp_r1_12511) = 0;
    if ((arg2 << 0x18) != 0) {
        *(0x03003BF0 + temp_r1_12511) = 0x100;
    }
    *(0x03003BF0 + temp_r1_12511) = (s32) (*(0x03003BF0 + temp_r1_12511) | (((0xF & arg1) * 0x10) + 0xC));
    M2C_FIELD(temp_r3_12513, s32 *, 4) = (s32) ((0xF0 & arg1) + 8);
    M2C_FIELD(temp_r3_12513, s8 *, 8) = 0;
    M2C_FIELD(temp_r3_12513, s8 *, 9) = 0;
    M2C_FIELD(temp_r3_12513, s8 *, 8) = (s8) M2C_FIELD(*(void **)0x0202FEB0, u16 *, 4);
}

void sub_0201E230(s32 arg0) {
    u8 temp_r0_12555;
    u8 temp_r2_12558;
    void *temp_r1_12553;

    temp_r1_12553 = (arg0 * 0xC) + 0x03003BF0;
    temp_r0_12555 = M2C_FIELD(temp_r1_12553, u8 *, 8) - 1;
    M2C_FIELD(temp_r1_12553, u8 *, 8) = temp_r0_12555;
    temp_r2_12558 = temp_r0_12555;
    if (temp_r2_12558 == 0) {
        M2C_FIELD(temp_r1_12553, u8 *, 9) = (u8) (M2C_FIELD(temp_r1_12553, u8 *, 9) + 1);
        if (M2C_FIELD(*(0x0202FEB0 + (M2C_FIELD(temp_r1_12553, u8 *, 9) * 4)), u8 *, 6) == 0xFF) {
            M2C_FIELD(temp_r1_12553, u8 *, 9) = temp_r2_12558;
        }
        M2C_FIELD(temp_r1_12553, u8 *, 8) = (u8) M2C_FIELD(*(0x0202FEB0 + (M2C_FIELD(temp_r1_12553, u8 *, 9) * 4)), u16 *, 4);
    }
}

void sub_0201E27C(s32 arg0, M2C_UNK arg3) {
    s32 temp_r1_12596;
    u8 temp_r0_12722;
    u8 temp_r1_12653;
    u8 temp_r1_12680;
    u8 temp_r2_12644;
    u8 temp_r2_12671;
    u8 temp_r4_12660;
    void *temp_r3_12628;
    void *temp_r6_12598;
    void *var_r5_12604;

    temp_r1_12596 = arg0 * 0xC;
    temp_r6_12598 = temp_r1_12596 + 0x03003BF0;
    var_r5_12604 = **(0x0202FEB0 + (M2C_FIELD(temp_r6_12598, u8 *, 9) * 4));
    if (M2C_FIELD(var_r5_12604, u16 *, 6) == 0xFFFF) {
        return;
    }
    do {
        temp_r3_12628 = (gGameState.unk_860 * 8) + gUnk3002410;
        M2C_FIELD(temp_r3_12628, s8 *, 0) = (s8) ((M2C_FIELD(var_r5_12604, u8 *, 0) + M2C_FIELD(temp_r6_12598, s32 *, 4)) - M2C_FIELD(&gGameState, u8 *, 0x846));
        temp_r2_12644 = (-0xD & M2C_FIELD(temp_r3_12628, u8 *, 1)) | (0xC & M2C_FIELD(var_r5_12604, u8 *, 1));
        M2C_FIELD(temp_r3_12628, u8 *, 1) = temp_r2_12644;
        temp_r1_12653 = (-0x21 & temp_r2_12644) | ((((u32) (M2C_FIELD(var_r5_12604, u8 *, 1) << 0x1A) >> 0x1F) & 1) << 5);
        M2C_FIELD(temp_r3_12628, u8 *, 1) = temp_r1_12653;
        temp_r4_12660 = (0x3F & temp_r1_12653) | (((u8) M2C_FIELD(var_r5_12604, u8 *, 1) >> 6) << 6);
        M2C_FIELD(temp_r3_12628, u8 *, 1) = temp_r4_12660;
        temp_r2_12671 = (-0x11 & M2C_FIELD(temp_r3_12628, u8 *, 3)) | ((((u32) (M2C_FIELD(var_r5_12604, u8 *, 3) << 0x1B) >> 0x1F) & 1) * 0x10);
        M2C_FIELD(temp_r3_12628, u8 *, 3) = temp_r2_12671;
        temp_r1_12680 = (-0x21 & temp_r2_12671) | ((((u32) (M2C_FIELD(var_r5_12604, u8 *, 3) << 0x1A) >> 0x1F) & 1) << 5);
        M2C_FIELD(temp_r3_12628, u8 *, 3) = temp_r1_12680;
        M2C_FIELD(temp_r3_12628, u8 *, 3) = (u8) ((temp_r1_12680 & 0x3F) | (((u8) M2C_FIELD(var_r5_12604, u8 *, 3) >> 6) << 6));
        M2C_FIELD(temp_r3_12628, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r3_12628, u16 *, 2)) | (((((u32) (M2C_FIELD(var_r5_12604, u16 *, 2) << 0x17) >> 0x17) + *(0x03003BF0 + temp_r1_12596)) - gGameState.unk_844) & 0x1FF));
        M2C_FIELD(temp_r3_12628, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r3_12628, u16 *, 4)) | ((u32) (M2C_FIELD(var_r5_12604, u16 *, 4) << 0x16) >> 0x16));
        M2C_FIELD(temp_r3_12628, u8 *, 1) = (u8) (temp_r4_12660 | 0x10);
        temp_r0_12722 = (-0xD & M2C_FIELD(temp_r3_12628, u8 *, 5)) | 4;
        M2C_FIELD(temp_r3_12628, u8 *, 5) = temp_r0_12722;
        M2C_FIELD(temp_r3_12628, u8 *, 5) = (u8) ((temp_r0_12722 & 0xF) | (((u8) M2C_FIELD(var_r5_12604, u8 *, 5) >> 4) * 0x10));
        gGameState.unk_860 += 1;
        var_r5_12604 += 8;
    } while (M2C_FIELD(var_r5_12604, u16 *, 6) != 0xFFFF);
}

void sub_0201E3DC(s32 arg0, u8 arg1) {
    u16 var_r4_12770;
    void *temp_r0_12773;
    void *temp_r5_12768;

    temp_r5_12768 = (arg0 * 0x30) + 0x03003C00;
    var_r4_12770 = 3;
loop_1:
    temp_r0_12773 = var_r4_12770 + 0x03003710;
    if (M2C_FIELD(temp_r0_12773, u8 *, 0x42F) == 0) {
        M2C_FIELD(temp_r0_12773, u8 *, 0x42F) = 1U;
        sub_02024B08(arg0, var_r4_12770, arg1, M2C_FIELD(temp_r5_12768, u8 *, 0x24));
        M2C_FIELD(temp_r5_12768, s16 *, 0x1C) = (s16) (var_r4_12770 + 1);
        return;
    }
    var_r4_12770 += 1;
    if ((s32) var_r4_12770 > 0x1D) {
        return;
    }
    goto loop_1;
}

void sub_0201E430(s32 arg0, u16 arg1, u8 arg2, u8 arg3) {
    s32 temp_r0_12816;
    s32 temp_r1_12860;
    s8 *temp_r0_12829;
    s8 *temp_r0_12831;
    u8 temp_r3_12812;
    void *temp_r0_12833;
    void *temp_r5_12818;

    temp_r3_12812 = arg3;
    temp_r0_12816 = arg0 * 0x30;
    temp_r5_12818 = temp_r0_12816 + 0x03003C00;
    M2C_FIELD(temp_r5_12818, u16 *, 0xC) = arg1;
    M2C_FIELD(temp_r5_12818, s8 *, 0x29) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x16) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x18) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x1A) = 0;
    temp_r0_12829 = (temp_r5_12818 + 0x29) - 1;
    *temp_r0_12829 = 0;
    temp_r0_12831 = temp_r0_12829 - 2;
    *temp_r0_12831 = 0;
    temp_r0_12833 = temp_r0_12831 - 1;
    M2C_FIELD(temp_r0_12833, s8 *, 0) = 0;
    M2C_FIELD(temp_r0_12833, s8 *, 2) = 0;
    M2C_FIELD(temp_r5_12818, u8 *, 0x2A) = 0U;
    M2C_FIELD(temp_r5_12818, s16 *, 0x1C) = 0;
    M2C_FIELD(temp_r5_12818, s8 *, 0x2B) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x1E) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x20) = 0;
    M2C_FIELD(temp_r5_12818, s16 *, 0x22) = 0;
    M2C_FIELD((temp_r5_12818 + 0x2B), s8 *, 1) = 0;
    M2C_FIELD(temp_r5_12818, s8 *, 0x2D) = 0;
    M2C_FIELD(temp_r5_12818, s32 *, 4) = (s32) ((0xF0 & arg2) + 8);
    temp_r1_12860 = (0xF & arg2) * 0x10;
    *(0x03003C00 + temp_r0_12816) = (s32) (temp_r1_12860 + 8);
    M2C_FIELD(temp_r5_12818, s16 *, 0xE) = (s16) arg2;
    if (temp_r3_12812 != 0) {
        *(0x03003C00 + temp_r0_12816) = (s32) (temp_r1_12860 + 0x108);
    }
    M2C_FIELD(temp_r5_12818, u8 *, 0x2A) = (u8) *(0x02030110 + M2C_FIELD(temp_r5_12818, u16 *, 0xC));
    M2C_FIELD(temp_r5_12818, u8 *, 0x24) = temp_r3_12812;
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 0x12) {
        sub_0201E3DC(arg0, 0U);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 7) {
        sub_0201E3DC(arg0, 3U);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 8) {
        sub_0201E3DC(arg0, 7U);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 9) {
        sub_0201E3DC(arg0, 0xBU);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 0xA) {
        sub_0201E3DC(arg0, 0xFU);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 0xB) {
        sub_0201E3DC(arg0, 0x13U);
    }
    if (M2C_FIELD(temp_r5_12818, u16 *, 0xC) == 6) {
        M2C_FIELD(temp_r5_12818, s8 *, 0x2D) = 1;
    }
}

void sub_0201E538(s32 arg0) {
    *(0x0202FECC + (M2C_FIELD(((arg0 * 0x30) + 0x03003C00), u8 *, 0x28) * 4))();
}

void sub_0201E560(void) {

}

void sub_0201E564(s32 arg0) {
    s32 temp_r1_12974;
    s32 temp_r1_12995;
    s32 temp_r5_13007;
    s32 var_r1_13013;
    s32 var_r3_12983;
    u16 temp_r0_12978;
    void *temp_r0_12987;
    void *temp_r4_12997;
    void *temp_r6_12976;

    temp_r1_12974 = arg0 * 0x30;
    temp_r6_12976 = temp_r1_12974 + 0x03003C00;
    temp_r0_12978 = M2C_FIELD(temp_r6_12976, u16 *, 0xC);
    if ((temp_r0_12978 != 3) && (temp_r0_12978 != 0xE)) {
        var_r3_12983 = 3;
loop_3:
        temp_r0_12987 = var_r3_12983 + 0x03003710;
        if (M2C_FIELD(temp_r0_12987, u8 *, 0x41A) == 0) {
            temp_r1_12995 = 0x54 * var_r3_12983;
            temp_r4_12997 = temp_r1_12995 + 0x03004790;
            M2C_FIELD(temp_r0_12987, u8 *, 0x41A) = 1U;
            sub_02024F08(var_r3_12983);
            temp_r5_13007 = 0x10 - ((s32) sub_02019AF0(&gGameState) % 33);
            var_r1_13013 = ((s32) sub_02019AF0(&gGameState) % 17) + 0x10;
            if (M2C_FIELD(temp_r6_12976, u16 *, 0xC) == 4) {
                var_r1_13013 = 0x10;
            }
            *(0x03004790 + temp_r1_12995) = (s32) (*(0x03003C00 + temp_r1_12974) + temp_r5_13007);
            M2C_FIELD(temp_r4_12997, s32 *, 4) = (s32) (M2C_FIELD(temp_r6_12976, s32 *, 4) - var_r1_13013);
            M2C_FIELD(temp_r4_12997, s8 *, 0x4E) = 1;
            return;
        }
        var_r3_12983 += 1;
        if (var_r3_12983 > 9) {

        } else {
            goto loop_3;
        }
    }
}

void sub_0201E608(s32 arg0) {
    s16 var_r4_13054;
    s32 temp_r1_13051;
    s32 var_r1_13154;
    s32 var_r2_13155;
    u16 temp_r0_13060;
    u16 temp_r0_13146;
    u16 temp_r0_13168;
    void *temp_r3_13053;

    temp_r1_13051 = arg0 * 0x30;
    temp_r3_13053 = temp_r1_13051 + 0x03003C00;
    var_r4_13054 = 0;
    if (M2C_FIELD(temp_r3_13053, u8 *, 0x28) == 3) {
        temp_r0_13060 = M2C_FIELD(temp_r3_13053, u16 *, 0xC);
        if (temp_r0_13060 == 3) {
            var_r4_13054 = 1;
        }
        if (temp_r0_13060 == 4) {
            var_r4_13054 = 2;
        }
        if (temp_r0_13060 == 5) {
            var_r4_13054 = 3;
        }
        if (temp_r0_13060 == 6) {
            var_r4_13054 = 4;
        }
        if (temp_r0_13060 == 0xE) {
            var_r4_13054 = 0x70;
        }
        if (temp_r0_13060 == 0xF) {
            var_r4_13054 = 0x71;
        }
        if (temp_r0_13060 == 0x10) {
            var_r4_13054 = 0x72;
        }
        if (temp_r0_13060 == 0x11) {
            var_r4_13054 = 0x73;
        }
    } else {
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 0x12) {
            var_r4_13054 = 0x858;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 0x11U;
        }
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 7) {
            var_r4_13054 = 0x809;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 6U;
        }
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 8) {
            var_r4_13054 = 0x811;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 6U;
        }
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 9) {
            var_r4_13054 = 0x819;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 6U;
        }
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 0xA) {
            var_r4_13054 = 0x821;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 6U;
        }
        if (M2C_FIELD(temp_r3_13053, u16 *, 0xC) == 0xB) {
            var_r4_13054 = 0x829;
            M2C_FIELD(temp_r3_13053, u16 *, 0xC) = 6U;
        }
    }
    if (!(*(0x03003C00 + temp_r1_13051) & 0x100)) {
        temp_r0_13146 = M2C_FIELD(temp_r3_13053, u16 *, 0xE);
        var_r1_13154 = ((0xF & temp_r0_13146) * 2) + (((temp_r0_13146 >> 4) & 0xF) << 5);
        var_r2_13155 = *(s32 *)0x03001B40 + 0x24;
    } else {
        temp_r0_13168 = M2C_FIELD(temp_r3_13053, u16 *, 0xE);
        var_r1_13154 = ((0xF & temp_r0_13168) * 2) + (((temp_r0_13168 >> 4) & 0xF) << 5);
        var_r2_13155 = *(void *)0x03001B40 + 0x224;
    }
    *(var_r2_13155 + var_r1_13154) = var_r4_13054;
}

void sub_0201E710(s32 arg0) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    u8 *sp10;
    s32 sp14;
    u8 *sp18;
    u8 *sp1C;
    s8 *sp20;
    u32 sp24;
    u8 *sp28;
    s16 *var_r1_13667;
    s16 *var_r1_13693;
    s16 var_r0_13668;
    s16 var_r0_13694;
    s32 temp_r1_13441;
    s32 temp_r2_13590;
    s32 temp_r3_13349;
    s32 temp_r3_13622;
    s32 temp_r4_13336;
    s32 temp_r4_13340;
    s32 temp_r4_13384;
    s32 temp_r4_13393;
    s32 var_r1_13564;
    s32 var_sl_13270;
    s8 *temp_r0_13248;
    u16 *temp_r1_13451;
    u16 *var_r0_13428;
    u16 temp_r2_13326;
    u16 temp_r2_13386;
    u16 temp_r3_13314;
    u16 temp_r3_13390;
    u16 var_r7_13353;
    u32 temp_r1_13402;
    u32 var_r0_13562;
    u8 *temp_r2_13296;
    u8 temp_r1_13208;
    u8 var_r8_13330;
    void *temp_r0_13250;
    void *temp_r1_13588;
    void *temp_r2_13305;
    void *temp_r5_13202;

    temp_r5_13202 = (arg0 * 0x30) + 0x03003C00;
    sp0 = 0x03003710;
    temp_r1_13208 = M2C_FIELD(temp_r5_13202, u8 *, 0x2A);
    if ((temp_r1_13208 == 0) || (0x80 & temp_r1_13208)) {
        sub_0201E564(arg0);
        M2C_FIELD(temp_r5_13202, s8 *, 0x27) = 8;
        M2C_FIELD(temp_r5_13202, s8 *, 0x26) = 0;
        M2C_FIELD(temp_r5_13202, s16 *, 0x14) = 0xFFFF;
        M2C_FIELD(temp_r5_13202, s8 *, 0x28) = 3;
        sub_0201E608(arg0);
        sub_02026A38(0x13U);
        sp1C = temp_r5_13202 + 0x28;
    } else {
        sub_02026A38(0x18U);
        M2C_FIELD(temp_r5_13202, s8 *, 0x27) = 2;
        temp_r0_13248 = (temp_r5_13202 + 0x27) - 1;
        *temp_r0_13248 = 0;
        temp_r0_13250 = temp_r0_13248 - 1;
        M2C_FIELD(temp_r0_13250, s8 *, 0) = 0;
        M2C_FIELD(temp_r0_13250, s8 *, 3) = 2;
        sp1C = temp_r0_13250 + 3;
    }
    if (M2C_FIELD(temp_r5_13202, u16 *, 0x1C) == 0) {
        return;
    }
    sp20 = temp_r5_13202 + 0x2B;
    if (M2C_FIELD(temp_r5_13202, u8 *, 0x2B) != 0) {
        return;
    }
    var_sl_13270 = 0;
    sp8 = sp0 + 0x417;
    sp24 = 0;
    sp28 = sp0 + 0x42C;
loop_9:
    if ((*sp28 == 1) && (M2C_FIELD(temp_r5_13202, u16 *, 0x1C) != 0)) {
        *(sp8 + (M2C_FIELD(temp_r5_13202, u16 *, 0x1C) + 0x17)) = 0;
        M2C_FIELD(temp_r5_13202, u16 *, 0x1C) = 0U;
        return;
    }
    sp4 = 0;
    sp14 = var_sl_13270 * 4;
    temp_r2_13296 = temp_r5_13202 + 0x24;
    sp18 = temp_r2_13296;
    M2C_FIELD(&sp0, u16 *, 0xC) = (u16) M2C_FIELD(temp_r5_13202, u16 *, 0xE);
    sp10 = temp_r2_13296;
loop_13:
    temp_r2_13305 = sp14 + sp4;
    temp_r3_13314 = (M2C_FIELD(&sp0, u16 *, 0xC) + (*(0x02030104 + (s32) temp_r2_13305) * 0x10)) & 0xF0;
    M2C_FIELD(temp_r5_13202, u16 *, 0x20) = temp_r3_13314;
    temp_r2_13326 = ((0xF & M2C_FIELD(&sp0, u16 *, 0xC)) + *(0x020300F8 + (s32) temp_r2_13305)) & 0xF;
    M2C_FIELD(temp_r5_13202, u16 *, 0x1E) = temp_r2_13326;
    var_r8_13330 = 0;
    if (*sp10 == 0) {
        temp_r4_13336 = *(s32 *)0x03001B40;
        temp_r4_13340 = temp_r3_13314 * 2;
        M2C_FIELD(temp_r5_13202, u16 *, 0x22) = (u16) *(temp_r4_13336 + 0x24 + ((M2C_FIELD(temp_r5_13202, u16 *, 0x1E) * 2) + temp_r4_13340));
        temp_r3_13349 = (temp_r2_13326 | temp_r3_13314) * 2;
        var_r7_13353 = *(sp0 + 0x10 + temp_r3_13349);
        if ((u32) temp_r2_13326 <= 1U) {
            var_r8_13330 = 1;
            M2C_FIELD(temp_r5_13202, u16 *, 0x22) = (u16) *(temp_r4_13336 + 0x224 + ((M2C_FIELD(temp_r5_13202, u16 *, 0x1E) * 2) + temp_r4_13340));
            var_r7_13353 = *(sp0 + 0x210 + temp_r3_13349);
        }
        if (*sp10 != 0) {
            goto block_17;
        }
    } else {
block_17:
        var_r8_13330 = 1;
        temp_r4_13384 = *(void *)0x03001B40;
        temp_r2_13386 = M2C_FIELD(temp_r5_13202, u16 *, 0x1E);
        temp_r3_13390 = M2C_FIELD(temp_r5_13202, u16 *, 0x20);
        temp_r4_13393 = ((0xF & temp_r2_13386) * 2) + ((temp_r3_13390 >> 4) << 5);
        M2C_FIELD(temp_r5_13202, u16 *, 0x22) = (u16) *(temp_r4_13384 + 0x224 + temp_r4_13393);
        temp_r1_13402 = (u32) ((temp_r3_13390 + temp_r2_13386) << 0x18) >> 0x17;
        var_r7_13353 = *(sp0 + 0x210 + temp_r1_13402);
        if ((u32) temp_r2_13386 > 0xDU) {
            var_r8_13330 = 0;
            M2C_FIELD(temp_r5_13202, u16 *, 0x22) = (u16) *(temp_r4_13384 + 0x24 + temp_r4_13393);
            var_r7_13353 = *(sp0 + 0x10 + temp_r1_13402);
        }
    }
    if (var_r8_13330 == 0) {
        var_r0_13428 = (u16 *)0x0600A000;
    } else {
        var_r0_13428 = (u16 *)0x0600A800;
    }
    M2C_FIELD(temp_r5_13202, u16 **, 8) = var_r0_13428;
    temp_r1_13441 = M2C_FIELD(temp_r5_13202, u16 *, 0x20) + M2C_FIELD(temp_r5_13202, u16 *, 0x1E);
    temp_r1_13451 = M2C_FIELD(temp_r5_13202, u16 **, 8) + ((temp_r1_13441 & 0xF0) * 8) + ((temp_r1_13441 & 0xF) * 4);
    M2C_FIELD(temp_r5_13202, u16 **, 8) = temp_r1_13451;
    if (((M2C_FIELD(temp_r5_13202, u16 *, 0x22) != 0) || (var_r7_13353 != 0xFFF) || ((u32) (u16) ((*temp_r1_13451 & 0x3FF) - 0x20) > 0x5EU)) && (sp4 != 3)) {
        temp_r3_13622 = sp4 + 1;
        sp4 = temp_r3_13622;
        if (temp_r3_13622 <= 3) {
            goto loop_13;
        }
    } else {
        *sp28 = 1;
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 0x12) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 1), var_r8_13330);
        }
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 7) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 4), var_r8_13330);
        }
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 8) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 8), var_r8_13330);
        }
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 9) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0xC), var_r8_13330);
        }
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 0xA) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0x10), var_r8_13330);
        }
        if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 0xB) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0x14), var_r8_13330);
        }
        if (var_r8_13330 == 0) {
            var_r0_13562 = (u32) ((M2C_FIELD(temp_r5_13202, u16 *, 0x20) + (u8) M2C_FIELD(temp_r5_13202, u16 *, 0x1E)) << 0x18) >> 0x17;
            var_r1_13564 = sp0 + 0x10;
        } else {
            var_r0_13562 = (u32) ((M2C_FIELD(temp_r5_13202, u16 *, 0x20) + (u8) M2C_FIELD(temp_r5_13202, u16 *, 0x1E)) << 0x18) >> 0x17;
            var_r1_13564 = sp0 + 0x210;
        }
        *(var_r1_13564 + var_r0_13562) = 0x7777;
        temp_r1_13588 = (0x2C * var_sl_13270) + 0x03004260;
        temp_r2_13590 = M2C_FIELD(temp_r5_13202, u16 *, 0x1E) * 0x10;
        M2C_FIELD(temp_r1_13588, s32 *, 0x10) = temp_r2_13590;
        if (var_r8_13330 != 0) {
            M2C_FIELD(temp_r1_13588, s32 *, 0x10) = (s32) (temp_r2_13590 | 0x100);
        }
        M2C_FIELD(temp_r1_13588, s32 *, 0xC) = (s32) M2C_FIELD(temp_r5_13202, u16 *, 0x20);
        M2C_FIELD(temp_r1_13588, s16 *, 0x20) = (s16) (M2C_FIELD(temp_r5_13202, u16 *, 0x1E) + M2C_FIELD(temp_r5_13202, u16 *, 0x20));
        if ((M2C_FIELD(temp_r5_13202, u16 *, 0x22) == 0) && (var_r7_13353 == 0xFFF)) {
            M2C_FIELD(temp_r1_13588, s8 *, 0x28) = 1;
        }
    }
    if ((M2C_FIELD(temp_r5_13202, u16 *, 0xC) != 0x12) || (var_sl_13270 != 1)) {
        sp24 += 0x10000;
        sp28 += 1;
        var_sl_13270 += 1;
        if (var_sl_13270 <= 2) {
            goto loop_9;
        }
    }
    sub_0201E608(arg0);
    if (*sp1C == 3) {
        if (*sp18 == 0) {
            if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 0x12) {
                var_r1_13667 = sp0 + 0x10 + (M2C_FIELD(temp_r5_13202, u16 *, 0xE) * 2);
                var_r0_13668 = 0x25;
            } else {
                var_r1_13667 = sp0 + 0x10 + (M2C_FIELD(temp_r5_13202, u16 *, 0xE) * 2);
                var_r0_13668 = 0x34;
            }
            *var_r1_13667 = var_r0_13668;
            if (*sp18 != 0) {
                goto block_59;
            }
        } else {
block_59:
            if (M2C_FIELD(temp_r5_13202, u16 *, 0xC) == 0x12) {
                var_r1_13693 = sp0 + 0x210 + (M2C_FIELD(temp_r5_13202, u16 *, 0xE) * 2);
                var_r0_13694 = 0x25;
            } else {
                var_r1_13693 = sp0 + 0x210 + (M2C_FIELD(temp_r5_13202, u16 *, 0xE) * 2);
                var_r0_13694 = 0x34;
            }
            *var_r1_13693 = var_r0_13694;
        }
    }
    *sp20 = 1;
    M2C_FIELD((sp0 + M2C_FIELD(temp_r5_13202, u16 *, 0x1C)), s8 *, 0x42E) = 0;
    M2C_FIELD(temp_r5_13202, u16 *, 0x1C) = 0xFFFFU;
}

void sub_0201EB48(s32 arg0) {
    s8 *sp0;
    s32 temp_r1_13752;
    s32 temp_r5_13817;
    s32 var_r0_13801;
    s32 var_r2_13805;
    u16 temp_r0_13796;
    u8 temp_r0_13765;
    void *temp_r0_13809;
    void *temp_r5_13819;
    void *temp_r6_13754;

    temp_r1_13752 = arg0 * 0x30;
    temp_r6_13754 = temp_r1_13752 + 0x03003C00;
    if (M2C_FIELD(temp_r6_13754, u8 *, 0x2C) == 0) {
        temp_r0_13765 = M2C_FIELD(temp_r6_13754, u8 *, 0x27) - 1;
        M2C_FIELD(temp_r6_13754, u8 *, 0x27) = temp_r0_13765;
        if ((temp_r0_13765 << 0x18) == 0) {
            M2C_FIELD(temp_r6_13754, u8 *, 0x27) = 2U;
            M2C_FIELD(temp_r6_13754, u8 *, 0x26) = (u8) (M2C_FIELD(temp_r6_13754, u8 *, 0x26) + 1);
            M2C_FIELD(temp_r6_13754, u8 *, 0x25) = (u8) *(0x02030123 + M2C_FIELD(temp_r6_13754, u8 *, 0x26));
        }
    }
    sp0 = temp_r6_13754 + 0x26;
    if (1 & M2C_FIELD(temp_r6_13754, u8 *, 0x26)) {
        temp_r0_13796 = M2C_FIELD(temp_r6_13754, u16 *, 0xC);
        if ((temp_r0_13796 != 3) && (temp_r0_13796 != 0xE)) {
            var_r0_13801 = 0;
            do {
                var_r2_13805 = 3;
loop_8:
                temp_r0_13809 = var_r2_13805 + 0x03003710;
                if (M2C_FIELD(temp_r0_13809, u8 *, 0x41A) == 0) {
                    temp_r5_13817 = 0x54 * var_r2_13805;
                    temp_r5_13819 = temp_r5_13817 + 0x03004790;
                    M2C_FIELD(temp_r0_13809, u8 *, 0x41A) = 1U;
                    sub_02024F08(var_r2_13805);
                    *(0x03004790 + temp_r5_13817) = (s32) ((*(0x03003C00 + temp_r1_13752) + 0x10) - ((s32) sub_02019AF0(&gGameState) % 33));
                    M2C_FIELD(temp_r5_13819, s32 *, 4) = (s32) ((M2C_FIELD(temp_r6_13754, s32 *, 4) - 0x10) - ((s32) sub_02019AF0(&gGameState) % 17));
                    M2C_FIELD(temp_r5_13819, s8 *, 0x4E) = 3;
                } else {
                    var_r2_13805 += 1;
                    if (var_r2_13805 <= 9) {
                        goto loop_8;
                    }
                }
                var_r0_13801 += 1;
            } while (var_r0_13801 <= 2);
        }
    }
    if ((u32) M2C_FIELD(temp_r6_13754, u8 *, 0x25) > 2U) {
        M2C_FIELD(temp_r6_13754, u8 *, 0x27) = 0U;
        *sp0 = 0;
        M2C_FIELD(temp_r6_13754, u8 *, 0x25) = 0U;
        M2C_FIELD(temp_r6_13754, u8 *, 0x2C) = 0U;
        *((temp_r6_13754 + 0x2C) - 4) = 0;
    }
}

void sub_0201EC6C(s32 arg0) {
    u16 temp_r0_13918;
    u16 temp_r0_13942;
    u16 temp_r0_13952;
    u16 temp_r0_13975;
    u16 temp_r0_13980;
    u16 temp_r1_13962;
    u16 temp_r3_13954;
    u32 var_r4_13915;
    u32 var_r5_13917;
    u8 temp_r0_13898;
    u8 temp_r0_13901;
    u8 temp_r0_13995;
    void *temp_r2_13895;

    temp_r2_13895 = (arg0 * 0x30) + 0x03003C00;
    temp_r0_13898 = M2C_FIELD(temp_r2_13895, u8 *, 0x27);
    if (temp_r0_13898 != 0) {
        temp_r0_13901 = temp_r0_13898 - 1;
        M2C_FIELD(temp_r2_13895, u8 *, 0x27) = temp_r0_13901;
        if (!(temp_r0_13901 & 1)) {
            M2C_FIELD(temp_r2_13895, u16 *, 0x16) = (u16) (M2C_FIELD(temp_r2_13895, u16 *, 0x16) + 1);
        }
    } else {
        var_r4_13915 = 0x200;
        var_r5_13917 = 0xF200;
        temp_r0_13918 = M2C_FIELD(temp_r2_13895, u16 *, 0xC);
        switch (temp_r0_13918) {                    /* irregular */
        case 14:
        case 3:
            var_r4_13915 = 0x800;
            var_r5_13917 = 0xE800;
            break;
        case 4:
            var_r4_13915 = 0x400;
            var_r5_13917 = 0xF800;
            break;
        }
        temp_r0_13942 = var_r4_13915 + M2C_FIELD(temp_r2_13895, u16 *, 0x12);
        M2C_FIELD(temp_r2_13895, u16 *, 0x12) = temp_r0_13942;
        if ((u32) temp_r0_13942 > var_r4_13915) {
            M2C_FIELD(temp_r2_13895, u16 *, 0x12) = (u16) var_r4_13915;
        }
        temp_r0_13952 = M2C_FIELD(temp_r2_13895, u16 *, 0x10) - M2C_FIELD(temp_r2_13895, u16 *, 0x12);
        M2C_FIELD(temp_r2_13895, u16 *, 0x10) = temp_r0_13952;
        temp_r3_13954 = M2C_FIELD(temp_r2_13895, u16 *, 0x14);
        if ((u32) temp_r0_13952 <= (u32) temp_r3_13954) {
            temp_r1_13962 = (0xFF00 & temp_r3_13954) - var_r4_13915;
            M2C_FIELD(temp_r2_13895, u16 *, 0x14) = temp_r1_13962;
            M2C_FIELD(temp_r2_13895, u16 *, 0x16) = (u16) (M2C_FIELD(temp_r2_13895, u16 *, 0x16) + 1);
            if ((u32) temp_r1_13962 < var_r5_13917) {
                M2C_FIELD(temp_r2_13895, u16 *, 0x18) = (u16) (M2C_FIELD(temp_r2_13895, u16 *, 0x18) + 1);
            }
            temp_r0_13975 = M2C_FIELD(temp_r2_13895, u16 *, 0xC);
            if ((temp_r0_13975 != 3) && (temp_r0_13975 != 0xE)) {
                temp_r0_13980 = M2C_FIELD(temp_r2_13895, u16 *, 0x1A);
                if ((u32) temp_r0_13980 <= 5U) {
                    M2C_FIELD(temp_r2_13895, u16 *, 0x1A) = (u16) (temp_r0_13980 + 1);
                }
            }
        }
        if ((u32) M2C_FIELD(temp_r2_13895, u16 *, 0x10) <= 0xD000U) {
            M2C_FIELD(temp_r2_13895, u16 *, 0x10) = 0xD000U;
            temp_r0_13995 = M2C_FIELD(temp_r2_13895, u8 *, 0x26) + 1;
            M2C_FIELD(temp_r2_13895, u8 *, 0x26) = temp_r0_13995;
            if ((u32) temp_r0_13995 > 0x20U) {
                M2C_FIELD(temp_r2_13895, s8 *, 0x28) = 4;
                M2C_FIELD(temp_r2_13895, s16 *, 0x1C) = 0;
            }
        }
    }
}

void sub_0201ED50(s32 arg0) {
    M2C_FIELD((arg0 + 0x03003710), s8 *, 0x44D) = 0;
}

void sub_0201ED68(void *arg0, s32 arg1) {
    s32 sp0;
    s32 sp4;
    M2C_UNK sp8;
    s32 temp_r0_14035;
    s32 var_r1_14195;
    u8 *temp_r6_14164;
    u8 temp_r2_14065;
    u8 temp_r3_14078;
    u8 temp_r4_14056;
    u8 temp_r4_14090;
    void *temp_r7_14037;
    void *var_r6_14045;

    temp_r0_14035 = arg1 * 0x30;
    temp_r7_14037 = temp_r0_14035 + 0x03003C00;
    var_r6_14045 = (gGameState.unk_860 * 8) + gUnk3002410;
    temp_r4_14056 = (0x3F & M2C_FIELD(var_r6_14045, u8 *, 1)) | ((((u32) M2C_FIELD(arg0, u32 *, 0) >> 0xE) & 3) << 6);
    M2C_FIELD(var_r6_14045, u8 *, 1) = temp_r4_14056;
    temp_r2_14065 = (0x3F & M2C_FIELD(var_r6_14045, u8 *, 3)) | (((u32) M2C_FIELD(arg0, u32 *, 0) >> 0x1E) << 6);
    M2C_FIELD(var_r6_14045, u8 *, 3) = temp_r2_14065;
    M2C_FIELD(var_r6_14045, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(var_r6_14045, u16 *, 4)) | (0x3FF & M2C_FIELD(arg0, u16 *, 0xC)));
    temp_r3_14078 = -0x11 & temp_r2_14065;
    M2C_FIELD(var_r6_14045, u8 *, 3) = temp_r3_14078;
    M2C_FIELD(var_r6_14045, u8 *, 5) = (u8) (((-0xD & M2C_FIELD(var_r6_14045, u8 *, 5)) | 4) & 0xF);
    temp_r4_14090 = temp_r4_14056 | 0x10;
    M2C_FIELD(var_r6_14045, u8 *, 1) = temp_r4_14090;
    if ((u32) (u8) (M2C_FIELD(temp_r7_14037, u8 *, 0x28) - 3) <= 1U) {
        M2C_FIELD(var_r6_14045, u8 *, 3) = (u8) (-0xF & temp_r3_14078);
        M2C_FIELD(var_r6_14045, u8 *, 1) = (u8) (((temp_r4_14090 & ~3) | 1) & ~0xC);
        sp0 = (u16) ((sp0 & 0xFFFF0000) | 0x100) | 0x01000000;
        if (M2C_FIELD(temp_r7_14037, u8 *, 0x29) == 0) {
            sp4 = (sp4 & 0xFFFF0000) | M2C_FIELD(temp_r7_14037, u16 *, 0x10);
        } else {
            sp4 = (sp4 & 0xFFFF0000) | (u16) (0 - M2C_FIELD(temp_r7_14037, u16 *, 0x10));
        }
        ObjAffineSet((struct ObjAffineSrcData *) &sp0, &sp8, 1, 2);
        M2C_FIELD(gUnk3002410, u16 *, 6) = (u16) M2C_FIELD(&sp8, u16 *, 0);
        M2C_FIELD(gUnk3002410, u16 *, 0xE) = (u16) M2C_FIELD(&sp8, u16 *, 2);
        temp_r6_14164 = &gUnk3002410[8] + 8;
        M2C_FIELD(temp_r6_14164, u16 *, 6) = (u16) M2C_FIELD(&sp8, u16 *, 4);
        M2C_FIELD(temp_r6_14164, u16 *, 0xE) = (u16) M2C_FIELD(&sp8, u16 *, 6);
        var_r6_14045 = (gGameState.unk_860 * 8) + gUnk3002410;
    }
    if (M2C_FIELD(temp_r7_14037, u8 *, 0x29) == 0) {
        var_r1_14195 = M2C_FIELD(arg0, s32 *, 8) + (*(0x03003C00 + temp_r0_14035) - gGameState.unk_844) + M2C_FIELD(temp_r7_14037, u16 *, 0x16) + M2C_FIELD(temp_r7_14037, u16 *, 0x1A);
    } else {
        var_r1_14195 = ((M2C_FIELD(arg0, s32 *, 8) + (*(0x03003C00 + temp_r0_14035) - gGameState.unk_844)) - M2C_FIELD(temp_r7_14037, u16 *, 0x16)) - M2C_FIELD(temp_r7_14037, u16 *, 0x1A);
    }
    M2C_FIELD(var_r6_14045, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(var_r6_14045, u16 *, 2)) | (var_r1_14195 & 0x1FF));
    M2C_FIELD(var_r6_14045, s8 *, 0) = (s8) (M2C_FIELD(arg0, s32 *, 4) + (M2C_FIELD(temp_r7_14037, s32 *, 4) - M2C_FIELD(&gGameState, u8 *, 0x846)) + M2C_FIELD(temp_r7_14037, u8 *, 0x18));
    gGameState.unk_860 += 1;
}

void sub_0201EF44(s32 arg0) {
    s32 temp_r1_14270;
    void *temp_r3_14265;

    temp_r3_14265 = (arg0 * 0x30) + 0x03003C00;
    temp_r1_14270 = M2C_FIELD(temp_r3_14265, s32 *, 4);
    if ((temp_r1_14270 >= (s32) gGameState.unk_846) && (temp_r1_14270 <= (s32) (gGameState.unk_846 + 0xC8)) && ((M2C_FIELD(temp_r3_14265, u8 *, 0x28) != 3) || !(2 & M2C_FIELD(temp_r3_14265, u8 *, 0x26)))) {
        sub_0201ED68((*(0x0202FEE0 + (s32) ((M2C_FIELD(temp_r3_14265, u16 *, 0xC) * 8) + M2C_FIELD(temp_r3_14265, u8 *, 0x25))) * 0x10) + 0x0202FF78, arg0);
    }
}

s32 sub_0201EFB8(u16 arg0, u16 arg1) {
    s32 temp_r1_14347;
    s32 var_r2_14336;
    u16 *var_r1_14340;
    u16 *var_r4_14338;
    u16 temp_r3_14318;
    u16 var_r0_14353;
    void *temp_r1_14326;

    temp_r3_14318 = arg0;
    temp_r1_14326 = (temp_r3_14318 * 0xC) + 0x0202F7FC;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(temp_r1_14326, u16 *, 4) | 0x800000);
    if (M2C_FIELD(temp_r1_14326, u16 *, 8) != 4) {
        var_r2_14336 = 0;
        var_r4_14338 = (void *)0x030041A0 + 0x64;
        var_r1_14340 = (void *)0x030041A0 + 0x5A;
loop_2:
        if (*var_r1_14340 == 0) {
            *var_r1_14340 = temp_r3_14318 + 1;
            temp_r1_14347 = arg1 * 4;
            if (M2C_FIELD((temp_r1_14347 + 0x02034CF4), u8 *, 3) == 0) {
                var_r0_14353 = *(0x02034CF4 + temp_r1_14347);
            } else {
                var_r0_14353 = sub_02024AEC(*(0x02034CF4 + temp_r1_14347));
            }
            *var_r4_14338 = var_r0_14353;
            return 1;
        }
        var_r4_14338 += 2;
        var_r1_14340 += 2;
        var_r2_14336 += 1;
        if (var_r2_14336 > 4) {
            goto block_8;
        }
        goto loop_2;
    }
block_8:
    return 0;
}

s16 sub_0201F030(void) {
    s32 temp_r1_14451;
    s32 temp_r3_14413;
    s32 temp_r4_14411;
    s32 var_r4_14389;
    u16 temp_r1_14401;
    u16 temp_r2_14415;
    u16 var_r0_14400;
    u16 var_r0_14441;

    var_r4_14389 = (3 & *(u8 *)0x03004230) * 0x10;
    if ((0xF & *(u8 *)0x0300422D) == 8) {
        var_r4_14389 += 8;
    }
    var_r0_14400 = sub_02019AF0(&gGameState);
    temp_r1_14401 = var_r0_14400;
    if ((s32) temp_r1_14401 < 0) {
        var_r0_14400 = temp_r1_14401 + 7;
    }
    temp_r4_14411 = (var_r4_14389 + (temp_r1_14401 - (((s32) var_r0_14400 >> 3) * 8))) & 0x3F;
    temp_r3_14413 = temp_r4_14411 * 2;
    temp_r2_14415 = *(0x020338FC + temp_r3_14413);
    if ((u32) (u16) (temp_r2_14415 - 0x7E) > 1U) {
        if ((temp_r2_14415 != 0x25) && (*(u16 *)0x03004202 != 0)) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
            var_r0_14441 = M2C_FIELD(((*(0x0203397C + temp_r3_14413) * 0xC) + 0x0202F7FC), u16 *, 4);
            goto block_12;
        }
        temp_r1_14451 = temp_r4_14411 * 2;
        sub_0201EFB8(*(0x0203397C + temp_r1_14451), *(0x020338FC + temp_r1_14451));
        return 0;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
    if (temp_r2_14415 == 0x7F) {
        var_r0_14441 = 0x434E;
    } else {
        var_r0_14441 = 0x4350;
    }
block_12:
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (var_r0_14441 | 0x800000);
    return 0xFE;
}

s32 sub_0201F0FC(u8 arg0) {
    M2C_UNK sp0;
    u8 *sp4;
    s32 sp8;
    u8 *spC;
    u16 *sp10;
    s32 temp_r0_14516;
    s32 temp_r1_14626;
    s32 temp_r1_14711;
    s32 temp_r1_14761;
    s32 temp_r2_14526;
    s32 temp_r2_14542;
    s32 temp_r3_14520;
    s32 temp_r3_14590;
    s32 temp_r3_14619;
    s32 var_r5_14540;
    s32 var_r6_14562;
    s8 temp_r0_14644;
    u16 *temp_r2_14629;
    u16 *temp_r6_14639;
    u16 *var_r1_14566;
    u32 temp_r1_14514;
    u32 temp_r1_14652;
    u32 temp_r2_14674;
    u8 temp_r0_14493;
    u8 temp_r1_14507;
    u8 temp_r4_14499;

    temp_r0_14493 = arg0;
    temp_r4_14499 = *(u8 *)0x0300422E;
    temp_r1_14507 = (0xF0 & temp_r4_14499) + (temp_r0_14493 & 0xF0);
    temp_r1_14514 = 0xF & temp_r4_14499;
    temp_r0_14516 = temp_r0_14493 & 0xF;
    temp_r3_14520 = temp_r1_14507 | ((temp_r1_14514 + temp_r0_14516) & 0xF);
    temp_r2_14526 = temp_r1_14507 | ((temp_r1_14514 - temp_r0_14516) & 0xF);
    *(s16 *)0x0300421A = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
    if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
        var_r5_14540 = 0x0600A000;
        temp_r2_14542 = temp_r3_14520 * 2;
        M2C_FIELD(&sp0, u16 *, 0) = (u16) *(0x03003720 + temp_r2_14542);
        if (temp_r1_14514 > (u32) (temp_r3_14520 & 0xF)) {
            var_r5_14540 = 0x0600A800;
            M2C_FIELD(&sp0, u16 *, 0) = (u16) *(0x03003920 + temp_r2_14542);
        }
        var_r6_14562 = 0x0600A000;
        var_r1_14566 = (temp_r2_14526 * 2) + 0x03003720;
        goto block_6;
    }
    *(s16 *)0x0300421A = 0x8000;
    var_r5_14540 = 0x0600A800;
    M2C_FIELD(&sp0, u16 *, 0) = (u16) *(0x03003920 + (temp_r3_14520 * 2));
    var_r6_14562 = 0x0600A800;
    temp_r3_14590 = temp_r2_14526 * 2;
    M2C_FIELD(&sp0, u16 *, 2) = (u16) *(0x03003920 + temp_r3_14590);
    if (temp_r1_14514 < (u32) (temp_r2_14526 & 0xF)) {
        var_r6_14562 = 0x0600A000;
        var_r1_14566 = temp_r3_14590 + 0x03003720;
block_6:
        M2C_FIELD(&sp0, u16 *, 2) = (u16) *var_r1_14566;
    }
    sp4 = (void *)0x030041A0 + 0x8E;
    M2C_FIELD((void *)0x030041A0, u16 *, 0x7A) = (u16) (M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) | M2C_FIELD((void *)0x030041A0, u16 *, 0x7A));
    temp_r3_14619 = temp_r3_14520 & 0xF0;
    sp8 = temp_r3_14619;
    temp_r1_14626 = temp_r3_14520 & 0xF;
    temp_r2_14629 = (temp_r1_14626 * 4) + (var_r5_14540 + (temp_r3_14619 * 8));
    temp_r6_14639 = var_r6_14562 + ((temp_r2_14526 & 0xF0) * 8) + ((temp_r2_14526 & 0xF) * 4);
    sp10 = temp_r2_14629;
    temp_r0_14644 = sub_0201F6DC(M2C_FIELD(&sp0, u16 *, 0), temp_r2_14629);
    spC = sp4;
    if ((temp_r0_14644 != 0) || (temp_r1_14652 = 0x3FF & *temp_r2_14629, (temp_r1_14652 <= 5U)) || ((u32) (u16) (temp_r1_14652 - 0x10) <= 5U) || (temp_r1_14652 > 0xAFU)) {
        if ((sub_0201F6DC(M2C_FIELD(&sp0, u16 *, 2), temp_r6_14639) != 0) || (temp_r2_14674 = 0x3FF & *temp_r6_14639, (temp_r2_14674 <= 5U)) || ((u32) (u16) (temp_r2_14674 - 0x10) <= 5U) || (temp_r2_14674 > 0xAFU)) {
            M2C_FIELD((void *)0x030041A0, u16 *, 0x7A) = 0U;
            return 0;
        }
        if ((s32) temp_r6_14639 & 0x800) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0x10000;
        }
        M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x70;
        temp_r1_14711 = M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r1_14711;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (temp_r1_14711 | (((0xF & *spC) << 0xC) + 0x800));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (((0xF0 & *spC) << 8) + 0x800);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x18) | (((temp_r2_14526 & 0xF) << 0xC) + 0x800));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = (s32) (((temp_r2_14526 & 0xF0) << 8) + 0x800);
        return temp_r2_14526;
    }
    if ((s32) temp_r2_14629 & 0x800) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0x10000;
    }
    M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x60;
    temp_r1_14761 = M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r1_14761;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (temp_r1_14761 | (((0xF & *sp4) << 0xC) + 0x800));
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (((0xF0 & *sp4) << 8) + 0x800);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x18) | ((temp_r1_14626 << 0xC) + 0x800));
    M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = (s32) ((sp8 << 8) + 0x800);
    return temp_r3_14520;
}

s32 sub_0201F368(void) {
    s32 var_r2_14825;
    s32 var_r5_14808;
    u8 temp_r0_14835;

    sub_0201F538(*(u8 *)0x0300422B);
    var_r5_14808 = 0;
loop_1:
    if (sub_0201F6DC(*(0x030041E8 + (var_r5_14808 * 2)), M2C_FIELD((void *)0x030041A0, u16 **, 0x44)) == 0) {
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r2_14825 = 0x0600A000;
        } else {
            var_r2_14825 = 0x0600A800;
        }
        temp_r0_14835 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E);
        if ((u32) (u16) ((*(((0xF0 & temp_r0_14835) * 8) + var_r2_14825 + ((0xF & temp_r0_14835) * 4) + *(0x02033A1C + (var_r5_14808 * 4))) & 0x3FF) - 0x20) > 0x5EU) {
            goto block_6;
        }
        var_r5_14808 += 1;
        if (var_r5_14808 > 3) {
            return 1;
        }
        goto loop_1;
    }
block_6:
    return 0;
}

s32 sub_0201F3F8(s32 arg0, s32 arg1, u8 arg2, M2C_UNK arg3) {
    s32 temp_r0_14898;
    s32 temp_r0_14974;
    s32 temp_r1_14888;
    s32 var_r0_14963;
    s32 var_r2_14951;
    u16 temp_r3_14946;
    u8 temp_r2_15006;
    u8 temp_r7_14885;
    u8 temp_sb_14928;
    u8 var_r1_15009;

    temp_r7_14885 = arg2;
    temp_r1_14888 = arg0 - M2C_FIELD((void *)0x030041A0, s32 *, 0);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r1_14888;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (arg1 - M2C_FIELD((void *)0x030041A0, s32 *, 4));
    if (temp_r1_14888 < 0) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) (0 - temp_r1_14888);
    }
    temp_r0_14898 = M2C_FIELD((void *)0x030041A0, s32 *, 0x24);
    if (temp_r0_14898 < 0) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (0 - temp_r0_14898);
    }
    if (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x20) <= 0x100) && ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x24) <= 0x100)) {
        return 1;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) ((s32) (arg0 - M2C_FIELD((void *)0x030041A0, s32 *, 0)) >> 8);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) ((s32) (arg1 - M2C_FIELD((void *)0x030041A0, s32 *, 4)) >> 8);
    temp_sb_14928 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8B);
    if (temp_r7_14885 != 0) {
        if (temp_r7_14885 != 1) {
            sub_020207C0(1U, arg0);
            sub_02020814(1U, arg1);
            temp_r3_14946 = ArcTan2((s16) M2C_FIELD((void *)0x030041A0, s32 *, 0x20), (s16) M2C_FIELD((void *)0x030041A0, s32 *, 0x24));
            if ((u32) temp_r3_14946 < (u32) *(u16 *)0x020338F8) {
                var_r2_14951 = 0;
                if ((u32) temp_r3_14946 > (u32) *(u16 *)0x020338DC) {
loop_18:
                    var_r2_14951 += 1;
                    if (var_r2_14951 <= 6) {
                        if ((u32) temp_r3_14946 <= (u32) *(0x020338DC + (var_r2_14951 * 4))) {

                        } else {
                            goto loop_18;
                        }
                    }
                }
            } else {
                var_r2_14951 = 0;
            }
            temp_r2_15006 = M2C_FIELD(((var_r2_14951 * 4) + 0x020338DC), u8 *, 2);
            var_r1_15009 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) - temp_r2_15006;
            if (0x80 & var_r1_15009) {
                var_r1_15009 = (u8) ((u32) ((~var_r1_15009 << 0x18) + 0x01000000) >> 0x18);
            }
            if ((u32) (u8) (var_r1_15009 - 2) <= 4U) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = temp_r2_15006;
            }
        } else {
            temp_r0_14974 = sub_02020814(0U, arg1);
            if (temp_r0_14974 != 0) {
                sub_020207C0(0U, arg0);
                var_r0_14963 = 0;
                goto block_16;
            }
            M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r0_14974;
        }
    } else {
        var_r0_14963 = sub_020207C0(0U, arg0);
        if (var_r0_14963 != 0) {
            sub_02020814(0U, arg1);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) temp_r7_14885;
        } else {
block_16:
            M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = var_r0_14963;
        }
    }
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) != temp_sb_14928) {
        sub_02020790();
    }
    return 0;
}

void sub_0201F538(void) {
    s32 temp_r0_15147;
    s32 temp_r1_15142;
    s32 temp_r3_15089;
    s32 var_r1_15169;
    s32 var_r5_15071;
    s8 temp_r2_15160;
    u16 var_r0_15119;
    u32 temp_r1_15108;
    u32 var_r6_15081;
    void *var_r4_15079;

    M2C_FIELD((void *)0x030041A0, s8 *, 0x8E) = (s8) ((u32) (((((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8) & 0xFF0 & 0xF0) << 0x14) | ((((s32) M2C_FIELD((void *)0x030041A0, s32 *, 4) >> 8) & 0xFF0) << 0x18)) >> 0x18);
    var_r5_15071 = 0;
    var_r4_15079 = (void *)0x030041A0 + 0x48;
    var_r6_15081 = 0x01000000;
    do {
        temp_r3_15089 = M2C_FIELD((void *)0x030041A0, s32 *, 0) + *(0x020339FC + ((u32) (var_r5_15071 << 0x19) >> 0x16));
        temp_r1_15108 = (u32) ((((temp_r3_15089 >> 8) & 0xF0) << 0x14) | ((((s32) (M2C_FIELD((void *)0x030041A0, s32 *, 4) + *(0x020339FC + ((var_r6_15081 >> 0x18) * 4))) >> 8) & ~0xF) << 0x18)) >> 0x18;
        if (!(temp_r3_15089 & 0xFF0000)) {
            M2C_FIELD(var_r4_15079, s16 *, 8) = (s16) temp_r1_15108;
            var_r0_15119 = *(0x03003720 + (temp_r1_15108 * 2));
        } else {
            M2C_FIELD(var_r4_15079, s16 *, 8) = (s16) temp_r1_15108;
            var_r0_15119 = *(0x03003920 + (temp_r1_15108 * 2));
        }
        M2C_FIELD(var_r4_15079, u16 *, 0) = var_r0_15119;
        var_r4_15079 += 2;
        var_r6_15081 += 0x02000000;
        var_r5_15071 += 1;
    } while (var_r5_15071 <= 3);
    temp_r1_15142 = M2C_FIELD((void *)0x030041A0, s32 *, 0) + 0xFFFFFE00;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r1_15142;
    temp_r0_15147 = M2C_FIELD((void *)0x030041A0, s32 *, 4) + 0x200;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = temp_r0_15147;
    temp_r2_15160 = ((temp_r0_15147 >> 8) & 0xFF0) | ((s32) ((temp_r1_15142 >> 8) & 0xFF0 & 0xF0) >> 4);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x8F) = temp_r2_15160;
    if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0x20) & 0xFF0000)) {
        var_r1_15169 = 0x0600A000;
    } else {
        var_r1_15169 = 0x0600A800;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x44) = (s32) (((temp_r2_15160 & 0xF0) * 8) + var_r1_15169 + ((temp_r2_15160 & 0xF) * 4));
}

void sub_0201F660(s32 arg0, u8 arg1, u16 arg2, u16 arg3) {
    s32 var_r1_15218;
    s32 var_r2_15219;
    s32 var_r3_15210;
    u32 temp_r4_15199;
    u8 temp_r5_15200;

    temp_r4_15199 = arg1 << 0x18;
    temp_r5_15200 = arg1;
    if (!(0xFF0000 & arg0)) {
        var_r3_15210 = 0x0600C000;
        var_r1_15218 = ((0xF & temp_r5_15200) * 2) + ((temp_r4_15199 >> 0x1C) << 5);
        var_r2_15219 = *(s32 *)0x03001B40 + 0x24;
    } else {
        var_r3_15210 = 0x0600C800;
        var_r1_15218 = ((0xF & temp_r5_15200) * 2) + ((temp_r4_15199 >> 0x1C) << 5);
        var_r2_15219 = *(void *)0x03001B40 + 0x224;
    }
    *(var_r2_15219 + var_r1_15218) = arg2;
    sub_02020A0C(var_r3_15210 + ((0xF0 & temp_r5_15200) * 8) + ((0xF & temp_r5_15200) * 4), arg3);
}

s8 sub_0201F6DC(u16 arg0, u16 *arg1) {
    s32 *var_r1_15268;
    s32 temp_r2_15274;
    s32 var_r3_15265;
    u16 temp_r0_15263;

    temp_r0_15263 = arg0;
    var_r3_15265 = 0;
    var_r1_15268 = (s32 *)0x02033A1C;
loop_1:
    temp_r2_15274 = 0x3FF & *(arg1 + *var_r1_15268);
    if (((var_r3_15265 != 1) || (temp_r2_15274 != 0x96)) && ((u32) (u16) (temp_r2_15274 - 0xB0) > 5U) && ((u32) (u16) (temp_r2_15274 - 0xC0) > 0x15U) && ((u32) (u16) (temp_r2_15274 - 0xE0) > 0x31FU)) {
        var_r1_15268 += 4;
        var_r3_15265 += 1;
        if (var_r3_15265 > 3) {
            if (((u32) (u16) (temp_r0_15263 - 0x1F) <= 1U) || ((u32) (u16) (temp_r0_15263 - 0x22) <= 3U) || ((u32) (u16) (temp_r0_15263 - 0x27) <= 8U) || ((u32) (u16) (temp_r0_15263 - 0x31) <= 3U) || ((u32) (u16) (temp_r0_15263 - 0x36) <= 6U) || (temp_r0_15263 == 0x41)) {
                return 1;
            }
            return 0;
        }
        goto loop_1;
    }
    return 2;
}

u8 sub_0201F78C(u8 arg0) {
    s32 var_r4_15368;
    s32 var_r4_15387;
    u8 temp_r0_15386;
    void *var_r1_15367;
    void *var_r4_15395;
    void *var_r4_15412;
    void *var_r5_15413;

    var_r1_15367 = (void *)0x03004242;
    var_r4_15368 = 7;
    do {
        M2C_FIELD(var_r1_15367, s8 *, 0) = 0;
        M2C_FIELD(var_r1_15367, u8 *, 8) = (u8) (M2C_FIELD(var_r1_15367, u8 *, 8) | 0xFF);
        var_r1_15367 += 1;
        var_r4_15368 -= 1;
    } while (var_r4_15368 >= 0);
    *(0x03004242 + *(u8 *)0x0300422B) = 1;
    if (arg0 == 0) {
        temp_r0_15386 = *(u8 *)0x0300422B;
        var_r4_15387 = temp_r0_15386 + 4;
        if (var_r4_15387 > 7) {
            var_r4_15387 = temp_r0_15386 - 4;
        }
        *(0x03004242 + var_r4_15387) = 1;
    }
    var_r4_15395 = NULL;
    do {
        if ((*(0x03004242 + (s32) var_r4_15395) == 0) && (sub_0201F844((u8) var_r4_15395) == 0)) {
            *(0x03004242 + (s32) var_r4_15395) = 1U;
        }
        var_r4_15395 += 1;
    } while ((s32) var_r4_15395 <= 7);
    var_r4_15412 = NULL;
    var_r5_15413 = NULL;
    do {
        if (*(0x03004242 + (s32) var_r4_15412) == 0) {
            *(0x0300424A + (s32) var_r5_15413) = (s8) var_r4_15412;
            var_r5_15413 += 1;
        }
        var_r4_15412 += 1;
    } while ((s32) var_r4_15412 <= 7);
    if (var_r5_15413 != NULL) {
        return *(0x0300424A + ((s32) sub_02019AF0(&gGameState) % (s32) var_r5_15413));
    }
    return 0x777U;
}

s32 sub_0201F844(u8 arg0) {
    s32 temp_r3_15467;
    s32 var_r2_15501;
    u16 *temp_r2_15527;
    u16 *var_r1_15499;
    u8 temp_r0_15456;
    u8 temp_r4_15487;

    temp_r0_15456 = arg0;
    temp_r3_15467 = M2C_FIELD((void *)0x030041A0, s32 *, 0) + *(0x02033A2C + (temp_r0_15456 * 8));
    temp_r4_15487 = ((temp_r3_15467 >> 0xC) & 0xF) | (((s32) (M2C_FIELD((void *)0x030041A0, s32 *, 4) + (*(0x02033A2C + (((temp_r0_15456 * 2) + 1) * 4)) + 0x800)) >> 8) & ~0xF);
    if (!(temp_r3_15467 & 0xFF0000)) {
        var_r1_15499 = (void *)0x030041A0 + 0x48;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x48) = (u16) *(0x03003720 + (temp_r4_15487 * 2));
        var_r2_15501 = 0x0600A000;
    } else {
        var_r1_15499 = (void *)0x030041A0 + 0x48;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x48) = (u16) *(0x03003920 + (temp_r4_15487 * 2));
        var_r2_15501 = 0x0600A800;
    }
    temp_r2_15527 = ((0xF0 & temp_r4_15487) * 8) + var_r2_15501 + ((0xF & temp_r4_15487) * 4);
    M2C_FIELD((void *)0x030041A0, u16 **, 0x44) = temp_r2_15527;
    if (sub_0201F6DC(*var_r1_15499, temp_r2_15527) == 0) {
        return 1;
    }
    return 0;
}

void sub_0201F8FC(u16 arg0) {
    s32 temp_r0_15704;
    s32 temp_r1_15635;
    s32 temp_r2_15693;
    s32 temp_r2_15722;
    s32 temp_r2_15758;
    s32 temp_r2_15819;
    s32 temp_r2_15849;
    s32 temp_r4_15725;
    s32 temp_r4_15761;
    s32 var_r2_15833;
    s32 var_r3_15566;
    s32 var_r3_15831;
    s32 var_r4_15561;
    s32 var_r4_15687;
    s32 var_r4_15822;
    s32 var_r5_15626;
    u16 *var_r2_15737;
    u16 *var_r5_15688;
    u16 temp_r1_15618;
    u16 var_r0_15617;
    u16 var_r0_15741;
    u16 var_r5_15553;
    u16 var_r5_15791;
    u32 temp_r3_15696;
    u32 temp_r3_15824;
    u32 temp_r3_15854;
    u32 var_r2_15565;
    u8 temp_r1_15668;
    u8 temp_r1_15690;
    u8 temp_r5_15634;
    u8 temp_r8_15560;
    void *temp_r2_15643;
    void *temp_r6_15637;

    var_r5_15553 = arg0;
    temp_r8_15560 = *(u8 *)0x0300421A;
    var_r4_15561 = 0;
    var_r2_15565 = 0;
    var_r3_15566 = 0;
loop_1:
    if (var_r5_15553 != *(0x02034062 + ((var_r2_15565 >> 0x18) * 2))) {
        var_r2_15565 += 0x05000000;
        var_r3_15566 += 5;
        var_r4_15561 += 1;
        if (var_r4_15561 <= 0xC) {
            goto loop_1;
        }
    } else {
        var_r5_15553 = *(0x02034062 + ((u32) ((var_r3_15566 + 1 + M2C_FIELD((void *)0x030041A0, u8 *, 0x90)) << 0x18) >> 0x17));
    }
    if (var_r4_15561 > 0xC) {
        *(s16 *)0x0300420E = 0xF;
        return;
    }
    if ((0xF & *(u8 *)0x0300422D) == 7) {
        var_r5_15553 += 0x10;
    }
    var_r0_15617 = sub_02019AF0(&gGameState);
    temp_r1_15618 = var_r0_15617;
    if ((s32) temp_r1_15618 < 0) {
        var_r0_15617 = temp_r1_15618 + 3;
    }
    var_r5_15626 = var_r5_15553 + (temp_r1_15618 - (((s32) var_r0_15617 >> 2) * 4));
    if (var_r5_15626 > 0x11F) {
        var_r5_15626 = 0;
    }
    temp_r5_15634 = *(0x020340E4 + var_r5_15626);
    temp_r1_15635 = temp_r5_15634 * 4;
    temp_r6_15637 = temp_r1_15635 + 0x02034CF4;
    temp_r2_15643 = (M2C_FIELD(temp_r6_15637, u8 *, 2) * 0xC) + 0x0202F7FC;
    if ((M2C_FIELD(temp_r2_15643, u16 *, 6) == 0xFFF) || (temp_r5_15634 == 0xD)) {
        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 0xF;
        return;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(temp_r2_15643, u16 *, 4) | 0x800000);
    temp_r1_15668 = M2C_FIELD(temp_r6_15637, u8 *, 2);
    if (((u32) (u8) (temp_r1_15668 - 3) <= 4U) || (temp_r1_15668 == 0x1E)) {
        M2C_FIELD((void *)0x030041A0, s16 *, 0x7C) = 0x3260;
        if (M2C_FIELD(temp_r6_15637, u8 *, 2) == 0x1E) {
            M2C_FIELD((void *)0x030041A0, s16 *, 0x7C) = 0x3268;
        }
        var_r4_15687 = 0;
        var_r5_15688 = (u16 *)0x02033A6C;
        temp_r1_15690 = M2C_FIELD(temp_r6_15637, u8 *, 2);
        temp_r2_15693 = temp_r8_15560 * 2;
        temp_r3_15696 = temp_r8_15560 >> 4;
        if (*(u16 *)0x02033A6C != temp_r1_15690) {
loop_21:
            var_r4_15687 += 1;
            if (var_r4_15687 <= 5) {
                temp_r0_15704 = var_r4_15687 * 4;
                var_r5_15688 = temp_r0_15704 + 0x02033A6C;
                if (*(0x02033A6C + temp_r0_15704) != temp_r1_15690) {
                    goto loop_21;
                }
            }
        }
        if (!(0x8000 & M2C_FIELD((void *)0x030041A0, u16 *, 0x7A))) {
            *(0x03003720 + temp_r2_15693) = 0x7777;
            temp_r2_15722 = *(void *)0x03001B40;
            temp_r4_15725 = 0xF & temp_r8_15560;
            *(temp_r2_15722 + 0x24 + ((temp_r4_15725 * 2) + (temp_r3_15696 << 5))) = M2C_FIELD(var_r5_15688, u16 *, 2);
            var_r2_15737 = temp_r2_15722 + 0x18F8 + (temp_r3_15696 * 2);
            var_r0_15741 = *var_r2_15737 & ~(1 << temp_r4_15725);
        } else {
            *(0x03003920 + temp_r2_15693) = 0x7777;
            temp_r2_15758 = *(void *)0x03001B40;
            temp_r4_15761 = 0xF & temp_r8_15560;
            *(temp_r2_15758 + 0x224 + ((temp_r4_15761 * 2) + (temp_r3_15696 << 5))) = M2C_FIELD(var_r5_15688, u16 *, 2);
            var_r2_15737 = temp_r2_15758 + 0x1918 + (temp_r3_15696 * 2);
            var_r0_15741 = *var_r2_15737 & ~(1 << temp_r4_15761);
        }
    } else {
        M2C_FIELD((void *)0x030041A0, s16 *, 0x7C) = 0x1270;
        if (M2C_FIELD(temp_r6_15637, u8 *, 3) == 0) {
            var_r5_15791 = *(0x02034CF4 + temp_r1_15635);
        } else {
            var_r5_15791 = sub_02024AEC(*(0x02034CF4 + temp_r1_15635));
        }
        if (!(0x8000 & M2C_FIELD((void *)0x030041A0, u16 *, 0x7A))) {
            *(0x03003720 + (temp_r8_15560 * 2)) = (s16) (M2C_FIELD(temp_r6_15637, u8 *, 2) + 0x8000);
            temp_r2_15819 = *(s32 *)0x03001B40;
            var_r4_15822 = 0xF & temp_r8_15560;
            temp_r3_15824 = temp_r8_15560 >> 4;
            *(temp_r2_15819 + 0x24 + ((var_r4_15822 * 2) + (temp_r3_15824 << 5))) = var_r5_15791;
            var_r3_15831 = temp_r3_15824 * 2;
            var_r2_15833 = temp_r2_15819 + 0x18F8;
        } else {
            *(0x03003920 + (temp_r8_15560 * 2)) = (s16) (M2C_FIELD(temp_r6_15637, u8 *, 2) + 0x8000);
            temp_r2_15849 = *(void *)0x03001B40;
            var_r4_15822 = 0xF & temp_r8_15560;
            temp_r3_15854 = temp_r8_15560 >> 4;
            *(temp_r2_15849 + 0x224 + ((var_r4_15822 * 2) + (temp_r3_15854 << 5))) = var_r5_15791;
            var_r3_15831 = temp_r3_15854 * 2;
            var_r2_15833 = temp_r2_15849 + 0x1918;
        }
        var_r2_15737 = var_r2_15833 + var_r3_15831;
        var_r0_15741 = (1 << var_r4_15822) | *var_r2_15737;
    }
    *var_r2_15737 = var_r0_15741;
}

void sub_0201FB9C(void) {
    s32 temp_r3_15929;
    s32 temp_r3_15966;
    s32 var_r3_15946;
    s32 var_r4_15944;
    s32 var_r5_15931;
    s32 var_r6_15940;
    u16 *temp_r3_15986;
    u32 temp_r4_15898;
    u32 temp_r4_15933;
    u32 temp_r4_15970;
    u8 temp_r0_15897;
    u8 temp_r6_15899;
    u8 temp_r7_15909;

    temp_r0_15897 = *(u8 *)0x0300421A;
    temp_r4_15898 = temp_r0_15897 << 0x18;
    temp_r6_15899 = temp_r0_15897;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
    temp_r7_15909 = (u8) ((s32) sub_02019AF0(&gGameState) % 9);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x40) | 0x5344);
    if (!(0x8000 & (u16) *(u8 *)0x0300421A)) {
        *(0x03003720 + (temp_r6_15899 * 2)) = 0x7777;
        temp_r3_15929 = *(s32 *)0x03001B40;
        var_r5_15931 = 0xF & temp_r6_15899;
        temp_r4_15933 = temp_r4_15898 >> 0x1C;
        var_r6_15940 = temp_r7_15909 * 2;
        *(temp_r3_15929 + 0x24 + ((var_r5_15931 * 2) + (temp_r4_15933 << 5))) = *(0x02033F80 + var_r6_15940);
        var_r4_15944 = temp_r4_15933 * 2;
        var_r3_15946 = temp_r3_15929 + 0x18F8;
    } else {
        *(0x03003920 + (temp_r6_15899 * 2)) = 0x7777;
        temp_r3_15966 = *(void *)0x03001B40;
        var_r5_15931 = 0xF & temp_r6_15899;
        temp_r4_15970 = temp_r4_15898 >> 0x1C;
        var_r6_15940 = temp_r7_15909 * 2;
        *(temp_r3_15966 + 0x224 + ((var_r5_15931 * 2) + (temp_r4_15970 << 5))) = *(0x02033F80 + var_r6_15940);
        var_r4_15944 = temp_r4_15970 * 2;
        var_r3_15946 = temp_r3_15966 + 0x1918;
    }
    temp_r3_15986 = var_r3_15946 + var_r4_15944;
    *temp_r3_15986 &= ~(1 << var_r5_15931);
    M2C_FIELD((void *)0x030041A0, u16 *, 0x7C) = (u16) *(0x0202F8EC + ((var_r6_15940 + temp_r7_15909) * 4));
}

void sub_0201FCB0(void) {
    u8 temp_r0_16019;
    u8 temp_r1_16046;
    u8 var_r0_16054;

    temp_r0_16019 = *(u8 *)0x0300422B;
    if (((temp_r0_16019 == 0) || (temp_r0_16019 == 2) || (temp_r0_16019 == 1) || (temp_r0_16019 == 6) || (temp_r0_16019 == 7)) && (*(u8 *)0x03004230 == 0)) {
        if (*(u8 *)0x03004232 == 0) {
            temp_r1_16046 = (*(u8 *)0x03004231 + 1) & 1;
            *(u8 *)0x03004231 = temp_r1_16046;
            if (temp_r1_16046 == 0) {
                var_r0_16054 = ((s32) sub_02019AF0(&gGameState) % 65) + 0x20;
            } else {
                var_r0_16054 = 4;
            }
            *(u8 *)0x03004232 = var_r0_16054;
        }
        *(u8 *)0x03004232 -= 1;
    }
}

s32 sub_0201FD1C(s32 arg0, s32 arg1) {
    s32 temp_r0_16078;
    s32 temp_r0_16138;
    s32 temp_r0_16144;
    s32 temp_r1_16082;
    s32 temp_r2_16160;
    s32 var_r1_16095;
    u16 temp_r2_16090;
    u8 *var_r5_16098;
    u8 temp_r0_16129;

    temp_r0_16078 = (s32) (arg0 - M2C_FIELD((void *)0x030041A0, s32 *, 0)) >> 8;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r0_16078;
    temp_r1_16082 = (s32) (arg1 - M2C_FIELD((void *)0x030041A0, s32 *, 4)) >> 8;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = temp_r1_16082;
    temp_r2_16090 = ArcTan2((s16) temp_r0_16078, (s16) temp_r1_16082);
    if ((u32) temp_r2_16090 < (u32) *(u16 *)0x020338F8) {
        var_r1_16095 = 0;
        var_r5_16098 = (void *)0x030041A0 + 0x94;
        if ((u32) temp_r2_16090 > (u32) *(u16 *)0x020338DC) {
loop_3:
            var_r1_16095 += 1;
            if (var_r1_16095 <= 6) {
                if ((u32) temp_r2_16090 <= (u32) *(0x020338DC + (var_r1_16095 * 4))) {

                } else {
                    goto loop_3;
                }
            }
        }
    } else {
        var_r1_16095 = 0;
        var_r5_16098 = (void *)0x030041A0 + 0x94;
    }
    if (*var_r5_16098 == 0) {
        temp_r0_16129 = M2C_FIELD(((var_r1_16095 * 4) + 0x020338DC), u8 *, 2);
        if (temp_r0_16129 != M2C_FIELD((void *)0x030041A0, u8 *, 0x8B)) {
            M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = temp_r0_16129;
            sub_02020790();
            *var_r5_16098 = 0x20;
        }
    }
    temp_r0_16138 = M2C_FIELD((void *)0x030041A0, s32 *, 0x20);
    if (temp_r0_16138 < 0) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) (0 - temp_r0_16138);
    }
    temp_r0_16144 = M2C_FIELD((void *)0x030041A0, s32 *, 0x24);
    if (temp_r0_16144 < 0) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (0 - temp_r0_16144);
    }
    if (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x20) <= 1) && ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x24) <= 1)) {
        temp_r2_16160 = ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 4) >> 8) & 0xFF0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = temp_r2_16160;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8) & 0xFF0);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8E) = (s8) temp_r2_16160;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8E) = (s8) (((s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x20) & 0xF0) >> 4) | temp_r2_16160);
        return 1;
    }
    return 0;
}

s8 sub_0201FDF4(u8 arg0) {
    u8 temp_r0_16196;

    temp_r0_16196 = *(u8 *)0x0300422A - 1;
    *(u8 *)0x0300422A = temp_r0_16196;
    if (temp_r0_16196 & 0x80) {
        *(u8 *)0x03004229 += 1;
        if (M2C_FIELD(*((*(u8 *)0x03004229 * 4) + *(0x02033680 + (*(u8 *)0x03004228 * 4))), u8 *, 6) == 0xFF) {
            *(u8 *)0x03004229 = 0;
            if (arg0 == 1) {
                return 1;
            }
        }
        *(void *)0x0300422A = (u8) M2C_FIELD(*((*(u8 *)0x03004229 * 4) + *(0x02033680 + (*(u8 *)0x03004228 * 4))), u16 *, 4);
        goto block_5;
    }
block_5:
    return 0;
}

void sub_0201FE6C(s32 arg0) {
    s32 temp_r1_16285;
    s32 temp_r2_16257;
    s32 temp_r2_16272;
    s32 temp_r7_16276;
    s32 var_r1_16267;
    u16 temp_r3_16282;

    temp_r2_16257 = arg0 * 2;
    *(0x030041FA + temp_r2_16257) = 0;
    *(0x03004204 + temp_r2_16257) = 0;
    var_r1_16267 = arg0;
    if (var_r1_16267 <= 3) {
        do {
            temp_r2_16272 = var_r1_16267 * 2;
            temp_r7_16276 = var_r1_16267 + 1;
            if (*(0x030041FA + temp_r2_16272) == 0) {
                temp_r3_16282 = *(0x03004204 + temp_r2_16272);
                if (temp_r3_16282 == 0) {
                    temp_r1_16285 = temp_r7_16276 * 2;
                    *(0x030041FA + temp_r2_16272) = (u16) *(0x030041FA + temp_r1_16285);
                    *(0x03004204 + temp_r2_16272) = (u16) *(0x03004204 + temp_r1_16285);
                    *(0x030041FA + temp_r1_16285) = temp_r3_16282;
                    *(0x03004204 + temp_r1_16285) = temp_r3_16282;
                }
            }
            var_r1_16267 = temp_r7_16276;
        } while (var_r1_16267 <= 3);
    }
}

s32 sub_0201FED4(u8 arg0, u8 arg1) {
    s32 temp_r1_16327;
    s32 var_r3_16317;
    void *temp_r0_16319;
    void *temp_r4_16329;

    var_r3_16317 = 3;
loop_1:
    temp_r0_16319 = var_r3_16317 + 0x03003710;
    if (M2C_FIELD(temp_r0_16319, u8 *, 0x41A) == 0) {
        temp_r1_16327 = 0x54 * var_r3_16317;
        temp_r4_16329 = temp_r1_16327 + 0x03004790;
        M2C_FIELD(temp_r0_16319, u8 *, 0x41A) = 1U;
        sub_02024F08(var_r3_16317);
        M2C_FIELD(temp_r4_16329, s16 *, 0x40) = (s16) arg1;
        M2C_FIELD((temp_r4_16329 + 0x40), u8 *, 0xB) = arg0;
        M2C_FIELD(temp_r4_16329, s8 *, 0x4E) = 5;
        *(0x03004790 + temp_r1_16327) = (s32) ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8);
        M2C_FIELD(temp_r4_16329, s32 *, 4) = (s32) ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 4) >> 8);
        return 1;
    }
    var_r3_16317 += 1;
    if (var_r3_16317 > 0xB) {
        return 0;
    }
    goto loop_1;
}

s32 sub_0201FF48(u8 arg0, u8 arg1, u16 arg2, u16 arg3) {
    s32 sp0;
    s32 sp4;
    void *sp8;
    s32 temp_r1_16492;
    s32 var_r4_16414;
    s32 var_r6_16481;
    u16 *temp_r4_16450;
    u16 temp_r2_16382;
    u16 temp_r3_16405;
    u16 temp_r3_16431;
    u32 temp_r2_16460;
    u8 *var_r2_16399;
    u8 temp_r1_16379;
    u8 temp_r1_16442;
    u8 temp_r2_16556;
    u8 var_sb_16380;
    void *temp_r3_16500;
    void *temp_r4_16494;
    void *var_r5_16482;

    sp0 = (s32) arg0;
    temp_r1_16379 = arg1;
    var_sb_16380 = temp_r1_16379;
    temp_r2_16382 = arg2;
    sp4 = (s32) arg3;
    if (temp_r1_16379 == 0) {
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r2_16399 = (void *)0x030041A0 + 0x8E;
            temp_r3_16405 = *(0x03003720 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2));
            if ((temp_r3_16405 != 0xFFF) && (temp_r3_16405 != 0x3333)) {
                goto block_27;
            }
            var_r4_16414 = 0x0600A000;
            goto block_10;
        }
        var_r2_16399 = (void *)0x030041A0 + 0x8E;
        temp_r3_16431 = *(0x03003920 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2));
        if ((temp_r3_16431 != 0xFFF) && (temp_r3_16431 != 0x3333)) {
            goto block_27;
        }
        var_r4_16414 = 0x0600A800;
block_10:
        temp_r1_16442 = *var_r2_16399;
        temp_r4_16450 = var_r4_16414 + ((0xF0 & temp_r1_16442) * 8) + ((0xF & temp_r1_16442) * 4);
        if (sub_0201F6DC(0U, temp_r4_16450) != 0) {
            goto block_27;
        }
        temp_r2_16460 = 0x3FF & *temp_r4_16450;
        if (temp_r2_16460 <= 5U) {
            goto block_27;
        }
        if (((u32) (u16) (temp_r2_16460 - 0x10) > 5U) && (temp_r2_16460 <= 0xAFU)) {
            goto block_16;
        }
        goto block_27;
    }
block_16:
    if (var_sb_16380 == 2) {
        var_sb_16380 = 0;
    }
    var_r6_16481 = 3;
    var_r5_16482 = (void *)6;
loop_19:
    if (*(0x03003B27 + (s32) var_r5_16482) == 0) {
        temp_r1_16492 = 0x54 * var_r6_16481;
        temp_r4_16494 = temp_r1_16492 + 0x03004790;
        temp_r3_16500 = (temp_r2_16382 * 0xC) + 0x0202F7FC;
        sp8 = temp_r3_16500;
        sub_02024F08(var_r6_16481);
        *(0x03004790 + temp_r1_16492) = (s32) (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8) - 8);
        M2C_FIELD(temp_r4_16494, s32 *, 4) = (s32) (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 4) >> 8) - 0x10);
        if (var_sb_16380 == 0) {
            M2C_FIELD(temp_r4_16494, s8 *, 0x4E) = 7;
        } else {
            M2C_FIELD(temp_r4_16494, s8 *, 0x4E) = 9;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x9E) = (s8) var_r6_16481;
        }
        *(0x03003B27 + (s32) var_r5_16482) = 1U;
        M2C_FIELD(temp_r4_16494, u16 *, 0x28) = temp_r2_16382;
        M2C_FIELD(temp_r4_16494, u16 *, 0x32) = (u16) M2C_FIELD(&sp0, u16 *, 4);
        M2C_FIELD(temp_r4_16494, u8 *, 0x4A) = (u8) M2C_FIELD(&sp0, u8 *, 0);
        temp_r2_16556 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E);
        M2C_FIELD(temp_r4_16494, s16 *, 0x3C) = (s16) temp_r2_16556;
        if (M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000) {
            M2C_FIELD(temp_r4_16494, s16 *, 0x3C) = (s16) (temp_r2_16556 | 0x1000);
        }
        M2C_FIELD(temp_r4_16494, s16 *, 0x3E) = (s16) (M2C_FIELD(temp_r3_16500, u16 *, 4) & 0x3FF);
        M2C_FIELD(temp_r4_16494, s8 *, 0x50) = (s8) ((u16) M2C_FIELD(temp_r3_16500, u16 *, 4) >> 0xC);
        return var_r6_16481;
    }
    var_r5_16482 += 1;
    var_r6_16481 += 1;
    if (var_r6_16481 > 0xB) {
block_27:
        return 0;
    }
    goto loop_19;
}

s32 sub_02020118(void *arg0, s32 arg1, s32 arg2) {
    s32 *var_r2_16642;
    s32 *var_r4_16644;
    s32 temp_r0_16698;
    s32 temp_r0_16710;
    s32 temp_r0_16715;
    s32 temp_r0_16723;
    s32 temp_r1_16649;
    s32 temp_r1_16724;
    s32 temp_r2_16722;
    s32 var_r0_16781;
    s32 var_r5_16645;
    u8 temp_r4_16767;
    u8 temp_r4_16789;

    M2C_FIELD((void *)0x030041A0, s32 *, 0x30) = arg1;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = arg2;
    if ((arg1 == 0) && (arg2 == 0)) {
        return 0;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (((0xF0 & M2C_FIELD(arg0, u16 *, 0xE)) << 8) + 0x800);
    M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 0;
    if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x30) != 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x34) != 0)) {
        var_r2_16642 = (void *)0x030041A0 + 0x28;
        var_r4_16644 = (void *)0x030041A0 + 0x30;
        var_r5_16645 = 1;
        do {
            temp_r1_16649 = *var_r4_16644 - M2C_FIELD((void *)0x030041A0, s32 *, 0);
            *var_r2_16642 = temp_r1_16649;
            if (temp_r1_16649 < 0) {
                *var_r2_16642 = 0;
            }
            var_r2_16642 += 4;
            var_r4_16644 += 4;
            var_r5_16645 -= 1;
        } while (var_r5_16645 >= 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x30) + 0x500);
        *(s8 *)0x03004239 = 0x40;
        if ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x28) > (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x2C)) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x34);
            *(s8 *)0x03004239 = 0x30;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x34) + 0xA00);
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = 0;
    } else {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x30) + 0x500);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x40;
        temp_r0_16698 = M2C_FIELD((void *)0x030041A0, s32 *, 0x34);
        if (temp_r0_16698 != 0) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r0_16698;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x30;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x34) + 0xA00);
        }
        temp_r0_16710 = M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = temp_r0_16710;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
        temp_r0_16715 = temp_r0_16710 - M2C_FIELD((void *)0x030041A0, s32 *, 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r0_16715;
        if (temp_r0_16715 < 0) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (0 - temp_r0_16715);
        }
        temp_r2_16722 = M2C_FIELD((void *)0x030041A0, s32 *, 0x1C);
        temp_r0_16723 = M2C_FIELD((void *)0x030041A0, s32 *, 4);
        temp_r1_16724 = temp_r2_16722 - temp_r0_16723;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = temp_r1_16724;
        if (temp_r1_16724 < 0) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (0 - temp_r1_16724);
        }
        if (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10) <= 0xFFF) && ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14) <= 0xFFF)) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x18);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = temp_r2_16722;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = 0;
        } else {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = 0;
            if (M2C_FIELD(arg0, u8 *, 0x24) != 0) {
                M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0x10000;
            }
            if ((s32) (M2C_FIELD(arg0, s32 *, 4) << 8) > temp_r0_16723) {
                temp_r4_16767 = (u8) M2C_FIELD(arg0, u16 *, 0xE) - 0x10;
                M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x10) | (((0xF & temp_r4_16767) << 0xC) + 0x800));
                var_r0_16781 = ((temp_r4_16767 & 0xF0) << 8) + 0x0FFFF400;
            } else {
                temp_r4_16789 = (u8) M2C_FIELD(arg0, u16 *, 0xE) + 0x10;
                M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x10) | (((0xF & temp_r4_16789) << 0xC) + 0x800));
                var_r0_16781 = ((temp_r4_16789 & 0xF0) << 8) + 0x800;
            }
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = var_r0_16781;
        }
    }
    return 1;
}

void sub_0202029C(void *arg0) {
    u16 sp0;
    s32 sp4;
    s32 sp8;
    void *spC;
    s32 *var_r5_16987;
    s32 temp_r0_16886;
    s32 temp_r1_16833;
    s32 temp_r1_16896;
    s32 temp_r1_16921;
    s32 temp_r1_16923;
    s32 temp_r1_16933;
    s32 temp_r2_16962;
    s32 temp_r4_16995;
    s32 temp_r6_16831;
    s32 temp_r7_16830;
    s32 var_r8_16989;
    u16 *temp_r2_17001;
    u16 *temp_r2_17007;
    u16 *var_r6_16985;
    u16 temp_r0_17017;
    u16 temp_r2_16826;
    u16 temp_r3_16883;
    u8 temp_r2_16837;
    void *temp_r3_16992;
    void *var_r7_16984;

    spC = arg0;
    temp_r2_16826 = M2C_FIELD(spC, u16 *, 0xE);
    temp_r7_16830 = 0xF & temp_r2_16826;
    temp_r6_16831 = temp_r7_16830 + 1;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x28) = temp_r6_16831;
    temp_r1_16833 = temp_r6_16831 << 0xC;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x30) = temp_r1_16833;
    temp_r2_16837 = M2C_FIELD(arg0, u8 *, 0x24);
    if (temp_r2_16837 == 0) {
        sp4 = 0x0600A000;
        M2C_FIELD(&sp0, u16 *, 0) = *(0x03003720 + (((0xF0 & temp_r2_16826) + temp_r6_16831) * 2));
        if (temp_r6_16831 == 0x10) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x28) = (s32) temp_r2_16837;
            sp4 = 0x0600A800;
            M2C_FIELD(&sp0, u16 *, 0) = *(0x03003920 + ((0xF0 & temp_r2_16826) * 2));
            M2C_FIELD((void *)0x030041A0, s32 *, 0x30) = 0x10000;
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x28) = (s32) ((0xF0 & temp_r2_16826) + M2C_FIELD((void *)0x030041A0, s32 *, 0x28));
        temp_r3_16883 = M2C_FIELD(spC, u16 *, 0xE);
        temp_r0_16886 = (0xF & temp_r3_16883) - 1;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) = temp_r0_16886;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = (s32) (temp_r0_16886 << 0xC);
        M2C_FIELD(&sp4, s32 *, 4) = 0x0600A000;
        temp_r1_16896 = (0xF0 & temp_r3_16883) + temp_r0_16886;
        M2C_FIELD(&sp0, u16 *, 2) = (u16) *(0x03003720 + (temp_r1_16896 * 2));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) = temp_r1_16896;
    } else {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x30) = (s32) (temp_r1_16833 | 0x10000);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = 0x10000;
        sp4 = 0x0600A800;
        temp_r1_16921 = temp_r2_16826 & 0xF0;
        temp_r1_16923 = temp_r1_16921 + temp_r6_16831;
        M2C_FIELD(&sp0, u16 *, 0) = *(0x03003920 + (temp_r1_16923 * 2));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x28) = temp_r1_16923;
        temp_r1_16933 = temp_r7_16830 - 1;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) = temp_r1_16933;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = (s32) ((temp_r1_16933 << 0xC) | 0x10000);
        M2C_FIELD(&sp4, s32 *, 4) = 0x0600A800;
        M2C_FIELD(&sp0, u16 *, 2) = (u16) *(0x03003920 + ((temp_r1_16921 + temp_r1_16933) * 2));
        if ((u8) temp_r1_16933 == 0xFF) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) = 0xF;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = 0;
            sp8 = 0x0600A000;
            temp_r2_16962 = M2C_FIELD((void *)0x030041A0, s32 *, 0x2C);
            M2C_FIELD(&sp0, u16 *, 2) = (u16) *(0x03003720 + (((0xF0 & temp_r2_16826) + temp_r2_16962) * 2));
            M2C_FIELD((void *)0x030041A0, s32 *, 0x34) = (s32) (temp_r2_16962 << 0xC);
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x2C) + temp_r1_16921);
    }
    var_r7_16984 = NULL;
    var_r6_16985 = &sp0;
    var_r5_16987 = (void *)0x030041A0 + 0x30;
    var_r8_16989 = 1;
    do {
        temp_r3_16992 = var_r7_16984 + sp;
        temp_r4_16995 = var_r7_16984 + 0x030041C8;
        temp_r2_17001 = M2C_FIELD(temp_r3_16992, u16 **, 4) + ((*(0x030041C8 + (s32) var_r7_16984) & 0xF0) * 8);
        M2C_FIELD(temp_r3_16992, u16 **, 4) = temp_r2_17001;
        temp_r2_17007 = temp_r2_17001 + ((*(0x030041C8 + (s32) var_r7_16984) & 0xF) * 4);
        M2C_FIELD(temp_r3_16992, u16 **, 4) = temp_r2_17007;
        if ((u32) (0x3FF & *temp_r2_17007) > 0x7FU) {
            *var_r5_16987 = 0;
        }
        temp_r0_17017 = *var_r6_16985;
        if ((temp_r0_17017 == 0x7777) || (temp_r0_17017 == 0x1F) || (temp_r0_17017 == 0x20)) {
            *var_r5_16987 = 0;
        }
        var_r7_16984 += 4;
        var_r6_16985 += 2;
        var_r5_16987 += 4;
        var_r8_16989 -= 1;
    } while (var_r8_16989 >= 0);
    sub_02020118(spC, M2C_FIELD((void *)0x030041A0, s32 *, 0x30), M2C_FIELD((void *)0x030041A0, s32 *, 0x34));
}

s32 sub_02020480(M2C_UNK arg3) {
    s32 temp_r0_17203;
    s32 temp_r1_17094;
    s32 var_r4_17116;
    s32 var_r6_17103;
    u8 *var_r3_17118;
    u8 temp_r0_17081;
    u8 temp_r0_17158;
    u8 temp_r4_17174;
    void *temp_r1_17124;

    if (*(u16 *)0x0300421E != 0) {
        *(u8 *)0x03004255 = 0;
        return 0;
    }
    temp_r0_17081 = sub_0202086C();
    if (temp_r0_17081 == 0) {
        *(void *)0x03004255 = temp_r0_17081;
        goto block_21;
    }
    temp_r1_17094 = 0xF & *(u8 *)0x0300422D;
    if ((temp_r1_17094 != 0) && (temp_r1_17094 != 2) && (temp_r1_17094 != 6)) {
        goto block_21;
    }
    var_r6_17103 = 0;
    var_r4_17116 = 0;
    var_r3_17118 = (u8 *)0x03003B5D;
loop_9:
    if ((*var_r3_17118 != 1) || (temp_r1_17124 = var_r4_17116 + 0x03003C00, (M2C_FIELD(temp_r1_17124, u16 *, 0xE) != *(0x030041F0 + ((u32) ((temp_r0_17081 - 1) << 0x18) >> 0x17)))) || (M2C_FIELD(temp_r1_17124, u8 *, 0x24) != ((s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0x10000) >> 0x10))) {
        var_r4_17116 += 0x30;
        var_r3_17118 += 1;
        var_r6_17103 += 1;
        if (var_r6_17103 <= 0x1D) {
            goto loop_9;
        }
    }
    if (var_r6_17103 == 0x1E) {
        *(void *)0x03004255 = 0U;
        return 0;
    }
    temp_r0_17158 = *(void *)0x03004255;
    if (temp_r0_17158 == 0) {
        temp_r4_17174 = *(0x020338D2 + (u8) ((M2C_FIELD((void *)0x030041A0, u8 *, 0x90) * 2) + M2C_FIELD((void *)0x030041A0, u8 *, 0xA1)));
        if ((s32) temp_r4_17174 < (s32) ((s32) sub_02019AF0(&gGameState) % 101)) {
            *(void *)0x03004255 = 1U;
            goto block_21;
        }
        M2C_FIELD((void *)0x030041A0, u8 *, 0x9B) = (u8) var_r6_17103;
        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = (s16) temp_r0_17158;
        temp_r0_17203 = (s32) sub_0202029C((M2C_FIELD((void *)0x030041A0, u8 *, 0x9B) * 0x30) + 0x03003C00);
        if (temp_r0_17203 != 0) {
            M2C_FIELD(((void *)0x030041A0 + 0x8B), u8 *, 1) = (u8) M2C_FIELD((void *)0x030041A0, u8 *, 0x8B);
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 4;
            sub_020218B0();
            return 1;
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r0_17203;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = temp_r0_17203;
        M2C_FIELD((void *)0x030041A0, s16 *, 0x7E) = 0x50;
        goto block_21;
    }
block_21:
    return 0;
}

void sub_020205E0(void) {
    s32 temp_r1_17246;
    s32 temp_r1_17268;
    s32 temp_r1_17276;
    s32 temp_r1_17316;
    s32 temp_r1_17324;
    s32 temp_r2_17251;
    s32 var_r5_17292;
    s8 var_r2_17291;
    u8 temp_r0_17259;
    u8 temp_r0_17341;
    u8 temp_r2_17387;
    u8 temp_r3_17394;

    temp_r1_17246 = *(u8 *)0x0300422B * 8;
    temp_r2_17251 = M2C_FIELD((void *)0x030041A0, s32 *, 0) + *(0x02033A84 + temp_r1_17246);
    M2C_FIELD((void *)0x030041A0, s32 *, 0) = temp_r2_17251;
    M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 4) + M2C_FIELD((temp_r1_17246 + 0x02033A84), s32 *, 4));
    temp_r0_17259 = M2C_FIELD((void *)0x030041A0, u8 *, 0x9A);
    if (temp_r0_17259 != 0) {
        M2C_FIELD((void *)0x030041A0, u8 *, 0x9A) = (u8) (temp_r0_17259 - 1);
        temp_r1_17268 = 0xFFF00 & temp_r2_17251;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 8) & 0xFFF00) != temp_r1_17268) {
            M2C_FIELD((void *)0x030041A0, s32 *, 8) = temp_r1_17268;
        }
        temp_r1_17276 = M2C_FIELD((void *)0x030041A0, s32 *, 4) & 0xFFF00;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0xC) & 0xFFF00) == temp_r1_17276) {
            return;
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = temp_r1_17276;
        return;
    }
    sub_0201F538(*(u8 *)0x0300422B);
    var_r2_17291 = 0;
    var_r5_17292 = 0;
loop_8:
    if (var_r5_17292 <= 3) {
        var_r2_17291 = sub_0201F6DC(*((void *)0x030041A0 + 0x48 + (var_r5_17292 * 2)), M2C_FIELD((void *)0x030041A0, u16 **, 0x44));
        if (var_r2_17291 == 0) {
            var_r5_17292 += 1;
            goto loop_8;
        }
    }
    if (var_r5_17292 == 4) {
        temp_r1_17316 = M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFFF00;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 8) & 0xFFF00) != temp_r1_17316) {
            M2C_FIELD((void *)0x030041A0, s32 *, 8) = temp_r1_17316;
        }
        temp_r1_17324 = M2C_FIELD((void *)0x030041A0, s32 *, 4) & 0xFFF00;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0xC) & 0xFFF00) != temp_r1_17324) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = temp_r1_17324;
        }
        M2C_FIELD((void *)0x030041A0, s8 *, 0xB5) = 0;
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0xB2) != 0) {
            temp_r0_17341 = M2C_FIELD((void *)0x030041A0, u8 *, 0xB3) + 1;
            M2C_FIELD((void *)0x030041A0, u8 *, 0xB3) = temp_r0_17341;
            if ((u32) temp_r0_17341 > 0x20U) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0xB2) = 0U;
                M2C_FIELD((void *)0x030041A0, u8 *, 0xB3) = 0U;
            }
        }
    } else if (var_r2_17291 == 1) {
        if (((u32) (u8) (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) - 3) > 2U) || (*(u8 *)0x03003BAA != M2C_FIELD((void *)0x030041A0, u8 *, 0x8E)) || (*(u8 *)0x03004BA6 != 1)) {
            if (sub_02020480() == 0) {
                goto block_23;
            }
        } else {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x03003BC4, s32 *, 0) << 8);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) ((M2C_FIELD((void *)0x03003BC4, s32 *, 4) << 8) + 0x1000);
            M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x20;
            M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 0;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 4;
            sub_020218B0();
        }
    } else {
block_23:
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 8);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0xC);
        temp_r2_17387 = sub_0201F78C(1U);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = 0;
        temp_r3_17394 = M2C_FIELD((void *)0x030041A0, u8 *, 0xB2) + 1;
        M2C_FIELD((void *)0x030041A0, u8 *, 0xB2) = temp_r3_17394;
        if ((temp_r2_17387 != 0x777) && ((u32) temp_r3_17394 <= 6U)) {
            M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = temp_r2_17387;
            *(((void *)0x030041A0 + 0xB2) - 0x2B) = 2;
            sub_02021720();
            return;
        }
        M2C_FIELD((void *)0x030041A0, u8 *, 0xB2) = 0U;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0x13;
        sub_020236D0();
    }
}

void sub_02020790(void) {
    u32 var_r1_17464;

    var_r1_17464 = 0xF & *(u8 *)0x0300422D;
    if (var_r1_17464 > 4U) {
        var_r1_17464 = (u32) (u16) (var_r1_17464 - 4);
    }
    *(s8 *)0x03004228 = (var_r1_17464 * 8) + *(u8 *)0x0300422B;
}

s32 sub_020207C0(u8 arg0, s32 arg1) {
    s32 temp_r3_17492;
    s32 var_r2_17493;
    s8 *var_r1_17509;
    s8 var_r0_17510;
    u8 temp_r5_17489;

    temp_r5_17489 = arg0;
    temp_r3_17492 = *(s32 *)0x030041A0;
    var_r2_17493 = arg1 - temp_r3_17492;
    if (var_r2_17493 < 0) {
        var_r2_17493 = 0 - var_r2_17493;
    }
    if (var_r2_17493 > 0x100) {
        if (arg1 > temp_r3_17492) {
            *(s32 *)0x030041A0 = temp_r3_17492 + 0x40;
            if (temp_r5_17489 == 0) {
                var_r1_17509 = (s32 *)0x030041A0 + 0x8B;
                var_r0_17510 = 6;
                goto block_8;
            }
        } else {
            *(s32 *)0x030041A0 = temp_r3_17492 - 0x40;
            if (temp_r5_17489 == 0) {
                var_r1_17509 = (s32 *)0x030041A0 + 0x8B;
                var_r0_17510 = 2;
block_8:
                *var_r1_17509 = var_r0_17510;
            }
        }
        return 0;
    }
    return 1;
}

s32 sub_02020814(u8 arg0, s32 arg1) {
    s32 temp_r3_17542;
    s32 var_r2_17543;
    u8 temp_r1_17539;

    temp_r1_17539 = arg0;
    temp_r3_17542 = M2C_FIELD((void *)0x030041A0, s32 *, 4);
    var_r2_17543 = arg1 - temp_r3_17542;
    if (var_r2_17543 < 0) {
        var_r2_17543 = 0 - var_r2_17543;
    }
    if (var_r2_17543 > 0x100) {
        if (arg1 > temp_r3_17542) {
            M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (temp_r3_17542 + 0x40);
            if (temp_r1_17539 == 0) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = temp_r1_17539;
            }
        } else {
            M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (temp_r3_17542 - 0x40);
            if (temp_r1_17539 == 0) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = 4U;
            }
        }
        return 0;
    }
    return 1;
}

u8 sub_0202086C(void) {
    s32 var_r2_17590;
    u16 temp_r1_17596;

    var_r2_17590 = 0;
loop_1:
    temp_r1_17596 = *(0x030041E8 + (var_r2_17590 * 2));
    if (((u32) (u16) (temp_r1_17596 - 0x22) <= 3U) || ((u32) (u16) (temp_r1_17596 - 0x27) <= 4U) || ((u32) (u16) (temp_r1_17596 - 0x31) <= 3U) || (temp_r1_17596 == 0x36)) {
        return var_r2_17590 + 1;
    }
    var_r2_17590 += 1;
    if (var_r2_17590 > 3) {
        return 0U;
    }
    goto loop_1;
}

s32 sub_020208BC(s32 arg0) {
    s32 temp_r1_17668;
    s32 var_r0_17681;
    s32 var_r1_17683;
    s32 var_r5_17725;
    u16 temp_r3_17698;
    u16 temp_r6_17713;
    u8 temp_r3_17642;

    temp_r3_17642 = *(u8 *)0x0300422E;
    if (((s32) *(*(s32 *)0x03001B40 + 0x18F8 + (((temp_r3_17642 >> 4) * 2) + ((u32) (arg0 << 0x18) >> 0x13))) >> (0xF & temp_r3_17642)) & 1) {
        if ((*(u16 *)0x03004218 == 0) && ((temp_r1_17668 = 0xF & *(u8 *)0x0300422D, (temp_r1_17668 == 3)) || (temp_r1_17668 == 7))) {
            if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
                var_r0_17681 = *(u8 *)0x0300422E * 2;
                var_r1_17683 = 0x03003720;
            } else {
                var_r0_17681 = *(u8 *)0x0300422E * 2;
                var_r1_17683 = 0x03003920;
            }
            temp_r3_17698 = *(var_r0_17681 + var_r1_17683);
            if (temp_r3_17698 != 0xFFF) {
                temp_r6_17713 = temp_r3_17698 & 0x8000;
                if ((temp_r6_17713 == 0) && (temp_r3_17698 != 0x3333) && (temp_r3_17698 != 0x7777) && (M2C_FIELD(((temp_r3_17698 * 0xC) + 0x0202F7FC), u16 *, 8) != 0xFFF)) {
                    var_r5_17725 = 0x32;
                    if (M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) == 1) {
                        var_r5_17725 = 0x19;
                    }
                    if ((var_r5_17725 >= (s32) ((s32) sub_02019AF0(&gGameState) % 101)) && ((sub_0201F0FC(0xF1U) << 0x10) != 0)) {
                        M2C_FIELD((void *)0x030041A0, s32 *, 8) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
                        M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
                        M2C_FIELD((void *)0x030041A0, u16 *, 0x7C) = temp_r6_17713;
                        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
                        M2C_FIELD(((void *)0x030041A0 + 0x6E), s8 *, 0x19) = 4;
                        sub_020218B0();
                        return 2;
                    }
                    goto block_17;
                }
            }
            goto block_17;
        }
block_17:
        return 1;
    }
    return 0;
}

void sub_020209E0(void) {
    u16 temp_r0_17787;

    temp_r0_17787 = *(0x020338C4 + (*(u8 *)0x03004233 * 2));
    *(s8 *)0x03004230 = (s8) temp_r0_17787;
    sub_02026C7C((u8) (temp_r0_17787 + 1));
}

void sub_02020A0C(void *arg0, u16 arg1) {
    u16 temp_r1_17803;
    void *temp_r0_17805;

    temp_r1_17803 = arg1;
    M2C_FIELD(arg0, u16 *, 0) = temp_r1_17803;
    temp_r0_17805 = arg0 + 2;
    M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_r1_17803 + 1);
    M2C_FIELD(temp_r0_17805, s16 *, 0x3E) = (s16) (temp_r1_17803 + 2);
    M2C_FIELD((temp_r0_17805 + 0x3E), s16 *, 2) = (s16) (temp_r1_17803 + 3);
}

u16 sub_02020A24(s32 arg0) {
    s32 var_r3_17834;
    u16 *var_r1_17835;
    u16 *var_r2_17839;

    if (((u32) (arg0 - 3) <= 4U) || (arg0 == 0x1E)) {
        *(s16 *)0x0300421C = 0x3260;
        if (arg0 == 0x1E) {
            *(s16 *)0x0300421C = 0x3268;
        }
        var_r3_17834 = 0;
        var_r1_17835 = (u16 *)0x02033A6C;
        if (*(u16 *)0x02033A6C != arg0) {
            var_r2_17839 = (u16 *)0x02033A6C;
loop_6:
            var_r2_17839 += 4;
            var_r3_17834 += 1;
            if (var_r3_17834 <= 5) {
                var_r1_17835 = var_r2_17839;
                if (*var_r1_17835 != arg0) {
                    goto loop_6;
                }
            }
        }
        return M2C_FIELD(var_r1_17835, u16 *, 2);
    }
    return 0U;
}

s32 sub_02020A78(void) {
    s32 var_r0_17916;
    s32 var_r0_17961;
    s32 var_r1_17918;
    s32 var_r1_17963;
    s32 var_r8_17871;
    s8 *var_r2_17959;
    s8 temp_r2_17906;
    u16 *temp_r2_17933;
    u32 temp_r1_17877;
    u32 var_r5_17876;
    u32 var_r5_17887;

    var_r8_17871 = 0;
    var_r5_17876 = 0xF & *(u8 *)0x0300422D;
    temp_r1_17877 = var_r5_17876;
    if (var_r5_17876 > 4U) {
        var_r5_17876 = (u32) (u16) (var_r5_17876 - 4);
    }
    var_r5_17887 = (u32) ((var_r5_17876 << 0x11) + 0x80430000) >> 0x10;
    if (temp_r1_17877 > 4U) {
        var_r5_17887 = (u32) (u16) (var_r5_17887 + 1);
    }
    if (sub_0201F368() != 0) {
        sub_0201F538(*(u8 *)0x0300422B);
        temp_r2_17906 = sub_0201F6DC((u16) *(u8 *)0x0300422E, M2C_FIELD((void *)0x030041A0, u16 **, 0x44));
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            if (temp_r2_17906 == 0) {
                var_r0_17916 = *(u8 *)0x0300422E * 2;
                var_r1_17918 = 0x03003720;
                goto block_10;
            }
        } else if (temp_r2_17906 == 0) {
            var_r0_17916 = *(u8 *)0x0300422E * 2;
            var_r1_17918 = 0x03003920;
block_10:
            temp_r2_17933 = var_r0_17916 + var_r1_17918;
            if (*temp_r2_17933 == 0xFFF) {
                *temp_r2_17933 = (u16) var_r5_17887;
                var_r8_17871 = 1;
            }
        }
        if (var_r8_17871 == 1) {
            sub_0201F660(M2C_FIELD((void *)0x030041A0, s32 *, 0), *(u8 *)0x0300422E, M2C_FIELD((void *)0x030041A0, u16 *, 0x72), 0x6234U);
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x85) == 0) {
                var_r2_17959 = (void *)0x030041A0 + 0x86;
                var_r0_17961 = M2C_FIELD((void *)0x030041A0, u8 *, 0x86) * 2;
                var_r1_17963 = 0x03003720;
            } else {
                var_r2_17959 = (void *)0x030041A0 + 0x86;
                var_r0_17961 = M2C_FIELD((void *)0x030041A0, u8 *, 0x86) * 2;
                var_r1_17963 = 0x03003920;
            }
            *(var_r1_17963 + var_r0_17961) = 0xFFF;
            *var_r2_17959 = 0;
            M2C_FIELD((void *)0x030041A0, u8 *, 0x85) = 0U;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 0;
            M2C_FIELD((void *)0x030041A0, u16 *, 0x72) = 0U;
            sub_02020790();
            return 1;
        }
        goto block_17;
    }
block_17:
    return 0;
}

void sub_02020B88(void) {
    s16 *temp_r1_18121;
    s16 *var_r0_18161;
    s16 *var_r1_18163;
    s32 var_r2_18139;
    s32 var_r2_18164;
    void *temp_r1_18026;
    void *temp_r1_18031;
    void *temp_r1_18033;
    void *temp_r1_18035;
    void *temp_r1_18037;
    void *temp_r1_18039;
    void *temp_r1_18041;
    void *temp_r1_18043;
    void *temp_r1_18047;
    void *temp_r1_18051;
    void *temp_r1_18053;
    void *temp_r1_18055;
    void *temp_r1_18057;
    void *temp_r1_18059;
    void *temp_r1_18061;
    void *temp_r1_18063;
    void *temp_r1_18065;
    void *temp_r1_18070;
    void *temp_r1_18072;
    void *temp_r1_18074;
    void *temp_r1_18076;
    void *temp_r1_18080;
    void *temp_r1_18082;
    void *temp_r1_18084;
    void *temp_r1_18088;
    void *temp_r1_18090;
    void *temp_r1_18094;
    void *temp_r1_18096;
    void *temp_r1_18098;
    void *temp_r1_18105;
    void *temp_r1_18107;
    void *temp_r1_18109;
    void *temp_r1_18113;
    void *temp_r1_18115;
    void *temp_r1_18117;
    void *var_r3_18021;

    M2C_FIELD((void *)0x030041A0, s32 *, 0) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 4) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 8) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x38) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = 0;
    var_r3_18021 = (void *)0x030041A0 + 0x48;
    M2C_FIELD((void *)0x030041A0, s16 *, 0x48) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x44) = 0;
    temp_r1_18026 = (void *)0x030041A0 + 0x85;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x85) = 0;
    M2C_FIELD(temp_r1_18026, s8 *, 1) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
    temp_r1_18031 = (temp_r1_18026 + 1) - 0x2E;
    M2C_FIELD(temp_r1_18031, s16 *, 0) = 0;
    temp_r1_18033 = temp_r1_18031 + 0x2F;
    M2C_FIELD(temp_r1_18031, s8 *, 0x2F) = 0;
    temp_r1_18035 = temp_r1_18033 + 1;
    M2C_FIELD(temp_r1_18033, s8 *, 1) = 0;
    temp_r1_18037 = temp_r1_18035 + 1;
    M2C_FIELD(temp_r1_18035, s8 *, 1) = 0;
    temp_r1_18039 = temp_r1_18037 + 1;
    M2C_FIELD(temp_r1_18037, s8 *, 1) = 0;
    temp_r1_18041 = temp_r1_18039 + 1;
    M2C_FIELD(temp_r1_18039, s8 *, 1) = 0;
    temp_r1_18043 = temp_r1_18041 + 1;
    M2C_FIELD(temp_r1_18041, s8 *, 1) = 0;
    M2C_FIELD(temp_r1_18043, s8 *, 1) = 0;
    temp_r1_18047 = (temp_r1_18043 + 1) - 0x1B;
    M2C_FIELD(temp_r1_18047, s16 *, 0) = 0;
    M2C_FIELD(temp_r1_18047, s8 *, 0x1C) = 0;
    temp_r1_18051 = (temp_r1_18047 + 0x1C) - 0x14;
    M2C_FIELD(temp_r1_18051, s16 *, 0) = 0;
    temp_r1_18053 = temp_r1_18051 + 0x15;
    M2C_FIELD(temp_r1_18051, s8 *, 0x15) = 0;
    temp_r1_18055 = temp_r1_18053 + 1;
    M2C_FIELD(temp_r1_18053, s8 *, 1) = 0;
    temp_r1_18057 = temp_r1_18055 + 1;
    M2C_FIELD(temp_r1_18055, s8 *, 1) = 0;
    temp_r1_18059 = temp_r1_18057 + 1;
    M2C_FIELD(temp_r1_18057, s8 *, 1) = 0;
    temp_r1_18061 = temp_r1_18059 + 1;
    M2C_FIELD(temp_r1_18059, s8 *, 1) = 0;
    temp_r1_18063 = temp_r1_18061 + 1;
    M2C_FIELD(temp_r1_18061, s8 *, 1) = 0;
    temp_r1_18065 = temp_r1_18063 + 1;
    M2C_FIELD(temp_r1_18063, s8 *, 1) = 0;
    M2C_FIELD((void *)0x030041A0, u8 *, 0x96) = 0U;
    temp_r1_18070 = temp_r1_18065 + 2;
    M2C_FIELD(temp_r1_18065, s8 *, 2) = 0;
    temp_r1_18072 = temp_r1_18070 + 1;
    M2C_FIELD(temp_r1_18070, s8 *, 1) = 0;
    temp_r1_18074 = temp_r1_18072 + 1;
    M2C_FIELD(temp_r1_18072, s8 *, 1) = 0;
    temp_r1_18076 = temp_r1_18074 + 1;
    M2C_FIELD(temp_r1_18074, s8 *, 1) = 0;
    M2C_FIELD(temp_r1_18076, s8 *, 1) = 0;
    temp_r1_18080 = (temp_r1_18076 + 1) - 0x2D;
    M2C_FIELD(temp_r1_18080, s16 *, 0) = 0;
    temp_r1_18082 = temp_r1_18080 + 2;
    M2C_FIELD(temp_r1_18080, s16 *, 2) = 0;
    temp_r1_18084 = temp_r1_18082 + 0x2C;
    M2C_FIELD(temp_r1_18082, s8 *, 0x2C) = 0;
    M2C_FIELD(temp_r1_18084, s8 *, 1) = 0;
    temp_r1_18088 = (temp_r1_18084 + 1) - 0x29;
    M2C_FIELD(temp_r1_18088, s16 *, 0) = 0;
    temp_r1_18090 = temp_r1_18088 + 0x2A;
    M2C_FIELD(temp_r1_18088, s8 *, 0x2A) = 0;
    M2C_FIELD(temp_r1_18090, s8 *, 1) = 0;
    temp_r1_18094 = (temp_r1_18090 + 1) - 0x23;
    M2C_FIELD(temp_r1_18094, s16 *, 0) = 0;
    temp_r1_18096 = temp_r1_18094 + 4;
    M2C_FIELD(temp_r1_18094, s16 *, 4) = 0;
    temp_r1_18098 = temp_r1_18096 + 4;
    M2C_FIELD(temp_r1_18096, s8 *, 4) = 0;
    M2C_FIELD(temp_r1_18098, s8 *, 0x1C) = 0;
    M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) = 0U;
    temp_r1_18105 = (temp_r1_18098 + 0x1C) - 0x1E;
    M2C_FIELD(temp_r1_18105, s16 *, 0) = 0;
    temp_r1_18107 = temp_r1_18105 + 0x30;
    M2C_FIELD(temp_r1_18105, s8 *, 0x30) = 0;
    temp_r1_18109 = temp_r1_18107 + 2;
    M2C_FIELD(temp_r1_18107, s8 *, 2) = 0;
    M2C_FIELD(temp_r1_18109, s8 *, 1) = 0;
    temp_r1_18113 = (temp_r1_18109 + 1) - 2;
    M2C_FIELD(temp_r1_18113, s8 *, 0) = 0;
    temp_r1_18115 = temp_r1_18113 + 3;
    M2C_FIELD(temp_r1_18113, s8 *, 3) = 0;
    temp_r1_18117 = temp_r1_18115 + 1;
    M2C_FIELD(temp_r1_18115, s8 *, 1) = 0;
    M2C_FIELD(temp_r1_18117, s8 *, 1) = 0;
    temp_r1_18121 = (temp_r1_18117 + 1) - 0x40;
    *temp_r1_18121 = 0x78;
    *(temp_r1_18121 - 2) = 0x2A30;
    M2C_FIELD((void *)0x030041A0, u8 *, 0x96) = (u8) M2C_FIELD(*(void **)0x03001B40, s32 *, 0x1944);
    M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) = (u8) *(0x02033F92 + M2C_FIELD((void *)0x030041A0, u8 *, 0x96));
    var_r2_18139 = 3;
    do {
        M2C_FIELD(var_r3_18021, s16 *, 0) = 0;
        M2C_FIELD(var_r3_18021, s16 *, 8) = 0;
        var_r3_18021 += 2;
        var_r2_18139 -= 1;
    } while (var_r2_18139 >= 0);
    var_r0_18161 = (void *)0x030041A0 + 0x64;
    var_r1_18163 = (void *)0x030041A0 + 0x5A;
    var_r2_18164 = 4;
    do {
        *var_r1_18163 = 0;
        *var_r0_18161 = 0;
        var_r0_18161 += 2;
        var_r1_18163 += 2;
        var_r2_18164 -= 1;
    } while (var_r2_18164 >= 0);
    *(s8 *)0x03004233 = 3;
    sub_020209E0();
    sub_02026C7C((u8) (M2C_FIELD((void *)0x030041A0, u8 *, 0x90) + 1));
    sub_02026BD8();
    M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = 0xFE;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x88) = 0x60;
    *(s8 *)0x03004227 = 0;
}

s32 sub_02020D20(void) {
    s32 temp_r0_18246;
    s32 temp_r1_18212;
    s32 temp_r1_18220;
    s32 temp_r2_18233;
    u16 temp_r2_18225;

    temp_r1_18212 = *(u8 *)0x03004236 * 7;
    *(s32 *)0x03000020 = temp_r1_18212;
    temp_r1_18220 = temp_r1_18212 + *(0x02033DC8 + *(u8 *)0x03003B26);
    *(s32 *)0x03000020 = temp_r1_18220;
    temp_r2_18225 = *(0x02033DE4 + (temp_r1_18220 * 2));
    *(s32 *)0x03000020 = (s32) temp_r2_18225;
    temp_r2_18233 = temp_r2_18225 + *(0x02033DE0 + *(u8 *)0x03004230);
    *(s32 *)0x03000020 = temp_r2_18233;
    if ((0xF & *(u8 *)0x0300422D) == 5) {
        *(s32 *)0x03000020 = temp_r2_18233 + 0x14;
    }
    temp_r0_18246 = *(s32 *)0x03000020;
    if (temp_r0_18246 > 0x9F) {
        return 0;
    }
    if (temp_r0_18246 > 0xA0) {
        *(s32 *)0x03000020 = 0;
    }
    return *(s32 *)0x03000020;
}

void sub_02020DA8(void) {
    s32 temp_r0_18314;
    s32 temp_r0_18378;
    s32 temp_r0_18435;
    s32 temp_r1_18307;
    s32 temp_r1_18322;
    s32 temp_r1_18416;
    s32 temp_r2_18424;
    s32 var_r0_18335;
    s32 var_r4_18368;
    s32 var_r4_18449;
    u16 *var_r5_18367;
    u16 *var_r7_18365;
    u16 temp_r0_18284;
    u16 temp_r6_18403;
    u16 var_r0_18371;
    u16 var_r1_18370;
    void *temp_r4_18324;
    void *temp_r6_18309;
    void *var_r6_18363;

    if (*(u8 *)0x03004227 == 0x10) {
        return;
    }
    temp_r0_18284 = *(u16 *)0x03004216;
    if (temp_r0_18284 != 0) {
        *(u16 *)0x03004216 = temp_r0_18284 - 1;
        return;
    }
    if ((*(u16 *)0x03004202 == 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x38) == 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) == 0)) {
        temp_r1_18307 = sub_02020D20() * 4;
        temp_r6_18309 = temp_r1_18307 + 0x02033B48;
        temp_r0_18314 = sub_0201FF48(0U, 1U, *(0x02033B48 + temp_r1_18307), M2C_FIELD(temp_r6_18309, u16 *, 2));
        if (temp_r0_18314 == 0) {
            return;
        }
        temp_r1_18322 = 0x54 * temp_r0_18314;
        temp_r4_18324 = temp_r1_18322 + 0x03004790;
        if (!(1 & sub_02019AF0(&gGameState))) {
            *(0x03004790 + temp_r1_18322) = 0x10;
            M2C_FIELD(temp_r4_18324, s32 *, 0x18) = 0x18;
            var_r0_18335 = 0x1D1;
        } else {
            *(0x03004790 + temp_r1_18322) = 0x1D0;
            M2C_FIELD(temp_r4_18324, s32 *, 0x18) = -0x18;
            var_r0_18335 = 0xF;
        }
        M2C_FIELD(temp_r4_18324, s32 *, 0x14) = var_r0_18335;
        M2C_FIELD(temp_r4_18324, s32 *, 4) = (s32) ((((s32) sub_02019AF0(&gGameState) % 5) * 0x10) + 0x50);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x38) = (s32) *(0x03004790 + temp_r1_18322);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_r4_18324, s32 *, 4);
        var_r6_18363 = temp_r6_18309 + 4;
        var_r7_18365 = temp_r4_18324 + 0x34;
        var_r5_18367 = temp_r4_18324 + 0x2A;
        var_r4_18368 = 3;
        do {
            var_r1_18370 = M2C_FIELD(var_r6_18363, u16 *, 0);
            var_r0_18371 = M2C_FIELD(var_r6_18363, u16 *, 2);
            if (var_r0_18371 == 4) {
                temp_r0_18378 = ((s32) sub_02019AF0(&gGameState) % 6) * 4;
                var_r1_18370 = *(0x02033B30 + temp_r0_18378);
                var_r0_18371 = M2C_FIELD((temp_r0_18378 + 0x02033B30), u16 *, 2);
            }
            *var_r5_18367 = var_r1_18370;
            *var_r7_18365 = var_r0_18371;
            var_r7_18365 += 2;
            var_r5_18367 += 2;
            var_r4_18368 -= 1;
            var_r6_18363 += 4;
        } while (var_r4_18368 >= 0);
        return;
    }
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x87) == 3) {
        temp_r6_18403 = *(u16 *)0x03004202;
        if (temp_r6_18403 != 0) {
            M2C_FIELD((void *)0x030041A0, s8 *, 0x9E) = 0;
            return;
        }
        temp_r1_18416 = 0xF & M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
        if ((temp_r1_18416 == 1) || (temp_r1_18416 == 5)) {
            temp_r2_18424 = M2C_FIELD((void *)0x030041A0, s32 *, 0x38) - M2C_FIELD((void *)0x030041A0, s32 *, 0);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r2_18424;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) - M2C_FIELD((void *)0x030041A0, s32 *, 4));
            if (temp_r2_18424 < 0) {
                M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) (0 - temp_r2_18424);
            }
            temp_r0_18435 = M2C_FIELD((void *)0x030041A0, s32 *, 0x24);
            if (temp_r0_18435 < 0) {
                M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (0 - temp_r0_18435);
            }
            if (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x20) <= 0x1000) && ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x24) <= 0x1000)) {
                var_r4_18449 = 0x64;
                if (M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) == 1) {
                    var_r4_18449 = 0x32;
                }
                if (var_r4_18449 >= (s32) ((s32) sub_02019AF0(&gGameState) % 101)) {
                    if ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) > (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x38)) {
                        M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = (s8) temp_r6_18403;
                    } else {
                        M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = 1;
                    }
                    M2C_FIELD((void *)0x030041A0, u8 *, 0x87) = 0xFU;
                    sub_02022C30();
                }
            }
        }
    }
}

s32 sub_02020F54(void) {
    s32 temp_r1_18502;
    s32 var_r1_18543;
    s32 var_r2_18522;
    s32 var_r3_18544;
    s32 var_r4_18578;
    s32 var_r7_18492;
    s8 temp_r1_18595;
    u16 *var_r2_18542;
    u32 var_r4_18521;

    var_r7_18492 = 0;
    if ((*(u16 *)0x03004214 == 0) && ((temp_r1_18502 = 0xF & *(u8 *)0x0300422D, (temp_r1_18502 == 4)) || (temp_r1_18502 == 8))) {
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r4_18521 = (u32) ((M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) << 0x10) + 0xE0000) >> 0x10;
            var_r2_18522 = 0x0600A000;
        } else {
            var_r4_18521 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) + 0x12;
            var_r2_18522 = 0x0600A800;
        }
        var_r2_18542 = var_r2_18522 + ((0xF0 & var_r4_18521) * 8) + ((var_r4_18521 & 0xF) * 4);
        var_r1_18543 = 0;
        var_r3_18544 = 0;
        do {
            if ((0x3FF & *var_r2_18542) == 0xF6) {
                var_r3_18544 += 1;
            }
            switch (var_r1_18543) {                 /* irregular */
            case 0:
            case 2:
                var_r2_18542 += 2;
                break;
            case 1:
                var_r2_18542 += 0x3E;
                break;
            }
            var_r1_18543 += 1;
        } while (var_r1_18543 <= 3);
        if (var_r3_18544 > 3) {
            var_r7_18492 = 1;
        }
        if (var_r7_18492 != 0) {
            var_r4_18578 = 0x19;
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) == 1) {
                var_r4_18578 = 0x32;
            }
            if (var_r4_18578 > (s32) ((s32) sub_02019AF0(&gGameState) % 101)) {
                temp_r1_18595 = M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000;
                if (temp_r1_18595 == 0) {
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = temp_r1_18595;
                } else {
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = 1;
                }
                M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0xD;
                sub_0202277C();
                return 1;
            }
            goto block_25;
        }
        goto block_25;
    }
block_25:
    return 0;
}

u16 sub_02021050(void) {
    s32 var_r0_18651;
    s32 var_r2_18652;
    u8 temp_r1_18645;
    u8 temp_r1_18671;

    if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
        *(0x03003720 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2)) = 0x7777;
        temp_r1_18645 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E);
        var_r0_18651 = ((0xF & temp_r1_18645) * 2) + ((temp_r1_18645 >> 4) << 5);
        var_r2_18652 = *(s32 *)0x03001B40 + 0x24;
    } else {
        *(0x03003920 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2)) = 0x7777;
        temp_r1_18671 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E);
        var_r0_18651 = ((0xF & temp_r1_18671) * 2) + ((temp_r1_18671 >> 4) << 5);
        var_r2_18652 = *(void *)0x03001B40 + 0x224;
    }
    return *(var_r2_18652 + var_r0_18651);
}

s32 sub_020210D4(void) {
    s32 temp_r0_18796;
    s32 temp_r1_18707;
    s32 temp_r1_18716;
    s32 temp_r1_18904;
    s32 temp_r2_18813;
    s32 var_r0_18728;
    s32 var_r0_18786;
    s32 var_r0_18887;
    s32 var_r1_18726;
    s32 var_r1_18889;
    s32 var_r3_18937;
    u16 *var_r2_18938;
    u16 temp_r1_18833;
    u16 temp_r6_18743;
    u16 var_sl_18702;
    u8 *var_r2_18724;
    void *temp_r2_18846;
    void *temp_r2_18922;
    void *temp_r2_18929;
    void *temp_r5_18774;

    var_sl_18702 = 0;
    temp_r1_18707 = 0xF & *(u8 *)0x0300422D;
    if ((temp_r1_18707 != 0) && (temp_r1_18707 != 3) && (temp_r1_18707 != 7)) {
        goto block_42;
    }
    temp_r1_18716 = M2C_FIELD((void *)0x030041A0, s32 *, 0);
    if (!(0xFF0000 & temp_r1_18716)) {
        var_r2_18724 = (void *)0x030041A0 + 0x8E;
        var_r1_18726 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
        var_r0_18728 = 0x03003720;
    } else {
        var_r2_18724 = (void *)0x030041A0 + 0x8E;
        var_r1_18726 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
        var_r0_18728 = 0x03003920;
    }
    temp_r6_18743 = *(var_r0_18728 + var_r1_18726);
    if (temp_r6_18743 == 0xFFF) {
        goto block_42;
    }
    if (temp_r6_18743 & 0x8000) {
        goto block_42;
    }
    if (temp_r6_18743 == 0x7777) {
        goto block_42;
    }
    if (temp_r6_18743 == 0x3333) {
        goto block_42;
    }
    temp_r5_18774 = (temp_r6_18743 * 0xC) + 0x0202F7FC;
    if (M2C_FIELD(temp_r5_18774, u16 *, 4) == 0xFFF) {
        goto block_42;
    }
    if (!(0xFF0000 & temp_r1_18716)) {
        var_r0_18786 = 0;
    } else {
        var_r0_18786 = 1;
    }
    temp_r0_18796 = sub_020208BC(var_r0_18786);
    if (temp_r0_18796 == 2) {
        goto block_46;
    }
    if (temp_r0_18796 == 1) {
        goto block_42;
    }
    M2C_FIELD((void *)0x030041A0, u8 *, 0xB6) = 0U;
    temp_r2_18813 = 0xF & M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
    if ((temp_r2_18813 == 3) || (temp_r2_18813 == 7)) {
        if ((M2C_FIELD((void *)0x030041A0, u16 *, 0x62) == 0) && ((u32) (u16) (M2C_FIELD(temp_r5_18774, u16 *, 8) - 7) > 7U)) {
            goto block_34;
        }
        goto block_42;
    }
    temp_r1_18833 = M2C_FIELD(temp_r5_18774, u16 *, 8);
    if ((u32) (u16) (temp_r1_18833 - 5) > 1U) {
        if ((u32) (u16) (temp_r1_18833 - 7) <= 7U) {
            temp_r2_18846 = (void *)0x030041A0 + 0x72;
            M2C_FIELD((void *)0x030041A0, u16 *, 0x72) = sub_02021050();
            M2C_FIELD((void *)0x030041A0, u8 *, 0xB6) = (u8) temp_r6_18743;
            M2C_FIELD(temp_r2_18846, u8 *, 0x14) = 0U;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x85) = 0;
            M2C_FIELD(temp_r2_18846, u8 *, 0x14) = (u8) *var_r2_18724;
            if (M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000) {
                M2C_FIELD((void *)0x030041A0, s8 *, 0x85) = 1;
                goto block_35;
            }
            goto block_36;
            goto block_38;
        }
        if (M2C_FIELD((void *)0x030041A0, u16 *, 0x62) == 0) {
block_34:
            var_sl_18702 = sub_02021050();
            goto block_35;
        }
        goto block_42;
    }
block_35:
    if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
block_36:
        var_r0_18887 = *var_r2_18724 * 2;
        var_r1_18889 = 0x03003720;
    } else {
        var_r0_18887 = *var_r2_18724 * 2;
        var_r1_18889 = 0x03003920;
    }
block_38:
    *(var_r1_18889 + var_r0_18887) = 0x7777;
    temp_r1_18904 = M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r1_18904;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) (temp_r1_18904 | (((0xF & *var_r2_18724) << 0xC) + 0x800));
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (((0xF0 & *var_r2_18724) << 8) + 0x800);
    temp_r2_18922 = (void *)0x030041A0 + 0x6E;
    M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
    M2C_FIELD(temp_r2_18922, s8 *, 0x2B) = 0x10;
    temp_r2_18929 = (temp_r2_18922 + 0x2B) - 0x12;
    M2C_FIELD(temp_r2_18929, s8 *, 0) = 4;
    M2C_FIELD(temp_r2_18929, s8 *, 0x19) = 0;
    if (var_sl_18702 != 0) {
        var_r3_18937 = 0;
        var_r2_18938 = (temp_r2_18929 + 0x19) - 0x46;
loop_40:
        if (*var_r2_18938 != 0) {
            var_r2_18938 += 2;
            var_r3_18937 += 1;
            if (var_r3_18937 > 4) {
block_42:
                return 0;
            }
            goto loop_40;
        }
        *var_r2_18938 = temp_r6_18743 + 1;
        *((void *)0x030041A0 + 0x64 + (var_r3_18937 * 2)) = var_sl_18702;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x95) = (s8) var_r3_18937;
        goto block_46;
    }
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0xB6) == 0) {
        M2C_FIELD(temp_r2_18929, s8 *, 0x19) = (s8) (temp_r6_18743 + 1);
    }
block_46:
    return 1;
}

s32 sub_020212F4(void) {
    s32 temp_r1_19002;
    s32 var_r0_19024;
    s32 var_r1_19022;
    u8 *var_r2_19020;
    u8 temp_r0_18992;

    temp_r0_18992 = *(u8 *)0x03004230;
    if (((temp_r0_18992 == 3) || (temp_r0_18992 == 1)) && ((temp_r1_19002 = 0xF & *(u8 *)0x0300422D, (temp_r1_19002 == 3)) || (temp_r1_19002 == 7)) && (*(u16 *)0x03004218 == 0)) {
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r2_19020 = (void *)0x030041A0 + 0x8E;
            var_r1_19022 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
            var_r0_19024 = 0x03003720;
        } else {
            var_r2_19020 = (void *)0x030041A0 + 0x8E;
            var_r1_19022 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
            var_r0_19024 = 0x03003920;
        }
        if ((*(var_r0_19024 + var_r1_19022) == 0xFFF) && ((s32) ((s32) sub_02019AF0(&gGameState) % 101) <= 5) && (sub_0201F368() != 0) && ((sub_0201F0FC(0xF1U) << 0x10) != 0)) {
            M2C_FIELD((void *)0x030041A0, s32 *, 8) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
            M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
            M2C_FIELD((void *)0x030041A0, s8 *, 0xB7) = 0;
            M2C_FIELD((void *)0x030041A0, u8 *, 0xB8) = (u8) *var_r2_19020;
            if (M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000) {
                M2C_FIELD((void *)0x030041A0, s8 *, 0xB7) = 1;
            }
            M2C_FIELD((void *)0x030041A0, s16 *, 0x7C) = 0;
            M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
            M2C_FIELD(((void *)0x030041A0 + 0x6E), s8 *, 0x19) = 4;
            sub_020218B0();
            return 2;
        }
        goto block_15;
    }
block_15:
    return 0;
}

void sub_020213DC(void) {
    s32 temp_r0_19220;
    s32 temp_r0_19256;
    s32 var_r0_19137;
    s32 var_r0_19230;
    s32 var_r1_19139;
    s32 var_r2_19231;
    u32 temp_r3_19171;
    u32 var_r2_19175;
    u32 var_r2_19185;
    u8 temp_r1_19214;
    u8 temp_r1_19250;
    void *var_r6_19222;

    if (M2C_FIELD((void *)0x03004B80, u16 *, 0x28) != 0) {
        sub_0201F660((u8) M2C_FIELD((void *)0x03004B80, u16 *, 0x28) << 0x10, M2C_FIELD((void *)0x03004B80, u8 *, 0x29), M2C_FIELD((void *)0x03004B80, u16 *, 0x1A), *(0x0202F7FC + (*(u8 *)0x03004BA4 * 0xC)));
        if ((u8) M2C_FIELD((void *)0x03004B80, u16 *, 0x28) == 0) {
            var_r0_19137 = M2C_FIELD((void *)0x03004B80, u8 *, 0x29) * 2;
            var_r1_19139 = 0x03003720;
        } else {
            var_r0_19137 = M2C_FIELD((void *)0x03004B80, u8 *, 0x29) * 2;
            var_r1_19139 = 0x03003920;
        }
        *(var_r0_19137 + var_r1_19139) = (s16) *(u8 *)0x03004BA4;
        M2C_FIELD((void *)0x03004B80, u16 *, 0x28) = 0;
        M2C_FIELD((void *)0x03004B80, u8 *, 0x29) = 0U;
        *(s8 *)0x03003B29 = 0;
    }
    temp_r3_19171 = 0xF & *(u8 *)0x0300422D;
    if (temp_r3_19171 != 0) {
        var_r2_19175 = temp_r3_19171;
        if (var_r2_19175 > 4U) {
            var_r2_19175 = (u32) (u16) (var_r2_19175 - 4);
        }
        var_r2_19185 = (u32) ((var_r2_19175 << 0x11) + 0x80430000) >> 0x10;
        if (temp_r3_19171 > 4U) {
            var_r2_19185 = (u32) (u16) (var_r2_19185 + 1);
        }
        if (*(s32 *)0x03004224 & 0xFFFF00) {
            if (*(u8 *)0x03004225 == 0) {
                *(0x03003720 + (*(u8 *)0x03004226 * 2)) = (s16) var_r2_19185;
                temp_r1_19214 = *(u8 *)0x03004226;
                temp_r0_19220 = 0xF & temp_r1_19214;
                var_r6_19222 = ((0xF0 & temp_r1_19214) * 8) + 0x0600C000 + (temp_r0_19220 * 4);
                var_r0_19230 = (temp_r0_19220 * 2) + (((temp_r1_19214 >> 4) & 0xF) << 5);
                var_r2_19231 = *(s32 *)0x03001B40 + 0x24;
            } else {
                *(0x03003920 + (*(void *)0x03004226 * 2)) = (s16) var_r2_19185;
                temp_r1_19250 = *(void *)0x03004226;
                temp_r0_19256 = 0xF & temp_r1_19250;
                var_r6_19222 = ((0xF0 & temp_r1_19250) * 8) + 0x0600C800 + (temp_r0_19256 * 4);
                var_r0_19230 = (temp_r0_19256 * 2) + (((temp_r1_19250 >> 4) & 0xF) << 5);
                var_r2_19231 = *(void *)0x03001B40 + 0x224;
            }
            *(var_r2_19231 + var_r0_19230) = *(u16 *)0x03004212;
            sub_02020A0C(var_r6_19222, 0x6234U);
            *(u8 *)0x03004226 = 0;
            *(u8 *)0x03004225 = 0;
            *(u8 *)0x0300422D = 0;
            *(u16 *)0x03004212 = 0;
            if (*(u8 *)0x03004227 == 3) {
                sub_02020790();
            }
        }
    }
}

void sub_02021574(void) {
    u8 temp_r1_19318;

    if ((*(u8 *)0x03003BAE != 0) && ((sub_02020DA8(), temp_r1_19318 = *(u8 *)0x03004227, ((u32) (u8) (temp_r1_19318 - 9) <= 1U)) || (*(u8 *)0x03004238 == 0))) {
        if (temp_r1_19318 == 3) {
            sub_020205E0();
        }
        *(0x0203380C + (*(u8 *)0x03004227 * 4))();
    }
}

void sub_020215D0(void) {
    *(s8 *)0x0300422A = 0;
    M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x03004229, s8 *, 2) = 0;
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x88) == 0x60) {
        *(s8 *)0x0300422A = 0xFE;
    }
    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 1;
}

void sub_02021608(void) {
    s32 temp_r0_19452;
    s32 var_r5_19479;
    u8 temp_r0_19394;
    u8 temp_r0_19487;
    u8 temp_r5_19442;

    temp_r0_19394 = *(u8 *)0x0300422A;
    if (temp_r0_19394 != 0xFE) {
        if (temp_r0_19394 == 0) {
            if (*(u8 *)0x03004228 == 0x5F) {
                if (*(u8 *)0x03004229 == 8) {
                    sub_02026A38(1U);
                }
                if (*(u8 *)0x03004229 == 0x13) {
                    sub_02026A38(0xEU);
                }
            } else {
                if (*(void *)0x03004229 == 1) {
                    sub_02026A38(1U);
                }
                if (*(void *)0x03004229 == 0xB) {
                    sub_02026A38(0xEU);
                }
            }
        }
        if (sub_0201FDF4(1U) != 0) {
            temp_r5_19442 = *(void *)0x03004228;
            if (temp_r5_19442 == 0x60) {
                M2C_FIELD((void *)0x03003BC4, s8 *, 0x11) = 1;
                temp_r0_19452 = M2C_FIELD((void *)0x030041A0, s32 *, 4) + 0x1200;
                M2C_FIELD((void *)0x030041A0, s32 *, 4) = temp_r0_19452;
                M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = temp_r0_19452;
                M2C_FIELD((void *)0x030041A0, u8 *, 0x94) = temp_r5_19442;
                M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
                sub_02021720();
                M2C_FIELD((void *)0x030041A0, s8 *, 0x9A) = 0x40;
                M2C_FIELD((void *)0x030041A0, s16 *, 0x58) = (s16) temp_r5_19442;
                return;
            }
            var_r5_19479 = 4;
            do {
                if (M2C_FIELD((void *)0x030041A0, u16 *, 0x5A) != 0) {
                    temp_r0_19487 = M2C_FIELD((void *)0x030041A0, u8 *, 0x93) + 1;
                    M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = temp_r0_19487;
                    if ((u32) temp_r0_19487 > 6U) {
                        M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = 6U;
                    }
                    sub_020209E0();
                    sub_0201FE6C(0);
                }
                var_r5_19479 -= 1;
            } while (var_r5_19479 >= 0);
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = 0xFE;
            *(void *)0x03004228 = 0x60U;
            *(s8 *)0x03004227 = 0;
            M2C_FIELD((void *)0x03003BC4, s8 *, 0x11) = 1;
        }
    }
}

void sub_02021720(void) {
    s32 var_r6_19528;
    u8 temp_r0_19552;
    void *temp_r0_19535;
    void *temp_r0_19537;
    void *temp_r4_19549;

    var_r6_19528 = 0;
    *(u8 *)0x03004228 = 0;
    M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
    temp_r0_19535 = (void *)0x03004229 + 1;
    M2C_FIELD((void *)0x03004229, s8 *, 1) = 0;
    temp_r0_19537 = temp_r0_19535 + 7;
    M2C_FIELD(temp_r0_19535, s8 *, 7) = 0;
    M2C_FIELD(temp_r0_19537, s8 *, 1) = 0;
    M2C_FIELD((temp_r0_19537 + 1), s8 *, 5) = 0;
    sub_02020790();
    temp_r4_19549 = **(0x02033680 + (*(u8 *)0x03004228 * 4));
    temp_r0_19552 = *(u8 *)0x03004230;
    if ((s32) temp_r0_19552 <= 2) {
        if ((s32) temp_r0_19552 < 1) {
            if (temp_r0_19552 != 0) {

            } else {
                goto block_5;
            }
        } else {
            var_r6_19528 = 0x100;
        }
    } else if (temp_r0_19552 == 3) {
block_5:
        var_r6_19528 = 0x180;
    }
    M2C_FIELD((void *)0x030041F8, s16 *, 0) = (s16) (var_r6_19528 + ((s32) sub_02019AF0(&gGameState) % 337));
    M2C_FIELD((void *)0x030041F8, s8 *, 0x32) = (s8) M2C_FIELD(temp_r4_19549, u16 *, 4);
    *(((void *)0x030041F8 + 0x32) - 3) = 3;
}

void sub_020217AC(void) {
    s32 temp_r0_19664;
    u16 temp_r0_19603;
    u16 temp_r0_19611;
    u16 temp_r0_19627;
    u16 temp_r0_19699;
    u16 temp_r1_19642;
    u8 temp_r0_19619;
    u8 temp_r0_19703;

    sub_0201FCB0();
    temp_r0_19603 = *(u16 *)0x0300421E;
    if (temp_r0_19603 != 0) {
        *(u16 *)0x0300421E = temp_r0_19603 - 1;
    }
    temp_r0_19611 = *(u16 *)0x03004218;
    if (temp_r0_19611 != 0) {
        *(u16 *)0x03004218 = temp_r0_19611 - 1;
    }
    temp_r0_19619 = *(u8 *)0x03004234;
    if (temp_r0_19619 != 0) {
        *(u8 *)0x03004234 = temp_r0_19619 - 1;
    }
    temp_r0_19627 = *(u16 *)0x03004214;
    if (temp_r0_19627 != 0) {
        *(u16 *)0x03004214 = temp_r0_19627 - 1;
    }
    if (0xF & *(u8 *)0x0300422D) {
        temp_r1_19642 = *(u16 *)0x03004222;
        if ((u32) temp_r1_19642 > 0x1C20U) {
            if (sub_02020A78() != 0) {
                *(u16 *)0x03004222 = 0;
            }
        } else {
            *(u16 *)0x03004222 = temp_r1_19642 + 1;
        }
    }
    if ((sub_020210D4() == 0) && (sub_02020F54() == 0) && (temp_r0_19664 = sub_020212F4(), (temp_r0_19664 == 0))) {
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x10) != 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x14) != 0) && (sub_0201FD1C() != 0)) {
            if ((u32) M2C_FIELD((void *)0x030041A0, u16 *, 0x58) <= 0x5FU) {
                M2C_FIELD((void *)0x030041A0, u16 *, 0x58) = 0x60U;
            }
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = temp_r0_19664;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = temp_r0_19664;
        }
        if ((M2C_FIELD((void *)0x030041A0, u8 *, 0x90) != 3) || (M2C_FIELD((void *)0x030041A0, s32 *, 0x14) == 0)) {
            temp_r0_19699 = M2C_FIELD((void *)0x030041A0, u16 *, 0x58);
            if (temp_r0_19699 == 0) {
                temp_r0_19703 = sub_0201F78C(0U);
                if (temp_r0_19703 != 0x777) {
                    M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) = temp_r0_19703;
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
                    sub_02021720();
                    return;
                }
                goto block_28;
            }
            M2C_FIELD((void *)0x030041A0, u16 *, 0x58) = (u16) (temp_r0_19699 - 1);
            goto block_28;
        }
block_28:
        sub_0201FDF4(0U);
    }
}

void sub_020218B0(void) {
    s16 var_r7_19740;
    s32 temp_r1_19742;
    s32 temp_r1_19752;
    s32 temp_r1_19873;
    s32 temp_r1_19902;
    s8 *var_r1_19879;
    s8 var_r0_19880;
    u8 temp_r0_19790;
    u8 temp_r1_19774;
    void *var_r6_19739;

    var_r6_19739 = NULL;
    var_r7_19740 = 0;
    sub_0201FCB0();
    temp_r1_19742 = M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
    if (temp_r1_19742 & 0xFFFF0000) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (u16) temp_r1_19742;
    }
    temp_r1_19752 = M2C_FIELD((void *)0x030041A0, s32 *, 0x1C);
    if (temp_r1_19752 & 0xFFFF0000) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = (s32) (u16) temp_r1_19752;
    }
    if (sub_0201F3F8(M2C_FIELD((void *)0x030041A0, s32 *, 0x10), M2C_FIELD((void *)0x030041A0, s32 *, 0x14), M2C_FIELD((void *)0x030041A0, u8 *, 0x6E)) == 0) {
        goto block_49;
    }
    temp_r1_19774 = M2C_FIELD((void *)0x030041A0, u8 *, 0x99);
    if ((temp_r1_19774 == 0x30) || (temp_r1_19774 == 0x40)) {
        var_r6_19739 = (M2C_FIELD((void *)0x030041A0, u8 *, 0x9B) * 0x30) + 0x03003C00;
    }
    temp_r0_19790 = M2C_FIELD((void *)0x030041A0, u8 *, 0x99);
    switch (temp_r0_19790) {                        /* irregular */
    case 0x70:
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = 1;
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x18) == 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) == 0)) {
block_45:
            M2C_FIELD((void *)0x030041A0, u8 *, 0x6E) = (s16) M2C_FIELD((void *)0x030041A0, s32 *, 0x1C);
            M2C_FIELD((void *)0x030041A0, u8 *, 0x99) = 0U;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0x11;
            sub_02022F28();
        } else {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x18);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x1C);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = 0;
            var_r7_19740 = 1;
        }
    default:
block_47:
        if (var_r7_19740 == 0) {
            M2C_FIELD((void *)0x030041A0, u8 *, 0x6E) = var_r7_19740;
            M2C_FIELD((void *)0x030041A0, u8 *, 0x99) = 0U;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) var_r7_19740;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) var_r7_19740;
            return;
        }
block_49:
        sub_0201FDF4(0U);
        return;
    case 0x10:
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 5;
        sub_02021AD8();
        goto block_47;
    case 0x20:
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x14) + 0xFFFFF000);
        M2C_FIELD((void *)0x03003BC4, s8 *, 0x11) = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x88) = 0x5F;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0;
        sub_020215D0();
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = 4;
        goto block_47;
    case 0x30:
        M2C_FIELD(var_r6_19739, s8 *, 0x29) = 0;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x18) == 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) == 0)) {
            temp_r1_19873 = 0xF & M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
            if ((temp_r1_19873 != 2) && (temp_r1_19873 != 6)) {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x62;
            } else {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x55;
            }
block_38:
            *var_r1_19879 = var_r0_19880;
            M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
            M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0xB;
            sub_020223AC();
            goto block_47;
        }
block_42:
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x18);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x1C);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x18) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) = 0;
        goto block_49;
    case 0x40:
        M2C_FIELD(var_r6_19739, s8 *, 0x29) = 1;
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x18) == 0) && (M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) == 0)) {
            temp_r1_19902 = 0xF & M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
            if ((temp_r1_19902 != 2) && (temp_r1_19902 != 6)) {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x61;
            } else {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x54;
            }
            goto block_38;
        }
        goto block_42;
    case 0x50:
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
        sub_0201F78C(1U);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
        sub_02021720();
        goto block_47;
    case 0x60:
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8B) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x10);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x14);
        if ((M2C_FIELD((void *)0x030041A0, s32 *, 0x18) != 0) || (M2C_FIELD((void *)0x030041A0, s32 *, 0x1C) != 0)) {
            goto block_42;
        }
        goto block_45;
    }
}

void sub_02021AD8(void) {
    s32 var_r2_20071;
    u16 var_r0_20110;
    u8 *var_r4_20055;
    u8 temp_r1_20078;
    u8 var_r1_20116;
    void *temp_r1_20096;

    M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
    *(s8 *)0x0300422A = 0;
    M2C_FIELD((void *)0x03004229, s8 *, 8) = 0;
    M2C_FIELD(((void *)0x03004229 + 8), s8 *, 1) = 0;
    *(s8 *)0x03004228 = 0x56;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(void ***)0x020337D8, u16 *, 4);
    if (!(*(s32 *)0x03004224 & 0xFFFF00)) {
        var_r4_20055 = (void *)0x030041A0 + 0x8E;
        sub_0201F660(M2C_FIELD((void *)0x030041A0, s32 *, 0), M2C_FIELD((void *)0x030041A0, u8 *, 0x8E), 0U, 0x200U);
    } else {
        var_r2_20071 = 0x0600C800;
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r2_20071 = 0x0600C000;
        }
        var_r4_20055 = (void *)0x030041A0 + 0x8E;
        temp_r1_20078 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E);
        sub_02020A0C(var_r2_20071 + ((0xF0 & temp_r1_20078) * 8) + ((0xF & temp_r1_20078) * 4), 0x200U);
    }
    sub_020262DC(*var_r4_20055, M2C_FIELD((void *)0x030041A0, s32 *, 0));
    temp_r1_20096 = (void *)0x030041A0 + 0xA0;
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0xA0) == 0) {
        if (M2C_FIELD(temp_r1_20096, u8 *, 0x16) == 0) {
            var_r0_20110 = *(((temp_r1_20096 + 0x16) - 0x5C) + (M2C_FIELD((void *)0x030041A0, u8 *, 0x95) * 2));
            goto block_10;
        }
        var_r1_20116 = M2C_FIELD(temp_r1_20096, u8 *, 0x16);
    } else {
        var_r0_20110 = (u16) M2C_FIELD((void *)0x030041A0, u8 *, 0xA0);
block_10:
        var_r1_20116 = var_r0_20110 - 1;
    }
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(((var_r1_20116 * 0xC) + 0x0202F7FC), u16 *, 4) | 0x800000);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 6;
}

void sub_02021BCC(void) {
    s32 sp0;
    u8 *sp4;
    u8 *sp8;
    s32 var_r0_20271;
    s32 var_r0_20371;
    s32 var_r0_20416;
    s32 var_r1_20273;
    s32 var_r1_20373;
    s32 var_r1_20418;
    s32 var_sb_20179;
    s32 var_sb_20296;
    s8 *var_r1_20503;
    s8 *var_r6_20247;
    s8 var_r0_20504;
    u16 var_r0_20197;
    u32 temp_r0_20441;
    u8 *var_r0_20310;
    u8 *var_r2_20269;
    u8 *var_r5_20249;
    u8 temp_r1_20223;
    u8 temp_r1_20324;
    u8 temp_r1_20350;
    u8 var_r7_20203;
    void *temp_r1_20484;
    void *temp_r1_20598;
    void *temp_r2_20215;

    sp0 = 0x03003710;
    if ((*(u8 *)0x03004228 == 0x56) && (*(u8 *)0x0300422A == 0) && (*(u8 *)0x03004229 == 2)) {
        sub_02026A38(0x1DU);
    }
    if (sub_0201FDF4(1U) == 0) {
        return;
    }
    var_sb_20179 = 0;
    sp8 = (u8 *)0x03004240;
    if (*(u8 *)0x03004240 == 0) {
        if (*(u8 *)0x03004256 == 0) {
            var_r0_20197 = *(0x030041FA + (*(u8 *)0x03004235 * 2));
            goto block_11;
        }
        var_r7_20203 = *(u8 *)0x03004256;
    } else {
        var_r0_20197 = (u16) *sp8;
block_11:
        var_r7_20203 = var_r0_20197 - 1;
    }
    temp_r2_20215 = (var_r7_20203 * 0xC) + 0x0202F7FC;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(temp_r2_20215, u16 *, 4) | 0x800000);
    temp_r1_20223 = M2C_FIELD((void *)0x030041A0, u8 *, 0x88);
    sp4 = (void *)0x030041A0 + 0x88;
    switch (temp_r1_20223) {                        /* switch 1; irregular */
    case 0x58:                                      /* switch 1 */
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x86) != M2C_FIELD((void *)0x030041A0, u8 *, 0x8E)) {
                var_r0_20416 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
                var_r1_20418 = sp0 + 0x10;
                goto block_44;
            }
        } else if (M2C_FIELD((void *)0x030041A0, u8 *, 0x86) != M2C_FIELD((void *)0x030041A0, u8 *, 0x8E)) {
            var_r0_20416 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
            var_r1_20418 = sp0 + 0x210;
block_44:
            *(var_r1_20418 + var_r0_20416) = 0xFFF;
        }
        temp_r0_20441 = M2C_FIELD(temp_r2_20215, u16 *, 8) - 1;
        var_r6_20247 = (void *)0x030041A0 + 0x8A;
        var_r5_20249 = (void *)0x030041A0 + 0x89;
        switch (temp_r0_20441) {                    /* switch 2 */
        case 0:                                     /* switch 2 */
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
        case 5:                                     /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 0x59;
            var_sb_20179 = 3;
        default:                                    /* switch 1 */
block_58:
            var_r6_20247 = (void *)0x030041A0 + 0x8A;
            var_r5_20249 = (void *)0x030041A0 + 0x89;
            break;
        case 3:                                     /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x93) = 0;
            temp_r1_20484 = ((void *)0x030041A0 + 0x93) - 3;
            M2C_FIELD(temp_r1_20484, s8 *, 0) = 1;
            M2C_FIELD(temp_r1_20484, s8 *, 7) = 0x5B;
            var_sb_20179 = 1;
            goto block_58;
        case 7:                                     /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 5;
            var_sb_20179 = 2;
            goto block_58;
        case 6:                                     /* switch 2 */
            var_r1_20503 = (void *)0x030041A0 + 0x8D;
            var_r0_20504 = 1;
block_57:
            *var_r1_20503 = var_r0_20504;
            var_sb_20179 = 2;
            goto block_58;
        case 9:                                     /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 6;
            var_sb_20179 = 2;
            goto block_58;
        case 8:                                     /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 2;
            var_sb_20179 = 2;
            goto block_58;
        case 11:                                    /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 7;
            var_sb_20179 = 2;
            goto block_58;
        case 10:                                    /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 3;
            var_sb_20179 = 2;
            goto block_58;
        case 13:                                    /* switch 2 */
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8D) = 8;
            var_sb_20179 = 2;
            goto block_58;
        case 12:                                    /* switch 2 */
            var_r1_20503 = (void *)0x030041A0 + 0x8D;
            var_r0_20504 = 4;
            goto block_57;
        }
        break;
    case 0x56:                                      /* switch 1 */
        *sp4 = 0x58;
        var_r6_20247 = (void *)0x030041A0 + 0x8A;
        var_r5_20249 = (void *)0x030041A0 + 0x89;
        if (*sp8 == 0) {

        } else {
            *sp4 = 0x57;
            sub_02026A38(0x19U);
        }
        break;
    case 0x57:                                      /* switch 1 */
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
            var_r2_20269 = (void *)0x030041A0 + 0x8E;
            var_r0_20271 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
            var_r1_20273 = sp0 + 0x10;
        } else {
            var_r2_20269 = (void *)0x030041A0 + 0x8E;
            var_r0_20271 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) * 2;
            var_r1_20273 = sp0 + 0x210;
        }
        *(var_r1_20273 + var_r0_20271) = 0xFFF;
        var_sb_20296 = 0;
        var_r6_20247 = (void *)0x030041A0 + 0x8A;
        var_r5_20249 = (void *)0x030041A0 + 0x89;
        var_r0_20310 = (u8 *)0x02034058;
loop_27:
        if (var_r7_20203 == *var_r0_20310) {
            temp_r1_20324 = *(0x02033FB6 + (u8) ((M2C_FIELD((void *)0x030041A0, u8 *, 0x96) * 9) + var_sb_20296));
            *(u8 *)0x03004233 += temp_r1_20324;
            if (0x80 & temp_r1_20324) {
                *(s8 *)0x03004237 = 0x5D;
            } else {
                M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 0x59;
            }
        } else {
            var_r0_20310 += 1;
            var_sb_20296 += 1;
            if (var_sb_20296 <= 8) {
                goto loop_27;
            }
        }
        var_sb_20179 = 3;
        temp_r1_20350 = *(u8 *)0x03004233;
        if (0x80 & temp_r1_20350) {
            *(u8 *)0x03004233 = 0;
            goto block_38;
        }
        if ((u32) temp_r1_20350 > 5U) {
            if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0) & 0xFF0000)) {
                var_r0_20371 = *var_r2_20269 * 2;
                var_r1_20373 = sp0 + 0x10;
            } else {
                var_r0_20371 = *var_r2_20269 * 2;
                var_r1_20373 = sp0 + 0x210;
            }
            *(var_r1_20373 + var_r0_20371) = 0x3333;
            *(u8 *)0x03004233 = 6;
        } else {
block_38:
            *sp8 = 0;
        }
        break;
    }
    switch (var_sb_20179) {                         /* switch 3; irregular */
    case 1:                                         /* switch 3 */
        sub_0201FE6C((s32) M2C_FIELD((void *)0x030041A0, u8 *, 0x95));
        /* fallthrough */
    case 3:                                         /* switch 3 */
        if (var_sb_20179 != 1) {
            sub_020209E0();
            if ((M2C_FIELD((void *)0x030041A0, u8 *, 0x90) == 2) && (M2C_FIELD((void *)0x030041A0, u8 *, 0xA1) == 0)) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x90) = 1U;
                sub_02026C7C(2U);
            }
        }
        temp_r1_20598 = (void *)0x030041A0 + 0x6E;
        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
        M2C_FIELD(temp_r1_20598, s8 *, 0x2B) = 0x50;
        *((temp_r1_20598 + 0x2B) - 0x12) = 7;
        sub_02021FA4();
        break;
    case 2:                                         /* switch 3 */
        sub_0201F660(M2C_FIELD((void *)0x030041A0, s32 *, 0), M2C_FIELD((void *)0x030041A0, u8 *, 0x8E), 0U, 0x200U);
        M2C_FIELD((void *)0x030041A0, s16 *, 0x82) = 0;
        M2C_FIELD(((void *)0x030041A0 + 0x82), s8 *, 0x12) = 0x20;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = (s8) var_sb_20179;
        sub_02021720();
        break;
    }
    *var_r6_20247 = (s8) M2C_FIELD(*((*var_r5_20249 * 4) + *(0x02033680 + (*sp4 * 4))), u16 *, 4);
}

void sub_02021FA4(void) {
    u32 temp_r0_20681;
    u8 *temp_r1_20672;
    void *temp_r1_20663;
    void *temp_r1_20665;
    void *temp_r5_20679;

    M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
    temp_r1_20663 = (void *)0x03004229 + 1;
    M2C_FIELD((void *)0x03004229, s8 *, 1) = 0;
    temp_r1_20665 = temp_r1_20663 + 7;
    M2C_FIELD(temp_r1_20663, s8 *, 7) = 0;
    M2C_FIELD(temp_r1_20665, s8 *, 1) = 0;
    temp_r1_20672 = (temp_r1_20665 + 1) - 0xA;
    *temp_r1_20672 = *(u8 *)0x03004237;
    temp_r5_20679 = **(0x02033680 + (*temp_r1_20672 * 4));
    temp_r0_20681 = *(u8 *)0x03004237 - 0x59;
    switch (temp_r0_20681) {
    case 0:
        sub_02026A38(9U);
        break;
    case 1:
        sub_02026A38(0xAU);
        break;
    case 2:
        sub_02026A38(0xBU);
        break;
    case 3:
        sub_02026A38(0xCU);
        break;
    case 4:
        sub_02026A38(0xDU);
        break;
    }
    sub_02026C7C((u8) (*(u8 *)0x03004230 + 1));
    *(s8 *)0x0300422A = (s8) M2C_FIELD(temp_r5_20679, u16 *, 4);
    *(s8 *)0x03004227 = 8;
}

void sub_02022054(void) {
    s16 *var_r0_20893;
    s16 *var_r1_20891;
    s32 var_r2_20894;
    u16 temp_r2_20773;
    u16 temp_r5_20798;
    u8 temp_r0_20836;

    if (sub_0201FDF4(1U) == 0) {
        return;
    }
    *(s8 *)0x03004234 = 0x20;
    if ((*(u8 *)0x03004240 != 0) && (*(u8 *)0x03004237 == 0x59)) {
        *(u8 *)0x03004240 = 0;
        if (*(u8 *)0x03004233 == 6) {
            temp_r2_20773 = M2C_FIELD((void *)0x030041FA, u16 *, 0);
            if (temp_r2_20773 != 0) {
                if (sub_0201FF48(1U, 0U, (u16) (temp_r2_20773 - 1), M2C_FIELD((void *)0x030041FA, u16 *, 0xA)) != 0) {
                    sub_0201FE6C(0);
                }
            } else {
                temp_r5_20798 = (u16) ((s32) sub_02019AF0(&gGameState) % 101);
                if ((u32) temp_r5_20798 <= 0x3BU) {
                    sub_0201FF48(0U, 0U, 0xBU, 8U);
                } else if ((u32) temp_r5_20798 <= 0x59U) {
                    sub_0201FF48(0U, 0U, 0x42U, 9U);
                } else if ((u32) temp_r5_20798 <= 0x61U) {
                    sub_0201FF48(0U, 0U, 0x43U, 0xAU);
                } else {
                    sub_0201FF48(0U, 0U, 0x44U, 0xBU);
                }
            }
        }
    }
    temp_r0_20836 = *(u8 *)0x03004239;
    if (temp_r0_20836 == 0x50) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 8);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0xC);
        *(s8 *)0x03004229 = 0;
        sub_02020790();
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = (s8) M2C_FIELD(**(0x02033680 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x88) * 4)), u16 *, 4);
        *(((void *)0x030041A0 + 0x8A) - 3) = 4;
        sub_020218B0();
        return;
    }
    if (temp_r0_20836 == 0x80) {
        M2C_FIELD((void *)0x03003BC4, s8 *, 0x11) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) (M2C_FIELD((void *)0x03003BC4, s32 *, 0) << 8);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (M2C_FIELD((void *)0x03003BC4, s32 *, 4) << 8);
        *(u8 *)0x03004239 = 0;
        M2C_FIELD((void *)0x030041A0, u8 *, 0x88) = 0x5FU;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0;
        sub_020215D0();
        M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = 4;
        var_r1_20891 = ((void *)0x030041A0 + 0x8A) - 0x26;
        var_r0_20893 = (void *)0x030041A0 + 0x5A;
        var_r2_20894 = 4;
        do {
            *var_r0_20893 = 0;
            *var_r1_20891 = 0;
            var_r1_20891 += 2;
            var_r0_20893 += 2;
            var_r2_20894 -= 1;
        } while (var_r2_20894 >= 0);
        return;
    }
    sub_0201F78C(1U);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
    sub_02021720();
}

void sub_020221C0(void) {
    s32 temp_r0_21000;
    s32 temp_r1_21005;
    s32 var_r0_20937;
    s32 var_r1_20939;
    s32 var_r1_21018;
    s8 *var_r3_21029;
    s8 *var_r6_21021;
    u16 *var_r0_21019;
    u16 temp_r1_20954;
    u16 temp_r2_21013;
    u8 *var_r5_21024;

    if (*(u8 *)0x0300423F == 0) {
        if (!(M2C_FIELD((void *)0x030041A0, s32 *, 0x10) & 0xFF0000)) {
            var_r0_20937 = M2C_FIELD((void *)0x030041A0, u8 *, 0x9D) * 2;
            var_r1_20939 = 0x03003720;
        } else {
            var_r0_20937 = M2C_FIELD((void *)0x030041A0, u8 *, 0x9D) * 2;
            var_r1_20939 = 0x03003920;
        }
        temp_r1_20954 = *(var_r0_20937 + var_r1_20939);
        if ((temp_r1_20954 == 0xFFF) || (temp_r1_20954 == 0x3333) || (temp_r1_20954 == 0x7777) || (M2C_FIELD(((temp_r1_20954 * 0xC) + 0x0202F7FC), u16 *, 4) == 0xFFF)) {
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
            sub_02021720();
            return;
        }
        goto block_9;
    }
block_9:
    sub_0201FED4(0U, 0x30U);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x98) = 0x30;
    *(((void *)0x030041A0 + 0x98) - 4) = 0x60;
    temp_r0_21000 = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x10) - M2C_FIELD((void *)0x030041A0, s32 *, 0)) >> 8;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r0_21000;
    temp_r1_21005 = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x14) - M2C_FIELD((void *)0x030041A0, s32 *, 4)) >> 8;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = temp_r1_21005;
    temp_r2_21013 = ArcTan2((s16) temp_r0_21000, (s16) temp_r1_21005);
    if ((u32) temp_r2_21013 < (u32) *(u16 *)0x020338F8) {
        var_r1_21018 = 0;
        var_r0_21019 = (u16 *)0x020338DC;
        var_r6_21021 = (void *)0x030041A0 + 0x87;
        var_r5_21024 = (void *)0x030041A0 + 0x8B;
        var_r3_21029 = (void *)0x030041A0 + 0x8A;
        if ((u32) temp_r2_21013 > (u32) *(u16 *)0x020338DC) {
loop_11:
            var_r0_21019 += 4;
            var_r1_21018 += 1;
            if (var_r1_21018 <= 6) {
                if ((u32) temp_r2_21013 <= (u32) *var_r0_21019) {

                } else {
                    goto loop_11;
                }
            }
        }
    } else {
        var_r1_21018 = 0;
        var_r6_21021 = (void *)0x030041A0 + 0x87;
        var_r5_21024 = (void *)0x030041A0 + 0x8B;
        var_r3_21029 = (void *)0x030041A0 + 0x8A;
    }
    *var_r5_21024 = M2C_FIELD(((var_r1_21018 * 4) + 0x020338DC), u8 *, 2);
    *(s8 *)0x03004229 = 0;
    *var_r3_21029 = 0;
    sub_02020790();
    *var_r6_21021 = 0xA;
}

void sub_020222F8(void) {
    u8 temp_r0_21082;
    u8 temp_r0_21118;
    u8 temp_r0_21129;
    u8 temp_r1_21095;
    u8 temp_r5_21085;
    u8 var_r0_21152;

    temp_r0_21082 = *(u8 *)0x03004238 - 1;
    *(u8 *)0x03004238 = temp_r0_21082;
    temp_r5_21085 = temp_r0_21082;
    if (temp_r5_21085 == 0) {
        if (*(u8 *)0x03004237 == 0) {
            temp_r1_21095 = *(u8 *)0x0300422D;
            if (0x40 & temp_r1_21095) {
                *(u8 *)0x0300422D = temp_r1_21095 - 0x40;
                sub_02020A78();
            }
            *(s8 *)0x03004227 = 2;
            sub_02021720();
            return;
        }
        *(u8 *)0x03004237 = temp_r5_21085;
        temp_r0_21118 = *(u8 *)0x03004233 - 1;
        *(u8 *)0x03004233 = temp_r0_21118;
        if (temp_r0_21118 & 0x80) {
            *(u8 *)0x03004233 = temp_r5_21085;
        }
        sub_020209E0();
        temp_r0_21129 = *(u8 *)0x03004230;
        if ((temp_r0_21129 == 0) || (temp_r0_21129 == 3)) {
            *(u8 *)0x0300422B = temp_r5_21085;
            sub_0201FED4(1U, 0x30U);
            *(u8 *)0x03004238 = 0x30;
            return;
        }
        if (*(u8 *)0x03004241 == 0) {
            *(u8 *)0x03004237 = 0x5B;
            var_r0_21152 = 1;
        } else {
            *(u8 *)0x03004237 = 0x5C;
            var_r0_21152 = 2;
        }
        *(u8 *)0x03004230 = var_r0_21152;
        *(void *)0x03004227 = 7;
        sub_02021FA4();
    }
}

void sub_020223AC(void) {
    s32 temp_r1_21205;
    void *temp_r4_21181;

    temp_r4_21181 = (*(u8 *)0x0300423B * 0x30) + 0x03003C00;
    *(s8 *)0x03004229 = 0;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
    M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
    M2C_FIELD((void *)0x0300420E, s16 *, 0x10) = 0;
    temp_r1_21205 = 0xF & M2C_FIELD(((void *)0x0300420E + 0x10), u8 *, 0xF);
    if ((temp_r1_21205 != 2) && (temp_r1_21205 != 6)) {
        *(s8 *)0x0300423C = 0;
        M2C_FIELD(temp_r4_21181, s8 *, 0x2C) = 1;
        *((temp_r4_21181 + 0x2C) - 4) = 1;
    } else {
        M2C_FIELD(temp_r4_21181, s8 *, 0x2C) = 0;
        *(void *)0x0300423C = 1;
    }
    *(s8 *)0x03004227 = 0xC;
}

void sub_0202243C(void) {
    void *temp_r4_21255;

    temp_r4_21255 = (*(u8 *)0x0300423B * 0x30) + 0x03003C00;
    if ((*(u8 *)0x03004229 != 0) && (*(u8 *)0x0300422A == 1)) {
        M2C_FIELD(temp_r4_21255, u8 *, 0x25) = (u8) *(0x02033B27 + (s32) (*(u8 *)0x03004229 - 1));
    }
    if (sub_0201FDF4(1U) != 0) {
        *(s16 *)0x0300421E = 0x258;
        *(s8 *)0x0300423C = 0;
        M2C_FIELD(temp_r4_21255, u8 *, 0x25) = 3U;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 8);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0xC);
        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 1;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x9B) = 0;
        sub_02020790();
        M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 1;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x50;
        *(((void *)0x030041A0 + 0x99) - 0x12) = 4;
        sub_020218B0();
    }
}

void sub_020224D8(void) {
    s16 temp_r2_21538;
    s32 temp_r0_21488;
    s32 temp_r0_21495;
    s32 temp_r1_21529;
    s32 temp_r4_21476;
    s32 var_r0_21435;
    s32 var_r0_21506;
    s32 var_r1_21433;
    s32 var_r1_21508;
    s32 var_r4_21460;
    u16 temp_r1_21479;
    u16 var_r0_21478;
    u8 temp_r1_21345;
    void *temp_r1_21531;
    void *temp_r1_21565;
    void *temp_r6_21338;

    temp_r6_21338 = (*(u8 *)0x0300423B * 0x30) + 0x03003C00;
    if (sub_0201FDF4(1U) != 0) {
        temp_r1_21345 = M2C_FIELD(temp_r6_21338, u8 *, 0x2A);
        if ((temp_r1_21345 == 0) || (0x80 & temp_r1_21345)) {
            M2C_FIELD((void *)0x0300421E, s16 *, 0) = 0x20;
            M2C_FIELD((void *)0x0300421E, s8 *, 0x1E) = 2;
        } else {
            *(s8 *)0x03004227 = 0xB;
            sub_020223AC();
        }
    }
    if ((*(s32 *)0x03004228 & 0xFFFF00) != 0x10300) {
        return;
    }
    if (M2C_FIELD(temp_r6_21338, u8 *, 0x2D) != 1) {

    } else if (*(u8 *)0x03004254 != 0) {

    } else if (*(u16 *)0x0300420E != 0) {

    } else if (*(u8 *)0x03003B26 != *(0x02033FA4 + *(u8 *)0x03004236)) {

    } else if ((s32) ((s32) sub_02019AF0(&gGameState) % 101) > 0x18) {

    } else {
        if (M2C_FIELD(temp_r6_21338, u8 *, 0x24) == 0) {
            var_r1_21433 = (M2C_FIELD(temp_r6_21338, u16 *, 0xE) + 0x10) * 2;
            var_r0_21435 = 0x03003720;
        } else {
            var_r1_21433 = (M2C_FIELD(temp_r6_21338, u16 *, 0xE) + 0x10) * 2;
            var_r0_21435 = 0x03003920;
        }
        if (*(var_r0_21435 + var_r1_21433) == 0xFFF) {
            *(u16 *)0x0300420E = 1;
            var_r4_21460 = 0;
            if ((0xF & *(u8 *)0x0300422D) == 6) {
                var_r4_21460 = 0x14;
            }
            temp_r4_21476 = var_r4_21460 + *(0x02033DE0 + *(u8 *)0x03004230);
            var_r0_21478 = sub_02019AF0(&gGameState);
            temp_r1_21479 = var_r0_21478;
            if ((s32) temp_r1_21479 < 0) {
                var_r0_21478 = temp_r1_21479 + 3;
            }
            temp_r0_21488 = (temp_r4_21476 + (temp_r1_21479 - (((s32) var_r0_21478 >> 2) * 4))) * 4;
            temp_r0_21495 = sub_0201FF48(0U, 2U, *(0x02033EE0 + temp_r0_21488), M2C_FIELD((temp_r0_21488 + 0x02033EE0), u16 *, 2));
            if (temp_r0_21495 != 0) {
                if (M2C_FIELD(temp_r6_21338, u8 *, 0x24) == 0) {
                    var_r0_21506 = *(u8 *)0x0300422E * 2;
                    var_r1_21508 = 0x03003720;
                } else {
                    var_r0_21506 = *(void *)0x0300422E * 2;
                    var_r1_21508 = 0x03003920;
                }
                *(var_r1_21508 + var_r0_21506) = 0x3333;
                temp_r1_21529 = 0x54 * temp_r0_21495;
                temp_r1_21531 = temp_r1_21529 + 0x03004790;
                M2C_FIELD(temp_r1_21531, s32 *, 0x10) = (s32) ((M2C_FIELD(temp_r1_21531, s32 *, 4) + 0x20) << 8);
                temp_r2_21538 = M2C_FIELD(temp_r6_21338, u16 *, 0xE) + 0x10;
                M2C_FIELD(temp_r1_21531, s16 *, 0x3C) = temp_r2_21538;
                if (M2C_FIELD(temp_r6_21338, u8 *, 0x24) != 0) {
                    M2C_FIELD(temp_r1_21531, s16 *, 0x3C) = (s16) (temp_r2_21538 | 0x1000);
                }
                M2C_FIELD(temp_r1_21531, s8 *, 0x52) = 0x35;
                M2C_FIELD(temp_r1_21531, s32 *, 4) = (s32) (M2C_FIELD(temp_r1_21531, s32 *, 4) - 0x20);
                *(0x03004790 + temp_r1_21529) = (s32) (M2C_FIELD(temp_r6_21338, s32 *, 0) - 8);
                *(u8 *)0x03004254 = 1;
            }
        }
    }
    temp_r1_21565 = temp_r6_21338 + 0x28;
    M2C_FIELD(temp_r6_21338, s8 *, 0x28) = 1;
    M2C_FIELD(temp_r1_21565, u8 *, 2) = (u8) (M2C_FIELD(temp_r1_21565, u8 *, 2) - 1);
    sub_02026A38(0U);
}

void sub_020226E8(void) {
    u16 temp_r0_21593;
    u16 temp_r1_21596;
    u8 temp_r0_21616;

    temp_r0_21593 = *(u16 *)0x0300421E - 1;
    *(u16 *)0x0300421E = temp_r0_21593;
    temp_r1_21596 = temp_r0_21593;
    if (temp_r1_21596 == 0) {
        *(u16 *)0x0300421E = 0x258;
        *(u16 *)0x0300420E = temp_r1_21596;
        *(s8 *)0x0300423C = 0;
        if (*(u8 *)0x03004230 == 1) {
            temp_r0_21616 = *(u8 *)0x03004233 + 1;
            *(u8 *)0x03004233 = temp_r0_21616;
            if ((u32) temp_r0_21616 > 6U) {
                *(u8 *)0x03004233 = 6;
            }
            sub_020209E0();
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 8);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0xC);
        *(u16 *)0x0300420E = 1;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x50;
        *(((void *)0x030041A0 + 0x99) - 2) = 0x59;
        sub_02021FA4();
    }
}

void sub_0202275C(void) {
    *(0x02033860 + (*(u8 *)0x0300423C * 4))();
}

void sub_0202277C(void) {
    u8 var_r0_21676;

    if (*(u8 *)0x0300422B == 0) {
        var_r0_21676 = 0x38;
    } else {
        var_r0_21676 = 0x41;
    }
    *(u8 *)0x03004228 = var_r0_21676;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
    *(s8 *)0x03004229 = 0;
    M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
    M2C_FIELD((void *)0x0300420E, s8 *, 0x2E) = 0;
    *(s8 *)0x03004227 = 0xE;
}

void sub_020227D8(void) {
    u8 var_r0_21729;

    if (sub_0201FDF4(1U) != 0) {
        if (*(u8 *)0x0300422B == 0) {
            var_r0_21729 = 0x39;
        } else {
            var_r0_21729 = 0x42;
        }
        *(u8 *)0x03004228 = var_r0_21729;
        *(u8 *)0x0300422A = (u8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
        *(u8 *)0x03004229 = 0;
        *(s16 *)0x0300420E = 0;
        M2C_FIELD((void *)0x03004210, s16 *, 0) = 0x20;
        M2C_FIELD((void *)0x03004210, s8 *, 0x2C) = 1;
    }
    if ((*(void *)0x0300422A == 1) && (*(void *)0x03004229 == 3)) {
        sub_02026A38(0x14U);
    }
}

void sub_02022858(void) {
    u16 temp_r0_21792;
    u16 temp_r2_21795;

    sub_0201FDF4(0U);
    temp_r0_21792 = *(u16 *)0x03004210 - 1;
    *(u16 *)0x03004210 = temp_r0_21792;
    temp_r2_21795 = temp_r0_21792;
    if (temp_r2_21795 == 0) {
        *(s8 *)0x03004229 = 0;
        *(u16 *)0x03004210 = 0x30;
        *(u16 *)0x0300420E = temp_r2_21795;
        sub_0201FED4(0U, 0x30U);
        *(s8 *)0x0300423C = 2;
    }
}

void sub_020228A0(void) {
    u16 temp_r0_21828;
    u8 *var_r1_21838;
    u8 var_r0_21839;

    temp_r0_21828 = *(u16 *)0x03004210 - 1;
    *(u16 *)0x03004210 = temp_r0_21828;
    if ((temp_r0_21828 << 0x10) == 0) {
        if (*(u8 *)0x0300422B == 0) {
            var_r1_21838 = (u16 *)0x03004210 + 0x18;
            var_r0_21839 = 0x3A;
        } else {
            var_r1_21838 = (u8 *)0x03004228;
            var_r0_21839 = 0x43;
        }
        *var_r1_21838 = var_r0_21839;
        *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*var_r1_21838 * 4)), u16 *, 4);
        *(s8 *)0x03004229 = 0;
        *(s16 *)0x0300420E = 0;
        *(s8 *)0x0300423C = 3;
        sub_02026AB8(0x15U);
        *(void *)0x03004210 = 0x51U;
    }
}

void sub_02022914(void) {
    u16 temp_r0_21892;
    u16 temp_r0_21895;
    u8 *var_r1_21904;
    u8 var_r0_21905;

    sub_0201FDF4(0U);
    temp_r0_21892 = *(u16 *)0x03004210 - 1;
    *(u16 *)0x03004210 = temp_r0_21892;
    temp_r0_21895 = temp_r0_21892;
    if (temp_r0_21895 == 0) {
        *(u16 *)0x03004210 = temp_r0_21895;
        if (*(u8 *)0x0300422B == 0) {
            var_r1_21904 = (u16 *)0x03004210 + 0x18;
            var_r0_21905 = 0x3B;
        } else {
            var_r1_21904 = (u8 *)0x03004228;
            var_r0_21905 = 0x44;
        }
        *var_r1_21904 = var_r0_21905;
        *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*var_r1_21904 * 4)), u16 *, 4);
        *(s8 *)0x03004229 = 0;
        M2C_FIELD((void *)0x0300420E, s16 *, 0) = sub_0201F030();
        M2C_FIELD((void *)0x0300420E, s8 *, 0x2E) = 4;
        sub_02026B38(0x15);
        sub_02026A38(0x16U);
    }
}

void sub_02022994(void) {
    s32 temp_r1_22008;
    u8 *var_r1_21977;
    u8 *var_r1_22032;
    u8 *var_r5_22005;
    u8 temp_r0_22017;
    u8 temp_r0_22050;
    u8 var_r0_21978;
    u8 var_r0_22033;
    void *temp_r0_22109;

    if (sub_0201FDF4(1U) == 0) {
        return;
    }
    sub_02026A38(0x1CU);
    if (*(u16 *)0x0300420E == 0) {
        if ((u16) M2C_FIELD((void *)0x030041A0, s32 *, 0x40) == 0x609E) {
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
                var_r1_21977 = (void *)0x030041A0 + 0x88;
                var_r0_21978 = 0x3E;
            } else {
                var_r1_21977 = (void *)0x030041A0 + 0x88;
                var_r0_21978 = 0x47;
            }
        } else if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
            var_r1_21977 = (void *)0x030041A0 + 0x88;
            var_r0_21978 = 0x40;
        } else {
            var_r1_21977 = (void *)0x030041A0 + 0x88;
            var_r0_21978 = 0x49;
        }
        *var_r1_21977 = var_r0_21978;
        var_r5_22005 = var_r1_21977;
    } else {
        temp_r1_22008 = M2C_FIELD((void *)0x030041A0, s32 *, 0x40);
        if ((u16) temp_r1_22008 == 0x434E) {
            temp_r0_22017 = M2C_FIELD((void *)0x030041A0, u8 *, 0x93) - 1;
            M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = temp_r0_22017;
            if (temp_r0_22017 & 0x80) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = 0U;
            }
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
                var_r1_22032 = (void *)0x030041A0 + 0x88;
                var_r0_22033 = 0x3E;
            } else {
                var_r1_22032 = (void *)0x030041A0 + 0x88;
                var_r0_22033 = 0x47;
            }
        } else if ((u16) temp_r1_22008 == 0x4350) {
            temp_r0_22050 = M2C_FIELD((void *)0x030041A0, u8 *, 0x93) + 1;
            M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = temp_r0_22050;
            if ((u32) temp_r0_22050 > 6U) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = 6U;
            }
            sub_0201FED4(3U, 0x30U);
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
                var_r1_22032 = (void *)0x030041A0 + 0x88;
                var_r0_22033 = 0x3F;
            } else {
                var_r1_22032 = (void *)0x030041A0 + 0x88;
                var_r0_22033 = 0x48;
            }
        } else if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
            var_r1_22032 = (void *)0x030041A0 + 0x88;
            var_r0_22033 = 0x40;
        } else {
            var_r1_22032 = (void *)0x030041A0 + 0x88;
            var_r0_22033 = 0x49;
        }
        *var_r1_22032 = var_r0_22033;
        var_r5_22005 = var_r1_22032;
        sub_020209E0();
    }
    M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 6;
    temp_r0_22109 = (void *)0x030041A0 + 0x70;
    M2C_FIELD((void *)0x030041A0, s16 *, 0x70) = 0;
    M2C_FIELD(temp_r0_22109, s8 *, 0x19) = 0;
    M2C_FIELD((temp_r0_22109 + 0x19), s8 *, 1) = (s8) M2C_FIELD(**(0x02033680 + (*var_r5_22005 * 4)), u16 *, 4);
}

void sub_02022AE4(void) {
    s8 *temp_r1_22145;
    void *temp_r1_22139;

    if (sub_0201FDF4(1U) != 0) {
        if ((u16) M2C_FIELD((void *)0x030041A0, s32 *, 0x40) == 0x609E) {
            temp_r1_22139 = (void *)0x030041A0 + 0x93;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x93) = 0;
            M2C_FIELD(temp_r1_22139, s8 *, 4) = 0x5C;
            temp_r1_22145 = (temp_r1_22139 + 4) - 7;
            *temp_r1_22145 = 2;
            *(temp_r1_22145 - 9) = 7;
            sub_02021FA4();
        } else {
            M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
            sub_02021720();
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
    }
}

void sub_02022B44(void) {
    s8 var_r0_22197;
    s8 var_r0_22210;
    s8 var_r0_22220;
    u8 *var_r2_22207;

    if (sub_0201FDF4(1U) != 0) {
        *(s16 *)0x03004214 = 0x708;
        if (M2C_FIELD((void *)0x0300420E, u16 *, 0) == 0) {
            if (M2C_FIELD((void *)0x0300420E, u8 *, 0x1D) == 0) {
                var_r0_22197 = 0x3C;
            } else {
                var_r0_22197 = 0x45;
            }
            *(s8 *)0x03004228 = var_r0_22197;
            var_r2_22207 = (u8 *)0x03004228;
            var_r0_22210 = 5;
        } else {
            if (*(u8 *)0x0300422B == 0) {
                var_r0_22220 = 0x3D;
            } else {
                var_r0_22220 = 0x46;
            }
            *(void *)0x03004228 = var_r0_22220;
            var_r2_22207 = (u8 *)0x03004228;
            var_r0_22210 = 7;
        }
        *(s8 *)0x0300423C = var_r0_22210;
        *(s16 *)0x03004210 = 0;
        M2C_FIELD((void *)0x0300420E, u16 *, 0) = 0U;
        M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
        M2C_FIELD((void *)0x03004229, s8 *, 1) = (s8) M2C_FIELD(**(0x02033680 + (*var_r2_22207 * 4)), u16 *, 4);
    }
}

void sub_02022BE0(void) {
    if (sub_0201FDF4(1U) != 0) {
        sub_0201F78C(1U);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
        sub_02021720();
    }
}

void sub_02022C10(void) {
    *(0x0203386C + (*(u8 *)0x0300423C * 4))();
}

void sub_02022C30(void) {
    u8 var_r0_22314;

    *(s8 *)0x03004229 = 0;
    if (*(u8 *)0x0300422B == 0) {
        var_r0_22314 = 0x4A;
    } else {
        var_r0_22314 = 0x4F;
    }
    *(u8 *)0x03004228 = var_r0_22314;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 0;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0x10;
}

void sub_02022C8C(void) {
    *(0x020338B8 + (*(u8 *)0x0300423C * 4))();
}

void sub_02022CAC(void) {
    s8 temp_r0_22417;
    u8 *var_r1_22433;
    u8 *var_r1_22454;
    u8 *var_r4_22445;
    u8 var_r0_22434;
    u8 var_r0_22455;
    void *temp_r3_22495;

    if (M2C_FIELD((void *)0x030041A0, s32 *, 0x40) == 0) {
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
        sub_02021720();
        return;
    }
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8A) == 0) {
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0x89) == 2) {
            sub_02026A38(0x1AU);
        }
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0x89) == 4) {
            sub_02026A38(0x1BU);
        }
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0x89) == 8) {
            sub_02026A38(0x1CU);
        }
    }
    temp_r0_22417 = sub_0201FDF4(1U);
    if (temp_r0_22417 != 0) {
        if ((u16) M2C_FIELD((void *)0x030041A0, s32 *, 0x40) == 0x609E) {
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
                var_r1_22433 = (void *)0x030041A0 + 0x88;
                var_r0_22434 = 0x4C;
            } else {
                var_r1_22433 = (void *)0x030041A0 + 0x88;
                var_r0_22434 = 0x51;
            }
            *var_r1_22433 = var_r0_22434;
            var_r4_22445 = var_r1_22433;
        } else {
            if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
                var_r1_22454 = (void *)0x030041A0 + 0x88;
                var_r0_22455 = 0x4D;
            } else {
                var_r1_22454 = (void *)0x030041A0 + 0x88;
                var_r0_22455 = 0x52;
            }
            *var_r1_22454 = var_r0_22455;
            var_r4_22445 = var_r1_22454;
            sub_0201FED4(3U, 0x30U);
        }
        M2C_FIELD((void *)0x030041A0, u8 *, 0x89) = 0U;
        M2C_FIELD((void *)0x030041A0, u8 *, 0x8A) = (u8) M2C_FIELD(**(0x02033680 + (*var_r4_22445 * 4)), u16 *, 4);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 1;
        return;
    }
    temp_r3_22495 = (0x54 * *(u8 *)0x0300423E) + 0x03004790;
    if ((M2C_FIELD((void *)0x030041A0, u8 *, 0x8A) == 1) && (M2C_FIELD((void *)0x030041A0, u8 *, 0x89) == 3)) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
        M2C_FIELD((*(u8 *)0x0300423E + 0x03003710), s8 *, 0x41A) = temp_r0_22417;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x70) = (u16) *(temp_r3_22495 + 0x28 + (M2C_FIELD(temp_r3_22495, u8 *, 0x4C) * 2));
        M2C_FIELD((void *)0x030041A0, u16 *, 0x6E) = (u16) *(temp_r3_22495 + 0x32 + (M2C_FIELD(temp_r3_22495, u8 *, 0x4C) * 2));
        M2C_FIELD((void *)0x030041A0, u16 *, 0x76) = 0x2A30U;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x76) = (u16) ((0x64 * ((s32) sub_02019AF0(&gGameState) % 109)) + M2C_FIELD((void *)0x030041A0, u16 *, 0x76));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x38) = (s32) temp_r0_22417;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) = (s32) temp_r0_22417;
        *(u8 *)0x0300423E = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0x40) | M2C_FIELD(((M2C_FIELD((void *)0x030041A0, u16 *, 0x70) * 0xC) + 0x0202F7FC), u16 *, 4));
    }
}

void sub_02022E54(void) {
    u8 var_r0_22599;

    if (sub_0201FDF4(1U) != 0) {
        sub_0201EFB8(*(u16 *)0x03004210, *(u16 *)0x0300420E);
        if (*(u8 *)0x0300422B == 0) {
            var_r0_22599 = 0x4B;
        } else {
            var_r0_22599 = 0x50;
        }
        *(u8 *)0x03004228 = var_r0_22599;
        M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
        M2C_FIELD((void *)0x03004229, s8 *, 1) = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
        *(s8 *)0x0300423C = 2;
    }
}

void sub_02022EC0(void) {
    s8 *temp_r1_22658;
    void *temp_r1_22651;

    if (sub_0201FDF4(1U) != 0) {
        sub_0201F78C(1U);
        if ((u16) M2C_FIELD((void *)0x030041A0, s32 *, 0x40) == 0x609E) {
            temp_r1_22651 = (void *)0x030041A0 + 0x93;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x93) = 0;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
            M2C_FIELD(temp_r1_22651, s8 *, 4) = 0x5C;
            temp_r1_22658 = (temp_r1_22651 + 4) - 7;
            *temp_r1_22658 = 2;
            *(temp_r1_22658 - 9) = 7;
            sub_02021FA4();
            return;
        }
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 2;
        sub_02021720();
    }
}

void sub_02022F28(void) {
    u8 var_r0_22695;

    if (*(u8 *)0x0300422B == 0) {
        var_r0_22695 = 0x28;
    } else {
        var_r0_22695 = 0x30;
    }
    *(u8 *)0x03004228 = var_r0_22695;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
    *(s8 *)0x03004229 = 0;
    M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
    M2C_FIELD((void *)0x0300420E, s8 *, 0x2E) = 0;
    *(s8 *)0x03004227 = 0x12;
}

void sub_02022F84(void) {
    s32 temp_r0_22780;
    s32 temp_r1_22819;
    s32 var_ip_22779;
    s32 var_sb_22745;
    s8 *var_r1_22895;
    s8 var_r0_22869;
    s8 var_r0_22896;
    u16 temp_r3_22785;
    u16 temp_r6_22823;
    u8 *var_r1_22907;
    u8 *var_r2_22880;
    u8 temp_r7_22743;
    u8 var_r0_22908;

    temp_r7_22743 = *(u8 *)0x0300421A;
    var_sb_22745 = 0;
    if ((*(u8 *)0x0300422A == 0) && (*(u8 *)0x03004229 == 3)) {
        sub_02026A38(0x21U);
    }
    if (sub_0201FDF4(1U) == 0) {
        return;
    }
    *(u16 *)0x0300420E = 0;
    if (0x8000 & (u16) *(void *)0x0300421A) {
        var_ip_22779 = 0x0600C800;
        temp_r0_22780 = temp_r7_22743 * 2;
        temp_r3_22785 = *(0x03003920 + temp_r0_22780);
        if (temp_r3_22785 == 0xFFF) {
            var_sb_22745 = 1;
        } else {
            *(u16 *)0x0300420E = temp_r3_22785;
            if ((u32) temp_r3_22785 > 0x56U) {
                *(u16 *)0x0300420E = 0x1E;
            }
        }
        *(0x03003920 + temp_r0_22780) = 0x7777U;
    } else {
        var_ip_22779 = 0x0600C000;
        temp_r1_22819 = temp_r7_22743 * 2;
        temp_r6_22823 = *(0x03003720 + temp_r1_22819);
        if (temp_r6_22823 == 0xFFF) {
            var_sb_22745 = 1;
        } else {
            *(u16 *)0x0300420E = temp_r6_22823;
            if ((u32) temp_r6_22823 > 0x56U) {
                *(u16 *)0x0300420E = 0x1E;
            }
        }
        *(0x03003720 + temp_r1_22819) = 0x7777U;
    }
    sub_02020A0C(var_ip_22779 + ((0xF0 & temp_r7_22743) * 8) + ((temp_r7_22743 & 0xF) * 4), 0x12ACU);
    if (var_sb_22745 == 0) {
        if (*(u8 *)0x0300422B == 0) {
            var_r0_22869 = 0x2B;
        } else {
            var_r0_22869 = 0x33;
        }
        *(s8 *)0x03004228 = var_r0_22869;
        var_r2_22880 = (u8 *)0x03004228;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x800000;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(((*(u16 *)0x0300420E * 0xC) + 0x0202F7FC), u16 *, 4) | 0x800000);
        var_r1_22895 = (void *)0x030041A0 + 0x9C;
        var_r0_22896 = 2;
    } else {
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8B) == 0) {
            var_r1_22907 = (void *)0x030041A0 + 0x88;
            var_r0_22908 = 0x2A;
        } else {
            var_r1_22907 = (void *)0x030041A0 + 0x88;
            var_r0_22908 = 0x32;
        }
        *var_r1_22907 = var_r0_22908;
        var_r2_22880 = var_r1_22907;
        var_r1_22895 = (void *)0x030041A0 + 0x9C;
        var_r0_22896 = 1;
    }
    *var_r1_22895 = var_r0_22896;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = (s8) M2C_FIELD(**(0x02033680 + (*var_r2_22880 * 4)), u16 *, 4);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x89) = 0;
}

void sub_02023120(void) {
    s32 temp_r2_23112;
    s32 temp_r2_23145;
    s32 temp_r4_23027;
    s32 var_r0_23126;
    s32 var_r2_23128;
    s32 var_r4_23114;
    s32 var_r8_22965;
    u16 *temp_r2_23164;
    u16 temp_r0_23023;
    u16 var_r6_23040;
    u32 temp_r3_23116;
    u32 temp_r3_23149;
    u8 temp_r0_23011;
    u8 temp_r0_23086;
    u8 temp_r7_22957;
    u8 var_r0_22986;

    temp_r7_22957 = *(u8 *)0x0300421A;
    if (sub_0201FDF4(1U) == 0) {
        return;
    }
    var_r8_22965 = 0;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
    M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
    if (M2C_FIELD((void *)0x03004229, u8 *, 2) == 0) {
        var_r0_22986 = 0x29;
    } else {
        var_r0_22986 = 0x31;
    }
    *(u8 *)0x03004228 = var_r0_22986;
    *(s8 *)0x0300423C = 4;
    *(s16 *)0x0300421C = 0x1270;
    if (*(u8 *)0x03004230 == 3) {
        temp_r0_23011 = *(u8 *)0x03004233 - 1;
        *(u8 *)0x03004233 = temp_r0_23011;
        if (temp_r0_23011 & 0x80) {
            *(u8 *)0x03004233 = 0;
        }
        sub_020209E0();
        temp_r0_23023 = *(u16 *)0x030041FA;
        if (temp_r0_23023 != 0) {
            temp_r4_23027 = temp_r0_23023 - 1;
            M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = (s32) (M2C_FIELD(((temp_r4_23027 * 0xC) + 0x0202F7FC), u16 *, 4) | 0x800000);
            var_r6_23040 = M2C_FIELD((void *)0x030041A0, u16 *, 0x64);
            if ((sub_02020A24(temp_r4_23027) << 0x10) != 0) {
                var_r6_23040 = sub_02020A24(temp_r4_23027);
                var_r8_22965 = 1;
            }
            sub_0201FE6C(0);
            goto block_18;
        }
        sub_0201FB9C();
        return;
    }
    if ((s32) ((s32) sub_02019AF0(&gGameState) % 101) <= 0x31) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x80609E;
        var_r6_23040 = sub_02024AEC(0x11U);
    } else {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0x8050C0;
        var_r6_23040 = 0x2512;
        temp_r0_23086 = M2C_FIELD((void *)0x030041A0, u8 *, 0x93) + 1;
        M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = temp_r0_23086;
        if ((u32) temp_r0_23086 > 6U) {
            M2C_FIELD((void *)0x030041A0, u8 *, 0x93) = 6U;
        }
        sub_020209E0();
    }
block_18:
    if (!(0x8000 & M2C_FIELD((void *)0x030041A0, u16 *, 0x7A))) {
        *(0x03003720 + (temp_r7_22957 * 2)) = 0x7777;
        temp_r2_23112 = *(s32 *)0x03001B40;
        var_r4_23114 = 0xF & temp_r7_22957;
        temp_r3_23116 = temp_r7_22957 >> 4;
        *(temp_r2_23112 + 0x24 + ((var_r4_23114 * 2) + (temp_r3_23116 << 5))) = var_r6_23040;
        if (var_r8_22965 == 0) {
            var_r0_23126 = temp_r3_23116 * 2;
            var_r2_23128 = temp_r2_23112 + 0x18F8;
            goto block_23;
        }
    } else {
        *(0x03003920 + (temp_r7_22957 * 2)) = 0x7777;
        temp_r2_23145 = *(void *)0x03001B40;
        var_r4_23114 = 0xF & temp_r7_22957;
        temp_r3_23149 = temp_r7_22957 >> 4;
        *(temp_r2_23145 + 0x224 + ((var_r4_23114 * 2) + (temp_r3_23149 << 5))) = var_r6_23040;
        if (var_r8_22965 == 0) {
            var_r0_23126 = temp_r3_23149 * 2;
            var_r2_23128 = temp_r2_23145 + 0x1918;
block_23:
            temp_r2_23164 = var_r2_23128 + var_r0_23126;
            *temp_r2_23164 |= 1 << var_r4_23114;
        }
    }
}

void sub_02023304(void) {
    s8 var_r0_23203;
    s8 var_r0_23246;
    s8 var_r0_23264;
    u16 temp_r0_23192;
    u8 *var_r5_23213;

    if (sub_0201FDF4(1U) != 0) {
        temp_r0_23192 = *(u16 *)0x0300420E;
        switch (temp_r0_23192) {                    /* irregular */
        case 15:
            if (*(u8 *)0x0300422B == 0) {
                var_r0_23203 = 0x2D;
            } else {
                var_r0_23203 = 0x35;
            }
            *(s8 *)0x03004228 = var_r0_23203;
            var_r5_23213 = (u8 *)0x03004228;
            M2C_FIELD((void *)0x03004233, s8 *, 0) = 0;
            M2C_FIELD((void *)0x03004233, s8 *, 4) = 0x5B;
            break;
        default:
            if (((u32) (u16) (temp_r0_23192 - 0x45) <= 0xCU) || (temp_r0_23192 == 0x54) || (temp_r0_23192 == 0x56)) {
            case 0:
            case 12:
            case 16:
                if (*(void *)0x0300422B == 0) {
                    var_r0_23246 = 0x2F;
                } else {
                    var_r0_23246 = 0x37;
                }
                *(void *)0x03004228 = var_r0_23246;
                var_r5_23213 = (u8 *)0x03004228;
            } else {
                if (*(void *)0x0300422B == 0) {
                    var_r0_23264 = 0x2E;
                } else {
                    var_r0_23264 = 0x36;
                }
                *(void *)0x03004228 = var_r0_23264;
                var_r5_23213 = (u8 *)0x03004228;
                sub_0201FED4(3U, 0x30U);
            }
            break;
        }
        *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*var_r5_23213 * 4)), u16 *, 4);
        *(s8 *)0x03004229 = 0;
        *(s8 *)0x0300423C = 5;
        sub_02026A38(0x1CU);
    }
}

void sub_020233E4(void) {
    u16 temp_r1_23358;
    u16 temp_r2_23314;
    u8 var_r0_23375;

    if (sub_0201FDF4(1U) != 0) {
        temp_r2_23314 = *(u16 *)0x0300420E;
        if (((u32) (u16) (temp_r2_23314 - 1) <= 1U) || (temp_r2_23314 == 8) || (temp_r2_23314 == 9) || (temp_r2_23314 == 0xA) || (temp_r2_23314 == 0xB) || (temp_r2_23314 == 0xE) || (temp_r2_23314 == 0x42) || (temp_r2_23314 == 0x43) || (temp_r2_23314 == 0x44) || (temp_r2_23314 == 0x52) || (temp_r2_23314 == 0x53) || (temp_r2_23314 == 0x55)) {
            sub_0201F8FC(*(u16 *)0x0300420E);
        }
        if (*(u16 *)0x0300420E == 0xF) {
            sub_0201FB9C();
        } else {
            temp_r1_23358 = *(u16 *)0x0300421C;
            if ((temp_r1_23358 != 0x3260) && (temp_r1_23358 != 0x3268)) {
                *(u16 *)0x0300421C = 0x1270;
            }
        }
        if (*(u8 *)0x0300422B == 0) {
            var_r0_23375 = 0x29;
        } else {
            var_r0_23375 = 0x31;
        }
        *(u8 *)0x03004228 = var_r0_23375;
        *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
        *(s8 *)0x03004229 = 0;
        *(s8 *)0x0300423C = 4;
    }
}

void sub_020234B0(void) {
    s32 var_r3_23433;
    s32 var_r3_23492;
    s8 *temp_r1_23541;
    u8 temp_r6_23419;
    void *temp_r1_23532;

    temp_r6_23419 = (u8) M2C_FIELD((void *)0x0300421A, u16 *, 0);
    if (M2C_FIELD((void *)0x0300421A, u8 *, 0x10) == 0) {
        if (*(u8 *)0x03004229 == 0xE) {
            var_r3_23433 = 0x0600C800;
            if (!(0x8000 & M2C_FIELD((void *)0x0300421A, u16 *, 0))) {
                var_r3_23433 = 0x0600C000;
            }
            sub_02020A0C(var_r3_23433 + ((0xF0 & temp_r6_23419) * 8) + ((0xF & temp_r6_23419) * 4), 0x200U);
        }
        if (*(u8 *)0x0300422A == 0) {
            if (*(u8 *)0x03004229 == 1) {
                sub_02026A38(0x1EU);
            }
            if (*(u8 *)0x03004229 == 0xA) {
                sub_02026A38(0x22U);
            }
            if (*(u8 *)0x03004229 == 0x11) {
                sub_02026A38(0x23U);
            }
        }
    }
    if (sub_0201FDF4(1U) != 0) {
        M2C_FIELD((void *)0x030041A0, s32 *, 0x40) = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0xB7) = 0;
        M2C_FIELD(((void *)0x030041A0 + 0xB7), s8 *, 1) = 0;
        var_r3_23492 = 0x0600C800;
        if (!(0x8000 & M2C_FIELD((void *)0x030041A0, u16 *, 0x7A))) {
            var_r3_23492 = 0x0600C000;
        }
        sub_02020A0C(var_r3_23492 + ((0xF0 & temp_r6_23419) * 8) + ((temp_r6_23419 & 0xF) * 4), M2C_FIELD((void *)0x030041A0, u16 *, 0x7C));
        M2C_FIELD((void *)0x030041A0, s16 *, 0x78) = 0x78;
        if (M2C_FIELD((void *)0x030041A0, u16 *, 0x7C) != 0x1270) {
            sub_02026A38(0x24U);
        }
        if (M2C_FIELD((void *)0x030041A0, u8 *, 0x97) == 0x5B) {
            M2C_FIELD((void *)0x030041A0, s8 *, 0xB2) = 0;
            temp_r1_23532 = (void *)0x030041A0 + 0x6E;
            M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
            M2C_FIELD(temp_r1_23532, s8 *, 0x2B) = 0x50;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x93) = 0;
            temp_r1_23541 = (temp_r1_23532 + 0x2B) - 9;
            *temp_r1_23541 = 1;
            *(temp_r1_23541 - 9) = 7;
            sub_02021FA4();
        } else {
            M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = 0x50;
            M2C_FIELD((void *)0x030041A0, s8 *, 0xB2) = 0;
            *(((void *)0x030041A0 + 0xB2) - 0x29) = 0;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = 0;
            sub_02020790();
            M2C_FIELD((void *)0x030041A0, s8 *, 0x8A) = (s8) M2C_FIELD(**(0x02033680 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x88) * 4)), u16 *, 4);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 8);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0xC);
            M2C_FIELD((void *)0x030041A0, s16 *, 0x6E) = 2;
            M2C_FIELD(((void *)0x030041A0 + 0x6E), s8 *, 0x19) = 4;
            sub_020218B0();
        }
        M2C_FIELD((void *)0x030041A0, u16 *, 0x7A) = 0U;
    }
}

void sub_02023628(void) {
    u8 temp_r1_23610;
    u8 var_r0_23622;
    u8 var_r0_23646;

    if (sub_0201FDF4(1U) != 0) {
        temp_r1_23610 = *(u8 *)0x03004228;
        if ((temp_r1_23610 == 0x2F) || (temp_r1_23610 == 0x37)) {
            if (*(void *)0x0300422B == 0) {
                var_r0_23622 = 0x29;
            } else {
                var_r0_23622 = 0x31;
            }
            *(u8 *)0x03004228 = var_r0_23622;
            *(void *)0x0300423C = 4;
            *(s16 *)0x0300421C = 0x1270;
        } else {
            if (*(u8 *)0x0300422B == 0) {
                var_r0_23646 = 0x2C;
            } else {
                var_r0_23646 = 0x34;
            }
            *(u8 *)0x03004228 = var_r0_23646;
            *(s8 *)0x0300423C = 3;
        }
        *(s8 *)0x0300422A = (s8) M2C_FIELD(**(0x02033680 + (*(u8 *)0x03004228 * 4)), u16 *, 4);
        *(s8 *)0x03004229 = 0;
    }
}

void sub_020236B0(void) {
    *(0x0203388C + (*(u8 *)0x0300423C * 4))();
}

void sub_020236D0(void) {
    *(s8 *)0x03004229 = 0;
    *(s8 *)0x0300422A = 0;
    M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
    M2C_FIELD((void *)0x0300420E, s16 *, 2) = 0;
    M2C_FIELD(((void *)0x0300420E + 2), s8 *, 0x18) = 0x5E;
    *(s8 *)0x0300422A = (s8) M2C_FIELD(**(void ***)0x020337F8, u16 *, 4);
    *(s16 *)0x03004220 = 0x2A30;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x030041A0, s32 *, 8) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0);
    M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 4);
    M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 0;
    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 0x14;
}

void sub_02023738(void) {
    if (*(u8 *)0x03004224 == 2) {
        M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
        M2C_FIELD((void *)0x0300420E, s16 *, 2) = 0;
        *(s8 *)0x0300423C = 3;
        return;
    }
    sub_0201FDF4(0U);
    M2C_FIELD((void *)0x03004220, u16 *, 0) = (u16) (M2C_FIELD((void *)0x03004220, u16 *, 0) - 1);
    if ((*(u8 *)0x0300422A == 0) && (M2C_FIELD((void *)0x03004220, u8 *, 9) == 2)) {
        sub_0201FED4(4U, 0x20U);
        sub_02026A38(0x25U);
    }
    if (0x8000 & M2C_FIELD((void *)0x03004220, u16 *, 0)) {
        gGameState.unk_824 |= 0x40;
        gGameState.unk_826 |= 0x40;
        gGameState.unk_828 |= 0x40;
        *(void *)0x03004224 = 1U;
        M2C_FIELD((void *)0x0300420E, s16 *, 0) = 0;
        M2C_FIELD((void *)0x0300420E, s8 *, 0x2E) = 1;
    }
}

void sub_020237E8(void) {
    s32 temp_r0_23855;
    s32 temp_r0_23866;
    s32 temp_r1_23859;
    u16 temp_r0_23847;
    u16 temp_r1_23876;

    temp_r0_23847 = *(u16 *)0x0300420E + 0x1111;
    *(u16 *)0x0300420E = temp_r0_23847;
    if ((temp_r0_23847 << 0x10) == 0xFFFF0000) {
        temp_r0_23855 = M2C_FIELD((void *)0x03003BC4, s32 *, 0) << 8;
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = temp_r0_23855;
        temp_r1_23859 = M2C_FIELD((void *)0x03003BC4, s32 *, 4) << 8;
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (temp_r1_23859 + 0x1000);
        M2C_FIELD((void *)0x03004B80, s32 *, 4) = temp_r1_23859;
        temp_r0_23866 = temp_r0_23855 + 0x1000;
        M2C_FIELD((void *)0x03004B80, s32 *, 0) = temp_r0_23866;
        gGameState.unk_840 = (temp_r0_23866 >> 8) - 0x80;
        temp_r1_23876 = (temp_r1_23859 >> 8) - 0x50;
        gGameState.unk_842 = temp_r1_23876;
        if (temp_r1_23876 & 0x800) {
            gGameState.unk_842 = 0;
        }
        if ((u32) gGameState.unk_842 > 0x60U) {
            gGameState.unk_842 = 0x60;
        }
        if (0x800 & gGameState.unk_840) {
            gGameState.unk_840 = 0;
        }
        if ((u32) gGameState.unk_840 > 0x100U) {
            gGameState.unk_840 = 0x100;
        }
        gGameState.unk_844 = gGameState.unk_840;
        gGameState.unk_846 = gGameState.unk_842;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 2;
    }
    *(u16 *)0x0400004C = M2C_FIELD((void *)0x030041A0, u16 *, 0x6E);
}

void sub_020238BC(void) {
    s8 *temp_r1_23992;
    s8 *temp_r1_23995;
    u16 temp_r0_23950;
    u16 temp_r4_23954;
    void *temp_r1_23984;

    temp_r0_23950 = *(u16 *)0x0300420E + 0xFFFFEEEF;
    *(u16 *)0x0300420E = temp_r0_23950;
    temp_r4_23954 = temp_r0_23950;
    if (temp_r4_23954 == 0) {
        gGameState.unk_824 ^= 0x40;
        gGameState.unk_826 ^= 0x40;
        gGameState.unk_828 ^= 0x40;
        *(s8 *)0x03004224 = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) temp_r4_23954;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) temp_r4_23954;
        temp_r1_23984 = (void *)0x030041A0 + 0x8E;
        M2C_FIELD((void *)0x030041A0, u8 *, 0x8E) = (u8) *(u8 *)0x03003BAA;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x93) = 0;
        M2C_FIELD(temp_r1_23984, s8 *, 0xB) = 0x80;
        temp_r1_23992 = (temp_r1_23984 + 0xB) - 2;
        *temp_r1_23992 = 0x5B;
        temp_r1_23995 = temp_r1_23992 - 7;
        *temp_r1_23995 = 1;
        *(temp_r1_23995 - 9) = 7;
        sub_02021FA4();
    }
    *(u16 *)0x0400004C = *(u16 *)0x0300420E;
}

void sub_02023968(void) {
    if (*(u8 *)0x03004224 == 1) {
        M2C_FIELD((void *)0x03004210, s16 *, 0) = 0x10;
        *(s16 *)0x0300420E = 0;
        M2C_FIELD((void *)0x03004210, s8 *, 0x2C) = 4;
    }
}

void sub_02023994(M2C_UNK arg3) {
    s32 temp_r0_24154;
    s32 temp_r2_24143;
    s32 var_r7_24173;
    s8 temp_r0_24179;
    s8 var_r0_24109;
    u16 *var_r4_24175;
    u16 temp_r1_24055;
    u16 temp_r1_24066;
    u8 *temp_r1_24191;

    temp_r1_24055 = *(u16 *)0x03004210 - 1;
    *(u16 *)0x03004210 = temp_r1_24055;
    if (!(temp_r1_24055 & 0x8000)) {
        return;
    }
    temp_r1_24066 = *(u16 *)0x0300420E;
    switch ((u32) temp_r1_24066) {                  /* irregular */
    case 0:
        sub_0201FED4(1U, 0x30U);
        M2C_FIELD((void *)0x03004229, s8 *, 0) = 0;
        M2C_FIELD((void *)0x03004229, s8 *, 1) = 0;
        *(u16 *)0x0300420E += 1;
        *(void *)0x03004210 = 0x30U;
        return;
    case 1:
        var_r0_24109 = 2;
block_8:
        *(s8 *)0x03004228 = var_r0_24109;
        *(u16 *)0x0300420E += 1;
        *(void *)0x03004210 = 0x20U;
        return;
    case 2:
        var_r0_24109 = 6;
        goto block_8;
    case 3:
        *(void *)0x03004228 = 0;
        *(u16 *)0x0300420E += 1;
        *(void *)0x03004210 = 0x10U;
        return;
    case 4:
        temp_r2_24143 = M2C_FIELD((void *)0x030041A0, s32 *, 8) - M2C_FIELD((void *)0x030041A0, s32 *, 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = temp_r2_24143;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (M2C_FIELD((void *)0x030041A0, s32 *, 0xC) - M2C_FIELD((void *)0x030041A0, s32 *, 4));
        if (temp_r2_24143 < 0) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) (0 - temp_r2_24143);
        }
        temp_r0_24154 = M2C_FIELD((void *)0x030041A0, s32 *, 0x24);
        if (temp_r0_24154 < 0) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) (0 - temp_r0_24154);
        }
        if (((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x20) > 0x2000) || ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x24) > 0x2000)) {
            sub_0201F538(M2C_FIELD((void *)0x030041A0, u8 *, 0x8B));
            var_r7_24173 = 0;
            var_r4_24175 = (void *)0x030041A0 + 0x48;
loop_17:
            temp_r0_24179 = sub_0201F6DC(*var_r4_24175, M2C_FIELD((void *)0x030041A0, u16 **, 0x44));
            if (temp_r0_24179 == 0) {
                var_r4_24175 += 2;
                var_r7_24173 += 1;
                if (var_r7_24173 > 3) {
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 0x59;
                    temp_r1_24191 = ((void *)0x030041A0 + 0x97) - 4;
                    if ((u32) *temp_r1_24191 <= 2U) {
                        *temp_r1_24191 = 3;
                        sub_020209E0();
                    }
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x99) = temp_r0_24179;
                    *(((void *)0x030041A0 + 0x99) - 0x15) = temp_r0_24179;
                    M2C_FIELD((void *)0x030041A0, s8 *, 0x87) = 7;
                    sub_02021FA4();
                    return;
                }
                goto loop_17;
            }
            goto block_22;
        }
block_22:
        M2C_FIELD((void *)0x030041A0, s16 *, 0x70) = 2;
        *(u16 *)0x0300420E = 5;
        return;
    case 5:
        M2C_FIELD((void *)0x030041A0, s32 *, 8) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 0xC) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 4);
        gGameState.unk_824 |= 0x40;
        gGameState.unk_826 |= 0x40;
        gGameState.unk_828 |= 0x40;
        *(u16 *)0x0300420E = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x9C) = 1;
        return;
    }
}

void sub_02023B38(void) {
    *(0x020338A4 + (*(u8 *)0x0300423C * 4))();
}

void sub_02023B58(M2C_UNK arg3) {
    s32 sp0;
    s32 temp_r0_24713;
    s32 temp_r1_24526;
    s32 temp_r1_24565;
    s32 temp_r1_24646;
    s32 temp_r3_24420;
    s32 var_r0_24607;
    s32 var_r1_24606;
    u16 temp_r2_24484;
    u32 temp_r3_24487;
    u32 var_r3_24399;
    u8 temp_r0_24465;
    u8 temp_r0_24559;
    u8 temp_r0_24574;
    u8 temp_r0_24654;
    u8 temp_r1_24357;
    u8 temp_r1_24385;
    u8 temp_r1_24536;
    u8 temp_r2_24347;
    u8 temp_r2_24375;
    u8 temp_r2_24392;
    u8 temp_r3_24364;
    void *temp_r4_24329;
    void *var_r6_24306;

    M2C_FIELD((void *)0x030041A0, s32 *, 0x24) = (s32) ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 4) >> 8);
    M2C_FIELD((void *)0x030041A0, s32 *, 0x20) = (s32) ((s32) M2C_FIELD((void *)0x030041A0, s32 *, 0) >> 8);
    var_r6_24306 = **((M2C_FIELD(((void *)0x030041A0 + 0x88), u8 *, 1) * 4) + *(0x02033680 + (M2C_FIELD((void *)0x030041A0, u8 *, 0x88) * 4)));
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x8A) == 0xFE) {
        return;
    }
    sp0 = 0;
    if (M2C_FIELD(var_r6_24306, u16 *, 6) == 0xFFFF) {
        return;
    }
loop_5:
    temp_r4_24329 = (*(u8 *)0x030023B0 * 8) + gUnk3002410;
    M2C_FIELD(temp_r4_24329, s8 *, 0) = (s8) ((M2C_FIELD(var_r6_24306, u8 *, 0) + M2C_FIELD((void *)0x030041A0, s32 *, 0x24)) - M2C_FIELD(&gGameState, u8 *, 0x846));
    temp_r2_24347 = (-0xD & M2C_FIELD(temp_r4_24329, u8 *, 1)) | (0xC & M2C_FIELD(var_r6_24306, u8 *, 1));
    M2C_FIELD(temp_r4_24329, u8 *, 1) = temp_r2_24347;
    temp_r1_24357 = (-0x21 & temp_r2_24347) | ((((u32) (M2C_FIELD(var_r6_24306, u8 *, 1) << 0x1A) >> 0x1F) & 1) << 5);
    M2C_FIELD(temp_r4_24329, u8 *, 1) = temp_r1_24357;
    temp_r3_24364 = (0x3F & temp_r1_24357) | (((u8) M2C_FIELD(var_r6_24306, u8 *, 1) >> 6) << 6);
    M2C_FIELD(temp_r4_24329, u8 *, 1) = temp_r3_24364;
    temp_r2_24375 = (-0x11 & M2C_FIELD(temp_r4_24329, u8 *, 3)) | ((((u32) (M2C_FIELD(var_r6_24306, u8 *, 3) << 0x1B) >> 0x1F) & 1) * 0x10);
    M2C_FIELD(temp_r4_24329, u8 *, 3) = temp_r2_24375;
    temp_r1_24385 = (-0x21 & temp_r2_24375) | ((((u32) (M2C_FIELD(var_r6_24306, u8 *, 3) << 0x1A) >> 0x1F) & 1) << 5);
    M2C_FIELD(temp_r4_24329, u8 *, 3) = temp_r1_24385;
    temp_r2_24392 = (0x3F & temp_r1_24385) | (((u8) M2C_FIELD(var_r6_24306, u8 *, 3) >> 6) << 6);
    M2C_FIELD(temp_r4_24329, u8 *, 3) = temp_r2_24392;
    M2C_FIELD(temp_r4_24329, u8 *, 1) = (u8) (temp_r3_24364 | 0x10);
    var_r3_24399 = (u32) (M2C_FIELD(var_r6_24306, u16 *, 2) << 0x17) >> 0x17;
    if (*(0x02033AC4 + M2C_FIELD((void *)0x030041A0, u8 *, 0x88)) != 0) {
        M2C_FIELD(temp_r4_24329, u8 *, 3) = (u8) ((temp_r2_24392 & ~0x10) | (((((u32) (M2C_FIELD(var_r6_24306, u8 *, 3) << 0x1B) >> 0x1F) ^ 1) & 1) * 0x10));
        temp_r3_24420 = ~var_r3_24399 + 1;
        if (((s32) M2C_FIELD(temp_r4_24329, s8 *, 0) & 0xC000C000) == 0x40000000) {
            var_r3_24399 = temp_r3_24420 - 0x10;
        } else {
            var_r3_24399 = temp_r3_24420 - 8;
        }
    }
    M2C_FIELD(temp_r4_24329, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r4_24329, u16 *, 2)) | (((var_r3_24399 + M2C_FIELD((void *)0x030041A0, s32 *, 0x20)) - gGameState.unk_844) & 0x1FF));
    temp_r0_24465 = (-0xD & M2C_FIELD(temp_r4_24329, u8 *, 5)) | 4;
    M2C_FIELD(temp_r4_24329, u8 *, 5) = temp_r0_24465;
    M2C_FIELD(temp_r4_24329, u8 *, 5) = (u8) ((temp_r0_24465 & 0xF) | (((u8) M2C_FIELD(var_r6_24306, u8 *, 5) >> 4) * 0x10));
    temp_r2_24484 = (0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4)) | ((u32) (M2C_FIELD(var_r6_24306, u16 *, 4) << 0x16) >> 0x16);
    M2C_FIELD(temp_r4_24329, u16 *, 4) = temp_r2_24484;
    temp_r3_24487 = M2C_FIELD((void *)0x030041A0, u32 *, 0x40);
    if ((0xFFFF0000 & temp_r3_24487) && ((u16) temp_r3_24487 != 0) && (((u32) (temp_r2_24484 << 0x16) >> 0x16) == (u16) (temp_r3_24487 >> 0x10))) {
        M2C_FIELD(temp_r4_24329, u16 *, 4) = (u16) ((temp_r2_24484 & 0xFFFFFC00) | (temp_r3_24487 & 0xFFF & 0x3FF));
        M2C_FIELD(temp_r4_24329, u8 *, 5) = (u8) ((0xF & M2C_FIELD(temp_r4_24329, u8 *, 5)) | ((u32) (M2C_FIELD((void *)0x030041A0, u32 *, 0x40) & 0xF000) >> 8));
    }
    temp_r1_24526 = 0xF & M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
    if ((temp_r1_24526 == 6) || (temp_r1_24526 == 8) || (temp_r1_24526 == 5) || (temp_r1_24526 == 7)) {
        temp_r1_24536 = M2C_FIELD(temp_r4_24329, u8 *, 5);
        if ((0xF0 & temp_r1_24536) == 0x20) {
            M2C_FIELD(temp_r4_24329, u8 *, 5) = (u8) ((0xF & temp_r1_24536) | 0x80);
        }
    }
    if ((u32) (u8) (M2C_FIELD((void *)0x030041A0, u8 *, 0x87) - 3) > 1U) {

    } else {
        temp_r0_24559 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8B);
        if (temp_r0_24559 == 0) {
            temp_r1_24565 = 0x3FF & M2C_FIELD(var_r6_24306, u16 *, 4);
            if ((temp_r1_24565 != 0x40) && (temp_r1_24565 != 0x42)) {

            } else {
                temp_r0_24574 = M2C_FIELD((void *)0x030041A0, u8 *, 0x90);
                switch (temp_r0_24574) {            /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x91) == 0) {
                        var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                        var_r0_24607 = 0x40;
                    } else {
                        var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                        var_r0_24607 = 0x42;
                    }
                    goto block_56;
                case 1:                             /* switch 1 */
                    var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                    var_r0_24607 = 0x44;
                    goto block_56;
                case 2:                             /* switch 1 */
                    var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                    var_r0_24607 = 0x46;
                    goto block_56;
                case 3:                             /* switch 1 */
                    var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                    var_r0_24607 = 0x48;
                    goto block_56;
                }
            }
        } else if ((((u32) (u8) (temp_r0_24559 - 1) <= 1U) || (temp_r0_24559 == 6) || (temp_r0_24559 == 7)) && ((temp_r1_24646 = 0x3FF & M2C_FIELD(var_r6_24306, u16 *, 4), (temp_r1_24646 == 0)) || (temp_r1_24646 == 2))) {
            temp_r0_24654 = M2C_FIELD((void *)0x030041A0, u8 *, 0x90);
            switch (temp_r0_24654) {                /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                if (M2C_FIELD((void *)0x030041A0, u8 *, 0x91) == 0) {
                    M2C_FIELD(temp_r4_24329, u16 *, 4) = (u16) (0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4));
                } else {
                    var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                    var_r0_24607 = 2;
block_56:
                    M2C_FIELD(temp_r4_24329, u16 *, 4) = (u16) (var_r1_24606 | var_r0_24607);
                }
                break;
            case 1:                                 /* switch 2 */
                var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                var_r0_24607 = 4;
                goto block_56;
            case 2:                                 /* switch 2 */
                var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                var_r0_24607 = 6;
                goto block_56;
            case 3:                                 /* switch 2 */
                var_r1_24606 = 0xFFFFFC00 & M2C_FIELD(temp_r4_24329, u16 *, 4);
                var_r0_24607 = 8;
                goto block_56;
            }
        }
    }
    *(void *)0x030023B0 = (u8) (*(void *)0x030023B0 + 1);
    temp_r0_24713 = sp0 + 1;
    sp0 = temp_r0_24713;
    var_r6_24306 += 8;
    if ((temp_r0_24713 <= 0x21) && (M2C_FIELD(var_r6_24306, u16 *, 6) != 0xFFFF)) {
        goto loop_5;
    }
}

s32 sub_02023ED8(u16 arg0) {
    s32 var_r2_24741;
    u16 temp_r1_24740;

    temp_r1_24740 = arg0;
    var_r2_24741 = 0;
    if ((temp_r1_24740 == 0x2511) || ((u32) (u16) (temp_r1_24740 + 0xFFFFE114) <= 0x63U) || (temp_r1_24740 == 0xFEA6)) {
        var_r2_24741 = 1;
    }
    return var_r2_24741;
}

s32 sub_02023F0C(u16 arg0) {
    s32 var_r3_24769;

    var_r3_24769 = 0;
    if (((u32) ((arg0 << 0x10) + 0xEA500000) <= 0x01FB0000U) || (arg0 == 0xFEA8)) {
        var_r3_24769 = 1;
    }
    return var_r3_24769;
}

s32 sub_02023F38(u16 arg0) {
    s32 var_r2_24794;

    var_r2_24794 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xE2580000) >> 0x10) <= 0x4FU) || (arg0 == 0xFEA4)) {
        var_r2_24794 = 1;
    }
    return var_r2_24794;
}

s32 sub_02023F60(u16 arg0) {
    s32 temp_r1_24852;
    s32 var_r3_24819;
    u16 temp_r2_24818;

    temp_r2_24818 = arg0;
    var_r3_24819 = 0;
    if ((temp_r2_24818 != 0x2511) && ((u32) (u16) (temp_r2_24818 + 0xFFFFE114) > 0x63U) && (temp_r2_24818 != 0xFEA6) && ((u32) ((temp_r2_24818 + 0xFFFFEA50) << 0x10) > 0x01FB0000U) && (temp_r2_24818 != 0xFEA8) && ((u32) (u16) (temp_r2_24818 + 0xFFFFE258) > 0x4FU) && (temp_r2_24818 != 0xFEA4) && ((temp_r1_24852 = 0xF000 & temp_r2_24818, (temp_r1_24852 == 0x1000)) || (temp_r1_24852 == 0x3000) || (temp_r2_24818 == 0xFEA1) || (temp_r2_24818 == 0xFEA2) || (temp_r2_24818 == 0xFEA3) || (temp_r2_24818 == 0xFEA5))) {
        var_r3_24819 = 1;
    }
    return var_r3_24819;
}

s32 sub_02024000(s32 arg0) {
    s32 var_r2_24894;

    var_r2_24894 = 0;
    if ((arg0 << 0x10) == 0x28000000) {
        var_r2_24894 = 1;
    }
    return var_r2_24894;
}

s32 sub_02024018(s32 arg0) {
    s32 var_r2_24910;

    var_r2_24910 = 0;
    if ((arg0 << 0x10) == 0x28040000) {
        var_r2_24910 = 1;
    }
    return var_r2_24910;
}

s32 sub_02024030(s32 arg0) {
    s32 var_r2_24926;

    var_r2_24926 = 0;
    if ((arg0 << 0x10) == 0x28030000) {
        var_r2_24926 = 1;
    }
    return var_r2_24926;
}

s32 sub_02024048(s32 arg0) {
    s32 var_r2_24942;

    var_r2_24942 = 0;
    if ((arg0 << 0x10) == 0x28020000) {
        var_r2_24942 = 1;
    }
    return var_r2_24942;
}

s32 sub_02024060(s32 arg0) {
    s32 var_r2_24958;

    var_r2_24958 = 0;
    if ((arg0 << 0x10) == 0x28010000) {
        var_r2_24958 = 1;
    }
    return var_r2_24958;
}

s32 sub_02024078(s32 arg0) {
    s32 var_r3_24974;
    u32 temp_r2_24973;

    temp_r2_24973 = arg0 << 0x10;
    var_r3_24974 = 0;
    if (((0xF0000000 & temp_r2_24973) == 0x20000000) && (((temp_r2_24973 >> 0x18) & 0xF) == 0xF)) {
        var_r3_24974 = 1;
    }
    return var_r3_24974;
}

s32 sub_020240A0(s32 arg0) {
    s32 var_r2_24998;

    var_r2_24998 = 0;
    if ((arg0 << 0x10) == 0x28050000) {
        var_r2_24998 = 1;
    }
    return var_r2_24998;
}

s32 sub_020240B8(s32 arg0) {
    s32 var_r2_25014;

    var_r2_25014 = 0;
    if ((arg0 << 0x10) == 0x28060000) {
        var_r2_25014 = 1;
    }
    return var_r2_25014;
}

s32 sub_020240D0(s32 arg0) {
    s32 var_r2_25030;

    var_r2_25030 = 0;
    if ((arg0 << 0x10) == 0x21030000) {
        var_r2_25030 = 1;
    }
    return var_r2_25030;
}

s32 sub_020240E8(s32 arg0) {
    s32 var_r2_25046;

    var_r2_25046 = 0;
    if ((arg0 << 0x10) == 0x21000000) {
        var_r2_25046 = 1;
    }
    return var_r2_25046;
}

s32 sub_02024100(s32 arg0) {
    s32 var_r2_25062;

    var_r2_25062 = 0;
    if ((arg0 << 0x10) == 0x21010000) {
        var_r2_25062 = 1;
    }
    return var_r2_25062;
}

s32 sub_02024118(s32 arg0) {
    s32 var_r2_25078;

    var_r2_25078 = 0;
    if ((arg0 << 0x10) == 0x21020000) {
        var_r2_25078 = 1;
    }
    return var_r2_25078;
}

s32 sub_02024130(u16 arg0) {
    if (((u32) ((u32) ((arg0 << 0x10) + 0xD6FE0000) >> 0x10) <= 8U) || (arg0 == 0xFEB1)) {
        return 1;
    }
    return 0;
}

s32 sub_0202415C(u16 arg0) {
    s32 temp_r1_25135;
    s32 var_r6_25121;
    u16 temp_r4_25120;

    temp_r4_25120 = arg0;
    var_r6_25121 = 0;
    if ((sub_02024130(temp_r4_25120) == 0) && ((0xF000 & temp_r4_25120) == 0x2000) && ((temp_r1_25135 = ((u32) (arg0 << 0x10) >> 0x18) & 0xF, (temp_r1_25135 == 0)) || (temp_r1_25135 == 9) || (temp_r1_25135 == 0xC) || (temp_r1_25135 == 0xB) || (temp_r1_25135 == 0xE))) {
        var_r6_25121 = 1;
    }
    return var_r6_25121;
}

s32 sub_020241A0(s32 arg0) {
    s32 var_r2_25158;

    var_r2_25158 = 0;
    if ((arg0 << 0x10) == 0x22000000) {
        var_r2_25158 = 1;
    }
    return var_r2_25158;
}

s32 sub_020241B8(s32 arg0) {
    s32 var_r2_25174;

    var_r2_25174 = 0;
    if ((arg0 << 0x10) == 0x22390000) {
        var_r2_25174 = 1;
    }
    return var_r2_25174;
}

s32 sub_020241D0(u16 arg0) {
    s32 var_r2_25191;
    u16 temp_r1_25190;

    temp_r1_25190 = arg0;
    var_r2_25191 = 0;
    if ((temp_r1_25190 == 0x2201) || (temp_r1_25190 == 0x2243) || (temp_r1_25190 == 0x2242) || (temp_r1_25190 == 0x2241) || (temp_r1_25190 == 0x2240) || (temp_r1_25190 == 0x223F) || (temp_r1_25190 == 0x223E) || (temp_r1_25190 == 0x223D)) {
        var_r2_25191 = 1;
    }
    return var_r2_25191;
}

s32 sub_02024214(s32 arg0) {
    s32 var_r2_25229;

    var_r2_25229 = 0;
    if ((arg0 << 0x10) == 0x223A0000) {
        var_r2_25229 = 1;
    }
    return var_r2_25229;
}

s32 sub_0202422C(s32 arg0) {
    s32 var_r2_25245;

    var_r2_25245 = 0;
    if ((arg0 << 0x10) == 0x22020000) {
        var_r2_25245 = 1;
    }
    return var_r2_25245;
}

s32 sub_02024244(s32 arg0) {
    s32 var_r2_25261;

    var_r2_25261 = 0;
    if ((arg0 << 0x10) == 0x223B0000) {
        var_r2_25261 = 1;
    }
    return var_r2_25261;
}

s32 sub_0202425C(s32 arg0) {
    s32 var_r2_25277;

    var_r2_25277 = 0;
    if ((arg0 << 0x10) == 0x22030000) {
        var_r2_25277 = 1;
    }
    return var_r2_25277;
}

s32 sub_02024274(s32 arg0) {
    s32 var_r2_25293;

    var_r2_25293 = 0;
    if ((arg0 << 0x10) == 0x223C0000) {
        var_r2_25293 = 1;
    }
    return var_r2_25293;
}

s32 sub_0202428C(u16 arg0) {
    s32 var_r2_25309;

    var_r2_25309 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xDDFC0000) >> 0x10) <= 0x1FU) || (arg0 == 0xFEA9)) {
        var_r2_25309 = 1;
    }
    return var_r2_25309;
}

s32 sub_020242B4(s32 arg0) {
    s32 var_r1_25333;

    var_r1_25333 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xDDD30000) >> 0x10) <= 0xBU) {
        var_r1_25333 = 1;
    }
    return var_r1_25333;
}

s32 sub_020242D0(s32 arg0) {
    s32 var_r1_25351;

    var_r1_25351 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xDDBC0000) >> 0x10) <= 7U) {
        var_r1_25351 = 1;
    }
    return var_r1_25351;
}

s32 sub_020242EC(s32 arg0) {
    s32 var_r1_25369;

    var_r1_25369 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xDDB40000) >> 0x10) <= 7U) {
        var_r1_25369 = 1;
    }
    return var_r1_25369;
}

s32 sub_02024308(s32 arg0) {
    s32 var_r1_25387;

    var_r1_25387 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xDDAC0000) >> 0x10) <= 7U) {
        var_r1_25387 = 1;
    }
    return var_r1_25387;
}

s32 sub_02024324(s32 arg0) {
    s32 var_r2_25405;

    var_r2_25405 = 0;
    if ((arg0 << 0x10) == 0x251E0000) {
        var_r2_25405 = 1;
    }
    return var_r2_25405;
}

s32 sub_0202433C(u16 arg0) {
    s32 var_r4_25423;
    u16 temp_r0_25421;

    temp_r0_25421 = arg0;
    var_r4_25423 = 0;
    if ((((0xF000 & temp_r0_25421) == 0x2000) && ((((u32) (arg0 << 0x10) >> 0x18) & 0xF) == 4)) || (temp_r0_25421 == 0xFEAE) || (temp_r0_25421 == 0xFEAF)) {
        var_r4_25423 = 1;
    }
    return var_r4_25423;
}

s32 sub_02024378(u16 arg0) {
    s32 var_r4_25459;
    u16 temp_r0_25457;

    temp_r0_25457 = arg0;
    var_r4_25459 = 0;
    if ((((0xF000 & temp_r0_25457) == 0x2000) && ((((u32) (arg0 << 0x10) >> 0x18) & 0xF) == 6)) || (temp_r0_25457 == 0xFEAA) || (temp_r0_25457 == 0xFEAB)) {
        var_r4_25459 = 1;
    }
    return var_r4_25459;
}

s32 sub_020243B4(u16 arg0) {
    s32 var_r4_25495;
    u16 temp_r0_25493;

    temp_r0_25493 = arg0;
    var_r4_25495 = 0;
    if ((((0xF000 & temp_r0_25493) == 0x2000) && ((((u32) (arg0 << 0x10) >> 0x18) & 0xF) == 7)) || (temp_r0_25493 == 0xFEAC) || (temp_r0_25493 == 0xFEAD)) {
        var_r4_25495 = 1;
    }
    return var_r4_25495;
}

s32 sub_020243F0(u16 arg0) {
    s32 var_r4_25531;
    u16 temp_r0_25529;

    temp_r0_25529 = arg0;
    var_r4_25531 = 0;
    if ((((0xF000 & temp_r0_25529) == 0x2000) && ((((u32) (arg0 << 0x10) >> 0x18) & 0xF) == 0xA)) || (temp_r0_25529 == 0xFEA7)) {
        var_r4_25531 = 1;
    }
    return var_r4_25531;
}

s32 sub_02024428(u16 arg0) {
    s32 var_r2_25562;

    var_r2_25562 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xDAF20000) >> 0x10) <= 2U) || (arg0 == 0xFEB2)) {
        var_r2_25562 = 1;
    }
    return var_r2_25562;
}

s32 sub_02024450(s32 arg0) {
    s32 var_r2_25586;

    var_r2_25586 = 0;
    if ((arg0 << 0x10) == 0x25120000) {
        var_r2_25586 = 1;
    }
    return var_r2_25586;
}

s32 sub_02024468(u16 arg0) {
    s32 var_r2_25602;

    var_r2_25602 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xDAEB0000) >> 0x10) <= 2U) || (arg0 == 0x251A)) {
        var_r2_25602 = 1;
    }
    return var_r2_25602;
}

s32 sub_02024490(u16 arg0) {
    s32 var_r2_25627;
    u16 temp_r1_25626;

    temp_r1_25626 = arg0;
    var_r2_25627 = 0;
    if ((temp_r1_25626 == 0x2514) || (temp_r1_25626 == 0x2518) || (temp_r1_25626 == 0x2519)) {
        var_r2_25627 = 1;
    }
    return var_r2_25627;
}

s32 sub_020244B8(s32 arg0) {
    s32 var_r2_25650;

    var_r2_25650 = 0;
    if ((arg0 << 0x10) == 0x251B0000) {
        var_r2_25650 = 1;
    }
    return var_r2_25650;
}

s32 sub_020244D0(s32 arg0) {
    s32 var_r1_25666;

    var_r1_25666 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xF7C40000) >> 0x10) <= 8U) {
        var_r1_25666 = 1;
    }
    return var_r1_25666;
}

s32 sub_020244EC(s32 arg0) {
    s32 var_r2_25684;

    var_r2_25684 = 0;
    if ((arg0 << 0x10) == 0x08490000) {
        var_r2_25684 = 1;
    }
    return var_r2_25684;
}

s32 sub_02024504(s32 arg0) {
    s32 var_r2_25700;

    var_r2_25700 = 0;
    if ((arg0 << 0x10) == 0x084A0000) {
        var_r2_25700 = 1;
    }
    return var_r2_25700;
}

s32 sub_0202451C(s32 arg0) {
    s32 var_r2_25716;

    var_r2_25716 = 0;
    if ((arg0 << 0x10) == 0x08480000) {
        var_r2_25716 = 1;
    }
    return var_r2_25716;
}

s32 sub_02024534(s32 arg0) {
    s32 var_r2_25732;

    var_r2_25732 = 0;
    if ((arg0 << 0x10) == 0x084B0000) {
        var_r2_25732 = 1;
    }
    return var_r2_25732;
}

s32 sub_0202454C(s32 arg0) {
    s32 var_r2_25748;

    var_r2_25748 = 0;
    if ((arg0 << 0x10) == 0x084C0000) {
        var_r2_25748 = 1;
    }
    return var_r2_25748;
}

s32 sub_02024564(s32 arg0) {
    s32 var_r2_25764;

    var_r2_25764 = 0;
    if ((arg0 << 0x10) == 0x084D0000) {
        var_r2_25764 = 1;
    }
    return var_r2_25764;
}

s32 sub_0202457C(s32 arg0) {
    s32 var_r2_25780;

    var_r2_25780 = 0;
    if ((arg0 << 0x10) == 0x08450000) {
        var_r2_25780 = 1;
    }
    return var_r2_25780;
}

s32 sub_02024594(s32 arg0) {
    s32 var_r2_25796;

    var_r2_25796 = 0;
    if ((arg0 << 0x10) == 0x08460000) {
        var_r2_25796 = 1;
    }
    return var_r2_25796;
}

s32 sub_020245AC(s32 arg0) {
    s32 var_r2_25812;

    var_r2_25812 = 0;
    if ((arg0 << 0x10) == 0x08470000) {
        var_r2_25812 = 1;
    }
    return var_r2_25812;
}

s32 sub_020245C4(s32 arg0) {
    s32 var_r2_25828;

    var_r2_25828 = 0;
    if ((arg0 << 0x10) == 0x28070000) {
        var_r2_25828 = 1;
    }
    return var_r2_25828;
}

s32 sub_020245DC(s32 arg0) {
    s32 var_r2_25844;

    var_r2_25844 = 0;
    if ((arg0 << 0x10) == 0x58500000) {
        var_r2_25844 = 1;
    }
    return var_r2_25844;
}

s32 sub_020245F4(s32 arg0) {
    s32 var_r2_25860;

    var_r2_25860 = 0;
    if ((arg0 << 0x10) == 0x58510000) {
        var_r2_25860 = 1;
    }
    return var_r2_25860;
}

s32 sub_0202460C(u16 arg0) {
    s32 var_r2_25877;
    u16 temp_r1_25876;

    temp_r1_25876 = arg0;
    var_r2_25877 = 0;
    if ((temp_r1_25876 == 0x800) || (temp_r1_25876 == 0x805) || (temp_r1_25876 == 0x80D) || (temp_r1_25876 == 0x815) || (temp_r1_25876 == 0x81D) || (temp_r1_25876 == 0x825) || (temp_r1_25876 == 0x82D) || (temp_r1_25876 == 0x832) || (temp_r1_25876 == 0x837) || (temp_r1_25876 == 0x84F)) {
        var_r2_25877 = 1;
    }
    return var_r2_25877;
}

s32 sub_0202465C(u16 arg0) {
    s32 var_r2_25922;
    u16 temp_r1_25921;

    temp_r1_25921 = arg0;
    var_r2_25922 = 0;
    if ((temp_r1_25921 == 0x801) || (temp_r1_25921 == 0x806) || (temp_r1_25921 == 0x80E) || (temp_r1_25921 == 0x816) || (temp_r1_25921 == 0x81E) || (temp_r1_25921 == 0x826) || (temp_r1_25921 == 0x82E) || (temp_r1_25921 == 0x833) || (temp_r1_25921 == 0x838) || (temp_r1_25921 == 0x850)) {
        var_r2_25922 = 1;
    }
    return var_r2_25922;
}

s32 sub_020246AC(u16 arg0) {
    s32 var_r2_25967;
    u16 temp_r1_25966;

    temp_r1_25966 = arg0;
    var_r2_25967 = 0;
    if ((temp_r1_25966 == 0x802) || (temp_r1_25966 == 0x807) || (temp_r1_25966 == 0x80F) || (temp_r1_25966 == 0x817) || (temp_r1_25966 == 0x81F) || (temp_r1_25966 == 0x827) || (temp_r1_25966 == 0x82F) || (temp_r1_25966 == 0x834) || (temp_r1_25966 == 0x839) || (temp_r1_25966 == 0x851)) {
        var_r2_25967 = 1;
    }
    return var_r2_25967;
}

s32 sub_020246FC(u16 arg0) {
    s32 var_r2_26012;
    u16 temp_r1_26011;

    temp_r1_26011 = arg0;
    var_r2_26012 = 0;
    if ((temp_r1_26011 == 0x803) || (temp_r1_26011 == 0x808) || (temp_r1_26011 == 0x810) || (temp_r1_26011 == 0x818) || (temp_r1_26011 == 0x820) || (temp_r1_26011 == 0x828) || (temp_r1_26011 == 0x830) || (temp_r1_26011 == 0x835) || (temp_r1_26011 == 0x83A) || (temp_r1_26011 == 0x852)) {
        var_r2_26012 = 1;
    }
    return var_r2_26012;
}

s32 sub_0202474C(u16 arg0) {
    s32 var_r2_26056;
    u16 temp_r1_26057;

    var_r2_26056 = 0;
    temp_r1_26057 = arg0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xFFA20000) >> 0x10) <= 1U) || (temp_r1_26057 == 0x69) || (temp_r1_26057 == 0x804) || ((u32) (u16) (temp_r1_26057 + 0xFFFFF7F7) <= 2U) || ((u32) (u16) (temp_r1_26057 - 0x811) <= 2U) || ((u32) (u16) (temp_r1_26057 - 0x819) <= 2U) || ((u32) (u16) (temp_r1_26057 - 0x821) <= 2U) || ((u32) (u16) (temp_r1_26057 - 0x829) <= 2U) || (temp_r1_26057 == 0x831) || (temp_r1_26057 == 0x836) || (temp_r1_26057 == 0x83B) || (temp_r1_26057 == 0x853)) {
        var_r2_26056 = 1;
    }
    return var_r2_26056;
}

s32 sub_020247D4(s32 arg0) {
    s32 var_r2_26126;

    var_r2_26126 = 0;
    if ((arg0 << 0x10) == 0x084E0000) {
        var_r2_26126 = 1;
    }
    return var_r2_26126;
}

s32 sub_020247EC(s32 arg0) {
    s32 var_r2_26142;

    var_r2_26142 = 0;
    if ((arg0 << 0x10) == 0x080C0000) {
        var_r2_26142 = 1;
    }
    return var_r2_26142;
}

s32 sub_02024804(s32 arg0) {
    s32 var_r2_26158;

    var_r2_26158 = 0;
    if ((arg0 << 0x10) == 0x08140000) {
        var_r2_26158 = 1;
    }
    return var_r2_26158;
}

s32 sub_0202481C(s32 arg0) {
    s32 var_r2_26174;

    var_r2_26174 = 0;
    if ((arg0 << 0x10) == 0x081C0000) {
        var_r2_26174 = 1;
    }
    return var_r2_26174;
}

s32 sub_02024834(s32 arg0) {
    s32 var_r2_26190;

    var_r2_26190 = 0;
    if ((arg0 << 0x10) == 0x08240000) {
        var_r2_26190 = 1;
    }
    return var_r2_26190;
}

s32 sub_0202484C(s32 arg0) {
    s32 var_r2_26206;

    var_r2_26206 = 0;
    if ((arg0 << 0x10) == 0x082C0000) {
        var_r2_26206 = 1;
    }
    return var_r2_26206;
}

s32 sub_02024864(u16 arg0) {
    s32 var_r1_26223;

    var_r1_26223 = 0;
    if (arg0 == 1) {
        var_r1_26223 = 1;
    }
    return var_r1_26223;
}

s32 sub_02024878(u16 arg0) {
    s32 var_r1_26237;

    var_r1_26237 = 0;
    if (arg0 == 2) {
        var_r1_26237 = 1;
    }
    return var_r1_26237;
}

s32 sub_0202488C(u16 arg0) {
    s32 var_r1_26251;

    var_r1_26251 = 0;
    if (arg0 == 3) {
        var_r1_26251 = 1;
    }
    return var_r1_26251;
}

s32 sub_020248A0(u16 arg0) {
    s32 var_r1_26265;

    var_r1_26265 = 0;
    if (arg0 == 4) {
        var_r1_26265 = 1;
    }
    return var_r1_26265;
}

s32 sub_020248B4(s32 arg0) {
    s32 var_r2_26278;

    var_r2_26278 = 0;
    if ((arg0 << 0x10) == 0x08540000) {
        var_r2_26278 = 1;
    }
    return var_r2_26278;
}

s32 sub_020248CC(s32 arg0) {
    s32 var_r2_26294;

    var_r2_26294 = 0;
    if ((arg0 << 0x10) == 0x08550000) {
        var_r2_26294 = 1;
    }
    return var_r2_26294;
}

s32 sub_020248E4(s32 arg0) {
    s32 var_r2_26310;

    var_r2_26310 = 0;
    if ((arg0 << 0x10) == 0x08560000) {
        var_r2_26310 = 1;
    }
    return var_r2_26310;
}

s32 sub_020248FC(s32 arg0) {
    s32 var_r2_26326;

    var_r2_26326 = 0;
    if ((arg0 << 0x10) == 0x08570000) {
        var_r2_26326 = 1;
    }
    return var_r2_26326;
}

s32 sub_02024914(s32 arg0) {
    s32 var_r1_26342;

    var_r1_26342 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xF7A80000) >> 0x10) <= 2U) {
        var_r1_26342 = 1;
    }
    return var_r1_26342;
}

s32 sub_02024930(s32 arg0) {
    s32 var_r2_26360;

    var_r2_26360 = 0;
    if ((arg0 << 0x10) == 0x085C0000) {
        var_r2_26360 = 1;
    }
    return var_r2_26360;
}

s32 sub_02024948(s32 arg0) {
    s32 var_r2_26376;

    var_r2_26376 = 0;
    if ((arg0 << 0x10) == 0x085B0000) {
        var_r2_26376 = 1;
    }
    return var_r2_26376;
}

s32 sub_02024960(u16 arg0) {
    s32 var_r1_26393;

    var_r1_26393 = 0;
    if (arg0 == 0x70) {
        var_r1_26393 = 1;
    }
    return var_r1_26393;
}

s32 sub_02024974(u16 arg0) {
    s32 var_r1_26407;

    var_r1_26407 = 0;
    if (arg0 == 0x71) {
        var_r1_26407 = 1;
    }
    return var_r1_26407;
}

s32 sub_02024988(u16 arg0) {
    s32 var_r1_26421;

    var_r1_26421 = 0;
    if (arg0 == 0x72) {
        var_r1_26421 = 1;
    }
    return var_r1_26421;
}

s32 sub_0202499C(u16 arg0) {
    s32 var_r1_26435;

    var_r1_26435 = 0;
    if (arg0 == 0x73) {
        var_r1_26435 = 1;
    }
    return var_r1_26435;
}

s32 sub_020249B0(s32 arg0) {
    s32 var_r2_26448;

    var_r2_26448 = 0;
    if ((arg0 << 0x10) == 0x584E0000) {
        var_r2_26448 = 1;
    }
    return var_r2_26448;
}

s32 sub_020249C8(u16 arg0) {
    s32 var_r2_26464;

    var_r2_26464 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xFFEF0000) >> 0x10) <= 0x18U) || (arg0 == 0xFEB0)) {
        var_r2_26464 = 1;
    }
    return var_r2_26464;
}

s32 sub_020249F0(s32 arg0) {
    s32 var_r1_26488;

    var_r1_26488 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xFFD60000) >> 0x10) <= 0x31U) {
        var_r1_26488 = 1;
    }
    return var_r1_26488;
}

s32 sub_02024A0C(s32 arg0) {
    s32 var_r2_26506;

    var_r2_26506 = 0;
    if ((arg0 << 0x10) == 0x085D0000) {
        var_r2_26506 = 1;
    }
    return var_r2_26506;
}

s32 sub_02024A24(s32 arg0) {
    s32 var_r2_26522;

    var_r2_26522 = 0;
    if ((arg0 << 0x10) == 0x08620000) {
        var_r2_26522 = 1;
    }
    return var_r2_26522;
}

s32 sub_02024A3C(s32 arg0) {
    s32 var_r1_26538;

    var_r1_26538 = 0;
    if ((u32) ((u32) ((arg0 << 0x10) + 0xFFF80000) >> 0x10) <= 2U) {
        var_r1_26538 = 1;
    }
    return var_r1_26538;
}

s32 sub_02024A58(u16 arg0) {
    s32 var_r2_26556;

    var_r2_26556 = 0;
    if (((u32) ((u32) ((arg0 << 0x10) + 0xFF9D0000) >> 0x10) <= 4U) || ((u32) (u16) (arg0 - 0x6A) <= 4U)) {
        var_r2_26556 = 1;
    }
    return var_r2_26556;
}

s32 sub_02024A84(s32 arg0) {
    s32 var_r2_26582;

    var_r2_26582 = 0;
    if ((arg0 << 0x10) == 0xFFFF0000) {
        var_r2_26582 = 1;
    }
    return var_r2_26582;
}

s32 sub_02024A9C(u16 arg0) {
    s32 (**var_r5_26600)(u16);
    s32 var_r4_26599;

    var_r4_26599 = 0;
    var_r5_26600 = (s32 (**)(u16))0x02034204;
loop_1:
    if (*var_r5_26600(arg0) != 0) {
        return var_r4_26599;
    }
    var_r5_26600 += 8;
    var_r4_26599 += 1;
    if (var_r4_26599 > 0x57) {
        return -1;
    }
    goto loop_1;
}

u16 sub_02024AD0(u32 arg0) {
    if (arg0 > 0x57U) {
        return 0U;
    }
    return M2C_FIELD(((arg0 * 8) + 0x02034204), u16 *, 4);
}

u16 sub_02024AEC(u32 arg0) {
    if (arg0 > 0x11U) {
        return 0U;
    }
    return *(0x020344C4 + (arg0 * 2));
}

void sub_02024B08(s32 arg0, u16 arg1, u8 arg2, u8 arg3) {
    s32 temp_r0_26750;
    s32 temp_r1_26698;
    s32 temp_r4_26668;
    u8 temp_r0_26705;
    void *temp_r2_26695;
    void *temp_r4_26670;

    temp_r4_26668 = arg1 * 0x2C;
    temp_r4_26670 = temp_r4_26668 + 0x03004260;
    M2C_FIELD(temp_r4_26670, u8 *, 0x23) = arg2;
    M2C_FIELD(temp_r4_26670, u8 *, 0x25) = arg3;
    M2C_FIELD((temp_r4_26670 + 0x25), s8 *, 2) = 0;
    M2C_FIELD(temp_r4_26670, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r4_26670, s32 *, 0x14) = 0;
    M2C_FIELD(temp_r4_26670, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r4_26670, s16 *, 0x20) = 0;
    M2C_FIELD(temp_r4_26670, s8 *, 0x28) = 0;
    temp_r2_26695 = (M2C_FIELD(temp_r4_26670, u8 *, 0x23) * 0x18) + 0x020344F8;
    temp_r1_26698 = arg0 * 0x30;
    M2C_FIELD(temp_r4_26670, s8 *, 0x22) = 1;
    temp_r0_26705 = M2C_FIELD(temp_r4_26670, u8 *, 0x23);
    switch (temp_r0_26705) {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
    case 22:
        M2C_FIELD(temp_r4_26670, s8 *, 0x22) = 2;
        /* fallthrough */
        temp_r0_26750 = M2C_FIELD((temp_r1_26698 + 0x03003C00), s32 *, 4) + M2C_FIELD(temp_r2_26695, s32 *, 4);
        M2C_FIELD(temp_r4_26670, s32 *, 4) = temp_r0_26750;
        M2C_FIELD(temp_r4_26670, s32 *, 0x14) = temp_r0_26750;
        *(0x03004260 + temp_r4_26668) = (s32) (*(0x03003C00 + temp_r1_26698) + M2C_FIELD(temp_r2_26695, s32 *, 8));
        M2C_FIELD(temp_r4_26670, u8 *, 0x24) = (u8) M2C_FIELD(temp_r2_26695, u8 *, 0x13);
        break;
    }
}

void sub_02024C00(void) {

}

void sub_02024C04(void) {

}

void sub_02024C08(s32 arg0) {
    void *temp_r4_26783;

    temp_r4_26783 = (0x2C * arg0) + 0x03004260;
    sub_02019AF0(&gGameState);
    M2C_FIELD(temp_r4_26783, s32 *, 8) = 0;
    M2C_FIELD(temp_r4_26783, s32 *, 0x18) = 0x200;
    M2C_FIELD(temp_r4_26783, s32 *, 0x1C) = 0x20;
    M2C_FIELD(temp_r4_26783, s8 *, 0x26) = 0x10;
    M2C_FIELD(temp_r4_26783, s8 *, 0x22) = 3;
}

void sub_02024C44(s32 arg0) {
    void *sp0;
    s8 *sp4;
    s32 temp_r0_26839;
    s32 temp_r1_26818;
    s32 temp_r1_26829;
    s32 temp_r1_26834;
    s32 var_r0_26957;
    s32 var_r1_26904;
    s32 var_r1_26959;
    s32 var_r2_26886;
    s32 var_r6_26887;
    s32 var_r7_26905;
    u16 temp_r0_26943;
    u16 temp_r0_26966;
    void *temp_r3_26925;
    void *temp_r4_26820;
    void *temp_r5_26885;

    temp_r1_26818 = 0x2C * arg0;
    temp_r4_26820 = temp_r1_26818 + 0x03004260;
    M2C_FIELD(temp_r4_26820, u8 *, 0x26) = (u8) (M2C_FIELD(temp_r4_26820, u8 *, 0x26) - 1);
    temp_r1_26829 = *(0x03004260 + temp_r1_26818);
    *(0x03004260 + temp_r1_26818) = (s32) (temp_r1_26829 + ((s32) (M2C_FIELD(temp_r4_26820, s32 *, 0x10) - temp_r1_26829) >> 1));
    temp_r1_26834 = M2C_FIELD(temp_r4_26820, s32 *, 8);
    M2C_FIELD(temp_r4_26820, s32 *, 4) = (s32) (M2C_FIELD(temp_r4_26820, s32 *, 0x14) - (temp_r1_26834 >> 8));
    temp_r0_26839 = M2C_FIELD(temp_r4_26820, s32 *, 0x18);
    M2C_FIELD(temp_r4_26820, s32 *, 8) = (s32) (temp_r1_26834 + temp_r0_26839);
    M2C_FIELD(temp_r4_26820, s32 *, 0x18) = (s32) (temp_r0_26839 - M2C_FIELD(temp_r4_26820, s32 *, 0x1C));
    if ((u16) M2C_FIELD(temp_r4_26820, u8 *, 0x26) == 0xC) {
        sub_02026A38(0x17U);
        M2C_FIELD(temp_r4_26820, s8 *, 0x27) = 1;
    }
    if (!(0x80 & M2C_FIELD(temp_r4_26820, u8 *, 0x26))) {
        return;
    }
    if ((s32) M2C_FIELD(temp_r4_26820, s32 *, 0xC) >= (s32) M2C_FIELD(temp_r4_26820, s32 *, 4)) {
        return;
    }
    sp4 = temp_r4_26820 + 0x22;
    sp0 = arg0 + 0x15;
    if (M2C_FIELD(temp_r4_26820, u8 *, 0x28) == 1) {
        temp_r5_26885 = (M2C_FIELD(temp_r4_26820, u8 *, 0x23) * 0x18) + 0x020344F8;
        var_r2_26886 = 0;
        var_r6_26887 = 0;
        do {
            if (M2C_FIELD(temp_r4_26820, u8 *, 0x25) == 0) {
                var_r1_26904 = (0xFF0 & M2C_FIELD(temp_r4_26820, u16 *, 0x20)) * 8;
                var_r7_26905 = 0x0600C000;
            } else {
                var_r1_26904 = (0xFF0 & M2C_FIELD(temp_r4_26820, u16 *, 0x20)) * 8;
                var_r7_26905 = 0x0600C800;
            }
            temp_r3_26925 = var_r1_26904 + var_r7_26905 + var_r2_26886 + ((0xF & M2C_FIELD(temp_r4_26820, u16 *, 0x20)) * 4);
            M2C_FIELD(temp_r3_26925, s16 *, 0) = (s16) (var_r6_26887 + M2C_FIELD(temp_r5_26885, u16 *, 0xE));
            M2C_FIELD(temp_r3_26925, s16 *, 2) = (s16) (var_r6_26887 + M2C_FIELD(temp_r5_26885, u16 *, 0xE) + 1);
            var_r2_26886 += 0x40;
            var_r6_26887 = 2;
        } while (var_r2_26886 <= 0x4F);
        if (M2C_FIELD(temp_r4_26820, u8 *, 0x25) == 0) {
            temp_r0_26943 = M2C_FIELD(temp_r4_26820, u16 *, 0x20);
            *(*(s32 *)0x03001B40 + 0x24 + (((0xF & temp_r0_26943) * 2) + (((temp_r0_26943 >> 4) & 0xF) << 5))) = M2C_FIELD(temp_r5_26885, u16 *, 0x10);
            var_r0_26957 = M2C_FIELD(temp_r4_26820, u16 *, 0x20) * 2;
            var_r1_26959 = 0x03003720;
        } else {
            temp_r0_26966 = M2C_FIELD(temp_r4_26820, u16 *, 0x20);
            *(*(s32 *)0x03001B40 + 0x224 + (((0xF & temp_r0_26966) * 2) + (((temp_r0_26966 >> 4) & 0xF) << 5))) = M2C_FIELD(temp_r5_26885, u16 *, 0x10);
            var_r0_26957 = M2C_FIELD(temp_r4_26820, u16 *, 0x20) * 2;
            var_r1_26959 = 0x03003920;
        }
        *(var_r1_26959 + var_r0_26957) = (s16) M2C_FIELD(temp_r5_26885, u8 *, 0x14);
    }
    *sp4 = 0;
    *(0x03003B27 + (s32) sp0) = 0;
}

void sub_02024DD0(s32 arg0) {
    *(0x020344E8 + (M2C_FIELD(((arg0 * 0x2C) + 0x03004260), u8 *, 0x22) * 4))();
}

void sub_02024DF8(s32 arg0) {
    s32 temp_r1_27039;
    s32 temp_r6_27048;
    u8 temp_r0_27108;
    u8 temp_r2_27079;
    u8 temp_r3_27070;
    void *temp_r1_27041;
    void *temp_r4_27060;
    void *temp_r6_27050;

    temp_r1_27039 = arg0 * 0x2C;
    temp_r1_27041 = temp_r1_27039 + 0x03004260;
    temp_r6_27048 = M2C_FIELD(temp_r1_27041, u8 *, 0x23) * 0x18;
    temp_r6_27050 = temp_r6_27048 + 0x020344F8;
    temp_r4_27060 = (gGameState.unk_860 * 8) + gUnk3002410;
    temp_r3_27070 = (0x3F & M2C_FIELD(temp_r4_27060, u8 *, 1)) | ((((u32) *(0x020344F8 + temp_r6_27048) >> 0xE) & 3) << 6);
    M2C_FIELD(temp_r4_27060, u8 *, 1) = temp_r3_27070;
    temp_r2_27079 = (0x3F & M2C_FIELD(temp_r4_27060, u8 *, 3)) | (((u32) *(0x020344F8 + temp_r6_27048) >> 0x1E) << 6);
    M2C_FIELD(temp_r4_27060, u8 *, 3) = temp_r2_27079;
    M2C_FIELD(temp_r4_27060, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r4_27060, u16 *, 4)) | (0x3FF & M2C_FIELD(temp_r6_27050, u16 *, 0xC)));
    M2C_FIELD(temp_r4_27060, u8 *, 1) = (u8) (temp_r3_27070 | 0x10);
    M2C_FIELD(temp_r4_27060, u8 *, 3) = (u8) ((temp_r2_27079 & ~0x10) | ((M2C_FIELD(temp_r1_27041, u8 *, 0x24) & 1) * 0x10));
    temp_r0_27108 = (-0xD & M2C_FIELD(temp_r4_27060, u8 *, 5)) | 4;
    M2C_FIELD(temp_r4_27060, u8 *, 5) = temp_r0_27108;
    M2C_FIELD(temp_r4_27060, u8 *, 5) = (u8) ((temp_r0_27108 & 0xF) | (M2C_FIELD(temp_r6_27050, u8 *, 0x12) * 0x10));
    M2C_FIELD(temp_r4_27060, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r4_27060, u16 *, 2)) | ((*(0x03004260 + temp_r1_27039) - gGameState.unk_844) & 0x1FF));
    M2C_FIELD(temp_r4_27060, s8 *, 0) = (s8) (M2C_FIELD(temp_r1_27041, s32 *, 4) - M2C_FIELD(&gGameState, u8 *, 0x846));
    gGameState.unk_860 += 1;
}

void sub_02024F08(s32 arg0) {
    s16 *temp_r1_27201;
    s32 temp_r1_27165;
    s32 var_r1_27208;
    void *temp_r0_27220;
    void *temp_r1_27167;
    void *temp_r1_27182;
    void *temp_r1_27197;
    void *var_r0_27207;

    temp_r1_27165 = arg0 * 0x54;
    temp_r1_27167 = temp_r1_27165 + 0x03004790;
    *(0x03004790 + temp_r1_27165) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 4) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 8) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x14) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x18) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x20) = 0;
    M2C_FIELD(temp_r1_27167, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r1_27167, s8 *, 0x4D) = 0;
    temp_r1_27182 = (temp_r1_27167 + 0x4D) - 1;
    M2C_FIELD(temp_r1_27182, s8 *, 0) = 0;
    M2C_FIELD(temp_r1_27182, s8 *, 2) = 0;
    M2C_FIELD((temp_r1_27182 + 2), s8 *, 1) = 0;
    M2C_FIELD(temp_r1_27167, s16 *, 0x40) = 0xA;
    M2C_FIELD(temp_r1_27167, s16 *, 0x3E) = 0;
    M2C_FIELD(temp_r1_27167, s8 *, 0x50) = 0;
    temp_r1_27197 = (temp_r1_27167 + 0x50) - 5;
    M2C_FIELD(temp_r1_27197, s8 *, 0) = 0;
    M2C_FIELD(temp_r1_27197, s8 *, 6) = 0;
    temp_r1_27201 = (temp_r1_27197 + 6) - 0xD;
    *temp_r1_27201 = 0;
    *(temp_r1_27201 - 2) = 0;
    var_r0_27207 = temp_r1_27167 + 0x28;
    var_r1_27208 = 4;
    do {
        M2C_FIELD(var_r0_27207, s16 *, 0) = 0;
        M2C_FIELD(var_r0_27207, s16 *, 0xA) = 0;
        var_r0_27207 += 2;
        var_r1_27208 -= 1;
    } while (var_r1_27208 >= 0);
    M2C_FIELD(temp_r1_27167, s8 *, 0x52) = 0;
    temp_r0_27220 = (temp_r1_27167 + 0x52) - 0xC;
    M2C_FIELD(temp_r0_27220, s16 *, 0) = 0;
    M2C_FIELD(temp_r0_27220, s16 *, 2) = 0;
    M2C_FIELD(temp_r1_27167, s16 *, 0x3C) = 0;
}

void sub_02024F8C(s32 arg0) {
    s32 temp_r0_27251;
    s32 temp_r1_27293;
    s32 temp_r1_27325;
    s32 temp_r1_27343;
    s32 var_r1_27301;
    s32 var_r2_27302;
    u16 temp_r1_27269;
    u16 var_r5_27245;
    u32 temp_r7_27270;
    u8 temp_r4_27271;
    void *temp_r3_27348;
    void *temp_r6_27242;
    void *var_r3_27295;

    temp_r6_27242 = (0x54 * arg0) + 0x03004790;
    var_r5_27245 = M2C_FIELD(temp_r6_27242, u16 *, 0x32);
    if (M2C_FIELD(temp_r6_27242, u8 *, 0x4A) == 0) {
        temp_r0_27251 = var_r5_27245 * 4;
        if (M2C_FIELD((temp_r0_27251 + 0x02034CF4), u8 *, 3) == 0) {
            var_r5_27245 = *(0x02034CF4 + temp_r0_27251);
        } else {
            var_r5_27245 = sub_02024AEC(*(0x02034CF4 + temp_r0_27251));
        }
    }
    temp_r1_27269 = M2C_FIELD(temp_r6_27242, u16 *, 0x3C);
    temp_r7_27270 = temp_r1_27269 << 0x18;
    temp_r4_27271 = (u8) temp_r1_27269;
    if (!(0x1000 & temp_r1_27269)) {
        *(0x03003720 + (temp_r4_27271 * 2)) = (s16) (0x8000 | M2C_FIELD(temp_r6_27242, u16 *, 0x28));
        temp_r1_27293 = 0xF & temp_r4_27271;
        var_r3_27295 = ((0xF0 & temp_r4_27271) * 8) + 0x0600C000 + (temp_r1_27293 * 4);
        var_r1_27301 = (temp_r1_27293 * 2) + ((temp_r7_27270 >> 0x1C) << 5);
        var_r2_27302 = *(s32 *)0x03001B40 + 0x24;
    } else {
        *(0x03003920 + (temp_r4_27271 * 2)) = (s16) (0x8000 | M2C_FIELD(temp_r6_27242, u16 *, 0x28));
        temp_r1_27325 = 0xF & temp_r4_27271;
        var_r3_27295 = ((0xF0 & temp_r4_27271) * 8) + 0x0600C800 + (temp_r1_27325 * 4);
        var_r1_27301 = (temp_r1_27325 * 2) + ((temp_r7_27270 >> 0x1C) << 5);
        var_r2_27302 = *(void *)0x03001B40 + 0x224;
    }
    *(var_r2_27302 + var_r1_27301) = var_r5_27245;
    temp_r1_27343 = M2C_FIELD(temp_r6_27242, u16 *, 0x28) * 0xC;
    M2C_FIELD(var_r3_27295, u16 *, 0) = (u16) *(0x0202F7FC + temp_r1_27343);
    temp_r3_27348 = var_r3_27295 + 2;
    M2C_FIELD(var_r3_27295, s16 *, 2) = (s16) (*(0x0202F7FC + temp_r1_27343) + 1);
    M2C_FIELD(temp_r3_27348, s16 *, 0x3E) = (s16) (*(0x0202F7FC + temp_r1_27343) + 2);
    M2C_FIELD((temp_r3_27348 + 0x3E), s16 *, 2) = (s16) (*(0x0202F7FC + temp_r1_27343) + 3);
    M2C_FIELD((arg0 + 0x03003710), s8 *, 0x41A) = 0;
}

void sub_020250B0(s32 arg0) {
    u16 temp_r0_27388;
    void *temp_r0_27385;

    temp_r0_27385 = (arg0 * 0x54) + 0x03004790;
    temp_r0_27388 = M2C_FIELD(temp_r0_27385, u16 *, 0x40);
    if (temp_r0_27388 == 0) {
        M2C_FIELD((arg0 + 0x03003710), s8 *, 0x41A) = (s8) temp_r0_27388;
        return;
    }
    M2C_FIELD(temp_r0_27385, u16 *, 0x40) = (u16) (temp_r0_27388 - 1);
}

void sub_020250EC(s32 arg0) {
    void *temp_r1_27420;
    void *temp_r2_27415;

    temp_r2_27415 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27420 = temp_r2_27415 + 0x4D;
    M2C_FIELD(temp_r2_27415, s8 *, 0x4D) = (s8) M2C_FIELD(*(void **)0x02034C24, u16 *, 4);
    M2C_FIELD(temp_r1_27420, s8 *, 2) = 1;
    *((temp_r1_27420 + 2) - 1) = 2;
}

void sub_02025118(s32 arg0) {
    s8 temp_r3_27459;
    u8 temp_r0_27447;
    u8 temp_r0_27456;
    void *temp_r1_27441;

    temp_r1_27441 = (0x54 * arg0) + 0x03004790;
    temp_r0_27447 = M2C_FIELD(temp_r1_27441, u8 *, 0x4D) - 1;
    M2C_FIELD(temp_r1_27441, u8 *, 0x4D) = temp_r0_27447;
    if ((temp_r0_27447 << 0x18) == 0) {
        temp_r0_27456 = M2C_FIELD(temp_r1_27441, u8 *, 0x4C) + 1;
        M2C_FIELD(temp_r1_27441, u8 *, 0x4C) = temp_r0_27456;
        temp_r3_27459 = 7 & temp_r0_27456;
        if (temp_r3_27459 == 0) {
            M2C_FIELD((arg0 + 0x03003710), s8 *, 0x41A) = temp_r3_27459;
            return;
        }
        M2C_FIELD(temp_r1_27441, u8 *, 0x4D) = (u8) M2C_FIELD(*(0x02034C24 + (M2C_FIELD(temp_r1_27441, u8 *, 0x4C) * 4)), u16 *, 4);
    }
}

void sub_02025180(s32 arg0) {
    void *temp_r1_27497;
    void *temp_r2_27492;

    temp_r2_27492 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27497 = temp_r2_27492 + 0x4D;
    M2C_FIELD(temp_r2_27492, s8 *, 0x4D) = (s8) M2C_FIELD(*(void **)0x02034C44, u16 *, 4);
    M2C_FIELD(temp_r1_27497, s8 *, 2) = 2;
    *((temp_r1_27497 + 2) - 1) = 4;
}

void sub_020251AC(s32 arg0) {
    u8 temp_r0_27523;
    u8 temp_r0_27532;
    u8 temp_r4_27526;
    void *temp_r1_27518;

    temp_r1_27518 = (0x54 * arg0) + 0x03004790;
    temp_r0_27523 = M2C_FIELD(temp_r1_27518, u8 *, 0x4D) - 1;
    M2C_FIELD(temp_r1_27518, u8 *, 0x4D) = temp_r0_27523;
    temp_r4_27526 = temp_r0_27523;
    if (temp_r4_27526 == 0) {
        temp_r0_27532 = M2C_FIELD(temp_r1_27518, u8 *, 0x4C) + 1;
        M2C_FIELD(temp_r1_27518, u8 *, 0x4C) = temp_r0_27532;
        if ((u32) temp_r0_27532 > 0x13U) {
            M2C_FIELD((arg0 + 0x03003710), u8 *, 0x41A) = temp_r4_27526;
            return;
        }
        M2C_FIELD(temp_r1_27518, u8 *, 0x4D) = (u8) M2C_FIELD(*(0x02034C44 + (M2C_FIELD(temp_r1_27518, u8 *, 0x4C) * 4)), u16 *, 4);
    }
}

void sub_02025210(s32 arg0) {
    u8 temp_r1_27572;
    void *temp_r4_27568;
    void *temp_r5_27576;

    temp_r4_27568 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27572 = M2C_FIELD(temp_r4_27568, u8 *, 0x4B);
    temp_r5_27576 = **(0x02034CE0 + (temp_r1_27572 * 4));
    switch (temp_r1_27572) {
    case 4:
        break;
    case 0:
        sub_02026A38(5U);
        break;
    case 1:
        sub_02026A38(6U);
        break;
    case 2:
        sub_02026A38(7U);
        break;
    case 3:
        sub_02026A38(8U);
        break;
    }
    M2C_FIELD(temp_r4_27568, s8 *, 0x4D) = (s8) M2C_FIELD(temp_r5_27576, u16 *, 4);
    M2C_FIELD(temp_r4_27568, s8 *, 0x4C) = 0;
    M2C_FIELD(temp_r4_27568, s8 *, 0x4F) = 3;
    *((temp_r4_27568 + 0x4F) - 1) = 6;
}

void sub_0202529C(s32 arg0) {
    u8 temp_r0_27643;
    u8 temp_r4_27647;
    void *temp_r1_27665;
    void *temp_r3_27637;

    temp_r3_27637 = (0x54 * arg0) + 0x03004790;
    temp_r0_27643 = M2C_FIELD(temp_r3_27637, u8 *, 0x4D) - 1;
    M2C_FIELD(temp_r3_27637, u8 *, 0x4D) = temp_r0_27643;
    temp_r4_27647 = temp_r0_27643;
    if (temp_r4_27647 == 0) {
        M2C_FIELD(temp_r3_27637, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_r3_27637, u8 *, 0x4C) + 1);
        temp_r1_27665 = *((M2C_FIELD(temp_r3_27637, u8 *, 0x4C) * 4) + *(0x02034CE0 + (M2C_FIELD(temp_r3_27637, u8 *, 0x4B) * 4)));
        if (M2C_FIELD(temp_r1_27665, u8 *, 6) == 0xFF) {
            M2C_FIELD((arg0 + 0x03003710), u8 *, 0x41A) = temp_r4_27647;
            return;
        }
        M2C_FIELD(temp_r3_27637, u8 *, 0x4D) = (u8) M2C_FIELD(temp_r1_27665, u16 *, 4);
    }
}

void sub_02025310(s32 arg0) {
    s32 temp_r4_27693;
    void *temp_r4_27695;

    temp_r4_27693 = 0x54 * arg0;
    temp_r4_27695 = temp_r4_27693 + 0x03004790;
    M2C_FIELD(temp_r4_27695, s32 *, 0xC) = (s32) (*(0x03004790 + temp_r4_27693) << 8);
    M2C_FIELD(temp_r4_27695, s32 *, 0x10) = (s32) (M2C_FIELD(temp_r4_27695, s32 *, 4) << 8);
    M2C_FIELD(temp_r4_27695, s32 *, 8) = 0;
    M2C_FIELD(temp_r4_27695, s32 *, 0x14) = 0x200;
    M2C_FIELD(temp_r4_27695, s32 *, 0x20) = 0x20;
    sub_02026A38(0x1EU);
    M2C_FIELD(temp_r4_27695, s8 *, 0x4F) = 0;
    M2C_FIELD(temp_r4_27695, s8 *, 0x4E) = 8;
}

void sub_02025354(s32 arg0) {
    s32 temp_r0_27741;
    s32 temp_r1_27729;
    s32 temp_r2_27737;
    s32 temp_r3_27739;
    s32 temp_r4_27736;
    u8 temp_r0_27748;
    void *temp_r1_27731;

    temp_r1_27729 = 0x54 * arg0;
    temp_r1_27731 = temp_r1_27729 + 0x03004790;
    *(0x03004790 + temp_r1_27729) = (s32) ((s32) M2C_FIELD(temp_r1_27731, s32 *, 0xC) >> 8);
    temp_r4_27736 = (s32) M2C_FIELD(temp_r1_27731, s32 *, 0x10) >> 8;
    temp_r2_27737 = M2C_FIELD(temp_r1_27731, s32 *, 8);
    temp_r3_27739 = temp_r4_27736 - (temp_r2_27737 >> 8);
    M2C_FIELD(temp_r1_27731, s32 *, 4) = temp_r3_27739;
    temp_r0_27741 = M2C_FIELD(temp_r1_27731, s32 *, 0x14);
    M2C_FIELD(temp_r1_27731, s32 *, 8) = (s32) (temp_r2_27737 + temp_r0_27741);
    M2C_FIELD(temp_r1_27731, s32 *, 0x14) = (s32) (temp_r0_27741 - M2C_FIELD(temp_r1_27731, s32 *, 0x20));
    temp_r0_27748 = M2C_FIELD(temp_r1_27731, u8 *, 0x52);
    if (temp_r0_27748 == 0) {
        if (temp_r3_27739 > (s32) (temp_r4_27736 + 8)) {
            sub_02024F8C(arg0);
        }
    } else {
        M2C_FIELD(temp_r1_27731, u8 *, 0x52) = (u8) (temp_r0_27748 - 1);
    }
}

void sub_020253A8(s32 arg0) {
    s32 temp_r1_27772;
    void *temp_r0_27801;
    void *temp_r1_27774;

    temp_r1_27772 = arg0 * 0x54;
    temp_r1_27774 = temp_r1_27772 + 0x03004790;
    M2C_FIELD(temp_r1_27774, s32 *, 0xC) = (s32) (*(0x03004790 + temp_r1_27772) << 8);
    M2C_FIELD(temp_r1_27774, s32 *, 0x10) = (s32) (M2C_FIELD(temp_r1_27774, s32 *, 4) << 8);
    M2C_FIELD(temp_r1_27774, s32 *, 8) = 0;
    M2C_FIELD(temp_r1_27774, s32 *, 0x20) = 0x20;
    M2C_FIELD(temp_r1_27774, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r1_27774, s8 *, 0x4D) = 0x10;
    M2C_FIELD(temp_r1_27774, s8 *, 0x4C) = 0;
    *((temp_r1_27774 + 0x4D) - 9) = 0x300;
    temp_r0_27801 = temp_r1_27774 + 0x46;
    M2C_FIELD(temp_r1_27774, s16 *, 0x46) = 0;
    M2C_FIELD(temp_r0_27801, s16 *, 2) = 0;
    M2C_FIELD((temp_r0_27801 + 2), s8 *, 7) = 0;
    M2C_FIELD(temp_r1_27774, s8 *, 0x4E) = 0xA;
}

void sub_02025400(s32 arg0) {
    s16 temp_r0_28034;
    s32 temp_r0_27941;
    s32 temp_r1_27824;
    s32 temp_r2_27833;
    s32 temp_r2_27989;
    s32 temp_r2_28035;
    s32 temp_r5_27893;
    u16 temp_r0_27959;
    u16 temp_r4_27891;
    u16 var_r4_27830;
    u8 temp_r0_27980;
    u8 temp_r0_28047;
    void *temp_r1_28012;
    void *temp_r3_27826;
    void *temp_r4_27995;

    temp_r1_27824 = 0x54 * arg0;
    temp_r3_27826 = temp_r1_27824 + 0x03004790;
    var_r4_27830 = 0;
    temp_r2_27833 = M2C_FIELD(temp_r3_27826, s32 *, 0xC) + M2C_FIELD(temp_r3_27826, s32 *, 0x18);
    M2C_FIELD(temp_r3_27826, s32 *, 0xC) = temp_r2_27833;
    *(0x03004790 + temp_r1_27824) = (s32) (temp_r2_27833 >> 8);
    M2C_FIELD(temp_r3_27826, s32 *, 4) = (s32) ((((s32) M2C_FIELD(temp_r3_27826, s32 *, 0x10) >> 8) - M2C_FIELD(temp_r3_27826, s32 *, 0x24)) + ((s32) M2C_FIELD(temp_r3_27826, s32 *, 8) >> 8));
    M2C_FIELD((void *)0x030041A0, s32 *, 0x38) = temp_r2_27833;
    M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_r3_27826, s32 *, 0x10);
    M2C_FIELD(temp_r3_27826, s32 *, 8) = (s32) (M2C_FIELD(temp_r3_27826, s32 *, 8) + M2C_FIELD(temp_r3_27826, s32 *, 0x20));
    if ((s32) M2C_FIELD(temp_r3_27826, s32 *, 0x18) >= 0) {
        if ((s32) *(0x03004790 + temp_r1_27824) > (s32) M2C_FIELD(temp_r3_27826, s32 *, 0x14)) {
            goto block_4;
        }
    } else if ((s32) *(0x03004790 + temp_r1_27824) < (s32) M2C_FIELD(temp_r3_27826, s32 *, 0x14)) {
block_4:
        var_r4_27830 = 1;
    }
    if ((M2C_FIELD((void *)0x030041A0, u16 *, 0x62) != 0) || (var_r4_27830 != 0)) {
        M2C_FIELD(temp_r3_27826, u16 *, 0x42) = (u16) (M2C_FIELD(temp_r3_27826, u16 *, 0x42) + 0xFFFFF900);
        temp_r4_27891 = M2C_FIELD(temp_r3_27826, u16 *, 0x44) + 0x10;
        M2C_FIELD(temp_r3_27826, u16 *, 0x44) = temp_r4_27891;
        temp_r5_27893 = M2C_FIELD(temp_r3_27826, s32 *, 0x24);
        if ((temp_r5_27893 > 0) && !(temp_r4_27891 & 0x10)) {
            M2C_FIELD(temp_r3_27826, s32 *, 0x24) = (s32) (temp_r5_27893 - 1);
        }
        if ((u32) M2C_FIELD(temp_r3_27826, u16 *, 0x44) <= 0x300U) {
            return;
        }
        M2C_FIELD(temp_r3_27826, u16 *, 0x44) = 0x300U;
        M2C_FIELD(temp_r3_27826, u16 *, 0x42) = 0U;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x76) = 0x2A30U;
        M2C_FIELD((void *)0x030041A0, u16 *, 0x76) = (u16) ((0x64 * ((s32) sub_02019AF0(&gGameState) % 109)) + M2C_FIELD((void *)0x030041A0, u16 *, 0x76));
        M2C_FIELD((void *)0x030041A0, s32 *, 0x38) = 0;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x3C) = 0;
        M2C_FIELD((arg0 + 0x03003710), s8 *, 0x41A) = 0;
        return;
    }
    temp_r0_27941 = M2C_FIELD(temp_r3_27826, s32 *, 0x24);
    if (temp_r0_27941 <= 0x17) {
        M2C_FIELD(temp_r3_27826, s32 *, 0x24) = (s32) (temp_r0_27941 + 1);
    }
    M2C_FIELD(temp_r3_27826, u16 *, 0x42) = (u16) (M2C_FIELD(temp_r3_27826, u16 *, 0x42) + 0x700);
    temp_r0_27959 = M2C_FIELD(temp_r3_27826, u16 *, 0x44) - 0x10;
    M2C_FIELD(temp_r3_27826, u16 *, 0x44) = temp_r0_27959;
    if ((u32) temp_r0_27959 <= 0xFFU) {
        M2C_FIELD(temp_r3_27826, u16 *, 0x44) = 0x100U;
        M2C_FIELD(temp_r3_27826, u16 *, 0x42) = var_r4_27830;
        if (M2C_FIELD(temp_r3_27826, u8 *, 0x4D) == 0) {
            M2C_FIELD(temp_r3_27826, u8 *, 0x4D) = 0x10U;
            temp_r0_27980 = M2C_FIELD(temp_r3_27826, u8 *, 0x4C) + 1;
            M2C_FIELD(temp_r3_27826, u8 *, 0x4C) = temp_r0_27980;
            if ((u32) temp_r0_27980 > 4U) {
                M2C_FIELD(temp_r3_27826, u8 *, 0x4C) = 0U;
            }
            temp_r2_27989 = M2C_FIELD(temp_r3_27826, u8 *, 0x4C) * 2;
            temp_r4_27995 = temp_r3_27826 + 0x28;
            if ((*(temp_r3_27826 + 0x32 + temp_r2_27989) == 0) && (*(temp_r4_27995 + temp_r2_27989) == 0)) {
                M2C_FIELD(temp_r3_27826, u8 *, 0x4C) = 0U;
            }
            temp_r1_28012 = (*(temp_r4_27995 + (M2C_FIELD(temp_r3_27826, u8 *, 0x4C) * 2)) * 0xC) + 0x0202F7FC;
            M2C_FIELD(temp_r3_27826, s16 *, 0x3E) = (s16) (0x3FF & M2C_FIELD(temp_r1_28012, u16 *, 4));
            M2C_FIELD(temp_r3_27826, s8 *, 0x50) = (s8) ((u16) M2C_FIELD(temp_r1_28012, u16 *, 4) >> 0xC);
        }
        M2C_FIELD(temp_r3_27826, u8 *, 0x4D) = (u8) (M2C_FIELD(temp_r3_27826, u8 *, 0x4D) - 1);
    }
    temp_r0_28034 = *(0x0202AD34 + (M2C_FIELD(temp_r3_27826, u16 *, 0x46) * 2));
    temp_r2_28035 = temp_r0_28034 >> 2;
    M2C_FIELD(temp_r3_27826, s32 *, 0x20) = temp_r2_28035;
    if (temp_r0_28034 & 0x8000) {
        M2C_FIELD(temp_r3_27826, s32 *, 0x20) = (s32) (temp_r2_28035 | 0xFFFF0000);
    }
    temp_r0_28047 = M2C_FIELD(temp_r3_27826, u16 *, 0x46) + 4;
    M2C_FIELD(temp_r3_27826, u16 *, 0x46) = (u16) temp_r0_28047;
    if (temp_r0_28047 == 0) {
        M2C_FIELD(temp_r3_27826, s32 *, 0x20) = (s32) temp_r0_28047;
    }
}

void sub_020255F0(s32 arg0) {
    *(0x020347E0 + (M2C_FIELD(((arg0 * 0x54) + 0x03004790), u8 *, 0x4E) * 4))();
}

void sub_02025618(s32 arg0) {
    s32 temp_r1_28091;
    void *temp_r2_28106;
    void *temp_r5_28093;

    temp_r1_28091 = arg0 * 0x54;
    temp_r5_28093 = temp_r1_28091 + 0x03004790;
    if (M2C_FIELD(temp_r5_28093, u8 *, 0x4E) == 0xA) {
        temp_r2_28106 = (gGameState.unk_860 * 8) + gUnk3002410;
        M2C_FIELD(temp_r2_28106, s8 *, 0) = (s8) ((((s32) M2C_FIELD(temp_r5_28093, s32 *, 0x10) >> 8) + ((s32) M2C_FIELD(temp_r5_28093, s32 *, 8) >> 8)) - M2C_FIELD(&gGameState, u8 *, 0x846));
        M2C_FIELD(temp_r2_28106, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r2_28106, u16 *, 2)) | ((*(0x03004790 + temp_r1_28091) - (gGameState.unk_844 - 8)) & 0x1FF));
        M2C_FIELD(temp_r2_28106, u8 *, 1) = (u8) (0x3F & M2C_FIELD(temp_r2_28106, u8 *, 1));
        M2C_FIELD(temp_r2_28106, u8 *, 3) = (u8) (0x3F & M2C_FIELD(temp_r2_28106, u8 *, 3));
        M2C_FIELD(temp_r2_28106, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r2_28106, u16 *, 4)) | 0x200);
        M2C_FIELD(temp_r2_28106, u8 *, 5) = (u8) ((((0xF & M2C_FIELD(temp_r2_28106, u8 *, 5)) | 0x10) & ~0xC) | 4);
        gGameState.unk_860 += 1;
    }
}

void sub_020256D0(s32 arg0) {
    s32 sp0;
    s32 sp4;
    M2C_UNK sp8;
    s32 temp_r1_28184;
    s32 temp_r1_28505;
    s32 var_r1_28206;
    s32 var_r8_28246;
    u8 temp_r0_28191;
    u8 temp_r1_28293;
    u8 temp_r1_28339;
    u8 temp_r1_28360;
    u8 temp_r2_28283;
    u8 temp_r2_28329;
    u8 temp_r2_28443;
    u8 var_r0_28209;
    void **var_r1_28188;
    void *temp_r1_28186;
    void *temp_r5_28267;
    void *temp_r5_28418;
    void *var_r3_28244;

    temp_r1_28184 = arg0 * 0x54;
    temp_r1_28186 = temp_r1_28184 + 0x03004790;
    var_r1_28188 = NULL;
    temp_r0_28191 = M2C_FIELD(temp_r1_28186, u8 *, 0x4F);
    switch (temp_r0_28191) {                        /* irregular */
    case 1:
        var_r1_28206 = 0x02034C24;
        var_r0_28209 = M2C_FIELD(temp_r1_28186, u8 *, 0x4C);
block_9:
        var_r1_28188 = *((var_r0_28209 * 4) + var_r1_28206);
        break;
    case 2:
        var_r1_28206 = 0x02034C44;
        var_r0_28209 = M2C_FIELD(temp_r1_28186, u8 *, 0x4C);
        goto block_9;
    case 3:
        var_r0_28209 = M2C_FIELD(temp_r1_28186, u8 *, 0x4C);
        var_r1_28206 = *(0x02034CE0 + (M2C_FIELD(temp_r1_28186, u8 *, 0x4B) * 4));
        goto block_9;
    }
    if (M2C_FIELD(temp_r1_28186, u8 *, 0x4F) == 0) {
        temp_r5_28418 = (gGameState.unk_860 * 8) + gUnk3002410;
        M2C_FIELD(temp_r5_28418, s8 *, 0) = (s8) (M2C_FIELD(temp_r1_28186, s32 *, 4) - M2C_FIELD(&gGameState, u8 *, 0x846));
        M2C_FIELD(temp_r5_28418, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r5_28418, u16 *, 2)) | ((*(0x03004790 + temp_r1_28184) - gGameState.unk_844) & 0x1FF));
        temp_r2_28443 = 0x3F & M2C_FIELD(temp_r5_28418, u8 *, 1);
        M2C_FIELD(temp_r5_28418, u8 *, 1) = temp_r2_28443;
        M2C_FIELD(temp_r5_28418, u8 *, 3) = (u8) ((0x3F & M2C_FIELD(temp_r5_28418, u8 *, 3)) | 0x40);
        M2C_FIELD(temp_r5_28418, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r5_28418, u16 *, 4)) | (0x3FF & M2C_FIELD(temp_r1_28186, u16 *, 0x3E)));
        M2C_FIELD(temp_r5_28418, u8 *, 1) = (u8) (temp_r2_28443 | 0x10);
        M2C_FIELD(temp_r5_28418, u8 *, 5) = (u8) ((((0xF & M2C_FIELD(temp_r5_28418, u8 *, 5)) | (M2C_FIELD(temp_r1_28186, u8 *, 0x50) * 0x10)) & ~0xC) | 4);
        gGameState.unk_860 += 1;
        if (M2C_FIELD(temp_r1_28186, u8 *, 0x4E) == 0xA) {
            M2C_FIELD(temp_r5_28418, u8 *, 3) = (u8) ((-0xF & M2C_FIELD(temp_r5_28418, u8 *, 3)) | 2);
            M2C_FIELD(temp_r5_28418, u8 *, 1) = (u8) (((-4 & M2C_FIELD(temp_r5_28418, u8 *, 1)) | 1) & ~0xC);
            temp_r1_28505 = (sp0 & 0xFFFF0000) | M2C_FIELD(temp_r1_28186, u16 *, 0x44);
            sp0 = temp_r1_28505;
            sp0 = (0xFFFF & temp_r1_28505) | (M2C_FIELD(temp_r1_28186, u16 *, 0x44) << 0x10);
            sp4 = (sp4 & 0xFFFF0000) | M2C_FIELD(temp_r1_28186, u16 *, 0x42);
            ObjAffineSet((struct ObjAffineSrcData *) &sp0, &sp8, 1, 2);
            M2C_FIELD(gUnk3002410, u16 *, 0x26) = (u16) M2C_FIELD(&sp8, u16 *, 0);
            M2C_FIELD(gUnk3002410, u16 *, 0x2E) = (u16) M2C_FIELD(&sp8, u16 *, 2);
            M2C_FIELD(gUnk3002410, u16 *, 0x36) = (u16) M2C_FIELD(&sp8, u16 *, 4);
            M2C_FIELD(gUnk3002410, u16 *, 0x3E) = (u16) M2C_FIELD(&sp8, u16 *, 6);
        }
        return;
    }
    var_r3_28244 = *var_r1_28188;
    var_r8_28246 = 0;
    if (M2C_FIELD(var_r3_28244, u16 *, 6) == 0xFFFF) {
        return;
    }
loop_15:
    temp_r5_28267 = (gGameState.unk_860 * 8) + gUnk3002410;
    M2C_FIELD(temp_r5_28267, s8 *, 0) = (s8) ((M2C_FIELD(var_r3_28244, u8 *, 0) + M2C_FIELD(temp_r1_28186, s32 *, 4)) - M2C_FIELD(&gGameState, u8 *, 0x846));
    temp_r2_28283 = (-0xD & M2C_FIELD(temp_r5_28267, u8 *, 1)) | (0xC & M2C_FIELD(var_r3_28244, u8 *, 1));
    M2C_FIELD(temp_r5_28267, u8 *, 1) = temp_r2_28283;
    temp_r1_28293 = (-0x21 & temp_r2_28283) | ((((u32) (M2C_FIELD(var_r3_28244, u8 *, 1) << 0x1A) >> 0x1F) & 1) << 5);
    M2C_FIELD(temp_r5_28267, u8 *, 1) = temp_r1_28293;
    M2C_FIELD(temp_r5_28267, u8 *, 1) = (u8) ((temp_r1_28293 & 0x3F) | (((u8) M2C_FIELD(var_r3_28244, u8 *, 1) >> 6) << 6));
    M2C_FIELD(temp_r5_28267, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r5_28267, u16 *, 2)) | (((((u32) (M2C_FIELD(var_r3_28244, u16 *, 2) << 0x17) >> 0x17) + *(0x03004790 + temp_r1_28184)) - gGameState.unk_844) & 0x1FF));
    temp_r2_28329 = (-0x11 & M2C_FIELD(temp_r5_28267, u8 *, 3)) | ((M2C_FIELD(temp_r1_28186, u8 *, 0x51) & 1) * 0x10);
    M2C_FIELD(temp_r5_28267, u8 *, 3) = temp_r2_28329;
    temp_r1_28339 = (-0x21 & temp_r2_28329) | ((((u32) (M2C_FIELD(var_r3_28244, u8 *, 3) << 0x1A) >> 0x1F) & 1) << 5);
    M2C_FIELD(temp_r5_28267, u8 *, 3) = temp_r1_28339;
    M2C_FIELD(temp_r5_28267, u8 *, 3) = (u8) ((temp_r1_28339 & 0x3F) | (((u8) M2C_FIELD(var_r3_28244, u8 *, 3) >> 6) << 6));
    M2C_FIELD(temp_r5_28267, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r5_28267, u16 *, 4)) | ((u32) (M2C_FIELD(var_r3_28244, u16 *, 4) << 0x16) >> 0x16));
    temp_r1_28360 = (-0xD & M2C_FIELD(temp_r5_28267, u8 *, 5)) | 4;
    M2C_FIELD(temp_r5_28267, u8 *, 5) = temp_r1_28360;
    if (M2C_FIELD(temp_r1_28186, u8 *, 0x4E) == 6) {
        M2C_FIELD(temp_r5_28267, u8 *, 5) = (u8) (temp_r1_28360 & ~0xC);
    }
    M2C_FIELD(temp_r5_28267, u8 *, 5) = (u8) ((0xF & M2C_FIELD(temp_r5_28267, u8 *, 5)) | (((u8) M2C_FIELD(var_r3_28244, u8 *, 5) >> 4) * 0x10));
    M2C_FIELD(temp_r5_28267, u8 *, 1) = (u8) (M2C_FIELD(temp_r5_28267, u8 *, 1) | 0x10);
    gGameState.unk_860 += 1;
    var_r8_28246 += 1;
    var_r3_28244 += 8;
    if (var_r8_28246 > 0xB) {
        return;
    }
    if (M2C_FIELD(var_r3_28244, u16 *, 6) != 0xFFFF) {
        goto loop_15;
    }
}

s32 sub_020259C8(void) {
    s32 temp_r0_28606;
    s32 temp_r0_28665;
    s32 temp_r0_28747;
    s32 temp_r2_28567;
    s32 temp_r2_28769;
    s32 temp_r3_28735;
    s32 var_r6_28628;
    u16 *var_r6_28561;
    u16 temp_r0_28707;
    u16 temp_r1_28644;
    u16 temp_r3_28583;
    u16 var_r7_28562;
    u32 temp_r2_28709;
    u8 temp_r2_28578;
    u8 temp_r2_28638;

    var_r6_28561 = NULL;
    var_r7_28562 = 0;
    temp_r2_28567 = M2C_FIELD((void *)0x03004B80, s32 *, 0x10);
    M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) = (u8) ((M2C_FIELD((void *)0x03004B80, s32 *, 0x14) & ~0xF) | ((s32) (0xF0 & temp_r2_28567) >> 4));
    if (!(temp_r2_28567 & 0xFF00)) {
        temp_r2_28578 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
        temp_r3_28583 = *(0x03003720 + (temp_r2_28578 * 2));
        if ((temp_r3_28583 != 0xFFF) && (temp_r3_28583 != 0x7777)) {
            goto block_37;
        }
        if ((*(u8 *)0x03004257 == 0) && (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) == *(u8 *)0x03004258)) {
            goto block_37;
        }
        temp_r0_28606 = temp_r2_28578 * 2;
        if ((*(0x03003720 + temp_r0_28606) == 0xFFF) || ((M2C_FIELD((void *)0x03004B80, u8 *, 0x28) == 0) && (temp_r2_28578 == M2C_FIELD((void *)0x03004B80, u8 *, 0x29)))) {
            *(0x03003720 + temp_r0_28606) = 0xFFFU;
            var_r7_28562 = *(0x03003720 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2));
            var_r6_28628 = 0x0600A000;
            goto block_20;
        }
        goto block_21;
    }
    temp_r2_28638 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
    temp_r1_28644 = *(0x03003920 + (temp_r2_28638 * 2));
    if ((temp_r1_28644 != 0xFFF) && (temp_r1_28644 != 0x7777)) {
        goto block_37;
    }
    if ((*(void *)0x03004257 == 0) || (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) != *(void *)0x03004258)) {
        temp_r0_28665 = temp_r2_28638 * 2;
        if ((*(0x03003920 + temp_r0_28665) == 0xFFF) || ((M2C_FIELD((void *)0x03004B80, u8 *, 0x28) != 0) && (temp_r2_28638 == M2C_FIELD((void *)0x03004B80, u8 *, 0x29)))) {
            *(0x03003920 + temp_r0_28665) = 0xFFFU;
            var_r7_28562 = *(0x03003920 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2));
            var_r6_28628 = 0x0600A800;
block_20:
            var_r6_28561 = ((0xF0 & M2C_FIELD((void *)0x03004B80, u8 *, 0x1E)) * 8) + var_r6_28628 + ((M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) & 0xF) * 4);
        }
block_21:
        if (sub_0201F6DC(var_r7_28562, var_r6_28561) == 0) {
            temp_r0_28707 = *var_r6_28561;
            temp_r2_28709 = 0x3FF & temp_r0_28707;
            if (((temp_r2_28709 > 5U) && ((u32) (u16) (temp_r2_28709 - 0x10) > 5U) && (temp_r2_28709 != 0x82) && (temp_r2_28709 <= 0xAFU)) || ((0x3FF & temp_r0_28707) == 0x13)) {
                temp_r3_28735 = M2C_FIELD((void *)0x03003BC4, s32 *, 8) - (((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8) - 8);
                M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = temp_r3_28735;
                M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = (s32) (M2C_FIELD((void *)0x03003BC4, s32 *, 0xC) - ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8));
                if (temp_r3_28735 < 0) {
                    M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = (s32) (0 - temp_r3_28735);
                }
                temp_r0_28747 = M2C_FIELD((void *)0x03004B80, s32 *, 0x14);
                if (temp_r0_28747 < 0) {
                    M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = (s32) (0 - temp_r0_28747);
                }
                if ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0x10) <= 0x20) {
                    if ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0x14) > 0x20) {
                        goto block_36;
                    }
                    goto block_37;
                }
                goto block_36;
            }
            goto block_37;
        }
        temp_r2_28769 = 0x3FF & *var_r6_28561;
        if (((u32) (u16) (temp_r2_28769 - 0xBC) <= 3U) || ((u32) (u16) (temp_r2_28769 - 0xC6) <= 5U)) {
block_36:
            return 0;
        }
        goto block_37;
    }
block_37:
    return 1;
}

s32 sub_02025B94(s32 arg0, s32 arg1, u16 arg2) {
    s32 temp_r1_28802;
    s32 var_r0_28814;
    s32 var_r3_28804;
    s32 var_r3_28812;
    u16 temp_r2_28799;

    temp_r2_28799 = arg2;
    temp_r1_28802 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
    var_r3_28804 = temp_r1_28802 - *(s32 *)0x030041A0;
    if (var_r3_28804 < 0) {
        var_r3_28804 = 0 - var_r3_28804;
    }
    if (var_r3_28804 <= 0x2FFF) {
        var_r3_28812 = temp_r1_28802 - arg0;
        var_r0_28814 = M2C_FIELD((void *)0x03004B80, s32 *, 4) - arg1;
        if (var_r3_28812 < 0) {
            var_r3_28812 = 0 - var_r3_28812;
        }
        if (var_r0_28814 < 0) {
            var_r0_28814 = 0 - var_r0_28814;
        }
        if (((s32) (var_r3_28812 >> 8) <= (s32) temp_r2_28799) && ((s32) (var_r0_28814 >> 8) <= (s32) temp_r2_28799)) {
            return 1;
        }
        goto block_10;
    }
block_10:
    return 0;
}

s32 sub_02025BEC(void) {
    *(u8 *)0x03004BA6 = 0;
    if (sub_02025B94(M2C_FIELD((void *)0x03003BC4, s32 *, 8) << 8, M2C_FIELD((void *)0x03003BC4, s32 *, 0xC) << 8, 0x10U) != 0) {
        *(u8 *)0x03004BA6 = 1;
    }
    if (*(u8 *)0x03004227 == 1) {
        if ((*(u8 *)0x03004BA6 != 0) && (*(u8 *)0x0300422A == 0xFE)) {
            *(u8 *)0x0300422A = 4;
            M2C_FIELD((void *)0x03003BC4, s8 *, 0x11) = 0;
            *(u8 *)0x03004BA6 = 0;
        }
        return 1;
    }
    return 0;
}

s8 sub_02025C4C(void) {
    u8 *var_r8_28909;
    u8 temp_r1_28939;

    if (*(u8 *)0x0300423A == 0) {
        var_r8_28909 = (u8 *)0x03004227;
        if (*(u8 *)0x03004227 == 3) {
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x03004B80, s32 *, 0);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x03004B80, s32 *, 4);
            goto block_3;
        }
        goto block_8;
    }
block_3:
    var_r8_28909 = (void *)0x030041A0 + 0x87;
    if (M2C_FIELD((void *)0x030041A0, u8 *, 0x87) == 3) {
        if (sub_02025B94(M2C_FIELD((void *)0x030041A0, s32 *, 0), M2C_FIELD((void *)0x030041A0, s32 *, 4), 8U) != 0) {
            M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 1;
            sub_0201FED4(2U, 0x30U);
            temp_r1_28939 = M2C_FIELD((void *)0x030041A0, u8 *, 0x8D);
            if (temp_r1_28939 != 0) {
                M2C_FIELD((void *)0x030041A0, u8 *, 0x8D) = (u8) (0x40 | temp_r1_28939);
                M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 0;
            }
            M2C_FIELD((void *)0x03004B80, s8 *, 0x26) = 0;
            M2C_FIELD((void *)0x030041A0, u8 *, 0x87) = 0xAU;
            M2C_FIELD((void *)0x030041A0, s8 *, 0x98) = 0x30;
            M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 0;
            sub_02025F60();
            return 1;
        }
        goto block_12;
    }
block_8:
    if ((*var_r8_28909 == 0x14) && (M2C_FIELD((void *)0x030041A0, u8 *, 0x9C) == 0) && (sub_02025B94(M2C_FIELD((void *)0x030041A0, s32 *, 0), M2C_FIELD((void *)0x030041A0, s32 *, 4), 0x10U) != 0)) {
        sub_02026A38(3U);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x84) = 2;
        M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 2;
        sub_020263A0();
        return 1;
    }
block_12:
    return 0;
}

s8 sub_02025D1C(void) {
    u8 temp_r0_29010;

    if ((*(u8 *)0x03004227 == 3) && ((temp_r0_29010 = *(u8 *)0x0300422D, (temp_r0_29010 == 1)) || (temp_r0_29010 == 5)) && (sub_02025B94(M2C_FIELD((void *)0x030041A0, s32 *, 0x38), M2C_FIELD((void *)0x030041A0, s32 *, 0x3C), 0x10U) != 0)) {
        *(u8 *)0x03004227 = 9;
        M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x38);
        M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) M2C_FIELD((void *)0x030041A0, s32 *, 0x3C);
        M2C_FIELD((void *)0x030041A0, s8 *, 0x97) = 0;
        M2C_FIELD((void *)0x030041A0, s8 *, 0x9F) = 1;
        return 1;
    }
    return 0;
}

void sub_02025D70(void) {
    void *temp_r0_29058;
    void *temp_r0_29063;
    void *temp_r0_29065;
    void *temp_r0_29071;
    void *temp_r0_29073;
    void *temp_r0_29075;
    void *temp_r0_29077;

    M2C_FIELD((void *)0x03004B80, s32 *, 0) = 0xF800;
    M2C_FIELD((void *)0x03004B80, s32 *, 4) = 0x8800;
    M2C_FIELD((void *)0x03004B80, s32 *, 8) = 0xF800;
    M2C_FIELD((void *)0x03004B80, s32 *, 0xC) = 0x8800;
    temp_r0_29058 = (void *)0x03004B80 + 0x21;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x21) = 0;
    M2C_FIELD(temp_r0_29058, s8 *, 1) = 0;
    temp_r0_29063 = (temp_r0_29058 + 1) - 2;
    M2C_FIELD(temp_r0_29063, s8 *, 0) = 0;
    temp_r0_29065 = temp_r0_29063 + 3;
    M2C_FIELD(temp_r0_29063, s8 *, 3) = 0;
    M2C_FIELD((void *)0x03004B80, s16 *, 0x18) = 0;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1E) = 0;
    M2C_FIELD((void *)0x03004B80, s16 *, 0x1A) = 0;
    temp_r0_29071 = temp_r0_29065 + 1;
    M2C_FIELD(temp_r0_29065, s8 *, 1) = 0;
    temp_r0_29073 = temp_r0_29071 + 1;
    M2C_FIELD(temp_r0_29071, s8 *, 1) = 0;
    temp_r0_29075 = temp_r0_29073 + 1;
    M2C_FIELD(temp_r0_29073, s8 *, 1) = 0;
    temp_r0_29077 = temp_r0_29075 + 1;
    M2C_FIELD(temp_r0_29075, s8 *, 1) = 0;
    M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r0_29077, s8 *, 1) = 0;
    M2C_FIELD((temp_r0_29077 + 1), s8 *, 1) = 0;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1C) = 0;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1D) = 0;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 0;
}

void sub_02025DC8(void) {
    s32 temp_r2_29106;
    s32 temp_r2_29140;
    s32 temp_r2_29183;
    s32 temp_r2_29215;
    s32 var_r0_29162;
    u16 temp_r0_29249;

    if (0x400040 & M2C_FIELD(&gGameState, s32 *, 0x818)) {
        temp_r2_29106 = M2C_FIELD((void *)0x03004B80, s32 *, 4);
        M2C_FIELD((void *)0x03004B80, s32 *, 4) = (s32) (temp_r2_29106 + 0xFFFFFE80);
        if (0x100 & gGameState.keys_held) {
            M2C_FIELD((void *)0x03004B80, s32 *, 4) = (s32) (temp_r2_29106 + 0xFFFFFD00);
        }
        if ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) <= 0xE00) {
            M2C_FIELD((void *)0x03004B80, s32 *, 4) = 0xE00;
        }
    } else if (M2C_FIELD(&gGameState, s32 *, 0x818) & 0x800080) {
        temp_r2_29140 = M2C_FIELD((void *)0x03004B80, s32 *, 4);
        M2C_FIELD((void *)0x03004B80, s32 *, 4) = (s32) (temp_r2_29140 + 0x180);
        if (0x100 & gGameState.keys_held) {
            M2C_FIELD((void *)0x03004B80, s32 *, 4) = (s32) (temp_r2_29140 + 0x300);
        }
        if (*(u8 *)0x03004224 == 0) {
            var_r0_29162 = 0xF7FF;
        } else {
            var_r0_29162 = 0xE7FF;
        }
        if (M2C_FIELD((void *)0x03004B80, s32 *, 4) > var_r0_29162) {
            M2C_FIELD((void *)0x03004B80, s32 *, 4) = (s32) (var_r0_29162 + 1);
        }
    }
    if (0x200020 & M2C_FIELD(&gGameState, s32 *, 0x818)) {
        temp_r2_29183 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
        M2C_FIELD((void *)0x03004B80, s32 *, 0) = (s32) (temp_r2_29183 + 0xFFFFFE80);
        if (0x100 & gGameState.keys_held) {
            M2C_FIELD((void *)0x03004B80, s32 *, 0) = (s32) (temp_r2_29183 + 0xFFFFFD00);
        }
        if ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) <= 0x600) {
            M2C_FIELD((void *)0x03004B80, s32 *, 0) = 0x600;
        }
    } else if (M2C_FIELD(&gGameState, s32 *, 0x818) & 0x100010) {
        temp_r2_29215 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
        M2C_FIELD((void *)0x03004B80, s32 *, 0) = (s32) (temp_r2_29215 + 0x180);
        if (0x100 & gGameState.keys_held) {
            M2C_FIELD((void *)0x03004B80, s32 *, 0) = (s32) (temp_r2_29215 + 0x300);
        }
        if ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) > 0x1DFFF) {
            M2C_FIELD((void *)0x03004B80, s32 *, 0) = 0x1E000;
        }
    }
    gGameState.unk_840 = ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8) - 0x80;
    temp_r0_29249 = ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) - 0x50;
    gGameState.unk_842 = temp_r0_29249;
    if (temp_r0_29249 & 0x800) {
        gGameState.unk_842 = 0;
    }
    if ((u32) gGameState.unk_842 > 0x60U) {
        gGameState.unk_842 = 0x60;
    }
    if (0x800 & gGameState.unk_840) {
        gGameState.unk_840 = 0;
    }
    if ((u32) gGameState.unk_840 > 0x100U) {
        gGameState.unk_840 = 0x100;
    }
    gGameState.unk_844 = gGameState.unk_840;
    gGameState.unk_846 = gGameState.unk_842;
}

void sub_02025F60(void) {
    *(s8 *)0x03004BA0 = 0;
    *(s8 *)0x03004BA3 = 0;
    *(s8 *)0x03004BA1 = 0;
    *(s8 *)0x03004BA2 = (s8) M2C_FIELD(**(void ***)0x02034ED4, u16 *, 4);
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 1;
}

void sub_02025F90(void) {
    s32 temp_r1_29362;
    s32 temp_r2_29358;
    s32 temp_r3_29360;
    s32 var_r1_29376;
    s32 var_r2_29378;
    s8 temp_r0_29629;
    s8 temp_r0_29633;
    s8 temp_r7_29474;
    u16 *temp_r2_29506;
    u16 *temp_r2_29538;
    u16 temp_r4_29487;
    u16 temp_r7_29393;
    u16 var_r6_29507;
    u8 temp_r0_29334;
    u8 temp_r0_29337;
    u8 temp_r0_29587;
    u8 temp_r1_29498;
    u8 temp_r1_29528;
    u8 temp_r2_29431;
    u8 temp_r2_29457;
    void *temp_r1_29478;
    void *temp_r1_29609;

    temp_r0_29334 = *(u8 *)0x03004BA7;
    if (temp_r0_29334 != 0) {
        temp_r0_29337 = temp_r0_29334 - 1;
        *(u8 *)0x03004BA7 = temp_r0_29337;
        if ((temp_r0_29337 << 0x18) != 0) {
            goto block_25;
        }
    }
    if (!(1 & gGameState.keys_pressed)) {
        goto block_25;
    }
    temp_r2_29358 = ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) & 0xFF0;
    M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = temp_r2_29358;
    temp_r3_29360 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
    temp_r1_29362 = (temp_r3_29360 >> 8) & 0xFF0;
    M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = temp_r1_29362;
    M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) = (u8) (temp_r2_29358 | ((s32) (0xF0 & temp_r1_29362) >> 4));
    if (!(temp_r1_29362 & 0xFF00)) {
        var_r1_29376 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2;
        var_r2_29378 = 0x03003720;
    } else {
        var_r1_29376 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2;
        var_r2_29378 = 0x03003920;
    }
    temp_r7_29393 = *(var_r1_29376 + var_r2_29378);
    switch (temp_r7_29393) {                        /* irregular */
    case 0xFFF:
block_27:
        M2C_FIELD((void *)0x03004B80, u8 *, 0x23) = 1U;
block_25:
        if (M2C_FIELD((void *)0x03004B80, u8 *, 0x23) == 0) {
            sub_02025DC8();
            return;
        }
        temp_r0_29587 = M2C_FIELD((void *)0x03004B80, u8 *, 0x22);
        if (temp_r0_29587 == 0) {
            M2C_FIELD((void *)0x03004B80, u8 *, 0x22) = (u8) (temp_r0_29587 - 1);
            return;
        }
        M2C_FIELD((void *)0x03004B80, u8 *, 0x21) = (u8) (M2C_FIELD((void *)0x03004B80, u8 *, 0x21) + 1);
        temp_r1_29609 = *((M2C_FIELD((void *)0x03004B80, u8 *, 0x21) * 4) + *(0x02034ED4 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x20) * 4)));
        if (M2C_FIELD(temp_r1_29609, u8 *, 6) != 0xFF) {
            M2C_FIELD((void *)0x03004B80, u8 *, 0x22) = (u8) M2C_FIELD(temp_r1_29609, u16 *, 4);
            return;
        }
        if (sub_02025BEC() != 0) {
            sub_02026A38(2U);
            M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 0;
            sub_02025F60();
            return;
        }
        temp_r0_29629 = sub_02025C4C();
        if (temp_r0_29629 == 0) {
            temp_r0_29633 = sub_02025D1C();
            if (temp_r0_29633 != 0) {
                M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = temp_r0_29629;
                sub_02025F60();
                return;
            }
            sub_02026A38(2U);
            M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = temp_r0_29633;
            sub_02025F60();
        } else {
            return;
        }
        break;
    case 0x7777:
        goto block_27;
    case 0x3333:
        goto block_27;
    default:
        if (M2C_FIELD(((temp_r7_29393 * 0xC) + 0x0202F7FC), u16 *, 8) == 0xFFF) {
            goto block_27;
        }
        if (!(M2C_FIELD((void *)0x03004B80, s32 *, 0x10) & 0xFF00)) {
            temp_r2_29431 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
            if (((s32) *(*(s32 *)0x03001B40 + 0x18F8 + ((temp_r2_29431 >> 4) * 2)) >> (0xF & temp_r2_29431)) & 1) {
                goto block_28;
            }
            goto block_20;
        }
        temp_r2_29457 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
        if (!(((s32) *(*(void *)0x03001B40 + 0x1918 + ((temp_r2_29457 >> 4) * 2)) >> (0xF & temp_r2_29457)) & 1)) {
block_20:
            temp_r7_29474 = temp_r7_29393 & 0xFFF;
            temp_r1_29478 = (temp_r7_29474 * 0xC) + 0x0202F7FC;
            if (M2C_FIELD(temp_r1_29478, u16 *, 4) != 0xFFF) {
                temp_r4_29487 = (temp_r3_29360 >> 8) & 0xFF00;
                if (temp_r4_29487 == 0) {
                    *(0x03003720 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2)) = 0x7777;
                    temp_r1_29498 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
                    temp_r2_29506 = *(s32 *)0x03001B40 + 0x24 + (((0xF & temp_r1_29498) * 2) + ((temp_r1_29498 >> 4) << 5));
                    var_r6_29507 = *temp_r2_29506;
                    *temp_r2_29506 = temp_r4_29487;
                    M2C_FIELD((void *)0x03004B80, s8 *, 0x28) = 0;
                } else {
                    *(0x03003920 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2)) = 0x7777;
                    temp_r1_29528 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
                    temp_r2_29538 = *(s32 *)0x03001B40 + 0x224 + (((0xF & temp_r1_29528) * 2) + ((temp_r1_29528 >> 4) << 5));
                    var_r6_29507 = *temp_r2_29538;
                    *temp_r2_29538 = 0;
                    M2C_FIELD((void *)0x03004B80, s8 *, 0x28) = 1;
                }
                M2C_FIELD((void *)0x03004B80, u8 *, 0x29) = (u8) M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
                M2C_FIELD((void *)0x03004B80, s8 *, 0x24) = temp_r7_29474;
                M2C_FIELD((void *)0x03004B80, u16 *, 0x18) = (u16) M2C_FIELD(temp_r1_29478, u16 *, 4);
                M2C_FIELD((void *)0x03004B80, u16 *, 0x1A) = var_r6_29507;
                sub_02026A38(3U);
                M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 2;
                sub_020263A0();
                return;
            }
            goto block_27;
        }
block_28:
        M2C_FIELD((void *)0x03004B80, u8 *, 0x23) = 1U;
        goto block_25;
    }
}

void sub_0202622C(u16 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4) {
    s16 *var_r3_29698;
    s16 *var_r3_29733;
    s16 var_r0_29735;
    s16 var_r4_29707;
    s32 var_r0_29670;
    s32 var_r1_29671;
    s32 var_r3_29686;
    u16 temp_r1_29682;
    u16 temp_r4_29661;
    u8 temp_r0_29663;
    u8 temp_r2_29666;

    temp_r4_29661 = arg0;
    temp_r0_29663 = arg2;
    temp_r2_29666 = (u8) arg4;
    if ((arg3 << 0x18) == 0) {
        var_r0_29670 = temp_r0_29663 * 2;
        var_r1_29671 = 0x03003720;
    } else {
        var_r0_29670 = temp_r0_29663 * 2;
        var_r1_29671 = 0x03003920;
    }
    temp_r1_29682 = *(var_r0_29670 + var_r1_29671);
    var_r3_29686 = 0x0600C800;
    if (!(0xFF0000 & arg1)) {
        var_r3_29686 = 0x0600C000;
    }
    var_r3_29698 = var_r3_29686 + ((0xF0 & temp_r4_29661) * 8) + ((0xF & temp_r4_29661) * 4);
    if ((temp_r1_29682 == 0x24) || (temp_r1_29682 == 0x2E)) {
        if (temp_r2_29666 == 0) {
            var_r3_29698 += 0x40;
            var_r4_29707 = 0x328F;
        } else {
            var_r3_29698 += 0x42;
            var_r4_29707 = 0x328C;
        }
        *var_r3_29698 = var_r4_29707;
    }
    if ((temp_r1_29682 == 0x25) || ((u32) (u16) (temp_r1_29682 - 0x27) <= 4U) || (temp_r1_29682 == 0x2F)) {
        if (temp_r2_29666 == 0) {
            var_r3_29733 = var_r3_29698 + 0x40;
            var_r0_29735 = 0x3297;
        } else {
            var_r3_29733 = var_r3_29698 + 0x42;
            var_r0_29735 = 0x3294;
        }
        *var_r3_29733 = var_r0_29735;
    }
}

void sub_020262DC(u16 arg0, s32 arg1) {
    s32 temp_r0_29777;
    s32 temp_r1_29767;
    s32 var_r0_29812;
    u16 temp_r4_29762;
    u8 var_r2_29811;

    temp_r4_29762 = arg0;
    temp_r1_29767 = temp_r4_29762 & 0xF;
    temp_r0_29777 = temp_r4_29762 & 0xF0;
    M2C_FIELD((void *)0x03004B80, u8 *, 0x1C) = (u8) (((temp_r1_29767 - 1) & 0xF) | temp_r0_29777);
    M2C_FIELD((void *)0x03004B80, u8 *, 0x1D) = (u8) (((temp_r1_29767 + 1) & 0xF) | temp_r0_29777);
    if (!(M2C_FIELD((void *)0x03004B80, s32 *, 0) & 0xFF0000)) {
        sub_0202622C(temp_r4_29762, arg1, M2C_FIELD((void *)0x03004B80, u8 *, 0x1C), 0, 0);
        if (!(0xF & M2C_FIELD((void *)0x03004B80, u8 *, 0x1D))) {
            sub_0202622C(temp_r4_29762, arg1, M2C_FIELD((void *)0x03004B80, u8 *, 0x1D), 1, 1);
            return;
        }
        var_r2_29811 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1D);
        var_r0_29812 = 1;
        goto block_6;
    }
    sub_0202622C(temp_r4_29762, arg1, M2C_FIELD((void *)0x03004B80, u8 *, 0x1D), 1, 1);
    if ((0xF & M2C_FIELD((void *)0x03004B80, u8 *, 0x1C)) == 0xF) {
        var_r2_29811 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1C);
        var_r0_29812 = 0;
block_6:
        sub_0202622C(temp_r4_29762, arg1, var_r2_29811, 0, var_r0_29812);
        return;
    }
    sub_0202622C(temp_r4_29762, arg1, M2C_FIELD((void *)0x03004B80, u8 *, 0x1C), 1, 0);
}

void sub_020263A0(void) {
    s32 temp_r0_29892;
    u16 temp_r2_29900;

    *(s8 *)0x03004BA0 = 1;
    *(s8 *)0x03004BA3 = 0;
    *(s8 *)0x03004BA1 = 0;
    *(s8 *)0x03004BA2 = (s8) M2C_FIELD(*M2C_FIELD((void *)0x02034ED4, void ***, 4), u16 *, 4);
    if (*(u8 *)0x03004224 == 0) {
        *(s8 *)0x03003B29 = 1;
        sub_02024F08(2);
        *(s16 *)0x03004878 = 0x30;
        temp_r0_29892 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
        M2C_FIELD((void *)0x03004838, s32 *, 0) = (s32) ((temp_r0_29892 >> 8) - 8);
        M2C_FIELD((void *)0x03004838, s32 *, 4) = (s32) (((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) - 2);
        temp_r2_29900 = M2C_FIELD((void *)0x03004B80, u16 *, 0x18);
        M2C_FIELD((void *)0x03004838, s16 *, 0x3E) = (s16) (0x3FF & temp_r2_29900);
        M2C_FIELD((void *)0x03004838, s8 *, 0x50) = (s8) ((u32) (temp_r2_29900 << 0x10) >> 0x1C);
        *(((void *)0x03004838 + 0x50) - 1) = 0;
        sub_0201F660(temp_r0_29892, M2C_FIELD((void *)0x03004B80, u8 *, 0x1E), 0U, 0x200U);
        sub_020262DC(M2C_FIELD((void *)0x03004B80, u8 *, 0x1E), M2C_FIELD((void *)0x03004B80, s32 *, 0));
    } else {
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x03004B80, s32 *, 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (M2C_FIELD((void *)0x03004B80, s32 *, 4) + 0x1200);
    }
    M2C_FIELD((void *)0x03004B80, s8 *, 0x25) = 0x20;
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 3;
}

void sub_02026464(void) {
    s32 var_r0_30005;
    u16 temp_r0_29958;
    u16 var_r0_30102;
    u8 temp_r0_29971;
    u8 temp_r0_29974;
    u8 temp_r0_30074;
    u8 temp_r4_30088;
    void *temp_r1_30029;
    void *temp_r1_30092;

    if (*(u8 *)0x03004224 == 0) {
        temp_r0_29958 = M2C_FIELD((void *)0x03004B80, u16 *, 0x28);
        if (temp_r0_29958 == 0) {
            M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = (s8) temp_r0_29958;
            sub_02025F60();
            return;
        }
    }
    temp_r0_29971 = M2C_FIELD((void *)0x03004B80, u8 *, 0x25);
    if (((temp_r0_29971 == 0) || (temp_r0_29974 = temp_r0_29971 - 1, M2C_FIELD((void *)0x03004B80, u8 *, 0x25) = temp_r0_29974, ((temp_r0_29974 << 0x18) == 0))) && (1 & gGameState.keys_pressed)) {
        if (*(void *)0x03004224 != 0) {
            M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = (s32) ((((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8) - 8) & 0xFF0);
            var_r0_30005 = (((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) + 0x18) & 0xFF0;
        } else {
            M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = (s32) (M2C_FIELD((void *)0x03004838, s32 *, 0) + 8);
            var_r0_30005 = M2C_FIELD((void *)0x03004838, s32 *, 4) + 8;
        }
        M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = var_r0_30005;
        if (sub_020259C8() == 0) {
            sub_02026A38(4U);
            M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 4;
            sub_020265A8();
            return;
        }
        temp_r1_30029 = (void *)0x03004B80 + 0x20;
        M2C_FIELD((void *)0x03004B80, u8 *, 0x20) = 3U;
        M2C_FIELD(temp_r1_30029, s8 *, 1) = 0;
        M2C_FIELD((temp_r1_30029 + 1), s8 *, 1) = (s8) M2C_FIELD(*M2C_FIELD((void *)0x02034ED4, void ***, 0xC), u16 *, 4);
        sub_02026A38(0x12U);
        goto block_12;
    }
block_12:
    sub_02025DC8();
    if (*(void *)0x03004224 == 0) {
        M2C_FIELD((void *)0x03004838, s16 *, 0x40) = 0x30;
        M2C_FIELD((void *)0x03004838, s32 *, 0) = (s32) (((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8) - 8);
        M2C_FIELD((void *)0x03004838, s32 *, 4) = (s32) (((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8) - 2);
    } else {
        M2C_FIELD((void *)0x030041A0, s32 *, 0) = (s32) M2C_FIELD((void *)0x03004B80, s32 *, 0);
        M2C_FIELD((void *)0x030041A0, s32 *, 4) = (s32) (M2C_FIELD((void *)0x03004B80, s32 *, 4) + 0x1200);
    }
    temp_r0_30074 = M2C_FIELD((void *)0x03004B80, u8 *, 0x22);
    if (temp_r0_30074 == 0) {
        M2C_FIELD((void *)0x03004B80, u8 *, 0x21) = (u8) (M2C_FIELD((void *)0x03004B80, u8 *, 0x21) + 1);
        temp_r4_30088 = M2C_FIELD((void *)0x03004B80, u8 *, 0x21);
        temp_r1_30092 = *((temp_r4_30088 * 4) + *(0x02034ED4 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x20) * 4)));
        if (M2C_FIELD(temp_r1_30092, u8 *, 6) == 0xFF) {
            M2C_FIELD((void *)0x03004B80, u8 *, 0x21) = (u8) (temp_r4_30088 - 1);
            return;
        }
        var_r0_30102 = M2C_FIELD(temp_r1_30092, u16 *, 4);
        goto block_20;
    }
    var_r0_30102 = temp_r0_30074 - 1;
block_20:
    M2C_FIELD((void *)0x03004B80, u8 *, 0x22) = (u8) var_r0_30102;
}

void sub_020265A8(void) {
    M2C_FIELD((void *)0x03004BA0, s8 *, 0) = 2;
    M2C_FIELD((void *)0x03004BA0, s8 *, 1) = 0;
    M2C_FIELD(((void *)0x03004BA0 + 1), s8 *, 1) = (s8) M2C_FIELD(*M2C_FIELD((void *)0x02034ED4, void ***, 8), u16 *, 4);
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 5;
}

void sub_020265D4(void) {
    s32 temp_r3_30338;
    s32 var_r0_30247;
    s32 var_r0_30272;
    s32 var_r1_30249;
    s32 var_r1_30274;
    s32 var_r1_30347;
    s32 var_r2_30340;
    s32 var_sb_30147;
    s8 *var_r2_30245;
    u16 temp_r0_30313;
    u8 temp_r0_30167;
    u8 temp_r0_30304;
    u8 temp_r2_30363;
    void *temp_r1_30205;
    void *temp_r8_30230;

    var_sb_30147 = 0;
    if ((*(u8 *)0x03004224 == 0) && (M2C_FIELD((void *)0x03004B80, u16 *, 0x28) == 0)) {
        M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 0;
        sub_02025F60();
        return;
    }
    temp_r0_30167 = M2C_FIELD((void *)0x03004B80, u8 *, 0x22);
    if (temp_r0_30167 != 0) {
        M2C_FIELD((void *)0x03004B80, u8 *, 0x22) = (u8) (temp_r0_30167 - 1);
        if ((M2C_FIELD((void *)0x03004B80, s32 *, 0x20) & 0xFFFF00) != 0x300) {
            return;
        }
        *(s8 *)0x03003B29 = 0;
        return;
    }
    M2C_FIELD((void *)0x03004B80, u8 *, 0x21) = (u8) (M2C_FIELD((void *)0x03004B80, u8 *, 0x21) + 1);
    temp_r1_30205 = *((M2C_FIELD((void *)0x03004B80, u8 *, 0x21) * 4) + *(0x02034ED4 + ((u8) M2C_FIELD((void *)0x03004B80, s32 *, 0x20) * 4)));
    if (M2C_FIELD(temp_r1_30205, u8 *, 6) != 0xFF) {
        M2C_FIELD((void *)0x03004B80, u8 *, 0x22) = (u8) M2C_FIELD(temp_r1_30205, u16 *, 4);
        return;
    }
    if (*(void *)0x03004224 != 0) {
        *(void *)0x03004224 = 1U;
    } else {
        temp_r8_30230 = (M2C_FIELD((void *)0x03004B80, u8 *, 0x24) * 0xC) + 0x0202F7FC;
        sub_0201F660(M2C_FIELD((void *)0x03004B80, s32 *, 0), M2C_FIELD((void *)0x03004B80, u8 *, 0x1E), M2C_FIELD((void *)0x03004B80, u16 *, 0x1A));
        if ((u8) M2C_FIELD((void *)0x03004B80, u16 *, 0x28) == 0) {
            var_r2_30245 = (void *)0x03004B80 + 0x29;
            var_r0_30247 = M2C_FIELD((void *)0x03004B80, u8 *, 0x29) * 2;
            var_r1_30249 = 0x03003720;
        } else {
            var_r2_30245 = (void *)0x03004B80 + 0x29;
            var_r0_30247 = M2C_FIELD((void *)0x03004B80, u8 *, 0x29) * 2;
            var_r1_30249 = 0x03003920;
        }
        *(var_r1_30249 + var_r0_30247) = 0xFFF;
        if (!(M2C_FIELD((void *)0x03004B80, s32 *, 0) & 0xFF0000)) {
            var_r0_30272 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2;
            var_r1_30274 = 0x03003720;
        } else {
            var_r0_30272 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E) * 2;
            var_r1_30274 = 0x03003920;
        }
        *(var_r1_30274 + var_r0_30272) = (s16) M2C_FIELD((void *)0x03004B80, u8 *, 0x24);
        M2C_FIELD((void *)0x03004B80, u16 *, 0x28) = 0;
        *var_r2_30245 = 0;
        if (*(u8 *)0x03004227 == 3) {
            if (*(u16 *)0x03004202 == 0) {
                temp_r0_30304 = *(u8 *)0x0300422D;
                switch (temp_r0_30304) {            /* switch 1; irregular */
                case 3:                             /* switch 1 */
                case 7:                             /* switch 1 */
                    temp_r0_30313 = M2C_FIELD(temp_r8_30230, u16 *, 8);
                    switch ((u32) temp_r0_30313) {  /* switch 2; irregular */
                    case 6:                         /* switch 2 */
                        goto block_28;
                    }
                    break;
                }
            } else if ((*(void *)0x0300422D == 0) && ((u32) (u16) (M2C_FIELD(temp_r8_30230, u16 *, 8) - 5) <= 9U)) {
            case 0:                                 /* switch 1 */
            case 5:                                 /* switch 2 */
block_28:
                var_sb_30147 = 1;
            }
        }
        temp_r3_30338 = M2C_FIELD((void *)0x03004B80, s32 *, 0);
        var_r2_30340 = temp_r3_30338 - M2C_FIELD((void *)0x030041A0, s32 *, 0);
        if (var_r2_30340 < 0) {
            var_r2_30340 = 0 - var_r2_30340;
        }
        var_r1_30347 = M2C_FIELD((void *)0x03004B80, s32 *, 4) - M2C_FIELD((void *)0x030041A0, s32 *, 4);
        if (var_r1_30347 < 0) {
            var_r1_30347 = 0 - var_r1_30347;
        }
        if ((var_r2_30340 <= 0x2FFF) && (var_r1_30347 <= 0x2FFF) && (var_sb_30147 == 1)) {
            temp_r2_30363 = M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
            M2C_FIELD((void *)0x030041A0, s32 *, 0x10) = (s32) ((temp_r3_30338 & 0xFF0000) | (((0xF & temp_r2_30363) << 0xC) + 0x800));
            M2C_FIELD((void *)0x030041A0, s32 *, 0x14) = (s32) (((0xF0 & temp_r2_30363) << 8) + 0x800);
            *(u8 *)0x03004227 = 9;
        }
    }
    M2C_FIELD((void *)0x03004B80, s8 *, 0x27) = 0x20;
    M2C_FIELD((void *)0x030041A0, u8 *, 0x9D) = (u8) M2C_FIELD((void *)0x03004B80, u8 *, 0x1E);
    M2C_FIELD((void *)0x03004B80, s8 *, 0x1F) = 0;
    sub_02025F60();
}

void sub_020267D0(void) {
    *(s8 *)0x03003B27 = 1;
    *(s8 *)0x03003B28 = 1;
    if ((*(u8 *)0x03004227 != 0x14) || (*(u8 *)0x0300423C == 0) || (*(u8 *)0x03004224 == 2)) {
        *(0x02034E0C + (M2C_FIELD((void *)0x03004B80, u8 *, 0x1F) * 4))();
    }
}

void sub_02026830(void) {
    u8 temp_r1_30526;
    u8 temp_r1_30554;
    u8 temp_r2_30516;
    u8 temp_r2_30544;
    u8 temp_r2_30604;
    u8 temp_r4_30533;
    void *temp_r3_30508;
    void *var_r5_30480;
    void *var_r8_30489;

    M2C_FIELD((void *)0x03004B80, s32 *, 0x14) = (s32) ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 4) >> 8);
    M2C_FIELD((void *)0x03004B80, s32 *, 0x10) = (s32) ((s32) M2C_FIELD((void *)0x03004B80, s32 *, 0) >> 8);
    var_r5_30480 = **((M2C_FIELD(((void *)0x03004B80 + 0x20), u8 *, 1) * 4) + *(0x02034ED4 + (M2C_FIELD((void *)0x03004B80, u8 *, 0x20) * 4)));
    *(s8 *)0x03003B27 = 0;
    *(s8 *)0x03003B28 = 0;
    var_r8_30489 = NULL;
    if (M2C_FIELD(var_r5_30480, u16 *, 6) == 0xFFFF) {
        return;
    }
    do {
        temp_r3_30508 = (gGameState.unk_860 * 8) + gUnk3002410;
        temp_r2_30516 = (-0xD & M2C_FIELD(temp_r3_30508, u8 *, 1)) | (0xC & M2C_FIELD(var_r5_30480, u8 *, 1));
        M2C_FIELD(temp_r3_30508, u8 *, 1) = temp_r2_30516;
        temp_r1_30526 = (-0x21 & temp_r2_30516) | ((((u32) (M2C_FIELD(var_r5_30480, u8 *, 1) << 0x1A) >> 0x1F) & 1) << 5);
        M2C_FIELD(temp_r3_30508, u8 *, 1) = temp_r1_30526;
        temp_r4_30533 = (0x3F & temp_r1_30526) | (((u8) M2C_FIELD(var_r5_30480, u8 *, 1) >> 6) << 6);
        M2C_FIELD(temp_r3_30508, u8 *, 1) = temp_r4_30533;
        temp_r2_30544 = (-0x11 & M2C_FIELD(temp_r3_30508, u8 *, 3)) | ((((u32) (M2C_FIELD(var_r5_30480, u8 *, 3) << 0x1B) >> 0x1F) & 1) * 0x10);
        M2C_FIELD(temp_r3_30508, u8 *, 3) = temp_r2_30544;
        temp_r1_30554 = (-0x21 & temp_r2_30544) | ((((u32) (M2C_FIELD(var_r5_30480, u8 *, 3) << 0x1A) >> 0x1F) & 1) << 5);
        M2C_FIELD(temp_r3_30508, u8 *, 3) = temp_r1_30554;
        M2C_FIELD(temp_r3_30508, u8 *, 3) = (u8) ((temp_r1_30554 & 0x3F) | (((u8) M2C_FIELD(var_r5_30480, u8 *, 3) >> 6) << 6));
        M2C_FIELD(temp_r3_30508, s8 *, 0) = (s8) ((M2C_FIELD(var_r5_30480, u8 *, 0) + M2C_FIELD((void *)0x03004B80, s32 *, 0x14)) - M2C_FIELD(&gGameState, u8 *, 0x846));
        M2C_FIELD(temp_r3_30508, u16 *, 2) = (u16) ((0xFFFFFE00 & M2C_FIELD(temp_r3_30508, u16 *, 2)) | (((((u32) (M2C_FIELD(var_r5_30480, u16 *, 2) << 0x17) >> 0x17) + M2C_FIELD((void *)0x03004B80, s32 *, 0x10)) - gGameState.unk_844) & 0x1FF));
        M2C_FIELD(temp_r3_30508, u16 *, 4) = (u16) ((0xFFFFFC00 & M2C_FIELD(temp_r3_30508, u16 *, 4)) | ((u32) (M2C_FIELD(var_r5_30480, u16 *, 4) << 0x16) >> 0x16));
        M2C_FIELD(temp_r3_30508, u8 *, 1) = (u8) (temp_r4_30533 | 0x10);
        temp_r2_30604 = -0xD & M2C_FIELD(temp_r3_30508, u8 *, 5);
        M2C_FIELD(temp_r3_30508, u8 *, 5) = temp_r2_30604;
        M2C_FIELD(temp_r3_30508, u8 *, 5) = (u8) ((0xF & temp_r2_30604) | (((u8) M2C_FIELD(var_r5_30480, u8 *, 5) >> 4) * 0x10));
        *(0x03003B27 + (s32) var_r8_30489) = 1;
        gGameState.unk_860 += 1;
        var_r8_30489 += 1;
        var_r5_30480 += 8;
    } while (M2C_FIELD(var_r5_30480, u16 *, 6) != 0xFFFF);
}

void sub_020269C8(void) {
    sub_02026E4C(0x02035BF4);
    sub_02026BD8();
    sub_020269F0();
}

void sub_020269E0(void) {
    sub_02026A34();
    sub_02028B44();
}

void sub_020269F0(void) {
    s16 sp0;
    s32 var_r1_30680;
    void *var_r0_30679;

    var_r0_30679 = (void *)0x03000038;
    var_r1_30680 = 2;
    do {
        M2C_FIELD(var_r0_30679, s32 *, 0) = -1;
        M2C_FIELD(var_r0_30679, s8 *, 4) = 0;
        var_r0_30679 += 8;
        var_r1_30680 -= 1;
    } while (var_r1_30680 >= 0);
    sp0 = 0xFFFF;
    CpuSet(&sp0, (void *)0x03000028, 0x01000005U);
}

void sub_02026A34(void) {

}

void sub_02026A38(u16 value) {
    s32 var_r2_30738;
    u16 temp_r6_30714;
    u32 temp_r1_30729;
    u32 temp_r4_30719;

    temp_r6_30714 = value;
    temp_r4_30719 = *(0x02035C10 + (temp_r6_30714 * 4));
    if (sub_0202846C(0) != 0) {
        temp_r1_30729 = *(0x02035C10 + (*(s16 *)0x03000028 * 4));
        if (!(0x04000000 & temp_r4_30719)) {
            var_r2_30738 = 1 & ~(temp_r4_30719 >> 0x19);
        } else {
            var_r2_30738 = 2;
        }
        if (!(0x04000000 & temp_r1_30729)) {
            if (var_r2_30738 >= (s32) (1 & ~(temp_r1_30729 >> 0x19))) {
                goto block_8;
            }
        } else if (var_r2_30738 > 1) {
            goto block_8;
        }
    } else {
block_8:
        sub_02028B90(0, 0U, (u16) temp_r4_30719);
        *(void *)0x03000028 = (s16) temp_r6_30714;
    }
}

void sub_02026AB8(u16 arg0) {
    s32 var_r2_30805;
    u16 temp_r7_30781;
    u32 temp_r1_30796;
    u32 temp_r4_30786;

    temp_r7_30781 = arg0;
    temp_r4_30786 = *(0x02035C10 + (temp_r7_30781 * 4));
    if (sub_0202846C(1) != 0) {
        temp_r1_30796 = *(0x02035C10 + (*(s16 *)0x0300002A * 4));
        if (!(0x04000000 & temp_r4_30786)) {
            var_r2_30805 = 1 & ~(temp_r4_30786 >> 0x19);
        } else {
            var_r2_30805 = 2;
        }
        if (!(0x04000000 & temp_r1_30796)) {
            if (var_r2_30805 >= (s32) (1 & ~(temp_r1_30796 >> 0x19))) {
                goto block_8;
            }
        } else if (var_r2_30805 > 1) {
            goto block_8;
        }
    } else {
block_8:
        sub_02028B90(1, 0U, (u16) temp_r4_30786);
        *(void *)0x0300002A = (s16) temp_r7_30781;
    }
}

void sub_02026B38(void) {
    sub_02028BCC(1U, 0U);
}

void sub_02026B48(u16 value) {
    s32 var_r2_30882;
    u16 temp_r6_30858;
    u32 temp_r1_30873;
    u32 temp_r4_30863;

    temp_r6_30858 = value;
    temp_r4_30863 = *(0x02035C10 + (temp_r6_30858 * 4));
    if (sub_0202846C(2) != 0) {
        temp_r1_30873 = *(0x02035C10 + (*(s16 *)0x0300002C * 4));
        if (!(0x04000000 & temp_r4_30863)) {
            var_r2_30882 = 1 & ~(temp_r4_30863 >> 0x19);
        } else {
            var_r2_30882 = 2;
        }
        if (!(0x04000000 & temp_r1_30873)) {
            if (var_r2_30882 >= (s32) (1 & ~(temp_r1_30873 >> 0x19))) {
                goto block_8;
            }
        } else if (var_r2_30882 > 1) {
            goto block_8;
        }
    } else {
block_8:
        sub_02028B90(2, 0U, (u16) temp_r4_30863);
        *(void *)0x0300002C = (s16) temp_r6_30858;
    }
}

void sub_02026BC8(u16 value) {
    sub_02028BCC(2U, 0U);
}

void sub_02026BD8(void) {
    sub_02028E10(sub_02026D74);
    sub_02028DE8(sub_02026DFC);
    *(s16 *)0x03000050 = 0xFFFF;
    *(s8 *)0x03000052 = 0;
}

void sub_02026C0C(void) {

}

void sub_02026C10(u16 value) {
    u16 temp_r4_30963;

    temp_r4_30963 = value;
    if ((sub_0202846C(4) == 0) || (*(u16 *)0x03000050 != temp_r4_30963)) {
        sub_02028B58(4U, *(0x02035CBC + (temp_r4_30963 * 2)));
        if (temp_r4_30963 == 1) {
            sub_02026C7C(*(u8 *)0x03000052);
        } else {
            sub_02028CE4(4, 0, 0U);
        }
        *(void *)0x03000050 = temp_r4_30963;
    }
}

void sub_02026C68(u16 value) {
    sub_02028BCC(4U, value);
}

void sub_02026C7C(u8 arg0) {
    u16 var_r5_31036;
    u8 temp_r4_31020;
    u8 var_r7_31035;

    temp_r4_31020 = arg0;
    if ((temp_r4_31020 != *(u8 *)0x03000052) && (*(u8 *)0x03000052 = temp_r4_31020, (sub_0202846C(4) != 0)) && (*(u16 *)0x03000050 == 1)) {
        var_r7_31035 = 0;
        var_r5_31036 = 0;
        switch (temp_r4_31020) {                    /* irregular */
        case 1:
            sub_02028CE4(4, 0xFFFF, 0U);
            sub_02028CE4(4, 0, 1U);
block_14:
            sub_02028CAC(4U, var_r7_31035);
            sub_02028C3C(4U, (s16) var_r5_31036);
            break;
        case 2:
            sub_02028CE4(4, 0xFFFF, 0U);
            sub_02028CE4(4, 0x94, 1U);
            var_r5_31036 = 0x1E;
            var_r7_31035 = 1;
            goto block_14;
        case 3:
            sub_02028CE4(4, 0xFFFF, 0U);
            sub_02028CE4(4, 0x210, 1U);
            var_r5_31036 = 0xFFF0;
            var_r7_31035 = 1;
            goto block_14;
        case 4:
            sub_02028CE4(4, 0xFFFF, 0U);
            sub_02028CE4(4, 0, 1U);
            var_r5_31036 = (u16) ((s32) (((*(u8 *)0x03001A59 << 8) | *(u8 *)0x03001A58) << 0x10) >> 0x11);
            goto block_14;
        }
    }
}

void sub_02026D74(void **arg0, u8 arg1, u8 arg2, u16 arg3) {
    u8 temp_r0_31156;
    u8 temp_r0_31183;
    u8 var_r0_31173;
    u8 var_r4_31139;

    var_r4_31139 = arg1;
    if (arg0 != M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x2C)) {
        if (*(u8 *)0x03000052 == 2) {
            temp_r0_31156 = (u8) (var_r4_31139 % 12U);
            switch (temp_r0_31156) {                /* irregular */
            case 0:
                var_r0_31173 = var_r4_31139 + 2;
                goto block_17;
            case 1:
            case 3:
            case 5:
                var_r0_31173 = var_r4_31139 + 1;
                goto block_17;
            }
        } else {
            temp_r0_31183 = (u8) (var_r4_31139 % 12U);
            if (temp_r0_31183 != 5) {
                if ((s32) temp_r0_31183 <= 5) {
                    if (temp_r0_31183 != 0) {

                    } else {
                        goto block_16;
                    }
                } else if (temp_r0_31183 == 7) {
                    goto block_16;
                }
            } else {
block_16:
                var_r0_31173 = var_r4_31139 - 1;
block_17:
                var_r4_31139 = var_r0_31173;
            }
        }
    }
    sub_020279BC(arg0, var_r4_31139, arg2, arg3);
}

void sub_02026DFC(void *arg0, u8 arg1) {
    s32 var_r3_31234;
    u8 temp_r0_31216;
    void **var_r2_31233;
    void *temp_r1_31236;

    temp_r0_31216 = *(u8 *)0x03000052;
    if (((temp_r0_31216 == 4) && (arg1 != 0)) || ((temp_r0_31216 == 2) && ((u32) (0xF & *(u8 *)0x04000100) <= 4U))) {
        var_r2_31233 = M2C_FIELD(arg0, s32 *, 8) + 8;
        var_r3_31234 = 9;
        do {
            temp_r1_31236 = *var_r2_31233;
            if (temp_r1_31236 != NULL) {
                M2C_FIELD(temp_r1_31236, s32 *, 0x34) = (s32) (M2C_FIELD(temp_r1_31236, s32 *, 0x34) + 0x708);
            }
            var_r2_31233 += 4;
            var_r3_31234 -= 1;
        } while (var_r3_31234 >= 0);
    }
}

void sub_02026E4C(s32 arg0) {
    *(s32 *)0x03000594 = arg0;
    *(s8 *)0x04000084 = 0;
    *(s8 *)0x04000084 = 0x80;
    M2C_FIELD((void *)0x04000080, s16 *, 0) = 0xFF77;
    M2C_FIELD((void *)0x04000080, s8 *, 2) = 0xD;
    *(u16 *)0x04000088 = (0x3FFF & *(u16 *)0x04000088) | 0x4000;
    M2C_FIELD((void *)0x04000060, s16 *, 0) = 8;
    M2C_FIELD((void *)0x04000060, s16 *, 2) = 0xF000;
    CpuFastSet(sub_02029004, (void *)0x03001064, 0xD8U);
    *(s32 *)0x03000598 = 0x03001064;
    *(s32 *)0x0300059C = (sub_020290C4 - sub_02029004) + 0x03001064;
    *(s32 *)0x030005A0 = (sub_020291E4 - sub_02029004) + 0x03001064;
    sub_02026F3C(0x030005A4);
    sub_02028ACC();
    sub_02028098();
    sub_02027074();
    sub_02028480();
    sub_02028190();
}

void sub_02026F0C(void) {
    sub_02026FAC();
}

void sub_02026F18(void) {
    sub_02028E38();
    sub_020281FC();
    sub_02027728();
    if (*(u8 *)0x0300006B != 0) {
        sub_02027610();
    }
}

void sub_02026F3C(s32 arg0) {
    *(s8 *)0x0300006B = 1;
    M2C_FIELD((void *)0x03000058, s32 *, 0) = arg0;
    M2C_FIELD((void *)0x03000060, s32 *, 0) = (s32) (arg0 + 0xB0);
    M2C_FIELD((void *)0x03000058, s32 *, 4) = (s32) (arg0 + 0x160);
    M2C_FIELD((void *)0x03000060, s32 *, 4) = (s32) (arg0 + 0x210);
    *(s16 *)0x03000068 = 0xF9C4;
    *(s8 *)0x0300006A = 0;
    *(s8 *)0x04000083 = 0x9A;
    M2C_FIELD((void *)0x040000A0, s32 *, 0) = 0;
    M2C_FIELD((void *)0x040000A0, s32 *, 4) = 0;
}

void sub_02026FAC(void) {
    *(s32 *)0x04000100 = *(u16 *)0x03000068 | 0x800000;
    if (*(u8 *)0x0300006B != 0) {
        M2C_FIELD((void *)0x040000BC, u16 *, 0xA) = (u16) ((u32) (M2C_FIELD((void *)0x040000BC, u16 *, 0xA) << 0x11) >> 0x11);
        M2C_FIELD((void *)0x040000C8, u16 *, 0xA) = (u16) ((u32) (M2C_FIELD((void *)0x040000C8, u16 *, 0xA) << 0x11) >> 0x11);
        M2C_FIELD((void *)0x040000BC, s32 *, 0) = (s32) *(0x03000058 + (*(u8 *)0x0300006A * 4));
        M2C_FIELD((void *)0x040000BC, s32 *, 4) = 0x040000A0;
        M2C_FIELD((void *)0x040000BC, s32 *, 8) = 0xB6400004;
        M2C_FIELD((void *)0x040000C8, s32 *, 0) = (s32) *(0x03000060 + (*(u8 *)0x0300006A * 4));
        M2C_FIELD((void *)0x040000C8, s32 *, 4) = 0x040000A4;
        M2C_FIELD((void *)0x040000C8, s32 *, 8) = 0xB6400004;
        *(u8 *)0x0300006A = 1 - *(u8 *)0x0300006A;
    }
}

void sub_02027040(void) {
    void *temp_r1_31488;

    *(s8 *)0x0300006B = 0;
    M2C_FIELD((void *)0x040000BC, u16 *, 0xA) = (u16) ((u32) (M2C_FIELD((void *)0x040000BC, u16 *, 0xA) << 0x11) >> 0x11);
    temp_r1_31488 = (void *)0x040000BC + 0xC;
    M2C_FIELD(temp_r1_31488, u16 *, 0xA) = (u16) ((u32) (M2C_FIELD(temp_r1_31488, u16 *, 0xA) << 0x11) >> 0x11);
}

void sub_02027068(void) {
    *(s8 *)0x0300006B = 1;
}

void sub_02027074(void) {
    s32 var_r4_31524;
    s32 var_r4_31549;
    s32 var_r4_31597;
    s32 var_r6_31596;
    s8 *var_r0_31526;
    u8 temp_r1_31601;
    u8 var_r3_31595;
    void *temp_r1_31579;
    void *temp_r2_31583;
    void *temp_r7_31522;
    void *var_r0_31548;
    void *var_r2_31594;

    M2C_FIELD((void *)0x03000070, s32 *, 0) = 0;
    temp_r7_31522 = (void *)0x03000070 + 0x178;
    var_r4_31524 = 3;
    var_r0_31526 = (s8 *)0x0300189D;
    do {
        *var_r0_31526 = 0;
        var_r0_31526 -= 0x7C;
        var_r4_31524 -= 1;
    } while (var_r4_31524 >= 0);
    M2C_FIELD((void *)0x03001728, s8 *, 0) = 1;
    M2C_FIELD((void *)0x03001728, s8 *, 0x7C) = 2;
    M2C_FIELD(((void *)0x03001728 + 0x7C), s8 *, 0x7C) = 3;
    M2C_FIELD((void *)0x03001728, s8 *, 0x174) = 4;
    var_r0_31548 = (void *)0x030013C4;
    var_r4_31549 = 6;
    do {
        M2C_FIELD(var_r0_31548, s8 *, 1) = 0;
        M2C_FIELD(var_r0_31548, s8 *, 0) = 0;
        var_r0_31548 += 0x7C;
        var_r4_31549 -= 1;
    } while (var_r4_31549 >= 0);
    M2C_FIELD((void *)0x03000070, s32 *, 0x16C) = 0x030013C4;
    *(s8 *)0x03001434 = 0x03001440;
    M2C_FIELD((void *)0x03001435, s8 *, 0) = (s8) (0x03001440U >> 8);
    M2C_FIELD((void *)0x03001435, s8 *, 1) = (s8) (0x03001440U >> 0x10);
    *(s8 *)0x03001437 = (s8) (0x03001440U >> 0x18);
    temp_r1_31579 = (void *)0x03000070 + 0xFC;
    *(s8 *)0x03001430 = (s8) temp_r1_31579;
    temp_r2_31583 = ((void *)0x03001435 + 1) - 5;
    M2C_FIELD(temp_r2_31583, s8 *, 0) = (s8) ((u32) temp_r1_31579 >> 8);
    M2C_FIELD(temp_r2_31583, s8 *, 1) = (s8) ((u32) temp_r1_31579 >> 0x10);
    *(s8 *)0x03001433 = (s8) ((u32) temp_r1_31579 >> 0x18);
    var_r2_31594 = temp_r2_31583 + 1 + 0x7A;
    var_r3_31595 = 0x030013C4;
    var_r6_31596 = 0x7C;
    var_r4_31597 = 4;
    do {
        temp_r1_31601 = var_r6_31596 + 0x03001440;
        M2C_FIELD(var_r2_31594, u8 *, 4) = temp_r1_31601;
        M2C_FIELD(var_r2_31594, u8 *, 5) = (u8) (temp_r1_31601 >> 8);
        M2C_FIELD(var_r2_31594, u8 *, 6) = (u8) (temp_r1_31601 >> 0x10);
        M2C_FIELD(var_r2_31594, s8 *, 7) = (s8) (temp_r1_31601 >> 0x18);
        M2C_FIELD(var_r2_31594, u8 *, 0) = var_r3_31595;
        M2C_FIELD(var_r2_31594, u8 *, 1) = (u8) (var_r3_31595 >> 8);
        M2C_FIELD(var_r2_31594, u8 *, 2) = (u8) (var_r3_31595 >> 0x10);
        M2C_FIELD(var_r2_31594, s8 *, 3) = (s8) (var_r3_31595 >> 0x18);
        var_r2_31594 += 0x7C;
        var_r3_31595 += 0x7C;
        var_r6_31596 += 0x7C;
        var_r4_31597 -= 1;
    } while (var_r4_31597 >= 0);
    *(s8 *)0x0300171C = (s8) temp_r7_31522;
    *(s8 *)0x0300171D = (s8) ((u32) temp_r7_31522 >> 8);
    *(s8 *)0x0300171E = (s8) ((u32) temp_r7_31522 >> 0x10);
    *(s8 *)0x0300171F = (s8) ((u32) temp_r7_31522 >> 0x18);
    *(s8 *)0x03001718 = 0x03001630;
    *(s8 *)0x03001719 = (s8) (0x03001630U >> 8);
    *(s8 *)0x0300171A = (s8) (0x03001630U >> 0x10);
    *(s8 *)0x0300171B = (s8) (0x03001630U >> 0x18);
    M2C_FIELD(temp_r7_31522, s32 *, 0x6C) = 0x030016AC;
    M2C_FIELD((temp_r7_31522 + 0xFFFFFE88), s32 *, 0x74) = (s32) (temp_r7_31522 - 0xF8);
    *(temp_r7_31522 - 0x8C) = temp_r7_31522 + 0xFFFFFE8C;
}

void sub_020271FC(u8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0x70) = (void *) M2C_FIELD(arg0, void **, 0x70);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x70), void **, 0x6C) = (void *) M2C_FIELD(arg0, void **, 0x6C);
}

void sub_0202720C(u8 *arg0) {
    u8 temp_r0_31754;
    u8 temp_r2_31715;
    void *temp_r2_31748;
    void *var_r1_31714;

    var_r1_31714 = M2C_FIELD((void *)0x03000070, void **, 0x74);
    temp_r2_31715 = M2C_FIELD(arg0, u8 *, 1);
    if (temp_r2_31715 == 1) {
        if ((var_r1_31714 != ((void *)0x03000070 + 0x80)) && ((M2C_FIELD(var_r1_31714, u8 *, 1) != 1) || ((u32) M2C_FIELD(arg0, u8 *, 8) >= (u32) M2C_FIELD(var_r1_31714, u8 *, 8)))) {
loop_4:
            var_r1_31714 = M2C_FIELD(var_r1_31714, void **, 0x70);
            if (var_r1_31714 != (void *)0x030000F0) {
                if ((M2C_FIELD(var_r1_31714, u8 *, 1) == 1) && ((u32) M2C_FIELD(arg0, u8 *, 8) < (u32) M2C_FIELD(var_r1_31714, u8 *, 8))) {

                } else {
                    goto loop_4;
                }
            }
        }
        goto block_16;
    }
    if (temp_r2_31715 == 2) {
        temp_r2_31748 = (void *)0x03000070 + 0x80;
        if ((var_r1_31714 != temp_r2_31748) && (M2C_FIELD(var_r1_31714, u8 *, 1) != 1)) {
            temp_r0_31754 = M2C_FIELD(arg0, u8 *, 8);
            if ((u32) temp_r0_31754 >= (u32) M2C_FIELD(var_r1_31714, u8 *, 8)) {
loop_13:
                var_r1_31714 = M2C_FIELD(var_r1_31714, void **, 0x70);
                if ((var_r1_31714 != temp_r2_31748) && (M2C_FIELD(var_r1_31714, u8 *, 1) != 1)) {
                    if ((u32) temp_r0_31754 >= (u32) M2C_FIELD(var_r1_31714, u8 *, 8)) {
                        goto loop_13;
                    }
                }
            }
        }
block_16:
        M2C_FIELD(arg0, void **, 0x70) = var_r1_31714;
        M2C_FIELD(arg0, u8 **, 0x6C) = (u8 *) M2C_FIELD(var_r1_31714, u8 **, 0x6C);
        M2C_FIELD(M2C_FIELD(var_r1_31714, u8 **, 0x6C), u8 **, 0x70) = arg0;
        M2C_FIELD(var_r1_31714, u8 **, 0x6C) = arg0;
    }
}

s32 sub_02027294(u8 *arg0, u8 arg1, u8 arg2) {
    s16 temp_r1_31793;
    u16 temp_r1_31790;
    u16 var_r2_31792;
    u8 temp_r0_31803;

    temp_r1_31790 = (arg1 + 0x30) - arg2;
    var_r2_31792 = temp_r1_31790;
    temp_r1_31793 = (s16) temp_r1_31790;
    if ((s32) temp_r1_31793 < 0) {
        var_r2_31792 = 0;
    } else if ((s32) temp_r1_31793 > 0x77) {
        var_r2_31792 = 0x78;
    }
    temp_r0_31803 = *arg0;
    switch (temp_r0_31803) {                        /* irregular */
    case 0:
        return *(0x02035E48 + ((s32) (var_r2_31792 << 0x10) >> 0xE));
    case 4:
        return (s32) (s16) var_r2_31792;
    default:
        return (s32) *(0x02035CE0 + ((s32) (var_r2_31792 << 0x10) >> 0xF));
    }
}

u8 sub_020272E8(u16 arg0) {
    u16 var_r1_31835;

    var_r1_31835 = arg0;
    if ((u32) var_r1_31835 > 0x77U) {
        var_r1_31835 = 0x77;
    }
    return *(0x02035DD0 + var_r1_31835);
}

void sub_02027300(u8 *arg0) {
    s16 temp_r1_31877;
    s32 temp_r2_31863;
    u8 temp_r1_31858;
    void *temp_r4_31852;

    temp_r4_31852 = arg0 + 0x44;
    if (M2C_FIELD(temp_r4_31852, u16 *, 8) == 0) {
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(temp_r4_31852, s32 *, 4);
        temp_r1_31858 = M2C_FIELD(temp_r4_31852, u8 *, 0x10);
        M2C_FIELD(temp_r4_31852, u8 *, 0x10) = (u8) (temp_r1_31858 + 1);
        temp_r2_31863 = M2C_FIELD(temp_r4_31852, s32 *, 0xC);
        if ((s32) *(((s8) M2C_FIELD(temp_r4_31852, u8 *, 0x10) * 4) + temp_r2_31863) < 0) {
            M2C_FIELD(temp_r4_31852, u8 *, 0x10) = temp_r1_31858;
        }
        temp_r1_31877 = M2C_FIELD((((s8) M2C_FIELD(temp_r4_31852, u8 *, 0x10) * 4) + temp_r2_31863), s16 *, 2);
        M2C_FIELD(temp_r4_31852, s32 *, 4) = (s32) temp_r1_31877;
        M2C_FIELD(temp_r4_31852, u16 *, 8) = (u16) *(((s8) M2C_FIELD(temp_r4_31852, u8 *, 0x10) * 4) + temp_r2_31863);
        M2C_FIELD(temp_r4_31852, s16 *, 0xA) = temp_r1_31877;
        M2C_FIELD(temp_r4_31852, s16 *, 0xA) = (s16) (temp_r1_31877 - M2C_FIELD(arg0, s32 *, 0x44));
        M2C_FIELD(temp_r4_31852, s16 *, 0xA) = (s16) ((s16) M2C_FIELD(temp_r4_31852, s16 *, 0xA) / (s32) M2C_FIELD(temp_r4_31852, u16 *, 8));
    }
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) + M2C_FIELD(temp_r4_31852, s16 *, 0xA));
    M2C_FIELD(temp_r4_31852, u16 *, 8) = (u16) (M2C_FIELD(temp_r4_31852, u16 *, 8) - 1);
}

void sub_02027370(void) {

}

u32 sub_02027374(u8 *arg0) {
    u32 temp_r0_31952;
    u32 temp_r4_31938;
    u32 var_r4_31942;
    void *temp_r0_31922;
    void *temp_r2_31921;

    if (M2C_FIELD(arg0, u8 *, 1) == 1) {
        temp_r2_31921 = M2C_FIELD(arg0, void **, 4);
        temp_r0_31922 = M2C_FIELD(temp_r2_31921, void **, 8);
        temp_r4_31938 = (u32) (M2C_FIELD(temp_r2_31921, u8 *, 0x4E) * ((u32) (M2C_FIELD(temp_r2_31921, u8 *, 0x4D) * ((u32) (M2C_FIELD(temp_r0_31922, u8 *, 0x40) * ((u32) (M2C_FIELD(temp_r0_31922, u16 *, 0x34) * (M2C_FIELD(arg0, u8 *, 9) << 8)) >> 7)) >> 7)) >> 0xF)) >> 7;
        var_r4_31942 = (u32) ((s32) sub_02027300(arg0) * temp_r4_31938) >> 0xF;
        M2C_FIELD(arg0, u32 *, 0x14) = var_r4_31942;
    } else {
        temp_r0_31952 = (u32) (M2C_FIELD(arg0, u32 *, 0x14) * (M2C_FIELD(arg0, u8 *, 0x5C) + 0xE6)) >> 9;
        M2C_FIELD(arg0, u32 *, 0x14) = temp_r0_31952;
        var_r4_31942 = temp_r0_31952;
    }
    return var_r4_31942 >> 8;
}

u8 sub_020273D0(u8 *arg0, u8 arg1) {
    s32 var_r1_32060;
    s32 var_r6_31970;
    u16 var_r2_32068;
    u32 temp_r0_32043;
    u32 temp_r4_32010;
    u32 temp_r4_32014;
    u32 temp_r4_32027;
    u32 temp_r5_32051;
    u32 var_r4_32018;
    u32 var_r4_32031;
    u8 var_r4_31971;
    u8 var_r6_32076;
    void *temp_r1_31992;
    void *temp_r1_32003;

    var_r6_31970 = 0;
    var_r4_31971 = M2C_FIELD(arg0, u8 *, 9);
    if (M2C_FIELD(arg0, u16 *, 0x4C) == 0) {
        var_r6_31970 = 1;
    }
    sub_02027300(arg0);
    if (var_r6_31970 == 0) {
        return 8U;
    }
    if (arg1 != 0) {
        var_r4_31971 *= 2;
    }
    temp_r1_31992 = M2C_FIELD(arg0, void **, 4);
    temp_r1_32003 = M2C_FIELD(temp_r1_31992, void **, 8);
    temp_r4_32010 = M2C_FIELD(temp_r1_32003, u16 *, 0x34) * ((u32) (M2C_FIELD(temp_r1_32003, u8 *, 0x40) * ((u32) (M2C_FIELD(temp_r1_31992, u8 *, 0x4E) * ((u32) (M2C_FIELD(temp_r1_31992, u8 *, 0x4D) * (var_r4_31971 << 0xF)) >> 0xE)) >> 7)) >> 8);
    if (M2C_FIELD(arg0, u8 *, 0) == 3) {
        temp_r4_32014 = temp_r4_32010 >> 0x16;
        M2C_FIELD(arg0, u32 *, 0x14) = temp_r4_32014;
        var_r4_32018 = (u32) (temp_r4_32014 * 5) >> 7;
        if (var_r4_32018 > 4U) {
            var_r4_32018 = 4;
        }
        return (u8) var_r4_32018;
    }
    temp_r4_32027 = temp_r4_32010 >> 0xF;
    M2C_FIELD(arg0, u32 *, 0x14) = temp_r4_32027;
    var_r4_32031 = (u32) (M2C_FIELD(arg0, s32 *, 0x44) * temp_r4_32027) >> 0x19;
    if (var_r4_32031 & ~0xF) {
        var_r4_32031 = 0xF;
    }
    temp_r0_32043 = (u32) (M2C_FIELD(arg0, u32 *, 0x14) * M2C_FIELD(arg0, s32 *, 0x48)) >> 0x19;
    M2C_FIELD(arg0, u32 *, 0x14) = temp_r0_32043;
    if (temp_r0_32043 & ~0xF) {
        M2C_FIELD(arg0, u32 *, 0x14) = 0xFU;
    }
    temp_r5_32051 = M2C_FIELD(arg0, u32 *, 0x14);
    if (temp_r5_32051 != var_r4_32031) {
        var_r1_32060 = temp_r5_32051 - var_r4_32031;
        if (var_r1_32060 < 0) {
            var_r1_32060 = 0 - var_r1_32060;
        }
        var_r2_32068 = (u16) ((s32) (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + 0xF) / var_r1_32060);
        if (var_r2_32068 == 0) {
            goto block_18;
        }
        if (0xFFF8 & var_r2_32068) {
            var_r2_32068 = 7;
        }
        var_r6_32076 = (var_r4_32031 * 0x10) | var_r2_32068;
        if (var_r4_32031 < temp_r5_32051) {
            var_r6_32076 |= 8;
        }
    } else {
block_18:
        var_r6_32076 = (var_r4_32031 * 0x10) | 8;
    }
    return var_r6_32076;
}

u32 sub_020274D0(u8 *arg0) {
    s32 temp_r0_32112;
    s32 temp_r0_32126;
    s32 temp_r0_32183;
    s32 temp_r1_32157;
    s32 temp_r2_32180;
    s32 temp_r4_32119;
    s8 temp_r0_32195;
    s8 temp_r1_32221;
    u32 temp_r1_32253;
    u32 var_r0_32232;
    u32 var_r3_32134;
    u8 temp_r1_32190;
    void *temp_r2_32111;
    void *temp_r4_32178;
    void *temp_r6_32109;

    temp_r6_32109 = M2C_FIELD(arg0, void **, 4);
    temp_r2_32111 = arg0 + 0x2C;
    temp_r0_32112 = M2C_FIELD(arg0, s32 *, 0x2C);
    if (temp_r0_32112 != 0) {
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_r0_32112 - 1);
    } else {
        temp_r4_32119 = M2C_FIELD(temp_r2_32111, s32 *, 4);
        if (temp_r4_32119 != 0) {
            M2C_FIELD(temp_r2_32111, s32 *, 8) = (s32) (M2C_FIELD(temp_r2_32111, s32 *, 8) + M2C_FIELD(temp_r2_32111, s32 *, 0x10));
            temp_r0_32126 = temp_r4_32119 - 1;
            M2C_FIELD(temp_r2_32111, s32 *, 4) = temp_r0_32126;
            if (temp_r0_32126 == 0) {
                M2C_FIELD(temp_r2_32111, s32 *, 8) = (s32) M2C_FIELD(temp_r2_32111, s32 *, 0xC);
            }
        }
    }
    var_r3_32134 = M2C_FIELD(arg0, s32 *, 0xC) + M2C_FIELD(temp_r2_32111, s32 *, 8);
    if (M2C_FIELD(temp_r6_32109, s8 *, 0x4F) != 0) {
        temp_r1_32157 = (s32) ((M2C_FIELD(temp_r6_32109, s8 *, 0x4F) * (*(0x02035E48 + ((M2C_FIELD(temp_r6_32109, u8 *, 0x50) + 0x30) * 4)) + 0xFFFF8000)) + 0x400000) >> 0xE;
        if (M2C_FIELD(arg0, u8 *, 0) == 0) {
            var_r3_32134 = (u32) (temp_r1_32157 * var_r3_32134) >> 8;
        } else {
            var_r3_32134 = 0x800 - ((u32) ((0x800 - var_r3_32134) << 8) / (u32) temp_r1_32157);
        }
    }
    temp_r4_32178 = arg0 + 0x20;
    temp_r2_32180 = M2C_FIELD(M2C_FIELD(temp_r4_32178, void **, 8), s32 *, 8);
    if (temp_r2_32180 != 0) {
        temp_r0_32183 = M2C_FIELD(temp_r4_32178, s32 *, 4);
        if (temp_r0_32183 == 0) {
            temp_r1_32190 = *(0x02036028 + ((u32) M2C_FIELD(arg0, u32 *, 0x20) >> 1));
            if (M2C_FIELD(arg0, u8 *, 0) == 0) {
                temp_r0_32195 = (s8) temp_r1_32190;
                if ((s32) temp_r0_32195 >= 0) {
                    var_r3_32134 += (u32) (temp_r2_32180 * (var_r3_32134 * temp_r0_32195)) >> 0x13;
                } else {
                    var_r3_32134 = ((u32) (var_r3_32134 << 0xC) / (u32) (((u32) (temp_r2_32180 * (0 - temp_r0_32195)) >> 3) + 0x10000)) * 0x10;
                }
            } else {
                temp_r1_32221 = (s8) temp_r1_32190;
                if ((s32) temp_r1_32221 >= 0) {
                    var_r0_32232 = (u32) ((0x800 - var_r3_32134) << 0x13) / (u32) ((temp_r2_32180 * temp_r1_32221) + 0x80000);
                } else {
                    var_r0_32232 = (u32) (((temp_r2_32180 * (0 - temp_r1_32221)) + 0x80000) * (0x800 - var_r3_32134)) >> 0x13;
                }
                var_r3_32134 = 0x800 - var_r0_32232;
            }
            temp_r1_32253 = M2C_FIELD(arg0, u32 *, 0x20) + M2C_FIELD(M2C_FIELD(temp_r4_32178, void **, 8), s32 *, 4);
            M2C_FIELD(arg0, u32 *, 0x20) = temp_r1_32253;
            if ((u32) (temp_r1_32253 >> 1) > 0xFFU) {
                M2C_FIELD(arg0, u32 *, 0x20) = (u32) (temp_r1_32253 + 0xFFFFFE00);
            }
        } else {
            M2C_FIELD(temp_r4_32178, s32 *, 4) = (s32) (temp_r0_32183 - 1);
        }
    }
    return var_r3_32134;
}

void sub_02027610(void) {
    s32 sp0;
    s32 var_r4_32367;
    s32 var_r5_32366;
    u32 temp_r7_32291;
    u32 var_r2_32316;
    u8 *temp_r1_32370;
    u8 *var_r5_32278;
    u8 var_r3_32302;
    u8 var_r6_32313;
    void *temp_r4_32298;

    var_r5_32278 = M2C_FIELD((void *)0x03000070, u8 **, 0x74);
    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03000864, 0x010000B0U);
    if (var_r5_32278 != ((void *)0x03000070 + 0x80)) {
        do {
            temp_r7_32291 = sub_02027374(var_r5_32278);
            if (M2C_FIELD(var_r5_32278, u8 *, 1) == 1) {
                M2C_FIELD(var_r5_32278, u16 *, 0x18) = (u16) (M2C_FIELD(var_r5_32278, u16 *, 0x18) - 1);
                temp_r4_32298 = M2C_FIELD(var_r5_32278, void **, 4);
                if (M2C_FIELD(var_r5_32278, u8 *, 0x1B) != 0) {
                    var_r3_32302 = M2C_FIELD(var_r5_32278, u8 *, 0x1C);
                } else {
                    var_r3_32302 = M2C_FIELD(temp_r4_32298, u8 *, 0x4B);
                }
                var_r6_32313 = var_r3_32302;
                var_r2_32316 = sub_020274D0(var_r5_32278);
                M2C_FIELD(var_r5_32278, u32 *, 0x10) = var_r2_32316;
                M2C_FIELD(var_r5_32278, u8 *, 0x1A) = (u8) M2C_FIELD(temp_r4_32298, u8 *, 0x4C);
                goto block_8;
            }
            if (temp_r7_32291 != 0) {
                var_r6_32313 = M2C_FIELD(var_r5_32278, u8 *, 0x1C);
                var_r2_32316 = M2C_FIELD(var_r5_32278, u32 *, 0x10);
block_8:
                if (sub_02027F0C(var_r5_32278, temp_r7_32291, (u32) ((u32) (0xB0 * ((u32) (M2C_FIELD(M2C_FIELD(var_r5_32278, void **, 0x60), s32 *, 4) * (var_r2_32316 >> 2)) / 10512U)) / 176U) >> 5, var_r6_32313) == 1) {
                    goto block_9;
                }
                var_r5_32278 = M2C_FIELD(var_r5_32278, u8 **, 0x70);
            } else {
block_9:
                var_r5_32278 = M2C_FIELD(var_r5_32278, u8 **, 0x70);
                sub_02027C78(M2C_FIELD(var_r5_32278, u8 **, 0x6C));
            }
        } while (var_r5_32278 != (u8 *)0x030000F0);
    }
    var_r5_32366 = 0;
    var_r4_32367 = 6;
    do {
        temp_r1_32370 = var_r5_32366 + 0x030013C4;
        if ((M2C_FIELD(temp_r1_32370, u8 *, 1) == 1) && (M2C_FIELD(temp_r1_32370, u16 *, 0x18) == 0)) {
            sub_02027B94(temp_r1_32370);
        }
        var_r5_32366 += 0x7C;
        var_r4_32367 -= 1;
    } while (var_r4_32367 >= 0);
    *(M2C_UNK (**)(s32, s32, s32))0x03000598(0x03000864, *(0x03000058 + (*(u8 *)0x0300006A * 4)), 0x03000B24);
}

void sub_02027728(void) {
    s32 temp_r0_32422;
    s32 temp_r0_32466;
    s32 var_sl_32417;
    u16 *temp_r0_32593;
    u16 temp_r3_32594;
    u32 temp_r0_32526;
    u32 temp_r0_32554;
    u32 temp_r1_32595;
    u32 var_r1_32556;
    u32 var_r1_32564;
    u32 var_r6_32443;
    u8 *temp_r4_32424;
    u8 *var_r2_32644;
    u8 temp_r0_32434;
    u8 temp_r0_32608;
    u8 temp_r2_32485;
    u8 temp_r3_32479;
    u8 temp_r5_32482;
    u8 temp_r5_32523;
    u8 temp_r7_32473;
    u8 var_r0_32448;
    u8 var_r1_32718;
    u8 var_r5_32599;
    u8 var_r8_32457;
    void *temp_r2_32587;

    var_sl_32417 = 0;
loop_1:
    temp_r0_32422 = var_sl_32417 * 0x7C;
    temp_r4_32424 = temp_r0_32422 + 0x03001728;
    if ((M2C_FIELD(temp_r4_32424, u8 *, 1) == 1) && (M2C_FIELD(temp_r4_32424, u16 *, 0x18) == 0)) {
        sub_02027B94(temp_r4_32424);
    }
    temp_r0_32434 = M2C_FIELD(temp_r4_32424, u8 *, 1);
    if (temp_r0_32434 == 0) {

    } else {
        if (temp_r0_32434 == 1) {
            var_r6_32443 = sub_020274D0(temp_r4_32424);
            M2C_FIELD(temp_r4_32424, u32 *, 0x10) = var_r6_32443;
            if (M2C_FIELD(temp_r4_32424, u8 *, 0x1B) != 0) {
                var_r0_32448 = M2C_FIELD(temp_r4_32424, u8 *, 0x1C);
            } else {
                var_r0_32448 = M2C_FIELD(M2C_FIELD(temp_r4_32424, void **, 4), u8 *, 0x4B);
            }
            var_r8_32457 = var_r0_32448;
        } else {
            var_r6_32443 = M2C_FIELD(temp_r4_32424, u32 *, 0x10);
            var_r8_32457 = M2C_FIELD(temp_r4_32424, u8 *, 0x1C);
        }
        temp_r0_32466 = 0x40 ^ var_r8_32457;
        temp_r7_32473 = sub_020273D0(temp_r4_32424, (u8) ((u32) ((0 - temp_r0_32466) | temp_r0_32466) >> 0x1F));
        temp_r3_32479 = *(0x03001728 + temp_r0_32422) - 1;
        temp_r5_32482 = 0x11 << temp_r3_32479;
        temp_r2_32485 = ~temp_r5_32482;
        if (var_r8_32457 == 0x40) {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | temp_r5_32482;
        } else if ((u32) var_r8_32457 <= 0x3FU) {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | (0x10 << temp_r3_32479);
        } else {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | (1 << temp_r3_32479);
        }
        temp_r5_32523 = M2C_FIELD(temp_r4_32424, u8 *, 1);
        if (temp_r5_32523 == 1) {
            temp_r0_32526 = M2C_FIELD(temp_r4_32424, u32 *, 0x64);
            if (temp_r0_32526 == 0) {
                sub_02027D14(temp_r4_32424, temp_r7_32473);
                M2C_FIELD(temp_r4_32424, u32 *, 0x64) = (u32) temp_r5_32523;
                M2C_FIELD(temp_r4_32424, u16 *, 0x18) = (u16) (M2C_FIELD(temp_r4_32424, u16 *, 0x18) - 1);
            } else {
                M2C_FIELD(temp_r4_32424, u32 *, 0x64) = (u32) (temp_r0_32526 + 1);
                M2C_FIELD(temp_r4_32424, u16 *, 0x18) = (u16) (M2C_FIELD(temp_r4_32424, u16 *, 0x18) - 1);
                goto block_29;
            }
        } else if (*(0x03001728 + temp_r0_32422) == 3) {
            temp_r0_32554 = (u32) (M2C_FIELD(temp_r4_32424, u32 *, 0x14) * (M2C_FIELD(temp_r4_32424, u8 *, 0x5C) + 0xE6)) >> 9;
            M2C_FIELD(temp_r4_32424, u32 *, 0x14) = temp_r0_32554;
            var_r1_32556 = temp_r0_32554;
            if (var_r8_32457 != 0x40) {
                var_r1_32556 *= 2;
            }
            var_r1_32564 = (u32) (var_r1_32556 * 5) >> 7;
            if (var_r1_32564 != 0) {
                if (var_r1_32564 > 4U) {
                    var_r1_32564 = 4;
                }
                *(u8 *)0x04000073 = *(0x02035CC4 + (u8) var_r1_32564);
            } else {
                sub_02027C78(temp_r4_32424);
            }
        } else {
block_29:
            temp_r2_32587 = M2C_FIELD(temp_r4_32424, void **, 0x58);
            if (1 & M2C_FIELD(temp_r2_32587, u8 *, 1)) {
                temp_r0_32593 = M2C_FIELD(temp_r4_32424, u16 **, 0x68);
                temp_r3_32594 = *temp_r0_32593;
                temp_r1_32595 = M2C_FIELD(temp_r4_32424, u32 *, 0x64);
                if (temp_r1_32595 < (u32) temp_r3_32594) {
                    var_r5_32599 = M2C_FIELD((temp_r0_32593 + temp_r1_32595), u8 *, 2);
                } else {
                    var_r5_32599 = M2C_FIELD((temp_r3_32594 + temp_r0_32593), u8 *, 1);
                }
            } else {
                var_r5_32599 = 0xFF;
            }
            temp_r0_32608 = *(0x03001728 + temp_r0_32422);
            switch (temp_r0_32608) {                /* irregular */
            case 1:
                if (temp_r7_32473 != 8) {
                    *(u8 *)0x04000063 = temp_r7_32473;
                    *(s16 *)0x04000064 = var_r6_32443 | 0x8000;
                } else if (M2C_FIELD(temp_r2_32587, u8 *, 8) == 8) {
                    *(void *)0x04000064 = (s16) var_r6_32443;
                }
                var_r2_32644 = (u8 *)0x04000062;
block_50:
                *var_r2_32644 &= 0xC0;
                if (var_r5_32599 != 0xFF) {
                    *var_r2_32644 = var_r5_32599 << 6;
                }
                break;
            case 2:
                if (temp_r7_32473 != 8) {
                    *(u8 *)0x04000069 = temp_r7_32473;
                    *(s16 *)0x0400006C = var_r6_32443 | 0x8000;
                } else {
                    *(void *)0x0400006C = (s16) var_r6_32443;
                }
                var_r2_32644 = (u8 *)0x04000068;
                goto block_50;
            case 3:
                *(u16 *)0x04000074 = (*(u16 *)0x04000074 & 0x4000) | var_r6_32443;
                if (temp_r7_32473 != 8) {
                    *(void *)0x04000073 = (u8) *(0x02035CC4 + temp_r7_32473);
                }
                break;
            case 4:
                if (temp_r7_32473 != 8) {
                    *(u8 *)0x04000079 = temp_r7_32473;
                    *(s8 *)0x0400007D = 0x80;
                }
                if (var_r5_32599 != 0xFF) {
                    var_r1_32718 = sub_020272E8((u16) var_r6_32443);
                    if (var_r5_32599 != 0) {
                        var_r1_32718 |= 8;
                    }
                    *(u8 *)0x0400007C = var_r1_32718;
                } else {
                    *(void *)0x0400007C = (u8) ((8 & *(void *)0x0400007C) | sub_020272E8((u16) var_r6_32443));
                }
                break;
            }
        }
    }
    var_sl_32417 += 1;
    if (var_sl_32417 <= 3) {
        goto loop_1;
    }
}

void sub_020279BC(void **arg0, u8 arg1, u8 arg2, u16 arg3) {
    void *sp0;
    s32 temp_r0_32934;
    s32 temp_r1_32965;
    s32 temp_r2_32910;
    s32 var_r0_32980;
    u16 temp_r0_32810;
    u16 temp_r3_32772;
    u32 var_r0_32799;
    u8 *temp_r0_32817;
    u8 *var_r4_32820;
    u8 temp_r0_32866;
    u8 temp_r0_32903;
    u8 temp_r0_32943;
    u8 temp_r0_32961;
    u8 var_r7_32786;
    void *temp_r4_32774;

    temp_r3_32772 = arg3;
    temp_r4_32774 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(arg0, u8 *, 0x4A) != 0) {
        return;
    }
    var_r7_32786 = arg1 + M2C_FIELD(arg0, u8 *, 0x51);
    sub_020280B4(arg0, var_r7_32786, &sp0);
    if (0x10 & M2C_FIELD(sp0, u8 *, 1)) {
        var_r0_32799 = temp_r3_32772 / (u16) M2C_FIELD(temp_r4_32774, u16 *, 0x30);
    } else {
        var_r0_32799 = (u32) ((s32) temp_r3_32772 / (s32) (M2C_FIELD(temp_r4_32774, s16 *, 0x32) + M2C_FIELD(temp_r4_32774, u16 *, 0x30)));
    }
    temp_r0_32810 = (u16) var_r0_32799;
    if (M2C_FIELD(arg0, u8 *, 0x49) != 0) {
        temp_r0_32817 = M2C_FIELD(arg0, u8 **, 0xC);
        if (temp_r0_32817 != NULL) {
            var_r4_32820 = temp_r0_32817;
            goto block_11;
        }
    }
    var_r4_32820 = sub_02027E74(*(0x02035CCC + M2C_FIELD(sp0, u8 *, 0)), arg0, M2C_FIELD(arg0, u8 *, 0x52));
    if (var_r4_32820 == NULL) {
        return;
    }
    sub_02028A34(arg0, var_r4_32820);
    M2C_FIELD(var_r4_32820, s32 *, 0x64) = 0;
    M2C_FIELD(var_r4_32820, void ***, 0x28) = (void **) (arg0 + 0x10);
    M2C_FIELD(var_r4_32820, s32 *, 0x20) = 0;
    M2C_FIELD(var_r4_32820, s32 *, 0x24) = (s32) M2C_FIELD(arg0, u16 *, 0x10);
    M2C_FIELD(var_r4_32820, s32 *, 0x50) = sp4;
    M2C_FIELD(var_r4_32820, s32 *, 0x44) = 0;
    M2C_FIELD(var_r4_32820, s32 *, 0x48) = 0;
    M2C_FIELD(var_r4_32820, s16 *, 0x4C) = 0;
    M2C_FIELD(var_r4_32820, s8 *, 0x54) = 0xFF;
    M2C_FIELD(var_r4_32820, u8 *, 0x5C) = (u8) M2C_FIELD(sp0, u8 *, 6);
    M2C_FIELD(var_r4_32820, void **, 0x58) = sp0;
block_11:
    temp_r0_32866 = M2C_FIELD(&sp0, u8 *, 0x11);
    M2C_FIELD(var_r4_32820, u8 *, 0x1B) = temp_r0_32866;
    if ((temp_r0_32866 << 0x18) != 0) {
        var_r7_32786 = 0x30;
        M2C_FIELD(var_r4_32820, u8 *, 0x1C) = (u8) M2C_FIELD(&sp0, u8 *, 0x10);
    } else if (M2C_FIELD(&sp0, u8 *, 0x12) != 0) {
        var_r7_32786 = 0x30;
    }
    M2C_FIELD(var_r4_32820, u8 *, 9) = arg2;
    M2C_FIELD(var_r4_32820, s32 *, 0x14) = 0;
    M2C_FIELD(var_r4_32820, u16 *, 0x18) = temp_r0_32810;
    M2C_FIELD(var_r4_32820, u8 *, 0x1A) = (u8) M2C_FIELD(arg0, u8 *, 0x4C);
    M2C_FIELD(var_r4_32820, s32 *, 0xC) = sub_02027294(var_r4_32820, var_r7_32786, M2C_FIELD(sp0, u8 *, 7));
    M2C_FIELD(var_r4_32820, void ***, 0x40) = (void **) (arg0 + 0x1C);
    temp_r0_32903 = M2C_FIELD(arg0, u8 *, 0x1C);
    if (temp_r0_32903 != 0) {
        temp_r2_32910 = sub_02027294(var_r4_32820, M2C_FIELD(arg0, u8 *, 0x1E), M2C_FIELD(sp0, u8 *, 7));
        M2C_FIELD(var_r4_32820, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, u16 *, 0x20);
        M2C_FIELD(var_r4_32820, u32 *, 0x30) = (u32) ((u32) (M2C_FIELD(arg0, u16 *, 0x22) * temp_r0_32810) >> 8);
        if (2 & M2C_FIELD(arg0, u8 *, 0x1D)) {
            M2C_FIELD(var_r4_32820, s32 *, 0x38) = (s32) (temp_r2_32910 - M2C_FIELD(var_r4_32820, s32 *, 0xC));
        } else {
            M2C_FIELD(var_r4_32820, s32 *, 0x38) = (s32) (M2C_FIELD(var_r4_32820, s32 *, 0xC) - temp_r2_32910);
            M2C_FIELD(var_r4_32820, s32 *, 0xC) = temp_r2_32910;
        }
        temp_r0_32934 = M2C_FIELD(var_r4_32820, s32 *, 0x38);
        M2C_FIELD(var_r4_32820, s32 *, 0x3C) = temp_r0_32934;
        M2C_FIELD(var_r4_32820, s32 *, 0x3C) = (s32) (temp_r0_32934 / (s32) M2C_FIELD(var_r4_32820, u32 *, 0x30));
        temp_r0_32943 = 4 & M2C_FIELD(arg0, u8 *, 0x1D);
        if (temp_r0_32943 != 0) {
            M2C_FIELD(arg0, u8 *, 0x1E) = var_r7_32786;
        } else {
            M2C_FIELD(arg0, u8 *, 0x1C) = temp_r0_32943;
        }
        M2C_FIELD(var_r4_32820, s32 *, 0x34) = 0;
    } else {
        M2C_FIELD(var_r4_32820, s32 *, 0x2C) = (s32) temp_r0_32903;
        M2C_FIELD(var_r4_32820, u32 *, 0x30) = (u32) temp_r0_32903;
        M2C_FIELD(var_r4_32820, s32 *, 0x34) = (s32) temp_r0_32903;
        M2C_FIELD(var_r4_32820, s32 *, 0x38) = (s32) temp_r0_32903;
        M2C_FIELD(var_r4_32820, s32 *, 0x3C) = (s32) temp_r0_32903;
    }
    temp_r0_32961 = M2C_FIELD(var_r4_32820, u8 *, 0);
    if (temp_r0_32961 == 0) {
        temp_r1_32965 = M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(var_r4_32820, s32 *, 0x60) = (s32) (temp_r1_32965 + *((M2C_FIELD(sp0, u16 *, 2) * 4) + temp_r1_32965));
    } else if (temp_r0_32961 != 3) {
        if (1 & M2C_FIELD(sp0, u8 *, 1)) {
            var_r0_32980 = sp8;
            goto block_31;
        }
        M2C_FIELD(var_r4_32820, s8 *, 0x68) = (s8) M2C_FIELD(sp0, u16 *, 2);
    } else {
        var_r0_32980 = spC;
block_31:
        M2C_FIELD(var_r4_32820, s8 *, 0x68) = var_r0_32980;
    }
    if (temp_r0_32810 == 0) {
        sub_02027B94(var_r4_32820);
    }
}

void sub_02027B94(u8 *arg0) {
    u16 temp_r2_33030;
    u32 temp_r1_33039;
    u8 *var_r2_33072;
    u8 temp_r0_33051;
    u8 temp_r3_33019;
    u8 var_r0_33036;
    u8 var_r1_33042;
    void *temp_r1_33110;

    if ((M2C_FIELD(arg0, u8 *, 1) == 1) && (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x49) == 0)) {
        temp_r3_33019 = M2C_FIELD(arg0, u8 *, 0);
        if (temp_r3_33019 == 0) {
            sub_020271FC(arg0);
            M2C_FIELD(arg0, u8 *, 1) = 2U;
            sub_0202720C(arg0);
        } else {
            temp_r2_33030 = M2C_FIELD(arg0, u16 *, 0x10);
            if (temp_r3_33019 == 3) {
                var_r0_33036 = 2;
            } else {
                temp_r1_33039 = (u8) M2C_FIELD(arg0, u8 *, 0x5C) >> 5;
                if (temp_r1_33039 == 0) {
                    var_r1_33042 = 0;
                } else {
                    var_r1_33042 = temp_r1_33039 | (M2C_FIELD(arg0, s32 *, 0x14) * 0x10);
                }
                temp_r0_33051 = M2C_FIELD(arg0, u8 *, 0);
                switch (temp_r0_33051) {            /* irregular */
                case 1:
                    *(u8 *)0x04000063 = var_r1_33042;
                    *(s16 *)0x04000064 = temp_r2_33030 | 0x8000;
                    var_r2_33072 = (u8 *)0x04000062;
block_17:
                    *var_r2_33072 &= 0xC0;
                    break;
                case 2:
                    *(u8 *)0x04000069 = var_r1_33042;
                    *(s16 *)0x0400006C = temp_r2_33030 | 0x8000;
                    var_r2_33072 = (u8 *)0x04000068;
                    goto block_17;
                case 4:
                    *(u8 *)0x04000079 = var_r1_33042;
                    *(s8 *)0x0400007D = 0x80;
                    break;
                }
                var_r0_33036 = 0;
            }
            M2C_FIELD(arg0, u8 *, 1) = var_r0_33036;
        }
        temp_r1_33110 = M2C_FIELD(arg0, void **, 4);
        if (M2C_FIELD(arg0, u8 *, 0x1B) == 0) {
            M2C_FIELD(arg0, u8 *, 0x1C) = (u8) M2C_FIELD(temp_r1_33110, u8 *, 0x4B);
        }
        sub_02028A4C(temp_r1_33110, arg0);
    }
}

void sub_02027C78(u8 *arg0) {
    s8 *var_r1_33172;
    s8 *var_r1_33177;
    s8 var_r0_33183;
    u8 *temp_r1_33159;
    u8 temp_r0_33136;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        temp_r0_33136 = M2C_FIELD(arg0, u8 *, 0);
        switch (temp_r0_33136) {
        case 0:
            sub_020271FC(arg0);
            temp_r1_33159 = *(u8 **)0x030001DC;
            M2C_FIELD(arg0, u8 **, 0x70) = temp_r1_33159;
            M2C_FIELD(arg0, s32 *, 0x6C) = 0x0300016C;
            M2C_FIELD(temp_r1_33159, u8 **, 0x6C) = arg0;
            *(u8 **)0x030001DC = arg0;
            break;
        case 1:
            *(s8 *)0x04000063 = 8;
            var_r1_33172 = (s8 *)0x04000063 + 2;
block_9:
            var_r0_33183 = 0xC0;
block_10:
            *var_r1_33172 = var_r0_33183;
            break;
        case 2:
            var_r1_33177 = (s8 *)0x04000069;
block_8:
            *var_r1_33177 = 8;
            var_r1_33172 = var_r1_33177 + 4;
            goto block_9;
        case 3:
            var_r1_33172 = (s8 *)0x04000070;
            var_r0_33183 = 0;
            goto block_10;
        case 4:
            var_r1_33177 = (s8 *)0x04000079;
            goto block_8;
        }
        sub_02028A4C(M2C_FIELD(arg0, void **, 4), arg0);
        M2C_FIELD(arg0, u8 *, 1) = 0U;
    }
}

void sub_02027D14(u8 *arg0, u8 arg1) {
    s8 *var_r1_33287;
    s8 var_r0_33291;
    u8 temp_r3_33216;
    u8 temp_r5_33215;
    u8 var_r0_33251;
    u8 var_r0_33350;
    u8 var_r1_33348;

    temp_r5_33215 = arg1;
    temp_r3_33216 = M2C_FIELD(arg0, u8 *, 0);
    switch (temp_r3_33216) {                        /* irregular */
    case 1:
        *(u8 *)0x04000060 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u8 *, 8);
        *(s16 *)0x04000064 = M2C_FIELD(arg0, s32 *, 0xC) | 0x8000;
        *(u8 *)0x04000063 = temp_r5_33215;
        if (temp_r3_33216 & M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u8 *, 1)) {
            var_r0_33251 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 2);
        } else {
            var_r0_33251 = (u8) M2C_FIELD(arg0, void **, 0x68);
        }
        *(s8 *)0x04000062 = var_r0_33251 << 6;
        *(void *)0x04000064 = (s16) (M2C_FIELD(arg0, s32 *, 0xC) | 0x8000);
        return;
    case 2:
        *(u8 *)0x04000069 = temp_r5_33215;
        *(s16 *)0x0400006C = M2C_FIELD(arg0, s32 *, 0xC) | 0x8000;
        var_r1_33287 = (s8 *)0x04000068;
        var_r0_33291 = (u8) M2C_FIELD(arg0, void **, 0x68) << 6;
block_22:
        *var_r1_33287 = var_r0_33291;
        return;
    case 3:
        if (M2C_FIELD(arg0, void **, 0x68) != *(void **)0x03000070) {
            *(s8 *)0x04000070 = 0;
            CpuSet(M2C_FIELD(arg0, void **, 0x68), (s8 *)0x04000070 + 0x20, 8U);
            *(void **)0x03000070 = M2C_FIELD(arg0, void **, 0x68);
        }
        *(void *)0x04000070 = 0xC0;
        *(s16 *)0x04000074 = M2C_FIELD(arg0, s32 *, 0xC) | 0x8000;
        *(u8 *)0x04000073 = *(0x02035CC4 + temp_r5_33215);
        var_r1_33287 = (s8 *)0x04000072;
block_21:
        var_r0_33291 = 0;
        goto block_22;
    case 4:
        *(u8 *)0x04000079 = temp_r5_33215;
        if (1 & M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u8 *, 1)) {
            var_r1_33348 = sub_020272E8((u16) M2C_FIELD(arg0, s32 *, 0xC));
            var_r0_33350 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 2);
        } else {
            var_r1_33348 = sub_020272E8((u16) M2C_FIELD(arg0, s32 *, 0xC));
            var_r0_33350 = (u8) M2C_FIELD(arg0, void **, 0x68);
        }
        if (var_r0_33350 != 0) {
            var_r1_33348 |= 8;
        }
        *(u8 *)0x0400007C = var_r1_33348;
        *(s8 *)0x0400007D = 0x80;
        var_r1_33287 = (s8 *)0x04000078;
        goto block_21;
    }
}

u8 *sub_02027E74(u8 arg0, u8 arg2) {
    u8 *temp_r2_33399;
    u8 *temp_r2_33410;
    u8 *var_r4_33405;
    u8 temp_r1_33390;
    u8 temp_r5_33392;

    temp_r1_33390 = arg0;
    temp_r5_33392 = arg2;
    if (temp_r1_33390 == 0) {
        temp_r2_33399 = *(u8 **)0x030001DC;
        if (temp_r2_33399 != (u8 *)0x030001E8) {
            var_r4_33405 = temp_r2_33399;
            goto block_7;
        }
        temp_r2_33410 = M2C_FIELD((void *)0x03000070, u8 **, 0x74);
        if ((temp_r2_33410 != ((void *)0x03000070 + 0x80)) && ((M2C_FIELD(temp_r2_33410, u8 *, 1) != 1) || ((u32) temp_r5_33392 >= (u32) M2C_FIELD(temp_r2_33410, u8 *, 8)))) {
            var_r4_33405 = temp_r2_33410;
            sub_02027C78(var_r4_33405);
block_7:
            sub_020271FC(var_r4_33405);
            M2C_FIELD(var_r4_33405, s8 *, 1) = 1;
            M2C_FIELD(var_r4_33405, u8 *, 8) = temp_r5_33392;
            sub_0202720C(var_r4_33405);
            goto block_14;
        }
        goto block_10;
    }
    var_r4_33405 = (temp_r1_33390 * 0x7C) + 0x030016AC;
    if ((M2C_FIELD(var_r4_33405, u8 *, 1) == 1) && ((u32) temp_r5_33392 < (u32) M2C_FIELD(var_r4_33405, u8 *, 8))) {
block_10:
        return NULL;
    }
    if (M2C_FIELD(var_r4_33405, u8 *, 1) != 0) {
        sub_02027C78(var_r4_33405);
    }
    M2C_FIELD(var_r4_33405, u8 *, 1) = 1U;
    M2C_FIELD(var_r4_33405, u8 *, 8) = temp_r5_33392;
block_14:
    return var_r4_33405;
}

u8 sub_02027F0C(u8 *arg0, u16 arg1, u32 arg2, u8 arg3) {
    u8 *sp10;
    s32 sp14;
    s32 sp18;
    u32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 temp_r1_33543;
    s32 temp_r1_33574;
    s32 temp_r1_33596;
    s32 temp_r2_33656;
    s32 temp_r4_33481;
    s32 var_r4_33563;
    s32 var_r5_33524;
    s32 var_r8_33486;
    s32 var_r8_33616;
    s32 var_sl_33597;
    u16 temp_r1_33483;
    u32 temp_r0_33511;
    u32 var_r7_33513;
    u8 temp_r3_33480;
    void *temp_r0_33542;
    void *temp_r1_33490;

    sp10 = arg0;
    temp_r3_33480 = arg3;
    temp_r4_33481 = M2C_FIELD(arg0, s32 *, 0x64);
    temp_r1_33483 = arg1;
    var_r8_33486 = 0;
    temp_r1_33490 = M2C_FIELD(sp10, void **, 0x60);
    sp20 = temp_r1_33490 + 0x10;
    sp14 = 0x03000864;
    sp18 = 0x030009C4;
    sp1C = (u32) (((0x7F - temp_r3_33480) * temp_r1_33483) << 0x10) >> 0x17;
    temp_r0_33511 = (u32) ((temp_r3_33480 * temp_r1_33483) << 0x10) >> 0x17;
    var_r7_33513 = M2C_FIELD(temp_r1_33490, u32 *, 0xC);
    if (var_r7_33513 == 0) {
        var_r7_33513 = M2C_FIELD(temp_r1_33490, u32 *, 0);
    }
    if ((u32) ((u32) (temp_r4_33481 + (arg2 * 0xB0)) >> 8) < var_r7_33513) {
        var_r5_33524 = sp18;
    } else {
        var_r5_33524 = (((u32) ((((var_r7_33513 << 8) - temp_r4_33481) - 1) + arg2) / arg2) * 2) + sp14;
        var_r8_33486 = 1;
    }
    temp_r0_33542 = M2C_FIELD(sp10, void **, 0x60);
    temp_r1_33543 = M2C_FIELD(temp_r0_33542, s32 *, 0xC);
    if ((temp_r1_33543 == 0) || (var_r8_33486 == 0)) {
        var_r4_33563 = *(void *)0x0300059C(sp20, sp14, sp18, var_r5_33524, temp_r4_33481, arg2, sp1C, temp_r0_33511);
        if (var_r8_33486 != 0) {
            return 1U;
        }
        goto block_16;
    }
    temp_r1_33574 = (temp_r1_33543 - M2C_FIELD(temp_r0_33542, s32 *, 8)) << 8;
    sp24 = temp_r1_33574;
    var_r4_33563 = *(s32 (**)(s32, s32, s32, s32, s32, u32, u32, u32))0x0300059C(sp20, sp14, sp18, var_r5_33524, temp_r4_33481, arg2, sp1C, temp_r0_33511) - temp_r1_33574;
    temp_r1_33596 = 0xB0 - ((s32) (var_r5_33524 - sp14) >> 1);
    var_sl_33597 = temp_r1_33596;
    if (temp_r1_33596 != 0) {
        do {
            sp14 = var_r5_33524;
            sp18 = var_r5_33524 + 0x160;
            if ((u32) ((u32) (var_r4_33563 + (arg2 * var_sl_33597)) >> 8) < var_r7_33513) {
                var_r5_33524 += var_sl_33597 * 2;
                var_r8_33616 = 0;
            } else {
                var_r5_33524 += ((u32) ((((var_r7_33513 << 8) - var_r4_33563) - 1) + arg2) / arg2) * 2;
                var_r8_33616 = 1;
            }
            var_r4_33563 = *(void *)0x0300059C(sp20, sp14, sp18, var_r5_33524, var_r4_33563, arg2, sp1C, temp_r0_33511);
            if (var_r8_33616 != 0) {
                var_r4_33563 -= sp24;
            }
            temp_r2_33656 = var_sl_33597 - ((s32) (var_r5_33524 - sp14) >> 1);
            var_sl_33597 = temp_r2_33656;
        } while (temp_r2_33656 != 0);
    }
block_16:
    M2C_FIELD(sp10, s32 *, 0x64) = var_r4_33563;
    return 0U;
}

void sub_02028098(void) {
    M2C_FIELD((void *)0x03000268, s8 *, 0) = 0;
    M2C_FIELD((void *)0x03000268, s8 *, 1) = 0;
    M2C_FIELD((void *)0x03000268, s16 *, 2) = 0;
    M2C_FIELD((void *)0x03000268, s16 *, 4) = 0;
    M2C_FIELD((void *)0x03000268, s8 *, 6) = 0;
    M2C_FIELD((void *)0x03000268, s8 *, 7) = 0x30;
}

void sub_020280B4(void **arg0, u8 arg1, void **arg2) {
    s32 temp_r2_33708;
    s32 temp_r3_33712;
    u16 var_r0_33744;
    u8 temp_r1_33722;
    u8 temp_r6_33697;
    void *temp_r0_33738;
    void *temp_r0_33742;
    void *temp_r0_33780;
    void *temp_r2_33791;
    void *temp_r5_33718;
    void *var_r0_33771;

    temp_r6_33697 = arg1;
    temp_r2_33708 = M2C_FIELD(*(void **)0x03000594, s32 *, 4);
    temp_r3_33712 = temp_r2_33708 + *((*((M2C_FIELD(arg0, u16 *, 0x40) * 2) + *M2C_FIELD(arg0, s32 **, 8)) * 4) + temp_r2_33708);
    temp_r5_33718 = temp_r3_33712 + *(temp_r3_33712 + (M2C_FIELD(arg0, u16 *, 0x42) * 2));
    M2C_FIELD(arg2, s8 *, 0x11) = 0;
    M2C_FIELD(arg2, s8 *, 0x12) = 0;
    temp_r1_33722 = M2C_FIELD(temp_r5_33718, u8 *, 0);
    if (0xF0 & temp_r1_33722) {
        switch (temp_r1_33722) {                    /* irregular */
        case 16:
            M2C_FIELD(arg2, s8 *, 0x11) = 1;
            temp_r0_33738 = ((u32) ((temp_r6_33697 - M2C_FIELD(temp_r5_33718, u8 *, 4)) << 0x18) >> 0x16) + (temp_r3_33712 + M2C_FIELD(temp_r5_33718, u16 *, 2));
            M2C_FIELD(arg2, u8 *, 0x10) = (u8) M2C_FIELD(temp_r0_33738, u8 *, 2);
            temp_r0_33742 = temp_r3_33712 + M2C_FIELD(temp_r0_33738, u16 *, 0);
            M2C_FIELD(arg2, void **, 0) = temp_r0_33742;
            var_r0_33744 = M2C_FIELD(temp_r0_33742, u16 *, 4);
            goto block_11;
        case 17:
            M2C_FIELD((void *)0x03000268, u16 *, 2) = (u16) *((temp_r6_33697 * 2) + (temp_r3_33712 + M2C_FIELD(temp_r5_33718, u16 *, 2)));
            M2C_FIELD(arg2, void **, 0) = (void *)0x03000268;
            M2C_FIELD(arg2, s32 *, 4) = 0x02035CD4;
            M2C_FIELD(arg2, s8 *, 0x12) = 1;
            break;
        case 18:
            var_r0_33771 = temp_r3_33712 + M2C_FIELD(temp_r5_33718, u16 *, 2);
loop_8:
            if ((u32) temp_r6_33697 > (u32) M2C_FIELD(var_r0_33771, u8 *, 0)) {
                var_r0_33771 += 4;
                goto loop_8;
            }
            temp_r0_33780 = temp_r3_33712 + M2C_FIELD(var_r0_33771, u16 *, 2);
            M2C_FIELD(arg2, void **, 0) = temp_r0_33780;
            var_r0_33744 = M2C_FIELD(temp_r0_33780, u16 *, 4);
            goto block_11;
        }
    } else {
        M2C_FIELD(arg2, void **, 0) = temp_r5_33718;
        var_r0_33744 = (u16) M2C_FIELD(temp_r5_33718, u8 *, 4);
block_11:
        M2C_FIELD(arg2, s32 *, 4) = (s32) (temp_r3_33712 + var_r0_33744);
    }
    temp_r2_33791 = M2C_FIELD(arg2, void **, 0);
    if (M2C_FIELD(temp_r2_33791, u8 *, 0) == 3) {
        M2C_FIELD(arg2, s32 *, 0xC) = (s32) (temp_r3_33712 + M2C_FIELD(temp_r5_33718, u16 *, 2));
    }
    if (1 & M2C_FIELD(temp_r2_33791, u8 *, 1)) {
        M2C_FIELD(arg2, s32 *, 8) = (s32) (temp_r3_33712 + M2C_FIELD(temp_r2_33791, u16 *, 2));
    }
}

void sub_02028190(void) {
    s32 *var_r0_33828;
    s32 var_r1_33827;
    s32 var_r2_33815;
    void *temp_r0_33822;

    var_r2_33815 = 0;
    do {
        temp_r0_33822 = (var_r2_33815 * 0x44) + 0x03001918;
        M2C_FIELD(temp_r0_33822, s8 *, 0x41) = 0;
        var_r2_33815 += 1;
        var_r1_33827 = 9;
        var_r0_33828 = temp_r0_33822 + 0x2C;
loop_2:
        *var_r0_33828 = 0;
        var_r0_33828 -= 4;
        var_r1_33827 -= 1;
        if (var_r1_33827 >= 0) {
            goto loop_2;
        }
    } while (var_r2_33815 <= 7);
}

void sub_020281C4(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) (-2 & M2C_FIELD(arg0, u8 *, 0x3C));
    M2C_FIELD(arg0, s16 *, 0x30) = 0x96;
    M2C_FIELD(arg0, s16 *, 0x32) = 0;
    M2C_FIELD(arg0, s8 *, 0x40) = 0x80;
    M2C_FIELD(arg0, s16 *, 0x34) = 0x8000;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x3A) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x43) = 0;
}

void sub_020281FC(void) {
    s32 sp0;
    s32 *var_r4_33917;
    s32 var_r2_33914;
    s32 var_r5_33918;
    s32 var_r6_33878;
    s32 var_r7_33888;
    u16 temp_r0_33906;
    u16 temp_r2_33891;
    u8 temp_r0_33887;
    void *temp_r1_33884;

    var_r6_33878 = 0;
    do {
        temp_r1_33884 = (var_r6_33878 * 0x44) + 0x03001918;
        temp_r0_33887 = M2C_FIELD(temp_r1_33884, u8 *, 0x41);
        var_r7_33888 = var_r6_33878 + 1;
        if (temp_r0_33887 != 0) {
            temp_r2_33891 = M2C_FIELD(temp_r1_33884, u16 *, 0x3A);
            if (temp_r2_33891 == 0) {
                if (temp_r0_33887 == 2) {
                    sub_020283D4(var_r6_33878);
                } else {
                    goto block_7;
                }
            } else {
                M2C_FIELD(temp_r1_33884, u16 *, 0x34) = (u16) (M2C_FIELD(temp_r1_33884, u16 *, 0x36) + M2C_FIELD(temp_r1_33884, u16 *, 0x34));
                temp_r0_33906 = temp_r2_33891 - 1;
                M2C_FIELD(temp_r1_33884, u16 *, 0x3A) = temp_r0_33906;
                if ((temp_r0_33906 << 0x10) == 0) {
                    M2C_FIELD(temp_r1_33884, u16 *, 0x34) = (u16) M2C_FIELD(temp_r1_33884, u16 *, 0x38);
                }
block_7:
                var_r2_33914 = 0;
                var_r7_33888 = var_r6_33878 + 1;
                var_r4_33917 = temp_r1_33884 + 8;
                var_r5_33918 = 9;
                do {
                    if (*var_r4_33917 != 0) {
                        sp0 = var_r2_33914;
                        if ((sub_020285C8() << 0x18) == 0) {
                            var_r2_33914 = 1;
                        } else {
                            *var_r4_33917 = 0;
                        }
                    }
                    var_r4_33917 += 4;
                    var_r5_33918 -= 1;
                } while (var_r5_33918 >= 0);
                if (var_r2_33914 == 0) {
                    sub_020283D4(var_r6_33878);
                }
            }
        }
        var_r6_33878 = var_r7_33888;
    } while (var_r6_33878 <= 7);
}

void sub_0202828C(s32 arg0, u32 arg1) {
    s32 temp_r1_33958;
    s32 temp_r2_33962;
    s32 temp_r3_33957;
    void *temp_r4_33956;

    temp_r4_33956 = *(void **)0x03000594;
    temp_r3_33957 = M2C_FIELD(temp_r4_33956, s32 *, 8);
    temp_r1_33958 = arg1 * 4;
    temp_r2_33962 = M2C_FIELD(temp_r4_33956, s32 *, 0x14);
    sub_020282E0(arg0, temp_r3_33957 + *(temp_r1_33958 + temp_r3_33957), temp_r2_33962 + *(temp_r1_33958 + temp_r2_33962));
}

void sub_020282B4(s32 arg0, u16 arg1, u32 arg2) {
    s32 temp_r1_33981;
    s32 temp_r2_33985;
    s32 temp_r4_33980;
    void *temp_r5_33979;

    temp_r5_33979 = *(void **)0x03000594;
    temp_r4_33980 = M2C_FIELD(temp_r5_33979, s32 *, 0xC);
    temp_r1_33981 = arg1 * 4;
    temp_r2_33985 = M2C_FIELD(temp_r5_33979, s32 *, 0x18);
    sub_02028368(arg0, temp_r4_33980 + *(temp_r1_33981 + temp_r4_33980), temp_r2_33985 + *(temp_r1_33981 + temp_r2_33985), arg2);
}

void sub_020282E0(s32 arg0, s8 *arg1, s32 arg2) {
    s32 temp_r0_34007;
    s32 var_r6_34030;
    s8 *temp_r0_34026;
    s8 temp_r7_34028;
    u16 *var_r4_34034;
    void **temp_r0_34039;
    void *temp_r5_34009;

    temp_r0_34007 = arg0 * 0x44;
    temp_r5_34009 = temp_r0_34007 + 0x03001918;
    if (M2C_FIELD(temp_r5_34009, u8 *, 0x41) != 0) {
        sub_020283D4(arg0);
    }
    M2C_FIELD(temp_r5_34009, s8 **, 4) = arg1;
    *(0x03001918 + temp_r0_34007) = arg2;
    M2C_FIELD(temp_r5_34009, s8 *, 0x42) = 0;
    sub_020281C4(temp_r5_34009);
    temp_r0_34026 = M2C_FIELD(temp_r5_34009, s8 **, 4);
    temp_r7_34028 = *temp_r0_34026;
    var_r6_34030 = 0;
    if ((s32) temp_r7_34028 > 0) {
        var_r4_34034 = temp_r0_34026 + 2;
        do {
            if (*var_r4_34034 != 0) {
                temp_r0_34039 = sub_020284A0();
                *(temp_r5_34009 + 8 + (var_r6_34030 * 4)) = temp_r0_34039;
                sub_020284C4(temp_r0_34039, temp_r5_34009, M2C_FIELD(temp_r5_34009, s8 **, 4) + *var_r4_34034);
            }
            var_r4_34034 += 2;
            var_r6_34030 += 1;
        } while (var_r6_34030 < (s32) temp_r7_34028);
    }
    M2C_FIELD(temp_r5_34009, u8 *, 0x41) = 1U;
}

void sub_02028368(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 temp_r0_34079;
    s32 temp_r2_34101;
    void **temp_r0_34099;
    void *temp_r5_34081;

    temp_r0_34079 = arg0 * 0x44;
    temp_r5_34081 = temp_r0_34079 + 0x03001918;
    if (M2C_FIELD(temp_r5_34081, u8 *, 0x41) != 0) {
        sub_020283D4(arg0);
    }
    M2C_FIELD(temp_r5_34081, s32 *, 4) = arg1;
    *(0x03001918 + temp_r0_34079) = arg2;
    M2C_FIELD(temp_r5_34081, s8 *, 0x42) = 1;
    sub_020281C4(temp_r5_34081);
    temp_r0_34099 = sub_020284A0();
    M2C_FIELD(temp_r5_34081, void ***, 8) = temp_r0_34099;
    temp_r2_34101 = M2C_FIELD(temp_r5_34081, s32 *, 4);
    sub_020284C4(temp_r0_34099, temp_r5_34081, temp_r2_34101 + *((arg3 * 2) + temp_r2_34101));
    M2C_FIELD(temp_r5_34081, u8 *, 0x41) = 1U;
}

void sub_020283D4(s32 arg0) {
    s32 var_r5_34137;
    void ***var_r4_34136;
    void *temp_r1_34127;

    temp_r1_34127 = (arg0 * 0x44) + 0x03001918;
    if (M2C_FIELD(temp_r1_34127, u8 *, 0x41) != 0) {
        var_r4_34136 = temp_r1_34127 + 8;
        var_r5_34137 = 9;
        do {
            sub_020285B0(*var_r4_34136);
            *var_r4_34136 = NULL;
            var_r4_34136 += 4;
            var_r5_34137 -= 1;
        } while (var_r5_34137 >= 0);
        M2C_FIELD(temp_r1_34127, u8 *, 0x41) = 0U;
    }
}

void sub_02028410(s32 arg0, s16 arg1) {
    void *temp_r4_34162;

    temp_r4_34162 = (arg0 * 0x44) + 0x03001918;
    if (M2C_FIELD(temp_r4_34162, u8 *, 0x41) != 0) {
        M2C_FIELD(temp_r4_34162, u8 *, 0x41) = 2U;
        M2C_FIELD(temp_r4_34162, s16 *, 0x38) = 0;
        M2C_FIELD(temp_r4_34162, s16 *, 0x3A) = arg1;
        M2C_FIELD(temp_r4_34162, s16 *, 0x36) = (s16) ((s32) (0 - M2C_FIELD(temp_r4_34162, u16 *, 0x34)) / arg1);
    }
}

void sub_02028448(s32 arg0, u8 arg1) {
    void *temp_r2_34193;

    temp_r2_34193 = (arg0 * 0x44) + 0x03001918;
    M2C_FIELD(temp_r2_34193, u8 *, 0x3C) = (u8) ((-2 & M2C_FIELD(temp_r2_34193, u8 *, 0x3C)) | (arg1 & 1));
}

u8 sub_0202846C(s32 arg0) {
    return *(0x03001959 + (arg0 * 0x44));
}

void sub_02028480(void) {
    s32 var_r2_34224;
    void *var_r0_34223;

    var_r0_34223 = (void *)0x03000B2C;
    var_r2_34224 = 0xF;
    do {
        M2C_FIELD(var_r0_34223, s8 *, 0) = 0;
        M2C_FIELD(var_r0_34223, s8 *, 1) = 0;
        M2C_FIELD(var_r0_34223, s8 *, 2) = 0;
        M2C_FIELD(var_r0_34223, s8 *, 3) = 0;
        var_r0_34223 += 0x54;
        var_r2_34224 -= 1;
    } while (var_r2_34224 >= 0);
}

void **sub_020284A0(void) {
    void **var_r1_34240;

    var_r1_34240 = (void **)0x03000B24;
loop_1:
    if (M2C_FIELD(var_r1_34240, s32 *, 8) == 0) {
        return var_r1_34240;
    }
    var_r1_34240 += 0x54;
    if ((s32) var_r1_34240 > 0x03001010) {
        return NULL;
    }
    goto loop_1;
}

void sub_020284C4(void **arg0, void *arg1, void *arg2) {
    s16 *temp_r0_34351;
    u8 temp_r3_34318;
    void *temp_r1_34289;
    void *temp_r1_34302;
    void *temp_r1_34305;
    void *temp_r1_34310;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, void **, 8) != NULL) {
            sub_020285B0(arg0);
        }
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x49) = 0;
        M2C_FIELD((arg0 + 0x49), s8 *, 1) = 0;
        M2C_FIELD(arg0, void **, 0) = arg2;
        M2C_FIELD(arg0, void **, 8) = arg1;
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        sub_02028A98(arg0, 0U);
        temp_r1_34289 = arg0 + 0x4B;
        M2C_FIELD(arg0, s8 *, 0x4B) = 0x40;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = 0x22;
        M2C_FIELD(arg0, s32 *, 0x18) = 0;
        M2C_FIELD(arg0, s8 *, 0x1C) = 0;
        M2C_FIELD(arg0, s8 *, 0x1D) = 0;
        M2C_FIELD(arg0, s8 *, 0x1E) = 0;
        M2C_FIELD(arg0, s16 *, 0x20) = 0;
        M2C_FIELD(arg0, s16 *, 0x22) = 0;
        temp_r1_34302 = temp_r1_34289 + 2;
        M2C_FIELD(temp_r1_34289, s8 *, 2) = 0x80;
        temp_r1_34305 = temp_r1_34302 + 1;
        M2C_FIELD(temp_r1_34302, s8 *, 1) = 0x80;
        M2C_FIELD(arg0, s8 *, 0x4F) = 0;
        temp_r1_34310 = temp_r1_34305 + 2;
        M2C_FIELD(temp_r1_34305, s8 *, 2) = 2;
        M2C_FIELD(arg0, s8 *, 0x51) = 0;
        temp_r3_34318 = M2C_FIELD(arg1, u8 *, 0x42);
        if (temp_r3_34318 == 1) {
            M2C_FIELD(temp_r1_34310, s8 *, 2) = 0xC;
            *((temp_r1_34310 + 2) - 6) = 0x7F;
            M2C_FIELD(arg0, u8 *, 0x53) = temp_r3_34318;
        } else {
            M2C_FIELD(arg0, s8 *, 0x52) = 3;
            M2C_FIELD(arg0, s8 *, 0x4C) = 0;
            M2C_FIELD((arg0 + 0x4C), s8 *, 7) = 0;
        }
        M2C_FIELD(arg0, s16 *, 0x44) = 0x7F;
        M2C_FIELD(arg0, s8 *, 0x48) = 0x7F;
        temp_r0_34351 = (arg0 + 0x48) - 2;
        *temp_r0_34351 = 0;
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) (temp_r0_34351 - 0x22);
    }
}

void sub_02028580(void **arg0) {
    u8 temp_r6_34368;
    void *temp_r4_34376;
    void *var_r0_34371;

    if (arg0 != NULL) {
        temp_r6_34368 = M2C_FIELD(arg0, u8 *, 0x49);
        M2C_FIELD(arg0, u8 *, 0x49) = 0U;
        var_r0_34371 = M2C_FIELD(arg0, void **, 0xC);
        if (var_r0_34371 != NULL) {
            do {
                temp_r4_34376 = M2C_FIELD(var_r0_34371, void **, 0x78);
                sub_02027B94();
                var_r0_34371 = temp_r4_34376;
            } while (var_r0_34371 != NULL);
        }
        M2C_FIELD(arg0, u8 *, 0x49) = temp_r6_34368;
    }
}

void sub_020285B0(void **arg0) {
    if (arg0 != NULL) {
        sub_02028580();
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 sub_020285C8(void **arg0, M2C_UNK arg3) {
    M2C_UNK sp0;
    M2C_UNK (*temp_r2_34788)(void **, u8);
    M2C_UNK (*temp_r7_34476)(void **, u8, u8, u16);
    s16 temp_r1_34555;
    s32 temp_r0_34934;
    s32 temp_r1_34927;
    s32 var_r1_34675;
    s8 temp_r0_34540;
    u16 var_r4_34449;
    u16 var_r4_34474;
    u16 var_r4_34514;
    u32 temp_r0_34571;
    u8 *var_r0_34772;
    u8 var_r1_34766;
    u8 var_r2_34451;
    u8 var_r6_34440;
    void ***temp_r6_34848;
    void **temp_r0_34654;
    void **temp_r0_34688;
    void **temp_r0_34849;
    void **temp_r1_34649;
    void **var_r4_34853;
    void *temp_r0_34461;
    void *temp_r0_34665;
    void *temp_r0_34668;
    void *temp_r0_34707;
    void *temp_r0_34791;
    void *temp_r1_34413;
    void *temp_r1_34679;
    void *temp_r1_34682;
    void *temp_r1_34686;
    void *temp_r1_34831;
    void *temp_r1_34833;
    void *temp_r1_34896;
    void *temp_r1_34901;
    void *temp_r2_34439;
    void *temp_r2_34441;
    void *temp_r2_34552;
    void *temp_r2_34838;
    void *temp_r3_34548;

    if ((arg0 == NULL) || (temp_r1_34413 = M2C_FIELD(arg0, void **, 8), (temp_r1_34413 == NULL))) {
        return 1;
    }
    if (!(1 & M2C_FIELD(temp_r1_34413, u8 *, 0x3C))) {
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3B:
    case 0x3C:
loop_67:
        temp_r1_34927 = M2C_FIELD(arg0, s32 *, 0x34);
        if (temp_r1_34927 <= 0) {
            temp_r2_34439 = M2C_FIELD(arg0, void **, 0);
            var_r6_34440 = M2C_FIELD(temp_r2_34439, u8 *, 0);
            temp_r2_34441 = temp_r2_34439 + 1;
            M2C_FIELD(arg0, void **, 0) = temp_r2_34441;
            if ((u32) var_r6_34440 <= 0xBFU) {
                if ((u32) var_r6_34440 <= 0x5FU) {
                    var_r4_34449 = M2C_FIELD(arg0, u16 *, 0x44);
                    var_r2_34451 = M2C_FIELD((arg0 + 0x44), u8 *, 4);
                } else {
                    var_r4_34449 = sub_02028A74(arg0);
                    M2C_FIELD(arg0, u16 *, 0x44) = var_r4_34449;
                    temp_r0_34461 = M2C_FIELD(arg0, void **, 0);
                    var_r2_34451 = M2C_FIELD(temp_r0_34461, u8 *, 0);
                    M2C_FIELD(arg0, void **, 0) = temp_r0_34461 + 1;
                    M2C_FIELD(arg0, u8 *, 0x48) = var_r2_34451;
                    var_r6_34440 -= 0x60;
                }
                var_r4_34474 = 0x96 * var_r4_34449;
                temp_r7_34476 = *(M2C_UNK (**)(void **, u8, u8, u16))0x03000270;
                if ((temp_r7_34476 != NULL) && (1 & M2C_FIELD(temp_r1_34413, u8 *, 0x43))) {
                    temp_r7_34476(arg0, var_r6_34440, var_r2_34451, var_r4_34474);
                } else {
                    sub_020279BC(arg0, var_r6_34440, var_r2_34451, var_r4_34474);
                }
                if (M2C_FIELD(arg0, u8 *, 0x53) != 1) {

                } else {
                    goto block_23;
                }
                goto loop_67;
            }
            if (var_r6_34440 == 0xC0) {
                var_r4_34514 = M2C_FIELD(arg0, u16 *, 0x46);
                goto block_22;
            }
            if (var_r6_34440 == 0xC1) {
                var_r4_34514 = sub_02028A74(arg0);
                M2C_FIELD(arg0, u16 *, 0x46) = var_r4_34514;
block_22:
                var_r4_34474 = 0x96 * var_r4_34514;
block_23:
                M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + var_r4_34474);
                goto loop_67;
            }
            if ((0xF0 & var_r6_34440) == 0xD0) {
                temp_r0_34540 = 0xF & var_r6_34440;
                M2C_FIELD(arg0, s8 *, 0x1D) = temp_r0_34540;
                M2C_FIELD(arg0, s8 *, 0x1E) = (s8) (M2C_FIELD(arg0, u8 *, 0x51) + M2C_FIELD(temp_r2_34439, u8 *, 1));
                temp_r3_34548 = temp_r2_34441 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r3_34548;
                M2C_FIELD(arg0, s16 *, 0x22) = (s16) M2C_FIELD(temp_r2_34441, u8 *, 1);
                temp_r2_34552 = temp_r3_34548 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r2_34552;
                temp_r1_34555 = 1 & temp_r0_34540;
                if (temp_r1_34555 != 0) {
                    M2C_FIELD(arg0, s16 *, 0x20) = (s16) M2C_FIELD(temp_r3_34548, u8 *, 1);
                    M2C_FIELD(arg0, void **, 0) = temp_r2_34552 + 1;
                } else {
                    M2C_FIELD(arg0, s16 *, 0x20) = temp_r1_34555;
                }
                M2C_FIELD(arg0, s8 *, 0x1C) = 1;
                goto loop_67;
            }
            temp_r0_34571 = var_r6_34440 - 0xC2;
            switch (temp_r0_34571) {                /* irregular */
            case 0x3D:
                temp_r1_34649 = M2C_FIELD(arg0, void ***, 0x30);
                if (temp_r1_34649 == (arg0 + 0x24)) {
                    sub_020285B0(arg0);
                    return 2;
                }
                temp_r0_34654 = temp_r1_34649 - 4;
                M2C_FIELD(arg0, void ***, 0x30) = temp_r0_34654;
                M2C_FIELD(arg0, void **, 0) = *temp_r0_34654;
                goto loop_67;
            case 0x26:
                M2C_FIELD(arg0, s8 *, 0x1C) = 0;
                goto loop_67;
            case 0x2E:
                temp_r0_34665 = M2C_FIELD(arg0, void **, 0);
                M2C_FIELD(&sp0, u8 *, 0) = (u8) M2C_FIELD(temp_r0_34665, u8 *, 0);
                temp_r0_34668 = temp_r0_34665 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r0_34668;
                M2C_FIELD(&sp0, u8 *, 1) = (u8) M2C_FIELD(temp_r0_34665, u8 *, 1);
                M2C_FIELD(arg0, void **, 0) = temp_r0_34668 + 1;
                var_r1_34675 = M2C_FIELD(temp_r1_34413, s32 *, 4);
block_38:
                M2C_FIELD(arg0, void **, 0) = var_r1_34675 + (u16) M2C_FIELD(&sp0, u8 *, 0);
                goto loop_67;
            case 0x32:
                temp_r1_34679 = M2C_FIELD(arg0, void **, 0);
                M2C_FIELD(&sp0, u8 *, 0) = (u8) M2C_FIELD(temp_r1_34679, u8 *, 0);
                temp_r1_34682 = temp_r1_34679 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r1_34682;
                M2C_FIELD(&sp0, u8 *, 1) = (u8) M2C_FIELD(temp_r1_34679, u8 *, 1);
                temp_r1_34686 = temp_r1_34682 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r1_34686;
                temp_r0_34688 = M2C_FIELD(arg0, void ***, 0x30);
                *temp_r0_34688 = temp_r1_34686;
                M2C_FIELD(arg0, void ***, 0x30) = (void **) (temp_r0_34688 + 4);
                var_r1_34675 = M2C_FIELD(temp_r1_34413, s32 *, 4);
                goto block_38;
            case 0x0:
                M2C_FIELD(arg0, u16 *, 0x42) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
block_56:
                M2C_FIELD(arg0, void **, 0) += 1;
                goto loop_67;
            case 0x5:
                temp_r0_34707 = M2C_FIELD(arg0, void **, 0);
                M2C_FIELD(arg0, void **, 0) = temp_r0_34707 + 1;
                sub_02028A98(arg0, M2C_FIELD(temp_r0_34707, u8 *, 0));
                goto loop_67;
            case 0x1:
                M2C_FIELD(arg0, u8 *, 0x4B) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x2:
                M2C_FIELD(arg0, u8 *, 0x52) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x1E:
                M2C_FIELD(arg0, u8 *, 0x4D) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x1F:
                M2C_FIELD(arg0, u8 *, 0x4F) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x20:
                M2C_FIELD(arg0, u8 *, 0x50) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x27:
                M2C_FIELD(arg0, u8 *, 0x51) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x21:
                M2C_FIELD(arg0, u8 *, 0x4C) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_56;
            case 0x3:
            case 0x4:
                sub_02028580(arg0);
                var_r1_34766 = 0;
                if (var_r6_34440 == 0xC5) {
                    var_r1_34766 = 1;
                }
                var_r0_34772 = arg0 + 0x49;
block_66:
                *var_r0_34772 = var_r1_34766;
                goto loop_67;
            case 0x6:
                M2C_FIELD(arg0, u8 *, 0x53) = 1U;
                goto loop_67;
            case 0x7:
                M2C_FIELD(arg0, u8 *, 0x53) = 0U;
                goto loop_67;
            case 0x8:
                temp_r2_34788 = *(M2C_UNK (**)(void **, u8))0x03000274;
                if (temp_r2_34788 != NULL) {
                    temp_r0_34791 = M2C_FIELD(arg0, void **, 0);
                    M2C_FIELD(arg0, void **, 0) = temp_r0_34791 + 1;
                    temp_r2_34788(arg0, M2C_FIELD(temp_r0_34791, u8 *, 0));
                } else {
                    goto block_56;
                }
                goto loop_67;
            case 0x22:
                M2C_FIELD(temp_r1_34413, u16 *, 0x30) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
block_61:
                M2C_FIELD(arg0, void **, 0) += 1;
                goto loop_67;
            case 0x23:
                M2C_FIELD(arg0, s16 *, 0x10) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_61;
            case 0x25:
                M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_61;
            case 0x24:
                M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0);
                goto block_61;
            case 0x36:
                temp_r1_34831 = M2C_FIELD(arg0, void **, 0);
                temp_r1_34833 = temp_r1_34831 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r1_34833;
                M2C_FIELD(&sp0, u8 *, 0) = (u8) M2C_FIELD(temp_r1_34831, u8 *, 1);
                temp_r2_34838 = temp_r1_34833 + 1;
                M2C_FIELD(arg0, void **, 0) = temp_r2_34838;
                M2C_FIELD(&sp0, u8 *, 1) = (u8) M2C_FIELD(temp_r1_34833, u8 *, 1);
                M2C_FIELD(arg0, void **, 0) = temp_r2_34838 + 1;
                temp_r6_34848 = temp_r1_34413 + 8 + (M2C_FIELD(temp_r1_34831, u8 *, 0) * 4);
                temp_r0_34849 = *temp_r6_34848;
                if (temp_r0_34849 == NULL) {
                    var_r4_34853 = sub_020284A0();
                    *temp_r6_34848 = var_r4_34853;
                } else {
                    var_r4_34853 = temp_r0_34849;
                    sub_020285B0();
                }
                sub_020284C4(var_r4_34853, temp_r1_34413, M2C_FIELD(temp_r1_34413, s32 *, 4) + (u16) M2C_FIELD(&sp0, u8 *, 0));
                M2C_FIELD(var_r4_34853, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
                M2C_FIELD(var_r4_34853, u16 *, 0x40) = (u16) M2C_FIELD(arg0, u16 *, 0x40);
                M2C_FIELD(var_r4_34853, u16 *, 0x42) = (u16) M2C_FIELD(arg0, u16 *, 0x42);
                M2C_FIELD((var_r4_34853 + 0x42), u8 *, 9) = (u8) M2C_FIELD(arg0, u8 *, 0x4B);
                M2C_FIELD(var_r4_34853, u8 *, 0x4C) = (u8) M2C_FIELD(arg0, u8 *, 0x4C);
                temp_r1_34896 = var_r4_34853 + 0x4D;
                M2C_FIELD(var_r4_34853, u8 *, 0x4D) = (u8) M2C_FIELD(arg0, u8 *, 0x4D);
                temp_r1_34901 = temp_r1_34896 + 1;
                M2C_FIELD(temp_r1_34896, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 0x4E);
                M2C_FIELD(temp_r1_34901, u8 *, 4) = (u8) M2C_FIELD(arg0, u8 *, 0x52);
                *((temp_r1_34901 + 4) - 3) = M2C_FIELD(arg0, u8 *, 0x4F);
                M2C_FIELD(var_r4_34853, u8 *, 0x50) = (u8) M2C_FIELD(arg0, u8 *, 0x50);
                var_r1_34766 = M2C_FIELD(arg0, u8 *, 0x51);
                var_r0_34772 = var_r4_34853 + 0x51;
                goto block_66;
            }
        } else {
            temp_r0_34934 = temp_r1_34927 - M2C_FIELD(temp_r1_34413, u16 *, 0x30);
            M2C_FIELD(arg0, s32 *, 0x34) = temp_r0_34934;
            M2C_FIELD(arg0, s32 *, 0x34) = (s32) (temp_r0_34934 - M2C_FIELD(temp_r1_34413, s16 *, 0x32));
            goto block_70;
        }
    } else {
        sub_02028580(arg0);
block_70:
        return 0;
    }
}

void sub_02028A34(void **arg0, u8 *arg1) {
    u8 *temp_r2_34958;
    void **temp_r2_34953;

    temp_r2_34953 = M2C_FIELD(arg1, void ***, 4);
    if (temp_r2_34953 == NULL) {
        M2C_FIELD(arg1, void ***, 4) = arg0;
        M2C_FIELD(arg1, void ***, 0x74) = temp_r2_34953;
        temp_r2_34958 = M2C_FIELD(arg0, u8 **, 0xC);
        M2C_FIELD(arg1, u8 **, 0x78) = temp_r2_34958;
        M2C_FIELD(arg0, u8 **, 0xC) = arg1;
        if (temp_r2_34958 != NULL) {
            M2C_FIELD(temp_r2_34958, u8 **, 0x74) = arg1;
        }
    }
}

void sub_02028A4C(void *arg0, u8 *arg1) {
    void *temp_r2_34975;
    void *temp_r2_34981;

    if (M2C_FIELD(arg1, s32 *, 4) != 0) {
        M2C_FIELD(arg1, s32 *, 4) = 0;
        temp_r2_34975 = M2C_FIELD(arg1, void **, 0x78);
        if (temp_r2_34975 != NULL) {
            M2C_FIELD(temp_r2_34975, void **, 0x74) = (void *) M2C_FIELD(arg1, void **, 0x74);
        }
        temp_r2_34981 = M2C_FIELD(arg1, void **, 0x74);
        if (temp_r2_34981 != NULL) {
            M2C_FIELD(temp_r2_34981, void **, 0x78) = (void *) M2C_FIELD(arg1, void **, 0x78);
            return;
        }
        M2C_FIELD(arg0, void **, 0xC) = (void *) M2C_FIELD(arg1, void **, 0x78);
    }
}

u16 sub_02028A74(void **arg0) {
    u8 var_r1_34997;
    void *temp_r2_34996;
    void *temp_r2_34998;

    temp_r2_34996 = *arg0;
    var_r1_34997 = M2C_FIELD(temp_r2_34996, u8 *, 0);
    temp_r2_34998 = temp_r2_34996 + 1;
    *arg0 = temp_r2_34998;
    if (0x80 & var_r1_34997) {
        var_r1_34997 = ((var_r1_34997 & 0x7F) << 8) | M2C_FIELD(temp_r2_34996, u8 *, 1);
        *arg0 = temp_r2_34998 + 1;
    }
    return (u16) var_r1_34997;
}

void sub_02028A98(void **arg0, s16 arg1) {
    s32 temp_r1_35034;
    void *temp_r2_35024;

    M2C_FIELD(arg0, s16 *, 0x40) = arg1;
    M2C_FIELD((arg0 + 0x40), s16 *, 2) = 0;
    temp_r2_35024 = *(void **)0x03000594;
    temp_r1_35034 = M2C_FIELD(temp_r2_35024, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_r1_35034 + *((*((*((arg1 * 2) + *M2C_FIELD(arg0, s32 **, 8)) * 2) + M2C_FIELD(temp_r2_35024, s32 *, 0x10)) * 4) + temp_r1_35034));
}

void sub_02028ACC(void) {
    *(s32 *)0x03000584 = 0x03000278;
    *(s32 *)0x03000588 = 0x03000278;
    *(s32 *)0x0300058C = 0x03000278;
    *(s32 *)0x03000590 = 0x03000578;
    *(s32 *)0x03000270 = 0;
    *(s32 *)0x03000274 = 0;
}

void *sub_02028B0C(void) {
    void *temp_r0_35088;
    void *temp_r2_35076;

    temp_r2_35076 = *(void **)0x03000584;
    if (temp_r2_35076 == *(s32 *)0x0300058C) {
        return NULL;
    }
    temp_r0_35088 = temp_r2_35076 + 0xC;
    *(void **)0x03000584 = temp_r0_35088;
    if (temp_r0_35088 == *(s32 *)0x03000590) {
        *(void **)0x03000584 = (void *)0x03000278;
    }
    return temp_r2_35076;
}

void sub_02028B44(void) {
    *(s32 *)0x0300058C = *(s32 *)0x03000588;
}

void sub_02028B58(u16 arg0, u16 arg1) {
    void *temp_r2_35123;
    void *temp_r2_35128;

    temp_r2_35123 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35123, s16 *, 0) = 0;
    M2C_FIELD(temp_r2_35123, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35123, s32 *, 8) = (s32) arg1;
    temp_r2_35128 = temp_r2_35123 + 0xC;
    *(void **)0x03000588 = temp_r2_35128;
    if (temp_r2_35128 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028B90(s32 arg0, u16 arg1, u16 arg2) {
    void *temp_r3_35153;
    void *temp_r3_35160;

    temp_r3_35153 = *(void **)0x03000588;
    M2C_FIELD(temp_r3_35153, s16 *, 0) = 1;
    M2C_FIELD(temp_r3_35153, s32 *, 4) = (s32) ((arg0 << 0x10) | arg1);
    M2C_FIELD(temp_r3_35153, s32 *, 8) = (s32) arg2;
    temp_r3_35160 = temp_r3_35153 + 0xC;
    *(void **)0x03000588 = temp_r3_35160;
    if (temp_r3_35160 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028BCC(u16 arg0, u16 arg1) {
    void *temp_r2_35185;
    void *temp_r2_35190;

    temp_r2_35185 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35185, s16 *, 0) = 2;
    M2C_FIELD(temp_r2_35185, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35185, s32 *, 8) = (s32) arg1;
    temp_r2_35190 = temp_r2_35185 + 0xC;
    *(void **)0x03000588 = temp_r2_35190;
    if (temp_r2_35190 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028C04(u16 arg0, u8 arg1) {
    void *temp_r2_35215;
    void *temp_r2_35220;

    temp_r2_35215 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35215, s16 *, 0) = 3;
    M2C_FIELD(temp_r2_35215, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35215, s32 *, 8) = (s32) arg1;
    temp_r2_35220 = temp_r2_35215 + 0xC;
    *(void **)0x03000588 = temp_r2_35220;
    if (temp_r2_35220 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028C3C(u16 arg0, s16 arg1) {
    void *temp_r2_35243;
    void *temp_r2_35250;

    temp_r2_35243 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35243, s16 *, 0) = 4;
    M2C_FIELD(temp_r2_35243, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35243, s32 *, 8) = (s32) arg1;
    temp_r2_35250 = temp_r2_35243 + 0xC;
    *(void **)0x03000588 = temp_r2_35250;
    if (temp_r2_35250 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028C74(u16 arg0, u8 arg1) {
    void *temp_r2_35275;
    void *temp_r2_35280;

    temp_r2_35275 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35275, s16 *, 0) = 5;
    M2C_FIELD(temp_r2_35275, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35275, s32 *, 8) = (s32) arg1;
    temp_r2_35280 = temp_r2_35275 + 0xC;
    *(void **)0x03000588 = temp_r2_35280;
    if (temp_r2_35280 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028CAC(u16 arg0, u8 arg1) {
    void *temp_r2_35305;
    void *temp_r2_35310;

    temp_r2_35305 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35305, s16 *, 0) = 6;
    M2C_FIELD(temp_r2_35305, s32 *, 4) = (s32) arg0;
    M2C_FIELD(temp_r2_35305, s32 *, 8) = (s32) arg1;
    temp_r2_35310 = temp_r2_35305 + 0xC;
    *(void **)0x03000588 = temp_r2_35310;
    if (temp_r2_35310 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028CE4(s32 arg0, s32 arg1, u8 arg2) {
    void *temp_r3_35333;
    void *temp_r3_35340;

    temp_r3_35333 = *(void **)0x03000588;
    M2C_FIELD(temp_r3_35333, s16 *, 0) = 7;
    M2C_FIELD(temp_r3_35333, s32 *, 4) = (s32) ((arg0 << 0x10) | arg2);
    M2C_FIELD(temp_r3_35333, s32 *, 8) = arg1;
    temp_r3_35340 = temp_r3_35333 + 0xC;
    *(void **)0x03000588 = temp_r3_35340;
    if (temp_r3_35340 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028D1C(s32 arg0, s32 arg1, u8 arg2) {
    void *temp_r3_35363;
    void *temp_r3_35370;

    temp_r3_35363 = *(void **)0x03000588;
    M2C_FIELD(temp_r3_35363, s16 *, 0) = 9;
    M2C_FIELD(temp_r3_35363, s32 *, 4) = (s32) ((arg0 << 0x10) | arg2);
    M2C_FIELD(temp_r3_35363, s32 *, 8) = arg1;
    temp_r3_35370 = temp_r3_35363 + 0xC;
    *(void **)0x03000588 = temp_r3_35370;
    if (temp_r3_35370 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028D54(s32 arg0, s32 arg1, u8 arg2) {
    void *temp_r3_35393;
    void *temp_r3_35400;

    temp_r3_35393 = *(void **)0x03000588;
    M2C_FIELD(temp_r3_35393, s16 *, 0) = 8;
    M2C_FIELD(temp_r3_35393, s32 *, 4) = (s32) ((arg0 << 0x10) | arg2);
    M2C_FIELD(temp_r3_35393, s32 *, 8) = arg1;
    temp_r3_35400 = temp_r3_35393 + 0xC;
    *(void **)0x03000588 = temp_r3_35400;
    if (temp_r3_35400 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028D8C(u8 arg0) {
    void *temp_r2_35422;
    void *temp_r2_35426;

    temp_r2_35422 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35422, s16 *, 0) = 0xA;
    M2C_FIELD(temp_r2_35422, s32 *, 4) = (s32) arg0;
    temp_r2_35426 = temp_r2_35422 + 0xC;
    *(void **)0x03000588 = temp_r2_35426;
    if (temp_r2_35426 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028DB8(s32 arg0, s32 arg1) {
    void *temp_r2_35445;
    void *temp_r2_35450;

    temp_r2_35445 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35445, s16 *, 0) = 0xB;
    M2C_FIELD(temp_r2_35445, s32 *, 4) = arg0;
    M2C_FIELD(temp_r2_35445, s32 *, 8) = arg1;
    temp_r2_35450 = temp_r2_35445 + 0xC;
    *(void **)0x03000588 = temp_r2_35450;
    if (temp_r2_35450 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028DE8(void (*arg0)(void *, u8)) {
    void *temp_r2_35470;
    void *temp_r2_35474;

    temp_r2_35470 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35470, s16 *, 0) = 0xC;
    M2C_FIELD(temp_r2_35470, void (**)(void *, u8), 4) = arg0;
    temp_r2_35474 = temp_r2_35470 + 0xC;
    *(void **)0x03000588 = temp_r2_35474;
    if (temp_r2_35474 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028E10(void (*arg0)(void **, u8, u8, u16)) {
    void *temp_r2_35492;
    void *temp_r2_35496;

    temp_r2_35492 = *(void **)0x03000588;
    M2C_FIELD(temp_r2_35492, s16 *, 0) = 0xD;
    M2C_FIELD(temp_r2_35492, void (**)(void **, u8, u8, u16), 4) = arg0;
    temp_r2_35496 = temp_r2_35492 + 0xC;
    *(void **)0x03000588 = temp_r2_35496;
    if (temp_r2_35496 == *(s32 *)0x03000590) {
        *(void **)0x03000588 = (void *)0x03000278;
    }
}

void sub_02028E38(void) {
    s32 *var_r1_35717;
    s32 temp_r1_35549;
    s32 var_r0_35573;
    s32 var_r2_35574;
    u16 temp_r0_35516;
    u32 temp_r0_35636;
    u32 temp_r0_35670;
    u32 temp_r0_35704;
    u32 temp_r1_35585;
    void **var_r2_35621;
    void **var_r2_35655;
    void **var_r2_35689;
    void *temp_r0_35584;
    void *temp_r0_35627;
    void *temp_r0_35661;
    void *temp_r0_35695;
    void *temp_r0_35733;

loop_38:
    temp_r0_35733 = sub_02028B0C();
    if (temp_r0_35733 != NULL) {
        temp_r0_35516 = M2C_FIELD(temp_r0_35733, u16 *, 0);
        switch ((u32) temp_r0_35516) {              /* irregular */
        case 0:
            sub_0202828C(M2C_FIELD(temp_r0_35733, s32 *, 4), M2C_FIELD(temp_r0_35733, u32 *, 8));
            break;
        case 1:
            temp_r1_35549 = M2C_FIELD(temp_r0_35733, s32 *, 4);
            sub_020282B4((s32) ((u32) temp_r1_35549 >> 0x10), (u16) temp_r1_35549, M2C_FIELD(temp_r0_35733, u32 *, 8));
            break;
        case 2:
            sub_02028410(M2C_FIELD(temp_r0_35733, s32 *, 4), (s16) M2C_FIELD(temp_r0_35733, u32 *, 8));
            break;
        case 3:
            sub_02028448(M2C_FIELD(temp_r0_35733, s32 *, 4), (u8) M2C_FIELD(temp_r0_35733, u32 *, 8));
            break;
        case 6:
            var_r0_35573 = M2C_FIELD(temp_r0_35733, s32 *, 4) * 0x44;
            var_r2_35574 = 0x0300195B;
block_11:
            *(var_r0_35573 + var_r2_35574) = (s8) M2C_FIELD(temp_r0_35733, u32 *, 8);
            break;
        case 4:
            temp_r0_35584 = (M2C_FIELD(temp_r0_35733, s32 *, 4) * 0x44) + 0x03001918;
            temp_r1_35585 = M2C_FIELD(temp_r0_35733, u32 *, 8);
            M2C_FIELD(temp_r0_35584, s8 *, 0x32) = (s8) temp_r1_35585;
            M2C_FIELD(temp_r0_35584, s8 *, 0x33) = (s8) (temp_r1_35585 >> 8);
            break;
        case 5:
            var_r0_35573 = M2C_FIELD(temp_r0_35733, s32 *, 4) * 0x44;
            var_r2_35574 = 0x03001958;
            goto block_11;
        case 7:
            if (M2C_FIELD(temp_r0_35733, u32 *, 8) != 0) {
                var_r2_35621 = (M2C_FIELD(temp_r0_35733, u16 *, 6) * 0x44) + 0x03001918 + 8;
                do {
                    if (M2C_FIELD(temp_r0_35733, u32 *, 8) & 1) {
                        temp_r0_35627 = *var_r2_35621;
                        if (temp_r0_35627 != NULL) {
                            M2C_FIELD(temp_r0_35627, s8 *, 0x4A) = (s8) M2C_FIELD(temp_r0_35733, s32 *, 4);
                        }
                    }
                    var_r2_35621 += 4;
                    temp_r0_35636 = (u32) M2C_FIELD(temp_r0_35733, u32 *, 8) >> 1;
                    M2C_FIELD(temp_r0_35733, u32 *, 8) = temp_r0_35636;
                } while (temp_r0_35636 != 0);
            }
            break;
        case 9:
            if (M2C_FIELD(temp_r0_35733, u32 *, 8) != 0) {
                var_r2_35655 = (M2C_FIELD(temp_r0_35733, u16 *, 6) * 0x44) + 0x03001918 + 8;
                do {
                    if (M2C_FIELD(temp_r0_35733, u32 *, 8) & 1) {
                        temp_r0_35661 = *var_r2_35655;
                        if (temp_r0_35661 != NULL) {
                            M2C_FIELD(temp_r0_35661, s8 *, 0x4E) = (s8) M2C_FIELD(temp_r0_35733, s32 *, 4);
                        }
                    }
                    var_r2_35655 += 4;
                    temp_r0_35670 = (u32) M2C_FIELD(temp_r0_35733, u32 *, 8) >> 1;
                    M2C_FIELD(temp_r0_35733, u32 *, 8) = temp_r0_35670;
                } while (temp_r0_35670 != 0);
            }
            break;
        case 8:
            if (M2C_FIELD(temp_r0_35733, u32 *, 8) != 0) {
                var_r2_35689 = (M2C_FIELD(temp_r0_35733, u16 *, 6) * 0x44) + 0x03001918 + 8;
                do {
                    if (M2C_FIELD(temp_r0_35733, u32 *, 8) & 1) {
                        temp_r0_35695 = *var_r2_35689;
                        if (temp_r0_35695 != NULL) {
                            M2C_FIELD(temp_r0_35695, s8 *, 0x4B) = (s8) M2C_FIELD(temp_r0_35733, s32 *, 4);
                        }
                    }
                    var_r2_35689 += 4;
                    temp_r0_35704 = (u32) M2C_FIELD(temp_r0_35733, u32 *, 8) >> 1;
                    M2C_FIELD(temp_r0_35733, u32 *, 8) = temp_r0_35704;
                } while (temp_r0_35704 != 0);
            }
            break;
        case 11:
            ((M2C_UNK (*)(u32)) M2C_FIELD(temp_r0_35733, s32 *, 4))(M2C_FIELD(temp_r0_35733, u32 *, 8));
            break;
        case 12:
            var_r1_35717 = (s32 *)0x03000274;
block_36:
            *var_r1_35717 = M2C_FIELD(temp_r0_35733, s32 *, 4);
            break;
        case 13:
            var_r1_35717 = (s32 *)0x03000270;
            goto block_36;
        case 10:
            sub_02027370((u8) M2C_FIELD(temp_r0_35733, s32 *, 4));
            break;
        }
        goto loop_38;
    }
}
#endif
