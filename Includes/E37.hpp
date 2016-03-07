#ifndef E37_HPP
#define E37_HPP

#include "Etat.hpp"

class E37 : public Etat
{
public:
	E37();
	virtual ~E37();
	valeurRetour E37::transition(AutomateLutin* automate, Symbole * s);
};

#endif //E37_HPP