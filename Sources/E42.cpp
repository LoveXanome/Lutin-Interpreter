#include "E42.hpp"

#include "E43.hpp"

E42::E42() : Etat(42)
{
	
}

E42::~E42()
{
	
}

valeurRetour E42::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VALEUR:
            automate->decalage(s, new E43, true);
            return RECONNU;  
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E42::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		VALEUR
	});
}
