#include "E19.hpp"
#include "Expression.hpp"
#include "ExpressionDivision.hpp"
#include "SymboleDefaut.hpp"
#include "ExpressionReduction.hpp"

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
		{
            ExpressionReduction* eR;

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eD = new Expression(*((Expression*)eR->getExpression()));
            delete eR;
            
            automate->popSymbole(); //SIGNE /

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eG = new Expression(*((Expression*)eR->getExpression()));
            delete eR;

            ExpressionDivision* division = new ExpressionDivision(eG, eD);
            ExpressionReduction* exp = new ExpressionReduction(EXP, division);

            automate->reduction(exp, 3, s);
            
        }
            retour = REDUIT;
            break;
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
