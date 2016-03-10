#include "E7.hpp"
#include "E8.hpp"

E7::E7() : Etat(7)
{
	
}

E7::~E7()
{
	
}

valeurRetour E7::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case AFFECTATION:
            automate->decalage(s, new E8, true);
            retour = RECONNU;
            break;
		default:
			retour = NON_RECONNU;
    }
	return retour;
}
