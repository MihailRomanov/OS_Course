struct CPUFeatures {
	_Bool sFPU;
	_Bool sSSE;
	_Bool sSE2;
	_Bool sHTT;
	_Bool sMPX;
};

struct CPUFeatures inlineasm()
{
	struct CPUFeatures CPU;
	
	__asm {
		mov eax, 1
		cpuid
		mov ebx, CPU
		bt edx, 0
		jnc sSSE
		mov[ebx].sFPU, 1

		sSSE:
		    bt edx, 25
			jnc sSE2
			mov[ebx].sSSE, 1

		sSE2:
			bt edx, 26
			jnc sHTT
			mov[ebx].sSSE2, 1

		sHTT :
			bt edx, 28
			jnc sMPX
			mov[ebx].sHTT, 1

		sMPX :
			mov eax, 7
			mov ecx, 0
			cpuid
			mov edx, CPU
			bt ebx, 14
			jnc exit
			mov[edx].sMPX, 1

			exit:
	}
	return CPU;
}
