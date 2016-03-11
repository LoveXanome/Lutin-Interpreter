#include "Identifiant.hpp"

Identifiant::Identifiant(const std::string& identifiant) : Identifiant(identifiant, IDENTIFIANT)
{
}


Identifiant::Identifiant(const std::string& identifiant, const SymboleEnum& enumRepresentation) : Expression(enumRepresentation), identifiant(identifiant)
{
}


Identifiant::~Identifiant()
{
}

std::string Identifiant::getIdentifiant() const
{
	return identifiant;
}

std::string Identifiant::toString() const
{
	return identifiant;
}
