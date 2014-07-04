// CSCE 312-100
// Summer I 2014
// David Verona
// a6.cpp
#include "a3.cpp"
#include <fstream>


// Helper Functions

int toDecimal(int output, bool* half) {
	output = 0;
	for( int i = 0; i < 15; i ++) {
		if (half[i] == true) output = output + (2^i);
	}
	return output;
}


// Required Functions

bool** createRegistry() {
bool** registry = new bool*[16];
registry[0] = new bool[8];
registry[1] = new bool[8];
registry[2] = new bool[8];
registry[3] = new bool[8];
registry[4] = new bool[8];
registry[5] = new bool[8];
registry[6] = new bool[8];
registry[7] = new bool[8];

registry[0][0] = 0;
registry[0][1] = 0;
registry[0][2] = 0;
registry[0][3] = 0;
registry[0][4] = 0;
registry[0][5] = 0;
registry[0][6] = 0;
registry[0][7] = 0;
registry[1][0] = 0;
registry[1][1] = 0;
registry[1][2] = 0;
registry[1][3] = 0;
registry[1][4] = 0;
registry[1][5] = 0;
registry[1][6] = 0;
registry[1][7] = 0;
registry[2][0] = 0;
registry[2][1] = 0;
registry[2][2] = 0;
registry[2][3] = 0;
registry[2][4] = 0;
registry[2][5] = 0;
registry[2][6] = 0;
registry[2][7] = 0;
registry[3][0] = 0;
registry[3][1] = 0;
registry[3][2] = 0;
registry[3][3] = 0;
registry[3][4] = 0;
registry[3][5] = 0;
registry[3][6] = 0;
registry[3][7] = 0;
registry[4][0] = 0;
registry[4][1] = 0;
registry[4][2] = 0;
registry[4][3] = 0;
registry[4][4] = 0;
registry[4][5] = 0;
registry[4][6] = 0;
registry[4][7] = 0;
registry[5][0] = 0;
registry[5][1] = 0;
registry[5][2] = 0;
registry[5][3] = 0;
registry[5][4] = 0;
registry[5][5] = 0;
registry[5][6] = 0;
registry[5][7] = 0;
registry[6][0] = 0;
registry[6][1] = 0;
registry[6][2] = 0;
registry[6][3] = 0;
registry[6][4] = 0;
registry[6][5] = 0;
registry[6][6] = 0;
registry[6][7] = 0;
registry[7][0] = 0;
registry[7][1] = 0;
registry[7][2] = 0;
registry[7][3] = 0;
registry[7][4] = 0;
registry[7][5] = 0;
registry[7][6] = 0;
registry[7][7] = 0;
registry[8][0] = 0;
registry[8][1] = 0;
registry[8][2] = 0;
registry[8][3] = 0;
registry[8][4] = 0;
registry[8][5] = 0;
registry[8][6] = 0;
registry[8][7] = 0;
registry[9][0] = 0;
registry[9][1] = 0;
registry[9][2] = 0;
registry[9][3] = 0;
registry[9][4] = 0;
registry[9][5] = 0;
registry[9][6] = 0;
registry[9][7] = 0;
registry[10][0] = 0;
registry[10][1] = 0;
registry[10][2] = 0;
registry[10][3] = 0;
registry[10][4] = 0;
registry[10][5] = 0;
registry[10][6] = 0;
registry[10][7] = 0;
registry[11][0] = 0;
registry[11][1] = 0;
registry[11][2] = 0;
registry[11][3] = 0;
registry[11][4] = 0;
registry[11][5] = 0;
registry[11][6] = 0;
registry[11][7] = 0;
registry[12][0] = 0;
registry[12][1] = 0;
registry[12][2] = 0;
registry[12][3] = 0;
registry[12][4] = 0;
registry[12][5] = 0;
registry[12][6] = 0;
registry[12][7] = 0;
registry[13][0] = 0;
registry[13][1] = 0;
registry[13][2] = 0;
registry[13][3] = 0;
registry[13][4] = 0;
registry[13][5] = 0;
registry[13][6] = 0;
registry[13][7] = 0;
registry[14][0] = 0;
registry[14][1] = 0;
registry[14][2] = 0;
registry[14][3] = 0;
registry[14][4] = 0;
registry[14][5] = 0;
registry[14][6] = 0;
registry[14][7] = 0;
registry[15][0] = 0;
registry[15][1] = 0;
registry[15][2] = 0;
registry[15][3] = 0;
registry[15][4] = 0;
registry[15][5] = 0;
registry[15][6] = 0;
registry[15][7] = 0;
registry[16][0] = 0;
registry[16][1] = 0;
registry[16][2] = 0;
registry[16][3] = 0;
registry[16][4] = 0;
registry[16][5] = 0;
registry[16][6] = 0;
registry[16][7] = 0;
return registry;
}


