#ifndef VALEUR_HPP
#define VALEUR_HPP

#include <iostream>
#include "Expression.hpp"

class Valeur : public Expression
{
public:
	Valeur();
	virtual ~Valeur();
	
private:
	double valeur;
	
};

#endif // VALEUR_HPP