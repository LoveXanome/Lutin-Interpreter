#include "E8.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"
#include "E9.hpp"

E8::E8() : Etat(8)
{
	
}

E8::~E8()
{
	
}

valeurRetour E8::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;

	switch (*s){
        case IDENTIFIANT :
            automate->decalage(s, new E11, true);
            retour = RECONNU;
            break;
        case VALEUR :
            automate->decalage(s, new E12, true);
            retour = RECONNU;
            break;
        case PARENTHESE_OUVRANTE :
            automate->decalage(s, new E13, true);
            retour = RECONNU;
            break;
        case EXP :
            automate->decalage(s, new E9, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
    }
    return retour;
}
