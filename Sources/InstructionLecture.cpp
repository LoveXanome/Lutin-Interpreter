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
	
	DeclarationVariable* d = (DeclarationVariable*) tableDesSymboles[identifiant];
	d->setExecValue(readValue);
}
