#include "Etat.hpp"

Etat::Etat(const unsigned int& number) : number(number)
{
	
}

Etat::~Etat()
{
	
}

std::string Etat::toString() const
{
	return std::to_string(number);
}
