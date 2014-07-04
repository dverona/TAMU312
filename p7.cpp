// CSCE 312-100
// Summer I 2014
// David Verona
// a6.cpp
#include "p1.h"
#include "p2.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "p7.h"
/*
Implement the following multi-cycle datapath
1: Instruction Fetch (IF): Write a function to decode an instruction.  Get the current instruction and decode it
2: Registry Load/Instruction Decode (ID): Obtain the appropriate values from the registry
3: ALU/Execution (EX): Perform the appropriate ALU operation (Assuming all alu operation takes only one cycle)
4: Memory Load/Store  (MEM): Read/Write to memory if needed
5: Registry Store/Writeback (WB): Write back to the registry

Implement li (load immediate value) instruction, which stores a value provided in the instruction in the appropriate register, using the appropriate datapath components.
Let 30(00011110)= LI
Refer to the description in Problem 9 for the format of LI.
*/

void LI(bool* registrylocation[8], bool value[16]) {
	registrylocation[0] = value[0];
	registrylocation[1] = value[1];
	registrylocation[2] = value[2];
	registrylocation[3] = value[3];
	registrylocation[4] = value[4];
	registrylocation[5] = value[5];
	registrylocation[6] = value[6];
	registrylocation[7] = value[7];
}


//bool** current = new bool*[4];
bool rs[8] = 0;
bool rt[8] = 0;
bool rd[8] = 0;

void IF(bool** current) {
	instructionFetch();
	current = IRSplit(IR);
	if (current[0] == [0, 0, 0, 1, 1, 1, 1, 0]) current = IRSplit3(IR);
	
}


void ID(bool** current) {
	if (current[3]) {
		rd = getRegistryValue(rs, current[1]);
		rs = getRegistryValue(rt, current[2]);
		rt = getRegistryValue(rd, current[3]);
	}
	else {
		rs = getRegistryValue(rs, current[1]);
		rt = getRegistryValue(rs, current[2]);
	}
}


void EX(bool** current) {
	if (current[3]) {
		rd = alu(current[0], rs, rt);
	}
}


void MEM(bool** current) {
	if (!current[3]) {
		mem(rt, rs, 0, 1);
	}
}


void WB(bool** current) {
	if (current[3]) current[1] = rd;
}
