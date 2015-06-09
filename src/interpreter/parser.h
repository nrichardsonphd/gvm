///////////////////////////////////////////////////////////////////////////////
///	\file parser.h
///		\author		Dr. Nicholas Richardson
///
///	Parser
///		\brief		This will parse the *.gvm file
///		\details
///			The parser takes the arrangement of tokens and finds the meaning to translate
///			to the graph virtual machine.
/// \see	Parser::Parse_File()
///////////////////////////////////////////////////////////////////////////////
#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <iostream>
using namespace std; 

#include "scanner.h"

class Parser
{
	public:
		Parser();										///< Standard Constructor
		~Parser();										///< Standard Destructor

		bool Parse_File( string filename );				///< Parse the file as part of a program
		bool Parse_Program( string filename );			///< Parse a program, this is where the gvm program will start

	private:
		Scanner scan;									///< Scanner for gvm file
		int token;										///< Holds the current token 
};

#endif	// PARSER_H