#ifndef E34_HPP
#define E34_HPP

#include "Etat.hpp"

class E34 : public Etat
{
public:
	E34();
	virtual ~E34();
	valeurRetour E34::transition(AutomateLutin* automate, Symbole * s)
};

#endif //E34_HPP
