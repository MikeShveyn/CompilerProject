%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include<ctype.h>
	#include "lex.yy.c"
	int yylex();
	void yyerror(const char* msg);
	int yywrap();
	FILE * f1;


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
	void func_start();
	void func_end();
	void while_start();
	void while_end();
	void while_rep();
	void for_start();
	void for_inter();
	void for_rep();
	void logical_gen();
	void algebric_gen();
	void codegen_assign();
	void push();
	void if_label1();
	void if_label2();
	void if_label3();
	void func_call_gen();
	int sem_errors=0;
	int param_count_current = 0;
	int current_param_list = 0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "real", "char", "void", "if", "else", "for", "while", "main", "return"};
	int label[200];
	int lnum=0;
	int ltop=0;
	int stop=0;
	int top=0;
	char st[1000][10];
	char temp_var[2]="t";
	int ind=0;

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

%}

%union
{
	struct node *node;
	struct node2 *node2;
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
%type<node> program code function  parameter_list body_func body return argument nothing statment_func declaration
%type<node> nested_declarations nested_statments nested_statments_func type code_block assignment_statement conditions loops  statment
%type<node> init update integer_literal variable_declaration variableL atributeList string_exp string_array function_call_params 
%type<node2> exp expressions  primitiveType args_cond vrd_temp lhs function_call function_lhs


%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 



%%
program:  code {head = $1;};

code:
	   function code  {$$ = mknode("",$1, $2); }
	 | COMMENT  code { $$ = mknode("",$2, NULL);}
	 | function  {$$ = mknode("",$1, NULL);}
	 
	 ;  
	 
 /* FUNCTION  */
function:
	   type VARIABLE_ID {add('F');} OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES {endScope();}  
	   {
 			 $$=mknode("FUNC",mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$5, NULL) ,mknode("RET",$1, NULL))) ,mknode("BODY",$8,$9));
	   }
	 
	 | VOID VARIABLE_ID {add('F');}  OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES {endScope();}
		{
			 $$=mknode("FUNC", mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$5, NULL) ,mknode("RET VOID",NULL, NULL))), mknode("BODY",$8,NULL));
		}
	 ;

parameter_list:
	  argument SEMICOLON parameter_list  {$$=mknode("",$1,$3);}
	| argument  {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("NONE)\n",$1,NULL);}
	 ;

argument: type atributeList {$$=mknode("ARGS-TYPE",$1,$2);};

atributeList:
	 VARIABLE_ID COMMA  atributeList {add_to_param_count(); $$=mknode($1,$3,NULL);}
	|VARIABLE_ID  {add_to_param_count(); $$=mknode($1,mknode(")",NULL,NULL),NULL);}
	;

body: 
	  nested_declarations body {$$=mknode("",$1,$2);}
	| nested_statments body {$$=mknode("",$1,$2);}
	| nested_declarations {$$=mknode("",$1, NULL);}
	| nested_statments {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("",$1,NULL);}
	|  COMMENT body {$$=mknode("",$2, NULL);}
	|  COMMENT {$$=NULL;}
	;

body_func: 
 	  nested_declarations body_func {$$=mknode("",$1,$2);}
	| nested_statments_func body_func {$$=mknode("",$1,$2);}
	| nested_declarations  {$$=mknode("",$1, NULL);}
	| nested_statments_func {$$=mknode("",$1,NULL);}
	| nothing  {$$=mknode("",$1,NULL);}
	|  COMMENT body_func {$$=mknode("",$2, NULL);}
	|  COMMENT {$$=NULL;}
	;

nested_statments_func:
	     statment_func nested_statments_func {$$=mknode("",$1,$2);}
	    |statment_func {$$=mknode("",$1,NULL);}
		| COMMENT  nested_statments_func {$$=mknode("",$2,NULL);}
		| COMMENT {$$=NULL;} 
	   ;

