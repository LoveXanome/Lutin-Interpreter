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
	switch (*s)
	{
		case MULTIPLIER:
		case DIVISER:
		case PLUS:
		case MOINS:
		case POINT_VIRGULE:
			Identifiant* i = (Identifiant*) automate->popSymbole();
			
			automate->reduction(new Identifiant(i->getIdentifiant(), EXP), 1, s);
			delete i;
			return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E11::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
