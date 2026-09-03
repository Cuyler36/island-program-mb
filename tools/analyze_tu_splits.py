#!/usr/bin/env python3
"""Rank likely translation-unit boundaries in the monolithic payload assembly.

This is deliberately a read-only analysis tool.  It never creates split files or
changes the build.  The output is evidence for manual review, not a claim that
the original source-file boundaries can be recovered with certainty.

The strongest signals available after linking are usually:

* a drop in nearby call-graph connectivity,
* a change in referenced ROM-data or IWRAM/BSS neighborhoods,
* separately-emitted duplicate floating constants or strings,
* ARM/Thumb mode transitions, and
* large changes in the local function-size profile.

Section alignment is reported but intentionally not given meaningful weight:
agbcc aligns individual functions so frequently that it is weak evidence for a
translation-unit boundary in this particular binary.
"""

from __future__ import annotations

import argparse
import collections
import dataclasses
import math
import re
import statistics
import struct
from pathlib import Path
from typing import Iterable, Sequence


FUNCTION_START_RE = re.compile(
    r"^\s*(?P<arch>thumb|arm)_func_start\s+(?P<name>[A-Za-z_.$][\w.$]*)\s*$"
)
ADDRESS_LABEL_RE = re.compile(
    r"^\s*(?P<name>[A-Za-z_.$][\w.$]*):\s*@\s*0x(?P<address>[0-9A-Fa-f]+)"
)
CALL_RE = re.compile(
    r"^\s*(?:bl|blx)\s+(?P<target>[A-Za-z_.$][\w.$]*)\b", re.IGNORECASE
)
TAIL_CALL_RE = re.compile(
    r"^\s*b\s+(?P<target>[A-Za-z_.$][\w.$]*)\b", re.IGNORECASE
)
WORD_RE = re.compile(r"\.4byte\s+(?P<value>[^\s@,]+)", re.IGNORECASE)
HEX_RE = re.compile(r"^0x(?P<value>[0-9A-Fa-f]+)$")
ALIGN_RE = re.compile(r"^\s*\.align\s+(?P<power>\d+)(?:\s*,\s*(?P<fill>[^\s@]+))?")
C_FUNCTION_RE = re.compile(
    r"^\s*(?:(?:static|extern|inline|const|volatile|signed|unsigned)\s+)*"
    r"(?:struct\s+\w+\s+|enum\s+\w+\s+|union\s+\w+\s+|[A-Za-z_]\w*\s*\**\s+)"
    r"(?P<name>[A-Za-z_]\w*)\s*\([^;]*\)\s*\{"
)
SUB_ADDRESS_RE = re.compile(r"^sub_(?P<address>[0-9A-Fa-f]{8})$", re.IGNORECASE)


@dataclasses.dataclass(slots=True)
class Function:
    index: int
    name: str
    arch: str
    start: int
    end: int
    source_line: int
    lines: list[str]
    calls: set[str] = dataclasses.field(default_factory=set)
    function_refs: set[str] = dataclasses.field(default_factory=set)
    numeric_text_refs: set[int] = dataclasses.field(default_factory=set)
    data_refs: set[int] = dataclasses.field(default_factory=set)
    ewram_refs: set[int] = dataclasses.field(default_factory=set)
    iwram_refs: set[int] = dataclasses.field(default_factory=set)
    mmio_refs: set[int] = dataclasses.field(default_factory=set)
    align_directives: int = 0
    jump_tables: int = 0

    @property
    def size(self) -> int:
        return self.end - self.start


@dataclasses.dataclass(slots=True)
class Boundary:
    left_index: int
    score: float
    evidence: list[str]
    cross_edges: int
    local_edges: int
    feature_similarity: float | None


@dataclasses.dataclass(slots=True)
class ElfSection:
    name: str
    offset: int
    size: int
    data: bytes


@dataclasses.dataclass(frozen=True, slots=True)
class FunctionPointerTable:
    address: int
    function_indices: tuple[int, ...]


def parse_int(value: str) -> int:
    return int(value, 0)


