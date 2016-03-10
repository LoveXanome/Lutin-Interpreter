#ifndef E11_HPP
#define E11_HPP

#include "Etat.hpp"

class E11 : public Etat
{
public:
	E11();
	virtual ~E11();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif //E11_HPP
