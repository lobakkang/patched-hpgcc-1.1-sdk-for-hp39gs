#include "syscall.h"


U32 kos_PutString(U32 dx, U32 dy, P_VOID ptr)
{
	return (U32)syscallArg3(PutStringEntry, (U32)dx, (U32)dy, (U32)ptr);
}
