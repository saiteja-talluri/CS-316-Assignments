#include "ast.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;

Ast::Ast(){}

Ast::~Ast(){}

Data_Type Ast::get_data_type(){
    return node_data_type;
}

void Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Ast::is_value_zero(){}

bool Ast::check_ast(){}

Symbol_Table_Entry & Ast::get_symbol_entry(){}



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
        cout << "cs316: Error: Data Type not compatabile in the assignment\n";
        return false;
    }
}

void Assignment_Ast::print(ostream & file_buffer){
    file_buffer << "\n         Asgn:\n            LHS (";
    lhs->print(file_buffer);
    file_buffer << ")\n            RHS (";
    rhs->print(file_buffer);
    file_buffer <<")";
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



Data_Type Arithmetic_Expr_Ast::get_data_type(){
    return node_data_type;
}


void Arithmetic_Expr_Ast::set_data_type(Data_Type dt){
    node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast(){
    if(ast_num_child == binary_arity){
        if((lhs->get_data_type() == rhs->get_data_type()) || rhs->is_value_zero()){
            node_data_type = lhs->get_data_type();
            return true;
        }
        else{
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


Return_Ast::Return_Ast(int line){
    lineno = line;
    ast_num_child = zero_arity;
}

Return_Ast::~Return_Ast(){}

void Return_Ast::print(ostream & file_buffer){}