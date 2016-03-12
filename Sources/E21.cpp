#include "E21.hpp"
#include "Expression.hpp"
#include "ExpressionMultiplication.hpp"
#include "SymboleDefaut.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "SymboleDefaut.hpp"

E21::E21() : Etat(21)
{
	
}

E21::~E21()
{
	
}

valeurRetour E21::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour;
	switch (*s){
		case PARENTHESE_FERMANTE :
        case PLUS :
        case MOINS :
        case POINT_VIRGULE :
			Expression* eD = (Expression *) automate->popSymbole(); 
			automate->popSymbole();
			Expression* eG = (Expression *) automate->popSymbole(); 
			
			automate->addInstructionToProgram(new ExpressionAddition(eG, eD));
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
