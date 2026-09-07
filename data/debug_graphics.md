The debug tile banks are extracted verbatim from the US GameCube asset
`aBTD_island_ldr.bin`. Decompress its GBA LZ77 stream at file offset `0x168`,
then extract these ranges from the decompressed payload:

Store the binaries in `assets/debug/`. This folder also holds the local
`test_island_gc_fmt.bin` and `test_island_agb_fmt.bin` fixtures. All `.bin`
files in this folder are ignored by Git; `.gitkeep` preserves the directory.
Normal builds do not require these local assets.

| File | Offset | Size | Original loader address | VRAM destination |
| --- | --- | --- | --- | --- |
| debug_obj_tiles.bin | 0x9A30 | 0x8000 | 0x02021A30 | 0x06010000 |
| debug_bg_tiles.bin | 0x11A30 | 0x8000 | 0x02029A30 | 0x06000000 |
| debug_bg3_tilemap.bin | 0x71E0 | 0x2000 | 0x0201F1E0 | 0x06008000 |
| debug_bg2_tilemap.bin | 0x51E0 | 0x2000 | 0x0201D1E0 | 0x0600A000 |
| debug_bg1_tilemap.bin | 0x19C30 | 0x2000 | 0x02031C30 | 0x0600C000 |
| debug_bg0_tilemap.bin | 0x31E0 | 0x2000 | 0x0201B1E0 | 0x0600E000 |

`debug_graphics.s` emits the banks only with `DEBUG_TESTING` defined.
`make DEBUG_TEST=1` includes the island fixture and enables these graphics.
`make DEBUG_TESTING=1` enables just the graphics setup, independently of the
island fixture. Both options default to off.

For standalone cartridge testing, the outer ROM stores OBJ at file offset
`0x40000` and BG at `0x48000`. The four tilemap banks follow at `0x50000`,
`0x52000`, `0x54000`, and `0x56000`, in BG3/BG2/BG1/BG0 order.
The payload reads the pixel banks at cartridge addresses
`0x08040000` and `0x08048000`; these must stay synchronized between the two
linker scripts. This debug path requires cartridge ROM mapping and is not a
replacement for the original multiboot loader.
The debug startup wrapper therefore reads the compressed program through its
cartridge address (`0x08000168`), while normal multiboot startup continues to
read it from EWRAM (`0x02000168`).

`DebugTesting_SetupGraphics` reproduces the loader's two 32 KiB pixel uploads
and four 8 KiB tilemap uploads before `InitializeIsland` overlays the earth
and NPC textures. The program rebuilds the playable field's maps, but depends
on the loader's maps for the initial overview. Normal builds
emit neither the setup function nor the banks.
