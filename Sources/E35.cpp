#include "E35.hpp"

E35::E35() : Etat()
{
	
}

E35::~E35()
{
	
}

valeurRetour E35::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case EGAL:
			automate->decalage(s, new E36);
			break;        
    }
	return NON_RECONNU;
}
