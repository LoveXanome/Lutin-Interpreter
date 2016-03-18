#include "E26.hpp"

#include "Expression.hpp"
#include "InstructionEcriture.hpp"
#include "SymboleDefaut.hpp"

E26::E26() : Etat(26)
{
	
}

E26::~E26()
{
	
}

valeurRetour E26::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;
    switch (*s)
    {
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
		case FIN:
			automate->popSymbole();
			Expression* e = (Expression*) automate->popSymbole();
			automate->popSymbole();

			InstructionEcriture* instrEcriture = new InstructionEcriture(e);
			automate->addInstructionToProgram(instrEcriture);
			
			automate->reduction(new SymboleDefaut(I2), 3, s);
			retour = REDUIT;
			break;
    }

	return retour;
}

std::vector<SymboleEnum> E26::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		IDENTIFIANT, ECRIRE, LIRE, FIN
    });
}

