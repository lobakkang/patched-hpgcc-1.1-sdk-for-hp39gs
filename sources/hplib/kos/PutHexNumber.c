#include "syscall.h"

void kos_PutHexNumber(U32 dx, U32 dy, U32 value)
{
	syscallArg3(PutHexNumberEntry, (U32)dx, (U32)dy, (U32)value);
}
