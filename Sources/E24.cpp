#include "E24.hpp"

#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"
#include "E25.hpp"

E24::E24() : Etat(24)
{
	
}

E24::~E24()
{
	
}

valeurRetour E24::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;

	switch (*s)
	{
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
            automate->decalage(s, new E25, false);
            retour = RECONNU;
            break;
    }
	return retour;
}

std::vector<SymboleEnum> E24::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		IDENTIFIANT, VALEUR, PARENTHESE_OUVRANTE, EXP
    });
}
