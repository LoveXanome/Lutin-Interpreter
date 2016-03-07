#include "E9.hpp"

E9::E9() : Etat()
{
	
}

E9::~E9()
{
	
}

Etat::valeurRetour E9::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case PointVirgule :
            automate->decalage(s, new E10);
            break;
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
