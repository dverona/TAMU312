#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "test_utils.h"
#include <iostream>


bool* alu(bool instruction[8], bool* output, bool input1[8], bool input2[8]) {
	//and instruction with each condition, or solutions
	bool* alu0 = new bool[8];
	bool* alu1 = new bool[8];
	bool* alu2 = new bool[8];
	bool* alu3 = new bool[8];
	bool* alu4 = new bool[8];
	bool* alu5 = new bool[8];
	bool* alu6 = new bool[8];
	bool* alu7 = new bool[8];
	bool* alu8 = new bool[8];
	bool* alu9 = new bool[8];
	bool* alu10 = new bool[8];
	bool* alu11 = new bool[8];
	bool* alu12 = new bool[8];
	bool* alu13 = new bool[8];
	bool* alu16 = new bool[8];
	bool* alu17 = new bool[8];
	bool* temp1 = new bool[8];
	temp1[0] = temp1[1] = temp1[2] = temp1[3] = temp1[4] = temp1[6] = temp1[7] = 0;
	temp1[5] = 1;
	bool* temp2 = new bool[8];
	bool* temp3 = new bool[8];

	alu0[0] = alu0[1] = alu0[2] = alu0[3] = alu0[4] = alu0[5] = alu0[6] = alu0[7] = 0;

	alu1[1] = alu1[2] = alu1[3] = alu1[4] = alu1[5] = alu1[6] = alu1[7] = 0;
	alu1[0] = 1;

	alu2[0] = alu2[2] = alu2[3] = alu2[4] = alu2[5] = alu2[6] = alu2[7] = 0;
	alu2[1] = 1;

	alu3[2] = alu3[3] = alu3[4] = alu3[5] = alu3[6] = alu3[7] = 0;
	alu3[0] = alu3[1] = 1;

	alu4[0] = alu4[1] = alu4[3] = alu4[4] = alu4[5] = alu4[6] = alu4[7] = 0;
	alu4[2] = 1;

	alu5[1] = alu5[3] = alu5[4] = alu5[5] = alu5[6] = alu5[7] = 0;
	alu5[0] = alu5[2] = 1;

	alu6[0] = alu6[3] = alu6[4] = alu6[5] = alu6[6] = alu6[7] = 0;
	alu6[1] = alu6[2] = 1;

	alu7[3] = alu7[4] = alu7[5] = alu7[6] = alu7[7] = 0;
	alu7[0] = alu7[1] = alu7[2] = 1;

	alu8[0] = alu8[1] = alu8[2] = alu8[4] = alu8[5] = alu8[6] = alu8[7] = 0;
	alu8[3] = 1;

	alu9[1] = alu9[2] = alu9[4] = alu9[5] = alu9[6] = alu9[7] = 0;
	alu9[0] = alu9[3] = 1;

	alu10[0] = alu10[2] = alu10[4] = alu10[5] = alu10[6] = alu10[7] = 0;
	alu10[1] = alu10[3] = 1;

	alu11[2] = alu11[4] = alu11[5] = alu11[6] = alu11[7] = 0;
	alu11[0] = alu11[1] = alu11[3] = 1;

	alu12[0] = alu12[1] = alu12[4] = alu12[5] = alu12[6] = alu12[7] = 0;
	alu12[2] = alu12[3] = 1;

	alu13[1] = alu13[4] = alu13[5] = alu13[6] = alu13[7] = 0;
	alu13[0] = alu13[2] = alu13[3] = 1;

	alu16[0] = alu16[1] = alu16[2] = alu16[3] = alu16[5] = alu16[6] = alu16[7] = 0;
	alu16[4] = 1;

	alu17[1] = alu17[2] = alu17[3] = alu17[5] = alu17[6] = alu17[7] = 0;
	alu17[0] = alu17[4] = 1;

	/*alu0 = and8(alu0, equal(temp2, instruction, to_bits8(temp1, 0)), add(output, input1, input2));
	alu1 = and8(alu1, equal(temp2, instruction, to_bits8(temp1, 1)), sub(output, input1, input2));
	alu2 = and8(alu2, equal(temp2, instruction, to_bits8(temp1, 2)), negate(output, input1));
	alu3 = and8(alu3, equal(temp2, instruction, to_bits8(temp1, 3)), equal(output, input1, input2));
	alu4 = and8(alu4, equal(temp2, instruction, to_bits8(temp1, 4)), lessthan(output, input1, input2));
	alu5 = and8(alu5, equal(temp2, instruction, to_bits8(temp1, 5)), greaterthan(output, input1, input2));
	alu6 = and8(alu6, equal(temp2, instruction, to_bits8(temp1, 6)), and8(output, input1, input2));
	alu7 = and8(alu7, equal(temp2, instruction, to_bits8(temp1, 7)), or8(output, input1, input2));
	alu8 = and8(alu8, equal(temp2, instruction, to_bits8(temp1, 8)), shiftLeft(output, input1));
	alu9 = and8(alu9, equal(temp2, instruction, to_bits8(temp1, 9)), shiftRight(output, input1));
	alu10 = and8(alu10, equal(temp2, instruction, to_bits8(temp1, 10)), multu(output, input1, input2));
	alu11 = and8(alu11, equal(temp2, instruction, to_bits8(temp1, 11)), mult(output, input1, input2));
	alu12 = and8(alu12, equal(temp2, instruction, to_bits8(temp1, 12)), divu(output, input1, input2));
	alu13 = and8(alu13, equal(temp2, instruction, to_bits8(temp1, 13)), div(output, input1, input2));
	alu16 = and8(alu16, to_bits8(temp1, 16), addu(output, input1, input2));
	alu17 = and8(alu17, equal(temp2, instruction, to_bits8(temp1, 17)), subu(output, input1, input2));
	*/

	printValueInDecimal(instruction);

	if (equal(instruction, alu0)) {
		output = add(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu1)) {
		output = sub(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu2)) {
		output = negate(output, input1);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu3)) {
		output = equal(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu4)) {
		output = lessthan(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu5)) {
		output = greaterthan(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu6)) {
		output = and8(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu7)) {
		output = or8(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu8)) {
		output = shiftLeft(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu9)) {
		output = shiftRight(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu10)) {
		output = multu(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu11)) {
		output = mult(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu12)) {
		output = divu(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu13)) {
		output = div(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu16)) {
		output = addu(output, input1, input2);
		printValueInDecimal(output);
	}

	if (equal(instruction, alu17)) {
		output = subu(output, input1, input2);
		printValueInDecimal(output);
	}
	//Or everything together for the answer
	//temp3 = or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, or8(temp3, alu0, alu1), alu2), alu3), alu4), alu5), alu6), alu7), alu8), alu9), alu10), alu11), alu12), alu13), alu16), alu17);
	/*output[0] = alu16[0];
	output[1] = alu16[1];
	output[2] = alu16[2];
	output[3] = alu16[3];
	output[4] = alu16[4];
	output[5] = alu16[5];
	output[6] = alu16[6];
	output[7] = alu16[7];*/
	return output;
}
