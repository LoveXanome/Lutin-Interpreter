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

Expression* ExpressionAddition::toTransform(TableDesSymboles& tableDesSymboles)
{
	if(Valeur* val = dynamic_cast<Valeur*>(membreGauche))
	{
		if(val->getValeur() == 0)
		{
			return membreDroite->toTransform(tableDesSymboles);
		}
	}
	if(Valeur* val = dynamic_cast<Valeur*>(membreDroite))
	{
		if(val->getValeur() == 0)
		{
			return membreGauche->toTransform(tableDesSymboles);
		}
	}
	membreDroite = membreDroite->toTransform(tableDesSymboles);
	membreGauche = membreGauche->toTransform(tableDesSymboles);
	if(Valeur* valGauche = dynamic_cast<Valeur*>(membreGauche))
	{
		if(Valeur* valDroite = dynamic_cast<Valeur*>(membreDroite))
		{
			return new Valeur(valGauche->getValeur() + valDroite->getValeur());
		}
	}
	return this;
}

double ExpressionAddition::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) + membreDroite->eval(tableDesSymboles);
}
