#ifndef IDENTIFIANT_HPP
#define IDENTIFIANT_HPP

#include <string>
#include "Expression.hpp"

class Identifiant : public Expression
{
public:
	Identifiant();
	virtual ~Identifiant();
	
private:
	std::string identifiant;
	
};

#endif // IDENTIFIANT_HPP