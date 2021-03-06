#ifndef E22_HPP
#define E22_HPP

#include "Etat.hpp"

class E22 : public Etat
{
public:
	E22();
	virtual ~E22();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E22_HPP
