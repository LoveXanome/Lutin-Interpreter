#include "Valeur.hpp"

#include "SymboleEnum.hpp"

Valeur::Valeur(const double& valeur) : Expression(VALEUR), valeur(valeur)
{

}

Valeur::~Valeur()
{

}
