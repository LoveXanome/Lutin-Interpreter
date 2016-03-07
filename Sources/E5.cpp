#include "E5.hpp"

E5::E5() : Etat()
{
	
}

E5::~E5()
{
	
}

valeurRetour E5::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case POINT_VIRGULE :
            automate->decalage(s, new E6);
            retour = RECONNU;
            break;
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}
