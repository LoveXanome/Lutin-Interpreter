#include "E27.hpp"

#include "SymboleEnum.hpp"
#include "SymboleDefaut.hpp"

E27::E27() : Etat(27)
{
}

E27::~E27()
{
}

valeurRetour E27::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case VAR:
		case CONST:
		case FIN:
			automate->popSymbole();
			automate->popSymbole();
			automate->reduction(new SymboleDefaut(D), 2, s);
			return REDUIT;
	}
	return NON_RECONNU;
}

std::vector<SymboleEnum> E27::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT, ECRIRE, LIRE, VAR, CONST, FIN
	});
}
