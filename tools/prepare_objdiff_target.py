#!/usr/bin/env python3
"""Prepare the monolithic ARM text object for objdiff.

The hand-written target assembly leaves most functions zero-sized so objdiff
can infer their extents and trim trailing ARM/Thumb alignment padding.  Modern
GNU as also emits R_ARM_V4BX marker relocations, which objdiff 3.7.1 does not
understand.  This script creates a generated copy that removes those marker
relocations without assigning function sizes.

Known data/BSS addresses in ARM literal pools are represented as ABS32
relocations. Resolving those relocations at the original addresses reproduces
the input bytes exactly. Instructions and original assembly remain unchanged.
"""

from __future__ import annotations

import argparse
import re
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

sys.dont_write_bytecode = True
from generate_objdiff_sections import DATA_OBJECTS, BSS_OBJECTS, DATA_ADDRESS


ELF_HEADER_SIZE = 52
ELFCLASS32 = 1
ELFDATA2LSB = 1
EM_ARM = 40
SHT_RELA = 4
SHT_REL = 9
R_ARM_V4BX = 40


def known_data_addresses(linker_path: Path) -> dict[int, str]:
    """Prefer owned objects over linker aliases for the same address."""
    result = {DATA_ADDRESS + obj.offset: obj.name for obj in DATA_OBJECTS
              if not obj.name.startswith("sData_")}
    result.update({obj.address: obj.name for obj in BSS_OBJECTS
                   if not obj.name.startswith("sBssPadding_")})
    for name, address in re.findall(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);",
                                    linker_path.read_text(), re.M):
        result.setdefault(int(address, 16), name)
    return result


def symbolize_data_literals(data: bytearray, addresses: dict[int, str]) -> int:
    """Add relocations only to aligned words in assembler-marked data ranges.

    ARM $d/$t/$a mapping symbols distinguish pools from executable instructions.
    Existing relocations are authoritative and are never replaced. New global
    undefined symbols and tables are appended, preserving all existing symbol
    indices and function sizes.
    """
    section_offset = struct.unpack_from("<I", data, 32)[0]
    stride, count, names_index = struct.unpack_from("<HHH", data, 46)
    sections = [struct.unpack_from("<10I", data, section_offset + i * stride)
                for i in range(count)]

    def contents(index):
        section = sections[index]
        return data[section[4]:section[4] + section[5]]

    def string(table, offset):
        return bytes(table[offset:table.index(0, offset)]).decode("ascii")

    names = contents(names_index)
    text_index = next(i for i, s in enumerate(sections) if string(names, s[0]) == ".text")
    text = sections[text_index]
    sym_index = next(i for i, s in enumerate(sections) if s[1] == 2)
    str_index = sections[sym_index][6]
    symbols, strings = contents(sym_index), contents(str_index)
    if sections[sym_index][9] != 16:
        raise ValueError("expected ELF32 symbol entries")
    mappings = []
    symbol_indices = {}
    for offset in range(0, len(symbols), 16):
        name, value, size, info, other, index = struct.unpack_from("<IIIBBH", symbols, offset)
        name = string(strings, name)
        if name:
            symbol_indices[name] = offset // 16
        if index == text_index and re.fullmatch(r"\$[dat](?:\..*)?", name):
            mappings.append((value, name[1]))
    rel_index = next(i for i, s in enumerate(sections)
                     if s[1] == SHT_REL and s[7] == text_index)
    if sections[rel_index][6] != sym_index or sections[rel_index][9] != 8:
        raise ValueError("unexpected text relocation table")
    relocations = contents(rel_index)
    occupied = {struct.unpack_from("<I", relocations, i)[0]
                for i in range(0, len(relocations), 8)}
    mappings.sort()
    mappings.append((text[5], "end"))
    changed = 0
    for (start, kind), (end, _) in zip(mappings, mappings[1:]):
        if kind != "d":
            continue
        for offset in range((start + 3) & ~3, end - 3, 4):
            if offset in occupied:
                continue
            value = struct.unpack_from("<I", data, text[4] + offset)[0]
            if value not in addresses:
                continue
            name = addresses[value]
            if name not in symbol_indices:
                symbol_indices[name] = len(symbols) // 16
                symbols.extend(struct.pack("<IIIBBH", len(strings), 0, 0, 0x11, 0, 0))
                strings.extend(name.encode("ascii") + b"\0")
            # ELF REL stores its addend in the relocated word; object bases
            # have addend zero, not the already-linked original address.
            struct.pack_into("<I", data, text[4] + offset, 0)
            relocations.extend(struct.pack("<II", offset, symbol_indices[name] << 8 | 2))
            changed += 1
    if changed:
        for index, table in ((str_index, strings), (sym_index, symbols), (rel_index, relocations)):
            data.extend(b"\0" * (-len(data) % 4))
            struct.pack_into("<II", data, section_offset + index * stride + 16, len(data), len(table))
            data.extend(table)
    return changed


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
    parser.add_argument("--linker", type=Path, default=Path("payload/ld_script.txt"))
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    data = bytearray(args.input.read_bytes())
    sections = read_sections(data)
    removed_relocations = remove_v4bx_relocations(data, sections)
    added_relocations = symbolize_data_literals(data, known_data_addresses(args.linker))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    print(
        f"Prepared {args.output}: preserved function sizes for objdiff inference; "
        f"removed {removed_relocations} R_ARM_V4BX marker relocations; "
        f"added {added_relocations} data/BSS literal relocations"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
