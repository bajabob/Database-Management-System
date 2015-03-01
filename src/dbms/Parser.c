/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

 
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
int yyerror(char* strout, yyscan_t scanner, const char *p) {fprintf(stderr,"Error:%s\n",p); return 0;}



#line 87 "Parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.h".  */
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
#line 22 "Parser.y" /* yacc.c:355  */

 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 

#line 126 "Parser.c" /* yacc.c:355  */

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
#line 41 "Parser.y" /* yacc.c:355  */

	char* vlit;
	char* vsymbl;
	char* strout;

#line 190 "Parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (char *strout, yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "Parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   108,   111,   113,   114,   118,   118,   122,
     123,   127,   128,   128,   128,   129,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   137,   138,   138,
     138,   142,   143,   144,   145,   149,   150,   151,   152,   153,
     154,   158,   159,   160,   165,   168,   170,   174,   177,   179,
     183,   186,   188,   192,   193,   194,   195,   196,   196,   197,
     198,   199,   200,   204,   209,   213,   216,   218,   222,   223,
     223,   227,   230,   232,   236,   239,   241,   245,   246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_OR", "TK_AND", "TK_ASSIGN",
  "TK_EQUALS", "TK_NOT_EQUALS", "TK_LESS_THAN", "TK_GRATE_THAN",
  "TK_LESS_THAN_EQUAL", "TK_GRATE_THAN_EQUAL", "TK_UNION", "TK_DIFFERENCE",
  "TK_PRODUCT", "TK_ISRELATION", "TK_END", "TK_COMMA", "TK_LPAREN",
  "TK_RPAREN", "TK_PROJECT", "TK_SELECT", "TK_RENAME", "TK_VARCHAR",
  "TK_INTEGER", "TK_OPEN", "TK_CLOSE", "TK_WRITE", "TK_EXIT", "TK_SHOW",
  "TK_CREATE", "TK_DELETE", "TK_TABLE", "TK_UPDATE", "TK_SET", "TK_WHERE",
  "TK_INSERT", "TK_INTO", "TK_VALUES", "TK_FROM", "TK_RELATION",
  "TK_PRIMARY", "TK_KEY", "VA_INTEGER", "VA_IDENTIFIER", "VA_LITERAL",
  "$accept", "program", "program_list", "query", "$@1", "command", "expr",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "atomic_expr", "$@11", "$@12", "comparison", "op", "literal",
  "attribute_list", "attribute_list_list", "rename_attribute_list",
  "rename_attribute_list_list", "primary_key_list",
  "primary_key_list_list", "command_list", "$@13", "create_cmd",
  "update_cmd", "assignment", "assignment_list", "insert_cmd", "$@14",
  "literals", "literal_list", "typed_attribute_list",
  "typed_attribute_list_list", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    13,     3,     7,    21,   -61,   -61,    22,    36,    53,
      64,   -61,   102,   -61,    87,    88,   -61,    33,    86,    89,
     -61,   -61,   -61,    -7,    62,    63,    77,   -61,    65,    95,
     -61,   -11,   -11,    89,   -61,   -61,   -61,   -61,   -61,    94,
     -61,    78,   -61,    80,   -61,   -12,   -61,   -61,   -12,   -61,
     -15,    10,    70,    81,   -61,    98,   101,   100,    60,   -61,
      71,    82,   -15,   -61,   -61,   -61,     9,    73,   -61,   -15,
     118,   -14,   106,   107,   109,   116,   117,   115,   112,   -61,
      91,    11,    49,   -15,   -15,   -61,   -61,   -61,   -61,   -61,
     -61,    42,     9,    42,   -61,   -61,   -15,   -61,   -61,    -7,
      -7,    -7,   -61,    92,   119,   -61,   -61,   -61,   129,   -61,
     -61,   -61,    72,    42,   -12,    52,    75,    96,    76,    97,
     -61,   -61,   -61,   120,    93,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   123,    -7,    -7,
      -7,    79,    99,   -61,   -61,   -61,   -61,   -61,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     4,     0,     0,     0,    56,    57,     0,     0,     0,
       0,     7,     0,     3,     0,     0,    10,     0,     0,    10,
      53,    54,    55,     0,     0,     0,     0,    60,     0,     0,
       1,     4,     4,     0,     2,     9,    28,    27,    58,     0,
      59,     0,    66,     0,    61,    12,     6,     5,    12,    75,
       0,     0,     0,     0,     8,     0,     0,     0,    11,    29,
       0,     0,     0,    43,    42,    41,    62,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,    35,    36,    37,    38,    39,
      40,     0,    64,     0,    72,    69,     0,    45,    48,     0,
       0,     0,    30,     0,     0,    78,    74,    32,    33,    34,
      31,    65,     0,     0,    12,     0,     0,     0,     0,     0,
      22,    24,    26,     0,     0,    73,    68,    71,    70,    13,
      46,    16,    44,    49,    19,    47,    51,     0,     0,     0,
       0,     0,     0,    77,    14,    17,    20,    52,    63,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,    68,   134,   -61,   -61,   -61,   -47,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -23,   -61,   -61,   -60,
     -61,   -43,   -61,   -61,   -61,   -61,   -61,   -61,     4,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    29,    15,    54,    55,   138,    56,
     139,    57,   140,    75,    76,    77,    58,    48,    78,    66,
      91,    67,   116,   117,   118,   119,   141,   142,    16,    23,
      40,    27,    51,    52,    44,   114,   112,   113,    60,    61,
     106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    59,    82,    62,    94,    19,    36,     1,   -15,    92,
     -18,    36,    83,    84,     2,     3,     4,     5,     6,     7,
       8,    33,     9,   108,   109,    10,    95,    68,    63,    64,
      65,    17,    37,    11,   104,   105,   115,    37,     2,     3,
       4,     5,     6,     7,     8,    69,     9,    20,   110,    10,
     111,    21,    83,    84,    24,    83,    84,    11,     2,     3,
       4,     5,     6,     7,     8,    22,     9,   128,   107,    10,
     127,   129,   -21,   -23,   -25,    25,   120,   121,   122,    85,
      86,    87,    88,    89,    90,    63,    64,    65,    79,   125,
      80,   126,   130,   133,   131,   134,   147,    26,   148,    46,
      47,    28,    30,    31,    32,    34,    39,    41,    35,    43,
      45,    42,    49,    50,    70,   144,   145,   146,    53,    72,
      71,    73,    74,    93,    96,    97,    81,    98,    99,   101,
     100,   102,   103,    84,   123,    18,   137,   124,   136,     0,
     132,   135,   143,   149
};

