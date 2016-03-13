#include "ExpressionMultiplication.hpp"

#include "SymboleEnum.hpp"

ExpressionMultiplication::ExpressionMultiplication(Expression* membreG , Expression* membreD) : ExpressionBinaire(membreG, membreD)
{

}

ExpressionMultiplication::~ExpressionMultiplication()
{

}

std::string ExpressionMultiplication::toString() const
{
	return membreGauche->toString() + "*" + membreDroite->toString();
}

std::string ExpressionMultiplication::toPrintString() const
{
	return membreGauche->toPrintString() + "*" + membreDroite->toPrintString();
}
