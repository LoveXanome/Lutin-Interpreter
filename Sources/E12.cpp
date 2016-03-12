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
	switch (*s){
        case MULTIPLIER :
        case DIVISER :
        case PLUS :
        case MOINS :
        case POINT_VIRGULE :
		{
			//On dépile rien de la pite des symboles, car on à déjà empiler juste avant une valeur
			automate->reduction(new SymboleDefaut(EXP), 1, s);

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
        MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
