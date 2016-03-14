#include "DeclarationVariable.hpp"

#include <iostream>

DeclarationVariable::DeclarationVariable(const std::string& identifiant) : Declaration(identifiant)
{
	
}

DeclarationVariable::~DeclarationVariable()
{
	
}

void DeclarationVariable::print() const
{
	std::cout << "var " << identifiant << ";" << std::endl;
}

std::string DeclarationVariable::getType() const
{
	return "VAR";
}