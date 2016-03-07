#include "E17.hpp"

E17::E17() : Etat()
{
	
}

E17::~E17()
{
	
}

Etat::valeurRetour E17::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case Multiplier :
            automate->decalage(s, new E16);
            break;
        case Diviser :
            automate->decalage(s, new E18);
            break;
        case Plus :
            automate->decalage(s, new E20);
            break;
        case Moins :
            automate->decalage(s, new E22);
            break;
    }
	return NON_RECONNU;
}
