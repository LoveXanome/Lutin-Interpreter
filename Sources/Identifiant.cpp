#include "Identifiant.hpp"

#include "SymboleEnum.hpp"

Identifiant::Identifiant(const std::string& identifiant) : Expression(IDENTIFIANT), identifiant(identifiant)
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
