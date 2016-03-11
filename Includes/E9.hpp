#ifndef E9_HPP
#define E9_HPP

#include "Etat.hpp"

class E9 : public Etat
{
public:
	E9();
	virtual ~E9();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;

};

#endif //E9_HPP
