#ifndef SYMBOLE_HPP
#define SYMBOLE_HPP

#include "SymboleEnum.hpp"
#include <string>
#include "Logger.hpp"

class Symbole
{
public:
	Symbole(const SymboleEnum& enumRepresentation);
	virtual ~Symbole();
	inline operator int() const { return enumRepresentation; }
	SymboleEnum getEnum();
	virtual std::string toString() const;
	
protected:
	SymboleEnum enumRepresentation;
	
	static const Logger logger;
};

#endif // SYMBOLE_HPP
