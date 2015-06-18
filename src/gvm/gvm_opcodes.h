#ifndef GVM_OPCODES_H
#define GVM_OPCODES_H

// Operations take 1 or 2 arguments
//	OP SRC DEST
//	OP TOP_OF_STACK
//	T/F operations place 
//		0x00 on top FALSE
//		0xFF on top TRUE

// math
#define	INC			0x01		
#define	DEC			0x02		
#define	FLT			0x03			// make integer to float
#define	INT			0x04			// make float to integer

// integer specific
#define	IADD		0x10
#define	ISUB		0x11
#define	IMUL		0x12
#define	IDIV		0x13			// integer division
#define	IMOD		0x14
#define	INEG		0x15			// negate top of stack

// real specific
#define	FADD		0x16
#define	FSUB		0x17
#define	FMUL		0x18
#define	FDIV		0x19			// float division
#define	FMOD		0x1a			// float modulus
#define	FNEG		0x1b			// negate top of stack

// bitwise operators
#define	NOT			0x20			
#define	AND			0x21			
#define	OR			0x22			
#define	XOR			0x23			
#define	COPY		0x24			// copy src, dest

// standard I/O
#define	OUTI		0x30			// integer
#define	OUTF		0x31			// float
#define	OUTCH		0x32			// character
#define	OUTS		0x33			// string

#define	INI			0x34			// integer
#define	INF			0x35			// float
#define	INCH		0x36			// char
#define	INS			0x37			// string

// Machine Operations
// use R0 - R3, IR, PC, memory
#define MOV			0x40			// src, dest
#define LOADD		0x41			// load direct
#define LOADI		0x42			// load indirect
#define LOADR		0x43			// load relative


// Stack Related
#define	DROP		0x44			// drop top of stack
#define	SWAP		0x45			// swap top two stack elements

// registers R0-R3		
// push register on top of stack
#define PUSH0		0x50
#define PUSH1		0x51
#define PUSH2		0x52
#define PUSH3		0x53

// pop top of stack to register
#define POP0		0x54
#define POP1		0x55
#define POP2		0x56
#define POP3		0x57

//logical
// test top of stack and replace TRUE/FALSE on top, stack is popped when tested
#define	TPS			0x60			// test positive
#define	TNG			0x61			// test negative
#define	TZE			0x62			// test zero
#define	TNP			0x63			// test not positive
#define	TNN			0x64			// test	not negative
#define	TNZ			0x65			// test not zero

// float tests
#define	TPSF		0x66			// test positive
#define	TNGF		0x67			// test negative
#define	TZEF		0x68			// test zero
#define	TNPF		0x69			// test not positive
#define	TNNF		0x6a			// test	not negative
#define	TNZF		0x6b			// test not zero

// conditional jump, check top of stack TRUE/FALSE
#define BYES		0x70			// branch yes
#define BNO			0x71			// branch no

// normal jump
#define	JMP			0x72
#define	JMPR		0x73			// relative jump
#define	JMPD		0x74			// direct jump



// Graph stuff is below


/*
// Only 3 types of sets allowed.
//	1. Class - set of graphs
//	2. Vertex set
//	3. Edge set
//	A graph contains 1 edgeset and 1 vertex set
// sets
#define IN
#define NOTIN
#define ADDG		// add graph to class
#define REMG		// remove graph from class



// output for graphs
#define OUTG6			// g6 format
#define OUTADJ			// adjacency matrix
#define OUTEL			// edge list

// input for graphs
#define ING6

// graphs specific
#define ADDE		// add edge to G
#define DELE		// delete edge from G
#define ADDV		// add vertex to G
#define DELV		// delete vertex from G
#define CONTE		// contract edge
#define SUBDE		// subdivide edge
#define COEXT		// coextend edge	*creates a family of graphs
#define JOIN		// join two graphs
#define UNIONS		// union two sets
#define INTERSECTS	// intersect two sets
#define UNIONG		// union two graphs
#define INTERSECTG	// intersect two graphs
#define DUNIONG		// disjoint union two graphs

#define COMPL		// edge complement graph
#define CANONG		// canonize graph
#define DEGREE		// degree of vertex
#define INDUCEG		// induce subgraph

#define YDELTA		// Y-delta transformation
#define DELTAY		// Delta-Y transformation

#define TRIM		// trim graph	d(v) =/= 1
#define SMOOTH		// smooth graph d(v) =/= 2
#define TSMTH		// trim and smoot	d(G) >= 3

// graph comparisons
// subgraph comparisons labeling
#define PSUBGRAPH
#define SUBGRAPH
#define PSUPGRAPH
#define SUPGRAPH

// subgraph comparisons isomorphic
#define PSUBGRAPHI	
#define SUBGRAPHI
#define PSUPGRAPHI
#define SUPGRAPHI

#define EQL
#define NEQ
#define ISO



*/






// Final machine opcodes
#define ERR		0xFC		// program error ( exit )
#define	HALT	0xFD		// end of program
#define	DUMP	0xFE		// core dump
#define	NOOP	0xFF		// no operation to be done


#endif	// GVM_OPCODES