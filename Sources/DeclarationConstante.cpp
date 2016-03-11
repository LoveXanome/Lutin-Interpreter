#include "DeclarationConstante.hpp"

#include <iostream>

DeclarationConstante::DeclarationConstante(const std::string& identifiant, const double& valeur) : Declaration(identifiant), valeur(valeur)
{
	
}

DeclarationConstante::~DeclarationConstante()
{
	
}

void DeclarationConstante::print() const
{
	std::cout << "const " << identifiant << " = " << std::to_string(valeur) << ";" << std::endl;
}