bool* getRegistryValue(bool* output, bool registryNum[8]) {	
	output[0] = registry[registryNum][0];
	output[1] = registry[registryNum][1];
	output[2] = registry[registryNum][2];
	output[3] = registry[registryNum][3];
	output[4] = registry[registryNum][4];
	output[5] = registry[registryNum][5];
	output[6] = registry[registryNum][6];
	output[7] = registry[registryNum][7];
	return output;
}


void setRegistryValue(bool registryNum[8], bool value[8]) {
	try{
	bool* output = new bool[8];
	bool tmpCheck = 0;
	if ( Eightto1bit(tmpCheck, LessThan(output, registryNum, [0,0,0,0,0,0,0,0]))) throw 10;
	if ( Eightto1bit(tmpCheck, GreaterThan(output, registryNum, [0,0,0,0,1,1,1,1]))) throw 10;
	value[0] = registry[registryNum][0];
	value[1] = registry[registryNum][1];
	value[2] = registry[registryNum][2];
	value[3] = registry[registryNum][3];
	value[4] = registry[registryNum][4];
	value[5] = registry[registryNum][5];
	value[6] = registry[registryNum][6];
	value[7] = registry[registryNum][7];
	}
	catch (int e) {
		std::cout<<"Reg(";
		PrintValueInDecimal(registryNum);
		std::cout<<") = ";
		PrintValue(registryNum);
		std::cout<<'\n';
	}
}


