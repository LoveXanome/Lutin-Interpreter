#include "E8.hpp"

E8::E8() : Etat()
{
	
}

E8::~E8()
{
	
}

Etat::valeurRetour E8::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case Identifiant :
            automate->decalage(s, new E11);
            break;
        case Valeur :
            automate->decalage(s, new E12);
            break;
        case ParentheseOuvrante :
            automate->decalage(s, new E13);
            break;
        case EXP :
            automate->decalage(s, new E9);
            break;
    }
	return NON_RECONNU;
}
