#include "E25.hpp"

#include "E16.hpp"
#include "E18.hpp"
#include "E20.hpp"
#include "E22.hpp"
#include "E26.hpp"

E25::E25() : Etat(25)
{
	
}

E25::~E25()
{
	
}

valeurRetour E25::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;

	switch (*s)
	{
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
            
        case POINT_VIRGULE :
            automate->decalage(s, new E26, true);
            retour = RECONNU;
            break;

    }
	return retour;
}

std::vector<SymboleEnum> E25::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
