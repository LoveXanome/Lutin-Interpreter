#ifndef E28_HPP
#define E28_HPP

#include "Etat.hpp"

class E28 : public Etat
{
public:
	E28();
	virtual ~E28();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
};

#endif // E28_HPP
