#include "E18.hpp"

E18::E18() : Etat()
{
	
}

E18::~E18()
{
	
}

bool E18::transition(AutomateLutin& automate, Symbole * s)
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