bool** createInstructionMemory() {
	bool** ins = new bool*[256];
	ins[0] = new bool[8];
	ins[1] = new bool[8];
	ins[2] = new bool[8];
	ins[3] = new bool[8];
	ins[4] = new bool[8];
	ins[5] = new bool[8];
	ins[6] = new bool[8];
	ins[7] = new bool[8];
	ins[8] = new bool[8];
	ins[9] = new bool[8];
	ins[10] = new bool[8];
	ins[11] = new bool[8];
	ins[12] = new bool[8];
	ins[13] = new bool[8];
	ins[14] = new bool[8];
	ins[15] = new bool[8];
	ins[16] = new bool[8];
	ins[17] = new bool[8];
	ins[18] = new bool[8];
	ins[19] = new bool[8];
	ins[20] = new bool[8];
	ins[21] = new bool[8];
	ins[22] = new bool[8];
	ins[23] = new bool[8];
	ins[24] = new bool[8];
	ins[25] = new bool[8];
	ins[26] = new bool[8];
	ins[27] = new bool[8];
	ins[28] = new bool[8];
	ins[29] = new bool[8];
	ins[30] = new bool[8];
	ins[31] = new bool[8];
	ins[32] = new bool[8];
	ins[33] = new bool[8];
	ins[34] = new bool[8];
	ins[35] = new bool[8];
	ins[36] = new bool[8];
	ins[37] = new bool[8];
	ins[38] = new bool[8];
	ins[39] = new bool[8];
	ins[40] = new bool[8];
	ins[41] = new bool[8];
	ins[42] = new bool[8];
	ins[43] = new bool[8];
	ins[44] = new bool[8];
	ins[45] = new bool[8];
	ins[46] = new bool[8];
	ins[47] = new bool[8];
	ins[48] = new bool[8];
	ins[49] = new bool[8];
	ins[50] = new bool[8];
	ins[51] = new bool[8];
	ins[52] = new bool[8];
	ins[53] = new bool[8];
	ins[54] = new bool[8];
	ins[55] = new bool[8];
	ins[56] = new bool[8];
	ins[57] = new bool[8];
	ins[58] = new bool[8];
	ins[59] = new bool[8];
	ins[60] = new bool[8];
	ins[61] = new bool[8];
	ins[62] = new bool[8];
	ins[63] = new bool[8];
	ins[64] = new bool[8];
	ins[65] = new bool[8];
	ins[66] = new bool[8];
	ins[67] = new bool[8];
	ins[68] = new bool[8];
	ins[69] = new bool[8];
	ins[70] = new bool[8];
	ins[71] = new bool[8];
	ins[72] = new bool[8];
	ins[73] = new bool[8];
	ins[74] = new bool[8];
	ins[75] = new bool[8];
	ins[76] = new bool[8];
	ins[77] = new bool[8];
	ins[78] = new bool[8];
	ins[79] = new bool[8];
	ins[80] = new bool[8];
	ins[81] = new bool[8];
	ins[82] = new bool[8];
	ins[83] = new bool[8];
	ins[84] = new bool[8];
	ins[85] = new bool[8];
	ins[86] = new bool[8];
	ins[87] = new bool[8];
	ins[88] = new bool[8];
	ins[89] = new bool[8];
	ins[90] = new bool[8];
	ins[91] = new bool[8];
	ins[92] = new bool[8];
	ins[93] = new bool[8];
	ins[94] = new bool[8];
	ins[95] = new bool[8];
	ins[96] = new bool[8];
	ins[97] = new bool[8];
	ins[98] = new bool[8];
	ins[99] = new bool[8];
	ins[100] = new bool[8];
	ins[101] = new bool[8];
	ins[102] = new bool[8];
	ins[103] = new bool[8];
	ins[104] = new bool[8];
	ins[105] = new bool[8];
	ins[106] = new bool[8];
	ins[107] = new bool[8];
	ins[108] = new bool[8];
	ins[109] = new bool[8];
	ins[110] = new bool[8];
	ins[111] = new bool[8];
	ins[112] = new bool[8];
	ins[113] = new bool[8];
	ins[114] = new bool[8];
	ins[115] = new bool[8];
	ins[116] = new bool[8];
	ins[117] = new bool[8];
	ins[118] = new bool[8];
	ins[119] = new bool[8];
	ins[120] = new bool[8];
	ins[121] = new bool[8];
	ins[122] = new bool[8];
	ins[123] = new bool[8];
	ins[124] = new bool[8];
	ins[125] = new bool[8];
	ins[126] = new bool[8];
	ins[127] = new bool[8];
	ins[128] = new bool[8];
	ins[129] = new bool[8];
	ins[130] = new bool[8];
	ins[131] = new bool[8];
	ins[132] = new bool[8];
	ins[133] = new bool[8];
	ins[134] = new bool[8];
	ins[135] = new bool[8];
	ins[136] = new bool[8];
	ins[137] = new bool[8];
	ins[138] = new bool[8];
	ins[139] = new bool[8];
	ins[140] = new bool[8];
	ins[141] = new bool[8];
	ins[142] = new bool[8];
	ins[143] = new bool[8];
	ins[144] = new bool[8];
	ins[145] = new bool[8];
	ins[146] = new bool[8];
	ins[147] = new bool[8];
	ins[148] = new bool[8];
	ins[149] = new bool[8];
	ins[150] = new bool[8];
	ins[151] = new bool[8];
	ins[152] = new bool[8];
	ins[153] = new bool[8];
	ins[154] = new bool[8];
	ins[155] = new bool[8];
	ins[156] = new bool[8];
	ins[157] = new bool[8];
	ins[158] = new bool[8];
	ins[159] = new bool[8];
	ins[160] = new bool[8];
	ins[161] = new bool[8];
	ins[162] = new bool[8];
	ins[163] = new bool[8];
	ins[164] = new bool[8];
	ins[165] = new bool[8];
	ins[166] = new bool[8];
	ins[167] = new bool[8];
	ins[168] = new bool[8];
	ins[169] = new bool[8];
	ins[170] = new bool[8];
	ins[171] = new bool[8];
	ins[172] = new bool[8];
	ins[173] = new bool[8];
	ins[174] = new bool[8];
	ins[175] = new bool[8];
	ins[176] = new bool[8];
	ins[177] = new bool[8];
	ins[178] = new bool[8];
	ins[179] = new bool[8];
	ins[180] = new bool[8];
	ins[181] = new bool[8];
	ins[182] = new bool[8];
	ins[183] = new bool[8];
	ins[184] = new bool[8];
	ins[185] = new bool[8];
	ins[186] = new bool[8];
	ins[187] = new bool[8];
	ins[188] = new bool[8];
	ins[189] = new bool[8];
	ins[190] = new bool[8];
	ins[191] = new bool[8];
	ins[192] = new bool[8];
	ins[193] = new bool[8];
	ins[194] = new bool[8];
	ins[195] = new bool[8];
	ins[196] = new bool[8];
	ins[197] = new bool[8];
	ins[198] = new bool[8];
	ins[199] = new bool[8];
	ins[200] = new bool[8];
	ins[201] = new bool[8];
	ins[202] = new bool[8];
	ins[203] = new bool[8];
	ins[204] = new bool[8];
	ins[205] = new bool[8];
	ins[206] = new bool[8];
	ins[207] = new bool[8];
	ins[208] = new bool[8];
	ins[209] = new bool[8];
	ins[210] = new bool[8];
	ins[211] = new bool[8];
	ins[212] = new bool[8];
	ins[213] = new bool[8];
	ins[214] = new bool[8];
	ins[215] = new bool[8];
	ins[216] = new bool[8];
	ins[217] = new bool[8];
	ins[218] = new bool[8];
	ins[219] = new bool[8];
	ins[220] = new bool[8];
	ins[221] = new bool[8];
	ins[222] = new bool[8];
	ins[223] = new bool[8];
	ins[224] = new bool[8];
	ins[225] = new bool[8];
	ins[226] = new bool[8];
	ins[227] = new bool[8];
	ins[228] = new bool[8];
	ins[229] = new bool[8];
	ins[230] = new bool[8];
	ins[231] = new bool[8];
	ins[232] = new bool[8];
	ins[233] = new bool[8];
	ins[234] = new bool[8];
	ins[235] = new bool[8];
	ins[236] = new bool[8];
	ins[237] = new bool[8];
	ins[238] = new bool[8];
	ins[239] = new bool[8];
	ins[240] = new bool[8];
	ins[241] = new bool[8];
	ins[242] = new bool[8];
	ins[243] = new bool[8];
	ins[244] = new bool[8];
	ins[245] = new bool[8];
	ins[246] = new bool[8];
	ins[247] = new bool[8];
	ins[248] = new bool[8];
	ins[249] = new bool[8];
	ins[250] = new bool[8];
	ins[251] = new bool[8];
	ins[252] = new bool[8];
	ins[253] = new bool[8];
	ins[254] = new bool[8];
	ins[255] = new bool[8];
}


