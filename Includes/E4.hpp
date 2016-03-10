#ifndef E4_HPP
#define E4_HPP

#include "Etat.hpp"

class E4 : public Etat
{
public:
	E4();
	virtual ~E4();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E4_HPP
