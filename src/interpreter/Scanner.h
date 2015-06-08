#ifndef SCANNER_H
#define SCANNER_H

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


#include "Tokens.h"

//////////////////////////
/// Scanner
///		This class will scan through a *.gvm document an tokenize it.
///		The tokens can then be used by the parser.
//////////////////////////
class Scanner
{
	public:
		Scanner();
		~Scanner();

		bool Scan_File( string filename );		/// initialize file to scan, will close any open file
		void Close_File();
		int Get_Next_Token();					/// call to get the next token in file
		

		bool Test_Tokens( bool detailed );		/// test with default file for all tokens defined
												/// detail=true for output of each token
	private:
		void Get_Next_Char();

		void Slash_Tokens();
		void Less_Tokens();
		void Greater_Tokens();

		FILE *fp;								/// pointer to file to scan
		
		char next_char;							/// store the next character of the file, this is the buffer
		int token;								/// the last token found, set when new token is found
		string token_string;					/// build the string for the token when searching
		
};

#endif // SCANNER_H