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

#define MAXN 128

//#include "nauty.h"

void Title_Screen();			///< Title screen for startup
void Get_Build_Number();		///< Find the Build number for Git
void To_Upper( string &str );	///< Convert string to upper case

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
	GVM_Memory mem;

	mem.Set_Memory_Size( 16 );
	mem.Allocate_Memory();
	mem.put4( 0, 0x44434241 );
	mem.put1( 8, 0xAA );
	mem.put2( 4, 0xDEAD );
	mem.put4( 12, 0x44434241 );
	mem.outHex( mem.get4( 0 ));

	mem.coredump( "tmp/tmp.hex" );
	string s = "soME CaSesS";
	cout << s << endl;
	To_Upper( s );
	cout << s << endl;
	mem.load( "tmp/tmp.hex" );
	gvm.cycle();
/*	graph g[MAXN*MAXM];
	
	
	EMPTYGRAPH( g, 2, 128 );
	ADDELEMENT( &g[0], 5 );
	ADDELEMENT( &g[5], 0 );
	
	cout << "maxn: " << MAXN << endl;
	cout << "maxm: " << MAXM << endl;
	cout << "ws: " << WORDSIZE << endl;
	*/
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
///		\details
///			Conver a string to uppercase letters.
///////////////////////////////////////////////////////////////////////////////
void To_Upper( string &str )
{
	for ( int i = 0; i < str.length(); ++i )
	{
		if ( str[i] >= 'a' && str[i] <= 'z' )
			str[i] -= 0x20;
	}
}