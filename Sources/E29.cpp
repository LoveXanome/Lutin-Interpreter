#include "E29.hpp"

#include "DeclarationVariable.hpp"
#include "Identifiant.hpp"
#include "SymboleDefaut.hpp"

E29::E29() : Etat(29)
{
}

E29::~E29()
{
}

valeurRetour E29::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case POINT_VIRGULE:
		case VIRGULE:
			Identifiant* i = (Identifiant*) automate->popSymbole();
			automate->addDeclarationToProgram(new DeclarationVariable(i->getIdentifiant()));
			
			automate->reduction(new SymboleDefaut(ID), 1);
			return REDUIT;
	}

	return NON_RECONNU;
}

