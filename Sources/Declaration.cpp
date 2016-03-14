#include "Declaration.hpp"
#include "SymbolFabric.hpp"
#include "StringHelper.hpp"

const Logger Declaration::logger("Declaration");

Declaration::Declaration(const std::string& identifiant) : Declaration(identifiant, D)
{
}

Declaration::Declaration(const std::string& identifiant, const SymboleEnum& enumRepresentation) : Symbole(enumRepresentation), identifiant(identifiant)
{
	logger.construction(StringHelper::format("Construction déclaration %s", SymbolFabric::makeSymbolNameFromNumber(enumRepresentation).c_str()));
}


Declaration::~Declaration()
{
	logger.destruction(StringHelper::format("Destruction déclaration %s", SymbolFabric::makeSymbolNameFromNumber(enumRepresentation).c_str()));
}
