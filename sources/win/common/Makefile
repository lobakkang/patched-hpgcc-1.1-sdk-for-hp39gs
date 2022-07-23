
INCLUDE_PATH=$(HPGCC_PATH)/include

SRC = $(shell echo *.c)

OBJ=$(SRC:%.c=%.o)

all: $(OBJ)

clean:
	@rm -rf *.o *.a

%.o : %.c
	@$(CC) ${ARM_ELF_CFLAGS} -I.. -I../../hplib -I../../hpg -c $< -o $@

depend:
	@$(CC) ${ARM_ELF_CFLAGS} -MM -I.. -I../../hplib -I../../hpg $(SRC) > Dependencies

include Dependencies
