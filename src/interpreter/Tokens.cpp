///////////////////////////////////////////////////////////////////////////////
///	\file tokens.cpp
///		\author		Dr. Nicholas Richardson
///		\brief This file will have some functions to display tokens
///////////////////////////////////////////////////////////////////////////////

#include "tokens.h"

///////////////////////////////////////////////////////////////////////////////
///		\param[in]		token	This is the number of the token to display, use the definition for reference.
///		\details
///			A simple swith that will output the token literal.
///////////////////////////////////////////////////////////////////////////////
void Display_Token( int token )
{
	switch ( token )
	{
		case TOK_ERR_EOF:	cout << "End of file token"; break;
		case TOK_LINE_COMMENT: cout << "Line Comment token"; break;
		case TOK_BLOCK_COMMENT: cout << "Block Comment token"; break;


		// Single Tokens
		case PLUS_TOK: cout << PLUS_TOK_LIT; break; 
		case DASH_TOK: cout << DASH_TOK_LIT; break;
		case SLASH_TOK: cout << SLASH_TOK_LIT; break;
		case BACKSLASH_TOK: cout << BACKSLASH_TOK_LIT; break;
		case STAR_TOK: cout << STAR_TOK_LIT; break;
		case EQUAL_TOK: cout << EQUAL_TOK_LIT; break;
		case AT_TOK: cout << AT_TOK_LIT; break;
		case POUND_TOK: cout << POUND_TOK_LIT; break;
		case DOLLAR_TOK: cout << DOLLAR_TOK_LIT; break;
		case PERCENT_TOK: cout << PERCENT_TOK_LIT; break;
		case SEMICOLON_TOK: cout << SEMICOLON_TOK_LIT; break;
		case APOSTROPHE_TOK: cout << APOSTROPHE_TOK_LIT; break;
		case QUOTE_TOK: cout << QUOTE_TOK_LIT; break;
		case TILDE_TOK: cout << TILDE_TOK_LIT; break;
		case LESS_TOK: cout << LESS_TOK_LIT; break;
		case GREATER_TOK: cout << GREATER_TOK_LIT; break;
		case COMMA_TOK: cout << COMMA_TOK_LIT; break;
		case PERIOD_TOK: cout << PERIOD_TOK_LIT; break;
		case QUESTION_TOK: cout << QUESTION_TOK_LIT; break;
		case PIPE_TOK: cout << PIPE_TOK_LIT; break;
		case AMPERSAND_TOK: cout << AMPERSAND_TOK_LIT; break;
		case COLON_TOK: cout << COLON_TOK_LIT; break;
		case CARROT_TOK: cout << CARROT_TOK_LIT; break;
		case BANG_TOK: cout << BANG_TOK_LIT; break;
		case UNDERSCORE_TOK: cout << UNDERSCORE_TOK_LIT; break;
		case SPACE_TOK: cout << SPACE_TOK_LIT; break;
		case TAB_TOK: cout << TAB_TOK_LIT; break;

		// Paired Tokens
		case OPEN_PAREN_TOK: cout << OPEN_PAREN_TOK_LIT; break;
		case CLOSE_PAREN_TOK: cout << CLOSE_PAREN_TOK_LIT; break;
		case OPEN_BRACKET_TOK: cout << OPEN_BRACKET_TOK_LIT; break;
		case CLOSE_BRACKET_TOK: cout << CLOSE_BRACKET_TOK_LIT; break;
		case OPEN_BRACE_TOK: cout << OPEN_BRACE_TOK_LIT; break;
		case CLOSE_BRACE_TOK: cout << CLOSE_BRACE_TOK_LIT; break;

		// Double Tokens
		case BANG_EQUAL_TOK: cout << BANG_EQUAL_TOK_LIT; break;
		case EQUAL_TILDE_TOK: cout << EQUAL_TILDE_TOK_LIT; break;
		case EQUAL_EQUAL_TOK: cout << EQUAL_EQUAL_TOK_LIT; break;
		case LESS_EQUAL_TOK: cout << LESS_EQUAL_TOK_LIT; break;
		case GREATER_EQUAL_TOK: cout << GREATER_EQUAL_TOK_LIT; break;
		case LESS_GREATER_TOK: cout << LESS_GREATER_TOK_LIT; break;
		case GREATER_LESS_TOK: cout << GREATER_LESS_TOK_LIT; break;
		case BACKSLASH_SLASH_TOK: cout << BACKSLASH_SLASH_TOK_LIT; break;
		case SLASH_BACKSLASH_TOK: cout << SLASH_BACKSLASH_TOK_LIT; break;
		case GREATER_GREATER_TOK: cout << GREATER_GREATER_TOK_LIT; break;
		case LESS_LESS_TOK: cout << LESS_LESS_TOK_LIT; break;
		case STAR_STAR_TOK: cout << STAR_STAR_TOK_LIT; break;
		case PIPE_PIPE_TOK: cout << PIPE_PIPE_TOK_LIT; break;
		case AMPERSAND_AMPERSAND_TOK: cout << AMPERSAND_AMPERSAND_TOK_LIT; break;
		case DASH_GREATER_TOK: cout << DASH_GREATER_TOK_LIT; break;
		case LESS_DASH_TOK: cout << LESS_DASH_TOK_LIT; break;
		case COLON_COLON_TOK: cout << COLON_COLON_TOK_LIT; break;
		case COLON_EQUAL_TOK: cout << COLON_EQUAL_TOK_LIT; break;
		case PLUS_EQUAL_TOK: cout << PLUS_EQUAL_TOK_LIT; break;
		case STAR_EQUAL_TOK: cout << STAR_EQUAL_TOK_LIT; break;
		case DASH_EQUAL_TOK: cout << DASH_EQUAL_TOK_LIT; break;
		case SLASH_EQUAL_TOK: cout << SLASH_EQUAL_TOK_LIT; break;
		case BACKSLASH_EQUAL_TOK: cout << BACKSLASH_EQUAL_TOK_LIT; break;
		case SLASH_SLASH_TOK: cout << SLASH_SLASH_TOK_LIT; break;

		// Triple Tokens
		case GREATER_GREATER_EQUAL_TOK: cout << GREATER_GREATER_EQUAL_TOK_LIT; break;
		case LESS_LESS_EQUAL_TOK: cout << LESS_LESS_EQUAL_TOK_LIT; break;
		case LESS_LESS_LESS_TOK: cout << LESS_LESS_LESS_TOK_LIT; break;
		case GREATER_GREATER_GREATER_TOK: cout << GREATER_GREATER_GREATER_TOK_LIT; break;

		// Quadruple Tokens
		case LESS_LESS_LESS_EQUAL_TOK: cout << LESS_LESS_LESS_EQUAL_TOK_LIT; break;
		case GREATER_GREATER_GREATER_EQUAL_TOK: cout << GREATER_GREATER_GREATER_EQUAL_TOK_LIT; break;

		////////////////////
		// Keyword Tokens //
		////////////////////

		// program structure
		case INCLUDE_TOK: cout << INCLUDE_TOK_KW; break;
		case START_TOK: cout << START_TOK_KW; break;
		case END_TOK: cout << END_TOK_KW; break;
		case FUNCTION_TOK: cout << FUNCTION_TOK_KW; break;
		case PROGRAM_TOK: cout << PROGRAM_TOK_KW; break;
		case CALL_TOK: cout << CALL_TOK_KW; break;
		case RETURN_TOK: cout << RETURN_TOK_KW; break;

		// control structures
		case IF_TOK: cout << IF_TOK_KW; break;
		case THEN_TOK: cout << THEN_TOK_KW; break;
		case ELSE_TOK: cout << ELSE_TOK_KW; break;
		case ENDIF_TOK: cout << ENDIF_TOK_KW; break;

		case SELECT_TOK: cout << SELECT_TOK_KW; break;
		case CASE_TOK: cout << CASE_TOK_KW; break;
		case DEFAULT_TOK: cout << DEFAULT_TOK_KW; break;

		// loop structures
		case FOR_TOK: cout << FOR_TOK_KW; break;
		case TO_TOK: cout << TO_TOK_KW; break;
		case STEP_TOK: cout << STEP_TOK_KW; break;
		case NEXT_TOK: cout << NEXT_TOK_KW; break;

		case DO_TOK: cout << DO_TOK_KW; break;
		case UNTIL_TOK: cout << UNTIL_TOK_KW; break;

		case WHILE_TOK: cout << WHILE_TOK_KW; break;
		case WEND_TOK: cout << WEND_TOK_KW; break;

		// math
		case MOD_TOK: cout << MOD_TOK_KW; break;
		case INFINITY_TOK: cout << INFINITY_TOK_KW; break;
		case NULL_TOK: cout << NULL_TOK_KW; break;
		case TRUE_TOK: cout << TRUE_TOK_KW; break;
		case FALSE_TOK: cout << FALSE_TOK_KW; break;

		// user i/o
		case PRINT_TOK: cout << PRINT_TOK_KW; break;
		case INPUT_TOK: cout << INPUT_TOK_KW; break;

		// file i/o
		case OPEN_TOK: cout << OPEN_TOK_KW; break;
		case CLOSE_TOK: cout << CLOSE_TOK_KW; break;
		case READ_TOK: cout << READ_TOK_KW; break;
		case WRITE_TOK: cout << WRITE_TOK_KW; break;
		case EOF_TOK: cout << EOF_TOK_KW; break;

		// variables
		case INT_TOK: cout << INT_TOK_KW; break;
		case REAL_TOK: cout << REAL_TOK_KW; break;
		case STRING_TOK: cout << STRING_TOK_KW; break;
		case BOOL_TOK: cout << BOOL_TOK_KW; break;

		// graph theory
		case CLASS_TOK: cout << CLASS_TOK_KW; break;
		case GRAPH_TOK: cout << GRAPH_TOK_KW; break;
		case VERTEX_TOK: cout << VERTEX_TOK_KW; break;
		case EDGE_TOK: cout << EDGE_TOK_KW; break;

		// set theory
		case SET_TOK: cout << SET_TOK_KW; break;
		case AND_TOK: cout << AND_TOK_KW; break;
		case OR_TOK: cout << OR_TOK_KW; break;
		case XOR_TOK: cout << XOR_TOK_KW; break;
		case NOT_TOK: cout << NOT_TOK_KW; break;
		case IN_TOK: cout << IN_TOK_KW; break;
		case NOTIN_TOK: cout << NOTIN_TOK_KW; break;

		// special structure loops
		case FORALL_TOK: cout << FORALL_TOK_KW; break;
		case FA_TRUE_TOK: cout << FA_TRUE_TOK_KW; break;
		case FA_FALSE_TOK: cout << FA_FALSE_TOK_KW; break;
		case THERE_EXISTS_TOK: cout << THERE_EXISTS_TOK_KW; break;
		case TE_TRUE_TOK: cout << TE_TRUE_TOK_KW; break;
		case TE_FALSE_TOK: cout << TE_FALSE_TOK_KW; break;

		////////////////////
		// Literal Tokens //
		////////////////////
		case IDENTIFIER_TOK: cout << "Identifier token"; break;
		case KEYWORD_TOK: cout << "Keyword token"; break;
		case NUMBER_LITERAL_TOK: cout << "Number Literal token"; break;
		case STRING_LITERAL_TOK: cout << "String Literal token"; break;






		default:
			cout << "ERROR: Token not found";

	};


}




