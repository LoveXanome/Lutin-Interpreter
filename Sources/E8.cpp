#include "E8.hpp"

#include "SymboleEnum.hpp"
#include "E9.hpp"
#include "E11.hpp"
#include "E12.hpp"
#include "E13.hpp"


E8::E8() : Etat(8)
{
	
}

E8::~E8()
{
	
}

valeurRetour E8::transition(AutomateLutin* automate, Symbole * s)
{
	switch (*s){
        case IDENTIFIANT :
            automate->decalage(s, new E11, true);
            return RECONNU;
        case VALEUR :
            automate->decalage(s, new E12, true);
            return RECONNU;
        case PARENTHESE_OUVRANTE :
            automate->decalage(s, new E13, true);
            return RECONNU;
        case EXP :
            automate->decalage(s, new E9, false);
            return RECONNU;
    }
	return NON_RECONNU;
}

std::vector<SymboleEnum> E8::getExpectedSymbols() const
{
    return std::vector<SymboleEnum>({
        IDENTIFIANT, VALEUR, PARENTHESE_OUVRANTE, EXP
    });
}