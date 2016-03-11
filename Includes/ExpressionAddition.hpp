#ifndef EXPRESSION_ADDITION_HPP
#define EXPRESSION_ADDITION_HPP

#include "ExpressionBinaire.hpp"

class ExpressionAddition : public ExpressionBinaire
{
public:
	ExpressionAddition(Expression* membreG , Expression* membreD);
	virtual ~ExpressionAddition();
	std::string toString() const;
};

#endif // EXPRESSION_ADDITION_HPP