statment_func:
		 function_call SEMICOLON  {$$=mknode("",$1->node, NULL);}
	   | assignment_statement {$$=mknode("",$1,NULL);}
	   | IF {add('K');} conditions {$$=mknode("",$3,NULL);}
	   | loops {$$=mknode("",$1,NULL);}
	   | {add('B');}code_block { $$=mknode("",$2,NULL);}
	   ;

function_call: function_lhs { func_call_gen();} OPEN_ANGLE_BRACES function_call_params  CLOSE_ANGLE_BRACES  {check_param_list();  $$=mknode2("FUNCTION_CALL",$1->node,$4, $1->type);};


function_call_params :
		  exp { add_to_current_param_list();} COMMA function_call_params  { $$=mknode("",$1->node, $4);}
		| exp { add_to_current_param_list(); $$=mknode("",$1->node, NULL);}
		| nothing {$$=mknode("", $1, NULL);}
		;

function_lhs:
	   VARIABLE_ID  {push(); check_declaration($1); set_param_count($1); $$=mknode2($1,NULL,NULL, get_type($1, 1));}
	 | VARIABLE_ID {push(); check_declaration($1); set_param_count($1); }  OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode2($1,$4->node,NULL, get_type($1, 1));}
	 ;


 /* Declarations  */
nested_declarations:
	     declaration nested_declarations {$$=mknode("",$1,$2);}
		| declaration {$$=mknode("",$1,NULL);}
		| COMMENT nested_declarations {$$=mknode("",$2,NULL);}
		| COMMENT {$$=NULL;} 
	 	;

declaration:
	     function { $$ = mknode("",$1, NULL); }
	   | variable_declaration {$$ = mknode("",$1, NULL); }
	   | string_array {$$ = mknode("STRING",$1, NULL); }
	   ;
	   
variable_declaration:
	  VAR  type  VARIABLE_ID {add('V');} vrd_temp 
	  {	
		  check_declaration_type(type, $5->type);
		  $$ = mknode("VAR",$2, mknode($3, $5->node, NULL));
	  } 
	  ;

vrd_temp:
	 COMMA VARIABLE_ID {add('V');} vrd_temp {$$=mknode2($2, $4->node, NULL, "NONE");}
	| SEMICOLON {$$=mknode2("",NULL, NULL, "NONE");}
	|ASSIGNMENT exp SEMICOLON 
	{	
		
		$$=mknode2("",$2->node,NULL, $2->type); 
	}
	;

string_array: STRING VARIABLE_ID {insert_type("STR"); add('V');} OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES SEMICOLON {$$=mknode($2,$5,NULL);} ;	 

variableL: 
	     lhs COMMA variableL { $$ = mknode("",$1->node, $3); }
	   | lhs ASSIGNMENT exp  COMMA variableL { $$ = mknode("=",$1->node, mknode("",$3->node, mknode("",$5,NULL))); }
	   ; 

/* Statments */
nested_statments: 
	     statment nested_statments {$$=mknode("",$1,$2);}
		| statment {$$=mknode("",$1,NULL);}
		| COMMENT nested_statments {$$=mknode("",$2,NULL);}
		| COMMENT {$$=NULL;} 
	   ;

statment: 
	     function_call SEMICOLON {$$=mknode("",$1->node, NULL);}
	   | assignment_statement   {$$=mknode("",$1,NULL);}
	   | return  {$$=mknode("",$1,NULL);}
	   | IF {add('K');} conditions {$$=mknode("",$3,NULL);}
	   | loops {$$=mknode("",$1,NULL);}
	   | {add('B');} code_block {$$=mknode("CODE_BLOCK",$2,NULL);}
	   ;

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES {endScope(); $$=mknode("CODE_BLOCK",$2,NULL);};

