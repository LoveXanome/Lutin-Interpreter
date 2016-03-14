#include "E15.hpp"

#include "Expression.hpp"

#include "ExpressionParenthese.hpp"

E15::E15() : Etat(15)
{
	
}

E15::~E15()
{
	
}

valeurRetour E15::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s)
	{
		case PLUS:
		case MOINS:
		case MULTIPLIER:
		case DIVISER:
		case PARENTHESE_FERMANTE:
		case POINT_VIRGULE:
			automate->popSymbole();
			Expression* e = (Expression*) automate->popSymbole();
			automate->popSymbole();
			ExpressionParenthese* ep = new ExpressionParenthese(e);
			
            automate->reduction(ep, 3, s);
            break;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E15::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        PARENTHESE_FERMANTE, MULTIPLIER, DIVISER, PLUS, MOINS, POINT_VIRGULE
    });
}
