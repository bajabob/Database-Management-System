%{
 
/*
 * SQLParser.y file
 * To generate the parser run: "bison SQLParser.y"
 */
 
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int yylex(); 
int yyerror(const char *p) {fprintf(stderr,"Error:%s\n",p); return 0;}


%}

%error-verbose

%union {
	char* vlit;
	char* vsymbl;
}
 
//all tokens and key words
 
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
	: TK_LPAREN program_list TK_RPAREN { cout << " found program" ; }
	| program_list
	;
	
program_list
	:	
	| command TK_END program 
	| query TK_END program 
	;

query
	: VA_IDENTIFIER TK_ISRELATION expr { cout << "ASSIGN TO " << $1; }
	;

command
	: TK_LPAREN command_list TK_RPAREN 
	| command_list
	;

expr
	: atomic_expr
	| TK_SELECT TK_LPAREN condition TK_RPAREN atomic_expr { cout << " SELECT "  ; }
	| TK_PROJECT TK_LPAREN attribute_list TK_RPAREN atomic_expr { cout << " PROJECT "  ; }
	| TK_RENAME TK_LPAREN attribute_list TK_RPAREN atomic_expr { cout << " RENAME "  ; }
	| atomic_expr TK_UNION atomic_expr { cout << " + "  ; }
	| atomic_expr TK_DIFFERENCE atomic_expr { cout << " - "  ; }
	| atomic_expr TK_PRODUCT atomic_expr { cout << " * "  ; }
	;
	
atomic_expr
	: VA_IDENTIFIER { cout << " FROM RELATION " << $1 ; }
	| TK_LPAREN expr TK_RPAREN { cout << " ALSO " ; }
	;
	
condition 
	: condition_list conjunction { cout << " R " ; }
	;

condition_list
	:
	| condition TK_OR { cout << " || " ; }
	;
	
conjunction
	: conjunction_list comparison { cout << " A " ; }
	;

conjunction_list
	:
	| conjunction TK_AND { cout << " && " ; }
	;
	
comparison 
	: literal op literal { cout << " OP " << $1 << " " << $2 << " " << $3 ; }
	| TK_LPAREN condition TK_RPAREN { cout << " () " ; }
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
	: attribute_list_list VA_IDENTIFIER  { cout << " ATTNAME " << $2 ; }
	;
	
attribute_list_list
	:
	| attribute_list TK_COMMA  { cout << " ," ; }
	;

primary_key_list
	: primary_key_list_list VA_IDENTIFIER  { cout << " KEYNAME " << $2 ; }
	;
	
primary_key_list_list
	:
	| primary_key_list TK_COMMA  { cout << " ," ; }
	;

command_list
	: TK_OPEN VA_IDENTIFIER { cout << "OPEN RELATION " << $2 ; }
	| TK_CLOSE VA_IDENTIFIER { cout << "CLOSE RELATION " << $2 ; }
	| TK_WRITE VA_IDENTIFIER { cout << "WRITE RELATION " << $2 ; }
	| TK_EXIT { cout << "EXIT" ; }
	| TK_SHOW atomic_expr { cout << " SHOW " ; }
	| TK_CREATE TK_TABLE create_cmd
	| TK_UPDATE update_cmd
	| TK_INSERT TK_INTO insert_cmd
	| TK_DELETE TK_FROM VA_IDENTIFIER TK_WHERE condition { cout << " DELETE FROM RELATION " << $3 ; }
	;

create_cmd
	: VA_IDENTIFIER TK_LPAREN typed_attribute_list TK_RPAREN TK_PRIMARY TK_KEY
		TK_LPAREN primary_key_list TK_RPAREN { cout << " CREATE RELATION " << $1; }
	;

update_cmd
	: VA_IDENTIFIER TK_SET assignment TK_WHERE condition { cout << " UPDATE FROM RELATION " << $1 ; }
	;
	
assignment
	: assignment_list VA_IDENTIFIER TK_ASSIGN literal  { cout << " "<< $2 << " = " << $4; }
	;
	
assignment_list
	:
	| assignment TK_COMMA { cout << " , " ; }
	;
	
insert_cmd 
	: VA_IDENTIFIER TK_VALUES TK_FROM TK_LPAREN literals TK_RPAREN { cout << " INSERT RELATION " << $1; }
	| VA_IDENTIFIER TK_VALUES TK_FROM TK_RELATION expr { cout << " INSERT RELATION " << $1; }
	;

literals
	: literal_list literal  { cout << "LIT " << $2; }
	;

literal_list
	:
	| literals TK_COMMA  { cout << " , " ; }
	;
	
typed_attribute_list
	: typed_attribute_list_list VA_IDENTIFIER type  { cout << "ATTNAME " << $2; }
	;
	
typed_attribute_list_list
	:
	| typed_attribute_list TK_COMMA  { cout << " , " ; }
	;
	
type
	: TK_VARCHAR TK_LPAREN VA_INTEGER TK_RPAREN { cout << " TYPE VARCHAR SIZE=" << $3 << " "; }
	| TK_INTEGER { cout << " TYPE INTEGER "; }
	;

%%

int main()
{
	yyparse();
	return 0;
}
