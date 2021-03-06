#ifndef E43_HPP
#define E43_HPP

#include "Etat.hpp"

class E43 : public Etat
{
public:
	E43();
	virtual ~E43();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E43_HPP
