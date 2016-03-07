#include "E39.hpp"

#include "SymboleDefaut.hpp"

E39::E39() : Etat()
{
	
}

E39::~E39()
{
	
}

valeurRetour E39::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case CONST:
        case VAR:
        case IDENTIFIANT:
        case LIRE:
        case ECRIRE:
        	automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(D2), 3);
            return REDUIT;
    }
	return NON_RECONNU;
}
