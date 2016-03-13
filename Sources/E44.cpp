#include "E44.hpp"

#include <stdexcept>
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
	return ACCEPTE;
}

std::vector<SymboleEnum> E44::getExpectedSymbols() const
{
	throw std::runtime_error("E44 does not have expected next symbols. End of program");
}
