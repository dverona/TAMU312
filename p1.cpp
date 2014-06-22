#include "basic_functions.h"
#include "p1.h"

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
bool Sum(bool a, bool b) {
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
	bool ab = Sum(a, b);
	bool ans = Sum(ab, carry);
	return ans;
}

