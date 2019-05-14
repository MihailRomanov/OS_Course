#include "exp.h"

NTSTATUS NtMyNewSystemCall(int Count)
{
	int i;
	static long callCount = 1;	
	
	for (i = 0; i < Count; i++)
	{
		DbgPrint("!!!!WRK NtMyNewSystemCall: %d\n", callCount);
	}
	
	callCount++;
	
	return STATUS_SUCCESS;
} 
