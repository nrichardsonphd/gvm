#include "Scanner.h"


Scanner::Scanner()
{
	this->next_char = '\0';
	this->token = 0;
}


Scanner::~Scanner()
{
	this->Close_File();
}

bool Scanner::Scan_File( string filename )
{
	this->Close_File( );

	if ( fp = fopen( filename.c_str(), "r" ) )
	{
		this->Get_Next_Char();
		return true;
	}
	else
	{
		cout << "Unable To find test file." << endl;
		return false;
	}
}

void Scanner::Close_File()
{
	this->next_char = '\0';
	this->token = 0;

	if ( fp )
	{
		fclose( fp );
	}
}

void Scanner::Get_Next_Char()
{
	if ( fp )
	{
		next_char = fgetc( fp );
	}
}

int Scanner::Get_Next_Token()
{


	
	
	return 0;
}

bool Scanner::Test_Tokens( bool detailed_output )
{	
	this->Scan_File("./src/tests/tokens.gvm");

	

	return true;
}