/* Rebase data.c's recovered COMMON allocation to a TU-local .bss section. */
SECTIONS
{
    .bss 0 (NOLOAD) :
    {
        gIslandData = .;
        . = 0x10;
        gGameState = .;
        . = 0x880;
        gIntrTable = .;
        . = 0x8C0;
        gIslandLandInfo = .;
        . = 0x8D0;
        GameOAMData = .;
        . = 0xCD0;
        gFontGlyphBlitterCode = .;
        . = 0xE30;
        gIslandTransferData = .;
        . = 0xE40;
        gMsgWindowNotice = .;
        . = 0xEE0;
        sMsgWindows = .;
        . = 0x1480;
        gMsgWindowMain = .;
        . = 0x1520;
        gMsgWindowPrompt = .;
        . = 0x15C0;
        gMsgGlyph = .;
        . = 0x15E0;
        gTransWork = .;
        . = 0x1620;
        sBssPadding_03003160 = .;
        . = 0x1BD0;
        gIslandFieldWork = .;
        . = 0x2070;
        gIslandBuildings = .;
        . = 0x2098;
        sBssPadding_03003BD8 = .;
        . = 0x20C0;
        gFieldObjects = .;
        . = 0x2660;
        gIslander = .;
        . = 0x2720;
        gFallingFruit = .;
        . = 0x2C48;
        sBssPadding_03004788 = .;
        . = 0x2C50;
        g_EntityTable = .;
        . = 0x3040;
        gPlayer = .;
        . = 0x306C;
        *data.o(COMMON)
    }
}
