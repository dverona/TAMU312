// CSCE 312-100
// Summer I 2014
// David Verona
// a3.cpp
#include "a2.cpp"
#include "a4.cpp"
#include "a5.cpp"
#include <iostream>

// Global variable for Counter

bool* alu(bool instruction[8], bool input1[8], bool input2[8]) {
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
	bool* output = new bool[8];

	alu0 = And8(alu0, instruction, Add(output, input1, input2));
	alu1 = And8(alu1, instruction, Sub(output, input1, input2));
	alu2 = And8(alu2, instruction, Negate(&output, input1));
	alu3 = And8(alu3, instruction, Equal(output, input1, input2));
	alu4 = And8(alu4, instruction, LessThan(output, input1, input2));
	alu5 = And8(alu5, instruction, GreaterThan(output, input1, input2));
	alu6 = And8(alu6, instruction, And8(output, input1, input2));
	alu7 = And8(alu7, instruction, Or8(output, input1, input2));
	alu8 = And8(alu8, instruction, ShiftLeft(output, input1));
	alu9 = And8(alu9, instruction, ShiftRight(output, input1));
	alu10 = And8(alu10, instruction, Multu(output, input1, input2));
	alu11 = And8(alu11, instruction, Mult(output, input1, input2));
	alu12 = And8(alu12, instruction, Divu(output, input1, input2));
	alu13 = And8(alu13, instruction, Div(output, input1, input2));
	alu16 = And8(alu16, instruction, Addu(output, input1, input2));
	alu17 = And8(alu17, instruction, Subu(output, input1, input2));

	//Or everything together for the answer
	output = Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, Or8(output, alu0, alu1), alu2), alu3), alu4), alu5), alu6), alu7), alu8), alu9), alu10), alu11), alu12), alu13), alu16), alu17);
	return output;
}

int main() {
	return 0;
}
