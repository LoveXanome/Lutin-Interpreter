#include "E35.hpp"

#include "E36.hpp"

E35::E35() : Etat(35)
{
	
}

E35::~E35()
{
	
}

valeurRetour E35::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case EGAL:
			automate->decalage(s, new E36, true);
			return RECONNU;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E35::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		EGAL
	});
}

