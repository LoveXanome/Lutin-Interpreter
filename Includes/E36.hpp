#ifndef E36_HPP
#define E36_HPP

#include "Etat.hpp"

class E36 : public Etat
{
public:
	E36();
	virtual ~E36();
	valeurRetour E36::transition(AutomateLutin* automate, Symbole * s);
};

#endif //E36_HPP