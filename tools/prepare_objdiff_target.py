#!/usr/bin/env python3
"""Prepare the monolithic ARM text object for objdiff.

The hand-written target assembly leaves most functions zero-sized so objdiff
can infer their extents and trim trailing ARM/Thumb alignment padding.  Modern
GNU as also emits R_ARM_V4BX marker relocations, which objdiff 3.7.1 does not
understand.  This script creates a generated copy that removes those marker
relocations without assigning function sizes.

This operation does not change section contents, data bytes, or instructions.
"""

from __future__ import annotations

import argparse
import struct
from dataclasses import dataclass
from pathlib import Path


ELF_HEADER_SIZE = 52
ELFCLASS32 = 1
ELFDATA2LSB = 1
EM_ARM = 40
SHT_RELA = 4
SHT_REL = 9
R_ARM_V4BX = 40


@dataclass(frozen=True, slots=True)
class Section:
    header_offset: int
    section_type: int
    offset: int
    size: int
    entry_size: int


def read_sections(data: bytearray) -> list[Section]:
    if len(data) < ELF_HEADER_SIZE or data[:4] != b"\x7fELF":
        raise ValueError("input is not an ELF file")
    if data[4] != ELFCLASS32 or data[5] != ELFDATA2LSB:
        raise ValueError("only 32-bit little-endian ELF files are supported")
    machine = struct.unpack_from("<H", data, 18)[0]
    if machine != EM_ARM:
        raise ValueError(f"expected an ARM ELF object, found e_machine={machine}")

    section_offset = struct.unpack_from("<I", data, 32)[0]
    section_entry_size, section_count = struct.unpack_from("<HH", data, 46)
    if section_entry_size < 40:
        raise ValueError(f"invalid ELF32 section-header size {section_entry_size}")

    sections: list[Section] = []
    for index in range(section_count):
        offset = section_offset + index * section_entry_size
        if offset + 40 > len(data):
            raise ValueError("section-header table extends beyond the input")
        fields = struct.unpack_from("<IIIIIIIIII", data, offset)
        sections.append(
            Section(
                header_offset=offset,
                section_type=fields[1],
                offset=fields[4],
                size=fields[5],
                entry_size=fields[9],
            )
        )
    return sections


def remove_v4bx_relocations(data: bytearray, sections: list[Section]) -> int:
    changed = 0
    for section in sections:
        if section.section_type not in (SHT_REL, SHT_RELA):
            continue
        entry_size = section.entry_size or (8 if section.section_type == SHT_REL else 12)
        if entry_size < 8:
            raise ValueError(f"invalid ELF32 relocation size {entry_size}")
        kept_entries: list[bytes] = []
        for relative_offset in range(0, section.size, entry_size):
            entry_offset = section.offset + relative_offset
            info_offset = entry_offset + 4
            if info_offset + 4 > len(data):
                raise ValueError("relocation table extends beyond the input")
            info = struct.unpack_from("<I", data, info_offset)[0]
            if info & 0xFF == R_ARM_V4BX:
                changed += 1
            else:
                kept_entries.append(bytes(data[entry_offset : entry_offset + entry_size]))

        if len(kept_entries) * entry_size != section.size:
            compacted = b"".join(kept_entries)
            old_end = section.offset + section.size
            new_end = section.offset + len(compacted)
            data[section.offset:new_end] = compacted
            data[new_end:old_end] = b"\0" * (old_end - new_end)
            struct.pack_into("<I", data, section.header_offset + 20, len(compacted))
    return changed


def build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "input",
        nargs="?",
        type=Path,
        default=Path("payload/build/payload/asm/all.o"),
    )
    parser.add_argument(
        "output",
        nargs="?",
        type=Path,
        default=Path("payload/build/objdiff/all.text.target.o"),
    )
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    data = bytearray(args.input.read_bytes())
    sections = read_sections(data)
    removed_relocations = remove_v4bx_relocations(data, sections)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    print(
        f"Prepared {args.output}: preserved function sizes for objdiff inference; "
        f"removed {removed_relocations} R_ARM_V4BX marker relocations"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
