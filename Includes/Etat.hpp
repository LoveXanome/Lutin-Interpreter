#ifndef ETAT_HPP
#define ETAT_HPP

#include <string>

class AutomateLutin;

#include <vector>
#include "AutomateLutin.hpp"
#include "Symbole.hpp"
#include "SymboleEnum.hpp"
#include "valeurRetour.hpp"


class Etat
{
public:
	Etat(const unsigned int& number);
	virtual ~Etat();
	std::string toString() const;
	virtual valeurRetour transition(AutomateLutin* automate, Symbole* s) = 0;
	virtual std::vector<SymboleEnum> getExpectedSymbols() const;
	
private:
	int number;
	
	static const Logger logger;
};

#endif // ETAT_HPP
