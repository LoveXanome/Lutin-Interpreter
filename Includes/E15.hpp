#ifndef E15_HPP
#define E15_HPP

#include "Etat.hpp"

class E15 : public Etat
{
public:
	E15();
	virtual ~E15();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E15_HPP
