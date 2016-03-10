#ifndef E34_HPP
#define E34_HPP

#include "Etat.hpp"

class E34 : public Etat
{
public:
	E34();
	virtual ~E34();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E34_HPP
