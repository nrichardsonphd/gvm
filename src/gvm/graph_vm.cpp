#include "graph_vm.h"


Graph_VM::Graph_VM( )
{
	this->initialize( );
}


Graph_VM::~Graph_VM( )
{

}

void Graph_VM::initialize( )
{
	this->done = false;
	this->program_counter = 0;
	this->IR = NOOP;
	this->R0 = 0;
	this->R1 = 0;
	this->R2 = 0;
	this->R3 = 0;

	while ( !this->Stack.empty( ) )
	{
		this->Stack.pop( );
	}

	//this->RAM.Clear_Memory();
}

bool Graph_VM::load( string filename )
{
	if ( !this->RAM.load( filename ) )
	{
		cout << "Graph_VM::Error loading RAM" << endl;
		return false;
	}
	
	this->initialize();
	return true;

}

float Graph_VM::real( unsigned int x )
{
	int i = x;
	float *f;
	f = (float *) &i;
	return *f;
}

unsigned int Graph_VM::unreal( float x )
{
	int *i;
	float f = x;
	i = (int*) &f;
	return *i;
}

unsigned int Graph_VM::next1()
{
	unsigned int ret;
	ret = this->RAM.get1( program_counter++ );
	return ret;
}

unsigned int Graph_VM::next2()
{
	unsigned int a, b, ret;
	a = this->next1();
	b = this->next1();
	ret = a | ( b << 8 );
	return ret;
}

unsigned int Graph_VM::next4( )
{
	unsigned int a, b, ret;
	a = this->next2();
	b = this->next2();
	ret = a | ( b << 16 );
	return ret;
}

void Graph_VM::cycle()
{
	this->IR = this->next1( );
	
	switch ( this->IR )
	{
		case INC:
		case DEC:
		case FLT:
		case INT:
			this->sw_int_flt_math();
			break;

		case IADD:
		case ISUB:
		case IMUL:
		case IDIV:
		case IMOD:
		case INEG:
			this->sw_int_math( );
			break;

		case FADD:
		case FSUB:
		case FMUL:
		case FDIV:
		case FMOD:
		case FNEG:
			this->sw_float_math( );
			break;


			
		case NOT:
		case AND:
		case OR:
		case XOR:
		case COPY:
			this->sw_bitwise();
			break;

		case OUTCH:
		case OUTF:
		case OUTI:
		case OUTS:
		case INCH:
		case INF:
		case INI:
		case INS:
			this->sw_io();
			break;

		case DROP:
		case SWAP:
		case PUSH0:
		case PUSH1:
		case PUSH2:
		case PUSH3:
		case POP0:
		case POP1:
		case POP2:
		case POP3:
			this->sw_stack();
			break;

		case MOV:
		case LOADD:
		case LOADI:
		case LOADR:
		case JMP:
		case JMPD:		
		case JMPR:
			this->sw_machine_op();
			break;

		case TPS:
		case TNG:
		case TZE:
		case TNN:
		case TNZ:
		case TNP:
			this->sw_logical_int_op( );
			break;
		case TPSF:
		case TNGF:
		case TZEF:
		case TNNF:
		case TNZF:
		case TNPF:
		case BYES:
		case BNO:
			this->sw_logical_flt_op();
			break;

		case ERR:
			cout << "PROGRAM ERROR" << endl;
			this->done = true;
			break;

		case HALT:
			cout << "PROGRAM COMPLETE" << endl;
			this->done = true;
			break;

		case DUMP:
			// do a core dump
			this->RAM.coredump_txt( "coredump.txt" );
			break;

		case NOOP: 
			break;

		default:
			if ( this->IR < 0x10 )
				printf( "Unkown instruction in IR: 0x0%X\n", this->IR );
			else
				printf( "Unkown instruction in IR: 0x%X\n", this->IR );

			//cout << "Unkown instruction in IR: " << (int)this->IR << endl;
			this->done = true;
			break;
	}
}


void Graph_VM::sw_int_flt_math( )
{
	switch ( this->IR )
	{
		case INC:
			a = this->Stack.top();	this->Stack.pop();
			this->Stack.push( a + 1 );
			break;

		case DEC:
			a = this->Stack.top();	this->Stack.pop();
			this->Stack.push( a - 1 );
			break;

		case FLT:
			a = this->Stack.top();	this->Stack.pop();
			f = real( a );
			this->Stack.push( unreal(f) );
			break;

		case INT:
			a = this->Stack.top();	this->Stack.pop();
			f = real(a);
			b = (int) f;
			this->Stack.push( b );
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_int_math( )
{
	switch ( this->IR )
	{
		case IADD:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( a + b );
			break;

		case ISUB:
			a = this->Stack.top( ); this->Stack.pop( );
			b = this->Stack.top( ); this->Stack.pop( );
			this->Stack.push( a - b );
			break;

		case IMUL:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( a * b );
			break;

		case IDIV:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( (int) a / b );
			break;

		case IMOD:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( a % b );
			break;

		case INEG:
			a = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( -1 * a );
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_float_math( )
{
	switch ( this->IR )
	{
		case FADD:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			g = real( b );
			this->Stack.push( unreal( f + g ) );
			break;

		case FSUB:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			g = real( b );
			this->Stack.push( unreal( f - g ) );
			break;

		case FMUL:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			g = real( b );
			this->Stack.push( unreal( f * g ) );
			break;

		case FDIV:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			g = real( b );
			this->Stack.push( unreal( f / g ) );
			break;

		case FMOD:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			g = real( b );
			this->Stack.push( unreal( fmod( f, g ) ) );
			break;

		case FNEG:
			a = this->Stack.top( );	this->Stack.pop( );
			f = real( a );
			this->Stack.push( unreal( -1 * f ) );
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_bitwise( )
{
	switch ( this->IR )
	{
		case NOT:
		case AND:
		case OR:
		case XOR:
		case COPY:
			break;
		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_io()
{
	switch ( this->IR )
	{
		case OUTCH:
			a = this->Stack.top( );	this->Stack.pop( );
			cout << (char) a;
			break;
		case OUTF:
			a = this->Stack.top( );	this->Stack.pop( );
			cout << (float) a;
			break;
		case OUTI:
			a = this->Stack.top( );	this->Stack.pop( );
			cout << (int) a;
			break;
		case OUTS:
			a = this->Stack.top( );	this->Stack.pop( );
			cout << "output string?";
			break;

		case INCH:
			cin >> a;
			this->Stack.push( a );
			break;
		case INF:
			cin >> a;
			this->Stack.push( a );
			break;
		case INI:
			cin >> a;
			this->Stack.push( a);
			break;
		case INS:
			a = this->Stack.top( );	this->Stack.pop( );
			b = this->Stack.top( );	this->Stack.pop( );
			this->Stack.push( a * b );
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_stack( )
{
	switch ( this->IR )
	{
		case DROP:
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}


void Graph_VM::sw_machine_op( )
{
	switch ( this->IR )
	{
		case MOV:
			break;

		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}



void Graph_VM::sw_logical_int_op( )
{
	switch ( this->IR )
	{
		case TPS:
			break;
		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

void Graph_VM::sw_logical_flt_op( )
{
	switch ( this->IR )
	{
		case TPSF:
			break;
		default:
			cout << "GVM ERROR: Unexpected IR " << this->IR << endl;
			break;
	}
}

