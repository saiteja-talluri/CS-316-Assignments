%{
#include "parser.tab.h"
#include "storetokens.hh"
int lineno = 1;
%}

digit [0-9]
operator [-+*/]
whitespaces [\t ]
int_number {digit}+
double_number {digit}*.{digit}+

%%

whitespaces;

int_number  { 
				store_token_name("INTEGER_NUMBER",yytext,lineno); 
				yyval.integer_value = atoi(yytext);
				return INTEGER_NUMBER;
			}

double_number
		    { 
				store_token_name("DOUBLE_NUMBER",yytext,lineno); 
				yyval.double_value = atof(yytext);
				return DOUBLE_NUMBER;
			}

void 		{ 
			`	store_token_name("VOID",yytext,lineno); 
				yyval.string_value = yytext;
			   	return VOID;
			}

int 		{ 
				store_token_name("INT",yytext,lineno); 
			   	return INT;
			}

float 		{ 
				store_token_name("INT",yytext,lineno); 
			   	return INT;
			}

\n 			{
				lineno++;
			}
