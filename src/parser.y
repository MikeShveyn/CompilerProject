%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	int yylex();
	int yyerror(char *eror);
%}

%union
{
    char *str;
}

// TYPES 
%token<str> BOOL CHAR CHAR_P INT INT_P REAL REAL_P STRING VOID
// STATMENTS
%token<str> IF ELSE DO WHILE FOR VAR RETURN
// OPERATORS
%token<str> AND DIVISION ASSIGNMENT EQL GREATER GREATER_EQL LESS LESS_EQL MINUS NOT NOT_EQL OR PLUS MULTIPLY ADDRESS
// SYNTAX
%token<str> LENGTH SEMICOLON COLON COMMA OPEN_CURLY_BRACES CLOSE_CURLY_BRACES OPEN_ANGLE_BRACES CLOSE_ANGLE_BRACES OPEN_SQUARE_BRACES CLOSE_SQUARE_BRACES
// LITERALS
%token<str> COMMENT NONE BOOL_TRUE BOOL_FALSE  CHAR_LITERAL STRING_LITERAL DECIMAL_LITERAL HEX_LITERAL REAL_LITERAL  VARIABLE_ID


%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 

%%
s: function {printf("Ok\n");}
function : returnType VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES ;
returnType : type | VOID ;
type : BOOL | CHAR | CHAR_P | INT | INT_P | REAL | REAL_P | STRING ;
parameter_list : argument SEMICOLON parameter_list | argument | nothing ;
argument : type atributeList ;
atributeList : VARIABLE_ID COMMA atributeList | VARIABLE_ID ;
nothing : ;
body : nested_declarations nested_statments | nested_declarations | nested_statments | nothing ;
nested_declarations : declaration nested_declarations| declaration ;
declaration : function | variable_declaration ;
variable_declaration : VAR type variableL ;
variableL : VARIABLE_ID COMMA variableL| VARIABLE_ID ASSIGNMENT exp  COMMA variableL | VARIABLE_ID ASSIGNMENT exp SEMICOLON | VARIABLE_ID SEMICOLON ; 
nested_statments : statment nested_statments | statment ;
statment: function_call SEMICOLON | assignment_statement SEMICOLON | RETURN SEMICOLON | conditions | code_block ;
code_block:
conditions:
assignment_statement: lhs  ASSIGNMENT expressions | VARIABLE_ID  ASSIGNMENT STRING_LITERAL ;
lhs: VARIABLE_ID | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES |
function_call: VARIABLE_ID OPEN_ANGLE_BRACES expressions  CLOSE_ANGLE_BRACES ;
expressions : exp COMMA expressions | exp | nothing ;
exp : 
	  exp PLUS exp            			
	| exp MINUS exp               				
	| exp MULTIPLY exp								
	| exp DIVISION exp															
	| exp EQL exp							
	| exp NOT_EQL exp							
	| exp LESS exp									
	| exp LESS_EQL exp								
	| exp GREATER exp								
	| exp GREATER_EQL exp
    | exp OR exp
	| exp AND exp												
	| primitiveType											
	| VARIABLE_ID											
	| function_call							
	| LENGTH VARIABLE_ID LENGTH											
	| OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES																
	| VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES
	| ADDRESS VARIABLE_ID											
	| ADDRESS VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES									
	;

primitiveType : NONE | BOOL_TRUE | BOOL_FALSE | CHAR_LITERAL | DECIMAL_LITERAL | HEX_LITERAL| REAL_LITERAL ;

%%

int main()
{
	return yyparse();	
}

int yyerror(char *e)
{
	printf("Error\n");
	return 0;
}