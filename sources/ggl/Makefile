#look for the platform, default to Unix
ifeq ($(OS),Windows_NT)
	PLATFORM=cygwin
else
	PLATFORM=unix-gcc
endif


#Win98 doesn't support the OS variable
#so we check if COMSPEC is set. If so, should be windows.
ifneq ($(COMSPEC),)
	PLATFORM=cygwin
endif



#look for HPGCC PATH
ifndef HPGCC_PATH
	export HPGCC_PATH=$(shell pwd)/../..
endif

INCLUDE_PATH=$(HPGCC_PATH)/include
LIBS_PATH=$(HPGCC_PATH)/lib

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


ifeq ($(PLATFORM),cygwin)
endif

export CUR_DIR= $(shell pwd)
export ARM_ELF_CFLAGS= -mtune=arm920t -mcpu=arm920t \
	-mapcs-32 -msingle-pic-base -fpic -mpic-register=r10 \
	-mlittle-endian -fomit-frame-pointer -msoft-float -Wall \
	-Os 
export ARM_ELF_ASFLAGS= -EL -k -mcpu=arm920t -mno-fpu -mapcs-32
export ARM_ELF_LDFLAGS= -nodefaultlibs -nostdlib

TARGET=ggl
LIBTARGET= lib$(TARGET).a
MODULES = ggl

all: $(LIBTARGET)

clean:
	@for I in ${MODULES}; do cd $$I && $(MAKE) $@ && cd ..; done;
	@rm -rf $(LIBTARGET)
	@rm -rf doc/

install: all
	cp $(LIBTARGET) $(LIBS_PATH)
	cp *.h $(INCLUDE_PATH)

doc:
	doxygen


$(LIBTARGET) : */*.c
	@for I in ${MODULES}; do cd $$I && $(MAKE) && cd ..; done;
	$(AR) rcv $(LIBTARGET) */*.o

depend:
	@for I in ${MODULES}; do cd $$I && $(MAKE) $@ && cd ..; done;
