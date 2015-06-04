// This file will have some functions to display tokens
#include "Tokens.h"

void Display_Token( int token )
{
	switch ( token )
	{
		case PLUS_TOK:
			cout << PLUS_TOK_LIT << endl;
			break;

		default:
			cout << "Token not found" << endl;

	};


}