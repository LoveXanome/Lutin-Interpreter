#ifndef EXPRESSION_REDUCTION_HPP
#define EXPRESSION_REDUCTION_HPP

#include <string>
#include "Symbole.hpp"
#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionReduction : public Symbole
{
public:
	ExpressionReduction();
	ExpressionReduction(const SymboleEnum& enumRepresentation, Expression* expression);
	virtual ~ExpressionReduction();
	std::string toString();
	Expression* getExpression();

private:
	Expression* expression;
};

#endif // EXPRESSION_REDUCTION_HPP
