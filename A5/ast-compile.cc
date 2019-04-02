#include "symbol-table.hh"
#include "ast.hh"
#include "local-environment.hh"
#include "icode.hh"
#include "reg-alloc.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;

Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register) {

}
//TODO: release registers

Code_For_Ast & Assignment_Ast::compile() {
	Code_For_Ast rhs_res = rhs->compile();
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_res.get_reg());	
	Code_For_Ast lhs_res = this->lhs->create_store_stmt(rhs_result->get_reg());
	Code_For_Ast *output = new Code_For_Ast(rhs_res.get_icode_list(), rhs_res.get_reg());
	output->append_ics(*(lhs_res.get_icode_list().front()));
	return *output;
}


Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}


Code_For_Ast & Name_Ast::compile() {
	Mem_Addr_Opd *opd1  = new Mem_Addr_Opd(*this->variable_symbol_entry);
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Move_IC_Stmt *load_stmt;
	if(this->variable_symbol_entry->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		load_stmt = new Move_IC_Stmt(load, opd1, result);
	}
	else if(this->variable_symbol_entry->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		load_stmt = new Move_IC_Stmt(load_d, opd1, result);
	}
	Code_For_Ast *output = new Code_For_Ast();
	output->set_reg(rd);
	output->append_ics(*load_stmt);
	return *output;
}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register) {
	Register_Addr_Opd *result = new Register_Addr_Opd(store_register);
	Mem_Addr_Opd *opd1  = new Mem_Addr_Opd(*this->variable_symbol_entry);
	Move_IC_Stmt *store_stmt;
	Code_For_Ast *output = new Code_For_Ast();
	if(store_register->get_use_category() == int_reg) {
		store_stmt = new Move_IC_Stmt(store, result, opd1);
	}
	else if(store_register->get_use_category() == float_reg) {
		store_stmt = new Move_IC_Stmt(store_d, result, opd1);
	}
	output->set_reg(store_register);
	output->append_ics(*store_stmt);
	return *output;
}

template <class T>
Code_For_Ast & Number_Ast<T>::compile() {
	Const_Opd<T> *opd1  = new Const_Opd<T>(this->constant);
	Register_Descriptor *rd;
	Move_IC_Stmt *load_stmt;
	Register_Addr_Opd *result;
	if(this->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		load_stmt = new Move_IC_Stmt(imm_load, opd1, result);
	}
		
	else if(this->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		load_stmt = new Move_IC_Stmt(imm_load_d, opd1, result);
	}
	 
	Code_For_Ast *output = new Code_For_Ast();
	output->set_reg(rd);
	output->append_ics(*load_stmt);
	return *output;
}


template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}


Code_For_Ast & Plus_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs->compile(); 
	Code_For_Ast rhs_code =	this->rhs->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Compute_IC_Stmt *plus_stmt;
	if(this->lhs->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		plus_stmt = new Compute_IC_Stmt(add, lhs_result, rhs_result, result);
	}
	else if(this->lhs->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		plus_stmt = new Compute_IC_Stmt(add_d, lhs_result, rhs_result, result);
	}
	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->set_reg(rd);
	output->append_ics(*plus_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	rhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}


Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & Minus_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs->compile(); 
	Code_For_Ast rhs_code =	this->rhs->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Compute_IC_Stmt *minus_stmt;
	if(this->lhs->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		minus_stmt = new Compute_IC_Stmt(sub, lhs_result, rhs_result, result);
	}
	else if(this->lhs->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		minus_stmt = new Compute_IC_Stmt(sub_d, lhs_result, rhs_result, result);
	}
	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->set_reg(rd);
	output->append_ics(*minus_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	rhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}


Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & Divide_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs->compile(); 
	Code_For_Ast rhs_code =	this->rhs->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Compute_IC_Stmt *divide_stmt;
	if(this->lhs->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		divide_stmt = new Compute_IC_Stmt(divd, lhs_result, rhs_result, result);
	}
	else if(this->lhs->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		divide_stmt = new Compute_IC_Stmt(div_d, lhs_result, rhs_result, result);
	}
	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->set_reg(rd);
	output->append_ics(*divide_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	rhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}

Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & Mult_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs->compile(); 
	Code_For_Ast rhs_code =	this->rhs->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Compute_IC_Stmt *mult_stmt;
	if(this->lhs->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		mult_stmt = new Compute_IC_Stmt(mult, lhs_result, rhs_result, result);
	}
	else if(this->lhs->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		mult_stmt = new Compute_IC_Stmt(mult_d, lhs_result, rhs_result, result);
	}
	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->set_reg(rd);
	output->append_ics(*mult_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	rhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}

Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & UMinus_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Descriptor *rd;
	Register_Addr_Opd *result;
	Move_IC_Stmt *uminus_stmt;
	if(this->lhs->get_data_type() == int_data_type) {
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		uminus_stmt = new Move_IC_Stmt(uminus, lhs_result, result);
	}
	else if(this->lhs->get_data_type() == double_data_type) {
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		uminus_stmt = new Move_IC_Stmt(uminus_d, lhs_result, result);
	}
	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->set_reg(rd);
	output->append_ics(*uminus_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}


Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}

