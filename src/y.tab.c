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
	

	/* Tree and semantyc */
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

	/* Print Tree  */
	void TreePrint(node *tree);
	void CalcShift(int t); 

	char *func_name=NULL;
	int shift = 0;
	int ret_flag = 0;	
	int ret_val_flag=0;
	

	/*  Semantic  */
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
		struct dataType symbol_table[50];
	} scopeStack[50];
	 
	int count_scope_stack_elements = -1;
	int current_scope_stack_top = -1;
    int count_symbol_table_line=0;
	int count_code_lines = 0;
    int q;
    int count_line = 0;
	char type[10];
	int flag = 0;
	int mulltipleMain = 0;
	int sem_errors=0;
	int param_count_current = 0;
	int current_param_list = 0;
	char errors[10][100];
	char reserved[10][10] = {"int", "real", "char", "void", "if", "else", "for", "while", "main", "return"};

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


	/* TAC */
	char buff[100];
	int label[200];
	int lnum=0;
	int ltop=0;
	int stop=0;
	int top=0;
	char st[1000][10];
	char temp_var[4]="t";
	int ind=0;
	FILE * f1;
	int function_call_tac = 0;

	char* check_alg_expr(char * type1, char * type2, char * op, char* operator);
	void check_declaration_type(char *type1, char *type2);
	void func_start();
	void func_end();
	void while_start();
	void while_end();
	void while_rep();
	void for_start();
	void for_inter();
	void for_rep();
	void logical_gen(char * op);
	void algebric_gen(char * op);
	void codegen_assign();
	void push(char * str);
	void if_label_start();
	void if_label_rep();
	void if_label_else();
	void func_call_gen();

#line 193 "y.tab.c"

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
    COMMA = 291,
    OPEN_CURLY_BRACES = 292,
    CLOSE_CURLY_BRACES = 293,
    COLON = 294,
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
#define COMMA 291
#define OPEN_CURLY_BRACES 292
#define CLOSE_CURLY_BRACES 293
#define COLON 294
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
#line 125 "parser.y"

	struct node *node;
	struct node2 *node2;
	char *str; 

