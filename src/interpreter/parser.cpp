///////////////////////////////////////////////////////////////////////////////
///	\file parser.cpp
///	\author		Dr. Nicholas Richardson
///
///	Parser
///	\todo Create the BNF
///	\tode Create the parser
///////////////////////////////////////////////////////////////////////////////
#include "parser.h"

///////////////////////////////////////////////////////////////////////////////
///	Standard Constructor
///////////////////////////////////////////////////////////////////////////////
Parser::Parser()
{

}

///////////////////////////////////////////////////////////////////////////////
///	\details
///	The destructor will close any open files
///////////////////////////////////////////////////////////////////////////////
Parser::~Parser()
{

}

///////////////////////////////////////////////////////////////////////////////
///	\param[in]		filename		Name of the file to parse in gvm language
///	\return			bool			Returns false if errors occured
///	
///	The file will be parsed through the GVM BNF.  This function parses only
/// an individual file.  Multiple files may be included in a single program,
/// this function parse only 1 of them at a time.
///
///	\note START and END (PROGRAM) should not occur in this file
/// \see Parser::Parse_Program()
///////////////////////////////////////////////////////////////////////////////
bool Parser::Parse_File( string filename )
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////
///	\param[in]		filename		Name of the file to parse in gvm language
///	\return			bool			Returns false if errors occured
///	
///	This will be called when starting to parse a program.  This should contain 
/// the keywords START and END for the main program in the GVM.  Other files may
/// be included, but those files should only have function definitions.  Each
/// individual file will be parsed in Parser::Parse_File().  This function deals
/// with the overall structure of the program.
/// \see Parser::Parse_File()
///////////////////////////////////////////////////////////////////////////////
bool Parser::Parse_Program( string filename )
{
	// open the file and grab the 1st token
	scan.Scan_File( filename );
	
	do
	{
		this->token = scan.Get_Next_Token( );
		Display_Token( this->token ); cout << " <::>" <<  scan.Get_Token_String() << endl;
		
		switch ( token )
		{
			/// Get Include files Block
			case INCLUDE_TOK:
				break;
			
			/// Function Block
			case FUNCTION_TOK:
				break;
			
			/// get global variables
			case REAL_TOK:
				break;

			case START_TOK:
				// expect identifier, PROGRAM starts main portion, any other id is a function
				this->token = this->scan.Get_Next_Token();
				
				if ( this->token == PROGRAM_TOK )
					cout << "program";
				break;

			default:
				break;
		};
	}
	while ( this->token != TOK_ERR_EOF );



	scan.Close_File();
	return true;
}

