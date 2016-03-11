#include "E13.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"
#include "E14.hpp"

E13::E13() : Etat(13)
{
	
}

E13::~E13()
{
	
}

valeurRetour E13::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
    switch (*s){
        case IDENTIFIANT:
            automate->decalage(s, new E11, true);
            retour = RECONNU;
            break;
        case VALEUR:
            automate->decalage(s, new E12, true);
            retour = RECONNU;
            break;
        case PARENTHESE_OUVRANTE:
            automate->decalage(s, new E13, true);
            retour = RECONNU;
            break;
        case EXP:
            automate->decalage(s, new E14, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
    }
    return retour;
}
