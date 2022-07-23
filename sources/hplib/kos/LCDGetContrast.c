#include "syscall.h"

U32 kos_LCDGetContrast(void)
{
	return (U32)syscallArg0(LCDGetContrastEntry);
}
