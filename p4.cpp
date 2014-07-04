#include <iostream>
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p4.h"

bool* add(bool* output, bool input1[8], bool input2[8]) {

	bool* i1 = new bool[8];
	bool* sum = new bool[8];
	// LSB
	input1 = invert(input1);
	input2 = invert(input2);
	bool i17 = input1[7];
	bool i27 = input2[7];
	bool sum7 = Sum(i17, i27, false);
	bool carryOut7 = CarryOut(i17, i27, false);

	// Bit 2
	bool i16 = input1[6];
	bool i26 = input2[6];
	bool sum6 = Sum(i16, i26, carryOut7);
	bool carryOut6 = CarryOut(i16, i26, carryOut7);

	// Bit 3
	bool i15 = input1[5];
	bool i25 = input2[5];
	bool sum5 = Sum(i15, i25, carryOut6);
	bool carryOut5 = CarryOut(i15, i25, carryOut6);

	// Bit 4
	bool i14 = input1[4];
	bool i24 = input2[4];
	bool sum4 = Sum(i14, i24, carryOut5);
	bool carryOut4 = CarryOut(i14, i24, carryOut5);

	// Bit 5
	bool i13 = input1[3];
	bool i23 = input2[3];
	bool sum3 = Sum(i13, i23, carryOut4);
	bool carryOut3 = CarryOut(i13, i23, carryOut4);

	// Bit 6
	bool i12 = input1[2];
	bool i22 = input2[2];
	bool sum2 = Sum(i12, i22, carryOut3);
	bool carryOut2 = CarryOut(i12, i22, carryOut3);

	// Bit 7
	bool i11 = input1[1];
	bool i21 = input2[1];
	bool sum1 = Sum(i11, i21, carryOut2);
	bool carryOut1 = CarryOut(i11, i21, carryOut2);

	// MSB
	bool i10 = input1[0];
	bool i20 = input2[0];
	bool sum0 = Sum(i10, i20, carryOut1);
	bool carryOut0 = CarryOut(i10, i20, carryOut1);

	if (carryOut0) throw;

	// Result
	output[0] = sum7;
	output[1] = sum6;
	output[2] = sum5;
	output[3] = sum4;
	output[4] = sum3;
	output[5] = sum2;
	output[6] = sum1;
	output[7] = sum0;

	return output;
}

bool* sub(bool* output, bool input1[8], bool input2[8]) {
	bool* neg2 = new bool[8];
	negate(neg2, input2);
	add(output, input1, neg2);
	return output;
}

