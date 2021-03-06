#ifndef EXPRESSION_DIVISION_HPP
#define EXPRESSION_DIVISION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionDivision : public ExpressionBinaire
{
public:
	ExpressionDivision();
	ExpressionDivision( Expression* membreG , Expression* membreD );
	virtual ~ExpressionDivision();
	double eval(TableDesSymboles& tableDesSymboles);
	std::string toString() const;
	std::string toPrintString() const;
	Expression* toTransform(TableDesSymboles& tableDesSymboles);
};

#endif // EXPRESSION_DIVISION_HPP