def read_elf32_section(path: Path, wanted_name: str) -> ElfSection:
    """Read one section from an ELF32 file without external dependencies."""

    raw = path.read_bytes()
    if len(raw) < 52 or raw[:4] != b"\x7fELF":
        raise ValueError(f"{path} is not an ELF file")
    if raw[4] != 1:
        raise ValueError(f"{path} is not ELF32")
    if raw[5] == 1:
        endian = "<"
    elif raw[5] == 2:
        endian = ">"
    else:
        raise ValueError(f"{path} has an unknown ELF byte order")

    section_offset = struct.unpack_from(f"{endian}I", raw, 0x20)[0]
    section_entry_size = struct.unpack_from(f"{endian}H", raw, 0x2E)[0]
    section_count = struct.unpack_from(f"{endian}H", raw, 0x30)[0]
    string_table_index = struct.unpack_from(f"{endian}H", raw, 0x32)[0]
    if section_entry_size < 40 or string_table_index >= section_count:
        raise ValueError(f"{path} has an invalid section table")

    section_headers: list[tuple[int, ...]] = []
    for index in range(section_count):
        offset = section_offset + index * section_entry_size
        if offset + 40 > len(raw):
            raise ValueError(f"{path} has a truncated section table")
        section_headers.append(struct.unpack_from(f"{endian}10I", raw, offset))

    strings_header = section_headers[string_table_index]
    strings_offset, strings_size = strings_header[4], strings_header[5]
    strings = raw[strings_offset : strings_offset + strings_size]

    def section_name(offset: int) -> str:
        end = strings.find(b"\0", offset)
        if end < 0:
            end = len(strings)
        return strings[offset:end].decode("ascii", errors="replace")

    for header in section_headers:
        name = section_name(header[0])
        if name == wanted_name:
            offset, size = header[4], header[5]
            return ElfSection(name, offset, size, raw[offset : offset + size])
    raise ValueError(f"section {wanted_name!r} was not found in {path}")


def locate_function_starts(lines: Sequence[str]) -> list[tuple[int, str, str, int]]:
    starts: list[tuple[int, str, str, int]] = []
    for line_index, line in enumerate(lines):
        match = FUNCTION_START_RE.match(line)
        if not match:
            continue
        name = match.group("name")
        address = None
        for label_line in lines[line_index + 1 : line_index + 6]:
            label_match = ADDRESS_LABEL_RE.match(label_line)
            if label_match and label_match.group("name") == name:
                address = int(label_match.group("address"), 16)
                break
        if address is None:
            raise ValueError(
                f"could not find an address-bearing label for {name} near line {line_index + 1}"
            )
        starts.append((line_index, match.group("arch"), name, address))
    if not starts:
        raise ValueError("no arm_func_start or thumb_func_start declarations were found")
    return starts


def parse_functions(asm_path: Path, data_base: int) -> list[Function]:
    lines = asm_path.read_text(encoding="utf-8").splitlines()
    starts = locate_function_starts(lines)
    names = {item[2] for item in starts}
    by_address = {item[3] & ~1: item[2] for item in starts}
    functions: list[Function] = []

    for index, (line_index, arch, name, address) in enumerate(starts):
        next_line_index = starts[index + 1][0] if index + 1 < len(starts) else len(lines)
        end_address = starts[index + 1][3] if index + 1 < len(starts) else data_base
        block = lines[line_index:next_line_index]
        function = Function(
            index=index,
            name=name,
            arch=arch,
            start=address,
            end=end_address,
            source_line=line_index + 1,
            lines=block,
        )

        for block_line in block:
            call_match = CALL_RE.match(block_line)
            if call_match:
                function.calls.add(call_match.group("target"))

            tail_match = TAIL_CALL_RE.match(block_line)
            if tail_match and tail_match.group("target") in names:
                function.calls.add(tail_match.group("target"))

            align_match = ALIGN_RE.match(block_line)
            if align_match:
                function.align_directives += 1
            if "@ jump table" in block_line:
                function.jump_tables += 1

            word_match = WORD_RE.search(block_line)
            if not word_match:
                continue
            value = word_match.group("value")
            hex_match = HEX_RE.match(value)
            if hex_match:
                numeric = int(hex_match.group("value"), 16)
                normalized = numeric & ~1
                if starts[0][3] <= normalized < data_base:
                    function.numeric_text_refs.add(numeric)
                    target_name = by_address.get(normalized)
                    if target_name:
                        function.function_refs.add(target_name)
                elif data_base <= numeric < 0x03000000:
                    function.data_refs.add(numeric)
                elif 0x02000000 <= numeric < starts[0][3]:
                    function.ewram_refs.add(numeric)
                elif 0x03000000 <= numeric < 0x04000000:
                    function.iwram_refs.add(numeric)
                elif 0x04000000 <= numeric < 0x05000000:
                    function.mmio_refs.add(numeric)
            elif value in names:
                function.function_refs.add(value)

        functions.append(function)

    return functions


