#include "E18.hpp"

#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"
#include "E19.hpp"

E18::E18() : Etat(18)
{
	
}

E18::~E18()
{
	
}

valeurRetour E18::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
    switch (*s)
    {
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
            automate->decalage(s, new E19, false);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}

std::vector<SymboleEnum> E18::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		IDENTIFIANT, VALEUR, PARENTHESE_OUVRANTE, EXP
    });
}
