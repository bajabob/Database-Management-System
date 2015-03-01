/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 22 "Parser.y" /* yacc.c:1909  */

 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 

#line 53 "Parser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_OR = 258,
    TK_AND = 259,
    TK_ASSIGN = 260,
    TK_EQUALS = 261,
    TK_NOT_EQUALS = 262,
    TK_LESS_THAN = 263,
    TK_GRATE_THAN = 264,
    TK_LESS_THAN_EQUAL = 265,
    TK_GRATE_THAN_EQUAL = 266,
    TK_UNION = 267,
    TK_DIFFERENCE = 268,
    TK_PRODUCT = 269,
    TK_ISRELATION = 270,
    TK_END = 271,
    TK_COMMA = 272,
    TK_LPAREN = 273,
    TK_RPAREN = 274,
    TK_PROJECT = 275,
    TK_SELECT = 276,
    TK_RENAME = 277,
    TK_VARCHAR = 278,
    TK_INTEGER = 279,
    TK_OPEN = 280,
    TK_CLOSE = 281,
    TK_WRITE = 282,
    TK_EXIT = 283,
    TK_SHOW = 284,
    TK_CREATE = 285,
    TK_DELETE = 286,
    TK_TABLE = 287,
    TK_UPDATE = 288,
    TK_SET = 289,
    TK_WHERE = 290,
    TK_INSERT = 291,
    TK_INTO = 292,
    TK_VALUES = 293,
    TK_FROM = 294,
    TK_RELATION = 295,
    TK_PRIMARY = 296,
    TK_KEY = 297,
    VA_INTEGER = 298,
    VA_IDENTIFIER = 299,
    VA_LITERAL = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 41 "Parser.y" /* yacc.c:1909  */

	char* vlit;
	char* vsymbl;
	char* strout;

#line 117 "Parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (char *strout, yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
