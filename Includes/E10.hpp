#ifndef E10_HPP
#define E10_HPP

#include "Etat.hpp"

class E10 : public Etat
{
public:
	E10();
	virtual ~E10();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E10_HPP