bool* tmpPC = new bool[8]; 	 //for compiling purposes


bool* createPC() {
bool tmpPC[8];
tmpPC[0] = 0;
tmpPC[1] = 0;
tmpPC[2] = 0;
tmpPC[3] = 0;
tmpPC[4] = 0;
tmpPC[5] = 0;
tmpPC[6] = 0;
tmpPC[7] = 0;
return tmpPC;
}


void incrementPC(bool* tmpPC) {
	tmpPC = Add(tmpPC, tmpPC, [0,0,0,0,0,1,0,0]);
}


void addPC(bool[8] addressOffset) {
	tmpPC = Add(tmpPC*, tmpPC, addressOffset);
}


bool IR[32];				// instruction register


// reads bool[64] at instructionMemory[PC] and writes it into IR
void instructionFetch(int num) {
	IR[0] = ins[num];
	IR[1] = ins[num+1];
	IR[2] = ins[num+2];
	IR[3] = ins[num+3];
	IR[4] = ins[num+4];
	IR[5] = ins[num+5];
	IR[6] = ins[num+6];
	IR[7] = ins[num+7];
	IR[8] = ins[num+8];
	IR[9] = ins[num+9];
	IR[10] = ins[num+10];
	IR[11] = ins[num+11];
	IR[12] = ins[num+12];
	IR[13] = ins[num+13];
	IR[14] = ins[num+14];
	IR[15] = ins[num+15];
	IR[16] = ins[num+16];
	IR[17] = ins[num+17];
	IR[18] = ins[num+18];
	IR[19] = ins[num+19];
	IR[20] = ins[num+20];
	IR[21] = ins[num+21];
	IR[22] = ins[num+22];
	IR[23] = ins[num+23];
	IR[24] = ins[num+24];
	IR[25] = ins[num+25];
	IR[26] = ins[num+26];
	IR[27] = ins[num+27];
	IR[28] = ins[num+28];
	IR[29] = ins[num+29];
	IR[30] = ins[num+30];
	IR[31] = ins[num+31];
	IR[32] = ins[num+32];
	IR[33] = ins[num+33];
	IR[34] = ins[num+34];
	IR[35] = ins[num+35];
	IR[36] = ins[num+36];
	IR[37] = ins[num+37];
	IR[38] = ins[num+38];
	IR[39] = ins[num+39];
	IR[40] = ins[num+40];
	IR[41] = ins[num+41];
	IR[42] = ins[num+42];
	IR[43] = ins[num+43];
	IR[44] = ins[num+44];
	IR[45] = ins[num+45];
	IR[46] = ins[num+46];
	IR[47] = ins[num+47];
	IR[48] = ins[num+48];
	IR[49] = ins[num+49];
	IR[50] = ins[num+50];
	IR[51] = ins[num+51];
	IR[52] = ins[num+52];
	IR[53] = ins[num+53];
	IR[54] = ins[num+54];
	IR[55] = ins[num+55];
	IR[56] = ins[num+56];
	IR[57] = ins[num+57];
	IR[58] = ins[num+58];
	IR[59] = ins[num+59];
	IR[60] = ins[num+60];
	IR[61] = ins[num+61];
	IR[62] = ins[num+62];
	IR[63] = ins[num+63];
}


