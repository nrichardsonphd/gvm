#ifndef GVM_TYPES
#define GVM_TYPES

#include <string>

// standard types
struct Integer
{
	int value;
};

struct Real
{
	float value;
};

struct String
{
	string str;
};


// set types
struct Set
{
	unsigned int *values;
};

// Graph types
struct Vertex
{
	int v;
};

struct Edge
{
	int v1;
	int v2;
};

// *** change to nauty
struct Graph
{
	int g[32];
};

struct Class
{
	Graph *list;
};

#endif	//GVM_TYPES