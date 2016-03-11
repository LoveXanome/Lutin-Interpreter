#include "E17.hpp"
#include "Expression.hpp"
#include "ExpressionMultiplication.hpp"
#include "SymboleDefaut.hpp"
#include "SymboleDefaut.hpp"
#include "InstructionAffectation.hpp"
#include "Expression.hpp"


E17::E17() : Etat(17)
{
	
}

E17::~E17()
{
	
}

valeurRetour E17::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
	switch (*s){
		case PARENTHESE_FERMANTE :
        case MULTIPLIER :
        case DIVISER :
        case PLUS :
        case MOINS :
		{
			Expression* eD = (Expression *) automate->popSymbole(); 
			automate->popSymbole();
			Expression* eG = (Expression *) automate->popSymbole(); 
			
			//instruction affectation mais comment on peut avoir le ID
			ExpressionMultiplication em = ExpressionMultiplication(*eG, *eD);
			automate->addInstructionToProgram(new InstructionAffectation("toReplaceInE17", em));
			
			automate->reduction(new SymboleDefaut(EXP), 3, s);
            
            retour = REDUIT;
		}
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
