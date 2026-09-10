#!/usr/bin/env python3
"""Extract a byte range from a binary file."""

from __future__ import annotations

import argparse
import os
from pathlib import Path


def nonnegative_integer(value: str) -> int:
    result = int(value, 0)
    if result < 0:
        raise argparse.ArgumentTypeError("value must be nonnegative")
    return result


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="source binary")
    parser.add_argument("output", type=Path, help="destination file")
    parser.add_argument("offset", type=nonnegative_integer, help="starting byte offset")
    parser.add_argument("size", type=nonnegative_integer, help="number of bytes")
    return parser.parse_args()


def extract_slice(source: Path, output: Path, offset: int, size: int) -> None:
    source = source.resolve(strict=True)
    output = output.resolve()
    source_size = source.stat().st_size
    end = offset + size
    if end > source_size:
        raise ValueError(
            f"requested range 0x{offset:X}-0x{end:X} exceeds "
            f"{source} (0x{source_size:X} bytes)"
        )

    output.parent.mkdir(parents=True, exist_ok=True)
    temporary_output = output.with_name(output.name + ".tmp")
    try:
        with source.open("rb") as source_file:
            source_file.seek(offset)
            data = source_file.read(size)
        temporary_output.write_bytes(data)
        os.replace(temporary_output, output)
    finally:
        temporary_output.unlink(missing_ok=True)


def main() -> None:
    args = parse_args()
    extract_slice(args.input, args.output, args.offset, args.size)


if __name__ == "__main__":
    main()
