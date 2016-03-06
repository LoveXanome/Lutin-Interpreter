#ifndef E3_HPP
#define E3_HPP

#include "Etat.hpp"

class E3 : public Etat
{
public:
	E3();
	virtual ~E3();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E3_HPP
