#include "InstructionAffectation.hpp"

InstructionAffectation::InstructionAffectation(string identifiant):identifiant(identifiant)
{
	
}

InstructionAffectation::~InstructionAffectation()
{
	
}
	 
string InstructionAffectation::getIdentifiant()
{
	return this->identifiant;
}

void InstructionAffectation::setIdentifiant(string identifiant)
{
	this->identifiant = identifiant;
}
