#include "E13.hpp"

E13::E13() : Etat()
{
	
}

E13::~E13()
{
	
}

Etat::valeurRetour E13::transition(AutomateLutin* automate, Symbole * s)
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
            automate->decalage(s, new E14);
            break;
    }
	return NON_RECONNU;
}
