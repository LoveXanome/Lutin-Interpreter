#include "ExpressionBinaire.hpp"

ExpressionBinaire::ExpressionBinaire(Expression* membreG , Expression* membreD)
: membreGauche(membreG), membreDroite(membreD)
{

}

ExpressionBinaire::~ExpressionBinaire()
{
	delete membreGauche;
	delete membreDroite;
}

std::list<std::string> ExpressionBinaire::getIdentifiants() const
{
	std::list<std::string> identifiantsGauche =	membreGauche->getIdentifiants();
	std::list<std::string> identifiantsDroite =	membreDroite->getIdentifiants();
	
	identifiantsGauche.insert(identifiantsGauche.begin(), identifiantsDroite.begin(), identifiantsDroite.end());
	return identifiantsGauche;
}
