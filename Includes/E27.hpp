#ifndef E27_HPP
#define E27_HPP

#include "Etat.hpp"

class E27 : public Etat
{
public:
	E27();
	virtual ~E27();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E27_HPP