def parse_c_functions(path: Path) -> set[str]:
    names: set[str] = set()
    for line in path.read_text(encoding="utf-8").splitlines():
        match = C_FUNCTION_RE.match(line)
        if match:
            names.add(match.group("name"))
    return names


def find_function_pointer_tables(
    data: bytes, data_base: int, functions: Sequence[Function]
) -> list[FunctionPointerTable]:
    """Find aligned runs of raw pointers to known functions in ROM data.

    Thumb function pointers carry bit zero, while ARM function pointers do not.
    Requiring at least two different targets in a run filters out most accidental
    matches in graphics and other opaque asset data.
    """
    by_address = {function.start: function.index for function in functions}
    tables: list[FunctionPointerTable] = []
    run_start: int | None = None
    run: list[int] = []

    def finish_run() -> None:
        nonlocal run_start, run
        if run_start is not None and len(run) >= 2 and len(set(run)) >= 2:
            tables.append(
                FunctionPointerTable(
                    address=data_base + run_start,
                    function_indices=tuple(run),
                )
            )
        run_start = None
        run = []

    for offset in range(0, len(data) - 3, 4):
        raw_value = int.from_bytes(data[offset : offset + 4], "little")
        function_index = by_address.get(raw_value & ~1)
        if function_index is None:
            finish_run()
            continue
        if run_start is None:
            run_start = offset
        run.append(function_index)
    finish_run()
    return tables


def union_attribute(functions: Iterable[Function], attribute: str) -> set:
    result: set = set()
    for function in functions:
        result.update(getattr(function, attribute))
    return result


def make_signature(functions: Sequence[Function]) -> collections.Counter[tuple[str, object]]:
    signature: collections.Counter[tuple[str, object]] = collections.Counter()
    for function in functions:
        for address in function.data_refs:
            signature[("data", address & ~0x3F)] += 3
        for address in function.iwram_refs:
            signature[("iwram", address & ~0x1F)] += 2
        for address in function.ewram_refs:
            signature[("ewram", address & ~0x3F)] += 2
        for address in function.mmio_refs:
            signature[("mmio", address)] += 1
        for callee in function.calls:
            signature[("call", callee)] += 1
    return signature


def cosine_similarity(
    left: collections.Counter[tuple[str, object]],
    right: collections.Counter[tuple[str, object]],
) -> float | None:
    if not left or not right:
        return None
    dot = sum(value * right.get(key, 0) for key, value in left.items())
    left_norm = math.sqrt(sum(value * value for value in left.values()))
    right_norm = math.sqrt(sum(value * value for value in right.values()))
    if left_norm == 0 or right_norm == 0:
        return None
    return dot / (left_norm * right_norm)


def data_bytes_at(data: bytes, data_base: int, address: int, size: int) -> bytes | None:
    offset = address - data_base
    if offset < 0 or offset + size > len(data):
        return None
    return data[offset : offset + size]


def plausible_float32(raw: bytes) -> float | None:
    if len(raw) != 4:
        return None
    word = int.from_bytes(raw, "little")
    exponent = (word >> 23) & 0xFF
    if not 0x6E <= exponent <= 0x91:
        return None
    value = struct.unpack("<f", raw)[0]
    if not math.isfinite(value) or value == 0.0 or abs(value) > 1_000_000:
        return None
    return value


