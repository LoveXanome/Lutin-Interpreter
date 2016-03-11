#include "Valeur.hpp"

#include "SymboleEnum.hpp"

Valeur::Valeur(const double& valeur) : Expression(VALEUR), valeur(valeur)
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
	return std::to_string(valeur) + " (VALEUR)";
}
