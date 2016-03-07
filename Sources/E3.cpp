#include "E3.hpp"

#include "SymboleDefaut.hpp"

E3::E3() : Etat()
{
	
}

E3::~E3()
{
	
}

Etat::valeurRetour E3::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        default :
			automate->popSymbole();
			automate->popSymbole();
            automate->reduction(new SymboleDefaut(I), 2);
            return REDUIT;
    }
	return NON_RECONNU;
}
