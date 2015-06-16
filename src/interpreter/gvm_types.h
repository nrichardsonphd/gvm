#ifndef GVM_TYPES
#define GVM_TYPES

#include <string>

struct type
{
	unsigned int address;
	unsigned int size;
};

// standard types
struct Integer
{
	type address;
	int *location

};

struct Real
{
	float *location;
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
	int *g;
	int maxn, maxm;
	int vertices;
};

struct Class
{
	Graph *list;
};

#endif	//GVM_TYPES