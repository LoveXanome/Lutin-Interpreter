#ifndef E25_HPP
#define E25_HPP

#include "Etat.hpp"

class E25 : public Etat
{
public:
	E25();
	virtual ~E25();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E25_HPP
