#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p4.h"
#include "p5.h"


bool FirstBit(bool input[8]) {
	bool* output = new bool[8];
	bool* one = new bool[8];
	bool out = false;
	one[7] = 1;
	one[6] = one[5] = one[4] = one[3] = one[2] = one[1] = one[0] = 0;
	out = Eightto1bit(out, and8(output, input, one));
	return out;
}


bool* multu(bool* output, bool input1[8], bool input2[8]) {
	bool* ans = new bool[16];
	bool* tmp = new bool[16];
	//bool* input1 = new bool[8];
	//bool* input2 = new bool[8];
	ans[0] = ans[1] = ans[2] = ans[3] = ans[4] = ans[5] = ans[6] = ans[7] = ans[8] = ans[9] = ans[10] = ans[11] = ans[12] = ans[13] = ans[14] = ans[15] = 0;

	//input1 = invert(i1);
	//input2 = invert(i2);


	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux16(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	output[15] = ans[0];
	output[14] = ans[1];
	output[13] = ans[2];
	output[12] = ans[3];
	output[11] = ans[4];
	output[10] = ans[5];
	output[9] = ans[6];
	output[8] = ans[7];
	output[7] = ans[8];
	output[6] = ans[9];
	output[5] = ans[10];
	output[4] = ans[11];
	output[3] = ans[12];
	output[2] = ans[13];
	output[1] = ans[14];
	output[0] = ans[15];

	return output;
}


bool* divu(bool* output, bool dividend[8], bool input2[8]) {
	bool* divisor = new bool[16];
	bool* ans = new bool[16];
	bool* gt8 = new bool[8];
	bool* one = new bool[8];
	one[7] = one[6] = one[5] = one[4] = one[3] = one[2] = one[1] = 0;
	one[0] = 1;
	bool gt = false;
	divisor[0] = input2[7];
	divisor[1] = input2[6];
	divisor[2] = input2[5];
	divisor[3] = input2[4];
	divisor[4] = input2[3];
	divisor[5] = input2[2];
	divisor[6] = input2[1];
	divisor[7] = input2[0];


	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	divisor = shiftRight16(divisor, divisor);
	ans = shiftLeft(ans, ans);
	gt = Eightto1bit(gt, greaterthan(gt8, dividend, divisor));
	dividend = mux(dividend, gt, subu(dividend, dividend, divisor), dividend);
	ans = mux(ans, gt, addu(ans, ans, one), ans);

	output[0] = ans[0];
	output[1] = ans[1];
	output[2] = ans[2];
	output[3] = ans[3];
	output[4] = ans[4];
	output[5] = ans[5];
	output[6] = ans[6];
	output[7] = ans[7];
	output[8] = ans[8];
	output[9] = ans[9];
	output[10] = ans[10];
	output[11] = ans[11];
	output[12] = ans[12];
	output[13] = ans[13];
	output[14] = ans[14];
	output[15] = ans[15];

	return output;
}


// Multiply and Divide Signed

bool* mult(bool* output, bool input1[8], bool input2[8]) {
	bool* ans = new bool[8];
	bool* tmp = new bool[8];
	//bool* input1 = new bool[8];
	//bool* input2 = new bool[8];
	ans[0] = ans[1] = ans[2] = ans[3] = ans[4] = ans[5] = ans[6] = ans[7] = 0;

	//input1 = invert(i1);
	//input2 = invert(i2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);

	tmp = addu(tmp, ans, input1);
	ans = mux(ans, input2[7], tmp, ans);
	input1 = shiftLeft(input1, input1);
	input2 = shiftRight(input2, input2);


	output[0] = ans[0];
	output[1] = ans[1];
	output[2] = ans[2];
	output[3] = ans[3];
	output[4] = ans[4];
	output[5] = ans[5];
	output[6] = ans[6];
	output[7] = ans[7];

	return output;
}


bool* div(bool* output, bool input1[8], bool input2[8]) {
  // TODO
	return output;
}
