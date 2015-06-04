#ifndef SCANNER_H
#define SCANNER_H

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


#include "Tokens.h"
#include "Token_Literals.h"

class Scanner
{
	public:
		Scanner();
		~Scanner();

		bool Scan_File( string filename );		// initialize file to scan, will close any open file
		void Close_File();
		int Get_Next_Token();					// call to get the next token in file
		

		bool Test_Tokens( bool detailed );		// test with default file for all tokens defined
												// detail=true for output of each token
	private:
		char Get_Next_Char( );				



		FILE *fp;						// pointer to file to scan
		char last_char;					// stores last character read

		string token;
		
		bool detail;
};

#endif // SCANNER_H