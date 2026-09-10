#!/usr/bin/env python3
"""Generate the Ninja and objdiff build configuration for this project."""

from __future__ import annotations

import argparse
import json
import os
import shutil
import sys
from pathlib import Path

from tools.generate_objdiff_text import UNIT_STARTS
from tools.generate_objdiff_sections import UNIT_BSS_RANGES, UNIT_DATA_RANGES


ROOT = Path(__file__).resolve().parent
PAYLOAD_CODE_UNITS = [name for name, _ in UNIT_STARTS if name != "syscalls"]
PAYLOAD_DATA_UNITS = ["msg_data", "sound_data", "time_palette", "world_pal"]
PAYLOAD_SECTION_UNITS = set(UNIT_DATA_RANGES) | set(UNIT_BSS_RANGES)
PAYLOAD_OBJDIFF_UNITS = [
    *PAYLOAD_CODE_UNITS[:-1],
    "time_palette",
    "msg_data",
    "world_pal",
    PAYLOAD_CODE_UNITS[-1],
    "sound_data",
]
LIBGCC_UNITS = [
    "_call_via_rX",
    "_divsi3",
    "_dvmd_tls",
    "_modsi3",
    "_udivsi3",
    "_umodsi3",
]
LIBC_UNITS = ["memcpy", "memset"]


def posix(path: Path | str) -> str:
    return Path(path).as_posix()


def ninja_escape(value: str) -> str:
    return value.replace("$", "$$").replace(" ", "$ ").replace(":", "$:")


class NinjaWriter:
    def __init__(self) -> None:
        self.lines: list[str] = []

    def line(self, value: str = "") -> None:
        self.lines.append(value)

    def variable(self, name: str, value: str) -> None:
        self.line(f"{name} = {value}")

    def rule(self, name: str, command: str, **attrs: str) -> None:
        self.line(f"rule {name}")
        self.line(f"  command = {command}")
        for key, value in attrs.items():
            self.line(f"  {key} = {value}")
        self.line()

    def build(
        self,
        outputs: str | list[str],
        rule: str,
        inputs: str | list[str] = (),
        *,
        implicit: list[str] = (),
        variables: dict[str, str] | None = None,
    ) -> None:
        if isinstance(outputs, str):
            outputs = [outputs]
        if isinstance(inputs, str):
            inputs = [inputs]
        output_text = " ".join(ninja_escape(v) for v in outputs)
        input_text = " ".join(ninja_escape(v) for v in inputs)
        implicit_text = ""
        if implicit:
            implicit_text = " | " + " ".join(ninja_escape(v) for v in implicit)
        self.line(f"build {output_text}: {rule} {input_text}{implicit_text}".rstrip())
        for key, value in (variables or {}).items():
            self.line(f"  {key} = {value}")

    def write(self, path: Path) -> None:
        path.write_text("\n".join(self.lines) + "\n", encoding="utf-8", newline="\n")


def find_ninja(explicit: Path | None) -> Path:
    if explicit is not None:
        candidate = explicit
    elif found := shutil.which("ninja"):
        candidate = Path(found)
    elif os.name == "nt":
        candidate = Path(sys.executable).parent / "Scripts" / "ninja.exe"
    else:
        candidate = Path("ninja")
    if candidate != Path("ninja") and not candidate.is_file():
        raise SystemExit(f"Ninja executable not found: {candidate}")
    return candidate.resolve() if candidate.is_file() else candidate


def require_file(path: Path, description: str) -> None:
    if not path.is_file():
        raise SystemExit(f"{description} not found: {path}")


