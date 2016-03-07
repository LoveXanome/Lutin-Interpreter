#include "E26.hpp"

#include "SymboleEnum.hpp"

E26::E26() : Etat()
{
	
}

E26::~E26()
{
	
}

valeurRetour E26::transition(AutomateLutin* automate, Symbole * s)
{
    valeurRetour retour = ERREUR_INIT;

    // I2 -> ecrire EXP pv•
    if( (*s == INDENTIFIANT) OR (*s == ECRIRE) OR (*s == LIRE) OR (*s == DOLLAR) )
    {
        automate->popSymbole();  //pv
        Expression e = (Expression *) automate->popSymbole(); //EXP
        automate->popSymbole();  //lire

        automate->addInstructionToProgram( new InstructionLecture( e->getIdentifiant() ) );
        automate->reduction( new SymboleDefaut(I2) , 3 );
        retour = REDUIT;
    }
    else
    {
        retour = SUIVANT_NON_VALIDE;
    }

	return retour;
}
