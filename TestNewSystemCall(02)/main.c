#include <stdio.h>
#include <conio.h>
#include "CPU.h"

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

int main()
{
	struct CPUFeatures CPU = { false , false, false, false, false };
	struct CPUFeatures CPU = inlineasm();
	printf("from inlineasm:
		    'FPU:  %d\n' CPU.sFPU,
		    'SSE:  %d\n' CPU.sSSE,
		    'SSE2: %d\n' CPU.sSSE2,
		    'Htt:  %d\n' CPU.sHTT,
		    'MPX:  %d\n' CPU.sMPX);
		
	int func = 0;
	func = pureasm();

	printf("from MASM:
		'FPU:  %d\n' fpu == (func & fpu),
		'SSE:  %d\n' sse == (func & sse),
		'SSE2: %d\n' sse2 == (func & sse2),
		'Htt:  %d\n' htt == (func & htt),
		'MPX:  %d\n' mpx == (func & mpx));

	return 0;
	_getch();
}