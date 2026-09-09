#!/usr/bin/env python3
"""Check migrated object boundaries and relocated bytes against the original image.

Code pointers are resolved at original function addresses, so unfinished text
matching does not obscure data errors. --elf also checks the normal link layout.
Only the Python standard library is required.
"""

import argparse
import re
import struct
import sys
from pathlib import Path

sys.dont_write_bytecode = True
from generate_objdiff_sections import (
    BSS_OBJECTS, DATA_OBJECTS, DATA_ADDRESS, IWRAM_ADDRESS, read_thumb_functions,
)


class Elf:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        if self.data[:6] != b"\x7fELF\x01\x01":
            raise ValueError(f"{path}: expected little-endian ELF32")
        offset = struct.unpack_from("<I", self.data, 32)[0]
        stride, count, names_index = struct.unpack_from("<HHH", self.data, 46)
        self.sections = [struct.unpack_from("<10I", self.data, offset + i * stride)
                         for i in range(count)]
        names = self.contents(names_index)
        self.section_names = [self.string(names, s[0]) for s in self.sections]
        self.symbols = []
        for section in self.sections:
            if section[1] != 2:
                continue
            strings = self.contents(section[6])
            for offset in range(section[4], section[4] + section[5], section[9]):
                name, value, size, info, other, index = struct.unpack_from(
                    "<IIIBBH", self.data, offset)
                self.symbols.append((self.string(strings, name), value, size, index))
        self.named = {s[0]: s for s in self.symbols if s[0]}

    @staticmethod
    def string(data, offset):
        return data[offset:data.index(0, offset)].decode("ascii")

    def contents(self, index):
        s = self.sections[index]
        return self.data[s[4]:s[4] + s[5]]


def check(args):
    obj = Elf(args.object)
    linked = Elf(args.elf) if args.elf else None
    errors = []
    addresses = {}
    for objects, section, base in ((DATA_OBJECTS, ".data", DATA_ADDRESS),
                                   (BSS_OBJECTS, ".bss", IWRAM_ADDRESS)):
        for entry in objects:
            offset = entry.offset if section == ".data" else entry.address - base
            addresses[entry.name] = base + offset
            symbol = obj.named.get(entry.name)
            # agbcc gives block-scope static objects a numeric suffix and does
            # not emit their ELF size.  The recovered next boundary still
            # verifies the table's extent.
            block_static = False
            if not symbol and entry.name == "sMsgControlCodeHandlers":
                symbol = next((candidate for candidate in obj.symbols
                               if candidate[0].startswith(entry.name + ".")), None)
                block_static = symbol is not None
            size_matches = symbol and (symbol[2] == entry.size or
                                       (block_static and symbol[2] == 0))
            if not symbol or (symbol[1], obj.section_names[symbol[3]]) != (
                    offset, section) or not size_matches:
                errors.append(f"{entry.name}: expected {section}+0x{offset:X}, size 0x{entry.size:X}")
            if linked:
                symbol = linked.named.get(entry.name)
                block_static = False
                if not symbol and entry.name == "sMsgControlCodeHandlers":
                    symbol = next((candidate for candidate in linked.symbols
                                   if candidate[0].startswith(entry.name + ".")), None)
                    block_static = symbol is not None
                size_matches = symbol and (symbol[2] == entry.size or
                                           (block_static and symbol[2] == 0))
                if not symbol or symbol[1] != base + offset or not size_matches:
                    errors.append(f"{entry.name}: incorrect linked address or size")
    for name, address in re.findall(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);",
                                    Path(args.linker).read_text(), re.M):
        if name in addresses:
            errors.append(f"{name}: linker assignment overrides a C definition")
        addresses[name] = int(address, 16)
    addresses.update({name: address for address, name in read_thumb_functions(
        Path(args.text_object)).items()})

    index = obj.section_names.index(".data")
    data = bytearray(obj.contents(index))
    for section in obj.sections:
        if section[1] != 9 or section[7] != index:
            continue
        for offset in range(section[4], section[4] + section[5], section[9]):
            where, info = struct.unpack_from("<II", obj.data, offset)
            name, value, size, symbol_section = obj.symbols[info >> 8]
            if info & 255 != 2:
                raise ValueError(f"unsupported data relocation {info & 255}")
            if name in addresses:
                address = addresses[name]
            elif symbol_section < len(obj.sections) and obj.section_names[symbol_section] in (".data", ".bss"):
                address = value + (DATA_ADDRESS if obj.section_names[symbol_section] == ".data" else IWRAM_ADDRESS)
            else:
                raise ValueError(f"no original address for relocation {name}")
            addend = struct.unpack_from("<I", data, where)[0]
            struct.pack_into("<I", data, where, (address + addend) & 0xFFFFFFFF)
    target = Path(args.data).read_bytes()
    if len(data) != len(target):
        errors.append(f"data size: 0x{len(data):X}, target 0x{len(target):X}")
    differences = [i for i, (a, b) in enumerate(zip(data, target)) if a != b]
    if differences:
        ranges = []
        start = previous = differences[0]
        for offset in differences[1:]:
            if offset != previous + 1:
                ranges.append((start, previous))
                start = offset
            previous = offset
        ranges.append((start, previous))
        details = ", ".join(
            f"0x{DATA_ADDRESS + start:08X}-0x{DATA_ADDRESS + end:08X}"
            for start, end in ranges[:8]
        )
        if len(ranges) > 8:
            details += f", and {len(ranges) - 8} more ranges"
        errors.append(f"{len(differences)} data bytes differ: {details}")
    bss = obj.sections[obj.section_names.index(".bss")]
    expected_bss = max(e.address + e.size for e in BSS_OBJECTS) - IWRAM_ADDRESS
    if bss[1] != 8 or bss[5] != expected_bss:
        errors.append("BSS must be NOBITS with the original size")
    if any(s[3] == 0xFFF2 for s in obj.symbols):
        errors.append("COMMON symbols remain; their link order is not fixed")
    if errors:
        raise ValueError("\n".join(errors))
    print(f"PASS: {len(DATA_OBJECTS)} data and {len(BSS_OBJECTS)} BSS objects; "
          f"0x{len(data):X} relocated data bytes identical; BSS size 0x{expected_bss:X}.")
    if linked:
        print("PASS: all linked data/BSS addresses and sizes match the target.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--object", default="payload/build/objdiff/all.base.o")
    parser.add_argument("--text-object", default="payload/build/payload/asm/all.o")
    parser.add_argument("--data", default="payload/data/data.bin")
    parser.add_argument("--linker", default="payload/ld_script.txt")
    parser.add_argument("--elf", help="optional normal linked payload ELF")
    args = parser.parse_args()
    try:
        check(args)
    except (ValueError, KeyError) as error:
        print(error, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
