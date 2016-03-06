#ifndef E1_HPP
#define E1_HPP

#include "Etat.hpp"

class E1 : public Etat
{
public:
	E1();
	virtual ~E1();
	bool transition(AutomateLutin* automate, Symbole* s);
};

#endif //E1_HPP
