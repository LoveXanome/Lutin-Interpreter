#include "E34.hpp"

E34::E34() : Etat()
{
	
}

E34::~E34()
{
	
}

valeurRetour E34::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT:
            automate->decalage(s, new E35);
            break;
        case EQ:
			automate->decalage(s, new E38);
			break;        
    }
	return NON_RECONNU;
}
