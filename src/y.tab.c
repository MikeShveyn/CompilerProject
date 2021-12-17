/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     CHAR = 259,
     CHAR_P = 260,
     INT = 261,
     INT_P = 262,
     REAL = 263,
     REAL_P = 264,
     STRING = 265,
     VOID = 266,
     IF = 267,
     ELSE = 268,
     DO = 269,
     WHILE = 270,
     FOR = 271,
     VAR = 272,
     RETURN = 273,
     AND = 274,
     DIVISION = 275,
     ASSIGNMENT = 276,
     EQL = 277,
     GREATER = 278,
     GREATER_EQL = 279,
     LESS = 280,
     LESS_EQL = 281,
     MINUS = 282,
     NOT = 283,
     NOT_EQL = 284,
     OR = 285,
     PLUS = 286,
     MULTIPLY = 287,
     ADDRESS = 288,
     LENGTH = 289,
     SEMICOLON = 290,
     COLON = 291,
     COMMA = 292,
     OPEN_CURLY_BRACES = 293,
     CLOSE_CURLY_BRACES = 294,
     OPEN_ANGLE_BRACES = 295,
     CLOSE_ANGLE_BRACES = 296,
     OPEN_SQUARE_BRACES = 297,
     CLOSE_SQUARE_BRACES = 298,
     COMMENT = 299,
     NONE = 300,
     BOOL_TRUE = 301,
     BOOL_FALSE = 302,
     CHAR_LITERAL = 303,
     STRING_LITERAL = 304,
     DECIMAL_LITERAL = 305,
     HEX_LITERAL = 306,
     REAL_LITERAL = 307,
     VARIABLE_ID = 308
   };
