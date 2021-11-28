%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	int yylex();
	int yyerror(char *error);
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
/* HOW TO CHECK RETURN STATMENT IN VOID  */
/*  !!! ADD NODES AND PRINTS   !!! */

%%
code: function code | function  {printf("Code\n");} ;

 /* FUNCTION  */
function:
	   type VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES  {printf("Function\n");}
	 | VOID VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES  {printf("Function Void \n");}
	 ;

parameter_list:
	   argument SEMICOLON parameter_list 
	 | argument 
	 | nothing 
	 ;

argument: type atributeList ;

atributeList:
	  VARIABLE_ID COMMA atributeList 
	| VARIABLE_ID 
	;

body: 
	  nested_declarations nested_statments {printf("BODY\n");}
	| nested_declarations {printf("BODY\n");}
	| nested_statments {printf("BODY\n");}
	| nothing {printf("BODY\n");}
	;

body_func: 
 	  nested_declarations nested_statments {printf("BODY-FUNC\n");}
	| nested_declarations {printf("BODY-FUNC\n");}
	| nested_statments_func {printf("BODY-FUNC\n");}
	| nothing {printf("BODY-FUNC\n");}
	;

nested_statments_func:
	     statment_func nested_statments {printf("NESTED-STATMENT-FUNC\n");}
	   | statment_func {printf("NESTED-STATMEN-FUNCT\n");}
	   ;

statment_func:
		 function_call  {printf("STATMENT-FUNC\n");}
	   | assignment_statement   {printf("STATMENT-FUNC\n");}
	   | conditions {printf("STATMENT-FUNC\n");}
	   | loops {printf("STATMENT-FUNC\n");}
	   | code_block {printf("STATMENT-FUNC\n");}
	   ;


function_call: VARIABLE_ID OPEN_ANGLE_BRACES expressions  CLOSE_ANGLE_BRACES ;

 /* Declarations  */
nested_declarations:
	   declaration nested_declarations {printf("DECLARATION\n");}
	 | declaration {printf("DECLARATION\n");}
	 ;

declaration:
	     function 
	   | variable_declaration 
	   ;
	   
variable_declaration: VAR type variableL {printf("VAR-DECLARATION\n");} ;

variableL: 
	     VARIABLE_ID COMMA variableL
	   | VARIABLE_ID ASSIGNMENT exp  COMMA variableL 
	   | VARIABLE_ID ASSIGNMENT exp SEMICOLON 
	   | VARIABLE_ID SEMICOLON 
	   ; 

/* Statments */
nested_statments: 
	     statment nested_statments {printf("NESTED-STATMENT\n");}
	   | statment {printf("NESTED-STATMENT\n");}
	   ;

statment: 
	     function_call  {printf("STATMENT\n");}
	   | assignment_statement   {printf("STATMENT\n");}
	   | return  {printf("STATMENT\n");}
	   | conditions {printf("STATMENT\n");}
	   | loops {printf("STATMENT\n");}
	   | code_block {printf("STATMENT\n");}
	   ;

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  {printf("CODE-BLOCK\n");};

conditions: 
	  IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  {printf("IF\n");}
	| IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES ELSE OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES {printf("IF-ELSE\n");}
	;

loops:
	  WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_ANGLE_BRACES SEMICOLON  {printf("WHILE\n");}
	| DO OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON  {printf("DO-WHILE\n");}
	| FOR OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES {printf("FOR\n");}
	;  

assignment_statement:
	   lhs  ASSIGNMENT expressions SEMICOLON {printf("A-STATMENT\n");}
	 | lhs  ASSIGNMENT STRING_LITERAL SEMICOLON {printf("A-STATMENT\n");}
	 ;

lhs:
	   VARIABLE_ID {printf("LHS\n");}
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {printf("LHS\n");}
	 ;

init: INT VARIABLE_ID ASSIGNMENT DECIMAL_LITERAL | INT VARIABLE_ID ASSIGNMENT HEX_LITERAL {printf("INIT\n");};
update: INT VARIABLE_ID ASSIGNMENT exp {printf("UPDATE");}; 
return: RETURN exp SEMICOLON {printf("RETURN\n");};

 /* Expression */
expressions: exp COMMA expressions | exp | nothing ;
exp: 
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
	| MULTIPLY VARIABLE_ID								
	;


 /* TYPES */
type: BOOL | CHAR | CHAR_P | INT | INT_P | REAL | REAL_P | STRING ;
primitiveType: NONE | BOOL_TRUE | BOOL_FALSE | CHAR_LITERAL | DECIMAL_LITERAL | HEX_LITERAL| REAL_LITERAL ;
nothing: ;


%%

int main()
{
	return yyparse();	
}

int yyerror(char *error)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"%s : ** %s **  at line %d\n" ,error, yytext, yylineno);
	return 0;
}