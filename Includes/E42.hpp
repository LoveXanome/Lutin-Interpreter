#ifndef E42_HPP
#define E42_HPP

#include "Etat.hpp"

class E42 : public Etat
{
public:
	E42();
	virtual ~E42();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E42_HPP
