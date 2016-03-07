#include "E14.hpp"

E14::E14() : Etat()
{
	
}

E14::~E14()
{
	
}

valeurRetour E14::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case ParentheseFermante :
            automate->decalage(s, new E15);
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
