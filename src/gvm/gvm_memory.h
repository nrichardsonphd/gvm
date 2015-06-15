#ifndef GVM_MEMORY
#define GVM_MEMORY

class GVM_Memory
{
	public:
		GVM_Memory();
		~GVM_Memory();

		unsigned int get1( unsigned int addr );
		unsigned int get2( unsigned int addr );
		unsigned int get4( unsigned int addr );

	private:
		char *ram;

};

#endif	// GVM_MEMORY