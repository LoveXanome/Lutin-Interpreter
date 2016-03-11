#ifndef E12_HPP
#define E12_HPP

#include "Etat.hpp"

class E12 : public Etat
{
public:
	E12();
	virtual ~E12();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E12_HPP
