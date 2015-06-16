#ifndef GRAPH_VM
#define GRAPH_VM

#include <stack>

#include "gvm_opcodes.h"
#include "gvm_memory.h"


class Graph_VM
{
	public:
		Graph_VM();
		~Graph_VM();

		bool load( string filename );
		float real( unsigned int );
		unsigned int unreal( float );

		unsigned int next1(); 
		unsigned int next2();
		unsigned int next4();

		void cycle();
	private:
		unsigned int program_counter;					///< keep track of current instruction
		unsigned char IR;								///< Instruction Register
		
		/// Registers for use during program
		unsigned int R0;
		unsigned int R1;
		unsigned int R2;
		unsigned int R3; 

		bool done;										///< check program finished
		
		GVM_Memory prgm;								///< Instruction set for program
		GVM_Memory RAM;									///< RAM for virtual machine
		std::stack<unsigned int> Stack;					///< stack for memory
		
};

#endif	// GRAPH_VM

