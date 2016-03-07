#include "E16.hpp"

E16::E16() : Etat()
{
	
}

E16::~E16()
{
	
}

valeurRetour E16::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case ParentheseOuvrante :
            automate->decalage(s, new E8);
            break;
        case Identifiant :
            automate->decalage(s, new E11);
            break;
        case Valeur :
            automate->decalage(s, new E12);
            break;
        case EXP :
            automate->decalage(s, new E17);
    }
	return NON_RECONNU;
}