///////////////////////////////////////////////////////////////////////////////
///	\param[in]		string		This is the string to check if it is a keyword
///	\return			int			This will return the keyword token, if not a keyword, identifier token will be returned
///
/// This will check an identifier to see if it matches a keyword.  Only identifiers
/// need to call this since operators and literals will not be keywords
/// \warning	Do not call this function if the token string, id, is not an identifier.
///////////////////////////////////////////////////////////////////////////////
int Keyword( string id )
{
	int token = IDENTIFIER_TOK;

	if ( id == START_TOK_KW )
		token = START_TOK;
	else if ( id == END_TOK_KW )
		token = END_TOK;
	else if ( id == PROGRAM_TOK_KW )
		token = PROGRAM_TOK;
	else if ( id == INCLUDE_TOK_KW )
		token = INCLUDE_TOK;
	else if ( id == FUNCTION_TOK_KW )
		token = FUNCTION_TOK;
	else if ( id == CALL_TOK_KW )
		token = CALL_TOK;
	else if ( id == RETURN_TOK_KW )
		token = RETURN_TOK;
	else if ( id == INPUT_TOK_KW )
		token = FINPUT_TOK;
	else if ( id == IF_TOK_KW )
		token = IF_TOK;
	else if ( id == THEN_TOK_KW )
		token = THEN_TOK;
	else if ( id == ELSE_TOK_KW )
		token = ELSE_TOK;
	else if ( id == ENDIF_TOK_KW )
		token = ENDIF_TOK;
	else if ( id == SELECT_TOK_KW )
		token = SELECT_TOK;
	else if ( id == CASE_TOK_KW )
		token = CASE_TOK;
	else if ( id == DEFAULT_TOK_KW )
		token = DEFAULT_TOK;
	else if ( id == FOR_TOK_KW )
		token = FOR_TOK;
	else if ( id == TO_TOK_KW )
		token = TO_TOK;
	else if ( id == STEP_TOK_KW )
		token = STEP_TOK;
	else if ( id == NEXT_TOK_KW )
		token = NEXT_TOK;
	else if ( id == DO_TOK_KW )
		token = DO_TOK;
	else if ( id == UNTIL_TOK_KW )
		token = UNTIL_TOK;
	else if ( id == WHILE_TOK_KW )
		token = WHILE_TOK;
	else if ( id == WEND_TOK_KW )
		token = WEND_TOK;
	else if ( id == MOD_TOK_KW )
		token = MOD_TOK;
	else if ( id == INFINITY_TOK_KW )
		token = INFINITY_TOK;
	else if ( id == NULL_TOK_KW )
		token = NULL_TOK;
	else if ( id == TRUE_TOK_KW )
		token = TRUE_TOK;
	else if ( id == FALSE_TOK_KW )
		token = FALSE_TOK;
	else if ( id == PRINT_TOK_KW )
		token = PRINT_TOK;
	else if ( id == INPUT_TOK_KW )
		token = INPUT_TOK;
	else if ( id == OPEN_TOK_KW )
		token = OPEN_TOK;
	else if ( id == CLOSE_TOK_KW )
		token = CLOSE_TOK;
	else if ( id == READ_TOK_KW )
		token = READ_TOK;
	else if ( id == WRITE_TOK_KW )
		token = WRITE_TOK;
	else if ( id == EOF_TOK_KW )
		token = EOF_TOK;
	else if ( id == INT_TOK_KW )
		token = INT_TOK;
	else if ( id == REAL_TOK_KW )
		token = REAL_TOK;
	else if ( id == STRING_TOK_KW )
		token = STRING_TOK;
	else if ( id == BOOL_TOK_KW )
		token = BOOL_TOK;
	else if ( id == CLASS_TOK_KW )
		token = CLASS_TOK;
	else if ( id == GRAPH_TOK_KW )
		token = GRAPH_TOK;
	else if ( id == VERTEX_TOK_KW )
		token = VERTEX_TOK;
	else if ( id == EDGE_TOK_KW )
		token = EDGE_TOK;
	else if ( id == SET_TOK_KW )
		token = SET_TOK;
	else if ( id == AND_TOK_KW )
		token = AND_TOK;
	else if ( id == OR_TOK_KW )
		token = OR_TOK;
	else if ( id == XOR_TOK_KW )
		token = XOR_TOK;
	else if ( id == NOT_TOK_KW )
		token = NOT_TOK;
	else if ( id == IN_TOK_KW )
		token = IN_TOK;
	else if ( id == NOTIN_TOK_KW )
		token = NOTIN_TOK;
	// special structure loops
	else if ( id == FORALL_TOK_KW )
		token = FORALL_TOK;
	else if ( id == FA_TRUE_TOK_KW )
		token = FA_TRUE_TOK;
	else if ( id == FA_FALSE_TOK_KW )
		token = FA_FALSE_TOK;
	else if ( id == THERE_EXISTS_TOK_KW )
		token = THERE_EXISTS_TOK;
	else if ( id == TE_TRUE_TOK_KW )
		token = TE_TRUE_TOK;
	else if ( id == TE_FALSE_TOK_KW )
		token = TE_FALSE_TOK;


	return token;
}