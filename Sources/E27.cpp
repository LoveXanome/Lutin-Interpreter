#include "E27.hpp"

#include "SymboleEnum.hpp"
#include "SymboleDefaut.hpp"

E27::E27() : Etat(27)
{
}

E27::~E27()
{
}

valeurRetour E27::transition(AutomateLutin* automate, Symbole* s)
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
			
			automate->reduction(new SymboleDefaut(D), 2);
			return REDUIT;
			break;
	}
	return NON_RECONNU;
}
