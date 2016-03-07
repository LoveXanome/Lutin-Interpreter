#include "E39.hpp"

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
        	automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(D2),3);
            break; 
        case VAR : 
            automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(D2),3);
            break;       
    }
	return NON_RECONNU;
}
