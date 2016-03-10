#include "RegexHelper.hpp"

#include <regex.h>
#include <stdexcept>
#include "SymboleEnum.hpp"
#include "SymboleTerminal.hpp"
#include "StringHelper.hpp"

const Logger RegexHelper::logger("RegexHelper");

// TODO : the code of the regex.h needs to be refactored : duplicated four times

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
	logger.debug(StringHelper::format("Searching '%s' in '%s'", regStr.c_str(), str.c_str()));
	
	regex_t regex;
	if (regcomp(&regex, regStr.c_str(), REG_EXTENDED))
		throw std::runtime_error(StringHelper::format("'%s' could not be compiled into a regex", regStr.c_str()));
	
	size_t nmatch = regex.re_nsub;
	regmatch_t* pmatch = new regmatch_t[nmatch]; // checking if correctly allocated is sooooo mainstream!
	
	if (regexec(&regex, str.c_str(), nmatch, pmatch, 0) == 0)
	{
		if (((unsigned int) pmatch[0].rm_so) < *firstPosition)
		{
			logger.debug("Is the new left-most matching pattern!");
			*firstPosition = pmatch[0].rm_so;
			*firstRegexStr = regStr;
		}
	}
	
	delete [] pmatch;
	regfree(&regex);
}

std::string RegexHelper::erase_regex(const std::string& str, const std::string& regStr)
{
	regex_t regex;
	if (regcomp(&regex, regStr.c_str(), REG_EXTENDED))
		throw std::runtime_error(StringHelper::format("'%s' could not be compiled into a regex", regStr.c_str()));
		
	size_t nmatch = regex.re_nsub;
	regmatch_t* pmatch = new regmatch_t[nmatch]; // no checking again lol
	
	std::string newStr(str);
	if (regexec(&regex, str.c_str(), nmatch, pmatch, 0) == 0)
	{
		newStr.erase(newStr.begin() + pmatch[0].rm_so, newStr.begin() + pmatch[0].rm_eo);
		logger.debug(StringHelper::format("Removing regex '%s' from '%s' => '%s'", regStr.c_str(), str.c_str(), newStr.c_str()));
	}
	
	delete [] pmatch;
	regfree(&regex);
	
	return newStr;
}

std::string RegexHelper::getIdentifiantRegex(const std::string& regStr, const std::string& str)
{
	if (regStr != IDENTIFIANT_REGEX_STR)
		return std::string();
		
	regex_t regex;
	if (regcomp(&regex, regStr.c_str(), REG_EXTENDED))
		throw std::runtime_error(StringHelper::format("'%s' could not be compiled into a regex", regStr.c_str()));
		
	size_t nmatch = regex.re_nsub;
	regmatch_t* pmatch = new regmatch_t[nmatch]; // no checking again lol
	
	std::string newStr;
	if (regexec(&regex, str.c_str(), nmatch, pmatch, 0) == 0)
	{
		size_t length = pmatch[0].rm_eo - pmatch[0].rm_so;
		newStr = str.substr(pmatch[0].rm_so, length);
		logger.debug(StringHelper::format("Extracted identifiant '%s'", newStr.c_str()));
	}
	
	delete [] pmatch;
	regfree(&regex);
	
	return newStr;
}

std::string RegexHelper::getValeurRegex(const std::string& regStr, const std::string& str)
{
	if (regStr != VALEUR_REGEX_STR)
		return std::string();
		
	regex_t regex;
	if (regcomp(&regex, regStr.c_str(), REG_EXTENDED))
		throw std::runtime_error(StringHelper::format("'%s' could not be compiled into a regex", regStr.c_str()));
		
	size_t nmatch = regex.re_nsub;
	regmatch_t* pmatch = new regmatch_t[nmatch]; // no checking again lol
	
	std::string newStr;
	if (regexec(&regex, str.c_str(), nmatch, pmatch, 0) == 0)
	{
		size_t length = pmatch[0].rm_eo - pmatch[0].rm_so;
		newStr = str.substr(pmatch[0].rm_so, length);
		logger.debug(StringHelper::format("Extracted valeur '%s'", newStr.c_str()));
	}
	
	delete [] pmatch;
	regfree(&regex);
	
	return newStr;
}

Symbole* RegexHelper::makeSymboleTerminal(const std::string& regStr)
{
	// TODO switch ?
	SymboleEnum enumVal = NONE;
	
	if (regStr == VAR_REGEX_STR)
		enumVal = VAR;
		
	if (regStr == CONST_REGEX_STR)
		enumVal = CONST;
	
	if (regStr == AFFECTATION_REGEX_STR)
		enumVal = AFFECTATION;
		
	if (regStr == ECRIRE_REGEX_STR)
		enumVal = ECRIRE;
		
	if (regStr == LIRE_REGEX_STR)
		enumVal = LIRE;
		
	if (regStr == POINT_VIRGULE_REGEX_STR)
		enumVal = POINT_VIRGULE;
		
	if (regStr == EGAL_REGEX_STR)
		enumVal = EGAL;
		
	if (regStr == PLUS_REGEX_STR)
		enumVal = PLUS;
		
	if (regStr == MOINS_REGEX_STR)
		enumVal = MOINS;
		
	if (regStr == MULTIPLIER_REGEX_STR)
		enumVal = MULTIPLIER;
		
	if (regStr == DIVISER_REGEX_STR)
		enumVal = DIVISER;
		
	if (regStr == PARENTHESE_OUVRANTE_REGEX_STR)
		enumVal = PARENTHESE_OUVRANTE;
		
	if (regStr == PARENTHESE_FERMANTE_REGEX_STR)
		enumVal = PARENTHESE_FERMANTE;
		
	if (regStr == VIRGULE_REGEX_STR)
		enumVal = VIRGULE;
		
	
	if (enumVal == NONE)
		throw std::runtime_error(StringHelper::format("No terminal symbol could have been created with regex '%s'", regStr.c_str()));
		
	return new SymboleTerminal(enumVal);
}

const std::string RegexHelper::IDENTIFIANT_REGEX_STR = "([a-zA-Z][a-zA-Z0-9]*)";
const std::string RegexHelper::VALEUR_REGEX_STR = "([0-9]+)";
const std::string RegexHelper::VAR_REGEX_STR = "(var)";
const std::string RegexHelper::CONST_REGEX_STR = "(const)";
const std::string RegexHelper::AFFECTATION_REGEX_STR = "(:=)";
const std::string RegexHelper::ECRIRE_REGEX_STR = "(ecrire)";
const std::string RegexHelper::LIRE_REGEX_STR = "(lire)";
const std::string RegexHelper::POINT_VIRGULE_REGEX_STR = "(;)";
const std::string RegexHelper::EGAL_REGEX_STR = "(=)";
const std::string RegexHelper::PLUS_REGEX_STR = "(\\+)";
const std::string RegexHelper::MOINS_REGEX_STR = "(\\-)";
const std::string RegexHelper::MULTIPLIER_REGEX_STR = "(\\*)";
const std::string RegexHelper::DIVISER_REGEX_STR = "(\\/)";
const std::string RegexHelper::PARENTHESE_OUVRANTE_REGEX_STR = "(\\()";
const std::string RegexHelper::PARENTHESE_FERMANTE_REGEX_STR = "(\\))";
const std::string RegexHelper::VIRGULE_REGEX_STR = "(,)";
