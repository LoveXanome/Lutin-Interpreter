#include "ExpressionParenthese.hpp"


ExpressionParenthese::ExpressionParenthese(Expression* membre)
:membreInt(membre)
{

}
ExpressionParenthese::ExpressionParenthese(const SymboleEnum& enumRepresentation)
: Expression(enumRepresentation)
{

}
ExpressionParenthese::ExpressionParenthese(const SymboleEnum& enumRepresentation, Expression* membre)
: Expression(enumRepresentation), membreInt(membre)
{

}
std::string ExpressionParenthese::toString() const
{
	return "(" + membreInt->toString() + ")";
}

std::string ExpressionParenthese::toPrintString() const
{
	return "(" + membreInt->toPrintString() + ")";
}



ExpressionParenthese::~ExpressionParenthese()
{
	delete membreInt;
}
