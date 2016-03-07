#include "E36.hpp"

E36::E36() : Etat()
{
	
}

E36::~E36()
{
	
}

valeurRetour E36::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VALEUR:
			automate->decalage(s, new E37);
			break;        
    }
	return NON_RECONNU;