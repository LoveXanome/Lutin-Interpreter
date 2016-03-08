#include "Etat.hpp"

const Logger Etat::logger("Etat");

Etat::Etat(const unsigned int& number) : number(number)
{
	
}

Etat::~Etat()
{
	logger.debug("Destruction etat");
}

std::string Etat::toString() const
{
	return std::to_string(number);
}
