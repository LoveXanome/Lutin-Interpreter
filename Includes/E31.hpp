#ifndef E31_HPP
#define E31_HPP

#include "Etat.hpp"

class E31 : public Etat
{
public:
	E31();
	virtual ~E31();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif // E31_HPP
