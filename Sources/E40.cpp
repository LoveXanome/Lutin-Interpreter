#include "E40.hpp"

#include "E41.hpp"

E40::E40() : Etat(40)
{
	
}

E40::~E40()
{
	
}

valeurRetour E40::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT:
            automate->decalage(s, new E41, true);
            return RECONNU;
    }
	return NON_RECONNU;
}
