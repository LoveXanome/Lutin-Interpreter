#include "E0.hpp"

#include "SymboleEnum.hpp"

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
            //automate->decalage(s, new E1);
            break;
    }
	return NON_RECONNU;
}
