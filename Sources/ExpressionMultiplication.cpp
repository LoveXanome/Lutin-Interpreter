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

Expression* ExpressionMultiplication::toTransform()
{
	if(Valeur* val = dynamic_cast<Valeur*>(membreGauche))
	{
		if(val->getValeur() == 1)
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

double ExpressionMultiplication::eval(TableDesSymboles& tableDesSymboles)
{
	return membreGauche->eval(tableDesSymboles) * membreDroite->eval(tableDesSymboles);
}
