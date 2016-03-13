#include "ExpressionDivision.hpp"

#include "SymboleEnum.hpp"

ExpressionDivision::ExpressionDivision(Expression* membreG , Expression* membreD) : ExpressionBinaire(membreG, membreD)
{

}

ExpressionDivision::~ExpressionDivision()
{

}

std::string ExpressionDivision::toString() const
{
	return membreGauche->toString() + "/" + membreDroite->toString();
}
