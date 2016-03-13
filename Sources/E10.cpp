#include "E10.hpp"
#include "Expression.hpp"
#include "Identifiant.hpp"
#include "InstructionAffectation.hpp"
#include "SymboleDefaut.hpp"
#include "ExpressionReduction.hpp"

E10::E10() : Etat(10)
{
	
}

E10::~E10()
{
	
}

valeurRetour E10::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
        case FIN :
        case ECRIRE :
        case LIRE :
        case IDENTIFIANT :
        case I2 :
		{
			automate->popSymbole(); //POINT_VIRGULE
			
			ExpressionReduction* eR = (ExpressionReduction*) automate->popSymbole();
			Expression* e = (Expression*) eR->getExpression();

			automate->popSymbole();//AFFECTATION

			Identifiant* i = (Identifiant*) automate->popSymbole();
				
			automate->addInstructionToProgram(new InstructionAffectation(i->getIdentifiant(), e));

			automate->reduction(new SymboleDefaut(I2), 4, s);

			retour = REDUIT;
			break;
		}
		default :
			retour = NON_RECONNU;
			break;
    }
	return retour;
}

std::vector<SymboleEnum> E10::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        IDENTIFIANT, ECRIRE, LIRE
    });
}
