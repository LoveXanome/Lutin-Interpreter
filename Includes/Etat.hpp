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
	virtual std::vector<SymboleEnum> getExpectedSymbols() const = 0;
	
	static const std::string ACCEPT_STATE;
	
private:
	int number;
	
	static const Logger logger;
	static uint32_t nbInstances;
};

#endif // ETAT_HPP
