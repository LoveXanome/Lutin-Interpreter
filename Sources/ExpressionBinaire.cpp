#include "ExpressionBinaire.hpp"

ExpressionBinaire::ExpressionBinaire(const SymboleEnum& enumRepresentation, Expression* membreG, Expression* membreD) : Expression(enumRepresentation), membreGauche(membreG), membreDroite(membreD)
{
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete membreGauche;
	delete membreDroite;
}
