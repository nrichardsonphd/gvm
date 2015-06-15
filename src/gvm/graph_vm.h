#ifndef GRAPH_VM
#define GRAPH_VM

#include "gvm_opcodes.h"
#include "gvm_memory.h"

class Graph_VM
{
	public:
		Graph_VM();
		~Graph_VM();


	private:
		unsigned int program_counter;					///< keep track of current instruction
		// instruction set
		
		// stack memory for local variables
		// heap memory for dynamic memory
		
		// binary file with instruction set?
		
		
};

#endif	// GRAPH_VM

