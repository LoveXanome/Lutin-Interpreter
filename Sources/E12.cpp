#include "E12.hpp"
#include "Expression.hpp"
#include "SymboleDefaut.hpp"
#include "SymboleEnum.hpp"

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
		{
			const SymboleEnum symbole = automate->popSymbole()->getEnum();
			Expression* e = new Expression(symbole);
			
			automate->addSymbole(e);

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
