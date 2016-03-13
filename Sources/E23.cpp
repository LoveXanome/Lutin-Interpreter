#include "E23.hpp"
#include "Expression.hpp"
#include "ExpressionSoustraction.hpp"
#include "SymboleDefaut.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "SymboleDefaut.hpp"
#include "ExpressionReduction.hpp"

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
        case POINT_VIRGULE :
		{
            ExpressionReduction* eR;

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eD = new Expression(*((Expression*)eR->getExpression()));
            delete eR;
            
            automate->popSymbole(); //SIGNE -

            eR = (ExpressionReduction*) automate->popSymbole();
            Expression* eG = new Expression(*((Expression*)eR->getExpression()));
            delete eR;

            ExpressionSoustraction* soustraction = new ExpressionSoustraction(eG, eD);
            ExpressionReduction* exp = new ExpressionReduction(EXP, soustraction);

            automate->reduction(exp, 3, s);
            
        }
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
