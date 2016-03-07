#include "E6.hpp"

#include "SymboleDefaut.hpp"
#include "InstructionLecture.hpp"
#include "Identifiant.hpp"

E6::E6() : Etat()
{
	
}

E6::~E6()
{
	
}

valeurRetour E6::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
        case IDENTIFIANT:
        case ECRIRE:
        case LIRE:
			automate->popSymbole();
			Identifiant* i = (Identifiant*) automate->popSymbole();
			automate->popSymbole();
			
			automate->addInstructionToProgram(new InstructionLecture(i->getIdentifiant()));
            automate->reduction(new SymboleDefaut(I2), 3);
            return REDUIT;
    }
	return NON_RECONNU;
}
