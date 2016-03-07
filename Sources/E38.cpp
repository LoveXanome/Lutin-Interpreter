#include "E38.hpp"

E38::E38() : Etat()
{
	
}

E38::~E38()
{
	
}

valeurRetour E38::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case POINT_VIRGULE:
            automate->decalage(s, new E39);
            break;
        case VIRGULE:
			automate->decalage(s, new E40);
			break;        
    }
	return NON_RECONNU;
}