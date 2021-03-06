#ifndef E32_HPP
#define E32_HPP

#include "Etat.hpp"

class E32 : public Etat
{
public:
	E32();
	virtual ~E32();
	valeurRetour transition(AutomateLutin* automate, Symbole* s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif // E32_HPP
