#include "E2.hpp"

E2::E2() : Etat()
{
	
}

E2::~E2()
{
	
}

bool E2::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case Ecrire :
            automate.decalage(s, new E24);
            break;
        case I2 :
            automate.decalage(s, new E3);
            break;
        case Lire :
            automate.decalage(s, new E4);
            break;
        case Identifiant :
            automate.decalage(s, new E3);
            break;
    }
	return false;
}
