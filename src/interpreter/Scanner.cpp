#include "Scanner.h"


Scanner::Scanner()
{

}


Scanner::~Scanner()
{

}

bool Scanner::Test_Tokens( bool detailed )
{	
	FILE *fp;

	if ( fp = fopen( "./src/tests/tokens.gvm", "r" ) )
	{
		cout << "Testing to get tokens" << endl;
	}
	else
	{
		cout << "Unable To find test file." << endl;
		return false;
	}


	return true;
}