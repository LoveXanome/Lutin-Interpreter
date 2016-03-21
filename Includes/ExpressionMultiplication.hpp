#ifndef EXPRESSION_MULTIPLICATION_HPP
#define EXPRESSION_MULTIPLICATION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionMultiplication : public ExpressionBinaire
{
public:
	ExpressionMultiplication();
	ExpressionMultiplication(Expression* membreG , Expression* membreD);
	virtual ~ExpressionMultiplication();
	double eval(TableDesSymboles& tableDesSymboles);
	std::string toString() const;
	std::string toPrintString() const;
	Expression* toTransform(TableDesSymboles& tableDesSymboles);
};

#endif // EXPRESSION_MULTIPLICATION_HPP
