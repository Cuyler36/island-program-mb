#include "global.h"
#include "m_name_table.h"
#include <string.h>

void sub_0201A0D4();                                   /* extern */
void sub_02027040();                                   /* extern */
extern u8 sub_02029004[];
extern u8 sub_020290C4[];
extern u8 sub_020291E4[];

static int transfer_size;
static int sMsgDirtyTileOffset;
static int sMsgDirtyTileCount;
static int _03000018; // ??
static u8 sMsgPreviousTextRow;
static u8 sMsgPreviousTextX;

GameState gGameState;
IslandFieldWork gIslandFieldWork; // @0x03003710
IslandBuilding gIslandBuildings[ISLAND_BUILDING_COUNT]; // @0x03003BB0
FieldObject gFieldObjects[FIELD_OBJECT_COUNT]; // @0x03003C00
Islander_AGB gIslander; // @0x030041A0
Entity g_EntityTable[12]; // @0x03004790
Player gPlayer; // @0x03004B80
Island_agb_c* gIslandData;

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
/* Ghidra name: Msg_ProcessControlCode (differs from the existing contextual name). */
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
#define gMsgVram ((u8 *)(BG_VRAM + TILE_OFFSET_4BPP(0x100)))
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
        CpuFastSet(tile_data + (tile * 32), gMsgVram + (tile * 16) + (tile * 16), (count * 8) & 0x1FFFFF);
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

/* Ghidra name: mMsg_GetStrLenWithEndContCodes (differs from the existing contextual name). */
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

/* Ghidra name: ControlCode_GetSize (differs from the existing contextual name). */
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

/* Ghidra name: Msg_DecrementCodeSize (differs; this decrements the text-delay timer). */
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

/* Ghidra name: Msg_ProcessLines (differs from the existing contextual name). */
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

s32 rand_u16(GameState *state) {
    u32 temp_r0_3407;

    temp_r0_3407 = (state->rngValue * 0x41C64E6D) + (state->unk_85B + 0x3039);
    state->rngValue = temp_r0_3407;
    return (s32)((u32)(temp_r0_3407 * 2) >> 0x11);
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

/* Ghidra name: mMsg_memcpy (differs from the existing contextual name). */
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

/* Initial reconstructions; progressively replace raw field accesses with recovered types. */

/* Forward declarations retain m2c's current inferred signatures. */
void sub_02019F08(void);
void sub_02019F0C(void);
void sub_0201A0C8(void);
void sub_0201A0D4(void);
s32 Swap32(u32 *arg0);
void sub_0201A218(void);
void JoybootHandler(void);
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
s32 sub_0201BB4C(void *arg0);
s32 sub_0201BB58(void *arg0);
s32 sub_0201BB64(void *arg0);
s32 sub_0201BB70(void *arg0);
s32 sub_0201BB7C(void *arg0);
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
s32 sub_0201C1B8(void);
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
void sub_0201C5F8(void *arg0);
void sub_0201C5FC(s32 arg0);
void sub_0201C668(void *arg0);
void sub_0201C69C(void *arg0);
void sub_0201C6C8(void);
void sub_0201C6CC(void *arg0);
void sub_0201C6EC(void *arg0);
void sub_0201C740(void *arg0);
void sub_0201C744(void *arg0);
void sub_0201C768(void);
void sub_0201C76C(void *arg0);
void sub_0201C78C(void *arg0);
void sub_0201C7E0(s32 arg0);
void sub_0201C870(void);
s32 sub_0201C8C0(void);
void sub_0201CB50(void);
s32 sub_0201CDA0(u16 arg0, s32 arg1, u8 arg2);
void sub_0201CF3C(u16 arg0, s32 arg1, u8 arg2);
void sub_0201D19C(void);
void UpdateHourlyPalette(void);
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
void sub_0201E038(u8 arg0, u8 arg1);
void sub_0201E060(void *arg0, s32 arg1, u8 arg2);
void sub_0201E178(s32 arg0, u8 arg1);
void sub_0201E1E0(s32 arg0, s32 arg1, u8 arg2);
void sub_0201E230(s32 arg0);
void sub_0201E27C(s32 arg0);
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
s32 Islander_StoreItem(u16 arg0, u16 arg1);
s16 Islander_GetFishingItem(void);
s32 sub_0201F0FC(u8 arg0);
s32 sub_0201F368(void);
s32 Islander_ChangeMoveDir(s32 arg0, s32 arg1, u8 arg2);
void sub_0201F538(u8 arg0);
void WriteItemToTile(s32 arg0, u8 arg1, u16 arg2, u16 arg3);
s32 CheckSurroundingCollision(u16 arg0, u16 *arg1);
u8 sub_0201F78C(u8 arg0);
s32 sub_0201F844(u8 arg0);
void Islander_BuryRandomItem(s32 arg0);
void Islander_PlantRandomFlower(void);
void sub_0201FCB0(void);
s32 sub_0201FD1C(s32 arg0, s32 arg1);
s32 Islander_PlayAnim(u8 arg0);
void Islander_ClearStoredItem(s32 arg0);
s32 sub_0201FED4(u8 arg0, u8 arg1);
s32 SpawnEntity(u8 arg0, u8 arg1, u16 arg2, u16 arg3);
s32 sub_02020118(void *arg0, s32 arg1, s32 arg2);
s32 sub_0202029C(void *arg0);
s32 Islander_DecideTreeAction(void);
void sub_020205E0(void);
void Islander_AdjustAnimForTool(void);
s32 sub_020207C0(u8 arg0, s32 arg1);
s32 sub_02020814(u8 arg0, s32 arg1);
u8 sub_0202086C(void);
s32 sub_020208BC(s32 arg0);
void Islander_OnMoodChanged(void);
void WriteItemTileToVRAM(void *arg0, u16 arg1);
u16 Item_GetItemIdFromTileId(s32 arg0);
s32 sub_02020A78(void);
void Islander_Init(void);
s32 Island_GetFloatingItem(void);
void Islander_StepFlyingItem(void);
s32 sub_02020F54(void);
u16 sub_02021050(void);
s32 sub_020210D4(void);
s32 sub_020212F4(void);
void sub_020213DC(void);
void sub_02021574(void);
void sub_020215D0(void);
void Islander_MoveIndoorsOrOutdoors(void);
void sub_02021720(void);
void sub_020217AC(void);
void sub_020218B0(void);
void sub_02021AD8(void);
void Islander_ProcessFood(void);
void IslanderMoveAction_UpdateEmotion(void);
void sub_02022054(void);
void sub_020221C0(void);
void Islander_CheckClickedOnTimer(void);
void sub_020223AC(void);
void Islander_MoveAction11_State0(void);
void Islander_MoveAction11_State1(void);
void Islander_MoveAction11_State2(void);
void sub_0202275C(void);
void Islander_Fishing_Init(void);
void Islander_Fishing_State0(void);
void Islander_Fishing_State1(void);
void Islander_Fishing_State2(void);
void Islander_Fishing_State3(void);
void Islander_Fishing_State4(void);
void Islander_Fishing_State5(void);
void Islander_Fishing_State6(void);
void Islander_Fishing_State7(void);
void IslanderMoveAction_Fishing(void);
void Islander_ReceiveItem_Init(void);
void IslanderMoveAction_ReceiveItem(void);
void Islander_DespawnFlyingItem(void);
void Islander_StoreHeldItem(void);
void Islander_ProcessFishReceived(void);
void IslanderMoveAction_Dig(void);
void Islander_BuryItem_State0(void);
void Islander_BuryItem_State1(void);
void Islander_BuryItem_State2(void);
void Islander_BuryItem_State3(void);
void Islander_BuryItem_State4(void);
void Islander_BuryItem_State5(void);
void IslanderMoveAction_Bury(void);
void Islander_MoveAction20_Init(void);
void Islander_MoveAction20_State0(void);
void Islander_MoveAction20_State1(void);
void Islander_MoveAction20_State2(void);
void Islander_MoveAction20_State3(void);
void Islander_MoveAction20_State4(void);
void Islander_MoveAction20_Move(void);
void sub_02023B58(void);
s32 Item_IsFossil(mActor_name_t arg0);
s32 Item_IsGyroid(mActor_name_t arg0);
s32 Item_IsNES(mActor_name_t arg0);
s32 Item_IsFurniture(mActor_name_t arg0);
s32 Item_IsApple(mActor_name_t arg0);
s32 Item_IsOrange(mActor_name_t arg0);
s32 Item_IsPeach(mActor_name_t arg0);
s32 Item_IsPear(mActor_name_t arg0);
s32 Item_IsCherry(mActor_name_t arg0);
s32 Item_IsTurnip(mActor_name_t arg0);
s32 Item_IsMushroom(mActor_name_t arg0);
s32 Item_IsCandy(mActor_name_t arg0);
s32 Item_Is100Bells(mActor_name_t arg0);
s32 Item_Is1KBells(mActor_name_t arg0);
s32 Item_Is10KBells(mActor_name_t arg0);
s32 Item_Is30KBells(mActor_name_t arg0);
s32 Item_IsFlowerBag(mActor_name_t arg0);
s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t arg0);
s32 Item_IsNet(mActor_name_t arg0);
s32 Item_IsGoldenNet(mActor_name_t arg0);
s32 Item_IsAxe(mActor_name_t arg0);
s32 Item_IsGoldenAxe(mActor_name_t arg0);
s32 Item_IsShovel(mActor_name_t arg0);
s32 Item_IsGoldenShovel(mActor_name_t arg0);
s32 Item_IsFishingRod(mActor_name_t arg0);
s32 Item_IsGoldenRod(mActor_name_t arg0);
s32 Item_IsUmbrella(mActor_name_t arg0);
s32 Item_IsPaint(mActor_name_t arg0);
s32 Item_IsBalloon(mActor_name_t arg0);
s32 Item_IsPinwheel(mActor_name_t arg0);
s32 Item_IsHandFan(mActor_name_t arg0);
s32 Item_IsSignboard(mActor_name_t arg0);
s32 Item_IsShirt(mActor_name_t arg0);
s32 Item_IsCarpet(mActor_name_t arg0);
s32 Item_IsWallpaper(mActor_name_t arg0);
s32 Item_IsAirCheck(mActor_name_t arg0);
s32 Item_IsTrash(mActor_name_t arg0);
s32 Item_IsPitfall(mActor_name_t arg0);
s32 Item_IsConchSeaShellIcon(mActor_name_t arg0);
s32 Item_IsLionsPawShellIcon(mActor_name_t arg0);
s32 Item_IsCoral(mActor_name_t arg0);
s32 Item_IsFlowerLeaves(mActor_name_t arg0);
s32 Item_IsPurpleCosmos(mActor_name_t arg0);
s32 Item_IsBlueCosmos(mActor_name_t arg0);
s32 Item_IsYellowCosmos(mActor_name_t arg0);
s32 Item_IsRedTulips(mActor_name_t arg0);
s32 Item_IsWhiteTulips(mActor_name_t arg0);
s32 Item_IsYellowTulips(mActor_name_t arg0);
s32 Item_IsWhitePansies(mActor_name_t arg0);
s32 Item_IsPurplePansies(mActor_name_t arg0);
s32 Item_IsYellowPansies(mActor_name_t arg0);
s32 Item_IsCoconut(mActor_name_t arg0);
s32 Item_IsCabana(mActor_name_t arg0);
s32 Item_IsIslanderHouse(mActor_name_t arg0);
s32 Item_IsSapling(mActor_name_t arg0);
s32 Item_IsSmallTree(mActor_name_t arg0);
s32 Item_IsMediumTree(mActor_name_t arg0);
s32 Item_IsLargeTree(mActor_name_t arg0);
s32 Item_IsFullyGrownTree(mActor_name_t arg0);
s32 Item_IsDeadSapling(mActor_name_t arg0);
s32 Item_IsFruitAppleTree(mActor_name_t arg0);
s32 Item_IsFruitOrangeTree(mActor_name_t arg0);
s32 Item_IsFruitPeachTree(mActor_name_t arg0);
s32 Item_IsPearFruitTree(mActor_name_t arg0);
s32 Item_IsFruitCherryTree(mActor_name_t arg0);
s32 Item_IsSmallStump(mActor_name_t arg0);
s32 Item_IsMediumStump(mActor_name_t arg0);
s32 Item_IsLargeStump(mActor_name_t arg0);
s32 Item_IsFullyGrownStump(mActor_name_t arg0);
s32 Item_IsPalmSapling(mActor_name_t arg0);
s32 Item_IsSmallPalmTree(mActor_name_t arg0);
s32 Item_IsMediumPalmTree(mActor_name_t arg0);
s32 Item_IsLargePalmTree(mActor_name_t arg0);
s32 Item_IsPalmTree(mActor_name_t arg0);
s32 Item_IsDeadPalmSapling(mActor_name_t arg0);
s32 Item_IsFruitPalmTree(mActor_name_t arg0);
s32 Item_IsSmallPalmStump(mActor_name_t arg0);
s32 Item_IsMediumPalmStump(mActor_name_t arg0);
s32 Item_IsLargePalmStump(mActor_name_t arg0);
s32 Item_IsFullyGrownPalmStump(mActor_name_t arg0);
s32 Item_IsIslandFlag(mActor_name_t arg0);
s32 Item_IsHole(mActor_name_t arg0);
s32 Item_IsBuriedPitfall(mActor_name_t arg0);
s32 Item_IsCedarSapling(mActor_name_t arg0);
s32 Item_IsDeadCedarSapling(mActor_name_t arg0);
s32 Item_IsWeed(mActor_name_t arg0);
s32 Item_IsRock(mActor_name_t arg0);
s32 Item_IsReserved(mActor_name_t arg0);
s32 Item_GetTypeIndex(mActor_name_t arg0);
mActor_name_t Item_GetItemFromTypeIndex(s32 idx);
mActor_name_t Item_TypeToIslandItem(s32 idx);
void sub_02024B08(s32 arg0, u16 arg1, u8 arg2, u8 arg3);
void sub_02024C00(void);
void sub_02024C04(void);
void sub_02024C08(s32 arg0);
void sub_02024C44(s32 arg0);
void sub_02024DD0(s32 arg0);
void sub_02024DF8(s32 arg0);
void Unk_Struct_Size54_ResetIdx(s32 arg0);
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
void sub_02026B38(u8 arg0);
void sub_02026B48(u16 value);
void sub_02026BC8(u16 value);
void sub_02026BD8(void);
void sub_02026C0C(void);
void sub_02026C10(u16 value);
void sub_02026C68(u16 value);
void ChangeEmotion(u8 arg0);
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
s32 sub_02027300(u8 *arg0);
void sub_02027370(u8 arg0);
u32 sub_02027374(u8 *arg0);
u8 sub_020273D0(u8 *arg0, u8 arg1);
u32 sub_020274D0(u8 *arg0);
void sub_02027610(void);
void sub_02027728(void);
void sub_020279BC(void **arg0, u8 arg1, u8 arg2, u16 arg3);
void sub_02027B94(u8 *arg0);
void sub_02027C78(u8 *arg0);
void sub_02027D14(u8 *arg0, u8 arg1);
u8 *sub_02027E74(u8 arg0, u8 arg1, u8 arg2);
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
s32 sub_020285C8(void **arg0);
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

    REG_DMA3SAD = 0x020357F4;
    REG_DMA3DAD = 0x02000000;
    REG_DMA3CNT = 0x80000100;
    REG_DMA3SAD = 0x020359F4;
    REG_DMA3DAD = (u32) gObjPaletteBuffer;
    REG_DMA3CNT = 0x80000100;
    REG_DMA3SAD = 0x02000000;
    REG_DMA3DAD = 0x05000000;
    REG_DMA3CNT = 0x80000200;
    *(void **)0x03002970 = (void *)0x0203B000;
    *(s32 *)0x03001B40 = 0x020102A0;
    CpuSet((void *)0x0203B000, (void *)0x020102A0, 0x04000E60U);
    var_r2_4016 = 0;
    var_r4_4019 = (s32 *)0x03002400;
    do {
        *var_r4_4019 = (*(s32 *)((u8 *)(((var_r2_4016 * 4) + *(void **)0x03002970)) + (0x14)));
        var_r4_4019 += 4;
        var_r2_4016 += 1;
    } while (var_r2_4016 <= 3);
    temp_r3_4030 = *(void **)0x03002970;
    temp_r0_4038 = (*(u8 *)((u8 *)(temp_r3_4030) + (0x193E))) * 0xE10;
    gGameState.game_time_frames = temp_r0_4038;
    temp_r0_4046 = temp_r0_4038 + ((*(u8 *)((u8 *)(temp_r3_4030) + (0x193D))) * 0x3C);
    gGameState.game_time_frames = temp_r0_4046;
    gGameState.game_time_frames = (temp_r0_4046 + (*(u8 *)((u8 *)(temp_r3_4030) + (0x193C)))) * 0x3C;
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
    s32 sp0;
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
    if ((*(u16 *)((u8 *)(&gGameState) + (0x850))) == 0x101) {
        (*(u16 *)((u8 *)(&sp0) + (0))) = (u16) REG_IE;
        (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *(u16 *)0x04000000;
        *(u16 *)0x04000000 = 0x80;
        *(s16 *)0x04000132 = 0x8204;
        REG_IE = 0x1000;
        SoundBiasReset();
        asm("swi 0x3"); /* BIOS Stop */
        SoundBiasSet();
        REG_IE = (*(u16 *)((u8 *)(&sp0) + (0)));
        *(s16 *)0x04000132 = 0;
        gGameState.unk_856 = 0;
        gGameState.unk_857 = 0;
        gGameState.unk_851 = 0;
        gGameState.unk_850 = 0;
        sub_0201A620();
    }
    sub_02019C88();
    temp_r1_4245 = (*(s32 *)((u8 *)((void *)0x03003120) + (0x18)));
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

s32 Swap32(u32 *arg0) {
    u8 bytes[4];
    u8* arg0_ptr = (u8*)arg0;

    bytes[0] = arg0_ptr[3];
    bytes[1] = arg0_ptr[2];
    bytes[2] = arg0_ptr[1];
    bytes[3] = arg0_ptr[0];

    return *(s32*)bytes;
}

void sub_0201A218(void) {
    s32 sp0;
    u16 temp_r4_4318;

    temp_r4_4318 = REG_IME;
    REG_IME = 0;
    (*(s16 *)((u8 *)((void *)0x04000134) + (0))) = 0xC000;
    *(s16 *)0x04000158 = 0;
    *(s32 *)0x04000154 = 0;
    (*(s16 *)((u8 *)((void *)0x04000134) + (0xC))) = 0x47;
    *(s16 *)0x04000202 = 0x80;
    *(s16 *)0x04000202 = 0x80;
    REG_IE |= 0x80;
    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03003120, 0x01000010U);
    REG_IME = temp_r4_4318;
}

void JoybootHandler(void) {
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
        sp4 = *(u32 *)0x04000150;
        temp_r2_4418 = *(u32 *)0x03003149;
        if (temp_r2_4418 != 1) {
            if (Swap32(&sp4) == *(s32 *)0x0202AFC4) {
                *(u32 *)0x03003149 = 1U;
            }
        } else {
            temp_r1_4423 = (*(u32 *)((u8 *)((void *)0x03003120) + (0x18)));
            if (temp_r1_4423 != 0xFFFE0105) {
                if (temp_r1_4423 <= 0xFFFE0105U) {
                    if (temp_r1_4423 > -0x1FEFEU) {
                        goto block_74;
                    }
                    if (temp_r1_4423 < -0x1FEFFU) {
                        goto block_74;
                    }
                    var_r1_4440 = (*(s32 *)((u8 *)((void *)0x03003120) + (8)));
                    if (var_r1_4440 < 0) {
                        var_r1_4440 += 3;
                    }
                    if ((s32) (*(s32 *)((u8 *)((void *)0x03003120) + (4))) > (s32) (var_r1_4440 >> 2)) {
                        temp_r4_4478 = (s8) *(u8 *)0x03003144;
                        if (temp_r4_4478 != 0) {
                            temp_r1_4486 = 8 & *(u16 *)0x04000158;
                            if (temp_r1_4486 != 0) {

                            } else {
                                var_r3_4491 = 0xFFFE0209;
                                if (temp_r4_4478 == 1) {
                                    var_r3_4491 = -0x1FDF8;
                                }
                                *(u32 *)0x04000154 = var_r3_4491;
                                (*(u8 *)((u8 *)((void *)0x03003145) + (0))) = (u8) *(u8 *)0x03003144;
                                (*(s8 *)((u8 *)((void *)0x03003145) + (4))) = (s8) temp_r1_4486;
                                (*(u32 *)((u8 *)((void *)0x03003120) + (0x18))) = (u32) temp_r1_4486;
                            }
                        } else if (sp4 == 0xFFFE0106) {
                            *(u8 *)0x03003144 = 1;
                        } else {
                            *(u8 *)0x03003144 = 2;
                        }
                    } else {
                        temp_r2_4526 = (*(s32 *)((u8 *)((void *)0x03003120) + (0xC)));
                        if (temp_r2_4526 >= 0) {
                            temp_r5_4534 = 8 & *(u32 *)0x04000158;
                            if (temp_r5_4534 != 0) {

                            } else {
                                var_r0_4539 = (*(s32 *)((u8 *)((void *)0x03003120) + (8)));
                                if (var_r0_4539 < 0) {
                                    var_r0_4539 += 3;
                                }
                                temp_r4_4545 = (*(s32 *)((u8 *)((void *)0x03003120) + (4)));
                                if (temp_r4_4545 == (var_r0_4539 >> 2)) {
                                    var_r1_4550 = ~(*(s32 *)((u8 *)((void *)0x03003120) + (0x20)));
                                    goto block_40;
                                }
                                if ((u8) temp_r2_4526 == 0xFF) {
                                    *(u32 *)0x04000154 = (s32) ~(*(s32 *)((u8 *)((void *)0x03003120) + (0x1C)));
                                    (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) = (s32) temp_r5_4534;
                                } else {
                                    var_r1_4550 = *(u32 *)((temp_r4_4545 * 4) + (*(s32 *)((u8 *)((void *)0x03003120) + (0))));
                                    (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) + var_r1_4550);
                                    (*(s32 *)((u8 *)((void *)0x03003120) + (0x20))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (0x20))) + var_r1_4550);
block_40:
                                    *(u32 *)0x04000154 = var_r1_4550;
                                    (*(s32 *)((u8 *)((void *)0x03003120) + (4))) = (s32) (temp_r4_4545 + 1);
                                }
                                goto block_68;
                            }
                        } else {
                            if ((*(u8 *)((u8 *)((void *)0x03003120) + (0x26))) != 1) {
                                goto block_73;
                            }
                            var_r2_4600 = 8 & *(u32 *)0x04000158;
                            if (var_r2_4600 != 0) {

                            } else {
                                var_r0_4606 = 0xFFFE0204;
                                goto block_72;
                            }
                        }
                    }
                } else if (temp_r1_4423 == 0xFFFE0202) {
                    var_r1_4613 = (*(s32 *)((u8 *)((void *)0x03003120) + (8)));
                    if (var_r1_4613 < 0) {
                        var_r1_4613 += 3;
                    }
                    if ((s32) (*(s32 *)((u8 *)((void *)0x03003120) + (4))) > (s32) (var_r1_4613 >> 2)) {
                        if (8 & *(u32 *)0x04000158) {

                        } else {
                            if ((*(s32 *)((u8 *)((void *)0x03003120) + (0x20))) == -1) {
                                *(u32 *)0x04000154 = 0xFFFE0208;
                                (*(u8 *)((u8 *)((void *)0x03003120) + (0x25))) = temp_r2_4418;
                            } else {
                                *(u32 *)0x04000154 = 0xFFFE0209;
                                (*(u8 *)((u8 *)((void *)0x03003120) + (0x25))) = 2U;
                            }
                            *(u32 *)0x03003149 = 0U;
                            (*(u32 *)((u8 *)((void *)0x03003120) + (0x18))) = 0U;
                        }
                    } else if ((s32) (*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) > -1) {
                        temp_r3_4673 = Swap32(&sp4);
                        temp_r1_4679 = 8 & *(u32 *)0x04000158;
                        if (temp_r1_4679 != 0) {

                        } else {
                            var_r0_4684 = (*(s32 *)((u8 *)((void *)0x03003120) + (8)));
                            if (var_r0_4684 < 0) {
                                var_r0_4684 += 3;
                            }
                            temp_r2_4690 = (*(s32 *)((u8 *)((void *)0x03003120) + (4)));
                            if (temp_r2_4690 == (var_r0_4684 >> 2)) {
                                *(u32 *)((temp_r2_4690 * 4) + (*(s32 *)((u8 *)((void *)0x03003120) + (0)))) = sp4;
                                goto block_67;
                            }
                            if ((u8) (*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) == 0xFF) {
                                temp_r0_4706 = (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) + temp_r3_4673;
                                (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) = temp_r0_4706;
                                if (temp_r0_4706 != -1) {
                                    (*(u8 *)((u8 *)((void *)0x03003120) + (0x25))) = 2U;
                                }
                                (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) = (s32) temp_r1_4679;
                            } else {
                                *(u32 *)((temp_r2_4690 * 4) + (*(s32 *)((u8 *)((void *)0x03003120) + (0)))) = sp4;
                                (*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (0x1C))) + temp_r3_4673);
block_67:
                                (*(s32 *)((u8 *)((void *)0x03003120) + (0x20))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (0x20))) + temp_r3_4673);
                                (*(s32 *)((u8 *)((void *)0x03003120) + (4))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (4))) + 1);
                            }
block_68:
                            (*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) + 1);
                        }
                    } else if ((*(u8 *)((u8 *)((void *)0x03003120) + (0x26))) == 1) {
                        var_r2_4600 = 8 & *(u32 *)0x04000158;
                        if (var_r2_4600 == 0) {
                            var_r0_4606 = 0xFFFE0104;
block_72:
                            *(u32 *)0x04000154 = var_r0_4606;
                            (*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) = (s32) var_r2_4600;
                        }
                    } else {
block_73:
                        *(u32 *)0x04000154 = 0xFFFE0205;
                    }
                } else {
block_74:
                    (*(u32 *)((u8 *)((void *)0x03003120) + (0x18))) = sp4;
                    if ((sp4 >= 0xFFFE0101U) && ((sp4 <= 0xFFFE0102U) || (sp4 == 0xFFFE0202))) {
                        sp0 = 0;
                        CpuFastSet(&sp0, (void *)0x03003120, 0x01000010U);
                        (*(s32 *)((u8 *)((void *)0x03003120) + (0xC))) = -1;
                        (*(u32 *)((u8 *)((void *)0x03003120) + (0x18))) = sp4;
                        (*(s8 *)((u8 *)((void *)0x03003120) + (0x29))) = 1;
                    }
                }
            } else {
                *(u32 *)0x04000154 = 0xFFFE0207;
                *(u32 *)0x03003149 = 0U;
                (*(u32 *)((u8 *)((void *)0x03003120) + (0x18))) = 0U;
            }
        }
    }
    *(u32 *)0x04000140 = var_r8_4372;
    *(s8 *)0x0300314A = 0;
}

void sub_0201A620(void) {
    s32 sp0;
    u16 temp_r4_4840;

    temp_r4_4840 = REG_IME;
    REG_IME = 0;
    (*(s16 *)((u8 *)((void *)0x04000134) + (0))) = 0x8000;
    (*(s16 *)((u8 *)((void *)0x04000134) + (0))) = 0xC000;
    *(s16 *)0x04000158 = 0;
    *(s32 *)0x04000154 = 0;
    (*(s16 *)((u8 *)((void *)0x04000134) + (0xC))) = 0x47;
    (*(s16 *)((u8 *)(((void *)0x04000134 + 0xC)) + (0xC2))) = 0x80;
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
    REG_IE = 0;
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
        temp_r1_4963 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
        if ((temp_r1_4963->draw_enabled == 0) && (mMsg_RequestAppearWait(temp_r1_4963) == 1)) {
            mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
            goto block_4;
        }
    } else {
        temp_r1_4981 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
        if ((temp_r1_4981 != NULL) && ((s8) (u8) temp_r1_4981->current_mode != 1)) {
            temp_r4_4994 = mMsg_RequestDisappearWait(temp_r1_4981);
            if (temp_r4_4994 == 1) {
                mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
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
    temp_r0_5014 = (*(void **)((u8 *)(arg0) + (0x14)));
    if (temp_r0_5014 == NULL) {
        return 1;
    }
    temp_r3_5024 = arg0 + 0x64;
    if ((*(u8 *)((u8 *)(temp_r0_5014) + (0x7C))) == 1) {
        temp_r1_5027 = (s8) temp_r1_5012;
        *(u32 *)(temp_r3_5024 + temp_r1_5027) = 0;
        if (temp_r1_5027 == 1) {
            (*(s8 *)((u8 *)(arg0) + (0x6D))) = 0;
        }
    }
    var_r5_5036 = 0;
    if (*(u32 *)(temp_r3_5024 + (s8) temp_r1_5012) == 0) {
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
    u32 sp0;
    u32 sp4;
    u8 sp8;
    u8 sp9;
    u8 spA;
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
            sub_02019BA8((u16 *)0x020357F4, 7U, temp_r4_5365, &sp8, &sp9, &spA);
            sp0 = sp9;
            sp4 = spA;
            sub_02019BD8(0U, 7U, temp_r4_5365, sp8, sp0, sp4);
            var_r5_5356 += 1;
        } while ((s32) var_r5_5356 <= 6);
        break;
    case 4:
        sp0 = 0x17;
        sp4 = 0x11;
        sub_02019BD8(0U, 7U, 1U, 0x10U, sp0, sp4);
        sp0 = 0x1B;
        sp4 = 0x13;
        sub_02019BD8(0U, 7U, 2U, 0x15U, sp0, sp4);
        sp0 = 0x1F;
        sp4 = 0x1A;
        sub_02019BD8(0U, 7U, 3U, 0x1AU, sp0, sp4);
        sp0 = 0x1E;
        sp4 = 0x14;
        sub_02019BD8(0U, 7U, 4U, 0x17U, sp0, sp4);
        sp0 = 0x1D;
        sp4 = 0x16;
        sub_02019BD8(0U, 7U, 5U, 0x16U, sp0, sp4);
        break;
    case 3:
        sp0 = 0x17;
        sp4 = 0x11;
        sub_02019BD8(0U, 7U, 1U, 0x17U, sp0, sp4);
        sp0 = 0x1B;
        sp4 = 0x13;
        sub_02019BD8(0U, 7U, 2U, 0x1BU, sp0, sp4);
        sp0 = 0x1F;
        sp4 = 0x1A;
        sub_02019BD8(0U, 7U, 3U, 0x1FU, sp0, sp4);
        sp0 = 0x1D;
        sp4 = 0x15;
        sub_02019BD8(0U, 7U, 4U, 0x1DU, sp0, sp4);
        sp0 = 0x1F;
        sp4 = 9;
        sub_02019BD8(0U, 7U, 5U, 0x1EU, sp0, sp4);
        sp0 = 0xB;
        sp4 = 8;
        sub_02019BD8(0U, 7U, 6U, 0xAU, sp0, sp4);
        break;
    case 1:
        if ((*(u8 *)((u8 *)(arg0) + (0x6F))) == 1) {
            sp0 = 0xA;
            sp4 = 4;
            sub_02019BD8(0U, 7U, 1U, 0x16U, sp0, sp4);
            sp0 = 0xE;
            sp4 = 6;
            sub_02019BD8(0U, 7U, 2U, 0x1AU, sp0, sp4);
            sp0 = 0xD;
            sp4 = 3;
            sub_02019BD8(0U, 7U, 3U, 0x1EU, sp0, sp4);
            sp0 = 0x15;
            sp4 = 0xC;
            sub_02019BD8(0U, 7U, 4U, 0x1DU, sp0, sp4);
            sp0 = 0x1F;
            sp4 = 0x15;
            var_r2_5295 = 5;
            goto block_14;
        }
        if ((*(u8 *)((u8 *)(arg0) + (0x6E))) == 1) {
            sp0 = 0x10;
            sp4 = 0x14;
            sub_02019BD8(0U, 7U, 1U, 8U, sp0, sp4);
            sp0 = 0x14;
            sp4 = 0x1B;
            sub_02019BD8(0U, 7U, 2U, 0xAU, sp0, sp4);
            sp0 = 0x19;
            sp4 = 0x1F;
            sub_02019BD8(0U, 7U, 3U, 0x15U, sp0, sp4);
            sp0 = 0x17;
            sp4 = 0x1D;
            sub_02019BD8(0U, 7U, 4U, 0x10U, sp0, sp4);
            sp0 = 0xF;
            sp4 = 0x1F;
            sub_02019BD8(0U, 7U, 5U, 7U, sp0, sp4);
            sp0 = 0x1F;
            sp4 = 0x1F;
            var_r2_5295 = 6;
block_14:
            sub_02019BD8(0U, 7U, var_r2_5295, 0x1FU, sp0, sp4);
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
    if (((*(s8 *)((u8 *)(arg0) + (0x50))) == 0) && (temp_r5_5405 != 1)) {
        (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) gGameState.unk_828;
        (*(u16 *)((u8 *)(arg0) + (0x36))) = (u16) gGameState.unk_82A;
        (*(u16 *)((u8 *)(arg0) + (0x48))) = (u16) gGameState.unk_81E;
        (*(u16 *)((u8 *)(arg0) + (0x44))) = (u16) gGameState.bg3_vofs;
        (*(u16 *)((u8 *)(arg0) + (0x46))) = (u16) gGameState.unk_848;
        (*(s8 *)((u8 *)(arg0) + (0x50))) = (s8) temp_r5_5405;
    }
    gGameState.unk_828 &= 0xFFFC;
    gGameState.unk_82A |= 0x1800;
    gGameState.unk_81E = 0;
    gGameState.bg3_vofs = 0;
    gGameState.unk_848 = 0;
}

void sub_0201AB3C(void *arg0, s8 arg1) {
    u16 temp_r1_5496;

    if (arg1 == (*(s8 *)((u8 *)(arg0) + (0x50)))) {
        gGameState.unk_828 = (*(u16 *)((u8 *)(arg0) + (0x34)));
        temp_r1_5496 = (*(u16 *)((u8 *)(arg0) + (0x36)));
        gGameState.unk_82A = temp_r1_5496;
        if (*(u16 *)0x0203E9A0 == 1) {
            gGameState.unk_82A = 0xFDFF & temp_r1_5496;
        }
        gGameState.unk_81E = (*(u16 *)((u8 *)(arg0) + (0x48)));
        gGameState.bg3_vofs = (*(u16 *)((u8 *)(arg0) + (0x44)));
        gGameState.unk_848 = (*(u16 *)((u8 *)(arg0) + (0x46)));
        (*(s8 *)((u8 *)(arg0) + (0x50))) = 0;
    }
}

void sub_0201ABBC(void *arg0) {
    mMsg_Window_c *temp_r1_5544;

    temp_r1_5544 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
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
    if ((gGameState.unk_850 == 0) && ((s8) (*(u8 *)((u8 *)(arg0) + (0x5A))) != 0)) {
        if (sub_0201A714(arg0, (s8) temp_r5_5568) == 1) {
            (*(u8 *)((u8 *)(arg0) + (0x5F))) = temp_r5_5568;
            (*(s32 *)((u8 *)(arg0) + (0x10))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
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
    if ((gGameState.unk_850 == 0) && ((s8) (*(u8 *)((u8 *)(arg0) + (0x58))) != 0)) {
        if (sub_0201A714(arg0, (s8) temp_r5_5612) == 1) {
            (*(u8 *)((u8 *)(arg0) + (0x5D))) = temp_r5_5612;
            (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
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
    if ((s8) (*(u8 *)((u8 *)(arg0) + (0x59))) != 0) {
        if (sub_0201A714(arg0, (s8) temp_r5_5656) == 1) {
            (*(u8 *)((u8 *)(arg0) + (0x5E))) = temp_r5_5656;
            (*(s32 *)((u8 *)(arg0) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
            sub_0201B1B8(arg0);
        }
        var_r1_5657 = 1;
    }
    return var_r1_5657;
}

void sub_0201ACCC(void *arg0) {
    (*(s32 *)((u8 *)((void *)0x03003120) + (8))) = 0x3980;
    (*(s32 *)((u8 *)((void *)0x03003120) + (0))) = (s32) *(s32 *)0x03002970;
    (*(s8 *)((u8 *)((void *)0x03003120) + (0x26))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x6A))) = 2;
    (*(s8 *)((u8 *)(arg0) + (0x71))) = 0;
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
        (*(s8 *)((u8 *)(arg0) + (0x6D))) = var_r1_5714;
    }
    return var_r1_5714;
}

void sub_0201AD34(void *arg0) {
    (*(s32 *)((u8 *)((void *)0x03003120) + (8))) = 0x3980;
    (*(s32 *)((u8 *)((void *)0x03003120) + (0))) = (s32) *(s32 *)0x03001B40;
    (*(s8 *)((u8 *)((void *)0x03003120) + (0x26))) = 1;
    if ((*(s32 *)((u8 *)((void *)0x03003120) + (0x18))) == 0xFFFE0101) {
        (*(s8 *)((u8 *)(arg0) + (0x70))) = 1;
    } else {
        (*(s8 *)((u8 *)(arg0) + (0x70))) = 0;
    }
    (*(s8 *)((u8 *)(arg0) + (0x6A))) = 1;
    (*(s8 *)((u8 *)((arg0 + 0x6A)) + (7))) = 1;
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
    if (((*(u16 *)((u8 *)(arg0) + (0x70))) == 0x100) && (var_r3_5792 == 1)) {
        *(s16 *)0x0203E9A0 = (s16) var_r3_5792;
        (*(s8 *)((u8 *)(*(void **)0x03001B40) + (0x13))) = 1;
    }
    return (s16) var_r3_5792;
}

void sub_0201ADDC(void) {

}

s32 sub_0201ADE0(void *arg0, s8 arg1) {
    (*(s8 *)((u8 *)(arg0) + (0x58))) = arg1;
    return 1;
}

s32 sub_0201ADE8(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x58))) = 1;
    return 1;
}

s32 sub_0201ADF4(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x58))) = 2;
    return 1;
}

s32 sub_0201AE00(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x58))) = 3;
    return 1;
}

void sub_0201AE0C(void *arg0) {
    s32 (*temp_r1_5889)(void *);

    if ((u32) (*(u8 *)((u8 *)(arg0) + (0x58))) <= 3U) {
        temp_r1_5889 = *(u32 *)(0x0202AFCC + ((s8) (*(u8 *)((u8 *)(arg0) + (0x58))) * 4));
        if (temp_r1_5889 != NULL) {
            temp_r1_5889(arg0);
            (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
        }
    }
}

void sub_0201AE40(void *arg0) {
    s32 var_r2_5910;
    s8 *var_r1_5921;

    var_r2_5910 = 0xB;
    if ((*(s32 *)((u8 *)((void *)0x03003120) + (0x18))) == 0xFFFE0101) {
        var_r2_5910 = 0x1E;
    }
    var_r1_5921 = arg0 + 0x58;
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03002980, var_r2_5910) == 1) {
        if ((*(s32 *)((u8 *)((void *)0x03003120) + (0x18))) == 0xFFFE0202) {
            sub_0201ACCC(arg0);
        } else {
            sub_0201AD34(arg0);
        }
        sub_0201A854(arg0, 2);
        sub_0201AA98(arg0, 2U);
        var_r1_5921 = arg0 + 0x58;
        (*(u8 *)((u8 *)(arg0) + (0x53))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x58)));
        (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x03002980;
    }
    *var_r1_5921 = 0;
}

void sub_0201AEBC(void *arg0) {
    u8 *var_r0_5997;
    u8 temp_r0_5980;
    u8 temp_r0_5984;
    u8 temp_r0_6000;
    u8 var_r1_5989;

    if ((*(u8 *)((u8 *)(arg0) + (0x71))) == 0) {
        (*(s8 *)((u8 *)(arg0) + (0x60))) = sub_0201ACF8(arg0);
    } else {
        temp_r0_5980 = (*(u8 *)((u8 *)(arg0) + (0x74)));
        if (temp_r0_5980 == 0) {
            temp_r0_5984 = (u8) sub_0201AD84(arg0);
            (*(u8 *)((u8 *)(arg0) + (0x75))) = temp_r0_5984;
            var_r1_5989 = temp_r0_5984;
            if (var_r1_5989 != 0) {
                (*(u8 *)((u8 *)(arg0) + (0x74))) = 0x3CU;
            } else {
                var_r0_5997 = arg0 + 0x60;
                goto block_8;
            }
        } else {
            temp_r0_6000 = temp_r0_5980 - 1;
            (*(u8 *)((u8 *)(arg0) + (0x74))) = temp_r0_6000;
            if ((temp_r0_6000 << 0x18) == 0) {
                var_r1_5989 = (*(u8 *)((u8 *)(arg0) + (0x75)));
                var_r0_5997 = (arg0 + 0x75) - 0x15;
block_8:
                *var_r0_5997 = var_r1_5989;
            }
        }
    }
    if (((u32) (u8) ((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x70))) - 3) <= 2U) && ((s8) (u8) (*(s8 *)((u8 *)(arg0) + (0x60))) != 0) && (sub_0201ADF4(arg0) != 0)) {
        sub_0201AE0C(arg0);
    }
}

void sub_0201AF48(void *arg0) {
    s32 sp[2];
    s8 *var_r6_6104;
    u16 var_r1_6128;
    u8 temp_r2_6050;

    memcpy(sp, (void *)0x0202B00C, sizeof(sp));
    temp_r2_6050 = (*(u8 *)((u8 *)(arg0) + (0x70)));
    if (temp_r2_6050 == 1) {
        gGameState.unk_856 = 0;
        gGameState.unk_857 = 0;
        gGameState.unk_84E = 0;
        gGameState.unk_84F = 0;
        if ((s8) (*(u8 *)((u8 *)(arg0) + (0x60))) != 2) {
            (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))->cancel_continue = temp_r2_6050;
            (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))->force_next = temp_r2_6050;
            (*(s32 *)((u8 *)(arg0) + (0x28))) = 0;
        } else {
            (*(s32 *)((u8 *)(arg0) + (0x28))) = 0x3C;
            sub_02019D78(0x28U);
        }
        (*(u8 *)((u8 *)(arg0) + (0x53))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x58)));
        (*(s8 *)((u8 *)(arg0) + (0x62))) = 0;
        var_r6_6104 = arg0 + 0x58;
    } else {
        var_r6_6104 = arg0 + 0x58;
        if ((mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), *((((s8) (*(u8 *)((u8 *)(arg0) + (0x60))) - 1) * 4) + sp)) == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
            var_r1_6128 = 0x28;
            if ((s8) (*(u8 *)((u8 *)(arg0) + (0x60))) == 1) {
                var_r1_6128 = 0x27;
            }
            sub_02019D78(var_r1_6128);
            gGameState.unk_856 = 0;
            gGameState.unk_857 = 0;
            mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
            (*(u8 *)((u8 *)(arg0) + (0x53))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x58)));
            (*(s8 *)((u8 *)(arg0) + (0x62))) = 0;
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

    temp_r1_6169 = (*(u8 *)((u8 *)(arg0) + (0x70)));
    if ((temp_r1_6169 == 1) && (temp_r0_6172 = (*(s32 *)((u8 *)(arg0) + (0x28))), (temp_r0_6172 != 0))) {
        temp_r0_6175 = temp_r0_6172 - 1;
        (*(s32 *)((u8 *)(arg0) + (0x28))) = temp_r0_6175;
        if (temp_r0_6175 == 0) {
            (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x7B))) = temp_r1_6169;
            (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x79))) = temp_r1_6169;
        }
    } else {
        temp_r1_6187 = (*(void **)((u8 *)(arg0) + (0x14)));
        temp_r2_6190 = (*(u8 *)((u8 *)(temp_r1_6187) + (0x7C)));
        if (temp_r2_6190 == 0) {
            if ((*(u8 *)((u8 *)(arg0) + (0x6D))) == 1) {
                (*(u8 *)((u8 *)(arg0) + (0x53))) = 3U;
                sub_02019B1C(&gGameState, 0x80U, 0x3FU, 0U);
                gGameState.unk_82A &= 0xFEFF;
                (*(u8 *)((u8 *)(arg0) + (0x6D))) = 0U;
                return;
            }
            temp_r0_6223 = arg0 + 0x53;
            (*(u8 *)((u8 *)(arg0) + (0x53))) = temp_r2_6190;
            (*(s16 *)((u8 *)(arg0) + (0x2C))) = (s16) temp_r2_6190;
            (*(s8 *)((u8 *)(temp_r0_6223) + (0x1D))) = 0;
            temp_r0_6232 = (s8) *(u32 *)((temp_r0_6223 + 0x1D) - 0x13);
            switch (temp_r0_6232) {                 /* irregular */
            case 1:
                sub_0201A854(arg0, 1);
                break;
            case 3:
                sub_0201A854(arg0, 3);
                break;
            }
            (*(void **)((u8 *)(arg0) + (0x14))) = (void *) (*(void **)((u8 *)(arg0) + (8)));
            sub_0201AB3C(arg0, 2);
            mMsg_CopyTilesToVram(0, 0x90, (*(u8 **)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x50))));
            if (gGameState.unk_856 == 1) {
                (*(u8 *)((u8 *)(arg0) + (0x72))) = (u8) gGameState.unk_856;
            }
        } else if (((u32) (u8) ((*(u8 *)((u8 *)(temp_r1_6187) + (0x70))) - 3) <= 2U) && ((*(u8 *)((u8 *)(arg0) + (0x70))) == 0) && (gGameState.unk_856 == 1)) {
            (*(u8 *)((u8 *)(temp_r1_6187) + (0x7B))) = (u8) gGameState.unk_856;
            (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x79))) = (u8) gGameState.unk_856;
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
    (*(s8 *)((u8 *)(arg0) + (0x59))) = arg1;
    return 1;
}

s32 sub_0201B194(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x59))) = 1;
    return 1;
}

s32 sub_0201B1A0(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x59))) = 2;
    return 1;
}

s32 sub_0201B1AC(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x59))) = 3;
    return 1;
}

void sub_0201B1B8(void *arg0) {
    s32 (*temp_r1_6376)(void *);

    if ((u32) (*(u8 *)((u8 *)(arg0) + (0x59))) <= 3U) {
        temp_r1_6376 = *(u32 *)(0x0202AFEC + ((s8) (*(u8 *)((u8 *)(arg0) + (0x59))) * 4));
        if (temp_r1_6376 != NULL) {
            temp_r1_6376(arg0);
            (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
        }
    }
}

void sub_0201B1EC(void *arg0) {
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03003060, 0x15) == 1) {
        sub_0201A854(arg0, 3);
        sub_0201AA98(arg0, 3U);
        (*(u8 *)((u8 *)(arg0) + (0x54))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x59)));
        (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x03003060;
    }
    (*(u8 *)((u8 *)(arg0) + (0x59))) = 0U;
}

void sub_0201B238(void *arg0) {
    void *temp_r2_6432;

    temp_r2_6432 = (*(void **)((u8 *)(arg0) + (0x14)));
    if ((*(u8 *)((u8 *)(temp_r2_6432) + (0x7C))) == 0) {
        if (sub_0201B1AC(arg0) == 1) {
            goto block_11;
        }
    } else if ((u32) (u8) ((*(u8 *)((u8 *)(temp_r2_6432) + (0x70))) - 3) <= 2U) {
        if ((*(s8 *)((u8 *)(temp_r2_6432) + (0x77))) != -1) {
            if ((mMsg_CheckControlCode((*(u8 **)((u8 *)(temp_r2_6432) + (0x54))), 1U, (*(s16 *)((u8 *)(temp_r2_6432) + (0x6C)))) == 0) || ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x5C))) != 0x16)) {
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
            (*(s8 *)((u8 *)(arg0) + (0x72))) = 1;
        }
    }
}

void sub_0201B2E8(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x54))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x59)));
    (*(u8 *)((u8 *)(arg0) + (0x59))) = 0U;
    (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
    (*(s32 *)((u8 *)(&gGameState) + (8))) = 0;
    gGameState.unk_850 = 1;
    gGameState.unk_85A = 1;
    sub_02019D98(0x14U);
}

void sub_0201B328(void *arg0) {
    mMsg_Window_c *temp_r0_6578;
    mMsg_Window_c *temp_r2_6594;
    s32 temp_r0_6567;

    if (gGameState.unk_850 == 1) {
        if ((s32) (*(s32 *)((u8 *)(&gGameState) + (8))) > 0x78) {
            temp_r0_6567 = mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), 0x17);
            if ((temp_r0_6567 == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
                (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
                temp_r0_6578 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
                temp_r0_6578->text_delay_timer = 0;
                mMsg_MainSetup_Window(temp_r0_6578);
                gGameState.unk_851 = (u8) temp_r0_6567;
            }
        }
        (*(s32 *)((u8 *)(&gGameState) + (8))) = (s32) ((*(s32 *)((u8 *)(&gGameState) + (8))) + 1);
        return;
    }
    temp_r2_6594 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
    if (temp_r2_6594->draw_enabled == 0) {
        if (sub_0201B1AC(arg0) == 1) {
            sub_0201B1B8(arg0);
        }
    } else if ((u32) (u8) ((u8) temp_r2_6594->current_mode - 3) <= 2U) {
        if (temp_r2_6594->selected_choice != -1) {
            if ((mMsg_CheckControlCode(temp_r2_6594->text, 1U, temp_r2_6594->text_offset) != 0) && ((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))->message_id == 0x17)) {
                goto block_15;
            }
        } else if (sub_0201A810(arg0 + 0x2C, 0x258) == 1) {
block_15:
            if (sub_0201B1A0(arg0) != 0) {
                sub_0201B1B8(arg0);
                (*(s32 *)((u8 *)(&gGameState) + (8))) = 0x78;
            }
        } else if (gGameState.unk_856 != 0) {
            (*(s8 *)((u8 *)(arg0) + (0x72))) = 1;
        }
    }
}

void sub_0201B420(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x54))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x59)));
    (*(u8 *)((u8 *)(arg0) + (0x59))) = 0U;
    if ((*(s32 *)((u8 *)(&gGameState) + (8))) != 0) {
        if ((s16) gGameState.unk_816 != -1) {
            sub_02019D88(gGameState.unk_816);
        }
        sub_02027068();
        (*(s32 *)((u8 *)(&gGameState) + (8))) = 0;
    }
}

void sub_0201B464(void *arg0) {
    u8 temp_r5_6714;

    temp_r5_6714 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x7C)));
    if (temp_r5_6714 == 0) {
        (*(u8 *)((u8 *)(arg0) + (0x54))) = temp_r5_6714;
        if ((*(s8 *)((u8 *)(arg0) + (0x5E))) == 1) {
            sub_0201A854(arg0, 1);
        }
        (*(s8 *)((u8 *)(arg0) + (0x5E))) = (s8) temp_r5_6714;
        (*(void **)((u8 *)(arg0) + (0x14))) = (void *) (*(void **)((u8 *)(arg0) + (0xC)));
        sub_0201AB3C(arg0, 3);
        mMsg_CopyTilesToVram(0, 0x90, (*(u8 **)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x50))));
        (*(s16 *)((u8 *)(arg0) + (0x2C))) = (s16) temp_r5_6714;
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
    if ((*(u8 *)((u8 *)(*(void **)0x03001B40) + (0x193A))) != 0) {
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
    if (temp_r5_6862 != (*(s8 *)((u8 *)(arg0) + (0x63)))) {
        CpuSet((temp_r5_6862 * 0x10) + 0x0202B014, (void *)0x02000190, 8U);
        CpuSet((temp_r5_6862 * 0xA) + 0x0202B194, (void *)0x020001D6, 5U);
        CpuFastSet((void *)0x02000180, (void *)0x05000180, 8U);
        CpuFastSet((void *)0x020001C0, (void *)0x050001C0, 8U);
        temp_r4_6893 = (temp_r5_6862 * 8) + 0x02034EE4;
        CpuSet(temp_r4_6893, (void *)0x02000102, 4U);
        CpuSet(temp_r4_6893, (void *)0x02000122, 4U);
        CpuFastSet((void *)0x02000100, (void *)0x05000100, 8U);
        CpuFastSet((void *)0x02000120, (void *)0x05000120, 8U);
        (*(s8 *)((u8 *)(arg0) + (0x63))) = (s8) temp_r5_6862;
    }
    gGameState.unk_820 = 0x2441;
    gGameState.unk_81C = 0x1006;
}

s32 sub_0201B680(void *arg0, s8 arg1) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = arg1;
    return 1;
}

s32 sub_0201B688(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 1;
    return 1;
}

s32 sub_0201B694(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 2;
    return 1;
}

s32 sub_0201B6A0(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 3;
    return 1;
}

s32 sub_0201B6AC(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 4;
    return 1;
}

s32 sub_0201B6B8(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 5;
    return 1;
}

s32 sub_0201B6C4(void *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x5A))) = 6;
    return 1;
}

void sub_0201B6D0(void *arg0) {
    s32 (*temp_r1_7021)(void *);

    if ((u32) (*(u8 *)((u8 *)(arg0) + (0x5A))) <= 6U) {
        temp_r1_7021 = *(u32 *)(0x0202B284 + ((s8) (*(u8 *)((u8 *)(arg0) + (0x5A))) * 4));
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
        (*(u8 *)((u8 *)(arg0) + (0x55))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x5A)));
        (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x03002980;
    }
    (*(u8 *)((u8 *)(arg0) + (0x5A))) = 0U;
}

void sub_0201B75C(void *arg0) {
    void *temp_r1_7080;

    temp_r1_7080 = (*(void **)((u8 *)(arg0) + (0x14)));
    if ((*(u8 *)((u8 *)(temp_r1_7080) + (0x7C))) == 0) {
        if (sub_0201B6B8(arg0) == 1) {
            sub_0201B6D0(arg0);
        }
    } else if ((mMsg_CheckControlCode((*(u8 **)((u8 *)(temp_r1_7080) + (0x54))), 1U, (*(s16 *)((u8 *)(temp_r1_7080) + (0x6C)))) != 0) && ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x5C))) == 6) && (sub_0201B694(arg0) == 1)) {
        sub_0201B6D0(arg0);
    }
}

void sub_0201B7B0(void *arg0) {
    s32 var_r2_7139;

    if ((mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), 0xF) == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
        mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
        var_r2_7139 = 0;
        (*(u8 *)((u8 *)(arg0) + (0x55))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x5A)));
        (*(s8 *)((u8 *)(*(void **)0x03001B40) + (0x397F))) = 0;
        do {
            (*(s32 *)((u8 *)(((var_r2_7139 * 4) + *(void **)0x03001B40)) + (0x14))) = 0;
            var_r2_7139 += 1;
        } while (var_r2_7139 <= 3);
        (*(s8 *)((u8 *)(arg0) + (0x69))) = 1;
        sub_0201C7E0(0);
    }
    (*(u8 *)((u8 *)(arg0) + (0x5A))) = 0U;
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
        if ((sub_0201B6A0(arg0) == 1) && (mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), temp_r0_7180) == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
            mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
            mMsg_ClearText((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
            sub_0201B6D0(arg0);
            return;
        }
    default:
        return;
    case 2:
        if (sub_0201B6AC(arg0) == 1) {
            temp_r0_7232 = mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), temp_r0_7180);
            if ((temp_r0_7232 == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
                mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
                mMsg_ClearText((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
                sub_0201B6D0(arg0);
                (*(s8 *)((u8 *)(arg0) + (0x6D))) = (s8) temp_r0_7232;
                return;
            }
        }
        break;
    case 0:
        if ((mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), temp_r0_7180) == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
            mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
            mMsg_ClearText((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
        }
        break;
    }
}

void sub_0201B90C(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x55))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x5A)));
    (*(u8 *)((u8 *)(arg0) + (0x5A))) = 0U;
}

void sub_0201B91C(void *arg0) {
    mMsg_Window_c *temp_r1_7287;
    s32 temp_r0_7298;

    temp_r1_7287 = (*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)));
    if (mMsg_CheckControlCode(temp_r1_7287->text, 1U, temp_r1_7287->text_offset) != 0) {
        temp_r0_7298 = mMsg_ChangeMsgData((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))), 0x11);
        if ((temp_r0_7298 == 1) && ((mMsg_RequestCursor((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14)))) << 0x18) != 0)) {
            (*(s8 *)((u8 *)(arg0) + (0x55))) = (s8) temp_r0_7298;
            mMsg_MainSetup_Window((*(mMsg_Window_c **)((u8 *)(arg0) + (0x14))));
        }
    }
}

void sub_0201B960(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x55))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x5A)));
    (*(u8 *)((u8 *)(arg0) + (0x5A))) = 0U;
}

void sub_0201B970(void *arg0) {
    if (((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x7C))) == 0) && (sub_0201B6B8(arg0) == 1)) {
        sub_0201B6D0(arg0);
    }
}

void sub_0201B994(void *arg0) {
    s32 *var_r7_7399;
    s32 temp_r0_7404;
    s32 var_r3_7393;
    s8 *var_r2_7359;
    u8 temp_r3_7355;

    temp_r3_7355 = (*(u8 *)((u8 *)(arg0) + (0x69)));
    if (temp_r3_7355 == 0) {
        var_r2_7359 = arg0 + 0x5A;
        *(u32 *)((arg0 + 0x69) - 0x14) = (*(u8 *)((u8 *)(arg0) + (0x5A)));
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
                (*(s32 *)((u8 *)(((var_r3_7393 * 4) + *(s32 *)0x03002970)) + (0x14))) = temp_r0_7404;
                var_r3_7393 += 1;
            } while (var_r3_7393 <= 3);
            (*(u8 *)((u8 *)(arg0) + (0x55))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x5A)));
            (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x03002980;
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

    temp_r0_7450 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x7C)));
    if (temp_r0_7450 == 0) {
        (*(u8 *)((u8 *)(arg0) + (0x55))) = temp_r0_7450;
        temp_r2_7459 = (*(s8 *)((u8 *)(arg0) + (0x5F)));
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
        (*(s8 *)((u8 *)(arg0) + (0x5F))) = 0;
        (*(void **)((u8 *)(arg0) + (0x14))) = (void *) (*(void **)((u8 *)(arg0) + (0x10)));
        sub_0201AB3C(arg0, 4);
        mMsg_CopyTilesToVram(0, 0x90, (*(u8 **)((u8 *)((*(void **)((u8 *)(arg0) + (0x14)))) + (0x50))));
        if ((*(u8 *)((u8 *)(arg0) + (0x6D))) == 1) {
            (*(u8 *)((u8 *)(arg0) + (0x55))) = 6U;
            sub_02019B1C(&gGameState, 0x80U, 0x3FU, 0U);
            gGameState.unk_82A &= 0xFEFF;
            sub_02019D98(0x14U);
            (*(u8 *)((u8 *)(arg0) + (0x6D))) = 0U;
        }
        (*(s8 *)((u8 *)(arg0) + (0x69))) = 0;
        (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
        *gIntrTable = (u32) JoybootHandler;
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
    (*(s8 *)((u8 *)(arg0) + (0x57))) = arg1;
    return 1;
}

s32 sub_0201BB4C(void *arg0) {
    return sub_0201BB44(arg0, 1);
}

s32 sub_0201BB58(void *arg0) {
    return sub_0201BB44(arg0, 2);
}

s32 sub_0201BB64(void *arg0) {
    return sub_0201BB44(arg0, 4);
}

s32 sub_0201BB70(void *arg0) {
    return sub_0201BB44(arg0, 3);
}

s32 sub_0201BB7C(void *arg0) {
    return sub_0201BB44(arg0, 5);
}

void sub_0201BB88(void *arg0) {
    s32 (*temp_r1_7625)(void *);

    if ((u32) (*(u8 *)((u8 *)(arg0) + (0x57))) <= 5U) {
        temp_r1_7625 = *(u32 *)(0x0202B2BC + ((s8) (*(u8 *)((u8 *)(arg0) + (0x57))) * 4));
        if (temp_r1_7625 != NULL) {
            temp_r1_7625(arg0);
        }
    }
}

void sub_0201BBB4(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x57)));
    (*(u8 *)((u8 *)(arg0) + (0x57))) = 0U;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
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
                var_r0_7699 = (*(s32 *)((u8 *)(&gGameState) + (0x84C))) & 0xFF00FF;
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
        (*(s8 *)((u8 *)(arg0) + (0x72))) = 1;
    }
}

void sub_0201BCA4(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x57)));
    (*(u8 *)((u8 *)(arg0) + (0x57))) = 0U;
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
    (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x57)));
    (*(u8 *)((u8 *)(arg0) + (0x57))) = 0U;
    sub_02019D98(0x14U);
}

void sub_0201BDC4(void *arg0) {
    if ((sub_0201D800(1U) == 1) && ((s32) sub_0201BB58(arg0) == 1)) {
        sub_0201BB88(arg0);
    }
}

void sub_0201BDE8(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x57)));
    (*(u8 *)((u8 *)(arg0) + (0x57))) = 0U;
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
        (*(u8 *)((u8 *)(arg0) + (0x52))) = temp_r0_7954;
        gGameState.unk_85A = temp_r0_7954;
    }
}

void sub_0201BE68(void *arg0) {
    if (mMsg_RequestAppear((mMsg_Window_c *)0x03002FC0, 0x1A) == 1) {
        sub_0201A854(arg0, 1);
        sub_0201AA98(arg0, 1U);
        (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x57)));
        (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x03002FC0;
    }
    (*(u8 *)((u8 *)(arg0) + (0x57))) = 0U;
}

void sub_0201BEB0(void *arg0) {
    s8 *var_r1_8020;
    void *temp_r1_8013;

    temp_r1_8013 = (*(void **)((u8 *)(arg0) + (0x14)));
    if ((*(u8 *)((u8 *)(temp_r1_8013) + (0x7C))) == 0) {
        var_r1_8020 = arg0 + 0x52;
        goto block_7;
    }
    if (((u32) (u8) ((*(u8 *)((u8 *)(temp_r1_8013) + (0x70))) - 3) <= 2U) && ((*(s8 *)((u8 *)(temp_r1_8013) + (0x77))) == -1) && ((gGameState.unk_856 != 0) || (gGameState.unk_84E != 0))) {
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
    if ((*(u8 *)((u8 *)(*(void **)0x03001B40) + (0x193A))) != 0) {
        gGameState.unk_83C = ((u16) gGameState.unk_844 >> 1) + *(u8 *)0x03003243;
        gGameState.unk_83E -= 4;
        *(u8 *)0x03003243 += 1;
    }
    sub_0201ABBC((void *)0x030031D0);
    if ((s8) *(u32 *)0x03003223 != 0) {
        ((void (*)(void *))*(u32 *)(0x0202AFDC + ((s8) *(u32 *)0x03003223 * 4)))((void *)0x030031D0);
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
    } else if ((s8) *(u32 *)0x03003225 != 0) {
        ((void (*)(void *))*(u32 *)(0x0202B2A0 + ((s8) *(u32 *)0x03003225 * 4)))((void *)0x030031D0);
        var_r8_8104 = 0;
    } else if (*(s8 *)0x03003224 != 0) {
        temp_r2_8238 = *(u32 *)0x03003242;
        if (temp_r2_8238 == 0) {
            if (*(u8 *)0x03003237 == 0) {
                ((void (*)(void *))*(u32 *)(0x0202AFFC + (*(s8 *)0x03003224 * 4)))((void *)0x030031D0);
            } else {
                temp_r0_8259 = (*(void **)((u8 *)((void *)0x030031D0) + (0x14)));
                if ((temp_r0_8259 == NULL) || ((*(u8 *)((u8 *)(temp_r0_8259) + (0x7C))) == 1)) {
                    *(u8 *)0x03003237 = temp_r2_8238;
                }
            }
        }
        if (*(u32 *)0x03003242 == 1) {
            sub_0201C1C4((void *)0x030031D0, 3U, 1U, 1U, 0);
        }
    } else {
        temp_r2_8284 = (*(s8 *)((u8 *)((void *)0x030031D0) + (0x52)));
        if (temp_r2_8284 != 0) {
            if ((temp_r2_8284 == 1) && (*(u16 *)0x0203E9A0 == 0) && (2 & gGameState.keys_pressed)) {
                gGameState.unk_84C = (u8) temp_r2_8284;
            }
            gGameState.unk_84E = sub_0201A7C8(0x030031D0);
            temp_r1_8313 = (*(u8 *)((u8 *)((void *)0x030031D0) + (0x72)));
            if (temp_r1_8313 == 0) {
                if ((*(u8 *)((u8 *)((void *)0x030031D0) + (0x65))) == 0) {
                    ((void (*)(void))*(u32 *)(0x0202B2D4 + ((s8) *(u32 *)0x03003222 * 4)))();
                } else {
                    temp_r0_8343 = (*(void **)((u8 *)((void *)0x030031D0) + (0x14)));
                    if ((temp_r0_8343 == NULL) || ((*(u8 *)((u8 *)(temp_r0_8343) + (0x7C))) == 1)) {
                        (*(u8 *)((u8 *)((void *)0x030031D0) + (0x65))) = temp_r1_8313;
                        (*(s16 *)((u8 *)((void *)0x030031D0) + (0x2C))) = (s16) temp_r1_8313;
                    }
                }
            }
            temp_r0_8354 = (*(u8 *)((u8 *)((void *)0x030031D0) + (0x72)));
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
    return (u16) ((s32) (*(s32 *)((u8 *)((void *)0x030031D0) + (0x18))) / 1000);
}

s32 sub_0201C1B8(void) {
    return sub_0201C8C0();
}

void sub_0201C1C4(void *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 temp_r0_8422;
    u8 temp_r7_8419;

    temp_r7_8419 = arg1;
    temp_r0_8422 = sub_0201A714(arg0, (s8) arg1);
    if (temp_r0_8422 == 1) {
        if ((arg2 != 0) && (gGameState.unk_856 != 0)) {
            sub_0201ADE8(arg0);
            (*(s8 *)((u8 *)(arg0) + (0x72))) = 0;
            *(u32 *)((arg0 + 0x72) - 0x15) = temp_r7_8419;
            (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
            sub_0201AE0C(arg0);
            gGameState.unk_857 = temp_r0_8422;
            goto block_7;
        }
        if ((arg3 != 0) && (gGameState.unk_84C != 0)) {
            sub_0201B688(arg0);
            (*(s8 *)((u8 *)(arg0) + (0x72))) = 0;
            *(u32 *)((arg0 + 0x72) - 0x13) = temp_r7_8419;
            (*(s32 *)((u8 *)(arg0) + (0x10))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
            sub_0201B6D0(arg0);
            gGameState.unk_84D = 1;
block_7:
            gGameState.unk_84E = 0;
            gGameState.unk_84F = 0;
            return;
        }
        if (((u8) arg4 != 0) && (gGameState.unk_84E != 0)) {
            sub_0201B194(arg0);
            (*(s8 *)((u8 *)(arg0) + (0x72))) = 0;
            (*(u8 *)((u8 *)(arg0) + (0x5E))) = temp_r7_8419;
            (*(s32 *)((u8 *)(arg0) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x14)));
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
    s32 (*temp_r1_8632)(m_msg_sprite_c *);
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
        temp_r5_8586 = *(u32 *)(0x0202B2FC + (temp_r0_8574 * 4));
        sp0 = 0;
        temp_r4_8590 = temp_r0_8578 * 0x60;
        temp_r7_8592 = temp_r4_8590 + 0x03003250;
        CpuFastSet(&sp0, temp_r7_8592, 0x01000018U);
        *(u32 *)(0x03003250 + temp_r4_8590) = (s32 (*)(m_msg_sprite_c *)) (*(s32 (**)(m_msg_sprite_c *))((u8 *)(temp_r5_8586) + (0)));
        *(u32 *)(0x03003254 + temp_r4_8590) = (s32) (*(s32 *)((u8 *)(temp_r5_8586) + (4)));
        *(u32 *)(0x03003258 + temp_r4_8590) = (s32) (*(s32 *)((u8 *)(temp_r5_8586) + (8)));
        *(u32 *)(0x0300325C + temp_r4_8590) = (s32) (*(s32 *)((u8 *)(temp_r5_8586) + (0xC)));
        temp_r7_8592->_57 = temp_r0_8574;
        *(u32 *)(0x0300327C + temp_r4_8590) = x;
        *(u32 *)(0x03003280 + temp_r4_8590) = y;
        *(u32 *)(0x03003264 + temp_r4_8590) = sp4;
        temp_r1_8632 = *(u32 *)(0x03003250 + temp_r4_8590);
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
    if (((*(s16 *)((u8 *)(arg0) + (0x34))) == 0) && ((*(s32 *)((u8 *)((((*(s16 *)((u8 *)(arg0) + (0x36))) * 8) + *(u32 *)(((*(s16 *)((u8 *)(arg0) + (0x38))) * 4) + arg1))) + (8))) == 0)) {
        var_r3_8689 = 1;
    }
    return var_r3_8689;
}

void sub_0201C428(void *arg0, s32 arg1, s16 arg2) {
    (*(s16 *)((u8 *)(arg0) + (0x38))) = arg2;
    (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) (*(u16 *)((u8 *)(*(u32 *)(((*(s16 *)((u8 *)(arg0) + (0x38))) * 4) + arg1)) + (4)));
    (*(s16 *)((u8 *)(arg0) + (0x36))) = 0;
}

void sub_0201C444(void *arg0, s32 arg1) {
    s32 temp_r1_8748;
    s32 temp_r3_8738;
    u8 var_r0_8751;
    void *temp_r0_8747;

    temp_r3_8738 = *(u32 *)(((*(s16 *)((u8 *)(arg0) + (0x38))) * 4) + arg1);
    if ((s32) ((*(s16 *)((u8 *)(arg0) + (0x34))) - 1) <= 0) {
        temp_r0_8747 = ((*(s16 *)((u8 *)(arg0) + (0x36))) * 8) + temp_r3_8738;
        temp_r1_8748 = (*(s32 *)((u8 *)(temp_r0_8747) + (8)));
        if (temp_r1_8748 == 0) {
            var_r0_8751 = (*(u8 *)((u8 *)(temp_r0_8747) + (6)));
            if (var_r0_8751 != 0) {
                (*(s16 *)((u8 *)(arg0) + (0x36))) = (s16) temp_r1_8748;
                goto block_5;
            }
        } else {
            (*(s16 *)((u8 *)(arg0) + (0x36))) = (s16) ((u16) (*(s16 *)((u8 *)(arg0) + (0x36))) + 1);
block_5:
            var_r0_8751 = (u8) (*(u16 *)((u8 *)((((*(s16 *)((u8 *)(arg0) + (0x36))) * 8) + temp_r3_8738)) + (4)));
        }
    } else {
        var_r0_8751 = (u16) (*(s16 *)((u8 *)(arg0) + (0x34))) - 1;
    }
    (*(s16 *)((u8 *)(arg0) + (0x34))) = (s16) var_r0_8751;
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

    (*(s8 *)((u8 *)(arg2) + (0))) = (s8) ((*(s32 *)((u8 *)(arg0) + (0x24))) + ((*(u8 *)((u8 *)(arg1) + (0))) + (*(s32 *)((u8 *)(arg0) + (0x30)))));
    temp_r4_8794 = (-4 & (*(u8 *)((u8 *)(arg2) + (1)))) | ((u32) ((*(u8 *)((u8 *)(arg1) + (1))) << 0x1E) >> 0x1E);
    (*(u8 *)((u8 *)(arg2) + (1))) = temp_r4_8794;
    temp_r5_8803 = (-0xD & temp_r4_8794) | (0xC & (*(u8 *)((u8 *)(arg1) + (1))));
    (*(u8 *)((u8 *)(arg2) + (1))) = temp_r5_8803;
    temp_r6_8813 = (-0x11 & temp_r5_8803) | (0x10 & (*(u8 *)((u8 *)(arg1) + (1))));
    (*(u8 *)((u8 *)(arg2) + (1))) = temp_r6_8813;
    temp_r3_8822 = (-0x21 & temp_r6_8813) | (0x20 & (*(u8 *)((u8 *)(arg1) + (1))));
    (*(u8 *)((u8 *)(arg2) + (1))) = temp_r3_8822;
    (*(u8 *)((u8 *)(arg2) + (1))) = (u8) ((temp_r3_8822 & 0x3F) | (((u8) (*(u8 *)((u8 *)(arg1) + (1))) >> 6) << 6));
    (*(u16 *)((u8 *)(arg2) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(arg2) + (2)))) | ((((u32) ((*(u16 *)((u8 *)(arg1) + (2))) << 0x17) >> 0x17) + (*(s32 *)((u8 *)(arg0) + (0x2C))) + (*(s32 *)((u8 *)(arg0) + (0x20)))) & 0x1FF));
    temp_r3_8853 = (-0xF & (*(u8 *)((u8 *)(arg2) + (3)))) | (0xE & (*(u8 *)((u8 *)(arg1) + (3))));
    (*(u8 *)((u8 *)(arg2) + (3))) = temp_r3_8853;
    temp_r4_8860 = (-0x11 & temp_r3_8853) | (0x10 & (*(u8 *)((u8 *)(arg1) + (3))));
    (*(u8 *)((u8 *)(arg2) + (3))) = temp_r4_8860;
    temp_r5_8866 = (-0x21 & temp_r4_8860) | (0x20 & (*(u8 *)((u8 *)(arg1) + (3))));
    (*(u8 *)((u8 *)(arg2) + (3))) = temp_r5_8866;
    (*(u8 *)((u8 *)(arg2) + (3))) = (u8) ((temp_r5_8866 & 0x3F) | (((u8) (*(u8 *)((u8 *)(arg1) + (3))) >> 6) << 6));
    (*(u16 *)((u8 *)(arg2) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(arg2) + (4)))) | ((u32) ((*(u16 *)((u8 *)(arg1) + (4))) << 0x16) >> 0x16));
    temp_r5_8888 = (-0xD & (*(u8 *)((u8 *)(arg2) + (5)))) | (0xC & (*(u8 *)((u8 *)(arg1) + (5))));
    (*(u8 *)((u8 *)(arg2) + (5))) = temp_r5_8888;
    (*(u8 *)((u8 *)(arg2) + (5))) = (u8) ((temp_r5_8888 & 0xF) | (((u8) (*(u8 *)((u8 *)(arg1) + (5))) >> 4) * 0x10));
    (*(u16 *)((u8 *)(arg2) + (6))) = (u16) (*(u16 *)((u8 *)(arg1) + (6)));
}

void sub_0201C5A0(void) {
    s32 (*temp_r1_8924)(void *);
    s32 (*temp_r1_8944)(void *);
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
            temp_r1_8924 = (*(s32 (**)(void *))((u8 *)(var_r4_8918) + (8)));
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
            temp_r1_8944 = (*(s32 (**)(void *))((u8 *)(var_r4_8938) + (0xC)));
            if (temp_r1_8944 != NULL) {
                temp_r1_8944(var_r4_8938);
            }
        }
        var_r6_8937 += 0x60;
        var_r4_8938 += 0x60;
        var_r5_8939 -= 1;
    } while (var_r5_8939 >= 0);
}

void sub_0201C5F8(void *arg0) {

}

void sub_0201C5FC(s32 arg0) {
    u8 red[8];
    u8 green[8];
    u8 blue[8];

    memcpy(red, (void *)0x0202B37C, sizeof(red));
    memcpy(green, (void *)0x0202B384, sizeof(green));
    memcpy(blue, (void *)0x0202B38C, sizeof(blue));
    sub_02019BD8(1U, 7U, 6U, red[arg0], green[arg0], blue[arg0]);
    CpuFastSet((void *)0x020002E0, (void *)0x050002E0, 8U);
}

void sub_0201C668(void *arg0) {
    s32 temp_r0_9026;

    sub_0201C5FC(((*(s32 *)((u8 *)(arg0) + (0x18))) & 3) + ((*(s32 *)((u8 *)(arg0) + (0x14))) * 4));
    temp_r0_9026 = (*(s32 *)((u8 *)(arg0) + (0x1C))) + 1;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = temp_r0_9026;
    if (temp_r0_9026 > 0xA) {
        (*(s32 *)((u8 *)(arg0) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x18))) + 1);
        (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    }
    sub_0201C5F8(arg0);
}

void sub_0201C69C(void *arg0) {
    sub_0201C428(arg0, 0x0202B378, 0);
    sub_0201C5F8(arg0);
    (*(void (**)(void *))((u8 *)(arg0) + (0x10))) = sub_0201C668;
    sub_0201C668(arg0);
}

void sub_0201C6C8(void) {

}

void sub_0201C6CC(void *arg0) {
    s32 (*temp_r1_9071)();

    temp_r1_9071 = (*(s32 (**)())((u8 *)(arg0) + (0x10)));
    if (temp_r1_9071 != NULL) {
        temp_r1_9071();
    }
    sub_0201C444(arg0, 0x0202B378);
}

void sub_0201C6EC(void *arg0) {
    void *var_r4_9095;

    var_r4_9095 = **(u32 **)(0x0202B378 + ((*(s16 *)((u8 *)(arg0) + (0x38))) * 4));
    if ((*(u16 *)((u8 *)(var_r4_9095) + (6))) != 0xFFFF) {
        do {
            sub_0201C490(arg0, var_r4_9095, (*(u8 *)0x030023B0 * 8) + gUnk3002410);
            *(u8 *)0x030023B0 += 1;
            var_r4_9095 += 8;
        } while ((*(u16 *)((u8 *)(var_r4_9095) + (6))) != 0xFFFF);
    }
}

void sub_0201C740(void *arg0) {

}

void sub_0201C744(void *arg0) {
    sub_0201C428(arg0, 0x0202B3DC, 0);
    (*(void (**)(void *))((u8 *)(arg0) + (0x10))) = sub_0201C740;
    sub_0201C740(arg0);
}

void sub_0201C768(void) {

}

void sub_0201C76C(void *arg0) {
    s32 (*temp_r1_9159)();

    temp_r1_9159 = (*(s32 (**)())((u8 *)(arg0) + (0x10)));
    if (temp_r1_9159 != NULL) {
        temp_r1_9159();
    }
    sub_0201C444(arg0, 0x0202B3DC);
}

void sub_0201C78C(void *arg0) {
    void *var_r4_9183;

    var_r4_9183 = **(u32 **)(0x0202B3DC + ((*(s16 *)((u8 *)(arg0) + (0x38))) * 4));
    if ((*(u16 *)((u8 *)(var_r4_9183) + (6))) != 0xFFFF) {
        do {
            sub_0201C490(arg0, var_r4_9183, (*(u8 *)0x030023B0 * 8) + gUnk3002410);
            *(u8 *)0x030023B0 += 1;
            var_r4_9183 += 8;
        } while ((*(u16 *)((u8 *)(var_r4_9183) + (6))) != 0xFFFF);
    }
}

void sub_0201C7E0(s32 arg0) {
    s32 sp0;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    *(s16 *)0x04000134 = 0;
    *(s32 *)0x04000128 = 0x2000;
    *(s32 *)0x04000128 = (s16) ((u16) *(s32 *)0x04000128 | 0x4003);
    sp0 = 0;
    CpuSet(&sp0, (void *)0x030036D0, 0x0500000EU);
    (*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) = -1;
    (*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) = -1;
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

void sub_0201C870(void) {
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    *(s16 *)0x04000134 = 0;
    *(s16 *)0x04000128 = 0x2003;
    (*(s32 *)((u8 *)((void *)0x0400010C) + (0))) = 0xA4FB;
    (*(s16 *)((u8 *)((void *)0x0400010C) + (0xF6))) = 0xC0;
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

    temp_r2_9322 = (*(s32 *)((u8 *)((void *)0x04000128) + (0)));
    var_r7_9324 = -1;
    temp_r0_9327 = (*(u8 *)((u8 *)((void *)0x030036D0) + (1)));
    switch (temp_r0_9327) {                         /* irregular */
    case 3:
        temp_r5_9525 = (*(s32 *)((u8 *)((void *)0x030036D0) + (0x14)));
        var_r4_9526 = temp_r5_9525;
        if (((*(u8 *)((u8 *)((void *)0x030036D0) + (0x32))) != 0) || ((s32) (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) > 1) || ((*(u8 *)((u8 *)((void *)0x030036D0) + (0x31))) != 0)) {
            var_r7_9324 = 0xA;
        } else {
            if (temp_r5_9525 > 0x1CC0) {
                var_r4_9526 = 0x1CC0;
            } else if (temp_r5_9525 < 0) {
                var_r4_9526 = 0;
            }
            if ((s32) (*(s16 *)((u8 *)((void *)0x030036D0) + (0x2E))) < var_r4_9526) {
                do {
                    temp_r0_9562 = (u16) (*(s16 *)((u8 *)((void *)0x030036D0) + (0x2E)));
                    (*(s16 *)((u8 *)((void *)0x030036D0) + (0x2E))) = (s16) (temp_r0_9562 + 1);
                    (*(u16 *)((u8 *)((void *)0x030036D0) + (0x2C))) = (u16) (*(u32 *)(((s32) (temp_r0_9562 << 0x10) >> 0xF) + (*(s32 *)((u8 *)((void *)0x030036D0) + (0xC)))) + (*(u16 *)((u8 *)((void *)0x030036D0) + (0x2C))));
                } while ((s32) (*(s16 *)((u8 *)((void *)0x030036D0) + (0x2E))) < var_r4_9526);
                (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) = 0;
            }
            if (temp_r5_9525 > 0x1CC0) {
                if ((s16) ((*(u16 *)((u8 *)((void *)0x030036D0) + (0x2C))) + (*(u16 *)((u8 *)((void *)0x030036D0) + (0x24)))) == -1) {
                    (*(s8 *)((u8 *)((void *)0x030036D0) + (3))) = 1;
                } else {
                    (*(s8 *)((u8 *)((void *)0x030036D0) + (4))) = 1;
                }
                (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) = 0;
                (*(u8 *)((u8 *)((void *)0x030036D0) + (1))) = 4U;
            }
        }
        break;
    case 4:
        temp_r0_9612 = (s8) (*(u8 *)((u8 *)((void *)0x030036D0) + (0x30)));
        if (temp_r0_9612 == 1) {
            var_r7_9324 = 9;
        } else if ((temp_r0_9612 == -1) || ((*(u8 *)((u8 *)((void *)0x030036D0) + (0x32))) != 0) || ((s32) (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) > 6)) {
            var_r7_9324 = 0xA;
        }
        if (var_r7_9324 != -1) {
            (*(u8 *)((u8 *)((void *)0x030036D0) + (1))) = 5U;
        }
        break;
    case 0:
        if ((s32) (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) > 0x258) {
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
                    REG_IE &= 0xFF7F;
                    REG_IE |= 0x40;
                    REG_IME = 1;
                    (*(u8 *)((u8 *)((void *)0x04000128) + (1))) = (u8) (-0x41 & (*(u8 *)((u8 *)((void *)0x04000128) + (1))));
                    *(s16 *)0x04000202 = 0xC0;
                    *(s32 *)0x0400010C = 0xA4FB;
                    (*(u8 *)((u8 *)((void *)0x030036D0) + (0))) = temp_r4_9368;
                    (*(s32 *)((u8 *)((void *)0x04000128) + (0))) = (s8) ((u8) (*(s32 *)((u8 *)((void *)0x04000128) + (0))) | 0x80);
                }
                var_r1_9411 = *(u16 **)0x03001B40;
                (*(u16 **)((u8 *)((void *)0x030036D0) + (8))) = var_r1_9411;
                (*(s32 *)((u8 *)((void *)0x030036D0) + (0xC))) = (s32) *(s32 *)0x03002970;
                var_r3_9417 = 0;
                var_r2_9419 = 0x1CC0;
                do {
                    var_r3_9417 += *var_r1_9411;
                    var_r1_9411 += 2;
                    var_r2_9419 -= 1;
                } while (var_r2_9419 != 0);
                (*(u16 *)((u8 *)((void *)0x030036D0) + (0x2A))) = (u16) ~var_r3_9417;
                if ((*(u8 *)((u8 *)((void *)0x030036D0) + (0))) != 0) {
                    *(s16 *)0x0400010E = 0xC0;
                }
                (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) = var_r2_9419;
                (*(u8 *)((u8 *)((void *)0x030036D0) + (1))) = 2U;
            }
        }
        break;
    case 2:
        temp_r3_9456 = (*(u8 *)((u8 *)((void *)0x030036D0) + (0x32)));
        if (temp_r3_9456 == 0) {
            temp_r1_9460 = (*(u8 *)((u8 *)((void *)0x030036D0) + (2)));
            if ((1 & temp_r1_9460) && (0xE & temp_r1_9460)) {
                var_r7_9324 = 8;
                if ((u32) ((u32) (temp_r2_9322 << 0x1A) >> 0x1E) > 1U) {

                } else {
                    var_r7_9324 = 7;
                    (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) = (s32) temp_r3_9456;
                    (*(u8 *)((u8 *)((void *)0x030036D0) + (1))) = 3U;
                    sub_02019D58(0x29U);
                }
            } else if ((s32) (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) > 0x258) {
                var_r7_9324 = 0x10;
            } else if (!(((s32) (*(u8 *)((u8 *)((void *)0x030036D0) + (2))) >> ((u32) (temp_r2_9322 << 0x1A) >> 0x1E)) & 1)) {
                temp_r0_9506 = (*(u8 *)((u8 *)((void *)0x030036D0) + (0x33)));
                if ((u32) temp_r0_9506 <= 7U) {
                    (*(u8 *)((u8 *)((void *)0x030036D0) + (0x33))) = (u8) (temp_r0_9506 + 1);
                } else {
                    (*(s8 *)((u8 *)((void *)0x030036D0) + (0x34))) = 1;
                }
            } else {
                (*(u8 *)((u8 *)((void *)0x030036D0) + (0x33))) = 0U;
            }
        } else {
            goto block_12;
        }
        break;
    }
    (*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x20))) + 1);
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
    u16 *var_r2_9691;
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

    sp0 = (*(s32 *)((u8 *)((void *)0x04000120) + (0)));
    sp4 = (*(s32 *)((u8 *)((void *)0x04000120) + (4)));
    temp_r1_9678 = (*(s32 *)((u8 *)((void *)0x04000128) + (0)));
    *(s8 *)0x03003702 = (s8) ((u32) (temp_r1_9678 << 0x19) >> 0x1F);
    temp_r3_9684 = (*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C)));
    if (temp_r3_9684 < 0) {
        var_r3_9688 = 0;
        var_r2_9691 = (u16 *)&sp0;
        do {
            if (*var_r2_9691 == 0xFEFE) {
                (*(u8 *)((u8 *)((void *)0x030036D0) + (2))) = (u8) ((1 << var_r3_9688) | (*(u8 *)((u8 *)((void *)0x030036D0) + (2))));
            }
            var_r2_9691 += 1;
            var_r3_9688 += 1;
        } while (var_r3_9688 <= 3);
        if ((3 & (*(u8 *)((u8 *)((void *)0x030036D0) + (2)))) != 3) {

        } else {
            (*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) + 1);
            (*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) + 1);
            (*(u16 *)((u8 *)((void *)0x030036D0) + (0x28))) = 0U;
            (*(u16 *)((u8 *)((void *)0x030036D0) + (0x26))) = 0U;
        }
    } else if (temp_r3_9684 <= 0x1DAD) {
        temp_r4_9735 = temp_r1_9678 << 0x1A;
        temp_r1_9744 = *(u16 *)((u8 *)&sp0 + (((temp_r4_9735 >> 0x1E) ^ 1) * 2)) + (*(u16 *)((u8 *)((void *)0x030036D0) + (0x26)));
        (*(u16 *)((u8 *)((void *)0x030036D0) + (0x26))) = temp_r1_9744;
        if ((temp_r3_9684 & 0x1F) == 0x1F) {
            if ((s16) temp_r1_9744 != -1) {
                (*(u8 *)((u8 *)((void *)0x030036D0) + (0x31))) = (u8) ((*(u8 *)((u8 *)((void *)0x030036D0) + (0x31))) | 1);
            }
            (*(u16 *)((u8 *)((void *)0x030036D0) + (0x26))) = 0U;
        } else {
            temp_r2_9772 = (*(s32 *)((u8 *)((void *)0x030036D0) + (0x14)));
            if (temp_r2_9772 <= 0x1CBF) {
                *(u16 *)((temp_r2_9772 * 2) + (*(s32 *)((u8 *)((void *)0x030036D0) + (0xC)))) = *(u16 *)((u8 *)&sp0 + (((temp_r4_9735 >> 0x1E) ^ 1) * 2));
                (*(s32 *)((u8 *)((void *)0x030036D0) + (0x14))) = (s32) (temp_r2_9772 + 1);
            }
        }
        (*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) + 1);
    } else if (temp_r3_9684 == 0x1DAE) {
        (*(u16 *)((u8 *)((void *)0x030036D0) + (0x24))) = *(u16 *)((u8 *)&sp0 + ((1 ^ ((u32) (temp_r1_9678 << 0x1A) >> 0x1E)) * 2));
        (*(s32 *)((u8 *)((void *)0x030036D0) + (0x1C))) = (s32) (temp_r3_9684 + 1);
        (*(s32 *)((u8 *)((void *)0x030036D0) + (0x14))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x14))) + 1);
    } else {
        temp_r1_9818 = (*(u16 *)((u8 *)(&sp0) + (0)));
        if ((u32) (u16) (temp_r1_9818 + 0x104) <= 1U) {
            temp_r2_9828 = (*(u16 *)((u8 *)(&sp0) + (2)));
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
    temp_r2_9853 = (*(s32 *)((u8 *)((void *)0x030036D0) + (0x18)));
    if (temp_r2_9853 < 0) {
        if ((*(u8 *)((u8 *)((void *)0x030036D0) + (0x34))) != 0) {
            (*(u16 *)((u8 *)((void *)0x04000128) + (2))) = 0xFEFEU;
        }
        (*(u16 *)((u8 *)((void *)0x030036D0) + (0x28))) = 0U;
    } else if (temp_r2_9853 <= 0x1DAD) {
        if ((temp_r2_9853 & 0x1F) == 0x1F) {
            (*(u16 *)((u8 *)((void *)0x04000128) + (2))) = (u16) ~(*(u16 *)((u8 *)((void *)0x030036D0) + (0x28)));
            (*(u16 *)((u8 *)((void *)0x030036D0) + (0x28))) = 0U;
        } else {
            temp_r2_9895 = (*(s32 *)((u8 *)((void *)0x030036D0) + (0x10)));
            temp_r0_9898 = (temp_r2_9895 * 2) + (*(s32 *)((u8 *)((void *)0x030036D0) + (8)));
            (*(u16 *)((u8 *)((void *)0x04000128) + (2))) = (u16) *temp_r0_9898;
            (*(u16 *)((u8 *)((void *)0x030036D0) + (0x28))) = (u16) (*temp_r0_9898 + (*(u16 *)((u8 *)((void *)0x030036D0) + (0x28))));
            (*(s32 *)((u8 *)((void *)0x030036D0) + (0x10))) = (s32) (temp_r2_9895 + 1);
        }
        (*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) = (s32) ((*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) + 1);
    } else if (temp_r2_9853 == 0x1DAE) {
        (*(u16 *)((u8 *)((void *)0x04000128) + (2))) = (u16) (*(u16 *)((u8 *)((void *)0x030036D0) + (0x2A)));
        (*(s32 *)((u8 *)((void *)0x030036D0) + (0x18))) = (s32) (temp_r2_9853 + 1);
    } else if ((temp_r2_9853 > 0x1DAE) && ((temp_r2_9933 = (*(u8 *)((u8 *)((void *)0x030036D0) + (3))), (temp_r2_9933 != 0)) || ((*(u8 *)((u8 *)((void *)0x030036D0) + (4))) != 0))) {
        var_r1_9941 = 0xFEFC;
        if (temp_r2_9933 != 0) {
            var_r1_9941 = 0xFEFD;
        }
        (*(u16 *)((u8 *)((void *)0x04000128) + (2))) = var_r1_9941;
    }
    if ((*(u8 *)((u8 *)((void *)0x030036D0) + (0))) == 8) {
        *(s16 *)0x0400010E = 0;
        (*(s32 *)((u8 *)((void *)0x04000128) + (0))) = (s16) ((u16) (*(s32 *)((u8 *)((void *)0x04000128) + (0))) | 0x80);
        *(s16 *)0x0400010E = 0xC0;
    }
}

s32 sub_0201CDA0(u16 arg0, s32 arg1, u8 arg2) {
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
                *(u32 *)(((0xFF0 & temp_r1_10000) * 8) + 0x0600C000 + ((0xF & temp_r1_10000) * 4) + ((var_r2_10011 & 0xFF8) * 8) + ((var_r2_10011 & 7) * 2)) = temp_r3_10021;
            }
            var_r5_10018 += 2;
            var_r2_10011 += 1;
        } while (var_r2_10011 <= 0x3F);
        var_r3_10039 = NULL;
        do {
            *(u32 *)(0x03003720 + ((u32) ((sp0 + *(u32 *)(0x0202FCFC + (s32) var_r3_10039)) << 0x18) >> 0x17)) = 0x1F;
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
                *(u32 *)(var_r4_10082 + ((0xF & temp_r1_10073) * 4) + ((var_r2_10098 & 0xFF8) * 8) + ((var_r2_10098 & 7) * 2)) = temp_r3_10105;
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

void sub_0201CF3C(u16 arg0, s32 arg1, u8 arg2) {
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
    u16 *var_r4_10302;
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
            *(u32 *)0x03003B24 = (u16) *(u32 *)(0x03003720 + (temp_r3_10243 * 2));
        } else {
            var_r4_10252 = 0x0600C800;
            *(u16 *)0x03003B24 = *(u32 *)(0x03003920 + (temp_r3_10243 * 2));
            var_sl_10202 = 1;
        }
        temp_r4_10287 = var_r4_10252 + ((0xFF0 & temp_r3_10243) * 8) + ((temp_r3_10243 & 0xF) * 4);
        temp_r2_10292 = *(u32 *)(0x0202FD16 + ((temp_r7_10196 - 5) * 2));
        if (*(u32 *)0x03003B24 == 0xFFF) {
            (*(u16 *)((u8 *)(temp_r4_10287) + (0x42))) = temp_r2_10292;
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
            var_r4_10302 += 1;
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
            (*(s16 *)((u8 *)(temp_r1_10403) + (0))) = 0x22AC;
            temp_r1_10426 = temp_r1_10403 + 2;
            (*(s16 *)((u8 *)(temp_r1_10403) + (2))) = 0x22AD;
            (*(s16 *)((u8 *)(temp_r1_10426) + (0x3E))) = 0x22AE;
            (*(s16 *)((u8 *)((temp_r1_10426 + 0x3E)) + (2))) = 0x22AF;
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
    temp_r1_10553 = 0x8000 & Item_GetTypeIndex(*(u32 *)(*(s32 *)0x03001B40 + 0x24 + temp_r5_10546));
    sp0 = var_r8_10533 + 1;
    if (temp_r1_10553 != 0) {

    } else {
        temp_r0_10567 = Item_GetTypeIndex(*(u32 *)(*(u32 *)0x03001B40 + 0x24 + temp_r5_10546));
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
                *(u32 *)(sp4 + temp_r1_10604) = (s16) temp_r0_10567;
                var_r7_10586 = temp_r1_10604;
            }
            if (*(u32 *)(0x0202F7FC + temp_r0_10575) == 0x270) {
                temp_r5_10617 = *(u32 *)0x03001B40;
                temp_r4_10620 = temp_r4_10542 & 0xF;
                temp_r3_10624 = temp_r5_10617 + 0x18F8 + (temp_r4_10620 * 2);
                temp_r2_10627 = var_r8_10533 & 0xF;
                *temp_r3_10624 |= 1 << temp_r2_10627;
                *(u32 *)(temp_r5_10617 + 0x24 + ((temp_r2_10627 * 2) + (temp_r4_10620 << 5))) = 0x2512;
                *(u32 *)(sp4 + var_r7_10586) = 0x10;
            }
            sp0 = var_r8_10533 + 1;
            if (temp_r0_10567 != 0x57) {
                temp_r0_10654 = sub_0201CDA0(*(u32 *)(0x0202F7FC + temp_r0_10575), var_r8_10533, 0U);
                if (temp_r0_10654 == 1) {
                    *(u16 *)0x03003B24 = *(u32 *)(0x0202F7FC + temp_r0_10575);
                    if (((s32) *(u32 *)(*(u32 *)0x03001B40 + 0x18F8 + ((temp_r4_10542 & 0xF) * 2)) >> (var_r8_10533 & 0xF)) & temp_r0_10654) {
                        *(u16 *)0x03003B24 = 0x1270;
                    }
                    var_r4_10683 = 0;
                    *(u32 *)0x03003B22 = 0U;
                    do {
                        temp_r2_10704 = var_r4_10683 + 0x0600C000 + ((0xFF0 & var_r8_10533) * 8) + ((0xF & var_r8_10533) * 4);
                        (*(s16 *)((u8 *)(temp_r2_10704) + (0))) = (s16) (*(u32 *)0x03003B22 + *(u16 *)0x03003B24);
                        (*(s16 *)((u8 *)(temp_r2_10704) + (2))) = (s16) (*(u32 *)0x03003B22 + *(u16 *)0x03003B24 + 1);
                        var_r4_10683 += 0x40;
                        *(u32 *)0x03003B22 = 2U;
                    } while (var_r4_10683 <= 0x4F);
                    sub_0201CF3C((*(u16 *)((u8 *)((temp_r0_10575 + 0x0202F7FC)) + (2))), var_r8_10533, 0U);
                }
            }
        }
    }
    temp_r4_10734 = ((var_r8_10533 & 0xF) * 2) + ((temp_r4_10542 & 0xF) << 5);
    if (0x8000 & Item_GetTypeIndex(*(u32 *)(*(u32 *)0x03001B40 + 0x224 + temp_r4_10734))) {

    } else {
        temp_r0_10753 = Item_GetTypeIndex(*(u32 *)(*(u32 *)0x03001B40 + 0x224 + temp_r4_10734));
        if (temp_r0_10753 > 0x57) {

        } else {
            temp_r0_10761 = temp_r0_10753 * 0xC;
            if (temp_r0_10753 == 0x57) {
                temp_r0_10768 = var_r8_10533 * 2;
                var_r7_10775 = temp_r0_10768;
                if (*(u32 *)(0x03003920 + temp_r0_10768) == 0xFFF) {
                    *(u32 *)(0x03003920 + temp_r0_10768) = 0x7777U;
                }
            } else {
                temp_r1_10796 = var_r8_10533 * 2;
                *(u32 *)(0x03003920 + temp_r1_10796) = (s16) temp_r0_10753;
                var_r7_10775 = temp_r1_10796;
            }
            if (*(u32 *)(0x0202F7FC + temp_r0_10761) == 0x270) {
                temp_r5_10812 = *(u32 *)0x03001B40;
                temp_r4_10815 = temp_r4_10542 & 0xF;
                temp_r3_10819 = temp_r5_10812 + 0x1918 + (temp_r4_10815 * 2);
                temp_r2_10821 = var_r8_10533 & 0xF;
                *temp_r3_10819 |= 1 << temp_r2_10821;
                *(u32 *)(temp_r5_10812 + 0x224 + ((temp_r2_10821 * 2) + (temp_r4_10815 << 5))) = 0x2512;
                *(u32 *)(0x03003920 + var_r7_10775) = 0x10;
            }
            if (temp_r0_10753 != 0x57) {
                temp_r0_10850 = sub_0201CDA0(*(u32 *)(0x0202F7FC + temp_r0_10761), var_r8_10533, 1U);
                if (temp_r0_10850 == 1) {
                    *(u32 *)0x03003B24 = (u16) *(u32 *)(0x0202F7FC + temp_r0_10761);
                    if (((s32) *(u32 *)(*(u32 *)0x03001B40 + 0x1918 + ((0xF & temp_r4_10542) * 2)) >> (var_r8_10533 & 0xF)) & temp_r0_10850) {
                        *(u32 *)0x03003B24 = 0x1270U;
                    }
                    var_r4_10880 = 0;
                    *(u32 *)0x03003B22 = 0U;
                    do {
                        temp_r2_10901 = var_r4_10880 + 0x0600C800 + ((0xFF0 & var_r8_10533) * 8) + ((0xF & var_r8_10533) * 4);
                        (*(s16 *)((u8 *)(temp_r2_10901) + (0))) = (s16) (*(u32 *)0x03003B22 + *(u32 *)0x03003B24);
                        (*(s16 *)((u8 *)(temp_r2_10901) + (2))) = (s16) (*(u32 *)0x03003B22 + *(u32 *)0x03003B24 + 1);
                        var_r4_10880 += 0x40;
                        *(u32 *)0x03003B22 = 2U;
                    } while (var_r4_10880 <= 0x4F);
                    sub_0201CF3C((*(u16 *)((u8 *)((temp_r0_10761 + 0x0202F7FC)) + (2))), var_r8_10533, 1U);
                }
            }
        }
    }
    var_r8_10533 = sp0;
    if (sp0 <= 0xFF) {
        goto loop_5;
    }
}

void UpdateHourlyPalette(void) {
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
            temp_r0_10975 = *(u32 *)(0x02034EE4 + ((var_r1_10968 >> 0x10) * 2));
            *var_r4_10965 = temp_r0_10975;
            *var_r3_10966 = temp_r0_10975;
            var_r1_10968 += 0x10000;
            var_r2_10964 += 1;
            var_r4_10965 += 2;
            var_r3_10966 += 2;
        } while (var_r2_10964 <= 3);
        *(u32 *)0x03003B26 = temp_r5_10958;
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
            temp_r0_11029 = *(u32 *)(0x02034EE4 + ((var_r1_11022 >> 0x10) * 2));
            *var_r4_11018 = temp_r0_11029;
            *var_r3_11019 = temp_r0_11029;
            var_r1_11022 += 0x10000;
            var_r2_11017 += 1;
            var_r4_11018 += 2;
            var_r3_11019 += 2;
        } while (var_r2_11017 <= 3);
        *(u32 *)0x03003B26 = temp_r5_11011;
    }
    *(u32 *)0x03003B26 = 0xFFU;
    *(s8 *)0x03003B27 = 1;
    sub_02025D70();
    Islander_Init();
    *(s8 *)0x03003BA7 = 4;
    *(s8 *)0x03003BA8 = 0;
    *(s8 *)0x03003BA9 = 0;
    *(s8 *)0x03003BAA = 0;
    (*(s32 *)((u8 *)((void *)0x03003710) + (8))) = 0;
    (*(s32 *)((u8 *)((void *)0x03003710) + (0xC))) = 0;
    (*(s32 *)((u8 *)((void *)0x03003710) + (0))) = 0;
    (*(s32 *)((u8 *)((void *)0x03003710) + (4))) = 0;
    (*(s8 *)((u8 *)((void *)0x03003710) + (0x49B))) = 0;
    (*(s16 *)((u8 *)((void *)0x03003710) + (0x410))) = 0;
    (*(s8 *)((u8 *)((void *)0x03003710) + (0x49D))) = 0;
    temp_r2_11087 = 3 & (*(u8 *)((u8 *)(*(void **)0x03001B40) + (0x1938)));
    (*(s8 *)((u8 *)((void *)0x03003710) + (0x49C))) = 0;
    switch (temp_r2_11087) {                        /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_r0_11120 = 0x0202D3FC;
block_15:
        REG_DMA3SAD = var_r0_11120;
        REG_DMA3DAD = 0x0600A000;
        REG_DMA3CNT = 0x84000200;
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
    temp_r2_11156 = 3 & (*(u8 *)((u8 *)(*(u32 *)0x03001B40) + (0x1939)));
    switch (temp_r2_11156) {                        /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        var_r0_11179 = 0x0202B3FC;
block_27:
        REG_DMA3SAD = var_r0_11179;
        REG_DMA3DAD = 0x0600A800;
        REG_DMA3CNT = 0x84000200;
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
        if ((*(u8 *)((u8 *)(*(void **)0x03001B40) + (0x193A))) != 0) {
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
        if (*(u32 *)0x03003B20 == 0) {
            *(u32 *)0x03003B20 = 0xFFFFU;
        }
        *(u32 *)0x03003BAB = temp_r2_11275;
        *(u8 *)0x03003BAC = temp_r2_11275;
        var_r2_11302 = *(u32 *)0x03003B20 + 0xFFFFEEEF;
        *(u32 *)0x03003B20 = var_r2_11302;
        if ((var_r2_11302 << 0x10) == 0) {
            gGameState.unk_824 ^= 0x40;
            gGameState.unk_826 ^= 0x40;
            gGameState.unk_828 ^= 0x40;
block_3:
            *(u16 *)0x0400004C = var_r2_11302;
            goto block_10;
        }
block_9:
        *(u32 *)0x0400004C = var_r2_11302;
        return 0U;
    }
block_10:
    return 1U;
}

u8 sub_0201D904(void) {
    *(s16 *)0x0400004C = 0;
    ((void (*)(void))*(u32 *)(0x0202FD28 + (*(u8 *)0x03003BAC * 4)))();
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

    UpdateHourlyPalette();
    gGameState.unk_820 = 0x3E41;
    gGameState.unk_81C = 0x1006;
    if (*(u8 *)0x03004224 != 1) {
        temp_r0_11457 = sub_0201D800(0U);
        if (temp_r0_11457 == 0) {
            gGameState.unk_840 = ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8) - 0x80;
            temp_r0_11470 = ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) - 0x50;
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
            ChangeEmotion((u8) (*(u8 *)0x03004230 + 1));
            gGameState.unk_844 = gGameState.unk_840;
            gGameState.unk_846 = gGameState.unk_842;
            *(s8 *)0x03003BAE = 1;
            return;
        }
    }
    temp_r4_11537 = gGameState.unk_856;
    if ((temp_r4_11537 == 1) && (*(u32 *)0x03004224 != 1)) {
        sub_02026C68(0x14U);
        sub_02026BD8();
        *(u16 *)0x03003B20 = 0;
        *(s8 *)0x03003BAD = 0;
        *(u32 *)0x03003BAE = 0;
        *(u8 *)0x03003BAB = temp_r4_11537;
        *(u8 *)0x03003BAC = temp_r4_11537;
        return;
    }
    temp_r4_11576 = gGameState.unk_84E;
    if ((temp_r4_11576 == 1) && (*(u32 *)0x03004224 != 1)) {
        sub_02026C68(0x14U);
        sub_02026BD8();
        *(u32 *)0x03003B20 = 0U;
        *(u32 *)0x03003BAD = 0;
        *(u32 *)0x03003BAE = 0;
        *(u32 *)0x03003BAB = temp_r4_11576;
        *(u32 *)0x03003BAC = 2U;
        return;
    }
    if ((2 & gGameState.keys_pressed) && (*(u32 *)0x03004224 != 1)) {
        temp_r4_11631 = 0x40 & gGameState.unk_824;
        if (temp_r4_11631 == 0) {
            sub_02026C68(0x14U);
            sub_02026BD8();
            *(u32 *)0x03003B20 = temp_r4_11631;
            *(u32 *)0x03003BAD = 0;
            *(u32 *)0x03003BAE = 0;
            *(u32 *)0x03003BAB = 1U;
            *(u32 *)0x03003BAC = 3U;
            return;
        }
    }
    if ((0xC000 & *(u16 *)0x0400000E) && (0xC000 & gGameState.unk_828)) {
        gGameState.unk_828 = (0xC000 ^ gGameState.unk_828) | 0x300;
        if ((*(u8 *)((u8 *)(*(void **)0x03001B40) + (0x193A))) != 0) {
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
            *var_r5_11706 = *(u32 *)(0x0202F3FC + temp_r1_11723);
            *var_r3_11707 = *(u32 *)(0x0202F5FC + temp_r1_11723);
            var_r2_11717 += 0x10000;
            var_r4_11712 += 1;
            var_r5_11706 += 2;
            var_r3_11707 += 2;
        } while (var_r4_11712 <= 0xF);
        temp_r0_11741 = *(u32 *)0x03003BA8 + 1;
        *(u32 *)0x03003BA8 = temp_r0_11741;
        if ((u32) temp_r0_11741 > 0xDU) {
            *(u32 *)0x03003BA8 = 0U;
        }
    }
    CpuSet((void *)0x02000000, (void *)0x05000000, 0x200U);
    gGameState.unk_848 = gGameState.unk_840;
    temp_r1_11766 = (*(s32 *)((u8 *)((void *)0x03003710) + (0))) + 0x40;
    (*(s32 *)((u8 *)((void *)0x03003710) + (0))) = temp_r1_11766;
    gGameState.bg3_vofs = (u16) ((s32) (gGameState.unk_842 + temp_r1_11766) >> 8);
    sub_020267D0();
    sub_02021574();
    var_r4_11778 = 0;
    do {
        if ((*(u8 *)((u8 *)((var_r4_11778 + 0x03003710)) + (0x42C))) == 1) {
            sub_02024DD0(var_r4_11778);
        }
        var_r4_11778 += 1;
    } while (var_r4_11778 <= 0x1D);
    var_r4_11792 = 0;
    do {
        if ((*(u8 *)((u8 *)((var_r4_11792 + 0x03003710)) + (0x44D))) == 1) {
            sub_0201E538(var_r4_11792);
        }
        var_r4_11792 += 1;
    } while (var_r4_11792 <= 0x1D);
    if ((*(u8 *)((u8 *)((void *)0x03003710) + (0x419))) == 1) {
        sub_020255F0(2);
    }
    var_r4_11814 = 3;
    do {
        if ((*(u8 *)((u8 *)((var_r4_11814 + 0x03003710)) + (0x41A))) == 1) {
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
        if (*(u32 *)(0x03003B27 + (s32) var_r6_11978) == 1) {
            sub_02026830();
        }
        var_r6_11978 += 1;
    } while ((s32) var_r6_11978 <= 1);
    var_r6_11991 = 3;
    do {
        if ((*(u8 *)((u8 *)((var_r6_11991 + 0x03003710)) + (0x41A))) == 1) {
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
    if ((*(u8 *)((u8 *)((var_r6_12013 + 0x03003710)) + (0x44D))) != 1) {

    } else {
        temp_r0_12027 = var_r6_12013 * 0x30;
        temp_r5_12029 = temp_r0_12027 + 0x03003C00;
        if ((var_sl_12008 == 0) && ((u32) (*(u8 *)((u8 *)((void *)0x03003BB0) + (0x10))) > (u32) (*(u16 *)((u8 *)(temp_r5_12029) + (0xE))))) {
            sub_0201E178(0, 0U);
            var_sl_12008 = 1;
        }
        if ((sp0 == 0) && ((u32) (*(u8 *)((u8 *)((void *)0x03003BC4) + (0x10))) > (u32) (*(u16 *)((u8 *)(temp_r5_12029) + (0xE))))) {
            sub_0201E178(1, 2U);
            sp0 = 1;
        }
        temp_r1_12058 = (*(u16 *)((u8 *)(temp_r5_12029) + (0x1C)));
        var_r8_12020 = var_r6_12013 - 1;
        if (temp_r1_12058 != 0) {
            if (temp_r1_12058 != 0xFFFF) {
                sub_02024DF8(temp_r1_12058 - 1);
            } else {
                var_r4_12083 = 0;
                do {
                    if ((*(u8 *)((u8 *)((var_r4_12083 + 0x03003710)) + (0x42C))) == 1) {
                        sub_02024DF8(var_r4_12083);
                    }
                    var_r4_12083 += 1;
                } while (var_r4_12083 <= 2);
            }
        }
        temp_r2_12102 = *(u32 *)(0x03003C00 + temp_r0_12027) - ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) >> 8);
        (*(s32 *)((u8 *)((void *)0x03003710) + (8))) = temp_r2_12102;
        temp_r3_12104 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4)));
        (*(s32 *)((u8 *)((void *)0x03003710) + (0xC))) = (s32) ((*(s32 *)((u8 *)(temp_r5_12029) + (4))) - (temp_r3_12104 >> 8));
        if (temp_r2_12102 < 0) {
            (*(s32 *)((u8 *)((void *)0x03003710) + (8))) = (s32) (0 - temp_r2_12102);
        }
        temp_r0_12114 = (*(s32 *)((u8 *)((void *)0x03003710) + (0xC)));
        if (temp_r0_12114 < 0) {
            (*(s32 *)((u8 *)((void *)0x03003710) + (0xC))) = (s32) (0 - temp_r0_12114);
        }
        if (((s32) (*(s32 *)((u8 *)((void *)0x03003710) + (8))) <= 0x10) && ((s32) (*(s32 *)((u8 *)((void *)0x03003710) + (0xC))) <= 0x10) && ((s32) (0xF0 & (*(u16 *)((u8 *)(temp_r5_12029) + (0xE)))) < (s32) (((s32) (temp_r3_12104 + 0xD00) >> 8) & 0xF0)) && (sp4 == 0)) {
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
        if ((*(u8 *)((u8 *)((var_r6_12174 + 0x03003710)) + (0x41A))) == 1) {
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
        (*(s32 *)((u8 *)(temp_r2_12211) + (4))) = (s32) ((0xFFF0 & arg2) + 0x10);
        *(u32 *)(0x03003BB0 + temp_r2_12209) = (s32) (((0xF & arg2) * 0x10) + 0x10);
    } else {
        (*(s32 *)((u8 *)(temp_r2_12211) + (4))) = (s32) ((0xFFF0 & arg2) + 8);
        if (arg3 == 0) {
            var_r0_12239 = ((0xF & arg2) * 0x10) + 8;
        } else {
            var_r0_12239 = ((0xF & arg2) * 0x10) + 0x108;
        }
        *(u32 *)(0x03003BB0 + temp_r2_12209) = var_r0_12239;
        temp_r1_12253 = *(u32 *)(0x03003BB0 + temp_r2_12209) << 8;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = temp_r1_12253;
        temp_r0_12259 = ((*(s32 *)((u8 *)(temp_r2_12211) + (4))) << 8) + 0x100;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = temp_r0_12259;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = temp_r1_12253;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = temp_r0_12259;
        (*(s32 *)((u8 *)(temp_r2_12211) + (8))) = (s32) (*(u32 *)(0x03003BB0 + temp_r2_12209) - 8);
        (*(s32 *)((u8 *)(temp_r2_12211) + (0xC))) = (s32) ((*(s32 *)((u8 *)(temp_r2_12211) + (4))) - 4);
    }
    (*(s8 *)((u8 *)(temp_r2_12211) + (0x10))) = arg2;
    (*(s8 *)((u8 *)(temp_r2_12211) + (0x11))) = 1;
}

void sub_0201E030(void) {

}

void sub_0201E034(void) {

}

void sub_0201E038(u8 arg0, u8 arg1) {
    if (arg1 == 2) {
        ((void (*)(void))*(u32 *)(0x0202FD38 + ((*(u8 *)((u8 *)((void *)0x03003BC4) + (0x11))) * 4)))();
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
    if ((arg2 != 5) || ((*(u8 *)((u8 *)(temp_r0_12320) + (0x11))) == 1)) {
        temp_r4_12347 = (0x3F & (*(u8 *)((u8 *)(temp_r6_12329) + (1)))) | ((((u32) (*(u32 *)((u8 *)(arg0) + (0))) >> 0xE) & 3) << 6);
        (*(u8 *)((u8 *)(temp_r6_12329) + (1))) = temp_r4_12347;
        temp_r2_12355 = (0x3F & (*(u8 *)((u8 *)(temp_r6_12329) + (3)))) | (((u32) (*(u32 *)((u8 *)(arg0) + (0))) >> 0x1E) << 6);
        (*(u8 *)((u8 *)(temp_r6_12329) + (3))) = temp_r2_12355;
        temp_r0_12364 = (-0x11 & temp_r2_12355) | (((*(u8 *)((u8 *)(arg0) + (0xF))) & 1) * 0x10);
        (*(u8 *)((u8 *)(temp_r6_12329) + (3))) = temp_r0_12364;
        (*(u8 *)((u8 *)(temp_r6_12329) + (3))) = (u8) ((temp_r0_12364 & ~0x20) | (((*(u8 *)((u8 *)(arg0) + (0x10))) & 1) << 5));
        (*(u8 *)((u8 *)(temp_r6_12329) + (5))) = (u8) ((((0xF & (*(u8 *)((u8 *)(temp_r6_12329) + (5)))) | ((*(u8 *)((u8 *)(arg0) + (0xE))) * 0x10)) & ~0xC) | 4);
        (*(u16 *)((u8 *)(temp_r6_12329) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r6_12329) + (2)))) | (((*(s32 *)((u8 *)(arg0) + (8))) + (*(u32 *)(0x03003BB0 + temp_r0_12318) - gGameState.unk_844)) & 0x1FF));
        (*(s8 *)((u8 *)(temp_r6_12329) + (0))) = (s8) ((*(s32 *)((u8 *)(arg0) + (4))) + ((*(s32 *)((u8 *)(temp_r0_12320) + (4))) - (*(u8 *)((u8 *)(&gGameState) + (0x846)))));
        (*(u16 *)((u8 *)(temp_r6_12329) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r6_12329) + (4)))) | (0x3FF & (*(u16 *)((u8 *)(arg0) + (0xC)))));
        (*(u8 *)((u8 *)(temp_r6_12329) + (1))) = (u8) (temp_r4_12347 | 0x10);
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
    *(u32 *)(0x03003BF0 + temp_r1_12511) = 0;
    if ((arg2 << 0x18) != 0) {
        *(u32 *)(0x03003BF0 + temp_r1_12511) = 0x100;
    }
    *(u32 *)(0x03003BF0 + temp_r1_12511) = (s32) (*(u32 *)(0x03003BF0 + temp_r1_12511) | (((0xF & arg1) * 0x10) + 0xC));
    (*(s32 *)((u8 *)(temp_r3_12513) + (4))) = (s32) ((0xF0 & arg1) + 8);
    (*(s8 *)((u8 *)(temp_r3_12513) + (8))) = 0;
    (*(s8 *)((u8 *)(temp_r3_12513) + (9))) = 0;
    (*(s8 *)((u8 *)(temp_r3_12513) + (8))) = (s8) (*(u16 *)((u8 *)(*(void **)0x0202FEB0) + (4)));
}

void sub_0201E230(s32 arg0) {
    u8 temp_r0_12555;
    u8 temp_r2_12558;
    void *temp_r1_12553;

    temp_r1_12553 = (arg0 * 0xC) + 0x03003BF0;
    temp_r0_12555 = (*(u8 *)((u8 *)(temp_r1_12553) + (8))) - 1;
    (*(u8 *)((u8 *)(temp_r1_12553) + (8))) = temp_r0_12555;
    temp_r2_12558 = temp_r0_12555;
    if (temp_r2_12558 == 0) {
        (*(u8 *)((u8 *)(temp_r1_12553) + (9))) = (u8) ((*(u8 *)((u8 *)(temp_r1_12553) + (9))) + 1);
        if ((*(u8 *)((u8 *)(*(u32 *)(0x0202FEB0 + ((*(u8 *)((u8 *)(temp_r1_12553) + (9))) * 4))) + (6))) == 0xFF) {
            (*(u8 *)((u8 *)(temp_r1_12553) + (9))) = temp_r2_12558;
        }
        (*(u8 *)((u8 *)(temp_r1_12553) + (8))) = (u8) (*(u16 *)((u8 *)(*(u32 *)(0x0202FEB0 + ((*(u8 *)((u8 *)(temp_r1_12553) + (9))) * 4))) + (4)));
    }
}

void sub_0201E27C(s32 arg0) {
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
    var_r5_12604 = **(u32 **)(0x0202FEB0 + ((*(u8 *)((u8 *)(temp_r6_12598) + (9))) * 4));
    if ((*(u16 *)((u8 *)(var_r5_12604) + (6))) == 0xFFFF) {
        return;
    }
    do {
        temp_r3_12628 = (gGameState.unk_860 * 8) + gUnk3002410;
        (*(s8 *)((u8 *)(temp_r3_12628) + (0))) = (s8) (((*(u8 *)((u8 *)(var_r5_12604) + (0))) + (*(s32 *)((u8 *)(temp_r6_12598) + (4)))) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
        temp_r2_12644 = (-0xD & (*(u8 *)((u8 *)(temp_r3_12628) + (1)))) | (0xC & (*(u8 *)((u8 *)(var_r5_12604) + (1))));
        (*(u8 *)((u8 *)(temp_r3_12628) + (1))) = temp_r2_12644;
        temp_r1_12653 = (-0x21 & temp_r2_12644) | ((((u32) ((*(u8 *)((u8 *)(var_r5_12604) + (1))) << 0x1A) >> 0x1F) & 1) << 5);
        (*(u8 *)((u8 *)(temp_r3_12628) + (1))) = temp_r1_12653;
        temp_r4_12660 = (0x3F & temp_r1_12653) | (((u8) (*(u8 *)((u8 *)(var_r5_12604) + (1))) >> 6) << 6);
        (*(u8 *)((u8 *)(temp_r3_12628) + (1))) = temp_r4_12660;
        temp_r2_12671 = (-0x11 & (*(u8 *)((u8 *)(temp_r3_12628) + (3)))) | ((((u32) ((*(u8 *)((u8 *)(var_r5_12604) + (3))) << 0x1B) >> 0x1F) & 1) * 0x10);
        (*(u8 *)((u8 *)(temp_r3_12628) + (3))) = temp_r2_12671;
        temp_r1_12680 = (-0x21 & temp_r2_12671) | ((((u32) ((*(u8 *)((u8 *)(var_r5_12604) + (3))) << 0x1A) >> 0x1F) & 1) << 5);
        (*(u8 *)((u8 *)(temp_r3_12628) + (3))) = temp_r1_12680;
        (*(u8 *)((u8 *)(temp_r3_12628) + (3))) = (u8) ((temp_r1_12680 & 0x3F) | (((u8) (*(u8 *)((u8 *)(var_r5_12604) + (3))) >> 6) << 6));
        (*(u16 *)((u8 *)(temp_r3_12628) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r3_12628) + (2)))) | (((((u32) ((*(u16 *)((u8 *)(var_r5_12604) + (2))) << 0x17) >> 0x17) + *(u32 *)(0x03003BF0 + temp_r1_12596)) - gGameState.unk_844) & 0x1FF));
        (*(u16 *)((u8 *)(temp_r3_12628) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r3_12628) + (4)))) | ((u32) ((*(u16 *)((u8 *)(var_r5_12604) + (4))) << 0x16) >> 0x16));
        (*(u8 *)((u8 *)(temp_r3_12628) + (1))) = (u8) (temp_r4_12660 | 0x10);
        temp_r0_12722 = (-0xD & (*(u8 *)((u8 *)(temp_r3_12628) + (5)))) | 4;
        (*(u8 *)((u8 *)(temp_r3_12628) + (5))) = temp_r0_12722;
        (*(u8 *)((u8 *)(temp_r3_12628) + (5))) = (u8) ((temp_r0_12722 & 0xF) | (((u8) (*(u8 *)((u8 *)(var_r5_12604) + (5))) >> 4) * 0x10));
        gGameState.unk_860 += 1;
        var_r5_12604 += 8;
    } while ((*(u16 *)((u8 *)(var_r5_12604) + (6))) != 0xFFFF);
}

void sub_0201E3DC(s32 arg0, u8 arg1) {
    u16 var_r4_12770;
    void *temp_r0_12773;
    void *temp_r5_12768;

    temp_r5_12768 = (arg0 * 0x30) + 0x03003C00;
    var_r4_12770 = 3;
loop_1:
    temp_r0_12773 = var_r4_12770 + 0x03003710;
    if ((*(u8 *)((u8 *)(temp_r0_12773) + (0x42F))) == 0) {
        (*(u8 *)((u8 *)(temp_r0_12773) + (0x42F))) = 1U;
        sub_02024B08(arg0, var_r4_12770, arg1, (*(u8 *)((u8 *)(temp_r5_12768) + (0x24))));
        (*(s16 *)((u8 *)(temp_r5_12768) + (0x1C))) = (s16) (var_r4_12770 + 1);
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
    (*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) = arg1;
    (*(s8 *)((u8 *)(temp_r5_12818) + (0x29))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x10))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x16))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x18))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x1A))) = 0;
    temp_r0_12829 = (temp_r5_12818 + 0x29) - 1;
    *temp_r0_12829 = 0;
    temp_r0_12831 = temp_r0_12829 - 2;
    *temp_r0_12831 = 0;
    temp_r0_12833 = temp_r0_12831 - 1;
    (*(s8 *)((u8 *)(temp_r0_12833) + (0))) = 0;
    (*(s8 *)((u8 *)(temp_r0_12833) + (2))) = 0;
    (*(u8 *)((u8 *)(temp_r5_12818) + (0x2A))) = 0U;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x1C))) = 0;
    (*(s8 *)((u8 *)(temp_r5_12818) + (0x2B))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x1E))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x20))) = 0;
    (*(s16 *)((u8 *)(temp_r5_12818) + (0x22))) = 0;
    (*(s8 *)((u8 *)((temp_r5_12818 + 0x2B)) + (1))) = 0;
    (*(s8 *)((u8 *)(temp_r5_12818) + (0x2D))) = 0;
    (*(s32 *)((u8 *)(temp_r5_12818) + (4))) = (s32) ((0xF0 & arg2) + 8);
    temp_r1_12860 = (0xF & arg2) * 0x10;
    *(u32 *)(0x03003C00 + temp_r0_12816) = (s32) (temp_r1_12860 + 8);
    (*(s16 *)((u8 *)(temp_r5_12818) + (0xE))) = (s16) arg2;
    if (temp_r3_12812 != 0) {
        *(u32 *)(0x03003C00 + temp_r0_12816) = (s32) (temp_r1_12860 + 0x108);
    }
    (*(u8 *)((u8 *)(temp_r5_12818) + (0x2A))) = (u8) *(u32 *)(0x02030110 + (*(u16 *)((u8 *)(temp_r5_12818) + (0xC))));
    (*(u8 *)((u8 *)(temp_r5_12818) + (0x24))) = temp_r3_12812;
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 0x12) {
        sub_0201E3DC(arg0, 0U);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 7) {
        sub_0201E3DC(arg0, 3U);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 8) {
        sub_0201E3DC(arg0, 7U);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 9) {
        sub_0201E3DC(arg0, 0xBU);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 0xA) {
        sub_0201E3DC(arg0, 0xFU);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 0xB) {
        sub_0201E3DC(arg0, 0x13U);
    }
    if ((*(u16 *)((u8 *)(temp_r5_12818) + (0xC))) == 6) {
        (*(s8 *)((u8 *)(temp_r5_12818) + (0x2D))) = 1;
    }
}

void sub_0201E538(s32 arg0) {
    ((void (*)(void))*(u32 *)(0x0202FECC + ((*(u8 *)((u8 *)(((arg0 * 0x30) + 0x03003C00)) + (0x28))) * 4)))();
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
    temp_r0_12978 = (*(u16 *)((u8 *)(temp_r6_12976) + (0xC)));
    if ((temp_r0_12978 != 3) && (temp_r0_12978 != 0xE)) {
        var_r3_12983 = 3;
loop_3:
        temp_r0_12987 = var_r3_12983 + 0x03003710;
        if ((*(u8 *)((u8 *)(temp_r0_12987) + (0x41A))) == 0) {
            temp_r1_12995 = 0x54 * var_r3_12983;
            temp_r4_12997 = temp_r1_12995 + 0x03004790;
            (*(u8 *)((u8 *)(temp_r0_12987) + (0x41A))) = 1U;
            Unk_Struct_Size54_ResetIdx(var_r3_12983);
            temp_r5_13007 = 0x10 - ((s32) rand_u16(&gGameState) % 33);
            var_r1_13013 = ((s32) rand_u16(&gGameState) % 17) + 0x10;
            if ((*(u16 *)((u8 *)(temp_r6_12976) + (0xC))) == 4) {
                var_r1_13013 = 0x10;
            }
            *(u32 *)(0x03004790 + temp_r1_12995) = (s32) (*(u32 *)(0x03003C00 + temp_r1_12974) + temp_r5_13007);
            (*(s32 *)((u8 *)(temp_r4_12997) + (4))) = (s32) ((*(s32 *)((u8 *)(temp_r6_12976) + (4))) - var_r1_13013);
            (*(s8 *)((u8 *)(temp_r4_12997) + (0x4E))) = 1;
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
    if ((*(u8 *)((u8 *)(temp_r3_13053) + (0x28))) == 3) {
        temp_r0_13060 = (*(u16 *)((u8 *)(temp_r3_13053) + (0xC)));
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
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 0x12) {
            var_r4_13054 = 0x858;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 0x11U;
        }
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 7) {
            var_r4_13054 = 0x809;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 6U;
        }
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 8) {
            var_r4_13054 = 0x811;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 6U;
        }
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 9) {
            var_r4_13054 = 0x819;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 6U;
        }
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 0xA) {
            var_r4_13054 = 0x821;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 6U;
        }
        if ((*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) == 0xB) {
            var_r4_13054 = 0x829;
            (*(u16 *)((u8 *)(temp_r3_13053) + (0xC))) = 6U;
        }
    }
    if (!(*(u32 *)(0x03003C00 + temp_r1_13051) & 0x100)) {
        temp_r0_13146 = (*(u16 *)((u8 *)(temp_r3_13053) + (0xE)));
        var_r1_13154 = ((0xF & temp_r0_13146) * 2) + (((temp_r0_13146 >> 4) & 0xF) << 5);
        var_r2_13155 = *(s32 *)0x03001B40 + 0x24;
    } else {
        temp_r0_13168 = (*(u16 *)((u8 *)(temp_r3_13053) + (0xE)));
        var_r1_13154 = ((0xF & temp_r0_13168) * 2) + (((temp_r0_13168 >> 4) & 0xF) << 5);
        var_r2_13155 = *(u32 *)0x03001B40 + 0x224;
    }
    *(u32 *)(var_r2_13155 + var_r1_13154) = var_r4_13054;
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
    temp_r1_13208 = (*(u8 *)((u8 *)(temp_r5_13202) + (0x2A)));
    if ((temp_r1_13208 == 0) || (0x80 & temp_r1_13208)) {
        sub_0201E564(arg0);
        (*(s8 *)((u8 *)(temp_r5_13202) + (0x27))) = 8;
        (*(s8 *)((u8 *)(temp_r5_13202) + (0x26))) = 0;
        (*(s16 *)((u8 *)(temp_r5_13202) + (0x14))) = 0xFFFF;
        (*(s8 *)((u8 *)(temp_r5_13202) + (0x28))) = 3;
        sub_0201E608(arg0);
        sub_02026A38(0x13U);
        sp1C = temp_r5_13202 + 0x28;
    } else {
        sub_02026A38(0x18U);
        (*(s8 *)((u8 *)(temp_r5_13202) + (0x27))) = 2;
        temp_r0_13248 = (temp_r5_13202 + 0x27) - 1;
        *temp_r0_13248 = 0;
        temp_r0_13250 = temp_r0_13248 - 1;
        (*(s8 *)((u8 *)(temp_r0_13250) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_r0_13250) + (3))) = 2;
        sp1C = temp_r0_13250 + 3;
    }
    if ((*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))) == 0) {
        return;
    }
    sp20 = temp_r5_13202 + 0x2B;
    if ((*(u8 *)((u8 *)(temp_r5_13202) + (0x2B))) != 0) {
        return;
    }
    var_sl_13270 = 0;
    sp8 = sp0 + 0x417;
    sp24 = 0;
    sp28 = sp0 + 0x42C;
loop_9:
    if ((*sp28 == 1) && ((*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))) != 0)) {
        *(u32 *)(sp8 + ((*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))) + 0x17)) = 0;
        (*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))) = 0U;
        return;
    }
    sp4 = 0;
    sp14 = var_sl_13270 * 4;
    temp_r2_13296 = temp_r5_13202 + 0x24;
    sp18 = temp_r2_13296;
    (*(u16 *)((u8 *)(&sp0) + (0xC))) = (u16) (*(u16 *)((u8 *)(temp_r5_13202) + (0xE)));
    sp10 = temp_r2_13296;
loop_13:
    temp_r2_13305 = sp14 + sp4;
    temp_r3_13314 = ((*(u16 *)((u8 *)(&sp0) + (0xC))) + (*(u32 *)(0x02030104 + (s32) temp_r2_13305) * 0x10)) & 0xF0;
    (*(u16 *)((u8 *)(temp_r5_13202) + (0x20))) = temp_r3_13314;
    temp_r2_13326 = ((0xF & (*(u16 *)((u8 *)(&sp0) + (0xC)))) + *(u32 *)(0x020300F8 + (s32) temp_r2_13305)) & 0xF;
    (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E))) = temp_r2_13326;
    var_r8_13330 = 0;
    if (*sp10 == 0) {
        temp_r4_13336 = *(s32 *)0x03001B40;
        temp_r4_13340 = temp_r3_13314 * 2;
        (*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) = (u16) *(u32 *)(temp_r4_13336 + 0x24 + (((*(u16 *)((u8 *)(temp_r5_13202) + (0x1E))) * 2) + temp_r4_13340));
        temp_r3_13349 = (temp_r2_13326 | temp_r3_13314) * 2;
        var_r7_13353 = *(u32 *)(sp0 + 0x10 + temp_r3_13349);
        if ((u32) temp_r2_13326 <= 1U) {
            var_r8_13330 = 1;
            (*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) = (u16) *(u32 *)(temp_r4_13336 + 0x224 + (((*(u16 *)((u8 *)(temp_r5_13202) + (0x1E))) * 2) + temp_r4_13340));
            var_r7_13353 = *(u32 *)(sp0 + 0x210 + temp_r3_13349);
        }
        if (*sp10 != 0) {
            goto block_17;
        }
    } else {
block_17:
        var_r8_13330 = 1;
        temp_r4_13384 = *(u32 *)0x03001B40;
        temp_r2_13386 = (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E)));
        temp_r3_13390 = (*(u16 *)((u8 *)(temp_r5_13202) + (0x20)));
        temp_r4_13393 = ((0xF & temp_r2_13386) * 2) + ((temp_r3_13390 >> 4) << 5);
        (*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) = (u16) *(u32 *)(temp_r4_13384 + 0x224 + temp_r4_13393);
        temp_r1_13402 = (u32) ((temp_r3_13390 + temp_r2_13386) << 0x18) >> 0x17;
        var_r7_13353 = *(u32 *)(sp0 + 0x210 + temp_r1_13402);
        if ((u32) temp_r2_13386 > 0xDU) {
            var_r8_13330 = 0;
            (*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) = (u16) *(u32 *)(temp_r4_13384 + 0x24 + temp_r4_13393);
            var_r7_13353 = *(u32 *)(sp0 + 0x10 + temp_r1_13402);
        }
    }
    if (var_r8_13330 == 0) {
        var_r0_13428 = (u16 *)0x0600A000;
    } else {
        var_r0_13428 = (u16 *)0x0600A800;
    }
    (*(u16 **)((u8 *)(temp_r5_13202) + (8))) = var_r0_13428;
    temp_r1_13441 = (*(u16 *)((u8 *)(temp_r5_13202) + (0x20))) + (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E)));
    temp_r1_13451 = (*(u16 **)((u8 *)(temp_r5_13202) + (8))) + ((temp_r1_13441 & 0xF0) * 8) + ((temp_r1_13441 & 0xF) * 4);
    (*(u16 **)((u8 *)(temp_r5_13202) + (8))) = temp_r1_13451;
    if ((((*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) != 0) || (var_r7_13353 != 0xFFF) || ((u32) (u16) ((*temp_r1_13451 & 0x3FF) - 0x20) > 0x5EU)) && (sp4 != 3)) {
        temp_r3_13622 = sp4 + 1;
        sp4 = temp_r3_13622;
        if (temp_r3_13622 <= 3) {
            goto loop_13;
        }
    } else {
        *sp28 = 1;
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 0x12) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 1), var_r8_13330);
        }
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 7) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 4), var_r8_13330);
        }
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 8) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 8), var_r8_13330);
        }
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 9) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0xC), var_r8_13330);
        }
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 0xA) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0x10), var_r8_13330);
        }
        if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 0xB) {
            sub_02024B08(arg0, (u16) (sp24 >> 0x10), (u8) (var_sl_13270 + 0x14), var_r8_13330);
        }
        if (var_r8_13330 == 0) {
            var_r0_13562 = (u32) (((*(u16 *)((u8 *)(temp_r5_13202) + (0x20))) + (u8) (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E)))) << 0x18) >> 0x17;
            var_r1_13564 = sp0 + 0x10;
        } else {
            var_r0_13562 = (u32) (((*(u16 *)((u8 *)(temp_r5_13202) + (0x20))) + (u8) (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E)))) << 0x18) >> 0x17;
            var_r1_13564 = sp0 + 0x210;
        }
        *(u32 *)(var_r1_13564 + var_r0_13562) = 0x7777;
        temp_r1_13588 = (0x2C * var_sl_13270) + 0x03004260;
        temp_r2_13590 = (*(u16 *)((u8 *)(temp_r5_13202) + (0x1E))) * 0x10;
        (*(s32 *)((u8 *)(temp_r1_13588) + (0x10))) = temp_r2_13590;
        if (var_r8_13330 != 0) {
            (*(s32 *)((u8 *)(temp_r1_13588) + (0x10))) = (s32) (temp_r2_13590 | 0x100);
        }
        (*(s32 *)((u8 *)(temp_r1_13588) + (0xC))) = (s32) (*(u16 *)((u8 *)(temp_r5_13202) + (0x20)));
        (*(s16 *)((u8 *)(temp_r1_13588) + (0x20))) = (s16) ((*(u16 *)((u8 *)(temp_r5_13202) + (0x1E))) + (*(u16 *)((u8 *)(temp_r5_13202) + (0x20))));
        if (((*(u16 *)((u8 *)(temp_r5_13202) + (0x22))) == 0) && (var_r7_13353 == 0xFFF)) {
            (*(s8 *)((u8 *)(temp_r1_13588) + (0x28))) = 1;
        }
    }
    if (((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) != 0x12) || (var_sl_13270 != 1)) {
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
            if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 0x12) {
                var_r1_13667 = sp0 + 0x10 + ((*(u16 *)((u8 *)(temp_r5_13202) + (0xE))) * 2);
                var_r0_13668 = 0x25;
            } else {
                var_r1_13667 = sp0 + 0x10 + ((*(u16 *)((u8 *)(temp_r5_13202) + (0xE))) * 2);
                var_r0_13668 = 0x34;
            }
            *var_r1_13667 = var_r0_13668;
            if (*sp18 != 0) {
                goto block_59;
            }
        } else {
block_59:
            if ((*(u16 *)((u8 *)(temp_r5_13202) + (0xC))) == 0x12) {
                var_r1_13693 = sp0 + 0x210 + ((*(u16 *)((u8 *)(temp_r5_13202) + (0xE))) * 2);
                var_r0_13694 = 0x25;
            } else {
                var_r1_13693 = sp0 + 0x210 + ((*(u16 *)((u8 *)(temp_r5_13202) + (0xE))) * 2);
                var_r0_13694 = 0x34;
            }
            *var_r1_13693 = var_r0_13694;
        }
    }
    *sp20 = 1;
    (*(s8 *)((u8 *)((sp0 + (*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))))) + (0x42E))) = 0;
    (*(u16 *)((u8 *)(temp_r5_13202) + (0x1C))) = 0xFFFFU;
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
    if ((*(u8 *)((u8 *)(temp_r6_13754) + (0x2C))) == 0) {
        temp_r0_13765 = (*(u8 *)((u8 *)(temp_r6_13754) + (0x27))) - 1;
        (*(u8 *)((u8 *)(temp_r6_13754) + (0x27))) = temp_r0_13765;
        if ((temp_r0_13765 << 0x18) == 0) {
            (*(u8 *)((u8 *)(temp_r6_13754) + (0x27))) = 2U;
            (*(u8 *)((u8 *)(temp_r6_13754) + (0x26))) = (u8) ((*(u8 *)((u8 *)(temp_r6_13754) + (0x26))) + 1);
            (*(u8 *)((u8 *)(temp_r6_13754) + (0x25))) = (u8) *(u32 *)(0x02030123 + (*(u8 *)((u8 *)(temp_r6_13754) + (0x26))));
        }
    }
    sp0 = temp_r6_13754 + 0x26;
    if (1 & (*(u8 *)((u8 *)(temp_r6_13754) + (0x26)))) {
        temp_r0_13796 = (*(u16 *)((u8 *)(temp_r6_13754) + (0xC)));
        if ((temp_r0_13796 != 3) && (temp_r0_13796 != 0xE)) {
            var_r0_13801 = 0;
            do {
                var_r2_13805 = 3;
loop_8:
                temp_r0_13809 = var_r2_13805 + 0x03003710;
                if ((*(u8 *)((u8 *)(temp_r0_13809) + (0x41A))) == 0) {
                    temp_r5_13817 = 0x54 * var_r2_13805;
                    temp_r5_13819 = temp_r5_13817 + 0x03004790;
                    (*(u8 *)((u8 *)(temp_r0_13809) + (0x41A))) = 1U;
                    Unk_Struct_Size54_ResetIdx(var_r2_13805);
                    *(u32 *)(0x03004790 + temp_r5_13817) = (s32) ((*(u32 *)(0x03003C00 + temp_r1_13752) + 0x10) - ((s32) rand_u16(&gGameState) % 33));
                    (*(s32 *)((u8 *)(temp_r5_13819) + (4))) = (s32) (((*(s32 *)((u8 *)(temp_r6_13754) + (4))) - 0x10) - ((s32) rand_u16(&gGameState) % 17));
                    (*(s8 *)((u8 *)(temp_r5_13819) + (0x4E))) = 3;
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
    if ((u32) (*(u8 *)((u8 *)(temp_r6_13754) + (0x25))) > 2U) {
        (*(u8 *)((u8 *)(temp_r6_13754) + (0x27))) = 0U;
        *sp0 = 0;
        (*(u8 *)((u8 *)(temp_r6_13754) + (0x25))) = 0U;
        (*(u8 *)((u8 *)(temp_r6_13754) + (0x2C))) = 0U;
        *(u32 *)((temp_r6_13754 + 0x2C) - 4) = 0;
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
    temp_r0_13898 = (*(u8 *)((u8 *)(temp_r2_13895) + (0x27)));
    if (temp_r0_13898 != 0) {
        temp_r0_13901 = temp_r0_13898 - 1;
        (*(u8 *)((u8 *)(temp_r2_13895) + (0x27))) = temp_r0_13901;
        if (!(temp_r0_13901 & 1)) {
            (*(u16 *)((u8 *)(temp_r2_13895) + (0x16))) = (u16) ((*(u16 *)((u8 *)(temp_r2_13895) + (0x16))) + 1);
        }
    } else {
        var_r4_13915 = 0x200;
        var_r5_13917 = 0xF200;
        temp_r0_13918 = (*(u16 *)((u8 *)(temp_r2_13895) + (0xC)));
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
        temp_r0_13942 = var_r4_13915 + (*(u16 *)((u8 *)(temp_r2_13895) + (0x12)));
        (*(u16 *)((u8 *)(temp_r2_13895) + (0x12))) = temp_r0_13942;
        if ((u32) temp_r0_13942 > var_r4_13915) {
            (*(u16 *)((u8 *)(temp_r2_13895) + (0x12))) = (u16) var_r4_13915;
        }
        temp_r0_13952 = (*(u16 *)((u8 *)(temp_r2_13895) + (0x10))) - (*(u16 *)((u8 *)(temp_r2_13895) + (0x12)));
        (*(u16 *)((u8 *)(temp_r2_13895) + (0x10))) = temp_r0_13952;
        temp_r3_13954 = (*(u16 *)((u8 *)(temp_r2_13895) + (0x14)));
        if ((u32) temp_r0_13952 <= (u32) temp_r3_13954) {
            temp_r1_13962 = (0xFF00 & temp_r3_13954) - var_r4_13915;
            (*(u16 *)((u8 *)(temp_r2_13895) + (0x14))) = temp_r1_13962;
            (*(u16 *)((u8 *)(temp_r2_13895) + (0x16))) = (u16) ((*(u16 *)((u8 *)(temp_r2_13895) + (0x16))) + 1);
            if ((u32) temp_r1_13962 < var_r5_13917) {
                (*(u16 *)((u8 *)(temp_r2_13895) + (0x18))) = (u16) ((*(u16 *)((u8 *)(temp_r2_13895) + (0x18))) + 1);
            }
            temp_r0_13975 = (*(u16 *)((u8 *)(temp_r2_13895) + (0xC)));
            if ((temp_r0_13975 != 3) && (temp_r0_13975 != 0xE)) {
                temp_r0_13980 = (*(u16 *)((u8 *)(temp_r2_13895) + (0x1A)));
                if ((u32) temp_r0_13980 <= 5U) {
                    (*(u16 *)((u8 *)(temp_r2_13895) + (0x1A))) = (u16) (temp_r0_13980 + 1);
                }
            }
        }
        if ((u32) (*(u16 *)((u8 *)(temp_r2_13895) + (0x10))) <= 0xD000U) {
            (*(u16 *)((u8 *)(temp_r2_13895) + (0x10))) = 0xD000U;
            temp_r0_13995 = (*(u8 *)((u8 *)(temp_r2_13895) + (0x26))) + 1;
            (*(u8 *)((u8 *)(temp_r2_13895) + (0x26))) = temp_r0_13995;
            if ((u32) temp_r0_13995 > 0x20U) {
                (*(s8 *)((u8 *)(temp_r2_13895) + (0x28))) = 4;
                (*(s16 *)((u8 *)(temp_r2_13895) + (0x1C))) = 0;
            }
        }
    }
}

void sub_0201ED50(s32 arg0) {
    (*(s8 *)((u8 *)((arg0 + 0x03003710)) + (0x44D))) = 0;
}

void sub_0201ED68(void *arg0, s32 arg1) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
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
    temp_r4_14056 = (0x3F & (*(u8 *)((u8 *)(var_r6_14045) + (1)))) | ((((u32) (*(u32 *)((u8 *)(arg0) + (0))) >> 0xE) & 3) << 6);
    (*(u8 *)((u8 *)(var_r6_14045) + (1))) = temp_r4_14056;
    temp_r2_14065 = (0x3F & (*(u8 *)((u8 *)(var_r6_14045) + (3)))) | (((u32) (*(u32 *)((u8 *)(arg0) + (0))) >> 0x1E) << 6);
    (*(u8 *)((u8 *)(var_r6_14045) + (3))) = temp_r2_14065;
    (*(u16 *)((u8 *)(var_r6_14045) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(var_r6_14045) + (4)))) | (0x3FF & (*(u16 *)((u8 *)(arg0) + (0xC)))));
    temp_r3_14078 = -0x11 & temp_r2_14065;
    (*(u8 *)((u8 *)(var_r6_14045) + (3))) = temp_r3_14078;
    (*(u8 *)((u8 *)(var_r6_14045) + (5))) = (u8) (((-0xD & (*(u8 *)((u8 *)(var_r6_14045) + (5)))) | 4) & 0xF);
    temp_r4_14090 = temp_r4_14056 | 0x10;
    (*(u8 *)((u8 *)(var_r6_14045) + (1))) = temp_r4_14090;
    if ((u32) (u8) ((*(u8 *)((u8 *)(temp_r7_14037) + (0x28))) - 3) <= 1U) {
        (*(u8 *)((u8 *)(var_r6_14045) + (3))) = (u8) (-0xF & temp_r3_14078);
        (*(u8 *)((u8 *)(var_r6_14045) + (1))) = (u8) (((temp_r4_14090 & ~3) | 1) & ~0xC);
        sp0 = (u16) ((sp0 & 0xFFFF0000) | 0x100) | 0x01000000;
        if ((*(u8 *)((u8 *)(temp_r7_14037) + (0x29))) == 0) {
            sp4 = (sp4 & 0xFFFF0000) | (*(u16 *)((u8 *)(temp_r7_14037) + (0x10)));
        } else {
            sp4 = (sp4 & 0xFFFF0000) | (u16) (0 - (*(u16 *)((u8 *)(temp_r7_14037) + (0x10))));
        }
        ObjAffineSet((struct ObjAffineSrcData *) &sp0, &sp8, 1, 2);
        (*(u16 *)((u8 *)(gUnk3002410) + (6))) = (u16) (*(u16 *)((u8 *)(&sp8) + (0)));
        (*(u16 *)((u8 *)(gUnk3002410) + (0xE))) = (u16) (*(u16 *)((u8 *)(&sp8) + (2)));
        temp_r6_14164 = &gUnk3002410[8] + 8;
        (*(u16 *)((u8 *)(temp_r6_14164) + (6))) = (u16) (*(u16 *)((u8 *)(&sp8) + (4)));
        (*(u16 *)((u8 *)(temp_r6_14164) + (0xE))) = (u16) (*(u16 *)((u8 *)(&sp8) + (6)));
        var_r6_14045 = (gGameState.unk_860 * 8) + gUnk3002410;
    }
    if ((*(u8 *)((u8 *)(temp_r7_14037) + (0x29))) == 0) {
        var_r1_14195 = (*(s32 *)((u8 *)(arg0) + (8))) + (*(u32 *)(0x03003C00 + temp_r0_14035) - gGameState.unk_844) + (*(u16 *)((u8 *)(temp_r7_14037) + (0x16))) + (*(u16 *)((u8 *)(temp_r7_14037) + (0x1A)));
    } else {
        var_r1_14195 = (((*(s32 *)((u8 *)(arg0) + (8))) + (*(u32 *)(0x03003C00 + temp_r0_14035) - gGameState.unk_844)) - (*(u16 *)((u8 *)(temp_r7_14037) + (0x16)))) - (*(u16 *)((u8 *)(temp_r7_14037) + (0x1A)));
    }
    (*(u16 *)((u8 *)(var_r6_14045) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(var_r6_14045) + (2)))) | (var_r1_14195 & 0x1FF));
    (*(s8 *)((u8 *)(var_r6_14045) + (0))) = (s8) ((*(s32 *)((u8 *)(arg0) + (4))) + ((*(s32 *)((u8 *)(temp_r7_14037) + (4))) - (*(u8 *)((u8 *)(&gGameState) + (0x846)))) + (*(u8 *)((u8 *)(temp_r7_14037) + (0x18))));
    gGameState.unk_860 += 1;
}

void sub_0201EF44(s32 arg0) {
    s32 temp_r1_14270;
    void *temp_r3_14265;

    temp_r3_14265 = (arg0 * 0x30) + 0x03003C00;
    temp_r1_14270 = (*(s32 *)((u8 *)(temp_r3_14265) + (4)));
    if ((temp_r1_14270 >= (s32) gGameState.unk_846) && (temp_r1_14270 <= (s32) (gGameState.unk_846 + 0xC8)) && (((*(u8 *)((u8 *)(temp_r3_14265) + (0x28))) != 3) || !(2 & (*(u8 *)((u8 *)(temp_r3_14265) + (0x26)))))) {
        sub_0201ED68((*(u32 *)(0x0202FEE0 + (s32) (((*(u16 *)((u8 *)(temp_r3_14265) + (0xC))) * 8) + (*(u8 *)((u8 *)(temp_r3_14265) + (0x25))))) * 0x10) + 0x0202FF78, arg0);
    }
}

s32 Islander_StoreItem(u16 arg0, u16 arg1) {
    s32 temp_r1_14347;
    s32 var_r2_14336;
    u16 *var_r1_14340;
    u16 *var_r4_14338;
    u16 temp_r3_14318;
    u16 var_r0_14353;
    void *temp_r1_14326;

    temp_r3_14318 = arg0;
    temp_r1_14326 = (temp_r3_14318 * 0xC) + 0x0202F7FC;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = 0x800000;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = (s32) ((*(u16 *)((u8 *)(temp_r1_14326) + (4))) | 0x800000);
    if ((*(u16 *)((u8 *)(temp_r1_14326) + (8))) != 4) {
        var_r2_14336 = 0;
        var_r4_14338 = (void *)0x030041A0 + 0x64;
        var_r1_14340 = (void *)0x030041A0 + 0x5A;
loop_2:
        if (*var_r1_14340 == 0) {
            *var_r1_14340 = temp_r3_14318 + 1;
            temp_r1_14347 = arg1 * 4;
            if ((*(u8 *)((u8 *)((temp_r1_14347 + 0x02034CF4)) + (3))) == 0) {
                var_r0_14353 = *(u32 *)(0x02034CF4 + temp_r1_14347);
            } else {
                var_r0_14353 = Item_TypeToIslandItem(*(u32 *)(0x02034CF4 + temp_r1_14347));
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

s16 Islander_GetFishingItem(void) {
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
    var_r0_14400 = rand_u16(&gGameState);
    temp_r1_14401 = var_r0_14400;
    if ((s32) temp_r1_14401 < 0) {
        var_r0_14400 = temp_r1_14401 + 7;
    }
    temp_r4_14411 = (var_r4_14389 + (temp_r1_14401 - (((s32) var_r0_14400 >> 3) * 8))) & 0x3F;
    temp_r3_14413 = temp_r4_14411 * 2;
    temp_r2_14415 = *(u32 *)(0x020338FC + temp_r3_14413);
    if ((u32) (u16) (temp_r2_14415 - 0x7E) > 1U) {
        if ((temp_r2_14415 != 0x25) && (*(u16 *)0x03004202 != 0)) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = 0x800000;
            var_r0_14441 = (*(u16 *)((u8 *)(((*(u32 *)(0x0203397C + temp_r3_14413) * 0xC) + 0x0202F7FC)) + (4)));
            goto block_12;
        }
        temp_r1_14451 = temp_r4_14411 * 2;
        Islander_StoreItem(*(u32 *)(0x0203397C + temp_r1_14451), *(u32 *)(0x020338FC + temp_r1_14451));
        return 0;
    }
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = 0x800000;
    if (temp_r2_14415 == 0x7F) {
        var_r0_14441 = 0x434E;
    } else {
        var_r0_14441 = 0x4350;
    }
block_12:
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = (s32) (var_r0_14441 | 0x800000);
    return 0xFE;
}

s32 sub_0201F0FC(u8 arg0) {
    s32 sp0;
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
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
    if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
        var_r5_14540 = 0x0600A000;
        temp_r2_14542 = temp_r3_14520 * 2;
        (*(u16 *)((u8 *)(&sp0) + (0))) = (u16) *(u32 *)(0x03003720 + temp_r2_14542);
        if (temp_r1_14514 > (u32) (temp_r3_14520 & 0xF)) {
            var_r5_14540 = 0x0600A800;
            (*(u16 *)((u8 *)(&sp0) + (0))) = (u16) *(u32 *)(0x03003920 + temp_r2_14542);
        }
        var_r6_14562 = 0x0600A000;
        var_r1_14566 = (temp_r2_14526 * 2) + 0x03003720;
        goto block_6;
    }
    *(s16 *)0x0300421A = 0x8000;
    var_r5_14540 = 0x0600A800;
    (*(u16 *)((u8 *)(&sp0) + (0))) = (u16) *(u32 *)(0x03003920 + (temp_r3_14520 * 2));
    var_r6_14562 = 0x0600A800;
    temp_r3_14590 = temp_r2_14526 * 2;
    (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *(u32 *)(0x03003920 + temp_r3_14590);
    if (temp_r1_14514 < (u32) (temp_r2_14526 & 0xF)) {
        var_r6_14562 = 0x0600A000;
        var_r1_14566 = temp_r3_14590 + 0x03003720;
block_6:
        (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *var_r1_14566;
    }
    sp4 = (void *)0x030041A0 + 0x8E;
    (*(u16 *)((u8 *)((void *)0x030041A0) + (0x7A))) = (u16) ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) | (*(u16 *)((u8 *)((void *)0x030041A0) + (0x7A))));
    temp_r3_14619 = temp_r3_14520 & 0xF0;
    sp8 = temp_r3_14619;
    temp_r1_14626 = temp_r3_14520 & 0xF;
    temp_r2_14629 = (temp_r1_14626 * 4) + (var_r5_14540 + (temp_r3_14619 * 8));
    temp_r6_14639 = var_r6_14562 + ((temp_r2_14526 & 0xF0) * 8) + ((temp_r2_14526 & 0xF) * 4);
    sp10 = temp_r2_14629;
    temp_r0_14644 = CheckSurroundingCollision((*(u16 *)((u8 *)(&sp0) + (0))), temp_r2_14629);
    spC = sp4;
    if ((temp_r0_14644 != 0) || (temp_r1_14652 = 0x3FF & *temp_r2_14629, (temp_r1_14652 <= 5U)) || ((u32) (u16) (temp_r1_14652 - 0x10) <= 5U) || (temp_r1_14652 > 0xAFU)) {
        if ((CheckSurroundingCollision((*(u16 *)((u8 *)(&sp0) + (2))), temp_r6_14639) != 0) || (temp_r2_14674 = 0x3FF & *temp_r6_14639, (temp_r2_14674 <= 5U)) || ((u32) (u16) (temp_r2_14674 - 0x10) <= 5U) || (temp_r2_14674 > 0xAFU)) {
            (*(u16 *)((u8 *)((void *)0x030041A0) + (0x7A))) = 0U;
            return 0;
        }
        if ((s32) temp_r6_14639 & 0x800) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0x10000;
        }
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0x70;
        temp_r1_14711 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r1_14711;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (temp_r1_14711 | (((0xF & *spC) << 0xC) + 0x800));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((0xF0 & *spC) << 8) + 0x800);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) | (((temp_r2_14526 & 0xF) << 0xC) + 0x800));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = (s32) (((temp_r2_14526 & 0xF0) << 8) + 0x800);
        return temp_r2_14526;
    }
    if ((s32) temp_r2_14629 & 0x800) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0x10000;
    }
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0x60;
    temp_r1_14761 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r1_14761;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (temp_r1_14761 | (((0xF & *sp4) << 0xC) + 0x800));
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((0xF0 & *sp4) << 8) + 0x800);
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) | ((temp_r1_14626 << 0xC) + 0x800));
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = (s32) ((sp8 << 8) + 0x800);
    return temp_r3_14520;
}

s32 sub_0201F368(void) {
    s32 var_r2_14825;
    s32 var_r5_14808;
    u8 temp_r0_14835;

    sub_0201F538(*(u8 *)0x0300422B);
    var_r5_14808 = 0;
loop_1:
    if (CheckSurroundingCollision(*(u32 *)(0x030041E8 + (var_r5_14808 * 2)), (*(u16 **)((u8 *)((void *)0x030041A0) + (0x44)))) == 0) {
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
            var_r2_14825 = 0x0600A000;
        } else {
            var_r2_14825 = 0x0600A800;
        }
        temp_r0_14835 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)));
        if ((u32) (u16) ((*(u32 *)(((0xF0 & temp_r0_14835) * 8) + var_r2_14825 + ((0xF & temp_r0_14835) * 4) + *(u32 *)(0x02033A1C + (var_r5_14808 * 4))) & 0x3FF) - 0x20) > 0x5EU) {
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

s32 Islander_ChangeMoveDir(s32 arg0, s32 arg1, u8 arg2) {
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
    temp_r1_14888 = arg0 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = temp_r1_14888;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) (arg1 - (*(s32 *)((u8 *)((void *)0x030041A0) + (4))));
    if (temp_r1_14888 < 0) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) (0 - temp_r1_14888);
    }
    temp_r0_14898 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24)));
    if (temp_r0_14898 < 0) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) (0 - temp_r0_14898);
    }
    if (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) <= 0x100) && ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) <= 0x100)) {
        return 1;
    }
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) ((s32) (arg0 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)))) >> 8);
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) ((s32) (arg1 - (*(s32 *)((u8 *)((void *)0x030041A0) + (4)))) >> 8);
    temp_sb_14928 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B)));
    if (temp_r7_14885 != 0) {
        if (temp_r7_14885 != 1) {
            sub_020207C0(1U, arg0);
            sub_02020814(1U, arg1);
            temp_r3_14946 = ArcTan2((s16) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))), (s16) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))));
            if ((u32) temp_r3_14946 < (u32) *(u16 *)0x020338F8) {
                var_r2_14951 = 0;
                if ((u32) temp_r3_14946 > (u32) *(u16 *)0x020338DC) {
loop_18:
                    var_r2_14951 += 1;
                    if (var_r2_14951 <= 6) {
                        if ((u32) temp_r3_14946 <= (u32) *(u32 *)(0x020338DC + (var_r2_14951 * 4))) {

                        } else {
                            goto loop_18;
                        }
                    }
                }
            } else {
                var_r2_14951 = 0;
            }
            temp_r2_15006 = (*(u8 *)((u8 *)(((var_r2_14951 * 4) + 0x020338DC)) + (2)));
            var_r1_15009 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) - temp_r2_15006;
            if (0x80 & var_r1_15009) {
                var_r1_15009 = (u8) ((u32) ((~var_r1_15009 << 0x18) + 0x01000000) >> 0x18);
            }
            if ((u32) (u8) (var_r1_15009 - 2) <= 4U) {
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r2_15006;
            }
        } else {
            temp_r0_14974 = sub_02020814(0U, arg1);
            if (temp_r0_14974 != 0) {
                sub_020207C0(0U, arg0);
                var_r0_14963 = 0;
                goto block_16;
            }
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = temp_r0_14974;
        }
    } else {
        var_r0_14963 = sub_020207C0(0U, arg0);
        if (var_r0_14963 != 0) {
            sub_02020814(0U, arg1);
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) temp_r7_14885;
        } else {
block_16:
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = var_r0_14963;
        }
    }
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) != temp_sb_14928) {
        Islander_AdjustAnimForTool();
    }
    return 0;
}

void sub_0201F538(u8 arg0) {
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

    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8E))) = (s8) ((u32) (((((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) >> 8) & 0xFF0 & 0xF0) << 0x14) | ((((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) >> 8) & 0xFF0) << 0x18)) >> 0x18);
    var_r5_15071 = 0;
    var_r4_15079 = (void *)0x030041A0 + 0x48;
    var_r6_15081 = 0x01000000;
    do {
        temp_r3_15089 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) + *(u32 *)(0x020339FC + ((u32) (var_r5_15071 << 0x19) >> 0x16));
        temp_r1_15108 = (u32) ((((temp_r3_15089 >> 8) & 0xF0) << 0x14) | ((((s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (4))) + *(u32 *)(0x020339FC + ((var_r6_15081 >> 0x18) * 4))) >> 8) & ~0xF) << 0x18)) >> 0x18;
        if (!(temp_r3_15089 & 0xFF0000)) {
            (*(s16 *)((u8 *)(var_r4_15079) + (8))) = (s16) temp_r1_15108;
            var_r0_15119 = *(u32 *)(0x03003720 + (temp_r1_15108 * 2));
        } else {
            (*(s16 *)((u8 *)(var_r4_15079) + (8))) = (s16) temp_r1_15108;
            var_r0_15119 = *(u32 *)(0x03003920 + (temp_r1_15108 * 2));
        }
        (*(u16 *)((u8 *)(var_r4_15079) + (0))) = var_r0_15119;
        var_r4_15079 += 2;
        var_r6_15081 += 0x02000000;
        var_r5_15071 += 1;
    } while (var_r5_15071 <= 3);
    temp_r1_15142 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) + 0xFFFFFE00;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = temp_r1_15142;
    temp_r0_15147 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) + 0x200;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = temp_r0_15147;
    temp_r2_15160 = ((temp_r0_15147 >> 8) & 0xFF0) | ((s32) ((temp_r1_15142 >> 8) & 0xFF0 & 0xF0) >> 4);
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8F))) = temp_r2_15160;
    if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) & 0xFF0000)) {
        var_r1_15169 = 0x0600A000;
    } else {
        var_r1_15169 = 0x0600A800;
    }
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x44))) = (s32) (((temp_r2_15160 & 0xF0) * 8) + var_r1_15169 + ((temp_r2_15160 & 0xF) * 4));
}

void WriteItemToTile(s32 arg0, u8 arg1, u16 arg2, u16 arg3) {
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
        var_r2_15219 = *(u32 *)0x03001B40 + 0x224;
    }
    *(u32 *)(var_r2_15219 + var_r1_15218) = arg2;
    WriteItemTileToVRAM(var_r3_15210 + ((0xF0 & temp_r5_15200) * 8) + ((0xF & temp_r5_15200) * 4), arg3);
}

s32 CheckSurroundingCollision(u16 arg0, u16 *arg1) {
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
        (*(s8 *)((u8 *)(var_r1_15367) + (0))) = 0;
        (*(u8 *)((u8 *)(var_r1_15367) + (8))) = (u8) ((*(u8 *)((u8 *)(var_r1_15367) + (8))) | 0xFF);
        var_r1_15367 += 1;
        var_r4_15368 -= 1;
    } while (var_r4_15368 >= 0);
    *(u32 *)(0x03004242 + *(u8 *)0x0300422B) = 1;
    if (arg0 == 0) {
        temp_r0_15386 = *(u8 *)0x0300422B;
        var_r4_15387 = temp_r0_15386 + 4;
        if (var_r4_15387 > 7) {
            var_r4_15387 = temp_r0_15386 - 4;
        }
        *(u32 *)(0x03004242 + var_r4_15387) = 1;
    }
    var_r4_15395 = NULL;
    do {
        if ((*(u32 *)(0x03004242 + (s32) var_r4_15395) == 0) && (sub_0201F844((u8) var_r4_15395) == 0)) {
            *(u32 *)(0x03004242 + (s32) var_r4_15395) = 1U;
        }
        var_r4_15395 += 1;
    } while ((s32) var_r4_15395 <= 7);
    var_r4_15412 = NULL;
    var_r5_15413 = NULL;
    do {
        if (*(u32 *)(0x03004242 + (s32) var_r4_15412) == 0) {
            *(u32 *)(0x0300424A + (s32) var_r5_15413) = (s8) var_r4_15412;
            var_r5_15413 += 1;
        }
        var_r4_15412 += 1;
    } while ((s32) var_r4_15412 <= 7);
    if (var_r5_15413 != NULL) {
        return *(u32 *)(0x0300424A + ((s32) rand_u16(&gGameState) % (s32) var_r5_15413));
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
    temp_r3_15467 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) + *(u32 *)(0x02033A2C + (temp_r0_15456 * 8));
    temp_r4_15487 = ((temp_r3_15467 >> 0xC) & 0xF) | (((s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (4))) + (*(u32 *)(0x02033A2C + (((temp_r0_15456 * 2) + 1) * 4)) + 0x800)) >> 8) & ~0xF);
    if (!(temp_r3_15467 & 0xFF0000)) {
        var_r1_15499 = (void *)0x030041A0 + 0x48;
        (*(u16 *)((u8 *)((void *)0x030041A0) + (0x48))) = (u16) *(u32 *)(0x03003720 + (temp_r4_15487 * 2));
        var_r2_15501 = 0x0600A000;
    } else {
        var_r1_15499 = (void *)0x030041A0 + 0x48;
        (*(u16 *)((u8 *)((void *)0x030041A0) + (0x48))) = (u16) *(u32 *)(0x03003920 + (temp_r4_15487 * 2));
        var_r2_15501 = 0x0600A800;
    }
    temp_r2_15527 = ((0xF0 & temp_r4_15487) * 8) + var_r2_15501 + ((0xF & temp_r4_15487) * 4);
    (*(u16 **)((u8 *)((void *)0x030041A0) + (0x44))) = temp_r2_15527;
    if (CheckSurroundingCollision(*var_r1_15499, temp_r2_15527) == 0) {
        return 1;
    }
    return 0;
}

void Islander_BuryRandomItem(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    BuriedItemUpdateGroup *buried_item_update;
    ItemGeneratorDef *generator_def;
    ItemGroupStruct *item_definition;
    Island_agb_c *island_data;
    u16 *deposit;
    mActor_name_t buried_item;
    s32 update_idx;
    u8 generator_idx;
    u8 tile_idx = islander->world_state;
    s32 group_idx;

    for (group_idx = 0; group_idx < ARRAY_COUNT(gBuriedItemRngTileGroups); group_idx++) {
        if (item_type == ((u16 *)gBuriedItemRngTileGroups)[(u8)(group_idx * 5)]) {
            item_type = ((u16 *)gBuriedItemRngTileGroups)[(u8)((group_idx * 5) + 1 + islander->emotion)];
            break;
        }
    }

    if (group_idx >= ARRAY_COUNT(gBuriedItemRngTileGroups)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }
    if ((islander->state & 0xF) == 7) {
        item_type += 0x10;
    }

    item_type += rand_u16(&gGameState) % 4;
    if (item_type >= 0x120) {
        item_type = 0;
    }

    generator_idx = gBuriedItemGeneratorIndices[item_type];
    generator_def = &gItemGeneratorDefs[generator_idx];
    item_definition = &g_ItemDefinitions[generator_def->item_type];

    if ((item_definition->default_generator_idx == 0xFFF) || (generator_idx == 0xD)) {
        islander->item_work.held_item.type_idx = ITEM_TYPE_TRASH;
        return;
    }

    islander->_40 = item_definition->held_item_oam_attr2 | 0x800000;

    if (IS_ITEM_TYPE_FRUIT(generator_def->item_type)) {
        islander->_7C[0] = 0x3260;
        if (generator_def->item_type == ITEM_TYPE_COCONUT) {
            islander->_7C[0] = 0x3268;
        }

        for (update_idx = 0; update_idx < 6; update_idx++) {
            buried_item_update = &gBuriedItemUpdateGroups[update_idx];
            if (buried_item_update->item_type == generator_def->item_type) {
                break;
            }
        }

        if ((islander->world_state & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = 0x7777;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[0][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = 0x7777;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item_update->buried_item;
            gIslandData->deposit[1][tile_idx >> 4] &= ~(1 << (tile_idx & 0xF));
        }
    } else {
        islander->_7C[0] = 0x1270;
        if (generator_def->use_island_id == 0) {
            buried_item = generator_def->item;
        } else {
            buried_item = Item_TypeToIslandItem(generator_def->item);
        }

        if ((islander->world_state & 0x8000) == 0) {
            field->fg_tiles[0][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[0][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        } else {
            field->fg_tiles[1][tile_idx] = generator_def->item_type + 0x8000;
            gIslandData->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = buried_item;
            gIslandData->deposit[1][tile_idx >> 4] |= (1 << (tile_idx & 0xF));
        }
    }
}
void Islander_PlantRandomFlower(void) {
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
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = 0x800000;
    temp_r7_15909 = (u8) ((s32) rand_u16(&gGameState) % 9);
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) | 0x5344);
    if (!(0x8000 & (u16) *(u8 *)0x0300421A)) {
        *(u32 *)(0x03003720 + (temp_r6_15899 * 2)) = 0x7777;
        temp_r3_15929 = *(s32 *)0x03001B40;
        var_r5_15931 = 0xF & temp_r6_15899;
        temp_r4_15933 = temp_r4_15898 >> 0x1C;
        var_r6_15940 = temp_r7_15909 * 2;
        *(u32 *)(temp_r3_15929 + 0x24 + ((var_r5_15931 * 2) + (temp_r4_15933 << 5))) = *(u32 *)(0x02033F80 + var_r6_15940);
        var_r4_15944 = temp_r4_15933 * 2;
        var_r3_15946 = temp_r3_15929 + 0x18F8;
    } else {
        *(u32 *)(0x03003920 + (temp_r6_15899 * 2)) = 0x7777;
        temp_r3_15966 = *(u32 *)0x03001B40;
        var_r5_15931 = 0xF & temp_r6_15899;
        temp_r4_15970 = temp_r4_15898 >> 0x1C;
        var_r6_15940 = temp_r7_15909 * 2;
        *(u32 *)(temp_r3_15966 + 0x224 + ((var_r5_15931 * 2) + (temp_r4_15970 << 5))) = *(u32 *)(0x02033F80 + var_r6_15940);
        var_r4_15944 = temp_r4_15970 * 2;
        var_r3_15946 = temp_r3_15966 + 0x1918;
    }
    temp_r3_15986 = var_r3_15946 + var_r4_15944;
    *temp_r3_15986 &= ~(1 << var_r5_15931);
    (*(u16 *)((u8 *)((void *)0x030041A0) + (0x7C))) = (u16) *(u32 *)(0x0202F8EC + ((var_r6_15940 + temp_r7_15909) * 4));
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
                var_r0_16054 = ((s32) rand_u16(&gGameState) % 65) + 0x20;
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

    temp_r0_16078 = (s32) (arg0 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)))) >> 8;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = temp_r0_16078;
    temp_r1_16082 = (s32) (arg1 - (*(s32 *)((u8 *)((void *)0x030041A0) + (4)))) >> 8;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = temp_r1_16082;
    temp_r2_16090 = ArcTan2((s16) temp_r0_16078, (s16) temp_r1_16082);
    if ((u32) temp_r2_16090 < (u32) *(u16 *)0x020338F8) {
        var_r1_16095 = 0;
        var_r5_16098 = (void *)0x030041A0 + 0x94;
        if ((u32) temp_r2_16090 > (u32) *(u16 *)0x020338DC) {
loop_3:
            var_r1_16095 += 1;
            if (var_r1_16095 <= 6) {
                if ((u32) temp_r2_16090 <= (u32) *(u32 *)(0x020338DC + (var_r1_16095 * 4))) {

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
        temp_r0_16129 = (*(u8 *)((u8 *)(((var_r1_16095 * 4) + 0x020338DC)) + (2)));
        if (temp_r0_16129 != (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B)))) {
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r0_16129;
            Islander_AdjustAnimForTool();
            *var_r5_16098 = 0x20;
        }
    }
    temp_r0_16138 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20)));
    if (temp_r0_16138 < 0) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) (0 - temp_r0_16138);
    }
    temp_r0_16144 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24)));
    if (temp_r0_16144 < 0) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) (0 - temp_r0_16144);
    }
    if (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) <= 1) && ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) <= 1)) {
        temp_r2_16160 = ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) >> 8) & 0xFF0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = temp_r2_16160;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) >> 8) & 0xFF0);
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8E))) = (s8) temp_r2_16160;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8E))) = (s8) (((s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) & 0xF0) >> 4) | temp_r2_16160);
        return 1;
    }
    return 0;
}

s32 Islander_PlayAnim(u8 arg0) {
    u8 temp_r0_16196;

    temp_r0_16196 = *(u8 *)0x0300422A - 1;
    *(u8 *)0x0300422A = temp_r0_16196;
    if (temp_r0_16196 & 0x80) {
        *(u8 *)0x03004229 += 1;
        if ((*(u8 *)((u8 *)(*(u32 *)((*(u8 *)0x03004229 * 4) + *(u32 *)(0x02033680 + (*(u8 *)0x03004228 * 4)))) + (6))) == 0xFF) {
            *(u8 *)0x03004229 = 0;
            if (arg0 == 1) {
                return 1;
            }
        }
        *(u32 *)0x0300422A = (u8) (*(u16 *)((u8 *)(*(u32 *)((*(u8 *)0x03004229 * 4) + *(u32 *)(0x02033680 + (*(u8 *)0x03004228 * 4)))) + (4)));
        goto block_5;
    }
block_5:
    return 0;
}

void Islander_ClearStoredItem(s32 arg0) {
    s32 temp_r1_16285;
    s32 temp_r2_16257;
    s32 temp_r2_16272;
    s32 temp_r7_16276;
    s32 var_r1_16267;
    u16 temp_r3_16282;

    temp_r2_16257 = arg0 * 2;
    *(u32 *)(0x030041FA + temp_r2_16257) = 0;
    *(u32 *)(0x03004204 + temp_r2_16257) = 0;
    var_r1_16267 = arg0;
    if (var_r1_16267 <= 3) {
        do {
            temp_r2_16272 = var_r1_16267 * 2;
            temp_r7_16276 = var_r1_16267 + 1;
            if (*(u32 *)(0x030041FA + temp_r2_16272) == 0) {
                temp_r3_16282 = *(u32 *)(0x03004204 + temp_r2_16272);
                if (temp_r3_16282 == 0) {
                    temp_r1_16285 = temp_r7_16276 * 2;
                    *(u32 *)(0x030041FA + temp_r2_16272) = (u16) *(u32 *)(0x030041FA + temp_r1_16285);
                    *(u32 *)(0x03004204 + temp_r2_16272) = (u16) *(u32 *)(0x03004204 + temp_r1_16285);
                    *(u32 *)(0x030041FA + temp_r1_16285) = temp_r3_16282;
                    *(u32 *)(0x03004204 + temp_r1_16285) = temp_r3_16282;
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
    if ((*(u8 *)((u8 *)(temp_r0_16319) + (0x41A))) == 0) {
        temp_r1_16327 = 0x54 * var_r3_16317;
        temp_r4_16329 = temp_r1_16327 + 0x03004790;
        (*(u8 *)((u8 *)(temp_r0_16319) + (0x41A))) = 1U;
        Unk_Struct_Size54_ResetIdx(var_r3_16317);
        (*(s16 *)((u8 *)(temp_r4_16329) + (0x40))) = (s16) arg1;
        (*(u8 *)((u8 *)((temp_r4_16329 + 0x40)) + (0xB))) = arg0;
        (*(s8 *)((u8 *)(temp_r4_16329) + (0x4E))) = 5;
        *(u32 *)(0x03004790 + temp_r1_16327) = (s32) ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) >> 8);
        (*(s32 *)((u8 *)(temp_r4_16329) + (4))) = (s32) ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) >> 8);
        return 1;
    }
    var_r3_16317 += 1;
    if (var_r3_16317 > 0xB) {
        return 0;
    }
    goto loop_1;
}

s32 SpawnEntity(u8 arg0, u8 arg1, u16 arg2, u16 arg3) {
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
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
            var_r2_16399 = (void *)0x030041A0 + 0x8E;
            temp_r3_16405 = *(u32 *)(0x03003720 + ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2));
            if ((temp_r3_16405 != 0xFFF) && (temp_r3_16405 != 0x3333)) {
                goto block_27;
            }
            var_r4_16414 = 0x0600A000;
            goto block_10;
        }
        var_r2_16399 = (void *)0x030041A0 + 0x8E;
        temp_r3_16431 = *(u32 *)(0x03003920 + ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2));
        if ((temp_r3_16431 != 0xFFF) && (temp_r3_16431 != 0x3333)) {
            goto block_27;
        }
        var_r4_16414 = 0x0600A800;
block_10:
        temp_r1_16442 = *var_r2_16399;
        temp_r4_16450 = var_r4_16414 + ((0xF0 & temp_r1_16442) * 8) + ((0xF & temp_r1_16442) * 4);
        if (CheckSurroundingCollision(0U, temp_r4_16450) != 0) {
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
    if (*(u32 *)(0x03003B27 + (s32) var_r5_16482) == 0) {
        temp_r1_16492 = 0x54 * var_r6_16481;
        temp_r4_16494 = temp_r1_16492 + 0x03004790;
        temp_r3_16500 = (temp_r2_16382 * 0xC) + 0x0202F7FC;
        sp8 = temp_r3_16500;
        Unk_Struct_Size54_ResetIdx(var_r6_16481);
        *(u32 *)(0x03004790 + temp_r1_16492) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) >> 8) - 8);
        (*(s32 *)((u8 *)(temp_r4_16494) + (4))) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) >> 8) - 0x10);
        if (var_sb_16380 == 0) {
            (*(s8 *)((u8 *)(temp_r4_16494) + (0x4E))) = 7;
        } else {
            (*(s8 *)((u8 *)(temp_r4_16494) + (0x4E))) = 9;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x9E))) = (s8) var_r6_16481;
        }
        *(u32 *)(0x03003B27 + (s32) var_r5_16482) = 1U;
        (*(u16 *)((u8 *)(temp_r4_16494) + (0x28))) = temp_r2_16382;
        (*(u16 *)((u8 *)(temp_r4_16494) + (0x32))) = (u16) (*(u16 *)((u8 *)(&sp0) + (4)));
        (*(u8 *)((u8 *)(temp_r4_16494) + (0x4A))) = (u8) (*(u8 *)((u8 *)(&sp0) + (0)));
        temp_r2_16556 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)));
        (*(s16 *)((u8 *)(temp_r4_16494) + (0x3C))) = (s16) temp_r2_16556;
        if ((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000) {
            (*(s16 *)((u8 *)(temp_r4_16494) + (0x3C))) = (s16) (temp_r2_16556 | 0x1000);
        }
        (*(s16 *)((u8 *)(temp_r4_16494) + (0x3E))) = (s16) ((*(u16 *)((u8 *)(temp_r3_16500) + (4))) & 0x3FF);
        (*(s8 *)((u8 *)(temp_r4_16494) + (0x50))) = (s8) ((u16) (*(u16 *)((u8 *)(temp_r3_16500) + (4))) >> 0xC);
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

    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) = arg1;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = arg2;
    if ((arg1 == 0) && (arg2 == 0)) {
        return 0;
    }
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((0xF0 & (*(u16 *)((u8 *)(arg0) + (0xE)))) << 8) + 0x800);
    (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = 0;
    if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) != 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) != 0)) {
        var_r2_16642 = (void *)0x030041A0 + 0x28;
        var_r4_16644 = (void *)0x030041A0 + 0x30;
        var_r5_16645 = 1;
        do {
            temp_r1_16649 = *var_r4_16644 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
            *var_r2_16642 = temp_r1_16649;
            if (temp_r1_16649 < 0) {
                *var_r2_16642 = 0;
            }
            var_r2_16642 += 4;
            var_r4_16644 += 4;
            var_r5_16645 -= 1;
        } while (var_r5_16645 >= 0);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) + 0x500);
        *(s8 *)0x03004239 = 0x40;
        if ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))) > (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C)))) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34)));
            *(s8 *)0x03004239 = 0x30;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) + 0xA00);
        }
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = 0;
    } else {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) + 0x500);
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0x40;
        temp_r0_16698 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34)));
        if (temp_r0_16698 != 0) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r0_16698;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0x30;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) + 0xA00);
        }
        temp_r0_16710 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = temp_r0_16710;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
        temp_r0_16715 = temp_r0_16710 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r0_16715;
        if (temp_r0_16715 < 0) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (0 - temp_r0_16715);
        }
        temp_r2_16722 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C)));
        temp_r0_16723 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4)));
        temp_r1_16724 = temp_r2_16722 - temp_r0_16723;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = temp_r1_16724;
        if (temp_r1_16724 < 0) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (0 - temp_r1_16724);
        }
        if (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) <= 0xFFF) && ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) <= 0xFFF)) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = temp_r2_16722;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = 0;
        } else {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = 0;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = 0;
            if ((*(u8 *)((u8 *)(arg0) + (0x24))) != 0) {
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = 0x10000;
            }
            if ((s32) ((*(s32 *)((u8 *)(arg0) + (4))) << 8) > temp_r0_16723) {
                temp_r4_16767 = (u8) (*(u16 *)((u8 *)(arg0) + (0xE))) - 0x10;
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) | (((0xF & temp_r4_16767) << 0xC) + 0x800));
                var_r0_16781 = ((temp_r4_16767 & 0xF0) << 8) + 0x0FFFF400;
            } else {
                temp_r4_16789 = (u8) (*(u16 *)((u8 *)(arg0) + (0xE))) + 0x10;
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) | (((0xF & temp_r4_16789) << 0xC) + 0x800));
                var_r0_16781 = ((temp_r4_16789 & 0xF0) << 8) + 0x800;
            }
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = var_r0_16781;
        }
    }
    return 1;
}

s32 sub_0202029C(void *arg0) {
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
    temp_r2_16826 = (*(u16 *)((u8 *)(spC) + (0xE)));
    temp_r7_16830 = 0xF & temp_r2_16826;
    temp_r6_16831 = temp_r7_16830 + 1;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))) = temp_r6_16831;
    temp_r1_16833 = temp_r6_16831 << 0xC;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) = temp_r1_16833;
    temp_r2_16837 = (*(u8 *)((u8 *)(arg0) + (0x24)));
    if (temp_r2_16837 == 0) {
        sp4 = 0x0600A000;
        (*(u16 *)((u8 *)(&sp0) + (0))) = *(u32 *)(0x03003720 + (((0xF0 & temp_r2_16826) + temp_r6_16831) * 2));
        if (temp_r6_16831 == 0x10) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))) = (s32) temp_r2_16837;
            sp4 = 0x0600A800;
            (*(u16 *)((u8 *)(&sp0) + (0))) = *(u32 *)(0x03003920 + ((0xF0 & temp_r2_16826) * 2));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) = 0x10000;
        }
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))) = (s32) ((0xF0 & temp_r2_16826) + (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))));
        temp_r3_16883 = (*(u16 *)((u8 *)(spC) + (0xE)));
        temp_r0_16886 = (0xF & temp_r3_16883) - 1;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) = temp_r0_16886;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = (s32) (temp_r0_16886 << 0xC);
        (*(s32 *)((u8 *)(&sp4) + (4))) = 0x0600A000;
        temp_r1_16896 = (0xF0 & temp_r3_16883) + temp_r0_16886;
        (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *(u32 *)(0x03003720 + (temp_r1_16896 * 2));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) = temp_r1_16896;
    } else {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))) = (s32) (temp_r1_16833 | 0x10000);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = 0x10000;
        sp4 = 0x0600A800;
        temp_r1_16921 = temp_r2_16826 & 0xF0;
        temp_r1_16923 = temp_r1_16921 + temp_r6_16831;
        (*(u16 *)((u8 *)(&sp0) + (0))) = *(u32 *)(0x03003920 + (temp_r1_16923 * 2));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x28))) = temp_r1_16923;
        temp_r1_16933 = temp_r7_16830 - 1;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) = temp_r1_16933;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = (s32) ((temp_r1_16933 << 0xC) | 0x10000);
        (*(s32 *)((u8 *)(&sp4) + (4))) = 0x0600A800;
        (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *(u32 *)(0x03003920 + ((temp_r1_16921 + temp_r1_16933) * 2));
        if ((u8) temp_r1_16933 == 0xFF) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) = 0xF;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = 0;
            sp8 = 0x0600A000;
            temp_r2_16962 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C)));
            (*(u16 *)((u8 *)(&sp0) + (2))) = (u16) *(u32 *)(0x03003720 + (((0xF0 & temp_r2_16826) + temp_r2_16962) * 2));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))) = (s32) (temp_r2_16962 << 0xC);
        }
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x2C))) + temp_r1_16921);
    }
    var_r7_16984 = NULL;
    var_r6_16985 = &sp0;
    var_r5_16987 = (void *)0x030041A0 + 0x30;
    var_r8_16989 = 1;
    do {
        temp_r3_16992 = (u8 *)&sp0 + (s32)var_r7_16984;
        temp_r4_16995 = var_r7_16984 + 0x030041C8;
        temp_r2_17001 = (*(u16 **)((u8 *)(temp_r3_16992) + (4))) + ((*(u32 *)(0x030041C8 + (s32) var_r7_16984) & 0xF0) * 8);
        (*(u16 **)((u8 *)(temp_r3_16992) + (4))) = temp_r2_17001;
        temp_r2_17007 = temp_r2_17001 + ((*(u32 *)(0x030041C8 + (s32) var_r7_16984) & 0xF) * 4);
        (*(u16 **)((u8 *)(temp_r3_16992) + (4))) = temp_r2_17007;
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
    return sub_02020118(spC, (*(s32 *)((u8 *)((void *)0x030041A0) + (0x30))), (*(s32 *)((u8 *)((void *)0x030041A0) + (0x34))));
}

s32 Islander_DecideTreeAction(void) {
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
        *(u32 *)0x03004255 = temp_r0_17081;
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
    if ((*var_r3_17118 != 1) || (temp_r1_17124 = var_r4_17116 + 0x03003C00, ((*(u16 *)((u8 *)(temp_r1_17124) + (0xE))) != *(u32 *)(0x030041F0 + ((u32) ((temp_r0_17081 - 1) << 0x18) >> 0x17)))) || ((*(u8 *)((u8 *)(temp_r1_17124) + (0x24))) != ((s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0x10000) >> 0x10))) {
        var_r4_17116 += 0x30;
        var_r3_17118 += 1;
        var_r6_17103 += 1;
        if (var_r6_17103 <= 0x1D) {
            goto loop_9;
        }
    }
    if (var_r6_17103 == 0x1E) {
        *(u32 *)0x03004255 = 0U;
        return 0;
    }
    temp_r0_17158 = *(u32 *)0x03004255;
    if (temp_r0_17158 == 0) {
        temp_r4_17174 = *(u32 *)(0x020338D2 + (u8) (((*(u8 *)((u8 *)((void *)0x030041A0) + (0x90))) * 2) + (*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1)))));
        if ((s32) temp_r4_17174 < (s32) ((s32) rand_u16(&gGameState) % 101)) {
            *(u32 *)0x03004255 = 1U;
            goto block_21;
        }
        (*(u8 *)((u8 *)((void *)0x030041A0) + (0x9B))) = (u8) var_r6_17103;
        (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = (s16) temp_r0_17158;
        temp_r0_17203 = (s32) sub_0202029C(((*(u8 *)((u8 *)((void *)0x030041A0) + (0x9B))) * 0x30) + 0x03003C00);
        if (temp_r0_17203 != 0) {
            (*(u8 *)((u8 *)(((void *)0x030041A0 + 0x8B)) + (1))) = (u8) (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B)));
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 4;
            sub_020218B0();
            return 1;
        }
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r0_17203;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = temp_r0_17203;
        (*(s16 *)((u8 *)((void *)0x030041A0) + (0x7E))) = 0x50;
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
    temp_r2_17251 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) + *(u32 *)(0x02033A84 + temp_r1_17246);
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = temp_r2_17251;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (4))) + (*(s32 *)((u8 *)((temp_r1_17246 + 0x02033A84)) + (4))));
    temp_r0_17259 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x9A)));
    if (temp_r0_17259 != 0) {
        (*(u8 *)((u8 *)((void *)0x030041A0) + (0x9A))) = (u8) (temp_r0_17259 - 1);
        temp_r1_17268 = 0xFFF00 & temp_r2_17251;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (8))) & 0xFFF00) != temp_r1_17268) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = temp_r1_17268;
        }
        temp_r1_17276 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) & 0xFFF00;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) & 0xFFF00) == temp_r1_17276) {
            return;
        }
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = temp_r1_17276;
        return;
    }
    sub_0201F538(*(u8 *)0x0300422B);
    var_r2_17291 = 0;
    var_r5_17292 = 0;
loop_8:
    if (var_r5_17292 <= 3) {
        var_r2_17291 = CheckSurroundingCollision(*(u32 *)((void *)0x030041A0 + 0x48 + (var_r5_17292 * 2)), (*(u16 **)((u8 *)((void *)0x030041A0) + (0x44))));
        if (var_r2_17291 == 0) {
            var_r5_17292 += 1;
            goto loop_8;
        }
    }
    if (var_r5_17292 == 4) {
        temp_r1_17316 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFFF00;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (8))) & 0xFFF00) != temp_r1_17316) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = temp_r1_17316;
        }
        temp_r1_17324 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) & 0xFFF00;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) & 0xFFF00) != temp_r1_17324) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = temp_r1_17324;
        }
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0xB5))) = 0;
        if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xB2))) != 0) {
            temp_r0_17341 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB3))) + 1;
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB3))) = temp_r0_17341;
            if ((u32) temp_r0_17341 > 0x20U) {
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB2))) = 0U;
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB3))) = 0U;
            }
        }
    } else if (var_r2_17291 == 1) {
        if (((u32) (u8) ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) - 3) > 2U) || (*(u8 *)0x03003BAA != (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)))) || (*(u8 *)0x03004BA6 != 1)) {
            if (Islander_DecideTreeAction() == 0) {
                goto block_23;
            }
        } else {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003BC4) + (0))) << 8);
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((*(s32 *)((u8 *)((void *)0x03003BC4) + (4))) << 8) + 0x1000);
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0x20;
            (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = 0;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 4;
            sub_020218B0();
        }
    } else {
block_23:
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (8)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC)));
        temp_r2_17387 = sub_0201F78C(1U);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = 0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = 0;
        temp_r3_17394 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB2))) + 1;
        (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB2))) = temp_r3_17394;
        if ((temp_r2_17387 != 0x777) && ((u32) temp_r3_17394 <= 6U)) {
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r2_17387;
            *(u32 *)(((void *)0x030041A0 + 0xB2) - 0x2B) = 2;
            sub_02021720();
            return;
        }
        (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB2))) = 0U;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0x13;
        Islander_MoveAction20_Init();
    }
}

void Islander_AdjustAnimForTool(void) {
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
    temp_r3_17542 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4)));
    var_r2_17543 = arg1 - temp_r3_17542;
    if (var_r2_17543 < 0) {
        var_r2_17543 = 0 - var_r2_17543;
    }
    if (var_r2_17543 > 0x100) {
        if (arg1 > temp_r3_17542) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (temp_r3_17542 + 0x40);
            if (temp_r1_17539 == 0) {
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r1_17539;
            }
        } else {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (temp_r3_17542 - 0x40);
            if (temp_r1_17539 == 0) {
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = 4U;
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
    temp_r1_17596 = *(u32 *)(0x030041E8 + (var_r2_17590 * 2));
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
    if (((s32) *(u32 *)(*(s32 *)0x03001B40 + 0x18F8 + (((temp_r3_17642 >> 4) * 2) + ((u32) (arg0 << 0x18) >> 0x13))) >> (0xF & temp_r3_17642)) & 1) {
        if ((*(u16 *)0x03004218 == 0) && ((temp_r1_17668 = 0xF & *(u8 *)0x0300422D, (temp_r1_17668 == 3)) || (temp_r1_17668 == 7))) {
            if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
                var_r0_17681 = *(u8 *)0x0300422E * 2;
                var_r1_17683 = 0x03003720;
            } else {
                var_r0_17681 = *(u8 *)0x0300422E * 2;
                var_r1_17683 = 0x03003920;
            }
            temp_r3_17698 = *(u32 *)(var_r0_17681 + var_r1_17683);
            if (temp_r3_17698 != 0xFFF) {
                temp_r6_17713 = temp_r3_17698 & 0x8000;
                if ((temp_r6_17713 == 0) && (temp_r3_17698 != 0x3333) && (temp_r3_17698 != 0x7777) && ((*(u16 *)((u8 *)(((temp_r3_17698 * 0xC) + 0x0202F7FC)) + (8))) != 0xFFF)) {
                    var_r5_17725 = 0x32;
                    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1))) == 1) {
                        var_r5_17725 = 0x19;
                    }
                    if ((var_r5_17725 >= (s32) ((s32) rand_u16(&gGameState) % 101)) && ((sub_0201F0FC(0xF1U) << 0x10) != 0)) {
                        (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
                        (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
                        (*(u16 *)((u8 *)((void *)0x030041A0) + (0x7C))) = temp_r6_17713;
                        (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = 2;
                        (*(s8 *)((u8 *)(((void *)0x030041A0 + 0x6E)) + (0x19))) = 4;
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

void Islander_OnMoodChanged(void) {
    u16 temp_r0_17787;

    temp_r0_17787 = *(u32 *)(0x020338C4 + (*(u8 *)0x03004233 * 2));
    *(s8 *)0x03004230 = (s8) temp_r0_17787;
    ChangeEmotion((u8) (temp_r0_17787 + 1));
}

void WriteItemTileToVRAM(void *arg0, u16 arg1) {
    u16 temp_r1_17803;
    void *temp_r0_17805;

    temp_r1_17803 = arg1;
    (*(u16 *)((u8 *)(arg0) + (0))) = temp_r1_17803;
    temp_r0_17805 = arg0 + 2;
    (*(s16 *)((u8 *)(arg0) + (2))) = (s16) (temp_r1_17803 + 1);
    (*(s16 *)((u8 *)(temp_r0_17805) + (0x3E))) = (s16) (temp_r1_17803 + 2);
    (*(s16 *)((u8 *)((temp_r0_17805 + 0x3E)) + (2))) = (s16) (temp_r1_17803 + 3);
}

u16 Item_GetItemIdFromTileId(s32 item_type) {
    Islander_AGB *islander = &gIslander;
    BuriedItemUpdateGroup *buried_item_update;
    int i;

    if (IS_ITEM_TYPE_FRUIT(item_type)) {
        islander->_7C[0] = 0x3260;
        if (item_type == ITEM_TYPE_COCONUT) {
            islander->_7C[0] = 0x3268;
        }

        for (i = 0; i < ARRAY_COUNT(gBuriedItemUpdateGroups); i++) {
            buried_item_update = &gBuriedItemUpdateGroups[i];
            if (item_type == buried_item_update->item_type) {
                break;
            }
        }

        return buried_item_update->buried_item;
    }

    return EMPTY_NO;
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
        temp_r2_17906 = CheckSurroundingCollision((u16) *(u8 *)0x0300422E, (*(u16 **)((u8 *)((void *)0x030041A0) + (0x44))));
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
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
            WriteItemToTile((*(s32 *)((u8 *)((void *)0x030041A0) + (0))), *(u8 *)0x0300422E, (*(u16 *)((u8 *)((void *)0x030041A0) + (0x72))), 0x6234U);
            if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x85))) == 0) {
                var_r2_17959 = (void *)0x030041A0 + 0x86;
                var_r0_17961 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x86))) * 2;
                var_r1_17963 = 0x03003720;
            } else {
                var_r2_17959 = (void *)0x030041A0 + 0x86;
                var_r0_17961 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x86))) * 2;
                var_r1_17963 = 0x03003920;
            }
            *(u32 *)(var_r1_17963 + var_r0_17961) = 0xFFF;
            *var_r2_17959 = 0;
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x85))) = 0U;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8D))) = 0;
            (*(u16 *)((u8 *)((void *)0x030041A0) + (0x72))) = 0U;
            Islander_AdjustAnimForTool();
            return 1;
        }
        goto block_17;
    }
block_17:
    return 0;
}

void Islander_Init(void) {
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

    (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = 0;
    var_r3_18021 = (void *)0x030041A0 + 0x48;
    (*(s16 *)((u8 *)((void *)0x030041A0) + (0x48))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x44))) = 0;
    temp_r1_18026 = (void *)0x030041A0 + 0x85;
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x85))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18026) + (1))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = 0;
    temp_r1_18031 = (temp_r1_18026 + 1) - 0x2E;
    (*(s16 *)((u8 *)(temp_r1_18031) + (0))) = 0;
    temp_r1_18033 = temp_r1_18031 + 0x2F;
    (*(s8 *)((u8 *)(temp_r1_18031) + (0x2F))) = 0;
    temp_r1_18035 = temp_r1_18033 + 1;
    (*(s8 *)((u8 *)(temp_r1_18033) + (1))) = 0;
    temp_r1_18037 = temp_r1_18035 + 1;
    (*(s8 *)((u8 *)(temp_r1_18035) + (1))) = 0;
    temp_r1_18039 = temp_r1_18037 + 1;
    (*(s8 *)((u8 *)(temp_r1_18037) + (1))) = 0;
    temp_r1_18041 = temp_r1_18039 + 1;
    (*(s8 *)((u8 *)(temp_r1_18039) + (1))) = 0;
    temp_r1_18043 = temp_r1_18041 + 1;
    (*(s8 *)((u8 *)(temp_r1_18041) + (1))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18043) + (1))) = 0;
    temp_r1_18047 = (temp_r1_18043 + 1) - 0x1B;
    (*(s16 *)((u8 *)(temp_r1_18047) + (0))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18047) + (0x1C))) = 0;
    temp_r1_18051 = (temp_r1_18047 + 0x1C) - 0x14;
    (*(s16 *)((u8 *)(temp_r1_18051) + (0))) = 0;
    temp_r1_18053 = temp_r1_18051 + 0x15;
    (*(s8 *)((u8 *)(temp_r1_18051) + (0x15))) = 0;
    temp_r1_18055 = temp_r1_18053 + 1;
    (*(s8 *)((u8 *)(temp_r1_18053) + (1))) = 0;
    temp_r1_18057 = temp_r1_18055 + 1;
    (*(s8 *)((u8 *)(temp_r1_18055) + (1))) = 0;
    temp_r1_18059 = temp_r1_18057 + 1;
    (*(s8 *)((u8 *)(temp_r1_18057) + (1))) = 0;
    temp_r1_18061 = temp_r1_18059 + 1;
    (*(s8 *)((u8 *)(temp_r1_18059) + (1))) = 0;
    temp_r1_18063 = temp_r1_18061 + 1;
    (*(s8 *)((u8 *)(temp_r1_18061) + (1))) = 0;
    temp_r1_18065 = temp_r1_18063 + 1;
    (*(s8 *)((u8 *)(temp_r1_18063) + (1))) = 0;
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x96))) = 0U;
    temp_r1_18070 = temp_r1_18065 + 2;
    (*(s8 *)((u8 *)(temp_r1_18065) + (2))) = 0;
    temp_r1_18072 = temp_r1_18070 + 1;
    (*(s8 *)((u8 *)(temp_r1_18070) + (1))) = 0;
    temp_r1_18074 = temp_r1_18072 + 1;
    (*(s8 *)((u8 *)(temp_r1_18072) + (1))) = 0;
    temp_r1_18076 = temp_r1_18074 + 1;
    (*(s8 *)((u8 *)(temp_r1_18074) + (1))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18076) + (1))) = 0;
    temp_r1_18080 = (temp_r1_18076 + 1) - 0x2D;
    (*(s16 *)((u8 *)(temp_r1_18080) + (0))) = 0;
    temp_r1_18082 = temp_r1_18080 + 2;
    (*(s16 *)((u8 *)(temp_r1_18080) + (2))) = 0;
    temp_r1_18084 = temp_r1_18082 + 0x2C;
    (*(s8 *)((u8 *)(temp_r1_18082) + (0x2C))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18084) + (1))) = 0;
    temp_r1_18088 = (temp_r1_18084 + 1) - 0x29;
    (*(s16 *)((u8 *)(temp_r1_18088) + (0))) = 0;
    temp_r1_18090 = temp_r1_18088 + 0x2A;
    (*(s8 *)((u8 *)(temp_r1_18088) + (0x2A))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18090) + (1))) = 0;
    temp_r1_18094 = (temp_r1_18090 + 1) - 0x23;
    (*(s16 *)((u8 *)(temp_r1_18094) + (0))) = 0;
    temp_r1_18096 = temp_r1_18094 + 4;
    (*(s16 *)((u8 *)(temp_r1_18094) + (4))) = 0;
    temp_r1_18098 = temp_r1_18096 + 4;
    (*(s8 *)((u8 *)(temp_r1_18096) + (4))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18098) + (0x1C))) = 0;
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1))) = 0U;
    temp_r1_18105 = (temp_r1_18098 + 0x1C) - 0x1E;
    (*(s16 *)((u8 *)(temp_r1_18105) + (0))) = 0;
    temp_r1_18107 = temp_r1_18105 + 0x30;
    (*(s8 *)((u8 *)(temp_r1_18105) + (0x30))) = 0;
    temp_r1_18109 = temp_r1_18107 + 2;
    (*(s8 *)((u8 *)(temp_r1_18107) + (2))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18109) + (1))) = 0;
    temp_r1_18113 = (temp_r1_18109 + 1) - 2;
    (*(s8 *)((u8 *)(temp_r1_18113) + (0))) = 0;
    temp_r1_18115 = temp_r1_18113 + 3;
    (*(s8 *)((u8 *)(temp_r1_18113) + (3))) = 0;
    temp_r1_18117 = temp_r1_18115 + 1;
    (*(s8 *)((u8 *)(temp_r1_18115) + (1))) = 0;
    (*(s8 *)((u8 *)(temp_r1_18117) + (1))) = 0;
    temp_r1_18121 = (temp_r1_18117 + 1) - 0x40;
    *temp_r1_18121 = 0x78;
    *(temp_r1_18121 - 2) = 0x2A30;
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x96))) = (u8) (*(s32 *)((u8 *)(*(void **)0x03001B40) + (0x1944)));
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1))) = (u8) *(u32 *)(0x02033F92 + (*(u8 *)((u8 *)((void *)0x030041A0) + (0x96))));
    var_r2_18139 = 3;
    do {
        (*(s16 *)((u8 *)(var_r3_18021) + (0))) = 0;
        (*(s16 *)((u8 *)(var_r3_18021) + (8))) = 0;
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
    Islander_OnMoodChanged();
    ChangeEmotion((u8) ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x90))) + 1));
    sub_02026BD8();
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8A))) = 0xFE;
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x88))) = 0x60;
    *(s8 *)0x03004227 = 0;
}

s32 Island_GetFloatingItem(void) {
    s32 temp_r0_18246;
    s32 temp_r1_18212;
    s32 temp_r1_18220;
    s32 temp_r2_18233;
    u16 temp_r2_18225;

    temp_r1_18212 = *(u8 *)0x03004236 * 7;
    *(s32 *)0x03000020 = temp_r1_18212;
    temp_r1_18220 = temp_r1_18212 + *(u32 *)(0x02033DC8 + *(u8 *)0x03003B26);
    *(s32 *)0x03000020 = temp_r1_18220;
    temp_r2_18225 = *(u32 *)(0x02033DE4 + (temp_r1_18220 * 2));
    *(s32 *)0x03000020 = (s32) temp_r2_18225;
    temp_r2_18233 = temp_r2_18225 + *(u32 *)(0x02033DE0 + *(u8 *)0x03004230);
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

void Islander_StepFlyingItem(void) {
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
    if ((*(u16 *)0x03004202 == 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) == 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) == 0)) {
        temp_r1_18307 = Island_GetFloatingItem() * 4;
        temp_r6_18309 = temp_r1_18307 + 0x02033B48;
        temp_r0_18314 = SpawnEntity(0U, 1U, *(u32 *)(0x02033B48 + temp_r1_18307), (*(u16 *)((u8 *)(temp_r6_18309) + (2))));
        if (temp_r0_18314 == 0) {
            return;
        }
        temp_r1_18322 = 0x54 * temp_r0_18314;
        temp_r4_18324 = temp_r1_18322 + 0x03004790;
        if (!(1 & rand_u16(&gGameState))) {
            *(u32 *)(0x03004790 + temp_r1_18322) = 0x10;
            (*(s32 *)((u8 *)(temp_r4_18324) + (0x18))) = 0x18;
            var_r0_18335 = 0x1D1;
        } else {
            *(u32 *)(0x03004790 + temp_r1_18322) = 0x1D0;
            (*(s32 *)((u8 *)(temp_r4_18324) + (0x18))) = -0x18;
            var_r0_18335 = 0xF;
        }
        (*(s32 *)((u8 *)(temp_r4_18324) + (0x14))) = var_r0_18335;
        (*(s32 *)((u8 *)(temp_r4_18324) + (4))) = (s32) ((((s32) rand_u16(&gGameState) % 5) * 0x10) + 0x50);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) = (s32) *(u32 *)(0x03004790 + temp_r1_18322);
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) = (s32) (*(s32 *)((u8 *)(temp_r4_18324) + (4)));
        var_r6_18363 = temp_r6_18309 + 4;
        var_r7_18365 = temp_r4_18324 + 0x34;
        var_r5_18367 = temp_r4_18324 + 0x2A;
        var_r4_18368 = 3;
        do {
            var_r1_18370 = (*(u16 *)((u8 *)(var_r6_18363) + (0)));
            var_r0_18371 = (*(u16 *)((u8 *)(var_r6_18363) + (2)));
            if (var_r0_18371 == 4) {
                temp_r0_18378 = ((s32) rand_u16(&gGameState) % 6) * 4;
                var_r1_18370 = *(u32 *)(0x02033B30 + temp_r0_18378);
                var_r0_18371 = (*(u16 *)((u8 *)((temp_r0_18378 + 0x02033B30)) + (2)));
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
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x87))) == 3) {
        temp_r6_18403 = *(u16 *)0x03004202;
        if (temp_r6_18403 != 0) {
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x9E))) = 0;
            return;
        }
        temp_r1_18416 = 0xF & (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D)));
        if ((temp_r1_18416 == 1) || (temp_r1_18416 == 5)) {
            temp_r2_18424 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = temp_r2_18424;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) - (*(s32 *)((u8 *)((void *)0x030041A0) + (4))));
            if (temp_r2_18424 < 0) {
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) = (s32) (0 - temp_r2_18424);
            }
            temp_r0_18435 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24)));
            if (temp_r0_18435 < 0) {
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) = (s32) (0 - temp_r0_18435);
            }
            if (((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x20))) <= 0x1000) && ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x24))) <= 0x1000)) {
                var_r4_18449 = 0x64;
                if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1))) == 1) {
                    var_r4_18449 = 0x32;
                }
                if (var_r4_18449 >= (s32) ((s32) rand_u16(&gGameState) % 101)) {
                    if ((s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) > (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38)))) {
                        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = (s8) temp_r6_18403;
                    } else {
                        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = 1;
                    }
                    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x87))) = MoveActionReceiveItemInit;
                    Islander_ReceiveItem_Init();
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
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
            var_r4_18521 = (u32) (((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) << 0x10) + 0xE0000) >> 0x10;
            var_r2_18522 = 0x0600A000;
        } else {
            var_r4_18521 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) + 0x12;
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
            if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xA1))) == 1) {
                var_r4_18578 = 0x32;
            }
            if (var_r4_18578 > (s32) ((s32) rand_u16(&gGameState) % 101)) {
                temp_r1_18595 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000;
                if (temp_r1_18595 == 0) {
                    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r1_18595;
                } else {
                    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = 1;
                }
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0xD;
                Islander_Fishing_Init();
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

    if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
        *(u32 *)(0x03003720 + ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2)) = 0x7777;
        temp_r1_18645 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)));
        var_r0_18651 = ((0xF & temp_r1_18645) * 2) + ((temp_r1_18645 >> 4) << 5);
        var_r2_18652 = *(s32 *)0x03001B40 + 0x24;
    } else {
        *(u32 *)(0x03003920 + ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2)) = 0x7777;
        temp_r1_18671 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)));
        var_r0_18651 = ((0xF & temp_r1_18671) * 2) + ((temp_r1_18671 >> 4) << 5);
        var_r2_18652 = *(u32 *)0x03001B40 + 0x224;
    }
    return *(u32 *)(var_r2_18652 + var_r0_18651);
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
    temp_r1_18716 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
    if (!(0xFF0000 & temp_r1_18716)) {
        var_r2_18724 = (void *)0x030041A0 + 0x8E;
        var_r1_18726 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2;
        var_r0_18728 = 0x03003720;
    } else {
        var_r2_18724 = (void *)0x030041A0 + 0x8E;
        var_r1_18726 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2;
        var_r0_18728 = 0x03003920;
    }
    temp_r6_18743 = *(u32 *)(var_r0_18728 + var_r1_18726);
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
    if ((*(u16 *)((u8 *)(temp_r5_18774) + (4))) == 0xFFF) {
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
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB6))) = 0U;
    temp_r2_18813 = 0xF & (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D)));
    if ((temp_r2_18813 == 3) || (temp_r2_18813 == 7)) {
        if (((*(u16 *)((u8 *)((void *)0x030041A0) + (0x62))) == 0) && ((u32) (u16) ((*(u16 *)((u8 *)(temp_r5_18774) + (8))) - 7) > 7U)) {
            goto block_34;
        }
        goto block_42;
    }
    temp_r1_18833 = (*(u16 *)((u8 *)(temp_r5_18774) + (8)));
    if ((u32) (u16) (temp_r1_18833 - 5) > 1U) {
        if ((u32) (u16) (temp_r1_18833 - 7) <= 7U) {
            temp_r2_18846 = (void *)0x030041A0 + 0x72;
            (*(u16 *)((u8 *)((void *)0x030041A0) + (0x72))) = sub_02021050();
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB6))) = (u8) temp_r6_18743;
            (*(u8 *)((u8 *)(temp_r2_18846) + (0x14))) = 0U;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x85))) = 0;
            (*(u8 *)((u8 *)(temp_r2_18846) + (0x14))) = (u8) *var_r2_18724;
            if ((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000) {
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0x85))) = 1;
                goto block_35;
            }
            goto block_36;
            goto block_38;
        }
        if ((*(u16 *)((u8 *)((void *)0x030041A0) + (0x62))) == 0) {
block_34:
            var_sl_18702 = sub_02021050();
            goto block_35;
        }
        goto block_42;
    }
block_35:
    if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
block_36:
        var_r0_18887 = *var_r2_18724 * 2;
        var_r1_18889 = 0x03003720;
    } else {
        var_r0_18887 = *var_r2_18724 * 2;
        var_r1_18889 = 0x03003920;
    }
block_38:
    *(u32 *)(var_r1_18889 + var_r0_18887) = 0x7777;
    temp_r1_18904 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r1_18904;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (temp_r1_18904 | (((0xF & *var_r2_18724) << 0xC) + 0x800));
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((0xF0 & *var_r2_18724) << 8) + 0x800);
    temp_r2_18922 = (void *)0x030041A0 + 0x6E;
    (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = 2;
    (*(s8 *)((u8 *)(temp_r2_18922) + (0x2B))) = 0x10;
    temp_r2_18929 = (temp_r2_18922 + 0x2B) - 0x12;
    (*(s8 *)((u8 *)(temp_r2_18929) + (0))) = 4;
    (*(s8 *)((u8 *)(temp_r2_18929) + (0x19))) = 0;
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
        *(u32 *)((void *)0x030041A0 + 0x64 + (var_r3_18937 * 2)) = var_sl_18702;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x95))) = (s8) var_r3_18937;
        goto block_46;
    }
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xB6))) == 0) {
        (*(s8 *)((u8 *)(temp_r2_18929) + (0x19))) = (s8) (temp_r6_18743 + 1);
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
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
            var_r2_19020 = (void *)0x030041A0 + 0x8E;
            var_r1_19022 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2;
            var_r0_19024 = 0x03003720;
        } else {
            var_r2_19020 = (void *)0x030041A0 + 0x8E;
            var_r1_19022 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))) * 2;
            var_r0_19024 = 0x03003920;
        }
        if ((*(u32 *)(var_r0_19024 + var_r1_19022) == 0xFFF) && ((s32) ((s32) rand_u16(&gGameState) % 101) <= 5) && (sub_0201F368() != 0) && ((sub_0201F0FC(0xF1U) << 0x10) != 0)) {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (8))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0xB7))) = 0;
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0xB8))) = (u8) *var_r2_19020;
            if ((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000) {
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0xB7))) = 1;
            }
            (*(s16 *)((u8 *)((void *)0x030041A0) + (0x7C))) = 0;
            (*(s16 *)((u8 *)((void *)0x030041A0) + (0x6E))) = 2;
            (*(s8 *)((u8 *)(((void *)0x030041A0 + 0x6E)) + (0x19))) = 4;
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

    if ((*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) != 0) {
        WriteItemToTile((u8) (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) << 0x10, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))), (*(u16 *)((u8 *)((void *)0x03004B80) + (0x1A))), *(u32 *)(0x0202F7FC + (*(u8 *)0x03004BA4 * 0xC)));
        if ((u8) (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) == 0) {
            var_r0_19137 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) * 2;
            var_r1_19139 = 0x03003720;
        } else {
            var_r0_19137 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) * 2;
            var_r1_19139 = 0x03003920;
        }
        *(u32 *)(var_r0_19137 + var_r1_19139) = (s16) *(u8 *)0x03004BA4;
        (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) = 0;
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) = 0U;
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
                *(u32 *)(0x03003720 + (*(u8 *)0x03004226 * 2)) = (s16) var_r2_19185;
                temp_r1_19214 = *(u8 *)0x03004226;
                temp_r0_19220 = 0xF & temp_r1_19214;
                var_r6_19222 = ((0xF0 & temp_r1_19214) * 8) + 0x0600C000 + (temp_r0_19220 * 4);
                var_r0_19230 = (temp_r0_19220 * 2) + (((temp_r1_19214 >> 4) & 0xF) << 5);
                var_r2_19231 = *(s32 *)0x03001B40 + 0x24;
            } else {
                *(u32 *)(0x03003920 + (*(u32 *)0x03004226 * 2)) = (s16) var_r2_19185;
                temp_r1_19250 = *(u32 *)0x03004226;
                temp_r0_19256 = 0xF & temp_r1_19250;
                var_r6_19222 = ((0xF0 & temp_r1_19250) * 8) + 0x0600C800 + (temp_r0_19256 * 4);
                var_r0_19230 = (temp_r0_19256 * 2) + (((temp_r1_19250 >> 4) & 0xF) << 5);
                var_r2_19231 = *(u32 *)0x03001B40 + 0x224;
            }
            *(u32 *)(var_r2_19231 + var_r0_19230) = *(u16 *)0x03004212;
            WriteItemTileToVRAM(var_r6_19222, 0x6234U);
            *(u8 *)0x03004226 = 0;
            *(u8 *)0x03004225 = 0;
            *(u8 *)0x0300422D = 0;
            *(u16 *)0x03004212 = 0;
            if (*(u8 *)0x03004227 == 3) {
                Islander_AdjustAnimForTool();
            }
        }
    }
}

void sub_02021574(void) {
    u8 temp_r1_19318;

    if ((*(u8 *)0x03003BAE != 0) && ((Islander_StepFlyingItem(), temp_r1_19318 = *(u8 *)0x03004227, ((u32) (u8) (temp_r1_19318 - 9) <= 1U)) || (*(u8 *)0x03004238 == 0))) {
        if (temp_r1_19318 == 3) {
            sub_020205E0();
        }
        ((void (*)(void))*(u32 *)(0x0203380C + (*(u8 *)0x03004227 * 4)))();
    }
}

void sub_020215D0(void) {
    *(s8 *)0x0300422A = 0;
    (*(s8 *)((u8 *)((void *)0x03004229) + (0))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = 0;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = 0;
    (*(s8 *)((u8 *)((void *)0x03004229) + (2))) = 0;
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x88))) == 0x60) {
        *(s8 *)0x0300422A = 0xFE;
    }
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 1;
}

void Islander_MoveIndoorsOrOutdoors(void) {
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
                if (*(u32 *)0x03004229 == 1) {
                    sub_02026A38(1U);
                }
                if (*(u32 *)0x03004229 == 0xB) {
                    sub_02026A38(0xEU);
                }
            }
        }
        if (Islander_PlayAnim(1U) != 0) {
            temp_r5_19442 = *(u32 *)0x03004228;
            if (temp_r5_19442 == 0x60) {
                (*(s8 *)((u8 *)((void *)0x03003BC4) + (0x11))) = 1;
                temp_r0_19452 = (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) + 0x1200;
                (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = temp_r0_19452;
                (*(s32 *)((u8 *)((void *)0x030041A0) + (0xC))) = temp_r0_19452;
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0x94))) = temp_r5_19442;
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 2;
                sub_02021720();
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0x9A))) = 0x40;
                (*(s16 *)((u8 *)((void *)0x030041A0) + (0x58))) = (s16) temp_r5_19442;
                return;
            }
            var_r5_19479 = 4;
            do {
                if ((*(u16 *)((u8 *)((void *)0x030041A0) + (0x5A))) != 0) {
                    temp_r0_19487 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x93))) + 1;
                    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x93))) = temp_r0_19487;
                    if ((u32) temp_r0_19487 > 6U) {
                        (*(u8 *)((u8 *)((void *)0x030041A0) + (0x93))) = 6U;
                    }
                    Islander_OnMoodChanged();
                    Islander_ClearStoredItem(0);
                }
                var_r5_19479 -= 1;
            } while (var_r5_19479 >= 0);
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8A))) = 0xFE;
            *(u32 *)0x03004228 = 0x60U;
            *(s8 *)0x03004227 = 0;
            (*(s8 *)((u8 *)((void *)0x03003BC4) + (0x11))) = 1;
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
    (*(s8 *)((u8 *)((void *)0x03004229) + (0))) = 0;
    temp_r0_19535 = (void *)0x03004229 + 1;
    (*(s8 *)((u8 *)((void *)0x03004229) + (1))) = 0;
    temp_r0_19537 = temp_r0_19535 + 7;
    (*(s8 *)((u8 *)(temp_r0_19535) + (7))) = 0;
    (*(s8 *)((u8 *)(temp_r0_19537) + (1))) = 0;
    (*(s8 *)((u8 *)((temp_r0_19537 + 1)) + (5))) = 0;
    Islander_AdjustAnimForTool();
    temp_r4_19549 = **(u32 **)(0x02033680 + (*(u8 *)0x03004228 * 4));
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
    (*(s16 *)((u8 *)((void *)0x030041F8) + (0))) = (s16) (var_r6_19528 + ((s32) rand_u16(&gGameState) % 337));
    (*(s8 *)((u8 *)((void *)0x030041F8) + (0x32))) = (s8) (*(u16 *)((u8 *)(temp_r4_19549) + (4)));
    *(u32 *)(((void *)0x030041F8 + 0x32) - 3) = 3;
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
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) != 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) != 0) && (sub_0201FD1C((*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))), (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)))) != 0)) {
            if ((u32) (*(u16 *)((u8 *)((void *)0x030041A0) + (0x58))) <= 0x5FU) {
                (*(u16 *)((u8 *)((void *)0x030041A0) + (0x58))) = 0x60U;
            }
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = temp_r0_19664;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = temp_r0_19664;
        }
        if (((*(u8 *)((u8 *)((void *)0x030041A0) + (0x90))) != 3) || ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) == 0)) {
            temp_r0_19699 = (*(u16 *)((u8 *)((void *)0x030041A0) + (0x58)));
            if (temp_r0_19699 == 0) {
                temp_r0_19703 = sub_0201F78C(0U);
                if (temp_r0_19703 != 0x777) {
                    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = temp_r0_19703;
                    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 2;
                    sub_02021720();
                    return;
                }
                goto block_28;
            }
            (*(u16 *)((u8 *)((void *)0x030041A0) + (0x58))) = (u16) (temp_r0_19699 - 1);
            goto block_28;
        }
block_28:
        Islander_PlayAnim(0U);
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
    temp_r1_19742 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
    if (temp_r1_19742 & 0xFFFF0000) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (u16) temp_r1_19742;
    }
    temp_r1_19752 = (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C)));
    if (temp_r1_19752 & 0xFFFF0000) {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = (s32) (u16) temp_r1_19752;
    }
    if (Islander_ChangeMoveDir((*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))), (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))), (*(u8 *)((u8 *)((void *)0x030041A0) + (0x6E)))) == 0) {
        goto block_49;
    }
    temp_r1_19774 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x99)));
    if ((temp_r1_19774 == 0x30) || (temp_r1_19774 == 0x40)) {
        var_r6_19739 = ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x9B))) * 0x30) + 0x03003C00;
    }
    temp_r0_19790 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x99)));
    switch (temp_r0_19790) {                        /* irregular */
    case 0x70:
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = 1;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) == 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) == 0)) {
block_45:
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x6E))) = (s16) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C)));
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0U;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0x11;
            IslanderMoveAction_Dig();
        } else {
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = 0;
            var_r7_19740 = 1;
        }
    default:
block_47:
        if (var_r7_19740 == 0) {
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x6E))) = var_r7_19740;
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x99))) = 0U;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) var_r7_19740;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) var_r7_19740;
            return;
        }
block_49:
        Islander_PlayAnim(0U);
        return;
    case 0x10:
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 5;
        sub_02021AD8();
        goto block_47;
    case 0x20:
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) + 0xFFFFF000);
        (*(s8 *)((u8 *)((void *)0x03003BC4) + (0x11))) = 0;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x88))) = 0x5F;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0;
        sub_020215D0();
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8A))) = 4;
        goto block_47;
    case 0x30:
        (*(s8 *)((u8 *)(var_r6_19739) + (0x29))) = 0;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) == 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) == 0)) {
            temp_r1_19873 = 0xF & (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D)));
            if ((temp_r1_19873 != 2) && (temp_r1_19873 != 6)) {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x62;
            } else {
                var_r1_19879 = (void *)0x030041A0 + 0x88;
                var_r0_19880 = 0x55;
            }
block_38:
            *var_r1_19879 = var_r0_19880;
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0xB;
            sub_020223AC();
            goto block_47;
        }
block_42:
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) = 0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) = 0;
        goto block_49;
    case 0x40:
        (*(s8 *)((u8 *)(var_r6_19739) + (0x29))) = 1;
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) == 0) && ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) == 0)) {
            temp_r1_19902 = 0xF & (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D)));
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
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
        sub_0201F78C(1U);
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 2;
        sub_02021720();
        goto block_47;
    case 0x60:
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x8B))) = 0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14)));
        if (((*(s32 *)((u8 *)((void *)0x030041A0) + (0x18))) != 0) || ((*(s32 *)((u8 *)((void *)0x030041A0) + (0x1C))) != 0)) {
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

    (*(s8 *)((u8 *)((void *)0x03004229) + (0))) = 0;
    *(s8 *)0x0300422A = 0;
    (*(s8 *)((u8 *)((void *)0x03004229) + (8))) = 0;
    (*(s8 *)((u8 *)(((void *)0x03004229 + 8)) + (1))) = 0;
    *(s8 *)0x03004228 = 0x56;
    *(s8 *)0x0300422A = (s8) (*(u16 *)((u8 *)(**(void ***)0x020337D8) + (4)));
    if (!(*(s32 *)0x03004224 & 0xFFFF00)) {
        var_r4_20055 = (void *)0x030041A0 + 0x8E;
        WriteItemToTile((*(s32 *)((u8 *)((void *)0x030041A0) + (0))), (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E))), 0U, 0x200U);
    } else {
        var_r2_20071 = 0x0600C800;
        if (!((*(s32 *)((u8 *)((void *)0x030041A0) + (0))) & 0xFF0000)) {
            var_r2_20071 = 0x0600C000;
        }
        var_r4_20055 = (void *)0x030041A0 + 0x8E;
        temp_r1_20078 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8E)));
        WriteItemTileToVRAM(var_r2_20071 + ((0xF0 & temp_r1_20078) * 8) + ((0xF & temp_r1_20078) * 4), 0x200U);
    }
    sub_020262DC(*var_r4_20055, (*(s32 *)((u8 *)((void *)0x030041A0) + (0))));
    temp_r1_20096 = (void *)0x030041A0 + 0xA0;
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0xA0))) == 0) {
        if ((*(u8 *)((u8 *)(temp_r1_20096) + (0x16))) == 0) {
            var_r0_20110 = *(u32 *)(((temp_r1_20096 + 0x16) - 0x5C) + ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x95))) * 2));
            goto block_10;
        }
        var_r1_20116 = (*(u8 *)((u8 *)(temp_r1_20096) + (0x16)));
    } else {
        var_r0_20110 = (u16) (*(u8 *)((u8 *)((void *)0x030041A0) + (0xA0)));
block_10:
        var_r1_20116 = var_r0_20110 - 1;
    }
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x40))) = (s32) ((*(u16 *)((u8 *)(((var_r1_20116 * 0xC) + 0x0202F7FC)) + (4))) | 0x800000);
    (*(s8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 6;
}

void Islander_ProcessFood(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    ItemGroupStruct *definition;
    u32 item_type_idx;
    s32 result;
    s32 i;
    u8 *pending_food;

    if (islander->anim_id == ISLANDER_ANIM_56) {
        if (islander->anim_timer == 0) {
            if (islander->anim_frame == 2) {
                sub_02026A38(0x1D);
            }
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    result = 0;
    pending_food = &islander->_A0;
    if (islander->_A0 == 0) {
        if (islander->_B2[4] == 0) {
            item_type_idx = islander->stored_item_tile_ids[islander->_94[1]] - 1;
        } else {
            item_type_idx = islander->_B2[4];
        }
    } else {
        item_type_idx = islander->_A0 - 1;
    }

    definition = g_ItemDefinitions + item_type_idx;
    islander->_40 = definition->held_item_oam_attr2 | 0x800000;

    switch (islander->anim_id) {
    case ISLANDER_ANIM_56:
        islander->anim_id = ISLANDER_ANIM_58;
        if (islander->_A0 != 0) {
            islander->anim_id = ISLANDER_ANIM_57;
            sub_02026A38(0x19);
        }
        break;

    case ISLANDER_ANIM_57: {
        u8 *food_preferences;
        u8 *food_preference_layout;
        u8 *stand_on_tile_idx;

        islander->_40 = 0;
        if ((islander->_00 & 0xFF0000) == 0) {
            stand_on_tile_idx = &islander->stand_on_tile_idx;
            field->fg_tiles[0][islander->stand_on_tile_idx] = 0xFFF;
        } else {
            stand_on_tile_idx = &islander->stand_on_tile_idx;
            field->fg_tiles[1][islander->stand_on_tile_idx] = 0xFFF;
        }

        food_preferences = ISLANDER_FOOD_PREFERENCES.preferences;
        food_preference_layout = food_preferences + sizeof(ISLANDER_FOOD_PREFERENCES.preferences);
        for (i = 0; i < 9; i++) {
            if (item_type_idx == food_preference_layout[i]) {
                u8 preference = food_preferences[islander->islander_npc_idx * 9 + i];

                islander->mood += preference;
                if ((preference & 0x80) == 0) {
                    islander->emotion_anim_id = ISLANDER_ANIM_59;
                } else {
                    islander->emotion_anim_id = ISLANDER_ANIM_5D;
                }
                break;
            }
            food_preference_layout++;
        }

        result = 3;
        if (islander->mood & 0x80) {
            islander->mood = 0;
            // islander->_A0 = 0;
            goto temp;
        } else if (islander->mood > 5) {
            if ((islander->_00 & 0xFF0000) == 0) {
                field->fg_tiles[0][islander->stand_on_tile_idx] = 0x3333;
            } else {
                field->fg_tiles[1][islander->stand_on_tile_idx] = 0x3333;
            }
            islander->mood = 6;
        } else {
temp:
            islander->_A0 = 0;
        }
        break;
    }

    case ISLANDER_ANIM_58:
        islander->_40 = 0;
        if ((islander->_00 & 0xFF0000) == 0) {
            if (islander->_86 != islander->stand_on_tile_idx) {
                field->fg_tiles[0][islander->stand_on_tile_idx] = 0xFFF;
            }
        } else if (islander->_86 != islander->stand_on_tile_idx) {
            field->fg_tiles[1][islander->stand_on_tile_idx] = 0xFFF;
        }

        switch (definition->interaction_type) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            islander->emotion_anim_id = ISLANDER_ANIM_59;
            result = 3;
            break;
        case 4:
            islander->mood = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->emotion_anim_id = ISLANDER_ANIM_ANGRY;
            result = 1;
            break;
        case 8:
            islander->state = 5;
            result = 2;
            break;
        case 7:
            islander->state = 1;
            result = 2;
            break;
        case 10:
            islander->state = 6;
            result = 2;
            break;
        case 9:
            islander->state = 2;
            result = 2;
            break;
        case 12:
            islander->state = 7;
            result = 2;
            break;
        case 11:
            islander->state = 3;
            result = 2;
            break;
        case 14:
            islander->state = 8;
            result = 2;
            break;
        case 13:
            islander->state = 4;
            result = 2;
            break;
        default:
            break;
        }
        break;
    }

    switch (result) {
    case 1:
        Islander_ClearStoredItem(islander->_94[1]);
        /* fallthrough */
    case 3:
        if (result != 1) {
            Islander_OnMoodChanged();
            if ((islander->emotion == ISLANDER_EMOTION_SAD) && (islander->reward_adjust == 0)) {
                islander->emotion = ISLANDER_EMOTION_ANGRY;
                ChangeEmotion(2);
            }
        }
        islander->item_work.held_item.type_idx = 2;
        islander->_99[0] = 0x50;
        islander->move_proc_idx = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case 2:
        WriteItemToTile(islander->_00, islander->stand_on_tile_idx, 0, 0x200);
        islander->_7C[3] = 0;
        islander->_94[0] = 0x20;
        islander->move_proc_idx = ActionOutside;
        sub_02021720();
        break;
    }

    islander->anim_timer = gIslanderAnimData[islander->anim_id][islander->anim_frame]->duration;
}

void IslanderMoveAction_UpdateEmotion(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->_91[0] = 0;
    islander->_91[1] = 0;
    islander->anim_id = islander->emotion_anim_id;
    anim_data = *gIslanderAnimData[islander->anim_id];

    switch (islander->emotion_anim_id) {
    case ISLANDER_ANIM_59:
        sub_02026A38(9);
        break;
    case ISLANDER_ANIM_5A:
        sub_02026A38(10);
        break;
    case ISLANDER_ANIM_ANGRY:
        sub_02026A38(11);
        break;
    case ISLANDER_ANIM_SAD:
        sub_02026A38(12);
        break;
    case ISLANDER_ANIM_5D:
        sub_02026A38(13);
        break;
    case ISLANDER_ANIM_5E:
        break;
    }

    ChangeEmotion(islander->emotion + 1);
    islander->anim_timer = anim_data->duration;
    islander->move_proc_idx = MoveAction8;
}

void sub_02022054(void) {
    Islander_AGB *islander = &gIslander;
    IslandBuilding *house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    mActor_name_t *stored_item;
    u16 *stored_item_tile_id;
    s32 i;
    u16 random = 0;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->_94[0] = 0x20;
    if ((islander->_A0 != 0) && (islander->emotion_anim_id == ISLANDER_ANIM_59)) {
        islander->_A0 = random;
        if (islander->mood == 6) {
            if (islander->stored_item_tile_ids[0] != 0) {
                if (SpawnEntity(1, 0, islander->stored_item_tile_ids[0] - 1,
                                islander->stored_items[0]) != 0) {
                    Islander_ClearStoredItem(0);
                }
            } else {
                random = rand_u16(&gGameState) % 101;
                if (random < 60) {
                    SpawnEntity(0, 0, 0xB, 8);
                } else if (random < 90) {
                    SpawnEntity(0, 0, 0x42, 9);
                } else if (random < 98) {
                    SpawnEntity(0, 0, 0x43, 10);
                } else {
                    SpawnEntity(0, 0, 0x44, 11);
                }
            }
        }
    }

    if (islander->_99[0] == 0x50) {
        islander->_10 = islander->_08;
        islander->_14 = islander->_0C;
        islander->anim_frame = 0;
        Islander_AdjustAnimForTool();
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->move_proc_idx = MoveAction4;
        sub_020218B0();
        return;
    }

    if (islander->_99[0] == 0x80) {
        house->state = 0;
        islander->_00 = house->x << 8;
        islander->_04 = house->y << 8;
        islander->_99[0] = 0;
        islander->anim_id = ISLANDER_ANIM_5F;
        islander->move_proc_idx = ActionInside;
        sub_020215D0();
        islander->anim_timer = 4;
        {
            u16 empty_item = 0;

            stored_item = islander->stored_items;
            stored_item_tile_id = islander->stored_item_tile_ids;
            i = 4;
            do {
                *stored_item_tile_id = empty_item;
                *stored_item = empty_item;
                stored_item++;
                stored_item_tile_id++;
                i--;
            } while (i >= 0);
        }
        return;
    }

    sub_0201F78C(1);
    islander->move_proc_idx = ActionOutside;
    sub_02021720();
}

void sub_020221C0(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    IslanderDirectionSector *sector;
    u16 tile_id;
    u16 angle;
    s32 sector_idx;

    if (islander->_9F == 0) {
        if ((islander->_10 & 0xFF0000) == 0) {
            tile_id = field->fg_tiles[0][islander->_9D];
        } else {
            tile_id = field->fg_tiles[1][islander->_9D];
        }

        if ((tile_id == 0xFFF) || (tile_id == 0x3333) || (tile_id == 0x7777) ||
            (g_ItemDefinitions[tile_id].held_item_oam_attr2 == 0xFFF)) {
            islander->move_proc_idx = ActionOutside;
            sub_02021720();
            return;
        }
    }

    sub_0201FED4(0, 0x30);
    islander->click_cooldown_timer = 0x30;
    islander->_94[0] = 0x60;
    islander->dir_x = (islander->_10 - islander->_00) >> 8;
    islander->dir_y = (islander->_14 - islander->_04) >> 8;
    angle = ArcTan2((s16)islander->dir_x, (s16)islander->dir_y);

    if (angle < gIslanderDirectionSectors[7].max_angle) {
        sector_idx = 0;
        sector = gIslanderDirectionSectors;
        if (angle > sector->max_angle) {
            do {
                sector++;
                sector_idx++;
            } while ((sector_idx <= 6) && (angle > sector->max_angle));
        }
    } else {
        sector_idx = 0;
    }

    islander->_8B = gIslanderDirectionSectors[sector_idx].direction;
    islander->anim_frame = 0;
    islander->anim_timer = 0;
    Islander_AdjustAnimForTool();
    islander->move_proc_idx = CheckClickedOnTimer;
}

void Islander_CheckClickedOnTimer(void) {
    Islander_AGB *islander = &gIslander;
    u8 timer;
    u8 state;

    timer = --islander->click_cooldown_timer;
    if (timer == 0) {
        if (islander->emotion_anim_id == ISLANDER_ANIM_00) {
            state = islander->state;
            if (state & 0x40) {
                islander->state = state - 0x40;
                sub_02020A78();
            }
            islander->move_proc_idx = ActionOutside;
            sub_02021720();
            return;
        }

        islander->emotion_anim_id = 0;
        islander->mood--;
        if (islander->mood & 0x80) {
            islander->mood = 0;
        }
        Islander_OnMoodChanged();

        if ((islander->emotion == ISLANDER_EMOTION_NEUTRAL) ||
            (islander->emotion == ISLANDER_EMOTION_HAPPY)) {
            islander->_8B = 0;
            sub_0201FED4(1, 0x30);
            islander->click_cooldown_timer = 0x30;
            return;
        }

        if (islander->reward_adjust == 0) {
            islander->emotion_anim_id = ISLANDER_ANIM_ANGRY;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
        } else {
            islander->emotion_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
        }
        islander->move_proc_idx = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
}

void sub_020223AC(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->_99[2]];

    islander->anim_frame = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->item_work.held_item.type_idx = 0;
    islander->_7C[1] = 0;
    if (((islander->state & 0xF) != 2) && ((islander->state & 0xF) != 6)) {
        islander->sub_move_action = 0;
        field_object->_2C = 1;
        field_object->state = 1;
    } else {
        field_object->_2C = 0;
        islander->sub_move_action = 1;
    }
    islander->move_proc_idx = MoveAction12;
}

void Islander_MoveAction11_State0(void) {
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->_99[2]];

    if ((islander->anim_frame != 0) && (islander->anim_timer == 1)) {
        field_object->anim_frame = gMoveAction11ObjectAnimFrames[islander->anim_frame - 1];
    }
    if (Islander_PlayAnim(1) != 0) {
        islander->_7C[1] = 600;
        islander->sub_move_action = 0;
        field_object->anim_frame = 3;
        islander->_10 = islander->_08;
        islander->_14 = islander->_0C;
        islander->item_work.held_item.type_idx = 1;
        islander->_99[2] = 0;
        Islander_AdjustAnimForTool();
        islander->item_work.held_item.type_idx = 1;
        islander->_99[0] = 0x50;
        islander->move_proc_idx = MoveAction4;
        sub_020218B0();
    }
}

void Islander_MoveAction11_State1(void) {
    IslandFieldWork *field = &gIslandFieldWork;
    Islander_AGB *islander = &gIslander;
    FieldObject *field_object = &gFieldObjects[islander->_99[2]];
    Entity *entity;
    EntitySpawnParams *spawn_params;
    u16 *tiles;
    s32 spawn_idx;
    s32 random;
    s32 entity_tile_idx;
    s32 map_tile_offset;

    if (Islander_PlayAnim(1) != 0) {
        if ((field_object->state_timer == 0) || (field_object->state_timer & 0x80)) {
            islander->_7C[1] = 0x20;
            islander->sub_move_action = 2;
        } else {
            islander->move_proc_idx = MoveAction11;
            sub_020223AC();
        }
    }

    if ((islander->anim_frame != 3) || (islander->anim_timer != 1)) {
        return;
    }

    if ((field_object->_2D == 1) && (islander->_B4 == 0) &&
        (islander->item_work.held_item.type_idx == 0) &&
        (field->last_palette_hour == gIslanderFavoriteHours[islander->islander_npc_idx]) &&
        ((rand_u16(&gGameState) % 101) <= 24)) {
        if (field_object->layer == 0) {
            map_tile_offset = field_object->tile_idx;
            map_tile_offset += 0x10;
            map_tile_offset *= sizeof(u16);
            tiles = field->fg_tiles[0];
        } else {
            map_tile_offset = field_object->tile_idx;
            map_tile_offset += 0x10;
            map_tile_offset *= sizeof(u16);
            tiles = field->fg_tiles[1];
        }
        if (*(u16 *)((u8 *)tiles + map_tile_offset) == 0xFFF) {
            islander->item_work.held_item.type_idx = 1;
            spawn_idx = 0;
            if ((islander->state & 0xF) == 6) {
                spawn_idx = 0x14;
            }
            spawn_idx += gMoveAction11EmotionSpawnOffsets[islander->emotion];
            random = rand_u16(&gGameState);
            spawn_idx += random % 4;
            spawn_params = &gMoveAction11EntitySpawnParams[spawn_idx];
            spawn_idx = SpawnEntity(0, 2, spawn_params->type, spawn_params->param);
            if (spawn_idx != 0) {
                if (field_object->layer == 0) {
                    map_tile_offset = islander->stand_on_tile_idx;
                    map_tile_offset *= sizeof(u16);
                    tiles = field->fg_tiles[0];
                } else {
                    map_tile_offset = islander->stand_on_tile_idx;
                    map_tile_offset *= sizeof(u16);
                    tiles = field->fg_tiles[1];
                }
                *(u16 *)((u8 *)tiles + map_tile_offset) = 0x3333;
                entity = &g_EntityTable[spawn_idx];
                entity->_10 = (entity->y + 0x20) << 8;
                entity_tile_idx = field_object->tile_idx + 0x10;
                entity->_3C = entity_tile_idx;
                if (field_object->layer != 0) {
                    entity->_3C = entity_tile_idx | 0x1000;
                }
                entity->_52 = 0x35;
                entity->y -= 0x20;
                entity->x = field_object->x - 8;
                islander->_B4 = 1;
            }
        }
    }
    field_object->state = 1;
    field_object->state_timer--;
    sub_02026A38(0);
}

void Islander_MoveAction11_State2(void) {
    Islander_AGB *islander = &gIslander;
    u16 next_timer;

    next_timer = (islander->_7C[1] = islander->_7C[1] - 1);
    if (next_timer == 0) {
        islander->_7C[1] = 600;
        islander->item_work.held_item.type_idx = next_timer;
        islander->sub_move_action = 0;
        if (islander->emotion == ISLANDER_EMOTION_ANGRY) {
            islander->mood++;
            if (islander->mood > 6) {
                islander->mood = 6;
            }
            Islander_OnMoodChanged();
        }
        islander->_10 = islander->_08;
        islander->_14 = islander->_0C;
        islander->item_work.held_item.type_idx = 1;
        islander->_99[0] = 0x50;
        islander->emotion_anim_id = ISLANDER_ANIM_59;
        IslanderMoveAction_UpdateEmotion();
    }
}

static Islander_SUB_MOVE_PROC sIslanderMoveAction11SubMoveProcs[] = {
    Islander_MoveAction11_State0,
    Islander_MoveAction11_State1,
    Islander_MoveAction11_State2,
};

void sub_0202275C(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderMoveAction11SubMoveProcs[islander->sub_move_action]();
}

void Islander_Fishing_Init(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->_8B == 0) {
        islander->anim_id = ISLANDER_ANIM_38;
    } else {
        islander->anim_id = ISLANDER_ANIM_41;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->sub_move_action = 0;
    islander->move_proc_idx = MoveActionFishing;
}

void Islander_Fishing_State0(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;
    u8 *anim_timer;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_39;
        } else {
            islander->anim_id = ISLANDER_ANIM_42;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_timer = anim_data->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->item_work.held_item.tile_no = 0x20;
        islander->sub_move_action = 1;
    }
    anim_timer = &islander->anim_timer;
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        sub_02026A38(0x14);
    }
}

void Islander_Fishing_State1(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->anim_frame = 0;
        islander->item_work.held_item.tile_no = 0x30;
        islander->item_work.held_item.type_idx = timer;
        sub_0201FED4(0, 0x30);
        islander->sub_move_action = 2;
    }
}

void Islander_Fishing_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (--islander->item_work.held_item.tile_no == 0) {
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_3A;
        } else {
            islander->anim_id = ISLANDER_ANIM_43;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->sub_move_action = 3;
        sub_02026AB8(0x15);
        islander->item_work.held_item.tile_no = 0x51;
    }
}

void Islander_Fishing_State3(void) {
    Islander_AGB *islander = &gIslander;
    u16 timer;

    Islander_PlayAnim(0);
    timer = --islander->item_work.held_item.tile_no;
    if (timer == 0) {
        islander->item_work.held_item.tile_no = timer;
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_3B;
        } else {
            islander->anim_id = ISLANDER_ANIM_44;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->item_work.held_item.type_idx = Islander_GetFishingItem();
        islander->sub_move_action = 4;
        sub_02026B38(0x15);
        sub_02026A38(0x16);
    }
}

void Islander_Fishing_State4(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }
    sub_02026A38(0x1C);
    if (islander->item_work.held_item.type_idx == 0) {
        if ((islander->_40 & 0xFFFF) == 0x609E) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
    } else {
        if ((islander->_40 & 0xFFFF) == 0x434E) {
            islander->mood--;
            if (islander->mood & 0x80) {
                islander->mood = 0;
            }
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_3E;
            } else {
                islander->anim_id = ISLANDER_ANIM_47;
            }
        } else if ((islander->_40 & 0xFFFF) == 0x4350) {
            islander->mood++;
            if (islander->mood > 6) {
                islander->mood = 6;
            }
            sub_0201FED4(3, 0x30);
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_3F;
            } else {
                islander->anim_id = ISLANDER_ANIM_48;
            }
        } else if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_40;
        } else {
            islander->anim_id = ISLANDER_ANIM_49;
        }
        Islander_OnMoodChanged();
    }
    anim_data = *gIslanderAnimData[islander->anim_id];
    islander->sub_move_action = 6;
    islander->item_work.held_item.tile_no = 0;
    islander->anim_frame = 0;
    islander->anim_timer = anim_data->duration;
}

void Islander_Fishing_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->_40 & 0xFFFF) == 0x609E) {
            islander->mood = 0;
            islander->emotion_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_proc_idx = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->move_proc_idx = ActionOutside;
            sub_02021720();
        }
        islander->_40 = 0;
    }
}

void Islander_Fishing_State6(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        islander->_74 = 0x708;
        if (islander->item_work.held_item.type_idx == 0) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_3C;
            } else {
                islander->anim_id = ISLANDER_ANIM_45;
            }
            islander->sub_move_action = 5;
        } else {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_3D;
            } else {
                islander->anim_id = ISLANDER_ANIM_46;
            }
            islander->sub_move_action = 7;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->item_work.held_item.tile_no = 0;
        islander->item_work.held_item.type_idx = 0;
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
    }
}

void Islander_Fishing_State7(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        sub_0201F78C(1);
        islander->_40 = 0;
        islander->move_proc_idx = ActionOutside;
        sub_02021720();
    }
}

static Islander_SUB_MOVE_PROC sIslanderFishingSubMoveProcs[] = {
    Islander_Fishing_State0,
    Islander_Fishing_State1,
    Islander_Fishing_State2,
    Islander_Fishing_State3,
    Islander_Fishing_State4,
    Islander_Fishing_State5,
    Islander_Fishing_State6,
    Islander_Fishing_State7,
};

void IslanderMoveAction_Fishing(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderFishingSubMoveProcs[islander->sub_move_action]();
}

void Islander_ReceiveItem_Init(void) {
    Islander_AGB *islander = &gIslander;

    islander->anim_frame = 0;
    if (islander->_8B == 0) {
        islander->anim_id = ISLANDER_ANIM_4A;
    } else {
        islander->anim_id = ISLANDER_ANIM_4F;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->_40 = 0x800000;
    islander->sub_move_action = 0;
    islander->move_proc_idx = MoveActionReceiveItem;
}

static Islander_SUB_MOVE_PROC sIslanderReceiveItemSubMoveProcs[] = {
    Islander_DespawnFlyingItem,
    Islander_StoreHeldItem,
    Islander_ProcessFishReceived,
};

void IslanderMoveAction_ReceiveItem(void) {
    Islander_AGB *islander = &gIslander;

    sIslanderReceiveItemSubMoveProcs[islander->sub_move_action]();
}

void Islander_DespawnFlyingItem(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 *anim_timer;
    u8 anim_timer_value;
    Entity *entity;
    AnimFrameData *anim_data;
    s32 anim_finished;

    if (islander->_40 == 0) {
        islander->move_proc_idx = ActionOutside;
        sub_02021720();
        return;
    }
    anim_timer_value = islander->anim_timer;
    anim_timer = &islander->anim_timer;
    if (anim_timer_value == 0) {
        if (islander->anim_frame == 2) {
            sub_02026A38(0x1A);
        }
        if (islander->anim_frame == 4) {
            sub_02026A38(0x1B);
        }
        if (islander->anim_frame == 8) {
            sub_02026A38(0x1C);
        }
    }
    anim_finished = Islander_PlayAnim(1);
    if (anim_finished != 0) {
        if ((islander->_40 & 0xFFFF) == 0x609E) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_4C;
            } else {
                islander->anim_id = ISLANDER_ANIM_51;
            }
        } else {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_4D;
            } else {
                islander->anim_id = ISLANDER_ANIM_52;
            }
            sub_0201FED4(3, 0x30);
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        *anim_timer = anim_data->duration;
        islander->sub_move_action = 1;
        return;
    }

    entity = &g_EntityTable[islander->floating_balloon_target_entity_id];
    if ((*anim_timer == 1) && (islander->anim_frame == 3)) {
        islander->_40 = 0x800000;
        field->entity_active[islander->floating_balloon_target_entity_id + 3] = anim_finished;
        islander->item_work.held_item.tile_no = entity->item_tile_no[entity->item_tile_frame];
        islander->item_work.held_item.type_idx = entity->item[entity->item_tile_frame];
        islander->flying_item_spawn_timer = 0x2A30;
        islander->flying_item_spawn_timer += (rand_u16(&gGameState) % 109) * 100;
        islander->_38 = anim_finished;
        islander->_3C = anim_finished;
        islander->floating_balloon_target_entity_id = 0;
        islander->_40 |= (g_ItemDefinitions + islander->item_work.held_item.tile_no)->held_item_oam_attr2;
    }
}

void Islander_StoreHeldItem(void) {
    Islander_AGB *islander = &gIslander;
    AnimFrameData *anim_data;

    if (Islander_PlayAnim(1) != 0) {
        Islander_StoreItem(islander->item_work.held_item.tile_no,
                           islander->item_work.held_item.type_idx);
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_4B;
        } else {
            islander->anim_id = ISLANDER_ANIM_50;
        }
        anim_data = *gIslanderAnimData[islander->anim_id];
        islander->anim_frame = 0;
        islander->anim_timer = anim_data->duration;
        islander->sub_move_action = 2;
    }
}

void Islander_ProcessFishReceived(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        sub_0201F78C(1);
        if ((islander->_40 & 0xFFFF) == 0x609E) {
            islander->mood = 0;
            islander->_40 = 0;
            islander->emotion_anim_id = ISLANDER_ANIM_SAD;
            islander->emotion = ISLANDER_EMOTION_SAD;
            islander->move_proc_idx = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
            return;
        }
        islander->_40 = 0;
        islander->move_proc_idx = ActionOutside;
        sub_02021720();
    }
}

void IslanderMoveAction_Dig(void) {
    Islander_AGB *islander = &gIslander;

    if (islander->_8B == 0) {
        islander->anim_id = ISLANDER_ANIM_28;
    } else {
        islander->anim_id = ISLANDER_ANIM_30;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    islander->item_work.held_item.type_idx = 0;
    islander->sub_move_action = 0;
    islander->move_proc_idx = MoveActionBury;
}

void Islander_BuryItem_State0(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    u8 tile_idx = islander->world_state;
    bool32 dug_empty = FALSE;
    u16 *tilemap_vram;
    ItemGroupStruct *definition;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 3) {
            sub_02026A38(0x21);
        }
    }
    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    islander->item_work.held_item.type_idx = 0;
    if (islander->world_state & 0x8000) {
        u16 item_type;

        tilemap_vram = (u16 *)BG_SCREEN_ADDR(25);
        item_type = field->fg_tiles[1][tile_idx];
        if (item_type == 0xFFF) {
            dug_empty = TRUE;
        } else {
            islander->item_work.held_item.type_idx = item_type;
            if (item_type > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[1][tile_idx] = 0x7777;
    } else {
        u16 item_type;

        tilemap_vram = (u16 *)BG_SCREEN_ADDR(24);
        item_type = field->fg_tiles[0][tile_idx];
        if (item_type == 0xFFF) {
            dug_empty = TRUE;
        } else {
            islander->item_work.held_item.type_idx = item_type;
            if (item_type > ITEM_TYPE_FLOWER_BAG) {
                islander->item_work.held_item.type_idx = ITEM_TYPE_COCONUT;
            }
        }
        field->fg_tiles[0][tile_idx] = 0x7777;
    }

    tilemap_vram += (tile_idx & 0xF0) * 4;
    tilemap_vram += (tile_idx & 0xF) * 2;
    WriteItemTileToVRAM(tilemap_vram, 0x12AC);
    if (dug_empty == FALSE) {
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_2B;
        } else {
            islander->anim_id = ISLANDER_ANIM_33;
        }
        definition = g_ItemDefinitions + islander->item_work.held_item.type_idx;

        islander->_40 = 0x800000;
        islander->_40 = definition->held_item_oam_attr2 | 0x800000;
        islander->sub_move_action = 2;
    } else {
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_2A;
        } else {
            islander->anim_id = ISLANDER_ANIM_32;
        }
        islander->sub_move_action = 1;
    }
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
}

void Islander_BuryItem_State1(void) {
    Islander_AGB *islander = &gIslander;
    IslandFieldWork *field = &gIslandFieldWork;
    Island_agb_c *island;
    mActor_name_t item;
    u8 tile_idx = islander->world_state;
    s32 is_tree;
    s32 item_type;
    ItemGroupStruct *definition;

    if (Islander_PlayAnim(1) == 0) {
        return;
    }

    is_tree = 0;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->anim_frame = 0;
    if (islander->_8B == 0) {
        islander->anim_id = ISLANDER_ANIM_29;
    } else {
        islander->anim_id = ISLANDER_ANIM_31;
    }
    islander->sub_move_action = 4;
    islander->_7C[0] = 0x1270;

    if (islander->emotion == ISLANDER_EMOTION_HAPPY) {
        islander->mood--;
        if (islander->mood & 0x80) {
            islander->mood = 0;
        }
        Islander_OnMoodChanged();

        if (islander->stored_item_tile_ids[0] != 0) {
            item_type = islander->stored_item_tile_ids[0];
            item_type--;
            definition = &g_ItemDefinitions[item_type];
            islander->_40 = definition->held_item_oam_attr2 | 0x800000;
            item = islander->stored_items[0];
            if (Item_GetItemIdFromTileId(item_type) != 0) {
                item = Item_GetItemIdFromTileId(item_type);
                is_tree = 1;
            }
            Islander_ClearStoredItem(0);
        } else {
            Islander_PlantRandomFlower();
            return;
        }
    } else if ((s32)rand_u16(&gGameState) % 101 <= 49) {
        islander->_40 = 0x80609E;
        item = Item_TypeToIslandItem(0x11);
    } else {
        islander->_40 = 0x8050C0;
        item = 0x2512;
        islander->mood++;
        if (islander->mood > 6) {
            islander->mood = 6;
        }
        Islander_OnMoodChanged();
    }

    if (!(islander->world_state & 0x8000)) {
        field->fg_tiles[0][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][0].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[0][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    } else {
        field->fg_tiles[1][tile_idx] = 0x7777;
        island = gIslandData;
        island->fgblock[0][1].items[tile_idx >> 4][tile_idx & 0xF] = item;
        if (is_tree == 0) {
            island->deposit[1][tile_idx >> 4] |= 1 << (tile_idx & 0xF);
        }
    }
}

void Islander_BuryItem_State2(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_2D;
            } else {
                islander->anim_id = ISLANDER_ANIM_35;
            }
            islander->mood = 0;
            islander->emotion_anim_id = ISLANDER_ANIM_ANGRY;
        } else if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FOSSIL) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_SEEDLING_DIARY_TICKET_GRAB_BAG) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_PITFALL) ||
                   IS_ITEM_TYPE_TOOL(islander->item_work.held_item.type_idx) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_AIR_CHECK) ||
                   (islander->item_work.held_item.type_idx == ITEM_TYPE_FLOWER_BAG)) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_2F;
            } else {
                islander->anim_id = ISLANDER_ANIM_37;
            }
        } else {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_2E;
            } else {
                islander->anim_id = ISLANDER_ANIM_36;
            }
            sub_0201FED4(3, 0x30);
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->sub_move_action = 5;
        sub_02026A38(0x1C);
    }
}

/* Ghidra name: Islander_BuryItem (differs; duplicate label, state 3 of the bury action). */
void Islander_BuryItem_State3(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->item_work.held_item.type_idx == ITEM_TYPE_FURNITURE) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_GYROID) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_TURNIP) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_MUSHROOM) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CANDY) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_100_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_SHIRT) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_1K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_10K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_30K_BELLS) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_CARPET) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_WALLPAPER) ||
            (islander->item_work.held_item.type_idx == ITEM_TYPE_NES)) {
            Islander_BuryRandomItem(islander->item_work.held_item.type_idx);
        }
        if (islander->item_work.held_item.type_idx == ITEM_TYPE_TRASH) {
            Islander_PlantRandomFlower();
        } else {
            if ((islander->_7C[0] != 0x3260) && (islander->_7C[0] != 0x3268)) {
                islander->_7C[0] = 0x1270;
            }
        }
        if (islander->_8B == 0) {
            islander->anim_id = ISLANDER_ANIM_29;
        } else {
            islander->anim_id = ISLANDER_ANIM_31;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
        islander->sub_move_action = 4;
    }
}

void Islander_BuryItem_State4(void) {
    Islander_AGB *islander = &gIslander;
    u16 world_state = islander->world_state;
    u8 tile_idx = world_state;
    u8 *tilemap_vram;

    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 0xE) {
            tilemap_vram = (0x8000 & world_state) ?
                (u8 *)BG_SCREEN_ADDR(25) : (u8 *)BG_SCREEN_ADDR(24);
            tilemap_vram += (tile_idx & 0xF0) * 8;
            tilemap_vram += (tile_idx & 0xF) * 4;
            WriteItemTileToVRAM(tilemap_vram, 0x200);
        }
    }
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 1) {
            sub_02026A38(0x1E);
        }
        if (islander->anim_frame == 0xA) {
            sub_02026A38(0x22);
        }
        if (islander->anim_frame == 0x11) {
            sub_02026A38(0x23);
        }
    }

    if (Islander_PlayAnim(1) != 0) {
        islander->_40 = 0;
        islander->_B2[5] = 0;
        islander->_B2[6] = 0;

        tilemap_vram = (0x8000 & islander->world_state) ?
            (u8 *)BG_SCREEN_ADDR(25) : (u8 *)BG_SCREEN_ADDR(24);
        tilemap_vram += (tile_idx & 0xF0) * 8;
        tilemap_vram += (tile_idx & 0xF) * 4;
        WriteItemTileToVRAM(tilemap_vram, islander->_7C[0]);
        islander->_78 = 0x78;
        if (islander->_7C[0] != 0x1270) {
            sub_02026A38(0x24);
        }

        if (islander->emotion_anim_id == ISLANDER_ANIM_ANGRY) {
            islander->_B2[0] = 0;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->_99[0] = 0x50;
            islander->mood = 0;
            islander->emotion = ISLANDER_EMOTION_ANGRY;
            islander->move_proc_idx = MoveAction7;
            IslanderMoveAction_UpdateEmotion();
        } else {
            islander->_99[0] = 0x50;
            islander->_B2[0] = 0;
            islander->anim_frame = 0;
            islander->anim_timer = 0;
            Islander_AdjustAnimForTool();
            islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
            islander->_10 = islander->_08;
            islander->_14 = islander->_0C;
            islander->item_work.held_item.type_idx = ITEM_TYPE_GYROID;
            islander->move_proc_idx = MoveAction4;
            sub_020218B0();
        }
        islander->world_state = 0;
    }
}

void Islander_BuryItem_State5(void) {
    Islander_AGB *islander = &gIslander;

    if (Islander_PlayAnim(1) != 0) {
        if ((islander->anim_id == ISLANDER_ANIM_2F) ||
            (islander->anim_id == ISLANDER_ANIM_37)) {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_29;
            } else {
                islander->anim_id = ISLANDER_ANIM_31;
            }
            islander->sub_move_action = 4;
            islander->_7C[0] = 0x1270;
        } else {
            if (islander->_8B == 0) {
                islander->anim_id = ISLANDER_ANIM_2C;
            } else {
                islander->anim_id = ISLANDER_ANIM_34;
            }
            islander->sub_move_action = 3;
        }
        islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
        islander->anim_frame = 0;
    }
}

void IslanderMoveAction_Bury(void) {
    Islander_AGB* islander = &gIslander;

    IslanderSubMoveAction_BuryProcTbl[islander->sub_move_action]();
}

void Islander_MoveAction20_Init(void) {
    Islander_AGB* islander = &gIslander;

    islander->anim_frame = 0;
    islander->anim_timer = 0;
    islander->item_work.move_action20.phase = 0;
    islander->item_work.move_action20.timer = 0;
    islander->anim_id = ISLANDER_ANIM_5E;
    islander->anim_timer = (*gIslanderAnimData[islander->anim_id])->duration;
    islander->_7C[2] = 0x2A30;
    islander->_10 = 0;
    islander->_14 = 0;
    islander->_08 = islander->_00;
    islander->_0C = islander->_04;
    islander->sub_move_action = 0;
    islander->move_proc_idx = MoveAction20;
}

void Islander_MoveAction20_State0(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->_84 == 2) {
        islander->item_work.move_action20.phase = 0;
        islander->item_work.move_action20.timer = 0;
        islander->sub_move_action = 3;
        return;
    }

    Islander_PlayAnim(0);
    islander->_7C[2]--;
    if (islander->anim_timer == 0) {
        if (islander->anim_frame == 2) {
            sub_0201FED4(4, 0x20);
            sub_02026A38(0x25);
        }
    }

    if (islander->_7C[2] & 0x8000) {
        gGameState.unk_824 |= 0x40;
        gGameState.unk_826 |= 0x40;
        gGameState.unk_828 |= 0x40;
        islander->_84 = 1;
        islander->item_work.move_action20.phase = 0;
        islander->sub_move_action = 1;
    }
}

void Islander_MoveAction20_State1(void) {
    Islander_AGB* islander = &gIslander;
    IslandBuilding* house = &gIslandBuildings[ISLAND_BUILDING_ISLANDER_HOUSE];
    Player* player = &gPlayer;
    s32 player_y;
    u16 phase;

    phase = (islander->item_work.move_action20.phase += 0x1111);
    if (phase == 0xFFFF) {
        islander->_00 = house->x << 8;
        player_y = house->y << 8;
        islander->_04 = player_y + 0x1000;
        player->y = player_y;
        player->x = islander->_00 + 0x1000;
        gGameState.unk_840 = (player->x >> 8) - 0x80;
        gGameState.unk_842 = (player->y >> 8) - 0x50;
        if (gGameState.unk_842 & 0x800) {
            gGameState.unk_842 = 0;
        }
        if (gGameState.unk_842 > 0x60) {
            gGameState.unk_842 = 0x60;
        }
        if (gGameState.unk_840 & 0x800) {
            gGameState.unk_840 = 0;
        }
        if (gGameState.unk_840 > 0x100) {
            gGameState.unk_840 = 0x100;
        }
        gGameState.unk_844 = gGameState.unk_840;
        gGameState.unk_846 = gGameState.unk_842;
        islander->sub_move_action = 2;
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State2(void) {
    Islander_AGB* islander = &gIslander;
    IslandFieldWork* island_field = &gIslandFieldWork;
    u32 mosaic;

    mosaic = (islander->item_work.move_action20.phase -= 0x1111);
    if (mosaic == 0) {
        gGameState.unk_824 ^= 0x40;
        gGameState.unk_826 ^= 0x40;
        gGameState.unk_828 ^= 0x40;
        islander->_84 = 0;
        islander->_10 = mosaic;
        islander->_14 = mosaic;
        islander->stand_on_tile_idx = island_field->special_tile_idx;
        islander->mood = 0;
        islander->_99[0] = 0x80;
        islander->emotion_anim_id = ISLANDER_ANIM_ANGRY;
        islander->emotion = ISLANDER_EMOTION_ANGRY;
        islander->move_proc_idx = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
    }
    REG_MOSAIC = islander->item_work.move_action20.phase;
}

void Islander_MoveAction20_State3(void) {
    Islander_AGB* islander = &gIslander;

    if (islander->_84 == 1) {
        islander->item_work.move_action20.timer = 0x10;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->sub_move_action = 4;
    }
}
void Islander_MoveAction20_State4(void) {
    Islander_AGB* islander = &gIslander;
    s32 collision;
    s32 i;

    islander->item_work.move_action20.timer--;
    if ((islander->item_work.move_action20.timer & 0x8000) == 0) {
        return;
    }

    switch ((IslanderMoveAction20Phase)islander->item_work.move_action20.phase) {
    case ISLANDER_MOVE_ACTION20_PHASE_BEGIN:
        sub_0201FED4(1, 0x30);
        islander->anim_frame = 0;
        islander->anim_timer = 0;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x30;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_02:
        islander->anim_id = ISLANDER_ANIM_02;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_06:
        islander->anim_id = ISLANDER_ANIM_06;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x20;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_ANIM_00:
        islander->anim_id = ISLANDER_ANIM_00;
        islander->item_work.move_action20.phase++;
        islander->item_work.move_action20.timer = 0x10;
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_CHECK_POSITION:
        islander->dir_x = islander->_08 - islander->_00;
        islander->dir_y = islander->_0C - islander->_04;
        if (islander->dir_x < 0) {
            islander->dir_x = -islander->dir_x;
        }
        if (islander->dir_y < 0) {
            islander->dir_y = -islander->dir_y;
        }
        if (islander->dir_x <= 0x2000 && islander->dir_y <= 0x2000) {
            islander->item_work.move_action20.timer = 2;
            islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
            return;
        }

        sub_0201F538(islander->_8B);
        for (i = 0; i < 4; i++) {
            collision = CheckSurroundingCollision(islander->_48[i], (u16*)islander->_44);
            if (collision != 0) {
                islander->item_work.move_action20.timer = 2;
                islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_RESTART;
                return;
            }
        }

        islander->emotion_anim_id = ISLANDER_ANIM_59;
        if (islander->mood < 3) {
            islander->mood = 3;
            Islander_OnMoodChanged();
        }
        islander->_99[0] = collision;
        islander->_84 = collision;
        islander->move_proc_idx = MoveAction7;
        IslanderMoveAction_UpdateEmotion();
        break;
    case ISLANDER_MOVE_ACTION20_PHASE_RESTART:
        islander->_08 = islander->_00;
        islander->_0C = islander->_04;
        gGameState.unk_824 |= 0x40;
        gGameState.unk_826 |= 0x40;
        gGameState.unk_828 |= 0x40;
        islander->item_work.move_action20.phase = ISLANDER_MOVE_ACTION20_PHASE_BEGIN;
        islander->sub_move_action = 1;
        break;
    }
}

void Islander_MoveAction20_Move(void) {
    static Islander_SUB_MOVE_PROC sub_move_procs[] = {
        Islander_MoveAction20_State0,
        Islander_MoveAction20_State1,
        Islander_MoveAction20_State2,
        Islander_MoveAction20_State3,
        Islander_MoveAction20_State4,
    };

    Islander_AGB* islander = &gIslander; // I don't know why I have to pull this out to match, but I do
    sub_move_procs[(u8)islander->sub_move_action]();
}

void sub_02023B58(void) {
    register Islander_AGB* islander asm("ip") = (Islander_AGB*)0x030041A0;
    register u32 tile_mask asm("sl");
    IslanderOamData* source;
    volatile s32 sprite_count;
    s32 dir_y;
    Islander_AGB* initial;

    dir_y = islander->_04 >> 8;
    initial = islander;
    initial->dir_y = dir_y;
    initial->dir_x = initial->_00 >> 8;
    source = gIslanderAnimData[islander->anim_id][islander->anim_frame]->sprite_gfx_p;

    if (islander->anim_timer == 0xFE) {
        return;
    }

    {
        register s32 initial_sprite_count asm("r2") = 0;
        sprite_count = initial_sprite_count;
    }
    if (source->affine_param == 0xFFFF) {
        return;
    }

    tile_mask = 0xFFFFFC00;
    do {
        register u8* oam_count asm("r1") = (u8*)0x030023B0;
        IslanderOamData* oam = &((IslanderOamData*)0x03002410)[*oam_count];
        s32 next_sprite_count;
        u32 x;
        u8 state;

        oam->y = source->y + islander->dir_y - ((GameState*)0x03001B50)->unk_846;
        oam->obj_mode = source->obj_mode;
        oam->bpp = source->bpp;
        oam->shape = source->shape;
        oam->h_flip = source->h_flip;
        oam->v_flip = source->v_flip;
        oam->size = source->size;
        oam->mosaic = TRUE;

        x = source->x;
        if (gIslanderAnimMirrorFlags[islander->anim_id] != FALSE) {
            oam->h_flip = source->h_flip ^ TRUE;
            x = ~x;
            x++;
            if ((*(u32*)oam & 0xC000C000) == 0x40000000) {
                x -= 16;
            } else {
                x -= 8;
            }
        }

        {
            register Islander_AGB* x_islander asm("r2") = islander;
            oam->x = x + x_islander->dir_x - ((GameState*)0x03001B50)->unk_844;
        }
        oam->priority = 1;
        oam->palette_num = source->palette_num;
        oam->tile_num = source->tile_num;

        {
            register u32 tile_override asm("r3") = islander->_40;

            if ((tile_override & 0xFFFF0000) != 0 && (tile_override & 0xFFFF) != 0 &&
                oam->tile_num == ((tile_override >> 16) & 0xFFFF)) {
                oam->tile_num = tile_override & 0xFFF;
                {
                    register Islander_AGB* palette_islander asm("r2") = islander;
                    u32 palette_override = palette_islander->_40;
                    u32 palette_bits = (palette_override & 0xF000) >> 8;

                    *(u8*)((u8*)oam + 5) = (*(u8*)((u8*)oam + 5) & 0xF) | palette_bits;
                }
            }
        }

        state = islander->state & 0xF;
        if ((state == 6 || state == 8 || state == 5 || state == 7) && oam->palette_num == 2) {
            oam->palette_num = 8;
        }

        if ((u8)(islander->move_proc_idx - MoveAction3) <= 1) {
            u8 substate = islander->_8B;

            if (substate == 0) {
                if (source->tile_num == 0x40 || source->tile_num == 0x42) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->_91[0] == 0) {
                            oam->tile_num = 0x40;
                        } else {
                            oam->tile_num = 0x42;
                        }
                        break;
                    case 1:
                        oam->tile_num = 0x44;
                        break;
                    case 2:
                        oam->tile_num = 0x46;
                        break;
                    case 3:
                        oam->tile_num = 0x48;
                        break;
                    }
                }
            } else {
                u8 adjusted_substate = substate - 1;

                if ((adjusted_substate <= 1 || substate == 6 || substate == 7) &&
                    (source->tile_num == 0 || source->tile_num == 2)) {
                    switch (islander->emotion) {
                    case 0:
                        if (islander->_91[0] == 0) {
                            oam->tile_num = 0;
                        } else {
                            oam->tile_num = 2;
                        }
                        break;
                    case 1:
                        oam->tile_num = 4;
                        break;
                    case 2:
                        oam->tile_num = 6;
                        break;
                    case 3:
                        oam->tile_num = 8;
                        break;
                    }
                }
            }
        }

        {
            register u8* oam_count_out asm("r3") = (u8*)0x030023B0;
            (*oam_count_out)++;
        }
        next_sprite_count = sprite_count + 1;
        sprite_count = next_sprite_count;
        source++;
        if (next_sprite_count > 0x21) {
            return;
        }
    } while (source->affine_param != 0xFFFF);
}

s32 Item_IsFossil(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item == ITM_FOSSIL) || ((mActor_name_t)(item - FTR_DINO_START) <= (FTR_DINO_END - FTR_DINO_START)) ||
        (item == RSV_ISLAND_FOSSIL)) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemIsGryoidOrUnk (differs; corrected typo and reserve-alias wording). */
s32 Item_IsGyroid(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)((item) - HANIWA_START)) <= ((HANIWA_END - HANIWA_START)) || item == RSV_ISLAND_HANIWA) {
        result = 1;
    }
    return result;
}

s32 Item_IsNES(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - FTR_FAMICOM_START) <= (FTR_FAMICOM_END - FTR_FAMICOM_START)) ||
        (item == RSV_ISLAND_FAMICOM)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFurniture(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((item != ITM_FOSSIL) && ((mActor_name_t)(item - FTR_DINO_START) > (FTR_DINO_END - FTR_DINO_START)) && (item != RSV_ISLAND_FOSSIL) &&
        ((mActor_name_t)((item - HANIWA_START)) > ((HANIWA_END - HANIWA_START))) && (item != RSV_ISLAND_HANIWA) &&
        ((mActor_name_t)(item - FTR_FAMICOM_START) > (FTR_FAMICOM_END - FTR_FAMICOM_START)) && (item != RSV_ISLAND_FAMICOM) &&
        (ITEM_IS_FTR(item) || (item == RSV_ISLAND_FTR_COMMON) || (item == RSV_ISLAND_FTR_RARE) || (item == RSV_ISLAND_FTR_EVENT) || (item == RSV_ISLAND_FTR_ISLAND))) {
        result = 1;
    }
    return result;
}

s32 Item_IsApple(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_APPLE) {
        result = 1;
    }
    return result;
}

s32 Item_IsOrange(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_ORANGE) {
        result = 1;
    }
    return result;
}

s32 Item_IsPeach(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEACH) {
        result = 1;
    }
    return result;
}

s32 Item_IsPear(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_PEAR) {
        result = 1;
    }
    return result;
}

s32 Item_IsCherry(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CHERRY) {
        result = 1;
    }
    return result;
}

s32 Item_IsTurnip(mActor_name_t item) {
    s32 result;
    u32 shifted_item;

    shifted_item = item << 16;
    result = 0;
    if (((shifted_item & 0xF0000000) == (NAME_TYPE_ITEM1 << 28)) &&
        (((shifted_item >> 24) & 0xF) == ITEM1_CAT_KABU)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMushroom(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_MUSHROOM) {
        result = 1;
    }
    return result;
}

s32 Item_IsCandy(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_CANDY) {
        result = 1;
    }
    return result;
}

s32 Item_Is100Bells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_100) {
        result = 1;
    }
    return result;
}

s32 Item_Is1KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_1000) {
        result = 1;
    }
    return result;
}

s32 Item_Is10KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_10000) {
        result = 1;
    }
    return result;
}

s32 Item_Is30KBells(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_MONEY_30000) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerBag(mActor_name_t item) {
    if (((mActor_name_t)(item - ITM_WHITE_PANSY_BAG) <= (ITM_YELLOW_TULIP_BAG - ITM_WHITE_PANSY_BAG)) ||
        (item == RSV_ISLAND_FLOWER_BAG)) {
        return 1;
    }
    return 0;
}

s32 Item_IsSeedlingDiaryTicketGrabBag(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((Item_IsFlowerBag(item) == 0) && ITEM_NAME_CHK_TYPE(item, NAME_TYPE_ITEM1)) {
        if ((ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PAPER) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_PLANT) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_TICKET) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_DUMMY) ||
            (ITEM_NAME_GET_CAT(item) == ITEM1_CAT_HUKUBUKURO)) {
            result = 1;
        }
    }
    return result;
}

s32 Item_IsNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenNet(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_NET) {
        result = 1;
    }
    return result;
}

s32 Item_IsAxe(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_AXE) || (item_no == ITM_AXE_USE_7) || (item_no == ITM_AXE_USE_6) ||
        (item_no == ITM_AXE_USE_5) || (item_no == ITM_AXE_USE_4) || (item_no == ITM_AXE_USE_3) ||
        (item_no == ITM_AXE_USE_2) || (item_no == ITM_AXE_USE_1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenAxe(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_AXE) {
        result = 1;
    }
    return result;
}

s32 Item_IsShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenShovel(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_SHOVEL) {
        result = 1;
    }
    return result;
}

s32 Item_IsFishingRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsGoldenRod(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_GOLDEN_ROD) {
        result = 1;
    }
    return result;
}

s32 Item_IsUmbrella(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_UMBRELLA_START) <= (ITM_UMBRELLA31 - ITM_UMBRELLA_START)) ||
        (item == RSV_ISLAND_UMBRELLA)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPaint(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_RED_PAINT) <= (ITM_BROWN_PAINT - ITM_RED_PAINT)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBalloon(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BALLOON_START) <= (ITM_BUNNY_O_BALLOON - ITM_BALLOON_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPinwheel(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_YELLOW_PINWHEEL) <= (ITM_FANCY_PINWHEEL - ITM_YELLOW_PINWHEEL)) {
        result = 1;
    }
    return result;
}

s32 Item_IsHandFan(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - ITM_BLUEBELL_FAN) <= (ITM_LEAF_FAN - ITM_BLUEBELL_FAN)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSignboard(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SIGNBOARD) {
        result = 1;
    }
    return result;
}

s32 Item_IsShirt(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CLOTH)) ||
        (item_no == RSV_ISLAND_CLOTH_COMMON) || (item_no == RSV_ISLAND_CLOTH_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCarpet(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_CARPET)) ||
        (item_no == RSV_ISLAND_CARPET_COMMON) || (item_no == RSV_ISLAND_CARPET_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsWallpaper(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_WALL)) ||
        (item_no == RSV_ISLAND_WALL_COMMON) || (item_no == RSV_ISLAND_WALL_RARE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsAirCheck(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;
    u32 shifted_item;

    shifted_item = item << 16;
    item_no = shifted_item >> 16;
    result = 0;
    if ((((item_no & 0xF000) == (NAME_TYPE_ITEM1 << 12)) &&
         (((shifted_item >> 24) & 0xF) == ITEM1_CAT_MINIDISK)) ||
        (item_no == RSV_ISLAND_MINIDISK)) {
        result = 1;
    }
    return result;
}

s32 Item_IsTrash(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_DUST0_EMPTY_CAN) <= (ITM_DUST2_OLD_TIRE - ITM_DUST0_EMPTY_CAN)) ||
        (item == RSV_ISLAND_TRASH)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_PITFALL) {
        result = 1;
    }
    return result;
}

s32 Item_IsConchSeaShellIcon(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ITM_SHELL1) <= (ITM_SHELL3 - ITM_SHELL1)) || (item == ITM_SHELL6)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLionsPawShellIcon(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == ITM_SHELL0) || (item_no == ITM_SHELL4) || (item_no == ITM_SHELL5)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoral(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_SHELL7) {
        result = 1;
    }
    return result;
}

s32 Item_IsFlowerLeaves(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - FLOWER_LEAVES_PANSIES0) <= (FLOWER_LEAVES_TULIP2 - FLOWER_LEAVES_PANSIES0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurpleCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS1) {
        result = 1;
    }
    return result;
}

s32 Item_IsBlueCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS2) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowCosmos(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_COSMOS0) {
        result = 1;
    }
    return result;
}

s32 Item_IsRedTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP0) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhiteTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowTulips(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_TULIP2) {
        result = 1;
    }
    return result;
}

s32 Item_IsWhitePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES0) {
        result = 1;
    }
    return result;
}

s32 Item_IsPurplePansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES1) {
        result = 1;
    }
    return result;
}

s32 Item_IsYellowPansies(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLOWER_PANSIES2) {
        result = 1;
    }
    return result;
}

s32 Item_IsCoconut(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == ITM_FOOD_COCONUT) {
        result = 1;
    }
    return result;
}

s32 Item_IsCabana(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_MY) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslanderHouse(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == COTTAGE_NPC) {
        result = 1;
    }
    return result;
}

s32 Item_IsSapling(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_SAPLING) || (item_no == TREE_APPLE_SAPLING) || (item_no == TREE_ORANGE_SAPLING) ||
        (item_no == TREE_PEACH_SAPLING) || (item_no == TREE_PEAR_SAPLING) || (item_no == TREE_CHERRY_SAPLING) ||
        (item_no == TREE_1000BELLS_SAPLING) || (item_no == TREE_10000BELLS_SAPLING) ||
        (item_no == TREE_30000BELLS_SAPLING) || (item_no == TREE_100BELLS_SAPLING)) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S0) || (item_no == TREE_APPLE_S0) || (item_no == TREE_ORANGE_S0) ||
        (item_no == TREE_PEACH_S0) || (item_no == TREE_PEAR_S0) || (item_no == TREE_CHERRY_S0) ||
        (item_no == TREE_1000BELLS_S0) || (item_no == TREE_10000BELLS_S0) ||
        (item_no == TREE_30000BELLS_S0) || (item_no == TREE_100BELLS_S0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S1) || (item_no == TREE_APPLE_S1) || (item_no == TREE_ORANGE_S1) ||
        (item_no == TREE_PEACH_S1) || (item_no == TREE_PEAR_S1) || (item_no == TREE_CHERRY_S1) ||
        (item_no == TREE_1000BELLS_S1) || (item_no == TREE_10000BELLS_S1) ||
        (item_no == TREE_30000BELLS_S1) || (item_no == TREE_100BELLS_S1)) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    item_no = item;
    result = 0;
    if ((item_no == TREE_S2) || (item_no == TREE_APPLE_S2) || (item_no == TREE_ORANGE_S2) ||
        (item_no == TREE_PEACH_S2) || (item_no == TREE_PEAR_S2) || (item_no == TREE_CHERRY_S2) ||
        (item_no == TREE_1000BELLS_S2) || (item_no == TREE_10000BELLS_S2) ||
        (item_no == TREE_30000BELLS_S2) || (item_no == TREE_100BELLS_S2)) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownTree(mActor_name_t item) {
    s32 result;
    mActor_name_t item_no;

    result = 0;
    item_no = item;
    if (((mActor_name_t)(item - TREE_BEES) <= (TREE_FTR - TREE_BEES)) || (item_no == TREE_BELLS) || (item_no == TREE) ||
        ((mActor_name_t)(item_no - TREE_APPLE_NOFRUIT_0) <= (TREE_APPLE_NOFRUIT_2 - TREE_APPLE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_ORANGE_NOFRUIT_0) <= (TREE_ORANGE_NOFRUIT_2 - TREE_ORANGE_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEACH_NOFRUIT_0) <= (TREE_PEACH_NOFRUIT_2 - TREE_PEACH_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_PEAR_NOFRUIT_0) <= (TREE_PEAR_NOFRUIT_2 - TREE_PEAR_NOFRUIT_0)) ||
        ((mActor_name_t)(item_no - TREE_CHERRY_NOFRUIT_0) <= (TREE_CHERRY_NOFRUIT_2 - TREE_CHERRY_NOFRUIT_0)) ||
        (item_no == TREE_1000BELLS) || (item_no == TREE_10000BELLS) || (item_no == TREE_30000BELLS) ||
        (item_no == TREE_100BELLS)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitAppleTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_APPLE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitOrangeTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_ORANGE_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPeachTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEACH_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsPearFruitTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PEAR_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitCherryTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_CHERRY_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargeStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S0) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S1) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_S2) {
        result = 1;
    }
    return result;
}

s32 Item_IsPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - TREE_PALM_NOFRUIT_0) <= (TREE_PALM_NOFRUIT_2 - TREE_PALM_NOFRUIT_0)) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadPalmSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_PALM_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsFruitPalmTree(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_FRUIT) {
        result = 1;
    }
    return result;
}

s32 Item_IsSmallPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP001) {
        result = 1;
    }
    return result;
}

s32 Item_IsMediumPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP002) {
        result = 1;
    }
    return result;
}

s32 Item_IsLargePalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP003) {
        result = 1;
    }
    return result;
}

s32 Item_IsFullyGrownPalmStump(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == TREE_PALM_STUMP004) {
        result = 1;
    }
    return result;
}

s32 Item_IsIslandFlag(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == FLAG) {
        result = 1;
    }
    return result;
}

s32 Item_IsHole(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - HOLE_START) <= (HOLE_END - HOLE_START)) || (item == RSV_ISLAND_HOLE)) {
        result = 1;
    }
    return result;
}

s32 Item_IsBuriedPitfall(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - BURIED_PITFALL_HOLE_START) <=
        (BURIED_PITFALL_HOLE_RSV_END - BURIED_PITFALL_HOLE_START)) {
        result = 1;
    }
    return result;
}

s32 Item_IsCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == CEDAR_TREE_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsDeadCedarSapling(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == DEAD_CEDAR_SAPLING) {
        result = 1;
    }
    return result;
}

s32 Item_IsWeed(mActor_name_t item) {
    s32 result;

    result = 0;
    if ((mActor_name_t)(item - GRASS_A) <= (GRASS_C - GRASS_A)) {
        result = 1;
    }
    return result;
}

s32 Item_IsRock(mActor_name_t item) {
    s32 result;

    result = 0;
    if (((mActor_name_t)(item - ROCK_A) <= (ROCK_E - ROCK_A)) ||
        ((mActor_name_t)(item - MONEY_ROCK_A) <= (MONEY_ROCK_E - MONEY_ROCK_A))) {
        result = 1;
    }
    return result;
}

/* Ghidra name: ItemCheckFunc (differs; this specifically tests reserved item 0xFFFF). */
s32 Item_IsReserved(mActor_name_t item) {
    s32 result;

    result = 0;
    if (item == RSV_NO) {
        result = 1;
    }
    return result;
}


typedef int (*Item_CHK_PROC)(mActor_name_t);

typedef struct item_type_entry_s {
    Item_CHK_PROC chk_proc;
    mActor_name_t item;
} Item_TypeEntry_c;

ItemGroupStruct g_ItemDefinitions[ITEM_TYPE_COUNT] = {
    { 0x423C, 0x0000, 0x409C, 0x0020, 0x0001, 0x0000 }, /* Item_IsFossil */
    { 0x4224, 0x0000, 0x4090, 0x0016, 0x0001, 0x0000 }, /* Item_IsFurniture */
    { 0x5228, 0x0000, 0x5092, 0x0021, 0x0002, 0x0000 }, /* Item_IsGyroid */
    { 0x4204, 0x0000, 0x4080, 0x0000, 0x0005, 0x0000 }, /* Item_IsApple */
    { 0x6208, 0x0000, 0x6082, 0x0001, 0x0005, 0x0000 }, /* Item_IsOrange */
    { 0x420C, 0x0000, 0x4084, 0x0002, 0x0005, 0x0000 }, /* Item_IsPeach */
    { 0x4210, 0x0000, 0x4086, 0x0003, 0x0005, 0x0000 }, /* Item_IsPear */
    { 0x4214, 0x0000, 0x4088, 0x0004, 0x0005, 0x0000 }, /* Item_IsCherry */
    { 0x5218, 0x0000, 0x508A, 0x0FFF, 0x0005, 0x0000 }, /* Item_IsTurnip */
    { 0x521C, 0x0000, 0x508C, 0x0006, 0x0005, 0x0000 }, /* Item_IsMushroom */
    { 0x4220, 0x0000, 0x408E, 0x0007, 0x0005, 0x0000 }, /* Item_IsCandy */
    { 0x522C, 0x0000, 0x5094, 0x0008, 0x0001, 0x0000 }, /* Item_Is100Bells */
    { 0x5230, 0x0000, 0x5096, 0x0FFF, 0x0001, 0x0000 }, /* Item_IsSeedlingDiaryTicketGrabBag */
    { 0x6234, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSignboard */
    { 0x6238, 0x0000, 0x609A, 0x001E, 0x0001, 0x0000 }, /* Item_IsShirt */
    { 0x6240, 0x0000, 0x609E, 0x0025, 0x0004, 0x0000 }, /* Item_IsTrash */
    { 0x5244, 0x0000, 0x50C0, 0x000C, 0x0002, 0x0000 }, /* Item_IsPitfall */
    { 0x5248, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsConchSeaShellIcon */
    { 0x524C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsLionsPawShellIcon */
    { 0x4250, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsCoral */
    { 0x4254, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsPurpleCosmos */
    { 0x6254, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsBlueCosmos */
    { 0x5254, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsYellowCosmos */
    { 0x4258, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsRedTulips */
    { 0x5258, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsWhiteTulips */
    { 0x6258, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsYellowTulips */
    { 0x425C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsWhitePansies */
    { 0x525C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsPurplePansies */
    { 0x625C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsYellowPansies */
    { 0x42A4, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFlowerLeaves */
    { 0x427C, 0x0000, 0x40C8, 0x0005, 0x0005, 0x0000 }, /* Item_IsCoconut */
    { 0x0001, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsCabana */
    { 0x0002, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsIslanderHouse */
    { 0x3260, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSapling */
    { 0x3280, 0x0003, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSmallTree */
    { 0x3284, 0x0004, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsMediumTree */
    { 0x3289, 0x0005, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsLargeTree */
    { 0x3291, 0x0006, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFullyGrownTree */
    { 0x3264, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsDeadSapling */
    { 0x3291, 0x0007, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFruitAppleTree */
    { 0x3291, 0x0008, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFruitOrangeTree */
    { 0x3291, 0x0009, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFruitPeachTree */
    { 0x3291, 0x000A, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsPearFruitTree */
    { 0x3291, 0x000B, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFruitCherryTree */
    { 0x3280, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSmallStump */
    { 0x3284, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsMediumStump */
    { 0x3289, 0x000C, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsLargeStump */
    { 0x3291, 0x000D, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFullyGrownStump */
    { 0x3268, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsPalmSapling */
    { 0x3298, 0x000E, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSmallPalmTree */
    { 0x329C, 0x000F, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsMediumPalmTree */
    { 0x32A0, 0x0010, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsLargePalmTree */
    { 0x32A4, 0x0011, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsPalmTree */
    { 0x326C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsDeadPalmSapling */
    { 0x32A4, 0x0012, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFruitPalmTree */
    { 0x3298, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsSmallPalmStump */
    { 0x329C, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsMediumPalmStump */
    { 0x32A0, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsLargePalmStump */
    { 0x32A4, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsFullyGrownPalmStump */
    { 0x32A8, 0x0013, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsIslandFlag */
    { 0x12AC, 0x0014, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsHole */
    { 0x0270, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsBuriedPitfall */
    { 0x3260, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsCedarSapling */
    { 0x3264, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsDeadCedarSapling */
    { 0x4278, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsWeed */
    { 0x12B0, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsRock */
    { 0x522C, 0x0000, 0x5094, 0x0009, 0x0001, 0x0000 }, /* Item_Is1KBells */
    { 0x522C, 0x0000, 0x5094, 0x000A, 0x0002, 0x0000 }, /* Item_Is10KBells */
    { 0x522C, 0x0000, 0x5094, 0x000B, 0x0003, 0x0000 }, /* Item_Is30KBells */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0007, 0x0000 }, /* Item_IsNet */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0008, 0x0000 }, /* Item_IsGoldenNet */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0009, 0x0000 }, /* Item_IsAxe */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x000A, 0x0000 }, /* Item_IsGoldenAxe */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x000B, 0x0000 }, /* Item_IsShovel */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x000C, 0x0000 }, /* Item_IsGoldenShovel */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x000D, 0x0000 }, /* Item_IsFishingRod */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x000E, 0x0000 }, /* Item_IsGoldenRod */
    { 0x6234, 0x0000, 0x6098, 0x0022, 0x0001, 0x0000 }, /* Item_IsUmbrella */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0002, 0x0000 }, /* Item_IsPaint */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0002, 0x0000 }, /* Item_IsBalloon */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0002, 0x0000 }, /* Item_IsPinwheel */
    { 0x6234, 0x0000, 0x6098, 0x0FFF, 0x0002, 0x0000 }, /* Item_IsHandFan */
    { 0x6238, 0x0000, 0x609A, 0x001A, 0x0001, 0x0000 }, /* Item_IsCarpet */
    { 0x6238, 0x0000, 0x609A, 0x001C, 0x0001, 0x0000 }, /* Item_IsWallpaper */
    { 0x6238, 0x0000, 0x609A, 0x0023, 0x0002, 0x0000 }, /* Item_IsAirCheck */
    { 0x4224, 0x0000, 0x7352, 0x0024, 0x0003, 0x0000 }, /* Item_IsNES */
    { 0x5230, 0x0000, 0x5096, 0x0FFF, 0x0001, 0x0000 }, /* Item_IsFlowerBag */
    { 0x0200, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000 }, /* Item_IsReserved */
};

static Item_TypeEntry_c Item_TypeEntries[ITEM_TYPE_COUNT] = {
    { Item_IsFossil, EMPTY_NO },
    { Item_IsFurniture, EMPTY_NO },
    { Item_IsGyroid, EMPTY_NO },
    { Item_IsApple, ITM_FOOD_APPLE },
    { Item_IsOrange, ITM_FOOD_ORANGE },
    { Item_IsPeach, ITM_FOOD_PEACH },
    { Item_IsPear, ITM_FOOD_PEAR },
    { Item_IsCherry, ITM_FOOD_CHERRY },
    { Item_IsTurnip, EMPTY_NO },
    { Item_IsMushroom, ITM_FOOD_MUSHROOM },
    { Item_IsCandy, ITM_FOOD_CANDY },
    { Item_Is100Bells, ITM_MONEY_100 },
    { Item_IsSeedlingDiaryTicketGrabBag, EMPTY_NO },
    { Item_IsSignboard, ITM_SIGNBOARD },
    { Item_IsShirt, EMPTY_NO },
    { Item_IsTrash, EMPTY_NO },
    { Item_IsPitfall, ITM_PITFALL },
    { Item_IsConchSeaShellIcon, EMPTY_NO },
    { Item_IsLionsPawShellIcon, EMPTY_NO },
    { Item_IsCoral, EMPTY_NO },
    { Item_IsPurpleCosmos, FLOWER_COSMOS1 },
    { Item_IsBlueCosmos, FLOWER_COSMOS2 },
    { Item_IsYellowCosmos, FLOWER_COSMOS0 },
    { Item_IsRedTulips, FLOWER_TULIP0 },
    { Item_IsWhiteTulips, FLOWER_TULIP1 },
    { Item_IsYellowTulips, FLOWER_TULIP2 },
    { Item_IsWhitePansies, FLOWER_PANSIES0 },
    { Item_IsPurplePansies, FLOWER_PANSIES1 },
    { Item_IsYellowPansies, FLOWER_PANSIES2 },
    { Item_IsFlowerLeaves, EMPTY_NO },
    { Item_IsCoconut, ITM_FOOD_COCONUT },
    { Item_IsCabana, EMPTY_NO },
    { Item_IsIslanderHouse, EMPTY_NO },
    { Item_IsSapling, EMPTY_NO },
    { Item_IsSmallTree, EMPTY_NO },
    { Item_IsMediumTree, EMPTY_NO },
    { Item_IsLargeTree, EMPTY_NO },
    { Item_IsFullyGrownTree, EMPTY_NO },
    { Item_IsDeadSapling, EMPTY_NO },
    { Item_IsFruitAppleTree, EMPTY_NO },
    { Item_IsFruitOrangeTree, EMPTY_NO },
    { Item_IsFruitPeachTree, EMPTY_NO },
    { Item_IsPearFruitTree, EMPTY_NO },
    { Item_IsFruitCherryTree, EMPTY_NO },
    { Item_IsSmallStump, EMPTY_NO },
    { Item_IsMediumStump, EMPTY_NO },
    { Item_IsLargeStump, EMPTY_NO },
    { Item_IsFullyGrownStump, EMPTY_NO },
    { Item_IsPalmSapling, EMPTY_NO },
    { Item_IsSmallPalmTree, EMPTY_NO },
    { Item_IsMediumPalmTree, EMPTY_NO },
    { Item_IsLargePalmTree, EMPTY_NO },
    { Item_IsPalmTree, EMPTY_NO },
    { Item_IsDeadPalmSapling, EMPTY_NO },
    { Item_IsFruitPalmTree, EMPTY_NO },
    { Item_IsSmallPalmStump, EMPTY_NO },
    { Item_IsMediumPalmStump, EMPTY_NO },
    { Item_IsLargePalmStump, EMPTY_NO },
    { Item_IsFullyGrownPalmStump, EMPTY_NO },
    { Item_IsIslandFlag, EMPTY_NO },
    { Item_IsHole, EMPTY_NO },
    { Item_IsBuriedPitfall, EMPTY_NO },
    { Item_IsCedarSapling, EMPTY_NO },
    { Item_IsDeadCedarSapling, EMPTY_NO },
    { Item_IsWeed, EMPTY_NO },
    { Item_IsRock, EMPTY_NO },
    { Item_Is1KBells, ITM_MONEY_1000 },
    { Item_Is10KBells, ITM_MONEY_10000 },
    { Item_Is30KBells, ITM_MONEY_30000 },
    { Item_IsNet, ITM_NET },
    { Item_IsGoldenNet, ITM_GOLDEN_NET },
    { Item_IsAxe, ITM_AXE },
    { Item_IsGoldenAxe, ITM_GOLDEN_AXE },
    { Item_IsShovel, ITM_SHOVEL },
    { Item_IsGoldenShovel, ITM_GOLDEN_SHOVEL },
    { Item_IsFishingRod, ITM_ROD },
    { Item_IsGoldenRod, ITM_GOLDEN_ROD },
    { Item_IsUmbrella, EMPTY_NO },
    { Item_IsPaint, EMPTY_NO },
    { Item_IsBalloon, EMPTY_NO },
    { Item_IsPinwheel, EMPTY_NO },
    { Item_IsHandFan, EMPTY_NO },
    { Item_IsCarpet, EMPTY_NO },
    { Item_IsWallpaper, EMPTY_NO },
    { Item_IsAirCheck, EMPTY_NO },
    { Item_IsNES, EMPTY_NO },
    { Item_IsFlowerBag, EMPTY_NO },
    { Item_IsReserved, EMPTY_NO },
};

/* Ghidra name: Item_GetTileId (differs; this returns the matching predicate-table index). */
s32 Item_GetTypeIndex(mActor_name_t item) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(Item_TypeEntries); i++) {
        if (Item_TypeEntries[i].chk_proc(item) != 0) {
            return i;
        }
    }
    return -1;
}

mActor_name_t Item_GetItemFromTypeIndex(s32 idx) {
    if (idx < ARRAY_COUNT(Item_TypeEntries)) {
        return Item_TypeEntries[idx].item;
    }
    return EMPTY_NO;
}

static mActor_name_t gc_rsv_island_item_table[] = {
    RSV_ISLAND_FTR_COMMON,
    RSV_ISLAND_FTR_RARE,
    RSV_ISLAND_FTR_EVENT,
    RSV_ISLAND_FAMICOM,
    RSV_ISLAND_FTR_ISLAND,
    RSV_ISLAND_FOSSIL,
    RSV_ISLAND_MINIDISK,
    RSV_ISLAND_HANIWA,
    RSV_ISLAND_UMBRELLA,
    RSV_ISLAND_CARPET_COMMON,
    RSV_ISLAND_CARPET_RARE,
    RSV_ISLAND_WALL_COMMON,
    RSV_ISLAND_WALL_RARE,
    RSV_ISLAND_CLOTH_COMMON,
    RSV_ISLAND_CLOTH_RARE,
    RSV_ISLAND_HOLE,
    RSV_ISLAND_FLOWER_BAG,
    RSV_ISLAND_TRASH,
};

mActor_name_t Item_TypeToIslandItem(s32 idx) {
    if (idx < ARRAY_COUNT(gc_rsv_island_item_table)) {
        return gc_rsv_island_item_table[idx];
    }
    return EMPTY_NO;
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
    (*(u8 *)((u8 *)(temp_r4_26670) + (0x23))) = arg2;
    (*(u8 *)((u8 *)(temp_r4_26670) + (0x25))) = arg3;
    (*(s8 *)((u8 *)((temp_r4_26670 + 0x25)) + (2))) = 0;
    (*(s32 *)((u8 *)(temp_r4_26670) + (0x10))) = 0;
    (*(s32 *)((u8 *)(temp_r4_26670) + (0x14))) = 0;
    (*(s32 *)((u8 *)(temp_r4_26670) + (0xC))) = 0;
    (*(s16 *)((u8 *)(temp_r4_26670) + (0x20))) = 0;
    (*(s8 *)((u8 *)(temp_r4_26670) + (0x28))) = 0;
    temp_r2_26695 = ((*(u8 *)((u8 *)(temp_r4_26670) + (0x23))) * 0x18) + 0x020344F8;
    temp_r1_26698 = arg0 * 0x30;
    (*(s8 *)((u8 *)(temp_r4_26670) + (0x22))) = 1;
    temp_r0_26705 = (*(u8 *)((u8 *)(temp_r4_26670) + (0x23)));
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
        (*(s8 *)((u8 *)(temp_r4_26670) + (0x22))) = 2;
        /* fallthrough */
        temp_r0_26750 = (*(s32 *)((u8 *)((temp_r1_26698 + 0x03003C00)) + (4))) + (*(s32 *)((u8 *)(temp_r2_26695) + (4)));
        (*(s32 *)((u8 *)(temp_r4_26670) + (4))) = temp_r0_26750;
        (*(s32 *)((u8 *)(temp_r4_26670) + (0x14))) = temp_r0_26750;
        *(u32 *)(0x03004260 + temp_r4_26668) = (s32) (*(u32 *)(0x03003C00 + temp_r1_26698) + (*(s32 *)((u8 *)(temp_r2_26695) + (8))));
        (*(u8 *)((u8 *)(temp_r4_26670) + (0x24))) = (u8) (*(u8 *)((u8 *)(temp_r2_26695) + (0x13)));
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
    rand_u16(&gGameState);
    (*(s32 *)((u8 *)(temp_r4_26783) + (8))) = 0;
    (*(s32 *)((u8 *)(temp_r4_26783) + (0x18))) = 0x200;
    (*(s32 *)((u8 *)(temp_r4_26783) + (0x1C))) = 0x20;
    (*(s8 *)((u8 *)(temp_r4_26783) + (0x26))) = 0x10;
    (*(s8 *)((u8 *)(temp_r4_26783) + (0x22))) = 3;
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
    (*(u8 *)((u8 *)(temp_r4_26820) + (0x26))) = (u8) ((*(u8 *)((u8 *)(temp_r4_26820) + (0x26))) - 1);
    temp_r1_26829 = *(u32 *)(0x03004260 + temp_r1_26818);
    *(u32 *)(0x03004260 + temp_r1_26818) = (s32) (temp_r1_26829 + ((s32) ((*(s32 *)((u8 *)(temp_r4_26820) + (0x10))) - temp_r1_26829) >> 1));
    temp_r1_26834 = (*(s32 *)((u8 *)(temp_r4_26820) + (8)));
    (*(s32 *)((u8 *)(temp_r4_26820) + (4))) = (s32) ((*(s32 *)((u8 *)(temp_r4_26820) + (0x14))) - (temp_r1_26834 >> 8));
    temp_r0_26839 = (*(s32 *)((u8 *)(temp_r4_26820) + (0x18)));
    (*(s32 *)((u8 *)(temp_r4_26820) + (8))) = (s32) (temp_r1_26834 + temp_r0_26839);
    (*(s32 *)((u8 *)(temp_r4_26820) + (0x18))) = (s32) (temp_r0_26839 - (*(s32 *)((u8 *)(temp_r4_26820) + (0x1C))));
    if ((u16) (*(u8 *)((u8 *)(temp_r4_26820) + (0x26))) == 0xC) {
        sub_02026A38(0x17U);
        (*(s8 *)((u8 *)(temp_r4_26820) + (0x27))) = 1;
    }
    if (!(0x80 & (*(u8 *)((u8 *)(temp_r4_26820) + (0x26))))) {
        return;
    }
    if ((s32) (*(s32 *)((u8 *)(temp_r4_26820) + (0xC))) >= (s32) (*(s32 *)((u8 *)(temp_r4_26820) + (4)))) {
        return;
    }
    sp4 = temp_r4_26820 + 0x22;
    sp0 = arg0 + 0x15;
    if ((*(u8 *)((u8 *)(temp_r4_26820) + (0x28))) == 1) {
        temp_r5_26885 = ((*(u8 *)((u8 *)(temp_r4_26820) + (0x23))) * 0x18) + 0x020344F8;
        var_r2_26886 = 0;
        var_r6_26887 = 0;
        do {
            if ((*(u8 *)((u8 *)(temp_r4_26820) + (0x25))) == 0) {
                var_r1_26904 = (0xFF0 & (*(u16 *)((u8 *)(temp_r4_26820) + (0x20)))) * 8;
                var_r7_26905 = 0x0600C000;
            } else {
                var_r1_26904 = (0xFF0 & (*(u16 *)((u8 *)(temp_r4_26820) + (0x20)))) * 8;
                var_r7_26905 = 0x0600C800;
            }
            temp_r3_26925 = var_r1_26904 + var_r7_26905 + var_r2_26886 + ((0xF & (*(u16 *)((u8 *)(temp_r4_26820) + (0x20)))) * 4);
            (*(s16 *)((u8 *)(temp_r3_26925) + (0))) = (s16) (var_r6_26887 + (*(u16 *)((u8 *)(temp_r5_26885) + (0xE))));
            (*(s16 *)((u8 *)(temp_r3_26925) + (2))) = (s16) (var_r6_26887 + (*(u16 *)((u8 *)(temp_r5_26885) + (0xE))) + 1);
            var_r2_26886 += 0x40;
            var_r6_26887 = 2;
        } while (var_r2_26886 <= 0x4F);
        if ((*(u8 *)((u8 *)(temp_r4_26820) + (0x25))) == 0) {
            temp_r0_26943 = (*(u16 *)((u8 *)(temp_r4_26820) + (0x20)));
            *(u32 *)(*(s32 *)0x03001B40 + 0x24 + (((0xF & temp_r0_26943) * 2) + (((temp_r0_26943 >> 4) & 0xF) << 5))) = (*(u16 *)((u8 *)(temp_r5_26885) + (0x10)));
            var_r0_26957 = (*(u16 *)((u8 *)(temp_r4_26820) + (0x20))) * 2;
            var_r1_26959 = 0x03003720;
        } else {
            temp_r0_26966 = (*(u16 *)((u8 *)(temp_r4_26820) + (0x20)));
            *(u32 *)(*(s32 *)0x03001B40 + 0x224 + (((0xF & temp_r0_26966) * 2) + (((temp_r0_26966 >> 4) & 0xF) << 5))) = (*(u16 *)((u8 *)(temp_r5_26885) + (0x10)));
            var_r0_26957 = (*(u16 *)((u8 *)(temp_r4_26820) + (0x20))) * 2;
            var_r1_26959 = 0x03003920;
        }
        *(u32 *)(var_r1_26959 + var_r0_26957) = (s16) (*(u8 *)((u8 *)(temp_r5_26885) + (0x14)));
    }
    *sp4 = 0;
    *(u32 *)(0x03003B27 + (s32) sp0) = 0;
}

void sub_02024DD0(s32 arg0) {
    ((void (*)(void))*(u32 *)(0x020344E8 + ((*(u8 *)((u8 *)(((arg0 * 0x2C) + 0x03004260)) + (0x22))) * 4)))();
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
    temp_r6_27048 = (*(u8 *)((u8 *)(temp_r1_27041) + (0x23))) * 0x18;
    temp_r6_27050 = temp_r6_27048 + 0x020344F8;
    temp_r4_27060 = (gGameState.unk_860 * 8) + gUnk3002410;
    temp_r3_27070 = (0x3F & (*(u8 *)((u8 *)(temp_r4_27060) + (1)))) | ((((u32) *(u32 *)(0x020344F8 + temp_r6_27048) >> 0xE) & 3) << 6);
    (*(u8 *)((u8 *)(temp_r4_27060) + (1))) = temp_r3_27070;
    temp_r2_27079 = (0x3F & (*(u8 *)((u8 *)(temp_r4_27060) + (3)))) | (((u32) *(u32 *)(0x020344F8 + temp_r6_27048) >> 0x1E) << 6);
    (*(u8 *)((u8 *)(temp_r4_27060) + (3))) = temp_r2_27079;
    (*(u16 *)((u8 *)(temp_r4_27060) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r4_27060) + (4)))) | (0x3FF & (*(u16 *)((u8 *)(temp_r6_27050) + (0xC)))));
    (*(u8 *)((u8 *)(temp_r4_27060) + (1))) = (u8) (temp_r3_27070 | 0x10);
    (*(u8 *)((u8 *)(temp_r4_27060) + (3))) = (u8) ((temp_r2_27079 & ~0x10) | (((*(u8 *)((u8 *)(temp_r1_27041) + (0x24))) & 1) * 0x10));
    temp_r0_27108 = (-0xD & (*(u8 *)((u8 *)(temp_r4_27060) + (5)))) | 4;
    (*(u8 *)((u8 *)(temp_r4_27060) + (5))) = temp_r0_27108;
    (*(u8 *)((u8 *)(temp_r4_27060) + (5))) = (u8) ((temp_r0_27108 & 0xF) | ((*(u8 *)((u8 *)(temp_r6_27050) + (0x12))) * 0x10));
    (*(u16 *)((u8 *)(temp_r4_27060) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r4_27060) + (2)))) | ((*(u32 *)(0x03004260 + temp_r1_27039) - gGameState.unk_844) & 0x1FF));
    (*(s8 *)((u8 *)(temp_r4_27060) + (0))) = (s8) ((*(s32 *)((u8 *)(temp_r1_27041) + (4))) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
    gGameState.unk_860 += 1;
}

void Unk_Struct_Size54_ResetIdx(s32 arg0) {
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
    *(u32 *)(0x03004790 + temp_r1_27165) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (4))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (8))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0xC))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x10))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x14))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x18))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x1C))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x20))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27167) + (0x24))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27167) + (0x4D))) = 0;
    temp_r1_27182 = (temp_r1_27167 + 0x4D) - 1;
    (*(s8 *)((u8 *)(temp_r1_27182) + (0))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27182) + (2))) = 0;
    (*(s8 *)((u8 *)((temp_r1_27182 + 2)) + (1))) = 0;
    (*(s16 *)((u8 *)(temp_r1_27167) + (0x40))) = 0xA;
    (*(s16 *)((u8 *)(temp_r1_27167) + (0x3E))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27167) + (0x50))) = 0;
    temp_r1_27197 = (temp_r1_27167 + 0x50) - 5;
    (*(s8 *)((u8 *)(temp_r1_27197) + (0))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27197) + (6))) = 0;
    temp_r1_27201 = (temp_r1_27197 + 6) - 0xD;
    *temp_r1_27201 = 0;
    *(temp_r1_27201 - 2) = 0;
    var_r0_27207 = temp_r1_27167 + 0x28;
    var_r1_27208 = 4;
    do {
        (*(s16 *)((u8 *)(var_r0_27207) + (0))) = 0;
        (*(s16 *)((u8 *)(var_r0_27207) + (0xA))) = 0;
        var_r0_27207 += 2;
        var_r1_27208 -= 1;
    } while (var_r1_27208 >= 0);
    (*(s8 *)((u8 *)(temp_r1_27167) + (0x52))) = 0;
    temp_r0_27220 = (temp_r1_27167 + 0x52) - 0xC;
    (*(s16 *)((u8 *)(temp_r0_27220) + (0))) = 0;
    (*(s16 *)((u8 *)(temp_r0_27220) + (2))) = 0;
    (*(s16 *)((u8 *)(temp_r1_27167) + (0x3C))) = 0;
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
    var_r5_27245 = (*(u16 *)((u8 *)(temp_r6_27242) + (0x32)));
    if ((*(u8 *)((u8 *)(temp_r6_27242) + (0x4A))) == 0) {
        temp_r0_27251 = var_r5_27245 * 4;
        if ((*(u8 *)((u8 *)((temp_r0_27251 + 0x02034CF4)) + (3))) == 0) {
            var_r5_27245 = *(u32 *)(0x02034CF4 + temp_r0_27251);
        } else {
            var_r5_27245 = Item_TypeToIslandItem(*(u32 *)(0x02034CF4 + temp_r0_27251));
        }
    }
    temp_r1_27269 = (*(u16 *)((u8 *)(temp_r6_27242) + (0x3C)));
    temp_r7_27270 = temp_r1_27269 << 0x18;
    temp_r4_27271 = (u8) temp_r1_27269;
    if (!(0x1000 & temp_r1_27269)) {
        *(u32 *)(0x03003720 + (temp_r4_27271 * 2)) = (s16) (0x8000 | (*(u16 *)((u8 *)(temp_r6_27242) + (0x28))));
        temp_r1_27293 = 0xF & temp_r4_27271;
        var_r3_27295 = ((0xF0 & temp_r4_27271) * 8) + 0x0600C000 + (temp_r1_27293 * 4);
        var_r1_27301 = (temp_r1_27293 * 2) + ((temp_r7_27270 >> 0x1C) << 5);
        var_r2_27302 = *(s32 *)0x03001B40 + 0x24;
    } else {
        *(u32 *)(0x03003920 + (temp_r4_27271 * 2)) = (s16) (0x8000 | (*(u16 *)((u8 *)(temp_r6_27242) + (0x28))));
        temp_r1_27325 = 0xF & temp_r4_27271;
        var_r3_27295 = ((0xF0 & temp_r4_27271) * 8) + 0x0600C800 + (temp_r1_27325 * 4);
        var_r1_27301 = (temp_r1_27325 * 2) + ((temp_r7_27270 >> 0x1C) << 5);
        var_r2_27302 = *(u32 *)0x03001B40 + 0x224;
    }
    *(u32 *)(var_r2_27302 + var_r1_27301) = var_r5_27245;
    temp_r1_27343 = (*(u16 *)((u8 *)(temp_r6_27242) + (0x28))) * 0xC;
    (*(u16 *)((u8 *)(var_r3_27295) + (0))) = (u16) *(u32 *)(0x0202F7FC + temp_r1_27343);
    temp_r3_27348 = var_r3_27295 + 2;
    (*(s16 *)((u8 *)(var_r3_27295) + (2))) = (s16) (*(u32 *)(0x0202F7FC + temp_r1_27343) + 1);
    (*(s16 *)((u8 *)(temp_r3_27348) + (0x3E))) = (s16) (*(u32 *)(0x0202F7FC + temp_r1_27343) + 2);
    (*(s16 *)((u8 *)((temp_r3_27348 + 0x3E)) + (2))) = (s16) (*(u32 *)(0x0202F7FC + temp_r1_27343) + 3);
    (*(s8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = 0;
}

void sub_020250B0(s32 arg0) {
    u16 temp_r0_27388;
    void *temp_r0_27385;

    temp_r0_27385 = (arg0 * 0x54) + 0x03004790;
    temp_r0_27388 = (*(u16 *)((u8 *)(temp_r0_27385) + (0x40)));
    if (temp_r0_27388 == 0) {
        (*(s8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = (s8) temp_r0_27388;
        return;
    }
    (*(u16 *)((u8 *)(temp_r0_27385) + (0x40))) = (u16) (temp_r0_27388 - 1);
}

void sub_020250EC(s32 arg0) {
    void *temp_r1_27420;
    void *temp_r2_27415;

    temp_r2_27415 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27420 = temp_r2_27415 + 0x4D;
    (*(s8 *)((u8 *)(temp_r2_27415) + (0x4D))) = (s8) (*(u16 *)((u8 *)(*(void **)0x02034C24) + (4)));
    (*(s8 *)((u8 *)(temp_r1_27420) + (2))) = 1;
    *(u32 *)((temp_r1_27420 + 2) - 1) = 2;
}

void sub_02025118(s32 arg0) {
    s8 temp_r3_27459;
    u8 temp_r0_27447;
    u8 temp_r0_27456;
    void *temp_r1_27441;

    temp_r1_27441 = (0x54 * arg0) + 0x03004790;
    temp_r0_27447 = (*(u8 *)((u8 *)(temp_r1_27441) + (0x4D))) - 1;
    (*(u8 *)((u8 *)(temp_r1_27441) + (0x4D))) = temp_r0_27447;
    if ((temp_r0_27447 << 0x18) == 0) {
        temp_r0_27456 = (*(u8 *)((u8 *)(temp_r1_27441) + (0x4C))) + 1;
        (*(u8 *)((u8 *)(temp_r1_27441) + (0x4C))) = temp_r0_27456;
        temp_r3_27459 = 7 & temp_r0_27456;
        if (temp_r3_27459 == 0) {
            (*(s8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = temp_r3_27459;
            return;
        }
        (*(u8 *)((u8 *)(temp_r1_27441) + (0x4D))) = (u8) (*(u16 *)((u8 *)(*(u32 *)(0x02034C24 + ((*(u8 *)((u8 *)(temp_r1_27441) + (0x4C))) * 4))) + (4)));
    }
}

void sub_02025180(s32 arg0) {
    void *temp_r1_27497;
    void *temp_r2_27492;

    temp_r2_27492 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27497 = temp_r2_27492 + 0x4D;
    (*(s8 *)((u8 *)(temp_r2_27492) + (0x4D))) = (s8) (*(u16 *)((u8 *)(*(void **)0x02034C44) + (4)));
    (*(s8 *)((u8 *)(temp_r1_27497) + (2))) = 2;
    *(u32 *)((temp_r1_27497 + 2) - 1) = 4;
}

void sub_020251AC(s32 arg0) {
    u8 temp_r0_27523;
    u8 temp_r0_27532;
    u8 temp_r4_27526;
    void *temp_r1_27518;

    temp_r1_27518 = (0x54 * arg0) + 0x03004790;
    temp_r0_27523 = (*(u8 *)((u8 *)(temp_r1_27518) + (0x4D))) - 1;
    (*(u8 *)((u8 *)(temp_r1_27518) + (0x4D))) = temp_r0_27523;
    temp_r4_27526 = temp_r0_27523;
    if (temp_r4_27526 == 0) {
        temp_r0_27532 = (*(u8 *)((u8 *)(temp_r1_27518) + (0x4C))) + 1;
        (*(u8 *)((u8 *)(temp_r1_27518) + (0x4C))) = temp_r0_27532;
        if ((u32) temp_r0_27532 > 0x13U) {
            (*(u8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = temp_r4_27526;
            return;
        }
        (*(u8 *)((u8 *)(temp_r1_27518) + (0x4D))) = (u8) (*(u16 *)((u8 *)(*(u32 *)(0x02034C44 + ((*(u8 *)((u8 *)(temp_r1_27518) + (0x4C))) * 4))) + (4)));
    }
}

void sub_02025210(s32 arg0) {
    u8 temp_r1_27572;
    void *temp_r4_27568;
    void *temp_r5_27576;

    temp_r4_27568 = (arg0 * 0x54) + 0x03004790;
    temp_r1_27572 = (*(u8 *)((u8 *)(temp_r4_27568) + (0x4B)));
    temp_r5_27576 = **(u32 **)(0x02034CE0 + (temp_r1_27572 * 4));
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
    (*(s8 *)((u8 *)(temp_r4_27568) + (0x4D))) = (s8) (*(u16 *)((u8 *)(temp_r5_27576) + (4)));
    (*(s8 *)((u8 *)(temp_r4_27568) + (0x4C))) = 0;
    (*(s8 *)((u8 *)(temp_r4_27568) + (0x4F))) = 3;
    *(u32 *)((temp_r4_27568 + 0x4F) - 1) = 6;
}

void sub_0202529C(s32 arg0) {
    u8 temp_r0_27643;
    u8 temp_r4_27647;
    void *temp_r1_27665;
    void *temp_r3_27637;

    temp_r3_27637 = (0x54 * arg0) + 0x03004790;
    temp_r0_27643 = (*(u8 *)((u8 *)(temp_r3_27637) + (0x4D))) - 1;
    (*(u8 *)((u8 *)(temp_r3_27637) + (0x4D))) = temp_r0_27643;
    temp_r4_27647 = temp_r0_27643;
    if (temp_r4_27647 == 0) {
        (*(u8 *)((u8 *)(temp_r3_27637) + (0x4C))) = (u8) ((*(u8 *)((u8 *)(temp_r3_27637) + (0x4C))) + 1);
        temp_r1_27665 = *(u32 *)(((*(u8 *)((u8 *)(temp_r3_27637) + (0x4C))) * 4) + *(u32 *)(0x02034CE0 + ((*(u8 *)((u8 *)(temp_r3_27637) + (0x4B))) * 4)));
        if ((*(u8 *)((u8 *)(temp_r1_27665) + (6))) == 0xFF) {
            (*(u8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = temp_r4_27647;
            return;
        }
        (*(u8 *)((u8 *)(temp_r3_27637) + (0x4D))) = (u8) (*(u16 *)((u8 *)(temp_r1_27665) + (4)));
    }
}

void sub_02025310(s32 arg0) {
    s32 temp_r4_27693;
    void *temp_r4_27695;

    temp_r4_27693 = 0x54 * arg0;
    temp_r4_27695 = temp_r4_27693 + 0x03004790;
    (*(s32 *)((u8 *)(temp_r4_27695) + (0xC))) = (s32) (*(u32 *)(0x03004790 + temp_r4_27693) << 8);
    (*(s32 *)((u8 *)(temp_r4_27695) + (0x10))) = (s32) ((*(s32 *)((u8 *)(temp_r4_27695) + (4))) << 8);
    (*(s32 *)((u8 *)(temp_r4_27695) + (8))) = 0;
    (*(s32 *)((u8 *)(temp_r4_27695) + (0x14))) = 0x200;
    (*(s32 *)((u8 *)(temp_r4_27695) + (0x20))) = 0x20;
    sub_02026A38(0x1EU);
    (*(s8 *)((u8 *)(temp_r4_27695) + (0x4F))) = 0;
    (*(s8 *)((u8 *)(temp_r4_27695) + (0x4E))) = 8;
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
    *(u32 *)(0x03004790 + temp_r1_27729) = (s32) ((s32) (*(s32 *)((u8 *)(temp_r1_27731) + (0xC))) >> 8);
    temp_r4_27736 = (s32) (*(s32 *)((u8 *)(temp_r1_27731) + (0x10))) >> 8;
    temp_r2_27737 = (*(s32 *)((u8 *)(temp_r1_27731) + (8)));
    temp_r3_27739 = temp_r4_27736 - (temp_r2_27737 >> 8);
    (*(s32 *)((u8 *)(temp_r1_27731) + (4))) = temp_r3_27739;
    temp_r0_27741 = (*(s32 *)((u8 *)(temp_r1_27731) + (0x14)));
    (*(s32 *)((u8 *)(temp_r1_27731) + (8))) = (s32) (temp_r2_27737 + temp_r0_27741);
    (*(s32 *)((u8 *)(temp_r1_27731) + (0x14))) = (s32) (temp_r0_27741 - (*(s32 *)((u8 *)(temp_r1_27731) + (0x20))));
    temp_r0_27748 = (*(u8 *)((u8 *)(temp_r1_27731) + (0x52)));
    if (temp_r0_27748 == 0) {
        if (temp_r3_27739 > (s32) (temp_r4_27736 + 8)) {
            sub_02024F8C(arg0);
        }
    } else {
        (*(u8 *)((u8 *)(temp_r1_27731) + (0x52))) = (u8) (temp_r0_27748 - 1);
    }
}

void sub_020253A8(s32 arg0) {
    s32 temp_r1_27772;
    void *temp_r0_27801;
    void *temp_r1_27774;

    temp_r1_27772 = arg0 * 0x54;
    temp_r1_27774 = temp_r1_27772 + 0x03004790;
    (*(s32 *)((u8 *)(temp_r1_27774) + (0xC))) = (s32) (*(u32 *)(0x03004790 + temp_r1_27772) << 8);
    (*(s32 *)((u8 *)(temp_r1_27774) + (0x10))) = (s32) ((*(s32 *)((u8 *)(temp_r1_27774) + (4))) << 8);
    (*(s32 *)((u8 *)(temp_r1_27774) + (8))) = 0;
    (*(s32 *)((u8 *)(temp_r1_27774) + (0x20))) = 0x20;
    (*(s32 *)((u8 *)(temp_r1_27774) + (0x24))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27774) + (0x4D))) = 0x10;
    (*(s8 *)((u8 *)(temp_r1_27774) + (0x4C))) = 0;
    *(u32 *)((temp_r1_27774 + 0x4D) - 9) = 0x300;
    temp_r0_27801 = temp_r1_27774 + 0x46;
    (*(s16 *)((u8 *)(temp_r1_27774) + (0x46))) = 0;
    (*(s16 *)((u8 *)(temp_r0_27801) + (2))) = 0;
    (*(s8 *)((u8 *)((temp_r0_27801 + 2)) + (7))) = 0;
    (*(s8 *)((u8 *)(temp_r1_27774) + (0x4E))) = 0xA;
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
    temp_r2_27833 = (*(s32 *)((u8 *)(temp_r3_27826) + (0xC))) + (*(s32 *)((u8 *)(temp_r3_27826) + (0x18)));
    (*(s32 *)((u8 *)(temp_r3_27826) + (0xC))) = temp_r2_27833;
    *(u32 *)(0x03004790 + temp_r1_27824) = (s32) (temp_r2_27833 >> 8);
    (*(s32 *)((u8 *)(temp_r3_27826) + (4))) = (s32) ((((s32) (*(s32 *)((u8 *)(temp_r3_27826) + (0x10))) >> 8) - (*(s32 *)((u8 *)(temp_r3_27826) + (0x24)))) + ((s32) (*(s32 *)((u8 *)(temp_r3_27826) + (8))) >> 8));
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) = temp_r2_27833;
    (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) = (s32) (*(s32 *)((u8 *)(temp_r3_27826) + (0x10)));
    (*(s32 *)((u8 *)(temp_r3_27826) + (8))) = (s32) ((*(s32 *)((u8 *)(temp_r3_27826) + (8))) + (*(s32 *)((u8 *)(temp_r3_27826) + (0x20))));
    if ((s32) (*(s32 *)((u8 *)(temp_r3_27826) + (0x18))) >= 0) {
        if ((s32) *(u32 *)(0x03004790 + temp_r1_27824) > (s32) (*(s32 *)((u8 *)(temp_r3_27826) + (0x14)))) {
            goto block_4;
        }
    } else if ((s32) *(u32 *)(0x03004790 + temp_r1_27824) < (s32) (*(s32 *)((u8 *)(temp_r3_27826) + (0x14)))) {
block_4:
        var_r4_27830 = 1;
    }
    if (((*(u16 *)((u8 *)((void *)0x030041A0) + (0x62))) != 0) || (var_r4_27830 != 0)) {
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) = (u16) ((*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) + 0xFFFFF900);
        temp_r4_27891 = (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) + 0x10;
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) = temp_r4_27891;
        temp_r5_27893 = (*(s32 *)((u8 *)(temp_r3_27826) + (0x24)));
        if ((temp_r5_27893 > 0) && !(temp_r4_27891 & 0x10)) {
            (*(s32 *)((u8 *)(temp_r3_27826) + (0x24))) = (s32) (temp_r5_27893 - 1);
        }
        if ((u32) (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) <= 0x300U) {
            return;
        }
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) = 0x300U;
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) = 0U;
        (*(u16 *)((u8 *)((void *)0x030041A0) + (0x76))) = 0x2A30U;
        (*(u16 *)((u8 *)((void *)0x030041A0) + (0x76))) = (u16) ((0x64 * ((s32) rand_u16(&gGameState) % 109)) + (*(u16 *)((u8 *)((void *)0x030041A0) + (0x76))));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))) = 0;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))) = 0;
        (*(s8 *)((u8 *)((arg0 + 0x03003710)) + (0x41A))) = 0;
        return;
    }
    temp_r0_27941 = (*(s32 *)((u8 *)(temp_r3_27826) + (0x24)));
    if (temp_r0_27941 <= 0x17) {
        (*(s32 *)((u8 *)(temp_r3_27826) + (0x24))) = (s32) (temp_r0_27941 + 1);
    }
    (*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) = (u16) ((*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) + 0x700);
    temp_r0_27959 = (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) - 0x10;
    (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) = temp_r0_27959;
    if ((u32) temp_r0_27959 <= 0xFFU) {
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x44))) = 0x100U;
        (*(u16 *)((u8 *)(temp_r3_27826) + (0x42))) = var_r4_27830;
        if ((*(u8 *)((u8 *)(temp_r3_27826) + (0x4D))) == 0) {
            (*(u8 *)((u8 *)(temp_r3_27826) + (0x4D))) = 0x10U;
            temp_r0_27980 = (*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) + 1;
            (*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) = temp_r0_27980;
            if ((u32) temp_r0_27980 > 4U) {
                (*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) = 0U;
            }
            temp_r2_27989 = (*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) * 2;
            temp_r4_27995 = temp_r3_27826 + 0x28;
            if ((*(u32 *)(temp_r3_27826 + 0x32 + temp_r2_27989) == 0) && (*(u32 *)(temp_r4_27995 + temp_r2_27989) == 0)) {
                (*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) = 0U;
            }
            temp_r1_28012 = (*(u32 *)(temp_r4_27995 + ((*(u8 *)((u8 *)(temp_r3_27826) + (0x4C))) * 2)) * 0xC) + 0x0202F7FC;
            (*(s16 *)((u8 *)(temp_r3_27826) + (0x3E))) = (s16) (0x3FF & (*(u16 *)((u8 *)(temp_r1_28012) + (4))));
            (*(s8 *)((u8 *)(temp_r3_27826) + (0x50))) = (s8) ((u16) (*(u16 *)((u8 *)(temp_r1_28012) + (4))) >> 0xC);
        }
        (*(u8 *)((u8 *)(temp_r3_27826) + (0x4D))) = (u8) ((*(u8 *)((u8 *)(temp_r3_27826) + (0x4D))) - 1);
    }
    temp_r0_28034 = *(u32 *)(0x0202AD34 + ((*(u16 *)((u8 *)(temp_r3_27826) + (0x46))) * 2));
    temp_r2_28035 = temp_r0_28034 >> 2;
    (*(s32 *)((u8 *)(temp_r3_27826) + (0x20))) = temp_r2_28035;
    if (temp_r0_28034 & 0x8000) {
        (*(s32 *)((u8 *)(temp_r3_27826) + (0x20))) = (s32) (temp_r2_28035 | 0xFFFF0000);
    }
    temp_r0_28047 = (*(u16 *)((u8 *)(temp_r3_27826) + (0x46))) + 4;
    (*(u16 *)((u8 *)(temp_r3_27826) + (0x46))) = (u16) temp_r0_28047;
    if (temp_r0_28047 == 0) {
        (*(s32 *)((u8 *)(temp_r3_27826) + (0x20))) = (s32) temp_r0_28047;
    }
}

void sub_020255F0(s32 arg0) {
    ((void (*)(void))*(u32 *)(0x020347E0 + ((*(u8 *)((u8 *)(((arg0 * 0x54) + 0x03004790)) + (0x4E))) * 4)))();
}

void sub_02025618(s32 arg0) {
    s32 temp_r1_28091;
    void *temp_r2_28106;
    void *temp_r5_28093;

    temp_r1_28091 = arg0 * 0x54;
    temp_r5_28093 = temp_r1_28091 + 0x03004790;
    if ((*(u8 *)((u8 *)(temp_r5_28093) + (0x4E))) == 0xA) {
        temp_r2_28106 = (gGameState.unk_860 * 8) + gUnk3002410;
        (*(s8 *)((u8 *)(temp_r2_28106) + (0))) = (s8) ((((s32) (*(s32 *)((u8 *)(temp_r5_28093) + (0x10))) >> 8) + ((s32) (*(s32 *)((u8 *)(temp_r5_28093) + (8))) >> 8)) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
        (*(u16 *)((u8 *)(temp_r2_28106) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r2_28106) + (2)))) | ((*(u32 *)(0x03004790 + temp_r1_28091) - (gGameState.unk_844 - 8)) & 0x1FF));
        (*(u8 *)((u8 *)(temp_r2_28106) + (1))) = (u8) (0x3F & (*(u8 *)((u8 *)(temp_r2_28106) + (1))));
        (*(u8 *)((u8 *)(temp_r2_28106) + (3))) = (u8) (0x3F & (*(u8 *)((u8 *)(temp_r2_28106) + (3))));
        (*(u16 *)((u8 *)(temp_r2_28106) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r2_28106) + (4)))) | 0x200);
        (*(u8 *)((u8 *)(temp_r2_28106) + (5))) = (u8) ((((0xF & (*(u8 *)((u8 *)(temp_r2_28106) + (5)))) | 0x10) & ~0xC) | 4);
        gGameState.unk_860 += 1;
    }
}

void sub_020256D0(s32 arg0) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
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
    temp_r0_28191 = (*(u8 *)((u8 *)(temp_r1_28186) + (0x4F)));
    switch (temp_r0_28191) {                        /* irregular */
    case 1:
        var_r1_28206 = 0x02034C24;
        var_r0_28209 = (*(u8 *)((u8 *)(temp_r1_28186) + (0x4C)));
block_9:
        var_r1_28188 = *(u32 *)((var_r0_28209 * 4) + var_r1_28206);
        break;
    case 2:
        var_r1_28206 = 0x02034C44;
        var_r0_28209 = (*(u8 *)((u8 *)(temp_r1_28186) + (0x4C)));
        goto block_9;
    case 3:
        var_r0_28209 = (*(u8 *)((u8 *)(temp_r1_28186) + (0x4C)));
        var_r1_28206 = *(u32 *)(0x02034CE0 + ((*(u8 *)((u8 *)(temp_r1_28186) + (0x4B))) * 4));
        goto block_9;
    }
    if ((*(u8 *)((u8 *)(temp_r1_28186) + (0x4F))) == 0) {
        temp_r5_28418 = (gGameState.unk_860 * 8) + gUnk3002410;
        (*(s8 *)((u8 *)(temp_r5_28418) + (0))) = (s8) ((*(s32 *)((u8 *)(temp_r1_28186) + (4))) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
        (*(u16 *)((u8 *)(temp_r5_28418) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r5_28418) + (2)))) | ((*(u32 *)(0x03004790 + temp_r1_28184) - gGameState.unk_844) & 0x1FF));
        temp_r2_28443 = 0x3F & (*(u8 *)((u8 *)(temp_r5_28418) + (1)));
        (*(u8 *)((u8 *)(temp_r5_28418) + (1))) = temp_r2_28443;
        (*(u8 *)((u8 *)(temp_r5_28418) + (3))) = (u8) ((0x3F & (*(u8 *)((u8 *)(temp_r5_28418) + (3)))) | 0x40);
        (*(u16 *)((u8 *)(temp_r5_28418) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r5_28418) + (4)))) | (0x3FF & (*(u16 *)((u8 *)(temp_r1_28186) + (0x3E)))));
        (*(u8 *)((u8 *)(temp_r5_28418) + (1))) = (u8) (temp_r2_28443 | 0x10);
        (*(u8 *)((u8 *)(temp_r5_28418) + (5))) = (u8) ((((0xF & (*(u8 *)((u8 *)(temp_r5_28418) + (5)))) | ((*(u8 *)((u8 *)(temp_r1_28186) + (0x50))) * 0x10)) & ~0xC) | 4);
        gGameState.unk_860 += 1;
        if ((*(u8 *)((u8 *)(temp_r1_28186) + (0x4E))) == 0xA) {
            (*(u8 *)((u8 *)(temp_r5_28418) + (3))) = (u8) ((-0xF & (*(u8 *)((u8 *)(temp_r5_28418) + (3)))) | 2);
            (*(u8 *)((u8 *)(temp_r5_28418) + (1))) = (u8) (((-4 & (*(u8 *)((u8 *)(temp_r5_28418) + (1)))) | 1) & ~0xC);
            temp_r1_28505 = (sp0 & 0xFFFF0000) | (*(u16 *)((u8 *)(temp_r1_28186) + (0x44)));
            sp0 = temp_r1_28505;
            sp0 = (0xFFFF & temp_r1_28505) | ((*(u16 *)((u8 *)(temp_r1_28186) + (0x44))) << 0x10);
            sp4 = (sp4 & 0xFFFF0000) | (*(u16 *)((u8 *)(temp_r1_28186) + (0x42)));
            ObjAffineSet((struct ObjAffineSrcData *) &sp0, &sp8, 1, 2);
            (*(u16 *)((u8 *)(gUnk3002410) + (0x26))) = (u16) (*(u16 *)((u8 *)(&sp8) + (0)));
            (*(u16 *)((u8 *)(gUnk3002410) + (0x2E))) = (u16) (*(u16 *)((u8 *)(&sp8) + (2)));
            (*(u16 *)((u8 *)(gUnk3002410) + (0x36))) = (u16) (*(u16 *)((u8 *)(&sp8) + (4)));
            (*(u16 *)((u8 *)(gUnk3002410) + (0x3E))) = (u16) (*(u16 *)((u8 *)(&sp8) + (6)));
        }
        return;
    }
    var_r3_28244 = *var_r1_28188;
    var_r8_28246 = 0;
    if ((*(u16 *)((u8 *)(var_r3_28244) + (6))) == 0xFFFF) {
        return;
    }
loop_15:
    temp_r5_28267 = (gGameState.unk_860 * 8) + gUnk3002410;
    (*(s8 *)((u8 *)(temp_r5_28267) + (0))) = (s8) (((*(u8 *)((u8 *)(var_r3_28244) + (0))) + (*(s32 *)((u8 *)(temp_r1_28186) + (4)))) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
    temp_r2_28283 = (-0xD & (*(u8 *)((u8 *)(temp_r5_28267) + (1)))) | (0xC & (*(u8 *)((u8 *)(var_r3_28244) + (1))));
    (*(u8 *)((u8 *)(temp_r5_28267) + (1))) = temp_r2_28283;
    temp_r1_28293 = (-0x21 & temp_r2_28283) | ((((u32) ((*(u8 *)((u8 *)(var_r3_28244) + (1))) << 0x1A) >> 0x1F) & 1) << 5);
    (*(u8 *)((u8 *)(temp_r5_28267) + (1))) = temp_r1_28293;
    (*(u8 *)((u8 *)(temp_r5_28267) + (1))) = (u8) ((temp_r1_28293 & 0x3F) | (((u8) (*(u8 *)((u8 *)(var_r3_28244) + (1))) >> 6) << 6));
    (*(u16 *)((u8 *)(temp_r5_28267) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r5_28267) + (2)))) | (((((u32) ((*(u16 *)((u8 *)(var_r3_28244) + (2))) << 0x17) >> 0x17) + *(u32 *)(0x03004790 + temp_r1_28184)) - gGameState.unk_844) & 0x1FF));
    temp_r2_28329 = (-0x11 & (*(u8 *)((u8 *)(temp_r5_28267) + (3)))) | (((*(u8 *)((u8 *)(temp_r1_28186) + (0x51))) & 1) * 0x10);
    (*(u8 *)((u8 *)(temp_r5_28267) + (3))) = temp_r2_28329;
    temp_r1_28339 = (-0x21 & temp_r2_28329) | ((((u32) ((*(u8 *)((u8 *)(var_r3_28244) + (3))) << 0x1A) >> 0x1F) & 1) << 5);
    (*(u8 *)((u8 *)(temp_r5_28267) + (3))) = temp_r1_28339;
    (*(u8 *)((u8 *)(temp_r5_28267) + (3))) = (u8) ((temp_r1_28339 & 0x3F) | (((u8) (*(u8 *)((u8 *)(var_r3_28244) + (3))) >> 6) << 6));
    (*(u16 *)((u8 *)(temp_r5_28267) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r5_28267) + (4)))) | ((u32) ((*(u16 *)((u8 *)(var_r3_28244) + (4))) << 0x16) >> 0x16));
    temp_r1_28360 = (-0xD & (*(u8 *)((u8 *)(temp_r5_28267) + (5)))) | 4;
    (*(u8 *)((u8 *)(temp_r5_28267) + (5))) = temp_r1_28360;
    if ((*(u8 *)((u8 *)(temp_r1_28186) + (0x4E))) == 6) {
        (*(u8 *)((u8 *)(temp_r5_28267) + (5))) = (u8) (temp_r1_28360 & ~0xC);
    }
    (*(u8 *)((u8 *)(temp_r5_28267) + (5))) = (u8) ((0xF & (*(u8 *)((u8 *)(temp_r5_28267) + (5)))) | (((u8) (*(u8 *)((u8 *)(var_r3_28244) + (5))) >> 4) * 0x10));
    (*(u8 *)((u8 *)(temp_r5_28267) + (1))) = (u8) ((*(u8 *)((u8 *)(temp_r5_28267) + (1))) | 0x10);
    gGameState.unk_860 += 1;
    var_r8_28246 += 1;
    var_r3_28244 += 8;
    if (var_r8_28246 > 0xB) {
        return;
    }
    if ((*(u16 *)((u8 *)(var_r3_28244) + (6))) != 0xFFFF) {
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
    temp_r2_28567 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10)));
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) = (u8) (((*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) & ~0xF) | ((s32) (0xF0 & temp_r2_28567) >> 4));
    if (!(temp_r2_28567 & 0xFF00)) {
        temp_r2_28578 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
        temp_r3_28583 = *(u32 *)(0x03003720 + (temp_r2_28578 * 2));
        if ((temp_r3_28583 != 0xFFF) && (temp_r3_28583 != 0x7777)) {
            goto block_37;
        }
        if ((*(u8 *)0x03004257 == 0) && ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) == *(u8 *)0x03004258)) {
            goto block_37;
        }
        temp_r0_28606 = temp_r2_28578 * 2;
        if ((*(u32 *)(0x03003720 + temp_r0_28606) == 0xFFF) || (((*(u8 *)((u8 *)((void *)0x03004B80) + (0x28))) == 0) && (temp_r2_28578 == (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29)))))) {
            *(u32 *)(0x03003720 + temp_r0_28606) = 0xFFFU;
            var_r7_28562 = *(u32 *)(0x03003720 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2));
            var_r6_28628 = 0x0600A000;
            goto block_20;
        }
        goto block_21;
    }
    temp_r2_28638 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
    temp_r1_28644 = *(u32 *)(0x03003920 + (temp_r2_28638 * 2));
    if ((temp_r1_28644 != 0xFFF) && (temp_r1_28644 != 0x7777)) {
        goto block_37;
    }
    if ((*(u32 *)0x03004257 == 0) || ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) != *(u32 *)0x03004258)) {
        temp_r0_28665 = temp_r2_28638 * 2;
        if ((*(u32 *)(0x03003920 + temp_r0_28665) == 0xFFF) || (((*(u8 *)((u8 *)((void *)0x03004B80) + (0x28))) != 0) && (temp_r2_28638 == (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29)))))) {
            *(u32 *)(0x03003920 + temp_r0_28665) = 0xFFFU;
            var_r7_28562 = *(u32 *)(0x03003920 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2));
            var_r6_28628 = 0x0600A800;
block_20:
            var_r6_28561 = ((0xF0 & (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)))) * 8) + var_r6_28628 + (((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) & 0xF) * 4);
        }
block_21:
        if (CheckSurroundingCollision(var_r7_28562, var_r6_28561) == 0) {
            temp_r0_28707 = *var_r6_28561;
            temp_r2_28709 = 0x3FF & temp_r0_28707;
            if (((temp_r2_28709 > 5U) && ((u32) (u16) (temp_r2_28709 - 0x10) > 5U) && (temp_r2_28709 != 0x82) && (temp_r2_28709 <= 0xAFU)) || ((0x3FF & temp_r0_28707) == 0x13)) {
                temp_r3_28735 = (*(s32 *)((u8 *)((void *)0x03003BC4) + (8))) - (((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8) - 8);
                (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = temp_r3_28735;
                (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = (s32) ((*(s32 *)((u8 *)((void *)0x03003BC4) + (0xC))) - ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8));
                if (temp_r3_28735 < 0) {
                    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = (s32) (0 - temp_r3_28735);
                }
                temp_r0_28747 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14)));
                if (temp_r0_28747 < 0) {
                    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = (s32) (0 - temp_r0_28747);
                }
                if ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) <= 0x20) {
                    if ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) > 0x20) {
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
    temp_r1_28802 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
    var_r3_28804 = temp_r1_28802 - *(s32 *)0x030041A0;
    if (var_r3_28804 < 0) {
        var_r3_28804 = 0 - var_r3_28804;
    }
    if (var_r3_28804 <= 0x2FFF) {
        var_r3_28812 = temp_r1_28802 - arg0;
        var_r0_28814 = (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) - arg1;
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
    if (sub_02025B94((*(s32 *)((u8 *)((void *)0x03003BC4) + (8))) << 8, (*(s32 *)((u8 *)((void *)0x03003BC4) + (0xC))) << 8, 0x10U) != 0) {
        *(u8 *)0x03004BA6 = 1;
    }
    if (*(u8 *)0x03004227 == 1) {
        if ((*(u8 *)0x03004BA6 != 0) && (*(u8 *)0x0300422A == 0xFE)) {
            *(u8 *)0x0300422A = 4;
            (*(s8 *)((u8 *)((void *)0x03003BC4) + (0x11))) = 0;
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
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4)));
            goto block_3;
        }
        goto block_8;
    }
block_3:
    var_r8_28909 = (void *)0x030041A0 + 0x87;
    if ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x87))) == 3) {
        if (sub_02025B94((*(s32 *)((u8 *)((void *)0x030041A0) + (0))), (*(s32 *)((u8 *)((void *)0x030041A0) + (4))), 8U) != 0) {
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x97))) = 1;
            sub_0201FED4(2U, 0x30U);
            temp_r1_28939 = (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D)));
            if (temp_r1_28939 != 0) {
                (*(u8 *)((u8 *)((void *)0x030041A0) + (0x8D))) = (u8) (0x40 | temp_r1_28939);
                (*(s8 *)((u8 *)((void *)0x030041A0) + (0x97))) = 0;
            }
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x26))) = 0;
            (*(u8 *)((u8 *)((void *)0x030041A0) + (0x87))) = 0xAU;
            (*(s8 *)((u8 *)((void *)0x030041A0) + (0x98))) = 0x30;
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 0;
            sub_02025F60();
            return 1;
        }
        goto block_12;
    }
block_8:
    if ((*var_r8_28909 == 0x14) && ((*(u8 *)((u8 *)((void *)0x030041A0) + (0x9C))) == 0) && (sub_02025B94((*(s32 *)((u8 *)((void *)0x030041A0) + (0))), (*(s32 *)((u8 *)((void *)0x030041A0) + (4))), 0x10U) != 0)) {
        sub_02026A38(3U);
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x84))) = 2;
        (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 2;
        sub_020263A0();
        return 1;
    }
block_12:
    return 0;
}

s8 sub_02025D1C(void) {
    u8 temp_r0_29010;

    if ((*(u8 *)0x03004227 == 3) && ((temp_r0_29010 = *(u8 *)0x0300422D, (temp_r0_29010 == 1)) || (temp_r0_29010 == 5)) && (sub_02025B94((*(s32 *)((u8 *)((void *)0x030041A0) + (0x38))), (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C))), 0x10U) != 0)) {
        *(u8 *)0x03004227 = 9;
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x38)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (*(s32 *)((u8 *)((void *)0x030041A0) + (0x3C)));
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x97))) = 0;
        (*(s8 *)((u8 *)((void *)0x030041A0) + (0x9F))) = 1;
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

    (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = 0xF800;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = 0x8800;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (8))) = 0xF800;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0xC))) = 0x8800;
    temp_r0_29058 = (void *)0x03004B80 + 0x21;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x21))) = 0;
    (*(s8 *)((u8 *)(temp_r0_29058) + (1))) = 0;
    temp_r0_29063 = (temp_r0_29058 + 1) - 2;
    (*(s8 *)((u8 *)(temp_r0_29063) + (0))) = 0;
    temp_r0_29065 = temp_r0_29063 + 3;
    (*(s8 *)((u8 *)(temp_r0_29063) + (3))) = 0;
    (*(s16 *)((u8 *)((void *)0x03004B80) + (0x18))) = 0;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1E))) = 0;
    (*(s16 *)((u8 *)((void *)0x03004B80) + (0x1A))) = 0;
    temp_r0_29071 = temp_r0_29065 + 1;
    (*(s8 *)((u8 *)(temp_r0_29065) + (1))) = 0;
    temp_r0_29073 = temp_r0_29071 + 1;
    (*(s8 *)((u8 *)(temp_r0_29071) + (1))) = 0;
    temp_r0_29075 = temp_r0_29073 + 1;
    (*(s8 *)((u8 *)(temp_r0_29073) + (1))) = 0;
    temp_r0_29077 = temp_r0_29075 + 1;
    (*(s8 *)((u8 *)(temp_r0_29075) + (1))) = 0;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = 0;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = 0;
    (*(s8 *)((u8 *)(temp_r0_29077) + (1))) = 0;
    (*(s8 *)((u8 *)((temp_r0_29077 + 1)) + (1))) = 0;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1C))) = 0;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1D))) = 0;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 0;
}

void sub_02025DC8(void) {
    s32 temp_r2_29106;
    s32 temp_r2_29140;
    s32 temp_r2_29183;
    s32 temp_r2_29215;
    s32 var_r0_29162;
    u16 temp_r0_29249;

    if (0x400040 & (*(s32 *)((u8 *)(&gGameState) + (0x818)))) {
        temp_r2_29106 = (*(s32 *)((u8 *)((void *)0x03004B80) + (4)));
        (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = (s32) (temp_r2_29106 + 0xFFFFFE80);
        if (0x100 & gGameState.keys_held) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = (s32) (temp_r2_29106 + 0xFFFFFD00);
        }
        if ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) <= 0xE00) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = 0xE00;
        }
    } else if ((*(s32 *)((u8 *)(&gGameState) + (0x818))) & 0x800080) {
        temp_r2_29140 = (*(s32 *)((u8 *)((void *)0x03004B80) + (4)));
        (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = (s32) (temp_r2_29140 + 0x180);
        if (0x100 & gGameState.keys_held) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = (s32) (temp_r2_29140 + 0x300);
        }
        if (*(u8 *)0x03004224 == 0) {
            var_r0_29162 = 0xF7FF;
        } else {
            var_r0_29162 = 0xE7FF;
        }
        if ((*(s32 *)((u8 *)((void *)0x03004B80) + (4))) > var_r0_29162) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) = (s32) (var_r0_29162 + 1);
        }
    }
    if (0x200020 & (*(s32 *)((u8 *)(&gGameState) + (0x818)))) {
        temp_r2_29183 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = (s32) (temp_r2_29183 + 0xFFFFFE80);
        if (0x100 & gGameState.keys_held) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = (s32) (temp_r2_29183 + 0xFFFFFD00);
        }
        if ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) <= 0x600) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = 0x600;
        }
    } else if ((*(s32 *)((u8 *)(&gGameState) + (0x818))) & 0x100010) {
        temp_r2_29215 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = (s32) (temp_r2_29215 + 0x180);
        if (0x100 & gGameState.keys_held) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = (s32) (temp_r2_29215 + 0x300);
        }
        if ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) > 0x1DFFF) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) = 0x1E000;
        }
    }
    gGameState.unk_840 = ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8) - 0x80;
    temp_r0_29249 = ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) - 0x50;
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
    *(s8 *)0x03004BA2 = (s8) (*(u16 *)((u8 *)(**(void ***)0x02034ED4) + (4)));
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 1;
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
    temp_r2_29358 = ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) & 0xFF0;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = temp_r2_29358;
    temp_r3_29360 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
    temp_r1_29362 = (temp_r3_29360 >> 8) & 0xFF0;
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = temp_r1_29362;
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) = (u8) (temp_r2_29358 | ((s32) (0xF0 & temp_r1_29362) >> 4));
    if (!(temp_r1_29362 & 0xFF00)) {
        var_r1_29376 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2;
        var_r2_29378 = 0x03003720;
    } else {
        var_r1_29376 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2;
        var_r2_29378 = 0x03003920;
    }
    temp_r7_29393 = *(u32 *)(var_r1_29376 + var_r2_29378);
    switch (temp_r7_29393) {                        /* irregular */
    case 0xFFF:
block_27:
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x23))) = 1U;
block_25:
        if ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x23))) == 0) {
            sub_02025DC8();
            return;
        }
        temp_r0_29587 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22)));
        if (temp_r0_29587 == 0) {
            (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22))) = (u8) (temp_r0_29587 - 1);
            return;
        }
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) = (u8) ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) + 1);
        temp_r1_29609 = *(u32 *)(((*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) * 4) + *(u32 *)(0x02034ED4 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x20))) * 4)));
        if ((*(u8 *)((u8 *)(temp_r1_29609) + (6))) != 0xFF) {
            (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22))) = (u8) (*(u16 *)((u8 *)(temp_r1_29609) + (4)));
            return;
        }
        if (sub_02025BEC() != 0) {
            sub_02026A38(2U);
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 0;
            sub_02025F60();
            return;
        }
        temp_r0_29629 = sub_02025C4C();
        if (temp_r0_29629 == 0) {
            temp_r0_29633 = sub_02025D1C();
            if (temp_r0_29633 != 0) {
                (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = temp_r0_29629;
                sub_02025F60();
                return;
            }
            sub_02026A38(2U);
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = temp_r0_29633;
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
        if ((*(u16 *)((u8 *)(((temp_r7_29393 * 0xC) + 0x0202F7FC)) + (8))) == 0xFFF) {
            goto block_27;
        }
        if (!((*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) & 0xFF00)) {
            temp_r2_29431 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
            if (((s32) *(u32 *)(*(s32 *)0x03001B40 + 0x18F8 + ((temp_r2_29431 >> 4) * 2)) >> (0xF & temp_r2_29431)) & 1) {
                goto block_28;
            }
            goto block_20;
        }
        temp_r2_29457 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
        if (!(((s32) *(u32 *)(*(u32 *)0x03001B40 + 0x1918 + ((temp_r2_29457 >> 4) * 2)) >> (0xF & temp_r2_29457)) & 1)) {
block_20:
            temp_r7_29474 = temp_r7_29393 & 0xFFF;
            temp_r1_29478 = (temp_r7_29474 * 0xC) + 0x0202F7FC;
            if ((*(u16 *)((u8 *)(temp_r1_29478) + (4))) != 0xFFF) {
                temp_r4_29487 = (temp_r3_29360 >> 8) & 0xFF00;
                if (temp_r4_29487 == 0) {
                    *(u32 *)(0x03003720 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2)) = 0x7777;
                    temp_r1_29498 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
                    temp_r2_29506 = *(s32 *)0x03001B40 + 0x24 + (((0xF & temp_r1_29498) * 2) + ((temp_r1_29498 >> 4) << 5));
                    var_r6_29507 = *temp_r2_29506;
                    *temp_r2_29506 = temp_r4_29487;
                    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x28))) = 0;
                } else {
                    *(u32 *)(0x03003920 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2)) = 0x7777;
                    temp_r1_29528 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
                    temp_r2_29538 = *(s32 *)0x03001B40 + 0x224 + (((0xF & temp_r1_29528) * 2) + ((temp_r1_29528 >> 4) << 5));
                    var_r6_29507 = *temp_r2_29538;
                    *temp_r2_29538 = 0;
                    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x28))) = 1;
                }
                (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) = (u8) (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
                (*(s8 *)((u8 *)((void *)0x03004B80) + (0x24))) = temp_r7_29474;
                (*(u16 *)((u8 *)((void *)0x03004B80) + (0x18))) = (u16) (*(u16 *)((u8 *)(temp_r1_29478) + (4)));
                (*(u16 *)((u8 *)((void *)0x03004B80) + (0x1A))) = var_r6_29507;
                sub_02026A38(3U);
                (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 2;
                sub_020263A0();
                return;
            }
            goto block_27;
        }
block_28:
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x23))) = 1U;
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
    temp_r1_29682 = *(u32 *)(var_r0_29670 + var_r1_29671);
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
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1C))) = (u8) (((temp_r1_29767 - 1) & 0xF) | temp_r0_29777);
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1D))) = (u8) (((temp_r1_29767 + 1) & 0xF) | temp_r0_29777);
    if (!((*(s32 *)((u8 *)((void *)0x03004B80) + (0))) & 0xFF0000)) {
        sub_0202622C(temp_r4_29762, arg1, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1C))), 0, 0);
        if (!(0xF & (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1D))))) {
            sub_0202622C(temp_r4_29762, arg1, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1D))), 1, 1);
            return;
        }
        var_r2_29811 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1D)));
        var_r0_29812 = 1;
        goto block_6;
    }
    sub_0202622C(temp_r4_29762, arg1, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1D))), 1, 1);
    if ((0xF & (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1C)))) == 0xF) {
        var_r2_29811 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1C)));
        var_r0_29812 = 0;
block_6:
        sub_0202622C(temp_r4_29762, arg1, var_r2_29811, 0, var_r0_29812);
        return;
    }
    sub_0202622C(temp_r4_29762, arg1, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1C))), 1, 0);
}

void sub_020263A0(void) {
    s32 temp_r0_29892;
    u16 temp_r2_29900;

    *(s8 *)0x03004BA0 = 1;
    *(s8 *)0x03004BA3 = 0;
    *(s8 *)0x03004BA1 = 0;
    *(s8 *)0x03004BA2 = (s8) (*(u16 *)((u8 *)(*(*(void ***)((u8 *)((void *)0x02034ED4) + (4)))) + (4)));
    if (*(u8 *)0x03004224 == 0) {
        *(s8 *)0x03003B29 = 1;
        Unk_Struct_Size54_ResetIdx(2);
        *(s16 *)0x03004878 = 0x30;
        temp_r0_29892 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        (*(s32 *)((u8 *)((void *)0x03004838) + (0))) = (s32) ((temp_r0_29892 >> 8) - 8);
        (*(s32 *)((u8 *)((void *)0x03004838) + (4))) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) - 2);
        temp_r2_29900 = (*(u16 *)((u8 *)((void *)0x03004B80) + (0x18)));
        (*(s16 *)((u8 *)((void *)0x03004838) + (0x3E))) = (s16) (0x3FF & temp_r2_29900);
        (*(s8 *)((u8 *)((void *)0x03004838) + (0x50))) = (s8) ((u32) (temp_r2_29900 << 0x10) >> 0x1C);
        *(u32 *)(((void *)0x03004838 + 0x50) - 1) = 0;
        WriteItemToTile(temp_r0_29892, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))), 0U, 0x200U);
        sub_020262DC((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))), (*(s32 *)((u8 *)((void *)0x03004B80) + (0))));
    } else {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) ((*(s32 *)((u8 *)((void *)0x03004B80) + (4))) + 0x1200);
    }
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x25))) = 0x20;
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 3;
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
        temp_r0_29958 = (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28)));
        if (temp_r0_29958 == 0) {
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = (s8) temp_r0_29958;
            sub_02025F60();
            return;
        }
    }
    temp_r0_29971 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x25)));
    if (((temp_r0_29971 == 0) || (temp_r0_29974 = temp_r0_29971 - 1, (*(u8 *)((u8 *)((void *)0x03004B80) + (0x25))) = temp_r0_29974, ((temp_r0_29974 << 0x18) == 0))) && (1 & gGameState.keys_pressed)) {
        if (*(u32 *)0x03004224 != 0) {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = (s32) ((((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8) - 8) & 0xFF0);
            var_r0_30005 = (((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) + 0x18) & 0xFF0;
        } else {
            (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = (s32) ((*(s32 *)((u8 *)((void *)0x03004838) + (0))) + 8);
            var_r0_30005 = (*(s32 *)((u8 *)((void *)0x03004838) + (4))) + 8;
        }
        (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = var_r0_30005;
        if (sub_020259C8() == 0) {
            sub_02026A38(4U);
            (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 4;
            sub_020265A8();
            return;
        }
        temp_r1_30029 = (void *)0x03004B80 + 0x20;
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x20))) = 3U;
        (*(s8 *)((u8 *)(temp_r1_30029) + (1))) = 0;
        (*(s8 *)((u8 *)((temp_r1_30029 + 1)) + (1))) = (s8) (*(u16 *)((u8 *)(*(*(void ***)((u8 *)((void *)0x02034ED4) + (0xC)))) + (4)));
        sub_02026A38(0x12U);
        goto block_12;
    }
block_12:
    sub_02025DC8();
    if (*(u32 *)0x03004224 == 0) {
        (*(s16 *)((u8 *)((void *)0x03004838) + (0x40))) = 0x30;
        (*(s32 *)((u8 *)((void *)0x03004838) + (0))) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8) - 8);
        (*(s32 *)((u8 *)((void *)0x03004838) + (4))) = (s32) (((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8) - 2);
    } else {
        (*(s32 *)((u8 *)((void *)0x030041A0) + (0))) = (s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        (*(s32 *)((u8 *)((void *)0x030041A0) + (4))) = (s32) ((*(s32 *)((u8 *)((void *)0x03004B80) + (4))) + 0x1200);
    }
    temp_r0_30074 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22)));
    if (temp_r0_30074 == 0) {
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) = (u8) ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) + 1);
        temp_r4_30088 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x21)));
        temp_r1_30092 = *(u32 *)((temp_r4_30088 * 4) + *(u32 *)(0x02034ED4 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x20))) * 4)));
        if ((*(u8 *)((u8 *)(temp_r1_30092) + (6))) == 0xFF) {
            (*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) = (u8) (temp_r4_30088 - 1);
            return;
        }
        var_r0_30102 = (*(u16 *)((u8 *)(temp_r1_30092) + (4)));
        goto block_20;
    }
    var_r0_30102 = temp_r0_30074 - 1;
block_20:
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22))) = (u8) var_r0_30102;
}

void sub_020265A8(void) {
    (*(s8 *)((u8 *)((void *)0x03004BA0) + (0))) = 2;
    (*(s8 *)((u8 *)((void *)0x03004BA0) + (1))) = 0;
    (*(s8 *)((u8 *)(((void *)0x03004BA0 + 1)) + (1))) = (s8) (*(u16 *)((u8 *)(*(*(void ***)((u8 *)((void *)0x02034ED4) + (8)))) + (4)));
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 5;
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
    if ((*(u8 *)0x03004224 == 0) && ((*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) == 0)) {
        (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 0;
        sub_02025F60();
        return;
    }
    temp_r0_30167 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22)));
    if (temp_r0_30167 != 0) {
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22))) = (u8) (temp_r0_30167 - 1);
        if (((*(s32 *)((u8 *)((void *)0x03004B80) + (0x20))) & 0xFFFF00) != 0x300) {
            return;
        }
        *(s8 *)0x03003B29 = 0;
        return;
    }
    (*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) = (u8) ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) + 1);
    temp_r1_30205 = *(u32 *)(((*(u8 *)((u8 *)((void *)0x03004B80) + (0x21))) * 4) + *(u32 *)(0x02034ED4 + ((u8) (*(s32 *)((u8 *)((void *)0x03004B80) + (0x20))) * 4)));
    if ((*(u8 *)((u8 *)(temp_r1_30205) + (6))) != 0xFF) {
        (*(u8 *)((u8 *)((void *)0x03004B80) + (0x22))) = (u8) (*(u16 *)((u8 *)(temp_r1_30205) + (4)));
        return;
    }
    if (*(u32 *)0x03004224 != 0) {
        *(u32 *)0x03004224 = 1U;
    } else {
        temp_r8_30230 = ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x24))) * 0xC) + 0x0202F7FC;
        WriteItemToTile((*(s32 *)((u8 *)((void *)0x03004B80) + (0))), (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))), (*(u16 *)((u8 *)((void *)0x03004B80) + (0x1A))), (*(u16 *)((u8 *)(temp_r8_30230) + (0))));
        if ((u8) (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) == 0) {
            var_r2_30245 = (void *)0x03004B80 + 0x29;
            var_r0_30247 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) * 2;
            var_r1_30249 = 0x03003720;
        } else {
            var_r2_30245 = (void *)0x03004B80 + 0x29;
            var_r0_30247 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x29))) * 2;
            var_r1_30249 = 0x03003920;
        }
        *(u32 *)(var_r1_30249 + var_r0_30247) = 0xFFF;
        if (!((*(s32 *)((u8 *)((void *)0x03004B80) + (0))) & 0xFF0000)) {
            var_r0_30272 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2;
            var_r1_30274 = 0x03003720;
        } else {
            var_r0_30272 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E))) * 2;
            var_r1_30274 = 0x03003920;
        }
        *(u32 *)(var_r1_30274 + var_r0_30272) = (s16) (*(u8 *)((u8 *)((void *)0x03004B80) + (0x24)));
        (*(u16 *)((u8 *)((void *)0x03004B80) + (0x28))) = 0;
        *var_r2_30245 = 0;
        if (*(u8 *)0x03004227 == 3) {
            if (*(u16 *)0x03004202 == 0) {
                temp_r0_30304 = *(u8 *)0x0300422D;
                switch (temp_r0_30304) {            /* switch 1; irregular */
                case 3:                             /* switch 1 */
                case 7:                             /* switch 1 */
                    temp_r0_30313 = (*(u16 *)((u8 *)(temp_r8_30230) + (8)));
                    switch ((u32) temp_r0_30313) {  /* switch 2; irregular */
                    case 6:                         /* switch 2 */
                        goto block_28;
                    }
                    break;
                }
            } else if ((*(u32 *)0x0300422D == 0) && ((u32) (u16) ((*(u16 *)((u8 *)(temp_r8_30230) + (8))) - 5) <= 9U)) {
block_28:
                var_sb_30147 = 1;
            }
        }
        temp_r3_30338 = (*(s32 *)((u8 *)((void *)0x03004B80) + (0)));
        var_r2_30340 = temp_r3_30338 - (*(s32 *)((u8 *)((void *)0x030041A0) + (0)));
        if (var_r2_30340 < 0) {
            var_r2_30340 = 0 - var_r2_30340;
        }
        var_r1_30347 = (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) - (*(s32 *)((u8 *)((void *)0x030041A0) + (4)));
        if (var_r1_30347 < 0) {
            var_r1_30347 = 0 - var_r1_30347;
        }
        if ((var_r2_30340 <= 0x2FFF) && (var_r1_30347 <= 0x2FFF) && (var_sb_30147 == 1)) {
            temp_r2_30363 = (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x10))) = (s32) ((temp_r3_30338 & 0xFF0000) | (((0xF & temp_r2_30363) << 0xC) + 0x800));
            (*(s32 *)((u8 *)((void *)0x030041A0) + (0x14))) = (s32) (((0xF0 & temp_r2_30363) << 8) + 0x800);
            *(u8 *)0x03004227 = 9;
        }
    }
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x27))) = 0x20;
    (*(u8 *)((u8 *)((void *)0x030041A0) + (0x9D))) = (u8) (*(u8 *)((u8 *)((void *)0x03004B80) + (0x1E)));
    (*(s8 *)((u8 *)((void *)0x03004B80) + (0x1F))) = 0;
    sub_02025F60();
}

void sub_020267D0(void) {
    *(s8 *)0x03003B27 = 1;
    *(s8 *)0x03003B28 = 1;
    if ((*(u8 *)0x03004227 != 0x14) || (*(u8 *)0x0300423C == 0) || (*(u8 *)0x03004224 == 2)) {
        ((void (*)(void))*(u32 *)(0x02034E0C + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x1F))) * 4)))();
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

    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14))) = (s32) ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (4))) >> 8);
    (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10))) = (s32) ((s32) (*(s32 *)((u8 *)((void *)0x03004B80) + (0))) >> 8);
    var_r5_30480 = **(u32 **)(((*(u8 *)((u8 *)(((void *)0x03004B80 + 0x20)) + (1))) * 4) + *(u32 *)(0x02034ED4 + ((*(u8 *)((u8 *)((void *)0x03004B80) + (0x20))) * 4)));
    *(s8 *)0x03003B27 = 0;
    *(s8 *)0x03003B28 = 0;
    var_r8_30489 = NULL;
    if ((*(u16 *)((u8 *)(var_r5_30480) + (6))) == 0xFFFF) {
        return;
    }
    do {
        temp_r3_30508 = (gGameState.unk_860 * 8) + gUnk3002410;
        temp_r2_30516 = (-0xD & (*(u8 *)((u8 *)(temp_r3_30508) + (1)))) | (0xC & (*(u8 *)((u8 *)(var_r5_30480) + (1))));
        (*(u8 *)((u8 *)(temp_r3_30508) + (1))) = temp_r2_30516;
        temp_r1_30526 = (-0x21 & temp_r2_30516) | ((((u32) ((*(u8 *)((u8 *)(var_r5_30480) + (1))) << 0x1A) >> 0x1F) & 1) << 5);
        (*(u8 *)((u8 *)(temp_r3_30508) + (1))) = temp_r1_30526;
        temp_r4_30533 = (0x3F & temp_r1_30526) | (((u8) (*(u8 *)((u8 *)(var_r5_30480) + (1))) >> 6) << 6);
        (*(u8 *)((u8 *)(temp_r3_30508) + (1))) = temp_r4_30533;
        temp_r2_30544 = (-0x11 & (*(u8 *)((u8 *)(temp_r3_30508) + (3)))) | ((((u32) ((*(u8 *)((u8 *)(var_r5_30480) + (3))) << 0x1B) >> 0x1F) & 1) * 0x10);
        (*(u8 *)((u8 *)(temp_r3_30508) + (3))) = temp_r2_30544;
        temp_r1_30554 = (-0x21 & temp_r2_30544) | ((((u32) ((*(u8 *)((u8 *)(var_r5_30480) + (3))) << 0x1A) >> 0x1F) & 1) << 5);
        (*(u8 *)((u8 *)(temp_r3_30508) + (3))) = temp_r1_30554;
        (*(u8 *)((u8 *)(temp_r3_30508) + (3))) = (u8) ((temp_r1_30554 & 0x3F) | (((u8) (*(u8 *)((u8 *)(var_r5_30480) + (3))) >> 6) << 6));
        (*(s8 *)((u8 *)(temp_r3_30508) + (0))) = (s8) (((*(u8 *)((u8 *)(var_r5_30480) + (0))) + (*(s32 *)((u8 *)((void *)0x03004B80) + (0x14)))) - (*(u8 *)((u8 *)(&gGameState) + (0x846))));
        (*(u16 *)((u8 *)(temp_r3_30508) + (2))) = (u16) ((0xFFFFFE00 & (*(u16 *)((u8 *)(temp_r3_30508) + (2)))) | (((((u32) ((*(u16 *)((u8 *)(var_r5_30480) + (2))) << 0x17) >> 0x17) + (*(s32 *)((u8 *)((void *)0x03004B80) + (0x10)))) - gGameState.unk_844) & 0x1FF));
        (*(u16 *)((u8 *)(temp_r3_30508) + (4))) = (u16) ((0xFFFFFC00 & (*(u16 *)((u8 *)(temp_r3_30508) + (4)))) | ((u32) ((*(u16 *)((u8 *)(var_r5_30480) + (4))) << 0x16) >> 0x16));
        (*(u8 *)((u8 *)(temp_r3_30508) + (1))) = (u8) (temp_r4_30533 | 0x10);
        temp_r2_30604 = -0xD & (*(u8 *)((u8 *)(temp_r3_30508) + (5)));
        (*(u8 *)((u8 *)(temp_r3_30508) + (5))) = temp_r2_30604;
        (*(u8 *)((u8 *)(temp_r3_30508) + (5))) = (u8) ((0xF & temp_r2_30604) | (((u8) (*(u8 *)((u8 *)(var_r5_30480) + (5))) >> 4) * 0x10));
        *(u32 *)(0x03003B27 + (s32) var_r8_30489) = 1;
        gGameState.unk_860 += 1;
        var_r8_30489 += 1;
        var_r5_30480 += 8;
    } while ((*(u16 *)((u8 *)(var_r5_30480) + (6))) != 0xFFFF);
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
        (*(s32 *)((u8 *)(var_r0_30679) + (0))) = -1;
        (*(s8 *)((u8 *)(var_r0_30679) + (4))) = 0;
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
    temp_r4_30719 = *(u32 *)(0x02035C10 + (temp_r6_30714 * 4));
    if (sub_0202846C(0) != 0) {
        temp_r1_30729 = *(u32 *)(0x02035C10 + (*(s16 *)0x03000028 * 4));
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
        *(u32 *)0x03000028 = (s16) temp_r6_30714;
    }
}

void sub_02026AB8(u16 arg0) {
    s32 var_r2_30805;
    u16 temp_r7_30781;
    u32 temp_r1_30796;
    u32 temp_r4_30786;

    temp_r7_30781 = arg0;
    temp_r4_30786 = *(u32 *)(0x02035C10 + (temp_r7_30781 * 4));
    if (sub_0202846C(1) != 0) {
        temp_r1_30796 = *(u32 *)(0x02035C10 + (*(s16 *)0x0300002A * 4));
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
        *(u32 *)0x0300002A = (s16) temp_r7_30781;
    }
}

void sub_02026B38(u8 arg0) {
    sub_02028BCC(1U, 0U);
}

void sub_02026B48(u16 value) {
    s32 var_r2_30882;
    u16 temp_r6_30858;
    u32 temp_r1_30873;
    u32 temp_r4_30863;

    temp_r6_30858 = value;
    temp_r4_30863 = *(u32 *)(0x02035C10 + (temp_r6_30858 * 4));
    if (sub_0202846C(2) != 0) {
        temp_r1_30873 = *(u32 *)(0x02035C10 + (*(s16 *)0x0300002C * 4));
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
        *(u32 *)0x0300002C = (s16) temp_r6_30858;
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
        sub_02028B58(4U, *(u32 *)(0x02035CBC + (temp_r4_30963 * 2)));
        if (temp_r4_30963 == 1) {
            ChangeEmotion(*(u8 *)0x03000052);
        } else {
            sub_02028CE4(4, 0, 0U);
        }
        *(u32 *)0x03000050 = temp_r4_30963;
    }
}

void sub_02026C68(u16 value) {
    sub_02028BCC(4U, value);
}

void ChangeEmotion(u8 arg0) {
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
    if (arg0 != (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + (8)))) + (0x2C)))) {
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
        var_r2_31233 = (*(s32 *)((u8 *)(arg0) + (8))) + 8;
        var_r3_31234 = 9;
        do {
            temp_r1_31236 = *var_r2_31233;
            if (temp_r1_31236 != NULL) {
                (*(s32 *)((u8 *)(temp_r1_31236) + (0x34))) = (s32) ((*(s32 *)((u8 *)(temp_r1_31236) + (0x34))) + 0x708);
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
    (*(s16 *)((u8 *)((void *)0x04000080) + (0))) = 0xFF77;
    (*(s8 *)((u8 *)((void *)0x04000080) + (2))) = 0xD;
    *(u16 *)0x04000088 = (0x3FFF & *(u16 *)0x04000088) | 0x4000;
    (*(s16 *)((u8 *)((void *)0x04000060) + (0))) = 8;
    (*(s16 *)((u8 *)((void *)0x04000060) + (2))) = 0xF000;
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
    (*(s32 *)((u8 *)((void *)0x03000058) + (0))) = arg0;
    (*(s32 *)((u8 *)((void *)0x03000060) + (0))) = (s32) (arg0 + 0xB0);
    (*(s32 *)((u8 *)((void *)0x03000058) + (4))) = (s32) (arg0 + 0x160);
    (*(s32 *)((u8 *)((void *)0x03000060) + (4))) = (s32) (arg0 + 0x210);
    *(s16 *)0x03000068 = 0xF9C4;
    *(s8 *)0x0300006A = 0;
    *(s8 *)0x04000083 = 0x9A;
    (*(s32 *)((u8 *)((void *)0x040000A0) + (0))) = 0;
    (*(s32 *)((u8 *)((void *)0x040000A0) + (4))) = 0;
}

void sub_02026FAC(void) {
    *(s32 *)0x04000100 = *(u16 *)0x03000068 | 0x800000;
    if (*(u8 *)0x0300006B != 0) {
        (*(u16 *)((u8 *)((void *)0x040000BC) + (0xA))) = (u16) ((u32) ((*(u16 *)((u8 *)((void *)0x040000BC) + (0xA))) << 0x11) >> 0x11);
        (*(u16 *)((u8 *)((void *)0x040000C8) + (0xA))) = (u16) ((u32) ((*(u16 *)((u8 *)((void *)0x040000C8) + (0xA))) << 0x11) >> 0x11);
        (*(s32 *)((u8 *)((void *)0x040000BC) + (0))) = (s32) *(u32 *)(0x03000058 + (*(u8 *)0x0300006A * 4));
        (*(s32 *)((u8 *)((void *)0x040000BC) + (4))) = 0x040000A0;
        (*(s32 *)((u8 *)((void *)0x040000BC) + (8))) = 0xB6400004;
        (*(s32 *)((u8 *)((void *)0x040000C8) + (0))) = (s32) *(u32 *)(0x03000060 + (*(u8 *)0x0300006A * 4));
        (*(s32 *)((u8 *)((void *)0x040000C8) + (4))) = 0x040000A4;
        (*(s32 *)((u8 *)((void *)0x040000C8) + (8))) = 0xB6400004;
        *(u8 *)0x0300006A = 1 - *(u8 *)0x0300006A;
    }
}

void sub_02027040(void) {
    void *temp_r1_31488;

    *(s8 *)0x0300006B = 0;
    (*(u16 *)((u8 *)((void *)0x040000BC) + (0xA))) = (u16) ((u32) ((*(u16 *)((u8 *)((void *)0x040000BC) + (0xA))) << 0x11) >> 0x11);
    temp_r1_31488 = (void *)0x040000BC + 0xC;
    (*(u16 *)((u8 *)(temp_r1_31488) + (0xA))) = (u16) ((u32) ((*(u16 *)((u8 *)(temp_r1_31488) + (0xA))) << 0x11) >> 0x11);
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

    (*(s32 *)((u8 *)((void *)0x03000070) + (0))) = 0;
    temp_r7_31522 = (void *)0x03000070 + 0x178;
    var_r4_31524 = 3;
    var_r0_31526 = (s8 *)0x0300189D;
    do {
        *var_r0_31526 = 0;
        var_r0_31526 -= 0x7C;
        var_r4_31524 -= 1;
    } while (var_r4_31524 >= 0);
    (*(s8 *)((u8 *)((void *)0x03001728) + (0))) = 1;
    (*(s8 *)((u8 *)((void *)0x03001728) + (0x7C))) = 2;
    (*(s8 *)((u8 *)(((void *)0x03001728 + 0x7C)) + (0x7C))) = 3;
    (*(s8 *)((u8 *)((void *)0x03001728) + (0x174))) = 4;
    var_r0_31548 = (void *)0x030013C4;
    var_r4_31549 = 6;
    do {
        (*(s8 *)((u8 *)(var_r0_31548) + (1))) = 0;
        (*(s8 *)((u8 *)(var_r0_31548) + (0))) = 0;
        var_r0_31548 += 0x7C;
        var_r4_31549 -= 1;
    } while (var_r4_31549 >= 0);
    (*(s32 *)((u8 *)((void *)0x03000070) + (0x16C))) = 0x030013C4;
    *(s8 *)0x03001434 = 0x03001440;
    (*(s8 *)((u8 *)((void *)0x03001435) + (0))) = (s8) (0x03001440U >> 8);
    (*(s8 *)((u8 *)((void *)0x03001435) + (1))) = (s8) (0x03001440U >> 0x10);
    *(s8 *)0x03001437 = (s8) (0x03001440U >> 0x18);
    temp_r1_31579 = (void *)0x03000070 + 0xFC;
    *(s8 *)0x03001430 = (s8) temp_r1_31579;
    temp_r2_31583 = ((void *)0x03001435 + 1) - 5;
    (*(s8 *)((u8 *)(temp_r2_31583) + (0))) = (s8) ((u32) temp_r1_31579 >> 8);
    (*(s8 *)((u8 *)(temp_r2_31583) + (1))) = (s8) ((u32) temp_r1_31579 >> 0x10);
    *(s8 *)0x03001433 = (s8) ((u32) temp_r1_31579 >> 0x18);
    var_r2_31594 = temp_r2_31583 + 1 + 0x7A;
    var_r3_31595 = 0x030013C4;
    var_r6_31596 = 0x7C;
    var_r4_31597 = 4;
    do {
        temp_r1_31601 = var_r6_31596 + 0x03001440;
        (*(u8 *)((u8 *)(var_r2_31594) + (4))) = temp_r1_31601;
        (*(u8 *)((u8 *)(var_r2_31594) + (5))) = (u8) (temp_r1_31601 >> 8);
        (*(u8 *)((u8 *)(var_r2_31594) + (6))) = (u8) (temp_r1_31601 >> 0x10);
        (*(s8 *)((u8 *)(var_r2_31594) + (7))) = (s8) (temp_r1_31601 >> 0x18);
        (*(u8 *)((u8 *)(var_r2_31594) + (0))) = var_r3_31595;
        (*(u8 *)((u8 *)(var_r2_31594) + (1))) = (u8) (var_r3_31595 >> 8);
        (*(u8 *)((u8 *)(var_r2_31594) + (2))) = (u8) (var_r3_31595 >> 0x10);
        (*(s8 *)((u8 *)(var_r2_31594) + (3))) = (s8) (var_r3_31595 >> 0x18);
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
    (*(s32 *)((u8 *)(temp_r7_31522) + (0x6C))) = 0x030016AC;
    (*(s32 *)((u8 *)((temp_r7_31522 + 0xFFFFFE88)) + (0x74))) = (s32) (temp_r7_31522 - 0xF8);
    *(u32 *)(temp_r7_31522 - 0x8C) = temp_r7_31522 + 0xFFFFFE8C;
}

void sub_020271FC(u8 *arg0) {
    (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + (0x6C)))) + (0x70))) = (void *) (*(void **)((u8 *)(arg0) + (0x70)));
    (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + (0x70)))) + (0x6C))) = (void *) (*(void **)((u8 *)(arg0) + (0x6C)));
}

void sub_0202720C(u8 *arg0) {
    u8 temp_r0_31754;
    u8 temp_r2_31715;
    void *temp_r2_31748;
    void *var_r1_31714;

    var_r1_31714 = (*(void **)((u8 *)((void *)0x03000070) + (0x74)));
    temp_r2_31715 = (*(u8 *)((u8 *)(arg0) + (1)));
    if (temp_r2_31715 == 1) {
        if ((var_r1_31714 != ((void *)0x03000070 + 0x80)) && (((*(u8 *)((u8 *)(var_r1_31714) + (1))) != 1) || ((u32) (*(u8 *)((u8 *)(arg0) + (8))) >= (u32) (*(u8 *)((u8 *)(var_r1_31714) + (8)))))) {
loop_4:
            var_r1_31714 = (*(void **)((u8 *)(var_r1_31714) + (0x70)));
            if (var_r1_31714 != (void *)0x030000F0) {
                if (((*(u8 *)((u8 *)(var_r1_31714) + (1))) == 1) && ((u32) (*(u8 *)((u8 *)(arg0) + (8))) < (u32) (*(u8 *)((u8 *)(var_r1_31714) + (8))))) {

                } else {
                    goto loop_4;
                }
            }
        }
        goto block_16;
    }
    if (temp_r2_31715 == 2) {
        temp_r2_31748 = (void *)0x03000070 + 0x80;
        if ((var_r1_31714 != temp_r2_31748) && ((*(u8 *)((u8 *)(var_r1_31714) + (1))) != 1)) {
            temp_r0_31754 = (*(u8 *)((u8 *)(arg0) + (8)));
            if ((u32) temp_r0_31754 >= (u32) (*(u8 *)((u8 *)(var_r1_31714) + (8)))) {
loop_13:
                var_r1_31714 = (*(void **)((u8 *)(var_r1_31714) + (0x70)));
                if ((var_r1_31714 != temp_r2_31748) && ((*(u8 *)((u8 *)(var_r1_31714) + (1))) != 1)) {
                    if ((u32) temp_r0_31754 >= (u32) (*(u8 *)((u8 *)(var_r1_31714) + (8)))) {
                        goto loop_13;
                    }
                }
            }
        }
block_16:
        (*(void **)((u8 *)(arg0) + (0x70))) = var_r1_31714;
        (*(u8 **)((u8 *)(arg0) + (0x6C))) = (u8 *) (*(u8 **)((u8 *)(var_r1_31714) + (0x6C)));
        (*(u8 **)((u8 *)((*(u8 **)((u8 *)(var_r1_31714) + (0x6C)))) + (0x70))) = arg0;
        (*(u8 **)((u8 *)(var_r1_31714) + (0x6C))) = arg0;
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
        return *(u32 *)(0x02035E48 + ((s32) (var_r2_31792 << 0x10) >> 0xE));
    case 4:
        return (s32) (s16) var_r2_31792;
    default:
        return (s32) *(u32 *)(0x02035CE0 + ((s32) (var_r2_31792 << 0x10) >> 0xF));
    }
}

u8 sub_020272E8(u16 arg0) {
    u16 var_r1_31835;

    var_r1_31835 = arg0;
    if ((u32) var_r1_31835 > 0x77U) {
        var_r1_31835 = 0x77;
    }
    return *(u32 *)(0x02035DD0 + var_r1_31835);
}

s32 sub_02027300(u8 *arg0) {
    s16 temp_r1_31877;
    s32 temp_r2_31863;
    u8 temp_r1_31858;
    void *temp_r4_31852;

    temp_r4_31852 = arg0 + 0x44;
    if ((*(u16 *)((u8 *)(temp_r4_31852) + (8))) == 0) {
        (*(s32 *)((u8 *)(arg0) + (0x44))) = (s32) (*(s32 *)((u8 *)(temp_r4_31852) + (4)));
        temp_r1_31858 = (*(u8 *)((u8 *)(temp_r4_31852) + (0x10)));
        (*(u8 *)((u8 *)(temp_r4_31852) + (0x10))) = (u8) (temp_r1_31858 + 1);
        temp_r2_31863 = (*(s32 *)((u8 *)(temp_r4_31852) + (0xC)));
        if ((s32) *(u32 *)(((s8) (*(u8 *)((u8 *)(temp_r4_31852) + (0x10))) * 4) + temp_r2_31863) < 0) {
            (*(u8 *)((u8 *)(temp_r4_31852) + (0x10))) = temp_r1_31858;
        }
        temp_r1_31877 = (*(s16 *)((u8 *)((((s8) (*(u8 *)((u8 *)(temp_r4_31852) + (0x10))) * 4) + temp_r2_31863)) + (2)));
        (*(s32 *)((u8 *)(temp_r4_31852) + (4))) = (s32) temp_r1_31877;
        (*(u16 *)((u8 *)(temp_r4_31852) + (8))) = (u16) *(u32 *)(((s8) (*(u8 *)((u8 *)(temp_r4_31852) + (0x10))) * 4) + temp_r2_31863);
        (*(s16 *)((u8 *)(temp_r4_31852) + (0xA))) = temp_r1_31877;
        (*(s16 *)((u8 *)(temp_r4_31852) + (0xA))) = (s16) (temp_r1_31877 - (*(s32 *)((u8 *)(arg0) + (0x44))));
        (*(s16 *)((u8 *)(temp_r4_31852) + (0xA))) = (s16) ((s16) (*(s16 *)((u8 *)(temp_r4_31852) + (0xA))) / (s32) (*(u16 *)((u8 *)(temp_r4_31852) + (8))));
    }
    (*(s32 *)((u8 *)(arg0) + (0x44))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x44))) + (*(s16 *)((u8 *)(temp_r4_31852) + (0xA))));
    (*(u16 *)((u8 *)(temp_r4_31852) + (8))) = (u16) ((*(u16 *)((u8 *)(temp_r4_31852) + (8))) - 1);
    return (*(s32 *)((u8 *)(arg0) + (0x44)));
}

void sub_02027370(u8 arg0) {

}

u32 sub_02027374(u8 *arg0) {
    u32 temp_r0_31952;
    u32 temp_r4_31938;
    u32 var_r4_31942;
    void *temp_r0_31922;
    void *temp_r2_31921;

    if ((*(u8 *)((u8 *)(arg0) + (1))) == 1) {
        temp_r2_31921 = (*(void **)((u8 *)(arg0) + (4)));
        temp_r0_31922 = (*(void **)((u8 *)(temp_r2_31921) + (8)));
        temp_r4_31938 = (u32) ((*(u8 *)((u8 *)(temp_r2_31921) + (0x4E))) * ((u32) ((*(u8 *)((u8 *)(temp_r2_31921) + (0x4D))) * ((u32) ((*(u8 *)((u8 *)(temp_r0_31922) + (0x40))) * ((u32) ((*(u16 *)((u8 *)(temp_r0_31922) + (0x34))) * ((*(u8 *)((u8 *)(arg0) + (9))) << 8)) >> 7)) >> 7)) >> 0xF)) >> 7;
        var_r4_31942 = (u32) ((s32) sub_02027300(arg0) * temp_r4_31938) >> 0xF;
        (*(u32 *)((u8 *)(arg0) + (0x14))) = var_r4_31942;
    } else {
        temp_r0_31952 = (u32) ((*(u32 *)((u8 *)(arg0) + (0x14))) * ((*(u8 *)((u8 *)(arg0) + (0x5C))) + 0xE6)) >> 9;
        (*(u32 *)((u8 *)(arg0) + (0x14))) = temp_r0_31952;
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
    var_r4_31971 = (*(u8 *)((u8 *)(arg0) + (9)));
    if ((*(u16 *)((u8 *)(arg0) + (0x4C))) == 0) {
        var_r6_31970 = 1;
    }
    sub_02027300(arg0);
    if (var_r6_31970 == 0) {
        return 8U;
    }
    if (arg1 != 0) {
        var_r4_31971 *= 2;
    }
    temp_r1_31992 = (*(void **)((u8 *)(arg0) + (4)));
    temp_r1_32003 = (*(void **)((u8 *)(temp_r1_31992) + (8)));
    temp_r4_32010 = (*(u16 *)((u8 *)(temp_r1_32003) + (0x34))) * ((u32) ((*(u8 *)((u8 *)(temp_r1_32003) + (0x40))) * ((u32) ((*(u8 *)((u8 *)(temp_r1_31992) + (0x4E))) * ((u32) ((*(u8 *)((u8 *)(temp_r1_31992) + (0x4D))) * (var_r4_31971 << 0xF)) >> 0xE)) >> 7)) >> 8);
    if ((*(u8 *)((u8 *)(arg0) + (0))) == 3) {
        temp_r4_32014 = temp_r4_32010 >> 0x16;
        (*(u32 *)((u8 *)(arg0) + (0x14))) = temp_r4_32014;
        var_r4_32018 = (u32) (temp_r4_32014 * 5) >> 7;
        if (var_r4_32018 > 4U) {
            var_r4_32018 = 4;
        }
        return (u8) var_r4_32018;
    }
    temp_r4_32027 = temp_r4_32010 >> 0xF;
    (*(u32 *)((u8 *)(arg0) + (0x14))) = temp_r4_32027;
    var_r4_32031 = (u32) ((*(s32 *)((u8 *)(arg0) + (0x44))) * temp_r4_32027) >> 0x19;
    if (var_r4_32031 & ~0xF) {
        var_r4_32031 = 0xF;
    }
    temp_r0_32043 = (u32) ((*(u32 *)((u8 *)(arg0) + (0x14))) * (*(s32 *)((u8 *)(arg0) + (0x48)))) >> 0x19;
    (*(u32 *)((u8 *)(arg0) + (0x14))) = temp_r0_32043;
    if (temp_r0_32043 & ~0xF) {
        (*(u32 *)((u8 *)(arg0) + (0x14))) = 0xFU;
    }
    temp_r5_32051 = (*(u32 *)((u8 *)(arg0) + (0x14)));
    if (temp_r5_32051 != var_r4_32031) {
        var_r1_32060 = temp_r5_32051 - var_r4_32031;
        if (var_r1_32060 < 0) {
            var_r1_32060 = 0 - var_r1_32060;
        }
        var_r2_32068 = (u16) ((s32) (u16) ((*(u16 *)((u8 *)(arg0) + (0x4C))) + 0xF) / var_r1_32060);
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

    temp_r6_32109 = (*(void **)((u8 *)(arg0) + (4)));
    temp_r2_32111 = arg0 + 0x2C;
    temp_r0_32112 = (*(s32 *)((u8 *)(arg0) + (0x2C)));
    if (temp_r0_32112 != 0) {
        (*(s32 *)((u8 *)(arg0) + (0x2C))) = (s32) (temp_r0_32112 - 1);
    } else {
        temp_r4_32119 = (*(s32 *)((u8 *)(temp_r2_32111) + (4)));
        if (temp_r4_32119 != 0) {
            (*(s32 *)((u8 *)(temp_r2_32111) + (8))) = (s32) ((*(s32 *)((u8 *)(temp_r2_32111) + (8))) + (*(s32 *)((u8 *)(temp_r2_32111) + (0x10))));
            temp_r0_32126 = temp_r4_32119 - 1;
            (*(s32 *)((u8 *)(temp_r2_32111) + (4))) = temp_r0_32126;
            if (temp_r0_32126 == 0) {
                (*(s32 *)((u8 *)(temp_r2_32111) + (8))) = (s32) (*(s32 *)((u8 *)(temp_r2_32111) + (0xC)));
            }
        }
    }
    var_r3_32134 = (*(s32 *)((u8 *)(arg0) + (0xC))) + (*(s32 *)((u8 *)(temp_r2_32111) + (8)));
    if ((*(s8 *)((u8 *)(temp_r6_32109) + (0x4F))) != 0) {
        temp_r1_32157 = (s32) (((*(s8 *)((u8 *)(temp_r6_32109) + (0x4F))) * (*(u32 *)(0x02035E48 + (((*(u8 *)((u8 *)(temp_r6_32109) + (0x50))) + 0x30) * 4)) + 0xFFFF8000)) + 0x400000) >> 0xE;
        if ((*(u8 *)((u8 *)(arg0) + (0))) == 0) {
            var_r3_32134 = (u32) (temp_r1_32157 * var_r3_32134) >> 8;
        } else {
            var_r3_32134 = 0x800 - ((u32) ((0x800 - var_r3_32134) << 8) / (u32) temp_r1_32157);
        }
    }
    temp_r4_32178 = arg0 + 0x20;
    temp_r2_32180 = (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_r4_32178) + (8)))) + (8)));
    if (temp_r2_32180 != 0) {
        temp_r0_32183 = (*(s32 *)((u8 *)(temp_r4_32178) + (4)));
        if (temp_r0_32183 == 0) {
            temp_r1_32190 = *(u32 *)(0x02036028 + ((u32) (*(u32 *)((u8 *)(arg0) + (0x20))) >> 1));
            if ((*(u8 *)((u8 *)(arg0) + (0))) == 0) {
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
            temp_r1_32253 = (*(u32 *)((u8 *)(arg0) + (0x20))) + (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_r4_32178) + (8)))) + (4)));
            (*(u32 *)((u8 *)(arg0) + (0x20))) = temp_r1_32253;
            if ((u32) (temp_r1_32253 >> 1) > 0xFFU) {
                (*(u32 *)((u8 *)(arg0) + (0x20))) = (u32) (temp_r1_32253 + 0xFFFFFE00);
            }
        } else {
            (*(s32 *)((u8 *)(temp_r4_32178) + (4))) = (s32) (temp_r0_32183 - 1);
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

    var_r5_32278 = (*(u8 **)((u8 *)((void *)0x03000070) + (0x74)));
    sp0 = 0;
    CpuFastSet(&sp0, (void *)0x03000864, 0x010000B0U);
    if (var_r5_32278 != ((void *)0x03000070 + 0x80)) {
        do {
            temp_r7_32291 = sub_02027374(var_r5_32278);
            if ((*(u8 *)((u8 *)(var_r5_32278) + (1))) == 1) {
                (*(u16 *)((u8 *)(var_r5_32278) + (0x18))) = (u16) ((*(u16 *)((u8 *)(var_r5_32278) + (0x18))) - 1);
                temp_r4_32298 = (*(void **)((u8 *)(var_r5_32278) + (4)));
                if ((*(u8 *)((u8 *)(var_r5_32278) + (0x1B))) != 0) {
                    var_r3_32302 = (*(u8 *)((u8 *)(var_r5_32278) + (0x1C)));
                } else {
                    var_r3_32302 = (*(u8 *)((u8 *)(temp_r4_32298) + (0x4B)));
                }
                var_r6_32313 = var_r3_32302;
                var_r2_32316 = sub_020274D0(var_r5_32278);
                (*(u32 *)((u8 *)(var_r5_32278) + (0x10))) = var_r2_32316;
                (*(u8 *)((u8 *)(var_r5_32278) + (0x1A))) = (u8) (*(u8 *)((u8 *)(temp_r4_32298) + (0x4C)));
                goto block_8;
            }
            if (temp_r7_32291 != 0) {
                var_r6_32313 = (*(u8 *)((u8 *)(var_r5_32278) + (0x1C)));
                var_r2_32316 = (*(u32 *)((u8 *)(var_r5_32278) + (0x10)));
block_8:
                if (sub_02027F0C(var_r5_32278, temp_r7_32291, (u32) ((u32) (0xB0 * ((u32) ((*(s32 *)((u8 *)((*(void **)((u8 *)(var_r5_32278) + (0x60)))) + (4))) * (var_r2_32316 >> 2)) / 10512U)) / 176U) >> 5, var_r6_32313) == 1) {
                    goto block_9;
                }
                var_r5_32278 = (*(u8 **)((u8 *)(var_r5_32278) + (0x70)));
            } else {
block_9:
                var_r5_32278 = (*(u8 **)((u8 *)(var_r5_32278) + (0x70)));
                sub_02027C78((*(u8 **)((u8 *)(var_r5_32278) + (0x6C))));
            }
        } while (var_r5_32278 != (u8 *)0x030000F0);
    }
    var_r5_32366 = 0;
    var_r4_32367 = 6;
    do {
        temp_r1_32370 = var_r5_32366 + 0x030013C4;
        if (((*(u8 *)((u8 *)(temp_r1_32370) + (1))) == 1) && ((*(u16 *)((u8 *)(temp_r1_32370) + (0x18))) == 0)) {
            sub_02027B94(temp_r1_32370);
        }
        var_r5_32366 += 0x7C;
        var_r4_32367 -= 1;
    } while (var_r4_32367 >= 0);
    ((s32 (*)(s32, s32, s32))*(u32 *)0x03000598)(0x03000864, *(u32 *)(0x03000058 + (*(u8 *)0x0300006A * 4)), 0x03000B24);
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
    if (((*(u8 *)((u8 *)(temp_r4_32424) + (1))) == 1) && ((*(u16 *)((u8 *)(temp_r4_32424) + (0x18))) == 0)) {
        sub_02027B94(temp_r4_32424);
    }
    temp_r0_32434 = (*(u8 *)((u8 *)(temp_r4_32424) + (1)));
    if (temp_r0_32434 == 0) {

    } else {
        if (temp_r0_32434 == 1) {
            var_r6_32443 = sub_020274D0(temp_r4_32424);
            (*(u32 *)((u8 *)(temp_r4_32424) + (0x10))) = var_r6_32443;
            if ((*(u8 *)((u8 *)(temp_r4_32424) + (0x1B))) != 0) {
                var_r0_32448 = (*(u8 *)((u8 *)(temp_r4_32424) + (0x1C)));
            } else {
                var_r0_32448 = (*(u8 *)((u8 *)((*(void **)((u8 *)(temp_r4_32424) + (4)))) + (0x4B)));
            }
            var_r8_32457 = var_r0_32448;
        } else {
            var_r6_32443 = (*(u32 *)((u8 *)(temp_r4_32424) + (0x10)));
            var_r8_32457 = (*(u8 *)((u8 *)(temp_r4_32424) + (0x1C)));
        }
        temp_r0_32466 = 0x40 ^ var_r8_32457;
        temp_r7_32473 = sub_020273D0(temp_r4_32424, (u8) ((u32) ((0 - temp_r0_32466) | temp_r0_32466) >> 0x1F));
        temp_r3_32479 = *(u32 *)(0x03001728 + temp_r0_32422) - 1;
        temp_r5_32482 = 0x11 << temp_r3_32479;
        temp_r2_32485 = ~temp_r5_32482;
        if (var_r8_32457 == 0x40) {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | temp_r5_32482;
        } else if ((u32) var_r8_32457 <= 0x3FU) {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | (0x10 << temp_r3_32479);
        } else {
            *(u8 *)0x04000081 = (temp_r2_32485 & *(u8 *)0x04000081) | (1 << temp_r3_32479);
        }
        temp_r5_32523 = (*(u8 *)((u8 *)(temp_r4_32424) + (1)));
        if (temp_r5_32523 == 1) {
            temp_r0_32526 = (*(u32 *)((u8 *)(temp_r4_32424) + (0x64)));
            if (temp_r0_32526 == 0) {
                sub_02027D14(temp_r4_32424, temp_r7_32473);
                (*(u32 *)((u8 *)(temp_r4_32424) + (0x64))) = (u32) temp_r5_32523;
                (*(u16 *)((u8 *)(temp_r4_32424) + (0x18))) = (u16) ((*(u16 *)((u8 *)(temp_r4_32424) + (0x18))) - 1);
            } else {
                (*(u32 *)((u8 *)(temp_r4_32424) + (0x64))) = (u32) (temp_r0_32526 + 1);
                (*(u16 *)((u8 *)(temp_r4_32424) + (0x18))) = (u16) ((*(u16 *)((u8 *)(temp_r4_32424) + (0x18))) - 1);
                goto block_29;
            }
        } else if (*(u32 *)(0x03001728 + temp_r0_32422) == 3) {
            temp_r0_32554 = (u32) ((*(u32 *)((u8 *)(temp_r4_32424) + (0x14))) * ((*(u8 *)((u8 *)(temp_r4_32424) + (0x5C))) + 0xE6)) >> 9;
            (*(u32 *)((u8 *)(temp_r4_32424) + (0x14))) = temp_r0_32554;
            var_r1_32556 = temp_r0_32554;
            if (var_r8_32457 != 0x40) {
                var_r1_32556 *= 2;
            }
            var_r1_32564 = (u32) (var_r1_32556 * 5) >> 7;
            if (var_r1_32564 != 0) {
                if (var_r1_32564 > 4U) {
                    var_r1_32564 = 4;
                }
                *(u8 *)0x04000073 = *(u32 *)(0x02035CC4 + (u8) var_r1_32564);
            } else {
                sub_02027C78(temp_r4_32424);
            }
        } else {
block_29:
            temp_r2_32587 = (*(void **)((u8 *)(temp_r4_32424) + (0x58)));
            if (1 & (*(u8 *)((u8 *)(temp_r2_32587) + (1)))) {
                temp_r0_32593 = (*(u16 **)((u8 *)(temp_r4_32424) + (0x68)));
                temp_r3_32594 = *temp_r0_32593;
                temp_r1_32595 = (*(u32 *)((u8 *)(temp_r4_32424) + (0x64)));
                if (temp_r1_32595 < (u32) temp_r3_32594) {
                    var_r5_32599 = (*(u8 *)((u8 *)((temp_r0_32593 + temp_r1_32595)) + (2)));
                } else {
                    var_r5_32599 = (*(u8 *)((u8 *)((temp_r3_32594 + temp_r0_32593)) + (1)));
                }
            } else {
                var_r5_32599 = 0xFF;
            }
            temp_r0_32608 = *(u32 *)(0x03001728 + temp_r0_32422);
            switch (temp_r0_32608) {                /* irregular */
            case 1:
                if (temp_r7_32473 != 8) {
                    *(u8 *)0x04000063 = temp_r7_32473;
                    *(s16 *)0x04000064 = var_r6_32443 | 0x8000;
                } else if ((*(u8 *)((u8 *)(temp_r2_32587) + (8))) == 8) {
                    *(u32 *)0x04000064 = (s16) var_r6_32443;
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
                    *(u32 *)0x0400006C = (s16) var_r6_32443;
                }
                var_r2_32644 = (u8 *)0x04000068;
                goto block_50;
            case 3:
                *(u16 *)0x04000074 = (*(u16 *)0x04000074 & 0x4000) | var_r6_32443;
                if (temp_r7_32473 != 8) {
                    *(u32 *)0x04000073 = (u8) *(u32 *)(0x02035CC4 + temp_r7_32473);
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
                    *(u32 *)0x0400007C = (u8) ((8 & *(u32 *)0x0400007C) | sub_020272E8((u16) var_r6_32443));
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
    s32 sp4;
    s32 sp8;
    s32 spC;
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
    temp_r4_32774 = (*(void **)((u8 *)(arg0) + (8)));
    if ((*(u8 *)((u8 *)(arg0) + (0x4A))) != 0) {
        return;
    }
    var_r7_32786 = arg1 + (*(u8 *)((u8 *)(arg0) + (0x51)));
    sub_020280B4(arg0, var_r7_32786, &sp0);
    if (0x10 & (*(u8 *)((u8 *)(sp0) + (1)))) {
        var_r0_32799 = temp_r3_32772 / (u16) (*(u16 *)((u8 *)(temp_r4_32774) + (0x30)));
    } else {
        var_r0_32799 = (u32) ((s32) temp_r3_32772 / (s32) ((*(s16 *)((u8 *)(temp_r4_32774) + (0x32))) + (*(u16 *)((u8 *)(temp_r4_32774) + (0x30)))));
    }
    temp_r0_32810 = (u16) var_r0_32799;
    if ((*(u8 *)((u8 *)(arg0) + (0x49))) != 0) {
        temp_r0_32817 = (*(u8 **)((u8 *)(arg0) + (0xC)));
        if (temp_r0_32817 != NULL) {
            var_r4_32820 = temp_r0_32817;
            goto block_11;
        }
    }
    var_r4_32820 = sub_02027E74(*(u32 *)(0x02035CCC + (*(u8 *)((u8 *)(sp0) + (0)))), arg0, (*(u8 *)((u8 *)(arg0) + (0x52))));
    if (var_r4_32820 == NULL) {
        return;
    }
    sub_02028A34(arg0, var_r4_32820);
    (*(s32 *)((u8 *)(var_r4_32820) + (0x64))) = 0;
    (*(void ***)((u8 *)(var_r4_32820) + (0x28))) = (void **) (arg0 + 0x10);
    (*(s32 *)((u8 *)(var_r4_32820) + (0x20))) = 0;
    (*(s32 *)((u8 *)(var_r4_32820) + (0x24))) = (s32) (*(u16 *)((u8 *)(arg0) + (0x10)));
    (*(s32 *)((u8 *)(var_r4_32820) + (0x50))) = sp4;
    (*(s32 *)((u8 *)(var_r4_32820) + (0x44))) = 0;
    (*(s32 *)((u8 *)(var_r4_32820) + (0x48))) = 0;
    (*(s16 *)((u8 *)(var_r4_32820) + (0x4C))) = 0;
    (*(s8 *)((u8 *)(var_r4_32820) + (0x54))) = 0xFF;
    (*(u8 *)((u8 *)(var_r4_32820) + (0x5C))) = (u8) (*(u8 *)((u8 *)(sp0) + (6)));
    (*(void **)((u8 *)(var_r4_32820) + (0x58))) = sp0;
block_11:
    temp_r0_32866 = (*(u8 *)((u8 *)(&sp0) + (0x11)));
    (*(u8 *)((u8 *)(var_r4_32820) + (0x1B))) = temp_r0_32866;
    if ((temp_r0_32866 << 0x18) != 0) {
        var_r7_32786 = 0x30;
        (*(u8 *)((u8 *)(var_r4_32820) + (0x1C))) = (u8) (*(u8 *)((u8 *)(&sp0) + (0x10)));
    } else if ((*(u8 *)((u8 *)(&sp0) + (0x12))) != 0) {
        var_r7_32786 = 0x30;
    }
    (*(u8 *)((u8 *)(var_r4_32820) + (9))) = arg2;
    (*(s32 *)((u8 *)(var_r4_32820) + (0x14))) = 0;
    (*(u16 *)((u8 *)(var_r4_32820) + (0x18))) = temp_r0_32810;
    (*(u8 *)((u8 *)(var_r4_32820) + (0x1A))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x4C)));
    (*(s32 *)((u8 *)(var_r4_32820) + (0xC))) = sub_02027294(var_r4_32820, var_r7_32786, (*(u8 *)((u8 *)(sp0) + (7))));
    (*(void ***)((u8 *)(var_r4_32820) + (0x40))) = (void **) (arg0 + 0x1C);
    temp_r0_32903 = (*(u8 *)((u8 *)(arg0) + (0x1C)));
    if (temp_r0_32903 != 0) {
        temp_r2_32910 = sub_02027294(var_r4_32820, (*(u8 *)((u8 *)(arg0) + (0x1E))), (*(u8 *)((u8 *)(sp0) + (7))));
        (*(s32 *)((u8 *)(var_r4_32820) + (0x2C))) = (s32) (*(u16 *)((u8 *)(arg0) + (0x20)));
        (*(u32 *)((u8 *)(var_r4_32820) + (0x30))) = (u32) ((u32) ((*(u16 *)((u8 *)(arg0) + (0x22))) * temp_r0_32810) >> 8);
        if (2 & (*(u8 *)((u8 *)(arg0) + (0x1D)))) {
            (*(s32 *)((u8 *)(var_r4_32820) + (0x38))) = (s32) (temp_r2_32910 - (*(s32 *)((u8 *)(var_r4_32820) + (0xC))));
        } else {
            (*(s32 *)((u8 *)(var_r4_32820) + (0x38))) = (s32) ((*(s32 *)((u8 *)(var_r4_32820) + (0xC))) - temp_r2_32910);
            (*(s32 *)((u8 *)(var_r4_32820) + (0xC))) = temp_r2_32910;
        }
        temp_r0_32934 = (*(s32 *)((u8 *)(var_r4_32820) + (0x38)));
        (*(s32 *)((u8 *)(var_r4_32820) + (0x3C))) = temp_r0_32934;
        (*(s32 *)((u8 *)(var_r4_32820) + (0x3C))) = (s32) (temp_r0_32934 / (s32) (*(u32 *)((u8 *)(var_r4_32820) + (0x30))));
        temp_r0_32943 = 4 & (*(u8 *)((u8 *)(arg0) + (0x1D)));
        if (temp_r0_32943 != 0) {
            (*(u8 *)((u8 *)(arg0) + (0x1E))) = var_r7_32786;
        } else {
            (*(u8 *)((u8 *)(arg0) + (0x1C))) = temp_r0_32943;
        }
        (*(s32 *)((u8 *)(var_r4_32820) + (0x34))) = 0;
    } else {
        (*(s32 *)((u8 *)(var_r4_32820) + (0x2C))) = (s32) temp_r0_32903;
        (*(u32 *)((u8 *)(var_r4_32820) + (0x30))) = (u32) temp_r0_32903;
        (*(s32 *)((u8 *)(var_r4_32820) + (0x34))) = (s32) temp_r0_32903;
        (*(s32 *)((u8 *)(var_r4_32820) + (0x38))) = (s32) temp_r0_32903;
        (*(s32 *)((u8 *)(var_r4_32820) + (0x3C))) = (s32) temp_r0_32903;
    }
    temp_r0_32961 = (*(u8 *)((u8 *)(var_r4_32820) + (0)));
    if (temp_r0_32961 == 0) {
        temp_r1_32965 = (*(s32 *)((u8 *)(arg0) + (4)));
        (*(s32 *)((u8 *)(var_r4_32820) + (0x60))) = (s32) (temp_r1_32965 + *(u32 *)(((*(u16 *)((u8 *)(sp0) + (2))) * 4) + temp_r1_32965));
    } else if (temp_r0_32961 != 3) {
        if (1 & (*(u8 *)((u8 *)(sp0) + (1)))) {
            var_r0_32980 = sp8;
            goto block_31;
        }
        (*(s8 *)((u8 *)(var_r4_32820) + (0x68))) = (s8) (*(u16 *)((u8 *)(sp0) + (2)));
    } else {
        var_r0_32980 = spC;
block_31:
        (*(s8 *)((u8 *)(var_r4_32820) + (0x68))) = var_r0_32980;
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

    if (((*(u8 *)((u8 *)(arg0) + (1))) == 1) && ((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (4)))) + (0x49))) == 0)) {
        temp_r3_33019 = (*(u8 *)((u8 *)(arg0) + (0)));
        if (temp_r3_33019 == 0) {
            sub_020271FC(arg0);
            (*(u8 *)((u8 *)(arg0) + (1))) = 2U;
            sub_0202720C(arg0);
        } else {
            temp_r2_33030 = (*(u16 *)((u8 *)(arg0) + (0x10)));
            if (temp_r3_33019 == 3) {
                var_r0_33036 = 2;
            } else {
                temp_r1_33039 = (u8) (*(u8 *)((u8 *)(arg0) + (0x5C))) >> 5;
                if (temp_r1_33039 == 0) {
                    var_r1_33042 = 0;
                } else {
                    var_r1_33042 = temp_r1_33039 | ((*(s32 *)((u8 *)(arg0) + (0x14))) * 0x10);
                }
                temp_r0_33051 = (*(u8 *)((u8 *)(arg0) + (0)));
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
            (*(u8 *)((u8 *)(arg0) + (1))) = var_r0_33036;
        }
        temp_r1_33110 = (*(void **)((u8 *)(arg0) + (4)));
        if ((*(u8 *)((u8 *)(arg0) + (0x1B))) == 0) {
            (*(u8 *)((u8 *)(arg0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(temp_r1_33110) + (0x4B)));
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

    if ((*(u8 *)((u8 *)(arg0) + (1))) != 0) {
        temp_r0_33136 = (*(u8 *)((u8 *)(arg0) + (0)));
        switch (temp_r0_33136) {
        case 0:
            sub_020271FC(arg0);
            temp_r1_33159 = *(u8 **)0x030001DC;
            (*(u8 **)((u8 *)(arg0) + (0x70))) = temp_r1_33159;
            (*(s32 *)((u8 *)(arg0) + (0x6C))) = 0x0300016C;
            (*(u8 **)((u8 *)(temp_r1_33159) + (0x6C))) = arg0;
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
        sub_02028A4C((*(void **)((u8 *)(arg0) + (4))), arg0);
        (*(u8 *)((u8 *)(arg0) + (1))) = 0U;
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
    temp_r3_33216 = (*(u8 *)((u8 *)(arg0) + (0)));
    switch (temp_r3_33216) {                        /* irregular */
    case 1:
        *(u8 *)0x04000060 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x58)))) + (8)));
        *(s16 *)0x04000064 = (*(s32 *)((u8 *)(arg0) + (0xC))) | 0x8000;
        *(u8 *)0x04000063 = temp_r5_33215;
        if (temp_r3_33216 & (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x58)))) + (1)))) {
            var_r0_33251 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x68)))) + (2)));
        } else {
            var_r0_33251 = (u8) (*(void **)((u8 *)(arg0) + (0x68)));
        }
        *(s8 *)0x04000062 = var_r0_33251 << 6;
        *(u32 *)0x04000064 = (s16) ((*(s32 *)((u8 *)(arg0) + (0xC))) | 0x8000);
        return;
    case 2:
        *(u8 *)0x04000069 = temp_r5_33215;
        *(s16 *)0x0400006C = (*(s32 *)((u8 *)(arg0) + (0xC))) | 0x8000;
        var_r1_33287 = (s8 *)0x04000068;
        var_r0_33291 = (u8) (*(void **)((u8 *)(arg0) + (0x68))) << 6;
block_22:
        *var_r1_33287 = var_r0_33291;
        return;
    case 3:
        if ((*(void **)((u8 *)(arg0) + (0x68))) != *(void **)0x03000070) {
            *(s8 *)0x04000070 = 0;
            CpuSet((*(void **)((u8 *)(arg0) + (0x68))), (s8 *)0x04000070 + 0x20, 8U);
            *(void **)0x03000070 = (*(void **)((u8 *)(arg0) + (0x68)));
        }
        *(u32 *)0x04000070 = 0xC0;
        *(s16 *)0x04000074 = (*(s32 *)((u8 *)(arg0) + (0xC))) | 0x8000;
        *(u8 *)0x04000073 = *(u32 *)(0x02035CC4 + temp_r5_33215);
        var_r1_33287 = (s8 *)0x04000072;
block_21:
        var_r0_33291 = 0;
        goto block_22;
    case 4:
        *(u8 *)0x04000079 = temp_r5_33215;
        if (1 & (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x58)))) + (1)))) {
            var_r1_33348 = sub_020272E8((u16) (*(s32 *)((u8 *)(arg0) + (0xC))));
            var_r0_33350 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x68)))) + (2)));
        } else {
            var_r1_33348 = sub_020272E8((u16) (*(s32 *)((u8 *)(arg0) + (0xC))));
            var_r0_33350 = (u8) (*(void **)((u8 *)(arg0) + (0x68)));
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

u8 *sub_02027E74(u8 arg0, u8 arg1, u8 arg2) {
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
        temp_r2_33410 = (*(u8 **)((u8 *)((void *)0x03000070) + (0x74)));
        if ((temp_r2_33410 != ((void *)0x03000070 + 0x80)) && (((*(u8 *)((u8 *)(temp_r2_33410) + (1))) != 1) || ((u32) temp_r5_33392 >= (u32) (*(u8 *)((u8 *)(temp_r2_33410) + (8)))))) {
            var_r4_33405 = temp_r2_33410;
            sub_02027C78(var_r4_33405);
block_7:
            sub_020271FC(var_r4_33405);
            (*(s8 *)((u8 *)(var_r4_33405) + (1))) = 1;
            (*(u8 *)((u8 *)(var_r4_33405) + (8))) = temp_r5_33392;
            sub_0202720C(var_r4_33405);
            goto block_14;
        }
        goto block_10;
    }
    var_r4_33405 = (temp_r1_33390 * 0x7C) + 0x030016AC;
    if (((*(u8 *)((u8 *)(var_r4_33405) + (1))) == 1) && ((u32) temp_r5_33392 < (u32) (*(u8 *)((u8 *)(var_r4_33405) + (8))))) {
block_10:
        return NULL;
    }
    if ((*(u8 *)((u8 *)(var_r4_33405) + (1))) != 0) {
        sub_02027C78(var_r4_33405);
    }
    (*(u8 *)((u8 *)(var_r4_33405) + (1))) = 1U;
    (*(u8 *)((u8 *)(var_r4_33405) + (8))) = temp_r5_33392;
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
    temp_r4_33481 = (*(s32 *)((u8 *)(arg0) + (0x64)));
    temp_r1_33483 = arg1;
    var_r8_33486 = 0;
    temp_r1_33490 = (*(void **)((u8 *)(sp10) + (0x60)));
    sp20 = temp_r1_33490 + 0x10;
    sp14 = 0x03000864;
    sp18 = 0x030009C4;
    sp1C = (u32) (((0x7F - temp_r3_33480) * temp_r1_33483) << 0x10) >> 0x17;
    temp_r0_33511 = (u32) ((temp_r3_33480 * temp_r1_33483) << 0x10) >> 0x17;
    var_r7_33513 = (*(u32 *)((u8 *)(temp_r1_33490) + (0xC)));
    if (var_r7_33513 == 0) {
        var_r7_33513 = (*(u32 *)((u8 *)(temp_r1_33490) + (0)));
    }
    if ((u32) ((u32) (temp_r4_33481 + (arg2 * 0xB0)) >> 8) < var_r7_33513) {
        var_r5_33524 = sp18;
    } else {
        var_r5_33524 = (((u32) ((((var_r7_33513 << 8) - temp_r4_33481) - 1) + arg2) / arg2) * 2) + sp14;
        var_r8_33486 = 1;
    }
    temp_r0_33542 = (*(void **)((u8 *)(sp10) + (0x60)));
    temp_r1_33543 = (*(s32 *)((u8 *)(temp_r0_33542) + (0xC)));
    if ((temp_r1_33543 == 0) || (var_r8_33486 == 0)) {
        var_r4_33563 = ((s32 (*)(s32, s32, s32, s32, s32, u32, u32, u32))*(u32 *)0x0300059C)(sp20, sp14, sp18, var_r5_33524, temp_r4_33481, arg2, sp1C, temp_r0_33511);
        if (var_r8_33486 != 0) {
            return 1U;
        }
        goto block_16;
    }
    temp_r1_33574 = (temp_r1_33543 - (*(s32 *)((u8 *)(temp_r0_33542) + (8)))) << 8;
    sp24 = temp_r1_33574;
    var_r4_33563 = ((s32 (*)(s32, s32, s32, s32, s32, u32, u32, u32))*(u32 *)0x0300059C)(sp20, sp14, sp18, var_r5_33524, temp_r4_33481, arg2, sp1C, temp_r0_33511) - temp_r1_33574;
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
            var_r4_33563 = ((s32 (*)(s32, s32, s32, s32, s32, u32, u32, u32))*(u32 *)0x0300059C)(sp20, sp14, sp18, var_r5_33524, var_r4_33563, arg2, sp1C, temp_r0_33511);
            if (var_r8_33616 != 0) {
                var_r4_33563 -= sp24;
            }
            temp_r2_33656 = var_sl_33597 - ((s32) (var_r5_33524 - sp14) >> 1);
            var_sl_33597 = temp_r2_33656;
        } while (temp_r2_33656 != 0);
    }
block_16:
    (*(s32 *)((u8 *)(sp10) + (0x64))) = var_r4_33563;
    return 0U;
}

void sub_02028098(void) {
    (*(s8 *)((u8 *)((void *)0x03000268) + (0))) = 0;
    (*(s8 *)((u8 *)((void *)0x03000268) + (1))) = 0;
    (*(s16 *)((u8 *)((void *)0x03000268) + (2))) = 0;
    (*(s16 *)((u8 *)((void *)0x03000268) + (4))) = 0;
    (*(s8 *)((u8 *)((void *)0x03000268) + (6))) = 0;
    (*(s8 *)((u8 *)((void *)0x03000268) + (7))) = 0x30;
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
    temp_r2_33708 = (*(s32 *)((u8 *)(*(void **)0x03000594) + (4)));
    temp_r3_33712 = temp_r2_33708 + *(u32 *)((*(u32 *)(((*(u16 *)((u8 *)(arg0) + (0x40))) * 2) + *(*(s32 **)((u8 *)(arg0) + (8)))) * 4) + temp_r2_33708);
    temp_r5_33718 = temp_r3_33712 + *(u32 *)(temp_r3_33712 + ((*(u16 *)((u8 *)(arg0) + (0x42))) * 2));
    (*(s8 *)((u8 *)(arg2) + (0x11))) = 0;
    (*(s8 *)((u8 *)(arg2) + (0x12))) = 0;
    temp_r1_33722 = (*(u8 *)((u8 *)(temp_r5_33718) + (0)));
    if (0xF0 & temp_r1_33722) {
        switch (temp_r1_33722) {                    /* irregular */
        case 16:
            (*(s8 *)((u8 *)(arg2) + (0x11))) = 1;
            temp_r0_33738 = ((u32) ((temp_r6_33697 - (*(u8 *)((u8 *)(temp_r5_33718) + (4)))) << 0x18) >> 0x16) + (temp_r3_33712 + (*(u16 *)((u8 *)(temp_r5_33718) + (2))));
            (*(u8 *)((u8 *)(arg2) + (0x10))) = (u8) (*(u8 *)((u8 *)(temp_r0_33738) + (2)));
            temp_r0_33742 = temp_r3_33712 + (*(u16 *)((u8 *)(temp_r0_33738) + (0)));
            (*(void **)((u8 *)(arg2) + (0))) = temp_r0_33742;
            var_r0_33744 = (*(u16 *)((u8 *)(temp_r0_33742) + (4)));
            goto block_11;
        case 17:
            (*(u16 *)((u8 *)((void *)0x03000268) + (2))) = (u16) *(u32 *)((temp_r6_33697 * 2) + (temp_r3_33712 + (*(u16 *)((u8 *)(temp_r5_33718) + (2)))));
            (*(void **)((u8 *)(arg2) + (0))) = (void *)0x03000268;
            (*(s32 *)((u8 *)(arg2) + (4))) = 0x02035CD4;
            (*(s8 *)((u8 *)(arg2) + (0x12))) = 1;
            break;
        case 18:
            var_r0_33771 = temp_r3_33712 + (*(u16 *)((u8 *)(temp_r5_33718) + (2)));
loop_8:
            if ((u32) temp_r6_33697 > (u32) (*(u8 *)((u8 *)(var_r0_33771) + (0)))) {
                var_r0_33771 += 4;
                goto loop_8;
            }
            temp_r0_33780 = temp_r3_33712 + (*(u16 *)((u8 *)(var_r0_33771) + (2)));
            (*(void **)((u8 *)(arg2) + (0))) = temp_r0_33780;
            var_r0_33744 = (*(u16 *)((u8 *)(temp_r0_33780) + (4)));
            goto block_11;
        }
    } else {
        (*(void **)((u8 *)(arg2) + (0))) = temp_r5_33718;
        var_r0_33744 = (u16) (*(u8 *)((u8 *)(temp_r5_33718) + (4)));
block_11:
        (*(s32 *)((u8 *)(arg2) + (4))) = (s32) (temp_r3_33712 + var_r0_33744);
    }
    temp_r2_33791 = (*(void **)((u8 *)(arg2) + (0)));
    if ((*(u8 *)((u8 *)(temp_r2_33791) + (0))) == 3) {
        (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) (temp_r3_33712 + (*(u16 *)((u8 *)(temp_r5_33718) + (2))));
    }
    if (1 & (*(u8 *)((u8 *)(temp_r2_33791) + (1)))) {
        (*(s32 *)((u8 *)(arg2) + (8))) = (s32) (temp_r3_33712 + (*(u16 *)((u8 *)(temp_r2_33791) + (2))));
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
        (*(s8 *)((u8 *)(temp_r0_33822) + (0x41))) = 0;
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
    (*(u8 *)((u8 *)(arg0) + (0x3C))) = (u8) (-2 & (*(u8 *)((u8 *)(arg0) + (0x3C))));
    (*(s16 *)((u8 *)(arg0) + (0x30))) = 0x96;
    (*(s16 *)((u8 *)(arg0) + (0x32))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x40))) = 0x80;
    (*(s16 *)((u8 *)(arg0) + (0x34))) = 0x8000;
    (*(s16 *)((u8 *)(arg0) + (0x36))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x3A))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x38))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x43))) = 0;
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
        temp_r0_33887 = (*(u8 *)((u8 *)(temp_r1_33884) + (0x41)));
        var_r7_33888 = var_r6_33878 + 1;
        if (temp_r0_33887 != 0) {
            temp_r2_33891 = (*(u16 *)((u8 *)(temp_r1_33884) + (0x3A)));
            if (temp_r2_33891 == 0) {
                if (temp_r0_33887 == 2) {
                    sub_020283D4(var_r6_33878);
                } else {
                    goto block_7;
                }
            } else {
                (*(u16 *)((u8 *)(temp_r1_33884) + (0x34))) = (u16) ((*(u16 *)((u8 *)(temp_r1_33884) + (0x36))) + (*(u16 *)((u8 *)(temp_r1_33884) + (0x34))));
                temp_r0_33906 = temp_r2_33891 - 1;
                (*(u16 *)((u8 *)(temp_r1_33884) + (0x3A))) = temp_r0_33906;
                if ((temp_r0_33906 << 0x10) == 0) {
                    (*(u16 *)((u8 *)(temp_r1_33884) + (0x34))) = (u16) (*(u16 *)((u8 *)(temp_r1_33884) + (0x38)));
                }
block_7:
                var_r2_33914 = 0;
                var_r7_33888 = var_r6_33878 + 1;
                var_r4_33917 = temp_r1_33884 + 8;
                var_r5_33918 = 9;
                do {
                    if (*var_r4_33917 != 0) {
                        sp0 = var_r2_33914;
                        if ((sub_020285C8((void **)*var_r4_33917) << 0x18) == 0) {
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
    temp_r3_33957 = (*(s32 *)((u8 *)(temp_r4_33956) + (8)));
    temp_r1_33958 = arg1 * 4;
    temp_r2_33962 = (*(s32 *)((u8 *)(temp_r4_33956) + (0x14)));
    sub_020282E0(arg0, temp_r3_33957 + *(u32 *)(temp_r1_33958 + temp_r3_33957), temp_r2_33962 + *(u32 *)(temp_r1_33958 + temp_r2_33962));
}

void sub_020282B4(s32 arg0, u16 arg1, u32 arg2) {
    s32 temp_r1_33981;
    s32 temp_r2_33985;
    s32 temp_r4_33980;
    void *temp_r5_33979;

    temp_r5_33979 = *(void **)0x03000594;
    temp_r4_33980 = (*(s32 *)((u8 *)(temp_r5_33979) + (0xC)));
    temp_r1_33981 = arg1 * 4;
    temp_r2_33985 = (*(s32 *)((u8 *)(temp_r5_33979) + (0x18)));
    sub_02028368(arg0, temp_r4_33980 + *(u32 *)(temp_r1_33981 + temp_r4_33980), temp_r2_33985 + *(u32 *)(temp_r1_33981 + temp_r2_33985), arg2);
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
    if ((*(u8 *)((u8 *)(temp_r5_34009) + (0x41))) != 0) {
        sub_020283D4(arg0);
    }
    (*(s8 **)((u8 *)(temp_r5_34009) + (4))) = arg1;
    *(u32 *)(0x03001918 + temp_r0_34007) = arg2;
    (*(s8 *)((u8 *)(temp_r5_34009) + (0x42))) = 0;
    sub_020281C4(temp_r5_34009);
    temp_r0_34026 = (*(s8 **)((u8 *)(temp_r5_34009) + (4)));
    temp_r7_34028 = *temp_r0_34026;
    var_r6_34030 = 0;
    if ((s32) temp_r7_34028 > 0) {
        var_r4_34034 = temp_r0_34026 + 2;
        do {
            if (*var_r4_34034 != 0) {
                temp_r0_34039 = sub_020284A0();
                *(u32 *)(temp_r5_34009 + 8 + (var_r6_34030 * 4)) = temp_r0_34039;
                sub_020284C4(temp_r0_34039, temp_r5_34009, (*(s8 **)((u8 *)(temp_r5_34009) + (4))) + *var_r4_34034);
            }
            var_r4_34034 += 2;
            var_r6_34030 += 1;
        } while (var_r6_34030 < (s32) temp_r7_34028);
    }
    (*(u8 *)((u8 *)(temp_r5_34009) + (0x41))) = 1U;
}

void sub_02028368(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 temp_r0_34079;
    s32 temp_r2_34101;
    void **temp_r0_34099;
    void *temp_r5_34081;

    temp_r0_34079 = arg0 * 0x44;
    temp_r5_34081 = temp_r0_34079 + 0x03001918;
    if ((*(u8 *)((u8 *)(temp_r5_34081) + (0x41))) != 0) {
        sub_020283D4(arg0);
    }
    (*(s32 *)((u8 *)(temp_r5_34081) + (4))) = arg1;
    *(u32 *)(0x03001918 + temp_r0_34079) = arg2;
    (*(s8 *)((u8 *)(temp_r5_34081) + (0x42))) = 1;
    sub_020281C4(temp_r5_34081);
    temp_r0_34099 = sub_020284A0();
    (*(void ***)((u8 *)(temp_r5_34081) + (8))) = temp_r0_34099;
    temp_r2_34101 = (*(s32 *)((u8 *)(temp_r5_34081) + (4)));
    sub_020284C4(temp_r0_34099, temp_r5_34081, temp_r2_34101 + *(u32 *)((arg3 * 2) + temp_r2_34101));
    (*(u8 *)((u8 *)(temp_r5_34081) + (0x41))) = 1U;
}

void sub_020283D4(s32 arg0) {
    s32 var_r5_34137;
    void ***var_r4_34136;
    void *temp_r1_34127;

    temp_r1_34127 = (arg0 * 0x44) + 0x03001918;
    if ((*(u8 *)((u8 *)(temp_r1_34127) + (0x41))) != 0) {
        var_r4_34136 = temp_r1_34127 + 8;
        var_r5_34137 = 9;
        do {
            sub_020285B0(*var_r4_34136);
            *var_r4_34136 = NULL;
            var_r4_34136 += 4;
            var_r5_34137 -= 1;
        } while (var_r5_34137 >= 0);
        (*(u8 *)((u8 *)(temp_r1_34127) + (0x41))) = 0U;
    }
}

void sub_02028410(s32 arg0, s16 arg1) {
    void *temp_r4_34162;

    temp_r4_34162 = (arg0 * 0x44) + 0x03001918;
    if ((*(u8 *)((u8 *)(temp_r4_34162) + (0x41))) != 0) {
        (*(u8 *)((u8 *)(temp_r4_34162) + (0x41))) = 2U;
        (*(s16 *)((u8 *)(temp_r4_34162) + (0x38))) = 0;
        (*(s16 *)((u8 *)(temp_r4_34162) + (0x3A))) = arg1;
        (*(s16 *)((u8 *)(temp_r4_34162) + (0x36))) = (s16) ((s32) (0 - (*(u16 *)((u8 *)(temp_r4_34162) + (0x34)))) / arg1);
    }
}

void sub_02028448(s32 arg0, u8 arg1) {
    void *temp_r2_34193;

    temp_r2_34193 = (arg0 * 0x44) + 0x03001918;
    (*(u8 *)((u8 *)(temp_r2_34193) + (0x3C))) = (u8) ((-2 & (*(u8 *)((u8 *)(temp_r2_34193) + (0x3C)))) | (arg1 & 1));
}

u8 sub_0202846C(s32 arg0) {
    return *(u32 *)(0x03001959 + (arg0 * 0x44));
}

void sub_02028480(void) {
    s32 var_r2_34224;
    void *var_r0_34223;

    var_r0_34223 = (void *)0x03000B2C;
    var_r2_34224 = 0xF;
    do {
        (*(s8 *)((u8 *)(var_r0_34223) + (0))) = 0;
        (*(s8 *)((u8 *)(var_r0_34223) + (1))) = 0;
        (*(s8 *)((u8 *)(var_r0_34223) + (2))) = 0;
        (*(s8 *)((u8 *)(var_r0_34223) + (3))) = 0;
        var_r0_34223 += 0x54;
        var_r2_34224 -= 1;
    } while (var_r2_34224 >= 0);
}

void **sub_020284A0(void) {
    void **var_r1_34240;

    var_r1_34240 = (void **)0x03000B24;
loop_1:
    if ((*(s32 *)((u8 *)(var_r1_34240) + (8))) == 0) {
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
        if ((*(void **)((u8 *)(arg0) + (8))) != NULL) {
            sub_020285B0(arg0);
        }
        (*(s32 *)((u8 *)(arg0) + (0x34))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x49))) = 0;
        (*(s8 *)((u8 *)((arg0 + 0x49)) + (1))) = 0;
        (*(void **)((u8 *)(arg0) + (0))) = arg2;
        (*(void **)((u8 *)(arg0) + (8))) = arg1;
        (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
        sub_02028A98(arg0, 0U);
        temp_r1_34289 = arg0 + 0x4B;
        (*(s8 *)((u8 *)(arg0) + (0x4B))) = 0x40;
        (*(s16 *)((u8 *)(arg0) + (0x10))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x14))) = 0x22;
        (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x1C))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x1D))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x1E))) = 0;
        (*(s16 *)((u8 *)(arg0) + (0x20))) = 0;
        (*(s16 *)((u8 *)(arg0) + (0x22))) = 0;
        temp_r1_34302 = temp_r1_34289 + 2;
        (*(s8 *)((u8 *)(temp_r1_34289) + (2))) = 0x80;
        temp_r1_34305 = temp_r1_34302 + 1;
        (*(s8 *)((u8 *)(temp_r1_34302) + (1))) = 0x80;
        (*(s8 *)((u8 *)(arg0) + (0x4F))) = 0;
        temp_r1_34310 = temp_r1_34305 + 2;
        (*(s8 *)((u8 *)(temp_r1_34305) + (2))) = 2;
        (*(s8 *)((u8 *)(arg0) + (0x51))) = 0;
        temp_r3_34318 = (*(u8 *)((u8 *)(arg1) + (0x42)));
        if (temp_r3_34318 == 1) {
            (*(s8 *)((u8 *)(temp_r1_34310) + (2))) = 0xC;
            *(u32 *)((temp_r1_34310 + 2) - 6) = 0x7F;
            (*(u8 *)((u8 *)(arg0) + (0x53))) = temp_r3_34318;
        } else {
            (*(s8 *)((u8 *)(arg0) + (0x52))) = 3;
            (*(s8 *)((u8 *)(arg0) + (0x4C))) = 0;
            (*(s8 *)((u8 *)((arg0 + 0x4C)) + (7))) = 0;
        }
        (*(s16 *)((u8 *)(arg0) + (0x44))) = 0x7F;
        (*(s8 *)((u8 *)(arg0) + (0x48))) = 0x7F;
        temp_r0_34351 = (arg0 + 0x48) - 2;
        *temp_r0_34351 = 0;
        (*(s32 *)((u8 *)(arg0) + (0x30))) = (s32) (temp_r0_34351 - 0x22);
    }
}

void sub_02028580(void **arg0) {
    u8 temp_r6_34368;
    void *temp_r4_34376;
    void *var_r0_34371;

    if (arg0 != NULL) {
        temp_r6_34368 = (*(u8 *)((u8 *)(arg0) + (0x49)));
        (*(u8 *)((u8 *)(arg0) + (0x49))) = 0U;
        var_r0_34371 = (*(void **)((u8 *)(arg0) + (0xC)));
        if (var_r0_34371 != NULL) {
            do {
                temp_r4_34376 = (*(void **)((u8 *)(var_r0_34371) + (0x78)));
                sub_02027B94(var_r0_34371);
                var_r0_34371 = temp_r4_34376;
            } while (var_r0_34371 != NULL);
        }
        (*(u8 *)((u8 *)(arg0) + (0x49))) = temp_r6_34368;
    }
}

void sub_020285B0(void **arg0) {
    if (arg0 != NULL) {
        sub_02028580(arg0);
        (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    }
}

s32 sub_020285C8(void **arg0) {
    s32 sp0;
    s32 (*temp_r2_34788)(void **, u8);
    s32 (*temp_r7_34476)(void **, u8, u8, u16);
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

    if ((arg0 == NULL) || (temp_r1_34413 = (*(void **)((u8 *)(arg0) + (8))), (temp_r1_34413 == NULL))) {
        return 1;
    }
    if (!(1 & (*(u8 *)((u8 *)(temp_r1_34413) + (0x3C))))) {
    m2c_case_0x9:
    m2c_case_0xA:
    m2c_case_0xB:
    m2c_case_0xC:
    m2c_case_0xD:
    m2c_case_0xE:
    m2c_case_0xF:
    m2c_case_0x10:
    m2c_case_0x11:
    m2c_case_0x12:
    m2c_case_0x13:
    m2c_case_0x14:
    m2c_case_0x15:
    m2c_case_0x16:
    m2c_case_0x17:
    m2c_case_0x18:
    m2c_case_0x19:
    m2c_case_0x1A:
    m2c_case_0x1B:
    m2c_case_0x1C:
    m2c_case_0x1D:
    m2c_case_0x28:
    m2c_case_0x29:
    m2c_case_0x2A:
    m2c_case_0x2B:
    m2c_case_0x2C:
    m2c_case_0x2D:
    m2c_case_0x2F:
    m2c_case_0x30:
    m2c_case_0x31:
    m2c_case_0x33:
    m2c_case_0x34:
    m2c_case_0x35:
    m2c_case_0x37:
    m2c_case_0x38:
    m2c_case_0x39:
    m2c_case_0x3A:
    m2c_case_0x3B:
    m2c_case_0x3C:
loop_67:
        temp_r1_34927 = (*(s32 *)((u8 *)(arg0) + (0x34)));
        if (temp_r1_34927 <= 0) {
            temp_r2_34439 = (*(void **)((u8 *)(arg0) + (0)));
            var_r6_34440 = (*(u8 *)((u8 *)(temp_r2_34439) + (0)));
            temp_r2_34441 = temp_r2_34439 + 1;
            (*(void **)((u8 *)(arg0) + (0))) = temp_r2_34441;
            if ((u32) var_r6_34440 <= 0xBFU) {
                if ((u32) var_r6_34440 <= 0x5FU) {
                    var_r4_34449 = (*(u16 *)((u8 *)(arg0) + (0x44)));
                    var_r2_34451 = (*(u8 *)((u8 *)((arg0 + 0x44)) + (4)));
                } else {
                    var_r4_34449 = sub_02028A74(arg0);
                    (*(u16 *)((u8 *)(arg0) + (0x44))) = var_r4_34449;
                    temp_r0_34461 = (*(void **)((u8 *)(arg0) + (0)));
                    var_r2_34451 = (*(u8 *)((u8 *)(temp_r0_34461) + (0)));
                    (*(void **)((u8 *)(arg0) + (0))) = temp_r0_34461 + 1;
                    (*(u8 *)((u8 *)(arg0) + (0x48))) = var_r2_34451;
                    var_r6_34440 -= 0x60;
                }
                var_r4_34474 = 0x96 * var_r4_34449;
                temp_r7_34476 = *(s32 (**)(void **, u8, u8, u16))0x03000270;
                if ((temp_r7_34476 != NULL) && (1 & (*(u8 *)((u8 *)(temp_r1_34413) + (0x43))))) {
                    temp_r7_34476(arg0, var_r6_34440, var_r2_34451, var_r4_34474);
                } else {
                    sub_020279BC(arg0, var_r6_34440, var_r2_34451, var_r4_34474);
                }
                if ((*(u8 *)((u8 *)(arg0) + (0x53))) != 1) {

                } else {
                    goto block_23;
                }
                goto loop_67;
            }
            if (var_r6_34440 == 0xC0) {
                var_r4_34514 = (*(u16 *)((u8 *)(arg0) + (0x46)));
                goto block_22;
            }
            if (var_r6_34440 == 0xC1) {
                var_r4_34514 = sub_02028A74(arg0);
                (*(u16 *)((u8 *)(arg0) + (0x46))) = var_r4_34514;
block_22:
                var_r4_34474 = 0x96 * var_r4_34514;
block_23:
                (*(s32 *)((u8 *)(arg0) + (0x34))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x34))) + var_r4_34474);
                goto loop_67;
            }
            if ((0xF0 & var_r6_34440) == 0xD0) {
                temp_r0_34540 = 0xF & var_r6_34440;
                (*(s8 *)((u8 *)(arg0) + (0x1D))) = temp_r0_34540;
                (*(s8 *)((u8 *)(arg0) + (0x1E))) = (s8) ((*(u8 *)((u8 *)(arg0) + (0x51))) + (*(u8 *)((u8 *)(temp_r2_34439) + (1))));
                temp_r3_34548 = temp_r2_34441 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r3_34548;
                (*(s16 *)((u8 *)(arg0) + (0x22))) = (s16) (*(u8 *)((u8 *)(temp_r2_34441) + (1)));
                temp_r2_34552 = temp_r3_34548 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r2_34552;
                temp_r1_34555 = 1 & temp_r0_34540;
                if (temp_r1_34555 != 0) {
                    (*(s16 *)((u8 *)(arg0) + (0x20))) = (s16) (*(u8 *)((u8 *)(temp_r3_34548) + (1)));
                    (*(void **)((u8 *)(arg0) + (0))) = temp_r2_34552 + 1;
                } else {
                    (*(s16 *)((u8 *)(arg0) + (0x20))) = temp_r1_34555;
                }
                (*(s8 *)((u8 *)(arg0) + (0x1C))) = 1;
                goto loop_67;
            }
            temp_r0_34571 = var_r6_34440 - 0xC2;
            switch (temp_r0_34571) {                /* irregular */
            case 0x3D:
                temp_r1_34649 = (*(void ***)((u8 *)(arg0) + (0x30)));
                if (temp_r1_34649 == (arg0 + 0x24)) {
                    sub_020285B0(arg0);
                    return 2;
                }
                temp_r0_34654 = temp_r1_34649 - 4;
                (*(void ***)((u8 *)(arg0) + (0x30))) = temp_r0_34654;
                (*(void **)((u8 *)(arg0) + (0))) = *temp_r0_34654;
                goto loop_67;
            case 0x26:
                (*(s8 *)((u8 *)(arg0) + (0x1C))) = 0;
                goto loop_67;
            case 0x2E:
                temp_r0_34665 = (*(void **)((u8 *)(arg0) + (0)));
                (*(u8 *)((u8 *)(&sp0) + (0))) = (u8) (*(u8 *)((u8 *)(temp_r0_34665) + (0)));
                temp_r0_34668 = temp_r0_34665 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r0_34668;
                (*(u8 *)((u8 *)(&sp0) + (1))) = (u8) (*(u8 *)((u8 *)(temp_r0_34665) + (1)));
                (*(void **)((u8 *)(arg0) + (0))) = temp_r0_34668 + 1;
                var_r1_34675 = (*(s32 *)((u8 *)(temp_r1_34413) + (4)));
block_38:
                (*(void **)((u8 *)(arg0) + (0))) = var_r1_34675 + (u16) (*(u8 *)((u8 *)(&sp0) + (0)));
                goto loop_67;
            case 0x32:
                temp_r1_34679 = (*(void **)((u8 *)(arg0) + (0)));
                (*(u8 *)((u8 *)(&sp0) + (0))) = (u8) (*(u8 *)((u8 *)(temp_r1_34679) + (0)));
                temp_r1_34682 = temp_r1_34679 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r1_34682;
                (*(u8 *)((u8 *)(&sp0) + (1))) = (u8) (*(u8 *)((u8 *)(temp_r1_34679) + (1)));
                temp_r1_34686 = temp_r1_34682 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r1_34686;
                temp_r0_34688 = (*(void ***)((u8 *)(arg0) + (0x30)));
                *temp_r0_34688 = temp_r1_34686;
                (*(void ***)((u8 *)(arg0) + (0x30))) = (void **) (temp_r0_34688 + 4);
                var_r1_34675 = (*(s32 *)((u8 *)(temp_r1_34413) + (4)));
                goto block_38;
            case 0x0:
                (*(u16 *)((u8 *)(arg0) + (0x42))) = (u16) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
block_56:
                (*(void **)((u8 *)(arg0) + (0))) += 1;
                goto loop_67;
            case 0x5:
                temp_r0_34707 = (*(void **)((u8 *)(arg0) + (0)));
                (*(void **)((u8 *)(arg0) + (0))) = temp_r0_34707 + 1;
                sub_02028A98(arg0, (*(u8 *)((u8 *)(temp_r0_34707) + (0))));
                goto loop_67;
            case 0x1:
                (*(u8 *)((u8 *)(arg0) + (0x4B))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x2:
                (*(u8 *)((u8 *)(arg0) + (0x52))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x1E:
                (*(u8 *)((u8 *)(arg0) + (0x4D))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x1F:
                (*(u8 *)((u8 *)(arg0) + (0x4F))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x20:
                (*(u8 *)((u8 *)(arg0) + (0x50))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x27:
                (*(u8 *)((u8 *)(arg0) + (0x51))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_56;
            case 0x21:
                (*(u8 *)((u8 *)(arg0) + (0x4C))) = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
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
                (*(u8 *)((u8 *)(arg0) + (0x53))) = 1U;
                goto loop_67;
            case 0x7:
                (*(u8 *)((u8 *)(arg0) + (0x53))) = 0U;
                goto loop_67;
            case 0x8:
                temp_r2_34788 = *(s32 (**)(void **, u8))0x03000274;
                if (temp_r2_34788 != NULL) {
                    temp_r0_34791 = (*(void **)((u8 *)(arg0) + (0)));
                    (*(void **)((u8 *)(arg0) + (0))) = temp_r0_34791 + 1;
                    temp_r2_34788(arg0, (*(u8 *)((u8 *)(temp_r0_34791) + (0))));
                } else {
                    goto block_56;
                }
                goto loop_67;
            case 0x22:
                (*(u16 *)((u8 *)(temp_r1_34413) + (0x30))) = (u16) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
block_61:
                (*(void **)((u8 *)(arg0) + (0))) += 1;
                goto loop_67;
            case 0x23:
                (*(s16 *)((u8 *)(arg0) + (0x10))) = (s16) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_61;
            case 0x25:
                (*(s32 *)((u8 *)(arg0) + (0x18))) = (s32) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_61;
            case 0x24:
                (*(s32 *)((u8 *)(arg0) + (0x14))) = (s32) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + (0)))) + (0)));
                goto block_61;
            case 0x36:
                temp_r1_34831 = (*(void **)((u8 *)(arg0) + (0)));
                temp_r1_34833 = temp_r1_34831 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r1_34833;
                (*(u8 *)((u8 *)(&sp0) + (0))) = (u8) (*(u8 *)((u8 *)(temp_r1_34831) + (1)));
                temp_r2_34838 = temp_r1_34833 + 1;
                (*(void **)((u8 *)(arg0) + (0))) = temp_r2_34838;
                (*(u8 *)((u8 *)(&sp0) + (1))) = (u8) (*(u8 *)((u8 *)(temp_r1_34833) + (1)));
                (*(void **)((u8 *)(arg0) + (0))) = temp_r2_34838 + 1;
                temp_r6_34848 = temp_r1_34413 + 8 + ((*(u8 *)((u8 *)(temp_r1_34831) + (0))) * 4);
                temp_r0_34849 = *temp_r6_34848;
                if (temp_r0_34849 == NULL) {
                    var_r4_34853 = sub_020284A0();
                    *temp_r6_34848 = var_r4_34853;
                } else {
                    var_r4_34853 = temp_r0_34849;
                    sub_020285B0(var_r4_34853);
                }
                sub_020284C4(var_r4_34853, temp_r1_34413, (*(s32 *)((u8 *)(temp_r1_34413) + (4))) + (u16) (*(u8 *)((u8 *)(&sp0) + (0))));
                (*(s32 *)((u8 *)(var_r4_34853) + (4))) = (s32) (*(s32 *)((u8 *)(arg0) + (4)));
                (*(u16 *)((u8 *)(var_r4_34853) + (0x40))) = (u16) (*(u16 *)((u8 *)(arg0) + (0x40)));
                (*(u16 *)((u8 *)(var_r4_34853) + (0x42))) = (u16) (*(u16 *)((u8 *)(arg0) + (0x42)));
                (*(u8 *)((u8 *)((var_r4_34853 + 0x42)) + (9))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x4B)));
                (*(u8 *)((u8 *)(var_r4_34853) + (0x4C))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x4C)));
                temp_r1_34896 = var_r4_34853 + 0x4D;
                (*(u8 *)((u8 *)(var_r4_34853) + (0x4D))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x4D)));
                temp_r1_34901 = temp_r1_34896 + 1;
                (*(u8 *)((u8 *)(temp_r1_34896) + (1))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x4E)));
                (*(u8 *)((u8 *)(temp_r1_34901) + (4))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x52)));
                *(u32 *)((temp_r1_34901 + 4) - 3) = (*(u8 *)((u8 *)(arg0) + (0x4F)));
                (*(u8 *)((u8 *)(var_r4_34853) + (0x50))) = (u8) (*(u8 *)((u8 *)(arg0) + (0x50)));
                var_r1_34766 = (*(u8 *)((u8 *)(arg0) + (0x51)));
                var_r0_34772 = var_r4_34853 + 0x51;
                goto block_66;
            }
        } else {
            temp_r0_34934 = temp_r1_34927 - (*(u16 *)((u8 *)(temp_r1_34413) + (0x30)));
            (*(s32 *)((u8 *)(arg0) + (0x34))) = temp_r0_34934;
            (*(s32 *)((u8 *)(arg0) + (0x34))) = (s32) (temp_r0_34934 - (*(s16 *)((u8 *)(temp_r1_34413) + (0x32))));
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

    temp_r2_34953 = (*(void ***)((u8 *)(arg1) + (4)));
    if (temp_r2_34953 == NULL) {
        (*(void ***)((u8 *)(arg1) + (4))) = arg0;
        (*(void ***)((u8 *)(arg1) + (0x74))) = temp_r2_34953;
        temp_r2_34958 = (*(u8 **)((u8 *)(arg0) + (0xC)));
        (*(u8 **)((u8 *)(arg1) + (0x78))) = temp_r2_34958;
        (*(u8 **)((u8 *)(arg0) + (0xC))) = arg1;
        if (temp_r2_34958 != NULL) {
            (*(u8 **)((u8 *)(temp_r2_34958) + (0x74))) = arg1;
        }
    }
}

void sub_02028A4C(void *arg0, u8 *arg1) {
    void *temp_r2_34975;
    void *temp_r2_34981;

    if ((*(s32 *)((u8 *)(arg1) + (4))) != 0) {
        (*(s32 *)((u8 *)(arg1) + (4))) = 0;
        temp_r2_34975 = (*(void **)((u8 *)(arg1) + (0x78)));
        if (temp_r2_34975 != NULL) {
            (*(void **)((u8 *)(temp_r2_34975) + (0x74))) = (void *) (*(void **)((u8 *)(arg1) + (0x74)));
        }
        temp_r2_34981 = (*(void **)((u8 *)(arg1) + (0x74)));
        if (temp_r2_34981 != NULL) {
            (*(void **)((u8 *)(temp_r2_34981) + (0x78))) = (void *) (*(void **)((u8 *)(arg1) + (0x78)));
            return;
        }
        (*(void **)((u8 *)(arg0) + (0xC))) = (void *) (*(void **)((u8 *)(arg1) + (0x78)));
    }
}

u16 sub_02028A74(void **arg0) {
    u8 var_r1_34997;
    void *temp_r2_34996;
    void *temp_r2_34998;

    temp_r2_34996 = *arg0;
    var_r1_34997 = (*(u8 *)((u8 *)(temp_r2_34996) + (0)));
    temp_r2_34998 = temp_r2_34996 + 1;
    *arg0 = temp_r2_34998;
    if (0x80 & var_r1_34997) {
        var_r1_34997 = ((var_r1_34997 & 0x7F) << 8) | (*(u8 *)((u8 *)(temp_r2_34996) + (1)));
        *arg0 = temp_r2_34998 + 1;
    }
    return (u16) var_r1_34997;
}

void sub_02028A98(void **arg0, s16 arg1) {
    s32 temp_r1_35034;
    void *temp_r2_35024;

    (*(s16 *)((u8 *)(arg0) + (0x40))) = arg1;
    (*(s16 *)((u8 *)((arg0 + 0x40)) + (2))) = 0;
    temp_r2_35024 = *(void **)0x03000594;
    temp_r1_35034 = (*(s32 *)((u8 *)(temp_r2_35024) + (0)));
    (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (temp_r1_35034 + *(u32 *)((*(u32 *)((*(u32 *)((arg1 * 2) + *(*(s32 **)((u8 *)(arg0) + (8)))) * 2) + (*(s32 *)((u8 *)(temp_r2_35024) + (0x10)))) * 4) + temp_r1_35034));
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
    (*(s16 *)((u8 *)(temp_r2_35123) + (0))) = 0;
    (*(s32 *)((u8 *)(temp_r2_35123) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35123) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r3_35153) + (0))) = 1;
    (*(s32 *)((u8 *)(temp_r3_35153) + (4))) = (s32) ((arg0 << 0x10) | arg1);
    (*(s32 *)((u8 *)(temp_r3_35153) + (8))) = (s32) arg2;
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
    (*(s16 *)((u8 *)(temp_r2_35185) + (0))) = 2;
    (*(s32 *)((u8 *)(temp_r2_35185) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35185) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35215) + (0))) = 3;
    (*(s32 *)((u8 *)(temp_r2_35215) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35215) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35243) + (0))) = 4;
    (*(s32 *)((u8 *)(temp_r2_35243) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35243) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35275) + (0))) = 5;
    (*(s32 *)((u8 *)(temp_r2_35275) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35275) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35305) + (0))) = 6;
    (*(s32 *)((u8 *)(temp_r2_35305) + (4))) = (s32) arg0;
    (*(s32 *)((u8 *)(temp_r2_35305) + (8))) = (s32) arg1;
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
    (*(s16 *)((u8 *)(temp_r3_35333) + (0))) = 7;
    (*(s32 *)((u8 *)(temp_r3_35333) + (4))) = (s32) ((arg0 << 0x10) | arg2);
    (*(s32 *)((u8 *)(temp_r3_35333) + (8))) = arg1;
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
    (*(s16 *)((u8 *)(temp_r3_35363) + (0))) = 9;
    (*(s32 *)((u8 *)(temp_r3_35363) + (4))) = (s32) ((arg0 << 0x10) | arg2);
    (*(s32 *)((u8 *)(temp_r3_35363) + (8))) = arg1;
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
    (*(s16 *)((u8 *)(temp_r3_35393) + (0))) = 8;
    (*(s32 *)((u8 *)(temp_r3_35393) + (4))) = (s32) ((arg0 << 0x10) | arg2);
    (*(s32 *)((u8 *)(temp_r3_35393) + (8))) = arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35422) + (0))) = 0xA;
    (*(s32 *)((u8 *)(temp_r2_35422) + (4))) = (s32) arg0;
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
    (*(s16 *)((u8 *)(temp_r2_35445) + (0))) = 0xB;
    (*(s32 *)((u8 *)(temp_r2_35445) + (4))) = arg0;
    (*(s32 *)((u8 *)(temp_r2_35445) + (8))) = arg1;
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
    (*(s16 *)((u8 *)(temp_r2_35470) + (0))) = 0xC;
    (*(void (**)(void *, u8))((u8 *)(temp_r2_35470) + (4))) = arg0;
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
    (*(s16 *)((u8 *)(temp_r2_35492) + (0))) = 0xD;
    (*(void (**)(void **, u8, u8, u16))((u8 *)(temp_r2_35492) + (4))) = arg0;
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
        temp_r0_35516 = (*(u16 *)((u8 *)(temp_r0_35733) + (0)));
        switch ((u32) temp_r0_35516) {              /* irregular */
        case 0:
            sub_0202828C((*(s32 *)((u8 *)(temp_r0_35733) + (4))), (*(u32 *)((u8 *)(temp_r0_35733) + (8))));
            break;
        case 1:
            temp_r1_35549 = (*(s32 *)((u8 *)(temp_r0_35733) + (4)));
            sub_020282B4((s32) ((u32) temp_r1_35549 >> 0x10), (u16) temp_r1_35549, (*(u32 *)((u8 *)(temp_r0_35733) + (8))));
            break;
        case 2:
            sub_02028410((*(s32 *)((u8 *)(temp_r0_35733) + (4))), (s16) (*(u32 *)((u8 *)(temp_r0_35733) + (8))));
            break;
        case 3:
            sub_02028448((*(s32 *)((u8 *)(temp_r0_35733) + (4))), (u8) (*(u32 *)((u8 *)(temp_r0_35733) + (8))));
            break;
        case 6:
            var_r0_35573 = (*(s32 *)((u8 *)(temp_r0_35733) + (4))) * 0x44;
            var_r2_35574 = 0x0300195B;
block_11:
            *(u32 *)(var_r0_35573 + var_r2_35574) = (s8) (*(u32 *)((u8 *)(temp_r0_35733) + (8)));
            break;
        case 4:
            temp_r0_35584 = ((*(s32 *)((u8 *)(temp_r0_35733) + (4))) * 0x44) + 0x03001918;
            temp_r1_35585 = (*(u32 *)((u8 *)(temp_r0_35733) + (8)));
            (*(s8 *)((u8 *)(temp_r0_35584) + (0x32))) = (s8) temp_r1_35585;
            (*(s8 *)((u8 *)(temp_r0_35584) + (0x33))) = (s8) (temp_r1_35585 >> 8);
            break;
        case 5:
            var_r0_35573 = (*(s32 *)((u8 *)(temp_r0_35733) + (4))) * 0x44;
            var_r2_35574 = 0x03001958;
            goto block_11;
        case 7:
            if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) != 0) {
                var_r2_35621 = ((*(u16 *)((u8 *)(temp_r0_35733) + (6))) * 0x44) + 0x03001918 + 8;
                do {
                    if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) & 1) {
                        temp_r0_35627 = *var_r2_35621;
                        if (temp_r0_35627 != NULL) {
                            (*(s8 *)((u8 *)(temp_r0_35627) + (0x4A))) = (s8) (*(s32 *)((u8 *)(temp_r0_35733) + (4)));
                        }
                    }
                    var_r2_35621 += 4;
                    temp_r0_35636 = (u32) (*(u32 *)((u8 *)(temp_r0_35733) + (8))) >> 1;
                    (*(u32 *)((u8 *)(temp_r0_35733) + (8))) = temp_r0_35636;
                } while (temp_r0_35636 != 0);
            }
            break;
        case 9:
            if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) != 0) {
                var_r2_35655 = ((*(u16 *)((u8 *)(temp_r0_35733) + (6))) * 0x44) + 0x03001918 + 8;
                do {
                    if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) & 1) {
                        temp_r0_35661 = *var_r2_35655;
                        if (temp_r0_35661 != NULL) {
                            (*(s8 *)((u8 *)(temp_r0_35661) + (0x4E))) = (s8) (*(s32 *)((u8 *)(temp_r0_35733) + (4)));
                        }
                    }
                    var_r2_35655 += 4;
                    temp_r0_35670 = (u32) (*(u32 *)((u8 *)(temp_r0_35733) + (8))) >> 1;
                    (*(u32 *)((u8 *)(temp_r0_35733) + (8))) = temp_r0_35670;
                } while (temp_r0_35670 != 0);
            }
            break;
        case 8:
            if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) != 0) {
                var_r2_35689 = ((*(u16 *)((u8 *)(temp_r0_35733) + (6))) * 0x44) + 0x03001918 + 8;
                do {
                    if ((*(u32 *)((u8 *)(temp_r0_35733) + (8))) & 1) {
                        temp_r0_35695 = *var_r2_35689;
                        if (temp_r0_35695 != NULL) {
                            (*(s8 *)((u8 *)(temp_r0_35695) + (0x4B))) = (s8) (*(s32 *)((u8 *)(temp_r0_35733) + (4)));
                        }
                    }
                    var_r2_35689 += 4;
                    temp_r0_35704 = (u32) (*(u32 *)((u8 *)(temp_r0_35733) + (8))) >> 1;
                    (*(u32 *)((u8 *)(temp_r0_35733) + (8))) = temp_r0_35704;
                } while (temp_r0_35704 != 0);
            }
            break;
        case 11:
            ((s32 (*)(u32)) (*(s32 *)((u8 *)(temp_r0_35733) + (4))))((*(u32 *)((u8 *)(temp_r0_35733) + (8))));
            break;
        case 12:
            var_r1_35717 = (s32 *)0x03000274;
block_36:
            *var_r1_35717 = (*(s32 *)((u8 *)(temp_r0_35733) + (4)));
            break;
        case 13:
            var_r1_35717 = (s32 *)0x03000270;
            goto block_36;
        case 10:
            sub_02027370((u8) (*(s32 *)((u8 *)(temp_r0_35733) + (4))));
            break;
        }
        goto loop_38;
    }
}

/* ARM-state mixer routines copied to IWRAM by sub_02026E4C. */
asm(".include \"asm/all_arm.inc\"");

/* AGB BIOS wrappers kept in assembly so their SWI sequences remain exact. */
asm(".include \"asm/gflib/syscalls.inc\"");
