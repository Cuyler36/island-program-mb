# m2c working output

Generated pseudocode is staging material for reconstruction in `src/all.c`,
not a source file used by the payload build. Generated files should be written
under `payload/build/m2c` so they remain untracked.

The generator uses the GBA/APCS target, processes the entire range together
for cross-function inference, and combines the preprocessed project headers
with `tools/m2c_range_context.c`.

Set up and regenerate from the repository root:

```powershell
git clone https://github.com/matt-kempster/m2c.git .cache/m2c
git -C .cache/m2c checkout a73bfba20a00db8a546ec84d6ebec76063ebcf60
python -B tools\generate_m2c.py
```

The generated assembly/context cache is kept under `payload/build/m2c` and is
ignored by Git.

Pass `--stack-structs` when stack-layout templates are useful for a difficult
function; they are omitted from the normal combined output for readability.

The initial reconstruction of every function after `sub_02019E88` was made
with:

```powershell
python -B tools\generate_m2c.py `
  --start sub_02019F08 --end sub_02028E38 `
  --output payload\build\m2c\all_remaining.valid.c `
  --valid-syntax
python -B tools\import_m2c.py `
  --m2c payload\build\m2c\all_remaining.valid.c
```

`generate_m2c.py` corrects the confirmed jump-table labels inside
`sub_02025210` in its generated assembly only. The range ends before the BIOS
wrappers and the separately split libgcc/libc objects. The ARM-state routines
`sub_02029004`, `sub_020290C4`, and `sub_020291E4` remain in `asm/all.s` because
this m2c workflow processes Thumb functions. The imported bodies are kept
behind `#if 0` until their `M2C_FIELD` accesses and unknown stack arguments
have been assigned real types.
