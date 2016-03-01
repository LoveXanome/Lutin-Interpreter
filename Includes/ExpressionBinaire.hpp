#ifndef EXPRESSION_BINAIRE_HPP
#define EXPRESSION_BINAIRE_HPP

#include "Expression.hpp"

class ExpressionBinaire : public Expression
{
public:
	ExpressionBinaire();
	virtual ~ExpressionBinaire();
	
protected:
	Expression membreGauche;
	Expression membreDroite;
};

#endif // EXPRESSION_BINAIRE_HPP
