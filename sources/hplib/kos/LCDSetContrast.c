#include "syscall.h"

void kos_LCDSetContrast(U32 contrast)
{
	syscallArg1(LCDSetContrastEntry, (U32)contrast);
}
