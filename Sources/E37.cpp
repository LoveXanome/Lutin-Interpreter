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
		// A modifier
        case VALEUR:
			automate->decalage(s, new E37);
			break;        
    }
	return NON_RECONNU;