def c_string_at(data: bytes, data_base: int, address: int) -> str | None:
    offset = address - data_base
    if offset < 0 or offset >= len(data):
        return None
    chunk = data[offset : offset + 80]
    terminator = chunk.find(b"\0")
    if terminator < 4:
        return None
    raw = chunk[:terminator]
    if not all(byte in (9, 10, 13) or 0x20 <= byte <= 0x7E for byte in raw):
        return None
    return raw.decode("ascii")


def duplicate_constant_evidence(
    left_refs: set[int],
    right_refs: set[int],
    data: bytes,
    data_base: int,
    word_occurrences: collections.Counter[bytes],
) -> tuple[list[str], float]:
    left_words: dict[bytes, set[int]] = collections.defaultdict(set)
    right_words: dict[bytes, set[int]] = collections.defaultdict(set)
    for address in left_refs:
        raw = data_bytes_at(data, data_base, address, 4)
        if raw is not None:
            left_words[raw].add(address)
    for address in right_refs:
        raw = data_bytes_at(data, data_base, address, 4)
        if raw is not None:
            right_words[raw].add(address)

    evidence: list[str] = []
    score = 0.0
    for raw in sorted(left_words.keys() & right_words.keys()):
        all_addresses = left_words[raw] | right_words[raw]
        if len(all_addresses) < 2 or word_occurrences[raw] > 6:
            continue
        value = plausible_float32(raw)
        if value is None:
            continue
        left_address = min(left_words[raw])
        right_address = min(right_words[raw])
        if left_address == right_address:
            continue
        evidence.append(
            f"duplicate referenced f32 {value:g} at 0x{left_address:08X}/0x{right_address:08X}"
        )
        score += 1.75
        if score >= 3.5:
            break
    return evidence, min(score, 3.5)


def duplicate_string_evidence(
    left_refs: set[int], right_refs: set[int], data: bytes, data_base: int
) -> tuple[list[str], float]:
    left_strings: dict[str, set[int]] = collections.defaultdict(set)
    right_strings: dict[str, set[int]] = collections.defaultdict(set)
    for address in left_refs:
        value = c_string_at(data, data_base, address)
        if value is not None:
            left_strings[value].add(address)
    for address in right_refs:
        value = c_string_at(data, data_base, address)
        if value is not None:
            right_strings[value].add(address)

    evidence: list[str] = []
    score = 0.0
    for value in sorted(left_strings.keys() & right_strings.keys()):
        left_address = min(left_strings[value])
        right_address = min(right_strings[value])
        if left_address == right_address:
            continue
        display = value.replace("\n", "\\n")
        if len(display) > 28:
            display = display[:25] + "..."
        evidence.append(
            f'duplicate referenced string "{display}" at '
            f"0x{left_address:08X}/0x{right_address:08X}"
        )
        score += 2.25
        if score >= 4.5:
            break
    return evidence, min(score, 4.5)


def median_or_none(values: set[int]) -> float | None:
    return statistics.median(values) if values else None


