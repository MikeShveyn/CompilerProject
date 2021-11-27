/*lex program to count number of words*/
%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"
%}

/* Rules Section*/
%%
[0-9]+ {return NUM;}
"+"  {return PLUS;}
"-"  {return MINUS;}
%%
