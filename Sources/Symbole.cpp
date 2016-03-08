#include "Symbole.hpp"

#include "SymbolFabric.hpp"
#include "StringHelper.hpp"

const Logger Symbole::logger("Symbole");

Symbole::Symbole(const SymboleEnum& enumRepresentation) : enumRepresentation(enumRepresentation)
{
	logger.debug(StringHelper::format("Construction symbole %s", toString().c_str()));
}

Symbole::~Symbole()
{
	logger.debug("Destruction symbole");
}

std::string Symbole::toString() const
{
	return SymbolFabric::makeSymbolNameFromNumber(enumRepresentation);
}
