///////////////////////////////////////////////////////////////////////////////
///	\file scanner.h
///		\author		Dr. Nicholas Richardson
///
/// Scanner
///		\brief		Scan a .gvm file for tokens
///		\details
///			This class will scan through a *.gvm document an tokenize it.
///			The tokens can then be used by the parser.
///			Send filename to Scan_File to start.
///			Call Get_Next_Token to get the token value that is next.
///////////////////////////////////////////////////////////////////////////////
#ifndef SCANNER_H
#define SCANNER_H

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


#include "tokens.h"

class Scanner
{
	public:
		Scanner();								///< Standard Constructor
		~Scanner();								///< Standard Destructor

		bool Scan_File( string filename );		///< \brief initialize file to scan, will close any open file
		void Close_File();						///< \brief Close file when finished
		int Get_Next_Token();					///< \brief Call to get the next token in file
		

		bool Test_Tokens( bool detailed );		///< \brief test with default file for all tokens defined
												///< detail=true for output of each token
	private:
		void Get_Next_Char();					///< Grab next character from file

		void Slash_Tokens();					///< \brief All tokens starting with a /
		void Less_Tokens();						///< \brief All tokens starting with a \<
		void Greater_Tokens();					///< \brief All tokens starting with a \>
		void Literal_Tokens();					///< \brief Deal with identifers, numbers and keywords

		FILE *fp;								///< pointer to file to scan
		
		char next_char;							///< store the next character of the file, this is the buffer
		int token;								///< the last token found, set when new token is found
		string token_string;					///< build the string for the token when searching
		
};

#endif // SCANNER_H