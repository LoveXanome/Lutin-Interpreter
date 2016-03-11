#ifndef EXPRESSION_BINAIRE_HPP
#define EXPRESSION_BINAIRE_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionBinaire : public Expression
{
public:
	ExpressionBinaire(const SymboleEnum& enumRepresentation, Expression* membreG , Expression* membreD);
	virtual ~ExpressionBinaire();
	virtual std::string toString() const = 0;
	
protected:
	Expression* membreGauche;
	Expression* membreDroite;
};

#endif // EXPRESSION_BINAIRE_HPP
