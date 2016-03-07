#ifndef ETAT_HPP
#define ETAT_HPP

#include <string>

class AutomateLutin;

#include "AutomateLutin.hpp"
#include "Symbole.hpp"

class Etat
{
protected :
	typedef enum {ACCEPTE, RECONNU, NON_RECONNU, REDUIT} valeurRetour;	
	
public:
	Etat();
	virtual ~Etat();
	void print() const;
	virtual valeurRetour transition(AutomateLutin* automate, Symbole* s) = 0;
};

#endif // ETAT_HPP
