#include "InstructionAffectation.hpp"
#include <iostream>

InstructionAffectation::InstructionAffectation(const std::string& identifiant, Expression* e)
	: Instruction(), identifiant(identifiant), expression(e)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	delete expression;
}

void InstructionAffectation::print() const
{
	std::cout << identifiant << " := " << expression->toString() << ";" << std::endl;
}

std::string InstructionAffectation::toString() const
{
	return identifiant + " := " + expression->toString() + ";";
}