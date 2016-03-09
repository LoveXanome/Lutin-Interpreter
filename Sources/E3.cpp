#include "E3.hpp"

#include "SymboleDefaut.hpp"

E3::E3() : Etat(3)
{
	
}

E3::~E3()
{
	
}

valeurRetour E3::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        default :
			automate->popSymbole();
			automate->popSymbole();
            automate->reduction(new SymboleDefaut(I), 2, s);
            return REDUIT;
    }
	return NON_RECONNU;
}
