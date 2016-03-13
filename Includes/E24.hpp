#ifndef E24_HPP
#define E24_HPP

#include "Etat.hpp"

class E24 : public Etat
{
public:
	E24();
	virtual ~E24();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E24_HPP
