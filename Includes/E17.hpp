#ifndef E17_HPP
#define E17_HPP

#include "Etat.hpp"

class E17 : public Etat
{
public:
	E17();
	virtual ~E17();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E17_HPP
