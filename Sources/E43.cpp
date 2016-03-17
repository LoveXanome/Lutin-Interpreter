#include "E43.hpp"

#include "SymboleDefaut.hpp"
#include "Valeur.hpp"
#include "Identifiant.hpp"
#include "DeclarationConstante.hpp"

E43::E43() : Etat(43)
{
	
}

E43::~E43()
{
	
}

valeurRetour E43::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case VIRGULE:
        case POINT_VIRGULE: 
            Valeur* v = (Valeur*) automate->popSymbole();
            delete automate->popSymbole();
            Identifiant* i = (Identifiant*) automate->popSymbole();
            delete automate->popSymbole();
            delete automate->popSymbole();
            
            automate->addDeclarationToProgram(new DeclarationConstante(i->getIdentifiant(), v->getValeur()));
            delete v;
            delete i;
            automate->reduction(new SymboleDefaut(EQ), 5, s);
            return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E43::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		POINT_VIRGULE, VIRGULE
	});
}
