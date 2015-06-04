// This file will contain all the tokens needed for the Graph Virtual Machine Language

// General programming tokens
// set theory tokens
// graph theory tokens
// operators

#include <iostream>
using namespace std;

#include "Token_Literals.h"
#include "Token_Keywords.h"

/////////////////////
// Operator tokens //
/////////////////////

// Single Tokens
#define PLUS_TOK							101
#define DASH_TOK							102
#define SLASH_TOK							103
#define BACKSLASH_TOK						104
#define STAR_TOK							105
#define EQUAL_TOK							106
#define AT_TOK								107
#define POUND_TOK							108
#define DOLLAR_TOK							109
#define PERCENT_TOK							110
#define SEMICOLON_TOK						111
#define APOSTROPHE_TOK						112
#define QUOTE_TOK							113
#define TILDE_TOK							114
#define LESS_TOK							115
#define GREATER_TOK							116
#define COMMA_TOK							117
#define PERIOD_TOK							118
#define QUESTION_TOK						119
#define PIPE_TOK							120
#define AMPERSAND_TOK						121
#define COLON_TOK							122
#define CARROT_TOK							123
#define BANG_TOK							124
#define UNDERSCORE_TOK						125
#define SPACE_TOK							126
#define TAB_TOK								127

// Paired Tokens
#define OPEN_PAREN_TOK						150
#define CLOSE_PAREN_TOK						151
#define OPEN_BRACKET_TOK					152
#define CLOSE_BRACKET_TOK					153
#define OPEN_BRACE_TOK						154
#define CLOSE_BRACE_TOK						155

// Double Tokens
#define BANG_EQUAL_TOK						201
#define EQUAL_TILDE_TOK						202
#define EQUAL_EQUAL_TOK						203
#define LESS_EQUAL_TOK						204
#define GREATER_EQUAL_TOK					205
#define LESS_GREATER_TOK					206
#define GREATER_LESS_TOK					207
#define BACKSLASH_SLASH_TOK					208
#define SLASH_BACKSLASH_TOK					209
#define GREATER_GREATER_TOK					210
#define LESS_LESS_TOK						211
#define STAR_STAR_TOK						212
#define PIPE_PIPE_TOK						213
#define DASH_GREATER_TOK					214
#define LESS_DASH_TOK						215
#define COLON_COLON_TOK						216
#define COLON_EQUAL_TOK						217
#define PLUS_EQUAL_TOK						218
#define STAR_EQUAL_TOK						219
#define DASH_EQUAL_TOK						220
#define SLASH_EQUAL_TOK						221
#define BACKSLASH_EQUAL_TOK					222
#define SLASH_SLASH_TOK						223

// Triple Tokens
#define GREATER_GREATER_EQUAL_TOK			301
#define LESS_LESS_EQUAL_TOK					302
#define LESS_LESS_LESS_TOK					303
#define GREATER_GREATER_GREATER_TOK			304

// Quadruple Tokens
#define LESS_LESS_LESS_EQUAL_TOK			401
#define GREATER_GREATER_GREATER_EQUAL_TOK	402

////////////////////
// Keyword Tokens //
////////////////////

// program structure
#define INCLUDE_TOK							501
#define START_TOK							502
#define END_TOK								503
#define FUNCTION_TOK						504
#define PROGRAM_TOK							505
#define CALL_TOK							506
#define RETURN_TOK							507

// control structures
#define IF_TOK								510
#define THEN_TOK							511
#define ELSE_TOK							512
#define ENDIF_TOK							513

#define SELECT_TOK							515
#define CASE_TOK							516
#define DEFAULT_TOK							517

// loop structures
#define FOR_TOK								520
#define TO_TOK								521
#define STEP_TOK							522
#define NEXT_TOK							523

#define DO_TOK								525
#define UNTIL_TOK							526

#define WHILE_TOK							527
#define WEND_TOK							528

// math
#define MOD_TOK								530
#define INFINITY_TOK						531
#define NULL_TOK							532
#define TRUE_TOK							533
#define FALSE_TOK							534

// user i/o
#define PRINT_TOK							540
#define INPUT_TOK							541

// file i/o
#define OPEN_TOK							545
#define CLOSE_TOK							546
#define READ_TOK							547
#define WRITE_TOK							548
#define EOF_TOK								549

// variables
#define INT_TOK								550
#define REAL_TOK							551
#define STRING_TOK							552
#define BOOL_TOK							553

// graph theory
#define CLASS_TOK							560
#define GRAPH_TOK							561
#define VERTEX_TOK							562
#define EDGE_TOK							563

// set theory
#define SET_TOK								570
#define AND_TOK								571
#define OR_TOK								572
#define XOR_TOK								573
#define NOT_TOK								574
#define IN_TOK								575
#define NOTIN_TOK							576

// special structure loops
#define FORALL_TOK							590
#define FA_TRUE_TOK							591
#define FA_FALSE_TOK						592
#define THERE_EXISTS_TOK					593
#define TE_TRUE_TOK							594
#define TE_FALSE_TOK						595



////////////////////
// Literal Tokens //
////////////////////
#define IDENTIFIER_TOK						601
#define KEYWORD_TOK							602
#define INTEGER_LITERAL_TOK					603
#define REAL_LITERAL_TOK					604
#define STRING_LITERAL_TOK					605
