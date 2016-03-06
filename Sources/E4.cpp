#include "E4.hpp"

E4::E4() : Etat()
{
	
}

E4::~E4()
{
	
}

bool E4::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case Identifiant :
            automate.decalage(s, new E5);
            break;
    }
	return false;
}
