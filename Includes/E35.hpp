#ifndef E35_HPP
#define E35_HPP

#include "Etat.hpp"

class E35 : public Etat
{
public:
	E35();
	virtual ~E35();
	valeurRetour E35::transition(AutomateLutin* automate, Symbole * s);
};

#endif //E35_HPP
