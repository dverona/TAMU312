// CSCE 312-100
// Summer I 2014
// David Verona
// a5.cpp
// Helper Functions

bool FirstBit(bool input[8]) {
	bool* output = new bool[8];
	bool* one = new bool[8];
	bool out = false;
	one[7] = 1;
	one[6] = one[5] = one[4] = one[3] = one[2] = one[1] = one[0] = 0;
	out = Eightto1bit(out, And8(output, input, one));
	return out;
}

// Multiply and Divide Unsigned

bool* Multu(bool* output, bool input1[8], bool input2[8]) {
	bool* ans = new bool[8];
	bool* tmp = new bool[8];

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	tmp = Addu(tmp, ans, input1);
	ans = Mux8(ans, FirstBit(input2), tmp, ans);
	input1 = ShiftLeft(input1, input1);
	input2 = ShiftRight(input2, input2);

	output = ans;

	return output;
}

bool* Divu(bool* output, bool dividend[8], bool input2[8]) {
	bool* divisor = new bool[16];
	bool* ans = new bool[8];
	bool* gt8 = new bool[8];
	bool* one = new bool[8];
	one[7] = one[6] = one[5] = one[4] = one[3] = one[2] = one[1] = 0;
	one[0] = 1;
	bool gt = false;
	divisor[0] = input2[0];
	divisor[1] = input2[1];
	divisor[2] = input2[2];
	divisor[3] = input2[3];
	divisor[4] = input2[4];
	divisor[5] = input2[5];
	divisor[6] = input2[6];
	divisor[7] = input2[7];

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	divisor = ShiftRight(divisor, divisor);
	ans = ShiftLeft(ans, ans);
	gt = Eightto1bit(gt, GreaterThan(gt8, dividend, divisor));
	dividend = Mux8(dividend, gt, Subu(dividend, dividend, divisor), dividend);
	ans = Mux8(ans, gt, Addu(ans, ans, one), ans);

	output = ans;
	return output;
}

// Multiply and Divide Signed

bool* Mult(bool* output, bool input1[8], bool input2[8]) {
	
	return output;
}

bool* Div(bool* output, bool input1[8], bool input2[8]) {
	
	return output;
}
