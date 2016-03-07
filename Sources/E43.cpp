#include "E43.hpp"

E43::E43() : Etat()
{
	
}

E43::~E43()
{
	
}

valeurRetour E43::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT : 
            automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(EQ),5);
            break;        
    }
	return NON_RECONNU;
}
