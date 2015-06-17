// math
#define	INC		0x01
#define	DEC		0x02
#define	ADD		0x03
#define	SUB		0x04
#define	MUL		0x05
#define	IDIV	0x06		// integer division
#define	MOD		0x07


#define	FADD	0x0a
#define	FSUB	0x0b
#define	FMUL	0x0c
#define	FDIV	0x0d		// float division
#define	FMOD	0x0e		// float modulus

#define	NEG		0x
#define	NOT		0x
#define	AND		0x
#define	OR		0x
#define	COPY	0x
#define	XOR		0x
#define	HALT	0x
#define	FLT		0x
#define	INT		0x

#define	DROP	0x
#define	SWAP	0x11
#define	JMP		0x
#define	JMPR	0x		// relative jump
#define	JMPD	0x		// direct jump

#define PUSH0
#define PUSH1
#define PUSH2
#define PUSH3
#define POP0
#define POP1
#define POP2
#define POP3

#define LOADD		// load direc
#define LOADI		// load indirect
#define LOADR		// load relative

//#define		0x

// I/O
#define	OUTCH	0x12
#define	OUTI	0x13
#define	OUTF	0x14
#define	OUTS	0x15
#define	INI		0x16
#define	INF		0x17
#define	INS		0x18
#define	INCH	0x19
//#define		0x
//#define		0x


//logical
#define	TPS		0x
#define	TNG		0x
#define	TZE		0x
#define	TNP		0x
#define	TNN		0x
#define	TNZ		0x
#define	TPSF	0x
#define	TNGF	0x
#define	TZEF	0x
#define	TNPF	0x
#define	TNNF	0x
#define	TNZF	0x

#define BYES		// branch yes
#define BNO			// branch no

#define JEZ			// jump equal to 0
#define JNZ			// jump not 0
#define JGZ			// jump greater than 0
#define JLZ			// jump less than 0
#define JNN			// jump not negative
#define JNP			// jump not positive


// graphs
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

// comparisons
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

// sets
#define IN
#define NOTIN

#define ADDG		// add graph to class
#define REMG		// remove graph from class


#define	DUMP	0x
#define	NOOP	0xFF
//#define		0x


//