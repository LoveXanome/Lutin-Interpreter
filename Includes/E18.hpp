#ifndef E18_HPP
#define E18_HPP

#include "Etat.hpp"

class E18 : public Etat
{
public:
	E18();
	virtual ~E18();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E18_HPP
