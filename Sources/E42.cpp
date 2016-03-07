#include "E42.hpp"

#include "E43.hpp"

E42::E42() : Etat()
{
	
}

E42::~E42()
{
	
}

Etat::valeurRetour E42::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VALEUR:
            automate->decalage(s, new E43, true);
            return RECONNU;  
    }
	return NON_RECONNU;
}
