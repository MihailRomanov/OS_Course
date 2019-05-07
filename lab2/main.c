#include "CPU.h"

void inlineasm(struct CPUFeatures *CPU);
int pureasm();

const int FPU = 1;
const int SSE = 2;
const int SSE2 = 4;
const int HTT = 8;
const int MPX = 16;

int main()
{
	struct CPUFeatures CPU = { false , false, false, false, false };
	inlineasm(&CPU);
	printf("(from inlineasm) CPU supports:\n\nx87 FPU: %d\nSSE: %d\nSSE2: %d\nHyper-threading: %d\nIntel MPX: %d\n", CPU.sFPU, CPU.sSSE, CPU.sSSE2, CPU.sHTT, CPU.sMPX);

	int func = 0;
	func = pureasm();

	printf("\n\n(from MASM) CPU supports:\n\nx87 FPU: %d\nSSE: %d\nSSE2: %d\nHyper-threading: %d\nIntel MPX: %d\n", FPU == (func & FPU), SSE == (func & SSE), SSE2 == (func & SSE2), HTT == (func & HTT), MPX == (func & MPX));

	return 0;
}