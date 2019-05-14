#include <stdio.h>
#include <conio.h>
#define fpu 1
#define sse 2
#define sse2 4
#define htt 8
#define mpx 16


struct CPUFeatures {
	_Bool FPU;
	_Bool SSE;
	_Bool SSE2;
	_Bool HTT;
	_Bool MPX;
};

struct CPUFeatures inlineasm();
int pureasm();

void main()
{
	struct CPUFeatures feat = inlineasm();
	printf("inlineasm:\nFPU %d\nSSE %d\nSSE2 %d\nHTT %d\nMPX %d\n\n", feat.FPU, feat.SSE, feat.SSE2, feat.HTT, feat.MPX);

	int ch = pureasm();
	printf("pureasm: %d\n", ch);
	if ((ch & fpu)= fpu) {
		printf("FPU Supported by the system\n")
	}
	else print("SSE Not supported by system\n")
	if ((ch & sse) == sse) {
		printf("SSE Supported by the system\n")
	}
	else print("SSE Not supported by system\n")
	if ((ch & sse2) == sse2) {
		printf("SSE Supported by the system\n")
	}
	else print("SSE2 Not supported by system\n")
	if ((ch & htt) == htt) {
		printf("HTT Supported by the system\n")
	}
	else print("HTT Not supported by system\n")
	if ((ch & mpx) == mpx) {
		printf("MPX Supported by the system\n")
	}
	else print("MPX Not supported by system\n")
	_getch();
}