#endif
/* Tokens.  */
#define BOOL 258
#define CHAR 259
#define CHAR_P 260
#define INT 261
#define INT_P 262
#define REAL 263
#define REAL_P 264
#define STRING 265
#define VOID 266
#define IF 267
#define ELSE 268
#define DO 269
#define WHILE 270
#define FOR 271
#define VAR 272
#define RETURN 273
#define AND 274
#define DIVISION 275
#define ASSIGNMENT 276
#define EQL 277
#define GREATER 278
#define GREATER_EQL 279
#define LESS 280
#define LESS_EQL 281
#define MINUS 282
#define NOT 283
#define NOT_EQL 284
#define OR 285
#define PLUS 286
#define MULTIPLY 287
#define ADDRESS 288
#define LENGTH 289
#define SEMICOLON 290
#define COLON 291
#define COMMA 292
#define OPEN_CURLY_BRACES 293
#define CLOSE_CURLY_BRACES 294
#define OPEN_ANGLE_BRACES 295
#define CLOSE_ANGLE_BRACES 296
#define OPEN_SQUARE_BRACES 297
#define CLOSE_SQUARE_BRACES 298
#define COMMENT 299
#define NONE 300
#define BOOL_TRUE 301
#define BOOL_FALSE 302
#define CHAR_LITERAL 303
#define STRING_LITERAL 304
#define DECIMAL_LITERAL 305
#define HEX_LITERAL 306
#define REAL_LITERAL 307
#define VARIABLE_ID 308




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	int yylex();
	int yyerror(char *error);

	typedef struct node
	{	
		char *token;
		struct node *left;
		struct node *right;
	} node;

	node *mknode(char *token, node *left, node*right);
	void TreePrint(node *tree);
	void CalcShift(int t); 
	char *func_name=NULL;
	int shift = 0;
	int args_flag=0;
	int ret_void_flag=0;
	int func_flag = 0 ;
	int body_done = 0;
	int body_flag = 0;
	int ret_flag = 0;	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "parser.y"
{
	struct node *node;
    char *str;
}
/* Line 193 of yacc.c.  */
#line 235 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 248 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    20,    29,    33,    35,
      37,    40,    44,    46,    49,    51,    53,    55,    57,    60,
      62,    64,    66,    68,    71,    73,    75,    77,    79,    81,
      83,    89,    92,    94,    96,    98,   100,   104,   111,   115,
     121,   126,   129,   132,   134,   136,   138,   140,   142,   144,
     146,   150,   156,   164,   170,   178,   188,   193,   195,   200,
     204,   208,   212,   216,   218,   220,   224,   228,   232,   236,
     240,   244,   248,   252,   256,   260,   264,   268,   270,   273,
     275,   277,   281,   285,   288,   294,   297,   301,   305,   309,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
     333,   335,   337,   339,   341,   343,   345,   347,   349,   351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    57,    56,    -1,    57,    -1,
      84,    53,    40,    58,    41,    38,    62,    80,    39,    -1,
      11,    53,    40,    58,    41,    38,    62,    39,    -1,    59,
      35,    58,    -1,    59,    -1,    87,    -1,    84,    60,    -1,
      53,    37,    60,    -1,    53,    -1,    66,    71,    -1,    66,
      -1,    71,    -1,    87,    -1,    44,    -1,    66,    63,    -1,
      66,    -1,    63,    -1,    87,    -1,    44,    -1,    64,    63,
      -1,    64,    -1,    65,    -1,    76,    -1,    74,    -1,    75,
      -1,    73,    -1,    77,    40,    81,    41,    35,    -1,    67,
      66,    -1,    67,    -1,    57,    -1,    68,    -1,    69,    -1,
      17,    84,    70,    -1,    10,    53,    42,    83,    43,    35,
      -1,    77,    37,    70,    -1,    77,    21,    82,    37,    70,
      -1,    77,    21,    82,    35,    -1,    77,    35,    -1,    72,
      71,    -1,    72,    -1,    65,    -1,    76,    -1,    80,    -1,
      74,    -1,    75,    -1,    73,    -1,    38,    61,    39,    -1,
      12,    40,    82,    41,    73,    -1,    12,    40,    82,    41,
      73,    13,    73,    -1,    15,    40,    82,    41,    73,    -1,
      14,    73,    15,    40,    82,    41,    35,    -1,    16,    40,
      78,    35,    82,    35,    79,    41,    73,    -1,    77,    21,
      81,    35,    -1,    53,    -1,    53,    42,    82,    43,    -1,
      77,    21,    86,    -1,    77,    21,    82,    -1,    18,    82,
      35,    -1,    82,    37,    81,    -1,    82,    -1,    87,    -1,
      82,    31,    82,    -1,    82,    27,    82,    -1,    82,    32,
      82,    -1,    82,    20,    82,    -1,    82,    22,    82,    -1,
      82,    29,    82,    -1,    82,    25,    82,    -1,    82,    26,
      82,    -1,    82,    23,    82,    -1,    82,    24,    82,    -1,
      82,    30,    82,    -1,    82,    19,    82,    -1,    85,    -1,
      28,    82,    -1,    53,    -1,    65,    -1,    34,    53,    34,
      -1,    40,    82,    41,    -1,    33,    53,    -1,    33,    53,
      42,    83,    43,    -1,    32,    53,    -1,    83,    31,    83,
      -1,    83,    27,    83,    -1,    83,    32,    83,    -1,    83,
      20,    83,    -1,    86,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    50,
      -1,    51,    -1,    52,    -1,    49,    -1,    50,    -1,    51,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    68,    69,    74,    79,    86,    87,    88,
      91,    94,    95,    99,   100,   101,   102,   103,   107,   108,
     109,   110,   111,   115,   116,   120,   121,   122,   123,   124,
     128,   132,   133,   137,   138,   139,   142,   144,   147,   148,
     149,   150,   155,   156,   160,   161,   162,   163,   164,   165,
     168,   171,   172,   176,   177,   178,   181,   184,   185,   188,
     190,   192,   196,   197,   198,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   226,   227,   228,   229,
     230,   236,   237,   238,   239,   240,   241,   242,   243,   247,
     248,   249,   250,   251,   252,   253,   254,   258,   259,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "CHAR", "CHAR_P", "INT", "INT_P",
  "REAL", "REAL_P", "STRING", "VOID", "IF", "ELSE", "DO", "WHILE", "FOR",
  "VAR", "RETURN", "AND", "DIVISION", "ASSIGNMENT", "EQL", "GREATER",
  "GREATER_EQL", "LESS", "LESS_EQL", "MINUS", "NOT", "NOT_EQL", "OR",
  "PLUS", "MULTIPLY", "ADDRESS", "LENGTH", "SEMICOLON", "COLON", "COMMA",
  "OPEN_CURLY_BRACES", "CLOSE_CURLY_BRACES", "OPEN_ANGLE_BRACES",
  "CLOSE_ANGLE_BRACES", "OPEN_SQUARE_BRACES", "CLOSE_SQUARE_BRACES",
  "COMMENT", "NONE", "BOOL_TRUE", "BOOL_FALSE", "CHAR_LITERAL",
  "STRING_LITERAL", "DECIMAL_LITERAL", "HEX_LITERAL", "REAL_LITERAL",
  "VARIABLE_ID", "$accept", "program", "code", "function",
  "parameter_list", "argument", "atributeList", "body", "body_func",
  "nested_statments_func", "statment_func", "function_call",
  "nested_declarations", "declaration", "variable_declaration",
  "string_array", "variableL", "nested_statments", "statment",
  "code_block", "conditions", "loops", "assignment_statement", "lhs",
  "init", "update", "return", "expressions", "exp", "string_exp", "type",
  "primitiveType", "integer_literal", "nothing", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    67,    68,    69,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    74,    74,    75,    75,    75,    76,    77,    77,    78,
      79,    80,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     9,     8,     3,     1,     1,
       2,     3,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       5,     2,     1,     1,     1,     1,     3,     6,     3,     5,
       4,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     7,     5,     7,     9,     4,     1,     4,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     1,
       1,     3,     3,     2,     5,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     2,     4,     0,     0,     1,     3,     0,   109,   109,
       0,     8,     0,     9,     0,     0,   109,    12,    10,     0,
     109,     7,     0,   109,     0,     0,     0,     0,     0,     0,
     109,    22,    57,    33,     0,    20,    24,    25,    19,    32,
      34,    35,    29,    27,    28,    26,     0,    21,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,    44,
      14,    15,    43,    49,    47,    48,    45,    46,    16,     0,
       6,    23,    18,    31,   109,   109,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   106,   103,   104,
     105,    79,    80,     0,     0,    77,     0,     0,     0,     0,
      36,     0,     0,    50,    13,    42,     0,     0,    63,    64,
       0,     5,   107,   108,     0,    90,    78,    85,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,    61,    58,    56,   109,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    76,    68,    69,    73,    74,    71,
      72,    66,    70,    75,    65,    67,    51,     0,    53,    59,
       0,     0,    38,    62,    30,    89,    87,    86,    88,    37,
       0,     0,     0,     0,    40,     0,    84,    52,    54,     0,
       0,    39,     0,     0,    60,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    43,    20,    21,    28,    68,    44,    45,
      46,   102,    48,    49,    50,    51,   110,    71,    72,    52,
      53,    54,    55,   103,   109,   200,    77,   117,   118,   124,
      13,   105,   125,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
     422,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,     1,
      64,  -144,   422,    19,    36,  -144,  -144,    42,   431,   431,
      56,    65,    53,  -144,    67,    72,   431,    85,  -144,   106,
     176,  -144,    53,   176,    93,   107,   110,   113,   114,   431,
     125,  -144,   115,  -144,   119,  -144,    46,  -144,    46,   382,
    -144,  -144,  -144,  -144,  -144,  -144,     9,  -144,  -144,   142,
     120,   185,   149,   185,   112,   112,   185,  -144,   131,  -144,
      13,  -144,    13,  -144,  -144,  -144,  -144,  -144,  -144,   185,
    -144,  -144,  -144,  -144,   185,   185,   132,    62,   185,   121,
     122,   123,   185,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,   -26,  -144,   137,   220,  -144,   154,   240,   152,   160,
    -144,    38,   335,  -144,  -144,  -144,   178,   161,   319,  -144,
     148,  -144,  -144,  -144,    84,  -144,  -144,  -144,   157,   172,
     260,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   110,   185,   110,    62,   185,   185,  -144,
     112,  -144,  -144,  -144,   185,   177,    62,    62,    62,    62,
     180,    62,  -144,  -144,  -144,    95,    44,    44,    44,    44,
      44,   392,    44,  -144,   392,    95,   198,   280,  -144,  -144,
     349,   300,  -144,  -144,  -144,  -144,   -10,   -10,  -144,  -144,
     118,   110,   181,   112,  -144,   112,  -144,  -144,  -144,   201,
     182,  -144,   185,   110,   378,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   212,    32,    21,  -144,   194,  -144,   195,    23,
    -144,   -22,    28,  -144,  -144,  -144,  -143,    33,  -144,   -36,
     -31,   -17,    -5,   -27,  -144,  -144,   168,   -84,   -46,   -78,
     133,  -144,   102,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      62,   120,    57,    56,    73,    57,    56,   182,    47,    74,
     156,    47,    78,    56,   -57,   104,    79,   107,    69,    56,
     112,    56,   159,    75,    47,    35,    47,    36,    37,    38,
      84,    66,    12,   116,    73,    76,    73,   108,   111,    74,
      24,    74,   126,    56,    12,    56,   130,    31,    69,    85,
      69,    40,   201,    75,    14,    75,   119,   119,    35,   148,
      36,    37,    38,   131,    15,    76,    42,    76,    70,    81,
     183,    82,    17,   149,   140,   150,    18,    83,   185,   186,
     187,   188,    19,   190,    40,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    25,   177,    42,
      26,   180,   181,   114,   156,   115,    27,   176,    29,   178,
      30,   157,   122,   123,   131,   158,   159,   133,   134,   135,
     136,   137,    32,   111,   139,   140,   119,   160,     1,     2,
       3,     4,     5,     6,     7,    34,     9,    35,   156,    36,
      37,    38,    39,    66,    33,   157,    60,    61,    40,   158,
     159,    22,    22,    63,    64,   197,   204,    79,    80,    22,
      66,   196,    87,    40,   106,    42,   199,   205,   111,    67,
     113,   121,    65,   146,   127,   128,   129,    85,    42,     1,
       2,     3,     4,     5,     6,     7,    34,     9,    35,   155,
      36,    37,    38,    39,   144,   147,   153,   131,   132,   161,
     133,   134,   135,   136,   137,   138,   162,   139,   140,   141,
     142,   191,   184,    88,    40,   189,   198,    89,    90,    91,
      41,   152,   202,   203,    16,    92,    58,    86,    59,    42,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   131,
     132,     0,   133,   134,   135,   136,   137,   138,   179,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   131,
     132,   143,   133,   134,   135,   136,   137,   138,     0,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   131,
     132,   145,   133,   134,   135,   136,   137,   138,     0,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   131,
     132,   163,   133,   134,   135,   136,   137,   138,     0,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   131,
     132,   192,   133,   134,   135,   136,   137,   138,     0,   139,
     140,   141,   142,     0,     0,   194,     0,   195,   131,   132,
       0,   133,   134,   135,   136,   137,   138,     0,   139,   140,
     141,   142,     0,     0,   131,   132,   154,   133,   134,   135,
     136,   137,   138,     0,   139,   140,   141,   142,   131,   132,
     151,   133,   134,   135,   136,   137,   138,     0,   139,   140,
     141,   142,     0,     0,   193,     1,     2,     3,     4,     5,
       6,     7,    34,     9,     0,     0,     0,   131,   132,    39,
     133,   134,   135,   136,   137,   138,     0,   139,   140,   141,
     142,   131,   132,     0,   133,   134,   135,   136,   137,     0,
       0,   139,   140,     0,   142,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     1,     2,     3,     4,     5,     6,
       7,     8
};

