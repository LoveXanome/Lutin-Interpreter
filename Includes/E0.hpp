#ifndef E0_HPP
#define E0_HPP

#include "Etat.hpp"

class E0 : public Etat
{
public:
	E0();
	virtual ~E0();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif // E0_HPP
