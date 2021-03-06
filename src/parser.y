%{
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
	int ret_flag = 0;	
	int ret_val_flag=0;
	int flag = 0;
%}

%union
{
	struct node *node;
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


// NODES FUNCTIONS 
%type<node> program code function exp expressions parameter_list body_func body return  primitiveType argument nothing statment_func declaration
%type<node> nested_declarations nested_statments nested_statments_func type code_block function_call assignment_statement conditions loops lhs statment
%type<node> init update integer_literal variable_declaration variableL atributeList string_exp string_array



%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 


/*  !!! TODO ADD POINTERS AND THIK ABOUT UNARY OPERATORS  STRINGS  ARRAYS COMMENTS !!! */

%%
program: code { TreePrint($1);};

code:
	   function code  { $$ = mknode("",$1, $2); }
	 | function   { $$ = mknode("",$1, NULL); }
	 ;  

 /* FUNCTION  */
function:
	   type VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES   
	   {
 			 $$=mknode("FUNC",mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$4, NULL) ,mknode("RET",$1, NULL))) ,mknode("BODY",$7,$8));
	   }
	 
	 | VOID VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES 
		{
			 $$=mknode("FUNC", mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$4, NULL) ,mknode("RET VOID",NULL, NULL))), mknode("BODY",$7,NULL));
		}
	 ;

parameter_list:
	  argument SEMICOLON parameter_list  {$$=mknode("",$1,$3);}
	| argument  {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("NONE)\n",$1,NULL);}
	 ;

argument: type atributeList {$$=mknode("ARGS-TYPE",$1,$2);};

atributeList:
	VARIABLE_ID COMMA atributeList {$$=mknode($1,$3,NULL);};
	|VARIABLE_ID {$$=mknode($1,mknode(")",NULL,NULL),NULL);};
	;

body: 
	  nested_declarations nested_statments {$$=mknode("",$1,$2);}
	| nested_declarations {$$=mknode("",$1, NULL);}
	| nested_statments {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("",$1,NULL);}
	| COMMENT {$$=NULL;}
	;

body_func: 
 	  nested_declarations nested_statments_func {$$=mknode("",$1,$2);}
	| nested_declarations  {$$=mknode("",$1, NULL);}
	| nested_statments_func {$$=mknode("",$1,NULL);}
	| nothing  {$$=mknode("",$1,NULL);}
	|  COMMENT {$$=NULL;}
	;

nested_statments_func:
	     statment_func nested_statments_func {$$=mknode("",$1,$2);}
	   | statment_func {$$=mknode("",$1,NULL);}
	   ;

statment_func:
		 function_call  {$$=mknode("",$1,NULL);}
	   | assignment_statement {$$=mknode("",$1,NULL);}
	   | conditions {$$=mknode("",$1,NULL);}
	   | loops {$$=mknode("",$1,NULL);}
	   | code_block {$$=mknode("",$1,NULL);}
	   ;


function_call: lhs OPEN_ANGLE_BRACES expressions  CLOSE_ANGLE_BRACES SEMICOLON {$$=mknode("FUNCTION_CALL",$1,$3);};

 /* Declarations  */
nested_declarations:
	   declaration nested_declarations {$$=mknode("",$1,$2);}
	 | declaration {$$=mknode("",$1,NULL);}
	 ;

declaration:
	     function { $$ = mknode("",$1, NULL); }
	   | variable_declaration { $$ = mknode("",$1, NULL); }
	   | string_array {$$ = mknode("STRING",$1, NULL); }
	   ;
	   
variable_declaration:VAR type variableL { $$ = mknode("VAR",$2, $3); };

string_array: STRING VARIABLE_ID OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES SEMICOLON {$$=mknode($2,$4,NULL);} ;	 

variableL: 
	     lhs COMMA variableL { $$ = mknode("",$1, $3); }
	   | lhs ASSIGNMENT exp  COMMA variableL { $$ = mknode("=",$1, mknode("",$3, mknode("",$5,NULL))); }
	   | lhs ASSIGNMENT exp SEMICOLON { $$ = mknode("=",$1, $3); }
	   | lhs SEMICOLON { $$ = mknode("",$1, NULL); }
	   ; 

/* Statments */
nested_statments: 
	     statment nested_statments {$$=mknode("",$1,$2);}
	   | statment {$$=mknode("",$1,NULL);}
	   ;

statment: 
	     function_call  {$$=mknode("",$1,NULL);}
	   | assignment_statement   {$$=mknode("",$1,NULL);}
	   | return  {$$=mknode("",$1,NULL);}
	   | conditions {$$=mknode("",$1,NULL);}
	   | loops {$$=mknode("",$1,NULL);}
	   | code_block {$$=mknode("CODE_BLOCK",$1,NULL);}
	   ;

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  {$$=mknode("CODE_BLOCK",$2,NULL);};

conditions: 
	  IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block  {$$=mknode("IF",$3,$5);}
	| IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block ELSE code_block {$$=mknode("IF-ELSE", mknode("",$3,$5), mknode("",$7,NULL));}
	;

