#include "E35.hpp"

#include "E36.hpp"

E35::E35() : Etat()
{
	
}

E35::~E35()
{
	
}

Etat::valeurRetour E35::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case EGAL:
			automate->decalage(s, new E36, true);
			return RECONNU;
    }
	return NON_RECONNU;
}
