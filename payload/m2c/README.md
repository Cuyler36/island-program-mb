# m2c working output

`all_02018D10_02019E88.c` is generated pseudocode for the inclusive target
assembly range from `sub_02018D10` through `sub_02019E88`. It is reference
material for reconstruction in `src/all.c`, not a source file used by the
payload build.

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
