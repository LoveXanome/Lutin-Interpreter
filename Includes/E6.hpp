#ifndef E6_HPP
#define E6_HPP

#include "Etat.hpp"

class E6 : public Etat
{
public:
	E6();
	virtual ~E6();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E6_HPP
