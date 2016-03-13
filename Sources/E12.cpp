#include "E12.hpp"
#include "Expression.hpp"
#include "SymboleDefaut.hpp"
#include "SymboleEnum.hpp"

#include "InstructionAffectation.hpp"
#include "SymboleDefaut.hpp"
#include "Valeur.hpp"

E12::E12() : Etat(12)
{
	
}

E12::~E12()
{
	
}

valeurRetour E12::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s)
	{
        case MULTIPLIER:
        case DIVISER:
        case PLUS:
        case MOINS:
        case POINT_VIRGULE:
        case PARENTHESE_FERMANTE:
		{
			Valeur* val = (Valeur*) automate->popSymbole();

			Valeur* expValeur = new Valeur(val->getValeur(), EXP);
			
			automate->reduction(expValeur, 1, s);

			retour = REDUIT;
			break;
		}
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}

std::vector<SymboleEnum> E12::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE, PARENTHESE_FERMANTE
    });
}
