#ifndef GRAPH_VM
#define GRAPH_VM

#include <stack>

#include "gvm_opcodes.h"
#include "gvm_memory.h"

// may need to deal with nauty here


class Graph_VM
{
	public:
		Graph_VM();
		~Graph_VM();

		bool load( string filename );					///< load file for virtual machine
		float real( unsigned int );
		unsigned int unreal( float );

		unsigned int next1();							///< get next 1 byte from instruction set
		unsigned int next2();							///< get next 2 bytes from instruction set
		unsigned int next4();							///< get next 4 bytes from instruction set

		void cycle();									///< Execute next instruction on virtual machine
	private:
		unsigned int program_counter;					///< keep track of current instruction
		unsigned char IR;								///< Instruction Register
		
		/// General Registers for use during program
		unsigned int R0;
		unsigned int R1;
		unsigned int R2;
		unsigned int R3; 

		bool done;										///< check program finished
		
		GVM_Memory RAM;									///< RAM for virtual machine
		std::stack<unsigned int> Stack;					///< stack for memory
		
		
		void initialize();								///< initialize virtual machine
};

#endif	// GRAPH_VM