#line 357 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   814

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

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
       0,   161,   161,   164,   165,   166,   172,   172,   172,   177,
     177,   177,   184,   185,   186,   189,   192,   193,   197,   198,
     199,   200,   201,   202,   203,   207,   208,   209,   210,   211,
     212,   213,   217,   218,   219,   220,   224,   225,   226,   226,
     227,   228,   228,   231,   235,   235,   236,   237,   241,   242,
     242,   248,   249,   250,   251,   255,   256,   257,   261,   261,
     269,   269,   270,   271,   278,   278,   287,   288,   289,   290,
     294,   295,   296,   297,   297,   298,   299,   299,   302,   305,
     306,   306,   307,   311,   311,   311,   311,   312,   312,   312,
     313,   313,   313,   313,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   329,   329,   332,   333,   333,   334,   337,
     337,   339,   339,   341,   346,   347,   348,   349,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   377,
     377,   378,   378,   379,   379,   380,   380,   381,   382,   387,
     388,   389,   390,   391,   392,   393,   394,   398,   404,   410,
     416,   422,   428,   434,   440,   449,   450,   453
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
  "PLUS", "MULTIPLY", "ADDRESS", "LENGTH", "SEMICOLON", "COMMA",
  "OPEN_CURLY_BRACES", "CLOSE_CURLY_BRACES", "COLON", "OPEN_ANGLE_BRACES",
  "CLOSE_ANGLE_BRACES", "OPEN_SQUARE_BRACES", "CLOSE_SQUARE_BRACES",
  "COMMENT", "NONE", "BOOL_TRUE", "BOOL_FALSE", "CHAR_LITERAL",
  "STRING_LITERAL", "DECIMAL_LITERAL", "HEX_LITERAL", "REAL_LITERAL",
  "VARIABLE_ID", "$accept", "program", "code", "function", "$@1", "$@2",
  "$@3", "$@4", "parameter_list", "argument", "atributeList", "body",
  "body_func", "nested_statments_func", "statment_func", "$@5", "$@6",
  "function_call", "function_call_params", "$@7", "function_lhs", "$@8",
  "nested_declarations", "declaration", "variable_declaration", "$@9",
  "vrd_temp", "$@10", "string_array", "$@11", "nested_statments",
  "statment", "$@12", "$@13", "code_block", "conditions", "$@14", "loops",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "args_cond", "assignment_statement", "$@23", "lhs", "$@24", "init",
  "$@25", "update", "$@26", "return", "expressions", "exp", "string_exp",
  "$@27", "$@28", "$@29", "$@30", "type", "primitiveType",
  "integer_literal", "nothing", YY_NULLPTR
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

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-168)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     293,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   -47,
     293,    23,  -140,   293,    -5,  -140,  -140,  -140,  -140,  -140,
      25,    65,   804,   804,    36,    78,    71,  -140,    92,   105,
     804,   119,  -140,   122,   445,  -140,    71,   496,   111,  -140,
    -140,  -140,  -140,   804,   124,   515,    -6,  -140,   127,   566,
     600,   141,   144,   140,   566,   165,  -140,  -140,  -140,  -140,
     162,  -140,  -140,   171,  -140,   153,   141,   158,   161,   151,
    -140,  -140,   585,   566,   164,   173,  -140,  -140,   600,  -140,
     218,  -140,  -140,   615,  -140,   165,  -140,   641,   615,   169,
     178,   667,  -140,   195,  -140,    -1,  -140,   615,    39,  -140,
    -140,  -140,   273,   175,   196,   324,   324,   593,   141,  -140,
    -140,  -140,  -140,   615,   615,   615,   184,   615,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,   118,  -140,   197,   328,
    -140,  -140,  -140,   615,  -140,   289,  -140,   531,  -140,    39,
     615,   198,   736,   200,   667,   201,   234,   223,     5,   222,
    -140,  -140,  -140,    48,  -140,   153,  -140,   375,   426,  -140,
    -140,  -140,  -140,   593,  -140,  -140,  -140,   776,  -140,   225,
     379,    39,  -140,   615,   615,   615,   615,   615,   615,   615,
     615,   615,   615,   615,   615,   221,   702,   226,   641,  -140,
    -140,   120,    37,   141,   615,   615,   615,   615,   615,   615,
     615,   615,   667,  -140,  -140,  -140,   615,  -140,   207,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
     168,  -140,   776,     2,     2,     2,     2,     2,   764,     2,
    -140,   764,   776,   615,   228,  -140,  -140,   229,   253,    41,
       8,   113,   115,   167,   446,   450,   100,  -140,   227,    59,
     667,   722,  -140,    39,    39,    39,    39,  -140,  -140,  -140,
    -140,   231,   141,  -140,   232,  -140,     5,  -140,    -8,    -8,
    -140,   141,   238,  -140,  -140,  -140,  -140,  -140,    -1,   265,
     233,  -140,   141,   615,  -140,   750
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   149,   150,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     2,     5,     0,     9,     4,     1,     3,     6,
       0,     0,   167,   167,     0,    13,     0,    14,     0,     0,
     167,    17,    15,     0,    41,    12,     0,    41,     0,    38,
      87,    83,    90,     0,     0,    31,    48,    55,     0,    28,
      33,     0,     0,     0,    27,    52,    56,    57,    40,    37,
       0,    29,    16,     0,    64,    82,     0,     0,     0,     0,
     108,    30,    28,    27,     0,     0,    10,    26,    35,    32,
      76,    42,    36,   167,    25,    54,    51,   167,     0,     0,
       0,     0,    39,     0,    84,     0,    58,     0,     0,    11,
      34,    73,    24,     0,     0,    20,    21,    67,     0,    75,
      71,    72,    22,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   164,   161,   162,   163,   131,   133,     0,    44,
     132,    47,    53,     0,   103,   115,   117,     0,     7,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
     165,   166,   148,     0,   147,    82,    23,    20,    21,    78,
      70,    18,    19,    69,    66,    77,   130,   138,   136,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   113,
       8,     0,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,   109,    91,     0,    62,     0,    59,
      50,   145,   141,   139,   143,   107,    74,    68,   134,   135,
       0,   129,   121,   122,   126,   127,   124,   125,   119,   123,
     128,   118,   120,   167,   135,   104,   114,     0,    79,   129,
     122,   126,   127,   124,   125,   123,   128,    88,     0,     0,
       0,     0,    60,     0,     0,     0,     0,   137,    45,    65,
      80,     0,     0,   110,     0,    63,     0,   146,   142,   140,
     144,     0,     0,    86,    92,    61,    81,    89,     0,     0,
       0,   111,     0,     0,    93,   112
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,    15,   181,  -140,  -140,  -140,  -140,    34,  -140,
     256,   -33,   -15,   -34,  -140,  -140,  -140,   112,    60,  -140,
    -140,  -140,   -35,  -140,  -140,  -140,    28,  -140,  -140,  -140,
     -89,  -140,  -140,  -140,   -66,   152,  -140,   -51,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -139,   -19,  -140,   -91,
    -140,  -140,  -140,  -140,  -140,   243,   107,   -80,  -125,  -140,
    -140,  -140,  -140,   452,  -140,    73,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    47,    21,   190,    20,    99,    24,    25,
      32,   161,    77,    49,    50,    65,    51,   127,   128,   185,
      53,    74,    54,    55,    56,   148,   209,   266,    57,    90,
     106,   107,   155,   108,    81,    92,   271,    58,    67,   144,
     248,    66,   261,    68,   250,   278,   141,    59,   187,    60,
      75,   147,   249,   280,   283,   111,   134,   142,   153,   255,
     254,   256,   253,    14,   130,   154,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    27,    27,   129,   146,   203,    15,   135,   137,    27,
      73,    72,   211,   158,   191,  -105,    79,   149,   164,    48,
      86,   173,    63,    17,   214,    16,   206,   173,    18,   109,
      71,    44,   182,   166,   167,   168,   -49,   170,   182,    84,
     207,   208,   165,   -94,   100,   105,   220,   103,    19,   -94,
     132,   109,   145,   186,   109,   109,   109,    28,    84,   112,
     192,   110,   131,   247,    35,    22,   136,   157,   211,   156,
     105,   105,  -102,   162,   217,   212,  -101,    29,  -102,   213,
     214,   112,  -101,   110,   112,   112,   110,   110,   110,   150,
     151,   215,   152,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    23,   109,   109,   135,   150,
     151,   264,   109,    30,   239,   240,   241,   242,   243,   244,
     245,   246,   105,   105,    31,   162,   251,   238,   267,   268,
     269,   270,   173,    33,   173,  -100,   112,   112,   110,   110,
     211,  -100,    34,   182,   110,   182,    52,   212,   -98,    52,
     -99,   213,   214,   129,   -98,    36,   -99,    52,   -48,    37,
     171,    52,    52,   237,    64,    76,    52,   136,     1,     2,
       3,     4,     5,     6,     7,    38,     9,    70,    80,    82,
      83,    13,    43,    87,    52,    52,   173,   279,   211,    88,
      52,    13,   104,    91,    13,   212,   273,   182,    94,   213,
     214,    95,   -96,   285,    96,   276,    97,   138,   -96,    85,
     143,   257,   131,   159,   104,    98,   284,   104,   104,   104,
     139,     1,     2,     3,     4,     5,     6,     7,    38,     9,
     101,   160,    40,    41,    42,    43,    88,   169,   172,   193,
     202,   173,   174,  -106,   175,   176,   177,   178,   179,   180,
      44,   181,   182,   183,   184,   204,  -167,   233,   205,   218,
     252,   235,   102,  -116,   259,   210,   260,   274,   262,   104,
     104,    46,   272,   277,   282,   104,     1,     2,     3,     4,
       5,     6,     7,    38,     9,   101,   281,    40,    41,    42,
      43,    88,    62,   258,   275,   236,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    44,    89,   216,   173,   174,
     -54,   175,   176,   177,   178,   179,   180,   102,   181,   182,
     183,   184,   263,     0,     0,   188,    46,     1,     2,     3,
       4,     5,     6,     7,    38,     9,   101,    10,    40,    41,
      42,    43,    88,     0,     0,     0,     0,   173,   174,     0,
     175,   176,   177,   178,   179,   180,    44,   181,   182,   183,
     184,   -76,     0,     0,     0,     0,     0,     0,   102,   -46,
       0,     0,     0,     0,     0,     0,     0,    46,     1,     2,
       3,     4,     5,     6,     7,    38,     9,   101,     0,    40,
      41,    42,    43,    88,     0,     0,     0,     0,   173,   174,
       0,   175,   176,   177,   178,   179,   180,    44,   181,   182,
     183,   184,   -53,     0,     0,     0,     0,     0,     0,   102,
     219,     0,     0,     0,     0,     0,     0,     0,    46,     1,
       2,     3,     4,     5,     6,     7,    38,     9,   101,     0,
      40,    41,    42,    43,    88,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,    38,     9,    39,    44,    40,
      41,    42,    43,   -68,     0,   173,     0,     0,     0,   173,
     102,     0,     0,     0,    26,    26,   182,    44,     0,    46,
     182,   -97,    26,  -167,     0,   -95,     0,   -97,     0,    45,
       0,   -95,     0,     0,     0,    69,     0,     0,    46,     1,
       2,     3,     4,     5,     6,     7,    38,     9,    39,     0,
      40,    41,    42,    43,  -167,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,    38,     9,    39,    44,    40,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,    44,     0,    46,
     173,   174,   -35,   175,   176,   177,   178,   179,   180,    45,
     181,   182,   183,   184,     0,     0,   189,     0,    46,     1,
       2,     3,     4,     5,     6,     7,    38,     9,    39,     0,
      40,    41,    42,    43,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,    38,     9,    39,    44,    40,
      41,    42,    43,   -41,     0,   101,     0,    40,    41,    42,
      45,    88,    39,     0,    40,    41,    42,    44,     0,    46,
       0,     0,   -34,     0,     0,    44,     0,     0,     0,    45,
       0,     0,    44,     0,     0,     0,     0,   163,    46,     0,
       0,     0,     0,   113,    78,     0,    46,   114,   115,   116,
       0,     0,     0,    46,     0,   117,     0,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   113,
       0,     0,     0,   114,   115,   116,     0,     0,     0,     0,
       0,   133,     0,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   140,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,   117,     0,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   173,   174,     0,   175,   176,   177,   178,   179,   180,
       0,   181,   182,   183,   184,     0,     0,     0,     0,     0,
       0,   173,   174,   234,   175,   176,   177,   178,   179,   180,
       0,   181,   182,   183,   184,   194,   174,   265,   195,   196,
     197,   198,   199,   180,     0,   200,   201,   183,   184,   173,
     174,     0,   175,   176,   177,   178,   179,   180,     0,   181,
     182,   183,   184,   173,   174,     0,   175,   176,   177,   178,
     179,     0,     0,   181,   182,   173,   184,     0,   175,   176,
     177,   178,   179,     0,     0,   181,   182,     1,     2,     3,
       4,     5,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
      66,    22,    23,    83,    95,   144,    53,    87,    88,    30,
      45,    45,    20,   102,   139,    21,    50,    97,   107,    34,
      55,    19,    37,     0,    32,    10,    21,    19,    13,    80,
      45,    32,    30,   113,   114,   115,    42,   117,    30,    54,
      35,    36,   108,    35,    78,    80,   171,    80,    53,    41,
      85,   102,    53,   133,   105,   106,   107,    23,    73,    80,
     140,    80,    83,   202,    30,    40,    87,   102,    20,   102,
     105,   106,    35,   106,   163,    27,    35,    41,    41,    31,
      32,   102,    41,   102,   105,   106,   105,   106,   107,    50,
      51,    43,    53,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,    40,   157,   158,   188,    50,
      51,   250,   163,    35,   194,   195,   196,   197,   198,   199,
     200,   201,   157,   158,    53,   158,   206,   193,   253,   254,
     255,   256,    19,    41,    19,    35,   157,   158,   157,   158,
      20,    41,    37,    30,   163,    30,    34,    27,    35,    37,
      35,    31,    32,   233,    41,    36,    41,    45,    40,    37,
      42,    49,    50,    43,    53,    38,    54,   188,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    53,    37,    35,
      40,     0,    17,    21,    72,    73,    19,   278,    20,    18,
      78,    10,    80,    40,    13,    27,   262,    30,    40,    31,
      32,    40,    35,   283,    53,   271,    42,    38,    41,    44,
      15,    43,   233,    38,   102,    42,   282,   105,   106,   107,
      42,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    35,    14,    15,    16,    17,    18,    53,    41,    41,
      40,    19,    20,    42,    22,    23,    24,    25,    26,    27,
      32,    29,    30,    31,    32,    21,    38,    36,    35,    34,
      53,    35,    44,    35,    35,    43,    13,    35,    41,   157,
     158,    53,    41,    35,    41,   163,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    21,    14,    15,    16,
      17,    18,    36,   233,   266,   188,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    32,    63,   155,    19,    20,
      37,    22,    23,    24,    25,    26,    27,    44,    29,    30,
      31,    32,   249,    -1,    -1,    36,    53,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    44,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    32,    29,    30,    31,
      32,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    32,    29,    30,
      31,    32,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    32,    14,
      15,    16,    17,    37,    -1,    19,    -1,    -1,    -1,    19,
      44,    -1,    -1,    -1,    22,    23,    30,    32,    -1,    53,
      30,    35,    30,    38,    -1,    35,    -1,    41,    -1,    44,
      -1,    41,    -1,    -1,    -1,    43,    -1,    -1,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    32,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    53,
      19,    20,    37,    22,    23,    24,    25,    26,    27,    44,
      29,    30,    31,    32,    -1,    -1,    35,    -1,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    32,    14,
      15,    16,    17,    37,    -1,    12,    -1,    14,    15,    16,
      44,    18,    12,    -1,    14,    15,    16,    32,    -1,    53,
      -1,    -1,    37,    -1,    -1,    32,    -1,    -1,    -1,    44,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    44,    53,    -1,
      -1,    -1,    -1,    28,    44,    -1,    53,    32,    33,    34,
      -1,    -1,    -1,    53,    -1,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    28,
      -1,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    28,    -1,    -1,    -1,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    41,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    19,    20,    35,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    19,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    30,    19,    32,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,     3,     4,     5,
       6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      44,    55,    56,    57,   117,    53,    56,     0,    56,    53,
      60,    58,    40,    40,    62,    63,   117,   120,    62,    41,
      35,    53,    64,    41,    37,    62,    36,    37,    10,    12,
      14,    15,    16,    17,    32,    44,    53,    57,    66,    67,
      68,    70,    71,    74,    76,    77,    78,    82,    91,   101,
     103,   120,    64,    66,    53,    69,    95,    92,    97,   117,
      53,    66,    67,    76,    75,   104,    38,    66,    44,    67,
      37,    88,    35,    40,    66,    44,    76,    21,    18,   109,
      83,    40,    89,    88,    40,    40,    53,    42,    42,    61,
      67,    12,    44,    65,    71,    76,    84,    85,    87,    91,
     101,   109,   120,    28,    32,    33,    34,    40,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    71,    72,   111,
     118,   120,    76,    40,   110,   111,   120,   111,    38,    42,
      28,   100,   111,    15,    93,    53,   103,   105,    79,   111,
      50,    51,    53,   112,   119,    86,    65,    76,    84,    38,
      35,    65,    65,    44,    84,    88,   111,   111,   111,    53,
     111,    42,    41,    19,    20,    22,    23,    24,    25,    26,
      27,    29,    30,    31,    32,    73,   111,   102,    36,    35,
      59,   112,   111,    41,    19,    22,    23,    24,    25,    26,
      29,    30,    40,   100,    21,    35,    21,    35,    36,    80,
      43,    20,    27,    31,    32,    43,    89,    84,    34,    41,
     112,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,    36,    41,    35,   110,    43,    88,   111,
     111,   111,   111,   111,   111,   111,   111,   100,    94,   106,
      98,   111,    53,   116,   114,   113,   115,    43,    72,    35,
      13,    96,    41,   119,   100,    35,    81,   112,   112,   112,
     112,    90,    41,    88,    35,    80,    88,    35,    99,   103,
     107,    21,    41,   108,    88,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    58,    59,    57,    60,
      61,    57,    62,    62,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    68,
      68,    70,    68,    71,    73,    72,    72,    72,    74,    75,
      74,    76,    76,    76,    76,    77,    77,    77,    79,    78,
      81,    80,    80,    80,    83,    82,    84,    84,    84,    84,
      85,    85,    85,    86,    85,    85,    87,    85,    88,    89,
      90,    89,    89,    92,    93,    94,    91,    95,    96,    91,
      97,    98,    99,    91,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   102,   101,   103,   104,   103,   103,   106,
     105,   108,   107,   109,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   113,
     112,   114,   112,   115,   112,   116,   112,   112,   112,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     0,     0,    11,     0,
       0,    10,     3,     1,     1,     2,     3,     1,     2,     2,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     0,     3,
       1,     0,     2,     4,     0,     4,     1,     1,     1,     0,
       5,     2,     1,     2,     1,     1,     1,     1,     0,     5,
       0,     4,     1,     3,     0,     7,     2,     1,     2,     1,
       2,     1,     1,     0,     3,     1,     0,     2,     3,     4,
       0,     7,     0,     0,     0,     0,     8,     0,     0,     9,
       0,     0,     0,    12,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     0,     5,     1,     0,     5,     2,     0,
       4,     0,     4,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     3,     3,     2,     4,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
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
#line 161 "parser.y"
               {head = (yyvsp[0].node);}
