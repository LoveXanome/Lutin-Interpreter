#include "E27.hpp"

#include "SymboleEnum.hpp"

E27::E27() : Etat()
{
}

E27::~E27()
{
}

bool E27::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		// TODO suivant de D
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case VAR:
		case CONST:
			automate->popSymbole();
			automate->popSymbole();
			
			automate->reduction(new SymboleDefaut(D), 2);
			break;
	}
	return false;
}
