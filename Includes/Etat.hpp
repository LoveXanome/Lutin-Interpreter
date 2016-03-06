#ifndef ETAT_HPP
#define ETAT_HPP

#include <string>

class AutomateLutin;

#include "AutomateLutin.hpp"
#include "Symbole.hpp"

class Etat
{
public:
	Etat();
	virtual ~Etat();
	void print() const;
	virtual bool transition(AutomateLutin* automate, Symbole* s) = 0;
};

#endif // ETAT_HPP
