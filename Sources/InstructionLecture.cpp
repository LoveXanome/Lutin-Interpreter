#include "InstructionLecture.hpp"

#include <iostream>

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
