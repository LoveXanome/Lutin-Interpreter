#include "E33.hpp"

#include "SymboleEnum.hpp"
#include "Identifiant.hpp"
#include "SymboleDefaut.hpp"
#include "DeclarationVariable.hpp"

E33::E33() : Etat()
{
}

E33::~E33()
{
}

bool E33::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case POINT_VIRGULE:
		case VIRGULE:
			Identifiant* i = (Identifiant*) automate->popSymbole();
			automate->popSymbole();
			automate->popSymbole();
			automate->addDeclarationToProgram(new DeclarationVariable(i->getIdentifiant()));
			
			automate->reduction(new SymboleDefaut(ID), 3);
			break;
	}
	return false;
}
