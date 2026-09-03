#!/usr/bin/env python3
"""Generate objdiff-only assembly for the payload's data and BSS sections.

The original payload data is currently available as one unsplit binary blob.
This script preserves that blob as ``.data``, adds labels for data objects whose
target addresses are known, and describes the known IWRAM objects in ``.bss``.
The message control-code handler table is emitted as symbol references so the
resulting object has relocations comparable to the C translation unit.

This output is only an objdiff target artifact.  It does not alter the payload
linker layout or make claims about whether any original object was ``const``.
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
SHT_SYMTAB = 2
STT_FUNC = 2

TEXT_ADDRESS = 0x0201820C
DATA_ADDRESS = 0x02029698
IWRAM_ADDRESS = 0x03000000
EXPECTED_DATA_SIZE = 0x1068C


@dataclass(frozen=True, slots=True)
class ElfSection:
    section_type: int
    offset: int
    size: int
    link: int
    entry_size: int


@dataclass(frozen=True, slots=True)
class DataObject:
    name: str
    offset: int
    size: int
    pointer_table: bool = False


@dataclass(frozen=True, slots=True)
class BssObject:
    name: str
    address: int
    size: int
    global_symbol: bool = False


DATA_OBJECTS = (
    DataObject("sMsgGlyphWidths", 0x0038, 0x0100),
    DataObject("sFontCodeWidths", 0x0138, 0x0100),
    DataObject("sMsgFontGlyphs", 0x0238, 0x1000),
    DataObject("sMsgSpaceGlyph", 0x1238, 0x0010),
    DataObject("sCachedMessageIds", 0x1248, 0x0024),
    DataObject("sMsgControlCodeHandlers", 0x126C, 0x01C4, pointer_table=True),
    DataObject("gMsgWindowScrollOffsets", 0x148C, 0x0030),
    DataObject("sMsgControlCodeInfo", 0x14BC, 0x01C4),
    DataObject("gMsgTextData", 0xB90C, 0x07D2),
    DataObject("sMsgOffsets", 0xC0E0, 0x007C),
)

BSS_OBJECTS = (
    BssObject("transfer_size", 0x03000000, 0x0004),
    BssObject("sMsgDirtyTileOffset", 0x03000010, 0x0004),
    BssObject("sMsgDirtyTileCount", 0x03000014, 0x0004),
    BssObject("_03000018", 0x03000018, 0x0004),
    BssObject("sMsgPreviousTextRow", 0x0300001C, 0x0001),
    BssObject("sMsgPreviousTextX", 0x0300001D, 0x0001),
    BssObject("gGameState", 0x03001B50, 0x0864, global_symbol=True),
    BssObject("gUnk3002410", 0x03002410, 0x0400),
    BssObject("sMsgWindows", 0x03002A20, 0x05A0),
)


def read_elf_sections(data: bytes) -> list[ElfSection]:
    if len(data) < ELF_HEADER_SIZE or data[:4] != b"\x7fELF":
        raise ValueError("text object is not an ELF file")
    if data[4] != ELFCLASS32 or data[5] != ELFDATA2LSB:
        raise ValueError("only 32-bit little-endian ELF files are supported")
    machine = struct.unpack_from("<H", data, 18)[0]
    if machine != EM_ARM:
        raise ValueError(f"expected an ARM ELF object, found e_machine={machine}")

    section_offset = struct.unpack_from("<I", data, 32)[0]
    section_entry_size, section_count = struct.unpack_from("<HH", data, 46)
    if section_entry_size < 40:
        raise ValueError(f"invalid ELF32 section-header size {section_entry_size}")

    sections: list[ElfSection] = []
    for index in range(section_count):
        offset = section_offset + index * section_entry_size
        if offset + 40 > len(data):
            raise ValueError("section-header table extends beyond the text object")
        fields = struct.unpack_from("<IIIIIIIIII", data, offset)
        sections.append(
            ElfSection(
                section_type=fields[1],
                offset=fields[4],
                size=fields[5],
                link=fields[6],
                entry_size=fields[9],
            )
        )
    return sections


def read_c_string(data: bytes, offset: int, limit: int) -> str:
    end = data.find(b"\0", offset, limit)
    if end < 0:
        raise ValueError("unterminated ELF string-table entry")
    return data[offset:end].decode("ascii")


def read_thumb_functions(path: Path) -> dict[int, str]:
    data = path.read_bytes()
    sections = read_elf_sections(data)
    functions: dict[int, str] = {}

    for symbol_table in (section for section in sections if section.section_type == SHT_SYMTAB):
        if symbol_table.link >= len(sections):
            raise ValueError("symbol table has an invalid string-table link")
        string_table = sections[symbol_table.link]
        string_end = string_table.offset + string_table.size
        entry_size = symbol_table.entry_size or 16
        if entry_size < 16:
            raise ValueError(f"invalid ELF32 symbol size {entry_size}")

        for relative_offset in range(0, symbol_table.size, entry_size):
            symbol_offset = symbol_table.offset + relative_offset
            if symbol_offset + 16 > len(data):
                raise ValueError("symbol table extends beyond the text object")
            name_offset, value, _, info, _, section_index = struct.unpack_from(
                "<IIIBBH", data, symbol_offset
            )
            if info & 0xF != STT_FUNC or section_index == 0 or name_offset == 0:
                continue
            name = read_c_string(
                data, string_table.offset + name_offset, string_end
            )
            pointer = TEXT_ADDRESS + (value & ~1) | 1
            old_name = functions.setdefault(pointer, name)
            if old_name != name:
                raise ValueError(
                    f"multiple function names at 0x{pointer:08X}: {old_name}, {name}"
                )

    if not functions:
        raise ValueError("no Thumb function symbols found in the text object")
    return functions


def quote_incbin_path(path: Path) -> str:
    return path.as_posix().replace('"', '\\"')


def emit_incbin(lines: list[str], path: str, offset: int, size: int) -> None:
    if size:
        lines.append(f'    .incbin "{path}", 0x{offset:X}, 0x{size:X}')


def emit_symbol_header(lines: list[str], name: str, global_symbol: bool) -> None:
    directive = ".global" if global_symbol else ".local"
    lines.extend((f"{directive} {name}", f".type {name}, %object", f"{name}:"))


def generate_assembly(text_object: Path, data_path: Path) -> str:
    data = data_path.read_bytes()
    if len(data) != EXPECTED_DATA_SIZE:
        raise ValueError(
            f"expected data blob size 0x{EXPECTED_DATA_SIZE:X}, found 0x{len(data):X}"
        )
    functions = read_thumb_functions(text_object)
    incbin_path = quote_incbin_path(data_path)

    lines = [
        "@ Generated by tools/generate_objdiff_sections.py. Do not edit.",
        ".syntax unified",
        "",
        '.section .data, "aw", %progbits',
        ".balign 4",
    ]
    cursor = 0
    for obj in DATA_OBJECTS:
        if obj.offset < cursor or obj.offset + obj.size > len(data):
            raise ValueError(f"invalid or overlapping data object {obj.name}")
        emit_incbin(lines, incbin_path, cursor, obj.offset - cursor)
        emit_symbol_header(lines, obj.name, global_symbol=False)
        if obj.pointer_table:
            if obj.size % 4:
                raise ValueError(f"pointer table {obj.name} is not word-sized")
            for pointer_offset in range(obj.offset, obj.offset + obj.size, 4):
                pointer = struct.unpack_from("<I", data, pointer_offset)[0]
                try:
                    function_name = functions[pointer]
                except KeyError as error:
                    raise ValueError(
                        f"{obj.name} contains unknown code pointer 0x{pointer:08X} "
                        f"at target address 0x{DATA_ADDRESS + pointer_offset:08X}"
                    ) from error
                lines.append(f"    .4byte {function_name}")
        else:
            emit_incbin(lines, incbin_path, obj.offset, obj.size)
        lines.append(f".size {obj.name}, 0x{obj.size:X}")
        cursor = obj.offset + obj.size
    emit_incbin(lines, incbin_path, cursor, len(data) - cursor)

    lines.extend(("", '.section .bss, "aw", %nobits', ".balign 4"))
    cursor = 0
    for obj in BSS_OBJECTS:
        offset = obj.address - IWRAM_ADDRESS
        if offset < cursor:
            raise ValueError(f"invalid or overlapping BSS object {obj.name}")
        if offset > cursor:
            lines.append(f"    .space 0x{offset - cursor:X}")
        emit_symbol_header(lines, obj.name, obj.global_symbol)
        lines.append(f"    .space 0x{obj.size:X}")
        lines.append(f".size {obj.name}, 0x{obj.size:X}")
        cursor = offset + obj.size

    lines.append("")
    return "\n".join(lines)


def build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--text-object",
        type=Path,
        default=Path("payload/build/payload/asm/all.o"),
    )
    parser.add_argument(
        "--data",
        type=Path,
        default=Path("payload/data/data.bin"),
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("payload/build/objdiff/all.data.target.s"),
    )
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    output = generate_assembly(args.text_object, args.data)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    if not args.output.exists() or args.output.read_text(encoding="ascii") != output:
        args.output.write_text(output, encoding="ascii", newline="\n")
    print(
        f"Generated {args.output}: {len(DATA_OBJECTS)} data symbols and "
        f"{len(BSS_OBJECTS)} BSS symbols"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
