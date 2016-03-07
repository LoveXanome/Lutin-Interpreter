#include "E28.hpp"

#include "E29.hpp"
#include "E30.hpp"

E28::E28() : Etat()
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
			break;
		case ID:
			automate->decalage(s, new E30, false);
			break;
	}
	return NON_RECONNU;
}