void initializeInstructionMemory(std::ifstream &fp) {
	std::string line;
	std::string text;
	if (fp.is_open()) {
		while ( getline(fp,line) ) {
			text << line << '\n';
		}
	myfile.close();
	}
}


bool* getInstructionValue(bool* output, std::string instructionName) {
	string op = "";
	int rs = 0;
	int rt = 0;
	int rd = 0;
	while(true) {
		if (instructionName[0] == ' ') break;
		op+=instructionName[0];
		if (instructionName[1] == ' ') break;
		op+=instructionName[1];
		if (instructionName[2] == ' ') break;
		op+=instructionName[2];
		if (instructionName[3] == ' ') break;
		op+=instructionName[3];
		if (instructionName[4] == ' ') break;
		op+=instructionName[4];
	}
	//std::getline(istream& is, instructionName, ' ');
	
	switch(op) {
	case "ADD": output[0] = output[1] = output[2] = output[3] = output[4] = output[5] = output[6] = output[7] = 0;
		break;
	case "SUB": output[0] = output[1] = output[2] = output[3] = output[4] = output[5] = output[6] = 0;
				output[7] = 1;
		break;
	case "NEG": output[0] = output[1] = output[2] = output[3] = output[4] = output[5] = output[7] = 0;
				output[6] = 1;
		break;
	case "EQ":  output[0] = output[1] = output[2] = output[3] = output[4] = output[5] = 0;
				output[6] = output[7] = 1;
		break;
	case "LT":  output[0] = output[1] = output[2] = output[3] = output[4] = output[6] = output[7] = 0;
				output[5] = 1;
		break;
	case "GT":  output[0] = output[1] = output[2] = output[3] = output[4] = output[6] = 0;
				output[5] = ouput[7] = 1;
		break;
	case "AND": output[0] = output[1] = output[2] = output[3] = output[4] = output[7] = 0;
				output[5] = ouput[6] = 1;
		break;
	case "OR":  output[0] = output[1] = output[2] = output[3] = output[4] = 0;
				output[5] = output[6] = output[7] = 1;
		break;
	case "SLL": output[0] = output[1] = output[2] = output[3] = output[5] = output[6] = output[7] = 0;
				output[4] = 1;
		break;
	case "SRL": output[0] = output[1] = output[2] = output[3] = output[5] = output[6] = 0;
				output[4] = output[7] = 1;
		break;
	case "MULTU": output[0] = output[1] = output[2] = output[3] = output[5] = output[7] = 0;
				  output[4] = output[6] = 1;
		break;
	case "MULT": output[0] = output[1] = output[2] = output[3] = output[5] = 0;
				 output[4] = output[6] = output[7] = 0;
		break;
	case "DIVU": output[0] = output[1] = output[2] = output[3] = output[6] = output[7] = 0;
				 output[4] = output[5] = 1;
		break;
	case "DIV": output[0] = output[1] = output[2] = output[3] = output[6] = 0;
				output[4] = output[5] = output[7] = 1;
		break;
	case "LW":  output[0] = output[1] = output[2] = output[3] = output[7] = 0;
				output[4] = output[5] = output[6] = 1;
		break;
	case "SW":  output[0] = output[1] = output[2] = output[3] = 0;
				output[4] = output[5] = output[6] = output[7] = 1;
		break;
	case "ADDU": output[0] = output[1] = output[2] = output[4] = output[5] = output[6] = output[7] = 0;
				 output[3] = 1;
		break;
	case "SUBU": output[0] = output[1] = output[2] = output[4] = output[5] = output[6] = 0;
				 output[3] = output[7] = 1;
		break;
	case "LI":  output[0] = output[1] = output[2] = output[7] = 0;
				output[3] = output[4] = output[5] = output[6] = 1;
		break;
	default: cout << "No function: " << instructionName << '\n';
		break;
	}
	return output;
}