def emit_c_object(
    n: NinjaWriter,
    source: str,
    output: str,
    *,
    cppflags: str,
    cflags: str,
    charmap: str,
    asflags: str,
    preproc_cwd: str | None = None,
    preproc_implicit: list[str] = (),
) -> None:
    output_path = Path(output)
    stem = output_path.with_suffix("")
    preprocessed = posix(stem.with_suffix(".i"))
    translated = posix(stem.with_suffix(".p.c"))
    assembly = posix(stem.with_suffix(".s"))
    n.build(preprocessed, "cpp", source, variables={"cppflags": cppflags})
    if preproc_cwd is None:
        preproc_rule = "preproc"
        preproc_variables = {"charmap": charmap}
    else:
        preproc_rule = "preproc_in_dir"
        preproc_variables = {
            "preproc_cwd": preproc_cwd,
            "preproc_input": posix(Path(preprocessed).relative_to(preproc_cwd)),
            "charmap": posix(Path(charmap).relative_to(preproc_cwd)),
        }
    n.build(
        translated,
        preproc_rule,
        preprocessed,
        implicit=["tools/capture_stdout.py", *preproc_implicit],
        variables=preproc_variables,
    )
    n.build(assembly, "cc1", translated, variables={"cflags": cflags})
    n.build(
        output,
        "as_compiled",
        assembly,
        implicit=["tools/agbcc_footer.s"],
        variables={"asflags": asflags},
    )


def emit_data_asm(
    n: NinjaWriter,
    source: str,
    output: str,
    *,
    cppflags: str,
    charmap: str,
    asflags: str,
    implicit: list[str] = (),
) -> None:
    stem = Path(output).with_suffix("")
    preprocessed = posix(stem.with_suffix(".pre.s"))
    assembly = posix(stem.with_suffix(".s"))
    n.build(
        preprocessed,
        "preproc",
        source,
        implicit=[*implicit, "tools/capture_stdout.py"],
        variables={"charmap": charmap},
    )
    n.build(assembly, "cpp_asm", preprocessed, variables={"cppflags": cppflags})
    n.build(output, "as", assembly, variables={"asflags": asflags})


def objdiff_c_unit(name: str) -> dict[str, object]:
    flags = "-O2 -g -mthumb-interwork -fhex-asm -Wimplicit -Werror -ffix-debug-line"
    if name == "sound":
        flags += " -fprologue-bugfix"
    return {
        "name": f"payload/{name}",
        "target_path": f"payload/build/objdiff/{name}{'.target.o' if name in PAYLOAD_SECTION_UNITS else '.text.target.o'}",
        "base_path": f"payload/build/payload/src/{name}.o",
        "scratch": {
            "platform": "gba",
            "compiler": "agbcc",
            "c_flags": flags,
            "ctx_path": f"payload/build/payload/src/{name}.i",
            "build_ctx": False,
        },
        "metadata": {
            "complete": False,
            "source_path": f"payload/src/{name}.c",
            "auto_generated": False,
        },
    }


