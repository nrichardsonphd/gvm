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
	
		void initialize( );								///< initialize virtual machine
		bool load( string filename );					///< load file for virtual machine
		
		/// use these two functions to have 1 stack of unsigned ints
		float real( unsigned int );						///< make a float
		unsigned int unreal( float );					///< make a integer

		unsigned int next1();							///< get next 1 byte from instruction set
		unsigned int next2();							///< get next 2 bytes from instruction set
		unsigned int next4();							///< get next 4 bytes from instruction set

		void cycle();									///< Execute next instruction on virtual machine
	private:
		unsigned int program_counter;					///< keep track of current instruction
		unsigned char IR;								///< Instruction Register
		unsigned int maxn;								///< Register for largest size of graph

		/// General Registers for use during program
		unsigned int R0;
		unsigned int R1;
		unsigned int R2;
		unsigned int R3; 

		
		

		bool done;										///< check program finished
		
		GVM_Memory RAM;									///< RAM for virtual machine
		std::stack<unsigned int> Stack;					///< stack for memory
	
		// temporary to help in cycle
		int a, b;
		float f, g;
		char c, d;
		string str;
	
		// functions to help in cycle
		void sw_int_flt_math();
		void sw_int_math();
		void sw_float_math();
		void sw_io();
		void sw_bitwise();
		void sw_stack();
		void sw_machine_op();
		void sw_logical_int_op();
		void sw_logical_flt_op( );

};

#endif	// GRAPH_VM

