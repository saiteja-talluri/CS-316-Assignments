#include "symbol-table.hh"
#include "ast.hh"
#include "local-environment.hh"


void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}

Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env) {
    /* TODO: */
}

void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result) {
    /* TODO: */
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

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */   
}

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}


Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
    /* TODO: */
}

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}


Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
    /* TODO: */
}

void Symbol_Table::create(Local_Environment & local_global_variables_table){
    list<Symbol_Table_Entry*>::iterator it;
    for(it = this->variable_table.begin(); it != this->variable_table.end(); it++) {
        Eval_Result *er;
        if((*it)->get_data_type() == int_data_type) {
            er = new Eval_Result_Value_Int();
            er->set_variable_status(0);
            if((*it)->get_symbol_scope() == global)
                er->set_value(0);
            local_global_variables_table.put_variable_value(*er, (*it)->get_variable_name());
        }
        else if((*it)->get_data_type() == double_data_type) {
            er = new Eval_Result_Value_Double();
            er->set_variable_status(0);
            if((*it)->get_symbol_scope() == global)
                er->set_value(0);
            local_global_variables_table.put_variable_value(*er, (*it)->get_variable_name());
        }
    }
}