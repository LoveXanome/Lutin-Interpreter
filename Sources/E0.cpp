#include "E0.hpp"

#include "SymboleEnum.hpp"

E0::E0() : Etat()
{
	
}

E0::~E0()
{
	
}

bool E0::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
        case D:
            //automate->decalage(s, new E1);
            break;
    }
	return false;
}
