#include "E23.hpp"

#include "SymboleEnum.hpp"

E23::E23() : Etat(23)
{
	
}

E23::~E23()
{
	
}

valeurRetour E23::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = NON_RECONNU;

	switch (*s){

		case DOLLAR :
            Expression eD = (Expression *) automate->popSymbole(); //EXP
            automate->popSymbole(); // - 
			Expression eG = (Expression *) automate->popSymbole(); //EXP
			
			automate->addInstructionToProgram( new ExpressionBinaire( eG , eD ) );
			automate->reduction(new SymboleDefaut(EXP), 3);
            retour = REDUIT;
            break;

		case PLUS :
			Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram(new ExpressionAddition() );
			automate->reduction(new SymboleDefaut(EXP), 3);
            retour = REDUIT;
            break;
            
        case MOINS :
            Expression e = (Expression *) automate->popSymbole(); //EXP
			automate->addInstructionToProgram( new ExpressionSoustraction() );
			automate->reduction(new SymboleDefaut(EXP), 3);
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
	return retour;
}
