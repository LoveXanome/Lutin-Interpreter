#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include <list>
#include "Symbole.hpp"
#include "SymboleEnum.hpp"
#include "TypeDefinitions.hpp"

class Expression : public Symbole
{
public:
	Expression();
	Expression(const SymboleEnum& enumRepresentation);
	virtual ~Expression();
	virtual double eval(TableDesSymboles& tableDesSymboles) = 0;
	virtual std::string toString() const = 0;
	virtual std::string toPrintString() const = 0;
	virtual Expression* toTransform() = 0;
	virtual std::list<std::string> getIdentifiants() const = 0;
};

#endif // EXPRESSION_HPP
