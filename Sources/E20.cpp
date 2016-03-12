#include "E20.hpp"
#include "E8.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E21.hpp"

E20::E20() : Etat(20)
{
	
}

E20::~E20()
{
	
}

valeurRetour E20::transition(AutomateLutin* automate, Symbole * s)
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
            automate->decalage(s, new E12, true);
            retour = RECONNU;
            break;
        case EXP :
            //automate->decalage(s, new E21, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
    }
    return retour;
}
