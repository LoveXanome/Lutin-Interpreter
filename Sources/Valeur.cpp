#include "Valeur.hpp"

#include "SymbolFabric.hpp"

Valeur::Valeur(const double& valeur) : Valeur(valeur, VALEUR)
{

}

Valeur::Valeur(const double& valeur, const SymboleEnum& enumRepresentation) : Expression(enumRepresentation), valeur(valeur)
{

}

Valeur::~Valeur()
{

}

double Valeur::getValeur() const
{
	return valeur;
}

std::string Valeur::toString() const
{
	return std::to_string(valeur) + "(" + SymbolFabric::makeSymbolNameFromNumber(enumRepresentation) + ")";
}
