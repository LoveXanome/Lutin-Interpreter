#include "E7.hpp"

#include "SymboleEnum.hpp"
#include "E8.hpp"

E7::E7() : Etat(7)
{
	
}

E7::~E7()
{
	
}

valeurRetour E7::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case AFFECTATION:
            automate->decalage(s, new E8, true);
            return RECONNU;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E7::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		AFFECTATION
	});
}
