#include "E2.hpp"

E2::E2() : Etat()
{
	
}

E2::~E2()
{
	
}

valeurRetour E2::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case ECRIRE :
            automate->decalage(s, new E24);
            break;
        case LIRE :
            automate->decalage(s, new E4);
            break;
        case IDENTIFIANT :
            automate->decalage(s, new E3);
            break;
    }
	return NON_RECONNU;
}
