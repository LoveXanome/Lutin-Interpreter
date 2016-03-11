#include "E16.hpp"
#include "E8.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E17.hpp"

E16::E16() : Etat(16)
{
	
}

E16::~E16()
{
	
}

valeurRetour E16::transition(AutomateLutin* automate, Symbole * s)
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
            automate->decalage(s, new E17, true);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
