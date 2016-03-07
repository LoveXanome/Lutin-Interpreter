#ifndef E18_HPP
#define E18_HPP

#include "Etat.hpp"

class E18 : public Etat
{
public:
	E18();
	virtual ~E18();
	valeurRetour(AutomateLutin* automate, Symbole* s);
};

#endif //E18_HPP
