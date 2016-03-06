#ifndef E20_HPP
#define E20_HPP

#include "Etat.hpp"

class E20 : public Etat
{
public:
	E20();
	virtual ~E20();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E20_HPP
