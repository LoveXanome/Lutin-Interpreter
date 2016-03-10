#ifndef E26_HPP
#define E26_HPP

#include "Etat.hpp"

class E26 : public Etat
{
public:
	E26();
	virtual ~E26();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E26_HPP
