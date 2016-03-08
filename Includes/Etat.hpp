#ifndef ETAT_HPP
#define ETAT_HPP

#include <string>

class AutomateLutin;

#include <string>
#include "AutomateLutin.hpp"
#include "Symbole.hpp"

typedef enum {ACCEPTE, RECONNU, NON_RECONNU, REDUIT, SUIVANT_NON_VALIDE, ERREUR_INIT} valeurRetour;	

class Etat
{
public:
	Etat(const unsigned int& number);
	virtual ~Etat();
	std::string toString() const;
	virtual valeurRetour transition(AutomateLutin* automate, Symbole* s) = 0;
	
private:
	int number;
};

#endif // ETAT_HPP
