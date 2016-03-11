#ifndef IDENTIFIANT_HPP
#define IDENTIFIANT_HPP

#include <string>
#include "Expression.hpp"
#include "SymboleEnum.hpp"

class Identifiant : public Expression
{
public:
	Identifiant(const std::string& identifiant);
	Identifiant(const std::string& identifiant, const SymboleEnum& enumRepresentation);
	virtual ~Identifiant();
	std::string getIdentifiant() const;
	std::string toString() const;
	
private:
	std::string identifiant;
	
};

#endif // IDENTIFIANT_HPP
