#include "E38.hpp"

#include "E39.hpp"
#include "E40.hpp"

E38::E38() : Etat()
{
	
}

E38::~E38()
{
	
}

valeurRetour E38::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case POINT_VIRGULE:
            automate->decalage(s, new E39, true);
            return RECONNU;
        case VIRGULE:
			automate->decalage(s, new E40, true);
			return RECONNU;
    }
	return NON_RECONNU;
}
