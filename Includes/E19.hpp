#ifndef E19_HPP
#define E19_HPP

#include "Etat.hpp"

class E19 : public Etat
{
public:
	E19();
	virtual ~E19();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif //E19_HPP
