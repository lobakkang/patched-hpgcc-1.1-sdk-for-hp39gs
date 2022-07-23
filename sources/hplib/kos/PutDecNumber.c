#include "syscall.h"

void kos_PutDecNumber(U32 dx, U32 dy, U32 value, U32 bit)
{
	syscallArg4(PutDecNumberEntry, (U32)dx, (U32)dy, (U32)value, (U32)bit);
}