loops:
	  WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block {$$=mknode("WHILE",$3,$5);}
	| DO code_block WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON{$$=mknode("DO-WHILE",$2,$5);}
	| FOR OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES code_block {$$=mknode("FOR",mknode("INIT", $3, mknode("COND", $5, mknode("UPDATE",$7, NULL))),$9);}
	;  

assignment_statement: lhs  ASSIGNMENT expressions SEMICOLON {$$=mknode("=",$1,$3);};

lhs:
	   VARIABLE_ID {$$=mknode($1,NULL,NULL);}
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode($1,$3,NULL);}
	 ;

init:  lhs ASSIGNMENT integer_literal {$$=mknode("=",$1,$3);};
	
update: lhs ASSIGNMENT exp {$$=mknode("=",$1,$3);};

return: RETURN exp SEMICOLON {$$=mknode("RET-VAL",$2,NULL);} ;

 /* Expression */
expressions: 
   exp COMMA expressions {$$=mknode("",$1,$3);}
 | exp {$$=mknode("",$1,NULL);}
 | nothing {$$=mknode("",$1,NULL);}
 ;

exp: 
	  exp PLUS exp {$$=mknode("+",$1,$3);}         			
	| exp MINUS exp {$$=mknode("-",$1,$3);}              				
	| exp MULTIPLY exp {$$=mknode("*",$1,$3);}								
	| exp DIVISION exp {$$=mknode("/",$1,$3);}															
	| exp EQL exp {$$=mknode("==",$1,$3);}							
	| exp NOT_EQL exp {$$=mknode("!=",$1,$3);}							
	| exp LESS exp {$$=mknode("<",$1,$3);}									
	| exp LESS_EQL exp {$$=mknode("<=",$1,$3);}								
	| exp GREATER exp {$$=mknode(">",$1,$3);}								
	| exp GREATER_EQL exp {$$=mknode(">=",$1,$3);}
    | exp OR exp {$$=mknode("||",$1,$3);}
	| exp AND exp {$$=mknode("&&",$1,$3);}												
	| primitiveType {$$=mknode("",$1, NULL);} 			
	| NOT exp {$$=mknode("!",$2,NULL);} 								
	| VARIABLE_ID {$$=mknode($1,NULL,NULL);}											
	| function_call {$$=mknode("function_call",$1,NULL);}	  							
	| LENGTH VARIABLE_ID LENGTH {$$=mknode($2,NULL,NULL);}	 									
	| OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES {$$=mknode("exp",$2,NULL);}																
	| ADDRESS VARIABLE_ID {$$=mknode("ADDRESS-OF",mknode($2,NULL,NULL),NULL);}	  											
	| ADDRESS VARIABLE_ID OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES {$$=mknode("ADDRESS-OF",mknode($2,$4,NULL),NULL);}	
	| MULTIPLY VARIABLE_ID {$$=mknode($2,NULL,NULL);}	 								
	;

string_exp:
	  string_exp PLUS string_exp {$$=mknode("+",$1,$3);}         			
	| string_exp MINUS string_exp {$$=mknode("-",$1,$3);}              				
	| string_exp MULTIPLY string_exp {$$=mknode("*",$1,$3);}								
	| string_exp DIVISION string_exp {$$=mknode("/",$1,$3);}	
	| integer_literal {$$=mknode("",$1,NULL);}  	
	;


 /* TYPES */
type: 
	  BOOL {$$=mknode("BOOL",NULL,NULL);} 
	| CHAR {$$=mknode("CHAR",NULL,NULL);} 
	| CHAR_P {$$=mknode("CHAR_P",NULL,NULL);} 
	| INT {$$=mknode("INT",NULL,NULL);} 
	| INT_P {$$=mknode("INT_P",NULL,NULL);} 
	| REAL {$$=mknode("REAL",NULL,NULL);} 
	| REAL_P {$$=mknode("REAL_P",NULL,NULL);} 
	| STRING {$$=mknode("STRING",NULL,NULL);} 
	;

primitiveType: 
	 NONE {$$=mknode("None",NULL,NULL);} 
	 |BOOL_TRUE {$$=mknode("True",NULL,NULL);} 
	 |BOOL_FALSE  {$$=mknode("False",NULL,NULL);} 
	 | CHAR_LITERAL {$$=mknode($1,NULL,NULL);} 
	 | DECIMAL_LITERAL  {$$=mknode($1,NULL,NULL);} 
	 | HEX_LITERAL {$$=mknode($1,NULL,NULL);} 
	 | REAL_LITERAL  {$$=mknode($1,NULL,NULL);} 
	 | STRING_LITERAL {$$=mknode($1,NULL,NULL);} 
	 ;

integer_literal:
	   DECIMAL_LITERAL  {$$=mknode($1,NULL,NULL);} 
	 | HEX_LITERAL {$$=mknode($1,NULL,NULL);} 
	 ;

nothing:  {$$=NULL;}; 


%%

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


int yyerror(char *error)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"%s : ** %s **  at line %d\n" ,error, yytext, yylineno);
	return 0;
}