#include "gvm_asm.h"


GVM_ASM::GVM_ASM()
{

}


GVM_ASM::~GVM_ASM()
{

}

bool GVM_ASM::convert( string filename_in, string filename_out )
{
	FILE *fp_in = fopen( filename_in.c_str(), "r" );
	FILE *fp_out = fopen( filename_out.c_str(), "wb" );
	
	if ( !fp_in || !fp_in )
	{
		cout << "GVM_ASM::Error with file" << endl;
		return false;
	}

	fscanf( fp_in, "%s", token );
	cout << "token: " << token << endl;
	int op = this->Get_OpCode();

	switch ( op )
	{
		// opcodes with no arguments
		case INC:
			break;

		// opcodes with 1 argument
		case JMP:
			break;

		// opcodes with 2 arguments
		// opcode source destination
		case MOV:
			break;

		default:
			cout << "GVM_ASM:: Unkown opcode " << op << endl;
	};
	
	fclose( fp_in );
	fclose( fp_out );

	return true;
}

unsigned int GVM_ASM::Get_OpCode()
{
	// math
	if ( strcmp( this->token, "INC" ) )
		return INC;	else if ( strcmp( this->token, "DEC" ) )		return DEC;	
	else if ( strcmp( this->token, "FLT" ) )	
		return FLT;	
	else if ( strcmp( this->token, "INT" ) )
		return INT;	
	// integer specific
	else if ( strcmp( this->token, "IADD" ) )
		return IADD;	
	else if ( strcmp( this->token, "ISUB" ) )
			return ISUB;	
	else if ( strcmp( this->token, "IMUL" ) )
		return IMUL;	
	else if ( strcmp( this->token, "IDIV" ) )
		return IDIV;	
	else if ( strcmp( this->token, "IMOD" ) )
		return IMOD;	
	else if ( strcmp( this->token, "INEG" ) )
		return INEG;	
	// real specific
	else if ( strcmp( this->token, "FADD" ) )
		return FADD;	
	else if ( strcmp( this->token, "FSUB" ) )
		return FSUB;	
	else if ( strcmp( this->token, "FMUL" ) )
		return FMUL;	
	else if ( strcmp( this->token, "FDIV" ) )
		return FDIV;	
	else if ( strcmp( this->token, "FMOD" ) )
		return FMOD;	
	else if ( strcmp( this->token, "FNEG" ) )
		return FNEG;	
	// bitwise operators
	else if ( strcmp( this->token, "NOT" ) )			
		return NOT;	
	else if ( strcmp( this->token, "AND" ) )
		return AND;	
	else if ( strcmp( this->token, "OR" ) )
		return OR;	
	else if ( strcmp( this->token, "XOR" ) )
		return XOR;	
	else if ( strcmp( this->token, "COPY" ) )
		return COPY;	
	// stardard I/O
	else if ( strcmp( this->token, "OUTI" ) )
		return OUTI;	
	else if ( strcmp( this->token, "OUTF" ) )
		return OUTF;	
	else if ( strcmp( this->token, "OUTCH" ) )
		return OUTCH;	
	else if ( strcmp( this->token, "OUTS" ) )
		return OUTS;	
	else if ( strcmp( this->token, "INI" ) )
		return INI;	
	else if ( strcmp( this->token, "INF" ) )
		return INF;	
	else if ( strcmp( this->token, "INCH" ) )
		return INCH;	
	else if ( strcmp( this->token, "INS" ) )
		return INS;	
	// Machine Operations
	// use R0 - R3, IR, PC, memory
	else if ( strcmp( this->token, "MOV" ) )
		return MOV;	
	else if ( strcmp( this->token, "LOAD" ) )
		return LOAD;	
	else if ( strcmp( this->token, "LOADD" ) )
		return LOADD;	
	else if ( strcmp( this->token, "LOADI" ) )
		return LOADI;	
	else if ( strcmp( this->token, "LOADRD" ) )
		return LOADRD;	
	else if ( strcmp( this->token, "LOADRI" ) )
		return LOADRI;	
	// Stack Related
	else if ( strcmp( this->token, "DROP" ) )
		return DROP;	
	else if ( strcmp( this->token, "SWAP" ) )
		return SWAP;	
	// registers R0-R3		
	// push register on top of stack
	else if ( strcmp( this->token, "PUSH0" ) )
		return PUSH0;
	else if ( strcmp( this->token, "PUSH1" ) )
		return PUSH1;
	else if ( strcmp( this->token, "PUSH2" ) )
		return PUSH2;
	else if ( strcmp( this->token, "PUSH3" ) )
		return PUSH3;
	// pop top of stack to register
	else if ( strcmp( this->token, "POP0" ) )
		return POP0;	
	else if ( strcmp( this->token, "POP1" ) )
		return POP1;	
	else if ( strcmp( this->token, "POP2" ) )
		return POP2;
	else if ( strcmp( this->token, "POP3" ) )
		return POP3;	
	//logical	
	// test top of stack and replace TRUE/FALSE on top, stack is popped when tested
	else if ( strcmp( this->token, "TPS" ) )
		return TPS;	
	else if ( strcmp( this->token, "TNG" ) )
		return TNG;	
	else if ( strcmp( this->token, "TZE" ) )
		return TZE;	
	else if ( strcmp( this->token, "TNP" ) )
		return TNP;	
	else if ( strcmp( this->token, "TNN" ) )
		return TNN;	
	else if ( strcmp( this->token, "TNZ" ) )
		return TNZ;	
	// float tests
	else if ( strcmp( this->token, "TPSF" ) )
		return TPSF;	
	else if ( strcmp( this->token, "TNGF" ) )
		return TNGF;	
	else if ( strcmp( this->token, "TZEF" ) )
		return TZEF;	
	else if ( strcmp( this->token, "TNPF" ) )
		return TNPF;	
	else if ( strcmp( this->token, "TNNF" ) )
		return TNNF;	
	else if ( strcmp( this->token, "TNZF" ) )
		return TNZF;	
	// conditional jump, check top of stack TRUE/FALSE
	else if ( strcmp( this->token, "BYES" ) )
		return BYES;	
	else if ( strcmp( this->token, "BNO" ) )
		return BNO;	
	// normal jump
	else if ( strcmp( this->token, "JMP" ) )
		return JMP;	
	else if ( strcmp( this->token, "JMPR" ) )
		return JMPR;	
	else if ( strcmp( this->token, "JMPD" ) )
		return JMPD;	
	else
	{
		cout << "GVM_ASM::Unknown command: " << this->token << endl;
		return ERR;
	}
	
	return 0;
}

