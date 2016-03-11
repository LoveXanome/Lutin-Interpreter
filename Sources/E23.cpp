#include "E23.hpp"
#include "Expression.hpp"
#include "ExpressionSoustraction.hpp"
#include "SymboleDefaut.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "SymboleDefaut.hpp"

E23::E23() : Etat(23)
{
	
}

E23::~E23()
{
	
}

valeurRetour E23::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour;
	switch (*s){
		case PARENTHESE_FERMANTE :
        case PLUS :
        case MOINS :
			Expression* eD = (Expression *) automate->popSymbole(); 
			automate->popSymbole();
			Expression* eG = (Expression *) automate->popSymbole(); 
			
			automate->addInstructionToProgram(new ExpressionSoustraction(eG, eD));
			automate->reduction(new SymboleDefaut(EXP), 3);
            
            retour = REDUIT;
            break;
		case MULTIPLIER :
            automate->decalage(s, new E16, true);
            retour = RECONNU;
            break;
		case DIVISER :
            automate->decalage(s, new E18, true);
            retour = RECONNU;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
