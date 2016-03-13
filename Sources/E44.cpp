#include "E44.hpp"

#include "SymboleDefaut.hpp"
#include "Valeur.hpp"
#include "Identifiant.hpp"
#include "DeclarationConstante.hpp"

E44::E44() : Etat(44)
{
	
}

E44::~E44()
{
	
}

valeurRetour E44::transition(AutomateLutin* automate, Symbole * s)
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
            automate->reduction(new SymboleDefaut(EQ), 5, s);
            return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E44::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		POINT_VIRGULE, VIRGULE
	});
}
