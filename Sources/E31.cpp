#include "E31.hpp"

#include "SymboleEnum.hpp"
#include "DeclarationVariable.hpp"

E31::E31() : Etat()
{
	
}

E31::~E31()
{
	
}

valeurRetour E31::transition(AutomateLutin* automate, Symbole* s)
{
	automate->reduction(new DeclarationVariable(..., D2, 3));
	
	return NON_RECONNU;
}
