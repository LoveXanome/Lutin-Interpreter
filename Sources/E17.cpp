#include "E17.hpp"

#include "Expression.hpp"
#include "ExpressionMultiplication.hpp"

E17::E17() : Etat(17)
{
	
}

E17::~E17()
{
	
}

valeurRetour E17::transition(AutomateLutin* automate, Symbole * s)
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
            automate->popSymbole();
			Expression* membreGauche = (Expression*)automate->popSymbole();

            ExpressionMultiplication* expMultiplication = new ExpressionMultiplication(membreGauche, membreDroite);

            automate->reduction(expMultiplication, 3, s);
            
            retour = REDUIT;
            break;
		}
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}

std::vector<SymboleEnum> E17::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
		PARENTHESE_FERMANTE, MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
