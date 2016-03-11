#include "E12.hpp"

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
	switch (*s){
      case MULTIPLIER:
		case DIVISER:
		case PLUS:
		case MOINS:
		case POINT_VIRGULE:
			Valeur* val = (Valeur*) automate->popSymbole();
			
			automate->reduction(new Valeur(val->getValeur(), EXP), 1, s);
			delete val;
			return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E12::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
