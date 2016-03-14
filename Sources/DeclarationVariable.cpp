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

void DeclarationVariable::setExecValue(const double& value)
{
	execValue = value;
}

double DeclarationVariable::getExecValue() const
{
	return execValue;
}
