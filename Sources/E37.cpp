#include "E37.hpp"

E37::E37() : Etat()
{
	
}

E37::~E37()
{
	
}

valeurRetour E37::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
		case IDENTIFIANT:
        	automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(EQ),3);
            break;             
    }
	return NON_RECONNU;
}