bool** IRSplit(bool ins[32]) {
	bool** blockIR = new bool*[4];
	blockIR[0] = new bool[8];
	blockIR[1] = new bool[8];
	blockIR[2] = new bool[8];
	blockIR[3] = new bool[8];

	blockIR[0][0] = ins[0];
	blockIR[0][1] = ins[1];
	blockIR[0][2] = ins[2];
	blockIR[0][3] = ins[3];
	blockIR[0][4] = ins[4];
	blockIR[0][5] = ins[5];
	blockIR[0][6] = ins[6];
	blockIR[0][7] = ins[7];

	blockIR[1][0] = ins[8];
	blockIR[1][1] = ins[9];
	blockIR[1][2] = ins[10];
	blockIR[1][3] = ins[11];
	blockIR[1][4] = ins[12];
	blockIR[1][5] = ins[13];
	blockIR[1][6] = ins[14];
	blockIR[1][7] = ins[15];

	blockIR[2][0] = ins[16];
	blockIR[2][1] = ins[17];
	blockIR[2][2] = ins[18];
	blockIR[2][3] = ins[19];
	blockIR[2][4] = ins[20];
	blockIR[2][5] = ins[21];
	blockIR[2][6] = ins[22];
	blockIR[2][7] = ins[23];

	blockIR[3][0] = ins[24];
	blockIR[3][1] = ins[25];
	blockIR[3][2] = ins[26];
	blockIR[3][3] = ins[27];
	blockIR[3][4] = ins[28];
	blockIR[3][5] = ins[29];
	blockIR[3][6] = ins[30];
	blockIR[3][7] = ins[31];

	return blockIR;
}


