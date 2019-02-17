#include "ast.hh"

template class Number_Ast<double>;
template class Number_Ast<int>;

Data_type Ast::get_data_type(){
    return node_data_type;
}

void Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Ast::is_value_zero(){
    return false;
    // TODO : Need to check what this function does and where it is used.
}

bool Ast::check_ast(){

}

Symbol_Table_Entry & Ast::get_symbol_entry(){

}

/*********************************   Assignment Ast   *****************************/

Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line){
    lhs = temp_lhs;
    rhs = temp_rhs;
    lineno = line;
    ast_num_child = binary_arity; // TODO: Confirm about this
}

Assignment_Ast::~Assignment_Ast(){
    free(lhs);
    free(rhs);
}

bool Assignment_Ast::check_ast(){
    if(lhs->check_ast() && rhs->check_ast() && (lhs->get_data_type() == rhs->get_data_type())){
        node_data_type = lhs->get_data_type();
        return true;
    }
    else{
        return false;
    }
}

void Assignment_Ast::print(ostream & file_buffer){

}

/*********************************   Name Ast   *****************************/

Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line){
    variable_symbol_entry = var_entry;
    lineno = line;
}

Name_Ast::~Name_Ast(){

}

Data_Type Name_Ast::get_data_type(){
    return node_data_type;
}

Symbol_Table_Entry & Name_Ast::get_symbol_entry(){
    return variable_symbol_entry;
}

void Name_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

void Name_Ast::print(ostream & file_buffer){
    
}

/*********************************   Number Ast   *****************************/

template <class T>
Number_Ast::Number_Ast(T number, Data_Type constant_data_type, int line){
    constant = number;
    node_data_type = constant_data_type;
    lineno = line;
}

/*********************************   Arithmetic Ast   *****************************/

Data_Type Arithmetic_Expr_Ast::get_data_type(){
    return node_data_type;
}


void Arithmetic_Expr_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast(){
    if(lhs->check_ast() && rhs->check_ast() && (lhs->get_data_type() == rhs->get_data_type())){
        node_data_type = lhs->get_data_type();
        return true;
    }
    else{
        return false;
    }
}

/*********************************   Plus Ast   *****************************/

Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Plus_Ast::print(ostream & file_buffer){
    
}

/*********************************   Minus Ast   *****************************/

Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Minus_Ast::print(ostream & file_buffer){
    
}

/*********************************   Divide Ast   *****************************/

Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Divide_Ast::print(ostream & file_buffer){
    
}

/*********************************   Mult Ast   *****************************/

Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = binary_arity;
}

void Mult_Ast::print(ostream & file_buffer){
    
}

/*********************************   UMinus Ast   *****************************/

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line){
    lhs = l;
    rhs = r;
    lineno = line;
    ast_num_child = unary_arity;
}

void UMinus_Ast::print(ostream & file_buffer){
    
}

/*********************************   Return Ast   *****************************/

Return_Ast::Return_Ast(int line){
    lineno = line;
    ast_num_child = zero_arity;
}

Return_Ast::~Return_Ast(){

}

void Return_Ast::print(ostream & file_buffer){
    
}

/*********************************   End of file   *****************************/