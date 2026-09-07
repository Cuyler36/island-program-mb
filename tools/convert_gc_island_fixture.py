#!/usr/bin/env python3
"""Convert a raw big-endian GameCube Island_c into Island_agb_c.

This is a small Python port of Animal Crossing's mISL_gc_to_agb conversion.
The input is the 0x1900-byte Island_c stored in the GameCube save. The output
is the 0x3980-byte little-endian structure consumed by the GBA island program.

The original converter obtains the earth texture, islander texture, and
islander palette from separate GameCube resources. This standalone converter
leaves those regions zero-filled, which is sufficient for basic loading and
tilemap tests.
"""

from __future__ import annotations

import argparse
from pathlib import Path


GC_ISLAND_SIZE = 0x1900
AGB_ISLAND_SIZE = 0x3980
AGB_LANDINFO_START = 0x0014
AGB_LANDINFO_END = 0x0024
AGB_CHECKSUM_OFFSET = 0x397F

# Special field actors rewritten by mISL_gc_to_agb_fg2.
FG_ACTOR_REMAP = {
    0xF123: 0x5850,  # DUMMY_COTTAGE_MY  -> COTTAGE_MY
    0xF124: 0x5851,  # DUMMY_COTTAGE_NPC -> COTTAGE_NPC
    0xF122: 0x584E,  # DUMMY_FLAG        -> FLAG
    0xF128: 0x584F,  # DUMMY_BOAT        -> BOAT
    0xF11F: 0xA012,  # dummy signboard   -> villager signboard
}

# Order used by l_misl_agb_npc_table in m_island.c.
ISLANDER_INDEX_BY_NPC_ID = {
    0xE0DA: 0,   # Bliss
    0xE0E0: 1,   # Dobie
    0xE0D9: 2,   # O'Hare
    0xE0DB: 3,   # Drift
    0xE0E7: 4,   # June
    0xE0E4: 5,   # Faith
    0xE0E1: 6,   # Flossie
    0xE0DF: 7,   # Flash
    0xE0D8: 8,   # Maelle
    0xE0E2: 9,   # Annalise
    0xE0DC: 10,  # Bud
    0xE0DE: 11,  # Elina
    0xE0DD: 12,  # Boomer
    0xE0E9: 13,  # Pigleg
    0xE0E5: 14,  # Yodel
    0xE0E3: 15,  # Plucky
    0xE0E6: 16,  # Rowan
    0xE0EA: 17,  # Ankha
}


def copy_bytes(src: bytes, src_offset: int, dst: bytearray, dst_offset: int, size: int) -> None:
    dst[dst_offset : dst_offset + size] = src[src_offset : src_offset + size]


def read_be16(src: bytes, offset: int) -> int:
    return int.from_bytes(src[offset : offset + 2], "big")


def read_be32(src: bytes, offset: int) -> int:
    return int.from_bytes(src[offset : offset + 4], "big")


def write_le(dst: bytearray, offset: int, value: int, size: int) -> None:
    dst[offset : offset + size] = value.to_bytes(size, "little")


def copy_u16s(src: bytes, src_offset: int, dst: bytearray, dst_offset: int, count: int) -> None:
    for index in range(count):
        write_le(dst, dst_offset + index * 2, read_be16(src, src_offset + index * 2), 2)


def copy_u32s(src: bytes, src_offset: int, dst: bytearray, dst_offset: int, count: int) -> None:
    for index in range(count):
        write_le(dst, dst_offset + index * 4, read_be32(src, src_offset + index * 4), 4)


