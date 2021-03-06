///////////////////////////////////////////////////////////////////////////////
///	\file token_operators.h
///		\author		Dr. Nicholas Richardson
///		\brief		This file contains the literals for each token operator
///		\details
///			The literals are the text of the tokens.  These will be used
///			when displaying a token or comparing token strings.  Not all
///			tokens need a literal, only keywords and operators.
///			See token_keywords.h for a list of keyword literals.
///////////////////////////////////////////////////////////////////////////////
#ifndef TOKEN_OPERATORS
#define TOKEN_OPERATORS

// Single Tokens
#define PLUS_TOK_LIT							'+'
#define DASH_TOK_LIT							'-'
#define SLASH_TOK_LIT							'/'
#define BACKSLASH_TOK_LIT						'\\'
#define STAR_TOK_LIT							'*'
#define EQUAL_TOK_LIT							'='
#define AT_TOK_LIT								'@'
#define POUND_TOK_LIT							'#'
#define DOLLAR_TOK_LIT							'$'
#define PERCENT_TOK_LIT							'%'
#define SEMICOLON_TOK_LIT						';'
#define APOSTROPHE_TOK_LIT						'\''
#define QUOTE_TOK_LIT							'\"'
#define TILDE_TOK_LIT							'~'
#define LESS_TOK_LIT							'<'
#define GREATER_TOK_LIT							'>'
#define COMMA_TOK_LIT							','
#define PERIOD_TOK_LIT							'.'
#define QUESTION_TOK_LIT						'?'
#define PIPE_TOK_LIT							'|'
#define AMPERSAND_TOK_LIT						'&'
#define COLON_TOK_LIT							':'
#define CARROT_TOK_LIT							'^'
#define BANG_TOK_LIT							'!'
#define UNDERSCORE_TOK_LIT						'_'
#define SPACE_TOK_LIT							' '
#define TAB_TOK_LIT								'\t'

// Paired Tokens
#define OPEN_PAREN_TOK_LIT						'('
#define CLOSE_PAREN_TOK_LIT						')'
#define OPEN_BRACKET_TOK_LIT					'['
#define CLOSE_BRACKET_TOK_LIT					']'
#define OPEN_BRACE_TOK_LIT						'{'
#define CLOSE_BRACE_TOK_LIT						'}'
#define SLASH_STAR_TOK_LIT						"/*"
#define STAR_SLASH_TOK_LIT						"*/"


// Double Tokens
#define BANG_EQUAL_TOK_LIT						"!="
#define EQUAL_TILDE_TOK_LIT						"=~"
#define EQUAL_EQUAL_TOK_LIT						"=="
#define LESS_EQUAL_TOK_LIT						"<="
#define GREATER_EQUAL_TOK_LIT					">="
#define LESS_GREATER_TOK_LIT					"<>"
#define GREATER_LESS_TOK_LIT					"><"
#define BACKSLASH_SLASH_TOK_LIT					"\\/"
#define SLASH_BACKSLASH_TOK_LIT					"/\\"
#define GREATER_GREATER_TOK_LIT					">>"
#define LESS_LESS_TOK_LIT						"<<"
#define STAR_STAR_TOK_LIT						"**"
#define PIPE_PIPE_TOK_LIT						"||"
#define AMPERSAND_AMPERSAND_TOK_LIT				"&&"
#define DASH_GREATER_TOK_LIT					"->"
#define LESS_DASH_TOK_LIT						"<-"
#define COLON_COLON_TOK_LIT						"::"
#define COLON_EQUAL_TOK_LIT						":="
#define PLUS_EQUAL_TOK_LIT						"+="
#define STAR_EQUAL_TOK_LIT						"*="
#define DASH_EQUAL_TOK_LIT						"-="
#define SLASH_EQUAL_TOK_LIT						"/="
#define BACKSLASH_EQUAL_TOK_LIT					"\\="
#define SLASH_SLASH_TOK_LIT						"//"

// Triple Tokens
#define GREATER_GREATER_EQUAL_TOK_LIT			">>="
#define LESS_LESS_EQUAL_TOK_LIT					"<<="
#define LESS_LESS_LESS_TOK_LIT					"<<<"
#define GREATER_GREATER_GREATER_TOK_LIT			">>>"

// Quadruple Tokens
#define LESS_LESS_LESS_EQUAL_TOK_LIT			"<<<="
#define GREATER_GREATER_GREATER_EQUAL_TOK_LIT	">>>="


#endif	// TOKEN_OPERATORS