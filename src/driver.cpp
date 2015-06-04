// Graph Virtual Machine
// This project will extend nauty by creating an language to interact with graphs easily.
// Dr. Nicholas Richardson



#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "Scanner.h"

void Title_Screen();
void Get_Build_Number();


int main()
{
	Title_Screen();

	Scanner s;
	s.Test_Tokens(true);

	return 0;
}

void Title_Screen()
{
	cout << "Graph Virtual Machine\t\t\t\t\tDr. Nicholas Richardson" << endl;
	cout << string( 79, '=' ) << "\n"; 
	
	const char *ts = "Build date: " __DATE__ "\t\t\t   Build Time: " __TIMESTAMP__;
	cout << ts << endl;
	cout << "Build Hash ID: ";
	Get_Build_Number( );
	cout << endl;

	cout << string(79,'=') << endl << endl;
}

void Get_Build_Number()
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