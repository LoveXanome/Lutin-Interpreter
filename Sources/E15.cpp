#include "E15.hpp"

E15::E15() : Etat(15)
{
	
}

E15::~E15()
{
	
}

valeurRetour E15::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        default :
            automate->reduction(new E14, 1);
            break;
    }
	return NON_RECONNU;
}
