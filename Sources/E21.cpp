#include "E21.hpp"
#include "Valeur.hpp"
#include "ExpressionAddition.hpp"
#include "SymboleDefaut.hpp"
#include "E16.hpp"
#include "E18.hpp"
#include "SymboleDefaut.hpp"

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
            automate->popSymbole(); 
            Valeur* eD = (Valeur *) automate->popSymbole(); 
            
            automate->popSymbole();

            automate->popSymbole(); 
            Valeur* eG = (Valeur *) automate->popSymbole(); 
            
            Symbole* addition = new ExpressionAddition(eG, eD);

            automate->addSymbole(addition);
            automate->reduction(new SymboleDefaut(EXP), 3, s);
            
        }	
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
        default:
            retour = NON_RECONNU;
            break;
    }
    return retour;
}
