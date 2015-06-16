#include "graph_vm.h"


Graph_VM::Graph_VM( )
{
	this->done = false;
	this->program_counter = 0;
	this->IR = 0;
	this->R0 = 0;
	this->R1 = 0;
	this->R2 = 0;
	this->R3 = 0;
}


Graph_VM::~Graph_VM( )
{
}


unsigned int Graph_VM::next1()
{
	return 0;
}




void Graph_VM::cycle()
{
	this->IR = 0xef;
	switch ( this->IR )
	{
		case ADD:
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