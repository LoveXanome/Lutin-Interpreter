#ifndef E31_HPP
#define E31_HPP

#include "Etat.hpp"

class E31 : public Etat
{
public:
	E31();
	virtual ~E31();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E31_HPP
