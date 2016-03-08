#ifndef REGEX_HELPER_HPP
#define REGEX_HELPER_HPP

#include <string>
#include "Symbole.hpp"
#include "AutomateLutin.hpp"

class RegexHelper
{
public:
	virtual ~RegexHelper();
	
	static std::string findFirstMatchingRegex(const std::string& str);
	static bool isIdentifiantRegex(const std::string& regStr);
	static bool isValeurRegex(const std::string& regStr);
	static symbole_ptr makeSymboleTerminal(const std::string& regStr);
	
private:
	RegexHelper();
	static void ifFirstRegexReplace(const std::string& str, const std::string& regStr, unsigned int* firstPosition, std::string* firstRegexStr);
	
	static const std::string IDENTIFIANT_REGEX_STR;
	static const std::string VALEUR_REGEX_STR;
	static const std::string VAR_REGEX_STR;
	static const std::string CONST_REGEX_STR;
	static const std::string AFFECTATION_REGEX_STR;
	static const std::string ECRIRE_REGEX_STR;
	static const std::string LIRE_REGEX_STR;
	static const std::string POINT_VIRGULE_REGEX_STR;
	static const std::string EGAL_REGEX_STR;
	static const std::string PLUS_REGEX_STR;
	static const std::string MOINS_REGEX_STR;
	static const std::string MULTIPLIER_REGEX_STR;
	static const std::string DIVISER_REGEX_STR;
	static const std::string PARENTHESE_OUVRANTE_REGEX_STR;
	static const std::string PARENTHESE_FERMANTE_REGEX_STR;
	static const std::string VIRGULE_REGEX_STR;
};

#endif // REGEX_HELPER_HPP
