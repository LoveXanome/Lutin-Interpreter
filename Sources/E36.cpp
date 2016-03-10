#include "E36.hpp"

#include "E37.hpp"

E36::E36() : Etat(36)
{
	
}

E36::~E36()
{
	
}

valeurRetour E36::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VALEUR:
			automate->decalage(s, new E37, true);
			return RECONNU;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E36::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		VALEUR
	});
}
