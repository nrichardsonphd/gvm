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

	if ( this->fp = fopen( filename.c_str( ), "r" ) )
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

	if ( this->fp )
	{
		fclose( this->fp );
	}
}

void Scanner::Get_Next_Char()
{
	if ( this->fp )
	{
		this->next_char = fgetc( this->fp );
	}
}

int Scanner::Get_Next_Token()
{
	bool skip_char;
	this->token = 0;
	this->token_lit.clear();
	this->token_lit = this->token_lit + this->next_char;
	
	do
	{
		skip_char = false;
		
		switch ( this->next_char )
		{
			// check end of file of .gvm
			case EOF:
				this->token = TOK_ERR_EOF;
				break;

			// white space removal
			case '\t':
			case '\r':
			case '\n':
			case ' ':
				skip_char = true;
				break;

			case '/':
				this->Slash_Tokens();
				break;

			default:
				this->token = TOK_ERR;
				break;
		}

		// do not get token if part of multi character token and already has it
		if ( this->token != SLASH_TOK ) 
			this->Get_Next_Char( );
	}
	while ( skip_char );
	
	return this->token;
}

void Scanner::Slash_Tokens()
{
	char tmp;
	this->Get_Next_Char( );

	switch ( this->next_char )
	{
		case '/':	// line comment
			do
			{
				this->Get_Next_Char( );
			}
			while ( this->next_char != '\n' );
			break;

		case '*':	// block/inline comment
			do
			{
				this->Get_Next_Char( );
				tmp = this->next_char;
			}
			while ( tmp != '*' && this->next_char != '/' );
			break;

		case '=':	// divide equal
			this->token = SLASH_EQUAL_TOK;
			break;

		default:
			this->token = SLASH_TOK;
			break;
	}

}
bool Scanner::Test_Tokens( bool detailed_output )
{	
	this->Scan_File("./src/tests/tokens.gvm");

	

	return true;
}