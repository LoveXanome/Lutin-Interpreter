#include "ExpressionParenthese.hpp"
#include "Valeur.hpp"
#include "Identifiant.hpp"


ExpressionParenthese::ExpressionParenthese(Expression* membre)
:Expression(), membreInt(membre)
{

}

ExpressionParenthese::~ExpressionParenthese()
{
	//delete membreInt;
}

std::string ExpressionParenthese::toString() const
{
	return "(" + membreInt->toString() + ")";
}

std::string ExpressionParenthese::toPrintString() const
{
	return "(" + membreInt->toPrintString() + ")";
}

Expression* ExpressionParenthese::toTransform(TableDesSymboles& tableDesSymboles)
{
	membreInt = membreInt->toTransform(tableDesSymboles);
	if(Valeur* val = dynamic_cast<Valeur*>(membreInt))
	{
		return val->toTransform(tableDesSymboles);
	}
	if(Identifiant* id = dynamic_cast<Identifiant*>(membreInt))
	{
		return id->toTransform(tableDesSymboles);
	}
	if(ExpressionParenthese* membreP = dynamic_cast<ExpressionParenthese*>(membreInt))
	{
		return membreP->toTransform(tableDesSymboles);
	}
	return this;
}

double ExpressionParenthese::eval(TableDesSymboles& tableDesSymboles)
{
	return membreInt->eval(tableDesSymboles);
}

std::list<std::string> ExpressionParenthese::getIdentifiants() const
{
	return membreInt->getIdentifiants();
}
