#ifndef EXPRESSION_DIVISION_HPP
#define EXPRESSION_DIVISION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionDivision : public ExpressionBinaire
{
public:
	ExpressionDivision();
	ExpressionDivision( Expression* membreG , Expression* membreD );
	virtual ~ExpressionDivision();
	std::string toString() const;
	std::string toPrintString() const;
};

#endif // EXPRESSION_DIVISION_HPP
