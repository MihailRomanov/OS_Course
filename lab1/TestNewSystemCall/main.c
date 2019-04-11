#include <windows.h>

NTSTATUS NtMyNewSystemCall(int count)
{
	void** stackFrame = (void*)(&count);
	__asm {
		mov eax, 296
		mov edx, stackFrame
		int 0x2E
	}
}

int main(int argc, char* argv[])
{
	int num = 0;
	if (argc == 2) num = atoi(argv[1]);
	NtMyNewSystemCall(num);
	return 0;
}