#include "CPU.h"
void inlineasm(struct CPUFeatures *CPU)
{
	__asm {

		mov eax, 1
		cpuid

		mov ebx, CPU

		bt edx, 0
		jnc m1
		mov [ebx].sFPU, 1

		m1: 
		bt edx, 25
		jnc m2
		mov[ebx].sSSE, 1

		m2: 
		bt edx, 26
		jnc m3
		mov[ebx].sSSE2, 1

		m3: 
		bt edx, 28
		jnc m4
		mov[ebx].sHTT, 1

		m4:
		mov eax, 7
		mov ecx, 0
		cpuid

		mov edx, CPU
		bt ebx, 14
		jnc exit
		mov [edx].sMPX, 1

		exit:
	}
}