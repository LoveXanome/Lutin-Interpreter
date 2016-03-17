#ifndef EXPRESSION_PARENTHESE_HPP
#define EXPRESSION_PARENTHESE_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class ExpressionParenthese : public Expression
{
public:
	ExpressionParenthese(Expression* membre);
	ExpressionParenthese(const SymboleEnum& enumRepresentation);
	ExpressionParenthese(const SymboleEnum& enumRepresentation, Expression* membre);
	virtual ~ExpressionParenthese();
	double eval(TableDesSymboles& tableDesSymboles);
	std::string toString() const;
	std::string toPrintString() const;
	Expression* toTransform();
	
private:
	Expression* membreInt;
};

#endif // EXPRESSION_PARENTHESE_HPP
