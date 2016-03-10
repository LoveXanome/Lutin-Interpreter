#ifndef E35_HPP
#define E35_HPP

#include "Etat.hpp"

class E35 : public Etat
{
public:
	E35();
	virtual ~E35();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E35_HPP
