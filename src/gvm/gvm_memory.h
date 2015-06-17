#ifndef GVM_MEMORY
#define GVM_MEMORY
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <iostream>
using namespace std;

#include "gvm_opcodes.h"

class GVM_Memory
{
	public:
		GVM_Memory();
		~GVM_Memory();

		void Set_Memory_Size( unsigned int max_size );
		bool Allocate_Memory();

		unsigned int get1( unsigned int addr );
		unsigned int get2( unsigned int addr );
		unsigned int get4( unsigned int addr );
		int *get4_ptr( unsigned int addr );

		void put1( unsigned int addr, unsigned int value );
		void put2( unsigned int addr, unsigned int value );
		void put4( unsigned int addr, unsigned int value );
		void put4( unsigned int addr, int *value );

		bool load( std::string filename );
		void coredump_txt( std::string filename );
		void coredump( std::string filename );

		void outHex( unsigned int );
	private:
		unsigned char *ram;
		int size;

};

#endif	// GVM_MEMORY