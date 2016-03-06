#include "E1.hpp"

E1::E1() : Etat()
{
	
}

E1::~E1()
{
	
}

bool E1::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case Const :
            automate.decalage(s, new E34);
            break;
        case I :
            automate.decalage(s, new E2);
            break;
        case D2 :
            automate.decalage(s, new E27);
            break;
    }
	return false;
}
