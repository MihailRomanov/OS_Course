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
	struct CPUFeatures CPU;
	inlineasm(&CPU);
	//inlineasm:
	printf("CPU technology:\n\nx87 FPU: %d\nSSE: %d\nSSE2: %d\nHyper-threading: %d\nIntel MPX: %d\n", CPU.FPU, CPU.SSE, CPU.SSE2, CPU.HTT, CPU.MPX);

	int func = 0;
	func = pureasm();
	//MASM:
	printf("\n\nCPU technology:\n\nx87 FPU: %d\nSSE: %d\nSSE2: %d\nHyper-threading: %d\nIntel MPX: %d\n", FPU == (func & FPU), SSE == (func & SSE), SSE2 == (func & SSE2), HTT == (func & HTT), MPX == (func & MPX));

	return 0;
}
