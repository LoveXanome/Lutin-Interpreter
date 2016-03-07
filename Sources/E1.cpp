#include "E1.hpp"

#include "E2.hpp"
#include "E27.hpp"
#include "E28.hpp"
#include "E34.hpp"

E1::E1() : Etat()
{
	
}

E1::~E1()
{
	
}

valeurRetour E1::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour = RECONNU;
	switch (*s)
	{
        case CONST:
            automate->decalage(s, new E34, true);
            break;
        case VAR:
			automate->decalage(s, new E28, true);
			break;
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
        case I:
            automate->decalage(s, new E2, false);
            break;
        case D2:
            automate->decalage(s, new E27, false);
            break;
        default:
			retour = NON_RECONNU;
			break;
    }
	return retour;
}
