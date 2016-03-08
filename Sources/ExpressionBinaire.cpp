#include "ExpressionBinaire.hpp"

ExpressionBinaire::ExpressionBinaire( Expression membreG , Expression membreD )
{
	membreGauche = membreG;
	membreDroite = membreD;
}

ExpressionBinaire::ExpressionBinaire(const SymboleEnum& enumRepresentation) : Expression(enumRepresentation)
{

}

ExpressionBinaire::~ExpressionBinaire()
{

}
