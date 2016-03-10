#include "E26.hpp"

#include "SymboleEnum.hpp"

E26::E26() : Etat(26)
{
	
}

E26::~E26()
{
	
}

valeurRetour E26::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = SUIVANT_NON_VALIDE;
    switch (*s)
    {
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case DOLLAR:
			automate->popSymbole();
			Expression e = (Expression *) automate->popSymbole();
			automate->popSymbole();

			automate->addInstructionToProgram(new InstructionLecture(e->getIdentifiant()));
			automate->reduction(new SymboleDefaut(I2), 3);
			retour = REDUIT;
			break;
    }

	return retour;
}
