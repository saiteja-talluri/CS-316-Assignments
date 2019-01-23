%{
#include "parser.tab.h"
#include "storetokens.hh"
#include <stdlib.h>
#include <string>
int lineno = 1;
%}

digit [0-9]
operator [-+*/]
whitespaces [\t ]
newline	[\n]
int_number [0-9]+
double_number {digit}*\.{digit}+
int_type int
float_type float
sl_comment \/[\/]+.*
name [a-zA-Z][a-zA-Z0-9]*
void_kw void
char .
assign =

%%

{whitespaces} {}


{int_number}  { 
				cout<<yytext<<endl;
				store_token_name("NUM",yytext,lineno); 
				yylval.integer_value = atoi(yytext);
				return INTEGER_NUMBER;
			}

{double_number} { 
				cout<<yytext<<endl;
		    	store_token_name("FNUM",yytext,lineno);
				yylval.double_value = atof(yytext);
				return DOUBLE_NUMBER;
			}

{int_type}	{
				cout<<yytext<<endl;
				store_token_name("INTEGER",yytext,lineno); 
			   	return INTEGER;
			}

{float_type}	{
				cout<<yytext<<endl;
				store_token_name("FLOAT",yytext,lineno); 
			   	return FLOAT;
			}

{sl_comment}	{}

{assign}	{
				cout<<yytext<<endl;
				store_token_name("ASSIGN_OP", yytext, lineno);
				return ASSIGN;
			}

{void_kw} 	{ 
				cout<<yytext<<endl;
				store_token_name("VOID",yytext,lineno); 
			   	return VOID;
			}

{name}  	{
				cout<<yytext<<endl;
				store_token_name("NAME", yytext, lineno);
				yylval.string_value = new string;
				*yylval.string_value = yytext;
				return NAME;
			}

{operator} 	{
				cout<<yytext<<endl;
				store_token_name("ARITHOP",yytext,lineno);
				return yytext[0];
			}

{char}		{
				cout<<yytext<<endl;
				store_token_name("META CHAR",yytext,lineno);
				return yytext[0];
			}

{newline} 	{
				lineno++;
			}

%%