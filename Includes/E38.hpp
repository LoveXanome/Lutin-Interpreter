#ifndef E38_HPP
#define E38_HPP

#include "Etat.hpp"

class E38 : public Etat
{
public:
	E38();
	virtual ~E38();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E38_HPP
