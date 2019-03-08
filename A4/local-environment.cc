#include "local-environment.hh"
#include <iostream>

int Eval_Result::get_int_value() {}
void Eval_Result::set_value(int value) {}
double Eval_Result::get_double_value() {}
void Eval_Result::set_value(double value) {}

bool Eval_Result::is_variable_defined() {}
void Eval_Result::set_variable_status(bool def) {}
void Eval_Result::set_result_enum(Result_Enum) {}


int Eval_Result_Value::get_int_value() {}
void Eval_Result_Value::set_value(int value) {}
double Eval_Result_Value::get_double_value() {}
void Eval_Result_Value::set_value(double value) {}

bool Eval_Result_Value::is_variable_defined() {}
void Eval_Result_Value::set_variable_status(bool def) {}
void Eval_Result_Value::set_result_enum(Result_Enum) {}





Eval_Result_Value_Int::Eval_Result_Value_Int() {}

Eval_Result_Value_Int::~Eval_Result_Value_Int() {}

int Eval_Result_Value_Int::get_int_value() {
    return value;
}

void Eval_Result_Value_Int::set_value(int value) {
    value = value;
}

void Eval_Result_Value_Int::set_value(double value) {
    //????
    value = (int)value;
}

void Eval_Result_Value_Int::set_variable_status(bool def) {
    defined = def;
}

bool Eval_Result_Value_Int::is_variable_defined() {
    return defined;
}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res) {
    result_type = res;
}

Result_Enum Eval_Result_Value_Int::get_result_enum() {
    return result_type;
}






Eval_Result_Value_Double::Eval_Result_Value_Double() {}

Eval_Result_Value_Double::~Eval_Result_Value_Double() {
    //???
}

double Eval_Result_Value_Double::get_double_value() {
    return value;
}

void Eval_Result_Value_Double::set_value(int value) {
    // ???
    value = (double)value;
}

void Eval_Result_Value_Double::set_value(double value) {
    value = value;
}

void Eval_Result_Value_Double::set_variable_status(bool def) {
    defined = def;
}

bool Eval_Result_Value_Double::is_variable_defined() {
    return defined;
}

void Eval_Result_Value_Double::set_result_enum(Result_Enum res) {
    result_type = res;
}

Result_Enum Eval_Result_Value_Double::get_result_enum() {
    return result_type;
}



Local_Environment::Local_Environment() {}
Local_Environment::~Local_Environment() {}

void Local_Environment::print(ostream& fb) {
    for(map<string, Eval_Result* >::iterator it = variable_table.begin(); it != variable_table.end(); it++) {
        fb << it->first ;
        fb << " " ;
        // fb << *(it->second);
        fb << "\n";
    }
}

bool Local_Environment::does_variable_exist(string name) {
    for(map<string, Eval_Result* >::iterator it = variable_table.begin(); it != variable_table.end(); it++) {
        if(it->first == name) return true;
    }
    return false;
}

Eval_Result *Local_Environment::get_variable_value(string name) {
    for(map<string, Eval_Result* >::iterator it = variable_table.begin(); it != variable_table.end(); it++) {
        if(it->first == name) return it->second;
    }
    return NULL;
}

void Local_Environment::put_variable_value(Eval_Result & value, string name) {
    variable_table[name] = &value;
}

bool Local_Environment::is_variable_defined(string name) {
    for(map<string, Eval_Result* >::iterator it = variable_table.begin(); it != variable_table.end(); it++) {
        if(it->first == name && it->second != NULL) return true;
    }
    return false;
}