def copy_u64(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    value = int.from_bytes(src[src_offset : src_offset + 8], "big")
    dst[dst_offset : dst_offset + 8] = value.to_bytes(8, "little")


def convert_time(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    copy_bytes(src, src_offset, dst, dst_offset, 6)
    write_le(dst, dst_offset + 6, read_be16(src, src_offset + 6), 2)


def convert_ymd(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    write_le(dst, dst_offset, read_be16(src, src_offset), 2)
    copy_bytes(src, src_offset + 2, dst, dst_offset + 2, 2)


def convert_personal_id(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    copy_bytes(src, src_offset, dst, dst_offset, 0x10)
    copy_u16s(src, src_offset + 0x10, dst, dst_offset + 0x10, 2)


def convert_animal_id(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    copy_u16s(src, src_offset, dst, dst_offset, 2)
    copy_bytes(src, src_offset + 4, dst, dst_offset + 4, 10)


def convert_home_layer(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    copy_u16s(src, src_offset, dst, dst_offset, 0x100)
    copy_u64(src, src_offset + 0x200, dst, dst_offset + 0x200)
    copy_u32s(src, src_offset + 0x208, dst, dst_offset + 0x208, 8)


def convert_cottage_floor(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    for layer in range(4):
        convert_home_layer(src, src_offset + layer * 0x228, dst, dst_offset + layer * 0x228)

    copy_bytes(src, src_offset + 0x8A0, dst, dst_offset + 0x8A0, 2)
    copy_bytes(src, src_offset + 0x8A2, dst, dst_offset + 0x8A4, 2)

    # The GC bitfield occupies one byte. The original stages it in a zeroed
    # four-byte object and applies mISL_int to that object.
    floor_bits = bytes((src[src_offset + 0x8A4] & 0xC0, 0, 0, 0))
    dst[dst_offset + 0x8A8 : dst_offset + 0x8AC] = reversed(floor_bits)


def convert_cottage(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    copy_bytes(src, src_offset, dst, dst_offset, 2)
    copy_bytes(src, src_offset + 2, dst, dst_offset + 4, 2)
    convert_cottage_floor(src, src_offset + 8, dst, dst_offset + 8)
    dst[dst_offset + 0x8B8] = src[src_offset + 4]
    dst[dst_offset + 0x8B9] = src[src_offset + 5]
    convert_time(src, src_offset + 0x8B0, dst, dst_offset + 0x8BC)
    dst[dst_offset + 0x8C4] = src[src_offset + 0x8B8]
    copy_u32s(src, src_offset + 0x8BC, dst, dst_offset + 0x8CC, 2)


def convert_letter(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    dst[dst_offset] = src[src_offset]
    dst[dst_offset + 1] = src[src_offset + 1]
    write_le(dst, dst_offset + 2, read_be16(src, src_offset + 2), 2)
    dst[dst_offset + 4] = src[src_offset + 4]
    copy_bytes(src, src_offset + 0x005, dst, dst_offset + 0x008, 0x18)
    copy_bytes(src, src_offset + 0x01D, dst, dst_offset + 0x020, 0xC0)
    copy_bytes(src, src_offset + 0x0DD, dst, dst_offset + 0x0E0, 0x20)
    convert_ymd(src, src_offset + 0x0FE, dst, dst_offset + 0x100)


def convert_memory(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    convert_personal_id(src, src_offset, dst, dst_offset)
    convert_time(src, src_offset + 0x14, dst, dst_offset + 0x14)
    copy_u32s(src, src_offset + 0x1C, dst, dst_offset + 0x1C, 3)

    # The original US conversion forgets to write saved_town_tune here.
    dst[dst_offset + 0x30] = src[src_offset + 0x30]

    # Expand the one-byte GC letter bitfield into the transfer u32.
    letter_bits = bytes((src[src_offset + 0x31] & 0xF8, 0, 0, 0))
    dst[dst_offset + 0x34 : dst_offset + 0x38] = reversed(letter_bits)
    convert_letter(src, src_offset + 0x32, dst, dst_offset + 0x38)


def convert_quest(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    packed_flags = bytes((src[src_offset], src[src_offset + 1] & 0xFC, 0, 0))
    dst[dst_offset : dst_offset + 4] = reversed(packed_flags)
    convert_time(src, src_offset + 2, dst, dst_offset + 4)
    write_le(dst, dst_offset + 0x0C, read_be16(src, src_offset + 0x0C), 2)
    convert_personal_id(src, src_offset + 0x0E, dst, dst_offset + 0x10)
    dst[dst_offset + 0x24] = src[src_offset + 0x22]
    dst[dst_offset + 0x28 : dst_offset + 0x2C] = reversed(
        src[src_offset + 0x24 : src_offset + 0x28]
    )


def convert_animal(src: bytes, src_offset: int, dst: bytearray, dst_offset: int) -> None:
    convert_animal_id(src, src_offset, dst, dst_offset)

    for memory in range(7):
        convert_memory(
            src,
            src_offset + 0x010 + memory * 0x138,
            dst,
            dst_offset + 0x010 + memory * 0x140,
        )

    copy_bytes(src, src_offset + 0x898, dst, dst_offset + 0x8D0, 5)
    copy_bytes(src, src_offset + 0x89D, dst, dst_offset + 0x8D8, 10)
    convert_quest(src, src_offset + 0x8A8, dst, dst_offset + 0x8E4)
    copy_bytes(src, src_offset + 0x8D0, dst, dst_offset + 0x910, 8)
    copy_u32s(src, src_offset + 0x8D8, dst, dst_offset + 0x91C, 2)
    dst[dst_offset + 0x928] = src[src_offset + 0x8E2]
    dst[dst_offset + 0x929] = src[src_offset + 0x8E3]
    copy_u16s(src, src_offset + 0x8E4, dst, dst_offset + 0x92A, 2)
    copy_bytes(src, src_offset + 0x8E8, dst, dst_offset + 0x92E, 6)
    write_le(dst, dst_offset + 0x934, read_be16(src, src_offset + 0x8EE), 2)
    copy_bytes(src, src_offset + 0x8F0, dst, dst_offset + 0x93C, 15)

    for mail in range(4):
        gc_mail = src_offset + 0x900 + mail * 0x1C
        agb_mail = dst_offset + 0x950 + mail * 0x1C
        convert_time(src, gc_mail, dst, agb_mail)
        copy_bytes(src, gc_mail + 8, dst, agb_mail + 8, 20)


def remap_foreground_actor(actor: int) -> int:
    if 0x0011 <= actor <= 0x0029:
        return 0
    return FG_ACTOR_REMAP.get(actor, actor)


def update_checksum(data: bytearray) -> None:
    data[AGB_CHECKSUM_OFFSET] = 0
    checked_sum = sum(data[:AGB_LANDINFO_START]) + sum(data[AGB_LANDINFO_END:])
    data[AGB_CHECKSUM_OFFSET] = (-checked_sum) & 0xFF


def convert_island(source: bytes, *, weather: int = 0) -> bytes:
    if len(source) != GC_ISLAND_SIZE:
        raise ValueError(
            f"expected a 0x{GC_ISLAND_SIZE:X}-byte GameCube Island_c, "
            f"got 0x{len(source):X} bytes"
        )
    if weather not in (0, 1):
        raise ValueError("weather must be 0 (clear) or 1 (rain)")

    result = bytearray(AGB_ISLAND_SIZE)

    copy_bytes(source, 0x0000, result, 0x0008, 8)
    result[0x0010] = source[0x18E0]
    result[0x0013] = 0

    copy_bytes(source, 0x0008, result, 0x0014, 8)
    result[0x001C] = source[0x0010]
    write_le(result, 0x001E, read_be16(source, 0x0012), 2)

    for index in range(0x200):
        actor = read_be16(source, 0x0014 + index * 2)
        write_le(result, 0x0024 + index * 2, remap_foreground_actor(actor), 2)

    convert_cottage(source, 0x0418, result, 0x0428)
    copy_bytes(source, 0x0CE0, result, 0x0D00, 0x220)
    convert_animal(source, 0x0F00, result, 0x0F20)
    copy_u16s(source, 0x1888, result, 0x18F8, 0x20)
    copy_bytes(source, 0x18C8, result, 0x1938, 2)
    result[0x193A] = weather
    convert_time(source, 0x18CA, result, 0x193C)

    npc_id = read_be16(source, 0x0F00)
    write_le(result, 0x1944, ISLANDER_INDEX_BY_NPC_ID.get(npc_id, 0), 4)

    # 0x1948..0x3968 stays zero: textures and palette come from GC resources.
    result[0x397D] = source[0x18E1]
    result[0x397E] = source[0x18E2]
    update_checksum(result)
    return bytes(result)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="raw big-endian 0x1900-byte Island_c")
    parser.add_argument("output", type=Path, help="output 0x3980-byte Island_agb_c")
    parser.add_argument(
        "--weather",
        choices=("clear", "rain"),
        default="clear",
        help="weather is external to Island_c in the original converter (default: clear)",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    converted = convert_island(args.input.read_bytes(), weather=args.weather == "rain")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(converted)
    print(
        f"Wrote {args.output} (0x{len(converted):X} bytes, "
        f"checksum 0x{converted[AGB_CHECKSUM_OFFSET]:02X})"
    )


if __name__ == "__main__":
    main()
