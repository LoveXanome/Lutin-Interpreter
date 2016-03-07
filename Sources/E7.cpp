#include "E7.hpp"

E7::E7() : Etat()
{
	
}

E7::~E7()
{
	
}

Etat::valeurRetour E7::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case Affectation :
            automate->decalage(s, new E8);
            break;
    }
	return NON_RECONNU;
}
