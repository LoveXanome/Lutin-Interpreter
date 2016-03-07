#include "E6.hpp"

E6::E6() : Etat()
{
	
}

E6::~E6()
{
	
}

valeurRetour E6::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
		case IDENTIFIANT:
            automate->reduction(new E2, 2);
            retour = REDUIT;
            break;
		case ECRIRE: 
            automate->reduction(new E2, 2);
            retour = REDUIT;
            break;
		case LIRE: 
            automate->reduction(new E2, 2);
            retour = REDUIT;
            break;
		case DOLLAR: 
            automate->reduction(new E2, 2);
            retour = RECONNU;
            break;
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}
