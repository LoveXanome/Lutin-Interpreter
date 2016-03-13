#ifndef E23_HPP
#define E23_HPP

#include "Etat.hpp"

class E23 : public Etat
{
public:
	E23();
	virtual ~E23();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E23_HPP
