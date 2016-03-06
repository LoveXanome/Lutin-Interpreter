#include "E20.hpp"

E20::E20() : Etat()
{
	
}

E20::~E20()
{
	
}

bool E20::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case ParentheseOuvrante :
            automate.decalage(s, new E8);
            break;
        case Identifiant :
            automate.decalage(s, new E11);
            break;
        case Valeur :
            automate.decalage(s, new E12);
            break;
        case EXP :
            automate.decalage(s, new E17);
    }
	return false;
}
