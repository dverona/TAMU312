// CSCE 312-100
// Summer I 2014
// David Verona
// a4.cpp

// Add and Subtract with Trap

bool* Add(bool* output, bool input1[8], bool input2[8]) {
	bool* sum = new bool[8];
	// LSB
	bool i17 = input1[7];
	bool i27 = input2[7];
	sum[7] = Sum(i17, i27, false);
	bool carryOut7 = CarryOut(i17, i27, false);

	// Bit 2
	bool i16 = input1[6];
	bool i26 = input2[6];
	sum[6] = Sum(i16, i26, carryOut7);
	bool carryOut6 = CarryOut(i16, i26, carryOut7);

	// Bit 3
	bool i15 = input1[5];
	bool i25 = input2[5];
	sum[5] = Sum(i15, i25, carryOut6);
	bool carryOut5 = CarryOut(i15, i25, carryOut6);

	// Bit 4
	bool i14 = input1[4];
	bool i24 = input2[4];
	sum[4] = Sum(i14, i24, carryOut5);
	bool carryOut4 = CarryOut(i14, i24, carryOut5);

	// Bit 5
	bool i13 = input1[3];
	bool i23 = input2[3];
	sum[3] = Sum(i13, i23, carryOut4);
	bool carryOut3 = CarryOut(i13, i23, carryOut4);

	// Bit 6
	bool i12 = input1[2];
	bool i22 = input2[2];
	sum[2] = Sum(i12, i22, carryOut3);
	bool carryOut2 = CarryOut(i12, i22, carryOut3);

	// Bit 7
	bool i11 = input1[1];
	bool i21 = input2[1];
	sum[1] = Sum(i11, i21, carryOut2);
	bool carryOut1 = CarryOut(i11, i21, carryOut2);

	// MSB
	bool i10 = input1[0];
	bool i20 = input2[0];
	sum[0] = Sum(i10, i20, carryOut1);
	bool carryOut0 = CarryOut(i10, i20, carryOut1);

	Mux8(output, carryOut0, input1, sum);

	if (carryOut0) std::cout<<"This operation created overflow. Input 1 returned";

	return output;
}

bool* Sub(bool* output, bool input1[8], bool input2[8]) {
	bool* neg2 = new bool[8];
	Negate(&neg2, input2);
	Add(output, input1, neg2);
	return output;
}
