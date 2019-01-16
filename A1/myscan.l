%{
#include "parser.tab.h"
#include "storetokens.hh"
int lineno = 1;
%}

digit [0-9]
operator [-+*/]

%%
\n {lineno++;}
{digit}+    { store_token_name("INTERGER_NUMBER",yytext,lineno); }