Code_For_Ast & Conditional_Expression_Ast::compile() {
	Code_For_Ast cond_code = this->cond->compile();
    Code_For_Ast lhs_code = this->lhs->compile();
	Code_For_Ast rhs_code = this->rhs->compile();
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Addr_Opd *cond_result = new Register_Addr_Opd(cond_code.get_reg());
	Register_Descriptor *rd = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd *result = new Register_Addr_Opd(rd);

	Label_IC_Stmt * label1 = new Label_IC_Stmt(j, this->get_new_label()); //why does label need tg_op?
	Label_IC_Stmt * label2 = new Label_IC_Stmt(j, this->get_new_label()); //why does label need tg_op?
	Control_Flow_IC_Stmt * jump_stmt = new Control_Flow_IC_Stmt(j, NULL, label2->get_label());

	Control_Flow_IC_Stmt * branch_stmt = new Control_Flow_IC_Stmt(beq, cond_result, label1->get_label());

	Code_For_Ast *output = new Code_For_Ast();
	output->set_reg(rd);
	output->get_icode_list().insert(output->get_icode_list().end(),cond_code.get_icode_list().begin(), cond_code.get_icode_list().end());
	output->append_ics(*branch_stmt);


	return *output;
}


Code_For_Ast & Return_Ast::compile() {
	//TODO:
}

Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra) {
	//TODO:
}


Code_For_Ast & Relational_Expr_Ast::compile() {
	Code_For_Ast lhs_code =	this->lhs_condition->compile(); 
	Code_For_Ast rhs_code =	this->rhs_condition->compile(); 
	Register_Addr_Opd *lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd *result = new Register_Addr_Opd(rd);
	
	Compute_IC_Stmt * comp_stmt;

	rd = machine_desc_object.get_new_register<int_reg>();
	result = new Register_Addr_Opd(rd);

	if(this->rel_op == less_equalto) {
		comp_stmt = new Compute_IC_Stmt(sle, lhs_result, rhs_result, result);
	}
	else if(this->rel_op == less_than) {
		comp_stmt = new Compute_IC_Stmt(slt, lhs_result, rhs_result, result);
	}
	else if(this->rel_op == greater_than) {
		comp_stmt = new Compute_IC_Stmt(sgt, lhs_result, rhs_result, result);
	}
	else if(this->rel_op == greater_equalto) {
		comp_stmt = new Compute_IC_Stmt(sge, lhs_result, rhs_result, result);
	}
	else if(this->rel_op == equalto) {
		comp_stmt = new Compute_IC_Stmt(seq, lhs_result, rhs_result, result);
	}
	else if(this->rel_op == not_equalto) {
		comp_stmt = new Compute_IC_Stmt(sne, lhs_result, rhs_result, result);
	}

	Code_For_Ast *output = new Code_For_Ast(lhs_code.get_icode_list(), rd);
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->set_reg(rd);
	output->append_ics(*comp_stmt);
	lhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	rhs_result->get_reg()->reset_use_for_expr_result();	// Free the registers
	return *output;
}

Code_For_Ast & Logical_Expr_Ast::compile() {
	Code_For_Ast lhs_code;
	Register_Addr_Opd *lhs_result;
	if(this->bool_op != _logical_not) {
		lhs_code =	this->lhs_op->compile(); 
		lhs_result = new Register_Addr_Opd(lhs_code.get_reg());
	}
	Code_For_Ast rhs_code =	this->rhs_op->compile(); 
	Register_Addr_Opd *rhs_result = new Register_Addr_Opd(rhs_code.get_reg());
	Register_Descriptor *rd = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd *result = new Register_Addr_Opd(rd);
	
	Compute_IC_Stmt * comp_stmt;
	rd = machine_desc_object.get_new_register<int_reg>();
	result = new Register_Addr_Opd(rd);

	if(this->bool_op == _logical_and) {
		comp_stmt = new Compute_IC_Stmt(and_t, lhs_result, rhs_result, result);
	}
	else if(this->bool_op == _logical_or) {
		comp_stmt = new Compute_IC_Stmt(or_t, lhs_result, rhs_result, result);
	}
	else if(this->bool_op == _logical_not) {
		comp_stmt = new Compute_IC_Stmt(not_t, NULL, rhs_result, result);
	}

	Code_For_Ast *output = new Code_For_Ast();
	output->set_reg(rd);
	if(this->bool_op != _logical_not)
		output->get_icode_list().insert(output->get_icode_list().end(),lhs_code.get_icode_list().begin(),lhs_code.get_icode_list().end());	
	output->get_icode_list().insert(output->get_icode_list().end(),rhs_code.get_icode_list().begin(),rhs_code.get_icode_list().end());
	output->append_ics(*comp_stmt);
	return *output;
}

