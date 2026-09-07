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


# Boundaries include the ARM mixers in sound.c and keep the BIOS wrappers in
# their own object, matching the order in payload/ld_script.txt.
UNIT_STARTS = (("all", "AgbMain"), ("sound", "Audio_Init"), ("syscalls", "ArcTan2"))
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


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--assembly", type=Path, default=Path("payload/asm/all.s"))
    parser.add_argument("--unit", choices=[unit for unit, _ in UNIT_STARTS], required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    preamble, bodies = split_text(args.assembly.read_text())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(preamble + bodies[args.unit])
    print(f"Generated {args.output}: {args.unit} translation unit")


if __name__ == "__main__":
    main()
