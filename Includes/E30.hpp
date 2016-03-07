#ifndef E30_HPP
#define E30_HPP

#include "Etat.hpp"

class E30 : public Etat
{
public:
	E30();
	virtual ~E30();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif // E30_HPP
