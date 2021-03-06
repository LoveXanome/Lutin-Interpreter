#include "ExpressionMultiplication.hpp"

#include "SymboleEnum.hpp"

#include "Valeur.hpp"

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

Expression* ExpressionMultiplication::toTransform(TableDesSymboles& tableDesSymboles)
{
	if (Valeur* val = dynamic_cast<Valeur*>(membreGauche))
	{
		if (val->getValeur() == 1)
		{
			return membreDroite->toTransform(tableDesSymboles);
		}
	}
	if (Valeur* val = dynamic_cast<Valeur*>(membreDroite))
	{
		if (val->getValeur() == 1)
		{
			return membreGauche->toTransform(tableDesSymboles);
		}
	}
	membreDroite = membreDroite->toTransform(tableDesSymboles);
	membreGauche = membreGauche->toTransform(tableDesSymboles);
	if (Valeur* valGauche = dynamic_cast<Valeur*>(membreGauche))
	{
		if (Valeur* valDroite = dynamic_cast<Valeur*>(membreDroite))
		{
			Valeur* v = new Valeur(valGauche->getValeur() * valDroite->getValeur());
			createdExpressionInOptimization.push_back(v);
			return v;
		}
	}
	return this;
}

double ExpressionMultiplication::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) * membreDroite->eval(tableDesSymboles);
}
