#ifndef GVM_MEMORY
#define GVM_MEMORY
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "gvm_opcodes.h"

class GVM_Memory
{
	public:
		GVM_Memory();
		~GVM_Memory();

		void Set_Memory_Size( unsigned int max_size );				///< set maximum memory size
		bool Allocate_Memory();										///< allocate virtual memory
		void Clear_Memory();										///< clean allocated memory

		unsigned int get1( unsigned int addr );						///< get 1 byte from address
		unsigned int get2( unsigned int addr );						///< get 2 byte from address
		unsigned int get4( unsigned int addr );						///< get 4 byte from address
		int *get4_ptr( unsigned int addr );							///< get 4 byte from address, this is an actual pointer

		void put1( unsigned int addr, unsigned int value );			///< place 1 byte at address
		void put2( unsigned int addr, unsigned int value );			///< place 2 byte at address
		void put4( unsigned int addr, unsigned int value );			///< place 4 byte at address
		void put4( unsigned int addr, int *value );					///< place 4 byte at address, this is an actual pointer

		bool load( std::string filename );							///< load ram from filename
		void coredump_txt( std::string filename );					///< dump memory into text format
		void coredump( std::string filename );						///< dump memory into binary format

		void outHex( unsigned int );								///< output integer in hexadecimal
	private:
		std::vector<unsigned char> ram;								///< virtual memory for instruction set
		std::vector<unsigned int *> Data_Vector;					///< vector to store data variables for virtual machine
		int size;													///< size of virtual memory

};

#endif	// GVM_MEMORY