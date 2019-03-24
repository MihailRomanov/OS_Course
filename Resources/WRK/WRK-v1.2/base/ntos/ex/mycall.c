#include "exp.h"

NTSTATUS NtMyNewSystemCall(int PrCount)
{
	int i;
	static long callCount = 1;	
	for (i = 0; i < PrCount; i++)
	{
		DbgPrint("WRK NtMyNewSystemCall: %d\n", callCount);
	}
	callCount++;
	return STATUS_SUCCESS;
}