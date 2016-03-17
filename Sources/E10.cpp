#include "E10.hpp"
#include "Expression.hpp"
#include "Identifiant.hpp"
#include "InstructionAffectation.hpp"
#include "SymboleDefaut.hpp"

E10::E10() : Etat(10)
{
	
}

E10::~E10()
{
	
}

valeurRetour E10::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s)
	{
        case ECRIRE:
        case LIRE:
        case IDENTIFIANT:
        case I2:
        case FIN:
        {
			delete automate->popSymbole();
			Expression* e = (Expression*) automate->popSymbole();
			delete automate->popSymbole();
			Identifiant* i = (Identifiant*) automate->popSymbole();
			
			InstructionAffectation* instructionAffectation = new InstructionAffectation(i->getIdentifiant(), e);
			delete i;
			automate->addInstructionToProgram(instructionAffectation);

			automate->reduction(new SymboleDefaut(I2), 4, s);

			retour = REDUIT;
			break;
		}
		default:
			retour = NON_RECONNU;
			break;
    }
	return retour;
}

std::vector<SymboleEnum> E10::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        IDENTIFIANT, ECRIRE, LIRE, I2, FIN
    });
}