static const yytype_int16 yycheck[] =
{
      36,    85,    30,    30,    40,    33,    33,   150,    30,    40,
      20,    33,    40,    40,    40,    61,    42,    63,    40,    46,
      66,    48,    32,    40,    46,    12,    48,    14,    15,    16,
      21,    18,     0,    79,    70,    40,    72,    64,    65,    70,
      19,    72,    88,    70,    12,    72,    92,    26,    70,    40,
      72,    38,   195,    70,    53,    72,    84,    85,    12,    21,
      14,    15,    16,    19,     0,    70,    53,    72,    40,    46,
     154,    48,    53,    35,    30,    37,    40,    49,   156,   157,
     158,   159,    40,   161,    38,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    41,   144,    53,
      35,   147,   148,    70,    20,    72,    53,   143,    41,   145,
      38,    27,    50,    51,    19,    31,    32,    22,    23,    24,
      25,    26,    37,   150,    29,    30,   154,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    20,    14,
      15,    16,    17,    18,    38,    27,    53,    40,    38,    31,
      32,    18,    19,    40,    40,   191,   202,    42,    39,    26,
      18,    43,    42,    38,    15,    53,   193,   203,   195,    44,
      39,    39,    39,    21,    53,    53,    53,    40,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    41,
      14,    15,    16,    17,    40,    35,    35,    19,    20,    42,
      22,    23,    24,    25,    26,    27,    34,    29,    30,    31,
      32,    13,    35,    28,    38,    35,    35,    32,    33,    34,
      44,    43,    21,    41,    12,    40,    32,    59,    33,    53,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,   146,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    41,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    41,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    41,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    41,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    -1,    -1,    35,    -1,    37,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    -1,    -1,    19,    20,    37,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    19,    20,
      35,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    19,    20,    17,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    19,    20,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    -1,    32,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     3,     4,     5,     6,     7,     8,
       9,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      55,    56,    57,    84,    53,     0,    56,    53,    40,    40,
      58,    59,    84,    87,    58,    41,    35,    53,    60,    41,
      38,    58,    37,    38,    10,    12,    14,    15,    16,    17,
      38,    44,    53,    57,    62,    63,    64,    65,    66,    67,
      68,    69,    73,    74,    75,    76,    77,    87,    60,    62,
      53,    40,    73,    40,    40,    84,    18,    44,    61,    65,
      66,    71,    72,    73,    74,    75,    76,    80,    87,    42,
      39,    63,    63,    66,    21,    40,    80,    42,    28,    32,
      33,    34,    40,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    65,    77,    82,    85,    15,    82,    77,    78,
      70,    77,    82,    39,    71,    71,    82,    81,    82,    87,
      81,    39,    50,    51,    83,    86,    82,    53,    53,    53,
      82,    19,    20,    22,    23,    24,    25,    26,    27,    29,
      30,    31,    32,    41,    40,    41,    21,    35,    21,    35,
      37,    35,    43,    35,    37,    41,    20,    27,    31,    32,
      43,    42,    34,    41,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    73,    82,    73,    86,
      82,    82,    70,    81,    35,    83,    83,    83,    83,    35,
      83,    13,    41,    35,    35,    37,    43,    73,    35,    77,
      79,    70,    21,    41,    82,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 65 "parser.y"
    { TreePrint((yyvsp[(1) - (1)].node));}
    break;

  case 3:
#line 68 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 4:
#line 69 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (1)].node), NULL); }
    break;

  case 5:
#line 75 "parser.y"
    {
 			 (yyval.node)=mknode("FUNC",mknode((yyvsp[(2) - (9)].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[(4) - (9)].node), NULL) ,mknode("RET",(yyvsp[(1) - (9)].node), NULL))) ,mknode("BODY",(yyvsp[(7) - (9)].node),(yyvsp[(8) - (9)].node)));
	   }
    break;

  case 6:
