#include "E37.hpp"

#include "SymboleDefaut.hpp"
#include "DeclarationConstante.hpp"
#include "Identifiant.hpp"
#include "Valeur.hpp"

E37::E37() : Etat(37)
{
	
}

E37::~E37()
{
	
}

valeurRetour E37::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
		case VIRGULE:
		case POINT_VIRGULE:
        	Valeur* v = (Valeur*) automate->popSymbole();
            automate->popSymbole();
            Identifiant* i = (Identifiant*) automate->popSymbole();
            
            automate->addDeclarationToProgram(new DeclarationConstante(i->getIdentifiant(), v->getValeur()));
            automate->reduction(new SymboleDefaut(EQ), 3);
            return REDUIT;            
    }
	return NON_RECONNU;
}
