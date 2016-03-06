#include "Expression.hpp"

Expression::Expression() : Symbole(EXP)
{

}

Expression::Expression(const SymboleEnum& enumRepresentation) : Symbole(enumRepresentation)
{

}

Expression::~Expression()
{

}

double Expression::eval(std::string variables)
{
	
	// TODO impl?
	return 0;
}