#line 80 "parser.y"
    {
			 (yyval.node)=mknode("FUNC", mknode((yyvsp[(2) - (8)].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[(4) - (8)].node), NULL) ,mknode("RET VOID",NULL, NULL))), mknode("BODY",(yyvsp[(7) - (8)].node),NULL));
		}
    break;

  case 7:
#line 86 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 8:
#line 87 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 9:
#line 88 "parser.y"
    {(yyval.node)=mknode("NONE)\n",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 10:
#line 91 "parser.y"
    {(yyval.node)=mknode("ARGS-TYPE",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 11:
#line 94 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].node),NULL);}
    break;

  case 12:
#line 95 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 13:
#line 99 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 14:
#line 100 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node), NULL);}
    break;

  case 15:
#line 101 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 16:
#line 102 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 17:
#line 103 "parser.y"
    {(yyval.node)=NULL;}
    break;

  case 18:
#line 107 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 19:
#line 108 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node), NULL);}
    break;

  case 20:
#line 109 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 21:
#line 110 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 22:
#line 111 "parser.y"
    {(yyval.node)=NULL;}
    break;

  case 23:
#line 115 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 24:
#line 116 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 25:
#line 120 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 26:
#line 121 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 27:
#line 122 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 28:
#line 123 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 29:
#line 124 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 30:
#line 128 "parser.y"
    {(yyval.node)=mknode("FUNCTION_CALL",(yyvsp[(1) - (5)].node),(yyvsp[(3) - (5)].node));}
    break;

  case 31:
#line 132 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 32:
#line 133 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 33:
#line 137 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (1)].node), NULL); }
    break;

  case 34:
#line 138 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (1)].node), NULL); }
    break;

  case 35:
#line 139 "parser.y"
    {(yyval.node) = mknode("STRING",(yyvsp[(1) - (1)].node), NULL); }
    break;

  case 36:
#line 142 "parser.y"
    { (yyval.node) = mknode("VAR",(yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 37:
#line 144 "parser.y"
    {(yyval.node)=mknode((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].node),NULL);}
    break;

  case 38:
#line 147 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 39:
#line 148 "parser.y"
    { (yyval.node) = mknode("=",(yyvsp[(1) - (5)].node), mknode("",(yyvsp[(3) - (5)].node), mknode("",(yyvsp[(5) - (5)].node),NULL))); }
    break;

  case 40:
#line 149 "parser.y"
    { (yyval.node) = mknode("=",(yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 41:
#line 150 "parser.y"
    { (yyval.node) = mknode("",(yyvsp[(1) - (2)].node), NULL); }
    break;

  case 42:
#line 155 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 43:
#line 156 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 44:
#line 160 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 45:
#line 161 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 46:
#line 162 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 47:
#line 163 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 48:
#line 164 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 49:
#line 165 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 50:
#line 168 "parser.y"
    {(yyval.node)=mknode("CODE_BLOCK",(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 51:
#line 171 "parser.y"
    {(yyval.node)=mknode("IF",(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 52:
#line 172 "parser.y"
    {(yyval.node)=mknode("IF-ELSE", mknode("",(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node)), mknode("",(yyvsp[(7) - (7)].node),NULL));}
    break;

  case 53:
#line 176 "parser.y"
    {(yyval.node)=mknode("WHILE",(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 54:
#line 177 "parser.y"
    {(yyval.node)=mknode("DO-WHILE",(yyvsp[(2) - (7)].node),(yyvsp[(5) - (7)].node));}
    break;

  case 55:
#line 178 "parser.y"
    {(yyval.node)=mknode("FOR",mknode("INIT", (yyvsp[(3) - (9)].node), mknode("COND", (yyvsp[(5) - (9)].node), mknode("UPDATE",(yyvsp[(7) - (9)].node), NULL))),(yyvsp[(9) - (9)].node));}
    break;

  case 56:
#line 181 "parser.y"
    {(yyval.node)=mknode("=",(yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));}
    break;

  case 57:
#line 184 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 58:
#line 185 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].node),NULL);}
    break;

  case 59:
#line 188 "parser.y"
    {(yyval.node)=mknode("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 60:
#line 190 "parser.y"
    {(yyval.node)=mknode("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 192 "parser.y"
    {(yyval.node)=mknode("RET-VAL",(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 62:
#line 196 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 197 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 64:
#line 198 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 65:
#line 202 "parser.y"
    {(yyval.node)=mknode("+",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 203 "parser.y"
    {(yyval.node)=mknode("-",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 204 "parser.y"
    {(yyval.node)=mknode("*",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 205 "parser.y"
    {(yyval.node)=mknode("/",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 206 "parser.y"
    {(yyval.node)=mknode("==",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 207 "parser.y"
    {(yyval.node)=mknode("!=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 208 "parser.y"
    {(yyval.node)=mknode("<",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 209 "parser.y"
    {(yyval.node)=mknode("<=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 210 "parser.y"
    {(yyval.node)=mknode(">",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 211 "parser.y"
    {(yyval.node)=mknode(">=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 212 "parser.y"
    {(yyval.node)=mknode("||",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 76:
#line 213 "parser.y"
    {(yyval.node)=mknode("&&",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 77:
#line 214 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node), NULL);}
    break;

  case 78:
#line 215 "parser.y"
    {(yyval.node)=mknode("!",(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 79:
#line 216 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 80:
#line 217 "parser.y"
    {(yyval.node)=mknode("function_call",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 81:
#line 218 "parser.y"
    {(yyval.node)=mknode((yyvsp[(2) - (3)].str),NULL,NULL);}
    break;

  case 82:
#line 219 "parser.y"
    {(yyval.node)=mknode("exp",(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 83:
#line 220 "parser.y"
    {(yyval.node)=mknode("ADDRESS-OF",mknode((yyvsp[(2) - (2)].str),NULL,NULL),NULL);}
    break;

  case 84:
#line 221 "parser.y"
    {(yyval.node)=mknode("ADDRESS-OF",mknode((yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].node),NULL),NULL);}
    break;

  case 85:
#line 222 "parser.y"
    {(yyval.node)=mknode((yyvsp[(2) - (2)].str),NULL,NULL);}
    break;

  case 86:
#line 226 "parser.y"
    {(yyval.node)=mknode("+",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 87:
#line 227 "parser.y"
    {(yyval.node)=mknode("-",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 88:
#line 228 "parser.y"
    {(yyval.node)=mknode("*",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 89:
#line 229 "parser.y"
    {(yyval.node)=mknode("/",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 90:
#line 230 "parser.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 91:
#line 236 "parser.y"
    {(yyval.node)=mknode("BOOL",NULL,NULL);}
    break;

  case 92:
#line 237 "parser.y"
    {(yyval.node)=mknode("CHAR",NULL,NULL);}
    break;

  case 93:
#line 238 "parser.y"
    {(yyval.node)=mknode("CHAR_P",NULL,NULL);}
    break;

  case 94:
#line 239 "parser.y"
    {(yyval.node)=mknode("INT",NULL,NULL);}
    break;

  case 95:
#line 240 "parser.y"
    {(yyval.node)=mknode("INT_P",NULL,NULL);}
    break;

  case 96:
#line 241 "parser.y"
    {(yyval.node)=mknode("REAL",NULL,NULL);}
    break;

  case 97:
#line 242 "parser.y"
    {(yyval.node)=mknode("REAL_P",NULL,NULL);}
    break;

  case 98:
#line 243 "parser.y"
    {(yyval.node)=mknode("STRING",NULL,NULL);}
    break;

  case 99:
#line 247 "parser.y"
    {(yyval.node)=mknode("None",NULL,NULL);}
    break;

  case 100:
#line 248 "parser.y"
    {(yyval.node)=mknode("True",NULL,NULL);}
    break;

  case 101:
#line 249 "parser.y"
    {(yyval.node)=mknode("False",NULL,NULL);}
    break;

  case 102:
#line 250 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 103:
#line 251 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 104:
#line 252 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 105:
#line 253 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 106:
#line 254 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 107:
#line 258 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 108:
#line 259 "parser.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].str),NULL,NULL);}
    break;

  case 109:
#line 262 "parser.y"
    {(yyval.node)=NULL;}
    break;


/* Line 1267 of yacc.c.  */
#line 2225 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 265 "parser.y"


int main()
{
	return yyparse();	
}


void CalcShift(int t) {
	for(int i= 0; i < t; i++){
		printf("	");
	}
}



void TreePrint(node* tree){
	if(strcmp(tree->token, "FUNC") == 0){
		func_flag = 1;
		func_name=(char*)malloc(sizeof(tree->left->token) + 1);
		strcpy(func_name,tree->left->token);
		printf("(%s\n",tree->token);
		shift++;
		CalcShift(shift);
	}else if(strcmp(tree->token, "BODY") == 0){
		CalcShift(shift);
		printf("(%s",tree->token);
		body_flag=1;
	}else if(strcmp(tree->token, "CODE") == 0 ){
		CalcShift(shift);
		printf("(%s\n",tree->token);
		shift++;	
	}else if(strcmp(tree->token, "ARGS") == 0) {
		CalcShift(shift);
		printf("(%s",tree->token);
	}
	else if(strcmp(tree->token,"RET-VAL")==0){
		ret_flag=1;
		printf("\n");
		shift++;
		CalcShift(shift);
		printf("(RET ");
		shift--;
	}
	else if(strcmp(tree->token, "RET") == 0 || strcmp(tree->token, "RET VOID") == 0 ){
		CalcShift(shift);
		printf("(%s",tree->token);
		ret_void_flag = 1;
	}
	else if(strcmp(tree->token, "") == 0 ){
	
	}
	else if(strcmp(tree->token, "NONE") == 0 ){
		printf(" NONE");
	}
	else if(strcmp(tree->token,"ARGS-TYPE") == 0){
		args_flag=1;
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(");
		shift--;
	}
	else if(strcmp(tree->token,"IF") == 0){
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(IF");
		shift--;
		
	}
	else if(strcmp(tree->token,"CODE_BLOCK") == 0){
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(CODE_BLOCK");
		shift--;
		
	}
	else if(strcmp(tree->token, "&&") == 0 || strcmp(tree->token, "/") == 0 || strcmp(tree->token, "==") == 0 ||
		strcmp(tree->token, ">") == 0 || strcmp(tree->token, ">=") == 0 || 
	strcmp(tree->token, "<") == 0 || strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "-") == 0 || 
	strcmp(tree->token, "!") == 0 || strcmp(tree->token, "!=") == 0 || strcmp(tree->token, "||") == 0 || 
	strcmp(tree->token, "+") == 0 || strcmp(tree->token, "*") == 0 || strcmp(tree->token, "&") == 0 || 
	strcmp(tree->token, "^") == 0 || strcmp(tree->token, "|") == 0 || strcmp(tree->token, ",") == 0 ){

		
		printf("\n");
		CalcShift(shift);
		printf("(%s ", tree->token);
	}
	else if(strcmp(tree->token, "=") == 0) {
		printf("\n");
		shift++;
		CalcShift(shift);
		printf("(%s", tree->token);
	}
	else{
		printf(" %s",tree->token);
		if(ret_flag==1){
			printf(")");
			ret_flag = 0;
		}
	}

	if(tree->left){
		TreePrint(tree->left);
	}
	

	if(tree->right){
		TreePrint(tree->right);
		if(strcmp(tree->token,"FUNC")==0){
			shift = 0;//code -> change to 1
		}

		if(body_flag == 1){
			shift = 1;//code -> change to 2
			printf("\n");
			CalcShift(shift);
			printf(")\n");
			body_flag = 0;
		}
		else if (strcmp(func_name,tree->token)==0){
			printf("\n");
		}
		else if(args_flag != 1 && func_flag != 1 && ret_void_flag != 1){
			printf("\n");
			CalcShift(shift);
			printf(")\n");
		}
		else{
			printf(")");
			ret_void_flag=0;
			args_flag = 0;
			func_flag = 0;
		}

	}
}




node *mknode(char *token,node *left,node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	char *newstr = (char*)malloc(sizeof(token) + 1);
	strcpy(newstr,token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return newnode;
}


int yyerror(char *error)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"%s : ** %s **  at line %d\n" ,error, yytext, yylineno);
	return 0;
}
