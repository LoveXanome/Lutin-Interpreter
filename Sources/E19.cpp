#include "E19.hpp"

#include "Expression.hpp"
#include "ExpressionDivision.hpp"

E19::E19() : Etat(19)
{
	
}

E19::~E19()
{
	
}

valeurRetour E19::transition(AutomateLutin* automate, Symbole* s)
{
	valeurRetour retour;
	switch (*s)
	{
		case PARENTHESE_FERMANTE :
        case MULTIPLIER :
        case DIVISER :
        case PLUS :
        case MOINS :
        case POINT_VIRGULE :
		{
			Expression* membreDroite = (Expression*)automate->popSymbole();
            delete automate->popSymbole();
			Expression* membreGauche = (Expression*)automate->popSymbole();

            ExpressionDivision* expDivision = new ExpressionDivision(membreGauche, membreDroite);

            automate->reduction(expDivision, 3, s);
            
            retour = REDUIT;
            break;
		}
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}

std::vector<SymboleEnum> E19::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		PARENTHESE_FERMANTE, MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
