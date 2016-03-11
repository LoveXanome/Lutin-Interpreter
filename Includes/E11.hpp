#ifndef E11_HPP
#define E11_HPP

#include "Etat.hpp"

class E11 : public Etat
{
public:
	E11();
	virtual ~E11();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E11_HPP
