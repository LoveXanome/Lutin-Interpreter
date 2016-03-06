#ifndef E8_HPP
#define E8_HPP

#include "Etat.hpp"

class E8 : public Etat
{
public:
	E8();
	virtual ~E8();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E8_HPP
