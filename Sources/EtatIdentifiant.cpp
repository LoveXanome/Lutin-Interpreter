#include "EtatIdentifiant.hpp"

const Logger EtatIdentifiant::logger("EtatIdentifiant");
uint32_t EtatIdentifiant::nbInstances = 0;

EtatIdentifiant::EtatIdentifiant() : declared(true), affected(false), used(false)
{
	logger.construction(std::to_string(++nbInstances));
}

EtatIdentifiant::~EtatIdentifiant()
{
	logger.destruction(std::to_string(--nbInstances));
}

void EtatIdentifiant::affect()
{
	affected = true;
}

void EtatIdentifiant::use()
{
	used = true;
}

bool EtatIdentifiant::isDeclared()
{
	return declared;
}

bool EtatIdentifiant::isAffected()
{
	return affected;
}

bool EtatIdentifiant::isUsed()
{
	return used;
}
