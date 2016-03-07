#include "E1.hpp"

E1::E1() : Etat()
{
	
}

E1::~E1()
{
	
}

valeurRetour E1::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case CONST:
            //automate->decalage(s, new E34);
            break;
        case VAR:
			automate->decalage(s, new E28);
			break;
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
        case I:
            //automate->decalage(s, new E2);
            break;
        case D2: // can happen ???
            //automate->decalage(s, new E27);
            break;
        
    }
	return NON_RECONNU;
}
