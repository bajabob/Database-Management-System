%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */
#include "Parser.h"
#include "Lexer.h"
 
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int yylex(); 
int yyerror(char* strout, yyscan_t scanner, const char *p) { strcpy(strout, "ERROR"); }


%}

%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 
}

%output  "Parser.c"
%defines "Parser.h"

%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { char *strout }
%parse-param { yyscan_t scanner }

%error-verbose

%union {
	char* vlit;
	char* vsymbl;
	char* strout;
}
 
%left TK_OR		// ||
%left TK_AND	// &&

%left <vsymbl> TK_ASSIGN				// =
%left <vsymbl> TK_EQUALS				// ==
%left <vsymbl> TK_NOT_EQUALS			// !=
%left <vsymbl> TK_LESS_THAN				// <
%left <vsymbl> TK_GRATE_THAN			// >
%left <vsymbl> TK_LESS_THAN_EQUAL		// <=
%left <vsymbl> TK_GRATE_THAN_EQUAL		// >=

%left TK_UNION			// +
%left TK_DIFFERENCE		// -
%left TK_PRODUCT		// *

%token TK_ISRELATION 	// ->
%token TK_END 			// ;
%token TK_COMMA 		// ,
%token TK_LPAREN		// (
%token TK_RPAREN		// )

%token TK_PROJECT		// project PROJECT
%token TK_SELECT		//	select SELECT
%token TK_RENAME 		//  rename RENAME

%token TK_VARCHAR		// VARCHAR
%token TK_INTEGER		// INTEGER

%token TK_OPEN			//  OPEN
%token TK_CLOSE			//  CLOSE
%token TK_WRITE			//  WRITE
%token TK_EXIT			//	EXIT
%token TK_SHOW			//	SHOW
%token TK_CREATE		//	CREATE
%token TK_DELETE		//	DELETE
%token TK_TABLE			//	TABLE
%token TK_UPDATE		//	UPDATE
%token TK_SET			//	SET
%token TK_WHERE			//	WHERE
%token TK_INSERT		//	INSERT
%token TK_INTO			//	INTO
%token TK_VALUES		//	VALUES
%token TK_FROM			//	FROM
%token TK_RELATION		//	RELATION
%token TK_PRIMARY		//	PRIMARY
%token TK_KEY			//	KEY


%token <vlit> VA_INTEGER		// [0-9]+
%token <vlit> VA_IDENTIFIER		// ^[a-zA-z][a-zA-Z0-9]+
%token <vlit> VA_LITERAL		// [a-zA-Z0-9]+

%type <vsymbl> op 
%type <vlit> literal

%start program

%%

program 
	: TK_LPAREN program_list TK_RPAREN { }
	| program_list
	;
	
program_list
	:	
	| command TK_END program 
	| query TK_END program 
	;

query
	: VA_IDENTIFIER { strcat(strout, " A1S2S3I4G5N TO "); strcat(strout, $1); strcat(strout, " > "); } TK_ISRELATION expr 
	;

command
	: TK_LPAREN command_list TK_RPAREN 
	| command_list
	;

expr
	: atomic_expr
	| { strcat(strout, " S1E2L3E4C5T "); } TK_SELECT TK_LPAREN comparison TK_RPAREN { strcat(strout, " ( ");  } atomic_expr { strcat(strout, " ) ");  }
	| { strcat(strout, " P1R2O3J4E5CT "); } TK_PROJECT TK_LPAREN attribute_list TK_RPAREN { strcat(strout, " ( ");  } atomic_expr { strcat(strout, " ) ");  } 
	| { strcat(strout, " R1E2N3A4M5E "); } TK_RENAME TK_LPAREN rename_attribute_list TK_RPAREN { strcat(strout, " ( ");  } atomic_expr { strcat(strout, " ) ");  } 
	| atomic_expr { strcat(strout, " + "); } TK_UNION atomic_expr
	| atomic_expr { strcat(strout, " - "); } TK_DIFFERENCE  atomic_expr
	| atomic_expr { strcat(strout, " * "); } TK_PRODUCT atomic_expr
	;
	
atomic_expr
	: VA_IDENTIFIER { strcat(strout, " ( "); strcat(strout, " FROM R1E2L3A4T5ION "); strcat(strout, $1); strcat(strout, " ) ");}
	| TK_LPAREN { strcat(strout, " ( ");  } expr { strcat(strout, " ) ");  } TK_RPAREN 
	;
	
comparison 
	: literal op literal { strcat(strout," 1O2P3 ");strcat(strout,$1);strcat(strout," ");strcat(strout,$2);strcat(strout," ");strcat(strout,$3); }
	| TK_LPAREN comparison TK_RPAREN
	| comparison TK_OR comparison { strcat(strout," ||"); }
	| comparison TK_AND comparison { strcat(strout," &&"); }
	;
	
