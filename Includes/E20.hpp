#ifndef E20_HPP
#define E20_HPP

#include "Etat.hpp"

class E20 : public Etat
{
public:
	E20();
	virtual ~E20();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E20_HPP
