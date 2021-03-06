#include "E2.hpp"

#include "E24.hpp"
#include "E4.hpp"
#include "E3.hpp"
#include "E7.hpp"
#include "SymboleDefaut.hpp"

E2::E2() : Etat(2)
{
	
}

E2::~E2()
{
	
}

valeurRetour E2::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case ECRIRE :
            automate->decalage(s, new E24, true);
            retour = RECONNU;
            break;
        case LIRE :
            automate->decalage(s, new E4, true);
            retour = RECONNU;
            break;
        case IDENTIFIANT:
			automate->decalage(s, new E7, true);
			retour = RECONNU;
			break;
        case I2:
            automate->decalage(s, new E3, false);
            retour = RECONNU;
            break;
        case FIN:
			automate->popSymbole();
			automate->popSymbole();
			automate->reduction(new SymboleDefaut(E), 2, s);
			retour = RECONNU;
			break;
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}

std::vector<SymboleEnum> E2::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		ECRIRE, LIRE, IDENTIFIANT
	});
}
