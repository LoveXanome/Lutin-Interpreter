#ifndef E8_HPP
#define E8_HPP

#include "Etat.hpp"

class E8 : public Etat
{
public:
	E8();
	virtual ~E8();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E8_HPP
