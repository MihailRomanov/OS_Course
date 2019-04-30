#include "exp.h"

NTSTATUS NtMyNewSystemCall(int PrCount)
{
	int d;
	static long callCount = 1;	
	for (d = 0; d < PrCount; d++)
	{
		DbgPrint("WRK NtMyNewSystemCall: %d\n", callCount);
	}
	callCount++;
	return STATUS_SUCCESS;
}