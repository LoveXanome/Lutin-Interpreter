#include "E34.hpp"

#include "E35.hpp"
#include "E38.hpp"

E34::E34() : Etat(34)
{
	
}

E34::~E34()
{
	
}

valeurRetour E34::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT:
            automate->decalage(s, new E35, true);
            return RECONNU;
        case EQ:
			automate->decalage(s, new E38, false);
			return RECONNU;        
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E34::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT, EQ
	});
}

