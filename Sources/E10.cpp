#include "E10.hpp"

#include "InstructionAffectation.hpp"
#include "Expression.hpp"
#include "SymboleDefaut.hpp"

E10::E10() : Etat(10)
{
	
}

E10::~E10()
{
	
}

valeurRetour E10::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
		case IDENTIFIANT:
		case ECRIRE:
		case LIRE:
			automate->popSymbole(); // pv
			Expression* e = (Expression *) automate->popSymbole(); //EXP
			automate->popSymbole(); // aff
			automate->popSymbole(); // id

			automate->addInstructionToProgram(new InstructionAffectation(*e));		

			automate->reduction(new SymboleDefaut(I2), 4, s);
			return REDUIT;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E10::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        IDENTIFIANT, ECRIRE, LIRE
    });
}
