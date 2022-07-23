#include <kos.h>

S32 fdelete(P_BYTE fname)
{
	FUNC1PTR	pFunc;

	pFunc = (FUNC1PTR)kos_GetFuncEntry(KOS_MODULE_FILESYSTEM, KOS_FUNC_FDELETE);

	return (S32)((*pFunc)((U32)fname));
}
