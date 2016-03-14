#ifndef DECLARATION_VARIABLE_HPP
#define DECLARATION_VARIABLE_HPP

#include "Declaration.hpp"
#include <string>

class DeclarationVariable : public Declaration
{
public:
	DeclarationVariable(const std::string& identifiant);
	virtual ~DeclarationVariable();
	void print() const;
	
	void setExecValue(const double& value);
	double getExecValue() const;
	
private:
	double execValue;
};

#endif // DECLARATION_VARIABLE_HPP
