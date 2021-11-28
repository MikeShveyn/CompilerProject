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


/*  !!! TODO ADD POINTERS AND THIK ABOUT UNARY OPERATORS  STRINGS  !!! */
/*  !!! ADD NODES AND PRINTS   !!! */

%%
s: function {printf("Ok\n");}
 /* FUNCTION  */
function :
	   type VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	 | VOID VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	 ;

parameter_list :
	   argument SEMICOLON parameter_list 
	 | argument 
	 | nothing 
	 ;

argument : type atributeList ;

atributeList :
	  VARIABLE_ID COMMA atributeList 
	| VARIABLE_ID 
	;

body : 
	  nested_declarations nested_statments 
	| nested_declarations 
	| nested_statments 
	| nothing 
	;


function_call: VARIABLE_ID OPEN_ANGLE_BRACES expressions  CLOSE_ANGLE_BRACES ;

 /* Declarations  */
nested_declarations :
	   declaration nested_declarations
	 | declaration 
	 ;

declaration :
	     function 
	   | variable_declaration 
	   ;
	   
variable_declaration : VAR type variableL ;

variableL : 
	     VARIABLE_ID COMMA variableL
	   | VARIABLE_ID ASSIGNMENT exp  COMMA variableL 
	   | VARIABLE_ID ASSIGNMENT exp SEMICOLON 
	   | VARIABLE_ID SEMICOLON 
	   ; 

/* Statments */
nested_statments : 
	     statment nested_statments 
	   | statment 
	   ;

statment: 
	     function_call SEMICOLON 
	   | assignment_statement SEMICOLON 
	   | return 
	   | conditions 
	   | loops 
	   | code_block ;

code_block:
	     OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	   | OPEN_CURLY_BRACES code_block CLOSE_CURLY_BRACES;

conditions: 
	  IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	| IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES ELSE OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	;

loops :
	  WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_ANGLE_BRACES SEMICOLON
	| DO OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON
	| FOR OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES
	;  

assignment_statement:
	   lhs  ASSIGNMENT expressions SEMICOLON
	 | lhs  ASSIGNMENT STRING_LITERAL SEMICOLON
	 ;

lhs :
	   VARIABLE_ID 
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES
	 ; 
init : INT VARIABLE_ID ASSIGNMENT DECIMAL_LITERAL | INT VARIABLE_ID ASSIGNMENT HEX_LITERAL ;
update : INT VARIABLE_ID ASSIGNMENT exp ; 
return : RETURN exp SEMICOLON;

 /* Expression */
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


 /* TYPES */
type : BOOL | CHAR | CHAR_P | INT | INT_P | REAL | REAL_P | STRING ;
primitiveType : NONE | BOOL_TRUE | BOOL_FALSE | CHAR_LITERAL | DECIMAL_LITERAL | HEX_LITERAL| REAL_LITERAL ;
nothing : ;


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