#line 1854 "y.tab.c"
    break;

  case 3:
#line 164 "parser.y"
                          {(yyval.node) = mknode("",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1860 "y.tab.c"
    break;

  case 4:
#line 165 "parser.y"
                         { (yyval.node) = mknode("",(yyvsp[0].node), NULL);}
#line 1866 "y.tab.c"
    break;

  case 5:
#line 166 "parser.y"
                     {(yyval.node) = mknode("",(yyvsp[0].node), NULL);}
#line 1872 "y.tab.c"
    break;

  case 6:
#line 172 "parser.y"
                            {add('F');}
#line 1878 "y.tab.c"
    break;

  case 7:
#line 172 "parser.y"
                                                                                                                                                   {endScope();}
#line 1884 "y.tab.c"
    break;

  case 8:
#line 173 "parser.y"
           {
 			 (yyval.node)=mknode("FUNC",mknode((yyvsp[-9].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[-6].node), NULL) ,mknode("RET",(yyvsp[-10].node), NULL))) ,mknode("BODY",(yyvsp[-3].node),(yyvsp[-2].node)));
	   }
#line 1892 "y.tab.c"
    break;

  case 9:
#line 177 "parser.y"
                            {add('F');}
#line 1898 "y.tab.c"
    break;

  case 10:
