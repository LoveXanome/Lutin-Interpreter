#ifndef E22_HPP
#define E22_HPP

#include "Etat.hpp"

class E22 : public Etat
{
public:
	E22();
	virtual ~E22();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E22_HPP
