#include "gvm_memory.h"


GVM_Memory::GVM_Memory()
{
	this->size = 64;
	this->Allocate_Memory();

	
}


GVM_Memory::~GVM_Memory()
{

}

void GVM_Memory::Set_Memory_Size( unsigned int max_size )
{
	this->size = max_size;
	this->Allocate_Memory();
}


bool GVM_Memory::Allocate_Memory()
{
	// allocate
	this->ram.resize( this->size );
	this->Clear_Memory();

	return true;
}

void GVM_Memory::Clear_Memory()
{
	// initialize
	for ( int i = 0; i < this->size; ++i )
	{
		this->ram[i] = NOOP;
	}
}

void GVM_Memory::put1( unsigned int address, unsigned int value )
{
	this->ram[address] = value & 0xFF;
}

void GVM_Memory::put2( unsigned int address, unsigned int value )
{
	this->put1( address, value );
	this->put1( address + 1, value >> 8 );
}

void GVM_Memory::put4( unsigned int address, unsigned int value )
{
	this->put2( address, value );
	this->put2( address+2, value >> 16 );
}

void GVM_Memory::put4( unsigned int address, int *value )
{
	this->put4( address, (unsigned int) value );
}

unsigned int GVM_Memory::get1( unsigned int address )
{
	unsigned int ret = this->ram[address];
	return ret;
}

unsigned int GVM_Memory::get2( unsigned int address )
{
	unsigned int ret = get1( address ) | ( get1( address + 1 ) << 8 );
	return ret;
}

unsigned int GVM_Memory::get4( unsigned int address )
{
	unsigned int ret = get2( address ) | ( get2( address + 2 ) << 16 );
	return ret;
}

int *GVM_Memory::get4_ptr( unsigned int address )
{
	return (int *) this->get4( address );
}

void GVM_Memory::coredump_txt( std::string filename )
{
	std::string summary;
	summary.clear();

	FILE *fp = fopen( filename.c_str(), "w" );
	
	for ( int i = 0; i < this->size; ++i )
	{
		// make all output chars 2 spaces
		if ( this->ram[i] < 0xf )
			fprintf( fp, "0");
		fprintf( fp, "%x ", this->ram[i] );

		// summary output
		if ( this->ram[i] >= 0x20 && this->ram[i] <= 0x7E )
			summary += this->ram[i];
		else
			summary += ".";

		// group by 8, 4 sections newline
		if ( i > 0 )
		{

			if ( i % 8 == 8-1 )
				fprintf( fp, " " );

			if ( i % 16 == 16 - 1 )
			{
				fprintf( fp, " " );
				summary += " ";
			}

			if ( i % 32 == 32 - 1 )
			{
				fprintf( fp, "\t %s\n", summary.c_str() );
				summary.clear();
			}
		}


	}

	fclose( fp );
}

void GVM_Memory::coredump( std::string filename )
{
	FILE *fp = fopen( filename.c_str(), "wb" );

	for ( int i = 0; i < this->size; ++i )
	{
		//fprintf( fp, "%u", this->ram[i] );
		putc( this->ram[i], fp );
	}

	fclose( fp );

}

bool GVM_Memory::load( std::string filename )
{
	FILE *fp = fopen( filename.c_str(), "rb" );
	unsigned char c;

	if ( fp == NULL )
	{
		cout << "GVM_Memory::Error opening file." << endl;
		return false;
	}

	// get file size
	fseek( fp, 0, SEEK_END );
	this->size = ftell( fp );

	if ( this->size == -1 )
	{
		cout << "GVM_Memory::Error finding file size." << endl;
		return false;
	}

	fseek( fp, 0, 0 );		// rewind

	this->Allocate_Memory();
	int pos = 0;
	c = fgetc( fp );

	do
	{
		this->put1( pos++, c );
		c = fgetc( fp );
	}
	while ( !feof( fp ) );

	fclose( fp );

	return true;
}


void GVM_Memory::outHex( unsigned int hex )
{
	cout << std::hex << (( hex >> 24 ) & 0xff) << " " << ( (hex >> 16 ) & 0xff) << " " <<( ( hex >> 8 ) & 0xff )<< " " << (hex & 0xff) << endl;
	cout << " " << (char) ( ( hex >> 24 ) & 0xff ) << "  " << (char) ( ( hex >> 16 ) & 0xff ) << "  " << (char) ( ( hex >> 8 ) & 0xff ) << "  " << (char) ( hex & 0xff ) << endl;
}