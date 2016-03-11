#include "ExpressionBinaire.hpp"

ExpressionBinaire::ExpressionBinaire( Expression membreG , Expression membreD )
{
	membreGauche = membreG;
	membreDroite = membreD;
}


ExpressionBinaire::ExpressionBinaire(const SymboleEnum& enumRepresentation, Expression membreG , Expression membreD )
 : Expression(enumRepresentation), membreGauche(membreG), membreDroite(membreD)
{
}

ExpressionBinaire::ExpressionBinaire(const SymboleEnum& enumRepresentation) : Expression(enumRepresentation)
{

}

ExpressionBinaire::~ExpressionBinaire()
{

}
