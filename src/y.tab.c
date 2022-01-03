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
	#include<ctype.h>
	#include "lex.yy.c"
	int yylex();
	void yyerror(const char* msg);
	int yywrap();


	typedef struct node
	{	
		char *token;
		struct node *left;
		struct node *right;
	
	} node;

	typedef struct node2
	{	
		node * node;
		char * type;
	} node2;

	struct node *head;
	node *mknode(char *token, node *left, node*right);
	node2 *mknode2(char *token, node *left, node*right,char *);
	void TreePrint(node *tree);
	void CalcShift(int t); 
	char *func_name=NULL;
	int shift = 0;
	int ret_flag = 0;	
	int ret_val_flag=0;
	int flag = 0;
	int mulltipleMain = 0;
	/*  Semantic  */
	void freeStack();
	void add(char);
    void insert_type();
    int search(char *);
	 void check_declaration(char *);
	 int searchForDeclaration(char *type);
	void check_return_type(const char *);
	int check_types(char *, char *);
	char *get_type(const char *, int is_func);
	void set_current_scope(const char *, int is_func);
	void add_to_param_count();
	void set_param_count(const char * name);
	void check_param_list();
	void add_to_current_param_list();
	void endScope();
	char* check_alg_expr(char * type1, char * type2, char * op);
	void check_declaration_type(char *type1, char *type2);
	int sem_errors=0;
	int param_count_current = 0;
	int current_param_list = 0;
	int label=0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "real", "char", "void", "if", "else", "for", "while", "main", "return"};

	struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    };

	struct scopeStack {
		char * scope_name;
		int last_index;
		char * param_types;
		int param_count;
		int is_function;
		int parent;
		struct dataType symbol_table[40];
	} scopeStack[40];
	 
	int count_scope_stack_elements = -1;
	int current_scope_stack_top = -1;
    int count_symbol_table_line=0;
	int count_code_lines = 0;
    int q;
    int count_line = 0;
	char type[10];


#line 159 "y.tab.c"

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
#line 91 "parser.y"

	struct node *node;
	struct node2 *node2;
	char *str; 

#line 323 "y.tab.c"

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
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

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
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   130,   131,   136,   136,   136,   141,   141,
     141,   148,   149,   150,   153,   156,   157,   161,   162,   163,
     164,   165,   166,   170,   171,   172,   173,   174,   175,   179,
     180,   184,   185,   186,   187,   188,   191,   195,   195,   196,
     200,   201,   201,   207,   208,   212,   213,   214,   218,   218,
     226,   227,   233,   242,   243,   247,   248,   249,   250,   251,
     252,   255,   258,   258,   259,   259,   259,   264,   264,   265,
     265,   266,   266,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   280,   283,   284,   284,   287,   289,   291,   294,
     295,   301,   306,   311,   316,   321,   330,   331,   332,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     360,   361,   362,   363,   364,   369,   370,   371,   372,   373,
     374,   375,   376,   380,   385,   390,   395,   400,   405,   410,
     415,   423,   424,   427
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
  "VARIABLE_ID", "$accept", "program", "code", "function", "$@1", "$@2",
  "$@3", "$@4", "parameter_list", "argument", "atributeList", "body",
  "body_func", "nested_statments_func", "statment_func", "function_call",
  "function_call_params", "$@5", "function_lhs", "$@6",
  "nested_declarations", "declaration", "variable_declaration", "$@7",
  "temp", "string_array", "nested_statments", "statment", "code_block",
  "conditions", "$@8", "$@9", "$@10", "loops", "$@11", "$@12", "$@13",
  "args_cond", "assignment_statement", "lhs", "$@14", "init", "update",
  "return", "ret_exp", "expressions", "exp", "string_exp", "type",
  "primitiveType", "integer_literal", "nothing", YY_NULLPTR
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

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     421,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -28,
      29,   -97,   421,    -8,   -97,   -97,   -97,   -97,    13,    45,
     430,   430,    27,    68,    55,   -97,   105,   119,   430,   121,
     -97,   124,     4,   -97,    55,     4,   129,   -97,   -97,   -97,
     -97,   430,   106,   -97,   -16,   -97,   149,     4,   118,   -97,
     151,     4,   357,   -97,   -97,   -97,   -97,   -97,   -97,   172,
     -97,   -97,   177,   159,   165,   167,   164,   168,   169,   170,
     183,   -97,   182,   -97,   106,   106,    49,   -97,   -97,   -97,
     -97,   -97,   -97,   180,   185,   -97,   -97,   -97,   175,   -97,
     -97,   166,   209,   136,   192,   192,   240,   192,   207,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   228,   -97,   -97,
     -97,   -97,   166,   166,   -97,   235,   236,   166,   225,   226,
     230,   166,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     132,   -97,   245,   308,   -97,   -97,   -97,   -97,   -97,   153,
     -97,   166,   243,   353,   247,   241,   250,   263,   286,   271,
     -18,   -97,   227,   242,   272,   273,   -97,   -97,   268,   278,
     270,   -97,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   -97,   136,   136,   136,   136,
     281,    51,   164,   166,   166,   166,   166,   166,   166,   166,
     166,   164,   192,   164,   136,   192,   166,   -97,   -97,   -97,
     -97,   175,   -97,   136,   -97,   -97,   -97,   393,    20,    20,
      20,    20,    20,   381,    20,   -97,   381,   393,   -97,   -97,
      15,    15,   -97,   -97,   -97,    84,    11,    19,   148,   162,
     284,   285,   125,   300,   276,   -97,   -97,   283,   324,   -97,
     255,   -97,   287,   207,   -97,   -97,   164,   -97,   302,   280,
     -97,   166,   164,   367,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,     2,     4,     0,     8,     1,     3,     5,     0,     0,
     143,   143,     0,    12,     0,    13,     0,     0,   143,    16,
      14,     0,   143,    11,     0,   143,     0,    62,    69,    67,
      71,     0,   143,    28,    40,    45,     0,    26,    30,    31,
       0,    25,    44,    46,    47,    35,    33,    34,    32,     0,
      27,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    55,    19,    20,    54,    60,    58,    59,
      56,    57,    21,     0,     0,     9,    24,    29,     0,    23,
      43,   143,     0,     0,     0,     0,     0,     0,     0,    48,
      90,    91,    92,    93,    94,    95,    89,     0,    61,    17,
      18,    53,     0,     0,    10,    37,     0,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   140,   137,   138,   139,
     113,   114,     0,    97,   111,    98,     6,   141,   142,     0,
     124,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,    88,     0,     0,     0,     0,   112,   119,   117,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     7,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    49,    42,
      85,     0,    36,     0,   115,   116,   110,   102,   103,   107,
     108,   105,   106,   100,   104,   109,    99,   101,    96,   123,
     121,   120,   122,    52,    63,   110,   103,   107,   108,   105,
     106,   104,   109,     0,     0,    68,    86,     0,     0,    38,
       0,    65,     0,     0,    51,   118,     0,    70,     0,     0,
      66,     0,     0,    87,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   312,    28,   -97,   -97,   -97,   -97,    41,   -97,
     295,    -4,     8,   288,   -97,    94,   140,   -97,   -97,   -97,
      14,   -97,   -97,   -97,   -97,   -97,   266,   -97,   -42,    63,
     -97,   -97,   -97,    89,   -97,   -97,   -97,   -91,   101,   -96,
     -97,   -97,   -97,   290,   -97,   184,   -90,   -24,   107,   -97,
     163,    16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    45,    19,   175,    18,   114,    22,    23,
      30,    72,    46,    47,    48,   131,   116,   154,    50,    83,
      51,    52,    53,   150,   198,    54,    75,    76,    55,    56,
      64,    65,   246,    57,    67,    66,    68,   142,    58,    59,
      84,   149,   249,    81,   107,   132,   143,   139,    13,   134,
     140,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,   133,   148,   196,   144,   -83,   146,     1,     2,     3,
       4,     5,     6,     7,    36,     9,    37,   197,    38,    39,
      40,    41,   152,   153,    96,    14,   -41,   156,    12,    15,
     162,   160,    77,    77,    77,   176,    25,    25,   162,   162,
      12,   171,    42,    62,    25,    17,   -73,   179,    43,   171,
     171,   181,   -73,    20,   -77,    86,    74,    44,    82,    89,
     -77,    37,    26,    38,    39,    40,    90,    70,    27,    33,
     109,   110,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   133,    21,   -81,    42,    74,    74,
      82,    82,   -81,   225,   226,   227,   228,   229,   230,   231,
     232,   234,    44,    28,   237,    78,   238,   135,    29,     1,
       2,     3,     4,     5,     6,     7,    36,     9,    37,   -80,
      38,    39,    40,    41,    70,   -80,    49,    24,    24,    49,
      37,    79,    38,    39,    40,    24,    73,    78,    78,    78,
     224,    49,    49,    80,    42,    49,    31,   248,    69,   233,
      71,   235,   219,   220,   221,   222,    42,    32,    34,    44,
     -79,   253,    35,    79,    79,    79,   -79,   162,    73,    73,
      73,    44,   -40,   176,   -41,    80,    80,    80,   171,   240,
     177,   162,    63,   -78,   178,   179,   137,   138,    85,   -78,
     135,    88,   171,    91,   117,    70,   180,   -75,   118,   119,
     120,    93,    42,   -75,   250,    94,   121,    95,    97,    98,
     254,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     141,   108,   112,    99,   118,   119,   120,   113,   115,   100,
     101,   102,   121,   103,   104,   105,   106,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   162,   163,   136,   164,
     165,   166,   167,   168,   169,   145,   170,   171,   172,   173,
     147,   162,   163,   151,   164,   165,   166,   167,   168,   169,
     199,   170,   171,   172,   173,   176,   -39,   155,   157,   158,
     161,   192,   177,   159,   182,   200,   178,   179,   191,   162,
     163,   193,   164,   165,   166,   167,   168,   169,   245,   170,
     171,   172,   173,   162,   162,   -84,   195,   194,   202,   201,
     203,   205,   204,   241,   171,   171,   223,   242,   243,   -76,
     -74,   252,   247,   251,    16,   -76,   -74,   162,   163,    61,
     164,   165,   166,   167,   168,   169,    87,   170,   171,   172,
     173,   239,   111,   162,   163,   174,   164,   165,   166,   167,
     168,   169,    92,   170,   171,   172,   173,   236,   218,   244,
       1,     2,     3,     4,     5,     6,     7,    36,     9,     0,
       0,     0,   183,   163,    41,   184,   185,   186,   187,   188,
     169,     0,   189,   190,   172,   173,   162,   163,     0,   164,
     165,   166,   167,   168,   169,     0,   170,   171,   172,   173,
     162,   163,     0,   164,   165,   166,   167,   168,     0,     0,
     170,   171,   162,   173,     0,   164,   165,   166,   167,   168,
       0,     0,   170,   171,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     1,     2,     3,     4,     5,     6,     7,
       8
};

