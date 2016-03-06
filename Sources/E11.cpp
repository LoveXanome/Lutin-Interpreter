#include "E11.hpp"

E11::E11() : Etat()
{
	
}

E11::~E11()
{
	
}

bool E11::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case default :
            automate.reduction(new E8, 1);
            break;
    }
	return false;
}
