<<<<<<< HEAD
// CSCE 312-100
// Summer I 2014
// David Verona
// p1.cpp

#include <iostream>

// Global variable for Counter
int counter = 0;

// Simple 1 Bit And
bool And (bool a, bool b) {
	counter++;
	if (a && b) return 1;
	return 0;
}

// Simple 1 Bit Or
bool Or (bool a, bool b) {
	counter++;
	if (a || b) return 1;
	return 0;
}

// Simple 1 Bit Not
bool Not(bool a) {
	counter++;
	return !a;
}

// Print number of operations used
void PrintFunctionCount() {
	std::cout<<"Function Count:"<<counter;
	return;
}

// Print Bit
void Print(bool a) {
	if (a) std::cout<<"1";
	else std::cout<<"0";
	return;
}

// Print Byte
void Print8(bool* a) {
	if (a[0]) std::cout<<"1";
	else std::cout<<"0";
	if (a[1]) std::cout<<"1";
	else std::cout<<"0";
	if (a[2]) std::cout<<"1";
	else std::cout<<"0";
	if (a[3]) std::cout<<"1";
	else std::cout<<"0";
	if (a[4]) std::cout<<"1";
	else std::cout<<"0";
	if (a[5]) std::cout<<"1";
	else std::cout<<"0";
	if (a[6]) std::cout<<"1";
	else std::cout<<"0";
	if (a[7]) std::cout<<"1";
	else std::cout<<"0";
}

// Reset number of operations counter
void ResetFunctionCount() {
	counter = 0;
	return;
}
=======
#include "basic_functions.h"
#include "p1.h"
>>>>>>> 2156ffb32a8522585ea87d2d8436b26b9afd07c9

// Simple 1 bit XOR
bool XOR(bool a, bool b){
	bool or1 = And(Not(a), b);
	bool or2 = And(Not(b), a);
	bool ans = Or(or1, or2);
	return ans;
}

// Simple 1 bit Mux
bool Mux(bool operation, bool output_if_true, bool output_if_false) {
	bool or1 = And(operation, output_if_true);
	bool or2 = And(Not(operation), output_if_false);
	bool ans = Or(or1, or2);
	return ans;
}

// Simple 1 bit Sum (XOR)
<<<<<<< HEAD
bool SumNoCarryout(bool a, bool b) {
=======
bool Sum(bool a, bool b) {
>>>>>>> 2156ffb32a8522585ea87d2d8436b26b9afd07c9
	return XOR(a, b);
}

// 1 bit Carryout Function
bool CarryOut(bool a, bool b, bool c) {
	bool o1 = And(a, b);
	bool o2 = And(a, c);
	bool o3 = And(b, c);
	bool ans = Or(Or(o1, o2), o3);
	return ans;
}

// 1 bit Equals Function
bool Equal(bool a, bool b) {
	return Not(XOR(a, b));
}

bool Sum(bool a, bool b, bool carry) {
<<<<<<< HEAD
	bool ab = SumNoCarryout(a, b);
	bool ans = SumNoCarryout(ab, carry);
	return ans;
}

// For compiling purposes
/*
int main() {
	return 0;
	}
*/
=======
	bool ab = Sum(a, b);
	bool ans = Sum(ab, carry);
	return ans;
}

>>>>>>> 2156ffb32a8522585ea87d2d8436b26b9afd07c9
