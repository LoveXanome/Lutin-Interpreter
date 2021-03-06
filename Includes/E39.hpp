#ifndef E39_HPP
#define E39_HPP

#include "Etat.hpp"

class E39 : public Etat
{
public:
	E39();
	virtual ~E39();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E39_HPP
