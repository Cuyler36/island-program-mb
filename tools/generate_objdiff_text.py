#!/usr/bin/env python3
"""Split the original assembly into objdiff targets matching the source TUs.

The canonical assembly stays untouched. Each generated file retains its original
instructions, literal pools, alignment and function macros, with the shared
assembler preamble. Assemble from the payload directory, just like asm/all.s.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path


# Keep this in the same order as the .text inputs in payload/ld_script.txt.
UNIT_STARTS = (
    ("main", "AgbMain"),
    ("interrupt", "UnusedInterruptHandler"),
    ("m_msg", "mFont_GetGlyphRows"),
    ("lib", "FixedMul8"),
    ("audio", "GameAudio_VBlank"),
    ("m_msg_util", "mMsg_ReplaceChar"),
    ("game", "InitializeHardware"),
    ("joyboot", "Swap32"),
    ("island_program", "IslandProgram_Restart"),
    ("m_msg_sprite", "mMsg_InitSprites"),
    ("multisio", "InitIslandLinkTransfer"),
    ("island_field", "LoadIslandBuildingTiles"),
    ("building", "InitIslandBuilding"),
    ("animated_field_obj", "AnimatedFieldObject_Init"),
    ("field_obj", "FieldObject_AttachEntity"),
    ("islander", "Islander_StoreItem"),
    ("item", "Item_IsFossil"),
    ("falling_fruit", "FallingFruit_Init"),
    ("entity", "Entity_Reset"),
    ("player_hand", "PlayerHand_IsItemPlacementBlocked"),
    ("sound", "Audio_Init"),
    ("syscalls", "ArcTan2"),
)

# These two functions were intentionally renamed when game.c was extracted.
# Rename target symbols and references only in generated objdiff assembly.
SYMBOL_RENAMES = {
    "IslandProgram_UpdateFrame": "Game_Update",
    "IslandProgram_Main": "Game_Main",
}
FUNCTION_START = re.compile(
    r"^[ \t]*(?:thumb|arm|non_word_aligned_thumb)_func_start[ \t]+(\w+)[ \t]*$",
    re.MULTILINE,
)


def split_text(source: str) -> tuple[str, dict[str, str]]:
    """Return the shared preamble and contiguous, non-overlapping TU bodies."""
    starts = {}
    for match in FUNCTION_START.finditer(source):
        name = match.group(1)
        if name in starts:
            raise ValueError(f"duplicate function start: {name}")
        starts[name] = match.start()
    boundaries = []
    for unit, name in UNIT_STARTS:
        if name not in starts:
            raise ValueError(f"missing start of {unit} TU: {name}")
        boundaries.append(starts[name])
    if boundaries != sorted(boundaries) or boundaries[0] != min(starts.values()):
        raise ValueError("translation-unit boundaries are not in assembly order")
    ends = boundaries[1:] + [len(source)]
    bodies = {unit: source[start:end]
              for (unit, _), start, end in zip(UNIT_STARTS, boundaries, ends)}
    return source[:boundaries[0]], bodies


def apply_symbol_renames(source: str) -> str:
    for old, new in SYMBOL_RENAMES.items():
        source = re.sub(rf"\b{re.escape(old)}\b", new, source)
    return source


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--assembly", type=Path, default=Path("payload/asm/all.s"))
    parser.add_argument("--unit", choices=[unit for unit, _ in UNIT_STARTS], required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    preamble, bodies = split_text(args.assembly.read_text())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(apply_symbol_renames(preamble + bodies[args.unit]))
    print(f"Generated {args.output}: {args.unit} translation unit")


if __name__ == "__main__":
    main()
