#include "E12.hpp"

E12::E12() : Etat()
{
	
}

E12::~E12()
{
	
}

bool E12::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case default :
            automate.reduction(new E8, 1);
            break;
    }
	return false;
}
