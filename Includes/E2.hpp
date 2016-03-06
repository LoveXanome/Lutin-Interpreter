#ifndef E2_HPP
#define E2_HPP

#include "Etat.hpp"

class E2 : public Etat
{
public:
	E2();
	virtual ~E2();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E2_HPP
