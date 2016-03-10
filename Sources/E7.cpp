#include "E7.hpp"

E7::E7() : Etat(7)
{
	
}

E7::~E7()
{
	
}

valeurRetour E7::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case Affectation :
            automate->decalage(s, new E8);
            break;
    }
	return NON_RECONNU;
}
