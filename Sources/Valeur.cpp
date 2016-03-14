#include "Valeur.hpp"

#include "SymbolFabric.hpp"

#include "StringHelper.hpp"



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

std::string Valeur::toPrintString() const
{
	return StringHelper::doubleToString(valeur);
}

Expression* Valeur::toTransform()
{
	return this;
}
