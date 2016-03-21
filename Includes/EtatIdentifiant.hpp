#ifndef ETAT_IDENTIFIANT_HPP
#define ETAT_IDENTIFIANT_HPP

#include "Logger.hpp"

// Structure pour analyse statique
class EtatIdentifiant
{
public:
	EtatIdentifiant();
	~EtatIdentifiant();

	void affect();
	void use();
	
	bool isDeclared();
	bool isAffected();
	bool isUsed();
	
private:
	static const Logger logger;
	static uint32_t nbInstances;
	bool declared;
    bool affected;
    bool used;
};

#endif // ETAT_IDENTIFIANT_HPP
