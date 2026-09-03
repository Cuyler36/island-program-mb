#!/usr/bin/env python3
"""Import generated m2c function bodies into payload/src/all.c."""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path


START_MARKER = "/* Initial m2c reconstructions after sub_02019E88. */"

# Non-project functions are provided by BIOS-wrapper and runtime objects.
ASM_ONLY_FUNCTIONS = {
    "ArcTan2",
    "CpuFastSet",
    "CpuSet",
    "ObjAffineSet",
    "RegisterRamReset",
    "SoundBiasReset",
    "SoundBiasSet",
    "_call_via_r0",
    "_call_via_r1",
    "_call_via_r2",
    "_call_via_r3",
    "_call_via_r4",
    "_call_via_r5",
    "_call_via_r6",
    "_call_via_r7",
    "_call_via_r8",
    "_call_via_r9",
    "_call_via_sl",
    "_call_via_fp",
    "_call_via_ip",
    "_call_via_sp",
    "_call_via_lr",
    "__divsi3",
    "__div0",
    "__modsi3",
    "__udivsi3",
    "__umodsi3",
    "memcpy",
    "memset",
}

FUNCTION_START_RE = re.compile(r"^(?P<signature>\S.*\)) \{$")
FUNCTION_NAME_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")


@dataclass(frozen=True, slots=True)
class Function:
    name: str
    signature: str
    body: str


def extract_functions(source: str) -> list[Function]:
    lines = source.splitlines()
    functions: list[Function] = []
    index = 0
    while index < len(lines):
        match = FUNCTION_START_RE.match(lines[index])
        if match is None:
            index += 1
            continue

        signature = match.group("signature")
        names = FUNCTION_NAME_RE.findall(signature)
        if not names:
            raise ValueError(f"could not parse function signature: {signature}")
        name = names[0]
        start = index
        depth = lines[index].count("{") - lines[index].count("}")
        index += 1
        while depth > 0 and index < len(lines):
            depth += lines[index].count("{") - lines[index].count("}")
            index += 1
        if depth != 0:
            raise ValueError(f"unterminated function body: {name}")
        functions.append(
            Function(name=name, signature=signature, body="\n".join(lines[start:index]))
        )
    return functions


def apply_known_fixes(function: Function) -> Function:
    return function


def build_argument_parser() -> argparse.ArgumentParser:
    root = Path(__file__).resolve().parents[1]
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--m2c",
        type=Path,
        default=root / "payload" / "build" / "m2c" / "all_remaining.valid.c",
    )
    parser.add_argument(
        "--base", type=Path, default=root / "payload" / "src" / "all.c"
    )
    parser.add_argument("--output", type=Path)
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    output_path = args.output or args.base
    functions = [
        apply_known_fixes(function)
        for function in extract_functions(args.m2c.read_text(encoding="utf-8"))
        if function.name not in ASM_ONLY_FUNCTIONS
    ]
    if len(functions) != 452:
        raise SystemExit(f"expected 452 C functions, found {len(functions)}")
    names = [function.name for function in functions]
    if len(names) != len(set(names)):
        raise SystemExit("m2c output contains duplicate function definitions")

    base = args.base.read_text(encoding="utf-8")
    if START_MARKER in base:
        base = base.split(START_MARKER, 1)[0].rstrip()
    prototypes = "\n".join(f"{function.signature};" for function in functions)
    bodies = "\n\n".join(function.body for function in functions)
    result = (
        f"{base}\n\n{START_MARKER}\n\n"
        "#if 0\n"
        "/* These bodies require field typing before they can enter the build. */\n\n"
        "/* Forward declarations retain m2c's current inferred signatures. */\n"
        f"{prototypes}\n\n{bodies}\n"
        "#endif\n"
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(result, encoding="utf-8", newline="\n")
    print(f"Imported {len(functions)} functions into {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
