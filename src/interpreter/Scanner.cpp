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
	bool skip_char = false;
	this->token = 0;
		
	do
	{
		// get the next character after a comment
		if ( skip_char )
		{
			this->Get_Next_Char();
		}

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

			// single character only tokens
			case '\'': this->token = APOSTROPHE_TOK; break;
			case '\"': this->token = QUOTE_TOK; break;
			case '#': this->token = POUND_TOK; break;
			case '$': this->token = DOLLAR_TOK; break;
			case '%': this->token = PERCENT_TOK; break;
			case ',': this->token = COMMA_TOK; break;
			case '.': this->token = PERIOD_TOK; break; 
			case ';': this->token = SEMICOLON_TOK; break; 
			case '?': this->token = QUESTION_TOK; break; 
			case '@': this->token = AT_TOK; break; 
			case '^': this->token = CARROT_TOK; break;
			case '_': this->token = UNDERSCORE_TOK; break;
			case '~': this->token = TILDE_TOK; break;
				
			// multi character tokens

			case '/':
				this->Slash_Tokens( );

				// get another token if it is a comment
				if ( this->token == TOK_COMMENT )
					skip_char = true;
				break;

			case '\\':
			case '*':
			case '-':
			case '=':
			case '+':
			case ':':
			case '!':
			case '|':
			case '<':
			case '>':
			case '&':
				break;
			default:
				this->token = TOK_ERR;
				break;
		}

		// do not get token if it is lead only of multi character token and already has it
		// / is 1st of  // and /*; if only /, the next character is already in the buffer
		//							/ \ * - = + : ! | < > &		single only
		if ( this->token != SLASH_TOK		&&this->token != BACKSLASH_TOK		&& this->token != STAR_TOK		&&
			 this->token != DASH_TOK		&& this->token != EQUAL_TOK			&& this->token != PLUS_TOK		&&
			 this->token != COLON_TOK		&& this->token != BANG_TOK			&& this->token != PIPE_TOK		&&
			 this->token != LESS_TOK		&& this->token != GREATER_TOK		&& this->token != AMPERSAND_TOK )
		{
			this->Get_Next_Char();
		}

		
	}
	while ( skip_char );
	
	return this->token;
}

// Contains all tokens that start with slash.
void Scanner::Slash_Tokens()
{
	bool comment = false;
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
			this->token = TOK_COMMENT;
			break;

		case '*':	// block/inline comment
			do
			{
				this->Get_Next_Char( );
				tmp = this->next_char;
			}
			while ( tmp != '*' && this->next_char != '/' );
			this->token = TOK_COMMENT;
			break;

		case '=':	// divide equal
			this->token = SLASH_EQUAL_TOK;
			break;

		case '\\':
			this->token = SLASH_BACKSLASH_TOK;
			break;

		default:
			this->token = SLASH_TOK;
			break;
	}

}

void Scanner::Less_Tokens()
{
	this->Get_Next_Char( );

	switch ( this->next_char )
	{
		case '<':	// may be 3 or 4 character token
			break;

		case '>': this->token = LESS_GREATER_TOK; break;
		case '=': this->token = LESS_EQUAL_TOK; break;
		case '-': this->token = LESS_DASH_TOK; break;
		default: this->token = LESS_TOK; break;
	}

}

void Scanner::Greater_Tokens()
{
	this->Get_Next_Char( );

	switch ( this->next_char )
	{
		case '>':	// may be 3 or 4 character token
			break;

		case '<': this->token = GREATER_LESS_TOK; break;
		case '=': this->token = GREATER_EQUAL_TOK; break;
		default: this->token = GREATER_TOK;	break;
	}
}

bool Scanner::Test_Tokens( bool detailed_output )
{	
	this->Scan_File("./src/tests/tokens.gvm");

	

	return true;
}