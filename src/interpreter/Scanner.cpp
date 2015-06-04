#include "Scanner.h"


Scanner::Scanner()
{
	this->detail = false;
	this->last_char = ' ';
	this->token = "";
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
		token = this->Get_Next_Token();
	}
	else
	{
		cout << "Unable To find test file." << endl;
		return false;
	}
}

void Scanner::Close_File()
{
	if ( fp )
	{
		fclose( fp );
	}
}

int Scanner::Get_Next_Token()
{
	return 0;
}

bool Scanner::Test_Tokens( bool detailed_output )
{	
	this->detail = detailed_output;
	return this->Scan_File("./src/tests/tokens.gvm");
}