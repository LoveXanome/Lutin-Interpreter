#include "E5.hpp"

#include "E6.hpp"

E5::E5() : Etat()
{
	
}

E5::~E5()
{
	
}

Etat::valeurRetour E5::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case POINT_VIRGULE :
            automate->decalage(s, new E6, true);
            retour = RECONNU;
            break;
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}
