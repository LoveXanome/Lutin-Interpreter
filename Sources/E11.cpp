#include "E11.hpp"

#include "InstructionAffectation.hpp"
#include "SymboleDefaut.hpp"
#include "Identifiant.hpp"

E11::E11() : Etat(11)
{
	
}

E11::~E11()
{
	
}

valeurRetour E11::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s)
	{
		case POINT_VIRGULE:
        case MULTIPLIER:
        case DIVISER:
        case PLUS:
        case MOINS:
        case PARENTHESE_FERMANTE:
        {
        	Identifiant* i = (Identifiant*) automate->popSymbole();
			
			Identifiant* expIdentifiant = new Identifiant(i->getIdentifiant(), EXP);
			automate->reduction(expIdentifiant, 1, s);
			
            retour = REDUIT;
            break;
		}
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}

std::vector<SymboleEnum> E11::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE, PARENTHESE_FERMANTE
    });
}
