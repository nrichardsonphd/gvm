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
#include <ctime>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "scanner.h"
#include "parser.h"

#include "graph_vm.h"
#include "gvm_asm.h"
#define MAXN 128

//#include "nauty.h"

void Title_Screen();			///< Title screen for startup
char *Get_Build_Number();		///< Find the Build number for Git
void Get_Run_Time();			///< Get current run time
void Update_Version_Number();	///< Automatically update version numbering system
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
	mem.put2( 4, 0xDEAD );
	mem.put1( 8, 0xAA );	
	mem.put4( 12, 0x44434241 );
	mem.outHex( mem.get4( 0 ));

	int *tmp = new int, *tmp2;
	*tmp = 0xff;

	cout << std::hex << "*: " << tmp << std::dec << "\tval: " << *tmp << endl;
	mem.put4( 8, tmp );

	tmp2 = mem.get4_ptr( 8 );
	
	cout << std::hex << "*: " << tmp2 << std::dec << "\tval: " << *tmp2 << endl;
	delete tmp;

	mem.coredump( "tmp/tmp.hex" );
	string s = "soME CaSesS123";
	cout << s << endl;
	To_Upper( s );
	cout << s << endl;
	mem.load( "tmp/tmp.hex" );


	gvm.load( "tmp/tmp.hex" );
	
	gvm.cycle();

	GVM_ASM gvm_asm;

	gvm_asm.convert( "src/tests/gvm.asm", "src/tests/gvm.x" );

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

	Update_Version_Number();
	Get_Run_Time();

	cout << string(79,'=') << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////
///		\details
///			Search git repository file structure to get build hash.
///////////////////////////////////////////////////////////////////////////////
char *Get_Build_Number( )
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

	fclose( fp );
	
	return build_number;
}


void Update_Version_Number()
{
	string build_date = __DATE__;
	string build_time = __TIME__;
	cout << "Build date: " << build_date << "\t\t\t\t\t   Build Time: " << build_time << endl;

	// get current version number
	cout << "Version ";
	FILE *fp = fopen( "version_no.txt", "r" );
	int version, revision, commit, build;
	fscanf( fp, "%i.%i.%i:%i", &version, &revision, &commit, &build );
	fclose( fp );
	
	// check commit number
	char *tmp = new char[128];
	string commit_hash;
	if ( fp = fopen( "log/commit_no.log", "r" ) )
	{
		fgets( tmp, 128, fp );
		commit_hash = tmp;
		fclose( fp );
	}
	else
	{
		// initial workspace, leavve commit number current
		commit_hash = "000-00-000";
	}

	fclose( fp ); 

	if ( commit_hash == "000-00-000" || commit_hash != Get_Build_Number() )
	{		
		fp = fopen( "log/commit_no.log", "w" );
		fprintf( fp, "%s", Get_Build_Number() );
		fclose( fp );
		commit++;
		build = 0;
	}

	cout << version << "." << revision << "." << commit << ":" << build;
	commit_hash.pop_back();		// remove newline char
	cout << "\t   Build Hash: " << commit_hash << endl;
	
	// check to update version numbering
	time_t t = time( 0 );		// current time
	const char *hh = &build_time.c_str()[0];		// hours
	const char *mm = &build_time.c_str()[3];		// minutes
	const char *ss = &build_time.c_str()[6];		// seconds

	// check difference between current time and build time, if < 10s adjust log file
	if ( localtime( &t )->tm_hour == atoi( hh ) && localtime( &t )->tm_min == atoi( mm ) && localtime( &t )->tm_sec - atoi( ss ) < 10 )
	{
		// This is likely the 1st run of the program, *** or same time as compiled on different day
		// update version number file
		fp = fopen( "version_no.txt", "w" );
		// add 1 to the build number
		// *** still need to figure out commit number
		fprintf( fp, "%i.%i.%i:%i\n", version, revision, commit, build + 1 );
		fclose( fp );
	}
	else
	{
		// do not update anything
	}

	
	
}


void Get_Run_Time()
{
	time_t t = time( 0 );
	cout << "Runtime: ";
	if ( localtime( &t )->tm_mon + 1 < 10 ) cout << "0"; cout << localtime( &t )->tm_mon + 1 << "-";
	if ( localtime( &t )->tm_mday < 10 ) cout << "0"; cout << localtime( &t )->tm_mday << "-";
	cout << localtime( &t )->tm_year + 1900 << " at ";

	if ( localtime( &t )->tm_hour < 10 ) cout << "0"; cout << localtime( &t )->tm_hour << ":";
	if ( localtime( &t )->tm_min < 10 ) cout << "0"; cout << localtime( &t )->tm_min << ":";
	if ( localtime( &t )->tm_sec < 10 ) cout << "0"; cout << localtime( &t )->tm_sec << endl;

}

///////////////////////////////////////////////////////////////////////////////
///		\details
///			Conver a string to uppercase letters.
///////////////////////////////////////////////////////////////////////////////
void To_Upper( string &str )
{
	for ( int i = 0; i < (int) str.length(); ++i )
	{
		if ( str[i] >= 'a' && str[i] <= 'z' )
			str[i] -= 0x20;
	}
}