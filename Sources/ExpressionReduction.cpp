#include "ExpressionReduction.hpp"

ExpressionReduction::ExpressionReduction() : Symbole(EXP)
{

}

ExpressionReduction::ExpressionReduction(const SymboleEnum& enumRepresentation, Expression* expression) : Symbole(enumRepresentation)
{
	this->expression = expression;
}

ExpressionReduction::~ExpressionReduction()
{
	delete expression;
}

std::string ExpressionReduction::toString()
{
	return expression->toString();
}

Expression* ExpressionReduction::getExpression()
{
	return expression;
}
