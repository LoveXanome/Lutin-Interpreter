#include "ExpressionAddition.hpp"

#include "SymboleEnum.hpp"

ExpressionAddition::ExpressionAddition(Expression* membreG , Expression* membreD) : ExpressionBinaire(PLUS, membreGauche, membreDroite)
{

}


ExpressionAddition::~ExpressionAddition()
{

}

std::string ExpressionAddition::toString() const
{
	return membreGauche->toString() + " + " + membreDroite->toString();
}
