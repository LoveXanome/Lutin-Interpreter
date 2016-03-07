#include "E24.hpp"

#include "SymboleEnum.hpp"

E24::E24() : Etat()
{
	
}

E24::~E24()
{
	
}

Etat::valeurRetour E24::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;

	switch (*s){

        case EXP :
            automate->decalage(s, new E25, false);
            retour = RECONNU;
            break;

        case PARENTHESE_OUVRANTE :
            automate->decalage(s, new E13, true);
            retour = RECONNU;
            break;

        case IDENTIFIANT :
            automate->decalage(s, new E11, true);
            retour = RECONNU;
            break;

        case VALEUR :
            automate->decalage(s, new E12, true);
            retour = RECONNU;
            break;

    }
	return retour;
}
