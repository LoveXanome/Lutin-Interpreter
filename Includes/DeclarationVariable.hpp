#ifndef DECLARATION_VARIABLE_HPP
#define DECLARATION_VARIABLE_HPP

#include "Declaration.hpp"
#include <string>

class DeclarationVariable : public Declaration
{
public:
	DeclarationVariable(const std::string& identifiant, const SymboleEnum& enumRepresentation);
	virtual ~DeclarationVariable();
};

#endif // DECLARATION_VARIABLE_HPP
