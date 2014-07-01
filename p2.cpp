#include "basic_functions.h"
#include <iostream>
#include "p1.h"
#include "p2.h"

bool* Oneto8bit(bool* output, bool input) {
	output[7] = input;
	output[6] = input;
	output[5] = input;
	output[4] = input;
	output[3] = input;
	output[2] = input;
	output[1] = input;
	output[0] = input;
	return output;
}


bool Eightto1bit(bool output, bool* input) {
	output = input[7];
	return output;
}


// 8-bit mux
bool* mux(bool* output, bool operation, bool input1[8], bool input2[8]) {
	output[7] = Mux(operation, input1[7], input2[7]);
	output[6] = Mux(operation, input1[6], input2[6]);
	output[5] = Mux(operation, input1[5], input2[5]);
	output[4] = Mux(operation, input1[4], input2[4]);
	output[3] = Mux(operation, input1[3], input2[3]);
	output[2] = Mux(operation, input1[2], input2[2]);
	output[1] = Mux(operation, input1[1], input2[1]);
	output[0] = Mux(operation, input1[0], input2[0]);
	return output;
}

bool* invert(bool input[8]) {
	bool* out = new bool[8];
	out[0] = input[7];
	out[1] = input[6];
	out[2] = input[5];
	out[3] = input[4];
	out[4] = input[3];
	out[5] = input[2];
	out[6] = input[1];
	out[7] = input[0];
	return out;
}

// 8-bit Addition Unsigned
bool* addu(bool* output, bool input1[8], bool input2[8]) {
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


// 8-bit Negating Function
bool* negate(bool* output, bool input[8]) {
	input = invert(input);
	bool ans[8];
	bool* out = new bool[8];
	ans[0] = Not(input[7]);
	ans[1] = Not(input[6]);
	ans[2] = Not(input[5]);
	ans[3] = Not(input[4]);
	ans[4] = Not(input[3]);
	ans[5] = Not(input[2]);
	ans[6] = Not(input[1]);
	ans[7] = Not(input[0]);
	bool* one = new bool[8];
	one[0] = 1;
	one[7] =one[6] = one[5] = one[4] = one[3] = one[2] = one[1] = 0;
	addu(output, ans, one);
	return output;
}


// 8-bit Subtraction
bool* subu(bool* output, bool input1[8], bool input2[8]) {
	bool* neg2 = new bool[8];
	negate(neg2, input2);
	addu(output, input1, neg2);
	return output;
}


bool equal(bool input1[8], bool input2[8]) {
	bool* neg2 = new bool[8];
	bool* output = new bool[8];
	bool ans = false;
	negate(neg2, input2);
	addu(output, input1, neg2);
	ans = Not(Or(output[7], Or(output[6], Or(output[5], Or(output[4], Or(output[3], Or(output[2], Or(output[1], output[0]))))))));
	return ans;
}


// 8-bit Equality
bool* equal(bool* output, bool input1[8], bool input2[8]) {
	bool* neg2 = new bool[8];
	negate(neg2, input2);
	addu(output, input1, neg2);
	return output;
	//Add bitwise Not
}


bool greaterthan(bool input1[8], bool input2[8]) {
	bool* temp = new bool[8];
	bool ans = false;
	subu(temp, input2, input1);
	ans = Mux(temp[7], 1, 0);
	return ans;
}


// 8-bit Greater-Than
bool* greaterthan(bool* output, bool input1[8], bool input2[8]) {
	// if input1 > input2, input1 - input2 == pos
	bool* temp = new bool[8];
	bool ans = false;
	subu(temp, input1, input2);
	ans = Mux(temp[0], 0, 1);
	output = Oneto8bit(output, ans);
	return output;
}


bool lessthan(bool input1[8], bool input2[8]) {
	bool* temp = new bool[8];
	bool ans = false;
	subu(temp, input1, input2);
	ans = Mux(temp[7], 1, 0);
	return ans;
}


// 8-bit Less-Than
bool* lessthan(bool* output, bool input1[8], bool input2[8]) {
	// if input1 < input2, input1 - input2 == neg
	bool* eq = new bool[8];
	bool* gt = new bool[8];
	bool ans = false;
	equal(eq, input1, input2);
	greaterthan(gt, input1, input2);
	ans = Not(And(eq, gt));
	output = Oneto8bit(output, ans);
	return output;
}


// 8-bit bitwise and
bool* and8(bool* output, bool input1[8], bool input2[8]) {
	output[7] = And(input1[7], input2[7]);
	output[6] = And(input1[6], input2[6]);
	output[5] = And(input1[5], input2[5]);
	output[4] = And(input1[4], input2[4]);
	output[3] = And(input1[3], input2[3]);
	output[2] = And(input1[2], input2[2]);
	output[1] = And(input1[1], input2[1]);
	output[0] = And(input1[0], input2[0]);
	return output;
}


// 8-bit bitwise or
bool* or8(bool* output, bool input1[8], bool input2[8]) {
	output[7] = Or(input1[7], input2[7]);
	output[6] = Or(input1[6], input2[6]);
	output[5] = Or(input1[5], input2[5]);
	output[4] = Or(input1[4], input2[4]);
	output[3] = Or(input1[3], input2[3]);
	output[2] = Or(input1[2], input2[2]);
	output[1] = Or(input1[1], input2[1]);
	output[0] = Or(input1[0], input2[0]);
	return output;
}


// 8-bit left shift
bool* shiftLeft(bool* output, bool input[8]) {
	input = invert(input);
	output[7] = input[1];
	output[6] = input[2];
	output[5] = input[3];
	output[4] = input[4];
	output[3] = input[5];
	output[2] = input[6];
	output[1] = input[7];
	output[0] = 0;
	return output;
}


// 8-bit right shift
bool* shiftRight(bool* output, bool input[8]) {
	input = invert(input);
	output[7] = 0;
	output[6] = input[0];
	output[5] = input[1];
	output[4] = input[2];
	output[3] = input[3];
	output[2] = input[4];
	output[1] = input[5];
	output[0] = input[6];
	return output;	
}
