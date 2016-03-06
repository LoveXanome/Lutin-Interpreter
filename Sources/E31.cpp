#include "E31.hpp"

#include "SymboleEnum.hpp"
#include "DeclarationVariable.hpp"

E31::E31() : Etat()
{
	
}

E31::~E31()
{
	
}

bool E31::transition(AutomateLutin* automate, Symbole* s)
{
	automate->reduction(new DeclarationVariable(..., D2, 3));
	
	return false;
}
