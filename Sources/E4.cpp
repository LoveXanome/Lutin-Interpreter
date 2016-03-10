#include "E4.hpp"

#include "E5.hpp"

E4::E4() : Etat(4)
{
	
}

E4::~E4()
{
	
}

valeurRetour E4::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case IDENTIFIANT:
            automate->decalage(s, new E5, true);
            retour = RECONNU;
            break;
		default:
			retour = NON_RECONNU;
    }
	return retour;
}

std::vector<SymboleEnum> E4::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT
	});
}
