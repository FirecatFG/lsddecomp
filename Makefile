# Binaries
GAME_ID         := slps01556
GAME            := lsdde

# Compilers
CROSS           := mipsel-linux-gnu-
AS              := $(CROSS)as
LD              := $(CROSS)ld
CPP				:= $(CROSS)cpp
OBJCOPY         := $(CROSS)objcopy
CC              := ./gcc263/cc1

AS_FLAGS        += -Iinclude -Iinclude/psyq -march=r3000 -mtune=r3000 -no-pad-sections -G8 -O2
CC_FLAGS        += -mips1 -mcpu=3000 -quiet -Wall -fno-builtin -mno-abicalls -funsigned-char -G0 -O2 
CPP_FLAGS       += -Iinclude -Iinclude/psyq -undef -Wall -lang-c -fno-builtin -gstabs
CPP_FLAGS       += -Dmips -D__GNUC__=2 -D__OPTIMIZE__ -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C
MASPSX_FLAGS	:= --dont-force-G0 --expand-div --aspsx-version=2.34 -G8

# Directories
ASM_DIR         := asm
SRC_DIR         := src
INCLUDE_DIR     := include
BUILD_DIR       := build
CONFIG_DIR      := config
TOOLS_DIR       := tools

# Files
LSDDE_ASM_DIRS   := $(ASM_DIR)/$(GAME) $(ASM_DIR)/$(GAME)/data
LSDDE_SRC_DIRS   := $(SRC_DIR)/$(GAME)
LSDDE_S_FILES    := $(foreach dir,	$(LSDDE_ASM_DIRS),	$(wildcard $(dir)/*.s)) \
					$(foreach dir,	$(LSDDE_ASM_DIRS),	$(wildcard $(dir)/**/*.s))
LSDDE_C_FILES    := $(foreach dir,	$(LSDDE_SRC_DIRS),	$(wildcard $(dir)/*.c)) \
					$(foreach dir,	$(LSDDE_SRC_DIRS),	$(wildcard $(dir)/**/*.c))
LSDDE_O_FILES    := $(foreach file,	$(LSDDE_S_FILES),	$(BUILD_DIR)/$(file).o) \
					$(foreach file,	$(LSDDE_C_FILES),	$(BUILD_DIR)/$(file).o)
LSDDE_TARGET     := $(BUILD_DIR)/$(GAME)

# Tooling
PYTHON          := python3
SPLAT_DIR       := $(TOOLS_DIR)/splat
SPLAT_APP       := $(SPLAT_DIR)/split.py
SPLAT           := $(PYTHON) $(SPLAT_APP)
ASMDIFFER_DIR   := $(TOOLS_DIR)/asm-differ
ASMDIFFER_APP   := $(ASMDIFFER_DIR)/diff.py
M2CTX_APP       := $(TOOLS_DIR)/m2ctx.py
M2CTX           := $(PYTHON) $(M2CTX_APP)
M2C_DIR         := $(TOOLS_DIR)/m2c
M2C_APP         := $(M2C_DIR)/m2c.py
M2C             := $(PYTHON) $(M2C_APP)
M2C_ARGS		:= -P 4
MASPSX_DIR      := $(TOOLS_DIR)/maspsx
MASPSX_APP      := $(MASPSX_DIR)/maspsx.py
MASPSX          := $(PYTHON) $(MASPSX_APP) $(MASPSX_FLAGS)

define list_src_files
	$(foreach dir, $(ASM_DIR)/$(GAME),         $(wildcard $(dir)/**.s))
	$(foreach dir, $(ASM_DIR)/$(GAME)/data,    $(wildcard $(dir)/**.s))
	$(foreach dir, $(SRC_DIR)/$(GAME),         $(wildcard $(dir)/**.c))
endef

define list_o_files
	$(foreach file,$(call list_src_files),$(BUILD_DIR)/$(file).o)
endef

define link
	$(LD) -o $(2) \
		-Map $(BUILD_DIR)/$(1).map \
		-T $(1).ld \
		-T $(CONFIG_DIR)/undefined_syms_auto.$(GAME_ID).$(1).txt \
		-T $(CONFIG_DIR)/undefined_funcs_auto.$(GAME_ID).$(1).txt \
		--no-check-sections \
		-nostdlib \
		-s
endef

all: build check
build: lsdde
clean:
	git clean -fdx asm/
	git clean -fdx $(BUILD_DIR)
	git clean -fX config/
format:
	clang-format -i $$(find $(SRC_DIR)/ -type f -name "*.c")
	clang-format -i $$(find $(SRC_DIR)/ -type f -name "*.h")
	clang-format -i $$(find $(INCLUDE_DIR)/ -type f -name "*.h")
check:
	sha1sum --check config/check.$(GAME_ID).sha
expected: check
	rm -rf expected/build
	cp -r build expected/

$(GAME).elf: $(LSDDE_O_FILES)
	$(LD) -o $@ \
	-Map $(LSDDE_TARGET).map \
	-T $(GAME).ld \
	-T $(CONFIG_DIR)/undefined_syms_auto.$(GAME_ID).$(GAME).txt \
	--no-check-sections \
	-nostdlib \
	-s

lsdde: $(BUILD_DIR)/SLPS_015.56
$(BUILD_DIR)/SLPS_015.56: $(BUILD_DIR)/$(GAME).elf
	$(OBJCOPY) -O binary $< $@
$(BUILD_DIR)/$(GAME).elf: $(call list_o_files)
	$(call link,lsdde,$@)

dirs:
	$(foreach dir,$(LSDDE_ASM_DIRS) $(LSDDE_SRC_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

$(BUILD_DIR)/%.elf: $$(call list_o_files,$$*)
	$(call link,$*,$@)

extract: extract_lsdde
extract_lsdde: require-tools dirs
	$(SPLAT) $(CONFIG_DIR)/splat.slps01556.lsdde.yaml

decompile: $(M2C_APP)
		$(M2CTX) $(SRC_DIR)/$(GAME)/$(FILE).c
		$(M2C) $(M2C_ARGS) --target mipsel-gcc-c --context ctx.c $(ASM_DIR)/$(GAME)/nonmatchings/$(FILE)/$(FUNC).s

require-tools: $(SPLAT_APP) $(ASMDIFFER_APP)
update-dependencies: require-tools $(M2CTX_APP) $(M2C_APP)
	pip3 install -r $(TOOLS_DIR)/requirements.txt

$(SPLAT_APP):
	git submodule init $(SPLAT_DIR)
	git submodule update $(SPLAT_DIR)
	pip3 install -r $(SPLAT_DIR)/requirements.txt
$(ASMDIFFER_APP):
	git submodule init $(ASMDIFFER_DIR)
	git submodule update $(ASMDIFFER_DIR)
$(M2CTX_APP):
	curl -o $@ https://raw.githubusercontent.com/ethteck/m2ctx/main/m2ctx.py
$(M2C_APP):
	git submodule init $(M2C_DIR)
	git submodule update $(M2C_DIR)
	python3 -m pip install --upgrade pycparser
$(MASPSX_APP):
	git submodule init $(MASPSX_DIR)
	git submodule update $(MASPSX_DIR)

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<
$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o -Map %.map $@ $<
$(BUILD_DIR)/%.c.o: %.c $(MASPSX_APP)
	$(CPP) $(CPP_FLAGS) $< | $(CC) $(CC_FLAGS) | $(MASPSX) | $(AS) $(AS_FLAGS) -o $@

SHELL = /bin/bash -e -o pipefail

.PHONY: all, clean, format, check, expected
.PHONY: lsdde
.PHONY: extract_lsdde
.PHONY: require-tools, update-dependencies
