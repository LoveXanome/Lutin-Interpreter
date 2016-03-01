#ifndef ETAT_HPP
#define ETAT_HPP

#include <string>

#include "AutomateLutin.hpp"
#include "Symbole.hpp"

class Etat
{
public:
	Etat(std::string name);
	virtual ~Etat();
	void print() const;
	virtual bool transition(AutomateLutin& automate, Symbole* s) = 0;
	
protected:
	std::string name;
};

#endif // ETAT_HPP
