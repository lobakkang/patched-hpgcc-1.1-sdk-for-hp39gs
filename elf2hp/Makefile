#you must first install libelf in /usr/local/
# if you want to compile this program

CC=gcc
C_FLAGS= -Wall --no-strict-aliasing -O3 -I/usr/local/include


install: all

all: elf2hp 

clean:
	rm -rf elf2hp.exe
	rm -rf *.o

archive: clean
	cd ..; tar cjvf elf2hp.tar.bz2 elf2hp


#elf2hp_old: elf2hp_old.c
#	gcc $(C_FLAGS) $< -o $@


elf2hp: elf2hp.c
	gcc $(C_FLAGS) $< -o $@ -s /usr/local/lib/libelf.a



