#ifndef E21_HPP
#define E21_HPP

#include "Etat.hpp"

class E21 : public Etat
{
public:
	E21();
	virtual ~E21();
	bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E21_HPP