bool** IRSplit3(bool ins[32]) {
	bool** blockIR = new bool*[3];
	blockIR[0] = new bool[8];
	blockIR[1] = new bool[8];
	blockIR[2] = new bool[16];

	blockIR[0][0] = ins[0];
	blockIR[0][1] = ins[1];
	blockIR[0][2] = ins[2];
	blockIR[0][3] = ins[3];
	blockIR[0][4] = ins[4];
	blockIR[0][5] = ins[5];
	blockIR[0][6] = ins[6];
	blockIR[0][7] = ins[7];

	blockIR[1][0] = ins[8];
	blockIR[1][1] = ins[9];
	blockIR[1][2] = ins[10];
	blockIR[1][3] = ins[11];
	blockIR[1][4] = ins[12];
	blockIR[1][5] = ins[13];
	blockIR[1][6] = ins[14];
	blockIR[1][7] = ins[15];

	blockIR[2][0] = ins[16];
	blockIR[2][1] = ins[17];
	blockIR[2][2] = ins[18];
	blockIR[2][3] = ins[19];
	blockIR[2][4] = ins[20];
	blockIR[2][5] = ins[21];
	blockIR[2][6] = ins[22];
	blockIR[2][7] = ins[23];
	blockIR[2][8] = ins[24];
	blockIR[2][9] = ins[25];
	blockIR[2][10] = ins[26];
	blockIR[2][11] = ins[27];
	blockIR[2][12] = ins[28];
	blockIR[2][13] = ins[29];
	blockIR[2][14] = ins[30];
	blockIR[2][15] = ins[31];

	return blockIR;
}


bool dataMemory[16][8];


void mem(bool registrylocation[8], bool memlocation[16], bool read, bool write) {  //(may use if() to choose one of the two following functions)
	if (read) {
		lw(registrylocation, memlocation);
	}
	else if (write) {
		sw(registrylocation , memlocation);
	}
	else std::cout<<"Invalid memory operation. Read = 0. Write = 0.\n";
}


void lw(bool registrylocation[8], bool memlocation[16]) {
	int index = 0;
	index = toDecimal(index, memlocation);
	registrylocation[0] = datamemory[index];
	registrylocation[1] = datamemory[index+1];
	registrylocation[2] = datamemory[index+2];
	registrylocation[3] = datamemory[index+3];
	registrylocation[4] = datamemory[index+4];
	registrylocation[5] = datamemory[index+5];
	registrylocation[6] = datamemory[index+6];
	registrylocation[7] = datamemory[index+7];
}


void sw(bool registrylocation[8], bool memlocation[16]) {
	int index = 0;
	index = toDecimal(index, memlocation);
	datamemory[index] = registrylocation[0];
	datamemory[index+1] = registrylocation[1];
	datamemory[index+2] = registrylocation[2];
	datamemory[index+3] = registrylocation[3];
	datamemory[index+4] = registrylocation[4];
	datamemory[index+5] = registrylocation[5];
	datamemory[index+6] = registrylocation[6];
	datamemory[index+7] = registrylocation[7];
}
