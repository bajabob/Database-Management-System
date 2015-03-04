%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
 
#include "Parser.h"
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
%}

%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge

OR			"||"
AND			"&&"

ASSIGN				"="
EQUALS				"=="
NOT_EQUALS			"!="
LESS_THAN			"<"
GRATE_THAN			">"
LESS_THAN_EQUAL		"<="
GRATE_THAN_EQUAL	">="

UNION			"+"
DIFFERENCE		"-"
PRODUCT			"*"

ISRELATION 		"<-"
END 			";"
COMMA 			","
LPAREN      	"("
RPAREN      	")"

project			"project"
PROJECT			"PROJECT"
select			"select" 
SELECT			"SELECT"
rename 		  	"rename"
RENAME			"RENAME"

VARCHAR			"VARCHAR"
INTEGER			"INTEGER"

OPEN			"OPEN"
CLOSE			"CLOSE"
WRITE			"WRITE"
EXIT			"EXIT"
SHOW			"SHOW"
CREATE			"CREATE"
DELETE			"DELETE"
TABLE			"TABLE"
UPDATE			"UPDATE"
SET				"SET"
WHERE			"WHERE"
INSERT			"INSERT"
INTO			"INTO"
VALUES			"VALUES"
FROM			"FROM"
RELATION		"RELATION"
PRIMARY			"PRIMARY"
KEY				"KEY"

NUMBER      	[0-9]+
IDENTIFIER		[a-zA-z][a-zA-Z0-9_]*
LITERAL  		\"[a-zA-Z0-9_ ]+\"
WS          	[ \r\n\t]+
 
%%

{OR}			{return TK_OR;}
{AND}			{return TK_AND;}

{ASSIGN}			{return TK_ASSIGN;}
{EQUALS}			{ yylval->vsymbl = strdup(yytext); return TK_EQUALS;}
{NOT_EQUALS}		{ yylval->vsymbl = strdup(yytext); return TK_NOT_EQUALS;}
{LESS_THAN}			{ yylval->vsymbl = strdup(yytext); return TK_LESS_THAN;}
{GRATE_THAN}		{ yylval->vsymbl = strdup(yytext); return TK_GRATE_THAN;}
{LESS_THAN_EQUAL}	{ yylval->vsymbl = strdup(yytext); return TK_LESS_THAN_EQUAL;}
{GRATE_THAN_EQUAL}	{ yylval->vsymbl = strdup(yytext); return TK_GRATE_THAN_EQUAL;}

{UNION}			{return TK_UNION;}
{DIFFERENCE}	{return TK_DIFFERENCE;}
{PRODUCT}		{return TK_PRODUCT;}

{ISRELATION}	{return TK_ISRELATION;}
{END}			{ return TK_END;}
{COMMA}			{return TK_COMMA;}
{LPAREN}		{return TK_LPAREN;}
{RPAREN}		{return TK_RPAREN;}

{project}		{return TK_PROJECT;}
{PROJECT}		{return TK_PROJECT;}
{select}		{return TK_SELECT;}
{SELECT}		{return TK_SELECT;}
{rename}		{return TK_RENAME;}
{RENAME}		{return TK_RENAME;}

{VARCHAR}		{return TK_VARCHAR;}
{INTEGER}		{return TK_INTEGER;}

{OPEN}			{return TK_OPEN;}
{CLOSE}			{return TK_CLOSE;}
{WRITE}			{return TK_WRITE;}
{EXIT}			{return TK_EXIT;}
{SHOW}			{return TK_SHOW;}
{CREATE}		{return TK_CREATE;}
{DELETE}		{return TK_DELETE;}
{TABLE}			{return TK_TABLE;}
{UPDATE}		{return TK_UPDATE;}
{SET}			{return TK_SET;}
{WHERE}			{return TK_WHERE;}
{INSERT}		{return TK_INSERT;}
{INTO}			{return TK_INTO;}
{VALUES}		{return TK_VALUES;}
{FROM}			{return TK_FROM;}
{RELATION}		{return TK_RELATION;}
{PRIMARY}		{return TK_PRIMARY;}
{KEY}			{return TK_KEY;}
 
{WS}            { /* Skip blanks. */ }
{NUMBER}        { yylval->vlit = strdup(yytext); return VA_INTEGER; }
{IDENTIFIER}	{ yylval->vlit = strdup(yytext); return VA_IDENTIFIER; }
{LITERAL}		{ yylval->vlit = strdup(yytext); return VA_LITERAL; }
.               {  }
 
%%

int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}