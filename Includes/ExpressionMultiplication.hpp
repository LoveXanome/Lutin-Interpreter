#ifndef EXPRESSION_MULTIPLICATION_HPP
#define EXPRESSION_MULTIPLICATION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionMultiplication : public ExpressionBinaire
{
public:
	ExpressionMultiplication();
	ExpressionMultiplication(Expression* membreG , Expression* membreD);
	virtual ~ExpressionMultiplication();
	std::string toString() const;
	std::string toPrintString() const;
	Expression* toTransform();
};

#endif // EXPRESSION_MULTIPLICATION_HPP
