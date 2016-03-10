#ifndef E3_HPP
#define E3_HPP

#include "Etat.hpp"

class E3 : public Etat
{
public:
	E3();
	virtual ~E3();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E3_HPP
