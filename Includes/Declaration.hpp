
#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <string>
#include "SymboleEnum.hpp"
#include "Symbole.hpp"

class Declaration : public Symbole
{
public:
	Declaration(const std::string& identifiant);
	Declaration(const std::string& identifiant, const SymboleEnum& enumRepresentation);
	virtual ~Declaration();

protected:
	std::string identifiant;
};

#endif // DECLARATION_HPP
