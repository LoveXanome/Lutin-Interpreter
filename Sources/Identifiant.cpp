#include "Identifiant.hpp"

#include "SymboleEnum.hpp"

Identifiant::Identifiant(const std::string& identifiant) : Expression(IDENTIFIANT), identifiant(identifiant)
{

}

Identifiant::~Identifiant()
{

}
