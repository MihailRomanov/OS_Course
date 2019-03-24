#include <windows.h>

BOOLEAN NtAnotherNewSystemCall(int count, char string[])
{
	void** stackFrame[2] = { (void*)(&count), (void*)(&string) };
	__asm {
		mov eax, 297
		mov edx - 4, stackFrame
		mov edx, [stackFrame+4]
		int 0x2E
	}
}

int main(int argc, char* argv[])
{
	int count = 5;
	char string[3] = "ok";
	BOOLEAN ret = FALSE;

	NtAnotherNewSystemCall(count, string);
	return 0;
}