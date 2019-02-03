%{
	#include <stdio.h>
	extern "C" void yyerror (char *);
%}

%token INTEGER_NAME
%token BBNUM
%token DOUBLE_NUMBER
%token NAME
%token RETURN
%token INTEGER
%token FLOAT
%token ASSIGN
%token VOID
%token UMINUS

%%

program					:	declaration_list procedure_definition
							{};

declaration_list		:	procedure_declaration |	variable_declaration_list procedure_declaration | procedure_declaration variable_declaration_list
							{};

procedure_declaration	:	VOID NAME '(' ')' ';' 
							{};

procedure_definition	:	NAME '(' ')'
                  	   		'{'
									optional_variable_declaration_list
	                        		statement_list
        	           		'}' 
        	           		{};


