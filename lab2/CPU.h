#pragma once
#include <stdbool.h>
#include <stdio.h>

struct CPUFeatures {
	bool FPU;
	bool SSE;
	bool SSE2;
	bool HTT;
	bool MPX;
};
