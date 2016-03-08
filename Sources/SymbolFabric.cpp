#include "SymbolFabric.hpp"

#include "RegexHelper.hpp"

#include <regex>
#include <stdexcept>
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
		
		line = std::regex_replace(line, std::regex(firstMatchingRegex), "");
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

std::string SymbolFabric::makeSymbolNameFromNumber(const SymboleEnum enumRepresentation)
{
	std::string enumString;
	
	switch (enumRepresentation)
	{
		case 0:
			enumString = "PLUS";
			break;
		case 1:
			enumString = "MOINS";
			break;
		case 2:
			enumString = "MULTIPLIER";
			break;
		case 3:
			enumString = "DIVISER";
			break;
		case 4:
			enumString = "PARENTHESE_OUVRANTE";
			break;
		case 5:
			enumString = "PARENTHESE_FERMANTE";
			break;
		case 6:
			enumString = "VAR";
			break;
		case 7:
			enumString = "POINT_VIRGULE";
			break;
		case 8:
			enumString = "CONST";
			break;
		case 9:
			enumString = "VIRGULE";
			break;
		case 10:
			enumString = "IDENTIFIANT";
			break;
		case 11:
			enumString = "EGAL";
			break;
		case 12:
			enumString = "VALEUR";
			break;
		case 13:
			enumString = "AFFECTATION";
			break;
		case 14:
			enumString = "ECRIRE";
			break;
		case 15:
			enumString = "LIRE";
			break;
		case 16:
			enumString = "DOLLAR";
			break;
		case 17:
			enumString = "E";
			break;
		case 18:
			enumString = "D";
			break;
		case 19:
			enumString = "D2";
			break;
		case 20:
			enumString = "ID";
			break;
		case 21:
			enumString = "EQ";
			break;
		case 22:
			enumString = "I";
			break;
		case 23:
			enumString = "I2";
			break;
		case 24:
			enumString = "EXP";
			break;

		default:
			throw std::runtime_error(StringHelper::format("Unknown enum number (%d) for symbol", enumRepresentation));
	}

	return enumString;
}
