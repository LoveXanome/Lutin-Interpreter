#include "Symbole.hpp"

#include "SymbolFabric.hpp"

Symbole::Symbole(const SymboleEnum& enumRepresentation) : enumRepresentation(enumRepresentation)
{
	
}

Symbole::~Symbole()
{
	
}

std::string Symbole::toString() const
{
	return SymbolFabric::makeSymbolNameFromNumber(enumRepresentation);
}
