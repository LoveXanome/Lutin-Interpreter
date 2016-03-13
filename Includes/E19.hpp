#ifndef E19_HPP
#define E19_HPP

#include "Etat.hpp"

class E19 : public Etat
{
public:
	E19();
	virtual ~E19();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E19_HPP
