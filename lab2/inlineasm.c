#include "CPU.h"
void inlineasm(struct CPUFeatures *CPU)
{
	__asm {
		mov eax, 1
		cpuid
		mov ebx, CPU

		xor al, al
		bt edx, 0
		rcl al, 1
		mov [ebx].FPU, al

		xor al, al
		bt edx, 25
		rcl al, 1
		mov [ebx].SSE, al

		xor al, al
		bt edx, 26
		rcl al, 1
		mov [ebx].SSE2, al

		xor al, al
		bt edx, 28
		rcl al, 1
		mov [ebx].HTT, al

		mov eax, 7
		mov ecx, 0
		cpuid

		xor al, al
		bt ebx, 14
		rcl al, 1
		mov ebx, CPU
		mov[ebx].MPX, al

	}
}
