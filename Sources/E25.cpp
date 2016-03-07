#include "E25.hpp"

#include "SymboleEnum.hpp"

E25::E25() : Etat()
{
	
}

E25::~E25()
{
	
}

valeurRetour E25::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;

	switch (*s){

        case POINT_VIRGULE :
            automate->decalage(s, new E26, true);
            retour = RECONNU;
            break;

        case PLUS :
            automate->decalage(s, new E20, true);
            retour = RECONNU;
            break;

        case MOINS :
            automate->decalage(s, new E22, true);
            retour = RECONNU;
            break;

        case MULTIPLIER :
            automate->decalage(s, new E16, true);
            retour = RECONNU;
            break;

        case DIVISER :
            automate->decalage(s, new E18, true);
            retour = RECONNU;
            break;

    }
	return retour;
}
