/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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
	//void printtree(node *tree);
	void Printtree(node *tree);
	void printTabs(int n);
	int printlevel=0;

#line 92 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

	struct node *node;
    char *str;

#line 255 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    70,    75,    79,    80,    81,
      84,    87,    88,    92,    93,    94,    95,    99,   100,   101,
     102,   106,   107,   111,   112,   113,   114,   115,   119,   123,
     124,   128,   129,   132,   135,   136,   137,   138,   143,   144,
     148,   149,   150,   151,   152,   153,   156,   159,   160,   164,
     165,   166,   170,   174,   175,   179,   180,   182,   183,   187,
     188,   189,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   220,   221,   222,   223,   224,   225,
     226,   227,   230,   231,   232,   233,   234,   235,   236,   237,
     239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "variableL", "nested_statments", "statment", "code_block", "conditions",
  "loops", "assignment_statement", "lhs", "init", "update", "return",
  "expressions", "exp", "type", "primitiveType", "nothing", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     439,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   -44,
      28,  -139,   439,   -30,    -1,  -139,  -139,     9,   448,   448,
      18,     8,    -3,  -139,    25,    29,   448,    31,  -139,    44,
     150,  -139,    -3,   150,    45,    51,    52,    53,   448,    99,
       2,  -139,    55,  -139,    46,  -139,    46,   389,  -139,  -139,
    -139,  -139,  -139,    70,  -139,  -139,    78,   144,    82,   144,
      48,    59,   144,    83,  -139,     3,  -139,     3,  -139,  -139,
    -139,  -139,  -139,  -139,   144,   144,  -139,  -139,  -139,  -139,
     144,    84,   144,    68,    71,    72,   144,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,     5,  -139,   227,  -139,    87,
     247,   107,    94,     1,  -139,   342,  -139,  -139,  -139,    89,
     326,  -139,   182,    96,  -139,  -139,  -139,    90,   101,   267,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,    51,   144,    51,   -17,   144,   144,  -139,
      59,  -139,   105,   144,  -139,  -139,   144,  -139,  -139,   197,
    -139,   411,   -16,   -16,   -16,   -16,   -16,   399,   -16,  -139,
     399,   411,   128,   287,  -139,  -139,  -139,   356,   307,  -139,
    -139,  -139,   212,  -139,    51,   108,    91,  -139,    59,  -139,
    -139,  -139,   124,   109,  -139,   144,    51,   385,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     2,     4,     0,     0,     1,     3,     0,   100,   100,
       0,     8,     0,     9,     0,     0,   100,    12,    10,     0,
     100,     7,     0,   100,     0,     0,     0,     0,     0,   100,
      53,    31,     0,    19,    22,    23,    18,    30,    32,    27,
      25,    26,    24,     0,    20,    11,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    14,    15,    39,    45,    43,
      44,    41,    42,    16,   100,     0,     6,    21,    17,    29,
     100,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    99,    96,    97,    98,    76,    77,     0,    74,     0,
       0,     0,     0,     0,    33,     0,    46,    13,    38,     0,
      60,    61,     0,     0,     5,    75,    83,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    58,     0,   100,    54,    52,     0,    78,    79,     0,
      73,    65,    66,    70,    71,    68,    69,    63,    67,    72,
      62,    64,    47,     0,    49,    55,    56,     0,     0,    34,
      28,    59,     0,    80,     0,     0,     0,    36,     0,    82,
      48,    50,     0,     0,    35,     0,     0,    57,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   134,    13,   -14,  -139,   116,  -139,   130,    19,
    -139,   103,   -10,  -139,  -139,  -138,    23,  -139,   -35,   -19,
     -13,   -12,  -139,  -139,  -139,   113,   -79,   -51,   100,  -139,
     -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    41,    20,    21,    28,    63,    42,    43,
      44,    96,    46,    47,    48,   104,    66,    67,    49,    50,
      51,    52,    53,   102,   183,    72,   109,   110,    13,    98,
      23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,   113,   169,   121,    68,    24,    97,    54,   100,    14,
      54,   105,    31,    12,   130,    34,    73,    35,    36,    37,
      69,    62,   138,    17,   112,    12,    70,    71,    15,    65,
      68,   115,    68,   165,   166,   119,   139,    79,   140,    18,
     184,    39,    74,    26,    75,    74,    69,   120,    69,    19,
      27,   111,    70,    71,    70,    71,    40,   111,    34,    25,
      35,    36,    37,    77,   171,    78,    29,    30,    32,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    33,   163,    39,    57,   167,   168,   107,    39,
     108,    80,    59,    60,    76,   172,    62,    99,   162,    40,
     164,   101,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    34,   103,    35,    36,    37,    38,    62,    22,    22,
     111,   116,   106,   114,   117,   118,    22,   134,   136,   137,
     142,   145,   146,    45,   187,   147,    45,    39,    61,   180,
     170,   174,    64,   181,   182,   185,    16,    45,    55,    45,
     186,   188,    40,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    34,    56,    35,    36,    37,    38,    64,    81,
      64,     0,    82,     0,     0,     0,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,    39,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,   121,   122,    40,   123,   124,   125,   126,   127,   128,
       0,   129,   130,   131,   132,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,   144,   129,   130,   131,   132,
       0,   121,   122,     0,   123,   124,   125,   126,   127,   128,
     173,   129,   130,   131,   132,     0,   121,   122,     0,   123,
     124,   125,   126,   127,   128,   179,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   121,   122,   133,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   121,   122,   135,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   121,   122,   148,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,   121,   122,   175,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
       0,     0,   177,     0,   178,   121,   122,     0,   123,   124,
     125,   126,   127,   128,     0,   129,   130,   131,   132,     0,
       0,   121,   122,   143,   123,   124,   125,   126,   127,   128,
       0,   129,   130,   131,   132,   121,   122,   141,   123,   124,
     125,   126,   127,   128,     0,   129,   130,   131,   132,     0,
       0,   176,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,   121,   122,    38,   123,   124,   125,
     126,   127,   128,     0,   129,   130,   131,   132,   121,   122,
       0,   123,   124,   125,   126,   127,     0,     0,   129,   130,
     121,   132,     0,   123,   124,   125,   126,   127,     0,     0,
     129,   130,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     1,     2,     3,     4,     5,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
      35,    80,   140,    19,    39,    19,    57,    30,    59,    53,
      33,    62,    26,     0,    30,    12,    39,    14,    15,    16,
      39,    18,    21,    53,    75,    12,    39,    39,     0,    39,
      65,    82,    67,    50,    51,    86,    35,    47,    37,    40,
     178,    38,    40,    35,    42,    40,    65,    42,    67,    40,
      53,    74,    65,    65,    67,    67,    53,    80,    12,    41,
      14,    15,    16,    44,   143,    46,    41,    38,    37,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    38,   134,    38,    40,   137,   138,    65,    38,
      67,    21,    40,    40,    39,   146,    18,    15,   133,    53,
     135,    53,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    53,    14,    15,    16,    17,    18,    18,    19,
     143,    53,    39,    39,    53,    53,    26,    40,    21,    35,
      41,    35,    42,    30,   185,    34,    33,    38,    38,   174,
      35,    13,    39,    35,    53,    21,    12,    44,    32,    46,
      41,   186,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    33,    14,    15,    16,    17,    65,    56,
      67,    -1,    28,    -1,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    38,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    19,    20,    53,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    43,    29,    30,    31,    32,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      43,    29,    30,    31,    32,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    43,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    41,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    41,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    41,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    41,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    -1,    35,    -1,    37,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    -1,
      -1,    19,    20,    37,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    19,    20,    35,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    -1,
      -1,    35,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    19,    20,    17,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    19,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      19,    32,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     3,     4,     5,     6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      55,    56,    57,    82,    53,     0,    56,    53,    40,    40,
      58,    59,    82,    84,    58,    41,    35,    53,    60,    41,
      38,    58,    37,    38,    12,    14,    15,    16,    17,    38,
      53,    57,    62,    63,    64,    65,    66,    67,    68,    72,
      73,    74,    75,    76,    84,    60,    62,    40,    72,    40,
      40,    82,    18,    61,    65,    66,    70,    71,    72,    73,
      74,    75,    79,    84,    40,    42,    39,    63,    63,    66,
      21,    79,    28,    32,    33,    34,    40,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    65,    81,    83,    15,
      81,    53,    77,    53,    69,    81,    39,    70,    70,    80,
      81,    84,    81,    80,    39,    81,    53,    53,    53,    81,
      42,    19,    20,    22,    23,    24,    25,    26,    27,    29,
      30,    31,    32,    41,    40,    41,    21,    35,    21,    35,
      37,    35,    41,    37,    43,    35,    42,    34,    41,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    72,    81,    72,    50,    51,    81,    81,    69,
      35,    80,    81,    43,    13,    41,    35,    35,    37,    43,
      72,    35,    53,    78,    69,    21,    41,    81,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    65,    66,
      66,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    74,
      74,    74,    75,    76,    76,    77,    77,    78,    79,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     9,     8,     3,     1,     1,
       2,     3,     1,     2,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     5,     2,
       1,     1,     1,     3,     3,     5,     4,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     7,     5,
       7,     9,     4,     1,     4,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     1,     1,     3,     3,
       4,     2,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 61 "parser.y"
              { printf("OK\n");  Printtree((yyvsp[0].node));}
