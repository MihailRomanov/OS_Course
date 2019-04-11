#include "exp.h"

NTSTATUS NtMyNewSystemCall(int count)
{
	static long callCount = 0;
	int i;
	for (i = 0; i < count;i++) DbgPrint("WRK NtMyNewSystemCall: %d\n", ++callCount);
	return STATUS_SUCCESS;
}