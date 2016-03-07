#ifndef E9_HPP
#define E9_HPP

#include "Etat.hpp"

class E9 : public Etat
{
public:
	E9();
	virtual ~E9();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif //E9_HPP
