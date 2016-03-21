#include "ExpressionDivision.hpp"

#include "SymboleEnum.hpp"

#include "Valeur.hpp"

#include <stdexcept>

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

std::string ExpressionDivision::toPrintString() const
{
	return membreGauche->toPrintString() + "/" + membreDroite->toPrintString();
}

Expression* ExpressionDivision::toTransform(TableDesSymboles& tableDesSymboles)
{
	//La division est useless seulement si le membre de droite est égal à 1 !!
	if(Valeur* val = dynamic_cast<Valeur*>(membreDroite))
	{
		if(val->getValeur() == 1)
		{
			return membreGauche->toTransform(tableDesSymboles);
		}
	}
	membreGauche = membreGauche->toTransform(tableDesSymboles);
	membreDroite = membreDroite->toTransform(tableDesSymboles);
	if (Valeur* valGauche = dynamic_cast<Valeur*>(membreGauche))
	{
		if (Valeur* valDroite = dynamic_cast<Valeur*>(membreDroite))
		{
			if (valDroite->getValeur() == 0)
			{
				throw std::runtime_error("ERROR: Division by zero");
			}
			else
			{
				return new Valeur(valGauche->getValeur() / valDroite->getValeur());
			}
		}
	}
	return this;
}

double ExpressionDivision::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) / membreDroite->eval(tableDesSymboles);
}
