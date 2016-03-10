#include "Symbole.hpp"

#include "SymbolFabric.hpp"
#include "StringHelper.hpp"

const Logger Symbole::logger("Symbole");

Symbole::Symbole(const SymboleEnum& enumRepresentation) : enumRepresentation(enumRepresentation)
{
	logger.construction(StringHelper::format("Symbole %s", toString().c_str()));
}

Symbole::~Symbole()
{
	logger.destruction(StringHelper::format("Symbole %s", toString().c_str()));
}

std::string Symbole::toString() const
{
	return SymbolFabric::makeSymbolNameFromNumber(enumRepresentation);
}
