#include "E12.hpp"

E12::E12() : Etat(12)
{
	
}

E12::~E12()
{
	
}

valeurRetour E12::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case default :
            automate->reduction(new E8, 1);
            break;
    }
	return NON_RECONNU;
}
