#include "E17.hpp"
#include "Expression.hpp"
#include "ExpressionMultiplication.hpp"
#include "SymboleDefaut.hpp"
#include "ExpressionReduction.hpp"
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
        case POINT_VIRGULE :
		{
            ExpressionReduction* eR;

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eD = new Expression(*((Expression*)eR->getExpression()));
            delete eR;
            
            automate->popSymbole(); //SIGNE *

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eG = new Expression(*((Expression*)eR->getExpression()));
            delete eR;

            ExpressionMultiplication* multiplication = new ExpressionMultiplication(eG, eD);
            ExpressionReduction* exp = new ExpressionReduction(EXP, multiplication);

            automate->reduction(exp, 3, s);
            
        }
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
