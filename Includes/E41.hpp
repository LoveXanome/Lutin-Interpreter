#ifndef E41_HPP
#define E41_HPP

#include "Etat.hpp"

class E41 : public Etat
{
public:
	E41();
	virtual ~E41();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
};

#endif //E41_HPP
