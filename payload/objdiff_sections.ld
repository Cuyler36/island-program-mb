/* Objdiff-only relocatable layout.  Keep recovered payload data and BSS at
 * section-relative offsets so they compare directly with the generated target. */
SECTIONS
{
    .text 0 :
    {
        *(.text)
    }

    .data 0 :
    {
        *interrupt.o(.data)
        *m_msg.o(.data)
        *lib.o(.data)
        *lib.o(.rodata)
        *joyboot.o(.data)
        *island_program.o(.data)
        *m_msg_sprite.o(.data)
        *multisio.o(.data)
        *island_field.o(.data)
        *building.o(.data)
        *animated_field_obj.o(.data)
        *field_obj.o(.data)
        *islander.o(.data)
        *item.o(.data)
        *falling_fruit.o(.data)
        *entity.o(.data)
        *player_hand.o(.data)
        *time_palette.o(.data)
        *msg_data.o(.data)
        *world_pal.o(.data)
        *sound.o(.data)
        *sound_data.o(.data)
        *data.o(.data)
    }

    .rodata 0 :
    {
        *(.rodata)
    }

    .bss 0 (NOLOAD) :
    {
        *main.o(.bss)
        . = 0x10;
        *m_msg.o(.bss)
        . = 0x20;
        *islander.o(.bss)
        *sound.o(.bss)

        . = 0x1B40;
        gIslandData = .;
        . = 0x1B50;
        gGameState = .;
        . = 0x23C0;
        gIntrTable = .;
        . = 0x2400;
        gIslandLandInfo = .;
        . = 0x2410;
        GameOAMData = .;
        . = 0x2810;
        gFontGlyphBlitterCode = .;
        . = 0x2970;
        gIslandTransferData = .;
        . = 0x2980;
        gMsgWindowNotice = .;
        . = 0x2A20;
        sMsgWindows = .;
        . = 0x2FC0;
        gMsgWindowMain = .;
        . = 0x3060;
        gMsgWindowPrompt = .;
        . = 0x3100;
        gMsgGlyph = .;
        . = 0x3120;
        gTransWork = .;
        . = 0x3160;
        sBssPadding_03003160 = .;
        . = 0x3710;
        gIslandFieldWork = .;
        . = 0x3BB0;
        gIslandBuildings = .;
        . = 0x3BD8;
        sBssPadding_03003BD8 = .;
        . = 0x3C00;
        gFieldObjects = .;
        . = 0x41A0;
        gIslander = .;
        . = 0x4260;
        gFallingFruit = .;
        . = 0x4788;
        sBssPadding_03004788 = .;
        . = 0x4790;
        g_EntityTable = .;
        . = 0x4B80;
        gPlayer = .;
        . = 0x4BAC;
        *data.o(COMMON)
    }
}
