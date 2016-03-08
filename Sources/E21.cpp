#include "E21.hpp"

E21::E21() : Etat(21)
{
	
}

E21::~E21()
{
	
}

valeurRetour E21::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
	
		case DOLLAR :
            Expression eD = (Expression *) automate->popSymbole(); //EXP
            automate->popSymbole(); // + 
			Expression eG = (Expression *) automate->popSymbole(); //EXP
			
			automate->addInstructionToProgram( new ExpressionBinaire( eG , eD ) );
			automate->reduction(new SymboleDefaut(EXP), 3);
            retour = REDUIT;
            break;
	
		case PLUS :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionAddition() );
			automate->reduction(new SymboleDefaut(EXP), 1);
            retour = REDUIT;
            break;
            
        case MOINS :
            Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram( new ExpressionSoustraction() );
			automate->reduction(new SymboleDefaut(EXP), 1);
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
            
    }
	return NON_RECONNU;
}
