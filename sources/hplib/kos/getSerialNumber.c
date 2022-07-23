
#include "syscall.h"

P_BYTE kos_getSerialNumber(void)
{
	return (P_BYTE)syscallArg0(GetSerialEntry);
}
