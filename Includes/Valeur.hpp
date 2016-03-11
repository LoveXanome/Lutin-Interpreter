#ifndef VALEUR_HPP
#define VALEUR_HPP

#include "Expression.hpp"
#include "SymboleEnum.hpp"

class Valeur : public Expression
{
public:
	Valeur(const double& valeur);
	Valeur(const double& valeur, const SymboleEnum& enumRepresentation);
	virtual ~Valeur();
	double getValeur() const;
	std::string toString() const;
	
private:
	double valeur;
};

#endif // VALEUR_HPP
