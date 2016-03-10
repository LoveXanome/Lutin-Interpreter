#include "E28.hpp"

#include "E29.hpp"
#include "E30.hpp"

E28::E28() : Etat(28)
{
}

E28::~E28()
{
}

valeurRetour E28::transition(AutomateLutin* automate, Symbole* s)
{
	switch(*s)
	{
		case IDENTIFIANT:
			automate->decalage(s, new E29, true);
			return RECONNU;
		case ID:
			automate->decalage(s, new E30, false);
			return RECONNU;
	}
	return NON_RECONNU;
}
