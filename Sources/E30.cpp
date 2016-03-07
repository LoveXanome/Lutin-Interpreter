#include "E30.hpp"

#include "SymboleEnum.hpp"

E30::E30() : Etat()
{
	
}

E30::~E30()
{
	
}

bool E30::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case POINT_VIRGULE:
			automate->decalage(s, new E31);
			break;
		case VIRGULE:
			automate->decalage(s, new E32);
			break;
    }
	return false;
}
