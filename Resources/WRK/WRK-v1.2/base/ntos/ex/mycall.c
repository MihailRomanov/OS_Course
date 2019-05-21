#include "exp.h"

NTSTATUS NtMyNewSystemCall(int Count)
{
	static long callCount = 0;
	for (int i = 0; i < Count; i++)
	{
		DbgPrint("WR NtMyNewSystemCall: %d\n", ++callCount);
	}
	return STATUS_SUCCESS;
}
