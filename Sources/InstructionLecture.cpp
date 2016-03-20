#include "InstructionLecture.hpp"

#include <iostream>
#include "DeclarationVariable.hpp"

InstructionLecture::InstructionLecture(const std::string& identifiant) : Instruction(), identifiant(identifiant)
{
	
}

InstructionLecture::~InstructionLecture()
{
	
}

void InstructionLecture::print() const
{
	std::cout << "lire " << identifiant << ";" << std::endl;
}

void InstructionLecture::transform()
{
}

void InstructionLecture::exec(TableDesSymboles& tableDesSymboles)
{
	double readValue;
	std::cin >> readValue;
	
	DeclarationVariable* d = (DeclarationVariable*) tableDesSymboles[identifiant]; // should never fail because of static analysis
	d->setExecValue(readValue);
}

std::string InstructionLecture::getIdentifiant() const
{
	return identifiant;
}