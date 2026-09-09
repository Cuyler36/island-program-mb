This repository builds one of the Animal Crossing Multiboot images which comes compressed within the GameCube Animal Crossing entry. This is done to assist in [the decompilation of the overall game](https://github.com/Prakxo/ac-decomp/).

Requires agbcc.  Need to install it like the Pokémon Decompilations, i.e.:

```
git clone https://github.com/pret/agbcc.git
cd agbcc
./build.sh
./install.sh path/to/island_loader_mb
```

It builds the following image:

    19066f9b168dc10581206faaf32b3a1e72e584b7  island-program-mb.gba

## Ninja build

After installing agbcc and devkitARM, generate the build graph and build the
ROM:

```sh
python configure.py
ninja
```

If Ninja was installed as a Python package but is not on `PATH`, use
`python -m ninja` for the second command.

`configure.py` accepts `--devkitarm PATH` when devkitARM is not installed at
its default location. Optional build modes are `--nonmatching`, `--debug-test`,
and `--debug-testing`; rerun the configure command when switching modes.

`--debug-test` requires the user-owned
`assets/debug/test_island_agb_fmt.bin` fixture. Builds never regenerate that
file. To construct it from a GameCube island plus an AGB-sized resource donor,
run `tools/convert_gc_island_fixture.py` explicitly with `--resources-from`.

Useful targets include `payload`, `rom`, and `objdiff_targets`. The Makefiles
remain available as a fallback during the transition.

Objdiff units include each translation unit's recovered `.data`, `.rodata`, and
`.bss` alongside its code. Data-only units appear in final payload order;
`payload/data_all` remains available for an aggregate data/BSS layout check.
