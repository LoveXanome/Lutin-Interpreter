#ifndef E6_HPP
#define E6_HPP

#include "Etat.hpp"

class E6 : public Etat
{
public:
	E6();
	virtual ~E6();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E6_HPP
