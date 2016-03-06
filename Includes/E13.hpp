#ifndef E13_HPP
#define E13_HPP

#include "Etat.hpp"

class E13 : public Etat
{
public:
	E13();
	virtual ~E13();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E13_HPP
