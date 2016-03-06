#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "SymboleEnum.hpp"

class Symbole
{
public:
	Symbole(const SymboleEnum& enumRepresentation);
	virtual ~Symbole();
	inline operator int() const { return enumRepresentation; }
	
protected:
	SymboleEnum enumRepresentation;
};

#endif // SYMBOLE_HPP
