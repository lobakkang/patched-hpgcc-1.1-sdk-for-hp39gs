#include "syscall.h"

void kos_ClearLcd(void)
{
	syscallArg0(ClearLcdEntry);
}
