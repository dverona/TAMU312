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
	bool[8] alu0 = new bool[8];
	bool[8] alu1 = new bool[8];
	bool[8] alu2 = new bool[8];
	bool[8] alu3 = new bool[8];
	bool[8] alu4 = new bool[8];
	bool[8] alu5 = new bool[8];
	bool[8] alu6 = new bool[8];
	bool[8] alu7 = new bool[8];
	bool[8] alu8 = new bool[8];
	bool[8] alu9 = new bool[8];
	bool[8] alu10 = new bool[8];
	bool[8] alu11 = new bool[8];
	bool[8] alu12 = new bool[8];
	bool[8] alu13 = new bool[8];
	bool[8] alu16 = new bool[8];
	bool[8] alu17 = new bool[8];
	bool[8] output = new bool[8];

	alu0 = And8(instruction, Add(output, input1, input2));
	alu1 = And8(instruction, Sub(output, input1, input2));
	alu2 = And8(instruction, Negate(output, input1);
	alu3 = And8(instruction, Equal(output, input1, input2));
	alu4 = And8(instruction, LessThan(output, input1, input2));
	alu5 = And8(instruction, GreaterThan(output, input1, input2));
	alu6 = And8(instruction, And8(output, input1, input2));
	alu7 = And8(instruction, Or8(output, input1, input2));
	alu8 = And8(instruction, ShiftLeft(output, input1));
	alu9 = And8(instruction, ShiftRight(output, input1));
	alu10 = And8(instruction, Multu(output, input1, input2));
	alu11 = And8(instruction, Mult(output, input1, input2));
	alu12 = And8(instruction, Divu(output, input1, input2));
	alu13 = And8(instruction, Div(output, input1, input2));
	alu16 = And8(instruction, Addu(output, input1, input2));
	alu17 = And8(instruction, Subu(output, input1, input2));

	//Or everything together for the answer
	output = Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(Or8(alu0, alu1), alu2), alu3), alu4), alu5), alu6), alu7), alu8), alu9), alu10), alu11), alu12), alu13), alu16), alu17);
	return output;
}
