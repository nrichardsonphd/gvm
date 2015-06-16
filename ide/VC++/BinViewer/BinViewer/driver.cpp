#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
using namespace std;

int main()
{
	string filename = "../../../../tmp/tmp.hex";
	FILE *fp = fopen( filename.c_str(), "r");
	unsigned char c;
	std::string summary;
	summary.clear( );
	c = getc( fp );
	int i = 0;

	do
	{
		// make all output chars 2 spaces
		if ( c <= 0x0f )
			printf( "0" );
		
		printf("%X ", c );

		// summary output
		if ( c >= 0x20 && c <= 0x7E )
			summary += c;
		else
			summary += ".";

		// group by 8, 4 sections newline
		if ( i > 0 )
		{

			if ( i % 8 == 8 - 1 )
				printf( " " );

			if ( i % 16 == 16 - 1 )
			{
				summary += " ";
				printf( "\t %s\n", summary.c_str( ) );
				summary.clear( );
			}
		}

		c = getc( fp );
		++i;
	}
	while ( !feof( fp ) );

	fclose( fp );
	return 0;
}