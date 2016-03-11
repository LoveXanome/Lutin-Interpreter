#include "ExpressionMultiplication.hpp"

#include "SymboleEnum.hpp"

ExpressionMultiplication::ExpressionMultiplication(Expression* membreG , Expression* membreD) : ExpressionBinaire(MULTIPLIER, membreGauche, membreDroite)
{

}

ExpressionMultiplication::~ExpressionMultiplication()
{

}

std::string ExpressionMultiplication::toString() const
{
	return membreGauche->toString() + "*" + membreDroite->toString();
}

