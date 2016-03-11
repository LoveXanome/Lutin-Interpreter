#ifndef IDENTIFIANT_HPP
#define IDENTIFIANT_HPP

#include <string>
#include "Expression.hpp"

class Identifiant : public Expression
{
public:
	Identifiant(const std::string& identifiant);
	virtual ~Identifiant();
	std::string getIdentifiant() const;
	std::string toString() const;
	
private:
	std::string identifiant;
	
};

#endif // IDENTIFIANT_HPP
