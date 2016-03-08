#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "SymboleEnum.hpp"
#include <string>

class Symbole
{
public:
	Symbole(const SymboleEnum& enumRepresentation);
	virtual ~Symbole();
	inline operator int() const { return enumRepresentation; }
	std::string toString() const;
	
protected:
	SymboleEnum enumRepresentation;
};

#endif // SYMBOLE_HPP