op
	: TK_EQUALS
	| TK_NOT_EQUALS
	| TK_LESS_THAN
	| TK_GRATE_THAN
	| TK_LESS_THAN_EQUAL
	| TK_GRATE_THAN_EQUAL
	;
		
literal
	: VA_LITERAL
	| VA_IDENTIFIER
	| VA_INTEGER
	;
	
	
attribute_list
	: attribute_list_list VA_IDENTIFIER  { strcat(strout , " A1T2T3N4A5ME "); strcat(strout , $2); }
	;
	
attribute_list_list
	:
	| attribute_list TK_COMMA  { strcat(strout , " ,") ; }
	;

rename_attribute_list
	: rename_attribute_list_list VA_IDENTIFIER  { strcat(strout , " R1E2A3T4T5NAME "); strcat(strout , $2); }
	;
	
rename_attribute_list_list
	:
	| rename_attribute_list TK_COMMA  { strcat(strout , " ,") ; }
	;	
	
primary_key_list
	: primary_key_list_list VA_IDENTIFIER  { strcat(strout , " K1E2Y3N4A5ME ");strcat(strout , $2 ); }
	;
	
primary_key_list_list
	:
	| primary_key_list TK_COMMA  { strcat(strout , " ,") ; }
	;

command_list
	: TK_OPEN VA_IDENTIFIER { strcat(strout , "O1P2E3N R1E2L3A4T5ION ");strcat(strout , $2) ; }
	| TK_CLOSE VA_IDENTIFIER { strcat(strout , "C1L2O3S4E R1E2L3A4T5ION ");strcat(strout , $2) ; }
	| TK_WRITE VA_IDENTIFIER { strcat(strout , "W1R2I3T4E R1E2L3A4T5ION ");strcat(strout , $2) ; }
	| TK_EXIT { strcat(strout , "E1X2I3T") ; }
	| TK_SHOW { strcat(strout , " S1H2O3W ") ; } atomic_expr 
	| TK_CREATE TK_TABLE create_cmd
	| TK_UPDATE update_cmd
	| TK_INSERT TK_INTO insert_cmd
	| TK_DELETE TK_FROM VA_IDENTIFIER TK_WHERE comparison { strcat(strout , " D1E2L3E4T5E FROM R1E2L3A4T5ION ");strcat(strout , $3) ; }
	;

create_cmd
	: VA_IDENTIFIER TK_LPAREN typed_attribute_list TK_RPAREN TK_PRIMARY TK_KEY
		TK_LPAREN primary_key_list TK_RPAREN { strcat(strout , " C1R2E3A4T5E R1E2L3A4T5ION ");strcat(strout , $1); }
	;

update_cmd
	: VA_IDENTIFIER TK_SET assignment TK_WHERE comparison { strcat(strout , " U1P2D3A4T5E FROM R1E2L3A4T5ION ");strcat(strout , $1) ; }
	;
	
assignment
	: assignment_list VA_IDENTIFIER TK_ASSIGN literal  { strcat(strout , " 1S2E3T4 ");strcat(strout, $2 );strcat(strout, " = " );strcat(strout, $4); }
	;
	
assignment_list
	:
	| assignment TK_COMMA { strcat(strout , " , " ); }
	;
	
insert_cmd 
	: VA_IDENTIFIER TK_VALUES TK_FROM TK_LPAREN literals TK_RPAREN { strcat(strout , " I1N2S3E4R5T R1E2L3A4T5ION ");strcat(strout , $1); }
	| VA_IDENTIFIER TK_VALUES TK_FROM TK_RELATION{ strcat(strout , " I1N2S3E4R5T ");strcat(strout , $1); strcat(strout, " R1E2L3A4T5ION ( "); } expr { strcat(strout, " ) ");  }
	;

literals
	: literal_list literal  { strcat(strout , "1L2I3T4 "); strcat(strout , $2); }
	;

literal_list
	:
	| literals TK_COMMA  { strcat(strout , " , "); }
	;
	
typed_attribute_list
	: typed_attribute_list_list VA_IDENTIFIER type  { strcat(strout , "A1T2T3N4A5ME "); strcat(strout, $2); }
	;
	
typed_attribute_list_list
	:
	| typed_attribute_list TK_COMMA  { strcat(strout , " , "); }
	;
	
type
	: TK_VARCHAR TK_LPAREN VA_INTEGER TK_RPAREN { strcat(strout , " 1T2Y3P4E5 VARCHAR SIZE "); strcat(strout, $3); strcat(strout, " ");}
	| TK_INTEGER {  strcat(strout , " 1T2Y3P4E5 INTEGER "); }
	;

%%
