#include "E32.hpp"

#include "SymboleEnum.hpp"

E32::E32() : Etat()
{
}

E32::~E32()
{
}

bool E32::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case IDENTIFIANT:
			automate->decalage(s, new E33, true);
			break;
	}
	return false;
}