#line 177 "parser.y"
                                                                                                                                             {endScope();}
#line 1904 "y.tab.c"
    break;

  case 11:
#line 178 "parser.y"
                {
			 (yyval.node)=mknode("FUNC", mknode((yyvsp[-8].str),mknode("\n",NULL,NULL), mknode("",mknode("ARGS",(yyvsp[-5].node), NULL) ,mknode("RET VOID",NULL, NULL))), mknode("BODY",(yyvsp[-2].node),NULL));
		}
#line 1912 "y.tab.c"
    break;

  case 12:
#line 184 "parser.y"
                                             {(yyval.node)=mknode("",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1918 "y.tab.c"
    break;

  case 13:
#line 185 "parser.y"
                    {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1924 "y.tab.c"
    break;

  case 14:
#line 186 "parser.y"
                  {(yyval.node)=mknode("NONE)\n",(yyvsp[0].node),NULL);}
#line 1930 "y.tab.c"
    break;

  case 15:
#line 189 "parser.y"
                            {(yyval.node)=mknode("ARGS-TYPE",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1936 "y.tab.c"
    break;

  case 16:
#line 192 "parser.y"
                                         {add_to_param_count(); (yyval.node)=mknode((yyvsp[-2].str),(yyvsp[0].node),NULL);}
#line 1942 "y.tab.c"
    break;

  case 17:
#line 193 "parser.y"
                      {add_to_param_count(); (yyval.node)=mknode((yyvsp[0].str),mknode(")",NULL,NULL),NULL);}
#line 1948 "y.tab.c"
    break;

  case 18:
#line 197 "parser.y"
                                   {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1954 "y.tab.c"
    break;

  case 19:
#line 198 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1960 "y.tab.c"
    break;

  case 20:
#line 199 "parser.y"
                              {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1966 "y.tab.c"
    break;

  case 21:
#line 200 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1972 "y.tab.c"
    break;

  case 22:
#line 201 "parser.y"
                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1978 "y.tab.c"
    break;

  case 23:
#line 202 "parser.y"
                        {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 1984 "y.tab.c"
    break;

  case 24:
#line 203 "parser.y"
                   {(yyval.node)=NULL;}
#line 1990 "y.tab.c"
    break;

  case 25:
#line 207 "parser.y"
                                        {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1996 "y.tab.c"
    break;

  case 26:
#line 208 "parser.y"
                                          {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2002 "y.tab.c"
    break;

  case 27:
#line 209 "parser.y"
                               {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 2008 "y.tab.c"
    break;

  case 28:
#line 210 "parser.y"
                                {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2014 "y.tab.c"
    break;

  case 29:
#line 211 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2020 "y.tab.c"
    break;

  case 30:
#line 212 "parser.y"
                             {(yyval.node)=mknode("",(yyvsp[0].node), NULL);}
#line 2026 "y.tab.c"
    break;

  case 31:
#line 213 "parser.y"
                   {(yyval.node)=NULL;}
#line 2032 "y.tab.c"
    break;

  case 32:
#line 217 "parser.y"
                                                 {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2038 "y.tab.c"
    break;

  case 33:
#line 218 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2044 "y.tab.c"
    break;

  case 34:
#line 219 "parser.y"
                                                 {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2050 "y.tab.c"
    break;

  case 35:
#line 220 "parser.y"
                          {(yyval.node)=NULL;}
#line 2056 "y.tab.c"
    break;

  case 36:
#line 224 "parser.y"
                                          {(yyval.node)=mknode("",(yyvsp[-1].node2)->node, NULL);}
#line 2062 "y.tab.c"
    break;

  case 37:
#line 225 "parser.y"
                                  {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2068 "y.tab.c"
    break;

  case 38:
#line 226 "parser.y"
                {add('K');}
#line 2074 "y.tab.c"
    break;

  case 39:
#line 226 "parser.y"
                                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2080 "y.tab.c"
    break;

  case 40:
#line 227 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2086 "y.tab.c"
    break;

  case 41:
#line 228 "parser.y"
             {add('B');}
#line 2092 "y.tab.c"
    break;

  case 42:
#line 228 "parser.y"
                                   { (yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2098 "y.tab.c"
    break;

  case 43:
#line 231 "parser.y"
                                                                                         { func_call_gen(); check_param_list();  (yyval.node2)=mknode2("FUNCTION_CALL",(yyvsp[-3].node2)->node,(yyvsp[-1].node), (yyvsp[-3].node2)->type);}
#line 2104 "y.tab.c"
    break;

  case 44:
#line 235 "parser.y"
                      { add_to_current_param_list();}
#line 2110 "y.tab.c"
    break;

  case 45:
#line 235 "parser.y"
                                                                                  { (yyval.node)=mknode("",(yyvsp[-3].node2)->node, (yyvsp[0].node));}
#line 2116 "y.tab.c"
    break;

  case 46:
#line 236 "parser.y"
                      { add_to_current_param_list(); (yyval.node)=mknode("",(yyvsp[0].node2)->node, NULL);}
#line 2122 "y.tab.c"
    break;

  case 47:
#line 237 "parser.y"
                          {(yyval.node)=mknode("", (yyvsp[0].node), NULL);}
#line 2128 "y.tab.c"
    break;

  case 48:
#line 241 "parser.y"
                        {push((yyvsp[0].str)); check_declaration((yyvsp[0].str)); set_param_count((yyvsp[0].str)); (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 1));}
#line 2134 "y.tab.c"
    break;

  case 49:
#line 242 "parser.y"
                       {push((yyvsp[0].str)); check_declaration((yyvsp[0].str)); set_param_count((yyvsp[0].str)); }
#line 2140 "y.tab.c"
    break;

  case 50:
#line 242 "parser.y"
                                                                                                                            {(yyval.node2)=mknode2((yyvsp[-4].str),(yyvsp[-1].node2)->node,NULL, get_type((yyvsp[-4].str), 1));}
#line 2146 "y.tab.c"
    break;

  case 51:
#line 248 "parser.y"
                                             {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2152 "y.tab.c"
    break;

  case 52:
#line 249 "parser.y"
                              {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2158 "y.tab.c"
    break;

  case 53:
#line 250 "parser.y"
                                              {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2164 "y.tab.c"
    break;

  case 54:
#line 251 "parser.y"
                          {(yyval.node)=NULL;}
#line 2170 "y.tab.c"
    break;

  case 55:
#line 255 "parser.y"
                      { (yyval.node) = mknode("",(yyvsp[0].node), NULL); }
#line 2176 "y.tab.c"
    break;

  case 56:
#line 256 "parser.y"
                                  {(yyval.node) = mknode("",(yyvsp[0].node), NULL); }
#line 2182 "y.tab.c"
    break;

  case 57:
#line 257 "parser.y"
                          {(yyval.node) = mknode("STRING",(yyvsp[0].node), NULL); }
#line 2188 "y.tab.c"
    break;

  case 58:
#line 261 "parser.y"
                                 {add('V');}
#line 2194 "y.tab.c"
    break;

  case 59:
#line 262 "parser.y"
          {	
		  check_declaration_type(type, (yyvsp[0].node2)->type);
		  (yyval.node) = mknode("VAR",(yyvsp[-3].node), mknode((yyvsp[-2].str), (yyvsp[0].node2)->node, NULL));
	  }
#line 2203 "y.tab.c"
    break;

  case 60:
#line 269 "parser.y"
                           {add('V');}
#line 2209 "y.tab.c"
    break;

  case 61:
#line 269 "parser.y"
                                                {(yyval.node2)=mknode2((yyvsp[-2].str), (yyvsp[0].node2)->node, NULL, "NONE");}
#line 2215 "y.tab.c"
    break;

  case 62:
#line 270 "parser.y"
                    {(yyval.node2)=mknode2("",NULL, NULL, "NONE");}
#line 2221 "y.tab.c"
    break;

  case 63:
#line 272 "parser.y"
        {	
		
		(yyval.node2)=mknode2("",(yyvsp[-1].node2)->node,NULL, (yyvsp[-1].node2)->type); 
	}
#line 2230 "y.tab.c"
    break;

  case 64:
#line 278 "parser.y"
                                 {insert_type("STR"); add('V');}
#line 2236 "y.tab.c"
    break;

  case 65:
#line 278 "parser.y"
                                                                                                                             {(yyval.node)=mknode((yyvsp[-5].str),(yyvsp[-2].node),NULL);}
#line 2242 "y.tab.c"
    break;

  case 66:
#line 287 "parser.y"
                                       {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2248 "y.tab.c"
    break;

  case 67:
#line 288 "parser.y"
                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2254 "y.tab.c"
    break;

  case 68:
#line 289 "parser.y"
                                           {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2260 "y.tab.c"
    break;

  case 69:
#line 290 "parser.y"
                          {(yyval.node)=NULL;}
#line 2266 "y.tab.c"
    break;

  case 70:
#line 294 "parser.y"
                                     {(yyval.node)=mknode("",(yyvsp[-1].node2)->node, NULL);}
#line 2272 "y.tab.c"
    break;

  case 71:
#line 295 "parser.y"
                                    {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2278 "y.tab.c"
    break;

  case 72:
#line 296 "parser.y"
                     {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2284 "y.tab.c"
    break;

  case 73:
#line 297 "parser.y"
                {add('K');}
#line 2290 "y.tab.c"
    break;

  case 74:
#line 297 "parser.y"
                                       {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2296 "y.tab.c"
    break;

  case 75:
#line 298 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2302 "y.tab.c"
    break;

  case 76:
#line 299 "parser.y"
             {add('B');}
#line 2308 "y.tab.c"
    break;

  case 77:
#line 299 "parser.y"
                                    {(yyval.node)=mknode("CODE_BLOCK",(yyvsp[0].node),NULL);}
#line 2314 "y.tab.c"
    break;

  case 78:
#line 302 "parser.y"
                                                      {endScope(); (yyval.node)=mknode("CODE_BLOCK",(yyvsp[-1].node),NULL);}
#line 2320 "y.tab.c"
    break;

  case 79:
#line 305 "parser.y"
                                                                     {if_label_rep(); (yyval.node)=mknode("IF",(yyvsp[-2].node2)->node,(yyvsp[0].node));}
#line 2326 "y.tab.c"
    break;

  case 80:
#line 306 "parser.y"
                                                                          {if_label_rep(); add('K');}
#line 2332 "y.tab.c"
    break;

  case 81:
#line 306 "parser.y"
                                                                                                                 {if_label_else(); (yyval.node)=mknode("IF-ELSE", mknode("",(yyvsp[-5].node2)->node,(yyvsp[-3].node)), mknode("",(yyvsp[0].node),NULL));}
#line 2338 "y.tab.c"
    break;

  case 82:
#line 307 "parser.y"
         {if_label_else();}
#line 2344 "y.tab.c"
    break;

  case 83:
#line 311 "parser.y"
                {add('K');}
#line 2350 "y.tab.c"
    break;

  case 84:
#line 311 "parser.y"
                                              {while_start();}
#line 2356 "y.tab.c"
    break;

  case 85:
#line 311 "parser.y"
                                                                         {while_rep();}
#line 2362 "y.tab.c"
    break;

  case 86:
#line 311 "parser.y"
                                                                                                                      {  (yyval.node)=mknode("WHILE",(yyvsp[-3].node2)->node,(yyvsp[0].node)); while_end();}
#line 2368 "y.tab.c"
    break;

  case 87:
#line 312 "parser.y"
             {add('K');}
#line 2374 "y.tab.c"
    break;

  case 88:
#line 312 "parser.y"
                                                                       {while_rep();}
#line 2380 "y.tab.c"
    break;

  case 89:
#line 312 "parser.y"
                                                                                                                  {  (yyval.node)=mknode("DO-WHILE",(yyvsp[-6].node),(yyvsp[-3].node2)->node); while_end();}
#line 2386 "y.tab.c"
    break;

  case 90:
#line 313 "parser.y"
              {add('K');}
#line 2392 "y.tab.c"
    break;

  case 91:
#line 313 "parser.y"
                                                           {for_inter();}
#line 2398 "y.tab.c"
    break;

  case 92:
#line 313 "parser.y"
                                                                                               {for_rep();}
#line 2404 "y.tab.c"
    break;

  case 93:
#line 313 "parser.y"
                                                                                                                                                  { (yyval.node)=mknode("FOR",mknode("INIT", (yyvsp[-8].node), mknode("COND", (yyvsp[-5].node2)->node, mknode("UPDATE",(yyvsp[-2].node), NULL))),(yyvsp[0].node));}
#line 2410 "y.tab.c"
    break;

  case 94:
#line 317 "parser.y"
                     {(yyval.node2)=mknode2("==",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2", "=="));}
#line 2416 "y.tab.c"
    break;

  case 95:
#line 318 "parser.y"
                          {(yyval.node2)=mknode2("!=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2", "!="));}
#line 2422 "y.tab.c"
    break;

  case 96:
#line 319 "parser.y"
                       {(yyval.node2)=mknode2("<",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", "<"));}
#line 2428 "y.tab.c"
    break;

  case 97:
#line 320 "parser.y"
                           {(yyval.node2)=mknode2("<=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", "<="));}
#line 2434 "y.tab.c"
    break;

  case 98:
#line 321 "parser.y"
                           {(yyval.node2)=mknode2(">",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", ">"));}
#line 2440 "y.tab.c"
    break;

  case 99:
#line 322 "parser.y"
                              {(yyval.node2)=mknode2(">=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", ">="));}
#line 2446 "y.tab.c"
    break;

  case 100:
#line 323 "parser.y"
                 {(yyval.node2)=mknode2("||",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log", "||"));}
#line 2452 "y.tab.c"
    break;

  case 101:
#line 324 "parser.y"
                       {(yyval.node2)=mknode2("&&",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log", "&&"));}
#line 2458 "y.tab.c"
    break;

  case 102:
#line 325 "parser.y"
                 {(yyval.node2)=mknode2("!",(yyvsp[0].node2)->node,NULL, check_alg_expr("NONE", (yyvsp[0].node2)->type, "not", "!"));}
#line 2464 "y.tab.c"
    break;

  case 103:
#line 329 "parser.y"
                                                  {codegen_assign();}
#line 2470 "y.tab.c"
    break;

  case 104:
#line 329 "parser.y"
                                                                                {check_declaration_type((yyvsp[-4].node2)->type, (yyvsp[-2].node2)->type); (yyval.node)=mknode("=",(yyvsp[-4].node2)->node,(yyvsp[-2].node2)->node); }
#line 2476 "y.tab.c"
    break;

  case 105:
#line 332 "parser.y"
                        {push((yyvsp[0].str)); check_declaration((yyvsp[0].str)); (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 0));}
#line 2482 "y.tab.c"
    break;

  case 106:
#line 333 "parser.y"
                       {push((yyvsp[0].str)); check_declaration((yyvsp[0].str));}
#line 2488 "y.tab.c"
    break;

  case 107:
#line 333 "parser.y"
                                                                                                            {(yyval.node2)=mknode2((yyvsp[-4].str),(yyvsp[-1].node),NULL, get_type((yyvsp[-4].str), 0));}
#line 2494 "y.tab.c"
    break;

  case 108:
#line 334 "parser.y"
                                 {push((yyvsp[-1].str)); check_declaration((yyvsp[0].str)); (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 3));}
#line 2500 "y.tab.c"
    break;

  case 109:
#line 337 "parser.y"
                      {push((yyvsp[0].str));}
#line 2506 "y.tab.c"
    break;

  case 110:
#line 337 "parser.y"
                                                  { (yyval.node)=mknode("=",(yyvsp[-3].node2)->node,(yyvsp[0].node));}
#line 2512 "y.tab.c"
    break;

  case 111:
#line 339 "parser.y"
                       {push((yyvsp[0].str));}
#line 2518 "y.tab.c"
    break;

  case 112:
#line 339 "parser.y"
                                       {(yyval.node)=mknode("=",(yyvsp[-3].node2)->node,(yyvsp[0].node2)->node);}
#line 2524 "y.tab.c"
    break;

  case 113:
#line 341 "parser.y"
                             {check_return_type((yyvsp[-1].node2)->type); (yyval.node)=mknode("RET-VAL",(yyvsp[-1].node2)->node,NULL);}
#line 2530 "y.tab.c"
    break;

  case 114:
#line 346 "parser.y"
                         {(yyval.node2)=mknode2("",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, "exp");}
#line 2536 "y.tab.c"
    break;

  case 115:
#line 347 "parser.y"
       {(yyval.node2)=mknode2("",(yyvsp[0].node2)->node,NULL, (yyvsp[0].node2)->type); }
#line 2542 "y.tab.c"
    break;

  case 116:
#line 348 "parser.y"
                                            {(yyval.node2)=mknode2("exp",(yyvsp[-1].node2)->node,NULL, (yyvsp[-1].node2)->type);}
#line 2548 "y.tab.c"
    break;

  case 117:
#line 349 "parser.y"
           {(yyval.node2)=mknode2("",(yyvsp[0].node),NULL, "NONE");}
#line 2554 "y.tab.c"
    break;

  case 118:
#line 353 "parser.y"
                        {(yyval.node2)=mknode2("+",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node, check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg",  "+"));}
#line 2560 "y.tab.c"
    break;

  case 119:
#line 354 "parser.y"
                        {(yyval.node2)=mknode2("-",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg", "-"));}
#line 2566 "y.tab.c"
    break;

  case 120:
#line 355 "parser.y"
                            {(yyval.node2)=mknode2("*",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg", "*"));}
#line 2572 "y.tab.c"
    break;

  case 121:
#line 356 "parser.y"
                            {(yyval.node2)=mknode2("/",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "alg", "/"));}
#line 2578 "y.tab.c"
    break;

  case 122:
#line 357 "parser.y"
                        {(yyval.node2)=mknode2("==",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2", "=="));}
#line 2584 "y.tab.c"
    break;

  case 123:
#line 358 "parser.y"
                           {(yyval.node2)=mknode2("!=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log2","!=" ));}
#line 2590 "y.tab.c"
    break;

  case 124:
#line 359 "parser.y"
                        {(yyval.node2)=mknode2("<",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", "<="));}
#line 2596 "y.tab.c"
    break;

  case 125:
#line 360 "parser.y"
                            {(yyval.node2)=mknode2("<=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3",">"));}
#line 2602 "y.tab.c"
    break;

  case 126:
#line 361 "parser.y"
                           {(yyval.node2)=mknode2(">",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", ">"));}
#line 2608 "y.tab.c"
    break;

  case 127:
#line 362 "parser.y"
                               {(yyval.node2)=mknode2(">=",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log3", ">="));}
#line 2614 "y.tab.c"
    break;

  case 128:
#line 363 "parser.y"
                  {(yyval.node2)=mknode2("||",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log", "||"));}
#line 2620 "y.tab.c"
    break;

  case 129:
#line 364 "parser.y"
                       {(yyval.node2)=mknode2("&&",(yyvsp[-2].node2)->node,(yyvsp[0].node2)->node,  check_alg_expr((yyvsp[-2].node2)->type, (yyvsp[0].node2)->type, "log", "&&"));}
#line 2626 "y.tab.c"
    break;

  case 130:
#line 365 "parser.y"
                  {(yyval.node2)=mknode2("!",(yyvsp[0].node2)->node,NULL, check_alg_expr("NONE", (yyvsp[0].node2)->type, "not", "!"));}
#line 2632 "y.tab.c"
    break;

  case 131:
#line 366 "parser.y"
                      {push((yyvsp[0].str)); check_declaration((yyvsp[0].str));  (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, get_type((yyvsp[0].str), 0));}
#line 2638 "y.tab.c"
    break;

  case 132:
#line 367 "parser.y"
                        {(yyval.node2)=mknode2("",(yyvsp[0].node2)->node, NULL, (yyvsp[0].node2)->type);}
#line 2644 "y.tab.c"
    break;

  case 133:
#line 368 "parser.y"
                        { (yyval.node2)=mknode2("function_call",(yyvsp[0].node2)->node,NULL, (yyvsp[0].node2)->type);}
#line 2650 "y.tab.c"
    break;

  case 134:
#line 369 "parser.y"
                                    {(yyval.node2)=mknode2((yyvsp[-1].str),NULL,NULL, "INT");}
#line 2656 "y.tab.c"
    break;

  case 135:
#line 370 "parser.y"
                                                   {(yyval.node2)=mknode2("exp",(yyvsp[-1].node2)->node,NULL, (yyvsp[-1].node2)->type);}
#line 2662 "y.tab.c"
    break;

  case 136:
#line 371 "parser.y"
                      {(yyval.node2)=mknode2("ADDRESS-OF", (yyvsp[0].node2)->node, NULL,  get_type((yyvsp[0].node2)->type, 4));}
#line 2668 "y.tab.c"
    break;

  case 137:
#line 372 "parser.y"
                                                                        {check_declaration((yyvsp[-2].str)); (yyval.node2)=mknode2("ADDRESS-OF",mknode((yyvsp[-3].str),(yyvsp[-1].node),NULL),NULL, get_type((yyvsp[-3].str), 0));}
#line 2674 "y.tab.c"
    break;

  case 138:
#line 373 "parser.y"
                       {(yyval.node2)=mknode2("POINTER-OF", (yyvsp[0].node2)->node,NULL, get_type((yyvsp[0].node2)->type, 3));}
#line 2680 "y.tab.c"
    break;

  case 139:
#line 377 "parser.y"
                          {push((yyvsp[0].str));}
#line 2686 "y.tab.c"
    break;

  case 140:
#line 377 "parser.y"
                                                 {(yyval.node)=mknode("+",(yyvsp[-3].node),(yyvsp[0].node));}
#line 2692 "y.tab.c"
    break;

  case 141:
#line 378 "parser.y"
                           {push((yyvsp[0].str));}
#line 2698 "y.tab.c"
    break;

  case 142:
#line 378 "parser.y"
                                                  {(yyval.node)=mknode("-",(yyvsp[-3].node),(yyvsp[0].node));}
#line 2704 "y.tab.c"
    break;

  case 143:
#line 379 "parser.y"
                              {push((yyvsp[0].str));}
#line 2710 "y.tab.c"
    break;

  case 144:
#line 379 "parser.y"
                                                     {(yyval.node)=mknode("*",(yyvsp[-3].node),(yyvsp[0].node));}
#line 2716 "y.tab.c"
    break;

  case 145:
#line 380 "parser.y"
                              {push((yyvsp[0].str));}
#line 2722 "y.tab.c"
    break;

  case 146:
#line 380 "parser.y"
                                                     {(yyval.node)=mknode("/",(yyvsp[-3].node),(yyvsp[0].node));}
#line 2728 "y.tab.c"
    break;

  case 147:
#line 381 "parser.y"
                          {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 2734 "y.tab.c"
    break;

  case 148:
#line 382 "parser.y"
                        {{push((yyvsp[0].str));} (yyval.node)=mknode((yyvsp[0].str),NULL,NULL);}
#line 2740 "y.tab.c"
    break;

  case 149:
#line 387 "parser.y"
               { insert_type("BOOL"); (yyval.node)=mknode("BOOL",NULL,NULL);}
#line 2746 "y.tab.c"
    break;

  case 150:
#line 388 "parser.y"
               {(yyval.node)=mknode("CHAR",NULL,NULL); insert_type("CHAR");}
#line 2752 "y.tab.c"
    break;

  case 151:
#line 389 "parser.y"
                 {(yyval.node)=mknode("CHAR_P",NULL,NULL); insert_type("CHAR_P");}
#line 2758 "y.tab.c"
    break;

  case 152:
#line 390 "parser.y"
              { insert_type("INT"); (yyval.node)=mknode("INT",NULL,NULL);}
#line 2764 "y.tab.c"
    break;

  case 153:
#line 391 "parser.y"
                {(yyval.node)=mknode("INT_P",NULL,NULL); insert_type("INT_P");}
#line 2770 "y.tab.c"
    break;

  case 154:
#line 392 "parser.y"
               {(yyval.node)=mknode("REAL",NULL,NULL); insert_type("REAL");}
#line 2776 "y.tab.c"
    break;

  case 155:
#line 393 "parser.y"
                 {(yyval.node)=mknode("REAL_P",NULL,NULL); insert_type("REAL_P");}
#line 2782 "y.tab.c"
    break;

  case 156:
#line 394 "parser.y"
                 {(yyval.node)=mknode("STRING",NULL,NULL); insert_type("STRING");}
#line 2788 "y.tab.c"
    break;

  case 157:
#line 399 "parser.y"
         {	
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2("None",NULL,NULL, "None");
		  add('C');
	 }
#line 2798 "y.tab.c"
    break;

  case 158:
#line 405 "parser.y"
         {	
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2("True",NULL,NULL, "BOOL");
		 add('C');
	  }
#line 2808 "y.tab.c"
    break;

  case 159:
#line 411 "parser.y"
          {
		  push((yyvsp[0].str));
		 (yyval.node2)=mknode2("False",NULL,NULL, "BOOL"); 
		 add('C'); 
	  }
#line 2818 "y.tab.c"
    break;

  case 160:
#line 417 "parser.y"
         {
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "CHAR");
		  add('C');
	 }
#line 2828 "y.tab.c"
    break;

  case 161:
#line 423 "parser.y"
         {
		 push((yyvsp[0].str));
		(yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "INT"); 
		add('C');
	 }
#line 2838 "y.tab.c"
    break;

  case 162:
#line 429 "parser.y"
         {
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "REAL");
		  add('C');
	 }
#line 2848 "y.tab.c"
    break;

  case 163:
#line 435 "parser.y"
         {
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "REAL");
		  add('C');
	 }
#line 2858 "y.tab.c"
    break;

  case 164:
#line 441 "parser.y"
         {
		 push((yyvsp[0].str));
		 (yyval.node2)=mknode2((yyvsp[0].str),NULL,NULL, "STR");
		  add('C');
	 }
#line 2868 "y.tab.c"
    break;

  case 165:
#line 449 "parser.y"
                            { push((yyvsp[0].str));(yyval.node)=mknode((yyvsp[0].str),NULL,NULL); add('C');}
#line 2874 "y.tab.c"
    break;

  case 166:
#line 450 "parser.y"
                       { push((yyvsp[0].str));(yyval.node)=mknode((yyvsp[0].str),NULL,NULL); add('C');}
#line 2880 "y.tab.c"
    break;

  case 167:
#line 453 "parser.y"
          {(yyval.node)=NULL;}
#line 2886 "y.tab.c"
    break;


#line 2890 "y.tab.c"

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
#line 455 "parser.y"


int main() {
   set_current_scope("global", 0);
   f1=fopen("output","w");
   if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		printf("\nParsing failed\n");
		exit(0);
	}
	
	fclose(f1);

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

/*TAC Section start*/
void func_start() {
	fprintf(f1,"%s:\n\tBeginFunc\n", yytext); 
}

void func_end() {
	fprintf(f1,"\tEndFunc\n"); 
}

void while_start() {
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"L%d:",lnum);
	lnum++;
 	fprintf(f1,"\tif( not ");
}

void while_end() {
	int x,y;	
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\tgoto L%d\n",x);
	fprintf(f1,"L%d:",y);
	top--;
}

void while_rep()
{
	
 	fprintf(f1,")\tgoto L%d\n",lnum);
 	label[++ltop]=lnum;
}

void for_start()
{
	lnum++;
	fprintf(f1,"L%d:",lnum);
}

void for_inter()
{
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"L%d:",lnum);
}

void for_rep()
{
	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto L%d\n",lnum);
 	label[++ltop]=lnum;
}

void if_label_start()
{
 	lnum++;
 	fprintf(f1,"\tif( not");
 	
}

void if_label_rep()
{	
	fprintf(f1,"\tgoto L%d\n",lnum);
 	label[++ltop]=lnum;
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\tgoto L%d\n",lnum);
	fprintf(f1,"L%d:",x); 
	label[++ltop]=lnum;
}

void if_label_else()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"L%d:",y);
	top--;
}

void push(char * str)
{	
	printf("inPush Top %d StackTop %s YYTEXT %s\n", top, st[top], str);
  	strcpy(st[++top],str);
}


void func_call_gen() {
	function_call_tac = 1;
	ind = 0;
	sprintf(temp_var,"t%d",ind); 
	fprintf(f1,"\t%s=%s\n",temp_var,st[top]);
	fprintf(f1,"\tPushParam %s: \n",temp_var);
	ind++;
	top--;
	sprintf(temp_var,"t%d",ind); 
	fprintf(f1,"\t%s = LCall %s: \n", temp_var,st[top]);
	top--;
	fprintf(f1,"\tPopParams %d: \n",4);

}

void logical_gen(char * op)
{
	function_call_tac = 1;
 	sprintf(temp_var,"t%d",ind);
  	fprintf(f1,"%s%s%s",st[top-1],op,st[top]);
  	top-=2;
 	strcpy(st[top],temp_var);
 	ind++;
}

void algebric_gen(char * op)
{
	function_call_tac = 1;
	ind++;	
 	sprintf(temp_var,"t%d",ind);
  	fprintf(f1,"\t%s=%s%s%s\n",temp_var,st[top-1],op,st[top]);
  	top-=2;
 	strcpy(st[top],temp_var);
 	ind++;
}

void codegen_assign()
{
		printf("inCode assign %d %s %s\n", top, st[top], st[top-1]);
		sprintf(temp_var,"t%d",ind);
	if(function_call_tac == 0){
		fprintf(f1,"\t%s=%s\n",temp_var,st[top]);
		fprintf(f1,"\t%s=%s\n",st[top-1],temp_var);
		top-=2;
	}else{
		fprintf(f1,"\t%s=%s\n",st[top],temp_var);
		function_call_tac = 0;
		top-=1;
	}
	
}
/*3 Section end*/

/* SEMANTIC START  */
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
	if(strcmp(func_datatype, value) != 0){
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", count_line+1);
		sem_errors++;
	}
}


char *get_type(const char *var, int is_func){
		for(int j = 0; j <= count_scope_stack_elements; j++){
		int temp = scopeStack[j].last_index;
			for(int i=0; i < temp; i++) {
				if(strcmp(scopeStack[j].symbol_table[i].id_name, var)== 0){
					if(is_func == 3){
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "INT_P")== 0){
								return "INT";
						}
							
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "REAL_P")== 0){
								return "REAL";
						}	
							
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "CHAR_P")== 0) {
								return "CHAR";
						}
						
					}
					else if(is_func == 4) {
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "INT")== 0){
								return "INT_P";
						}
							
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "REAL")== 0){
								return "REAL_P";
						}	
							
						if(strcmp(scopeStack[j].symbol_table[i].data_type, "CHAR")== 0) {
								return "CHAR_P";
						}
					}
					else{
						return scopeStack[j].symbol_table[i].data_type;
					}
				}
			
			}
		}
	return "NONE";
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

char* check_alg_expr(char * type1, char * type2, char * op, char * operator) {
	int temp = check_types(type1, type2);
	if(strcmp(op, "alg") == 0){
		algebric_gen(operator);
		if( temp == 7)
			return "INT";
		else if(temp == 1 || temp == 2 || temp == 8)
			return "REAL";
	}else if(strcmp(op, "log")== 0){
		logical_gen(operator);
		if(temp == 9)
			return "BOOL";	
	}else if(strcmp(op, "log3")== 0){
		logical_gen(operator);
		if(temp == 1 || temp == 2 || temp==7 || temp == 8)
			return "BOOL";	
	}else if(strcmp(op, "log2")== 0){
		logical_gen(operator);
		if(strcmp(type1, type2)==0)
			return "BOOL";	
	}else if(strcmp(op, "not")== 0){
		logical_gen(operator);
		if(strcmp(type2,"BOOL")==0)
			return "BOOL";
	}else{
		
	}

	sprintf(errors[sem_errors], "Line %d: TYPE CASTING ERROR \n", count_line+1);
	sem_errors++;
	return "EROR";
}


void check_declaration_type(char *type1, char *type2) {
	int temp = check_types(type1, type2);

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

			if(strcmp(yytext, "for")==0) {
				for_start();
			}

			if(strcmp(yytext, "if")==0) {
				if_label_start(); 
			}

			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup(yytext);
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup("N/A");
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Keyword\t");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
			count_line++;
			set_current_scope(yytext, 0);
		}

		else if(c == 'B') {
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].id_name=strdup("Block");
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].data_type=strdup("N/A");
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].line_no=count_line;
			scopeStack[current_scope_stack_top].symbol_table[count_symbol_table_line].type=strdup("Keyword\t");
			count_symbol_table_line++;
			scopeStack[current_scope_stack_top].last_index = count_symbol_table_line;
			count_line++;
			set_current_scope("Block", 0);
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

			
			func_start();
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

	if(scopeStack[current_scope_stack_top].is_function == 1){
		func_end();
	}
	current_scope_stack_top = scopeStack[current_scope_stack_top].parent;
	count_symbol_table_line = scopeStack[current_scope_stack_top].last_index;
}


/* SEMANTIC END  */


/* AST  START*/
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

/* AST END  */

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
