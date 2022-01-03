%{
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

	struct node *head;
	node *mknode(char *token, node *left, node*right);
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
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	void set_current_scope(const char *, int is_func);
	void add_to_param_count();
	void set_param_count(const char * name);
	void check_param_list();
	void add_to_current_param_list();
	void endScope();
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
%type<node> init update integer_literal variable_declaration variableL atributeList string_exp string_array temp function_call_params function_lhs



%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 



%%
program:  code {head = $1;};

code:
	   function code  { $$ = mknode("",$1, $2); }
	 | function   { $$ = mknode("",$1, NULL);}
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
	 VARIABLE_ID  COMMA atributeList {add_to_param_count(); $$=mknode($1,$3,NULL);}
	|VARIABLE_ID {add_to_param_count(); $$=mknode($1,mknode(")",NULL,NULL),NULL);}
	;

body: 
	  nested_declarations body {$$=mknode("",$1,$2);}
	| nested_statments body {$$=mknode("",$1,$2);}
	| nested_declarations {$$=mknode("",$1, NULL);}
	| nested_statments {$$=mknode("",$1,NULL);}
	| nothing {$$=mknode("",$1,NULL);}
	| COMMENT {$$=NULL;}
	;

body_func: 
 	  nested_declarations body_func {$$=mknode("",$1,$2);}
	| nested_statments_func body_func {$$=mknode("",$1,$2);}
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

function_call: function_lhs OPEN_ANGLE_BRACES function_call_params  CLOSE_ANGLE_BRACES SEMICOLON {check_param_list(); $$=mknode("FUNCTION_CALL",$1,$3);};


function_call_params :
		  VARIABLE_ID {check_declaration($1); add_to_current_param_list();} COMMA function_call_params  { $$=mknode($1,$4, NULL);}
		| VARIABLE_ID {check_declaration($1); add_to_current_param_list(); $$=mknode($1,NULL, NULL);}
		;

function_lhs:
	   VARIABLE_ID  {check_declaration($1); set_param_count($1); $$=mknode($1,NULL,NULL);}
	 | VARIABLE_ID {check_declaration($1); set_param_count($1); }  OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode($1,$4,NULL);}
	 ;


 /* Declarations  */
nested_declarations:
	   declaration nested_declarations {$$=mknode("",$1,$2);}
	 | declaration {$$=mknode("",$1,NULL);}
	 ;

declaration:
	     function { $$ = mknode("",$1, NULL); }
	   | variable_declaration {$$ = mknode("",$1, NULL); }
	   | string_array {$$ = mknode("STRING",$1, NULL); }
	   ;
	   
variable_declaration:
	  VAR  type  VARIABLE_ID {add('V');} temp 
	  {
		  $$ = mknode("VAR",$2, mknode($3, $5, NULL));
	  } 
	  ;

temp:
	 SEMICOLON {$$=mknode("",NULL,NULL);}
	|ASSIGNMENT exp SEMICOLON 
	{
		$$=mknode("",$2,NULL); 
	}
	;

string_array: STRING VARIABLE_ID OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES SEMICOLON {$$=mknode($2,$4,NULL);} ;	 

variableL: 
	     lhs COMMA variableL { $$ = mknode("",$1, $3); }
	   | lhs ASSIGNMENT exp  COMMA variableL { $$ = mknode("=",$1, mknode("",$3, mknode("",$5,NULL))); }
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

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES {endScope(); $$=mknode("CODE_BLOCK",$2,NULL);};

