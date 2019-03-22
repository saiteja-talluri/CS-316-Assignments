#include "symbol-table.hh"
#include "ast.hh"
#include "local-environment.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;

Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register) {

}


Code_For_Ast & Assignment_Ast::compile() {

}


Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}


Code_For_Ast & Name_Ast::compile() {

}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register) {

}




Code_For_Ast & Arithmetic_Expr_Ast::compile() {

}
Code_For_Ast & Arithmetic_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}

Code_For_Ast & Plus_Ast::compile() {

}
Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}


Code_For_Ast & Minus_Ast::compile() {

}
Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}

Code_For_Ast & Divide_Ast::compile() {

}
Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}

Code_For_Ast & Mult_Ast::compile() {

}
Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}

Code_For_Ast & UMinus_Ast::compile() {

}
Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}


Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {

}


Code_For_Ast & Logical_Expr_Ast::compile() {

}
Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {

}



Code_For_Ast & Selection_Statement_Ast::compile() {

}
Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {

}

Code_For_Ast & Iteration_Statement_Ast::compile() {

}
Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {

}










