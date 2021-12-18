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

	/*  Semantic  */
	void add(char);
    void insert_type();
    int search(char *);
	 void check_declaration(char *);
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	int sem_errors=0;
	int label=0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};

	struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    int count=0;
    int q;
    char type[10];
    extern int countn;

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
%type<node> init update integer_literal variable_declaration variableL atributeList string_exp string_array temp



%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQL NOT_EQL LESS LESS_EQL GREATER_EQL GREATER 
%left OR AND
%left SEMICOLON COMMA
%right NOT ADDRESS ASSIGNMENT 


/*  !!! TODO ADD POINTERS AND THIK ABOUT UNARY OPERATORS  STRINGS  ARRAYS COMMENTS !!! */

%%
program: code {head = $1;};

code:
	   function code  { $$ = mknode("",$1, $2); }
	 | function   { $$ = mknode("",$1, NULL);}
	 ;  

 /* FUNCTION  */
function:
	   type VARIABLE_ID {add('F'); } OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func return CLOSE_CURLY_BRACES   
	   {
 			 $$=mknode("FUNC",mknode($2,mknode("\n",NULL,NULL), mknode("",mknode("ARGS",$5, NULL) ,mknode("RET",$1, NULL))) ,mknode("BODY",$8,$9));
	   }
	 
	 | VOID VARIABLE_ID {add('F');}  OPEN_ANGLE_BRACES parameter_list CLOSE_ANGLE_BRACES  OPEN_CURLY_BRACES body_func CLOSE_CURLY_BRACES 
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
	   | variable_declaration {$$ = mknode("",$1, NULL); }
	   | string_array {$$ = mknode("STRING",$1, NULL); }
	   ;
	   
variable_declaration:
	  VAR  type  VARIABLE_ID {add('V');} temp {$$ = mknode("VAR",$2, mknode($3, $5, NULL));}
	;

temp:
	 SEMICOLON {$$=mknode("",NULL,NULL);}
	|ASSIGNMENT exp SEMICOLON {$$=mknode("",$2,NULL);}
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

code_block: OPEN_CURLY_BRACES body CLOSE_CURLY_BRACES  {$$=mknode("CODE_BLOCK",$2,NULL);};

conditions: 
	  IF {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block  { $$=mknode("IF",$4,$6);}
	| IF {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block ELSE {add('K');} code_block { $$=mknode("IF-ELSE", mknode("",$4,$6), mknode("",$9,NULL));}
	;

loops:
	  WHILE {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES code_block {  $$=mknode("WHILE",$4,$6);}
	| DO  code_block WHILE {add('K');} OPEN_ANGLE_BRACES exp CLOSE_ANGLE_BRACES SEMICOLON{  $$=mknode("DO-WHILE",$2,$6);}
	| FOR {add('K');} OPEN_ANGLE_BRACES init SEMICOLON exp SEMICOLON update CLOSE_ANGLE_BRACES code_block { $$=mknode("FOR",mknode("INIT", $4, mknode("COND", $6, mknode("UPDATE",$8, NULL))),$10);}
	;  

assignment_statement: lhs  ASSIGNMENT expressions SEMICOLON {$$=mknode("=",$1,$3); };

lhs:
	   VARIABLE_ID {$$=mknode($1,NULL,NULL);}
	 | VARIABLE_ID OPEN_SQUARE_BRACES exp CLOSE_SQUARE_BRACES {$$=mknode($1,$3,NULL);}
	 ;

init:  lhs ASSIGNMENT integer_literal {$$=mknode("=",$1,$3);};
	
update: lhs ASSIGNMENT exp {$$=mknode("=",$1,$3);};

return: RETURN { add('K'); } exp SEMICOLON { $$=mknode("RET-VAL",$3,NULL);} ;

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
	  BOOL { insert_type(); $$=mknode("BOOL",NULL,NULL);} 
	| CHAR {$$=mknode("CHAR",NULL,NULL); insert_type();} 
	| CHAR_P {$$=mknode("CHAR_P",NULL,NULL); insert_type();} 
	| INT { insert_type(); $$=mknode("INT",NULL,NULL);} 
	| INT_P {$$=mknode("INT_P",NULL,NULL); insert_type();} 
	| REAL {$$=mknode("REAL",NULL,NULL); insert_type();} 
	| REAL_P {$$=mknode("REAL_P",NULL,NULL); insert_type();} 
	| STRING {$$=mknode("STRING",NULL,NULL); insert_type();} 
	;

primitiveType: 
	 NONE {$$=mknode("None",NULL,NULL); add('C');} 
	 |BOOL_TRUE {$$=mknode("True",NULL,NULL); add('K'); } 
	 |BOOL_FALSE  {$$=mknode("False",NULL,NULL); add('K'); } 
	 | CHAR_LITERAL {$$=mknode($1,NULL,NULL); add('C');} 
	 | DECIMAL_LITERAL  {$$=mknode($1,NULL,NULL); add('C');} 
	 | HEX_LITERAL {$$=mknode($1,NULL,NULL); add('C');} 
	 | REAL_LITERAL  {$$=mknode($1,NULL,NULL); add('C');} 
	 | STRING_LITERAL {$$=mknode($1,NULL,NULL); add('C');} 
	 ;

integer_literal:
	   DECIMAL_LITERAL  {$$=mknode($1,NULL,NULL); add('C');} 
	 | HEX_LITERAL {$$=mknode($1,NULL,NULL); add('C');} 
	 ;

nothing:  {$$=NULL;}; 


%%

int main() {
    yyparse();
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	/* print_tree(head);  */
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
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
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
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void add(char c) {
	if(c == 'V'){
		for(int i=0; i<10; i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
	if(!q) {
		if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
    }
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
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

