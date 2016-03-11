#include "InstructionAffectation.hpp"

InstructionAffectation::InstructionAffectation(std::string identifiant, Expression exp)
	: Instruction(), identifiant(identifiant), expression(exp)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	
}
