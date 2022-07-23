SRC = $(shell echo *.c)

OBJ=$(SRC:%.c=%.o)



all: $(OBJ)

clean:
	@rm -rf *.o *.a

%.o : %.c
	@$(CC) ${ARM_ELF_CFLAGS} -I.. -c $< -o $@

depend:
	@$(CC) ${ARM_ELF_CFLAGS} -MM -I. -I.. $(SRC) > Dependencies

include Dependencies
