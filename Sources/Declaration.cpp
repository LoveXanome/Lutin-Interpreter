#include "Declaration.hpp"
#include "SymbolFabric.hpp"
#include "StringHelper.hpp"

const Logger Declaration::logger("Declaration");

Declaration::Declaration(const std::string& identifiant) : identifiant(identifiant)
{
	logger.construction(StringHelper::format("Construction déclaration %s", identifiant.c_str()));
}

Declaration::~Declaration()
{
	logger.destruction(StringHelper::format("Destruction déclaration %s", identifiant.c_str()));
}

std::string Declaration::getIdentifiant() const
{
	return identifiant;
}
