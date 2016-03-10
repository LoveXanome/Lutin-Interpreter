#ifndef E7_HPP
#define E7_HPP

#include "Etat.hpp"

class E7 : public Etat
{
public:
	E7();
	virtual ~E7();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E7_HPP
