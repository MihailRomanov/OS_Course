#pragma once
#include <stdbool.h>
#include <stdio.h>

struct CPUFeatures {
	bool  sFPU;
	bool  sSSE;
	bool sSSE2;
	bool sHTT;
	bool sMPX;
};