static const yytype_int16 yycheck[] =
{
      23,    48,    62,    18,    18,     1,    18,    18,    20,    69,
      22,    18,     3,     4,    25,    26,    27,    28,    29,    30,
      31,    17,    33,    83,    84,    36,    40,    17,    43,    44,
      45,    18,    44,    44,    23,    24,    96,    44,    25,    26,
      27,    28,    29,    30,    31,    35,    33,    44,    91,    36,
      93,    44,     3,     4,    32,     3,     4,    44,    25,    26,
      27,    28,    29,    30,    31,    44,    33,   114,    19,    36,
     113,    19,    12,    13,    14,    39,    99,   100,   101,     6,
       7,     8,     9,    10,    11,    43,    44,    45,    17,    17,
      19,    19,    17,    17,    19,    19,    17,    44,    19,    31,
      32,    37,     0,    16,    16,    19,    44,    44,    19,    44,
      15,    34,    18,    35,    44,   138,   139,   140,    38,    21,
      39,    20,    22,     5,    18,    18,    44,    18,    12,    14,
      13,    19,    41,     4,    42,     1,    43,    18,    18,    -1,
      44,    44,    19,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    25,    26,    27,    28,    29,    30,    31,    33,
      36,    44,    47,    48,    49,    51,    74,    18,    48,    74,
      44,    44,    44,    75,    32,    39,    44,    77,    37,    50,
       0,    16,    16,    74,    19,    19,    18,    44,    62,    44,
      76,    44,    34,    44,    80,    15,    47,    47,    63,    18,
      35,    78,    79,    38,    52,    53,    55,    57,    62,    52,
      84,    85,    18,    43,    44,    45,    65,    67,    17,    35,
      44,    39,    21,    20,    22,    59,    60,    61,    64,    17,
      19,    44,    65,     3,     4,     6,     7,     8,     9,    10,
      11,    66,    65,     5,    18,    40,    18,    18,    18,    12,
      13,    14,    19,    41,    23,    24,    86,    19,    65,    65,
      67,    67,    82,    83,    81,    65,    68,    69,    70,    71,
      62,    62,    62,    42,    18,    17,    19,    67,    52,    19,
      17,    19,    44,    17,    19,    44,    18,    43,    54,    56,
      58,    72,    73,    19,    62,    62,    62,    17,    19,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    50,    49,    51,
      51,    52,    53,    54,    52,    55,    56,    52,    57,    58,
      52,    59,    52,    60,    52,    61,    52,    62,    63,    64,
      62,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    69,    69,    70,    71,    71,
      72,    73,    73,    74,    74,    74,    74,    75,    74,    74,
      74,    74,    74,    76,    77,    78,    79,    79,    80,    81,
      80,    82,    83,    83,    84,    85,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     3,     3,     0,     4,     3,
       1,     1,     0,     0,     7,     0,     0,     7,     0,     0,
       7,     0,     4,     0,     4,     0,     4,     1,     0,     0,
       5,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     2,     1,     0,     3,     3,
       2,     3,     5,     9,     5,     4,     0,     2,     6,     0,
       6,     2,     0,     2,     3,     0,     2,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (strout, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, strout, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, char *strout, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (strout);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, char *strout, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, strout, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, char *strout, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , strout, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, strout, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, char *strout, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (strout);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (char *strout, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 107 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " found program") ; }
#line 1401 "Parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ASSIGN TO "); strcat(strout, (yyvsp[0].vlit)); strcat(strout, " > "); }
#line 1407 "Parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " SELECT "); }
#line 1413 "Parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ( ");  }
#line 1419 "Parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ) ");  }
#line 1425 "Parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " PROJECT "); }
#line 1431 "Parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ( ");  }
#line 1437 "Parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ) ");  }
#line 1443 "Parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 130 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " RENAME "); }
#line 1449 "Parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ( ");  }
#line 1455 "Parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ) ");  }
#line 1461 "Parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 131 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " + "); }
#line 1467 "Parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 132 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " - "); }
#line 1473 "Parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " * "); }
#line 1479 "Parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 137 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ( "); strcat(strout, " FROM RELATION "); strcat(strout, (yyvsp[0].vlit)); strcat(strout, " ) ");}
#line 1485 "Parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 138 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ( ");  }
#line 1491 "Parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ) ");  }
#line 1497 "Parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 142 "Parser.y" /* yacc.c:1646  */
    { strcat(strout," OP ");strcat(strout,(yyvsp[-2].vlit));strcat(strout," ");strcat(strout,(yyvsp[-1].vsymbl));strcat(strout," ");strcat(strout,(yyvsp[0].vlit)); }
#line 1503 "Parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 144 "Parser.y" /* yacc.c:1646  */
    { strcat(strout," ||"); }
#line 1509 "Parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 145 "Parser.y" /* yacc.c:1646  */
    { strcat(strout," &&"); }
#line 1515 "Parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 165 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " ATTNAME "); strcat(strout , (yyvsp[0].vlit)); }
#line 1521 "Parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 170 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " ,") ; }
#line 1527 "Parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " REATTNAME "); strcat(strout , (yyvsp[0].vlit)); }
#line 1533 "Parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 179 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " ,") ; }
#line 1539 "Parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 183 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " KEYNAME ");strcat(strout , (yyvsp[0].vlit) ); }
#line 1545 "Parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 188 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " ,") ; }
#line 1551 "Parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 192 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "OPEN RELATION ");strcat(strout , (yyvsp[0].vlit)) ; }
#line 1557 "Parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 193 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "CLOSE RELATION ");strcat(strout , (yyvsp[0].vlit)) ; }
#line 1563 "Parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "WRITE RELATION ");strcat(strout , (yyvsp[0].vlit)) ; }
#line 1569 "Parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "EXIT") ; }
#line 1575 "Parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 196 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " SHOW ") ; }
#line 1581 "Parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 200 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " DELETE FROM RELATION ");strcat(strout , (yyvsp[-2].vlit)) ; }
#line 1587 "Parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 205 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " CREATE RELATION ");strcat(strout , (yyvsp[-8].vlit)); }
#line 1593 "Parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " UPDATE FROM RELATION ");strcat(strout , (yyvsp[-4].vlit)) ; }
#line 1599 "Parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 213 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " SET ");strcat(strout, (yyvsp[-2].vlit) );strcat(strout, " = " );strcat(strout, (yyvsp[0].vlit)); }
#line 1605 "Parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 218 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " , " ); }
#line 1611 "Parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 222 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " INSERT RELATION ");strcat(strout , (yyvsp[-5].vlit)); }
#line 1617 "Parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 223 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " INSERT ");strcat(strout , (yyvsp[-3].vlit)); strcat(strout, " RELATION ( "); }
#line 1623 "Parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 223 "Parser.y" /* yacc.c:1646  */
    { strcat(strout, " ) ");  }
#line 1629 "Parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 227 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "LIT "); strcat(strout , (yyvsp[0].vlit)); }
#line 1635 "Parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 232 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " , "); }
#line 1641 "Parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 236 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , "ATTNAME "); strcat(strout, (yyvsp[-1].vlit)); }
#line 1647 "Parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 241 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " , "); }
#line 1653 "Parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 245 "Parser.y" /* yacc.c:1646  */
    { strcat(strout , " TYPE VARCHAR SIZE "); strcat(strout, (yyvsp[-1].vlit)); strcat(strout, " ");}
#line 1659 "Parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 246 "Parser.y" /* yacc.c:1646  */
    {  strcat(strout , " TYPE INTEGER "); }
#line 1665 "Parser.c" /* yacc.c:1646  */
    break;


#line 1669 "Parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (strout, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (strout, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, strout, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, strout, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (strout, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, strout, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, strout, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 249 "Parser.y" /* yacc.c:1906  */

