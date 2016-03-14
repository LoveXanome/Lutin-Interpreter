#include "ExpressionAddition.hpp"

#include "SymboleEnum.hpp"

#include "Valeur.hpp"

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

std::string ExpressionAddition::toPrintString() const
{
	return membreGauche->toPrintString() + " + " + membreDroite->toPrintString();
}

Expression* ExpressionAddition::toTransform()
{
	if(Valeur* val = dynamic_cast<Valeur*>(membreGauche))
	{
		if(val->getValeur() == 0)
		{
			return membreDroite;
		}
	}
	else
	{
		membreGauche->toTransform();
	}
	
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

double ExpressionAddition::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) + membreDroite->eval(tableDesSymboles);
}
