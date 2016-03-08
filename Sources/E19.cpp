#include "E19.hpp"

E19::E19() : Etat(19)
{
	
}

E19::~E19()
{
	
}

valeurRetour E19::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
		case PLUS :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionAddition() );
			automate->reduction(new SymboleDefaut(EXP), 1);
            retour = REDUIT;
            break;
        case MOINS :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionSoustraction() );
			automate->reduction(new SymboleDefaut(EXP), 1);
            retour = REDUIT;
            break;
        case MULTIPLIER :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionMultiplication() );
			automate->reduction(new SymboleDefaut(EXP), 1);
            retour = REDUIT;
            break;
        case DIVISER :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionDivision() );
			automate->reduction(new SymboleDefaut(EXP), 1);
            retour = REDUIT;
            break;
        case DOLLAR :
			Expression e1 = (Expression *) automate->popSymbole(); //EXP
			automate->popSymbole(); // /
			Expression e2 = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionBinaire( e1, e2 ));
			automate->reduction(new SymboleDefaut(EXP), 3);
            retour = REDUIT;
    }
	return NON_RECONNU;
}
