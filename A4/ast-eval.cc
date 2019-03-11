#include "symbol-table.hh"
#include "ast.hh"
#include "local-environment.hh"

void Symbol_Table::create(Local_Environment & local_global_variables_table){
    list<Symbol_Table_Entry*>::iterator it;
    for(it = this->variable_table.begin(); it != this->variable_table.end(); it++) {
        Eval_Result *er;
        if((*it)->get_data_type() == int_data_type) {
            er = new Eval_Result_Value_Int();
            er->set_variable_status(0);
            local_global_variables_table.put_variable_value(*er, (*it)->get_variable_name());
        }
        else if((*it)->get_data_type() == double_data_type) {
            er = new Eval_Result_Value_Double();
            er->set_variable_status(0);
            local_global_variables_table.put_variable_value(*er, (*it)->get_variable_name());
        }
    }
}