#ifndef E29_HPP
#define E29_HPP

#include "Etat.hpp"

class E29 : public Etat
{
public:
	E29();
	virtual ~E29();
	bool transition(AutomateLutin* automate, Symbole* s);
};

#endif // E29_HPP
