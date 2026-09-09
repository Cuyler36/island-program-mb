ifneq (,$(wildcard /c/devkitPro/devkitARM))
DEVKITPRO := /c/devkitPro
DEVKITARM := /c/devkitPro/devkitARM
endif
TOOLCHAIN := $(DEVKITARM)
COMPARE ?= 0
DEBUG_TEST ?= 0
DEBUG_TESTING ?= $(DEBUG_TEST)

ifeq ($(CC),)
HOSTCC := gcc
else
HOSTCC := $(CC)
endif

ifeq ($(CXX),)
HOSTCXX := g++
else
HOSTCXX := $(CXX)
endif

ifneq (,$(wildcard $(TOOLCHAIN)/base_tools))
include $(TOOLCHAIN)/base_tools
else
export PATH := $(TOOLCHAIN)/bin:$(PATH)
PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
OBJDUMP := $(PREFIX)objdump
export CC := $(PREFIX)gcc
export AS := $(PREFIX)as
endif
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld
export AR := $(PREFIX)ar
export OBJCOPY := $(PREFIX)objcopy
export OBJDUMP := $(PREFIX)objdump

PREPROC := tools/preproc/preproc
SCANINC := tools/scaninc/scaninc
GBAFIX := tools/gbafix/gbafix
GBAGFX := tools/gbagfx/gbagfx
ifeq ($(OS),Windows_NT)
WINDOWS_LOCALAPPDATA := /$(subst :,,$(subst \,/,$(LOCALAPPDATA)))
WINDOWS_PYTHON := $(lastword $(sort $(wildcard $(WINDOWS_LOCALAPPDATA)/Programs/Python/Python*/python.exe)))
PYTHON := $(if $(WINDOWS_PYTHON),$(WINDOWS_PYTHON),python3)
else
PYTHON := python3
endif
PERL := perl

NAME := island-program-mb
ROM := $(NAME).gba
ELF := $(NAME).elf
SYM = $(ROM:.gba=.sym)

PAYLOAD   := payload/payload.gba
PAYLOADLZ := $(PAYLOAD).lz
DEBUG_TEST_ISLAND_AGB := assets/debug/test_island_agb_fmt.bin

OBJ_DIR := build/$(NAME)

ASM_SRCS := $(wildcard asm/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(OBJ_DIR)/%.o)
C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=$(OBJ_DIR)/%.o)
DATA_ASM_SRCS := $(wildcard data/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(OBJ_DIR)/%.o)

CC1 := tools/agbcc/bin/agbcc
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef
CFLAGS := -O3 -g3 -mthumb-interwork -fhex-asm -Wimplicit -Werror -ffix-debug-line
ASFLAGS := -mcpu=arm7tdmi
ifeq (1,$(DEBUG_TESTING))
CPPFLAGS += -DDEBUG_TESTING
ASFLAGS += --defsym DEBUG_TESTING=1
endif
LIBS := -L../../tools/agbcc/lib -lgcc -lc

SUBDIRS := asm src data

ALL_OBJS := $(ASM_OBJS) $(C_OBJS) $(DATA_ASM_OBJS)

TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(patsubst %/Makefile,%,$(wildcard tools/*/Makefile)))

infoshell = $(foreach line, $(shell $1 | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))

# Special rules for particular files
$(OBJ_DIR)/src/unk_200E344.o: CFLAGS := -mthumb-interwork -fhex-asm -Wimplicit -Werror
$(OBJ_DIR)/src/siirtc.o:      CC1    := tools/agbcc/bin/agbcc
$(OBJ_DIR)/src/siirtc.o:      CFLAGS := -mthumb-interwork -fhex-asm -Wimplicit -Werror

MAKEFLAGS += --no-print-directory
# Build tools when building the rom
# Disable dependency scanning for clean/tidy/tools
ifeq (,$(filter-out all compare,$(MAKECMDGOALS)))
$(call infoshell, $(MAKE) tools)
else
NODEP := 1
endif

$(shell mkdir -p $(SUBDIRS:%=$(OBJ_DIR)/%))

.SUFFIXES:
.SECONDARY:
.DELETE_ON_ERROR:
.SECONDEXPANSION:

.PHONY: all rom clean compare tools cleantools mostlyclean payload

ALL_ROMS := needle-loader-mb.gba

all: rom
	@:

rom: $(ROM)
ifeq ($(COMPARE),1)
	sha1sum -c $(NAME).sha1
endif

mostlyclean:
	$(MAKE) -C payload mostlyclean
	$(RM) -r $(ALL_ROMS) $(ALL_ROMS:%.gba=%.elf) $(ALL_ROMS:%.gba=%.map) build/

clean: mostlyclean
	$(MAKE) -C payload clean
	@$(foreach tool,$(TOOLDIRS),$(MAKE) clean -C $(tool);)

tools:
	@$(foreach tool,$(TOOLDIRS),$(MAKE) -C $(tool);)

ifeq ($(NODEP),1)
$(OBJ_DIR)/asm/%.o: asm_dep :=
$(OBJ_DIR)/src/%.o: c_dep :=
$(OBJ_DIR)/data/%.o: data_dep :=
else
$(OBJ_DIR)/asm/%.o: asm_dep = $(shell $(SCANINC) -I include $*.s)
$(OBJ_DIR)/src/%.o: c_dep = $(shell $(SCANINC) -I include $*.c)
$(OBJ_DIR)/data/%.o: data_dep = $(shell $(SCANINC) -I include $*.s)
endif

$(ASM_OBJS): $(OBJ_DIR)/%.o: %.s $$(asm_dep)
	$(AS) $(ASFLAGS) -o $@ $<

$(C_OBJS): $(OBJ_DIR)/%.o: %.c $$(c_dep)
	$(CPP) $(CPPFLAGS) -o $(OBJ_DIR)/$*.i $<
	$(PREPROC) $(OBJ_DIR)/$*.i charmap.txt | $(CC1) $(CFLAGS) -o $(OBJ_DIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(OBJ_DIR)/$*.s

$(DATA_ASM_OBJS): $(OBJ_DIR)/%.o: %.s $$(data_dep)
	$(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) | $(AS) $(ASFLAGS) -o $@

.PHONY: FORCE_DEBUG_GRAPHICS
FORCE_DEBUG_GRAPHICS:

# Always preprocess this small wrapper so switching debug modes removes assets.
$(OBJ_DIR)/data/debug_graphics.o: data_dep :=
$(OBJ_DIR)/data/debug_graphics.o: FORCE_DEBUG_GRAPHICS
ifeq (1,$(DEBUG_TESTING))
$(OBJ_DIR)/data/debug_graphics.o: assets/debug/debug_bg_tiles.bin assets/debug/debug_obj_tiles.bin
$(OBJ_DIR)/data/debug_graphics.o: $(addprefix assets/debug/debug_bg,0_tilemap.bin 1_tilemap.bin 2_tilemap.bin 3_tilemap.bin)
endif
$(OBJ_DIR)/asm/crt0.o: FORCE_DEBUG_GRAPHICS

# Keep direct `make rom` builds current even when include scanning is disabled.
$(OBJ_DIR)/data/payload.o: $(PAYLOADLZ)

$(OBJ_DIR)/ld_script.ld: ld_script.txt
	cd $(OBJ_DIR) && sed "s#tools/#../../tools/#g" ../../$< > ld_script.ld

$(ELF): $(OBJ_DIR)/ld_script.ld $(ALL_OBJS)
	cd $(OBJ_DIR) && $(LD) -Map ../../$(NAME).map -T ../../$< -o ../../$@ $(LIBS)
	$(GBAFIX) $@ -cAGBJ -m01 -r0 --silent

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@
	$(GBAFIX) $@ --silent

%.lz: %
	$(GBAGFX) $< $@

ifeq (1,$(DEBUG_TEST))
payload: $(DEBUG_TEST_ISLAND_AGB)
endif

payload:
	@$(MAKE) -C payload COMPARE=$(COMPARE) NONMATCHING=$(NONMATCHING) DEBUG_TEST=$(DEBUG_TEST) DEBUG_TESTING=$(DEBUG_TESTING) PYTHON=$(PYTHON)

# objdiff passes the configured base object path to make. Forward every split
# source object to the payload build and always recompile it, so header-only
# edits are reflected even though dependency scanning is disabled for this goal.
.PHONY: FORCE_OBJDIFF_BASE
FORCE_OBJDIFF_BASE:

payload/build/payload/src/%.o: payload/src/%.c payload/Makefile FORCE_OBJDIFF_BASE
	@$(MAKE) -B -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/src/$*.o

payload/build/payload/asm/gflib/syscalls.o: payload/asm/gflib/syscalls.s payload/asm/gflib/syscalls.inc payload/Makefile
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/asm/gflib/syscalls.o

# Forward the recovered archive-member source objects to the payload build.
payload/build/payload/asm/libgcc/%.o: payload/asm/libgcc/%.s payload/Makefile asm/macros/function.inc
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/asm/libgcc/$*.o

payload/build/payload/src/libc/%.o: payload/src/libc/%.c payload/Makefile
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/src/libc/$*.o

# Build split objdiff targets for each original translation unit.  Recovered
# data/BSS is attached to the source object that owns it; the all.data target is
# retained as an aggregate layout check.
OBJDIFF_DIR := payload/build/objdiff
OBJDIFF_TEXT_OBJ := payload/build/payload/asm/all.o
OBJDIFF_C_UNITS := main interrupt m_msg lib audio m_msg_util game joyboot \
	island_program m_msg_sprite multisio island_field building \
	animated_field_obj field_obj islander item falling_fruit entity player_hand \
	sound
OBJDIFF_DATA_UNITS := time_palette msg_data world_pal sound_data
OBJDIFF_SECTION_CODE_UNITS := main interrupt m_msg lib joyboot island_program \
	m_msg_sprite multisio island_field building animated_field_obj field_obj \
	islander item falling_fruit entity player_hand sound
OBJDIFF_SECTION_UNITS := $(OBJDIFF_SECTION_CODE_UNITS) $(OBJDIFF_DATA_UNITS) data
OBJDIFF_TEXT_UNITS := $(OBJDIFF_C_UNITS) syscalls
OBJDIFF_TEXT_ASM := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .text.target.s,$(OBJDIFF_TEXT_UNITS)))
OBJDIFF_TEXT_RAW := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .text.raw.o,$(OBJDIFF_TEXT_UNITS)))
OBJDIFF_TEXT_TARGETS := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .text.target.o,$(OBJDIFF_TEXT_UNITS)))
OBJDIFF_DATA_ASM := $(OBJDIFF_DIR)/all.data.target.s
OBJDIFF_DATA_TARGET := $(OBJDIFF_DIR)/all.data.target.o
OBJDIFF_UNIT_DATA_ASM := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .data.target.s,$(OBJDIFF_SECTION_UNITS)))
OBJDIFF_CODE_DATA_TARGETS := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .data.target.o,$(OBJDIFF_SECTION_CODE_UNITS)))
OBJDIFF_COMBINED_TARGETS := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .target.o,$(OBJDIFF_SECTION_CODE_UNITS)))
OBJDIFF_DATA_ONLY_TARGETS := $(addprefix $(OBJDIFF_DIR)/,$(addsuffix .target.o,$(OBJDIFF_DATA_UNITS)))
OBJDIFF_DATA_COMMON_TARGET := $(OBJDIFF_DIR)/data.target.o
OBJDIFF_DATA_COMMON_BASE := $(OBJDIFF_DIR)/data.base.o
OBJDIFF_COMPILED_BASE := $(addprefix payload/build/payload/src/,$(addsuffix .o,$(OBJDIFF_C_UNITS))) payload/build/payload/asm/gflib/syscalls.o
OBJDIFF_COMPILED_DATA_BASE := $(addprefix payload/build/payload/src/,$(addsuffix .o,$(OBJDIFF_DATA_UNITS))) payload/build/payload/src/data.o
OBJDIFF_BASE := $(OBJDIFF_DIR)/all.base.o
OBJDIFF_TEXT_DEPS := payload/asm/all.s asm/macros/function.inc constants/gba_constants.inc
OBJDIFF_LIBGCC_NAMES := _call_via_rX _divsi3 _dvmd_tls _modsi3 _udivsi3 _umodsi3
OBJDIFF_LIBC_NAMES := memcpy memset
OBJDIFF_LIBGCC_TARGETS := $(addprefix $(OBJDIFF_DIR)/libgcc/,$(addsuffix .o,$(OBJDIFF_LIBGCC_NAMES)))
OBJDIFF_LIBC_TARGETS := $(addprefix $(OBJDIFF_DIR)/libc/,$(addsuffix .o,$(OBJDIFF_LIBC_NAMES)))

$(OBJDIFF_TEXT_OBJ): $(OBJDIFF_TEXT_DEPS)
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/asm/all.o

$(OBJDIFF_TEXT_ASM): $(OBJDIFF_DIR)/%.text.target.s: payload/asm/all.s tools/generate_objdiff_text.py
	@$(PYTHON) tools/generate_objdiff_text.py --unit $* --output $@

$(OBJDIFF_TEXT_RAW): $(OBJDIFF_DIR)/%.text.raw.o: $(OBJDIFF_DIR)/%.text.target.s $(OBJDIFF_TEXT_DEPS)
	@cd payload && $(AS) $(ASFLAGS) -o build/objdiff/$*.text.raw.o build/objdiff/$*.text.target.s

$(OBJDIFF_TEXT_TARGETS): $(OBJDIFF_DIR)/%.text.target.o: $(OBJDIFF_DIR)/%.text.raw.o tools/prepare_objdiff_target.py tools/generate_objdiff_sections.py payload/ld_script.txt Makefile
	@$(PYTHON) tools/prepare_objdiff_target.py $< $@

$(OBJDIFF_UNIT_DATA_ASM): $(OBJDIFF_DIR)/%.data.target.s: tools/generate_objdiff_sections.py payload/data/data.bin $(OBJDIFF_TEXT_OBJ)
	@$(PYTHON) tools/generate_objdiff_sections.py --text-object $(OBJDIFF_TEXT_OBJ) --data payload/data/data.bin --unit $* --output $@

$(OBJDIFF_CODE_DATA_TARGETS): $(OBJDIFF_DIR)/%.data.target.o: $(OBJDIFF_DIR)/%.data.target.s
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJDIFF_COMBINED_TARGETS): $(OBJDIFF_DIR)/%.target.o: $(OBJDIFF_DIR)/%.text.target.o $(OBJDIFF_DIR)/%.data.target.o
	$(LD) -r -S -o $@ $^

$(OBJDIFF_DATA_ONLY_TARGETS): $(OBJDIFF_DIR)/%.target.o: $(OBJDIFF_DIR)/%.data.target.s
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJDIFF_DATA_COMMON_TARGET): $(OBJDIFF_DIR)/data.data.target.s
	$(AS) $(ASFLAGS) -o $@ $<

$(OBJDIFF_DATA_COMMON_BASE): payload/build/payload/src/data.o payload/objdiff_data_common.ld
	$(LD) -r -d -S -T payload/objdiff_data_common.ld -o $@ $<

$(OBJDIFF_DATA_ASM): tools/generate_objdiff_sections.py payload/data/data.bin $(OBJDIFF_TEXT_OBJ)
	@$(PYTHON) tools/generate_objdiff_sections.py --text-object $(OBJDIFF_TEXT_OBJ) --data payload/data/data.bin --output $@

$(OBJDIFF_DATA_TARGET): $(OBJDIFF_DATA_ASM)
	$(AS) $(ASFLAGS) -o $@ $<

# Use the installed agbcc archives as the objdiff targets.  These paths and
# filenames preserve the original library member boundaries exactly.
$(OBJDIFF_LIBGCC_TARGETS): $(OBJDIFF_DIR)/libgcc/%.o: tools/agbcc/lib/libgcc.a
	@mkdir -p $(@D)
	@cd $(@D) && $(AR) x $(abspath $<) $*.o

$(OBJDIFF_LIBC_TARGETS): $(OBJDIFF_DIR)/libc/%.o: tools/agbcc/lib/libc.a
	@mkdir -p $(@D)
	@cd $(@D) && $(AR) x $(abspath $<) $*.o

# agbcc emits tentative globals such as gGameState as COMMON.  Assign them to
# BSS in an objdiff-only relocatable link so they participate in data matching.
# Each individual object retains DWARF; agbcc debug units cannot be merged.
$(OBJDIFF_BASE): $(OBJDIFF_COMPILED_BASE) $(OBJDIFF_COMPILED_DATA_BASE) payload/objdiff_sections.ld
	$(LD) -r -d -S -T payload/objdiff_sections.ld -o $@ $(OBJDIFF_COMPILED_BASE) $(OBJDIFF_COMPILED_DATA_BASE)

.PHONY: check-payload-data
check-payload-data: $(OBJDIFF_BASE) $(OBJDIFF_TEXT_OBJ)
	$(PYTHON) tools/check_data_layout.py

$(PAYLOADLZ): payload
	@:

compare:
	@$(MAKE) COMPARE=1

nonmatching:
	@$(MAKE) NONMATCHING=1 COMPARE=1

###################
### Symbol file ###
###################

symbols: $(SYM)

$(SYM): $(ELF)
	$(OBJDUMP) -t $< | sort -u | grep -E "^0[2389]" | $(PERL) -p -e 's/^(\w{8}) (\w).{6} \S+\t(\w{8}) (\S+)$$/\1 \2 \3 \4/g' > $@
