#include "ast.hh"
#include "local-environment.hh"
#include <stdlib.h> //to use exit()
template class Number_Ast<double>;
template class Number_Ast<int>;

#include "symbol-table.hh"




Ast::Ast(){}

Ast::~Ast(){}

int Ast::labelCounter;

Data_Type Ast::get_data_type(){
    return node_data_type;
}

void Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Ast::is_value_zero() {
    return false;
    //TODO: I'm writing this to mitigate errors in check_ast.
}

bool Ast::check_ast(){}

Symbol_Table_Entry & Ast::get_symbol_entry(){}

void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}

Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env) {
    /* TODO: */
}

void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result) {
    /* TODO: */
}

Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line){
    lhs = temp_lhs;
    rhs = temp_rhs;
    lineno = line;
    ast_num_child = binary_arity;
    node_data_type = lhs->get_data_type();
}

Assignment_Ast::~Assignment_Ast(){
    delete lhs;
    delete rhs;
}

bool Assignment_Ast::check_ast(){
    if((lhs->get_data_type() == rhs->get_data_type()) || rhs->is_value_zero()){
        node_data_type = lhs->get_data_type();
        return true;
    }
    else{
        cerr << "cs316: Error: Line "<<lineno<<": Data Type not compatabile in the assignment\n";
        exit(EXIT_FAILURE);
        return false;
        //Should exit here right?
    }
}

void Assignment_Ast::print(ostream & file_buffer){
    file_buffer << "\n         Asgn:\n            LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n            RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
    string lhs = this->lhs->get_symbol_entry().get_variable_name();
    
    file_buffer<<"Asgn:\n";
    file_buffer<<"\tLHS (Name : "<<lhs<<")\n";
    file_buffer<<"\tRHS (NUM : ";
    Eval_Result *rhs = this->rhs->evaluate(eval_env, file_buffer);
    eval_env.put_variable_value(*rhs, lhs);
    return *rhs;
}


Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line){
    variable_symbol_entry = &var_entry;
    set_data_type(var_entry.get_data_type());
    lineno = line;
}

Name_Ast::~Name_Ast(){}

Data_Type Name_Ast::get_data_type(){
    return node_data_type;
}

Symbol_Table_Entry & Name_Ast::get_symbol_entry(){
    return *variable_symbol_entry;
}

void Name_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

void Name_Ast::print(ostream & file_buffer){
    file_buffer << "Name : " << variable_symbol_entry->get_variable_name();
}

void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer) {
    string name = this->variable_symbol_entry->get_variable_name();
    if(eval_env.get_variable_value(name)->get_result_enum() == int_result)
        file_buffer << name << " : " << eval_env.get_variable_value(name)->get_int_value();
    else
        file_buffer << name << " : " << eval_env.get_variable_value(name)->get_double_value();
    file_buffer<<"\n";
}

Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env) {
    string name = this->variable_symbol_entry->get_variable_name();
    // if(eval_env.is_variable_defined(name)) {
    return *eval_env.get_variable_value(name);
    // }
}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result) {
    string name = this->variable_symbol_entry->get_variable_name();
    if(eval_env.does_variable_exist(name)) {
        eval_env.put_variable_value(result, name);
    }
    
}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: what is expected here? */
    
    print_value(eval_env, file_buffer);
    return get_value_of_evaluation(eval_env);
}


template <class T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line){
    constant = number;
    node_data_type = constant_data_type;
    lineno = line;
}

template <class T>
Number_Ast<T>::~Number_Ast(){}

template <class T>
Data_Type Number_Ast<T>::get_data_type(){
    return node_data_type;
}

template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt){
    node_data_type = dt;
}

template <class T>
bool Number_Ast<T>::is_value_zero(){
    if(constant == 0)
        return true;
    else
        return false;
}

template <class T>
void Number_Ast<T>::print(ostream & file_buffer){
    file_buffer << "Num : " << constant;
}

template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
    Eval_Result *res
    if(get_data_type() == int_data_type)
        res = new Eval_Result_Value_Int();
    else if(get_data_type() == double_data_type)
        res = new Eval_Result_Value_Double();
    eval_env.put_variable_value(constant, *res);
    return *res;
}


Data_Type Arithmetic_Expr_Ast::get_data_type(){
    return node_data_type;
}


