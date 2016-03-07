#include "E42.hpp"

E42::E42() : Etat()
{
	
}

E42::~E42()
{
	
}

valeurRetour E42::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT:
            automate->decalage(s, new E43);
            break;        
    }
	return NON_RECONNU;
}
