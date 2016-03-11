#ifndef EXPRESSION_BINAIRE_HPP
#define EXPRESSION_BINAIRE_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionBinaire : public Expression
{
public:
	ExpressionBinaire( Expression membreG , Expression membreD );
	ExpressionBinaire(const SymboleEnum& enumRepresentation);
	ExpressionBinaire(const SymboleEnum& enumRepresentation, Expression membreG , Expression membreD );
	virtual ~ExpressionBinaire();
	
protected:
	Expression membreGauche;
	Expression membreDroite;
};

#endif // EXPRESSION_BINAIRE_HPP
