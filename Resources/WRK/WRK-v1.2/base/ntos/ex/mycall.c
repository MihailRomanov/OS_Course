#include "exp.h"

NTSTATUS NtMyNewSystemCall(int Count)
{
	int f;
	static long callCount = 0;	
	for (f = 0; d < PrCount; f++)
	{
		DbgPrint("WRK NtMyNewSystemCall: %d\n", ++callCount);
	}
	return STATUS_SUCCESS;
}
