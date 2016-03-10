#ifndef E33_HPP
#define E33_HPP

#include "Etat.hpp"

class E33 : public Etat
{
public:
	E33();
	virtual ~E33();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif // E33_HPP
