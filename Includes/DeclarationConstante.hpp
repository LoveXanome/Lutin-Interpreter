#ifndef DECLARATION_CONSTANTE_HPP
#define DECLARATION_CONSTANTE_HPP

#include "Declaration.hpp"

class DeclarationConstante : public Declaration 
{
public:
	DeclarationConstante(const std::string& identifiant, const double& valeur);
	virtual ~DeclarationConstante();
	void print() const;
	double getExecValue() const;
	
private:
	double valeur;
};

#endif // DECLARATION_CONSTANTE_HPP
