#ifndef E21_HPP
#define E21_HPP

#include "Etat.hpp"

class E21 : public Etat
{
public:
	E21();
	virtual ~E21();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E21_HPP
