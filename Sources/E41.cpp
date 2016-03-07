#include "E41.hpp"

#include "E42.hpp"

E41::E41() : Etat()
{
	
}

E41::~E41()
{
	
}

valeurRetour E41::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case EGAL:
            automate->decalage(s, new E42, true);
            return RECONNU;
    }
	return NON_RECONNU;
}
