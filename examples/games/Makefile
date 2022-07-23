INCLUDE_PATH= ../../include
LIBS_PATH= ../../lib
ELF2HP_PATH=../../elf2hp
export CUR_DIR= $(shell pwd)
export CC= arm-elf-gcc
export C_FLAGS= -mtune=arm920t -mcpu=arm920t \
	-mapcs-32 -fPIC -mpic-register=r10 -msingle-pic-base \
	-mlittle-endian -fomit-frame-pointer -Wall \
	-Os -I$(INCLUDE_PATH) -L$(LIBS_PATH)
export LD= arm-elf-ld
export LD_FLAGS= -L$(LIBS_PATH) -T MMUld.script $(LIBS_PATH)/crt0.o 
export LIBS= -lhpg -lhplib -lgcc
export AR= arm-elf-ar
export ELF2HP= elf2hp.exe

SRC = $(shell echo *.c)

OBJ = $(SRC:%.c=%.o)

EXE = $(SRC:%.c=%.exe)

HP = $(SRC:%.c=%.hp)

all: $(HP)

install: all

clean:
	rm -rf *.o *.hp *.exe

archive: clean
	cd ..; tar cjvf examples.tar.bz2 examples


%.o: %.c
	$(CC) $(C_FLAGS) -c $<

%.exe: %.o
	$(LD) $(LD_FLAGS) $< $(LIBS) -o $@

%.hp: %.exe
	$(ELF2HP) $< $@



