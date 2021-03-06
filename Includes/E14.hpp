#ifndef E14_HPP
#define E14_HPP

#include "Etat.hpp"

class E14 : public Etat
{
public:
	E14();
	virtual ~E14();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E14_HPP
