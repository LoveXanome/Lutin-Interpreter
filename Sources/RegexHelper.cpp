#include "RegexHelper.hpp"

#include <regex>
#include <stdexcept>
#include "SymboleEnum.hpp"
#include "SymboleTerminal.hpp"
#include "StringHelper.hpp"

RegexHelper::RegexHelper()
{
}

RegexHelper::~RegexHelper()
{
}

std::string RegexHelper::findFirstMatchingRegex(const std::string& str)
{
	unsigned int firstPosition = str.size(); // initialized at the end of the string
	std::string firstRegexStr;
	
	// TODO list of regex
	// TODO attention à l'ordre! Identifiant doit matché si var/const/lire/ecrire ne match pas
	ifFirstRegexReplace(str, VAR_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, CONST_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, ECRIRE_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, LIRE_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, VALEUR_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, IDENTIFIANT_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, AFFECTATION_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, POINT_VIRGULE_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, EGAL_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, PLUS_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, MOINS_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, MULTIPLIER_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, DIVISER_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, PARENTHESE_OUVRANTE_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, PARENTHESE_FERMANTE_REGEX_STR, &firstPosition, &firstRegexStr);
	ifFirstRegexReplace(str, VIRGULE_REGEX_STR, &firstPosition, &firstRegexStr);

	if (firstPosition == str.size())
		throw std::runtime_error(StringHelper::format("'%s' could not be interpreted", str.c_str()));
		
	return firstRegexStr;
}


void RegexHelper::ifFirstRegexReplace(const std::string& str, const std::string& regStr, unsigned int* firstPosition, std::string* firstRegexStr)
{
	std::smatch match;
	std::regex reg(regStr);
	if (regex_search(str, match, reg))
	{
		if (match.position() < *firstPosition)
		{
			*firstPosition = match.position();
			*firstRegexStr = regStr;
		}
	}
}

bool RegexHelper::isIdentifiantRegex(const std::string& regStr)
{
	return regStr == IDENTIFIANT_REGEX_STR;
}

bool RegexHelper::isValeurRegex(const std::string& regStr)
{
	return regStr == VALEUR_REGEX_STR;
}

symbole_ptr RegexHelper::makeSymboleTerminal(const std::string& regStr)
{
	// TODO switch ?
	
	if (regStr == VAR_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(VAR));
		
	if (regStr == CONST_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(CONST));
	
	if (regStr == AFFECTATION_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(AFFECTATION));
		
	if (regStr == ECRIRE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(ECRIRE));
		
	if (regStr == LIRE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(LIRE));
		
	if (regStr == POINT_VIRGULE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(POINT_VIRGULE));
		
	if (regStr == EGAL_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(EGAL));
		
	if (regStr == PLUS_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(PLUS));
		
	if (regStr == MOINS_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(MOINS));
		
	if (regStr == MULTIPLIER_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(MULTIPLIER));
		
	if (regStr == DIVISER_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(DIVISER));
		
	if (regStr == PARENTHESE_OUVRANTE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(PARENTHESE_OUVRANTE));
		
	if (regStr == PARENTHESE_FERMANTE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(PARENTHESE_FERMANTE));
		
	if (regStr == VIRGULE_REGEX_STR)
		return std::make_shared<Symbole>(SymboleTerminal(VIRGULE));
		
		
	throw std::runtime_error(StringHelper::format("No terminal symbol could have been created with regex '%s'", regStr.c_str()));
}

const std::string RegexHelper::IDENTIFIANT_REGEX_STR = "[a-zA-Z][a-zA-Z0-9]*";
const std::string RegexHelper::VALEUR_REGEX_STR = "[0-9]+";
const std::string RegexHelper::VAR_REGEX_STR = "var";
const std::string RegexHelper::CONST_REGEX_STR = "const";
const std::string RegexHelper::AFFECTATION_REGEX_STR = ":=";
const std::string RegexHelper::ECRIRE_REGEX_STR = "ecrire";
const std::string RegexHelper::LIRE_REGEX_STR = "lire";
const std::string RegexHelper::POINT_VIRGULE_REGEX_STR = ";";
const std::string RegexHelper::EGAL_REGEX_STR = "=";
const std::string RegexHelper::PLUS_REGEX_STR = "\\+";
const std::string RegexHelper::MOINS_REGEX_STR = "\\-";
const std::string RegexHelper::MULTIPLIER_REGEX_STR = "\\*";
const std::string RegexHelper::DIVISER_REGEX_STR = "\\/";
const std::string RegexHelper::PARENTHESE_OUVRANTE_REGEX_STR = "\\(";
const std::string RegexHelper::PARENTHESE_FERMANTE_REGEX_STR = "\\)";
const std::string RegexHelper::VIRGULE_REGEX_STR = ",";
