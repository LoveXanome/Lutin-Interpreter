#include "E0.hpp"

#include "SymboleEnum.hpp"
#include "E1.hpp"
#include "E44.hpp"

E0::E0() : Etat(0)
{
	
}

E0::~E0()
{
	
}

valeurRetour E0::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case VAR:
		case CONST:
        case D:
            automate->decalage(s, new E1, false);
            return RECONNU;
		case FIN:
			//automate->decalage(s, new E44, false);
			return RECONNU;
    }
	return NON_RECONNU;
}


std::vector<SymboleEnum> E0::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		VAR, CONST, D
	});
}
