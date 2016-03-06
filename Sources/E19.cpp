#include "E19.hpp"

E19::E19() : Etat()
{
	
}

E19::~E19()
{
	
}

bool E19::transition(AutomateLutin& automate, Symbole * s)
{
	switch (*s){
        case Multiplier :
            automate.decalage(s, new E16);
            break;
        case Diviser :
            automate.decalage(s, new E18);
            break;
        case Plus :
            automate.decalage(s, new E20);
            break;
        case Moins :
            automate.decalage(s, new E22);
            break;
    }
	return false;
}
