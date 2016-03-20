#ifndef ETAT_IDENTIFIANT_HPP
#define ETAT_IDENTIFIANT_HPP

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
	bool declared;
    bool affected;
    bool used;
};

#endif // ETAT_IDENTIFIANT_HPP
