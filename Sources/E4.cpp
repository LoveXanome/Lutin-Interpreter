#include "E4.hpp"

#include "E5.hpp"

E4::E4() : Etat()
{
	
}

E4::~E4()
{
	
}

Etat::valeurRetour E4::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case IDENTIFIANT:
            automate->decalage(s, new E5, true);
            retour = RECONNU;
            break;
		default:
			retour = NON_RECONNU;
    }
	return retour;
}
