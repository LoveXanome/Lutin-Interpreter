#ifndef E29_HPP
#define E29_HPP

#include "Etat.hpp"

class E29 : public Etat
{
public:
	E29();
	virtual ~E29();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E29_HPP