def score_boundaries(
    functions: Sequence[Function],
    data: bytes,
    data_base: int,
    window: int,
    function_pointer_tables: Sequence[FunctionPointerTable],
) -> list[Boundary]:
    name_to_index = {function.name: function.index for function in functions}
    edges: set[tuple[int, int]] = set()
    for function in functions:
        for target in function.calls | function.function_refs:
            target_index = name_to_index.get(target)
            if target_index is not None and target_index != function.index:
                edges.add((function.index, target_index))

    word_occurrences: collections.Counter[bytes] = collections.Counter(
        data[offset : offset + 4] for offset in range(0, len(data) - 3, 4)
    )
    boundaries: list[Boundary] = []

    for left_index in range(len(functions) - 1):
        left_start = max(0, left_index - window + 1)
        right_end = min(len(functions), left_index + 1 + window)
        left_functions = functions[left_start : left_index + 1]
        right_functions = functions[left_index + 1 : right_end]
        local_indices = set(range(left_start, right_end))
        left_indices = set(range(left_start, left_index + 1))
        right_indices = set(range(left_index + 1, right_end))
        local_edges = {
            edge for edge in edges if edge[0] in local_indices and edge[1] in local_indices
        }
        cross_edges = {
            edge
            for edge in local_edges
            if (edge[0] in left_indices and edge[1] in right_indices)
            or (edge[0] in right_indices and edge[1] in left_indices)
        }

        score = 0.0
        evidence: list[str] = []
        left_function = functions[left_index]
        right_function = functions[left_index + 1]

        if left_function.arch != right_function.arch:
            score += 5.0
            evidence.append(f"instruction mode changes {left_function.arch}->{right_function.arch}")

        if local_edges:
            cut_ratio = len(cross_edges) / len(local_edges)
            if not cross_edges and len(local_edges) >= 2:
                score += 1.25
                evidence.append(f"no crossing calls among {len(local_edges)} nearby call edges")
            elif cut_ratio <= 0.15:
                score += 0.75
                evidence.append(
                    f"low nearby call cut ({len(cross_edges)}/{len(local_edges)} edges)"
                )
            score -= min(5.0, len(cross_edges) * 0.8)
        if (
            right_function.name in left_function.calls | left_function.function_refs
            or left_function.name in right_function.calls | right_function.function_refs
        ):
            score -= 2.5
            evidence.append("adjacent functions directly reference each other")

        spanning_pointer_tables = [
            table
            for table in function_pointer_tables
            if any(index in left_indices for index in table.function_indices)
            and any(index in right_indices for index in table.function_indices)
        ]
        if spanning_pointer_tables:
            score -= min(3.0, 1.5 * len(spanning_pointer_tables))
            sample_addresses = "/".join(
                f"0x{table.address:08X}" for table in spanning_pointer_tables[:2]
            )
            evidence.append(
                f"ROM function-pointer table spans both sides ({sample_addresses})"
            )

        left_signature = make_signature(left_functions)
        right_signature = make_signature(right_functions)
        similarity = cosine_similarity(left_signature, right_signature)
        if similarity is not None and sum(left_signature.values()) >= 4 and sum(right_signature.values()) >= 4:
            score += 2.0 * (1.0 - similarity)
            if similarity < 0.2:
                evidence.append(f"nearby reference profiles diverge (cosine {similarity:.2f})")
            elif similarity > 0.7:
                score -= min(1.0, (similarity - 0.7) * 3.0)

        left_data = union_attribute(left_functions, "data_refs")
        right_data = union_attribute(right_functions, "data_refs")
        shared_data = left_data & right_data
        if shared_data:
            score -= min(2.5, 0.4 * len(shared_data))
        left_data_median = median_or_none(left_data)
        right_data_median = median_or_none(right_data)
        if left_data_median is not None and right_data_median is not None:
            gap = abs(right_data_median - left_data_median)
            if not shared_data and gap >= 0x40:
                score += 0.5
            if gap >= 0x200:
                score += 0.5
            if gap >= 0x1000:
                score += 0.5
            if not shared_data and min(right_data) > max(left_data):
                score += 0.75
                evidence.append(
                    f"ROM-data references advance from 0x{max(left_data):08X} "
                    f"to 0x{min(right_data):08X}"
                )
            elif gap >= 0x400:
                evidence.append(f"ROM-data median shifts by 0x{int(gap):X}")

        left_iwram = union_attribute(left_functions, "iwram_refs")
        right_iwram = union_attribute(right_functions, "iwram_refs")
        shared_iwram = left_iwram & right_iwram
        if shared_iwram:
            score -= min(2.0, 0.25 * len(shared_iwram))
        left_iwram_median = median_or_none(left_iwram)
        right_iwram_median = median_or_none(right_iwram)
        if left_iwram_median is not None and right_iwram_median is not None:
            gap = abs(right_iwram_median - left_iwram_median)
            if not shared_iwram and gap >= 0x40:
                score += 0.5
            if gap >= 0x400:
                score += 0.5
                evidence.append(f"IWRAM/BSS median shifts by 0x{int(gap):X}")

        constant_evidence, constant_score = duplicate_constant_evidence(
            left_data, right_data, data, data_base, word_occurrences
        )
        evidence.extend(constant_evidence)
        score += constant_score
        string_evidence, string_score = duplicate_string_evidence(
            left_data, right_data, data, data_base
        )
        evidence.extend(string_evidence)
        score += string_score

        left_sizes = [function.size for function in left_functions]
        right_sizes = [function.size for function in right_functions]
        if left_sizes and right_sizes:
            left_size = max(2.0, statistics.median(left_sizes))
            right_size = max(2.0, statistics.median(right_sizes))
            ratio = max(left_size, right_size) / min(left_size, right_size)
            if ratio >= 4.0:
                score += 0.5
                evidence.append(f"median function size changes {left_size:g}->{right_size:g} bytes")

        boundaries.append(
            Boundary(
                left_index=left_index,
                score=score,
                evidence=evidence,
                cross_edges=len(cross_edges),
                local_edges=len(local_edges),
                feature_similarity=similarity,
            )
        )
    return boundaries


