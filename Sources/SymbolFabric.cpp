#include "SymbolFabric.hpp"

#include "RegexHelper.hpp"

#include <regex>
#include "Identifiant.hpp"
#include "Valeur.hpp"
#include "StringHelper.hpp"

SymbolFabric::SymbolFabric()
{
}

SymbolFabric::~SymbolFabric()
{
}

std::vector<Symbole*> SymbolFabric::makeSymbolsFromLine(std::string& line)
{
	std::vector<Symbole*> symboles;
	
	while (!StringHelper::isOnlyWhitespaces(line))
	{
		std::string firstMatchingRegex = RegexHelper::findFirstMatchingRegex(line);
		
		Symbole* symb = createCorrespondingSymbol(firstMatchingRegex, line);
		symboles.push_back(symb);
		
		//line = std::regex_replace(line, std::regex(firstMatchingRegex), "");
	}
	
	return symboles;
}

Symbole* SymbolFabric::createCorrespondingSymbol(const std::string& regStr, const std::string& str)
{
	if (RegexHelper::isIdentifiantRegex(regStr))
	{
		std::regex reg(regStr);
		std::smatch m;
		std::regex_search(str, m, reg);
		return new Identifiant(m[0]);
	}
	
	if (RegexHelper::isValeurRegex(regStr))
	{
		std::regex reg(regStr);
		std::smatch m;
		std::regex_search(str, m, reg);
		return new Valeur(std::stod(m[0]));
	}
	
	return RegexHelper::makeSymboleTerminal(regStr);
}
