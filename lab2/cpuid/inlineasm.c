struct CPUFeatures {
	_Bool FPU;
	_Bool SSE;
	_Bool SSE2;
	_Bool HTT;
	_Bool MPX;
};

struct CPUFeatures inlineasm()
{

	struct CPUFeatures feat;
	__asm {

		mov eax, 1
		cpuid

		mov al, feat.FPU
		bt edx, 0
		setc al
		mov feat.FPU, al

		
		mov al, feat.SSE
		bt edx, 25
		setc al
		mov feat.SSE, al

		mov al, feat.SSE2
		bt edx, 26
		setc al
		mov feat.SSE2, al


		mov al, feat.HTT
		bt edx, 28
		setc al
		mov feat.HTT, al


		mov eax, 7
		mov ecx, 0
		cpuid

		mov al, feat.MPX
		bt ebx, 15
		setc al
		mov feat.MPX, al
	}

	return feat;
}