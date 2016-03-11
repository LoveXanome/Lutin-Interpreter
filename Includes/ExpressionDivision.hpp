#ifndef EXPRESSION_DIVISION_HPP
#define EXPRESSION_DIVISION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionDivision : public ExpressionBinaire
{
public:
	ExpressionDivision(Expression* membreG , Expression* membreD);
	virtual ~ExpressionDivision();
	std::string toString() const;
};

#endif // EXPRESSION_DIVISION_HPP
