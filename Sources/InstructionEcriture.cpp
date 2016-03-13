#include "InstructionEcriture.hpp"

#include <iostream>

InstructionEcriture::InstructionEcriture(Expression* e) : Instruction(), expression(e)
{
	
}

InstructionEcriture::~InstructionEcriture()
{
	delete expression;
}

void InstructionEcriture::print() const
{
	std::cout << "ecrire " << expression->toPrintString() << ";" << std::endl;
}
