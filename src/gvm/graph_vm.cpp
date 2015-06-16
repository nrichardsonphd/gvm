#include "graph_vm.h"


Graph_VM::Graph_VM( )
{
	this->initialize( );
}


Graph_VM::~Graph_VM( )
{

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
	int a, b, c = 0;
	
	switch ( this->IR )
	{
		case ADD:
			a = this->Stack.top();	this->Stack.pop();
			b = this->Stack.top();	this->Stack.pop();
			this->Stack.push( a + b );
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


void Graph_VM::initialize()
{
	this->done = false;
	this->program_counter = 0;
	this->IR = 0;
	this->R0 = 0;
	this->R1 = 0;
	this->R2 = 0;
	this->R3 = 0;

}