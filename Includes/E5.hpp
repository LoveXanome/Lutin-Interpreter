#ifndef E5_HPP
#define E5_HPP

#include "Etat.hpp"

class E5 : public Etat
{
public:
	E5();
	virtual ~E5();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E5_HPP
