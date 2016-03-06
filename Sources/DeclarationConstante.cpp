#include "DeclarationConstante.hpp"

DeclarationConstante::DeclarationConstante(const std::string& identifiant, const double& valeur, const SymboleEnum& enumRepresentation) : Declaration(identifiant, enumRepresentation), valeur(valeur)
{
	
}

DeclarationConstante::~DeclarationConstante()
{
	
}