conditions: 
	  OPEN_ANGLE_BRACES args_cond CLOSE_ANGLE_BRACES code_block  {$$=mknode("IF",$2->node,$4);}
	| OPEN_ANGLE_BRACES args_cond CLOSE_ANGLE_BRACES code_block ELSE {add('K');} code_block {if_label3(); $$=mknode("IF-ELSE", mknode("",$2->node,$4), mknode("",$7,NULL));}
	|{if_label3();}
	;

loops:
	  WHILE {add('K');} OPEN_ANGLE_BRACES args_cond {while_rep();} CLOSE_ANGLE_BRACES code_block {  $$=mknode("WHILE",$4->node,$7); while_end();}
	| DO {add('K');} code_block WHILE  OPEN_ANGLE_BRACES args_cond {while_rep();} CLOSE_ANGLE_BRACES SEMICOLON{  $$=mknode("DO-WHILE",$3,$6->node); while_end();}
	| FOR {add('K');} OPEN_ANGLE_BRACES init SEMICOLON {for_inter();} args_cond  SEMICOLON {for_rep();} update  CLOSE_ANGLE_BRACES code_block { $$=mknode("FOR",mknode("INIT", $4, mknode("COND", $7->node, mknode("UPDATE",$10, NULL))),$12);}
	;  

