#include "E6.hpp"

#include "SymboleDefaut.hpp"
#include "InstructionLecture.hpp"
#include "Identifiant.hpp"

E6::E6() : Etat(6)
{
	
}

E6::~E6()
{
	
}

valeurRetour E6::transition(AutomateLutin* automate, Symbole* s)
{
	valeurRetour retour = SUIVANT_NON_VALIDE;
	switch (*s)
	{
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case FIN:
			automate->popSymbole();
			Identifiant* i = (Identifiant*) automate->popSymbole();
			automate->popSymbole();
			
			automate->addInstructionToProgram(new InstructionLecture(i->getIdentifiant()));
			automate->reduction(new SymboleDefaut(I2), 3, s);
			retour = REDUIT;
			break;
	}
	return retour;
}

std::vector<SymboleEnum> E6::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		IDENTIFIANT, ECRIRE, LIRE, FIN
	});
}
