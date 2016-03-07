#include "E0.hpp"

#include "SymboleEnum.hpp"
#include "E1.hpp"

E0::E0() : Etat()
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
            break;
    }
	return NON_RECONNU;
}