def write_objdiff(ninja: Path) -> None:
    # Data-only sources are placed where their bytes occur in the final payload.
    # Code sources retain the original .text translation-unit order.
    units: list[dict[str, object]] = [objdiff_c_unit(name) for name in PAYLOAD_OBJDIFF_UNITS]
    units.append(
        {
            "name": "payload/syscalls",
            "target_path": "payload/build/objdiff/syscalls.text.target.o",
            "base_path": "payload/build/payload/asm/gflib/syscalls.o",
            "metadata": {
                "complete": True,
                "source_path": "payload/asm/gflib/syscalls.s",
                "auto_generated": False,
            },
        }
    )
    units.append(
        {
            "name": "payload/data",
            "target_path": "payload/build/objdiff/data.target.o",
            "base_path": "payload/build/objdiff/data.base.o",
            "metadata": {
                "complete": False,
                "source_path": "payload/src/data.c",
                "auto_generated": False,
            },
        }
    )
    units.append(
        {
            "name": "payload/data_all",
            "target_path": "payload/build/objdiff/all.data.target.o",
            "base_path": "payload/build/objdiff/all.base.o",
            "metadata": {
                "complete": False,
                "source_path": "payload/src/data.c",
                "auto_generated": False,
            },
        }
    )
    for name in LIBGCC_UNITS:
        units.append(
            {
                "name": f"libgcc/{name}",
                "target_path": f"payload/build/objdiff/libgcc/{name}.o",
                "base_path": f"payload/build/payload/asm/libgcc/{name}.o",
                "metadata": {
                    "complete": True,
                    "source_path": f"payload/asm/libgcc/{name}.s",
                    "auto_generated": False,
                },
            }
        )
    for name in LIBC_UNITS:
        units.append(
            {
                "name": f"libc/{name}",
                "target_path": f"payload/build/objdiff/libc/{name}.o",
                "base_path": f"payload/build/payload/src/libc/{name}.o",
                "metadata": {
                    "complete": True,
                    "source_path": f"payload/src/libc/{name}.c",
                    "auto_generated": False,
                },
            }
        )
    config = {
        "min_version": "3.7.1",
        "custom_make": posix(ninja),
        "build_base": True,
        "build_target": True,
        "watch_patterns": [
            "*.c",
            "*.h",
            "*.s",
            "*.inc",
            "*.py",
            "*.bin",
            "*.txt",
            "*.json",
        ],
        "ignore_patterns": ["build/**/*", "payload/build/**/*"],
        "units": units,
    }
    (ROOT / "objdiff.json").write_text(
        json.dumps(config, indent=2) + "\n", encoding="utf-8", newline="\n"
    )


