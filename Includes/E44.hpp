#ifndef E44_HPP
#define E44_HPP

#include "Etat.hpp"

class E44 : public Etat
{
public:
	E44();
	virtual ~E44();
	valeurRetour transition(AutomateLutin* automate, Symbole * s);
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
};

#endif //E44_HPP
