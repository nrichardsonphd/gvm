#ifndef GVM_ASM_H
#define GVM_ASM_H
#define _CRT_SECURE_NO_DEPRECATE

// convert an assembly GVM language file (text) to a binary gvm executable file

#include <string>

#include "gvm_opcodes.h"
#include "graph_vm.h"

class GVM_ASM
{
	public:
		GVM_ASM();
		~GVM_ASM();

		bool convert( string filename_in, string filename_out );

	private:
		unsigned int Get_OpCode();

		char token[16];
		unsigned int data1, data2;
		float real;

};

#endif