ifneq (,$(wildcard /c/devkitPro/devkitARM))
DEVKITPRO := /c/devkitPro
DEVKITARM := /c/devkitPro/devkitARM
endif
TOOLCHAIN := $(DEVKITARM)
COMPARE ?= 0

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
WINDOWS_LOCALAPPDATA := $(subst \,/,$(LOCALAPPDATA))
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

OBJ_DIR := build/$(NAME)

ASM_SRCS := $(wildcard asm/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(OBJ_DIR)/%.o)
C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=$(OBJ_DIR)/%.o)
DATA_ASM_SRCS := $(wildcard data/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(OBJ_DIR)/%.o)

CC1 := tools/agbcc/bin/agbcc
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef
CFLAGS := -O3 -g3 -mthumb-interwork -fhex-asm -Wimplicit -Werror
ASFLAGS := -mcpu=arm7tdmi
LIBS := -L../../tools/agbcc/lib -lgcc -lc

SUBDIRS := asm src data

ALL_OBJS := $(ASM_OBJS) $(C_OBJS) $(DATA_ASM_OBJS)

TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(wildcard tools/*))

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

.PHONY: all rom clean compare tools cleantools mostlyclean payload payload/build/payload/src/all.o

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

payload:
	@$(MAKE) -C payload COMPARE=$(COMPARE) NONMATCHING=$(NONMATCHING)

# objdiff passes the configured base object path to make. Forward that path to
# the payload build and force a compile so header-only edits are reflected too.
payload/build/payload/src/all.o:
	@$(MAKE) -B -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/src/all.o

# Forward the recovered archive-member source objects to the payload build.
payload/build/payload/asm/libgcc/%.o: payload/asm/libgcc/%.s payload/Makefile asm/macros/function.inc
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/asm/libgcc/$*.o

payload/build/payload/src/libc/%.o: payload/src/libc/%.c payload/Makefile
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/src/libc/$*.o

# Build separate objdiff targets for the original text and the complete raw
# data/BSS.  Keeping the sections in separate units avoids running objdiff's
# expensive byte-level data comparison during normal text matching.
OBJDIFF_DIR := payload/build/objdiff
OBJDIFF_TEXT_OBJ := payload/build/payload/asm/all.o
OBJDIFF_TEXT_TARGET := $(OBJDIFF_DIR)/all.text.target.o
OBJDIFF_DATA_ASM := $(OBJDIFF_DIR)/all.data.target.s
OBJDIFF_DATA_TARGET := $(OBJDIFF_DIR)/all.data.target.o
OBJDIFF_COMPILED_BASE := payload/build/payload/src/all.o
OBJDIFF_BASE := $(OBJDIFF_DIR)/all.base.o
OBJDIFF_TEXT_DEPS := payload/asm/all.s asm/macros/function.inc constants/gba_constants.inc
OBJDIFF_LIBGCC_NAMES := _call_via_rX _divsi3 _dvmd_tls _modsi3 _udivsi3 _umodsi3
OBJDIFF_LIBC_NAMES := memcpy memset
OBJDIFF_LIBGCC_TARGETS := $(addprefix $(OBJDIFF_DIR)/libgcc/,$(addsuffix .o,$(OBJDIFF_LIBGCC_NAMES)))
OBJDIFF_LIBC_TARGETS := $(addprefix $(OBJDIFF_DIR)/libc/,$(addsuffix .o,$(OBJDIFF_LIBC_NAMES)))

$(OBJDIFF_TEXT_OBJ): $(OBJDIFF_TEXT_DEPS)
	@$(MAKE) -C payload DEVKITPRO=$(if $(wildcard /c/devkitPro),/c/devkitPro,$(DEVKITPRO)) DEVKITARM=$(if $(wildcard /c/devkitPro/devkitARM),/c/devkitPro/devkitARM,$(DEVKITARM)) build/payload/asm/all.o

$(OBJDIFF_TEXT_TARGET): $(OBJDIFF_TEXT_OBJ) tools/prepare_objdiff_target.py
	@$(PYTHON) tools/prepare_objdiff_target.py $< $@

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
$(OBJDIFF_BASE): $(OBJDIFF_COMPILED_BASE)
	$(LD) -r -d -o $@ $<

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
