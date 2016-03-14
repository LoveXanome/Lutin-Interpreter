#include "ExpressionDivision.hpp"

#include "SymboleEnum.hpp"

#include "Valeur.hpp"

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

Expression* ExpressionDivision::toTransform()
{
	//La division est useless seulement si le membre de droite est égal à 1 !!
	if(Valeur* val = dynamic_cast<Valeur*>(membreDroite))
	{
		if(val->getValeur() == 1)
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

