#include "E15.hpp"

E15::E15() : Etat()
{
	
}

E15::~E15()
{
	
}

Etat::valeurRetour E15::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case default :
            automate->reduction(new E14, 1);
            break;
    }
	return NON_RECONNU;
}
