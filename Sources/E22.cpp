#include "E22.hpp"
#include "E8.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E23.hpp"

E22::E22() : Etat(22)
{
	
}

E22::~E22()
{
	
}

valeurRetour E22::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
    switch (*s){
        case PARENTHESE_OUVRANTE :
            automate->decalage(s, new E8, true);
            retour = RECONNU;
            break;
        case IDENTIFIANT :
            automate->decalage(s, new E11, true);
            retour = RECONNU;
            break;
        case VALEUR :
            //automate->decalage(s, new E12, true);
            retour = RECONNU;
            break;
        case EXP :
            //automate->decalage(s, new E23, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
    }
    return retour;
}