def select_spaced_boundaries(
    boundaries: Sequence[Boundary], count: int, minimum_separation: int
) -> list[Boundary]:
    selected: list[Boundary] = []
    for boundary in sorted(boundaries, key=lambda item: item.score, reverse=True):
        if any(
            abs(boundary.left_index - existing.left_index) < minimum_separation
            for existing in selected
        ):
            continue
        selected.append(boundary)
        if len(selected) >= count:
            break
    return selected


def boundary_label(boundary: Boundary, functions: Sequence[Function]) -> str:
    left = functions[boundary.left_index]
    right = functions[boundary.left_index + 1]
    return (
        f"0x{right.start:08X}  {left.name} | {right.name} "
        f"(functions {left.index + 1}/{right.index + 1})"
    )


def print_boundary(boundary: Boundary, functions: Sequence[Function], rank: int | None = None) -> None:
    prefix = f"{rank:2d}. " if rank is not None else "    "
    print(f"{prefix}{boundary.score:6.2f}  {boundary_label(boundary, functions)}")
    if boundary.evidence:
        print("      " + "; ".join(boundary.evidence[:5]))
    else:
        print("      no positive boundary evidence; retained only for relative comparison")


def resolve_around(value: str, functions: Sequence[Function]) -> int:
    for function in functions:
        if function.name.casefold() == value.casefold():
            return function.index
    try:
        address = parse_int(value)
    except ValueError as error:
        raise ValueError(f"unknown function or address for --around: {value}") from error
    for function in functions:
        if function.start == address:
            return function.index
    raise ValueError(f"no function starts at 0x{address:08X}")


def build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Rank likely original translation-unit boundaries without changing the project."
    )
    parser.add_argument("--asm", type=Path, default=Path("payload/asm/all.s"))
    parser.add_argument("--data", type=Path, default=Path("payload/data/data.bin"))
    parser.add_argument(
        "--asm-object",
        type=Path,
        default=Path("payload/build/payload/asm/all.o"),
        help="ELF object whose .text size determines the data base",
    )
    parser.add_argument(
        "--data-base",
        type=parse_int,
        help="override the inferred ROM-data base (for example 0x02029698)",
    )
    parser.add_argument(
        "--c-source",
        type=Path,
        default=Path("payload/src/all.c"),
        help="optional current C file used only to summarize existing coverage",
    )
    parser.add_argument("--window", type=int, default=7, help="functions per side to inspect")
    parser.add_argument("--top", type=int, default=30, help="number of spaced candidates to show")
    parser.add_argument(
        "--minimum-separation",
        type=int,
        default=5,
        help="minimum number of functions between displayed top candidates",
    )
    parser.add_argument(
        "--around",
        help="also show every boundary near a function name or start address",
    )
    parser.add_argument("--radius", type=int, default=5, help="radius used with --around")
    parser.add_argument(
        "--show-pointer-tables",
        action="store_true",
        help="list inferred ROM function-pointer runs and a sample of their targets",
    )
    return parser


