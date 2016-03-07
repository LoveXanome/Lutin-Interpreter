#include "E5.hpp"

E5::E5() : Etat()
{
	
}

E5::~E5()
{
	
}

valeurRetour E5::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case PointVirgule :
            automate->decalage(s, new E6);
            break;
    }
	return NON_RECONNU;
}
