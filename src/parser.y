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
	//void printtree(node *tree);
	void Printtree(node *tree);
	void printTabs(int n);
	int printlevel=0;
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
%type<node> init update forPrimitiveType variable_declaration variableL atributeList



%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 


/*  !!! TODO ADD POINTERS AND THIK ABOUT UNARY OPERATORS  STRINGS  ARRAYS COMMENTS !!! */

%%
program: code { printf("OK\n");  Printtree($1);};

code:
	   function code  { $$ = mknode("",$1, $2); }
	 | function   { $$ = mknode("",$1, NULL); }
	 ;  

 /* FUNCTION  */
function:
	   type VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES   
	   {
 			 $$=mknode("FUNC", mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$4, NULL) ,mknode("RET",$1, NULL))), mknode("BODY",$7,$8));
	   }
	 
	 | VOID VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES 
		{
			 $$=mknode("FUNC", mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$4, NULL) ,mknode("RET-VOID",NULL, NULL))), mknode("BODY",$7,NULL));
		}
	 ;

parameter_list:
	  argument SEMICOLON parameter_list  {$$=mknode("",$1,$3);}
	| argument  {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("",$1,NULL);}
	 ;

argument: type atributeList {$$=mknode("ARG-TYPE",$1,$2);};

atributeList:
	  VARIABLE_ID COMMA atributeList {$$=mknode($1,$3,NULL);};
	| VARIABLE_ID {$$=mknode($1,NULL,NULL);};
	;

body: 
	  nested_declarations nested_statments {$$=mknode("",$1,$2);}
	| nested_declarations {$$=mknode("",$1, NULL);}
	| nested_statments {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("",$1,NULL);}
	;

body_func: 
 	  nested_declarations nested_statments_func {$$=mknode("",$1,$2);}
	| nested_declarations  {$$=mknode("",$1, NULL);}
	| nested_statments_func {$$=mknode("",$1,NULL);}
	| nothing  {$$=mknode("",$1,NULL);}
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
	   ;
	   
variable_declaration: VAR type variableL { $$ = mknode("VAR",$2, $3); }

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
	   | code_block {$$=mknode("",$1,NULL);}
	   ;

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  {$$=mknode("CODE_BLOCK",$2,NULL);};

conditions: 
	  IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block  {$$=mknode("IF",$3,$5);}
	| IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block ELSE code_block {$$=mknode("IF-ELSE", mknode("",$3,$5), mknode("",$7,NULL));}
	;

loops:
	  WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block {$$=mknode("WHILE",$3,$5);}
	| DO code_block WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON{$$=mknode("D0-WHILE",$2,$5);}
	| FOR OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES code_block {$$=mknode("FOR",mknode("INIT", $3, mknode("COND", $5, mknode("UPDATE",$7, NULL))),$9);}
	;  

assignment_statement:
	   lhs  ASSIGNMENT expressions SEMICOLON {$$=mknode("=",$1,$3);}
	 ;

lhs:
	   VARIABLE_ID {$$=mknode($1,NULL,NULL);}
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode($1,$3,NULL);}
	 ;

init:  lhs ASSIGNMENT forPrimitiveType {$$=mknode("=",$1,$3);};
	
update: lhs ASSIGNMENT exp {$$=mknode("=",$1,$3);};

return: RETURN exp SEMICOLON {$$=mknode("RET",$2,NULL);} ; 

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
	| NOT exp {$$=mknode("!",$1,NULL);} 								
	| VARIABLE_ID {$$=mknode($1,NULL,NULL);}											
	| function_call							
	| LENGTH VARIABLE_ID LENGTH									
	| OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES															
	| VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES 
	| ADDRESS VARIABLE_ID 											
	| ADDRESS VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES 
	| MULTIPLY VARIABLE_ID								
	;


 /* TYPES */
type: 
	BOOL 
	| CHAR {$$=mknode("CHAR",NULL,NULL);} 
	| CHAR_P {$$=mknode("CHAR_P",NULL,NULL);} 
	| INT {$$=mknode("INT",NULL,NULL);} 
	| INT_P {$$=mknode("INT_P",NULL,NULL);} 
	| REAL {$$=mknode("REAL",NULL,NULL);} 
	| REAL_P {$$=mknode("REAL_P",NULL,NULL);} 
	| STRING {$$=mknode("STRING",NULL,NULL);} 
	;
primitiveType: 
	 NONE {$$=mknode("NONE",NULL,NULL);} 
	 |BOOL_TRUE {$$=mknode("TRUE",NULL,NULL);} 
	 |BOOL_FALSE  {$$=mknode("FALSE",NULL,NULL);} 
	 | CHAR_LITERAL {$$=mknode("CHAR_LITERAL",NULL,NULL);} 
	 | DECIMAL_LITERAL  {$$=mknode("DECIMAL_LITERAL",NULL,NULL);} 
	 | HEX_LITERAL {$$=mknode("HEX_LITERAL",NULL,NULL);} 
	 | REAL_LITERAL  {$$=mknode("REAL_LITERAL",NULL,NULL);} 
	 | STRING_LITERAL {$$=mknode("STRING_LITERAL",NULL,NULL);} 
	 ;

forPrimitiveType:
	   DECIMAL_LITERAL  {$$=mknode("DECIMAL_LITERAL",NULL,NULL);} 
	 | HEX_LITERAL {$$=mknode("HEX_LITERAL",NULL,NULL);} 
	 ;

nothing:  {$$=NULL;}; 


%%

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
		
		printf("(VAR ");
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
		else if(strcmp(tree->token, "ARG-TYPE") == 0)
	{
		printf("(");
		flag =2 ;
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
	else if(strcmp(tree->token, "RET-VOID") == 0)
	{
		printf("(RET VOID");
		flag = 2;
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