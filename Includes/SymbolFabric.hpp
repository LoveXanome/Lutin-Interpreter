#ifndef SYMBOL_FABRIC_HPP
#define SYMBOL_FABRIC_HPP

#include <vector>
#include <string>
#include "Symbole.hpp"

class SymbolFabric
{
public:
	virtual ~SymbolFabric();
	static std::vector<Symbole*> makeSymbolsFromLine(std::string& line);
	
private:
	SymbolFabric();
	static Symbole* createCorrespondingSymbol(const std::string& regStr, const std::string& str);
};

#endif // SYMBOL_FABRIC_HPP
