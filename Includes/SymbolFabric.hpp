#ifndef SYMBOL_FABRIC_HPP
#define SYMBOL_FABRIC_HPP

#include <vector>
#include <string>
#include "Symbole.hpp"
#include "SymboleEnum.hpp"
#include "AutomateLutin.hpp"

class SymbolFabric
{
public:
	virtual ~SymbolFabric();
	static std::vector<symbole_ptr> makeSymbolsFromLine(std::string& line);
	static std::string makeSymbolNameFromNumber(const SymboleEnum enumRepresentation);
	
private:
	SymbolFabric();
	static symbole_ptr createCorrespondingSymbol(const std::string& regStr, const std::string& str);
};

#endif // SYMBOL_FABRIC_HPP
