#include "E31.hpp"

#include "SymboleEnum.hpp"
#include "SymboleDefaut.hpp"

E31::E31() : Etat(31)
{
	
}

E31::~E31()
{
	
}

valeurRetour E31::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case VAR:
		case CONST:
		case FIN:
			delete automate->popSymbole();
			delete automate->popSymbole();
			delete automate->popSymbole();
			automate->reduction(new SymboleDefaut(D2), 3, s);
			return REDUIT;
	}
	
	return NON_RECONNU;
}

std::vector<SymboleEnum> E31::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT, ECRIRE, LIRE, VAR, CONST, FIN
	});
}
