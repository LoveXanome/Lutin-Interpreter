#include "ExpressionSoustraction.hpp"

#include "SymboleEnum.hpp"

#include "Valeur.hpp"

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

std::string ExpressionSoustraction::toPrintString() const
{
	return membreGauche->toPrintString() + " - " + membreDroite->toPrintString();
}

Expression* ExpressionSoustraction::toTransform()
{
	if(Valeur* val = dynamic_cast<Valeur*>(membreDroite))
	{
		if(val->getValeur() == 0)
		{
			return membreGauche;
		}
	}
	else
	{
		membreDroite->toTransform();
	}
	return this;
}

double ExpressionSoustraction::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) / membreDroite->eval(tableDesSymboles);
}
