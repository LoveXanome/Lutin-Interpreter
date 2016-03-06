#include "E22.hpp"

E22::E22() : Etat()
{
	
}

E22::~E22()
{
	
}

bool E22::transition(AutomateLutin& automate, Symbole * s)
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
