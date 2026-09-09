#!/usr/bin/env python3
"""Run a command and atomically capture its standard output to a file."""

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path


def main() -> None:
    arguments = sys.argv[1:]
    cwd = None
    if arguments[:1] == ["--cwd"]:
        if len(arguments) < 3:
            raise SystemExit(f"usage: {sys.argv[0]} [--cwd DIR] OUTPUT COMMAND [ARG ...]")
        cwd = arguments[1]
        arguments = arguments[2:]
    if len(arguments) < 2:
        raise SystemExit(f"usage: {sys.argv[0]} [--cwd DIR] OUTPUT COMMAND [ARG ...]")

    output = Path(arguments[0])
    temporary = output.with_name(output.name + ".tmp")
    try:
        with temporary.open("wb") as stream:
            subprocess.run(arguments[1:], cwd=cwd, stdout=stream, check=True)
        os.replace(temporary, output)
    finally:
        temporary.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
