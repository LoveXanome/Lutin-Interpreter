#include "ExpressionSoustraction.hpp"

#include "SymboleEnum.hpp"

ExpressionSoustraction::ExpressionSoustraction(Expression* membreG , Expression* membreD) : ExpressionBinaire(membreG, membreD)
{

}

ExpressionSoustraction::~ExpressionSoustraction()
{

}

std::string ExpressionSoustraction::toString() const
{
	return membreGauche->toString() + " - " + membreDroite->toString();
}
