#!/usr/bin/env python3
"""Atomically extract one archive member without routing binary data via stdout."""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import tempfile
from pathlib import Path


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("output", type=Path, help="destination path")
    parser.add_argument("archiver", help="ar executable")
    parser.add_argument("archive", type=Path, help="input archive")
    parser.add_argument("member", help="archive member name")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    output = args.output.resolve()
    archive = args.archive.resolve(strict=True)
    member_name = Path(args.member).name
    if member_name != args.member:
        raise ValueError(f"archive member must be a filename: {args.member!r}")

    output.parent.mkdir(parents=True, exist_ok=True)
    temporary_output = output.with_name(output.name + ".tmp")
    try:
        with tempfile.TemporaryDirectory(
            prefix=f".{output.name}.", dir=output.parent
        ) as temporary_directory:
            subprocess.run(
                [args.archiver, "x", os.fspath(archive), args.member],
                cwd=temporary_directory,
                check=True,
            )
            extracted = Path(temporary_directory, member_name)
            if not extracted.is_file():
                raise FileNotFoundError(
                    f"archive did not produce member {args.member!r}"
                )

            # A file moved out of TemporaryDirectory can retain that
            # directory's restrictive Windows ACL. Copying into the output
            # directory first gives the staged file normal inherited access.
            with extracted.open("rb") as source, temporary_output.open("wb") as target:
                shutil.copyfileobj(source, target)
        os.replace(temporary_output, output)
    finally:
        temporary_output.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
