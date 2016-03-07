#ifndef E39_HPP
#define E39_HPP

#include "Etat.hpp"

class E39 : public Etat
{
public:
	E39();
	virtual ~E39();
	valeurRetour E39::transition(AutomateLutin* automate, Symbole * s);
};

#endif //E39_HPP