def main() -> int:
    args = build_argument_parser().parse_args()
    if args.window < 1 or args.top < 1 or args.minimum_separation < 1 or args.radius < 0:
        raise SystemExit("window, top, and minimum-separation must be positive; radius cannot be negative")

    preliminary_lines = args.asm.read_text(encoding="utf-8").splitlines()
    starts = locate_function_starts(preliminary_lines)
    text_section = read_elf32_section(args.asm_object, ".text")
    inferred_data_base = starts[0][3] + text_section.size
    data_base = args.data_base if args.data_base is not None else inferred_data_base
    data = args.data.read_bytes()
    functions = parse_functions(args.asm, data_base)
    function_pointer_tables = find_function_pointer_tables(data, data_base, functions)
    boundaries = score_boundaries(
        functions, data, data_base, args.window, function_pointer_tables
    )

    print("TU split analysis (read-only dry run)")
    print(f"Assembly:      {args.asm}")
    print(f"Text object:   {args.asm_object} (.text = 0x{text_section.size:X} bytes)")
    print(f"Functions:     {len(functions)} (0x{functions[0].start:08X}-0x{functions[-1].end:08X})")
    print(f"ROM data:      {args.data} at 0x{data_base:08X} (0x{len(data):X} bytes)")
    if args.data_base is not None and data_base != inferred_data_base:
        print(f"Inferred base: 0x{inferred_data_base:08X} (overridden)")
    print(
        "References:    "
        f"{sum(len(function.data_refs) for function in functions)} ROM-data, "
        f"{sum(len(function.iwram_refs) for function in functions)} IWRAM/BSS, "
        f"{sum(len(function.mmio_refs) for function in functions)} MMIO"
    )
    print(
        "Alignment:     "
        f"{sum(function.align_directives for function in functions)} explicit directives; "
        "reported as weak evidence only"
    )
    print(
        "Data tables:   "
        f"{len(function_pointer_tables)} likely function-pointer runs, "
        f"{sum(len(table.function_indices) for table in function_pointer_tables)} entries"
    )

    if args.show_pointer_tables:
        print("Inferred ROM function-pointer runs:")
        for table in function_pointer_tables:
            unique_indices = list(dict.fromkeys(table.function_indices))
            shown = ", ".join(functions[index].name for index in unique_indices[:6])
            if len(unique_indices) > 6:
                shown += ", ..."
            print(
                f"  0x{table.address:08X}: {len(table.function_indices)} entries, "
                f"{len(unique_indices)} unique ({shown})"
            )

    if args.c_source.exists():
        c_names = parse_c_functions(args.c_source)
        asm_by_casefold = {function.name.casefold(): function for function in functions}
        exact = c_names & {function.name for function in functions}
        casefold = {name for name in c_names if name.casefold() in asm_by_casefold}
        sub_addresses = [
            int(match.group("address"), 16)
            for name in c_names
            if (match := SUB_ADDRESS_RE.match(name)) is not None
        ]
        coverage_suffix = (
            f", highest sub_ address 0x{max(sub_addresses):08X}" if sub_addresses else ""
        )
        print(
            f"Current C:     {len(c_names)} definitions; {len(exact)} exact and "
            f"{len(casefold)} case-insensitive asm-name matches{coverage_suffix}"
        )

    print()
    print(
        "Top candidate boundaries (relative ranking; spacing suppresses adjacent duplicates):"
    )
    selected = select_spaced_boundaries(boundaries, args.top, args.minimum_separation)
    for rank, boundary in enumerate(selected, start=1):
        print_boundary(boundary, functions, rank)

    if args.around:
        around_index = resolve_around(args.around, functions)
        start = max(0, around_index - args.radius)
        end = min(len(boundaries), around_index + args.radius + 1)
        print()
        print(f"Boundary neighborhood around {functions[around_index].name}:")
        for boundary in boundaries[start:end]:
            print_boundary(boundary, functions)

    print()
    print(
        "Caveat: linked binaries erase authoritative TU metadata. Treat these as hypotheses to "
        "test against compiler-emitted object layout and duplicated constants, not as final splits."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
