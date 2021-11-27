
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define YYSTYPE struct  node*
#include "lex.yy.c"
int yylex();
int yyerror(const char *s);

typedef struct node
{
char *token;
struct node *left;
struct node *right;
} node;

node *mknode(char *token,node *left,node *right);
void printtree(node *tree);

%}

%token PLUS MINUS NUM
%left PLUS MINUS

%%
S: exp { printf("ok\n"); printtree($1); }

exp: exp PLUS exp {$$=mknode("+",$1,$3);}
   | exp MINUS exp {$$=mknode("-",$1,$3);}
        | NUM {$$ = mknode(yytext,NULL,NULL);};
%%

int  main (){
return yyparse();
}
int yyerror(const char *s){printf("error");return 0;}
int yywrap(){return 1;}

node *mknode(char *token,node *left,node *right)
{
node *newnode = (node*)malloc(sizeof(node));
char *newstr = (char*)malloc(sizeof(token)+1);
strcpy(newstr,token);
newnode->left=left;
newnode->right=right;
newnode->token=newstr;
return newnode;
}

void printtree(node *tree)
{
printf("%s\n",tree->token);
if(tree->left)
        {printtree(tree->left);}
if(tree->right)
        {printtree(tree->right);}
}


