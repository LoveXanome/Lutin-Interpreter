#ifndef SYMBOLE_TERMINAL_HPP
#define SYMBOLE_TERMINAL_HPP

#include "Symbole.hpp"

class SymboleTerminal : public Symbole
{
public:
	SymboleTerminal(const SymboleEnum& enumRepresentation);
	virtual ~SymboleTerminal();
};

#endif // SYMBOLE_TERMINAL_HPP
