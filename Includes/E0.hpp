#ifndef E0_HPP
#define E0_HPP

#include "Etat.hpp"

class E0 : public Etat
{
	public:
		bool transition(AutomateLutin& automate, Symbole* s);
};

#endif //E0_HPP
