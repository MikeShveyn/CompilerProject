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
%type<node> program code function exp expressions parameter_list body_func return  primitiveType argument nothing



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
program: code { printf("OK\n");  Printtree($1);};

code:
	   function code  { $$ = mknode("",$1, $2); }
	 | function   { $$ = mknode("",$1, NULL); }
	 ;  

 /* FUNCTION  */
function:
	   type VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES   
	   {
 			 $$=mknode("func", mknode($2,mknode("\n",NULL,NULL), mknode("ARGS",$4, NULL)), mknode("",$7,$8));
	   }
	 
	 | VOID VARIABLE_ID OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES 
	 ;

parameter_list:
	   argument SEMICOLON parameter_list  {$$=NULL;};
	 | argument 
	 | nothing
	 ;

argument: type atributeList ;

atributeList:
	  VARIABLE_ID COMMA atributeList 
	| VARIABLE_ID 
	;

body: 
	  nested_declarations nested_statments
	| nested_declarations 
	| nested_statments 
	| nothing 
	;

body_func: 
 	  nested_declarations nested_statments {$$=NULL;};
	| nested_declarations 
	| nested_statments_func 
	| nothing 
	;

nested_statments_func:
	     statment_func nested_statments 
	   | statment_func 
	   ;

statment_func:
		 function_call  
	   | assignment_statement   
	   | conditions 
	   | loops 
	   | code_block 
	   ;


function_call: VARIABLE_ID OPEN_ANGLE_BRACES expressions  CLOSE_ANGLE_BRACES ;

 /* Declarations  */
nested_declarations:
	   declaration nested_declarations 
	 | declaration 
	 ;

declaration:
	     function 
	   | variable_declaration 
	   ;
	   
variable_declaration: VAR type variableL ;

variableL: 
	     VARIABLE_ID COMMA variableL
	   | VARIABLE_ID ASSIGNMENT exp  COMMA variableL 
	   | VARIABLE_ID ASSIGNMENT exp SEMICOLON 
	   | VARIABLE_ID SEMICOLON 
	   ; 

/* Statments */
nested_statments: 
	     statment nested_statments 
	   | statment 
	   ;

statment: 
	     function_call  
	   | assignment_statement   
	   | return  
	   | conditions 
	   | loops 
	   | code_block 
	   ;

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  ;

conditions: 
	  IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  
	| IF OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES ELSE OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES 
	;

loops:
	  WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_ANGLE_BRACES SEMICOLON  
	| DO OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES WHILE OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON  
	| FOR OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES
	;  

assignment_statement:
	   lhs  ASSIGNMENT expressions SEMICOLON 
	 | lhs  ASSIGNMENT STRING_LITERAL SEMICOLON 
	 ;

lhs:
	   VARIABLE_ID
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES 
	 ;

init: INT VARIABLE_ID ASSIGNMENT DECIMAL_LITERAL | INT VARIABLE_ID ASSIGNMENT HEX_LITERAL ;
update: INT VARIABLE_ID ASSIGNMENT exp ;
return: RETURN exp SEMICOLON {$$=mknode("return",$2,NULL);} | {$$=NULL;}; 

 /* Expression */
expressions: 
   exp COMMA expressions
 | exp 
 | nothing ;

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
	| primitiveType {$$=mknode("primT",$1, NULL);}			
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
type: BOOL | CHAR | CHAR_P | INT | INT_P | REAL | REAL_P | STRING ;
primitiveType: NONE | BOOL_TRUE | BOOL_FALSE | CHAR_LITERAL | DECIMAL_LITERAL | HEX_LITERAL| REAL_LITERAL ;
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
	if(strcmp(tree->token, "var") == 0)
	{
		
		printf("(DECLARE ");
		flag=2;
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		printf("(IF\n");
		flag = 1;
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		printf("(WHILE\n");
		flag = 1;
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{
		printf("(FOR\n");
		flag = 1;
		
		
	}
		else if(strcmp(tree->token, "func") == 0 ||strcmp(tree->token, "proc") == 0 ||strcmp(tree->token, "CODE") == 0||strcmp(tree->token, "Call func") == 0)
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
		else if(strcmp(tree->token, "if-else") == 0)
	{
		printf("(IF-ELSE\n");
		printlevel--;
		
		flag = 1;
	}
			else if(strcmp(tree->token, "return") == 0)
	{
		printf("(RET ");
		flag = 2;
	}
	else if(strcmp(tree->token, "{") == 0)
	{
                printf("(BLOCK\n");
				
				
	}
	else if(strcmp(tree->token, "}") == 0)
	{
		printf(")\n");
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
			printf("%s ", tree->token);
			
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