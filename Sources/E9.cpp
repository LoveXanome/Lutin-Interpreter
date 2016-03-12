#include "E9.hpp"
#include "E10.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "E20.hpp"
#include "E22.hpp"

#include "E10.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "E20.hpp"
#include "E22.hpp"
#include "SymboleEnum.hpp"


E9::E9() : Etat(9)
{
	
}

E9::~E9()
{
	
}

valeurRetour E9::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
	switch (*s){
        case POINT_VIRGULE :
            automate->decalage(s, new E10, true);
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
        case PLUS :
            automate->decalage(s, new E20, true);
            retour = RECONNU;
            break;
        case MOINS :
            automate->decalage(s, new E22, true);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
    }
	return retour;
}

std::vector<SymboleEnum> E9::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        POINT_VIRGULE, MULTIPLIER, DIVISER, PLUS, MOINS
    });
}