Code_For_Ast & Selection_Statement_Ast::compile() {
	Code_For_Ast cond_code = this->cond->compile(); 
	Code_For_Ast then_code = this->then_part->compile(); 
	Code_For_Ast else_code;
	Label_IC_Stmt * label1 = new Label_IC_Stmt(j, this->get_new_label()); //why does label need tg_op?
	Label_IC_Stmt * label2;
	Control_Flow_IC_Stmt *jump_stmt;
	if(this->else_part != NULL) {
		else_code = this->else_part->compile();
		Register_Addr_Opd *else_result = new Register_Addr_Opd(else_code.get_reg());
		label2 = new Label_IC_Stmt(j, this->get_new_label());
		jump_stmt = new Control_Flow_IC_Stmt(j, NULL, label2->get_label());
	}

	Register_Addr_Opd *cond_result = new Register_Addr_Opd(cond_code.get_reg());
	Register_Addr_Opd *then_result = new Register_Addr_Opd(then_code.get_reg());
	Register_Descriptor *rd = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd *result = new Register_Addr_Opd(rd);
	Control_Flow_IC_Stmt *rel_stmt = new Control_Flow_IC_Stmt(beq, cond_result, label1->get_label());

	Code_For_Ast *output = new Code_For_Ast(cond_code.get_icode_list(), rd);
	output->append_ics(*rel_stmt);
	output->get_icode_list().insert(output->get_icode_list().end(),then_code.get_icode_list().begin(),then_code.get_icode_list().end());
	if(this->else_part != NULL) {
		output->append_ics(*jump_stmt);
	}
	output->append_ics(*label1);
	if(this->else_part != NULL) {
		output->get_icode_list().insert(output->get_icode_list().end(),else_code.get_icode_list().begin(),else_code.get_icode_list().end());
		output->append_ics(*label2);
	}
	
	output->set_reg(rd);
	return *output;
}

Code_For_Ast & Iteration_Statement_Ast::compile() {
	//TODO:
	Code_For_Ast cond_code = this->cond->compile(); 
	Code_For_Ast body_code = this->body->compile(); 

	Label_IC_Stmt * label1 = new Label_IC_Stmt(j, this->get_new_label()); //why does label need tg_op?
	Label_IC_Stmt * label2 = new Label_IC_Stmt(j, this->get_new_label()); //why does label need tg_op?
	Control_Flow_IC_Stmt * jump_stmt = new Control_Flow_IC_Stmt(j, NULL, label2->get_label());

	Register_Addr_Opd *cond_result = new Register_Addr_Opd(cond_code.get_reg());
	Register_Addr_Opd *body_result = new Register_Addr_Opd(body_code.get_reg());
	Register_Descriptor *rd = machine_desc_object.get_new_register<int_reg>();
	Register_Addr_Opd *result = new Register_Addr_Opd(rd);
	Control_Flow_IC_Stmt *control_stmt = new Control_Flow_IC_Stmt(bne, cond_result, label1->get_label());
	jump_stmt = new Control_Flow_IC_Stmt(j, NULL, label2->get_label());

	Code_For_Ast *output = new Code_For_Ast();
	output->set_reg(rd);
	if(!this->is_do_form)
		output->append_ics(*jump_stmt);
	output->append_ics(*label1);
	output->get_icode_list().insert(output->get_icode_list().end(), body_code.get_icode_list().begin(), body_code.get_icode_list().end());
	output->append_ics(*label2);
	output->get_icode_list().insert(output->get_icode_list().end(), cond_code.get_icode_list().begin(), cond_code.get_icode_list().end());
	output->append_ics(*control_stmt);
	
	return *output;
}

Code_For_Ast & Sequence_Ast::compile() {
	list<Ast *>::iterator it;
	for(it = this->statement_list.begin(); it != this->statement_list.end(); it++) {
		Code_For_Ast temp = (*it)->compile();
		this->sa_icode_list.insert(this->sa_icode_list.end(), temp.get_icode_list().begin(),
		 temp.get_icode_list().end());
	}

	Code_For_Ast *output = new Code_For_Ast(this->sa_icode_list, NULL);
	return *output;
}

