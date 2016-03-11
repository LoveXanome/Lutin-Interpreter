#include "E11.hpp"

E11::E11() : Etat(11)
{
	
}

E11::~E11()
{
	
}

valeurRetour E11::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
		case POINT_VIRGULE :
        case MULTIPLIER :
        case DIVISER :
        case PLUS :
        case MOINS :
            //TODO

            retour = REDUIT;
            break;
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}
