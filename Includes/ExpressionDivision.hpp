#ifndef EXPRESSION_DIVISION_HPP
#define EXPRESSION_DIVISION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionDivision : public ExpressionBinaire
{
public:
	ExpressionDivision();
	ExpressionDivision( Expression membreG , Expression membreD );
	virtual ~ExpressionDivision();
};

#endif // EXPRESSION_DIVISION_HPP
