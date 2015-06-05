// This file will have some functions to display tokens
#include "Tokens.h"

void Display_Token( int token )
{
	switch ( token )
	{
		case TOK_ERR_EOF:	cout << "End of file token" << endl; break;
		case TOK_IDENTIFIER: cout << "Identifier token" << endl; break;
		case TOK_COMMENT: cout << "Comment token" << endl;


		// Single Tokens
		case PLUS_TOK: cout << PLUS_TOK_LIT << endl; break; 
		case DASH_TOK: cout << DASH_TOK_LIT << endl; break;
		case SLASH_TOK: cout << SLASH_TOK_LIT << endl; break;
		case BACKSLASH_TOK: cout << BACKSLASH_TOK_LIT << endl; break;
		case STAR_TOK: cout << STAR_TOK_LIT << endl; break;
		case EQUAL_TOK: cout << EQUAL_TOK_LIT << endl; break;
		case AT_TOK: cout << AT_TOK_LIT << endl; break;
		case POUND_TOK: cout << POUND_TOK_LIT << endl; break;
		case DOLLAR_TOK: cout << DOLLAR_TOK_LIT << endl; break;
		case PERCENT_TOK: cout << PERCENT_TOK_LIT << endl; break;
		case SEMICOLON_TOK: cout << SEMICOLON_TOK_LIT << endl; break;
		case APOSTROPHE_TOK: cout << APOSTROPHE_TOK_LIT << endl; break;
		case QUOTE_TOK: cout << QUOTE_TOK_LIT << endl; break;
		case TILDE_TOK: cout << TILDE_TOK_LIT << endl; break;
		case LESS_TOK: cout << LESS_TOK_LIT << endl; break;
		case GREATER_TOK: cout << GREATER_TOK_LIT << endl; break;
		case COMMA_TOK: cout << COMMA_TOK_LIT << endl; break;
		case PERIOD_TOK: cout << PERIOD_TOK_LIT << endl; break;
		case QUESTION_TOK: cout << QUESTION_TOK_LIT << endl; break;
		case PIPE_TOK: cout << PIPE_TOK_LIT << endl; break;
		case AMPERSAND_TOK: cout << AMPERSAND_TOK_LIT << endl; break;
		case COLON_TOK: cout << COLON_TOK_LIT << endl; break;
		case CARROT_TOK: cout << CARROT_TOK_LIT << endl; break;
		case BANG_TOK: cout << BANG_TOK_LIT << endl; break;
		case UNDERSCORE_TOK: cout << UNDERSCORE_TOK_LIT << endl; break;
		case SPACE_TOK: cout << SPACE_TOK_LIT << endl; break;
		case TAB_TOK: cout << TAB_TOK_LIT << endl; break;

		// Paired Tokens
		case OPEN_PAREN_TOK: cout << OPEN_PAREN_TOK_LIT << endl; break;
		case CLOSE_PAREN_TOK: cout << CLOSE_PAREN_TOK_LIT << endl; break;
		case OPEN_BRACKET_TOK: cout << OPEN_BRACKET_TOK_LIT << endl; break;
		case CLOSE_BRACKET_TOK: cout << CLOSE_BRACKET_TOK_LIT << endl; break;
		case OPEN_BRACE_TOK: cout << OPEN_BRACE_TOK_LIT << endl; break;
		case CLOSE_BRACE_TOK: cout << CLOSE_BRACE_TOK_LIT << endl; break;

		// Double Tokens
		case BANG_EQUAL_TOK: cout << BANG_EQUAL_TOK_LIT << endl; break;
		case EQUAL_TILDE_TOK: cout << EQUAL_TILDE_TOK_LIT << endl; break;
		case EQUAL_EQUAL_TOK: cout << EQUAL_EQUAL_TOK_LIT << endl; break;
		case LESS_EQUAL_TOK: cout << LESS_EQUAL_TOK_LIT << endl; break;
		case GREATER_EQUAL_TOK: cout << GREATER_EQUAL_TOK_LIT << endl; break;
		case LESS_GREATER_TOK: cout << LESS_GREATER_TOK_LIT << endl; break;
		case GREATER_LESS_TOK: cout << GREATER_LESS_TOK_LIT << endl; break;
		case BACKSLASH_SLASH_TOK: cout << BACKSLASH_SLASH_TOK_LIT << endl; break;
		case SLASH_BACKSLASH_TOK: cout << SLASH_BACKSLASH_TOK_LIT << endl; break;
		case GREATER_GREATER_TOK: cout << GREATER_GREATER_TOK_LIT << endl; break;
		case LESS_LESS_TOK: cout << LESS_LESS_TOK_LIT << endl; break;
		case STAR_STAR_TOK: cout << STAR_STAR_TOK_LIT << endl; break;
		case PIPE_PIPE_TOK: cout << PIPE_PIPE_TOK_LIT << endl; break;
		case AMPERSAND_AMPERSAND_TOK: cout << AMPERSAND_AMPERSAND_TOK_LIT << endl; break;
		case DASH_GREATER_TOK: cout << DASH_GREATER_TOK_LIT << endl; break;
		case LESS_DASH_TOK: cout << LESS_DASH_TOK_LIT << endl; break;
		case COLON_COLON_TOK: cout << COLON_COLON_TOK_LIT << endl; break;
		case COLON_EQUAL_TOK: cout << COLON_EQUAL_TOK_LIT << endl; break;
		case PLUS_EQUAL_TOK: cout << PLUS_EQUAL_TOK_LIT << endl; break;
		case STAR_EQUAL_TOK: cout << STAR_EQUAL_TOK_LIT << endl; break;
		case DASH_EQUAL_TOK: cout << DASH_EQUAL_TOK_LIT << endl; break;
		case SLASH_EQUAL_TOK: cout << SLASH_EQUAL_TOK_LIT << endl; break;
		case BACKSLASH_EQUAL_TOK: cout << BACKSLASH_EQUAL_TOK_LIT << endl; break;
		case SLASH_SLASH_TOK: cout << SLASH_SLASH_TOK_LIT << endl; break;

		// Triple Tokens
		case GREATER_GREATER_EQUAL_TOK: cout << GREATER_GREATER_EQUAL_TOK_LIT << endl; break;
		case LESS_LESS_EQUAL_TOK: cout << LESS_LESS_EQUAL_TOK_LIT << endl; break;
		case LESS_LESS_LESS_TOK: cout << LESS_LESS_LESS_TOK_LIT << endl; break;
		case GREATER_GREATER_GREATER_TOK: cout << GREATER_GREATER_GREATER_TOK_LIT << endl; break;

		// Quadruple Tokens
		case LESS_LESS_LESS_EQUAL_TOK: cout << LESS_LESS_LESS_EQUAL_TOK_LIT << endl; break;
		case GREATER_GREATER_GREATER_EQUAL_TOK: cout << GREATER_GREATER_GREATER_EQUAL_TOK_LIT << endl; break;

		////////////////////
		// Keyword Tokens //
		////////////////////

		// program structure
		case INCLUDE_TOK: cout << INCLUDE_TOK_KW << endl; break;
		case START_TOK: cout << START_TOK_KW << endl; break;
		case END_TOK: cout << END_TOK_KW << endl; break;
		case FUNCTION_TOK: cout << FUNCTION_TOK_KW << endl; break;
		case PROGRAM_TOK: cout << PROGRAM_TOK_KW << endl; break;
		case CALL_TOK: cout << CALL_TOK_KW << endl; break;
		case RETURN_TOK: cout << RETURN_TOK_KW << endl; break;

		// control structures
		case IF_TOK: cout << IF_TOK_KW << endl; break;
		case THEN_TOK: cout << THEN_TOK_KW << endl; break;
		case ELSE_TOK: cout << ELSE_TOK_KW << endl; break;
		case ENDIF_TOK: cout << ENDIF_TOK_KW << endl; break;

		case SELECT_TOK: cout << SELECT_TOK_KW << endl; break;
		case CASE_TOK: cout << CASE_TOK_KW << endl; break;
		case DEFAULT_TOK: cout << DEFAULT_TOK_KW << endl; break;

		// loop structures
		case FOR_TOK: cout << FOR_TOK_KW << endl; break;
		case TO_TOK: cout << TO_TOK_KW << endl; break;
		case STEP_TOK: cout << STEP_TOK_KW << endl; break;
		case NEXT_TOK: cout << NEXT_TOK_KW << endl; break;

		case DO_TOK: cout << DO_TOK_KW << endl; break;
		case UNTIL_TOK: cout << UNTIL_TOK_KW << endl; break;

		case WHILE_TOK: cout << WHILE_TOK_KW << endl; break;
		case WEND_TOK: cout << WEND_TOK_KW << endl; break;

		// math
		case MOD_TOK: cout << MOD_TOK_KW << endl; break;
		case INFINITY_TOK: cout << INFINITY_TOK_KW << endl; break;
		case NULL_TOK: cout << NULL_TOK_KW << endl; break;
		case TRUE_TOK: cout << TRUE_TOK_KW << endl; break;
		case FALSE_TOK: cout << FALSE_TOK_KW << endl; break;

		// user i/o
		case PRINT_TOK: cout << PRINT_TOK_KW << endl; break;
		case INPUT_TOK: cout << INPUT_TOK_KW << endl; break;

		// file i/o
		case OPEN_TOK: cout << OPEN_TOK_KW << endl; break;
		case CLOSE_TOK: cout << CLOSE_TOK_KW << endl; break;
		case READ_TOK: cout << READ_TOK_KW << endl; break;
		case WRITE_TOK: cout << WRITE_TOK_KW << endl; break;
		case EOF_TOK: cout << EOF_TOK_KW << endl; break;

		// variables
		case INT_TOK: cout << INT_TOK_KW << endl; break;
		case REAL_TOK: cout << REAL_TOK_KW << endl; break;
		case STRING_TOK: cout << STRING_TOK_KW << endl; break;
		case BOOL_TOK: cout << BOOL_TOK_KW << endl; break;

		// graph theory
		case CLASS_TOK: cout << CLASS_TOK_KW << endl; break;
		case GRAPH_TOK: cout << GRAPH_TOK_KW << endl; break;
		case VERTEX_TOK: cout << VERTEX_TOK_KW << endl; break;
		case EDGE_TOK: cout << EDGE_TOK_KW << endl; break;

		// set theory
		case SET_TOK: cout << SET_TOK_KW << endl; break;
		case AND_TOK: cout << AND_TOK_KW << endl; break;
		case OR_TOK: cout << OR_TOK_KW << endl; break;
		case XOR_TOK: cout << XOR_TOK_KW << endl; break;
		case NOT_TOK: cout << NOT_TOK_KW << endl; break;
		case IN_TOK: cout << IN_TOK_KW << endl; break;
		case NOTIN_TOK: cout << NOTIN_TOK_KW << endl; break;

		// special structure loops
		case FORALL_TOK: cout << FORALL_TOK_KW << endl; break;
		case FA_TRUE_TOK: cout << FA_TRUE_TOK_KW << endl; break;
		case FA_FALSE_TOK: cout << FA_FALSE_TOK_KW << endl; break;
		case THERE_EXISTS_TOK: cout << THERE_EXISTS_TOK_KW << endl; break;
		case TE_TRUE_TOK: cout << TE_TRUE_TOK_KW << endl; break;
		case TE_FALSE_TOK: cout << TE_FALSE_TOK_KW << endl; break;

		////////////////////
		// Literal Tokens //
		////////////////////
		case IDENTIFIER_TOK: cout << IDENTIFIER_TOK << endl; break;
		case KEYWORD_TOK: cout << KEYWORD_TOK << endl; break;
		case INTEGER_LITERAL_TOK: cout << INTEGER_LITERAL_TOK << endl; break;
		case REAL_LITERAL_TOK: cout << REAL_LITERAL_TOK << endl; break;
		case STRING_LITERAL_TOK: cout << STRING_LITERAL_TOK << endl; break;






		default:
			cout << "ERROR: Token not found" << endl;

	};


}