void Arithmetic_Expr_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast(){
    // cerr<<"arith check "<<lhs->get_data_type()<<" "<<rhs->get_data_type()<<endl;
    if(ast_num_child == binary_arity){
        if((lhs->get_data_type() == rhs->get_data_type()) || rhs->is_value_zero()){
            node_data_type = lhs->get_data_type();
            return true;
        }
        else{
            cerr << "cs316: Error: Line "<<lineno<<": Data Type not compatabile in arithmetic expression\n";
            exit(EXIT_FAILURE);
            return false;
        }
    }
    else{
        return true;
    }
}


Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Plus_Ast::print(ostream & file_buffer){
    file_buffer << "\n            Arith: PLUS\n               LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n               RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
    Eval_Result *res;
    
    file_buffer << "Arith: PLUS\n";
    file_buffer << "LHS ( ";
    Eval_Result *lhs_res = lhs->evaluate(eval_env, file_buffer);
    file_buffer << "\n";
    file_buffer << "RHS ";
    Eval_Result *rhs_res = rhs->evaluate(eval_env, file_buffer);
    file_buffer << ")\n";
    if(get_data_type() == int_data_type) {
        res = new Eval_Result_Value_Int();
        res->set_value(lhs_res->get_int_value() + rhs_res->get_int_value());
    }
    else {
        res = new Eval_Result_Value_Double();
        res->set_value(lhs_res->get_double_value() + rhs_res->get_double_value());
    }

    return *res;

}

Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Minus_Ast::print(ostream & file_buffer){
    file_buffer << "\n            Arith: MINUS\n               LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n               RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */

    
}

Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Divide_Ast::print(ostream & file_buffer){
    file_buffer << "\n            Arith: DIV\n               LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n               RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}


Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Mult_Ast::print(ostream & file_buffer){
    file_buffer << "\n            Arith: MULT\n               LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n               RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}


UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = unary_arity;
}

void UMinus_Ast::print(ostream & file_buffer){
    file_buffer << "\n            Arith: UMINUS\n               LHS (";
    lhs->print(file_buffer);
    file_buffer <<")";
}

Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}


Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* cond, Ast* l, Ast* r, int line){
    lhs = l;
    rhs = r;
    cond = cond;
    ast_num_child = ternary_arity;
}

Conditional_Expression_Ast::~Conditional_Expression_Ast(){
    /* TODO: */
}

void Conditional_Expression_Ast::print(ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Return_Ast::Return_Ast(int line){
    lineno = line;
    ast_num_child = zero_arity;
}

Return_Ast::~Return_Ast(){}

void Return_Ast::print(ostream & file_buffer){}

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Relational_Expr_Ast::Relational_Expr_Ast(Ast * lhs, Relational_Op rop, Ast * rhs, int line){
    lhs_condition = lhs;
    rhs_condition = rhs;
    rel_op = rop;
    lineno = line;
    ast_num_child = binary_arity;
}

Relational_Expr_Ast::~Relational_Expr_Ast(){
    /* TODO: */
}

Data_Type Relational_Expr_Ast::get_data_type(){
    return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Relational_Expr_Ast::check_ast(){
    /* TODO: */
}

void Relational_Expr_Ast::print(ostream & file_buffer){
    /* TODO: */
}


Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}


Logical_Expr_Ast::Logical_Expr_Ast(Ast * lhs, Logical_Op bop, Ast * rhs, int line){
    lhs_op = lhs;
    rhs_op = rhs;
    bool_op = bop;
    lineno = line;
    ast_num_child = binary_arity;
}

Logical_Expr_Ast::~Logical_Expr_Ast(){
    /* TODO: */
}

Data_Type Logical_Expr_Ast::get_data_type(){
    return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Logical_Expr_Ast::check_ast(){
    /* TODO: */
}

void Logical_Expr_Ast::print(ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}


Selection_Statement_Ast::Selection_Statement_Ast(Ast * cond,Ast* then_part, Ast* else_part, int line){
    cond = cond;
    then_part = then_part;
    else_part = else_part;
    lineno = line;
    ast_num_child = ternary_arity;
}

Selection_Statement_Ast::~Selection_Statement_Ast(){
    /* TODO: */
}

Data_Type Selection_Statement_Ast::get_data_type(){
    return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Selection_Statement_Ast::check_ast(){
    /* TODO: */
}

void Selection_Statement_Ast::print(ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}


Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * cond, Ast* body, int line, bool do_form){
    cond = cond;
    body = body;
    is_do_form = do_form;
    lineno = line;
    ast_num_child = binary_arity;
}

Iteration_Statement_Ast::~Iteration_Statement_Ast(){
    /* TODO: */
}

Data_Type Iteration_Statement_Ast::get_data_type(){
    return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Iteration_Statement_Ast::check_ast(){
    /* TODO: */
}

void Iteration_Statement_Ast::print(ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Sequence_Ast::Sequence_Ast(int line){
    lineno = line;
}

Sequence_Ast::~Sequence_Ast(){
    /* TODO: */
}

void Sequence_Ast::ast_push_back(Ast * ast){
    statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}