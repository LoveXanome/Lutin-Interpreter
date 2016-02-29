#ifndef DECLARATION_CONSTANTE_HPP
#define DECLARATION_CONSTANTE_HPP

#include "Declaration.hpp"

class DeclarationConstante : public Declaration 
{
	public:
		DeclarationConstante();
		virtual ~DeclarationConstante();
		
	private:
		double valeur;
};

#endif // DECLARATION_CONSTANTE_HPP
