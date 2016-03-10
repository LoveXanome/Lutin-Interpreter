#include "Declaration.hpp"


Declaration::Declaration(const std::string& identifiant) : Declaration(identifiant, D)
{
}

Declaration::Declaration(const std::string& identifiant, const SymboleEnum& enumRepresentation) : Symbole(enumRepresentation), identifiant(identifiant)
{
}


Declaration::~Declaration()
{
	
}
