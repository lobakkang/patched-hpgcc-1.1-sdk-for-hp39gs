SRC = $(shell echo *.c)
AS_SRC = $(shell echo *.s)

OBJ=$(SRC:%.c=%.o)
AS_OBJ=$(AS_SRC:%.s=%.o)


all: $(OBJ) $(AS_OBJ)

clean:
	@rm -rf *.o *.a

%.o : %.c
	@$(CC) ${ARM_ELF_CFLAGS} -I.. -c $< -o $@

%.o : %.s
	@$(AS) ${ARM_ELF_ASFLAGS} $< -o $@

depend:
	@$(CC) ${ARM_ELF_CFLAGS} -MM -I. -I.. $(SRC) > Dependencies

include Dependencies