static const yytype_int16 yycheck[] =
{
      42,    91,    98,    21,    95,    21,    97,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    35,    14,    15,
      16,    17,   112,   113,    66,    53,    42,   117,     0,     0,
      19,   121,    74,    75,    76,    20,    20,    21,    19,    19,
      12,    30,    38,    35,    28,    53,    35,    32,    44,    30,
      30,   141,    41,    40,    35,    47,    42,    53,    42,    51,
      41,    12,    21,    14,    15,    16,    52,    18,    41,    28,
      74,    75,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    40,    35,    38,    74,    75,
      74,    75,    41,   183,   184,   185,   186,   187,   188,   189,
     190,   192,    53,    35,   195,    42,   196,    91,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    35,
      14,    15,    16,    17,    18,    41,    32,    20,    21,    35,
      12,    42,    14,    15,    16,    28,    42,    74,    75,    76,
     182,    47,    48,    42,    38,    51,    41,   243,    41,   191,
      44,   193,   176,   177,   178,   179,    38,    38,    37,    53,
      35,   251,    38,    74,    75,    76,    41,    19,    74,    75,
      76,    53,    40,    20,    42,    74,    75,    76,    30,   203,
      27,    19,    53,    35,    31,    32,    50,    51,    39,    41,
     174,    40,    30,    21,    28,    18,    43,    35,    32,    33,
      34,    42,    38,    41,   246,    40,    40,    40,    40,    40,
     252,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      28,    39,    42,    53,    32,    33,    34,    42,    53,    46,
      47,    48,    40,    50,    51,    52,    53,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    19,    20,    39,    22,
      23,    24,    25,    26,    27,    15,    29,    30,    31,    32,
      53,    19,    20,    35,    22,    23,    24,    25,    26,    27,
      43,    29,    30,    31,    32,    20,    41,    41,    53,    53,
      35,    40,    27,    53,    41,    43,    31,    32,    41,    19,
      20,    41,    22,    23,    24,    25,    26,    27,    43,    29,
      30,    31,    32,    19,    19,    42,    35,    21,    35,    37,
      42,    41,    34,    13,    30,    30,    35,    41,    35,    35,
      35,    41,    35,    21,    12,    41,    41,    19,    20,    34,
      22,    23,    24,    25,    26,    27,    48,    29,    30,    31,
      32,   201,    76,    19,    20,    37,    22,    23,    24,    25,
      26,    27,    62,    29,    30,    31,    32,   194,   174,    35,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    19,    20,    17,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      19,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    19,    32,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     3,     4,     5,     6,     7,     8,     9,
      10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      55,    56,    57,   102,    53,     0,    56,    53,    60,    58,
      40,    40,    62,    63,   102,   105,    62,    41,    35,    53,
      64,    41,    38,    62,    37,    38,    10,    12,    14,    15,
      16,    17,    38,    44,    53,    57,    66,    67,    68,    69,
      72,    74,    75,    76,    79,    82,    83,    87,    92,    93,
     105,    64,    66,    53,    84,    85,    89,    88,    90,   102,
      18,    44,    65,    69,    74,    80,    81,    82,    83,    87,
      92,    97,   105,    73,    94,    39,    66,    67,    40,    66,
      74,    21,    97,    42,    40,    40,    82,    40,    40,    53,
      46,    47,    48,    50,    51,    52,    53,    98,    39,    65,
      65,    80,    42,    42,    61,    53,    70,    28,    32,    33,
      34,    40,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    69,    99,   100,   103,   105,    39,    50,    51,   101,
     104,    28,    91,   100,    91,    15,    91,    53,    93,    95,
      77,    35,   100,   100,    71,    41,   100,    53,    53,    53,
     100,    35,    19,    20,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    37,    59,    20,    27,    31,    32,
      43,   100,    41,    19,    22,    23,    24,    25,    26,    29,
      30,    41,    40,    41,    21,    35,    21,    35,    78,    43,
      43,    37,    35,    42,    34,    41,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,    99,   101,
     101,   101,   101,    35,    82,   100,   100,   100,   100,   100,
     100,   100,   100,    82,    91,    82,   104,    91,   100,    70,
     101,    13,    41,    35,    35,    43,    86,    35,    93,    96,
      82,    21,    41,   100,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    58,    59,    57,    60,    61,
      57,    62,    62,    62,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    69,    71,    70,    70,
      72,    73,    72,    74,    74,    75,    75,    75,    77,    76,
      78,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    84,    83,    85,    86,    83,    88,    87,    89,
      87,    90,    87,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    94,    93,    95,    96,    97,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     0,    11,     0,     0,
      10,     3,     1,     1,     2,     3,     1,     2,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     0,     4,     1,
       1,     0,     5,     2,     1,     1,     1,     1,     0,     5,
       1,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     6,     0,     0,     9,     0,     6,     0,
       8,     0,    10,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     1,     0,     5,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     3,     3,     2,     5,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0
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
#line 127 "parser.y"
               {head = (yyvsp[0].node);}
#line 1727 "y.tab.c"
    break;

  case 3:
#line 130 "parser.y"
                          { (yyval.node) = mknode("",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1733 "y.tab.c"
    break;

  case 4:
#line 131 "parser.y"
                      { (yyval.node) = mknode("",(yyvsp[0].node), NULL);}
#line 1739 "y.tab.c"
    break;

  case 5:
#line 136 "parser.y"
                            {add('F');}
#line 1745 "y.tab.c"
    break;

  case 6:
#line 136 "parser.y"
                                                                                                                                                   {endScope();}
#line 1751 "y.tab.c"
    break;

  case 7:
#line 137 "parser.y"
           {
 			 (yyval.node)=mknode("FUNC",mknode((yyvsp[-9].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[-6].node), NULL) ,mknode("RET",(yyvsp[-10].node), NULL))) ,mknode("BODY",(yyvsp[-3].node),(yyvsp[-2].node)));
	   }
#line 1759 "y.tab.c"
    break;

  case 8:
#line 141 "parser.y"
                            {add('F');}
#line 1765 "y.tab.c"
    break;

  case 9:
#line 141 "parser.y"
                                                                                                                                             {endScope();}
#line 1771 "y.tab.c"
    break;

  case 10:
#line 142 "parser.y"
                {
			 (yyval.node)=mknode("FUNC", mknode((yyvsp[-8].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[-5].node), NULL) ,mknode("RET VOID",NULL, NULL))), mknode("BODY",(yyvsp[-2].node),NULL));
		}
