
CUR_DIR= $(shell pwd)

export HPGCC_PATH=$(CUR_DIR)/..

export INCLUDE_PATH=$(HPGCC_PATH)/include
export LIBS_PATH=$(HPGCC_PATH)/lib
export ELF2HP_PATH=$(HPGCC_PATH)/elf2hp

MODULES= crt0 hplib hpg ggl win

ifeq ($(SHELL),)
  $(warning Compiler detection does not work on Windows)
  $(warning Assuming CC_TARGET=arm-elf)
  CC_TARGET=arm-elf
endif

ifeq ($(CC_TARGET),)
  ifneq ($(shell which arm-linux-gcc),)
    CC_TARGET=arm-linux
  else
    ifneq ($(shell which arm-elf-gcc),)
      CC_TARGET=arm-elf
    else
      $(error No compiler found. Check PATH or provide a CC_TARGET)
    endif
  endif
endif

export CC=$(CC_TARGET)-gcc
export AS=$(CC_TARGET)-as
export LD=$(CC_TARGET)-ld
export AR=$(CC_TARGET)-ar

all: libs_install

install: directories all doc

directories:
	mkdir -p ${ELF2HP_PATH}; \
	mkdir -p ${INCLUDE_PATH}; \
	mkdir -p ${LIBS_PATH}; \

clean:
	@for I in ${MODULES}; do cd $$I && $(MAKE) clean && cd ..; done;

archive: doc clean
	cd ..; tar cjvf sources.tar.bz2 sources

small_distrib: all doc
	cd ..; tar cjvf hpgcc_small.tar.bz2 --exclude=sources --exclude=*.bz2 *

distrib: all doc
	cd ..; tar cjvf hpgcc_bin.tar.gz \
	bin/* lib/* include/* 
	sources/* \
	doc_html/*


full_distrib: all doc
	cd ..; tar cjvf hpgcc_full.tar.gz \
	*/*

doc:
	rm -rf ../doc_html; mkdir ../doc_html
	@for I in ${MODULES}; do cd $$I && $(MAKE) doc && cd ..; done;

libs_install:
	@for I in ${MODULES}; do cd $$I && $(MAKE) install && cd ..; done;

depend:
	@for I in $(MODULES); do cd $$I && $(MAKE) depend && cd ..; done;
