#include "E6.hpp"

#include "SymboleDefaut.hpp"
#include "InstructionLecture.hpp"
#include "Identifiant.hpp"

E6::E6() : Etat()
{
	
}

E6::~E6()
{
	
}

Etat::valeurRetour E6::transition(AutomateLutin* automate, Symbole * s)
{
	valeurRetour retour = ERREUR_INIT;

	if( (*s == IDENTIFIANT) || (*s == ECRIRE) || (*s == LIRE) || (*s == DOLLAR) )
	{
		automate->popSymbole(); //pv
		Identifiant* i = (Identifiant*) automate->popSymbole(); //id
		automate->popSymbole();//lire
		
		automate->addInstructionToProgram(new InstructionLecture(i->getIdentifiant()));
		automate->reduction(new SymboleDefaut(I2),3);
		retour = REDUIT;
	}
	else
	{
		retour = SUIVANT_NON_VALIDE;
    }
	return retour;
}
