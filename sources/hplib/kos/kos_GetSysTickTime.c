//KOS Time functions

// Added by iblank 2004-10-23

#include "syscall.h"
#include "kos.h"

U32 kos_GetSysTickTime(void)
{
	return (U32)syscallArg0(GetSysTickTimeEntry);
}
