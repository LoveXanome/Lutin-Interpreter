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

Expression* ExpressionSoustraction::toTransform(TableDesSymboles& tableDesSymboles)
{
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
			return new Valeur(valGauche->getValeur() - valDroite->getValeur());
		}
	}
	return this;
}

double ExpressionSoustraction::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) / membreDroite->eval(tableDesSymboles);
}
