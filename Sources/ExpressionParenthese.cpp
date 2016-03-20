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

ExpressionParenthese::~ExpressionParenthese()
{
	delete membreInt;
}

std::string ExpressionParenthese::toString() const
{
	return "(" + membreInt->toString() + ")";
}

std::string ExpressionParenthese::toPrintString() const
{
	return "(" + membreInt->toPrintString() + ")";
}

Expression* ExpressionParenthese::toTransform()
{
	return membreInt->toTransform();
}

double ExpressionParenthese::eval(TableDesSymboles& tableDesSymboles)
{
	return membreInt->eval(tableDesSymboles);
}

std::list<std::string> ExpressionParenthese::getIdentifiants() const
{
	return membreInt->getIdentifiants();
}
