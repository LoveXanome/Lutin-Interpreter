#include "ExpressionMultiplication.hpp"

#include "SymboleEnum.hpp"

ExpressionMultiplication::ExpressionMultiplication(Expression* membreG , Expression* membreD) : ExpressionBinaire(MULTIPLIER, membreG, membreD)
{

}

ExpressionMultiplication::~ExpressionMultiplication()
{

}

std::string ExpressionMultiplication::toString() const
{
	return membreGauche->toString() + "*" + membreDroite->toString();
}

