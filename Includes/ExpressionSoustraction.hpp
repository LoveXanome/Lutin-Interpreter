#ifndef EXPRESSION_SOUSTRACTION_HPP
#define EXPRESSION_SOUSTRACTION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionSoustraction : public ExpressionBinaire
{
public:
	ExpressionSoustraction();
	ExpressionSoustraction( Expression membreG , Expression membreD );
	virtual ~ExpressionSoustraction();
};

#endif // EXPRESSION_SOUSTRACTION_HPP
