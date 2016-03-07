#ifndef E10_HPP
#define E10_HPP

#include "Etat.hpp"

class E10 : public Etat
{
public:
	E10();
	virtual ~E10();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif //E10_HPP
