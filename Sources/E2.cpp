#include "E2.hpp"

E2::E2() : Etat()
{
	
}

E2::~E2()
{
	
}

valeurRetour E2::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour transition retour = NON_RECONNU;
	switch (*s){
        case ECRIRE :
            automate->decalage(s, new E24);
            retour = RECONNU;
            break;
        case LIRE :
            automate->decalage(s, new E4);
            retour = RECONNU;
            break;
        case IDENTIFIANT :
            automate->decalage(s, new E3);
            retour = RECONNU;
            break;
    }
	return retour;
}
