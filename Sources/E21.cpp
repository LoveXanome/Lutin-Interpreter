#include "E21.hpp"

E21::E21() : Etat()
{
	
}

E21::~E21()
{
	
}

bool E21::transition(AutomateLutin& automate, Symbole * s)
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
