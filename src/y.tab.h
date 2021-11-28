/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    FUNCTION = 274,
    AND = 275,
    DIVISION = 276,
    ASSIGNMENT = 277,
    EQL = 278,
    GREATER = 279,
    GREATER_EQL = 280,
    LESS = 281,
    LESS_EQL = 282,
    MINUS = 283,
    NOT = 284,
    NOT_EQL = 285,
    OR = 286,
    PLUS = 287,
    MULTIPLY = 288,
    ADDRESS = 289,
    LENGTH = 290,
    SEMICOLON = 291,
    COLON = 292,
    COMMA = 293,
    OPEN_CURLY_BRACES = 294,
    CLOSE_CURLY_BRACES = 295,
    OPEN_ANGLE_BRACES = 296,
    CLOSE_ANGLE_BRACES = 297,
    OPEN_SQUARE_BRACES = 298,
    CLOSE_SQUARE_BRACES = 299,
    COMMENT = 300,
    NONE = 301,
    BOOL_TRUE = 302,
    BOOL_FALSE = 303,
    CHAR_LITERAL = 304,
    STRING_LITERAL = 305,
    DECIMAL_LITERAL = 306,
    HEX_LITERAL = 307,
    REAL_LITERAL = 308,
    VARIABLE_ID = 309
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
#define FUNCTION 274
#define AND 275
#define DIVISION 276
#define ASSIGNMENT 277
#define EQL 278
#define GREATER 279
#define GREATER_EQL 280
#define LESS 281
#define LESS_EQL 282
#define MINUS 283
#define NOT 284
#define NOT_EQL 285
#define OR 286
#define PLUS 287
#define MULTIPLY 288
#define ADDRESS 289
#define LENGTH 290
#define SEMICOLON 291
#define COLON 292
#define COMMA 293
#define OPEN_CURLY_BRACES 294
#define CLOSE_CURLY_BRACES 295
#define OPEN_ANGLE_BRACES 296
#define CLOSE_ANGLE_BRACES 297
#define OPEN_SQUARE_BRACES 298
#define CLOSE_SQUARE_BRACES 299
#define COMMENT 300
#define NONE 301
#define BOOL_TRUE 302
#define BOOL_FALSE 303
#define CHAR_LITERAL 304
#define STRING_LITERAL 305
#define DECIMAL_LITERAL 306
#define HEX_LITERAL 307
#define REAL_LITERAL 308
#define VARIABLE_ID 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

    char *str;

#line 169 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
