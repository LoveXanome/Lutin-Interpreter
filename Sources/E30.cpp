#include "E30.hpp"

#include "SymboleEnum.hpp"
#include "E31.hpp"
#include "E32.hpp"

E30::E30() : Etat(30)
{
	
}

E30::~E30()
{
	
}

valeurRetour E30::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case POINT_VIRGULE:
			automate->decalage(s, new E31, true);
			return RECONNU;
		case VIRGULE:
			automate->decalage(s, new E32, true);
			return RECONNU;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E30::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		POINT_VIRGULE, VIRGULE
	});
}