#line 1621 "y.tab.c"
    break;

  case 3:
#line 64 "parser.y"
                          { (yyval.node) = mknode("",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1627 "y.tab.c"
    break;

  case 4:
#line 65 "parser.y"
                      { (yyval.node) = mknode("",(yyvsp[0].node), NULL); }
#line 1633 "y.tab.c"
    break;

  case 5:
#line 71 "parser.y"
           {
 			 (yyval.node)=mknode("FUNC", mknode((yyvsp[-7].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[-5].node), NULL) ,mknode("RET",(yyvsp[-8].node), NULL))), mknode("BODY",(yyvsp[-2].node),(yyvsp[-1].node)));
	   }
#line 1641 "y.tab.c"
    break;

  case 7:
#line 79 "parser.y"
                                             {(yyval.node)=NULL;}
#line 1647 "y.tab.c"
    break;

  case 9:
#line 81 "parser.y"
                  {(yyval.node)=NULL;}
#line 1653 "y.tab.c"
    break;

  case 13:
#line 92 "parser.y"
                                               {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1659 "y.tab.c"
    break;

  case 14:
#line 93 "parser.y"
                              {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1665 "y.tab.c"
    break;

  case 15:
#line 94 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1671 "y.tab.c"
    break;

  case 16:
#line 95 "parser.y"
                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1677 "y.tab.c"
    break;

  case 17:
#line 99 "parser.y"
                                                    {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1683 "y.tab.c"
    break;

  case 18:
#line 100 "parser.y"
                               {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1689 "y.tab.c"
    break;

  case 19:
#line 101 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1695 "y.tab.c"
    break;

  case 20:
#line 102 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1701 "y.tab.c"
    break;

  case 21:
#line 106 "parser.y"
                                                 {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1707 "y.tab.c"
    break;

  case 22:
#line 107 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1713 "y.tab.c"
    break;

  case 23:
#line 111 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1719 "y.tab.c"
    break;

  case 24:
#line 112 "parser.y"
                                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1725 "y.tab.c"
    break;

  case 25:
#line 113 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1731 "y.tab.c"
    break;

  case 26:
#line 114 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1737 "y.tab.c"
    break;

  case 27:
#line 115 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1743 "y.tab.c"
    break;

  case 28:
#line 119 "parser.y"
                                                                                       {(yyval.node)=mknode("FUNCTION_CALL",(yyvsp[-4].str),(yyvsp[-2].node));}
#line 1749 "y.tab.c"
    break;

  case 29:
#line 123 "parser.y"
                                           {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1755 "y.tab.c"
    break;

  case 30:
#line 124 "parser.y"
                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1761 "y.tab.c"
    break;

  case 31:
#line 128 "parser.y"
                      {(yyval.node)=NULL;}
#line 1767 "y.tab.c"
    break;

  case 32:
#line 129 "parser.y"
                                  {(yyval.node)=NULL;}
#line 1773 "y.tab.c"
    break;

  case 38:
#line 143 "parser.y"
                                       {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1779 "y.tab.c"
    break;

  case 39:
#line 144 "parser.y"
                      {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1785 "y.tab.c"
    break;

  case 40:
#line 148 "parser.y"
                            {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1791 "y.tab.c"
    break;

  case 41:
#line 149 "parser.y"
                                    {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1797 "y.tab.c"
    break;

  case 42:
#line 150 "parser.y"
                     {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1803 "y.tab.c"
    break;

  case 43:
#line 151 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1809 "y.tab.c"
    break;

  case 44:
#line 152 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1815 "y.tab.c"
    break;

  case 45:
#line 153 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1821 "y.tab.c"
    break;

  case 46:
#line 156 "parser.y"
                                                       {(yyval.node)=mknode("CODE_BLOCK",(yyvsp[-1].node),NULL);}
#line 1827 "y.tab.c"
    break;

  case 47:
#line 159 "parser.y"
                                                                  {(yyval.node)=mknode("IF",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1833 "y.tab.c"
    break;

  case 48:
#line 160 "parser.y"
                                                                                 {(yyval.node)=mknode("IF-ELSE", mknode("",(yyvsp[-4].node),(yyvsp[-2].node)), mknode("",(yyvsp[0].node),NULL));}
#line 1839 "y.tab.c"
    break;

  case 49:
#line 164 "parser.y"
                                                                    {(yyval.node)=mknode("WHILE",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1845 "y.tab.c"
    break;

  case 50:
#line 165 "parser.y"
                                                                                {(yyval.node)=mknode("D0-WHILE",(yyvsp[-5].node),(yyvsp[-2].node));}
#line 1851 "y.tab.c"
    break;

  case 51:
#line 166 "parser.y"
                                                                                                  {(yyval.node)=mknode("FOR",mknode("INIT", (yyvsp[-6].node), mknode("COND", (yyvsp[-4].node), mknode("UPDATE",(yyvsp[-2].node), NULL))),(yyvsp[0].node));}
#line 1857 "y.tab.c"
    break;

  case 52:
#line 170 "parser.y"
                                                 {(yyval.node)=mknode("=",(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1863 "y.tab.c"
    break;

  case 53:
#line 174 "parser.y"
                       {(yyval.node)=mknode((yyvsp[0].str),NULL,NULL);}
#line 1869 "y.tab.c"
    break;

  case 54:
#line 175 "parser.y"
                                                                  {(yyval.node)=mknode((yyvsp[-3].str),(yyvsp[-1].node),NULL);}
#line 1875 "y.tab.c"
    break;

  case 55:
#line 179 "parser.y"
                                                {(yyval.node)=mknode("=",(yyvsp[-2].str),(yyvsp[0].str));}
#line 1881 "y.tab.c"
    break;

  case 56:
#line 180 "parser.y"
                                             {(yyval.node)=mknode("=",(yyvsp[-2].str),(yyvsp[0].str));}
#line 1887 "y.tab.c"
    break;

  case 57:
#line 182 "parser.y"
                                   {(yyval.node)=mknode("=",(yyvsp[-2].str),(yyvsp[0].node));}
#line 1893 "y.tab.c"
    break;

  case 58:
#line 183 "parser.y"
                             {(yyval.node)=mknode("RET",(yyvsp[-1].node),NULL);}
#line 1899 "y.tab.c"
    break;

  case 59:
#line 187 "parser.y"
                         {(yyval.node)=mknode("",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1905 "y.tab.c"
    break;

  case 60:
#line 188 "parser.y"
       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1911 "y.tab.c"
    break;

  case 61:
#line 189 "parser.y"
           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1917 "y.tab.c"
    break;

  case 62:
#line 193 "parser.y"
                       {(yyval.node)=mknode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1923 "y.tab.c"
    break;

  case 63:
#line 194 "parser.y"
                        {(yyval.node)=mknode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1929 "y.tab.c"
    break;

  case 64:
#line 195 "parser.y"
                           {(yyval.node)=mknode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1935 "y.tab.c"
    break;

  case 65:
#line 196 "parser.y"
                           {(yyval.node)=mknode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1941 "y.tab.c"
    break;

  case 66:
#line 197 "parser.y"
                      {(yyval.node)=mknode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1947 "y.tab.c"
    break;

  case 67:
#line 198 "parser.y"
                          {(yyval.node)=mknode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1953 "y.tab.c"
    break;

  case 68:
#line 199 "parser.y"
                       {(yyval.node)=mknode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1959 "y.tab.c"
    break;

  case 69:
#line 200 "parser.y"
                           {(yyval.node)=mknode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1965 "y.tab.c"
    break;

  case 70:
#line 201 "parser.y"
                          {(yyval.node)=mknode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1971 "y.tab.c"
    break;

  case 71:
#line 202 "parser.y"
                              {(yyval.node)=mknode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1977 "y.tab.c"
    break;

  case 72:
#line 203 "parser.y"
                 {(yyval.node)=mknode("||",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1983 "y.tab.c"
    break;

  case 73:
#line 204 "parser.y"
                      {(yyval.node)=mknode("&&",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1989 "y.tab.c"
    break;

  case 74:
#line 205 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1995 "y.tab.c"
    break;

  case 75:
#line 206 "parser.y"
                  {(yyval.node)=mknode("!",(yyvsp[-1].str),NULL);}
#line 2001 "y.tab.c"
    break;

  case 76:
#line 207 "parser.y"
                      {(yyval.node)=mknode((yyvsp[0].str),NULL,NULL);}
#line 2007 "y.tab.c"
    break;

  case 85:
#line 221 "parser.y"
               {(yyval.node)=mknode("CHAR",NULL,NULL);}
#line 2013 "y.tab.c"
    break;

  case 86:
#line 222 "parser.y"
                 {(yyval.node)=mknode("CHAR_P",NULL,NULL);}
#line 2019 "y.tab.c"
    break;

  case 87:
#line 223 "parser.y"
              {(yyval.node)=mknode("INT",NULL,NULL);}
#line 2025 "y.tab.c"
    break;

  case 88:
#line 224 "parser.y"
                {(yyval.node)=mknode("INT_P",NULL,NULL);}
#line 2031 "y.tab.c"
    break;

  case 89:
#line 225 "parser.y"
               {(yyval.node)=mknode("REAL",NULL,NULL);}
#line 2037 "y.tab.c"
    break;

  case 90:
#line 226 "parser.y"
                 {(yyval.node)=mknode("REAL_P",NULL,NULL);}
#line 2043 "y.tab.c"
    break;

  case 91:
#line 227 "parser.y"
                 {(yyval.node)=mknode("STRING",NULL,NULL);}
#line 2049 "y.tab.c"
    break;

  case 92:
#line 230 "parser.y"
              {(yyval.node)=mknode("NONE",NULL,NULL);}
#line 2055 "y.tab.c"
    break;

  case 93:
#line 231 "parser.y"
                    {(yyval.node)=mknode("TRUE",NULL,NULL);}
#line 2061 "y.tab.c"
    break;

  case 94:
#line 232 "parser.y"
                      {(yyval.node)=mknode("FALSE",NULL,NULL);}
#line 2067 "y.tab.c"
    break;

  case 95:
#line 233 "parser.y"
                        {(yyval.node)=mknode("CHAR_LITERAL",NULL,NULL);}
#line 2073 "y.tab.c"
    break;

  case 96:
#line 234 "parser.y"
                            {(yyval.node)=mknode("DECIMAL_LITERAL",NULL,NULL);}
#line 2079 "y.tab.c"
    break;

  case 97:
#line 235 "parser.y"
                       {(yyval.node)=mknode("HEX_LITERAL",NULL,NULL);}
#line 2085 "y.tab.c"
    break;

  case 98:
#line 236 "parser.y"
                         {(yyval.node)=mknode("REAL_LITERAL",NULL,NULL);}
#line 2091 "y.tab.c"
    break;

  case 99:
#line 237 "parser.y"
                          {(yyval.node)=mknode("STRING_LITERAL",NULL,NULL);}
#line 2097 "y.tab.c"
    break;

  case 100:
#line 239 "parser.y"
          {(yyval.node)=NULL;}
#line 2103 "y.tab.c"
    break;


#line 2107 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 242 "parser.y"


int main()
{
	return yyparse();	
}

/*ADD PROGRAMM C FRO PRINT TREE*/
/* void printtree(node *tree)
{
	printf("%s\n", tree->token);
		if(tree->left)
			printtree(tree->left);
		if(tree->right)
			printtree(tree->right);
} 
 */

 void printTabs(int n)
{
	int i;
	for(i=0;i<n/3;i++)
		printf(" ");
}
void Printtree(node* tree)
{
	int flag = 4;
	printTabs(printlevel); 
	if(strcmp(tree->token, "VAR") == 0)
	{
		
		printf("(DECLARE ");
		flag=2;
		
		
	}
	else if(strcmp(tree->token, "IF") == 0)
	{
		printf("(IF\n");
		flag = 1;
		
	}
	else if(strcmp(tree->token, "WHILE") == 0)
	{
		printf("(WHILE\n");
		flag = 1;
		
		
	}
	else if(strcmp(tree->token, "DO-WHILE") == 0)
	{
		printf("(DO-WHILE\n");
		flag = 1;
		
		
	}
	else if(strcmp(tree->token, "FOR") == 0)
	{
		printf("(FOR\n");
		flag = 1;
		
		
	}
	else if(strcmp(tree->token, "FUNC") == 0 || strcmp(tree->token, "CODE") == 0 || strcmp(tree->token, "FUNCTION_CALL") == 0)
	{
		printf("(%s \n",tree->token);
		flag= 2;
		
	}
	else if(strcmp(tree->token, "ARGS") == 0)
	{
		printf("(ARGS ");
		if(tree->left)
		{
			flag = 2;
			printf("\n");
			
		}
		else{
			printf(" NONE)\n"); 
		}
	

	}
	else if(strcmp(tree->token, "IF-ELSE") == 0)
	{
		printf("(IF-ELSE\n");
		printlevel--;
		flag = 1;
	}
	else if(strcmp(tree->token, "RET") == 0)
	{
		printf("(RET ");
		if(tree->left)
		{
			flag = 2;
			
		}
		else{
			printf(" NONE)\n"); 
		}
	}

	else if(strcmp(tree->token, "BODY") == 0)
	{
		printf("(BODY ");
		if(tree->left || tree->right)
		{
			flag = 2;
			printf("\n");
		}
		else{
			printf(" NONE)\n"); 
		}
	}

	else if(strcmp(tree->token, "CODE_BLOCK") == 0)
	{
		printf("(CODE_BLOCK\n");
		flag = 2;
				
	}

	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0)
			printf("(");
	else if(strcmp(tree->token, "\n") == 0)
			printf("\n");
	else if(strcmp(tree->token, ")") == 0)
			printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
			printf(",");
	else if(strcmp(tree->token, ";") == 0)
			printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||
strcmp(tree->token, "/") == 0 || 
strcmp(tree->token, "=") == 0 || 
strcmp(tree->token, "==") == 0 || 
strcmp(tree->token, ">") == 0 || 
strcmp(tree->token, ">=") == 0 || 
strcmp(tree->token, "<") == 0 || 
strcmp(tree->token, "<=") == 0 || 
strcmp(tree->token, "-") == 0 || 
strcmp(tree->token, "!") == 0 || 
strcmp(tree->token, "!=") == 0 || 
strcmp(tree->token, "||") == 0 || 
strcmp(tree->token, "+") == 0 || 
strcmp(tree->token, "*") == 0 || 
strcmp(tree->token, "&") == 0 || 
strcmp(tree->token, "^") == 0 || 
strcmp(tree->token, "|") == 0 || 
strcmp(tree->token, ",") == 0 )
	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;		
	}
	else
	{
		if(tree && (!tree->left && !tree->right)
		||strcmp(tree->token, "Main") == 0)
		{
			printf("%s", tree->token);
			
		}
		else
		{
			printlevel++;
			printf("%s", tree->token);
			printlevel--;
		
		}
	}
	if (tree->left) 
	{
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	
	if (tree->right)
	{
		printlevel++;
		Printtree(tree->right);
		printlevel--;
		
	}
	if(flag == 2)
		printf(")\n");
	
	if(flag == 1)
		printf(")");
	if(flag == 0)
		printf("\n)");
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
