#include "E10.hpp"

E10::E10() : Etat()
{
	
}

E10::~E10()
{
	
}

bool E10::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case default :
            automate.reduction(new E9, 1);
            break;
    }
	return false;
}
