#include "exp.h"

BOOLEAN NtAnotherNewSystemCall(char string[], int count2)
{
	DbgPrint("%d %s\n", count2, string);
	return TRUE;
}