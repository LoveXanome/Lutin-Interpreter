#include "Etat.hpp"

#include "StringHelper.hpp"

const Logger Etat::logger("Etat");
uint32_t Etat::nbInstances = 0;

const std::string Etat::ACCEPT_STATE("44");

Etat::Etat(const unsigned int& number) : number(number)
{
	logger.construction(StringHelper::format("Etat %d (existe : %d)", number, ++nbInstances));
}

Etat::~Etat()
{
	logger.destruction(StringHelper::format("Etat %d (existe : %d)", number, --nbInstances));
}

std::string Etat::toString() const
{
	return std::to_string(number);
}
