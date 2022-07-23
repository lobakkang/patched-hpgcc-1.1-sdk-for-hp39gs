#include "syscall.h"
#include "kos.h"

void kos_KillBeep(void)
{
	syscallArg0(StopBeepEntry);
}

BOOL kos_CheckBeepEnd(void)
{
	return (U32)syscallArg0(CheckBeepEndEntry);
}

S32 kos_beep(U32 freq, TIME_T time, U32 override)
{
	int retval;
	
	if((retval=syscallArg3(beepEntry, (U32)freq, (U32)time, (U32)override)) == SUCCESS)
		while(kos_CheckBeepEnd() == FALSE);
		
	
	return retval;
}
