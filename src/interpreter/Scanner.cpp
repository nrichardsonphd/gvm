#include "Scanner.h"

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Initialize buffer and token
///////////////////////////////////////////////////////////////////////////////
Scanner::Scanner()
{
	this->next_char = '\0';
	this->token = 0;
	this->token_string.clear();
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Will close any open file.
///////////////////////////////////////////////////////////////////////////////
Scanner::~Scanner( )
{
	this->Close_File();
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\param		filename	The file to scan should be *.gvm
///		\details
///			Scan the file "filename" ( should be .gvm ).  The 1st character will be retrieved.  An error (false) is returned if 
///			the file cannot be opened.
///////////////////////////////////////////////////////////////////////////////
bool Scanner::Scan_File( string filename )
{
	this->Close_File();

	if ( this->fp = fopen( filename.c_str(), "r" ) )
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

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Close the file and reset tokens
///////////////////////////////////////////////////////////////////////////////
void Scanner::Close_File( )
{
	this->next_char = '\0';
	this->token = 0;

	if ( this->fp )
	{
		fclose( this->fp );
	}
}

///////////////////////////////////////////////////////////////////////////////
/// Function Name
///		\author		Dr. Nicholas Richardson
///		\details
///			Grab the next character in the file.  This overwrites what is in next_char
///			The character is added to the token string.  If a token is reset after, 
///			this character must be added to the begining of the string.
///////////////////////////////////////////////////////////////////////////////
void Scanner::Get_Next_Char( )
{
	if ( this->fp )
	{
		this->next_char = fgetc( this->fp );
		this->token_string += this->next_char;
		
	}
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details	
///			Return the next token in the file
///////////////////////////////////////////////////////////////////////////////
int Scanner::Get_Next_Token( )
{
	bool skip_char = false;
	this->token = 0;
	
	// clear the current token string and eat whitespace
	do
	{
		this->token_string.clear();
		skip_char = false;

		switch ( this->next_char )
		{
			case '\t':
			case '\r':
			case '\n':
			case ' ':
				skip_char = true;
				this->Get_Next_Char();
				break;
			default:
				this->token_string += this->next_char;
				break;
		}
	}
	while ( skip_char );
		
	// 
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

			// single character only tokens
			case '\'': this->token = APOSTROPHE_TOK; break;
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
				
			// paired tokens
			case '(': this->token = OPEN_PAREN_TOK; break;
			case ')': this->token = CLOSE_PAREN_TOK; break;
			case '[': this->token = OPEN_BRACKET_TOK; break;
			case ']': this->token = CLOSE_BRACKET_TOK; break;
			case '{': this->token = OPEN_BRACE_TOK; break;
			case '}': this->token = CLOSE_BRACE_TOK; break;

			// multi character tokens

			case '/':
				this->Slash_Tokens();

				// get another token if it is a comment
			/*	if ( this->token == TOK_COMMENT )
				{
					this->Get_Next_Char();
					skip_char = true;
					this->token_string.clear( );
					this->token_string += this->next_char;
				}*/
				break;
	
			case '!':
				this->Get_Next_Char();

				if ( this->next_char == '=' )
				{
					this->token = BANG_EQUAL_TOK;
				}
				else
				{
					this->token = BANG_TOK;
				}

				break;

			case '|':
				this->Get_Next_Char();

				if ( this->next_char == '|' )
				{
					this->token = PIPE_PIPE_TOK;
				}
				else
				{
					this->token = PIPE_TOK;
				}

				break;

			case '&':
				this->Get_Next_Char();

				if ( this->next_char == '&' )
				{
					this->token = AMPERSAND_AMPERSAND_TOK;
				}
				else
				{
					this->token = AMPERSAND_TOK;
				}

				break;
			
			case '+':
				this->Get_Next_Char();

				if ( this->next_char == '=' )
				{
					this->token = PLUS_EQUAL_TOK;
				}
				else
				{
					this->token = PLUS_TOK;
				}

				break;

			case '-':
				this->Get_Next_Char();

				switch ( this->next_char )
				{
					case '>': this->token = DASH_GREATER_TOK; break;
					case '=': this->token = DASH_EQUAL_TOK; break;
					default: this->token = DASH_TOK; break;
				}

				break;

			case '\\':
				this->Get_Next_Char();

				switch ( this->next_char )
				{
					case '/': this->token = BACKSLASH_SLASH_TOK; break;
					case '=': this->token = BACKSLASH_EQUAL_TOK; break;
					default:  this->token = BACKSLASH_TOK; break; 
				}

				break;

			case '*':
				this->Get_Next_Char();
				
				switch ( this->next_char )
				{
					case '*': this->token = STAR_STAR_TOK; break;
					case '=': this->token = STAR_EQUAL_TOK; break;
					default: this->token = STAR_TOK; break;
				}

				break;


			case '=':
				this->Get_Next_Char();

				switch ( this->next_char )
				{
					case '~': this->token = EQUAL_TILDE_TOK; break;
					case '=': this->token = EQUAL_EQUAL_TOK; break;
					default: this->token = EQUAL_TOK; break;
				}

				break;

			case ':':
				this->Get_Next_Char();

				switch ( this->next_char )
				{
					case '=': this->token = COLON_EQUAL_TOK; break;
					case ':': this->token = COLON_COLON_TOK; break;
					default: this->token = COLON_TOK; break;
				}

				break;


			case '<':
				this->Less_Tokens();
				break;

			case '>':
				this->Greater_Tokens();
				break;

			case '\"':	// string literal
				this->token = QUOTE_TOK;

				do
				{
					this->Get_Next_Char( );
				}
				while ( this->next_char != '\"' && this->next_char != EOF );

				if ( this->next_char == '\"' )
					this->token = STRING_LITERAL_TOK;

				break;

			default:	
				// deal with identifers, numbers and keywords
				this->Literal_Tokens();		
	
				break;
		}

		// do not get token if it is lead only of multi character token and already has it
		// / is 1st of  // and /*; if only /, the next character is already in the buffer
		//							/ \ * - = + : ! | < > &		single only	, char in buffer
		// <, <<, <<<, >, >>, >>> all have character in buffer
		if ( this->token != SLASH_TOK		&& this->token != BACKSLASH_TOK			&& this->token != STAR_TOK				&&
			 this->token != DASH_TOK		&& this->token != EQUAL_TOK				&& this->token != PLUS_TOK				&&
			 this->token != COLON_TOK		&& this->token != BANG_TOK				&& this->token != PIPE_TOK				&&
			 this->token != IDENTIFIER_TOK	&& this->token != NUMBER_LITERAL_TOK	&& this->token != AMPERSAND_TOK			&&
			 this->token != LESS_TOK		&& this->token != LESS_LESS_TOK			&& this->token != LESS_LESS_LESS_TOK	&&
			 this->token != GREATER_TOK		&& this->token != GREATER_GREATER_TOK	&& this->token != GREATER_GREATER_GREATER_TOK
			)
		{
			this->Get_Next_Char();
		}
		
		// remove the last character from the token string
		this->token_string.pop_back();
		

		
	}
	while ( skip_char );
	
	return this->token;
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details 
///			This function will find numbers, strings, and identifiers.
///			A keyword is an identifier that matches a keyword in the GVM language
///			Numbers are only literals, just a string 0-9, no decimals, +, -
///			A string is surrounded by ""
///////////////////////////////////////////////////////////////////////////////
void Scanner::Literal_Tokens()
{
	if ( ( this->next_char >= 'a' && this->next_char <= 'z' ) || ( this->next_char >= 'A' && this->next_char <= 'Z' ) )
	{
		//This is a identifier or keyword  // the 1st character cannot be a number or underscore
		while ( ( this->next_char >= 'a' && this->next_char <= 'z' ) || ( this->next_char >= 'A' && this->next_char <= 'Z' ) ||
				( this->next_char >= '0' && this->next_char <= '9' ) || this->next_char == '_' )
		{
			this->Get_Next_Char();
		}
		
		// check if a keyword

		this->token = IDENTIFIER_TOK;
	}
	else if ( ( this->next_char >= '0' && this->next_char <= '9' ) )
	{
		// This is a number
		while ( this->next_char >= '0' && this->next_char <= '9' )
		{
			this->Get_Next_Char();
		}

		this->token = NUMBER_LITERAL_TOK;
	}
	else
	{
		// Unknown token
		this->token = TOK_ERR;
	}

//	this->token_string.pop_back( );

}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Subprogram that deals with all tokens whose 1st character is a /
///			If the token is only /  then you should not get the next character since it is in the buffer.
///			If the token is /* it is a comment
///			If the token is / something, a call to Get_Next_Char() should be down to update buffer.
///////////////////////////////////////////////////////////////////////////////
void Scanner::Slash_Tokens( )
{
	bool comment = false;
	char tmp;
	this->Get_Next_Char();

	switch ( this->next_char )
	{
		case '/':	// line comment
			do
			{
				this->Get_Next_Char();
			}
			while ( this->next_char != '\n' && this->next_char != EOF );
			this->token = TOK_LINE_COMMENT;
			break;

		case '*':	// block/inline comment
			do
			{
				tmp = this->next_char;
				this->Get_Next_Char();				
			}
			while ( tmp != '*' || this->next_char != '/' && this->next_char != EOF );
			this->token = TOK_BLOCK_COMMENT;
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

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Subprogram that deals with all tokens whose 1st character is a <
///			If the token is only <  then you should not get the next character since it is in the buffer.
///			If the token is < something, a call to Get_Next_Char() should be down to update buffer.
///			This has the possibility of being <<< or <<<=, similar conditions for updating buffer
///////////////////////////////////////////////////////////////////////////////
void Scanner::Less_Tokens( )
{
	this->Get_Next_Char();

	switch ( this->next_char )
	{
		case '<':	// may be 3 or 4 character token
			this->Get_Next_Char();

			switch ( this->next_char )
			{
				case '<': 
					this->Get_Next_Char();

					if ( next_char == '=' )
					{
						this->token = LESS_LESS_LESS_EQUAL_TOK;
					}
					else
					{
						this->token = LESS_LESS_LESS_TOK;
					}

					break;

				case '=': this->token = LESS_LESS_EQUAL_TOK; break;
				default: this->token = LESS_LESS_TOK; break;
			}

			break;

		case '>': this->token = LESS_GREATER_TOK; break;
		case '=': this->token = LESS_EQUAL_TOK; break;
		case '-': this->token = LESS_DASH_TOK; break;
		default: this->token = LESS_TOK; break;
	}

}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Subprogram that deals with all tokens whose 1st character is a >
///			If the token is only >  then you should not get the next character since it is in the buffer.
///			If the token is > something, a call to Get_Next_Char() should be down to update buffer.
///			This has the possibility of being >>> or >>>=, similar conditions for updating buffer
///////////////////////////////////////////////////////////////////////////////
void Scanner::Greater_Tokens()
{
	this->Get_Next_Char();

	switch ( this->next_char )
	{
		case '>':	// may be 3 or 4 character token
			this->Get_Next_Char( );

			switch ( this->next_char )
			{
				case '<':
					this->Get_Next_Char( );

					if ( next_char == '=' )
					{
						this->token = GREATER_GREATER_GREATER_EQUAL_TOK;
					}
					else
					{
						this->token = GREATER_GREATER_GREATER_TOK;
					}

					break;

				case '=': this->token = GREATER_GREATER_EQUAL_TOK; break;
				default: this->token = GREATER_GREATER_TOK; break;
			}
			break;

		case '<': this->token = GREATER_LESS_TOK; break;
		case '=': this->token = GREATER_EQUAL_TOK; break;
		default: this->token = GREATER_TOK;	break;
	}
}



///////////////////////////////////////////////////////////////////////////////
// Test_Tokens
///		\author		Dr. Nicholas Richardson
///		\param		detailed_output		Show all tokens or just test that it works(T/F)
///		\details	
///			This will read a file to test that all tokens are read correctly.
///////////////////////////////////////////////////////////////////////////////
bool Scanner::Test_Tokens( bool detailed_output )
{	
	this->Scan_File("./src/tests/tokens.gvm");
	int tk = 0;
	int i = 0;

	do
	{
		tk = this->Get_Next_Token();

		cout << "Token found " << ++i << ": ";
		Display_Token( tk );
		cout << " " << " <" << tk << "> " << this->token_string << endl;
	}
	while ( this->token != TOK_ERR_EOF );

	return true;
}