def generate(args: argparse.Namespace) -> None:
    ninja_path = find_ninja(args.ninja)
    devkitarm = args.devkitarm.resolve()
    tool_bin = devkitarm / "bin"
    exe = ".exe" if os.name == "nt" else ""
    agbcc = ROOT / f"tools/agbcc/bin/agbcc{exe}"
    preproc = ROOT / f"tools/preproc/preproc{exe}"
    gbagfx = ROOT / f"tools/gbagfx/gbagfx{exe}"
    gbafix = ROOT / f"tools/gbafix/gbafix{exe}"
    cpp = tool_bin / f"arm-none-eabi-cpp{exe}"
    assembler = tool_bin / f"arm-none-eabi-as{exe}"
    linker = tool_bin / f"arm-none-eabi-ld{exe}"
    objcopy = tool_bin / f"arm-none-eabi-objcopy{exe}"
    ar = tool_bin / f"arm-none-eabi-ar{exe}"
    for path, description in (
        (cpp, "ARM preprocessor"),
        (assembler, "ARM assembler"),
        (linker, "ARM linker"),
        (objcopy, "ARM objcopy"),
        (ar, "ARM archiver"),
        (agbcc, "agbcc"),
        (preproc, "preproc"),
        (gbagfx, "gbagfx"),
        (gbafix, "gbafix"),
    ):
        require_file(path, description)

    debug_testing = args.debug_testing or args.debug_test
    payload_defines: list[str] = []
    outer_defines: list[str] = []
    if args.nonmatching:
        payload_defines.append("-DNONMATCHING")
    if debug_testing:
        payload_defines.append("-DDEBUG_TESTING")
        outer_defines.append("-DDEBUG_TESTING")
    if args.debug_test:
        payload_defines.append("-DDEBUG_TEST")

    payload_cppflags = " ".join(
        ["-I tools/agbcc/include", "-iquote payload/include", "-nostdinc", "-undef", *payload_defines]
    )
    outer_cppflags = " ".join(
        ["-I tools/agbcc/include", "-iquote include", "-nostdinc", "-undef", *outer_defines]
    )
    payload_asflags = " ".join(
        ["-mcpu=arm7tdmi", "-I payload", "-I payload/include"]
        + (["--defsym NONMATCHING=1"] if args.nonmatching else [])
    )
    outer_asflags = " ".join(
        ["-mcpu=arm7tdmi", "-I ."]
        + (["--defsym DEBUG_TESTING=1"] if debug_testing else [])
    )
    cflags = "-O2 -g -mthumb-interwork -fhex-asm -Wimplicit -Werror -ffix-debug-line"
    data_cflags = cflags.replace(" -Werror", "")
    libc_cppflags = payload_cppflags + (
        " -DABORT_PROVIDED -DHAVE_GETTIMEOFDAY -D__thumb__ -DARM_RDI_MONITOR"
        " -D__GNUC__ -DINTERNAL_NEWLIB -D__USER_LABEL_PREFIX__="
    )

    payload_build = ROOT / "payload/build/payload"
    outer_build = ROOT / "build/island-program-mb"
    for directory in (
        payload_build / "src/libc",
        payload_build / "asm/gflib",
        payload_build / "asm/libgcc",
        payload_build / "data",
        ROOT / "payload/build/objdiff/libgcc",
        ROOT / "payload/build/objdiff/libc",
        outer_build / "asm",
        outer_build / "data",
    ):
        directory.mkdir(parents=True, exist_ok=True)
    payload_ld = (ROOT / "payload/ld_script.txt").read_text(encoding="utf-8")
    (payload_build / "ld_script.ld").write_text(payload_ld, encoding="utf-8", newline="\n")
    outer_ld = (ROOT / "ld_script.txt").read_text(encoding="utf-8")
    (outer_build / "ld_script.ld").write_text(outer_ld, encoding="utf-8", newline="\n")

    n = NinjaWriter()
    n.line("# Generated by configure.py. Do not edit.")
    n.line("ninja_required_version = 1.10")
    n.variable("python", posix(Path(sys.executable).resolve()))
    n.variable("ninja", posix(ninja_path))
    n.variable("cpp", posix(cpp))
    n.variable("as", posix(assembler))
    n.variable("ld", posix(linker))
    n.variable("objcopy", posix(objcopy))
    n.variable("ar", posix(ar))
    n.variable("cc1", posix(agbcc))
    n.variable("preproc", posix(preproc))
    n.variable("gbagfx", posix(gbagfx))
    n.variable("gbafix", posix(gbafix))
    n.line()

    if os.name == "nt":
        payload_cd = 'cmd /d /s /c "cd /d payload\\build\\payload && '
        outer_cd = 'cmd /d /s /c "cd /d build\\island-program-mb && '
        command_suffix = '"'
        objcopy_fix_command = (
            'cmd /d /s /c ""$objcopy" -O binary "$in" "$out" '
            '&& "$gbafix" "$out" --silent"'
        )
    else:
        payload_cd = "cd payload/build/payload && "
        outer_cd = "cd build/island-program-mb && "
        command_suffix = ""
        objcopy_fix_command = '"$objcopy" -O binary "$in" "$out" && "$gbafix" "$out" --silent'

    configure_args = [f'--ninja "{posix(ninja_path)}"', f'--devkitarm "{posix(devkitarm)}"']
    if args.nonmatching:
        configure_args.append("--nonmatching")
    if args.debug_test:
        configure_args.append("--debug-test")
    if args.debug_testing and not args.debug_test:
        configure_args.append("--debug-testing")
    n.rule(
        "configure",
        '"$python" configure.py ' + " ".join(configure_args),
        description="CONFIGURE",
        generator="1",
    )
    n.rule(
        "cpp",
        '"$cpp" $cppflags -MMD -MF "${out}.d" -MT "$out" -o "$out" "$in"',
        description="CPP $in",
        depfile="${out}.d",
        deps="gcc",
    )
    n.rule(
        "preproc",
        '"$python" tools/capture_stdout.py "$out" "$preproc" "$in" "$charmap"',
        description="PREPROC $in",
    )
    n.rule(
        "preproc_in_dir",
        '"$python" tools/capture_stdout.py --cwd "$preproc_cwd" "$out" '
        '"$preproc" "$preproc_input" "$charmap"',
        description="PREPROC $in",
    )
    n.rule("cc1", '"$cc1" $cflags -o "$out" "$in"', description="CC $in")
    n.rule(
        "as_compiled",
        '"$as" $asflags -o "$out" "$in" tools/agbcc_footer.s',
        description="AS $out",
    )
    n.rule("as", '"$as" $asflags -o "$out" "$in"', description="AS $out")
    n.rule("cpp_asm", '"$cpp" $cppflags -o "$out" "$in"', description="CPP-AS $in")
    n.rule("objcopy", '"$objcopy" -O binary "$in" "$out"', description="OBJCOPY $out")
    n.rule(
        "objcopy_fix",
        objcopy_fix_command,
        description="OBJCOPY $out",
    )
    n.rule("payload_lz", '"$gbagfx" "$in" "$out" -search 1', description="LZ $out")
    n.rule(
        "payload_link",
        payload_cd + '"$ld" -Map ../../payload.map -T ld_script.ld '
        '-o ../../payload.elf $link_inputs -L../../../tools/agbcc/lib -lgcc -lc' + command_suffix,
        description="LD payload/payload.elf",
    )
    n.rule(
        "outer_link",
        outer_cd + '"$ld" -Map ../../island-program-mb.map '
        '-T ld_script.ld -o ../../island-program-mb.elf $link_inputs '
        '-L../../tools/agbcc/lib -lgcc -lc && "$gbafix" ../../island-program-mb.elf '
        '-cAGBJ -m01 -r0 --silent' + command_suffix,
        description="LD island-program-mb.elf",
    )
    n.rule(
        "objdiff_split",
        '"$python" tools/generate_objdiff_text.py --unit $unit --output "$out"',
        description="SPLIT $unit",
    )
    n.rule(
        "objdiff_prepare",
        '"$python" tools/prepare_objdiff_target.py "$in" "$out"',
        description="OBJDIF-FIX $out",
    )
    n.rule(
        "objdiff_data",
        '"$python" tools/generate_objdiff_sections.py --text-object '
        'payload/build/payload/asm/all.o --data payload/data/data.bin $unit_arg --output "$out"',
        description="OBJDIF-DATA $out",
    )
    n.rule(
        "reloc_combine",
        '"$ld" -r -S -o "$out" $in',
        description="LD-R $out",
    )
    n.rule(
        "reloc_data_common",
        '"$ld" -r -d -S -T payload/objdiff_data_common.ld -o "$out" $in',
        description="LD-R $out",
    )
    n.rule(
        "reloc_link",
        '"$ld" -r -d -S -T payload/objdiff_sections.ld -o "$out" $in',
        description="LD-R $out",
    )
    n.rule(
        "archive_member",
        '"$python" tools/extract_archive_member.py "$out" "$ar" "$archive" "$member"',
        description="AR $member",
    )
    n.rule(
        "binary_slice",
        '"$python" tools/extract_binary_slice.py "$in" "$out" $offset $size',
        description="SLICE $out",
    )
    n.build(
        [
            "build.ninja",
            "objdiff.json",
            "payload/build/payload/ld_script.ld",
            "build/island-program-mb/ld_script.ld",
        ],
        "configure",
        ["configure.py", "tools/generate_objdiff_text.py", "payload/ld_script.txt", "ld_script.txt"],
    )
    for output, offset in (
        ("payload/data/island_right_acre_tilemaps.bin", "0x1D64"),
        ("payload/data/island_left_acre_tilemaps.bin", "0x3D64"),
    ):
        n.build(
            output,
            "binary_slice",
            "payload/data/data.bin",
            implicit=["tools/extract_binary_slice.py"],
            variables={"offset": offset, "size": "0x2000"},
        )

    payload_objects: list[str] = []
    for unit in PAYLOAD_CODE_UNITS:
        source = f"payload/src/{unit}.c"
        output = f"payload/build/payload/src/{unit}.o"
        unit_flags = cflags + (" -fprologue-bugfix" if unit == "sound" else "")
        preproc_cwd = "payload" if unit == "island_field" else None
        preproc_implicit = (
            [
                "payload/data/island_right_acre_tilemaps.bin",
                "payload/data/island_left_acre_tilemaps.bin",
            ]
            if unit == "island_field"
            else []
        )
        emit_c_object(
            n,
            source,
            output,
            cppflags=payload_cppflags,
            cflags=unit_flags,
            charmap="payload/charmap.txt",
            asflags=payload_asflags,
            preproc_cwd=preproc_cwd,
            preproc_implicit=preproc_implicit,
        )
        payload_objects.append(output)

    data_object = "payload/build/payload/src/data.o"
    emit_c_object(
        n,
        "payload/src/data.c",
        data_object,
        cppflags=payload_cppflags,
        cflags=data_cflags,
        charmap="payload/charmap.txt",
        asflags=payload_asflags,
    )
    payload_objects.append(data_object)

    data_objects: list[str] = []
    for unit in PAYLOAD_DATA_UNITS:
        output = f"payload/build/payload/src/{unit}.o"
        emit_c_object(
            n,
            f"payload/src/{unit}.c",
            output,
            cppflags=payload_cppflags,
            cflags=data_cflags,
            charmap="payload/charmap.txt",
            asflags=payload_asflags,
        )
        data_objects.append(output)
    payload_objects.extend(data_objects)

    libc_objects: list[str] = []
    for unit in LIBC_UNITS:
        output = f"payload/build/payload/src/libc/{unit}.o"
        emit_c_object(
            n,
            f"payload/src/libc/{unit}.c",
            output,
            cppflags=libc_cppflags,
            cflags="-O2 -fno-builtin",
            charmap="payload/charmap.txt",
            asflags=payload_asflags,
        )
        libc_objects.append(output)

    asm_dependencies = [
        "asm/macros/function.inc",
        "constants/gba_constants.inc",
        "payload/asm/all_arm.inc",
        "payload/asm/gflib/syscalls.inc",
    ]
    payload_crt = "payload/build/payload/asm/crt0.o"
    n.build(payload_crt, "as", "payload/asm/crt0.s", implicit=asm_dependencies, variables={"asflags": payload_asflags})
    syscalls = "payload/build/payload/asm/gflib/syscalls.o"
    n.build(syscalls, "as", "payload/asm/gflib/syscalls.s", implicit=asm_dependencies, variables={"asflags": payload_asflags})
    libgcc_objects: list[str] = []
    for unit in LIBGCC_UNITS:
        output = f"payload/build/payload/asm/libgcc/{unit}.o"
        n.build(output, "as", f"payload/asm/libgcc/{unit}.s", implicit=asm_dependencies, variables={"asflags": payload_asflags})
        libgcc_objects.append(output)
    original_text = "payload/build/payload/asm/all.o"
    n.build(original_text, "as", "payload/asm/all.s", implicit=asm_dependencies, variables={"asflags": payload_asflags})

    debug_island = "payload/build/payload/data/debug_test_island.o"
    debug_implicit: list[str] = []
    if args.debug_test:
        debug_implicit.append("assets/debug/test_island_agb_fmt.bin")
    emit_data_asm(
        n,
        "payload/data/debug_test_island.s",
        debug_island,
        cppflags=payload_cppflags,
        charmap="payload/charmap.txt",
        asflags=payload_asflags,
        implicit=debug_implicit,
    )
    payload_objects.extend([payload_crt, syscalls, *libgcc_objects, *libc_objects, debug_island])

    payload_link_args = [
        "asm/crt0.o",
        *[f"src/{name}.o" for name in PAYLOAD_CODE_UNITS],
        "asm/gflib/syscalls.o",
        *[f"asm/libgcc/{name}.o" for name in LIBGCC_UNITS],
        *[f"src/libc/{name}.o" for name in LIBC_UNITS],
        *[f"src/{name}.o" for name in PAYLOAD_DATA_UNITS],
        "src/data.o",
        "data/debug_test_island.o",
    ]
    n.build(
        "payload/payload.elf",
        "payload_link",
        payload_objects,
        implicit=["payload/build/payload/ld_script.ld"],
        variables={"link_inputs": " ".join(payload_link_args)},
    )
    n.build("payload/payload.gba", "objcopy", "payload/payload.elf")
    n.build("payload/payload.gba.lz", "payload_lz", "payload/payload.gba")

    outer_crt = "build/island-program-mb/asm/crt0.o"
    n.build(outer_crt, "as", "asm/crt0.s", implicit=asm_dependencies, variables={"asflags": outer_asflags})
    payload_data = "build/island-program-mb/data/payload.o"
    emit_data_asm(
        n,
        "data/payload.s",
        payload_data,
        cppflags=outer_cppflags,
        charmap="charmap.txt",
        asflags=outer_asflags,
        implicit=["payload/payload.gba.lz"],
    )
    debug_graphics = "build/island-program-mb/data/debug_graphics.o"
    debug_assets = []
    if debug_testing:
        debug_assets = [
            "assets/debug/debug_obj_tiles.bin",
            "assets/debug/debug_bg_tiles.bin",
            "assets/debug/debug_bg3_tilemap.bin",
            "assets/debug/debug_bg2_tilemap.bin",
            "assets/debug/debug_bg1_tilemap.bin",
            "assets/debug/debug_bg0_tilemap.bin",
        ]
    emit_data_asm(
        n,
        "data/debug_graphics.s",
        debug_graphics,
        cppflags=outer_cppflags,
        charmap="charmap.txt",
        asflags=outer_asflags,
        implicit=debug_assets,
    )
    outer_objects = [outer_crt, payload_data, debug_graphics]
    n.build(
        "island-program-mb.elf",
        "outer_link",
        outer_objects,
        implicit=["build/island-program-mb/ld_script.ld"],
        variables={"link_inputs": "asm/crt0.o data/payload.o data/debug_graphics.o"},
    )
    n.build("island-program-mb.gba", "objcopy_fix", "island-program-mb.elf")

    objdiff_targets: list[str] = []
    for unit, _ in UNIT_STARTS:
        target_asm = f"payload/build/objdiff/{unit}.text.target.s"
        raw = f"payload/build/objdiff/{unit}.text.raw.o"
        text_target = f"payload/build/objdiff/{unit}.text.target.o"
        n.build(
            target_asm,
            "objdiff_split",
            "payload/asm/all.s",
            implicit=["tools/generate_objdiff_text.py"],
            variables={"unit": unit},
        )
        n.build(raw, "as", target_asm, implicit=asm_dependencies, variables={"asflags": payload_asflags})
        n.build(
            text_target,
            "objdiff_prepare",
            raw,
            implicit=["tools/prepare_objdiff_target.py", "tools/generate_objdiff_sections.py"],
        )
        if unit in PAYLOAD_SECTION_UNITS:
            section_asm = f"payload/build/objdiff/{unit}.data.target.s"
            section_target = f"payload/build/objdiff/{unit}.data.target.o"
            target = f"payload/build/objdiff/{unit}.target.o"
            n.build(
                section_asm,
                "objdiff_data",
                ["payload/data/data.bin", original_text],
                implicit=["tools/generate_objdiff_sections.py"],
                variables={"unit_arg": f"--unit {unit}"},
            )
            n.build(section_target, "as", section_asm, variables={"asflags": payload_asflags})
            n.build(target, "reloc_combine", [text_target, section_target])
            objdiff_targets.append(target)
        else:
            objdiff_targets.append(text_target)

    for unit in PAYLOAD_DATA_UNITS:
        section_asm = f"payload/build/objdiff/{unit}.data.target.s"
        target = f"payload/build/objdiff/{unit}.target.o"
        n.build(
            section_asm,
            "objdiff_data",
            ["payload/data/data.bin", original_text],
            implicit=["tools/generate_objdiff_sections.py"],
            variables={"unit_arg": f"--unit {unit}"},
        )
        n.build(target, "as", section_asm, variables={"asflags": payload_asflags})
        objdiff_targets.append(target)

    data_common_asm = "payload/build/objdiff/data.data.target.s"
    data_common_target = "payload/build/objdiff/data.target.o"
    data_common_base = "payload/build/objdiff/data.base.o"
    n.build(
        data_common_asm,
        "objdiff_data",
        ["payload/data/data.bin", original_text],
        implicit=["tools/generate_objdiff_sections.py"],
        variables={"unit_arg": "--unit data"},
    )
    n.build(data_common_target, "as", data_common_asm, variables={"asflags": payload_asflags})
    n.build(
        data_common_base,
        "reloc_data_common",
        data_object,
        implicit=["payload/objdiff_data_common.ld"],
    )
    objdiff_targets.append(data_common_target)

    data_target_asm = "payload/build/objdiff/all.data.target.s"
    data_target = "payload/build/objdiff/all.data.target.o"
    n.build(
        data_target_asm,
        "objdiff_data",
        ["payload/data/data.bin", original_text],
        implicit=["tools/generate_objdiff_sections.py"],
    )
    n.build(data_target, "as", data_target_asm, variables={"asflags": payload_asflags})
    objdiff_targets.append(data_target)

    for unit in LIBGCC_UNITS:
        output = f"payload/build/objdiff/libgcc/{unit}.o"
        n.build(
            output,
            "archive_member",
            "tools/agbcc/lib/libgcc.a",
            implicit=["tools/extract_archive_member.py"],
            variables={"archive": "tools/agbcc/lib/libgcc.a", "member": f"{unit}.o"},
        )
        objdiff_targets.append(output)
    for unit in LIBC_UNITS:
        output = f"payload/build/objdiff/libc/{unit}.o"
        n.build(
            output,
            "archive_member",
            "tools/agbcc/lib/libc.a",
            implicit=["tools/extract_archive_member.py"],
            variables={"archive": "tools/agbcc/lib/libc.a", "member": f"{unit}.o"},
        )
        objdiff_targets.append(output)

    aggregate_inputs = [
        *[f"payload/build/payload/src/{name}.o" for name in PAYLOAD_CODE_UNITS],
        syscalls,
        *data_objects,
        data_object,
    ]
    n.build(
        "payload/build/objdiff/all.base.o",
        "reloc_link",
        aggregate_inputs,
        implicit=["payload/objdiff_sections.ld"],
    )
    n.build("objdiff_targets", "phony", objdiff_targets)
    n.build("payload", "phony", "payload/payload.gba.lz")
    n.build("rom", "phony", "island-program-mb.gba")
    n.build("all", "phony", "rom")
    n.line()
    n.line("default all")
    n.write(ROOT / "build.ninja")
    write_objdiff(ninja_path)
    print(f"Generated build.ninja and objdiff.json (Ninja: {ninja_path})")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ninja", type=Path, help="path to ninja executable")
    parser.add_argument(
        "--devkitarm",
        type=Path,
        default=Path("C:/devkitPro/devkitARM") if os.name == "nt" else Path(os.environ.get("DEVKITARM", "/opt/devkitpro/devkitARM")),
        help="path to devkitARM",
    )
    parser.add_argument("--nonmatching", action="store_true")
    parser.add_argument("--debug-test", action="store_true")
    parser.add_argument("--debug-testing", action="store_true")
    generate(parser.parse_args())


if __name__ == "__main__":
    main()
