#ifndef E24_HPP
#define E24_HPP

#include "Etat.hpp"

class E24 : public Etat
{
public:
	E24();
	virtual ~E24();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E24_HPP
