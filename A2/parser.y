%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern "C" void yyerror(char *s);
	extern int yylex(void);
%}

%union {
	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
}

%token <integer_value> INTEGER_NUMBER
%token <double_value> DOUBLE_NUMBER
%token <string_value> NAME
%token BBNUM  RETURN  INTEGER  FLOAT  ASSIGN  VOID  UMINUS

%left '+' '-'
%left '*' '/'
%right UMINUS

%start program

%%

program					:	optional_variable_declaration_list procedure_definition
							{};

procedure_definition	:	VOID NAME '(' ')'
                  	   		'{'
									optional_variable_declaration_list
	                        		statement_list
        	           		'}' 
        	           		{};


optional_variable_declaration_list	:	/* empty */ 
										|	variable_declaration_list
										;

variable_declaration_list			:	variable_declaration 
										|	variable_declaration_list variable_declaration
										;

variable_declaration				:	declaration ';'
										;

declaration							:	INTEGER variable_list 
										| FLOAT variable_list
                                        ;

variable_list                       :	NAME  {INSERT $1 IN SYMBOL TABLE}
										| variable_list ',' NAME {INSERT $3 IN SYMBOL TABLE}
										;


statement_list	        :	/* empty */ 
							|	statement_list assignment_statement
							;

assignment_statement	:	NAME ASSIGN expression ';'
							;

expression				: 	INTEGER_NUMBER
							| DOUBLE_NUMBER 
							| NAME 
							| expression '+' expression 
							| expression '*' expression 
							| expression '-' expression 
							| expression '/' expression 
							| '('expression')'
							;
%%

int yyerror (char *msg)
{
	fprintf (stderr, "%s\n", msg);
}