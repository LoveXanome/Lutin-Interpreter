#ifndef EXPRESSION_BINAIRE_HPP
#define EXPRESSION_BINAIRE_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionBinaire : public Expression
{
public:
	ExpressionBinaire();
	ExpressionBinaire(const SymboleEnum& enumRepresentation);
	virtual ~ExpressionBinaire();
	
protected:
	Expression membreGauche;
	Expression membreDroite;
};

#endif // EXPRESSION_BINAIRE_HPP
