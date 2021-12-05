/*Scanner-file*/
%{
#include<stdio.h>
#include "y.tab.h"
%}

%%
  /*TYPES*/
bool {return BOOL;}
char {return CHAR;}
char\* {return CHAR_P;}
int {return INT;}
int\* {return INT_P;}
real {return REAL;}
real\* {return REAL_P;}
string {return STRING;}
void {return VOID;}


  /*STATMENTS*/
if {return IF;}
else {return ELSE;}
do {return DO;}
while {return WHILE;}
for {return FOR;}
var {return VAR;}
return {return RETURN;}

  /*OPERATORS*/
"&&" {return AND;}
"/" {return DIVISION;}
"=" {return ASSIGNMENT;}
"==" {return EQL;}
">" {return GREATER;}
">=" {return GREATER_EQL;}
"<" {return LESS;}
"<=" {return LESS_EQL;}
"-" {return MINUS;}
"!" {return NOT;}
"!=" {return NOT_EQL;}
"||" {return OR;}
"+" {return PLUS;}
"*" {return MULTIPLY;}
"&" {return ADDRESS;}

  /*OTHER LEXEMES*/
"|" {return LENGTH;}
";" {return SEMICOLON;}
":" {return COLON;}
"," {return COMMA;}
"{" {return OPEN_CURLY_BRACES;}
"}" {return CLOSE_CURLY_BRACES;}
"(" {return OPEN_ANGLE_BRACES;}
")" {return CLOSE_ANGLE_BRACES;}
"[" {return OPEN_SQUARE_BRACES;}
"]" {return CLOSE_SQUARE_BRACES;}
 
 "/*"([^*]*|(\*+[^/]))*"*/" {return COMMENT;}

  /*Literl*/
null {return NONE;}  
"true" {return BOOL_TRUE;}
"false" {return BOOL_FALSE;}
\'.\' {yylval.str= strdup(yytext); return CHAR_LITERAL;}
"\""[^"]*"\"" {yylval.str = strdup(yytext); return STRING_LITERAL;}
[+-]?[1-9][0-9]*|[0-9] {yylval.str= strdup(yytext); return DECIMAL_LITERAL;}
0(x|X)[0-9A-F]+ {yylval.str= strdup(yytext); return HEX_LITERAL;}
[-+]?[0-9]*\.?[0-9]*[eE]?[-+]?[0-9]+ {yylval.str= strdup(yytext); return REAL_LITERAL;}
[a-zA-Z][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return VARIABLE_ID;} 

[\n] {yylineno++;}
[ \t]+ ;

. return yytext[0];
%%

