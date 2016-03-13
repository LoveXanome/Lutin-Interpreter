#include "E14.hpp"

#include "E15.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "E20.hpp"
#include "E22.hpp"

E14::E14() : Etat(14)
{
	
}

E14::~E14()
{
	
}

valeurRetour E14::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
	switch (*s){
        case PARENTHESE_FERMANTE:
            automate->decalage(s, new E15, true);
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

std::vector<SymboleEnum> E14::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        PARENTHESE_FERMANTE, MULTIPLIER, DIVISER, PLUS, MOINS
    });
}
