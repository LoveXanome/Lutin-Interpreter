#include "E3.hpp"

E3::E3() : Etat()
{
	
}

E3::~E3()
{
	
}

valeurRetour E3::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case default :
            automate->reduction(new E2, 1);
            break;
    }
	return NON_RECONNU;
}
