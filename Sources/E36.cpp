#include "E36.hpp"

#include "E37.hpp"

E36::E36() : Etat()
{
	
}

E36::~E36()
{
	
}

Etat::valeurRetour E36::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VALEUR:
			automate->decalage(s, new E37, true);
			return RECONNU;
    }
	return NON_RECONNU;
}
