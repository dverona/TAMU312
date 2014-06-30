#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "p7.h"


// store instructions in an indexed list
// Call 5 pipeline instruction from 7 from n to n-4
// Increment n until n == null

void runProgram() {
	int n = 0;
	while (true) {
		instructionFetch(PC);
		if (IR != [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]) {
			// execute n
			IF(IR);
			if (n-1 >= 0) ID(instructionFetch(PC-1));
			if (n-2 >= 0) EX(instructionFetch(PC-2));
			if (n-3 >= 0) MEM(instructionFetch(PC-3));
			if (n-4 >= 0) WB(instructionFetch(PC-4));
		}
		else {
			break;
		}
		incrementPC();
	}
}

// Create Register locks that stop execution when hazards are attempted

// You can create temporary registers between two stages

// check stall function

// 