args_cond : 
	 exp EQL exp {$$=mknode2("==",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log2"));}							
	| exp NOT_EQL exp {$$=mknode2("!=",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log2"));}							
	| exp LESS exp {$$=mknode2("<",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log3"));}									
	| exp LESS_EQL exp {$$=mknode2("<=",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log3"));}								
	| exp GREATER  exp {$$=mknode2(">",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log3"));}								
	| exp GREATER_EQL exp {$$=mknode2(">=",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log3"));}
    | exp OR exp {$$=mknode2("||",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log"));}
	| exp AND  exp {$$=mknode2("&&",$1->node,$3->node, check_alg_expr($1->type, $3->type, "log"));}														
	| NOT  exp  {$$=mknode2("!",$2->node,NULL, $2->type);} 

assignment_statement: lhs {push();} ASSIGNMENT expressions {codegen_assign();} SEMICOLON {check_declaration_type($1->type, $4->type); $$=mknode("=",$1->node,$4->node); };

lhs:
	   VARIABLE_ID  {check_declaration($1); $$=mknode2($1,NULL,NULL, get_type($1, 0));}
	 | VARIABLE_ID {check_declaration($1);} OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES {$$=mknode2($1,$4,NULL, get_type($1, 0));}
	 | MULTIPLY VARIABLE_ID  {check_declaration($2); $$=mknode2($2,NULL,NULL, get_type($2, 3));}
	 ;

init:  lhs ASSIGNMENT {push();} integer_literal { $$=mknode("=",$1->node,$4);};
	
update: lhs ASSIGNMENT {push();} exp {$$=mknode("=",$1->node,$4->node);};

return: RETURN exp SEMICOLON {check_return_type($2->type); $$=mknode("RET-VAL",$2->node,NULL);} ;


 /* Expression */
expressions: 
   exp COMMA expressions {$$=mknode2("",$1->node,$3->node, "exp");}
 | exp {$$=mknode2("",$1->node,NULL, $1->type); }
 | OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES {$$=mknode2("exp",$2->node,NULL, $2->type);}	 
 | nothing {$$=mknode2("",$1,NULL, "NONE");}
 ;

exp: 
	  exp PLUS {push();} exp {$$=mknode2("+",$1->node,$4->node, check_alg_expr($1->type, $4->type, "alg"));}         			
	| exp MINUS {push();} exp {$$=mknode2("-",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "alg"));}              				
	| exp MULTIPLY {push();} exp {$$=mknode2("*",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "alg"));}								
	| exp DIVISION {push();} exp {$$=mknode2("/",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "alg"));}															
	| exp EQL {push();} exp  {$$=mknode2("==",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log2"));}							
	| exp NOT_EQL {push();} exp {$$=mknode2("!=",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log2"));}							
	| exp LESS {push();} exp {$$=mknode2("<",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log3"));}									
	| exp LESS_EQL {push();} exp {$$=mknode2("<=",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log3"));}								
	| exp GREATER {push();} exp {$$=mknode2(">",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log3"));}								
	| exp GREATER_EQL {push();} exp {$$=mknode2(">=",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log3"));}
    | exp OR {push();} exp {$$=mknode2("||",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log"));}
	| exp AND {push();} exp {$$=mknode2("&&",$1->node,$4->node,  check_alg_expr($1->type, $4->type, "log"));}												
	| NOT {push();} exp {$$=mknode2("!",$3->node,NULL, check_alg_expr("NONE", $3->type, "not"));} 								
	| VARIABLE_ID {push(); check_declaration($1);  $$=mknode2($1,NULL,NULL, get_type($1, 0));}	  
	| primitiveType {$$=mknode2("",$1->node, NULL, $1->type);} 											
	| function_call { $$=mknode2("function_call",$1->node,NULL, $1->type);}	  							
	| LENGTH VARIABLE_ID LENGTH {$$=mknode2($2,NULL,NULL, "INT");}	 									
	| OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES {$$=mknode2("exp",$2->node,NULL, $2->type);}																
	| ADDRESS exp {$$=mknode2("ADDRESS-OF", $2->node, NULL,  get_type($2->type, 4));}	  	
	| VARIABLE_ID OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES {check_declaration($2); $$=mknode2("ADDRESS-OF",mknode($1,$3,NULL),NULL, get_type($1, 0));}	
	| MULTIPLY exp {$$=mknode2("POINTER-OF", $2->node,NULL, get_type($2->type, 3));}	 								
	;

string_exp:
	  string_exp PLUS {push();} string_exp {$$=mknode("+",$1,$4);}         			
	| string_exp MINUS {push();} string_exp {$$=mknode("-",$1,$4);}              				
	| string_exp MULTIPLY {push();} string_exp {$$=mknode("*",$1,$4);}								
	| string_exp DIVISION {push();} string_exp {$$=mknode("/",$1,$4);}	
	| integer_literal {$$=mknode("",$1,NULL);}  
	| VARIABLE_ID  	{{push();} $$=mknode($1,NULL,NULL);}  
	;

 /* TYPES */
type: 
	  BOOL { insert_type("BOOL"); $$=mknode("BOOL",NULL,NULL);} 
	| CHAR {$$=mknode("CHAR",NULL,NULL); insert_type("CHAR");} 
	| CHAR_P {$$=mknode("CHAR_P",NULL,NULL); insert_type("CHAR_P");} 
	| INT { insert_type("INT"); $$=mknode("INT",NULL,NULL);} 
	| INT_P {$$=mknode("INT_P",NULL,NULL); insert_type("INT_P");} 
	| REAL {$$=mknode("REAL",NULL,NULL); insert_type("REAL");} 
	| REAL_P {$$=mknode("REAL_P",NULL,NULL); insert_type("REAL_P");} 
	| STRING {$$=mknode("STRING",NULL,NULL); insert_type("STRING");} 
	;

primitiveType: 
	 NONE 
	 {	
		 push();
		 $$=mknode2("None",NULL,NULL, "None");
		  add('C');
	 } 
	 |BOOL_TRUE 
	 {	
		 push();
		 $$=mknode2("True",NULL,NULL, "BOOL");
		 add('C');
	  } 
	 |BOOL_FALSE 
	  {
		  push();
		 $$=mknode2("False",NULL,NULL, "BOOL"); 
		 add('C'); 
	  } 
	 | CHAR_LITERAL 
	 {
		 push();
		 $$=mknode2($1,NULL,NULL, "CHAR");
		  add('C');
	 } 
	 | DECIMAL_LITERAL  
	 {
		 push();
		$$=mknode2($1,NULL,NULL, "INT"); 
		add('C');
	 } 
	 | HEX_LITERAL 
	 {
		 push();
		 $$=mknode2($1,NULL,NULL, "REAL");
		  add('C');
	 } 
	 | REAL_LITERAL  
	 {
		 push();
		 $$=mknode2($1,NULL,NULL, "REAL");
		  add('C');
	 } 
	 | STRING_LITERAL 
	 {
		 push();
		 $$=mknode2($1,NULL,NULL, "STR");
		  add('C');
	 } 
	 ;

integer_literal:
	   DECIMAL_LITERAL  { push();$$=mknode($1,NULL,NULL); add('C');} 
	 | HEX_LITERAL { push();$$=mknode($1,NULL,NULL); add('C');} 
	 ;

nothing:  {$$=NULL;}; 

%%

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

/*3 Section start*/
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
	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto L%d\n",lnum);
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

void if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto L%d\n",lnum);
 	label[++ltop]=lnum;
}

void if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\tgoto L%d\n",lnum);
	fprintf(f1,"L%d:",x); 
	label[++ltop]=lnum;
}

void if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"L%d:",y);
	top--;
}

void push()
{	

  	strcpy(st[++top],yytext);
}


void func_call_gen() {
	ind = 0;
	sprintf(temp_var,"t%d",ind); 
	fprintf(f1,"\tPushParam %s: \n",temp_var);
	ind++;
	sprintf(temp_var,"t%d",ind); 
	ind++;
	fprintf(f1,"\t%s %s LCall %s: \n", temp_var,st[top-1],st[top]);
	fprintf(f1,"\tPopParams %d: \n",4);
}

void logical_gen()
{
 	sprintf(temp_var,"t%d",ind);
  	fprintf(f1,"\t%s%s%s%s\n",temp_var,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp_var);
 	ind++;
}

void algebric_gen()
{
 	sprintf(temp_var,"t%d",ind); // converts temp to reqd format
  	fprintf(f1,"\t%s=%s%s%s\n",temp_var,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp_var);
 	ind++;
}

void codegen_assign()
{
	sprintf(temp_var,"t%d",ind);
	fprintf(f1,"\t%s=%s\n",temp_var,st[top]);
 	fprintf(f1,"\t%s=%s\n",st[top-1],temp_var);
 	top-=2;
}
/*3 Section end*/
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
		printf("Check %s %d\n", var, is_func);
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
						printf("Int return\n");
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

char* check_alg_expr(char * type1, char * type2, char * op) {
	printf("Check Alg exp %s %s %s\n", type1, type2, op);
	int temp = check_types(type1, type2);
	printf("%d\n", temp);
	if(strcmp(op, "alg") == 0){
		algebric_gen();
		if( temp == 7)
			return "INT";
		else if(temp == 1 || temp == 2 || temp == 8)
			return "REAL";
	}else if(strcmp(op, "log")== 0){
		logical_gen();
		if(temp == 9)
			return "BOOL";	
	}else if(strcmp(op, "log3")== 0){
		logical_gen();
		if(temp == 1 || temp == 2 || temp==7 || temp == 8)
			return "BOOL";	
	}else if(strcmp(op, "log2")== 0){
		logical_gen();
		if(strcmp(type1, type2)==0)
			return "BOOL";	
	}else if(strcmp(op, "not")== 0){
		logical_gen();
		if(strcmp(type2,"BOOL")==0)
			return "BOOL";
	}else{
		
	}

	sprintf(errors[sem_errors], "Line %d: TYPE CASTING ERROR \n", count_line+1);
	sem_errors++;
	return "EROR";
}


void check_declaration_type(char *type1, char *type2) {
	printf("Check decl types %s %s\n", type1, type2);
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

			if(strcmp(yytext, "while")==0 || strcmp(yytext, "do")==0) {
				while_start();
			}

			if(strcmp(yytext, "if")==0) {
				if_label1();
			}

			if(strcmp(yytext, "else")==0) {
				if_label2();
			}

			if(strcmp(yytext, "for")==0) {
				for_start();
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

