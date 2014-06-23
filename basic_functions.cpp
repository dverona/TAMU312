#include <iostream>
#include "basic_functions.h"

using namespace std;

// Global variable for Counter
int functionCount = 0;

// Simple 1 Bit And
bool And (bool a, bool b) {
	functionCount++;
	if (a && b) return 1;
	return 0;
}

// Simple 1 Bit Or
bool Or (bool a, bool b) {
	functionCount++;
	if (a || b) return 1;
	return 0;
}

// Simple 1 Bit Not
bool Not(bool a) {
	functionCount++;
	return !a;
}

// Print number of operations used
void printFunctionCount() {
	std::cout<<"Function Count:"<<functionCount;
	return;
}

// Print Bit
void print(bool a) {
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

// Reset number of operations functionCount
void resetFunctionCount() {
	functionCount = 0;
	return;
}

// Return the value of a bit within a byte
bool getValue(bool byte[8], int offset) {
	return byte[offset];
}

// Write a new value to a bit within a byte
void writeValue(bool* byte, int offset, bool value) {
	byte[offset] = value;
	return;
}

// Print out binary interpretation of a byte
void printValue(bool byte[8]) {
	int* ans = new int[8];
	for( int i = 0; i < 7; i ++) {
		if (byte[i] == false) ans[i] = 0;
		else ans[i] = 1;
	}
	std::cout<<ans;
	return;
}

// Print out decimal interpretation of a byte
void printValueInDecimal(bool byte[8]) {
	int ans = 0;
	for( int i = 0; i < 7; i ++) {
		if (byte[i] == true) ans = ans + (2^i);
	}
	std::cout<<ans;
	return;
}