conditions: 
	 IF {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block  { $$=mknode("IF",$4,$6);}
	|IF {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block ELSE {add('K');} code_block { $$=mknode("IF-ELSE", mknode("",$4,$6), mknode("",$9,NULL));}
	   
	;

loops:
	  WHILE {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block {  $$=mknode("WHILE",$4,$6);}
	| DO {add('K');} code_block WHILE  OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON{  $$=mknode("DO-WHILE",$3,$6);}
	| FOR {add('K');} OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES code_block { $$=mknode("FOR",mknode("INIT", $4, mknode("COND", $6, mknode("UPDATE",$8, NULL))),$10);}
	;  

assignment_statement: lhs  ASSIGNMENT expressions SEMICOLON {$$=mknode("=",$1,$3); };

lhs:
	   VARIABLE_ID  {check_declaration($1); $$=mknode($1,NULL,NULL);}
	 | VARIABLE_ID {check_declaration($1);} OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode($1,$4,NULL);}
	 ;

init:  lhs ASSIGNMENT integer_literal {$$=mknode("=",$1,$3);};
	
update: lhs ASSIGNMENT exp {$$=mknode("=",$1,$3);};

return: RETURN  exp SEMICOLON { $$=mknode("RET-VAL",$2,NULL);} ;

 /* Expression */
expressions: 
   exp COMMA expressions {$$=mknode("",$1,$3);}
 | exp {$$=mknode("",$1,NULL); }
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
	| VARIABLE_ID {check_declaration($1);  $$=mknode($1,NULL,NULL);}											
	| function_call {$$=mknode("function_call",$1,NULL);}	  							
	| LENGTH VARIABLE_ID LENGTH {$$=mknode($2,NULL,NULL);}	 									
	| OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES {$$=mknode("exp",$2,NULL);}																
	| ADDRESS VARIABLE_ID {check_declaration($2); $$=mknode("ADDRESS-OF",mknode($2,NULL,NULL),NULL);}	  											
	| ADDRESS VARIABLE_ID OPEN_SQUARE_BRACES string_exp CLOSE_SQUARE_BRACES {check_declaration($2); $$=mknode("ADDRESS-OF",mknode($2,$4,NULL),NULL);}	
	| MULTIPLY VARIABLE_ID {check_declaration($2); $$=mknode($2,NULL,NULL);}	 								
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
		 $$=mknode("None",NULL,NULL);
		  add('C');
	 } 
	 |BOOL_TRUE 
	 {
		 $$=mknode("True",NULL,NULL);
		 add('K');
	  } 
	 |BOOL_FALSE 
	  {
		 $$=mknode("False",NULL,NULL); 
		 add('K'); 
	  } 
	 | CHAR_LITERAL 
	 {
		 $$=mknode($1,NULL,NULL);
		  add('C');
	 } 
	 | DECIMAL_LITERAL  
	 {
		$$=mknode($1,NULL,NULL); 
		add('C');
	 } 
	 | HEX_LITERAL 
	 {
		 $$=mknode($1,NULL,NULL);
		  add('C');
	 } 
	 | REAL_LITERAL  
	 {
		 $$=mknode($1,NULL,NULL);
		  add('C');
	 } 
	 | STRING_LITERAL 
	 {
		 $$=mknode($1,NULL,NULL);
		  add('C');
	 } 
	 ;

integer_literal:
	   DECIMAL_LITERAL  {$$=mknode($1,NULL,NULL); add('C');} 
	 | HEX_LITERAL {$$=mknode($1,NULL,NULL); add('C');} 
	 ;

nothing:  {$$=NULL;}; 



%%

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
		
		printf("Scopes \n");
	for(j = 0; j <= count_scope_stack_elements; j++){
		printf("%s \n" , scopeStack[j].scope_name);
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

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", count_line+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "NONE"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "INT") && !strcmp(type2, "REAL"))
		return 1;
	if(!strcmp(type1, "REAL") && !strcmp(type2, "INT"))
		return 2;
	if(!strcmp(type1, "INT") && !strcmp(type2, "CHAR"))
		return 3;
	if(!strcmp(type1, "CHAR") && !strcmp(type2, "INT"))
		return 4;
	if(!strcmp(type1, "REAL") && !strcmp(type2, "CHAR"))
		return 5;
	if(!strcmp(type1, "CHAR") && !strcmp(type2, "REAL"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count_symbol_table_line; i++) {
		// Handle case of use before declaration
		if(!strcmp(scopeStack[current_scope_stack_top].symbol_table[i].id_name, var)) {
			return scopeStack[current_scope_stack_top].symbol_table[i].data_type;
		}
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

			printf("%s\n", yytext);

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

			printf("%s\n", yytext);

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

	/* if(scopeStack[current_scope_stack_top].is_function == 1) {

	} */

}


void add_to_param_count() {

	if(strcmp(scopeStack[current_scope_stack_top].scope_name, "main")== 0) {
		sprintf(errors[sem_errors], "Line %d: Main can't accept arguments \n", count_line+1);
		sem_errors++;
	}else{
		scopeStack[current_scope_stack_top].param_count ++;
		printf("Count new func params %s %d\n", scopeStack[current_scope_stack_top].scope_name, scopeStack[current_scope_stack_top].param_count);
	} 
	
}

void set_param_count(const char * name) {
	int i;
	for( i = current_scope_stack_top; i >=0; i--) {
		if(strcmp(scopeStack[i].scope_name, name) == 0) {
			param_count_current = scopeStack[i].param_count;
		}
	
	}

	printf("Paramer count %s %d\n", name ,param_count_current);
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
	printf("EndScope : %s %d\n" , scopeStack[current_scope_stack_top].scope_name, current_scope_stack_top);
	current_scope_stack_top = scopeStack[current_scope_stack_top].parent;
	count_symbol_table_line = scopeStack[current_scope_stack_top].last_index;
	printf("NewScope : %s %d\n",  scopeStack[current_scope_stack_top].scope_name, current_scope_stack_top);
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

