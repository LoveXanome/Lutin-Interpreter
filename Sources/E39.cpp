#include "E39.hpp"

#include "SymboleDefaut.hpp"

E39::E39() : Etat(39)
{
	
}

E39::~E39()
{
	
}

valeurRetour E39::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case CONST:
        case VAR:
        case IDENTIFIANT:
        case LIRE:
        case ECRIRE:
        	automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            automate->reduction(new SymboleDefaut(D2), 3, s);
            return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E39::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		CONST, VAR, IDENTIFIANT, LIRE, ECRIRE
	});
}
