#include "icode.hh"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
template class Const_Opd<double>;
template class Const_Opd<int>;


///////////////////////// Instruction Descriptor ///////////////////////////////////

Instruction_Descriptor::Instruction_Descriptor (Tgt_Op op, string name, string mnn, string ics, Icode_Format icf, Assembly_Format af) {
	this->inst_op = op;
	this->mnemonic = mnn;
	this->ic_symbol = ics;
	this->name = name;
	this->ic_format = icf;
	this->assem_format = af;
}

Instruction_Descriptor::Instruction_Descriptor() {
	/* TODO */
}

Tgt_Op Instruction_Descriptor::Tgt_Op get_op() {
	return this->inst_op;
}


string Instruction_Descriptor::get_name() {
	return this->name;
}

string Instruction_Descriptor::get_mnemonic() {
	return this->mnemonic;
}
	
string Instruction_Descriptor::get_ic_symbol() {
	return this->ic_symbol;
}

Icode_Format Instruction_Descriptor::get_ic_format() {
	return this->ic_format;
}

Assembly_Format Instruction_Descriptor::get_assembly_format() {
	return this->assem_format;
}
 
void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer) {
	/* TODO */
}

///////////////////////////// Icode statement operand ///////////////////////////////////

Register_Descriptor * Ics_Opd::get_reg() {}

Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se) {
	this->symbol_entry = &se;
}

void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer) {
	/* TODO */
}

void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer) {
	/* TODO */
}

Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs) {
	this->symbol_entry = rhs.symbol_entry;
}

Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd); {
	this->register_description = rd;
}

Register_Descriptor * Register_Addr_Opd::get_reg() {
	return this->register_description;
}

void Register_Addr_Opd::print_ics_opd(ostream & file_buffer) {
	/* TODO */
}

void Register_Addr_Opd::print_asm_opd(ostream & file_buffer) {
	/* TODO */
}

Register_Addr_Opd & operator=(const Register_Addr_Opd & rhs) {
	this->register_description = rhs.register_description;
}

template <class T>
Const_Opd<T>::Const_Opd(T num){
    this->num = num;
}

template <class T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer) {
	/* TODO */
}

template <class T>
void Const_Opd<T>::print_asm_opd(ostream & file_buffer) {
	/* TODO */
}

template <class T>
Const_Opd & Const_Opd<T>::operator=(const Const_Opd & rhs) {
	this->num = rhs.num;
}

///////////////////////////////// Intermediate code statements //////////////////////////


