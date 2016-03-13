#include "E21.hpp"

#include "ExpressionAddition.hpp"
#include "Expression.hpp"

#include "E16.hpp"
#include "E18.hpp"

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
		{
            Expression* membreDroite = (Expression*)automate->popSymbole();
            automate->popSymbole();
			Expression* membreGauche = (Expression*)automate->popSymbole();

            ExpressionAddition* expAddition = new ExpressionAddition(membreGauche, membreDroite);

            automate->reduction(expAddition, 3, s);
            
            retour = REDUIT;
            break;
		}
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

std::vector<SymboleEnum> E21::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		PARENTHESE_FERMANTE, MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
