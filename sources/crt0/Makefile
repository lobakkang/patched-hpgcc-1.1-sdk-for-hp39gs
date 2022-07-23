

#look for the platform, default to Unix
ifeq ($(OS),Windows_NT)
	PLATFORM=cygwin
else
	PLATFORM=unix-gcc
endif


#Win98 doesn't support the OS variable
#so we check if COMSPEC is not null. COMSPEC points to command.com
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


all: crt0.o MMUglobals.o MMUloader.o

clean:
	rm -rf *.o
	
install: all
	cp *.o *.a MMUld.script $(LIBS_PATH)

doc:

#crt0.o is equivalent of the classical crt0.o of PC
# It contains the _start() function

crt0.o : crt0.c
	$(CC) $(ARM_ELF_CFLAGS) -c $< -o $@ 

MMUglobals.o : MMUglobals.c
	$(CC) $(ARM_ELF_CFLAGS) -c $< -o $@ 

MMUloader.o : MMUloader.c
	$(CC) -mtune=arm920t -mcpu=arm920t -mapcs-32 -mlittle-endian \
		-fomit-frame-pointer -ffixed-r10 -O3 -fno-inline \
		-c $< -o $@ 


depend:
