#ifndef E40_HPP
#define E40_HPP

#include "Etat.hpp"

class E40 : public Etat
{
public:
	E40();
	virtual ~E40();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
};

#endif //E40_HPP
