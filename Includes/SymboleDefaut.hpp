#ifndef SYMBOLE_DEFAUT_HPP
#define SYMBOLE_DEFAUT_HPP

#include "Symbole.hpp"
#include "SymboleEnum.hpp"

class SymboleDefaut : public Symbole
{
public:
	SymboleDefaut(const SymboleEnum& enumRepresentation);
	virtual ~SymboleDefaut();
};

#endif // SYMBOLE_DEFAUT_HPP
