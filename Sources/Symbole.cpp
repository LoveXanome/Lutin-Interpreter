#include "Symbole.hpp"

#include "SymbolFabric.hpp"
#include "StringHelper.hpp"

const Logger Symbole::logger("Symbole");
uint32_t Symbole::nbInstances = 0;

Symbole::Symbole(const SymboleEnum& enumRepresentation) : enumRepresentation(enumRepresentation)
{
	logger.construction(StringHelper::format("Symbole %s (existe : %d)", toString().c_str(), ++nbInstances));
}

Symbole::~Symbole()
{
	logger.destruction(StringHelper::format("Symbole %s (existe : %d)", toString().c_str(), --nbInstances));
}

std::string Symbole::toString() const
{
	return SymbolFabric::makeSymbolNameFromNumber(enumRepresentation);
}
