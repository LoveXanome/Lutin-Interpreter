#include "E3.hpp"

#include "SymboleDefaut.hpp"

E3::E3() : Etat(3)
{
	
}

E3::~E3()
{
	
}

valeurRetour E3::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        default :
			delete automate->popSymbole();
			delete automate->popSymbole();
            automate->reduction(new SymboleDefaut(I), 2, s);
            return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E3::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		NULL
	});
}
