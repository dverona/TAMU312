#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "p7.h"
#include "p8.h"


// make lists of instructions

// ADD 3, 0, 2 # Reg(3) = Reg(0) + Reg(2)  	 			00000000 00000000 00000010 00000011
// SUB 6, 4. 5 # Reg(6) = Reg(4) - Reg(5)   			00000001 00000100 00000101 00000110
// AND 3, 7, 1 # Reg(3) = Reg(7) & Reg(1)   			00000110 00000111 00000001 00000011
// OR  4, 6, 2 # Reg(4) = Reg(6) | Reg(2)   			00000111 00000110 00000010 00000100


// NEG 1, 4    # Reg(1) = - Reg(4)          			00000010 00000100 00000001 00000000
// SLL 5, 4    # Reg(5) = Reg(4) << 1       			00001000 00000101 00000100 00000000
// SRL 3, 1    # Reg(3) = Reg(1) >> 1       			00001001 00000001 00000011 00000000


// LI  3, 30   # Reg(3) = Immediate(30)     			00011110 00000011 00000000 00011110


// LW  3, 0    # Reg(3) = DataMemory[0]     			00001110 00000000 00000011 00000000
// SW  4, 8    # DataMemory[8] = Reg(4)     			00001111 00001000 00000100 00000000


// EQ  16, 5, 6 # PC = PC + 16 if Reg(5) == Reg(6)  	00000011 00000101 00000110 00010000
// LT -12, 2, 3 # PC = PC - 12 if Reg(2) < Reg(3)  		00000100 00000010 00000011 11110100
// GT -32, 2, 3 # PC = PC - 32 if Reg(2) > Reg(3)    	00000101 00000010 00000011 11100000
