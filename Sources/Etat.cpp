#include "Etat.hpp"

#include "StringHelper.hpp"

const Logger Etat::logger("Etat");

Etat::Etat(const unsigned int& number) : number(number)
{
	logger.construction(StringHelper::format("Etat %d", number));
}

Etat::~Etat()
{
	logger.destruction(StringHelper::format("Etat %d", number));
}

std::string Etat::toString() const
{
	return std::to_string(number);
}

std::vector<SymboleEnum> Etat::getExpectedSymbols() const
{
	return std::vector<SymboleEnum>({
		NONE
	});
}
