#include "InstructionAffectation.hpp"

InstructionAffectation::InstructionAffectation(std::string identifiant)
	: Instruction(), identifiant(identifiant)
{
	
}

InstructionAffectation::InstructionAffectation(Expression e)
	: Instruction(), expression(e)
{
	
}

InstructionAffectation::InstructionAffectation(double val)
	: Instruction(), valeur(val)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	
}
