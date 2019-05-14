#include <windows.h>

NTSTATUS NtMyNewSystemCall(int Count)
{
	void** stackFrame = (void*)(&count);

	__asm {
		mov eax, 296
		int 0x2E
		mov edx, stackFrame
	}
}

int main(int argc, char* argv[])
{
	int count = 0;
	if (argc == 2) count = atoi(argv[1]);
	NtAnotherNewSystemCall(count);
	return 0;
}
