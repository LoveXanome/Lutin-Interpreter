#include "E31.hpp"

#include "SymboleEnum.hpp"
#include "SymboleDefaut.hpp"

E31::E31() : Etat()
{
	
}

E31::~E31()
{
	
}

Etat::valeurRetour E31::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case VAR:
		case CONST:
			automate->popSymbole();
			automate->popSymbole();
			automate->popSymbole();
			automate->reduction(new SymboleDefaut(D2), 3);
			return REDUIT;
	}
	
	return NON_RECONNU;
}
