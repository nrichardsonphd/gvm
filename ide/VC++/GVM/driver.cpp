#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "Scanner.h"

void Get_Build_Number();


int main()
{
	cout << "Graph Virtual Machine\t";
	Get_Build_Number();
	cout << "Dr. Nicholas Richardson" << endl;
	return 0;
}


void Get_Build_Number()
{
	FILE *fp;
	char *build_number = new char[128];
	

	if ( fp = fopen( "./../../../.git/refs/heads/master", "r" ) )
	{
		fgets( build_number, 128, fp );
		fclose( fp );
	}
	else
	{
		build_number = "000-00-0000";
	}

	
	cout << "Build Number: " << build_number << endl;
}