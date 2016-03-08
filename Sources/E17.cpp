#include "E17.hpp"

E17::E17() : Etat(17)
{
	
}

E17::~E17()
{
	
}

valeurRetour E17::transition(AutomateLutin* automate, Symbole * s)
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
			Expression eD = (Expression *) automate->popSymbole(); //EXP
            automate->popSymbole(); // / 
			Expression eG = (Expression *) automate->popSymbole(); //EXP			
			automate->addInstructionToProgram( new ExpressionBinaire( eG , eD ) );
			automate->reduction(new SymboleDefaut(EXP), 3);
            retour = REDUIT;
            break;
    }
	return NON_RECONNU;
}
