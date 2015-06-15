/// \file driver.cpp
/// Graph Virtual Machine
/// This file contains the main function and the functions to set up the program.
/// This project will extend nauty by creating an language to interact with graphs easily.
/// \author Dr. Nicholas Richardson
/// \version Version 0
/// \see main()
///		\todo
///			add some type of version numbering


#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "scanner.h"
#include "parser.h"

#include "graph_vm.h"




#include "nauty.h"

void Title_Screen();			///< Title screen for startup
void Get_Build_Number();		///< Find the Build number for Git

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\param[in]		argc	argument count
///		\param[in]		argv	argument list
///		\details
///			This is the start of the program
///////////////////////////////////////////////////////////////////////////////
int main( int argc, char **argv )
{
	Title_Screen();

	//Scanner s;
	//s.Test_Tokens(true);

	//Parser p;
	//p.Parse_Program( "src/tests/code.gvm" );

	Graph_VM gvm;
	graph g[32];
	ADDELEMENT( &g[0], 5 );
	ADDELEMENT( &g[5], 0 );

	cout << "maxn: " << MAXN << endl;

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Display a default title screen when program starts.
///////////////////////////////////////////////////////////////////////////////
void Title_Screen()
{
	cout << "Graph Virtual Machine\t\t    GVM    \t\tDr. Nicholas Richardson" << endl;
	cout << string( 79, '=' ) << "\n"; 
	
	const char *ts = "Build date: " __DATE__ "\t\t\t   Build Time: " __TIMESTAMP__;
	cout << ts << endl;
	cout << "Build Hash ID: ";
	Get_Build_Number( );
	cout << endl;

	cout << string(79,'=') << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////
///		\author		Dr. Nicholas Richardson
///		\details
///			Search git repository file structure to get build hash.
///////////////////////////////////////////////////////////////////////////////
void Get_Build_Number( )
{
	FILE *fp;
	char *build_number = new char[128];
	

	if ( fp = fopen( "./.git/refs/heads/master", "r" ) )
	{
		fgets( build_number, 128, fp );
		fclose( fp );
	}
	else
	{
		build_number = "000-00-0000";
	}

	int i = 0;

	do
	{
		cout << build_number[i++];
	}
	while ( build_number[i] != '\n' );
	
}