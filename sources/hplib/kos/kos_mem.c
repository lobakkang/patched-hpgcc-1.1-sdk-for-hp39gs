//KOS memory mangement

#include "syscall.h"

#ifndef HEAP0   
#define HEAP0 0x0100   
#endif

//modified by Al 19th Oct '04, always use HEAP0 type

void *kos_malloc(SIZE_T size)
{
	return (void *)syscallArg2(mallocEntry, (U32)HEAP0, (U32)size);
}

S32 kos_free(void *pMemory)
{
	if(pMemory == 0)return -1; //if trying to free NULL, return -1
	return (S32)syscallArg1(freeEntry, (U32)pMemory);
}
