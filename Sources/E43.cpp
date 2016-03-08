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
            automate->popSymbole();
            Identifiant* i = (Identifiant*) automate->popSymbole();
            automate->popSymbole();
            automate->popSymbole();
            
            automate->addDeclarationToProgram(new DeclarationConstante(i->getIdentifiant(), v->getValeur()));
            automate->reduction(new SymboleDefaut(EQ), 5);
            return REDUIT;
    }
	return NON_RECONNU;
}
