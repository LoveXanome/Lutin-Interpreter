#ifndef E16_HPP
#define E16_HPP

#include "Etat.hpp"

class E16 : public Etat
{
public:
	E16();
	virtual ~E16();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E16_HPP
