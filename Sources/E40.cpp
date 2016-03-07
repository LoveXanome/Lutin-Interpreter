#include "E40.hpp"

E40::E40() : Etat()
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
            automate->decalage(s, new E41);
            break;       
    }
	return NON_RECONNU;
}
