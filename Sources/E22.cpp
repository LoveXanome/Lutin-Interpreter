#include "E22.hpp"

#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"
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
        case EXP :
            automate->decalage(s, new E23, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}

std::vector<SymboleEnum> E22::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        IDENTIFIANT, VALEUR, PARENTHESE_OUVRANTE, EXP
    });
}
