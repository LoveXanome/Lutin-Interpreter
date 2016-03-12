#include "E19.hpp"
#include "Expression.hpp"
#include "ExpressionMultiplication.hpp"
#include "SymboleDefaut.hpp"
#include "SymboleDefaut.hpp"

E19::E19() : Etat(19)
{
	
}

E19::~E19()
{
	
}

valeurRetour E19::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
		case PARENTHESE_FERMANTE :
        case MULTIPLIER :
        case DIVISER :
        case PLUS :
        case MOINS :
        case POINT_VIRGULE :
			Expression eD = (Expression *) automate->popSymbole(); 
			automate->popSymbole();
			Expression eG = (Expression *) automate->popSymbole(); 
			
			automate->addInstructionToProgram(new ExpressionDivision(eG, eD));
			
			automate->reduction(new SymboleDefaut(EXP), 3);
            
            retour = REDUIT;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