#line 1779 "y.tab.c"
    break;

  case 11:
#line 148 "parser.y"
                                             {(yyval.node)=mknode("",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1785 "y.tab.c"
    break;

  case 12:
#line 149 "parser.y"
                    {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1791 "y.tab.c"
    break;

  case 13:
#line 150 "parser.y"
                  {(yyval.node)=mknode("NONE)\n",(yyvsp[0].node),NULL);}
#line 1797 "y.tab.c"
    break;

  case 14:
#line 153 "parser.y"
                            {(yyval.node)=mknode("ARGS-TYPE",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1803 "y.tab.c"
    break;

  case 15:
#line 156 "parser.y"
                                         {add_to_param_count(); (yyval.node)=mknode((yyvsp[-2].str),(yyvsp[0].node),NULL);}
#line 1809 "y.tab.c"
    break;

  case 16:
#line 157 "parser.y"
                      {add_to_param_count(); (yyval.node)=mknode((yyvsp[0].str),mknode(")",NULL,NULL),NULL);}
#line 1815 "y.tab.c"
    break;

  case 17:
#line 161 "parser.y"
                                   {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1821 "y.tab.c"
    break;

  case 18:
#line 162 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1827 "y.tab.c"
    break;

  case 19:
#line 163 "parser.y"
                              {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1833 "y.tab.c"
    break;

  case 20:
#line 164 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1839 "y.tab.c"
    break;

  case 21:
#line 165 "parser.y"
                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1845 "y.tab.c"
    break;

  case 22:
#line 166 "parser.y"
                  {(yyval.node)=NULL;}
#line 1851 "y.tab.c"
    break;

  case 23:
#line 170 "parser.y"
                                        {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1857 "y.tab.c"
    break;

  case 24:
#line 171 "parser.y"
                                          {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1863 "y.tab.c"
    break;

  case 25:
#line 172 "parser.y"
                               {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1869 "y.tab.c"
    break;

  case 26:
#line 173 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1875 "y.tab.c"
    break;

  case 27:
#line 174 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1881 "y.tab.c"
    break;

  case 28:
#line 175 "parser.y"
                   {(yyval.node)=NULL;}
#line 1887 "y.tab.c"
    break;

  case 29:
#line 179 "parser.y"
                                                 {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1893 "y.tab.c"
    break;

  case 30:
#line 180 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1899 "y.tab.c"
    break;

  case 31:
#line 184 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1905 "y.tab.c"
    break;

  case 32:
#line 185 "parser.y"
                                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1911 "y.tab.c"
    break;

  case 33:
#line 186 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1917 "y.tab.c"
    break;

  case 34:
#line 187 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1923 "y.tab.c"
    break;

  case 35:
#line 188 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1929 "y.tab.c"
    break;

  case 36:
#line 191 "parser.y"
                                                                                                 {check_param_list(); (yyval.node)=mknode("FUNCTION_CALL",(yyvsp[-4].node),(yyvsp[-2].node));}
#line 1935 "y.tab.c"
    break;

  case 37:
#line 195 "parser.y"
                              {check_declaration((yyvsp[0].str)); add_to_current_param_list();}
#line 1941 "y.tab.c"
    break;

  case 38:
#line 195 "parser.y"
                                                                                                                { (yyval.node)=mknode((yyvsp[-3].str),(yyvsp[0].node), NULL);}
#line 1947 "y.tab.c"
    break;

  case 39:
#line 196 "parser.y"
                              {check_declaration((yyvsp[0].str)); add_to_current_param_list(); (yyval.node)=mknode((yyvsp[0].str),NULL, NULL);}
#line 1953 "y.tab.c"
    break;

  case 40:
#line 200 "parser.y"
                        {check_declaration((yyvsp[0].str)); set_param_count((yyvsp[0].str)); (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);}
#line 1959 "y.tab.c"
    break;

  case 41:
#line 201 "parser.y"
                       {check_declaration((yyvsp[0].str)); set_param_count((yyvsp[0].str)); }
#line 1965 "y.tab.c"
    break;

  case 42:
#line 201 "parser.y"
                                                                                                                  {(yyval.node)=mknode((yyvsp[-4].str),(yyvsp[-1].node2)->node,NULL);}
#line 1971 "y.tab.c"
    break;

  case 43:
#line 207 "parser.y"
                                           {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1977 "y.tab.c"
    break;

  case 44:
#line 208 "parser.y"
                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1983 "y.tab.c"
    break;

  case 45:
#line 212 "parser.y"
                      { (yyval.node) = mknode("",(yyvsp[0].node), NULL); }
#line 1989 "y.tab.c"
    break;

  case 46:
#line 213 "parser.y"
                                  {(yyval.node) = mknode("",(yyvsp[0].node), NULL); }
#line 1995 "y.tab.c"
    break;

  case 47:
#line 214 "parser.y"
                          {(yyval.node) = mknode("STRING",(yyvsp[0].node), NULL); }
#line 2001 "y.tab.c"
    break;

  case 48:
#line 218 "parser.y"
                                 {add('V');}
#line 2007 "y.tab.c"
    break;

  case 49:
#line 219 "parser.y"
          {	
		  check_declaration_type(type, (yyvsp[0].node2)->type);
		  (yyval.node) = mknode("VAR",(yyvsp[-3].node), mknode((yyvsp[-2].str), (yyvsp[0].node2)->node, NULL));
	  }
#line 2016 "y.tab.c"
    break;

  case 50:
#line 226 "parser.y"
                   {(yyval.node2)=mknode2("",NULL, NULL, "NONE");}
#line 2022 "y.tab.c"
    break;

  case 51:
#line 228 "parser.y"
        {
		(yyval.node2)=mknode2("",(yyvsp[-1].node2)->node,NULL, (yyvsp[-1].node2)->type); 
	}
#line 2030 "y.tab.c"
    break;

  case 52:
#line 233 "parser.y"
                                                                                             {(yyval.node)=mknode((yyvsp[-4].str),(yyvsp[-2].node),NULL);}
#line 2036 "y.tab.c"
    break;

  case 53:
#line 242 "parser.y"
                                       {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2042 "y.tab.c"
    break;

  case 54:
#line 243 "parser.y"
                      {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2048 "y.tab.c"
    break;

  case 55:
#line 247 "parser.y"
                            {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2054 "y.tab.c"
    break;

  case 56:
#line 248 "parser.y"
                                    {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2060 "y.tab.c"
    break;

  case 57:
#line 249 "parser.y"
                     {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2066 "y.tab.c"
    break;

  case 58:
#line 250 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2072 "y.tab.c"
    break;

  case 59:
#line 251 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2078 "y.tab.c"
    break;

  case 60:
#line 252 "parser.y"
                        {(yyval.node)=mknode("CODE_BLOCK",(yyvsp[0].node),NULL);}
#line 2084 "y.tab.c"
    break;

  case 61:
#line 255 "parser.y"
                                                      {endScope(); (yyval.node)=mknode("CODE_BLOCK",(yyvsp[-1].node),NULL);}
#line 2090 "y.tab.c"
    break;

  case 62:
#line 258 "parser.y"
            {add('K');}
#line 2096 "y.tab.c"
    break;

  case 63:
#line 258 "parser.y"
                                                                                   { (yyval.node)=mknode("IF",(yyvsp[-2].node2)->node,(yyvsp[0].node));}
#line 2102 "y.tab.c"
    break;

  case 64:
#line 259 "parser.y"
            {add('K');}
#line 2108 "y.tab.c"
    break;

  case 65:
#line 259 "parser.y"
                                                                                       {add('K');}
#line 2114 "y.tab.c"
    break;

  case 66:
#line 259 "parser.y"
                                                                                                              { (yyval.node)=mknode("IF-ELSE", mknode("",(yyvsp[-5].node2)->node,(yyvsp[-3].node)), mknode("",(yyvsp[0].node),NULL));}
#line 2120 "y.tab.c"
    break;

  case 67:
#line 264 "parser.y"
                {add('K');}
#line 2126 "y.tab.c"
    break;

  case 68:
#line 264 "parser.y"
                                                                                      {  (yyval.node)=mknode("WHILE",(yyvsp[-2].node2)->node,(yyvsp[0].node));}
#line 2132 "y.tab.c"
    break;

  case 69:
#line 265 "parser.y"
             {add('K');}
#line 2138 "y.tab.c"
    break;

  case 70:
#line 265 "parser.y"
                                                                                                   {  (yyval.node)=mknode("DO-WHILE",(yyvsp[-5].node),(yyvsp[-2].node2)->node);}
#line 2144 "y.tab.c"
    break;

  case 71:
#line 266 "parser.y"
              {add('K');}
#line 2150 "y.tab.c"
    break;

  case 72:
#line 266 "parser.y"
                                                                                                                    { (yyval.node)=mknode("FOR",mknode("INIT", (yyvsp[-6].node), mknode("COND", (yyvsp[-4].node2)->node, mknode("UPDATE",(yyvsp[-2].node), NULL))),(yyvsp[0].node));}
#line 2156 "y.tab.c"
    break;

  case 73:
#line 270 "parser.y"
                     {(yyval.node2)=mknode2("==",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2"));}
#line 2162 "y.tab.c"
    break;

  case 74:
#line 271 "parser.y"
                          {(yyval.node2)=mknode2("!=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2"));}
#line 2168 "y.tab.c"
    break;

  case 75:
#line 272 "parser.y"
                       {(yyval.node2)=mknode2("<",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2174 "y.tab.c"
    break;

  case 76:
#line 273 "parser.y"
                           {(yyval.node2)=mknode2("<=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2180 "y.tab.c"
    break;

  case 77:
#line 274 "parser.y"
                          {(yyval.node2)=mknode2(">",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2186 "y.tab.c"
    break;

  case 78:
#line 275 "parser.y"
                              {(yyval.node2)=mknode2(">=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2192 "y.tab.c"
    break;

  case 79:
#line 276 "parser.y"
                 {(yyval.node2)=mknode2("||",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log"));}
#line 2198 "y.tab.c"
    break;

  case 80:
#line 277 "parser.y"
                      {(yyval.node2)=mknode2("&&",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log"));}
#line 2204 "y.tab.c"
    break;

  case 81:
#line 278 "parser.y"
                  {(yyval.node2)=mknode2("!",(yyvsp[0].node2)->node,NULL, (yyvsp[0].node2)->type);}
#line 2210 "y.tab.c"
    break;

  case 82:
#line 280 "parser.y"
                                                            {check_declaration_type((yyvsp[-3].node2)->type, (yyvsp[-1].node2)->type); (yyval.node)=mknode("=",(yyvsp[-3].node2)->node,(yyvsp[-1].node2)->node); }
#line 2216 "y.tab.c"
    break;

  case 83:
#line 283 "parser.y"
                        {check_declaration((yyvsp[0].str));   (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 0));}
#line 2222 "y.tab.c"
    break;

  case 84:
#line 284 "parser.y"
                       {check_declaration((yyvsp[0].str));}
#line 2228 "y.tab.c"
    break;

  case 85:
#line 284 "parser.y"
                                                                                           {(yyval.node2)=mknode2((yyvsp[-4].str),(yyvsp[-1].node2)->node,NULL, get_type((yyvsp[-4].str), 0));}
#line 2234 "y.tab.c"
    break;

  case 86:
#line 287 "parser.y"
                                      {(yyval.node)=mknode("=",(yyvsp[-2].node2)->node,(yyvsp[0].node));}
#line 2240 "y.tab.c"
    break;

  case 87:
#line 289 "parser.y"
                           {(yyval.node)=mknode("=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node);}
#line 2246 "y.tab.c"
    break;

  case 88:
#line 291 "parser.y"
                                 { (yyval.node)=mknode("RET-VAL",(yyvsp[-1].node),NULL);}
#line 2252 "y.tab.c"
    break;

  case 89:
#line 294 "parser.y"
                    {check_declaration((yyvsp[0].str)); check_return_type((yyvsp[0].str));  (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);}
#line 2258 "y.tab.c"
    break;

  case 90:
#line 296 "parser.y"
         {
		 (yyval.node)=mknode("True",NULL,NULL);
		 add('C');

	  }
#line 2268 "y.tab.c"
    break;

  case 91:
#line 302 "parser.y"
          {
		 (yyval.node)=mknode("False",NULL,NULL); 
		 add('C');
	  }
#line 2277 "y.tab.c"
    break;

  case 92:
#line 307 "parser.y"
         {
		 (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);
		 add('C');
	 }
#line 2286 "y.tab.c"
    break;

  case 93:
#line 312 "parser.y"
         {
		(yyval.node)=mknode((yyvsp[0].str),NULL,NULL); 
	    add('C');
	 }
#line 2295 "y.tab.c"
    break;

  case 94:
#line 317 "parser.y"
         {
		 (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);
	     add('C');
	 }
#line 2304 "y.tab.c"
    break;

  case 95:
#line 322 "parser.y"
         {
		 (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);
		 add('C');
	 }
#line 2313 "y.tab.c"
    break;

  case 96:
#line 330 "parser.y"
                         {(yyval.node2)=mknode2("",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, "exp");}
#line 2319 "y.tab.c"
    break;

  case 97:
#line 331 "parser.y"
       {(yyval.node2)=mknode2("",(yyvsp[0].node2)->node,NULL, (yyvsp[0].node2)->type); }
#line 2325 "y.tab.c"
    break;

  case 98:
#line 332 "parser.y"
           {(yyval.node2)=mknode2("",(yyvsp[0].node),NULL, "NONE");}
#line 2331 "y.tab.c"
    break;

  case 99:
#line 336 "parser.y"
                       {(yyval.node2)=mknode2("+",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg"));}
#line 2337 "y.tab.c"
    break;

  case 100:
#line 337 "parser.y"
                        {(yyval.node2)=mknode2("-",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg"));}
#line 2343 "y.tab.c"
    break;

  case 101:
#line 338 "parser.y"
                           {(yyval.node2)=mknode2("*",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg"));}
#line 2349 "y.tab.c"
    break;

  case 102:
#line 339 "parser.y"
                           {(yyval.node2)=mknode2("/",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg"));}
#line 2355 "y.tab.c"
    break;

  case 103:
#line 340 "parser.y"
                      {(yyval.node2)=mknode2("==",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2"));}
#line 2361 "y.tab.c"
    break;

  case 104:
#line 341 "parser.y"
                          {(yyval.node2)=mknode2("!=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2"));}
#line 2367 "y.tab.c"
    break;

  case 105:
#line 342 "parser.y"
                       {(yyval.node2)=mknode2("<",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2373 "y.tab.c"
    break;

  case 106:
#line 343 "parser.y"
                           {(yyval.node2)=mknode2("<=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2379 "y.tab.c"
    break;

  case 107:
#line 344 "parser.y"
                          {(yyval.node2)=mknode2(">",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2385 "y.tab.c"
    break;

  case 108:
#line 345 "parser.y"
                              {(yyval.node2)=mknode2(">=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3"));}
#line 2391 "y.tab.c"
    break;

  case 109:
#line 346 "parser.y"
                 {(yyval.node2)=mknode2("||",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log"));}
#line 2397 "y.tab.c"
    break;

  case 110:
#line 347 "parser.y"
                      {(yyval.node2)=mknode2("&&",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log"));}
#line 2403 "y.tab.c"
    break;

  case 111:
#line 348 "parser.y"
                        {(yyval.node2)=mknode2("",(yyvsp[0].node2)->node, NULL, (yyvsp[0].node2)->type);}
#line 2409 "y.tab.c"
    break;

  case 112:
#line 349 "parser.y"
                  {(yyval.node2)=mknode2("!",(yyvsp[0].node2)->node,NULL, check_alg_expr("NONE", (yyvsp[0].node2)->type, "not"));}
#line 2415 "y.tab.c"
    break;

  case 113:
#line 350 "parser.y"
                      {check_declaration((yyvsp[0].str));  (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 0));}
#line 2421 "y.tab.c"
    break;

  case 114:
#line 351 "parser.y"
                        {(yyval.node2)=mknode2("function_call",(yyvsp[0].node),NULL, "func");}
#line 2427 "y.tab.c"
    break;

  case 115:
#line 352 "parser.y"
                                    {(yyval.node2)=mknode2((yyvsp[-1].str),NULL,NULL, get_type((yyvsp[-1].str), 0));}
#line 2433 "y.tab.c"
    break;

  case 116:
#line 353 "parser.y"
                                                   {(yyval.node2)=mknode2("exp",(yyvsp[-1].node2)->node,NULL, (yyvsp[-1].node2)->type);}
#line 2439 "y.tab.c"
    break;

  case 117:
#line 354 "parser.y"
                              {check_declaration((yyvsp[0].str)); (yyval.node2)=mknode2("ADDRESS-OF",mknode((yyvsp[0].str),NULL,NULL),NULL, get_type((yyvsp[0].str), 0));}
#line 2445 "y.tab.c"
    break;

  case 118:
#line 355 "parser.y"
                                                                                {check_declaration((yyvsp[-3].str)); (yyval.node2)=mknode2("ADDRESS-OF",mknode((yyvsp[-3].str),(yyvsp[-1].node),NULL),NULL, get_type((yyvsp[-3].str), 0));}
#line 2451 "y.tab.c"
    break;

  case 119:
#line 356 "parser.y"
                               {check_declaration((yyvsp[0].str)); (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 0));}
#line 2457 "y.tab.c"
    break;

  case 120:
#line 360 "parser.y"
                                     {(yyval.node)=mknode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2463 "y.tab.c"
    break;

  case 121:
#line 361 "parser.y"
                                      {(yyval.node)=mknode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2469 "y.tab.c"
    break;

  case 122:
#line 362 "parser.y"
                                         {(yyval.node)=mknode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2475 "y.tab.c"
    break;

  case 123:
#line 363 "parser.y"
                                         {(yyval.node)=mknode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2481 "y.tab.c"
    break;

  case 124:
#line 364 "parser.y"
                          {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2487 "y.tab.c"
    break;

  case 125:
#line 369 "parser.y"
               { insert_type("BOOL"); (yyval.node)=mknode("BOOL",NULL,NULL);}
#line 2493 "y.tab.c"
    break;

  case 126:
#line 370 "parser.y"
               {(yyval.node)=mknode("CHAR",NULL,NULL); insert_type("CHAR");}
#line 2499 "y.tab.c"
    break;

  case 127:
#line 371 "parser.y"
                 {(yyval.node)=mknode("CHAR_P",NULL,NULL); insert_type("CHAR_P");}
#line 2505 "y.tab.c"
    break;

  case 128:
#line 372 "parser.y"
              { insert_type("INT"); (yyval.node)=mknode("INT",NULL,NULL);}
#line 2511 "y.tab.c"
    break;

  case 129:
#line 373 "parser.y"
                {(yyval.node)=mknode("INT_P",NULL,NULL); insert_type("INT_P");}
#line 2517 "y.tab.c"
    break;

  case 130:
#line 374 "parser.y"
               {(yyval.node)=mknode("REAL",NULL,NULL); insert_type("REAL");}
#line 2523 "y.tab.c"
    break;

  case 131:
#line 375 "parser.y"
                 {(yyval.node)=mknode("REAL_P",NULL,NULL); insert_type("REAL_P");}
#line 2529 "y.tab.c"
    break;

  case 132:
#line 376 "parser.y"
                 {(yyval.node)=mknode("STRING",NULL,NULL); insert_type("STRING");}
#line 2535 "y.tab.c"
    break;

  case 133:
#line 381 "parser.y"
         {
		 (yyval.node2)=mknode2("None",NULL,NULL, "None");
		  add('C');
	 }
#line 2544 "y.tab.c"
    break;

  case 134:
#line 386 "parser.y"
         {
		 (yyval.node2)=mknode2("True",NULL,NULL, "BOOL");
		 add('C');
	  }
#line 2553 "y.tab.c"
    break;

  case 135:
#line 391 "parser.y"
          {
		 (yyval.node2)=mknode2("False",NULL,NULL, "BOOL"); 
		 add('C'); 
	  }
#line 2562 "y.tab.c"
    break;

  case 136:
#line 396 "parser.y"
         {
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "CHAR");
		  add('C');
	 }
#line 2571 "y.tab.c"
    break;

  case 137:
#line 401 "parser.y"
         {
		(yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "INT"); 
		add('C');
	 }
#line 2580 "y.tab.c"
    break;

  case 138:
#line 406 "parser.y"
         {
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "REAL");
		  add('C');
	 }
#line 2589 "y.tab.c"
    break;

  case 139:
#line 411 "parser.y"
         {
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "REAL");
		  add('C');
	 }
#line 2598 "y.tab.c"
    break;

  case 140:
#line 416 "parser.y"
         {
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "STR");
		  add('C');
	 }
#line 2607 "y.tab.c"
    break;

  case 141:
#line 423 "parser.y"
                            {(yyval.node)=mknode((yyvsp[0].str),NULL,NULL); add('C');}
#line 2613 "y.tab.c"
    break;

  case 142:
#line 424 "parser.y"
                       {(yyval.node)=mknode((yyvsp[0].str),NULL,NULL); add('C');}
#line 2619 "y.tab.c"
    break;

  case 143:
#line 427 "parser.y"
          {(yyval.node)=NULL;}
#line 2625 "y.tab.c"
    break;


#line 2629 "y.tab.c"

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
#line 429 "parser.y"


int main() {
	set_current_scope("global", 0);
    yyparse();
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER  SCOPE\n");
	printf("_______________________________________\n\n");
	int i,j=0;
	int flag = 0;
	for(j = 0; j <= count_scope_stack_elements; j++){
		int temp = scopeStack[j].last_index;
		for(i=0; i < temp; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t\n",
			 scopeStack[j].symbol_table[i].id_name, 
			 scopeStack[j].symbol_table[i].data_type,
			 scopeStack[j].symbol_table[i].type,
			 scopeStack[j].symbol_table[i].line_no,
			 scopeStack[j].scope_name);

			if(strcmp(scopeStack[j].symbol_table[i].id_name, "main") == 0){
				flag = 1;
			}
		}
	}
	

	if(flag == 1) {
		printf("\n\n");
		printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
		TreePrint(head);
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
		if(sem_errors>0) {
			printf("Semantic analysis completed with %d errors\n", sem_errors);
			for(int i=0; i<sem_errors; i++){
				printf("\t - %s", errors[i]);
			}
		} else {
			printf("Semantic analysis completed with no errors");
		}
		printf("\n\n");
	}else{
		printf("\n\n");
		printf("Semantic analysis completed with error , main function requared");
		printf("\n\n");
	}

	//freeStack();
	
}

int search(char *type) {
	int i;
	for(i=count_symbol_table_line-1; i>=0; i--) {
		if(strcmp(scopeStack[current_scope_stack_top].symbol_table[i].type, "Function")==0 || strcmp(scopeStack[current_scope_stack_top].symbol_table[i].type, "Variable")==0){
			if(strcmp(scopeStack[current_scope_stack_top].symbol_table[i].id_name, type)==0) {
				return -1;
				break;
			}
		}
		
	}
	return 0;
}

int searchForDeclaration(char *type) {
	int i,j;
	int flag = 0;
	for(j=count_scope_stack_elements; j >= 0; j--) {
		for(i = scopeStack[j].last_index-1; i>=0; i--) {
			if(strcmp(scopeStack[j].symbol_table[i].type, "Function")==0 || strcmp(scopeStack[j].symbol_table[i].type, "Variable")==0){
				if(strcmp(scopeStack[j].symbol_table[i].id_name, type)==0) {
					flag = 1;
					break;
				}
			}
			
		}

		if(flag == 1){
			break;
		}
	}

	return flag;
}

void check_declaration(char *c) {
    q = searchForDeclaration(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", count_line+1, c);
		sem_errors++;
    }
}

void check_return_type(const char *value) {
	char *func_datatype = get_type(scopeStack[current_scope_stack_top].scope_name, 1);
	char *return_datatype = get_type(value, 0);
	if(strcmp(func_datatype, return_datatype) != 0){
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", count_line+1);
		sem_errors++;
	}
}


char *get_type(const char *var, int is_func){
	int temp = current_scope_stack_top;
	if(is_func) {
		temp = scopeStack[current_scope_stack_top].parent;
	}
	for(int i=0; i<count_symbol_table_line; i++) {
		if(!strcmp(scopeStack[temp].symbol_table[i].id_name, var)) {
			return scopeStack[temp].symbol_table[i].data_type;
		}
	}
}

int check_types(char *type1, char *type2){
	if(strcmp(type2, "NONE")==0 )
		return -1;
	if(strcmp(type1, "INT")==0  && strcmp(type2, "REAL")==0 )
		return 1;
	if(strcmp(type1, "REAL")==0  && strcmp(type2, "INT")==0 )
		return 2;
	if(strcmp(type1, "INT")==0  && strcmp(type2, "CHAR")==0 )
		return 3;
	if(strcmp(type1, "CHAR")==0  && strcmp(type2, "INT")==0 )
		return 4;
	if(strcmp(type1, "REAL")==0  && strcmp(type2, "CHAR")==0 )
		return 5;
	if(strcmp(type1, "CHAR")==0  && strcmp(type2, "REAL")==0 )
		return 6;
	if(strcmp(type1, "INT")==0 && strcmp(type2, "INT")==0)
		return 7;
	if(strcmp(type1, "REAL")==0  && strcmp(type2, "REAL")==0 )
		return 8;
	if(strcmp(type1, "BOOL")==0  && strcmp(type2, "BOOL")==0 )
		return 9;

	return 10;
}

char* check_alg_expr(char * type1, char * type2, char * op) {
	printf("Check Alg exp %s %s %s\n", type1, type2, op);
	int temp = check_types(type1, type2);
	printf("%d\n", temp);
	if(strcmp(op, "alg") == 0){
		if( temp == 7)
			return "INT";
		else if(temp == 1 || temp == 2 || temp == 8)
			return "REAL";
	}else if(strcmp(op, "log")== 0){
		if(temp == 9)
			return "BOOL";	
	}else if(strcmp(op, "log3")== 0){
		if(temp == 1 || temp == 2 || temp==7 || temp == 8)
			return "BOOL";	
	}else if(strcmp(op, "log2")== 0){
		if(strcmp(type1, type2)==0)
			return "BOOL";	
	}else if(strcmp(op, "not")== 0){
		if(strcmp(type2,"BOOL")==0)
			return "BOOL";
	}else{
		
	}

	sprintf(errors[sem_errors], "Line %d: TYPE CASTING ERROR \n", count_line+1);
	sem_errors++;
	return "EROR";
}


void check_declaration_type(char *type1, char *type2) {
	printf("Check declaration type %s %s\n", type1, type2);
	int temp = check_types(type1, type2);
	printf(" Temp %d\n", temp);
	
	if(strcmp(type1, type2) !=0  && temp != -1 ){
		sprintf(errors[sem_errors], "Line %d: TYPE CASTING ERROR \n", count_line+1);
		sem_errors++;
	}
}


void add(char c) {
	if(c == 'V'){
		for(int i=0; i<10; i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", count_line+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
	if(!q) {
		if(c == 'K') {
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup(yytext);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup("N/A");
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Keyword\t");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
			count_line++;
			set_current_scope(yytext, 0);
		}
		
		else if(c == 'V') {
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup(yytext);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup(type);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Variable");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
		}

		else if(c == 'C') {
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup(yytext);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup("CONST");
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Constant");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
			count_line++;
		}

		else if(c == 'F') {
			if(strcmp(yytext, "main") == 0 && mulltipleMain == 1){
				sprintf(errors[sem_errors], "Line %d: mulltiple main declaration !\n", count_line+1);
				sem_errors++;
				return;
			}

			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup(yytext);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup(type);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Function");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
			count_line++;

			if (strcmp(yytext, "main")== 0) {
				mulltipleMain = 1;
			}

			set_current_scope(yytext, 1);
		}
	
    }
    else if((c == 'V' || c =='F') && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", count_line+1, yytext);
		sem_errors++;
    }
}

void insert_type(const char* scope) {
	strcpy(type, scope);
}


void add_to_param_count() {

	if(strcmp(scopeStack[current_scope_stack_top].scope_name, "main")== 0) {
		sprintf(errors[sem_errors], "Line %d: Main can't accept arguments \n", count_line+1);
		sem_errors++;
	}else{
		scopeStack[current_scope_stack_top].param_count ++;
	} 

}

void set_param_count(const char * name) {
	int i;
	for( i = count_scope_stack_elements; i >=0; i--) {
		if(strcmp(scopeStack[i].scope_name, name) == 0) {
			param_count_current = scopeStack[i].param_count;
		}
	
	}
}

void check_param_list() {
	if(param_count_current - current_param_list != 0) {
		sprintf(errors[sem_errors], "Line %d: Function attribute list not matched \n", count_line+1);
		sem_errors++;
	}
}

void add_to_current_param_list() {
	current_param_list ++;
}

void set_current_scope(const char* scope, int is_func) {
	int temp = current_scope_stack_top;
	count_scope_stack_elements++;
	current_scope_stack_top = count_scope_stack_elements;
	scopeStack[count_scope_stack_elements].scope_name = strdup(scope);
	scopeStack[count_scope_stack_elements].last_index = 0;
	scopeStack[count_scope_stack_elements].param_count = 0;
	scopeStack[count_scope_stack_elements].is_function = is_func;
	scopeStack[count_scope_stack_elements].parent = temp;
	count_symbol_table_line = 0;
}

void endScope() {
	current_scope_stack_top = scopeStack[current_scope_stack_top].parent;
	count_symbol_table_line = scopeStack[current_scope_stack_top].last_index;
}



void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

void freeStack() {
 int i,j = 0;	
 for(j = 0; i < count_scope_stack_elements; i++){
	 for(i=0; i < count_symbol_table_line;i++) {
		free(scopeStack[j].symbol_table[i].id_name);
		free(scopeStack[j].symbol_table[i].type);
		free(scopeStack[j].symbol_table[i].data_type);
	}
	free(scopeStack[j].scope_name);
 }		
}

/* AST  */
void CalcShift(int t) {
	for(int i= 0; i < t; i++){
		printf("	");
	}
}



void TreePrint(node* tree){
	if(strcmp(tree->token, "FUNC") == 0){
		func_name=(char*)malloc(sizeof(tree->left->token) + 1);
		strcpy(func_name,tree->left->token);
		printf("(%s\n",tree->token);
		shift++;
		CalcShift(shift);
		flag = 1;
	}else if(strcmp(tree->token, "BODY") == 0){
		CalcShift(shift);
		printf("(%s",tree->token);
		flag=1;
	}else if(strcmp(tree->token, "CODE") == 0 ){
		CalcShift(shift);
		printf("(%s\n",tree->token);
		shift++;	
	}else if(strcmp(tree->token, "ARGS") == 0) {
		CalcShift(shift);
		printf("(%s",tree->token);
	}
	else if(strcmp(tree->token,"RET-VAL")==0){
		ret_val_flag=1;
		printf("\n");
		shift++;
		CalcShift(shift);
		printf("(RET ");
		shift--;
	}
	else if(strcmp(tree->token, "RET") == 0 || strcmp(tree->token, "RET VOID") == 0 ){
		ret_flag=1;
		CalcShift(shift);
		printf("(%s",tree->token);
	}
	else if(strcmp(tree->token, "") == 0 ){
	
	}
	else if(strcmp(tree->token, "NONE") == 0 ){
		printf(" NONE");
	}
	else if(strcmp(tree->token,"ARGS-TYPE") == 0){
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(");
		shift--;
	}
	else if(strcmp(tree->token,"IF") == 0||strcmp(tree->token,"CODE_BLOCK") == 0){
		flag = 1;
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(%s",tree->token);
		shift--;
	}
	else if(strcmp(tree->token, "&&") == 0 || strcmp(tree->token, "/") == 0 || strcmp(tree->token, "==") == 0 ||
		strcmp(tree->token, ">") == 0 || strcmp(tree->token, ">=") == 0 || 
	strcmp(tree->token, "<") == 0 || strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "-") == 0 || 
	strcmp(tree->token, "!") == 0 || strcmp(tree->token, "!=") == 0 || strcmp(tree->token, "||") == 0 || 
	strcmp(tree->token, "+") == 0 || strcmp(tree->token, "*") == 0 || strcmp(tree->token, "&") == 0 || 
	strcmp(tree->token, "^") == 0 || strcmp(tree->token, "|") == 0 || strcmp(tree->token, ",") == 0 ){
		shift++;
		printf("\n");
		CalcShift(shift);
		printf("(%s", tree->token);
		shift--;
	}
	else if(strcmp(tree->token, "=") == 0) {
		printf("\n");
		shift++;
		CalcShift(shift);
		printf("(%s", tree->token);
	}
	else{
		printf(" %s",tree->token);
		if(ret_val_flag==1){
			printf(")");
			ret_val_flag=0;
		}
	}

	if(tree->left){
		TreePrint(tree->left);
	}


	if(tree->right){
		TreePrint(tree->right);
		if(strcmp(tree->token, "&&") == 0 || strcmp(tree->token, "/") == 0 || strcmp(tree->token, "==") == 0 ||
			strcmp(tree->token, ">") == 0 || strcmp(tree->token, ">=") == 0 || 
		strcmp(tree->token, "<") == 0 || strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "-") == 0 || 
		strcmp(tree->token, "!") == 0 || strcmp(tree->token, "!=") == 0 || strcmp(tree->token, "||") == 0 || 
		strcmp(tree->token, "+") == 0 || strcmp(tree->token, "*") == 0 || strcmp(tree->token, "&") == 0 || 
		strcmp(tree->token, "^") == 0 || strcmp(tree->token, "|") == 0 || strcmp(tree->token, ",") == 0){
			printf(")");
		}
		else if (strcmp(func_name,tree->token)==0){
			printf("\n");
		}
		else if(flag == 1 && ret_flag != 1||strcmp("ARGS-TYPE",tree->token)==1)
		{
			if(strcmp(tree->token,"BODY") == 0){
				shift = 1;//code -> change to 2
			}
			printf("\n");
			CalcShift(shift);
			printf(")\n");
			flag=0;
		}
		else{
			printf(")");
			ret_flag = 0;
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

node2 *mknode2(char *token, node *left, node*right, char * type) {
	node2 *newnode = (node2*)malloc(sizeof(node2));
	char *newstr2 = (char*)malloc(sizeof(type) + 1);
	strcpy(newstr2,type);
	char *newstr = (char*)malloc(sizeof(token) + 1);
	strcpy(newstr,token);
	newnode->node = mknode(newstr, left, right);
	newnode->type= newstr2;
	return newnode;
}

