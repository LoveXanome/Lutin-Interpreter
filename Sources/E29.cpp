#include "E29.hpp"

#include "DeclarationVariable.hpp"
#include "Identifiant.hpp"

E29::E29() : Etat()
{
}

E29::~E29()
{
}

valeurRetour E29::transition(AutomateLutin* automate, Symbole* s)
{
	Identifiant* i = (Identifiant*) s;
	
	automate->reduction(new DeclarationVariable(i->getIdentifiant(), ID), 1);
	
	return NON_RECONNU;
}

