#include "ExpressionAddition.hpp"

#include "SymboleEnum.hpp"

ExpressionAddition::ExpressionAddition(Expression* membreG , Expression* membreD) : ExpressionBinaire(membreG, membreD)
{

}


ExpressionAddition::~ExpressionAddition()
{

}

std::string ExpressionAddition::toString() const
{
	return membreGauche->toString() + " + " + membreDroite->toString();
}
