#!/usr/bin/env python3
"""Generate typed m2c output for an inclusive function range in payload/all.s."""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path


DEFAULT_START = "mMsg_CheckChoiceNext"
DEFAULT_END = "sub_02019E88"
TESTED_M2C_COMMIT = "a73bfba20a00db8a546ec84d6ebec76063ebcf60"

# Symbolizing known absolute addresses prevents m2c from folding typed globals
# back into raw pointer arithmetic.  The transformed assembly lives in build/.
ADDRESS_SYMBOLS = {
    "0x02000200": "gObjPaletteBuffer",
    "0x02029698": "gIntrTableTemplate",
    "0x0202A8E0": "INT_ARRAY_0202a8e0",
    "0x0202AAC8": "gMsgTwoChoiceHighlightTiles",
    "0x0202AAD0": "gMsgThreeChoiceHighlightTiles",
    "0x0202AADC": "gMsgModeSetupCallbacks",
    "0x0202AB00": "gMsgModeCallbacks",
    "0x0202AB24": "gMsgWindowScrollOffsets",
    "0x0202AB54": "sMsgControlCodeInfo",
    "0x0202AD18": "gMsgChoiceTemplateParams",
    "0x0202AD1C": "gUnk_0202AD1C",
    "0x0202AD28": "gUnk_0202AD28",
    "0x0202AFB4": "gUnk_0202AFB4",
    "0x02034FA4": "gMsgTextData",
    "0x02035774": "sMsgOffsetsBase",
    "0x02035778": "sMsgOffsets",
    "0x02000400": "gMsgCodeBuffers",
    "0x02001D80": "gMsgTileBuffers",
    "0x0200F580": "gMsgWindowTileData",
    "0x03001B50": "gGameState",
    "0x030023C0": "gIntrTable",
    "0x03002410": "gUnk3002410",
    "0x03002A20": "sMsgWindows",
    "0x03002A70": "sMsgWindows + 0x50",
    "0x03002A74": "sMsgWindows + 0x54",
    "0x03003100": "gMsgGlyph",
    "0x03007FFC": "gIntrMain",
    "0x040000D4": "REG_DMA3",
    "0x04000130": "REG_KEYINPUT",
    "0x04000200": "REG_IRQ",
    "0x04000204": "REG_WAITCNT",
    "0x04000208": "REG_IME",
    "0x06002000": "gMsgVram",
}

FUNCTION_START_RE = re.compile(r"^\s*thumb_func_start\s+(\S+)\s*$")


def parse_args() -> argparse.Namespace:
    root = Path(__file__).resolve().parents[1]
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--start", default=DEFAULT_START)
    parser.add_argument("--end", default=DEFAULT_END)
    parser.add_argument("--passes", type=int, default=4)
    parser.add_argument(
        "--stack-structs",
        action="store_true",
        help="Include m2c's inferred stack-layout templates in the output",
    )
    parser.add_argument("--m2c-dir", type=Path, default=root / ".cache" / "m2c")
    parser.add_argument(
        "--output",
        type=Path,
        default=root / "payload" / "m2c" / "all_02018D10_02019E88.c",
    )
    parser.add_argument(
        "--skip-context-build",
        action="store_true",
        help="Use the existing preprocessed all.i without rebuilding it first",
    )
    return parser.parse_args()


def select_functions(assembly: str, start: str, end: str) -> list[str]:
    functions = [
        match.group(1)
        for line in assembly.splitlines()
        if (match := FUNCTION_START_RE.match(line))
    ]
    try:
        start_index = functions.index(start)
        end_index = functions.index(end)
    except ValueError as error:
        raise SystemExit(f"function not found in payload/asm/all.s: {error}") from error
    if start_index > end_index:
        raise SystemExit(f"start function {start} occurs after end function {end}")
    return functions[start_index : end_index + 1]


def symbolize_assembly(assembly: str) -> str:
    for address, symbol in ADDRESS_SYMBOLS.items():
        assembly = re.sub(
            rf"(?m)^(\s*[^@\n]*\.4byte\s+){re.escape(address)}(\s*)$",
            rf"\1{symbol}\2",
            assembly,
        )
    return assembly


def get_m2c_commit(m2c_dir: Path) -> str:
    result = subprocess.run(
        ["git", "-C", str(m2c_dir), "rev-parse", "HEAD"],
        check=False,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip() if result.returncode == 0 else "unknown"


def main() -> int:
    args = parse_args()
    root = Path(__file__).resolve().parents[1]
    assembly_path = root / "payload" / "asm" / "all.s"
    context_path = root / "payload" / "build" / "payload" / "src" / "all.i"
    extra_context_path = root / "tools" / "m2c_range_context.c"
    typed_assembly_path = root / "payload" / "build" / "m2c" / "all.typed.s"
    m2c_path = args.m2c_dir.resolve() / "m2c.py"
    output_path = args.output.resolve()

    if not m2c_path.is_file():
        raise SystemExit(
            f"m2c not found at {m2c_path}\n"
            "Clone it with: git clone https://github.com/matt-kempster/m2c.git .cache/m2c"
        )

    if not args.skip_context_build:
        make = shutil.which("make")
        if make is None:
            raise SystemExit("make was not found in PATH")
        subprocess.run(
            [make, "payload/build/payload/src/all.o"], cwd=root, check=True
        )
    if not context_path.is_file():
        raise SystemExit(f"preprocessed context was not generated: {context_path}")

    assembly = assembly_path.read_text(encoding="utf-8")
    functions = select_functions(assembly, args.start, args.end)
    typed_assembly_path.parent.mkdir(parents=True, exist_ok=True)
    typed_assembly_path.write_text(symbolize_assembly(assembly), encoding="utf-8")

    command = [
        sys.executable,
        "-B",
        str(m2c_path),
        "-t",
        "gba",
        "--passes",
        str(args.passes),
        "--context",
        str(context_path),
        "--context",
        str(extra_context_path),
        "--no-cache",
        "--globals",
        "used",
        "--deterministic-vars",
    ]
    if args.stack_structs:
        command.append("--stack-structs")
    for function in functions:
        command.extend(("-f", function))
    command.append(str(typed_assembly_path))

    result = subprocess.run(command, cwd=root, capture_output=True, text=True)
    if result.returncode != 0:
        sys.stderr.write(result.stdout)
        sys.stderr.write(result.stderr)
        return result.returncode

    commit = get_m2c_commit(args.m2c_dir.resolve())
    header = (
        "/*\n"
        " * Generated by tools/generate_m2c.py. Do not compile as-is.\n"
        f" * Range: {args.start} through {args.end} ({len(functions)} functions).\n"
        f" * m2c commit: {commit}\n"
        " */\n\n"
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(header + result.stdout, encoding="utf-8")

    missing = [
        function
        for function in functions
        if re.search(
            rf"(?m)^[^/\n;]*\b{re.escape(function)}\s*\([^;]*\)\s*\{{",
            result.stdout,
        )
        is None
    ]
    if result.stderr:
        sys.stderr.write(result.stderr)
    print(f"Generated {output_path.relative_to(root)} with {len(functions)} functions")
    if commit != TESTED_M2C_COMMIT:
        print(f"Note: tested with m2c {TESTED_M2C_COMMIT}, found {commit}")
    if missing:
        print("Functions without emitted definitions: " + ", ".join(missing))
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
