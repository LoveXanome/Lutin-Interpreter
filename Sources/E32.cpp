#include "E32.hpp"

#include "SymboleEnum.hpp"
#include "E33.hpp"

E32::E32() : Etat(32)
{
}

E32::~E32()
{
}

valeurRetour E32::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case IDENTIFIANT:
			automate->decalage(s, new E33, true);
			return RECONNU;
	}
	return NON_RECONNU;
}

std::vector<SymboleEnum> E32::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT
	});
}
