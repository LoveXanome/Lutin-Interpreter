#ifndef E0_HPP
#define E0_HPP

#include "Etat.hpp"

class E0 : public Etat
{
public:
	E0();
	virtual ~E0();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E0_HPP
