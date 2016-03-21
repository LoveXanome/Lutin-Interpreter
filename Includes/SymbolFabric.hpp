#ifndef SYMBOL_FABRIC_HPP
#define SYMBOL_FABRIC_HPP

#include <vector>
#include <string>
#include "Symbole.hpp"
#include "SymboleEnum.hpp"

class SymbolFabric
{
public:
	static std::vector<Symbole*> makeSymbolsFromLine(std::string& line);
	static std::string makeSymbolNameFromNumber(const SymboleEnum enumRepresentation);
	
private:
	static const Logger logger;
	
	static Symbole* createCorrespondingSymbol(const std::string& regStr, const std::string& str);
};

#endif // SYMBOL_FABRIC_HPP
