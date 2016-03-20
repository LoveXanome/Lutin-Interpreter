#include "EtatIdentifiant.hpp"

EtatIdentifiant::EtatIdentifiant() : declared(true), affected(false), used(false)
{
}

EtatIdentifiant::~EtatIdentifiant()
{
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
