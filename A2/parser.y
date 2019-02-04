%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern "C" void yyerror(char *s);
	extern int yylex(void);
	list<Symbol_Table_Entry> entry_list;
	Symbol_Table global_sym_table;
	Symbol_Table local_sym_table;
	Procedure main_proc = Procedure(void_data_type,"main", 0); /* TODO: Need to get the line number some how */ 
	list<Ast *>  our_ast_list;
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
	list<Symbol_Table_Entry *> * symbol_entry_list;
}

%token <integer_value> INTEGER_NUMBER
%token <double_value> DOUBLE_NUMBER
%token <string_value> NAME
%token BBNUM  RETURN  INTEGER  FLOAT  ASSIGN  VOID  UMINUS

%type <symbol_entry_list> variable_list

%left '+' '-'
%left '*' '/'
%right UMINUS

%start program

%%

program					:	optional_variable_declaration_list procedure_definition
							{
								for(list<Symbol_Table_Entry>::iterator it = entry_list.begin(); it != entry_list.end(); it++) {
									it->set_symbol_scope(global);
									global_sym_table.push_symbol(&(*it));
								}
								program_object.set_global_table(global_sym_table);
								program_object.set_procedure(&main_proc, 0); /* TODO : Need to get the line number some how */
							}
							;

procedure_definition	:	VOID NAME '(' ')'
                  	   		'{'
									optional_variable_declaration_list statement_list
        	           		'}' 
							{	
								for(list<Symbol_Table_Entry>::iterator it = entry_list.begin(); it != entry_list.end(); it++) {
									it->set_symbol_scope(local);
									local_sym_table.push_symbol(&(*it));
								}
								main_proc.set_local_list(local_sym_table);
								main_proc.set_ast_list(our_ast_list);
							}
        	           		;


optional_variable_declaration_list	:	/* empty */ 
										|	variable_declaration_list
										;

variable_declaration_list			:	variable_declaration 
										|	variable_declaration_list variable_declaration
										;

variable_declaration				:	declaration ';'
										;

declaration							:	INTEGER variable_list
										{
											for(list<Symbol_Table_Entry>::iterator it = entry_list.begin(); it != entry_list.end(); it++) {
												it->set_data_type(int_data_type);
											}
										}
										| FLOAT variable_list 
										{
											for(list<Symbol_Table_Entry>::iterator it = entry_list.begin(); it != entry_list.end(); it++) {
												it->set_data_type(double_data_type);
											}
										}
                                        ;

variable_list                       :	NAME	
										{
											Symbol_Table_Entry x = Symbol_Table_Entry(*$1,int_data_type,0);
											entry_list.push_back(x);
										} /* TODO: Line number needs to be added */
										| variable_list ',' NAME
										{
											Symbol_Table_Entry x = Symbol_Table_Entry(*$3,int_data_type,0);
											entry_list.push_back(x);
										} /* TODO: Line number needs to be added */
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