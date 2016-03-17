#include "E29.hpp"

#include "DeclarationVariable.hpp"
#include "Identifiant.hpp"
#include "SymboleDefaut.hpp"

E29::E29() : Etat(29)
{
}

E29::~E29()
{
}

valeurRetour E29::transition(AutomateLutin* automate, Symbole* s)
{
	switch (*s)
	{
		case POINT_VIRGULE:
		case VIRGULE:
			Identifiant* i = (Identifiant*) automate->popSymbole();
			automate->addDeclarationToProgram(new DeclarationVariable(i->getIdentifiant()));
			delete i;
			automate->reduction(new SymboleDefaut(ID), 1, s);
			return REDUIT;
	}

	return NON_RECONNU;
}

std::vector<SymboleEnum> E29::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		POINT_VIRGULE, VIRGULE
	});
}

