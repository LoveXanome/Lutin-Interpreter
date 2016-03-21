#include "Expression.hpp"

Expression::Expression() : Symbole(EXP)
{

}

Expression::Expression(const SymboleEnum& enumRepresentation) : Symbole(enumRepresentation)
{

}

Expression::~Expression()
{

}

void Expression::deleteCreatedExpressionInOptimization()
{
	for (Expression* e : createdExpressionInOptimization)
		delete e;
}

std::list<Expression*> Expression::createdExpressionInOptimization;
