#ifdef DEBUG_TESTING
    .section .debug_graphics,"a",%progbits
    .balign 4

/* Original address: 0x02021A30 (island loader) */
    .global sDebugObjTiles
    .type sDebugObjTiles, %object
sDebugObjTiles:
    .incbin "assets/debug/debug_obj_tiles.bin"
    .size sDebugObjTiles, . - sDebugObjTiles

/* Original address: 0x02029A30 (island loader) */
    .global sDebugBgTiles
    .type sDebugBgTiles, %object
sDebugBgTiles:
    .incbin "assets/debug/debug_bg_tiles.bin"
    .size sDebugBgTiles, . - sDebugBgTiles

/* Original address: 0x0201F1E0 (island loader) */
    .global sDebugBg3Tilemap
    .type sDebugBg3Tilemap, %object
sDebugBg3Tilemap:
    .incbin "assets/debug/debug_bg3_tilemap.bin"
    .size sDebugBg3Tilemap, . - sDebugBg3Tilemap

/* Original address: 0x0201D1E0 (island loader) */
    .global sDebugBg2Tilemap
    .type sDebugBg2Tilemap, %object
sDebugBg2Tilemap:
    .incbin "assets/debug/debug_bg2_tilemap.bin"
    .size sDebugBg2Tilemap, . - sDebugBg2Tilemap

/* Original address: 0x02031C30 (island loader) */
    .global sDebugBg1Tilemap
    .type sDebugBg1Tilemap, %object
sDebugBg1Tilemap:
    .incbin "assets/debug/debug_bg1_tilemap.bin"
    .size sDebugBg1Tilemap, . - sDebugBg1Tilemap

/* Original address: 0x0201B1E0 (island loader) */
    .global sDebugBg0Tilemap
    .type sDebugBg0Tilemap, %object
sDebugBg0Tilemap:
    .incbin "assets/debug/debug_bg0_tilemap.bin"
    .size sDebugBg0Tilemap, . - sDebugBg0Tilemap
#endif
