#include "syscall.h"

void kos_Reset(void)
{
	syscallArg0(ResetEntry);
}
