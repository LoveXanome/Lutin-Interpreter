#include "E6.hpp"

E6::E6() : Etat()
{
	
}

E6::~E6()
{
	
}

bool E6::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case default :
            automate.reduction(new E2, 2);
            break;
    }
	return false;
}
